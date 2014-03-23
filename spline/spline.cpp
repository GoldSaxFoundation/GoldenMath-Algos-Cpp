
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <cmath>

# include <ctime>

# include <cstring>

# include <string>

using namespace std;

# include "spline.hpp"

double basis_function_b_val ( double tdata[], double tval )

{

# define NDATA 5

  int left;

  int right;

  double u;

  double yval;

  if ( tval <= tdata[0] || tdata[NDATA-1] <= tval )

  {

    yval = 0.0;

    return yval;

  }

  r8vec_bracket ( NDATA, tdata, tval, &left, &right );

  u = ( tval - tdata[left-1] ) / ( tdata[right-1] - tdata[left-1] );

  if ( tval < tdata[1] )

  {

    yval = pow ( u, 3 ) / 6.0;

  }

  else if ( tval < tdata[2] )

  {

    yval = ( ( (     - 3.0 

                 * u + 3.0 ) 

                 * u + 3.0 ) 

                 * u + 1.0 ) / 6.0;

  }

  else if ( tval < tdata[3])

  {

    yval = ( ( (     + 3.0 

                 * u - 6.0 ) 

                 * u + 0.0 ) 

                 * u + 4.0 ) / 6.0;

  }

  else if ( tval < tdata[4] )

  {

    yval = pow ( ( 1.0 - u ), 3 ) / 6.0;

  }

  return yval;

# undef NDATA

}

double basis_function_beta_val ( double beta1, double beta2, double tdata[], 

  double tval )

{

# define NDATA 5

  double a;

  double b;

  double c;

  double d;

  int left;

  int right;

  double u;

  double yval;

  if ( tval <= tdata[0] || tdata[NDATA-1] <= tval )

  {

    yval = 0.0;

    return yval;

  }

  r8vec_bracket ( NDATA, tdata, tval, &left, &right );

  u = ( tval - tdata[left-1] ) / ( tdata[right-1] - tdata[left-1] );

  if ( tval < tdata[1] )

  {

    yval = 2.0 * u * u * u;

  }

  else if ( tval < tdata[2] )

  {

    a = beta2 + 4.0 * beta1 + 4.0 * beta1 * beta1

      + 6.0 * ( 1.0 - beta1 * beta1 ) 

      - 3.0 * ( 2.0 + beta2 + 2.0 * beta1 ) 

      + 2.0 * ( 1.0 + beta2 + beta1 + beta1 * beta1 );

    b = - 6.0 * ( 1.0 - beta1 * beta1 ) 

        + 6.0 * ( 2.0 + beta2 + 2.0 * beta1 ) 

        - 6.0 * ( 1.0 + beta2 + beta1 + beta1 * beta1 );

    c = - 3.0 * ( 2.0 + beta2 + 2.0 * beta1 ) 

        + 6.0 * ( 1.0 + beta2 + beta1 + beta1 * beta1 );

    d = - 2.0 * ( 1.0 + beta2 + beta1 + beta1 * beta1 );

    yval = a + b * u + c * u * u + d * u * u * u;

  }

  else if ( tval < tdata[3] )

  {

    a = beta2 + 4.0 * beta1 + 4.0 * beta1 * beta1;

    b = - 6.0 * beta1 * ( 1.0 - beta1 * beta1 );

    c = - 3.0 * ( beta2 + 2.0 * beta1 * beta1 

      + 2.0 * beta1 * beta1 * beta1 );

    d = 2.0 * ( beta2 + beta1 + beta1 * beta1 + beta1 * beta1 * beta1 );

    yval = a + b * u + c * u * u + d * u * u * u;

  }

  else if ( tval < tdata[4] )

  {

    yval = 2.0 * pow ( beta1 * ( 1.0 - u ), 3 );

  }

  yval = yval / ( 2.0 + beta2 + 4.0 * beta1 + 4.0 * beta1 * beta1

    + 2.0 * beta1 * beta1 * beta1 );

  return yval;

# undef NDATA

}

double *basis_matrix_b_uni ( )

{

  int i;

  int j;

  double *mbasis;

  double mbasis_save[4*4] = {

    -1.0 / 6.0, 

     3.0 / 6.0, 

    -3.0 / 6.0, 

     1.0 / 6.0,

     3.0 / 6.0,

    -6.0 / 6.0,

     0.0,

     4.0 / 6.0,

    -3.0 / 6.0,

     3.0 / 6.0,

     3.0 / 6.0,

     1.0 / 6.0,

     1.0 / 6.0,

     0.0,

     0.0,

     0.0 };

  mbasis = new double[4*4];

  for ( j = 0; j < 4; j++ )

  {

    for ( i = 0; i < 4; i++ )

    {

      mbasis[i+j*4] = mbasis_save[i+j*4];

    }

  }

  return mbasis;

}

double *basis_matrix_beta_uni ( double beta1, double beta2 )

{

  double delta;

  int i;

  int j;

  double *mbasis;

  mbasis = new double[4*4];

  mbasis[0+0*4] = - 2.0 * beta1 * beta1 * beta1;

  mbasis[0+1*4] =   2.0 * beta2 

    + 2.0 * beta1 * ( beta1 * beta1 + beta1 + 1.0 );

  mbasis[0+2*4] = - 2.0 * ( beta2 + beta1 * beta1 + beta1 + 1.0 );

  mbasis[0+3*4] =   2.0;

  mbasis[1+0*4] =   6.0 * beta1 * beta1 * beta1;

  mbasis[1+1*4] = - 3.0 * beta2 

    - 6.0 * beta1 * beta1 * ( beta1 + 1.0 );

  mbasis[1+2*4] =   3.0 * beta2 + 6.0 * beta1 * beta1;

  mbasis[1+3*4] =   0.0;

  mbasis[2+0*4] = - 6.0 * beta1 * beta1 * beta1;

  mbasis[2+1*4] =   6.0 * beta1 * ( beta1 - 1.0 ) * ( beta1 + 1.0 );

  mbasis[2+2*4] =   6.0 * beta1;

  mbasis[2+3*4] =   0.0;

  mbasis[3+0*4] =   2.0 * beta1 * beta1 * beta1;

  mbasis[3+1*4] =   4.0 * beta1 * ( beta1 + 1.0 ) + beta2;

  mbasis[3+2*4] =   2.0;

  mbasis[3+3*4] =   0.0;

  delta = ( ( 2.0   

    * beta1 + 4.0 ) 

    * beta1 + 4.0 ) 

    * beta1 + 2.0 + beta2;

  for ( j = 0; j < 4; j++ )

  {

    for ( i = 0; i < 4; i++ )

    {

      mbasis[i+j*4] = mbasis[i+j*4] / delta;

    }

  }

  return mbasis;

}

double *basis_matrix_bezier ( )

{

  double *mbasis;

  mbasis = new double[4*4];

  mbasis[0+0*4] = -1.0;

  mbasis[0+1*4] =  3.0;

  mbasis[0+2*4] = -3.0;

  mbasis[0+3*4] =  1.0;

  mbasis[1+0*4] =  3.0;

  mbasis[1+1*4] = -6.0;

  mbasis[1+2*4] =  3.0;

  mbasis[1+3*4] =  0.0;

  mbasis[2+0*4] = -3.0;

  mbasis[2+1*4] =  3.0;

  mbasis[2+2*4] =  0.0;

  mbasis[2+3*4] =  0.0;

  mbasis[3+0*4] =  1.0;

  mbasis[3+1*4] =  0.0;

  mbasis[3+2*4] =  0.0;

  mbasis[3+3*4] =  0.0;

  return mbasis;

}

double *basis_matrix_hermite ( )

{

  double *mbasis;

  mbasis = new double[4*4];

  mbasis[0+0*4] =  2.0;

  mbasis[0+1*4] = -2.0;

  mbasis[0+2*4] =  1.0;

  mbasis[0+3*4] =  1.0;

  mbasis[1+0*4] = -3.0;

  mbasis[1+1*4] =  3.0;

  mbasis[1+2*4] = -2.0;

  mbasis[1+3*4] = -1.0;

  mbasis[2+0*4] =  0.0;

  mbasis[2+1*4] =  0.0;

  mbasis[2+2*4] =  1.0;

  mbasis[2+3*4] =  0.0;

  mbasis[3+0*4] =  1.0;

  mbasis[3+1*4] =  0.0;

  mbasis[3+2*4] =  0.0;

  mbasis[3+3*4] =  0.0;

  return mbasis;

}

double *basis_matrix_overhauser_nonuni ( double alpha, double beta )

{

  double *mbasis;

  mbasis = new double[4*4];

  mbasis[0+0*4] = - ( 1.0 - alpha ) * ( 1.0 - alpha ) / alpha;

  mbasis[0+1*4] =   beta + ( 1.0 - alpha ) / alpha;

  mbasis[0+2*4] =   alpha - 1.0 / ( 1.0 - beta );

  mbasis[0+3*4] =   beta * beta / ( 1.0 - beta );

  mbasis[1+0*4] =   2.0 * ( 1.0 - alpha ) * ( 1.0 - alpha ) / alpha;

  mbasis[1+1*4] = ( - 2.0 * ( 1.0 - alpha ) - alpha * beta ) / alpha;

  mbasis[1+2*4] = ( 2.0 * ( 1.0 - alpha ) 

    - beta * ( 1.0 - 2.0 * alpha ) ) / ( 1.0 - beta );

  mbasis[1+3*4] = - beta * beta / ( 1.0 - beta );

  mbasis[2+0*4] = - ( 1.0 - alpha ) * ( 1.0 - alpha ) / alpha;

  mbasis[2+1*4] =   ( 1.0 - 2.0 * alpha ) / alpha;

  mbasis[2+2*4] =   alpha;

  mbasis[2+3*4] =   0.0;

  mbasis[3+0*4] =   0.0;

  mbasis[3+1*4] =   1.0;

  mbasis[3+2*4] =   0.0;

  mbasis[3+3*4] =   0.0;

  return mbasis;

}

double *basis_matrix_overhauser_nul ( double alpha )

{

  double *mbasis;

  mbasis = new double[3*3];

  mbasis[0+0*3] =   1.0 / alpha;

  mbasis[0+1*3] = - 1.0 / ( alpha * ( 1.0 - alpha ) );

  mbasis[0+2*3] =   1.0 / ( 1.0 - alpha );

  mbasis[1+0*3] = - ( 1.0 + alpha ) / alpha;

  mbasis[1+1*3] =   1.0 / ( alpha * ( 1.0 - alpha ) );

  mbasis[1+2*3] = - alpha / ( 1.0 - alpha );

  mbasis[2+0*3] =   1.0;

  mbasis[2+1*3] =   0.0;

  mbasis[2+2*3] =   0.0;

  return mbasis;

}

double *basis_matrix_overhauser_nur ( double beta )

{

  double *mbasis;

  mbasis = new double[3*3];

  mbasis[0+0*3] =   1.0 / beta;

  mbasis[0+1*3] = - 1.0 / ( beta * ( 1.0 - beta ) );

  mbasis[0+2*3] =   1.0 / ( 1.0 - beta );

  mbasis[1+0*3] = - ( 1.0 + beta ) / beta;

  mbasis[1+1*3] =   1.0 / ( beta * ( 1.0 - beta ) );

  mbasis[1+2*3] = - beta / ( 1.0 - beta );

  mbasis[2+0*3] =   1.0;

  mbasis[2+1*3] =   0.0;

  mbasis[2+2*3] =   0.0;

  return mbasis;

}

double *basis_matrix_overhauser_uni ( void)

{

  double *mbasis;

  mbasis = new double[4*4];

  mbasis[0+0*4] = - 1.0 / 2.0;

  mbasis[0+1*4] =   3.0 / 2.0;

  mbasis[0+2*4] = - 3.0 / 2.0;

  mbasis[0+3*4] =   1.0 / 2.0;

  mbasis[1+0*4] =   2.0 / 2.0;

  mbasis[1+1*4] = - 5.0 / 2.0;

  mbasis[1+2*4] =   4.0 / 2.0;

  mbasis[1+3*4] = - 1.0 / 2.0;

  mbasis[2+0*4] = - 1.0 / 2.0;

  mbasis[2+1*4] =   0.0;

  mbasis[2+2*4] =   1.0 / 2.0;

  mbasis[2+3*4] =   0.0;

  mbasis[3+0*4] =   0.0;

  mbasis[3+1*4] =   2.0 / 2.0;

  mbasis[3+2*4] =   0.0;

  mbasis[3+3*4] =   0.0;

  return mbasis;

}

double *basis_matrix_overhauser_uni_l ( )

{

  double *mbasis;

  mbasis = new double[3*3];

  mbasis[0+0*3] =   2.0;

  mbasis[0+1*3] = - 4.0;

  mbasis[0+2*3] =   2.0;

  mbasis[1+0*3] = - 3.0;

  mbasis[1+1*3] =   4.0;

  mbasis[1+2*3] = - 1.0;

  mbasis[2+0*3] =   1.0;

  mbasis[2+1*3] =   0.0;

  mbasis[2+2*3] =   0.0;

  return mbasis;

}

double *basis_matrix_overhauser_uni_r ( )

{

  double *mbasis;

  mbasis = new double[3*3];

  mbasis[0+0*3] =   2.0;

  mbasis[0+1*3] = - 4.0;

  mbasis[0+2*3] =   2.0;

  mbasis[1+0*3] = - 3.0;

  mbasis[1+1*3] =   4.0;

  mbasis[1+2*3] = - 1.0;

  mbasis[2+0*3] =   1.0;

  mbasis[2+1*3] =   0.0;

  mbasis[2+2*3] =   0.0;

  return mbasis;

}

double basis_matrix_tmp ( int left, int n, double mbasis[], int ndata, 

  double tdata[], double ydata[], double tval )

{

  double arg;

  int first;

  int i;

  int j;

  double tm;

  double *tvec;

  double yval;

  tvec = new double[n];

  if ( left == 1 )

  {

    arg = 0.5 * ( tval - tdata[left-1] );

    first = left;

  }

  else if ( left < ndata - 1 )

  {

    arg = tval - tdata[left-1];

    first = left - 1;

  }

  else if ( left == ndata - 1 )

  {

    arg = 0.5 * ( 1.0 + tval - tdata[left-1] );

    first = left - 1;

  }

  tvec[n-1] = 1.0;

  for ( i = n-2; 0 <= i; i-- )

  {

    tvec[i] = arg * tvec[i+1];

  }

  yval = 0.0;

  for ( j = 0; j < n; j++ )

  {

    tm = 0.0;

    for ( i = 0; i < n; i++ )

    {

      tm = tm + tvec[i] * mbasis[i+j*n];

    }

    yval = yval + tm * ydata[first - 1 + j];

  }

  delete [] tvec;

  return yval;

}

void bc_val ( int n, double t, double xcon[], double ycon[], double *xval,

  double *yval )

{

  double *bval;

  int i;

  bval = bp01 ( n, t );

  *xval = 0.0;

  for ( i = 0; i <= n; i++ )

  {

    *xval = *xval + xcon[i] * bval[i];

  }

  *yval = 0.0;

  for ( i = 0; i <= n; i++ )

  {

    *yval = *yval + ycon[i] * bval[i];

  }

  delete [] bval;

  return;

}

double bez_val ( int n, double x, double a, double b, double y[] )

{

  double *bval;

  int i;

  double value;

  double x01;

  if ( b - a == 0.0 )

  {

    cerr << "\n";

    cerr << "BEZ_VAL - Fatal error!\n";

    cerr << "  Null interval, A = B = " << a << "\n";

    exit ( 1 );

  }

  x01 = ( x - a ) / ( b - a );

  bval = bp01 ( n, x01 );

  value = 0.0;

  for ( i = 0; i <= n; i++ )

  {

    value = value + y[i] * bval[i];

  }

  delete [] bval;

  return value;

}

double bpab_approx ( int n, double a, double b, double ydata[], double xval )

{

  double *bvec;

  int i;

  double yval;

  bvec = bpab ( n, a, b, xval );

  yval = 0.0;

  for ( i = 0; i <= n; i++ )

  {

    yval = yval + ydata[i] * bvec[i];

  }

  delete [] bvec;

  return yval;

}

double *bp01 ( int n, double x )

{

  double *bern;

  int i;

  int j;

  bern = new double[n+1];

  if ( n == 0 )

  {

    bern[0] = 1.0;

  }

  else if ( 0 < n )

  {

    bern[0] = 1.0 - x;

    bern[1] = x;

    for ( i = 2; i <= n; i++ )

    {

      bern[i] = x * bern[i-1];

      for ( j = i-1; 1 <= j; j-- )

      {

        bern[j] = x * bern[j-1] + ( 1.0 - x ) * bern[j];

      }

      bern[0] = ( 1.0 - x ) * bern[0];

    }

  }

  return bern;

}

double *bpab ( int n, double a, double b, double x )

{

  double *bern;

  int i;

  int j;

  if ( b == a )

  {

    cerr << "\n";

    cerr << "BPAB - Fatal error!\n";

    cerr << "  A = B = " << a << "\n";

    exit ( 1 );

  }

  bern = new double[n+1];

  if ( n == 0 )

  {

    bern[0] = 1.0;

  }

  else if ( 0 < n )

  {

    bern[0] = ( b - x ) / ( b - a );

    bern[1] = ( x - a ) / ( b - a );

    for ( i = 2; i <= n; i++ )

    {

      bern[i] = ( x - a ) * bern[i-1] / ( b - a );

      for ( j = i-1; 1 <= j; j-- )

      {

        bern[j] = ( ( b - x ) * bern[j] + ( x - a ) * bern[j-1] ) / ( b - a );

      }

      bern[0] = ( b - x ) * bern[0] / ( b - a );

    }

  }

  return bern;

}

int chfev ( double x1, double x2, double f1, double f2, double d1, double d2,

  int ne, double xe[], double fe[], int next[] )

{

  double c2;

  double c3;

  double del1;

  double del2;

  double delta;

  double h;

  int i;

  int ierr;

  double x;

  double xma;

  double xmi;

  if ( ne < 1 )

  {

    ierr = -1;

    cerr << "\n";

    cerr << "CHFEV - Fatal error!\n";

    cerr << "  Number of evaluation points is less than 1.\n";

    cerr << "  NE = " << ne << "\n";

    return ierr;

  }

  h = x2 - x1;

  if ( h == 0.0 )

  {

    ierr = -2;

    cerr << "\n";

    cerr << "CHFEV - Fatal error!\n";

    cerr << "  The interval [X1,X2] is of zero length.\n";

    return ierr;

  }

  ierr = 0;

  next[0] = 0;

  next[1] = 0;

  xmi = r8_min ( 0.0, h );

  xma = r8_max ( 0.0, h );

  delta = ( f2 - f1 ) / h;

  del1 = ( d1 - delta ) / h;

  del2 = ( d2 - delta ) / h;

  c2 = -( del1 + del1 + del2 );

  c3 = ( del1 + del2 ) / h;

  for ( i = 0; i < ne; i++ )

  {

    x = xe[i] - x1;

    fe[i] = f1 + x * ( d1 + x * ( c2 + x * c3 ) );

    if ( x < xmi )

    {

      next[0] = next[0] + 1;

    }

    if ( xma < x )

    {

      next[1] = next[1] + 1;

    }

  }

  return 0;

}

double *d3_mxv ( int n, double a[], double x[] )

{

  double *b;

  int i;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] =        a[1+i*3] * x[i];

  }

  for ( i = 0; i < n-1; i++ )

  {

    b[i] = b[i] + a[0+(i+1)*3] * x[i+1];

  }

  for ( i = 1; i < n; i++ )

  {

    b[i] = b[i] + a[2+(i-1)*3] * x[i-1];

  }

  return b;

}

double *d3_np_fs ( int n, double a[], double b[] )

{

  int i;

  double *x;

  double xmult;

  for ( i = 0; i < n; i++ )

  {

    if ( a[1+i*3] == 0.0 )

    {

      return NULL;

    }

  }

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  for ( i = 1; i < n; i++ )

  {

    xmult = a[2+(i-1)*3] / a[1+(i-1)*3];

    a[1+i*3] = a[1+i*3] - xmult * a[0+i*3];

    x[i] = x[i] - xmult * x[i-1];

  }

  x[n-1] = x[n-1] / a[1+(n-1)*3];

  for ( i = n-2; 0 <= i; i-- )

  {

    x[i] = ( x[i] - a[0+(i+1)*3] * x[i+1] ) / a[1+i*3];

  }

  return x;

}

void d3_print ( int n, double a[], string title )

{

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  d3_print_some ( n, a, 1, 1, n, n );

  return;

}

void d3_print_some ( int n, double a[], int ilo, int jlo, int ihi, int jhi )

{

# define INCX 5

  int i;

  int i2hi;

  int i2lo;

  int inc;

  int j;

  int j2;

  int j2hi;

  int j2lo;

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n );

    j2hi = i4_min ( j2hi, jhi );

    inc = j2hi + 1 - j2lo;

    cout << "\n";

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      j2 = j + 1 - j2lo;

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2lo = i4_max ( i2lo, j2lo - 1 );

    i2hi = i4_min ( ihi, n );

    i2hi = i4_min ( i2hi, j2hi + 1 );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(6) << i << "  ";

      for ( j2 = 1; j2 <= inc; j2++ )

      {

        j = j2lo - 1 + j2;

        if ( 1 < i-j || 1 < j-i )

        {

          cout << "              ";

        }

        else if ( j == i+1 )

        {

          cout << setw(12) << a[0+(j-1)*3] << "  ";

        }

        else if ( j == i )

        {

          cout << setw(12) << a[1+(j-1)*3] << "  ";

        }

        else if ( j == i-1 )

        {

          cout << setw(12) << a[2+(j-1)*3] << "  ";

        }

      }

      cout << "\n";

    }

  }

  return;

# undef INCX

}

double *d3_uniform ( int n, int *seed )

{

  double *a;

  int i;

  double *u;

  double *v;

  double *w;

  a = new double[3*n];

  u = r8vec_uniform_new ( n-1, 0.0, 1.0, seed );

  v = r8vec_uniform_new ( n,   0.0, 1.0, seed );

  w = r8vec_uniform_new ( n-1, 0.0, 1.0, seed );

  a[0+0*3] = 0.0;

  for ( i = 1; i < n; i++ )

  {

    a[0+i*3] = u[i-1];

  }

   for ( i = 0; i < n; i++ )

  {

    a[1+i*3] = v[i];

  }

  for ( i = 0; i < n-1; i++ )

  {

    a[2+i*3] = w[i];

  }

  a[2+(n-1)*3] = 0.0;

  delete [] u;

  delete [] v;

  delete [] w;

  return a;

}

void data_to_dif ( int ntab, double xtab[], double ytab[], double diftab[] )

{

  int i;

  int j;

  for ( i = 0; i < ntab; i++ )

  {

    diftab[i] = ytab[i];

  }

  for ( i = 0; i < ntab; i++ )

  {

    for ( j = i+1; j < ntab; j++ )

    {

      if ( xtab[i] - xtab[j] == 0.0 )

      {

        cerr << "\n";

        cerr << "DATA_TO_DIF - Fatal error!\n";

        cerr << "  Two entries of XTAB are equal!\n";

        cerr << "  XTAB[" << i << "] = " << xtab[i] << "\n";

        cerr << "  XTAB[" << j << "] = " << xtab[j] << "\n";

        exit ( 1 );

      }

    }

  }

  for ( i = 1; i <= ntab-1; i++ )

  {

    for ( j = ntab-1; i <= j; j-- )

    {

      diftab[j] = ( diftab[j] - diftab[j-1] ) / ( xtab[j] - xtab[j-i] );

    }

  }

 

  return;

}

double dif_val ( int ntab, double xtab[], double diftab[], double xval )

{

  int i;

  double value;

  value = diftab[ntab-1];

  for ( i = 2; i <= ntab; i++ )

  {

    value = diftab[ntab-i] + ( xval - xtab[ntab-i] ) * value;

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

void least_set ( int point_num, double x[], double f[], double w[], 

  int nterms, double b[], double c[], double d[] )

{

  int i;

  int j;

  int k;

  double p;

  double *pj;

  double *pjm1;

  double *s;

  double tol = 0.0;

  int unique_num;

  unique_num = r8vec_unique_count ( point_num, x, tol );

  if ( unique_num < nterms )

  {

    cerr << "\n";

    cerr << "LEAST_SET - Fatal error!\n";

    cerr << "  The number of distinct X values must be\n";

    cerr << "  at least NTERMS = " << nterms << "\n";

    cerr << "  but the input data has only " << unique_num << "\n";

    cerr << "  distinct entries.\n";

    return;

  }

  for ( i = 0; i < point_num; i++ )

  {

    if ( w[i] <= 0.0 )

    {

      cerr << "\n";

      cerr << "LEAST_SET - Fatal error!\n";

      cerr << "  All weights W must be positive,\n";

      cerr << "  but weight " << i << "\n";

      cerr << "  is " << w[i] << "\n";

      return;

    }

  }

  s = new double[nterms];

  r8vec_zero ( nterms, b );

  r8vec_zero ( nterms, c );

  r8vec_zero ( nterms, d );

  r8vec_zero ( nterms, s );

  pjm1 = new double[point_num];

  pj = new double[point_num];

  r8vec_zero ( point_num, pjm1 );

  for ( i = 0; i < point_num; i++ )

  {

    pj[i] = 1.0;

  }

  for ( j = 1; j <= nterms; j++ )

  {

    for ( k = 0; k < point_num; k++ )

    {

      d[j-1] = d[j-1] + w[k] * f[k] * pj[k];

      b[j-1] = b[j-1] + w[k] * x[k] * pj[k] * pj[k];

      s[j-1] = s[j-1] + w[k] * pj[k] * pj[k];

    }

    d[j-1] = d[j-1] / s[j-1];

    if ( j == nterms )

    {

      c[j-1] = 0.0;

      break;

    }

    b[j-1] = b[j-1] / s[j-1];

    if ( j == 1 )

    {

      c[j-1] = 0.0;

    }

    else

    {

      c[j-1] = s[j-1] / s[j-2];

    }

    for ( i = 1; i <= point_num; i++ )

    {

      p = pj[i-1];

      pj[i-1] = ( x[i-1] - b[j-1] ) * pj[i-1] - c[j-1] * pjm1[i-1];

      pjm1[i-1] = p;

    }

  }

  delete [] pj;

  delete [] pjm1;

  delete [] s;

  return;

}

double least_val ( int nterms, double b[], double c[], double d[], 

  double x )

{

  int i;

  double prev;

  double prev2;

  double px;

  px = d[nterms-1];

  prev = 0.0;

  for ( i = nterms-1; 1 <= i; i-- )

  {

    prev2 = prev;

    prev = px;

    if ( i == nterms-1 )

    {

      px = d[i-1] + ( x - b[i-1] ) * prev;

    }

    else

    {

      px = d[i-1] + ( x - b[i-1] ) * prev - c[i] * prev2;

    }

  }

  return px;

}

void least_val2 ( int nterms, double b[], double c[], double d[], double x, 

  double *px, double *pxp )

{

  int i;

  double pxm1;

  double pxm2;

  double pxpm1;

  double pxpm2;

  *px = d[nterms-1];

  *pxp = 0.0;

  pxm1 = 0.0;

  pxpm1 = 0.0;

  for ( i = nterms-1; 1 <= i; i-- )

  {

    pxm2 = pxm1;

    pxpm2 = pxpm1;

    pxm1 = *px;

    pxpm1 = *pxp;

    if ( i == nterms-1 )

    {

      *px = d[i-1] + ( x - b[i-1] ) * pxm1;

      *pxp = pxm1  + ( x - b[i-1] ) * pxpm1;

    }

    else

    {

      *px = d[i-1] + ( x - b[i-1] ) * pxm1  - c[i] * pxm2;

      *pxp = pxm1  + ( x - b[i-1] ) * pxpm1 - c[i] * pxpm2;

    }

  }

  return;

}

void least_set_old ( int ntab, double xtab[], double ytab[], int ndeg, 

  double ptab[], double b[], double c[], double d[], double *eps, int *ierror )

{

  int B_OFFSET = -1;

  int D_OFFSET = -2;

  int i;

  int i0l1;

  int i1l1;

  int it;

  int k;

  int mdeg;

  double rn0;

  double rn1;

  double s;

  double sum2;

  double y_sum;

  double *ztab;

  *ierror = 0;

  ztab = new double[2*ntab];

  if ( ndeg < 1 )

  {

    *ierror = 1;

    cerr << "\n";

    cerr << "LEAST_SET_OLD - Fatal error!\n";

    cerr << "  NDEG < 1.\n";

    exit ( 1 );

  }

  if ( ntab <= ndeg )

  {

    *ierror = 1;

    cerr << "\n";

    cerr << "LEAST_SET_OLD - Fatal error!\n";

    cerr << "  NTAB <= NDEG.\n";

    exit ( 1 );

  }

  for ( i = 1; i <= ntab-1; i++ )

  {

    if ( xtab[i] <= xtab[i-1] )

    {

      *ierror = 1;

      cerr << "\n";

      cerr << "LEAST_SET_OLD - Fatal error!\n";

      cerr << "  XTAB must be strictly increasing, but\n";

      cerr << "  XTAB(" << i-1 << ") = " << xtab[i-1] << "\n";

      cerr << "  XTAB(" << i   << ") = " << xtab[i]   << "\n";

      exit ( 1 );

    }

  }

  i0l1 = 0;

  i1l1 = ntab;

  y_sum = 0.0;

  for ( i = 0; i < ntab; i++ )

  {

    y_sum = y_sum + ytab[i];

  }

  rn0 = ntab;

  c[0] = y_sum / ( double ) ( ntab );

  for ( i = 0; i < ntab; i++ )

  {

    ptab[i] = y_sum / ( double ) ( ntab );

  }

  if ( ndeg == 0 )

  {

    *eps = 0.0;

    for ( i = 0; i < ntab; i++ )

    {

      *eps = *eps + pow ( ( y_sum / ( double ) ( ntab ) - ytab[i] ), 2 );

    }

    *eps = sqrt ( *eps / ( double ) ( ntab ) );

    delete [] ztab;

    return;

  }

  ztab[0] = 0.0;

  for ( i = 0; i < ntab; i++ )

  {

    ztab[0] = ztab[0] + xtab[i];

  }

  b[1+B_OFFSET] = ztab[0] / ( double ) ( ntab );

  s = 0.0;

  sum2 = 0.0;

  for ( i = 0; i < ntab; i++ )

  {

    ztab[i1l1+i] = xtab[i] - b[1+B_OFFSET];

    s = s + ztab[i1l1+i] * ztab[i1l1+i];

    sum2 = sum2 + ztab[i1l1+i] * ( ytab[i] - ptab[i] );

  }

  rn1 = s;

  c[1] = sum2 / s;

  for ( i = 0; i < ntab; i++ )

  {

    ptab[i] = ptab[i] + c[1] * ztab[i1l1+i];

  }

  if ( ndeg == 1 )

  {

    *eps = 0.0;

    for ( i = 0; i < ntab; i++ )

    {

      *eps = *eps + pow ( ( ptab[i] - ytab[i] ), 2 );

    }

    *eps = sqrt ( *eps / ( double ) ( ntab ) );

    delete [] ztab;

    return;

  }

  for ( i = 0; i < ntab; i++ )

  {

    ztab[i] = 1.0;

  }

  mdeg = 2;

  k = 2;

  for ( ; ; )

  {

    d[k+D_OFFSET] = rn1 / rn0;

    sum2 = 0.0;

    for ( i = 0; i < ntab; i++ )

    {

      sum2 = sum2 + xtab[i] * ztab[i1l1+i] * ztab[i1l1+i];

    }

    b[k+B_OFFSET] = sum2 / rn1;

    s = 0.0;

    sum2 = 0.0;

    for ( i = 0; i < ntab; i++ )

    {

      ztab[i0l1+i] = ( xtab[i] - b[k+B_OFFSET] ) * ztab[i1l1+i] 

        - d[k+D_OFFSET] * ztab[i0l1+i];

      s = s + ztab[i0l1+i] * ztab[i0l1+i];

      sum2 = sum2 + ztab[i0l1+i] * ( ytab[i] - ptab[i] );

    }

    rn0 = rn1;

    rn1 = s;

    c[k] = sum2 / rn1;

    it = i0l1;

    i0l1 = i1l1;

    i1l1 = it;

    for ( i = 0; i < ntab; i++ )

    {

      ptab[i] = ptab[i] + c[k] * ztab[i1l1+i];

    }

    if ( ndeg <= mdeg )

    {

      break;

    }

    mdeg = mdeg + 1;

    k = k + 1;

  }

  *eps = 0.0;

  for ( i = 0; i < ntab; i++ )

  {

    *eps = *eps + pow ( ( ptab[i] - ytab[i] ), 2 );

  }

  *eps = sqrt ( *eps / ( double ) ( ntab ) );

  delete [] ztab;

  return;

}

double least_val_old ( double x, int ndeg, double b[], double c[], double d[] )

{

  int B_OFFSET = -1;

  int D_OFFSET = -2;

  int k;

  double sk;

  double skp1;

  double skp2;

  double value;

  if ( ndeg <= 0 )

  {

    value = c[0];

  }

  else if ( ndeg == 1 )

  {

    value = c[0] + c[1] * ( x - b[1+B_OFFSET] );

  }

  else

  {

    skp2 = c[ndeg];

    skp1 = c[ndeg-1] + ( x - b[ndeg+B_OFFSET] ) * skp2;

    for ( k = ndeg-2; 0 <= k; k-- )

    {

      sk = c[k] + ( x - b[k+1+B_OFFSET] ) * skp1 - d[k+2+D_OFFSET] * skp2;

      skp2 = skp1;

      skp1 = sk;

    }

    value = sk;

  }

  return value;

}

void parabola_val2 ( int ndim, int ndata, double tdata[], double ydata[], 

  int left, double tval, double *yval )

{

  double dif1;

  double dif2;

  int i;

  double t1;

  double t2;

  double t3;

  double y1;

  double y2;

  double y3;

  if ( left < 1 )

  {

    cerr << "\n";

    cerr << "PARABOLA_VAL2 - Fatal error!\n";

    cerr << "  LEFT < 0.\n";

    exit ( 1 );

  }

  if ( ndata-2 < left )

  {

    cerr << "\n";

    cerr << "PARABOLA_VAL2 - Fatal error!\n";

    cerr << " NDATA-2 < LEFT.\n";

    exit ( 1 );

  }

  if ( ndim < 1 )

  {

    cerr << "\n";

    cerr << "PARABOLA_VAL2 - Fatal error!\n";

    cerr << " NDIM < 1.\n";

    exit ( 1 );

  }

  t1 = tdata[left-1];

  t2 = tdata[left];

  t3 = tdata[left+1];

  if ( t2 <= t1 || t3 <= t2 )

  {

    cerr << "\n" ;

    cerr << "PARABOLA_VAL2 - Fatal error!\n";

    cerr << "  T2 <= T1 or T3 <= T2.\n";

    cerr << "  T1 = " << t1 << "\n";

    cerr << "  T2 = " << t2 << "\n";

    cerr << "  T3 = " << t3 << "\n";

    exit ( 1 );

  }

  for ( i = 0; i < ndim; i++ )

  {

    y1 = ydata[i+(left-1)*ndim];

    y2 = ydata[i+(left  )*ndim];

    y3 = ydata[i+(left+1)*ndim];

    dif1 = ( y2 - y1 ) / ( t2 - t1 );

    dif2 =

      ( ( y3 - y1 ) / ( t3 - t1 )

      - ( y2 - y1 ) / ( t2 - t1 ) ) / ( t3 - t2 );

    yval[i] = y1 + ( tval - t1 ) * ( dif1 + ( tval - t2 ) * dif2 );

  }

  return;

}

double pchst ( double arg1, double arg2 )

{

  double value;

  if ( arg1 == 0.0 )

  {

    value = 0.0;

  }

  else if ( arg1 < 0.0 )

  {

    if ( arg2 < 0.0 )

    {

      value = 1.0;

    }

    else if ( arg2 == 0.0 )

    {

      value = 0.0;

    }

    else if ( 0.0 < arg2 )

    {

      value = -1.0;

    }

  }

  else if ( 0.0 < arg1 )

  {

    if ( arg2 < 0.0 )

    {

      value = -1.0;

    }

    else if ( arg2 == 0.0 )

    {

      value = 0.0;

    }

    else if ( 0.0 < arg2 )

    {

      value = 1.0;

    }

  }

  return value;

}

double *penta ( int n, double a1[], double a2[], double a3[], double a4[], 

  double a5[], double b[] )

{

  int i;

  double *x;

  double xmult;

  x = new double[n];

  for ( i = 1; i < n - 1; i++ )

  {

    xmult = a2[i] / a3[i-1];

    a3[i] = a3[i] - xmult * a4[i-1];

    a4[i] = a4[i] - xmult * a5[i-1];

    b[i] = b[i] - xmult * b[i-1];

    xmult = a1[i+1] / a3[i-1];

    a2[i+1] = a2[i+1] - xmult * a4[i-1];

    a3[i+1] = a3[i+1] - xmult * a5[i-1];

    b[i+1] = b[i+1] - xmult * b[i-1];

  }

  xmult = a2[n-1] / a3[n-2];

  a3[n-1] = a3[n-1] - xmult * a4[n-2];

  x[n-1] = ( b[n-1] - xmult * b[n-2] ) / a3[n-1];

  x[n-2] = ( b[n-2] - a4[n-2] * x[n-1] ) / a3[n-2];

  for ( i = n - 3; 0 <= i; i-- )

  {

    x[i] = ( b[i] - a4[i] * x[i+1] - a5[i] * x[i+2] ) / a3[i];

  }

  return x;

}

double r8_abs ( double x )

{

  double value;

  if ( 0.0 <= x )

  {

    value = + x;

  }

  else

  {

    value = - x;

  }

  return value;

}

double r8_max ( double x, double y )

{

  if ( y < x )

  {

    return x;

  } 

  else

  {

    return y;

  }

}

double r8_min ( double x, double y )

{

  if ( y < x )

  {

    return y;

  } 

  else

  {

    return x;

  }

}

double r8_uniform_01 ( int *seed )

{

  int k;

  double r;

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )

  {

    *seed = *seed + 2147483647;

  }

  r = ( double ) ( *seed ) * 4.656612875E-10;

  return r;

}

double *r8ge_fs_new ( int n, double a[], double b[] )

{

  int i;

  int ipiv;

  int j;

  int jcol;

  double piv;

  double t;

  double *x;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  for ( jcol = 1; jcol <= n; jcol++ )

  {

    piv = r8_abs ( a[jcol-1+(jcol-1)*n] );

    ipiv = jcol;

    for ( i = jcol+1; i <= n; i++ )

    {

      if ( piv < r8_abs ( a[i-1+(jcol-1)*n] ) )

      {

        piv = r8_abs ( a[i-1+(jcol-1)*n] );

        ipiv = i;

      }

    }

    if ( piv == 0.0 )

    {

      cerr << "\n";

      cerr << "R8GE_FS_NEW - Fatal error!\n";

      cerr << "  Zero pivot on step " << jcol << "\n";

      exit ( 1 );

    }

    if ( jcol != ipiv )

    {

      for ( j = 1; j <= n; j++ )

      {

        t                 = a[jcol-1+(j-1)*n];

        a[jcol-1+(j-1)*n] = a[ipiv-1+(j-1)*n];

        a[ipiv-1+(j-1)*n] = t;

      }

      t         = x[jcol-1];

      x[jcol-1] = x[ipiv-1];

      x[ipiv-1] = t;

    }

    t = a[jcol-1+(jcol-1)*n];

    a[jcol-1+(jcol-1)*n] = 1.0;

    for ( j = jcol+1; j <= n; j++ )

    {

      a[jcol-1+(j-1)*n] = a[jcol-1+(j-1)*n] / t;

    }

    x[jcol-1] = x[jcol-1] / t;

    for ( i = jcol+1; i <= n; i++ )

    {

      if ( a[i-1+(jcol-1)*n] != 0.0 )

      {

        t = - a[i-1+(jcol-1)*n];

        a[i-1+(jcol-1)*n] = 0.0;

        for ( j = jcol+1; j <= n; j++ )

        {

          a[i-1+(j-1)*n] = a[i-1+(j-1)*n] + t * a[jcol-1+(j-1)*n];

        }

        x[i-1] = x[i-1] + t * x[jcol-1];

      }

    }

  }

  for ( jcol = n; 2 <= jcol; jcol-- )

  {

    for ( i = 1; i < jcol; i++ )

    {

      x[i-1] = x[i-1] - a[i-1+(jcol-1)*n] * x[jcol-1];

    }

  }

  return x;

}

void r8vec_bracket ( int n, double x[], double xval, int *left, 

  int *right )

{

  int i;

  for ( i = 2; i <= n - 1; i++ ) 

  {

    if ( xval < x[i-1] ) 

    {

      *left = i - 1;

      *right = i;

      return;

    }

   }

  *left = n - 1;

  *right = n;

  return;

}

void r8vec_bracket3 ( int n, double t[], double tval, int *left )

{

  int high;

  int low;

  int mid;

  if ( n < 2 ) 

  {

    cerr << "\n";

    cerr << "R8VEC_BRACKET3 - Fatal error!\n";

    cerr << "  N must be at least 2.\n";

    exit ( 1 );

  }

  if ( *left < 1 || n - 1 < *left ) 

  {

    *left = ( n + 1 ) / 2;

  }

  if ( tval < t[*left] ) 

  {

    if ( *left == 1 ) 

    {

      return;

    }

    else if ( *left == 2 ) 

    {

      *left = 1;

      return;

    }

    else if ( t[*left-2] <= tval )

    {

      *left = *left - 1;

      return;

    }

    else if ( tval <= t[1] ) 

    {

      *left = 1;

      return;

    }

    low = 2;

    high = *left - 2;

    for (;;)

    {

      if ( low == high )

      {

        *left = low;

        return;

      }

      mid = ( low + high + 1 ) / 2;

      if ( t[mid-1] <= tval ) 

      {

        low = mid;

      }

      else 

      {

        high = mid - 1;

      }

    }

  }

  else if ( t[*left] < tval ) 

  {

    if ( *left == n - 1 ) 

    {

      return;

    }

    else if ( *left == n - 2 ) 

    {

      *left = *left + 1;

      return;

    }

    else if ( tval <= t[*left+1] )

    {

      *left = *left + 1;

      return;

    }

    else if ( t[n-2] <= tval ) 

    {

      *left = n - 1;

      return;

    }

    low = *left + 2;

    high = n - 2;

    for ( ; ; ) 

    {

      if ( low == high ) 

      {

        *left = low;

        return;

      }

      mid = ( low + high + 1 ) / 2;

      if ( t[mid-1] <= tval ) 

      {

        low = mid;

      }

      else 

      {

        high = mid - 1;

      }

    }

  }

  else 

  {

  }

  return;

}

double *r8vec_even_new ( int n, double alo, double ahi )

{

  double *a;

  int i;

  a = new double[n];

  if ( n == 1 )

  {

    a[0] = 0.5 * ( alo + ahi );

  }

  else

  {

    for ( i = 0; i < n; i++ )

    {

      a[i] = ( ( double ) ( n - i - 1 ) * alo

             + ( double ) (     i     ) * ahi )

             / ( double ) ( n     - 1 );

    }

  }

  return a;

}

double *r8vec_indicator_new ( int n )

{

  double *a;

  int i;

  a = new double[n];

  for ( i = 0; i <= n-1; i++ )

  {

    a[i] = ( double ) ( i + 1 );

  }

  return a;

}

int r8vec_order_type ( int n, double x[] )

{

  int i;

  int order;

  i = 0;

  for ( ; ; )

  {

    i = i + 1;

    if ( n-1 < i )

    {

      order = 0;

      return order;

    }

    if ( x[0] < x[i] )

    {

      if ( i == 1 )

      {

        order = 2;

        break;

      }

      else

      {

        order = 1;

        break;

      }

    }

    else if ( x[i] < x[0] )

    {

      if ( i == 1 )

      {

        order = 4;

        break;

      }

      else

      {

        order = 3;

        break;

      }

    }

  }

  for ( ; ; )

  {

    i = i + 1;

    if ( n - 1 < i )

    {

      break;

    }

    if ( order == 1 )

    {

      if ( x[i] < x[i-1] )

      {

        order = -1;

        break;

      }

    }

    else if ( order == 2 )

    {

      if ( x[i] < x[i-1] )

      {

        order = -1;

        break;

      }

      else if ( x[i] == x[i-1] )

      {

        order = 1;

      }

    }

    else if ( order == 3 )

    {

      if ( x[i-1] < x[i] )

      {

        order = -1;

        break;

      }

    }

    else if ( order == 4 )

    {

      if ( x[i-1] < x[i] )

      {

        order = -1;

        break;

      }

      else if ( x[i] == x[i-1] )

      {

        order = 3;

      }

    }

  }

  return order;

}

void r8vec_print ( int n, double a[], string title )

{

  int i;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  for ( i = 0; i <= n-1; i++ ) 

  {

    cout << setw(6)  << i + 1 << "  " 

         << setw(14) << a[i]  << "\n";

  }

  return;

}

void r8vec_sort_bubble_a ( int n, double a[] )

{

  int i;

  int j;

  double temp;

  for ( i = 0; i < n-1; i++ ) 

  {

    for ( j = i+1; j < n; j++ ) 

    {

      if ( a[j] < a[i] ) 

      {

        temp = a[i];

        a[i] = a[j];

        a[j] = temp;

      }

    }

  }

}

double *r8vec_uniform_new ( int n, double b, double c, int *seed )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  double *r;

  if ( *seed == 0 )

  {

    cerr << "\n";

    cerr << "R8VEC_UNIFORM_NEW - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  r = new double[n];

  for ( i = 0; i < n; i++ )

  {

    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )

    {

      *seed = *seed + i4_huge;

    }

    r[i] = b + ( c - b ) * ( double ) ( *seed ) * 4.656612875E-10;

  }

  return r;

}

int r8vec_unique_count ( int n, double a[], double tol )

{

  int i;

  int j;

  int unique_num;

  unique_num = 0;

  for ( i = 0; i < n; i++ )

  {

    unique_num = unique_num + 1;

    for ( j = 0; j < i; j++ )

    {

      if ( fabs ( a[i] - a[j] ) <= tol )

      {

        unique_num = unique_num - 1;

        break;

      }

    }

  }

  return unique_num;

}

void r8vec_zero ( int n, double a[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    a[i] = 0.0;

  }

  return;

}

double spline_b_val ( int ndata, double tdata[], double ydata[], double tval )

{

  double bval;

  int left;

  int right;

  double u;

  double yval;

  r8vec_bracket ( ndata, tdata, tval, &left, &right );

  u = ( tval - tdata[left-1] ) / ( tdata[right-1] - tdata[left-1] );

  yval = 0.0;

  bval = ( ( (     - 1.0   

               * u + 3.0 ) 

               * u - 3.0 ) 

               * u + 1.0 ) / 6.0;

  if ( 0 < left-1 )

  {

    yval = yval + ydata[left-2] * bval;

  }

  else

  {

    yval = yval + ( 2.0 * ydata[0] - ydata[1] ) * bval;

  }

  bval = ( ( (       3.0   

               * u - 6.0 ) 

               * u + 0.0 ) 

               * u + 4.0 ) / 6.0;

  yval = yval + ydata[left-1] * bval;

  bval = ( ( (     - 3.0   

               * u + 3.0 ) 

               * u + 3.0 ) 

               * u + 1.0 ) / 6.0;

  yval = yval + ydata[right-1] * bval;

  bval = pow ( u, 3 ) / 6.0;

  if ( right+1 <= ndata )

  {

    yval = yval + ydata[right] * bval;

  }

  else

  {

    yval = yval + ( 2.0 * ydata[ndata-1] - ydata[ndata-2] ) * bval;

  }

  return yval;

}

double spline_beta_val ( double beta1, double beta2, int ndata, double tdata[],

  double ydata[], double tval )

{

  double a;

  double b;

  double bval;

  double c;

  double d;

  double delta;

  int left;

  int right;

  double u;

  double yval;

  r8vec_bracket ( ndata, tdata, tval, &left, &right );

  u = ( tval - tdata[left-1] ) / ( tdata[right-1] - tdata[left-1] );

  delta = ( ( 2.0   

    * beta1 + 4.0 ) 

    * beta1 + 4.0 ) 

    * beta1 + 2.0 + beta2;

  yval = 0.0;

  bval = 2.0 * pow ( ( beta1 * ( 1.0 - u ) ), 3 )  / delta;

  if ( 0 < left-1 )

  {

    yval = yval + ydata[left-2] * bval;

  }

  else

  {

    yval = yval + ( 2.0 * ydata[0] - ydata[1] ) * bval;

  }

  a = beta2 + ( 4.0 + 4.0 * beta1 ) * beta1;

  b = - 6.0 * beta1 * ( 1.0 - beta1 ) * ( 1.0 + beta1 );

  c = ( (     - 6.0   

      * beta1 - 6.0 ) 

      * beta1 + 0.0 ) 

      * beta1 - 3.0 * beta2;

  d = ( (     + 2.0   

      * beta1 + 2.0 ) 

      * beta1 + 2.0 ) 

      * beta1 + 2.0 * beta2;

  bval = ( a + u * ( b + u * ( c + u * d ) ) ) / delta;

  yval = yval + ydata[left-1] * bval;

  a = 2.0;

  b = 6.0 * beta1;

  c = 3.0 * beta2 + 6.0 * beta1 * beta1;

  d = - 2.0 * ( 1.0 + beta2 + beta1 + beta1 * beta1 );

  bval = ( a + u * ( b + u * ( c + u * d ) ) ) / delta;

  yval = yval + ydata[right-1] * bval;

  bval = 2.0 * pow ( u, 3 ) / delta;

  if ( right+1 <= ndata )

  {

    yval = yval + ydata[right] * bval;

  }

  else

  {

    yval = yval + ( 2.0 * ydata[ndata-1] - ydata[ndata-2] ) * bval;

  }

  return yval;

}

double spline_constant_val ( int ndata, double tdata[], double ydata[], 

  double tval )

{

  int i;

  for ( i = 0; i < ndata-1; i++ )

  {

    if ( tval <= tdata[i] )

    {

      return ydata[i];

    }

  }

  return ydata[ndata-1];

}

double *spline_cubic_set ( int n, double t[], double y[], int ibcbeg, 

  double ybcbeg, int ibcend, double ybcend )

{

  double *a1;

  double *a2;

  double *a3;

  double *a4;

  double *a5;

  double *b;

  int i;

  double *ypp;

  if ( n <= 1 )

  {

    cerr << "\n";

    cerr << "SPLINE_CUBIC_SET - Fatal error!\n";

    cerr << "  The number of data points N must be at least 2.\n";

    cerr << "  The input value is " << n << ".\n";

    exit ( 1 );

  }

  for ( i = 0; i < n - 1; i++ )

  {

    if ( t[i+1] <= t[i] )

    {

      cerr << "\n";

      cerr << "SPLINE_CUBIC_SET - Fatal error!\n";

      cerr << "  The knots must be strictly increasing, but\n";

      cerr << "  T(" << i   << ") = " << t[i]   << "\n";

      cerr << "  T(" << i+1 << ") = " << t[i+1] << "\n";

      exit ( 1 );

    }

  }

  a1 = new double[n];

  a2 = new double[n];

  a3 = new double[n];

  a4 = new double[n];

  a5 = new double[n];

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    a1[i] = 0.0;

    a2[i] = 0.0;

    a3[i] = 0.0;

    a4[i] = 0.0;

    a5[i] = 0.0;

  }

   if ( ibcbeg == 0 )

  {

    b[0] = 0.0;

    a3[0] = 1.0;

    a4[0] = -1.0;

  }

  else if ( ibcbeg == 1 )

  {

    b[0] = ( y[1] - y[0] ) / ( t[1] - t[0] ) - ybcbeg;

    a3[0] = ( t[1] - t[0] ) / 3.0;

    a4[0] = ( t[1] - t[0] ) / 6.0;

  }

  else if ( ibcbeg == 2 )

  {

    b[0] = ybcbeg;

    a3[0] = 1.0;

    a4[0] = 0.0;

  }

  else if ( ibcbeg == 3 )

  {

    b[0] = 0.0;

    a3[0] = - ( t[2] - t[1] );

    a4[0] =   ( t[2]        - t[0] );

    a5[0] = - (        t[1] - t[0] );

  }

  else

  {

    cerr << "\n";

    cerr << "SPLINE_CUBIC_SET - Fatal error!\n";

    cerr << "  IBCBEG must be 0, 1 or 2.\n";

    cerr << "  The input value is " << ibcbeg << ".\n";

    exit ( 1 );

  }

  for ( i = 1; i < n-1; i++ )

  {

    b[i] = ( y[i+1] - y[i] ) / ( t[i+1] - t[i] )

      - ( y[i] - y[i-1] ) / ( t[i] - t[i-1] );

    a2[i] = ( t[i+1] - t[i]   ) / 6.0;

    a3[i] = ( t[i+1] - t[i-1] ) / 3.0;

    a4[i] = ( t[i]   - t[i-1] ) / 6.0;

  }

  if ( ibcend == 0 )

  {

    b[n-1] = 0.0;

    a2[n-1] = -1.0;

    a3[n-1] = 1.0;

  }

  else if ( ibcend == 1 )

  {

    b[n-1] = ybcend - ( y[n-1] - y[n-2] ) / ( t[n-1] - t[n-2] );

    a2[n-1] = ( t[n-1] - t[n-2] ) / 6.0;

    a3[n-1] = ( t[n-1] - t[n-2] ) / 3.0;

  }

  else if ( ibcend == 2 )

  {

    b[n-1] = ybcend;

    a2[n-1] = 0.0;

    a3[n-1] = 1.0;

  }

  else if ( ibcbeg == 3 )

  {

    b[n-1] = 0.0;

    a1[n-1] = - ( t[n-1] - t[n-2] );

    a2[n-1] =   ( t[n-1]          - t[n-3] );

    a3[n-1] = - (          t[n-2] - t[n-3] );

  }

  else

  {

    cerr << "\n";

    cerr << "SPLINE_CUBIC_SET - Fatal error!\n";

    cerr << "  IBCEND must be 0, 1 or 2.\n";

    cerr << "  The input value is " << ibcend << ".\n";

    exit ( 1 );

  }

  if ( n == 2 && ibcbeg == 0 && ibcend == 0 )

  {

    ypp = new double[2];

    ypp[0] = 0.0;

    ypp[1] = 0.0;

  }

  else

  {

    ypp = penta ( n, a1, a2, a3, a4, a5, b );

  }

  delete [] a1;

  delete [] a2;

  delete [] a3;

  delete [] a4;

  delete [] a5;

  delete [] b;

  return ypp;

}

double spline_cubic_val ( int n, double t[], double y[], double ypp[], 

  double tval, double *ypval, double *yppval )

{

  double dt;

  double h;

  int i;

  int ival;

  double yval;

  ival = n - 2;

  for ( i = 0; i < n-1; i++ )

  {

    if ( tval < t[i+1] )

    {

      ival = i;

      break;

    }

  }

  dt = tval - t[ival];

  h = t[ival+1] - t[ival];

  yval = y[ival]

    + dt * ( ( y[ival+1] - y[ival] ) / h

           - ( ypp[ival+1] / 6.0 + ypp[ival] / 3.0 ) * h

    + dt * ( 0.5 * ypp[ival]

    + dt * ( ( ypp[ival+1] - ypp[ival] ) / ( 6.0 * h ) ) ) );

  *ypval = ( y[ival+1] - y[ival] ) / h

    - ( ypp[ival+1] / 6.0 + ypp[ival] / 3.0 ) * h

    + dt * ( ypp[ival]

    + dt * ( 0.5 * ( ypp[ival+1] - ypp[ival] ) / h ) );

  *yppval = ypp[ival] + dt * ( ypp[ival+1] - ypp[ival] ) / h;

  return yval;

}

void spline_cubic_val2 ( int n, double t[], double tval, int *left, double y[], 

  double ypp[], double *yval, double *ypval, double *yppval )

{

  double dt;

  double h;

  int right;

  r8vec_bracket3 ( n, t, tval, left );

  right = *left + 1;

  dt = tval - t[*left-1];

  h = t[right-1] - t[*left-1];

  *yval = y[*left-1]

     + dt * ( ( y[right-1] - y[*left-1] ) / h

        - ( ypp[right-1] / 6.0 + ypp[*left-1] / 3.0 ) * h

     + dt * ( 0.5 * ypp[*left-1]

     + dt * ( ( ypp[right-1] - ypp[*left-1] ) / ( 6.0 * h ) ) ) );

  *ypval = ( y[right-1] - y[*left-1] ) / h

     - ( ypp[right-1] / 6.0 + ypp[*left-1] / 3.0 ) * h

     + dt * ( ypp[*left-1]

     + dt * ( 0.5 * ( ypp[right-1] - ypp[*left-1] ) / h ) );

  *yppval = ypp[*left-1] + dt * ( ypp[right-1] - ypp[*left-1] ) / h;

  return;

}

double *spline_hermite_set ( int ndata, double tdata[], double ydata[], 

  double ypdata[] )

{

  double *c;

  double divdif1;

  double divdif3;

  double dt;

  int i;

  int j;

  c = new double[4*ndata];

  for ( j = 0; j < ndata; j++ )

  {

    c[0+j*4] = ydata[j];

  }

  for ( j = 0; j < ndata; j++ )

  {

    c[1+j*4] = ypdata[j];

  }

  for ( i = 1; i <= ndata-1; i++ )

  {

    dt = tdata[i] - tdata[i-1];

    divdif1 = ( c[0+i*4] - c[0+(i-1)*4] ) / dt;

    divdif3 = c[1+(i-1)*4] + c[1+i*4] - 2.0 * divdif1;

    c[2+(i-1)*4] = ( divdif1 - c[1+(i-1)*4] - divdif3 ) / dt;

    c[3+(i-1)*4] = divdif3 / ( dt * dt );

  }

  c[2+(ndata-1)*4] = 0.0;

  c[3+(ndata-1)*4] = 0.0;

  return c;

}

void spline_hermite_val ( int ndata, double tdata[], double c[], double tval, 

  double *sval, double *spval )

{

  double dt;

  int left;

  int right;

  r8vec_bracket ( ndata, tdata, tval, &left, &right );

  dt = tval - tdata[left-1];

  *sval =        c[0+(left-1)*4] 

        + dt * ( c[1+(left-1)*4] 

        + dt * ( c[2+(left-1)*4] 

        + dt *   c[3+(left-1)*4] ) );

  *spval =             c[1+(left-1)*4] 

        + dt * ( 2.0 * c[2+(left-1)*4] 

        + dt *   3.0 * c[3+(left-1)*4] );

  return;

}

double spline_linear_int ( int ndata, double tdata[], double ydata[], 

  double a, double b )

{

  double a_copy;

  int a_left;

  int a_right;

  double b_copy;

  int b_left;

  int b_right;

  int i_left;

  double int_val;

  double tval;

  double yp;

  double yval;

  int_val = 0.0;

  if ( a == b )

  {

    return int_val;

  }

  a_copy = r8_min ( a, b );

  b_copy = r8_max ( a, b );

  r8vec_bracket ( ndata, tdata, a_copy, &a_left, &a_right );

  r8vec_bracket ( ndata, tdata, b_copy, &b_left, &b_right );

  if ( a_left == b_left )

  {

    tval = ( a_copy + b_copy ) / 2.0;

    yp = ( ydata[a_right-1] - ydata[a_left-1] ) / 

         ( tdata[a_right-1] - tdata[a_left-1] );

    yval = ydata[a_left-1] + ( tval - tdata[a_left-1] ) * yp;

    int_val = yval * ( b_copy - a_copy );

    return int_val;

  }

  tval = ( a_copy + tdata[a_right-1] ) / 2.0;

  yp = ( ydata[a_right-1] - ydata[a_left-1] ) / 

       ( tdata[a_right-1] - tdata[a_left-1] );

  yval = ydata[a_left-1] + ( tval - tdata[a_left-1] ) * yp;

  int_val = int_val + yval * ( tdata[a_right-1] - a_copy );

  for ( i_left = a_right; i_left <= b_left - 1; i_left++ )

  {

    tval = ( tdata[i_left] + tdata[i_left-1] ) / 2.0;

    yp = ( ydata[i_left-1] - ydata[i_left-2] ) / 

         ( tdata[i_left-1] - tdata[i_left-2] );

    yval = ydata[i_left-2] + ( tval - tdata[i_left-2] ) * yp;

    int_val = int_val + yval * ( tdata[i_left-1] - tdata[i_left-2] );

  }

  tval = ( tdata[b_left-1] + b_copy ) / 2.0E+0;

  yp = ( ydata[b_right-1] - ydata[b_left-1] ) / 

       ( tdata[b_right-1] - tdata[b_left-1] );

  yval = ydata[b_left-1] + ( tval - tdata[b_left-1] ) * yp;

  int_val = int_val + yval * ( b_copy - tdata[b_left-1] );

  if ( b < a )

  {

    int_val = -int_val;

  }

  return int_val;

}

void spline_linear_intset ( int n, double int_x[], double int_v[], 

  double data_x[], double data_y[] )

{

  double *a;

  double *b;

  double *c;

  int i;

  a = new double[3*n];

  b = new double[n];

  for ( i = 1; i <= n; i++ )

  {

    data_x[i-1] = 0.5 * ( int_x[i-1] + int_x[i] );

  }

  for ( i = 0; i < n-2; i++ )

  {

    a[2+i*3] = 1.0 - ( 0.5 * ( data_x[i+1] + int_x[i+1] ) 

      - data_x[i] ) / ( data_x[i+1] - data_x[i] );

  }

  a[2+(n-2)*3] = 0.0;

  a[2+(n-1)*3] = 0.0;

  a[1+0*3] = int_x[1] - int_x[0];

  for ( i = 1; i < n-1; i++ )

  {

    a[1+i*3] = 1.0 + ( 0.5 * ( data_x[i] + int_x[i] ) 

    - data_x[i-1] ) / ( data_x[i] - data_x[i-1] ) 

    - ( 0.5 * ( data_x[i] + int_x[i+1] ) - data_x[i] ) 

    / ( data_x[i+1] - data_x[i] );

  }

  a[1+(n-1)*3] = int_x[n] - int_x[n-1];

  a[0+0*3] = 0.0;

  a[0+1*3] = 0.0;

  for ( i = 2; i < n; i++ )

  {

    a[0+i*3] = ( 0.5 * ( data_x[i-1] + int_x[i] ) 

    - data_x[i-1] ) / ( data_x[i] - data_x[i-1] );

  }

  b[0] = int_v[0];

  for ( i = 2; i <= n-1; i++ )

  {

    b[i-1] = 2.0 * int_v[i-1] / ( int_x[i] - int_x[i-1] );

  }

  b[n-1] = int_v[n-1];

  c = d3_np_fs ( n, a, b );

  for ( i = 0; i < n; i++ )

  {

     data_y[i] = c[i];

  }

  delete [] a;

  delete [] b;

  delete [] c;

  return;

}

void spline_linear_val ( int ndata, double tdata[], double ydata[], 

  double tval, double *yval, double *ypval )

{

  int left;

  int right;

  r8vec_bracket ( ndata, tdata, tval, &left, &right );

  *ypval = ( ydata[right-1] - ydata[left-1] ) 

         / ( tdata[right-1] - tdata[left-1] );

  *yval = ydata[left-1] +  ( tval - tdata[left-1] ) * (*ypval);

  return;

}

double spline_overhauser_nonuni_val ( int ndata, double tdata[], 

  double ydata[], double tval )

{

  double alpha;

  double beta;

  double d21;

  double d32;

  double d43;

  int left;

  double *mbasis;

  int right;

  double yval;

  if ( ndata < 3 )

  {

    cerr << "\n";

    cerr << "SPLINE_OVERHAUSER_NONUNI_VAL - Fatal error!\n";

    cerr << "  NDATA < 3.\n";

    exit ( 1 );

  }

  r8vec_bracket ( ndata, tdata, tval, &left, &right );

  if ( left == 1 )

  {

    d21 = sqrt ( pow ( tdata[1] - tdata[0], 2 )

               + pow ( ydata[1] - ydata[0], 2 ) );

    d32 = sqrt ( pow ( tdata[2] - tdata[1], 2 )

               + pow ( ydata[2] - ydata[1], 2 ) );

    alpha = d21 / ( d32 + d21 );

    mbasis = basis_matrix_overhauser_nul ( alpha );

    yval = basis_matrix_tmp ( left, 3, mbasis, ndata, tdata, ydata, tval );

  }

  else if ( left < ndata-1 )

  {

    d21 = sqrt ( pow ( tdata[left-1] - tdata[left-2], 2 ) 

               + pow ( ydata[left-1] - ydata[left-2], 2 ) );

    d32 = sqrt ( pow ( tdata[left] - tdata[left-1], 2 ) 

               + pow ( ydata[left] - ydata[left-1], 2 ) );

    d43 = sqrt ( pow ( tdata[left+1] - tdata[left], 2 ) 

               + pow ( ydata[left+1] - ydata[left], 2 ) );

    alpha = d21 / ( d32 + d21 );

    beta  = d32 / ( d43 + d32 );

    mbasis = basis_matrix_overhauser_nonuni ( alpha, beta );

    yval = basis_matrix_tmp ( left, 4, mbasis, ndata, tdata, ydata, tval );

  }

  else if ( left == ndata-1 )

  {

    d32 = sqrt ( pow ( tdata[ndata-2] - tdata[ndata-3], 2 ) 

               + pow ( ydata[ndata-2] - ydata[ndata-3], 2 ) );

    d43 = sqrt ( pow ( tdata[ndata-1] - tdata[ndata-2], 2 ) 

               + pow ( ydata[ndata-1] - ydata[ndata-2], 2 ) );

    beta  = d32 / ( d43 + d32 );

    mbasis = basis_matrix_overhauser_nur ( beta );

    yval = basis_matrix_tmp ( left, 3, mbasis, ndata, tdata, ydata, tval );

  }

  else

  {

    cerr << "\n";

    cerr << "SPLINE_OVERHAUSER_NONUNI_VAL - Fatal error!\n";

    cerr << "  Nonsensical value of LEFT = " << left << "\n";

    cerr << "  but 0 < LEFT < NDATA = " << ndata << "\n";

    cerr << "  is required.\n";

    exit ( 1 );

  }

  delete [] mbasis;

  return yval;

}

double spline_overhauser_uni_val ( int ndata, double tdata[], double ydata[],

  double tval )

{

  int left;

  double *mbasis;

  int right;

  double yval;

  if ( ndata < 3 )

  {

    cerr << "\n";

    cerr << "SPLINE_OVERHAUSER_UNI_VAL - Fatal error!\n";

    cerr << "  NDATA < 3.\n";

    exit ( 1 );

  }

  r8vec_bracket ( ndata, tdata, tval, &left, &right );

  if ( left == 1 )

  {

    mbasis = basis_matrix_overhauser_uni_l ( );

    yval = basis_matrix_tmp ( left, 3, mbasis, ndata, tdata, ydata, tval );

  }

  else if ( left < ndata-1 )

  {

    mbasis = basis_matrix_overhauser_uni ( );

    yval = basis_matrix_tmp ( left, 4, mbasis, ndata, tdata, ydata, tval );

  }

  else if ( left == ndata-1 )

  {

    mbasis = basis_matrix_overhauser_uni_r ( );

    yval = basis_matrix_tmp ( left, 3, mbasis, ndata, tdata, ydata, tval );

  }

  delete [] mbasis;

  return yval;

}

void spline_overhauser_val ( int ndim, int ndata, double tdata[], 

  double ydata[], double tval, double yval[] )

{

  int i;

  int left;

  int order;

  int right;

  double *yl;

  double *yr;

  order = r8vec_order_type ( ndata, tdata );

  if ( order != 2 )

  {

    cerr << "\n";

    cerr << "SPLINE_OVERHAUSER_VAL - Fatal error!\n";

    cerr << "  The data abscissas are not strictly ascending.\n";

    exit ( 1 );

  }

  if ( ndata < 3 )

  {

    cerr << "\n";

    cerr << "SPLINE_OVERHAUSER_VAL - Fatal error!\n";

    cerr << "  NDATA < 3.\n";

    exit ( 1 );

  }

  r8vec_bracket ( ndata, tdata, tval, &left, &right );

  yl = new double[ndim];

  yr = new double[ndim];

  if ( 0 < left-1 )

  {

    parabola_val2 ( ndim, ndata, tdata, ydata, left-1, tval, yl );

  }

  if ( right+1 <= ndata )

  {

    parabola_val2 ( ndim, ndata, tdata, ydata, left, tval, yr );

  }

  if ( left == 1 )

  {

    for ( i = 0; i < ndim; i++ )

    {

      yval[i] = yr[i];

    }

  }

  else if ( right < ndata ) 

  {

    for ( i = 0; i < ndim; i++ )

    {

      yval[i] = (

          ( tdata[right-1] - tval                 ) * yl[i]

        + (                  tval - tdata[left-1] ) * yr[i] )

        / ( tdata[right-1]        - tdata[left-1] );

    }

  }

  else

  {

    for ( i = 0; i < ndim; i++ )

    {

      yval[i] = yl[i];

    }

  }

  delete [] yl;

  delete [] yr;

  return;

}

void spline_pchip_set ( int n, double x[], double f[], double d[] )

{

  double del1;

  double del2;

  double dmax;

  double dmin;

  double drat1;

  double drat2;

  double dsave;

  double h1;

  double h2;

  double hsum;

  double hsumt3;

  int i;

  int ierr;

  int nless1;

  double temp;

  double w1;

  double w2;

  if ( n < 2 )

  {

    ierr = -1;

    cerr << "\n";

    cerr << "SPLINE_PCHIP_SET - Fatal error!\n";

    cerr << "  Number of data points less than 2.\n";

    exit ( ierr );

  }

  for ( i = 1; i < n; i++ )

  {

    if ( x[i] <= x[i-1] )

    {

      ierr = -3;

      cerr << "\n";

      cerr << "SPLINE_PCHIP_SET - Fatal error!\n";

      cerr << "  X array not strictly increasing.\n";

      exit ( ierr );

    }

  }

  ierr = 0;

  nless1 = n - 1;

  h1 = x[1] - x[0];

  del1 = ( f[1] - f[0] ) / h1;

  dsave = del1;

  if ( n == 2 )

  {

    d[0] = del1;

    d[n-1] = del1;

    return;

  }

  h2 = x[2] - x[1];

  del2 = ( f[2] - f[1] ) / h2;

  hsum = h1 + h2;

  w1 = ( h1 + hsum ) / hsum;

  w2 = -h1 / hsum;

  d[0] = w1 * del1 + w2 * del2;

  if ( pchst ( d[0], del1 ) <= 0.0 )

  {

    d[0] = 0.0;

  }

  else if ( pchst ( del1, del2 ) < 0.0 )

  {

     dmax = 3.0 * del1;

     if ( fabs ( dmax ) < fabs ( d[0] ) )

     {

       d[0] = dmax;

     }

  }

  for ( i = 2; i <= nless1; i++ )

  {

    if ( 2 < i )

    {

      h1 = h2;

      h2 = x[i] - x[i-1];

      hsum = h1 + h2;

      del1 = del2;

      del2 = ( f[i] - f[i-1] ) / h2;

    }

    d[i-1] = 0.0;

    temp = pchst ( del1, del2 );

    if ( temp < 0.0 )

    {

      ierr = ierr + 1;

      dsave = del2;

    }

    else if ( temp == 0.0 )

    {

      if ( del2 != 0.0 )

      {

        if ( pchst ( dsave, del2 ) < 0.0 )

        {

          ierr = ierr + 1;

        }

        dsave = del2;

      }

    }

    else

    {

      hsumt3 = 3.0 * hsum;

      w1 = ( hsum + h1 ) / hsumt3;

      w2 = ( hsum + h2 ) / hsumt3;

      dmax = r8_max ( fabs ( del1 ), fabs ( del2 ) );

      dmin = r8_min ( fabs ( del1 ), fabs ( del2 ) );

      drat1 = del1 / dmax;

      drat2 = del2 / dmax;

      d[i-1] = dmin / ( w1 * drat1 + w2 * drat2 );

    }

  }

  w1 = -h2 / hsum;

  w2 = ( h2 + hsum ) / hsum;

  d[n-1] = w1 * del1 + w2 * del2;

  if ( pchst ( d[n-1], del2 ) <= 0.0 )

  {

    d[n-1] = 0.0;

  }

  else if ( pchst ( del1, del2 ) < 0.0 )

  {

    dmax = 3.0 * del2;

    if ( fabs ( dmax ) < fabs ( d[n-1] ) )

    {

      d[n-1] = dmax;

    }

  }

  return;

}

void spline_pchip_val ( int n, double x[], double f[], double d[],  

  int ne, double xe[], double fe[] )

{

  int i;

  int ierc;

  int ierr;

  int ir;

  int j;

  int j_first;

  int j_new;

  int j_save;

  int next[2];

  int nj;

  if ( n < 2 )

  {

    ierr = -1;

    cerr << "\n";

    cerr << "SPLINE_PCHIP_VAL - Fatal error!\n";

    cerr << "  Number of data points less than 2.\n";

    exit ( ierr );

  }

  for ( i = 1; i < n; i++ )

  {

    if ( x[i] <= x[i-1] )

    {

      ierr = -3;

      cerr << "\n";

      cerr << "SPLINE_PCHIP_VAL - Fatal error!\n";

      cerr << "  X array not strictly increasing.\n";

      exit ( ierr );

    }

  }

  if ( ne < 1 )

  {

    ierr = -4;

    cerr << "\n";

    cerr << "SPLINE_PCHIP_VAL - Fatal error!\n";

    cerr << "  Number of evaluation points less than 1.\n";

    return;

  }

  ierr = 0;

  j_first = 1;

  ir = 2;

  for ( ; ; )

  {

    if ( ne < j_first )

    {

      break;

    }

    j_save = ne + 1;

    for ( j = j_first; j <= ne; j++ )

    {

      if ( x[ir-1] <= xe[j-1] )

      {

        j_save = j;

        if ( ir == n )

        {

          j_save = ne + 1;

        }

        break;

      }

    }

    j = j_save;

    nj = j - j_first;

    if ( nj != 0 )

    {

      ierc = chfev ( x[ir-2], x[ir-1], f[ir-2], f[ir-1], d[ir-2], d[ir-1], 

        nj, xe+j_first-1, fe+j_first-1, next );

      if ( ierc < 0 )

      {

        ierr = -5;

        cerr << "\n";

        cerr << "SPLINE_PCHIP_VAL - Fatal error!\n";

        cerr << "  Error return from CHFEV.\n";

        exit ( ierr );

      }

      if ( next[1] != 0 )

      {

        if ( ir < n )

        {

          ierr = -5;

          cerr << "\n";

          cerr << "SPLINE_PCHIP_VAL - Fatal error!\n";

          cerr << "  IR < N.\n";

          exit ( ierr );

        }

        ierr = ierr + next[1];

      }

      if ( next[0] != 0 )

      {

        if ( ir <= 2 )

        {

          ierr = ierr + next[0];

        }

        else

        {

          j_new = -1;

          for ( i = j_first; i <= j-1; i++ )

          {

            if ( xe[i-1] < x[ir-2] )

            {

              j_new = i;

              break;

            }

          }

          if ( j_new == -1 )

          {

            ierr = -5;

            cerr << "\n";

            cerr << "SPLINE_PCHIP_VAL - Fatal error!\n";

            cerr << "  Could not bracket the data point.\n";

            exit ( ierr );

          }

          j = j_new;

          for ( i = 1; i <= ir-1; i++ )

          {

            if ( xe[j-1] < x[i-1] )

            {

              break;

            }

          }

          ir = i4_max ( 1, i-1 );

        }

      }

      j_first = j;

    }

    ir = ir + 1;

    if ( n < ir )

    {

      break;

    }

  }

  return;

}

void spline_quadratic_val ( int ndata, double tdata[], double ydata[], 

  double tval, double *yval, double *ypval )

{

  double dif1;

  double dif2;

  int left;

  int right;

  double t1;

  double t2;

  double t3;

  double y1;

  double y2;

  double y3;

  if ( ndata < 3 )

  {

    cerr << "\n";

    cerr << "SPLINE_QUADRATIC_VAL - Fatal error!\n";

    cerr << "  NDATA < 3.\n";

    exit ( 1 );

  }

  if ( ndata % 2 == 0 )

  {

    cerr << "\n";

    cerr << "SPLINE_QUADRATIC_VAL - Fatal error!\n";

    cerr << "  NDATA must be odd.\n";

    exit ( 1 );

  }

  r8vec_bracket ( ndata, tdata, tval, &left, &right );

  if ( left % 2 == 0 )

  {

    left = left - 1;

  }

  t1 = tdata[left-1];

  t2 = tdata[left  ];

  t3 = tdata[left+1];

  if ( t2 <= t1 || t3 <= t2 )

  {

    cerr << "\n";

    cerr << "SPLINE_QUADRATIC_VAL - Fatal error!\n";

    cerr << "  T2 <= T1 or T3 <= T2.\n";

    exit ( 1 );

  }

  y1 = ydata[left-1];

  y2 = ydata[left  ];

  y3 = ydata[left+1];

  dif1 = ( y2 - y1 ) / ( t2 - t1 );

  dif2 = ( ( y3 - y1 ) / ( t3 - t1 ) 

       - ( y2 - y1 ) / ( t2 - t1 ) ) / ( t3 - t2 );

  *yval = y1 + ( tval - t1 ) * ( dif1 + ( tval - t2 ) * dif2 );

  *ypval = dif1 + dif2 * ( 2.0 * tval - t1 - t2 );

  return;

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