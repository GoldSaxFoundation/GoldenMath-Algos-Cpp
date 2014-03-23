
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <fstream>

# include <iomanip>

# include <cmath>

# include <ctime>

# include <string>

using namespace std;

int main ( int argc, char *argv[] );

char ch_cap ( char ch );

bool ch_eqi ( char ch1, char ch2 );

int ch_to_digit ( char ch );

int file_column_count ( string input_filename );

int file_row_count ( string input_filename );

int i4_max ( int i1, int i2 );

int i4_min ( int i1, int i2 );

int i4col_compare ( int m, int n, int a[], int i, int j );

void i4col_sort_a ( int m, int n, int a[] );

void i4col_sort2_a ( int m, int n, int a[] );

int i4col_sorted_unique_count ( int m, int n, int a[] );

void i4col_swap ( int m, int n, int a[], int icol1, int icol2 );

void i4i4_sort_a ( int i1, int i2, int *j1, int *j2 );

int *i4mat_data_read ( string input_filename, int m, int n );

void i4mat_header_read ( string input_filename, int *m, int *n );

void i4mat_transpose_print_some ( int m, int n, int a[], int ilo, int jlo,

  int ihi, int jhi, string title );

void i4mat_write ( string output_filename, int m, int n, int table[] );

double *r8mat_data_read ( string input_filename, int m, int n );

void r8mat_header_read ( string input_filename, int *m, int *n );

void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo,

  int ihi, int jhi, string title );

void r8mat_write ( string output_filename, int m, int n, double table[] );

int s_len_trim ( string s );

int s_to_i4 ( string s, int *last, bool *error );

bool s_to_i4vec ( string s, int n, int ivec[] );

double s_to_r8 ( string s, int *lchar, bool *error );

bool s_to_r8vec ( string s, int n, double rvec[] );

int s_word_count ( string s );

void sort_heap_external ( int n, int *indx, int *i, int *j, int isgn );

void tet_mesh_base_zero ( int node_num, int element_order, int element_num,

  int element_node[] );

void tet_mesh_order4_to_order10_compute ( int element_num, int element_node1[],

  int node_num1, double node_xyz1[], int edge_data[], int element_node2[],

  int node_num2, double node_xyz2[] );

void tet_mesh_order4_to_order10_size ( int element_num, int element_node1[],

  int node_num1, int edge_data[], int *node_num2 );

void timestamp ( );

int main ( int argc, char *argv[] )

{

  int dim_num;

  int *edge_data;

  int *element_node1;

  int *element_node2;

  int element_num;

  int element_order1;

  int element_order2 = 10;

  string input_node_filename;

  string input_element_filename;

  int node_num1;

  int node_num2;

  double *node_xyz1;

  double *node_xyz2;

  string output_node_filename;

  string output_element_filename;

  string prefix;

  cout << "\n";

  timestamp ( );

  cout << "\n";

  cout << "TET_MESH_L2Q\n";

  cout << "  C++ version\n";

  cout << "  Read a \"linear\" tet mesh and\n";

  cout << "  write out a \"quadratic\" one.\n";

  cout << "\n";

  cout << "  Read a node file of NODE_NUM1 nodes in 3 dimensions.\n";

  cout << "  Read an associated tet mesh of TETRA_NUM\n";

  cout << "  tetrahedrons, using 4 nodes per tetrahedron.\n";

  cout << "\n";

  cout << "  Create new nodes which are midpoints of sides,\n";

  cout << "  generate new node and tet mesh data for\n";

  cout << "  quadratic 10-node tetrahedrons, and write them out.\n";

  cout << "\n";

  cout << "  Compiled on " << __DATE__ << " at " << __TIME__ << ".\n";

  if ( argc <= 1 )

  {

    cout << "\n";

    cout << "TET_MESH_L2Q:\n";

    cout << "  Please enter the filename prefix.\n";

    cin >> prefix;

  }

  else

  {

    prefix = argv[1];

  }

  input_node_filename = prefix + "_nodes.txt";

  input_element_filename = prefix + "_elements.txt";

  output_node_filename = prefix + "_l2q_nodes.txt";

  output_element_filename = prefix + "_l2q_elements.txt";

  r8mat_header_read ( input_node_filename, &dim_num, &node_num1 );

  if ( dim_num != 3 )

  {

    cout << "\n";

    cout << "TET_MESH_L2Q - Fatal error!\n";

    cout << "  The spatial dimension must be 3.\n";

    exit ( 1 );

  }

  cout << "\n";

  cout << "  Read the header of \"" << input_node_filename << "\".\n";

  cout << "\n";

  cout << "  Spatial dimension = " << dim_num << "\n";

  cout << "  Number of nodes   = " << node_num1 << "\n";

  node_xyz1 = r8mat_data_read ( input_node_filename, dim_num,

    node_num1 );

  cout << "\n";

  cout << "  Read the data in \"" << input_node_filename << "\".\n";

  r8mat_transpose_print_some ( dim_num, node_num1,

    node_xyz1, 1, 1, dim_num, 5, "  First 5 nodes:" );

  i4mat_header_read ( input_element_filename, &element_order1, &element_num );

  if ( element_order1 != 4 )

  {

    cout << "\n";

    cout << "TET_MESH_L2Q - Fatal error!\n";

    cout << "  The tet mesh must have order 4.\n";

    exit ( 1 );

  }

  cout << "\n";

  cout << "  Read the header of \"" << input_element_filename << "\".\n";

  cout << "\n";

  cout << "  Tetrahedron order = " << element_order1 << "\n";

  cout << "  Number of tetras  = " << element_num << "\n";

  element_node1 = i4mat_data_read ( input_element_filename, element_order1,

    element_num );

  cout << "\n";

  cout << "  Read the data in \"" << input_element_filename << "\".\n";

  i4mat_transpose_print_some ( element_order1, element_num,

    element_node1, 1, 1, element_order1, 5, "  First 5 tetrahedrons:" );

  tet_mesh_base_zero ( node_num1, element_order1, element_num, element_node1 );

  edge_data = new int[5*6*element_num];

  tet_mesh_order4_to_order10_size ( element_num, element_node1, node_num1,

    edge_data, &node_num2 );

  cout << "  Number of quadratic nodes = " << node_num2 << "\n";

  node_xyz2 = new double[dim_num*node_num2];

  element_node2 = new int[element_order2*element_num];

  tet_mesh_order4_to_order10_compute ( element_num, element_node1, node_num1,

    node_xyz1, edge_data, element_node2, node_num2, node_xyz2 );

  r8mat_transpose_print_some ( dim_num, node_num2, node_xyz2,

    1, 1, dim_num, 5, "  First 5 quadratic nodes:" );

  i4mat_transpose_print_some ( element_order2, element_num, element_node2,

    1, 1, element_order2, 5, "  First 5 quadratic tetras" );

  r8mat_write ( output_node_filename, dim_num, node_num2, node_xyz2 );

  cout << "\n";

  cout << "  Wrote the file \"" << output_node_filename << "\".\n";

  i4mat_write ( output_element_filename, element_order2, element_num, element_node2 );

  cout << "  Wrote the file \"" << output_element_filename << "\".\n";

  delete [] edge_data;

  delete [] node_xyz1;

  delete [] node_xyz2;

  delete [] element_node1;

  delete [] element_node2;

  cout << "\n";

  cout << "TET_MESH_L2Q:\n";

  cout << "  Normal end of execution.\n";

  cout << "\n";

  timestamp ( );

  return 0;

}

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

int i4col_compare ( int m, int n, int a[], int i, int j )

{

  int k;

  if ( i < 1 )

  {

    cout << "\n";

    cout << "I4COL_COMPARE - Fatal error!\n";

    cout << "  Column index I = " << i << " is less than 1.\n";

    exit ( 1 );

  }

  if ( n < i )

  {

    cout << "\n";

    cout << "I4COL_COMPARE - Fatal error!\n";

    cout << "  N = " << n << " is less than column index I = " << i << ".\n";

    exit ( 1 );

  }

  if ( j < 1 )

  {

    cout << "\n";

    cout << "I4COL_COMPARE - Fatal error!\n";

    cout << "  Column index J = " << j << " is less than 1.\n";

    exit ( 1 );

  }

  if ( n < j )

  {

    cout << "\n";

    cout << "I4COL_COMPARE - Fatal error!\n";

    cout << "  N = " << n << " is less than column index J = " << j << ".\n";

    exit ( 1 );

  }

  if ( i == j )

  {

    return 0;

  }

  k = 1;

  while ( k <= m )

  {

    if ( a[k-1+(i-1)*m] < a[k-1+(j-1)*m] )

    {

      return (-1);

    }

    else if ( a[k-1+(j-1)*m] < a[k-1+(i-1)*m] )

    {

      return 1;

    }

    k = k + 1;

  }

  return 0;

}

void i4col_sort_a ( int m, int n, int a[] )

{

  int i;

  int indx;

  int isgn;

  int j;

  i = 0;

  indx = 0;

  isgn = 0;

  j = 0;

  for ( ; ; )

  {

    sort_heap_external ( n, &indx, &i, &j, isgn );

    if ( 0 < indx )

    {

      i4col_swap ( m, n, a, i, j );

    }

    else if ( indx < 0 )

    {

      isgn = i4col_compare ( m, n, a, i, j );

    }

    else if ( indx == 0 )

    {

      break;

    }

  }

  return;

}

void i4col_sort2_a ( int m, int n, int a[] )

{

  int col;

  int i;

  int indx;

  int isgn;

  int j;

  int row;

  int temp;

  if ( m <= 1 )

  {

    return;

  }

  if ( n <= 0 )

  {

    return;

  }

  for ( col = 0; col < n; col++ )

  {

    i = 0;

    indx = 0;

    isgn = 0;

    j = 0;

    for ( ; ; )

    {

      sort_heap_external ( m, &indx, &i, &j, isgn );

      if ( 0 < indx )

      {

        temp       = a[i-1+col*m];

        a[i-1+col*m] = a[j-1+col*m];

        a[j-1+col*m] = temp;

      }

      else if ( indx < 0 )

      {

        if ( a[j-1+col*m] < a[i-1+col*m] )

        {

          isgn = +1;

        }

        else

        {

          isgn = -1;

        }

      }

      else if ( indx == 0 )

      {

        break;

      }

    }

  }

  return;

}

int i4col_sorted_unique_count ( int m, int n, int a[] )

{

  int i;

  int j1;

  int j2;

  int unique_num;

  if ( n <= 0 )

  {

    unique_num = 0;

    return unique_num;

  }

  unique_num = 1;

  j1 = 0;

  for ( j2 = 1; j2 < n; j2++ )

  {

    for ( i = 0; i < m; i++ )

    {

      if ( a[i+j1*m] != a[i+j2*m] )

      {

        unique_num = unique_num + 1;

        j1 = j2;

        break;

      }

    }

  }

  return unique_num;

}

void i4col_swap ( int m, int n, int a[], int icol1, int icol2 )

{

# define OFFSET 1

  int i;

  int t;

  if ( icol1 - OFFSET < 0 || n-1 < icol1 - OFFSET )

  {

    cout << "\n";

    cout << "I4COL_SWAP - Fatal error!\n";

    cout << "  ICOL1 is out of range.\n";

    exit ( 1 );

  }

  if ( icol2 - OFFSET < 0 || n-1 < icol2 - OFFSET )

  {

    cout << "\n";

    cout << "I4COL_SWAP - Fatal error!\n";

    cout << "  ICOL2 is out of range.\n";

    exit ( 1 );

  }

  if ( icol1 == icol2 )

  {

    return;

  }

  for ( i = 0; i < m; i++ )

  {

    t                     = a[i+(icol1-OFFSET)*m];

    a[i+(icol1-OFFSET)*m] = a[i+(icol2-OFFSET)*m];

    a[i+(icol2-OFFSET)*m] = t;

  }

  return;

# undef OFFSET

}

void i4i4_sort_a ( int i1, int i2, int *j1, int *j2 )

{

  int k1;

  int k2;

  k1 = i1;

  k2 = i2;

  *j1 = i4_min ( k1, k2 );

  *j2 = i4_max ( k1, k2 );

  return;

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

    return NULL;

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

void i4mat_header_read ( string input_filename, int *m, int *n )

{

  *m = file_column_count ( input_filename );

  if ( *m <= 0 )

  {

    cerr << "\n";

    cerr << "I4MAT_HEADER_READ - Fatal error!\n";

    cerr << "  FILE_COLUMN_COUNT failed.\n";

    *n = -1;

    return;

  }

  *n = file_row_count ( input_filename );

  if ( *n <= 0 )

  {

    cerr << "\n";

    cerr << "I4MAT_HEADER_READ - Fatal error!\n";

    cerr << "  FILE_ROW_COUNT failed.\n";

    return;

  }

  return;

}

void i4mat_transpose_print_some ( int m, int n, int a[], int ilo, int jlo,

  int ihi, int jhi, string title )

{

# define INCX 10

  int i;

  int i2hi;

  int i2lo;

  int j;

  int j2hi;

  int j2lo;

  if ( 0 < s_len_trim ( title ) )

  {

    cout << "\n";

    cout << title << "\n";

  }

  for ( i2lo = ilo; i2lo <= ihi; i2lo = i2lo + INCX )

  {

    i2hi = i2lo + INCX - 1;

    i2hi = i4_min ( i2hi, m );

    i2hi = i4_min ( i2hi, ihi );

    cout << "\n";

    cout << "  Row: ";

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(6) << i << "  ";

    }

    cout << "\n";

    cout << "  Col\n";

    cout << "\n";

    j2lo = i4_max ( jlo, 1 );

    j2hi = i4_min ( jhi, n );

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(5) << j << "  ";

      for ( i = i2lo; i <= i2hi; i++ )

      {

        cout << setw(6) << a[i-1+(j-1)*m] << "  ";

      }

      cout << "\n";

    }

  }

  return;

# undef INCX

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

    return;

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

    return;

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

void sort_heap_external ( int n, int *indx, int *i, int *j, int isgn )

{

  static int i_save = 0;

  static int j_save = 0;

  static int k = 0;

  static int k1 = 0;

  static int n1 = 0;

  if ( *indx == 0 )

  {

    i_save = 0;

    j_save = 0;

    k = n / 2;

    k1 = k;

    n1 = n;

  }

  else if ( *indx < 0 )

  {

    if ( *indx == -2 )

    {

      if ( isgn < 0 )

      {

        i_save = i_save + 1;

      }

      j_save = k1;

      k1 = i_save;

      *indx = -1;

      *i = i_save;

      *j = j_save;

      return;

    }

    if ( 0 < isgn )

    {

      *indx = 2;

      *i = i_save;

      *j = j_save;

      return;

    }

    if ( k <= 1 )

    {

      if ( n1 == 1 )

      {

        i_save = 0;

        j_save = 0;

        *indx = 0;

      }

      else

      {

        i_save = n1;

        j_save = 1;

        n1 = n1 - 1;

        *indx = 1;

      }

      *i = i_save;

      *j = j_save;

      return;

    }

    k = k - 1;

    k1 = k;

  }

  else if ( *indx == 1 )

  {

    k1 = k;

  }

  for ( ; ; )

  {

    i_save = 2 * k1;

    if ( i_save == n1 )

    {

      j_save = k1;

      k1 = i_save;

      *indx = -1;

      *i = i_save;

      *j = j_save;

      return;

    }

    else if ( i_save <= n1 )

    {

      j_save = i_save + 1;

      *indx = -2;

      *i = i_save;

      *j = j_save;

      return;

    }

    if ( k <= 1 )

    {

      break;

    }

    k = k - 1;

    k1 = k;

  }

  if ( n1 == 1 )

  {

    i_save = 0;

    j_save = 0;

    *indx = 0;

    *i = i_save;

    *j = j_save;

  }

  else

  {

    i_save = n1;

    j_save = 1;

    n1 = n1 - 1;

    *indx = 1;

    *i = i_save;

    *j = j_save;

  }

  return;

}

void tet_mesh_base_zero ( int node_num, int element_order, int element_num,

  int element_node[] )

{

  int element;

  int node;

  int node_max;

  int node_min;

  int order;

  node_min = node_num + 1;

  node_max = -1;

  for ( element = 0; element < element_num; element++ )

  {

    for ( order = 0; order < element_order; order++ )

    {

      node = element_node[order+element*element_order];

      node_min = i4_min ( node_min, node );

      node_max = i4_max ( node_max, node );

    }

  }

  if ( node_min == 1 && node_max == node_num )

  {

    cout << "\n";

    cout << "TET_MESH_BASE_ZERO:\n";

    cout << "  The element indexing appears to be 1-based!\n";

    cout << "  This will be converted to 0-based.\n";

    for ( element = 0; element < element_num; element++ )

    {

      for ( order = 0; order < element_order; order++ )

      {

        element_node[order+element*element_order] =

          element_node[order+element*element_order] - 1;

      }

    }

  }

  else if ( node_min == 0 && node_max == node_num - 1 )

  {

    cout << "\n";

    cout << "TET_MESH_BASE_ZERO:\n";

    cout << "  The element indexing appears to be 0-based!\n";

    cout << "  No conversion is necessary.\n";

  }

  else

  {

    cout << "\n";

    cout << "TET_MESH_BASE_ZERO - Warning!\n";

    cout << "  The element indexing is not of a recognized type.\n";

  }

  return;

}

void tet_mesh_order4_to_order10_compute ( int element_num, int element_node1[],

  int node_num1, double node_xyz1[], int edge_data[], int element_node2[],

  int node_num2, double node_xyz2[] )

{

  int dim_num = 3;

  int edge;

  int i;

  int j;

  int n1;

  int n1_old;

  int n2;

  int n2_old;

  int node;

  int tetra;

  int element_order1 = 4;

  int element_order2 = 10;

  int v;

  int v1;

  int v2;

  for ( j = 0; j < node_num1; j++ )

  {

    for ( i = 0; i < dim_num; i++ )

    {

      node_xyz2[i+j*dim_num] = node_xyz1[i+j*dim_num];

    }

  }

  for ( j = 0; j < element_num; j++ )

  {

    for ( i = 0; i < element_order1; i++ )

    {

      element_node2[i+j*element_order2] = element_node1[i+j*element_order1];

    }

  }

  node = node_num1;

  n1_old = -1;

  n2_old = -1;

  for ( edge = 0; edge < 6 * element_num; edge++ )

  {

    n1 = edge_data[0+edge*5];

    n2 = edge_data[1+edge*5];

    if ( n1 != n1_old || n2 != n2_old )

    {

      if ( node_num2 <= node )

      {

        cout << "\n";

        cout << "TET_MESH_ORDER4_TO_ORDER10_COMPUTE - Fatal error!\n";

        cout << "  Node index exceeds NODE_NUM2.\n";

        exit ( 1 );

      }

      for ( i = 0; i < dim_num; i++ )

      {

        node_xyz2[i+node*dim_num] =

        ( node_xyz2[i+(n1-1)*dim_num] + node_xyz2[i+(n2-1)*dim_num] ) / 2.0;

      }

      node = node + 1;

      n1_old = n1;

      n2_old = n2;

    }

    v1 = edge_data[2+edge*5];

    v2 = edge_data[3+edge*5];

    if ( v1 == 1 && v2 == 2 )

    {

      v = 5;

    }

    else if ( v1 == 1 && v2 == 3 )

    {

      v = 6;

    }

    else if ( v1 == 1 && v2 == 4 )

    {

      v = 7;

    }

    else if ( v1 == 2 && v2 == 3 )

    {

      v = 8;

    }

    else if ( v1 == 2 && v2 == 4 )

    {

      v = 9;

    }

    else if ( v1 == 3 && v2 == 4 )

    {

      v = 10;

    }

    tetra = edge_data[4+edge*5];

    element_node2[v-1+tetra*element_order2] = node;

  }

  return;

}

void tet_mesh_order4_to_order10_size ( int element_num, int element_node1[],

  int node_num1, int edge_data[], int *node_num2 )

{

  int a;

  int b;

  int edge;

  int i;

  int j;

  int k;

  int l;

  int n1;

  int n1_old;

  int n2;

  int n2_old;

  int tetra;

  int element_order1 = 4;

  for ( tetra = 0; tetra < element_num; tetra++ )

  {

    i = element_node1[0+tetra*element_order1];

    j = element_node1[1+tetra*element_order1];

    k = element_node1[2+tetra*element_order1];

    l = element_node1[3+tetra*element_order1];

    i4i4_sort_a ( i, j, &a, &b );

    edge_data[0+(6*tetra)*5] = a;

    edge_data[1+(6*tetra)*5] = b;

    edge_data[2+(6*tetra)*5] = 1;

    edge_data[3+(6*tetra)*5] = 2;

    edge_data[4+(6*tetra)*5] = tetra;

    i4i4_sort_a ( i, k, &a, &b );

    edge_data[0+(6*tetra+1)*5] = a;

    edge_data[1+(6*tetra+1)*5] = b;

    edge_data[2+(6*tetra+1)*5] = 1;

    edge_data[3+(6*tetra+1)*5] = 3;

    edge_data[4+(6*tetra+1)*5] = tetra;

    i4i4_sort_a ( i, l, &a, &b );

    edge_data[0+(6*tetra+2)*5] = a;

    edge_data[1+(6*tetra+2)*5] = b;

    edge_data[2+(6*tetra+2)*5] = 1;

    edge_data[3+(6*tetra+2)*5] = 4;

    edge_data[4+(6*tetra+2)*5] = tetra;

    i4i4_sort_a ( j, k, &a, &b );

    edge_data[0+(6*tetra+3)*5] = a;

    edge_data[1+(6*tetra+3)*5] = b;

    edge_data[2+(6*tetra+3)*5] = 2;

    edge_data[3+(6*tetra+3)*5] = 3;

    edge_data[4+(6*tetra+3)*5] = tetra;

    i4i4_sort_a ( j, l, &a, &b );

    edge_data[0+(6*tetra+4)*5] = a;

    edge_data[1+(6*tetra+4)*5] = b;

    edge_data[2+(6*tetra+4)*5] = 2;

    edge_data[3+(6*tetra+4)*5] = 4;

    edge_data[4+(6*tetra+4)*5] = tetra;

    i4i4_sort_a ( k, l, &a, &b );

    edge_data[0+(6*tetra+5)*5] = a;

    edge_data[1+(6*tetra+5)*5] = b;

    edge_data[2+(6*tetra+5)*5] = 3;

    edge_data[3+(6*tetra+5)*5] = 4;

    edge_data[4+(6*tetra+5)*5] = tetra;

  }

  i4col_sort_a ( 5, 6*element_num, edge_data );

  *node_num2 = node_num1;

  n1_old = -1;

  n2_old = -1;

  for ( edge = 0; edge < 6 * element_num; edge++ )

  {

    n1 = edge_data[0+edge*5];

    n2 = edge_data[1+edge*5];

    if ( n1 != n1_old || n2 != n2_old )

    {

      *node_num2 = *node_num2 + 1;

      n1_old = n1;

      n2_old = n2;

    }

  }

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

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/