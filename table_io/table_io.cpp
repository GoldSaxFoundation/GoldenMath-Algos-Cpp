
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <fstream>

# include <ctime>

# include <cmath>

# include <cstring>

using namespace std;

# include "table_io.hpp"

char ch_cap ( char ch )

{

  if ( 97 <= ch && ch <= 122 )

  {

    ch = ch - 32;

  }

  return ch;

}

bool ch_eqi ( char ch1, char ch2 )

{

  if ( 97 <= ch1 && ch1 <= 122 )

  {

    ch1 = ch1 - 32;

  }

  if ( 97 <= ch2 && ch2 <= 122 )

  {

    ch2 = ch2 - 32;

  }

  return ( ch1 == ch2 );

}

int ch_to_digit ( char ch )

{

  int digit;

  if ( '0' <= ch && ch <= '9' )

  {

    digit = ch - '0';

  }

  else if ( ch == ' ' )

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

    exit ( 1 );

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

    exit ( 1 );

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

int i4_log_10 ( int i )

{

  int i_abs;

  int ten_pow;

  int value;

  if ( i == 0 )

  {

    value = 0;

  }

  else

  {

    value = 0;

    ten_pow = 10;

    i_abs = abs ( i );

    while ( ten_pow <= i_abs )

    {

      value = value + 1;

      ten_pow = ten_pow * 10;

    }

  }

  return value;

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

int *i4mat_border_add ( int m, int n, int table[] )

{

  int i;

  int j;

  int *table2;

  table2 = new int[(m+2)*(n+2)];

  for ( j = 0; j < n+2; j++ )

  {

    for ( i = 0; i < m+2; i++ )

    {

      if ( i == 0 || i == m+1 || j == 0 || j == n+1 )

      {

        table2[i+j*(m+2)] = 0;

      }

      else

      {

        table2[i+j*(m+2)] = table[(i-1)+(j-1)*m];

      }

    }

  }

  return table2;

}

int *i4mat_border_cut ( int m, int n, int table[] )

{

  int i;

  int j;

  int *table2;

  if ( m <= 2 || n <= 2 )

  {

    return NULL;

  }

  table2 = new int[(m-2)*(n-2)];

  for ( j = 0; j < n-2; j++ )

  {

    for ( i = 0; i < m-2; i++ )

    {

      table2[i+j*(m-2)] = table[(i+1)+(j+1)*m];

    }

  }

  return table2;

}

int *i4mat_data_read ( string input_filename, int m, int n )

{

  bool error;

  ifstream input;

  int i;

  int j;

  string line;

  int *table;

  int *x;

  input.open ( input_filename.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "I4MAT_DATA_READ - Fatal error!\n";

    cerr << "  Could not open the input file: \"" << input_filename << "\"\n";

    exit ( 1 );

  }

  table = new int[m*n];

  x = new int[m];

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

    error = s_to_i4vec ( line, m, x );

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

void i4mat_header_read ( string input_filename, int &m, int &n )

{

  m = file_column_count ( input_filename );

  if ( m <= 0 )

  {

    cerr << "\n";

    cerr << "I4MAT_HEADER_READ - Fatal error!\n";

    cerr << "  FILE_COLUMN_COUNT failed.\n";

    exit ( 1 );

  }

  n = file_row_count ( input_filename );

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "I4MAT_HEADER_READ - Fatal error!\n";

    cerr << "  FILE_ROW_COUNT failed.\n";

    exit ( 1 );

  }

  return;

}

int *i4mat_indicator_new ( int m, int n )

{

  int fac;

  int i;

  int j;

  int *table;

  table = new int[m*n];

  fac = ( int ) pow ( 10.0, ( i4_log_10 ( n ) + 1 ) );

  for ( i = 1; i <= m; i++ )

  {

    for ( j = 1; j <= n; j++ )

    {

      table[i-1+(j-1)*m] = fac * i + j;

    }

  }

  return table;

}

void i4mat_print ( int m, int n, int a[], string title )

{

  int i;

  int j;

  int jhi;

  int jlo;

  i4mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;

}

void i4mat_print_some ( int m, int n, int a[], int ilo, int jlo, int ihi,

  int jhi, string title )

{

# define INCX 10

  int i;

  int i2hi;

  int i2lo;

  int j;

  int j2hi;

  int j2lo;

  cout << "\n";

  cout << title << "\n";

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n );

    j2hi = i4_min ( j2hi, jhi );

    cout << "\n";

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(6) << j << "  ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, m );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(5) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        cout << setw(6) << a[i-1+(j-1)*m] << "  ";

      }

      cout << "\n";

    }

  }

  return;

# undef INCX

}

int *i4mat_read ( string input_filename, int &m, int &n )

{

  int *table;

  i4mat_header_read ( input_filename, m, n );

  table = i4mat_data_read ( input_filename, m, n );

  return table;

}

void i4mat_write ( string output_filename, int m, int n, int table[] )

{

  int i;

  int j;

  ofstream output;

  output.open ( output_filename.c_str ( ) );

  if ( !output )

  {

    cerr << "\n";

    cerr << "I4MAT_WRITE - Fatal error!\n";

    cerr << "  Could not open the output file.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      output << "  " << setw(10) << table[i+j*m];

    }

    output << "\n";

  }

  output.close ( );

  return;

}

bool *lvec_data_read ( string input_filename, int n )

{

  ifstream input;

  int i;

  int j;

  int l;

  string line;

  bool *table;

  input.open ( input_filename.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "LVEC_DATA_READ - Fatal error!\n";

    cerr << "  Could not open the input file: \"" << input_filename << "\"\n";

    exit ( 1 );

  }

  table = new bool[n];

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

    table[j] = s_to_l ( line );

    j = j + 1;

  }

  input.close ( );

  return table;

}

void lvec_header_read ( string input_filename, int &n )

{

  n = file_row_count ( input_filename );

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "LVEC_HEADER_READ - Fatal error!\n";

    cerr << "  FILE_ROW_COUNT failed.\n";

    exit ( 1 );

  }

  return;

}

void lvec_write ( string output_filename, int n, bool table[] )

{

  int j;

  ofstream output;

  output.open ( output_filename.c_str ( ) );

  if ( !output )

  {

    cerr << "\n";

    cerr << "LVEC_WRITE - Fatal error!\n";

    cerr << "  Could not open the output file.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    if ( !table[j] )

    {

      output << "0\n";

    }

    else

    {

      output << "1\n";

    }

  }

  output.close ( );

  return;

}

float *r4mat_data_read ( string input_filename, int m, int n )

{

  bool error;

  ifstream input;

  int i;

  int j;

  string line;

  float *table;

  float *x;

  input.open ( input_filename.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R4MAT_DATA_READ - Fatal error!\n";

    cerr << "  Could not open the input file: \"" << input_filename << "\"\n";

    exit ( 1 );

  }

  table = new float[m*n];

  x = new float[m];

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

    error = s_to_r4vec ( line, m, x );

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

void r4mat_header_read ( string input_filename, int &m, int &n )

{

  m = file_column_count ( input_filename );

  if ( m <= 0 )

  {

    cerr << "\n";

    cerr << "R4MAT_HEADER_READ - Fatal error!\n";

    cerr << "  FILE_COLUMN_COUNT failed.\n";

    exit ( 1 );

  }

  n = file_row_count ( input_filename );

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "R4MAT_HEADER_READ - Fatal error!\n";

    cerr << "  FILE_ROW_COUNT failed.\n";

    exit ( 1 );

  }

  return;

}

float *r4mat_indicator_new ( int m, int n )

{

  int fac;

  int i;

  int j;

  float *table;

  table = new float[m*n];

  fac = ( int ) pow ( 10.0, ( i4_log_10 ( n ) + 1 ) );

  for ( i = 1; i <= m; i++ )

  {

    for ( j = 1; j <= n; j++ )

    {

      table[i-1+(j-1)*m] = ( float ) ( fac * i + j );

    }

  }

  return table;

}

void r4mat_print ( int m, int n, float a[], string title )

{

  r4mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;

}

void r4mat_print_some ( int m, int n, float a[], int ilo, int jlo, int ihi,

  int jhi, string title )

{

# define INCX 5

  int i;

  int i2hi;

  int i2lo;

  int j;

  int j2hi;

  int j2lo;

  cout << "\n";

  cout << title << "\n";

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n );

    j2hi = i4_min ( j2hi, jhi );

    cout << "\n";

    cout << "  Col:    ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, m );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(5) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        cout << setw(12) << a[i-1+(j-1)*m] << "  ";

      }

      cout << "\n";

    }

  }

  return;

# undef INCX

}

float *r4mat_read ( string input_filename, int &m, int &n )

{

  float *table;

  r4mat_header_read ( input_filename, m, n );

  table = r4mat_data_read ( input_filename, m, n );

  return table;

}

void r4mat_transpose_print ( int m, int n, float a[], string title )

{

  r4mat_transpose_print_some ( m, n, a, 1, 1, m, n, title );

  return;

}

void r4mat_transpose_print_some ( int m, int n, float a[], int ilo, int jlo,

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

  cout << "\n";

  cout << title << "\n";

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

float *r4mat_uniform_01 ( int m, int n, int &seed )

{

  int i;

  int j;

  int k;

  float *r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R4MAT_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  r = new float[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + 2147483647;

      }

      r[i+j*m] = ( float ) ( seed ) * 4.656612875E-10;

    }

  }

  return r;

}

void r4mat_write ( string output_filename, int m, int n, float table[] )

{

  int i;

  int j;

  ofstream output;

  output.open ( output_filename.c_str ( ) );

  if ( !output )

  {

    cerr << "\n";

    cerr << "R4MAT_WRITE - Fatal error!\n";

    cerr << "  Could not open the output file.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      output << "  " << setw(24) << setprecision(16) << table[i+j*m];

    }

    output << "\n";

  }

  output.close ( );

  return;

}

double *r8mat_border_add ( int m, int n, double table[] )

{

  int i;

  int j;

  double *table2;

  table2 = new double[(m+2)*(n+2)];

  for ( j = 0; j < n+2; j++ )

  {

    for ( i = 0; i < m+2; i++ )

    {

      if ( i == 0 || i == m+1 || j == 0 || j == n+1 )

      {

        table2[i+j*(m+2)] = 0.0;

      }

      else

      {

        table2[i+j*(m+2)] = table[(i-1)+(j-1)*m];

      }

    }

  }

  return table2;

}

double *r8mat_border_cut ( int m, int n, double table[] )

{

  int i;

  int j;

  double *table2;

  if ( m <= 2 || n <= 2 )

  {

    return NULL;

  }

  table2 = new double[(m-2)*(n-2)];

  for ( j = 0; j < n-2; j++ )

  {

    for ( i = 0; i < m-2; i++ )

    {

      table2[i+j*(m-2)] = table[(i+1)+(j+1)*m];

    }

  }

  return table2;

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

    exit ( 1 );

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

void r8mat_header_read ( string input_filename, int &m, int &n )

{

  m = file_column_count ( input_filename );

  if ( m <= 0 )

  {

    cerr << "\n";

    cerr << "R8MAT_HEADER_READ - Fatal error!\n";

    cerr << "  FILE_COLUMN_COUNT failed.\n";

    exit ( 1 );

  }

  n = file_row_count ( input_filename );

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "R8MAT_HEADER_READ - Fatal error!\n";

    cerr << "  FILE_ROW_COUNT failed.\n";

    exit ( 1 );

  }

  return;

}

double *r8mat_indicator_new ( int m, int n )

{

  int fac;

  int i;

  int j;

  double *table;

  table = new double[m*n];

  fac = ( int ) pow ( 10.0, ( i4_log_10 ( n ) + 1 ) );

  for ( i = 1; i <= m; i++ )

  {

    for ( j = 1; j <= n; j++ )

    {

      table[i-1+(j-1)*m] = ( double ) ( fac * i + j );

    }

  }

  return table;

}

void r8mat_print ( int m, int n, double a[], string title )

{

  r8mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;

}

void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,

  int jhi, string title )

{

# define INCX 5

  int i;

  int i2hi;

  int i2lo;

  int j;

  int j2hi;

  int j2lo;

  cout << "\n";

  cout << title << "\n";

  if ( m <= 0 || n <= 0 )

  {

    cout << "\n";

    cout << "  (None)\n";

    return;

  }

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    if ( n < j2hi )

    {

      j2hi = n;

    }

    if ( jhi < j2hi )

    {

      j2hi = jhi;

    }

    cout << "\n";

    cout << "  Col:    ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j - 1 << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "\n";

    if ( 1 < ilo )

    {

      i2lo = ilo;

    }

    else

    {

      i2lo = 1;

    }

    if ( ihi < m )

    {

      i2hi = ihi;

    }

    else

    {

      i2hi = m;

    }

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(5) << i - 1 << ": ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        cout << setw(12) << a[i-1+(j-1)*m] << "  ";

      }

      cout << "\n";

    }

  }

  return;

# undef INCX

}

double *r8mat_read ( string input_filename, int &m, int &n )

{

  double *table;

  r8mat_header_read ( input_filename, m, n );

  table = r8mat_data_read ( input_filename, m, n );

  return table;

}

void r8mat_transpose_print ( int m, int n, double a[], string title )

{

  r8mat_transpose_print_some ( m, n, a, 1, 1, m, n, title );

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

  cout << "\n";

  cout << title << "\n";

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

double *r8mat_uniform_01 ( int m, int n, int &seed )

{

  int i;

  int j;

  int k;

  double *r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8MAT_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  r = new double[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + 2147483647;

      }

      r[i+j*m] = ( double ) ( seed ) * 4.656612875E-10;

    }

  }

  return r;

}

void r8mat_write ( string output_filename, int m, int n, double table[] )

{

  int i;

  int j;

  ofstream output;

  output.open ( output_filename.c_str ( ) );

  if ( !output )

  {

    cerr << "\n";

    cerr << "R8MAT_WRITE - Fatal error!\n";

    cerr << "  Could not open the output file.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      output << "  " << setw(24) << setprecision(16) << table[i+j*m];

    }

    output << "\n";

  }

  output.close ( );

  return;

}

double *r8vec_data_read ( string input_filename, int n )

{

  bool error;

  ifstream input;

  int i;

  int j;

  int lchar;

  string line;

  double *table;

  double x;

  input.open ( input_filename.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R8VEC_DATA_READ - Fatal error!\n";

    cerr << "  Could not open the input file: \"" << input_filename << "\"\n";

    exit ( 1 );

  }

  table = new double[n];

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

    x = s_to_r8 ( line, &lchar, &error );

    if ( error )

    {

      continue;

    }

    table[j] = x;

    j = j + 1;

  }

  input.close ( );

  return table;

}

void r8vec_header_read ( string input_filename, int &n )

{

  n = file_row_count ( input_filename );

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "R8VEC_HEADER_READ - Fatal error!\n";

    cerr << "  FILE_ROW_COUNT failed.\n";

    exit ( 1 );

  }

  return;

}

void r8vec_write ( string output_filename, int n, double x[] )

{

  int j;

  ofstream output;

  output.open ( output_filename.c_str ( ) );

  if ( !output )

  {

    cerr << "\n";

    cerr << "R8VEC_WRITE - Fatal error!\n";

    cerr << "  Could not open the output file.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    output << "  " << setw(24) << setprecision(16) << x[j] << "\n";

  }

  output.close ( );

  return;

}

void r8vec2_write ( string output_filename, int n, double x[], double y[] )

{

  int j;

  ofstream output;

  output.open ( output_filename.c_str ( ) );

  if ( !output )

  {

    cerr << "\n";

    cerr << "R8VEC2_WRITE - Fatal error!\n";

    cerr << "  Could not open the output file.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    output << "  " << setw(24) << setprecision(16) << x[j] 

           << "  " << setw(24) << setprecision(16) << y[j] << "\n";

  }

  output.close ( );

  return;

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

bool s_to_i4vec ( string s, int n, int ivec[] )

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

    ivec[i] = s_to_i4 ( s.substr(begin,length), &lchar, &error );

    if ( error )

    {

      return error;

    }

    begin = begin + lchar;

    length = length - lchar;

  }

  return error;

}

bool s_to_l ( string s )

{

  int i;

  bool l;

  int length;

  length = s.length ( );

  if ( length < 1 )

  {

    cerr << "\n";

    cerr << "S_TO_L - Fatal error!\n";

    cerr << "  Input string is empty.\n";

    exit ( 1 );

  }

  for ( i = 0; i < length; i++ )

  {

    if ( s[i] == '0' ||

         s[i] == 'f' ||

         s[i] == 'F' )

    {

      l = false;

      return l;

    }

    else if ( s[i] == '1' ||

              s[i] == 't' ||

              s[i] == 'T' )

    {

      l = true;

      return l;

    }

  }

  cerr << "\n";

  cerr << "S_TO_L - Fatal error!\n";

  cerr << "  Input did not contain boolean data.\n";

  exit ( 1 );

}

float s_to_r4 ( string s, int *lchar, bool *error )

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

  float r;

  const float r4_ten = 10.0;

  float rbot;

  float rexp;

  float rtop;

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

        rtop = r4_ten * rtop + ( float ) ndig;

      }

      else if ( ihave == 5 )

      {

        rtop = r4_ten * rtop + ( float ) ndig;

        rbot = r4_ten * rbot;

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

      rexp = pow ( r4_ten, jsgn * jtop );

    }

    else

    {

      rexp = jsgn * jtop;

      rexp = rexp / jbot;

      rexp = pow ( r4_ten, rexp );

    }

  }

  r = isgn * rexp * rtop / rbot;

  return r;

}

bool s_to_r4vec ( string s, int n, float rvec[] )

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

    rvec[i] = s_to_r4 ( s.substr(begin,length), &lchar, &error );

    if ( error )

    {

      return error;

    }

    begin = begin + lchar;

    length = length - lchar;

  }

  return error;

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

  const struct std::tm *tm_ptr;

  size_t len;

  std::time_t now;

  now = std::time ( NULL );

  tm_ptr = std::localtime ( &now );

  len = std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;

# undef TIME_SIZE

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/