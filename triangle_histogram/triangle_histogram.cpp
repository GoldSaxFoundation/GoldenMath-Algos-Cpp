
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <cmath>

# include <iostream>

# include <fstream>

# include <iomanip>

# include <string>

# include <ctime>

using namespace std;

int main ( int argc, char *argv[] );

char ch_cap ( char c );

bool ch_eqi ( char c1, char c2 );

int ch_to_digit ( char c );

int file_column_count ( string input_filename );

int file_row_count ( string input_filename );

int i4_max ( int i1, int i2 );

int i4_min ( int i1, int i2 );

int i4vec_min ( int n, int a[] );

int i4vec_max ( int n, int a[] );

double i4vec_mean ( int n, int x[] );

double i4vec_std ( int n, int x[] );

double *r8mat_data_read ( string input_filename, int m, int n );

void r8mat_header_read ( string input_filename, int *m, int *n );

void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo, 

  int ihi, int jhi, string title );

int s_len_trim ( string s );

int s_to_i4 ( string s, int *last, bool *error );

double s_to_r8 ( string s, int *lchar, bool *error );

bool s_to_r8vec ( string s, int n, double rvec[] );

int s_word_count ( string s );

void timestamp ( );

int main ( int argc, char *argv[] )

{

  int d;

  string data_filename;

  int data_num;

  double *data_xy;

  int dim_num;

  int *histo;

  double histo_ave;

  int histo_max;

  int histo_min;

  double histo_std;

  int i;

  int j;

  int k;

  int n;

  int sub_num;

  int t;

  cout << "\n";

  timestamp ( );

  cout << "\n";

  cout << "TRIANGLE_HISTOGRAM\n";

  cout << "  C++ version\n";

  cout << "  Compute a histogram for data in the reference triangle.\n";

  cout << "\n";

  cout << "  Compiled on " << __DATE__ << " at " << __TIME__ << ".\n";

  if ( argc <= 1 ) 

  {

    cout << "\n";

    cout << "TRIANGLE_HISTOGRAM:\n";

    cout << "  Please enter the data filename.\n";

    cin >> data_filename;

  }

  else 

  {

    data_filename = argv[1];

  }

  if ( argc <= 2 ) 

  {

    cout << "\n";

    cout << "TRIANGLE_HISTOGRAM:\n";

    cout << "  Please enter the value of N.\n";

    cin >> n;

  }

  else 

  {

    n = atoi ( argv[2] );

  }

  r8mat_header_read ( data_filename, &dim_num, &data_num );

  cout << "\n";

  cout << "  Read the header of \"" << data_filename << "\".\n";

  cout << "\n";

  cout << "  Spatial dimension DIM_NUM =  " << dim_num << "\n";

  cout << "  Number of points DATA_NUM  = " << data_num << "\n";

  if ( dim_num != 2 )

  {

    cout << "\n";

    cout << "TRIANGLE_HISTOGRAM - Fatal error!\n";

    cout << "  Dataset must have spatial dimension 2.\n";

    return 1;

  }

  data_xy = r8mat_data_read ( data_filename, dim_num, data_num );

  cout << "\n";

  cout << "  Read the data in \"" << data_filename << "\".\n";

  r8mat_transpose_print_some ( dim_num, data_num, data_xy, 1, 1, 5, 5, 

    "  5 by 5 portion of data read from file:" );

  for ( d = 0; d < data_num; d++ )

  {

    if ( data_xy[0+d*2] < 0.0 ||

         data_xy[1+d*2] < 0.0 ||

                        1.0 < data_xy[0+d*2] + data_xy[1+d*2] )

    {

      cout << "\n";

      cout << "TRIANGLE_HISTOGRAM - Fatal error!\n";

      cout << "  Point " << d << " does not lie inside the triangle.\n";

      cout << "  X = " << data_xy[0+d*2] << "\n";

      cout << "  Y = " << data_xy[1+d*2] << "\n";

      exit ( 1 );

    }

  }

  sub_num = n * n;

  histo = new int[sub_num+1];

  for ( i = 0; i < sub_num + 1; i++ )

  {

    histo[i] = 0;

  }

  for ( d = 0; d < data_num; d++ )

  {

    i = ( int ) (         data_xy[0+d*2]                    * ( double ) ( n ) ) + 1;

    j = ( int ) (                          data_xy[1+d*2]   * ( double ) ( n ) ) + 1;

    k = ( int ) ( ( 1.0 - data_xy[0+d*2] - data_xy[1+d*2] ) * ( double ) ( n ) ) + 1;

    if ( i < 1 || n < i ||

         j < 1 || n < j ||

         k < 1 || n < k )

    {

      t = n * n + 1;

    }

    else

    {

      t = 2 * i + ( n - j ) * ( n - j ) + ( ( k - 1) %  2 ) - 1;

    }

    histo[t-1] = histo[t-1] + 1;

  }

  histo_ave = i4vec_mean ( sub_num, histo );

  histo_max = i4vec_max ( sub_num, histo );

  histo_min = i4vec_min ( sub_num, histo );

  histo_std = i4vec_std ( sub_num, histo );

  cout << "\n";

  cout << "  Data from file \"" << data_filename << "\".\n";

  cout << "  Number of points = " << data_num << "\n";

  cout << "\n";

  cout << "  Triangle refinement level N = " <<  n << "\n";

  cout << "  Number of triangles = " <<  sub_num << "\n";

  cout << "\n";

  cout << "  Counting number of points in each subtriangle:\n";

  cout << "\n";

  cout << "  Minimum = " <<  histo_min << "\n";

  cout << "  Average = " <<  histo_ave << "\n";

  cout << "  Maximum = " <<  histo_max << "\n";

  cout << "  STD     = " <<  histo_std << "\n";

  cout << "\n";

  cout << "     COUNT\n";

  cout << "\n";

  for ( k = 0; k < n * n; k++ )

  {

    cout << "  " << setw(8) << histo[k] << "\n";

  }

  cout << "\n";

  cout << "  Number of out-or-range points = " << histo[n*n] << "\n";

  delete [] data_xy;

  delete [] histo;

  

  cout << "\n";

  cout << "TRIANGLE_HISTOGRAM:\n";

  cout << "  Normal end of execution.\n";

  cout << "\n";

  timestamp ( );

  return 0;

}

char ch_cap ( char c )

{

  if ( 97 <= c && c <= 122 ) 

  {

    c = c - 32;

  }   

  return c;

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

int file_column_count ( string filename )

{

  int column_num;

  ifstream input;

  bool got_one;

  string text;

  input.open ( filename.c_str ( ) );

  if ( !input )

  {

    column_num = -1;

    cerr << "\n";

    cerr << "FILE_COLUMN_COUNT - Fatal error!\n";

    cerr << "  Could not open the file:\n";

    cerr << "  \"" << filename << "\"\n";

    return column_num;

  }

  got_one = false;

  for ( ; ; )

  {

    getline ( input, text );

    if ( input.eof ( ) )

    {

      break;

    }

    if ( s_len_trim ( text ) <= 0 )

    {

      continue;

    }

    if ( text[0] == '#' )

    {

      continue;

    }

    got_one = true;

    break;

  }

  if ( !got_one )

  {

    input.close ( );

    input.open ( filename.c_str ( ) );

    for ( ; ; )

    {

      input >> text;

      if ( input.eof ( ) )

      {

        break;

      }

      if ( s_len_trim ( text ) == 0 )

      {

        continue;

      }

      got_one = true;

      break;

    }

  }

  input.close ( );

  if ( !got_one )

  {

    cerr << "\n";

    cerr << "FILE_COLUMN_COUNT - Warning!\n";

    cerr << "  The file does not seem to contain any data.\n";

    return -1;

  }

  column_num = s_word_count ( text );

  return column_num;

}

int file_row_count ( string input_filename )

{

  int bad_num;

  int comment_num;

  ifstream input;

  int i;

  string line;

  int record_num;

  int row_num;

  row_num = 0;

  comment_num = 0;

  record_num = 0;

  bad_num = 0;

  input.open ( input_filename.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "FILE_ROW_COUNT - Fatal error!\n";

    cerr << "  Could not open the input file: \"" << input_filename << "\"\n";

    return (-1);

  }

  for ( ; ; )

  {

    getline ( input, line );

    if ( input.eof ( ) )

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

  input.close ( );

  return row_num;

}

int i4_max ( int i1, int i2 )

{

  int value;

  if ( i2 < i1 )

  {

    value = i1;

  }

  else

  {

    value = i2;

  }

  return value;

}

int i4_min ( int i1, int i2 )

{

  int value;

  if ( i1 < i2 )

  {

    value = i1;

  }

  else

  {

    value = i2;

  }

  return value;

}

int i4vec_max ( int n, int a[] )

{

  int i;

  int value;

  if ( n <= 0 )

  {

    return 0;

  }

  value = a[0];

  for ( i = 1; i < n; i++ )

  {

    if ( value < a[i] )

    {

      value = a[i];

    }

  }

  return value;  

}

double i4vec_mean ( int n, int x[] )

{

  int i;

  double mean;

  mean = 0.0;

  for ( i = 0; i < n; i++ )

  {

    mean = mean + ( double ) x[i];

  }

  mean = mean / ( double ) n;

  return mean;

}

int i4vec_min ( int n, int a[] )

{

  int i;

  int value;

  if ( n <= 0 )

  {

    return 0;

  }

  value = a[0];

  for ( i = 1; i < n; i++ )

  {

    if ( a[i] < value )

    {

      value = a[i];

    }

  }

  return value; 

}

double i4vec_std ( int n, int x[] )

{

  int i;

  double mean;

  double std;

  if ( n < 2 )

  {

    std = 0.0;

  }

  else

  {

    mean = 0.0;

    for ( i = 0; i < n; i++ )

    {

      mean = mean + ( double ) x[i];

    }

    mean = mean / ( double ) n;

    std = 0.0;

    for ( i = 0; i < n; i++ )

    {

      std = std + pow ( ( double ) x[i] - mean, 2 );

    }

    std = sqrt ( std / ( double ) ( n - 1 ) );

  }

  return std;

}

double *r8mat_data_read ( string input_filename, int m, int n )

{

  bool error;

  ifstream input;

  int i;

  int j;

  string line;

  double *table;

  double *x;

  input.open ( input_filename.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R8MAT_DATA_READ - Fatal error!\n";

    cerr << "  Could not open the input file: \"" << input_filename << "\"\n";

    return NULL;

  }

  table = new double[m*n];

  x = new double[m];

  j = 0;

  while ( j < n )

  {

    getline ( input, line );

    if ( input.eof ( ) )

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

      table[i+j*m] = x[i];

    }

    j = j + 1;

  }

  input.close ( );

  delete [] x;

  return table;

}

 

void r8mat_header_read ( string input_filename, int *m, int *n )

 

{

  *m = file_column_count ( input_filename );

  if ( *m <= 0 )

  {

    cerr << "\n";

    cerr << "R8MAT_HEADER_READ - Fatal error!\n";

    cerr << "  FILE_COLUMN_COUNT failed.\n";

    *n = -1;

    return;

  }

  *n = file_row_count ( input_filename );

  if ( *n <= 0 )

  {

    cerr << "\n";

    cerr << "R8MAT_HEADER_READ - Fatal error!\n";

    cerr << "  FILE_ROW_COUNT failed.\n";

    return;

  }

  return;

}

void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo, 

  int ihi, int jhi, string title )

{

# define INCX 5

  int i;

  int i2;

  int i2hi;

  int i2lo;

  int inc;

  int j;

  int j2hi;

  int j2lo;

  if ( 0 < s_len_trim ( title ) )

  {

    cout << "\n";

    cout << title << "\n";

  }

  for ( i2lo = i4_max ( ilo, 1 ); i2lo <= i4_min ( ihi, m ); i2lo = i2lo + INCX )

  {

    i2hi = i2lo + INCX - 1;

    i2hi = i4_min ( i2hi, m );

    i2hi = i4_min ( i2hi, ihi );

    inc = i2hi + 1 - i2lo;

    cout << "\n";

    cout << "  Row: ";

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(7) << i << "       ";

    }

    cout << "\n";

    cout << "  Col\n";

    cout << "\n";

    j2lo = i4_max ( jlo, 1 );

    j2hi = i4_min ( jhi, n );

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(5) << j << " ";

      for ( i2 = 1; i2 <= inc; i2++ )

      {

        i = i2lo - 1 + i2;

        cout << setw(14) << a[(i-1)+(j-1)*m];

      }

      cout << "\n";

    }

  }

  return;

# undef INCX

}

int s_len_trim ( string s )

{

  int n;

  n = s.length ( );

  while ( 0 < n ) 

  {

    if ( s[n-1] != ' ' )

    {

      return n;

    }

    n = n - 1;

  }

  return n;

}

int s_to_i4 ( string s, int *last, bool *error )

{

  char c;

  int i;

  int isgn;

  int istate;

  int ival;

  *error = false;

  istate = 0;

  isgn = 1;

  i = 0;

  ival = 0;

  for ( ; ; ) 

  {

    c = s[i];

    i = i + 1;

    if ( istate == 0 )

    {

      if ( c == ' ' )

      {

      }

      else if ( c == '-' )

      {

        istate = 1;

        isgn = -1;

      }

      else if ( c == '+' )

      {

        istate = 1;

        isgn = + 1;

      }

      else if ( '0' <= c && c <= '9' )

      {

        istate = 2;

        ival = c - '0';

      }

      else

      {

        *error = true;

        return ival;

      }

    }

    else if ( istate == 1 )

    {

      if ( c == ' ' )

      {

      }

      else if ( '0' <= c && c <= '9' )

      {

        istate = 2;

        ival = c - '0';

      }

      else

      {

        *error = true;

        return ival;

      }

    }

    else if ( istate == 2 )

    {

      if ( '0' <= c && c <= '9' )

      {

        ival = 10 * (ival) + c - '0';

      }

      else

      {

        ival = isgn * ival;

        *last = i - 1;

        return ival;

      }

    }

  }

  if ( istate == 2 )

  {

    ival = isgn * ival;

    *last = s_len_trim ( s );

  }

  else

  {

    *error = true;

    *last = 0;

  }

  return ival;

}

double s_to_r8 ( string s, int *lchar, bool *error )

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

bool s_to_r8vec ( string s, int n, double rvec[] )

{

  int begin;

  bool error;

  int i;

  int lchar;

  int length;

  begin = 0;

  length = s.length ( );

  error = 0;

  for ( i = 0; i < n; i++ )

  {

    rvec[i] = s_to_r8 ( s.substr(begin,length), &lchar, &error );

    if ( error )

    {

      return error;

    }

    begin = begin + lchar;

    length = length - lchar;

  }

  return error;

}

int s_word_count ( string s )

{

  bool blank;

  int char_count;

  int i;

  int word_count;

  word_count = 0;

  blank = true;

  char_count = s.length ( );

  for ( i = 0; i < char_count; i++ )

  {

    if ( isspace ( s[i] ) )

    {

      blank = true;

    }

    else if ( blank )

    {

      word_count = word_count + 1;

      blank = false;

    }

  }

  return word_count;

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

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/