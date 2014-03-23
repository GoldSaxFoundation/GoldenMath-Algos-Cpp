
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <cmath>

# include <ctime>

using namespace std;

# include "vandermonde.hpp"

int main ( );

void bivand1_test ( );

void dvand_test ( );

void pvand_test ( );

int main ( )

/*

  Purpose:

    MAIN is the main program for VANDERMONDE_PRB.

  Discussion:

    VANDERMONDE_TEST tests the VANDERMONDE library.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 February 2014

  Author:

    John Burkardt

*/

{

  timestamp ( );

  cout << "\n";

  cout << "VANDERMONDE_PRB\n";

  cout << "  C++ version.\n";

  cout << "  Test the VANDERMONDE library.\n";

  bivand1_test ( );

  dvand_test ( );

  pvand_test ( );

  cout << "\n";

  cout << "VANDERMONDE_PRB\n";

  cout << "  Normal end of execution.\n";

  cout << "\n";

  timestamp ( );

  return 0;

}

void bivand1_test ( )

{

# define N 3

  double *a;

  double alpha[N] = { 1.0, 2.0, 3.0 };

  double beta[N] = { 10.0, 20.0, 30.0 };

  int n = N;

  int n2;

  cout << "\n";

  cout << "BIVAND1_TEST:\n";

  cout << "  Compute a bidimensional Vandermonde matrix.\n";

  r8vec_print ( n, alpha, "  Vandermonde vector ALPHA:" );

  r8vec_print ( n, beta, "  Vandermonde vector BETA:" );

  a = bivand1 ( n, alpha, beta );

  n2 = ( n * ( n + 1 ) ) / 2;

  r8mat_print ( n2, n2, a, "  Bidimensional Vandermonde matrix:" );

  delete [] a;

  return;

# undef N

}

void dvand_test ( )

{

# define N 5

  double *a;

  double *alpha;

  double alpha1[N] = { 0.0, 1.0, 2.0, 3.0, 4.0 };

  double *b;

  int n = N;

  int seed;

  int test;

  double *x;

  double x1[N] = { 5.0, 3.0, 4.0, 1.0, 2.0 };

  cout << "\n";

  cout << "DVAND_TEST:\n";

  cout << "  Solve a Vandermonde linear system A'*x=b\n";

  for ( test = 1; test <= 2; test++ )

  {

    if ( test == 1 ) 

    {

      alpha = r8vec_copy_new ( n, alpha1 );

    }

    else if ( test == 2 )

    {

      alpha = r8vec_uniform_01_new ( n, seed );

    }

    r8vec_print ( n, alpha, "  Vandermonde vector ALPHA:" );

    a = vand1 ( n, alpha );

    x = r8vec_copy_new ( n, x1 );

    b = r8mat_mtv_new ( n, n, a, x );

    r8vec_print ( n, b, "  Right hand side B:" );

    delete [] x;

    x = dvand ( n, alpha, b );

    r8vec_print ( n, x, "  Solution X:" );

    delete [] a;

    delete [] alpha;

    delete [] b;

    delete [] x;

  }

  return;

# undef N

}

void pvand_test ( )

{

# define N 5

  double *a;

  double *alpha;

  double alpha1[N] = { 0.0, 1.0, 2.0, 3.0, 4.0 };

  double *b;

  int n = N;

  int seed;

  int test;

  double *x;

  double x1[N] = { 5.0, 3.0, 4.0, 1.0, 2.0 };

  cout << "\n";

  cout << "PVAND_TEST:\n";

  cout << "  Solve a Vandermonde linear system A*x=b\n";

  for ( test = 1; test <= 2; test++ )

  {

    if ( test == 1 )

    {

      alpha = r8vec_copy_new ( n, alpha1 );

    }

    else if ( test == 2 )

    {

      seed = 123456789;

      alpha = r8vec_uniform_01_new ( n, seed );

    }

    r8vec_print ( n, alpha, "  Vandermonde vector ALPHA:" );

    a = vand1 ( n, alpha );

    x = r8vec_copy_new ( n, x1 );

    b = r8mat_mv_new ( n, n, a, x );

    r8vec_print ( n, b, "  Right hand side B:" );

    delete [] x;

    x = pvand ( n, alpha, b );

    r8vec_print ( n, x, "  Solution X:" );

    delete [] a;

    delete [] alpha;

    delete [] b;

    delete [] x;

  }

  return;

# undef N

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/