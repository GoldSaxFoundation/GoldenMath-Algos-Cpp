
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <fstream>

using namespace std;

# include "table_io.hpp"

int main ( );

void test01 ( );

void test02 ( );

void test03 ( );

void test04 ( );

void test05 ( );

void test06 ( );

int main ( )

{

  timestamp ( );

  cout << "\n";

  cout << "TABLE_IO_PRB\n";

  cout << "  C++ version\n";

  cout << "  Test the TABLE_IO library.\n";

  test01 ( );

  test02 ( );

  test03 ( );

  test04 ( );

  test05 ( );

  test06 ( );

  cout << "\n";

  cout << "TABLE_IO_PRB\n";

  cout << "  Normal end of execution.\n";

  cout << "\n";

  timestamp ( );

  return 0;

}

void test01 ( )

{

# define M 5

# define N 20

  int i;

  int j;

  string output_filename = "r8mat_05_00020.txt";

  double table[M*N];

  cout << "\n";

  cout << "TEST01\n";

  cout << "  R8MAT_WRITE writes an R8MAT file.\n";

  for ( i = 0; i < M; i++ )

  {

    for ( j = 0; j < N; j++ )

    {

      table[i+j*M] = ( double ) ( 100 * ( j + 1 ) + ( i + 1 ) ) / 10.0;

    }

  }

  cout << "\n";

  cout << "  Spatial dimension M = " << M << "\n";

  cout << "  Number of points N  = " << N << "\n";

  r8mat_print_some ( M, N, table, 1, 1, 5, 5, 

    "  5x5 portion of the data written to file:" );

  r8mat_transpose_print_some ( M, N, table, 1, 1, 5, 5, 

    "  5x5 portion of the TRANSPOSED data:" );

  r8mat_write ( output_filename, M, N, table );

  cout << "\n";

  cout << "  Wrote the header and data for \"" 

    << output_filename << "\"\n";

  return;

# undef M

# undef N

}

void test02 ( )

{

  string input_filename = "r8mat_05_00020.txt";

  int i;

  int j;

  int m;

  int n;

  double *table;

  cout << "\n";

  cout << "TEST02\n";

  cout << "  For data stored in an R8MAT file,\n";

  cout << "  R8MAT_HEADER_READ reads the header\n";

  cout << "  (Information about the dimension of the data)\n";

  cout << "  R8MAT_DATA_READ reads the data.\n";

  r8mat_header_read ( input_filename, m, n );

  cout << "\n";

  cout << "  Read the header of \"" << input_filename << "\".\n";

  cout << "\n";

  cout << "  Spatial dimension M = " << m << "\n";

  cout << "  Number of points N  = " << n << "\n";

  table = r8mat_data_read ( input_filename, m, n );

  cout << "\n";

  cout << "  Read the data in \"" << input_filename << "\".\n";

  r8mat_print_some ( m, n, table, 1, 1, 5, 5, 

    "  5x5 portion of data read from file:" );

  delete [] table;

  return;

}

void test03 ( )

{

# define M 5

# define N 20

  int i;

  int j;

  string output_filename = "i4mat_05_00020.txt";

  int table[M*N];

  cout << "\n";

  cout << "TEST03\n";

  cout << "  I4MAT_WRITE writes an I4MAT file.\n";

  for ( i = 0; i < M; i++ )

  {

    for ( j = 0; j < N; j++ )

    {

      table[i+j*M] = ( 100 * ( j + 1 ) + ( i + 1 ) );

    }

  }

  cout << "\n";

  cout << "  Spatial dimension M = " << M << "\n";

  cout << "  Number of points N  = " << N << "\n";

  i4mat_print_some ( M, N, table, 1, 1, 5, 5, 

    "  5 x 5 portion of data written to file:" );

  i4mat_write ( output_filename, M, N, table );

  cout << "\n";

  cout << "  Wrote the header and data for \"" 

    << output_filename << "\"\n";

  return;

# undef M

# undef N

}

void test04 ( )

{

  string input_filename = "i4mat_05_00020.txt";

  int m;

  int n;

  int *table;

  cout << "\n";

  cout << "TEST04\n";

  cout << "  For data stored in an I4MAT file,\n";

  cout << "  I4MAT_HEADER_READ reads the header\n";

  cout << "  (Information about the dimension of the data)\n";

  cout << "  I4MAT_DATA_READ reads the data.\n";

  i4mat_header_read ( input_filename, m, n );

  cout << "\n";

  cout << "  Read the header of \"" << input_filename << "\".\n";

  cout << "\n";

  cout << "  Spatial dimension M = " << m << "\n";

  cout << "  Number of points N  = " << n << "\n";

  table = i4mat_data_read (  input_filename, m, n );

  cout << "\n";

  cout << "  Read the data in \"" << input_filename << "\".\n";

  i4mat_print_some ( m, n, table, 1, 1, 5, 5, 

    "  5x5 portion of data read from file:" );

  delete [] table;

  return;

}

void test05 ( )

{

# define M 2

# define N 10

  int seed = 123456789;

  double *table;

  cout << "\n";

  cout << "TEST05\n";

  cout << "  R8MAT_UNIFORM_01 sets a random R8MAT.\n";

  cout << "\n";

  cout << "  Spatial dimension M = " << M << "\n";

  cout << "  Number of points N =  " << N << "\n";

  table = r8mat_uniform_01 ( M, N, seed );

  r8mat_print_some ( M, N, table, 1, 1, 5, 10, 

    "  5x10 portion of random real table dataset:" );

  delete [] table;

  return;

# undef M

# undef N

}

void test06 ( )

{

  int m = 6;

  int n = 4;

  int *table;

  int *table2;

  int *table3;

  cout << "\n";

  cout << "TEST06\n";

  cout << "  I4MAT_BORDER_CUT cuts off the border;\n";

  cout << "  I4MAT_BORDER_ADD adds a zero border;\n";

  cout << "\n";

  cout << "  Spatial dimension M = " << m << "\n";

  cout << "  Number of points N =  " << n << "\n";

  table = i4mat_indicator_new ( m, n );

  i4mat_print ( m, n, table, "  Initial dataset:" );

  table2 = i4mat_border_cut ( m, n, table );

  i4mat_print ( m-2, n-2, table2, "  'Cut' dataset:" );

  table3 = i4mat_border_add ( m - 2, n - 2, table2 );

  i4mat_print ( m, n, table3, "  'Added' dataset:" );

  delete [] table;

  delete [] table2;

  delete [] table3;

  return;

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/