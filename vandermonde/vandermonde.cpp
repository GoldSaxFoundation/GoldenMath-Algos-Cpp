
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <cmath>

# include <ctime>

using namespace std;

# include "vandermonde.hpp"

double *bivand1 ( int n, double alpha[], double beta[] )

{

  double *a;

  int e;

  int e1;

  int e2;

  int i1;

  int i2;

  int ii;

  int j1;

  int j2;

  int jj;

  int n2;

  n2 = ( n * ( n + 1 ) ) / 2;

  a = new double[n2*n2];

  e1 = 0;

  e2 = 0;

  e = 0;

  for ( ii = 0; ii < n2; ii++ )

  {

    j1 = 0;

    j2 = 0;

    for ( jj = 0; jj < n2; jj++ )

    {

      if ( ii == 0 )

      {

        a[ii+jj*n2] = 1.0;

      }

      else

      {

        a[ii+jj*n2] = pow ( alpha[j1], e1 ) * pow ( beta[j2], e2 );

      }

      if ( j1 + j2 < n - 1 )

      {

        j1 = j1 + 1;

      }

      else

      {

        j1 = 0;

        j2 = j2 + 1;

      }

    }

    if ( e2 < e )

    {

      e1 = e1 - 1;

      e2 = e2 + 1;

    }

    else

    {

      e = e + 1;

      e1 = e;

      e2 = 0;

    }

  }

  return a;

}

double *dvand ( int n, double alpha[], double b[] )

{

  int j;

  int k;

  double *x;

  x = r8vec_copy_new ( n, b );

  for ( k = 0; k < n - 1; k++ )

  {

    for ( j = n - 1; k < j; j-- )

    {

      x[j] = ( x[j] - x[j-1] ) / ( alpha[j] - alpha[j-k-1] );

    }

  }

  for ( k = n - 2; 0 <= k; k-- )

  {

    for ( j = k; j < n - 1; j++ )

    {

      x[j] = x[j] - alpha[k] * x[j+1];

    }

  }

  return x;

}

double *pvand ( int n, double alpha[], double b[] )

{

  int j;

  int k;

  double *x;

  x = r8vec_copy_new ( n, b );

  for ( k = 0; k < n - 1; k++ )

  {

    for ( j = n - 1; k < j; j-- )

    {

      x[j] = x[j] - alpha[k] * x[j-1];

    }

  }

  for ( k = n - 2; 0 <= k; k-- )

  {

    for ( j = k + 1; j < n; j++ )

    {

      x[j] = x[j] / ( alpha[j] - alpha[j-k-1] );

    }

    for ( j = k; j < n - 1; j++ )

    {

      x[j] = x[j] - x[j+1];

    }

  }

  return x;

}

double *r8mat_mtv_new ( int m, int n, double a[], double x[] )

{

  int i;

  int j;

  double *y;

  y = new double[n];

  for ( j = 0; j < n; j++ )

  {

    y[j] = 0.0;

    for ( i = 0; i < m; i++ )

    {

      y[j] = y[j] + a[i+j*m] * x[i];

    }

  }

  return y;

}

double *r8mat_mv_new ( int m, int n, double a[], double x[] )

{

  int i;

  int j;

  double *y;

  y = new double[m];

  for ( i = 0; i < m; i++ )

  {

    y[i] = 0.0;

    for ( j = 0; j < n; j++ )

    {

      y[i] = y[i] + a[i+j*m] * x[j];

    }

  }

  return y;

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

double *r8vec_copy_new ( int n, double a1[] )

{

  double *a2;

  int i;

  a2 = new double[n];

  for ( i = 0; i < n; i++ )

  {

    a2[i] = a1[i];

  }

  return a2;

}

void r8vec_print ( int n, double a[], string title )

{

  int i;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  for ( i = 0; i < n; i++ )

  {

    cout << "  " << setw(8)  << i

         << ": " << setw(14) << a[i]  << "\n";

  }

  return;

}

double *r8vec_uniform_01_new ( int n, int &seed )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  double *r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8VEC_UNIFORM_01_NEW - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  r = new double[n];

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    r[i] = ( double ) ( seed ) * 4.656612875E-10;

  }

  return r;

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

double *vand1 ( int n, double x[] )

{

  double *a;

  int i;

  int j;

  a = new double[n*n];

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      if ( i == 0 && x[j] == 0.0 )

      {

        a[i+j*n] = 1.0;

      }

      else

      {

        a[i+j*n] = pow ( x[j], i );

      }

    }

  }

  return a;

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/