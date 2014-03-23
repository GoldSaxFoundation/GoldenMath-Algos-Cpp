
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/// Author : Eric Thiemard 

# include <cstdlib>

# include <iostream>

# include <fstream>

# include <cmath>

# include <ctime>

# include <iomanip>

# include <cstring>

using namespace std;

typedef struct som sommet;

struct som

{

  int id;

  sommet *pt;

};

static int s;

static int n;

static int num;

static int den;

static int num2;

static int subtotala = 0;

static int subtotalb = 0;

static int *lexsizealpha;

static int *maxsizealpha;

static int *lexsizebeta;

static int *maxsizebeta;

static double epsilon;

static double borne_sup = 0.0;

static double borne_inf = 0.0;

static double *points;

static sommet *superarbre;

static sommet **lexalpha;

static sommet **lexbeta;

int main ( int argc, char *argv[] );

bool ch_eqi ( char c1, char c2 );

int ch_to_digit ( char c );

double *data_read ( char *file_in_name, int m, int n );

void decomposition ( double *alpha, double *beta, int min, double value );

int explore ( sommet *liste, double *pave, int dim );

int fastexplore ( double *pave, int range, int *maxsize, int *lexsize,

  sommet **lex, int *subtotal );

int file_column_count ( char *file_in_name );

int file_row_count ( char *file_in_name );

static void file_usage ( );

void freetree ( sommet *noeud );

void initlex ( );

void initparameters ( int argc, char *argv[] );

void insertlex ( sommet *noeud, int range, int *maxsize, int *lexsize, 

  sommet **lex );

double lowbound ( int npoints, double volume, double *pave );

static void memory ( );

void quicksort ( sommet *liste, int dim, int l, int r );

void readfile ( char *filename );

int s_len_trim ( char *s );

double s_to_r8 ( char *s, int *lchar, bool *error );

bool s_to_r8vec ( char *s, int n, double dvec[] );

int s_word_count ( char *s );

sommet *subtree ( sommet *liste, int min, int next, int dim );

void supertree ( );

void timestamp ( );

void traiter ( double *outputalpha, double *outputbeta, int range );

static void usage ( char *exec_name );

int main ( int argc, char *argv[] )

{

  int i;

  int j;

  int n_max;

  double *oalpha;

  double *obeta;

  timestamp ( );

  cout << "\n";

  cout << "STAR_DISCREPANCY:\n";

  cout << "  C++ version\n";

  cout << "\n";

  cout << "  Compiled on " << __DATE__ << " at " << __TIME__ << ".\n";

  cout << "\n";

  cout << "  A program to estimate the discrepancy\n";

  cout << "  of a set of N points in M dimensions.\n";

  initparameters ( argc, argv );

  s = file_column_count ( argv[3] );

  if ( s < 2 ) 

  {

    cout << "\n";

    cout << "STAR_DISCREPANCY - Fatal error!\n";

    cout << "  The spatial dimension S must be at least 2.\n";

    exit ( 1 );

  }

  n_max = file_row_count ( argv[3] );

  if ( n_max < n )

  {

    cout << "\n";

    cout << "STAR_DISCREPANCY - Fatal error!\n";

    cout << "  The number of data points requested is N = " << n << ".\n";

    cout << "  The data file only contains N_MAX = " << n_max << ".\n";

    exit ( 1 );

  }

  points = data_read ( argv[3], s, n );

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < s; j++ )

    {

      if ( points[j+i*s] < 0.0 || 1.0 < points[j+i*s] )

      {

        cout << "\n";

        cout << "STAR_DISCREPANCY - Fatal error!\n";

        cout << "  Every coordinate of every point must be between 0 and 1.\n";

        cout << "  However, coordinate " << j << " of point " << i << "\n";

        cout << "  is equal to " << points[j+i*s] << "\n";

        exit ( 1 );

      }

    }

  }

  if ( n <= 20 )

  {

    cout << "\n";

    cout << "x = \n";

    cout << "{\n";

    for ( i = 0; i < n; i++ )

    {

      cout << "  {";

      for ( j = 0; j < s; j++ )

      {

        cout << setw(10) << points[j+i*s] << "  ";

      }

      cout << "  }\n";

    }

    cout << "}\n";

    cout << "\n";

  }

  supertree ( );

  initlex ( );

  

  oalpha = (double *) calloc ( (unsigned) s, sizeof(double) );

  obeta  = (double *) calloc ( (unsigned) s, sizeof(double) );

  for ( i = 0; i < s; i++ )

  {

    obeta[i] = 1.0;

  }

  decomposition ( oalpha, obeta, 0, 1.0 );

  cout << "\n";

  cout << "  S = " << s << "\n";

  cout << "  Epsilon = " << epsilon << "\n";

  cout << "  N = " << n << "\n";

  cout << "\n";

  cout << "  Estimate of Discrepancy D_n^*(x):\n";

  cout << "\n";

  cout << "   Lower         Upper\n";

  cout << "   bound         bound\n";

  cout << "------------  ------------\n";

  cout << "\n";

  cout << setw(12) << borne_inf << "  " 

       << setw(12) << borne_sup << "\n";

  cout << "\n";

  cout << "STAR_DISCREPANCY:\n";

  cout << "  Normal end of execution.\n";

  cout << "\n";

  timestamp ( );

  return 0;

}

bool ch_eqi ( char c1, char c2 )

{

  if ( 97 <= c1 && c1 <= 122 ) 

  {

    c1 = c1 - 32;

  } 

  if ( 97 <= c2 && c2 <= 122 ) 

  {

    c2 = c2 - 32;

  }     

  return ( c1 == c2 );

}

int ch_to_digit ( char c )

{

  int digit;

  if ( '0' <= c && c <= '9' )

  {

    digit = c - '0';

  }

  else if ( c == ' ' )

  {

    digit = 0;

  }

  else

  {

    digit = -1;

  }

  return digit;

}

double *data_read ( char *file_in_name, int m, int n )

{

  double *coord;

  bool error;

  ifstream file_in;

  int i;

  int j;

  char line[255];

  double *x;

  file_in.open ( file_in_name );

  if ( !file_in )

  {

    cout << "\n";

    cout << "DATA_READ - Fatal error!\n";

    cout << "  Could not open the input file: \"" << file_in_name << "\"\n";

    exit ( 1 );

  }

  coord = new double[m*n];

  x = new double[m];

  j = 0;

  while ( j < n )

  {

    file_in.getline ( line, sizeof ( line ) );

    if ( file_in.eof ( ) )

    {

      break;

    }

    if ( line[0] == '#' || s_len_trim ( line ) == 0 )

    {

      continue;

    }

    error = s_to_r8vec ( line, m, x );

    if ( error )

    {

      continue;

    }

    for ( i = 0; i < m; i++ )

    {

      coord[i+j*m] = x[i];

    }

    j = j + 1;

  }

  file_in.close ( );

  delete [] x;

  return coord;

}

void decomposition ( double *alpha, double *beta, int min, double value )

{

  int i;

  double pbetaminp = 1.0;

  double palpha = 1.0;

  double pbeta;

  double delta;

  double *subalpha;

  double *subbeta;

  double *gamma;

  subalpha = (double *) calloc ( (unsigned) s, sizeof(double) );

  subbeta  = (double *) calloc ( (unsigned) s+1, sizeof(double) );

  gamma  = (double *) calloc ( (unsigned) s+1, sizeof(double) );

  for ( i = min; i < s; i++ )

  {

    pbetaminp = pbetaminp * beta[i];

  }

  pbeta = pbetaminp;

  for ( i = 0; i < min; i++ )

  {

    pbetaminp = pbetaminp * beta[i];

    palpha = palpha * alpha[i];

  }

  pbetaminp = pbetaminp - epsilon;

  delta = pow ( pbetaminp / ( pbeta * palpha ), 1.0 / ( s - min ) );

  for ( i = 0; i < min; i++ )

  {

    gamma[i] = alpha[i];

    subalpha[i] = gamma[i];

    subbeta[i] = beta[i];

  }

  for ( i = min; i < s; i++ )

  {

    gamma[i] = delta * beta[i];

    subalpha[i] = alpha[i];

    subbeta[i] = beta[i];

  }

  subbeta[min] = gamma[min];

  value = value * delta;

  if ( epsilon < value )

  {

    for ( i = min; i < s; i++ )

    {

      decomposition ( subalpha, subbeta, i, value );

      subalpha[i]  = gamma[i];

      subbeta[i]   = beta[i];

      subbeta[i+1] = gamma[i+1];

    }

  }

  else

  {

    for ( i = min; i < s; i++ )

    {

      traiter ( subalpha, subbeta, (i==0)?0:i-1 );

      subalpha[i]  = gamma[i];

      subbeta[i]   = beta[i];

      subbeta[i+1] = gamma[i+1];

    }

  }

  traiter ( gamma, beta, s-1 );

  free ( gamma );

  free ( subalpha );

  free ( subbeta );

  return;

}

int explore ( sommet *liste, double *pave, int dim )

{

  int i;

  int min = 1;

  int max;

  int next;

  int total;

  if ( pave[dim] <= points[dim+(liste[1].id)*s] )

  {

    return 0;

  }

  if ( liste[0].id == 1 )

  {

    total = 1;

    next = liste[1].id; 

    for ( i = dim; i < s; i++ )

    {

      if ( pave[i] <= points[i+next*s] )

      {

        total = 0;

        break;

      }

    }

  }

  else

  {

    total = 0;

    max = liste[0].id;

    if ( dim == s-1 )

    {

      if ( points[dim+(liste[max].id)*s] < pave[dim] )

      {

        total = max;

      }

      else

      {

        while ( min <= max )

        {

          next = ( min + max + 1 ) / 2;

          if ( points[dim+(liste[next].id)*s] < pave[dim] )

          {    

            total = total + next - min + 1;

            min = next + 1;

          }

          else

          {

            max = next - 1;

          }

        }

      }

    }

    else

    {

      while ( min <= max )

      {

        next = ( ( 1 + min ) * num2 + max * num ) / den;

        if ( points[dim+(liste[next].id)*s] < pave[dim] )

        {

          if ( liste[next].pt == NULL )

          {

            liste[next].pt = subtree ( liste, min, next, dim+1 );

          }

          total = total + explore ( liste[next].pt, pave, dim+1 );

          min = next + 1;

        }

        else

        {

          max = next - 1;

        }

      }

    }

  }

  return total;

}

int fastexplore ( double *pave, int range, int *maxsize, int *lexsize,

  sommet **lex, int *subtotal )

{

  int j;

  int i;

  int min;

  int max;

  int next;

  int start;

  int size = lexsize[range];

  int right;

  int total = 0;

  double seuil = pave[range];

  sommet refnoeud;

  sommet *noeud;

  if ( range == s - 1 )

  {

    for ( i = size-1; 0 <= i; i-- )

    {

      refnoeud = lex[range][i];

      noeud = refnoeud.pt;

      min = refnoeud.id;

      max = noeud[0].id;

      if ( max < min )

      {

        lexsize[range]--;

        lex[range][i] = lex[range][lexsize[range]];

        *subtotal = *subtotal + min - 1;

      }

      else

      {

        total = total + min - 1;

        right = 1;

        while ( min <= max )

        {

          next = ( min + max + 1 ) / 2;

          if ( points[range+(noeud[next].id)*s] < seuil )

          {    

            total = total + next - min + 1;

            min = next + 1;

            if ( right == 1 )

            {

              lex[range][i].id = min;

            }

          }

          else

          {

            right = 0;

            max = next - 1;

          }

        }

      }

    }

    total = total + *subtotal;

  }

  else

  {

    *subtotal = 0;

    lexsize[range+1] = 0;

    for ( i = 0; i < size; i++ )

    {

      refnoeud = lex[range][i];

      noeud = refnoeud.pt;

      start = refnoeud.id;

      min = 1;

      max = noeud[0].id;

      while ( min != start )

      {

        next = ( ( 1 + min ) * num2 + max * num ) / den;

        insertlex ( noeud[next].pt, range+1, maxsize, lexsize, lex );

        total = total + explore ( noeud[next].pt, pave, range+1 );

        min = next + 1;

      }

      right = 1;

      while ( min <= max )

      {

        next = ( ( 1 + min ) * num2 + max * num ) / den;

        if ( points[range+(noeud[next].id)*s] < seuil )

        {

          if ( noeud[next].pt == NULL )

          {

            noeud[next].pt = subtree ( noeud, min, next, range+1 );

          }

          insertlex ( noeud[next].pt, range+1, maxsize, lexsize, lex );

          total = total + explore ( noeud[next].pt, pave, range+1 );

          min = next + 1;

          if ( right == 1 )

          {

            if ( range == 0 )

            {

              if ( lex == lexalpha )

              {

                for ( j = lex[range][i].id; j < next; j++ )

                {

                  if ( noeud[j].pt != NULL )

                  {

                    freetree ( noeud[j].pt );

                  }

                }

              }

            }

            lex[range][i].id = min;

          }

        }

        else

        {

          right = 0;

          max = next - 1;

        }

      }

    }

  }

  return total;

}

int file_column_count ( char *file_in_name )

{

  ifstream file_in;

  bool got_one;

  char line[256];

  int ncolumn;

  file_in.open ( file_in_name );

  if ( !file_in )

  {

    ncolumn = -1;

    cout << "\n";

    cout << "FILE_COLUMN_COUNT - Fatal error!\n";

    cout << "  Could not open the file:\n";

    cout << "  \"" << file_in_name << "\"\n";

    return ncolumn;

  }

  got_one = false;

  for ( ; ; )

  {

    file_in.getline ( line, sizeof ( line ) );

    if ( file_in.eof ( ) )

    {

      break;

    }

    if ( s_len_trim ( line ) == 0 )

    {

      continue;

    }

    if ( line[0] == '#' )

    {

      continue;

    }

    got_one = true;

    break;

  }

  if ( !got_one )

  {

    file_in.close ( );

    file_in.open ( file_in_name );

    for ( ; ; )

    {

      file_in.getline ( line, sizeof ( line ) );

      if ( file_in.eof ( ) )

      {

        break;

      }

      if ( s_len_trim ( line ) == 0 )

      {

        continue;

      }

      got_one = true;

      break;

    }

  }

  file_in.close ( );

  if ( !got_one )

  {

    cout << "\n";

    cout << "FILE_COLUMN_COUNT - Warning!\n";

    cout << "  The file does not seem to contain any data.\n";

    return 0;

  }

  ncolumn = s_word_count ( line );

  return ncolumn;

}

int file_row_count ( char *file_in_name )

{

  int bad_num;

  int comment_num;

  ifstream file_in;

  int i;

  char line[100];

  int record_num;

  int row_num;

  row_num = 0;

  comment_num = 0;

  record_num = 0;

  bad_num = 0;

  file_in.open ( file_in_name );

  if ( !file_in )

  {

    cout << "\n";

    cout << "FILE_ROW_COUNT - Fatal error!\n";

    cout << "  Could not open the input file: \"" << file_in_name << "\"\n";

    exit ( 1 );

  }

  for ( ; ; )

  {

    file_in.getline ( line, sizeof ( line ) );

    if ( file_in.eof ( ) )

    {

      break;

    }

    record_num = record_num + 1;

    if ( line[0] == '#' )

    {

      comment_num = comment_num + 1;

      continue;

    }

    if ( s_len_trim ( line ) == 0 )

    {

      comment_num = comment_num + 1;

      continue;

    }

    row_num = row_num + 1;

  }

  file_in.close ( );

  return row_num;

}

static void file_usage ( )

{

  cout << "\n";

  cout << "FILE_USAGE:\n";

  cout << "  This program requires an input file that defines\n";

  cout << "  the point set.\n";

  cout << "  We assume that the points are S-dimensional, and \n";

  cout << "  that there are N_MAX of them.\n";

  cout << "\n";

  cout << "  We also require that the points be in the unit hypercube.\n";

  cout << "\n";

  cout << "  Then the input file contains N_MAX lines or records.\n";

  cout << "  Each record contains the S coordinate values of one point.\n";

  cout << "\n";

  cout << "  Comment lines begin with the character \"#\",\n";

  cout << "  and may occur anywhere in the file.\n";

  cout << "\n";

  cout << "  At runtime, the user specifies N, the number of points\n";

  cout << "  to be read from the file, which must be less than or\n";

  cout << "  equal to N_MAX.\n";

  cout << "\n";

  cout << "  Here is an example of a file containing N_MAX = 5\n";

  cout << "  points in S = 3 dimensions:\n";

  cout << "\n";

  cout << "#  input_3x5.txt\n";

  cout << "#\n";

  cout << "#  Suitable for input to DISCRBOUND.\n";

  cout << "#  Spatial dimension = 3\n";

  cout << "#  Number of points = 5\n";

  cout << "#\n";

  cout << "  0.00  0.20  0.90\n";

  cout << "  0.80  0.40  0.30\n";

  cout << "  0.20  1.00  0.50\n";

  cout << "  0.40  0.60  0.10\n";

  cout << "  0.60  0.80  0.70\n";

  cout << "\n";

  return;

}

void freetree ( sommet *noeud )

{

  int i;

  int max = noeud[0].id;

  for ( i = 1; i <= max; i++ )

  {

    if ( noeud[i].pt != NULL )

    {

      freetree ( noeud[i].pt );

    }

  }

  free ( noeud );

  return;

}

void initlex ( )

{

  int i;

  maxsizealpha = (int *) calloc ( (unsigned) s, sizeof(int) );

  for ( i = 0; i < s; i++ )

  {

    maxsizealpha[i] = 1;

  }

  lexsizealpha = (int *) calloc ( (unsigned) s, sizeof(int) );

  lexsizealpha[0] = 1;

  lexalpha = (sommet **) calloc ( (unsigned) s, sizeof(sommet *) );

  for ( i = 0; i < s; i++ )

  {

    lexalpha[i] = (sommet *) calloc ( (unsigned) maxsizealpha[i], sizeof(sommet) );

  }

  lexalpha[0][0].id = 1;

  lexalpha[0][0].pt = superarbre;

  maxsizebeta = (int *) calloc ( (unsigned) s, sizeof(int) );

  for ( i = 0; i < s; i++ )

  {

    maxsizebeta[i] = 1;

  }

  lexsizebeta = (int *) calloc ( (unsigned) s, sizeof(int) );

  lexsizebeta[0] = 1;

  lexbeta = (sommet **) calloc ( (unsigned) s, sizeof(sommet *) );

 

  for ( i = 0; i < s; i++ )

  {

    lexbeta[i] = (sommet *) calloc ( (unsigned) maxsizebeta[i], sizeof(sommet) );

  }

  lexbeta[0][0].id = 1;

  lexbeta[0][0].pt = superarbre;

  return;

}

void initparameters ( int argc, char *argv[] )

{

  if ( ( argc != 4 ) && ( argc != 6 ) )

  {

    usage ( argv[0] );

    exit ( 1 );

  }

  epsilon = atof ( argv[1] );

  if ( epsilon <= 0.0 || 1.0 <= epsilon )

  {

    cout << "\n";

    cout << "INITPARAMETERS: Fatal error!\n";

    cout << "  The error tolerance EPSILON = " << epsilon << ".\n";

    cout << "  But EPSILON must be between 0 and 1.\n";

    exit ( 1 );

  }

  n = atoi ( argv[2] );

  if ( n < 1 )

  {

    usage ( argv[0] );

    exit ( 1 );

  }

  if ( argc == 6 )

  {

    num = atoi ( argv[4] );

    den = atoi ( argv[5] );

    if ( num < 1 || den <= num )

    {

      usage ( argv[0] );

      exit ( 1 );

    }

  }

  else

  {

    num = 1;

    den = 2;

  }

  num2 = den - num;

  return;

}

void insertlex ( sommet *noeud, int range, int *maxsize, int *lexsize, 

  sommet **lex )

{

  int i = lexsize[range];

  if ( i == maxsize[range] )

  {

    maxsize[range] *= 2;

    lex[range] = ( sommet * ) realloc ( lex[range], 

      (unsigned) maxsize[range]*sizeof(sommet) );

    if ( lex[range] == NULL)

    {

      memory();

    }

  }

  lex[range][i].pt = noeud;

  lex[range][i].id = 1;

  lexsize[range] = ++i;

  return;

}

double lowbound ( int npoints, double volume, double *pave )

{

  int i;

  int j;

  double tmp;

  if ( borne_inf < fabs ( volume - ( (double) npoints / n ) ) )

  {

    if ( volume < ( (double) npoints / n ) )

    {

      volume = 1.0;

      for ( j = 0; j < s; j++ )

      {

        tmp = 0.0;

        for ( i = 0; i < n; i++ )

        {

          if ( tmp < points[j+i*s] && points[j+i*s] <= pave[j] )

          {

            tmp = points[j+i*s];

          }

        }

        volume = volume * tmp;

      }

    }

    else

    {

      volume = 1.0;

      for ( j = 0; j < s; j++ )

      {

        tmp = 1.0;

        for ( i = 0; i < n; i++ )

        {

          if ( points[j+i*s] < tmp && pave[j] <= points[j+i*s] )

          {

            tmp = points[j+i*s];

          }

        }

        volume = volume * tmp;

      }

    }

    return fabs ( volume - ( (double) npoints / n ) );

  }

  else

  {

    return borne_inf;

  }

}

static void memory ( )

{

  cout << "\n";

  cout << "MEMORY - Fatal error!\n";

  cout << "  Memory allocation problem\n";

  exit ( 1 );

}

void quicksort ( sommet *liste, int dim, int l, int r )

{

  int i = l;

  int j = r+1;

  int tmp;

  double pivot = points[dim+(liste[l].id)*s];

  while ( i < j )

  {

    do

    i++;

    while ( i < r && points[dim+(liste[i].id)*s] < pivot );

    do

    j--;

    while ( pivot < points[dim+(liste[j].id)*s] );

    if ( i < j )

    {

      tmp = liste[i].id;

      liste[i].id = liste[j].id;

      liste[j].id = tmp;

    }

  }

  tmp = liste[l].id;

  liste[l].id = liste[j].id;

  liste[j].id = tmp;

  if ( l < j-1 )

  {

    quicksort ( liste, dim, l, j-1 );

  }

  if ( j+1 < r )

  {

    quicksort ( liste, dim, j+1, r );

  }

  return;

}

int s_len_trim ( char *s )

{

  int n;

  char *t;

  n = strlen ( s );

  t = s + strlen ( s ) - 1;

  while ( 0 < n ) 

  {

    if ( *t != ' ' )

    {

      return n;

    }

    t--;

    n--;

  }

  return n;

}

double s_to_r8 ( char *s, int *lchar, bool *error )

{

  char c;

  int ihave;

  int isgn;

  int iterm;

  int jbot;

  int jsgn;

  int jtop;

  int nchar;

  int ndig;

  double r;

  double rbot;

  double rexp;

  double rtop;

  char TAB = 9;

  nchar = s_len_trim ( s );

  *error = false;

  r = 0.0;

  *lchar = -1;

  isgn = 1;

  rtop = 0.0;

  rbot = 1.0;

  jsgn = 1;

  jtop = 0;

  jbot = 1;

  ihave = 1;

  iterm = 0;

  for ( ; ; )

  {

    c = s[*lchar+1];

    *lchar = *lchar + 1;

    if ( c == ' ' || c == TAB )

    {

      if ( ihave == 2 )

      {

      }

      else if ( ihave == 6 || ihave == 7 )

      {

        iterm = 1;

      }

      else if ( 1 < ihave )

      {

        ihave = 11;

      }

    }

    else if ( c == ',' || c == ';' )

    {

      if ( ihave != 1 )

      {

        iterm = 1;

        ihave = 12;

        *lchar = *lchar + 1;

      }

    }

    else if ( c == '-' )

    {

      if ( ihave == 1 )

      {

        ihave = 2;

        isgn = -1;

      }

      else if ( ihave == 6 )

      {

        ihave = 7;

        jsgn = -1;

      }

      else

      {

        iterm = 1;

      }

    }

    else if ( c == '+' )

    {

      if ( ihave == 1 )

      {

        ihave = 2;

      }

      else if ( ihave == 6 )

      {

        ihave = 7;

      }

      else

      {

        iterm = 1;

      }

    }

    else if ( c == '.' )

    {

      if ( ihave < 4 )

      {

        ihave = 4;

      }

      else if ( 6 <= ihave && ihave <= 8 )

      {

        ihave = 9;

      }

      else

      {

        iterm = 1;

      }

    }

    else if ( ch_eqi ( c, 'E' ) || ch_eqi ( c, 'D' ) )

    {

      if ( ihave < 6 )

      {

        ihave = 6;

      }

      else

      {

        iterm = 1;

      }

    }

    else if ( ihave < 11 && '0' <= c && c <= '9' )

    {

      if ( ihave <= 2 )

      {

        ihave = 3;

      }

      else if ( ihave == 4 )

      {

        ihave = 5;

      }

      else if ( ihave == 6 || ihave == 7 )

      {

        ihave = 8;

      }

      else if ( ihave == 9 )

      {

        ihave = 10;

      }

      ndig = ch_to_digit ( c );

      if ( ihave == 3 )

      {

        rtop = 10.0 * rtop + ( double ) ndig;

      }

      else if ( ihave == 5 )

      {

        rtop = 10.0 * rtop + ( double ) ndig;

        rbot = 10.0 * rbot;

      }

      else if ( ihave == 8 )

      {

        jtop = 10 * jtop + ndig;

      }

      else if ( ihave == 10 )

      {

        jtop = 10 * jtop + ndig;

        jbot = 10 * jbot;

      }

    }

    else

    {

      iterm = 1;

    }

    if ( iterm == 1 || nchar <= *lchar + 1 )

    {

      break;

    }

  }

  if ( iterm != 1 && (*lchar) + 1 == nchar )

  {

    *lchar = nchar;

  }

  if ( ihave == 1 || ihave == 2 || ihave == 6 || ihave == 7 )

  {

    *error = true;

    return r;

  }

  if ( jtop == 0 )

  {

    rexp = 1.0;

  }

  else

  {

    if ( jbot == 1 )

    {

      rexp = pow ( 10.0, jsgn * jtop );

    }

    else

    {

      rexp = jsgn * jtop;

      rexp = rexp / jbot;

      rexp = pow ( 10.0, rexp );

    }

  }

  r = isgn * rexp * rtop / rbot;

  return r;

}

bool s_to_r8vec ( char *s, int n, double dvec[] )

{

  bool error;

  int i;

  int lchar;

  for ( i = 0; i < n; i++ )

  {

    dvec[i] = s_to_r8 ( s, &lchar, &error );

    if ( error )

    {

      return error;

    }

    s = s + lchar;

  }

  return error;

}

int s_word_count ( char *s )

{

  bool blank;

  int i;

  int nword;

  nword = 0;

  blank = true;

  while ( *s != NULL ) 

  {

    if ( *s == ' ' )

    {

      blank = true;

    }

    else if ( blank )

    {

      nword = nword + 1;

      blank = false;

    }

    *s++;

  }

  return nword;

}

sommet *subtree ( sommet *liste, int min, int next, int dim )

{

  int i;

  int aux;

  int n2;

  sommet *newarbre;

  aux = min - 1;

  n2 = next - min + 1;

  newarbre = (sommet *) calloc ( (unsigned) n2+1, sizeof(sommet) );

  if ( newarbre == NULL )

  {

    memory();

  }

  for ( i = 1; i <= n2; i++ )

  {

    newarbre[i].id = liste[i+aux].id;

  }

  newarbre[0].id = n2;

  if ( 1 < n2 )

  {

    quicksort ( newarbre, dim, 1, n2 );

  }

  return newarbre;

}

void supertree ( )

{

  int i;

  superarbre = (sommet *) calloc ( (unsigned) n+1, sizeof(sommet) );

  if ( superarbre == NULL )

  {

    memory();

  }

  for ( i = 1; i <= n; i++ )

  {

    superarbre[i].id = i - 1;

  }

  superarbre[0].id = n;

  quicksort ( superarbre, 0, 1, n );

  return;

}

void timestamp ( )

{

# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];

  const struct tm *tm;

  size_t len;

  time_t now;

  now = time ( NULL );

  tm = localtime ( &now );

  len = strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  cout << time_buffer << "\n";

  return;

# undef TIME_SIZE

}

void traiter ( double *outputalpha, double *outputbeta, int range )

{

  int i;

  double valpha = 1.0;

  double vbeta = 1.0;

  double newborne;

  int nalpha;

  int nbeta;

  for ( i = 0; i < s; i++ )

  {

    valpha = valpha * outputalpha[i];

    vbeta = vbeta * outputbeta[i];

  }

  nalpha = fastexplore ( outputalpha, range, maxsizealpha, lexsizealpha,

   lexalpha, &subtotala );

  nbeta = fastexplore ( outputbeta, range, maxsizebeta, lexsizebeta, 

    lexbeta, &subtotalb );

  newborne = ( (double) nbeta / n ) - valpha;

  if ( borne_sup < newborne )

  {

    borne_sup = newborne;

  }

  newborne = vbeta - ( (double) nalpha / n );

  if ( borne_sup < newborne )

  {

    borne_sup = newborne;

  }

  borne_inf = lowbound ( nalpha, valpha, outputalpha );

  borne_inf = lowbound ( nbeta,  vbeta,  outputbeta );

  return;

}

static void usage ( char *exec_name )

{

  cout << "\n";

  cout << "Usage:\n";

  cout << "\n";

  cout << "  " << exec_name << " EPSILON N FILENAME\n";

  cout << "\n";

  cout << "  EPSILON,  accuracy parameter, 0.0 < epsilon < 1.0\n";

  cout << "  N,        number of points, integer, at least 1.\n";

  cout << "  FILENAME, containing the pointset.\n";

  cout << "\n";

  cout << "  " << exec_name << " EPSILON N FILENAME NUM DEN\n";

  cout << "\n";

  cout << "  Same as above, plus:\n";

  cout << "\n";

  cout << "  NUM,	optional balance numerator,\n";

  cout << "  DEN,       optional balance denominator,\n";

  cout << "		such that 0.0 < NUM / DEN < 1.0\n";

  cout << "             Default is NUM=1, DEN=2.\n"; 

  return;

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/