
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <fstream>

# include <ctime>

# include <cmath>

using namespace std;

# include "linplus.hpp"

void c8vec_print ( int n, double a[], string title )

{

  int i;

  int k;

  k = 0;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  cout << "                  Real     Imaginary\n";

  cout << "                  Part     Part\n";

  cout << "\n";

  for ( i = 0; i <= n-1; i++ ) 

  {

    cout << setw(6)  << i + 1  << "  " 

         << setw(14) << a[k]   << "  "

         << setw(14) << a[k+1] << "\n";

    k = k + 2;

  }

  return;

}

void c8vec_sort_a2 ( int n, double x[] )

{

  int i;

  int indx;

  int isgn;

  int j;

  double normsq_i;

  double normsq_j;

  double temp;

  i = 0;

  indx = 0;

  isgn = 0;

  j = 0;

  for ( ; ; )

  {

    sort_heap_external ( n, &indx, &i, &j, isgn );

    if ( 0 < indx )

    {

      temp     = x[0+(i-1)*2];

      x[0+(i-1)*2] = x[0+(j-1)*2];

      x[0+(j-1)*2] = temp;

      temp     = x[1+(i-1)*2];

      x[1+(i-1)*2] = x[1+(j-1)*2];

      x[1+(j-1)*2] = temp;

    }

    else if ( indx < 0 )

    {

      normsq_i = x[0+(i-1)*2] * x[0+(i-1)*2]

               + x[1+(i-1)*2] * x[1+(i-1)*2];

      normsq_j = x[0+(j-1)*2] * x[0+(j-1)*2]

               + x[1+(j-1)*2] * x[1+(j-1)*2];

      if ( normsq_i < normsq_j )

      {

        isgn = -1;

      }

      else

      {

        isgn = +1;

      }

    }

    else if ( indx == 0 )

    {

      break;

    }

  }

  return;

}

double *c8vec_unity ( int n )

{

  double *a;

  int i;

  double const pi = 3.141592653589793;

  double theta;

  a = new double[2*n];

  for ( i = 0; i < n; i++ )

  {

    theta = pi * ( double ) ( 2 * i ) / ( double ) ( n );

    a[0+i*2] = cos ( theta );

    a[1+i*2] = sin ( theta );

  }

  return a;

}

void daxpy ( int n, double sa, double x[], int incx, double y[], int incy )

{

  int i;

  int ix;

  int iy;

  if ( n <= 0 )

  {

  }

  else if ( sa == 0.0 )

  {

  }

  else if ( incx == 1 && incy == 1 )

  {

    for ( i = 0; i < n; i++ )

    {

      y[i] = y[i] + sa * x[i];

    }

  }

  else

  {

    if ( 0 <= incx )

    {

      ix = 0;

    }

    else

    {

      ix = ( - n + 1 ) * incx;

    }

    if ( 0 <= incy  )

    {

      iy = 0;

    }

    else

    {

      iy = ( - n + 1 ) * incy;

    }

    for ( i = 0; i < n; i++ )

    {

      y[iy] = y[iy] + sa * x[ix];

      ix = ix + incx;

      iy = iy + incy;

    }

  }

  return;

}

int file_delete ( string filename )

{

  int value;

  if ( !file_exist ( filename ) )

  {

    return 1;

  }

  value = remove ( filename.c_str ( ) );

  if ( value != 0 )

  {

    cerr << "\n";

    cerr << "FILE_DELETE: Warning!\n";

    cerr << "  Could not delete \"" << filename << "\".\n";

    return value;

  }

  cout << "\n";

  cout << "FILE_DELETE:\n";

  cout << "  Deleting old version of \"" << filename << "\".\n";

  return value;

}

bool file_exist ( string file_name )

{

  ifstream file;

  file.open ( file_name.c_str ( ), ios::in );

  if ( !file )

  {

    return false;

  }

  else

  {

    return true;

  }

}

int get_seed ( )

{

# define I_MAX 2147483647

  time_t clock;

  int ihour;

  int imin;

  int isec;

  int seed;

  struct tm *lt;

  time_t tloc;

  clock = time ( &tloc );

  lt = localtime ( &clock );

  ihour = lt->tm_hour;

  if ( ihour > 12 )

  {

    ihour = ihour - 12;

  }

  ihour = ihour - 1;

  imin = lt->tm_min;

  isec = lt->tm_sec;

  seed = isec + 60 * ( imin + 60 * ihour );

  seed = seed + 1;

  seed = ( int ) 

    ( ( ( double ) seed )

    * ( ( double ) I_MAX ) / ( 60.0 * 60.0 * 12.0 ) );

  if ( seed == 0 )

  {

    seed = 1;

  }

  return seed;

# undef I_MAX

}

double *hilbert_inverse ( int n )

{

  double *a;

  int i;

  int j;

  a = new double[n*n];

  a[0+0*n] = ( double ) ( n * n );

  i = 1;

  for ( j = 2; j <= n; j++ )

  {

    a[i-1+(j-1)*n] = -a[i-1+(j-2)*n] 

      * ( double ) ( ( n + j - 1 ) * ( i + j - 2 ) * ( n + 1 - j ) ) 

      / ( double ) ( ( i + j - 1 ) * ( j - 1 ) * ( j - 1 ) );

  }

  for ( i = 2; i <= n; i++ )

  {

    for (  j = 1; j <= n; j++ )

    {

      a[i-1+(j-1)*n] = -a[i-2+(j-1)*n] 

        * ( double ) ( ( n + i - 1 ) * ( i + j - 2 ) * ( n + 1 - i ) ) 

        / ( double ) ( ( i + j - 1 ) * ( i - 1 ) * ( i - 1 ) );

    }

  }

  return a;

}

int i4_huge ( )

{

  return 2147483647;

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

  if ( i2 < i1 )

  {

    return i1;

  }

  else

  {

    return i2;

  }

}

int i4_min ( int i1, int i2 )

{

  if ( i1 < i2 )

  {

    return i1;

  }

  else

  {

    return i2;

  }

}

int i4_modp ( int i, int j )

{

  int value;

  if ( j == 0 )

  {

    cerr << "\n";

    cerr << "I4_MODP - Fatal error!\n";

    cerr << "  I4_MODP ( I, J ) called with J = " << j << "\n";

    exit ( 1 );

  }

  value = i % j;

  if ( value < 0 )

  {

    value = value + abs ( j );

  }

  return value;

}

int i4_power ( int i, int j )

{

  int k;

  int value;

  if ( j < 0 )

  {

    if ( i == 1 )

    {

      value = 1;

    }

    else if ( i == 0 )

    {

      cerr << "\n";

      cerr << "I4_POWER - Fatal error!\n";

      cerr << "  I^J requested, with I = 0 and J negative.\n";

      exit ( 1 );

    }

    else

    {

      value = 0;

    }

  }

  else if ( j == 0 )

  {

    if ( i == 0 )

    {

      cerr << "\n";

      cerr << "I4_POWER - Fatal error!\n";

      cerr << "  I^J requested, with I = 0 and J = 0.\n";

      exit ( 1 );

    }

    else

    {

      value = 1;

    }

  }

  else if ( j == 1 )

  {

    value = i;

  }

  else

  {

    value = 1;

    for ( k = 1; k <= j; k++ )

    {

      value = value * i;

    }

  }

  return value;

}

int i4_uniform ( int a, int b, int *seed )

{

  int k;

  float r;

  int value;

  if ( *seed == 0 )

  {

    cerr << "\n";

    cerr << "I4_UNIFORM - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )

  {

    *seed = *seed + 2147483647;

  }

  r = ( float ) ( *seed ) * 4.656612875E-10;

  r = ( 1.0 - r ) * ( ( float ) ( i4_min ( a, b ) ) - 0.5 ) 

    +         r   * ( ( float ) ( i4_max ( a, b ) ) + 0.5 );

  value = r4_nint ( r );

  value = i4_max ( value, i4_min ( a, b ) );

  value = i4_min ( value, i4_max ( a, b ) );

  return value;

}

void i4vec_print ( int n, int a[], string title )

{

  int i;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  for ( i = 0; i <= n-1; i++ ) 

  {

    cout << setw(6) << i + 1 << "  " 

         << setw(6) << a[i]  << "\n";

  }

  return;

}

int i4vec_search_binary_a ( int n, int a[], int b )

{

  int high;

  int index;

  int low;

  int mid;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "I4VEC_SEARCH_BINARY_A - Fatal error!\n";

    cerr << "  The array dimension N is less than 1.\n";

    exit ( 1 );

  }

  index = -1;

  low = 1;

  high = n;

  while ( low <= high )

  {

    mid = ( low + high ) / 2;

    if ( a[mid-1] == b )

    {

      index = mid;

      break;

    }

    else if ( a[mid-1] < b )

    {

      low = mid + 1;

    }

    else if ( b < a[mid-1] )

    {

      high = mid - 1;

    }

  }

  return index;

}

float r4_abs ( float x )

{

  float value;

  if ( 0.0 <= x )

  {

    value = x;

  } 

  else

  {

    value = -x;

  }

  return value;

}

int r4_nint ( float x )

{

  int value;

  if ( x < 0.0 )

  {

    value = - ( int ) ( r4_abs ( x ) + 0.5 );

  }

  else

  {

    value =   ( int ) ( r4_abs ( x ) + 0.5 );

  }

  return value;

}

float r4_uniform ( float a, float b, int *seed )

{

  int k;

  float value;

  if ( *seed == 0 )

  {

    cerr << "\n";

    cerr << "R4_UNIFORM - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )

  {

    *seed = *seed + 2147483647;

  }

  value = ( double ) ( *seed ) * 4.656612875E-10;

  value = a + ( b - a ) * value;

  return value;

}

float r4_uniform_01 ( int *seed )

{

  int k;

  float r;

  if ( *seed == 0 )

  {

    cerr << "\n";

    cerr << "R4_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )

  {

    *seed = *seed + 2147483647;

  }

  r = ( float ) ( *seed ) * 4.656612875E-10;

  return r;

}

double r8_abs ( double x )

{

  double value;

  if ( 0.0 <= x )

  {

    value = x;

  } 

  else

  {

    value = - x;

  }

  return value;

}

bool r8_is_int ( double r )

{

  if ( ( ( double ) i4_huge ( ) ) < r )

  {

    return false;

  }

  else if ( r < -( ( double ) i4_huge ( ) ) )

  {

    return false;

  }

  else if ( r == ( ( double ) ( ( int ) r ) ) )

  {

    return true;

  }

  else

  {

    return false;

  }

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

double r8_sign ( double x )

{

  double value;

  if ( x < 0.0 )

  {

    value = -1.0;

  }

  else

  {

    value = 1.0;

  }

  return value;

}

double r8_sign2 ( double x, double y )

{

  if ( 0.0 <= y )

  {

    return x;

  } 

  else

  {

    return (-x);

  }

}

void r8_swap ( double *x, double *y )

{

  double z;

  z = *x;

  *x = *y;

  *y = z;

 

  return;

}

double r8_uniform ( double rlo, double rhi, int *seed )

{

  double t;

  t = r8_uniform_01 ( seed );

  t = ( 1.0 - t ) * rlo + t * rhi;

  return t;

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

double *r83_cr_fa ( int n, double a[] )

{

  double *a_cr;

  int iful;

  int ifulp;

  int ihaf;

  int il;

  int ilp;

  int inc;

  int incr;

  int ipnt;

  int ipntp;

  int j;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "R83_CR_FA - Fatal error!\n";

    cerr << "  Nonpositive N = " << n << "\n";

    exit ( 1 );

  }

  a_cr = new double[3*(2*n+1)];

  if ( n == 1 )

  {

    a_cr[0+0*3] = 0.0;

    a_cr[0+1*3] = 0.0;

    a_cr[0+2*3] = 0.0;

    a_cr[1+0*3] = 0.0;

    a_cr[1+1*3] = 1.0 / a[1+0*3];

    a_cr[1+2*3] = 0.0;

    a_cr[2+0*3] = 0.0;

    a_cr[2+1*3] = 0.0;

    a_cr[2+2*3] = 0.0;

    return a_cr;

  }

  a_cr[0+0*3] = 0.0;

  for ( j = 1; j <= n-1; j++ )

  {

    a_cr[0+j*3] = a[0+j*3];

  }

  for ( j = n; j <= 2*n; j++ )

  {

    a_cr[0+j*3] = 0.0;

  }

  a_cr[1+0*3] = 0.0;

  for ( j = 1; j <= n; j++ )

  {

    a_cr[1+j*3] = a[1+(j-1)*3];

  }

  for ( j = n+1; j <= 2*n; j++ )

  {

    a_cr[1+j*3] = 0.0;

  }

  a_cr[2+0*3] = 0.0;

  for ( j = 1; j <= n-1; j++ )

  {

    a_cr[2+j*3] = a[2+(j-1)*3];

  }

  for ( j = n; j <= 2*n; j++ )

  {

    a_cr[2+j*3] = 0.0;

  }

  il = n;

  ipntp = 0;

  while ( 1 < il )

  {

    ipnt = ipntp;

    ipntp = ipntp + il;

    if ( ( il % 2 ) == 1 )

    {

      inc = il + 1;

    }

    else

    {

      inc = il;

    }

    incr = inc / 2;

    il = il / 2;

    ihaf = ipntp + incr + 1;

    ifulp = ipnt + inc + 2;

    for ( ilp = incr; 1 <= ilp; ilp-- )

    {

      ifulp = ifulp - 2;

      iful = ifulp - 1;

      ihaf = ihaf - 1;

      a_cr[1+iful*3] = 1.0 / a_cr[1+iful*3];

      a_cr[2+iful*3]  = a_cr[2+iful*3]  * a_cr[1+iful*3];

      a_cr[0+ifulp*3] = a_cr[0+ifulp*3] * a_cr[1+(ifulp+1)*3];

      a_cr[1+ihaf*3]  = a_cr[1+ifulp*3] 

        - a_cr[0+iful*3]  * a_cr[2+iful*3]

        - a_cr[0+ifulp*3] * a_cr[2+ifulp*3];

      a_cr[2+ihaf*3] = -a_cr[2+ifulp*3] * a_cr[2+(ifulp+1)*3];

      a_cr[0+ihaf*3] = -a_cr[0+ifulp*3] * a_cr[0+(ifulp+1)*3];

    }

  }

  a_cr[1+(ipntp+1)*3] = 1.0 / a_cr[1+(ipntp+1)*3];

  return a_cr;

}

double *r83_cr_sl ( int n, double a_cr[], double b[] )

{

  int i;

  int iful;

  int ifulm;

  int ihaf;

  int il;

  int ipnt;

  int ipntp;

  int ndiv;

  double *rhs;

  double *x;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "R83_CR_SL - Fatal error!\n";

    cerr << "  Nonpositive N = " << n << "\n";

    exit ( 1 );

  }

  if ( n == 1 )

  {

    x = new double[1];

    x[0] = a_cr[1+1*3] * b[0];

    return x;

  }

  rhs = new double[2*n+1];

  rhs[0] = 0.0;

  for ( i = 1; i <= n; i++ )

  {

    rhs[i] = b[i-1];

  }

  for ( i = n+1; i <= 2*n; i++ )

  {

    rhs[i] = 0.0;

  }

  il = n;

  ndiv = 1;

  ipntp = 0;

  while ( 1 < il )

  {

    ipnt = ipntp;

    ipntp = ipntp + il;

    il = il / 2;

    ndiv = ndiv * 2;

    ihaf = ipntp;

    for ( iful = ipnt + 2; iful <= ipntp; iful = iful + 2 )

    {

      ihaf = ihaf + 1;

      rhs[ihaf] = rhs[iful] 

        - a_cr[2+(iful-1)*3] * rhs[iful-1]

        - a_cr[0+iful*3]     * rhs[iful+1];

    }

  }

  rhs[ihaf] = rhs[ihaf] * a_cr[1+ihaf*3];

  ipnt = ipntp;

  while ( 0 < ipnt )

  {

    ipntp = ipnt;

    ndiv = ndiv / 2;

    il = n / ndiv;

    ipnt = ipnt - il;

    ihaf = ipntp;

    for ( ifulm = ipnt + 1; ifulm <= ipntp; ifulm = ifulm + 2 )

    {

      iful = ifulm + 1;

      ihaf = ihaf + 1;

      rhs[iful] = rhs[ihaf];

      rhs[ifulm] = a_cr[1+ifulm*3] * ( 

                                rhs[ifulm] 

        - a_cr[2+(ifulm-1)*3] * rhs[ifulm-1] 

        - a_cr[0+ifulm*3]     * rhs[iful] );

    }

  }

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = rhs[i+1];

  }

  delete [] rhs;

  return x;

}

double *r83_cr_sls ( int n, double a_cr[], int nb, double b[] )

{

  int i;

  int iful;

  int ifulm;

  int ihaf;

  int il;

  int ipnt;

  int ipntp;

  int j;

  int ndiv;

  double *rhs;

  double *x;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "R83_CR_SLS - Fatal error!\n";

    cerr << "  Nonpositive N = " << n << "\n";

    exit ( 1 );

  }

  if ( n == 1 )

  {

    x = new double[1*nb];

    for ( j = 0; j < nb; j++ )

    {

      x[0+j*n] = a_cr[1+1*3] * b[0+j*n];

    }

    return x;

  }

  rhs = new double[(2*n+1)*nb];

  for ( j = 0; j < nb; j++ )

  {

    rhs[0+j*n] = 0.0;

    for ( i = 1; i <= n; i++ )

    {

      rhs[i+j*n] = b[i-1+j*n];

    }

    for ( i = n + 1; i <= 2 * n; i++ )

    {

      rhs[i+j*n] = 0.0;

    }

  }

  il = n;

  ndiv = 1;

  ipntp = 0;

  while ( 1 < il )

  {

    ipnt = ipntp;

    ipntp = ipntp + il;

    il = il / 2;

    ndiv = ndiv * 2;

    for ( j = 0; j < nb; j++ )

    {

      ihaf = ipntp;

      for ( iful = ipnt + 2; iful <= ipntp; iful = iful + 2 )

      {

        ihaf = ihaf + 1;

        rhs[ihaf+j*n] = rhs[iful+j*n] 

          - a_cr[2+(iful-1)*3] * rhs[iful-1+j*n]

          - a_cr[0+iful*3]     * rhs[iful+1+j*n];

      }

    }

  }

  for ( j = 0; j < nb; j++ )

  {

    rhs[ihaf+j*n] = rhs[ihaf+j*n] * a_cr[1+ihaf*3];

  }

  ipnt = ipntp;

  while ( 0 < ipnt )

  {

    ipntp = ipnt;

    ndiv = ndiv / 2;

    il = n / ndiv;

    ipnt = ipnt - il;

    for ( j = 0; j < nb; j++ )

    {

      ihaf = ipntp;

      for ( ifulm = ipnt + 1; ifulm <= ipntp; ifulm = ifulm + 2 )

      {

        iful = ifulm + 1;

        ihaf = ihaf + 1;

        rhs[iful+j*n] = rhs[ihaf+j*n];

        rhs[ifulm+j*n] = a_cr[1+ifulm*3] * ( 

                                  rhs[ifulm+j*n] 

          - a_cr[2+(ifulm-1)*3] * rhs[ifulm-1+j*n] 

          - a_cr[0+ifulm*3]     * rhs[iful+j*n] );

      }

    }

  }

  x = new double[n*nb];

  for ( j = 0; j < nb; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      x[i+j*n] = rhs[i+1+j*n];

    }

  }

  delete [] rhs;

  return x;

}

void r83_gs_sl ( int n, double a[], double b[], double x[], int it_max, 

  int job )

{

  int i;

  int it_num;

  for ( i = 0; i < n; i++ )

  {

    if ( a[1+i*3] == 0.0 )

    {

      cerr << "\n";

      cerr << "R83_GS_SL - Fatal error!\n";

      cerr << "  Zero diagonal entry, index = " << i << "\n";

      exit ( 1 );

    }

  }

  if ( job == 0 )

  {

    for ( it_num = 1; it_num <= it_max; it_num++ )

    {

      x[0] =   ( b[0]                   - a[2+0*3] * x[1]     ) / a[1+0*3];

      for ( i = 1; i < n-1; i++ )

      {

        x[i] = ( b[i] - a[0+i*3] * x[i-1] - a[2+i*3] * x[i+1] ) / a[1+i*3];

      }

      x[n-1] =   ( b[n-1] - a[0+(n-1)*3] * x[n-2]             ) / a[1+(n-1)*3];

    }

  }

  else

  {

    for ( it_num = 1; it_num <= it_max; it_num++ )

    {

      x[0] =   ( b[0]                     - a[0+1*3] * x[1]     ) 

           / a[1+0*3];

      for ( i = 1; i < n-1; i++ )

      {

        x[i] = ( b[i] - a[2+(i-1)*3] * x[i-1] - a[0+(i+1)*3] * x[i+1] ) 

             / a[1+i*3];

      }

      x[n-1] =   ( b[n-1] - a[2+(n-2)*3] * x[n-2]                     ) 

             / a[1+(n-1)*3];

    }

  }

  return;

}

double *r83_indicator ( int n )

{

  double *a;

  int fac;

  int i;

  int j;

  a = new double[3*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  a[0+0*3] = 0.0;

  for ( j = 2; j <= n; j++ )

  {

    i = j - 1;

    a[0+(j-1)*3] = ( double ) ( fac * i + j );

  }

  for ( j = 1; j <= n; j++ )

  {

    i = j;

    a[1+(j-1)*3] = ( double ) ( fac * i + j );

  }

  for ( j = 1; j <= n-1; j++ )

  {

    i = j + 1;

    a[2+(j-1)*3] = ( double ) ( fac * i + j );

  }

  a[2+(n-1)*3] = 0.0;

  return a;

}

void r83_jac_sl ( int n, double a[], double b[], double x[], int it_max, 

  int job )

{

  int i;

  int it_num;

  double *xnew;

  xnew = new double[n];

  for ( i = 0; i < n; i++ )

  {

    if ( a[1+i*3] == 0.0 )

    {

      cerr << "\n";

      cerr << "R83_JAC_SL - Fatal error!\n";

      cerr << "  Zero diagonal entry, index = " << i << "\n";

      exit ( 1 );

    }

  }

  for ( it_num = 1; it_num <= it_max; it_num++ )

  {

    if ( job == 0 )

    {

      xnew[0] =   b[0]                           - a[2+0*3] * x[1];

      for ( i = 1; i < n-1; i++ )

      {

        xnew[i] = b[i]   - a[0+i*3]     * x[i-1] - a[2+i*3] * x[i+1];

      }

      xnew[n-1] = b[n-1] - a[0+(n-1)*3] * x[n-2];

    }

    else

    {

      xnew[0] =   b[0]                     - a[0+1*3] * x[1];

      for ( i = 1; i < n-1; i++ )

      {

        xnew[i] = b[i] - a[2+(i-1)*3] * x[i-1] - a[0+(i+1)*3] * x[i+1];

      }

      xnew[n-1] =   b[n-1] - a[2+(n-2)*3] * x[n-2];

    }

    for ( i = 0; i < n; i++ )

    {

      xnew[i] = xnew[i] / a[1+i*3];

    }

    for ( i = 0; i < n; i++ )

    {

      x[i] = xnew[i];

    }

  }

  delete [] xnew;

  return;

}

double *r83_mxv ( int n, double a[], double x[] )

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

double r83_np_det ( int n, double a_lu[] )

{

  double det;

  int j;

  det = 1.0;

  for ( j = 0; j < n; j++ )

  {

    det = det * a_lu[1+j*3];

  }

  return det;

}

int r83_np_fa ( int n, double a[] )

{

  int i;

  for ( i = 1; i <= n-1; i++ )

  {

    if ( a[1+(i-1)*3] == 0.0 )

    {

      cerr << "\n";

      cerr << "R83_NP_FA - Fatal error!\n";

      cerr << "  Zero pivot on step " << i << "\n";

      exit ( 1 );

    }

    a[2+(i-1)*3] = a[2+(i-1)*3] / a[1+(i-1)*3];

    a[1+i*3] = a[1+i*3] - a[2+(i-1)*3] * a[0+i*3];

  }

  if ( a[1+(n-1)*3] == 0.0 )

  {

    cerr << "\n";

    cerr << "R83_NP_FA - Fatal error!\n";

    cerr << "  Zero pivot on step " << n << "\n";

    exit ( 1 );

  }

  return 0;

}

double *r83_np_fs ( int n, double a[], double b[] )

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

double *r83_np_ml ( int n, double a_lu[], double x[], int job )

{

  double *b;

  int i;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = x[i];

  }

  if ( job == 0 )

  {

    for ( i = 1; i <= n; i++ )

    {

      b[i-1] = a_lu[1+(i-1)*3] * b[i-1];

      if ( i < n )

      {

        b[i-1] = b[i-1] + a_lu[0+i*3] * b[i];

      }

    }

    for ( i = n; 2 <= i; i-- )

    {

      b[i-1] = b[i-1] + a_lu[2+(i-2)*3] * b[i-2];

    }

  }

  else

  {

    for ( i = 1; i <= n-1; i++ )

    {

      b[i-1] = b[i-1] + a_lu[2+(i-1)*3] * b[i];

    }

    for ( i = n; 1 <= i; i-- )

    {

      b[i-1] = a_lu[1+(i-1)*3] * b[i-1];

      if ( 1 < i )

      {

        b[i-1] = b[i-1] + a_lu[0+(i-1)*3] * b[i-2];

      }

    }

  }

  return b;

}

double *r83_np_sl ( int n, double a_lu[], double b[], int job )

{

  int i;

  double *x;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  if ( job == 0 )

  {

    for ( i = 1; i < n; i++ )

    {

      x[i] = x[i] - a_lu[2+(i-1)*3] * x[i-1];

    }

    for ( i = n; 1 <= i; i-- )

    {

      x[i-1] = x[i-1] / a_lu[1+(i-1)*3];

      if ( 1 < i )

      {

        x[i-2] = x[i-2] - a_lu[0+(i-1)*3] * x[i-1];

      }

    }

  }

  else

  {

    for ( i = 1; i <= n; i++ )

    {

      x[i-1] = x[i-1] / a_lu[1+(i-1)*3];

      if ( i < n )

      {

        x[i] = x[i] - a_lu[0+i*3] * x[i-1];

      }

    }

    for ( i = n-1; 1 <= i; i-- )

    {

      x[i-1] = x[i-1] - a_lu[2+(i-1)*3] * x[i];

    }

  }

  return x;

}

void r83_print ( int n, double a[], string title )

{

  r83_print_some ( n, a, 1, 1, n, n, title );

  return;

}

void r83_print_some ( int n, double a[], int ilo, int jlo, int ihi, int jhi,

  string title )

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

  cout << "\n";

  cout << title << "\n";

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

      cout << setw(6) << i << ": ";

      for ( j2 = 1; j2 <= inc; j2++ )

      {

        j = j2lo - 1 + j2;

        if ( 1 < i - j || 1 < j - i )

        {

          cout << "              ";

        }

        else if ( j == i + 1 )

        {

          cout << setw(12) << a[0+(j-1)*3] << "  ";

        }

        else if ( j == i )

        {

          cout << setw(12) << a[1+(j-1)*3] << "  ";

        }

        else if ( j == i - 1 )

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

double *r83_random ( int n, int *seed )

{

  double *a;

  int i;

  double *u;

  double *v;

  double *w;

  a = new double[3*n];

  u = r8vec_random ( n-1, 0.0, 1.0, seed );

  v = r8vec_random ( n,   0.0, 1.0, seed );

  w = r8vec_random ( n-1, 0.0, 1.0, seed );

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

double *r83_to_r8ge ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( i = 1; i <= n; i++ )

  {

    for ( j = 1; j <= n; j++ )

    {

      if ( j == i-1 )

      {

        b[i-1+(j-1)*n] = a[0+(i-1)*3];

      }

      else if ( i == j )

      {

        b[i-1+(j-1)*n] = a[1+(i-1)*3];

      }

      else if ( j == i+1 )

      {

        b[i-1+(j-1)*n] = a[2+(i-1)*3];

      }

      else

      {

        b[i-1+(j-1)*n] = 0.0;

      }

    }

  }

  return b;

}

double *r83_vxm ( int n, double a[], double x[] )

{

  double *b;

  int i;

  b = new double[n];

  for ( i = 1; i <= n; i++ )

  {

    b[i-1] = a[1+(i-1)*3] * x[i-1];

  }

  for ( i = 1; i <= n-1; i++ )

  {

    b[i-1] = b[i-1] + a[2+(i-1)*3] * x[i];

  }

  for ( i = 2; i <= n; i++ )

  {

    b[i-1] = b[i-1] + a[0+(i-1)*3] * x[i-2];

  }

  return b;

}

double *r83_zero ( int n )

{

  double *a;

  int i;

  int j;

  a = new double[3*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < 3; i++ )

    {

      a[i+j*3] = 0.0;

    }

  }

  return a;

}

double *r83np_fs ( int n, double a[], double b[] )

{

  int i;

  double *x;

  for ( i = 0; i < n; i++ )

  {

    if ( a[1+i*3] == 0.0 )

    {

      cerr << "\n";

      cerr << "R83NP_FS - Fatal error!\n";

      cerr << "  A[1+" << i << "*3] = 0.\n";

      exit ( 1 );

    }

  }

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  for ( i = 1; i < n; i++ )

  {

    a[1+i*3] = a[1+i*3] - a[2+(i-1)*3] * a[0+i*3] / a[1+(i-1)*3];

    x[i]     = x[i]     - x[i-1]       * a[0+i*3] / a[1+(i-1)*3];

  }

  x[n-1] = x[n-1] / a[1+(n-1)*3];

  for ( i = n-2; 0 <= i; i-- )

  {

    x[i] = ( x[i] - a[2+i*3] * x[i+1] ) / a[1+i*3];

  }

  return x;

}

double r83p_det ( int n, double a_lu[], double work4 )

{

  double det;

  int i;

  det = work4;

  for ( i = 0; i <= n-2; i++ )

  {

    det = det * a_lu[1+i*3];

  }

  return det;

}

int r83p_fa ( int n, double a[], double work2[], double work3[], double *work4 )

{

  int i;

  int info;

  int job;

  double *work1;

  work1 = new double[n-1];

  info = r83_np_fa ( n-1, a );

  if ( info != 0 )

  {

    cerr << "\n";

    cerr << "R83P_FA - Fatal error!\n";

    cerr << "  R83_NP_FA returned INFO = " << info << "\n";

    cerr << "  Factoring failed for column INFO.\n";

    cerr << "  The tridiagonal matrix A1 is singular.\n";

    cerr << "  This algorithm cannot continue!\n";

    exit ( 1 );

  }

  work2[0] = a[2+(n-1)*3];

  for ( i = 1; i < n-2; i++)

  {

    work2[i] = 0.0;

  }

  work2[n-2] = a[0+(n-1)*3];

  job = 0;

  work1 = r83_np_sl ( n-1, a, work2, job );

  for ( i = 0; i < n-1; i++ )

  {

    work2[i] = work1[i];

  }

  work3[0] = a[0+0*3];

  for ( i = 1; i < n-2; i++)

  {

    work3[i] = 0.0;

  }

  work3[n-2] = a[2+(n-2)*3];

  job = 1;

  work1 = r83_np_sl ( n-1, a, work3, job );

  for ( i = 0; i < n-1; i++ )

  {

    work3[i] = work1[i];

  }

  *work4 = a[1+(n-1)*3] - a[0+0*3] * work2[0] - a[2+(n-2)*3] * work2[n-2];

  if ( *work4 == 0.0 )

  {

    cerr << "\n";

    cerr << "R83P_FA - Fatal error!\n";

    cerr << "  The factored A4 submatrix is zero.\n";

    cerr << "  This algorithm cannot continue!\n";

    exit ( 1 );

  }

  delete [] work1;

  return 0;

}

double *r83p_indicator ( int n )

{

  double *a;

  int fac;

  int i;

  int j;

  a = new double[3*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  i = n;

  j = 1;

  a[0+(j-1)*3] = ( double ) ( fac * i + j );

  for ( j = 2; j <= n; j++ )

  {

    i = j - 1;

    a[0+(j-1)*3] = ( double ) ( fac * i + j );

  }

  for ( j = 1; j <= n; j++ )

  {

    i = j;

    a[1+(j-1)*3] = ( double ) ( fac * i + j );

  }

  for ( j = 1; j <= n-1; j++ )

  {

    i = j + 1;

    a[2+(j-1)*3] = ( double ) ( fac * i + j );

  }

  i = 1;

  j = n;

  a[2+(j-1)*3] = ( double ) ( fac * i + j );

  return a;

}

double *r83p_ml ( int n, double a_lu[], double x[], int job )

{

  double *b;

  double *b_short;

  int i;

  b_short = r83_np_ml ( n-1, a_lu, x, job );

  b = new double[n];

  for ( i = 0; i < n-1; i++ )

  {

    b[i] = b_short[i];

  }

  b[n-1] = 0.0;

  delete [] b_short;

  if ( job == 0 )

  {

    b[0] = b[0] + a_lu[2+(n-1)*3] * x[n-1];

    b[n-2] = b[n-2] + a_lu[0+(n-1)*3] * x[n-1];

    b[n-1] = a_lu[0+0*3] * x[0] + a_lu[2+(n-2)*3] * x[n-2] 

      + a_lu[1+(n-1)*3] * x[n-1];

  }

  else

  {

    b[0] = b[0] + a_lu[0+0*3] * x[n-1];

    b[n-2] = b[n-2] + a_lu[2+(n-2)*3] * x[n-1];

    b[n-1] = a_lu[2+(n-1)*3] * x[0] + a_lu[0+(n-1)*3] * x[n-2] 

           + a_lu[1+(n-1)*3] * x[n-1];

  }

  return b;

}

double *r83p_mxv ( int n, double a[], double x[] )

{

  double *b;

  int i;

  b = new double[n];

  b[0] =   a[2+(n-1)*3] * x[n-1] + a[1+0*3]     * x[0]   + a[0+1*3]     * x[1];

  for ( i = 1; i < n-1; i++ )

  {

    b[i] = a[2+(i-1)*3] * x[i-1] + a[1+i*3]     * x[i]   + a[0+(i+1)*3] * x[i+1];

  }

  b[n-1] = a[2+(n-2)*3] * x[n-2] + a[1+(n-1)*3] * x[n-1] + a[0+0*3]     * x[0];

  return b;

}

void r83p_print ( int n, double a[], string title )

{

  r83p_print_some ( n, a, 1, 1, n, n, title );

  return;

}

void r83p_print_some ( int n, double a[], int ilo, int jlo, int ihi, int jhi,

  string title )

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

  cout << "\n";

  cout << title << "\n";

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

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    if ( 1 < i2lo || j2hi < n )

    {

      i2lo = i4_max ( i2lo, j2lo - 1 );

    }

    i2hi = i4_min ( ihi, n );

    if ( i2hi < n || 1 < j2lo )

    {

      i2hi = i4_min ( i2hi, j2hi + 1 );

    }

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j2 = 1; j2 <= inc; j2++ )

      {

        j = j2lo - 1 + j2;

        if ( i == n && j == 1 )

        {

          cout << setw(12) << a[0+(j-1)*3] << "  ";

        }

        else if ( i == 1 && j == n )

        {

          cout << setw(12) << a[2+(j-1)*3] << "  ";

        }

        else if ( 1 < i-j || 1 < j-i )

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

  cout << "\n";

  return;

# undef INCX

}

double *r83p_random ( int n, int *seed )

{

  double *a;

  int i;

  int j;

  a = new double[3*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < 3; i++ )

    {

      a[i+j*3] = r8_uniform_01 ( seed );

    }

  }

  return a;

}

double *r83p_sl ( int n, double a_lu[], double b[], int job, double work2[], 

  double work3[], double work4 )

{

  int i;

  double *x;

  double *xnm1;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  if ( job == 0 )

  {

    xnm1 = r83_np_sl ( n-1, a_lu, x, job );

    for ( i = 0; i < n-1; i++ )

    {

      x[i] = xnm1[i];

    }

    delete [] xnm1;

    x[n-1] = x[n-1] - a_lu[0+0*3] * x[0] - a_lu[2+(n-2)*3] * x[n-2];

    x[n-1] = x[n-1] / work4;

    for ( i = 0; i < n-1; i++ )

    {

      x[i] = x[i] - work2[i] * x[n-1];

    }

  }

  else

  {

    xnm1 = r83_np_sl ( n-1, a_lu, x, job );

    for ( i = 0; i < n-1; i++ )

    {

      x[i] = xnm1[i];

    }

    delete [] xnm1;

    x[n-1] = x[n-1] - a_lu[2+(n-1)*3] * x[0] - a_lu[0+(n-1)*3] * x[n-2];

    x[n-1] = x[n-1] / work4;

    for ( i = 0; i < n-1; i++ )

    {

      x[i] = x[i] - work3[i] * x[n-1];

    }

  }

  return x;

}

double *r83p_to_r8ge ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( i = 1; i <= n; i++ )

  {

    for ( j = 1; j <= n; j++ )

    {

      if ( i == j )

      {

        b[i-1+(j-1)*n] = a[1+(j-1)*3];

      }

      else if ( j == i-1 )

      {

        b[i-1+(j-1)*n] = a[2+(j-1)*3];

      }

      else if ( j == i+1 )

      {

        b[i-1+(j-1)*n] = a[0+(j-1)*3];

      }

      else if ( i == 1 && j == n )

      {

        b[i-1+(j-1)*n] = a[2+(j-1)*3];

      }

      else if ( i == n && j == 1 )

      {

        b[i-1+(j-1)*n] = a[0+(j-1)*3];

      }

      else

      {

        b[i-1+(j-1)*n] = 0.0;

      }

    }

  }

  return b;

}

double *r83p_vxm ( int n, double a[], double x[] )

{

  double *b;

  int i;

  b = new double[n];

  b[0] = a[0+0*3] * x[n-1] + a[1+0*3] * x[0] + a[2+0*3] * x[1];

  for ( i = 2; i <= n-1; i++ )

  {

    b[i-1] = a[0+(i-1)*3] * x[i-2] + a[1+(i-1)*3] * x[i-1] + a[2+(i-1)*3] * x[i];

  }

  b[n-1] = a[0+(n-1)*3] * x[n-2] + a[1+(n-1)*3] * x[n-1] + a[2+(n-1)*3] * x[0];

  return b;

}

double *r83p_zero ( int n )

{

  double *a;

  int i;

  int j;

  a = new double[3*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < 3; i++ )

    {

      a[i+j*3] = 0.0;

    }

  }

  return a;

}

double *r85_indicator ( int n )

{

  double *a;

  int fac;

  int i;

  int j;

  a = new double[5*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  a[0+0*5] = 0.0;

  a[0+1*5] = 0.0;

  for ( j = 3; j <= n; j++ )

  {

    i = j - 2;

    a[0+(j-1)*5] = ( double ) ( fac * i + j );

  }

  a[1+0*5] = 0.0;

  for ( j = 2; j <= n; j++ )

  {

    i = j - 1;

    a[1+(j-1)*5] = ( double ) ( fac * i + j );

  }

  for ( j = 1; j <= n; j++ )

  {

    i = j;

    a[2+(j-1)*5] = ( double ) ( fac * i + j );

  }

  for ( j = 1; j <= n-1; j++ )

  {

    i = j + 1;

    a[3+(j-1)*5] = ( double ) ( fac * i + j );

  }

  a[3+(n-1)*5] = 0.0;

  for ( j = 1; j <= n-2; j++ )

  {

    i = j + 2;

    a[4+(j-1)*5] = ( double ) ( fac * i + j );

  }

  a[4+(n-2)*5] = 0.0;

  a[4+(n-1)*5] = 0.0;

  return a;

}

double *r85_np_fs ( int n, double a[], double b[] )

{

  int i;

  double *x;

  double xmult;

  for ( i = 0; i < n; i++ )

  {

    if ( a[2+i*5] == 0.0 )

    {

      return NULL;

    }

  }

  x = new double[n];

  for ( i = 2; i <= n-1; i++ )

  {

    xmult = a[1+(i-1)*5] / a[2+(i-2)*5];

    a[2+(i-1)*5] = a[2+(i-1)*5] - xmult * a[3+(i-2)*5];

    a[3+(i-1)*5] = a[3+(i-1)*5] - xmult * a[4+(i-2)*5];

    b[i-1] = b[i-1] - xmult * b[i-2];

    xmult = a[0+i*5] / a[2+(i-2)*5];

    a[1+i*5] = a[1+i*5] - xmult * a[3+(i-2)*5];

    a[2+i*5] = a[2+i*5] - xmult * a[4+(i-2)*5];

    b[i] = b[i] - xmult * b[i-2];

  }

  xmult = a[1+(n-1)*5] / a[2+(n-2)*5];

  a[2+(n-1)*5] = a[2+(n-1)*5] - xmult * a[3+(n-2)*5];

  x[n-1] = ( b[n-1] - xmult * b[n-2] ) / a[2+(n-1)*5];

  x[n-2] = ( b[n-2] - a[3+(n-2)*5] * x[n-1] ) / a[2+(n-2)*5];

  for ( i = n - 2; 1 <= i; i-- )

  {

    x[i-1] = ( b[i-1] - a[3+(i-1)*5] * x[i] - a[4+(i-1)*5] * x[i+1] ) 

      / a[2+(i-1)*5];

  }

  return x;

}

double *r85_mxv ( int n, double a[], double x[] )

{

  double *b;

  int i;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = a[2+i*5] * x[i];

  }

  for ( i = 2; i < n; i++ )

  {

    b[i] = b[i] + a[0+i*5] * x[i-2];

  }

  for ( i = 1; i < n; i++ )

  {

    b[i] = b[i] + a[1+i*5] * x[i-1];

  }

  for ( i = 0; i < n-1; i++ )

  {

    b[i] = b[i] + a[3+i*5] * x[i+1];

  }

  for ( i = 0; i < n-2; i++ )

  {

    b[i] = b[i] + a[4+i*5] * x[i+2];

  }

  return b;

}

void r85_print ( int n, double a[], string title )

{

  r85_print_some ( n, a, 1, 1, n, n, title );

  return;

}

void r85_print_some ( int n, double a[], int ilo, int jlo, int ihi, int jhi,

  string title )

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

  cout << "\n";

  cout << title << "\n";

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n );

    j2hi = i4_min ( j2hi, jhi );

    inc = j2hi + 1 - j2lo;

    cout << "\n";

    cout << "  Col:  ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2lo = i4_max ( i2lo, j2lo - 2 );

    i2hi = i4_min ( ihi, n );

    i2hi = i4_min ( i2hi, j2hi + 2 );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(6) << i << "  ";

      for ( j2 = 1; j2 <= inc; j2++ )

      {

        j = j2lo - 1 + j2;

        if ( 2 < i-j || 2 < j-i )

        {

          cout << "            ";

        }

        else if ( j == i+2 )

        {

          cout << setw(10) << a[0+(j-1)*5] << "  ";

        }

        else if ( j == i+1 )

        {

          cout << setw(10) << a[1+(j-1)*5] << "  ";

        }

        else if ( j == i )

        {

          cout << setw(10) << a[2+(j-1)*5] << "  ";

        }

        else if ( j == i-1 )

        {

          cout << setw(10) << a[3+(j-1)*5] << "  ";

        }

        else if ( j == i-2 )

        {

          cout << setw(10) << a[4+(j-1)*5] << "  ";

        }

      }

      cout << "\n";

    }

    cout << "\n";

  }

  cout << "\n";

  return;

# undef INCX

}

double *r85_random ( int n, int *seed )

{

  double *a;

  int i;

  int j;

  a = new double[5*n];

  i = 0;

  a[0+0*5]     = 0.0;

  a[0+1*5]     = 0.0;

  for ( j = 2; j < n; j++ )

  {

    a[i+j*5] = r8_uniform_01 ( seed );

  }

  i = 1;

  a[1+0*5]     = 0.0;

  for ( j = 1; j < n; j++ )

  {

    a[i+j*5] = r8_uniform_01 ( seed );

  }

  i = 2;

  for ( j = 0; j < n; j++ )

  {

    a[i+j*5] = r8_uniform_01 ( seed );

  }

  i = 3;

  for ( j = 0; j < n-1; j++ )

  {

    a[i+j*5] = r8_uniform_01 ( seed );

  }

  a[3+(n-1)*5] = 0.0;

  i = 4;

  for ( j = 0; j < n-2; j++ )

  {

    a[i+j*5] = r8_uniform_01 ( seed );

  }

  a[4+(n-2)*5] = 0.0;

  a[4+(n-1)*5] = 0.0;

  return a;

}

double *r85_to_r8ge ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      if ( j == i-2 )

      {

        b[i+j*5] = a[0+i*5];

      }

      else if ( j == i-1 )

      {

        b[i+j*5] = a[1+i*5];

      }

      else if ( i == j )

      {

        b[i+j*5] = a[2+i*5];

      }

      else if ( j == i+1 )

      {

        b[i+j*5] = a[3+i*5];

      }

      else if ( j == i+2 )

      {

        b[i+j*5] = a[4+i*5];

      }

      else

      {

        b[i+j*5] = 0.0;

      }

    }

  }

  return b;

}

double *r85_vxm ( int n, double a[], double x[] )

{

  double *b;

  int j;

  b = new double[n];

  for ( j = 0; j < n; j++ )

  {

    b[j] = a[2+j*5] * x[j];

  }

  for ( j = 1; j < n; j++ )

  {

    b[j] = b[j] + a[3+j*5] * x[j-1];

  }

  for ( j = 2; j < n; j++ )

  {

    b[j] = b[j] + a[4+j*5] * x[j-2];

  }

  for ( j = 0; j < n-1; j++ )

  {

    b[j] = b[j] + a[1+j*5] * x[j+1];

  }

  for ( j = 0; j < n-2; j++ )

  {

    b[j] = b[j] + a[0+j*5] * x[j+2];

  }

  return b;

}

double *r85_zero ( int n )

{

  double *a;

  int i;

  int j;

  a = new double[5*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < 5; i++ )

    {

      a[i+j*5] = 0.0;

    }

  }

  return a;

}

void r8bb_add ( int n1, int n2, int ml, int mu, double a[], int i, int j, 

  double value )

{

  int ij;

  if ( value == 0.0 )

  {

    return;

  }

  if ( i <= 0 || n1 + n2 < i )

  {

    cerr << "\n";

    cerr << "R8BB_ADD - Fatal error!\n";

    cerr << "  Illegal input value of row index I = " << i << "\n";

    exit ( 1 );

  }

  if ( j <= 0 || n1 + n2 < j )

  {

    cerr << "\n";

    cerr << "R8BB_ADD - Fatal error!\n";

    cerr << "  Illegal input value of column index J = " << j << "\n";

    exit ( 1 );

  }

  if ( i <= n1 && j <= n1 )

  {

    if ( (mu+ml) < (j-i) || ml < (i-j) )

    {

      cout << "\n";

      cout << "R8BB_ADD - Warning!\n";

      cout << "  Unable to add to entry (" << i << ", " << j << ").\n";

    }

    else

    {

      ij = (i-j+ml+mu+1)+(j-1)*(2*ml+mu+1);

    }

  }

  else if ( i <= n1 && n1 < j )

  {

    ij = (2*ml+mu+1)*n1+(j-n1-1)*n1 + i;

  }

  else if ( n1 < i )

  {

    ij = (2*ml+mu+1)*n1+n2*n1+(j-1)*n2 + (i-n1);

  }

  a[ij-1] = a[ij-1] + value;

  return;

}

int r8bb_fa ( int n1, int n2, int ml, int mu, double a[], int pivot[] )

{

  double *b;

  int i;

  int ij;

  int ik;

  int info;

  int j;

  int jk;

  int job;

  int k;

  int nband;

  double *x;

  nband = (2*ml+mu+1) * n1;

  if ( 0 < n1 )

  {

    info = r8gb_fa ( n1, ml, mu, a, pivot );

    if ( info != 0 )

    {

      return info;

    }

  }

  if ( 0 < n1 && 0 < n2 )

  {

    for ( i = nband+1; i <= nband+n1*n2; i++ )

    {

      a[i-1] = -a[i-1];

    }

    b = new double[n1];

    x = new double[n1];

    job = 0;

    for ( j = 1; j <= n2; j++ )

    {

      for ( i = 0; i < n1; i++ )

      {

        b[i] = a[nband+(j-1)*n1+i];

      }

      x = r8gb_sl ( n1, ml, mu, a, pivot, b, job );

      for ( i = 0; i < n1; i++ )

      {

        a[nband+(j-1)*n1+i] = x[i];

      }

      delete [] x;

    }

    delete [] b;

    for ( i = 1; i <= n2; i++ )

    {

      for ( j = 1; j <= n1; j++ )

      {

        ij = nband + n1*n2 + (j-1)*n2 + i;

        for ( k = 1; k <= n2; k++ )

        {

          ik = nband + 2*n1*n2 + (k-1)*n2 + i;

          jk = nband + (k-1) * n1 + j;

          a[ik-1] = a[ik-1] + a[ij-1] * a[jk-1];

        }

      }

    }

  }

  if ( 0 < n2 )

  {

    info = r8ge_fa ( n2, a+(nband+2*n1*n2), pivot+n1 );

    if ( info != 0 )

    {

      return info;

    }

  }

  return 0;

}

double r8bb_get ( int n1, int n2, int ml, int mu, double a[], int i, int j )

{

  int ij;

  if ( i <= 0 || n1 + n2 < i )

  {

    cerr << "\n";

    cerr << "R8BB_GET - Fatal error!\n";

    cerr << "  Illegal input value of row index I = " << i << "\n";

    exit ( 1 );

  }

  if ( j <= 0 || n1 + n2 < j )

  {

    cerr << "\n";

    cerr << "R8BB_GET - Fatal error!\n";

    cerr << "  Illegal input value of column index J = " << j << "\n";

    exit ( 1 );

  }

  if ( i <= n1 && j <= n1 )

  {

    if ( (mu+ml) < (j-i) || ml < (i-j) )

    {

      return 0.0;

    }

    else

    {

      ij = (i-j+ml+mu+1) + (j-1)*(2*ml+mu+1);

    }

  }

  else if ( i <= n1 && n1 < j )

  {

    ij = (2*ml+mu+1)*n1 + (j-n1-1)*n1 + i;

  }

  else if ( n1 < i )

  {

    ij = (2*ml+mu+1)*n1 + n2*n1 + (j-1)*n2 + (i-n1);

  }

  return a[ij-1];

}

double *r8bb_indicator ( int n1, int n2, int ml, int mu )

{

  double *a;

  int base;

  int fac;

  int i;

  int j;

  int row;

  a = new double[(2*ml+mu+1)*n1+2*n1*n2+n2*n2];

  fac = i4_power ( 10, i4_log_10 ( n1 + n2 ) + 1 );

  for ( j = 1; j <= n1; j++ )

  {

    for ( row = 1; row <= 2 * ml + mu + 1; row++ )

    {

      i = row + j - ml - mu - 1;

      if ( ml < row && 1 <= i && i <= n1 )

      {

        a[row-1+(j-1)*(2*ml+mu+1)] = ( double ) ( fac * i + j );

      }

      else

      {

        a[row-1+(j-1)*(2*ml+mu+1)] = 0.0;

      }

    }

  }

  base = ( 2 * ml + mu + 1 ) * n1;

  for ( i = 1; i <= n1; i++ )

  {

    for ( j = n1 + 1; j <= n1 + n2; j++ )

    {

      a[base + i-1 + (j-n1-1)*n1 ] = ( double ) ( fac * i + j );

    }

  }

  base = ( 2 * ml + mu + 1 ) * n1 + n1 * n2;

  for ( i = n1 + 1; i <= n1 + n2; i++ )

  {

    for ( j = 1; j <= n1; j++ )

    {

      a[base + i-n1-1 + (j-1)*n2 ] = ( double ) ( fac * i + j );

    }

  }

  base = ( 2 * ml + mu + 1 ) * n1 + n1 * n2 + n2 * n1;

  for ( i = n1 + 1; i <= n1 + n2; i++ )

  {

    for ( j = n1 + 1; j <= n1 + n2; j++ )

    {

      a[base + i-n1-1 + (j-n1-1)*n2 ] = ( double ) ( fac * i + j );

    }

  }

  return a;

}

double *r8bb_mxv ( int n1, int n2, int ml, int mu, double a[], double x[] )

{

  double *b;

  int i;

  int ihi;

  int ij;

  int ilo;

  int j;

  b = new double[n1+n2];

  for ( i = 0; i < n1 + n2; i++ )

  {

    b[i] = 0.0;

  }

  for ( j = 1; j <= n1; j++ )

  {

    ilo = i4_max ( 1, j - mu - ml );

    ihi = i4_min ( n1, j + ml );

    ij = (j-1) * (2*ml+mu+1) - j + ml + mu + 1;

    for ( i = ilo; i <= ihi; i++ )

    {

      b[i-1] = b[i-1] + a[ij+i-1] * x[j-1];

    }

  }

  for ( j = n1+1; j <= n1 + n2; j++ )

  {

    ij = (2*ml+mu+1)*n1 + (j-n1-1)*n1;

    for ( i = 1; i <= n1; i++ )

    {

      b[i-1] = b[i-1] + a[ij+i-1] * x[j-1];

    }

  }

  for ( j = 1; j <= n1 + n2; j++ )

  {

    ij = (2*ml+mu+1)*n1 + n1*n2 + (j-1)*n2 - n1;

    for ( i = n1+1; i <= n1+n2; i++ )

    {

      b[i-1] = b[i-1] + a[ij+i-1] * x[j-1];

    }

  }

  return b;

}

void r8bb_print ( int n1, int n2, int ml, int mu, double a[], string title )

{

  r8bb_print_some ( n1, n2, ml, mu, a, 1, 1, n1+n2, n1+n2, title );

  return;

}

void r8bb_print_some ( int n1, int n2, int ml, int mu, double a[], int ilo, 

  int jlo, int ihi, int jhi, string title )

{

# define INCX 5

  double aij;

  int i;

  int i2hi;

  int i2lo;

  int ij;

  int j;

  int j2hi;

  int j2lo;

  cout << "\n";

  cout << title << "\n";

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n1+n2 );

    j2hi = i4_min ( j2hi, jhi );

    cout << "\n";

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, n1+n2 );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        aij = 0.0;

        if ( i <= n1 && j <= n1 )

        {

          if ( (j-i) <= mu+ml && (i-j) <= ml )

          {

            ij = (i-j+ml+mu+1) + (j-1)*(2*ml+mu+1);

            aij = a[ij-1];

          }

        }

        else if ( i <= n1 && n1 < j )

        {

          ij = (2*ml+mu+1)*n1 + (j-n1-1)*n1 + i;

          aij = a[ij-1];

        }

        else if ( n1 < i )

        {

          ij = (2*ml+mu+1)*n1 + n2*n1 + (j-1)*n2 + (i-n1);

          aij = a[ij-1];

        }

        cout << setw(12) << aij << "  ";

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8bb_random ( int n1, int n2, int ml, int mu, int *seed )

{

  double *a;

  int i;

  int j;

  double r;

  int row;

  a = new double[(2*ml+mu+1)*n1+2*n1*n2+n2*n2];

  for ( j = 1; j <= n1; j++ )

  {

    for ( row = 1; row <= 2 * ml + mu + 1; row++ )

    {

      i = row + j - ml - mu - 1;

      if ( ml < row && 1 <= i && i <= n1 )

      {

        r = r8_uniform_01 ( seed );

      }

      else

      {

        r = 0.0;

      }

      a[row-1+(j-1)*(2*ml+mu+1)] = r;

    }

  }

  for ( i = (2*ml+mu+1)*n1; i < (2*ml+mu+1)*n1+2*n1*n2+n2*n2; i++ )

  {

    a[i] = r8_uniform_01 ( seed );

  }

  return a;

}

void r8bb_set ( int n1, int n2, int ml, int mu, double a[], int i, int j, 

  double value )

{

  int ij;

  if ( i <= 0 || n1 + n2 < i )

  {

    cerr << "\n";

    cerr << "R8BB_SET - Fatal error!\n";

    cerr << "  Illegal input value of row index I = " << i << "\n";

    exit ( 1 );

  }

  if ( j <= 0 || n1 + n2 < j )

  {

    cerr << "\n";

    cerr << "R8BB_SET - Fatal error!\n";

    cerr << "  Illegal input value of column index J = " << j << "\n";

    exit ( 1 );

  }

  if ( i <= n1 && j <= n1 )

  {

    if ( (mu+ml) < (j-i) || ml < (i-j) )

    {

      cout << "\n";

      cout << "R8BB_SET - Warning!\n";

      cout << "  Unable to set entry (" << i << ", " << j << ").\n";

    }

    else

    {

      ij = (i-j+ml+mu+1) + (j-1)*(2*ml+mu+1);

    }

  }

  else if ( i <= n1 && n1 < j )

  {

    ij = (2*ml+mu+1)*n1 + (j-n1-1)*n1 + i;

  }

  else if ( n1 < i )

  {

    ij = (2*ml+mu+1)*n1 + n2*n1 + (j-1)*n2 + (i-n1);

  }

  a[ij-1] = value;

  return;

}

double *r8bb_sl ( int n1, int n2, int ml, int mu, double a_lu[], int pivot[], 

  double b[] )

{

  double *b22;

  int i;

  int ij;

  int j;

  int job;

  int nband;

  double *x;

  double *x1;

  double *x2;

  nband = (2*ml+mu+1)*n1;

  if ( 0 < n1 )

  {

    job = 0;

    x1 = r8gb_sl ( n1, ml, mu, a_lu, pivot, b, job );

  }

  if ( 0 < n2 )

  {

    b22 = new double[n2];

    for ( i = 0; i < n2; i++ )

    {

      b22[i] = b[n1+i];

      for ( j = 0; j < n1; j++ )

      {

        ij = nband + n1*n2 + j*n2 + i;

        b22[i] = b22[i] - a_lu[ij] * x1[j];

      }

    }

  }

  if ( 0 < n2 )

  {

    job = 0;

    x2 = r8ge_sl_new ( n2, a_lu+(nband+2*n1*n2), pivot+n1, b22, job );

    delete [] b22;

  }

  for ( i = 0; i < n1; i++ )

  {

    for ( j = 0; j < n2; j++ )

    {

      ij = nband + j*n1 + i;

      x1[i] = x1[i] + a_lu[ij] * x2[j];

    }

  }

  x = new double[n1+n2];

  if ( 0 < n1 )

  {

    for ( i = 0; i < n1; i++ )

    {

      x[i] = x1[i];

    }

    delete [] x1;

  }

  if ( 0 < n2 )

  {

    for ( i = 0; i < n2; i++ )

    {

      x[n1+i] = x2[i];

    }

    delete [] x2;

  }

  return x;

}

double *r8bb_to_r8ge ( int n1, int n2, int ml, int mu, double a[] )

{

  double *b;

  int i;

  int ij;

  int j;

  b = new double[(1+n2)*(n1+n2)];

  for ( i = 1; i <= n1; i++ )

  {

    for ( j = 1; j <= n1; j++ )

    {

      if ( mu+ml < (j-i) || ml < (i-j) )

      {

        b[i-1+(j-1)*(n1+n2)] = 0.0;

      }

      else

      {

        ij = (i-j+ml+mu+1) + (j-1)*(2*ml+mu+1);

        b[i-1+(j-1)*(n1+n2)]  = a[ij-1];

      }

    }

  }

  for ( i = 1; i <= n1; i++ )

  {

    for ( j = n1+1; j <= n2; j++ )

    {

      ij = (2*ml+mu+1)*n1 + (j-n1-1)*n1 + i;

      b[i-1+(j-1)*(n1+n2)]  = a[ij-1];

    }

  }

  for ( i = n1+1; i <= n2; i++ )

  {

    for ( j = 1; j <= n1+n2; j++ )

    {

      ij = (2*ml+mu+1)*n1 + n2*n1 + (j-1)*n2 + (i-n1);

      b[i-1+(j-1)*(n1+n2)]  = a[ij-1];

    }

  }

  return b;

}

double *r8bb_vxm ( int n1, int n2, int ml, int mu, double a[], double x[] )

{

  double *b;

  int i;

  int ihi;

  int ij;

  int ilo;

  int j;

  b = new double[n1+n2];

  for ( i = 0; i < n1+n2; i++ )

  {

    b[i] = 0.0;

  }

  for ( j = 1; j <= n1; j++ )

  {

    ilo = i4_max ( 1, j - mu - ml );

    ihi = i4_min ( n1, j + ml );

    ij = (j-1) * (2*ml+mu+1) - j + ml + mu + 1;

    for ( i = ilo; i <= ihi; i++ )

    {

      b[j-1] = b[j-1] + x[i-1] * a[ij+i-1];

    }

  }

  for ( j = n1+1; j <= n1+n2; j++ )

  {

    ij = (2*ml+mu+1)*n1 + (j-n1-1)*n1;

    for ( i = 1; i <= n1; i++ )

    {

      b[j-1] = b[j-1] + x[i-1] * a[ij+i-1];

    }

  }

  for ( j = 1; j <= n1+n2; j++ )

  {

    ij = (2*ml+mu+1)*n1 + n1*n2 + (j-1)*n2 - n1;

    for ( i = n1+1; i <= n1+n2; i++ )

    {

      b[j-1] = b[j-1] + x[i-1] * a[ij+i-1];

    }

  }

  return b;

}

double *r8bb_zero ( int n1, int n2, int ml, int mu )

{

  double *a;

  int i;

  a = new double[(2*ml+mu+1)*n1+2*n1*n2+n2*n2];

  for ( i = 0; i < (2*ml+mu+1)*n1 + 2*n1*n2 + n2*n2; i++ )

  {

    a[i] = 0.0;

  }

  return a;

}

double r8blt_det ( int n, int ml, double a[] )

{

  double det;

  int j;

  det = 1.0;

  for ( j = 0; j < n; j++ )

  {

    det = det * a[0+j*(ml+1)];

  }

  return det;

}

double *r8blt_indicator ( int n, int ml )

{

  double *a;

  int fac;

  int i;

  int j;

  int jlo;

  a = new double[(ml+1)*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( i = 1; i <= n; i++ )

  {

    jlo = i4_max ( 1, i - ml );

    for ( j = jlo; j <= i; j++ )

    {

      a[i-j+(j-1)*(ml+1)] = ( double ) ( fac * i + j );

    }

  }

  for ( i = n; i < n + ml; i++ )

  {

    for ( j = i - ml; j < n; j++ )

    {

      a[i-j+j*(ml+1)] = 0.0;

    }

  }

  return a;

}

double *r8blt_mxv ( int n, int ml, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  int jhi;

  int jlo;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

    jlo = i4_max ( 0, i - ml );

    jhi = i;

    for ( j = jlo; j <= jhi; j++ )

    {

      b[i] = b[i] + a[i-j+j*(ml+1)] * x[j];

    }

  }

  return b;

}

void r8blt_print ( int n, int ml, double a[], string title )

{

  r8blt_print_some ( n, ml, a, 1, 1, n, n, title );

  return;

}

void r8blt_print_some ( int n, int ml, double a[], int ilo, int jlo, int ihi, 

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

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2lo = i4_max ( i2lo, j2lo );

    i2hi = i4_min ( ihi, n );

    i2hi = i4_min ( i2hi, j2hi + ml );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(5) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( ml < i-j || 0 < j-i )

        {

          cout << "              ";

        }

        else

        {

          cout << setw(12) << a[i-j+(j-1)*(ml+1)] << "  ";

        }

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8blt_random ( int n, int ml, int *seed )

{

  double *a;

  int i;

  int j;

  int jlo;

  a = new double[(ml+1)*n];

  for ( i = 0; i < n; i++ )

  {

    jlo = i4_max ( 0, i - ml );

    for ( j = jlo; j <= i; j++ )

    {

      a[i-j+j*(ml+1)] = r8_uniform_01 ( seed );

    }

  }

  for ( i = n; i < n + ml; i++ )

  {

    for ( j = i - ml; j < n; j++ )

    {

      a[i-j+j*(ml+1)] = 0.0;

    }

  }

  return a;

}

double *r8blt_sl ( int n, int ml, double a[], double b[], int job )

{

  int i;

  int ihi;

  int ilo;

  int j;

  double *x;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  if ( job == 0 )

  {

    for ( j = 0; j < n; j++ )

    {

      x[j] = x[j] / a[0+j*(ml+1)];

      ihi = i4_min ( j + ml, n - 1 );

      for ( i = j+1; i <= ihi; i++ )

      {

        x[i] = x[i] - a[i-j+j*(ml+1)] * x[j];

      }

    }

  }

  else

  {

    for ( j = n-1; 0 <= j; j-- )

    {

      x[j] = x[j] / a[0+j*(ml+1)];

      ilo = i4_max ( j - ml, 0 );

      for ( i = ilo; i <= j-1; i++ )

      {

        x[i] = x[i] - a[j-i+i*(ml+1)] * x[j];

      }

    }

  }

  return x;

}

double *r8blt_to_r8ge ( int n, int ml, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( i = 1; i <= n; i++ )

  {

    for ( j = 1; j <= n; j++ )

    {

      if ( j <= i && i <= j + ml )

      {

        b[i-1+(j-1)*n] = a[i-j+(j-1)*(ml+1)];

      }

      else

      {

        b[i-1+(j-1)*n] = 0.0;

      }

    }

  }

  return b;

}

double *r8blt_vxm ( int n, int ml, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  int jhi;

  int jlo;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

  }

  for ( i = 0; i < n; i++ )

  {

    jlo = i4_max ( 0, i - ml );

    jhi = i;

    for ( j = jlo; j <= jhi; j++ )

    {

      b[j] = b[j] + x[i] * a[i-j+j*(ml+1)];

    }

  }

  return b;

}

double *r8blt_zero ( int n, int ml )

{

  double *a;

  int i;

  int j;

  a = new double[(ml+1)*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < ml+1; i++ )

    {

      a[i+j*(ml+1)] = 0.0;

    }

  }

  return a;

}

double *r8bto_indicator ( int m, int l )

{

  double *a;

  int fac;

  int i;

  int i2;

  int j;

  int j2;

  int k;

  a = new double[m*m*(2*l-1)];

  fac = i4_power ( 10, i4_log_10 ( m * l ) + 1 );

  j = 0;

  for ( k = 1; k <= l; k++ )

  {

    for ( j2 = 1; j2 <= m; j2++ )

    {

      j = j + 1;

      for ( i = 1; i <= m; i++ )

      {

        a[i-1+(j2-1)*m+(k-1)*m*m] = ( double ) ( fac * i + j );

      }

    }

  }

  i = m;

  for ( k = l+1; k <= 2*l-1; k++ )

  {

    for ( i2 = 1; i2 <= m; i2++ )

    {

      i = i + 1;

      for ( j = 1; j <= m; j++ )

      {

        a[i2-1+(j-1)*m+(k-1)*m*m] = ( double ) ( fac * i + j );

      }

    }

  }

  return a;

}

double *r8bto_mxv ( int m, int l, double a[], double x[] )

{

  double *b;

  int i;

  int i2;

  int j;

  int k;

  b = new double[m*l];

  for ( j = 0; j < l; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      b[i+j*m] = 0.0;

    }

    for ( k = 0; k <= j-1; k++ )

    {

      for ( i = 0; i < m; i++ )

      {

        for ( i2 = 0; i2 < m; i2++ )

        {

          b[i+j*m] = b[i+j*m] + a[i+i2*m+(l+j-k-1)*m*m] * x[i2+k*m];

        }

      }

    }

    for ( k = j; k < l; k++ )

    {

      for ( i = 0; i < m; i++ )

      {

        for ( i2 = 0; i2 < m; i2++ )

        {

          b[i+j*m] = b[i+j*m] + a[i+i2*m+(k-j)*m*m] * x[i2+k*m];

        }

      }

    }

  }

  return b;

}

void r8bto_print ( int m, int l, double a[], string title )

{

  r8bto_print_some ( m, l, a, 1, 1, m*l, m*l, title );

  return;

}

void r8bto_print_some ( int m, int l, double a[], int ilo, int jlo, int ihi, 

  int jhi, string title )

{

# define INCX 5

  int i;

  int i1;

  int i2;

  int i3hi;

  int i3lo;

  int inc;

  int j;

  int j1;

  int j2;

  int j3hi;

  int j3lo;

  int n;

  n = m * l;

  cout << "\n";

  cout << title << "\n";

  for ( j3lo = jlo; j3lo <= jhi; j3lo = j3lo + INCX )

  {

    j3hi = j3lo + INCX - 1;

    j3hi = i4_min ( j3hi, n );

    j3hi = i4_min ( j3hi, jhi );

    inc = j3hi + 1 - j3lo;

    cout << "\n";

    cout << "  Col: ";

    for ( j = j3lo; j <= j3hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i3lo = i4_max ( ilo, 1 );

    i3hi = i4_min ( ihi, n );

    for ( i = i3lo; i <= i3hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j = j3lo; j <= j3lo + inc - 1; j++ )

      {

        i1 = ( i - 1 ) / m + 1;

        i2 = i - m * ( i1 - 1 );

        j1 = ( j - 1 ) / m + 1;

        j2 = j - m * ( j1 - 1 );

        if ( i1 <= j1 )

        {

          cout << setw(12) << a[i2-1+(j2-1)*m+(j1-i1)*m*m] << "  ";

        }

        else

        {

          cout << setw(12) << a[i2-1+(j2-1)*m+(l-1+i1-j1)*m*m] << "  ";

        }

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8bto_random ( int m, int l, int *seed )

{

  double *a;

  int i;

  int j;

  int k;

  a = new double[m*m*(2*l-1)];

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < m; j++ )

    {

      for ( k = 0; k < 2 * l - 1; k++ )

      {

        a[i+j*m+k*m*m] = r8_uniform_01 ( seed );

      }

    }

  }

  return a;

}

double *r8bto_to_r8ge ( int m, int l, double a[] )

{

  double *b;

  int i;

  int i1;

  int i2;

  int j;

  int j1;

  int j2;

  int n;

  n = m * l;

  b = new double[n*n];

  for ( i = 1; i <= n; i++ )

  {

    i1 = ( i - 1 ) / m + 1;

    i2 = i - m * ( i1 - 1 );

    for ( j = 1; j <= n; j++ )

    {

      j1 = ( j - 1 ) / m + 1;

      j2 = j - m * ( j1 - 1 );

      if ( i1 <= j1 )

      {

        b[i-1+(j-1)*n] = a[i2-1+(j2-1)*m+(j1-i1)*m*m];

      }

      else

      {

        b[i-1+(j-1)*n] = a[i2-1+(j2-1)*m+(l+i1-j1-1)*m*m];

      }

    }

  }

  return b;

}

double *r8bto_vxm ( int m, int l, double a[], double x[] )

{

  double *b;

  int i;

  int i2;

  int j;

  int k;

  b = new double[m*l];

  for ( j = 1; j <= l; j++ )

  {

    for ( i = 1; i <= m; i++ )

    {

      b[i-1+(j-1)*m] = 0.0;

    }

    for ( k = 1; k <= j; k++ )

    {

      for ( i = 1; i <= m; i++ )

      {

        for ( i2 = 1; i2 <= m; i2++ )

        {

          b[i-1+(j-1)*m] = b[i-1+(j-1)*m] 

          + a[i2-1+(i-1)*m+(j-k)*m*m] * x[i2-1+(k-1)*m];

        }

      }

    }

    for ( k = j+1; k <= l; k++ )

    {

      for ( i = 1; i <= m; i++ )

      {

        for ( i2 = 1; i2 <= m; i2++ )

        {

          b[i-1+(j-1)*m] = b[i-1+(j-1)*m] 

          + a[i2-1+(i-1)*m+(l+k-j-1)*m*m] * x[i2-1+(k-1)*m];

        }

      }

    }

  }

  return b;

}

double *r8bto_zero ( int m, int l )

{

  double *a;

  int i;

  int j;

  int k;

  a = new double[m*m*(2*l-1)];

  for ( k = 0; k <= 2 * l - 1; k++ )

  {

    for ( j = 0; j < m; j++ )

    {

      for ( i = 0; i < m; i++ )

      {

        a[i+m*(j+m*k)] = 0.0;

      }

    }

  }

  return a;

}

double r8but_det ( int n, int mu, double a[] )

{

  double det;

  int j;

  det = 1.0;

  for ( j = 1; j <= n; j++ )

  {

    det = det * a[(mu+1-1)+(j-1)*(mu+1)];

  }

  return det;

}

double *r8but_indicator ( int n, int mu )

{

  double *a;

  int fac;

  int i;

  int j;

  a = new double[(mu+1)*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( i = 1; i <= n; i++ )

  {

    for ( j = i; j <= i4_min ( n, i + mu ); j++ )

    {

      a[i-j+mu+1-1+(j-1)*(mu+1)] = ( double ) ( fac * i + j );

    }

  }

  for ( i = 1; i <= mu; i++ )

  {

    for ( j = 1; j <= mu+1-i; j++ )

    {

      a[i-1+(j-1)*(mu+1)] = 0.0;

    }

  }

  return a;

}

double *r8but_mxv ( int n, int mu, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[n];

  for ( i = 1; i <= n; i++ )

  {

    b[i-1] = 0.0;

    for ( j = i; j <= i4_min ( n, i + mu ); j++ )

    {

      b[i-1] = b[i-1] + a[i-j+mu+1-1+(j-1)*(mu+1)] * x[j-1];

    }

  }

  return b;

}

void r8but_print ( int n, int mu, double a[], string title )

{

  r8but_print_some ( n, mu, a, 1, 1, n, n, title );

  return;

}

void r8but_print_some ( int n, int mu, double a[], int ilo, int jlo, 

  int ihi, int jhi, string title )

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

  cout << "\n";

  cout << title << "\n";

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

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2lo = i4_max ( i2lo, j2lo );

    i2hi = i4_min ( ihi, n );

    i2hi = i4_min ( i2hi, j2hi + mu );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j2 = 1; j2 <= inc; j2++ )

      {

        j = j2lo - 1 + j2;

        if ( i <= j && j <= i + mu )

        {

          cout << setw(12) << a[i-j+mu+1-1+(j-1)*(mu+1)] << "  ";

        }

        else

        {

          cout << "              ";

        }

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8but_random ( int n, int mu, int *seed )

{

  double *a;

  int i;

  int j;

  a = new double[(mu+1)*n];

  for ( i = 1; i <= mu + 1; i++ )

  {

    for ( j = 1; j <= mu + 1 - i; j++ )

    {

      a[i-1+(j-1)*(mu+1)] = 0.0;

    }

    for ( j = i4_max ( 1, mu + 2 - i ); j <= n; j++ )

    {

      a[i-1+(j-1)*(mu+1)] = r8_uniform_01 ( seed );

    }

  }

  return a;

}

double *r8but_sl ( int n, int mu, double a[], double b[], int job )

{

  int i;

  int ihi;

  int j;

  int jlo;

  double *x;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  if ( job == 0 )

  {

    for ( j = n; 1 <= j; j-- )

    {

      x[j-1] = x[j-1] / a[j-j+mu+(j-1)*(mu+1)];

      jlo = i4_max ( 1, j - mu );

      for ( i = jlo; i <= j-1; i++ )

      {

        x[i-1] = x[i-1] - a[i-j+mu+(j-1)*(mu+1)] * x[j-1];

      }

    }

  }

  else

  {

    for ( j = 1; j <= n; j++ )

    {

      x[j-1] = x[j-1] / a[j-j+mu+(j-1)*(mu+1)];

      ihi = i4_min ( n, j + mu );

      for ( i = j + 1; i <= ihi; i++ )

      {

        x[i-1] = x[i-1] - a[j-i+mu+(i-1)*(mu+1)] * x[j-1];

      }

    }

  }

  return x;

}

double *r8but_to_r8ge ( int n, int mu, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( i = 1; i <= n; i++ )

  {

    for ( j = 1; j <= n; j++ )

    {

      if ( i <= j && j <= i+mu )

      {

        b[i-1+(j-1)*n] = a[mu+i-j+(j-1)*(mu+1)];

      }

      else

      {

        b[i-1+(j-1)*n] = 0.0;

      }

    }

  }

  return b;

}

double *r8but_vxm ( int n, int mu, double a[], double x[] )

{

  double *b;

  int i;

  int ilo;

  int j;

  b = new double[n];

  for ( i = 1; i <= n; i++ )

  {

    b[i-1] = 0.0;

    ilo = i4_max ( 1, i - mu );

    for ( j = ilo; j <= i; j++ )

    {

      b[i-1] = b[i-1] + x[j-1] * a[j-i+mu+(i-1)*(mu+1)];

    }

  }

  return b;

}

double r8cb_det ( int n, int ml, int mu, double a_lu[] )

{

  double det;

  int j;

  det = 1.0;

  for ( j = 0; j < n; j++ )

  {

    det = det * a_lu[mu+j*(ml+mu+1)];

  }

  return det;

}

double *r8cb_indicator ( int m, int n, int ml, int mu )

{

  double *a;

  int col = ml + mu + 1;

  int diag;

  int fac;

  int i;

  int j;

  int k;

  a = new double[(ml+mu+1)*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  k = 0;

  for ( j = 1; j <= n; j++ )

  {

    for ( diag = 1; diag <= ml + mu + 1; diag++ )

    {

      i = diag + j - mu - 1;

      if ( 1 <= i && i <= m && i - ml <= j && j <= i + mu )

      {

        a[diag-1+(j-1)*col] = ( double ) ( fac * i + j );

      }

      else

      {

        k = k + 1;

        a[diag-1+(j-1)*col] = - ( double ) k;

      }

    }

  }

  return a;

}

double *r8cb_ml ( int n, int ml, int mu, double a_lu[], double x[], int job )

{

  double *b;

  int i;

  int ihi;

  int ilo;

  int j;

  int jhi;

  int nrow = ml + mu + 1;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = x[i];

  }

  if ( job == 0 )

  {

    for ( j = 0; j < n; j++ )

    {

      ilo = i4_max ( 0, j - mu );

      for ( i = ilo; i < j; i++ )

      {

        b[i] = b[i] + a_lu[i-j+mu+j*nrow] * b[j];

      }

      b[j] = a_lu[j-j+mu+j*nrow] * b[j];

    }

    for ( j = n - 2; 0 <= j; j-- )

    {

      ihi = i4_min ( n - 1, j + ml );

      for ( i = j + 1; i <= ihi; i++ )

      {

        b[i] = b[i] - a_lu[i-j+mu+j*nrow] * b[j];

      }

    }

  }

  else

  {

    for ( j = 0; j < n - 1; j++ )

    {

      jhi = i4_min ( n - 1, j + ml );

      for ( i = j + 1; i <= jhi; i++ )

      {

        b[j] = b[j] - b[i] * a_lu[i-j+mu+j*nrow];

      }

    }

    for ( i = n - 1; 0 <= i; i-- )

    {

      jhi = i4_min ( n - 1, i + mu );

      for ( j = i+1; j <= jhi; j++ )

      {

        b[j] = b[j] + b[i] * a_lu[i-j+mu+j*nrow];

      }

      b[i] = b[i] * a_lu[i-i+mu+i*nrow];

    }

  }

  return b;

}

double *r8cb_mxv ( int n, int ml, int mu, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  int jhi;

  int jlo;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

    jlo = i4_max ( 0, i - ml );

    jhi = i4_min ( n-1, i + mu );

    for ( j = jlo; j <= jhi; j++ )

    {

      b[i] = b[i] + a[i-j+mu+j*(ml+mu+1)] * x[j];

    }

  }

  return b;

}

int r8cb_np_fa ( int n, int ml, int mu, double a[] )

{

  int i;

  int j;

  int ju;

  int k;

  int lm;

  int m;

  int mm;

  m = mu + 1;

  ju = 0;

  for ( k = 1; k <= n-1; k++ )

  {

    if ( a[m-1+(k-1)*(ml+mu+1)] == 0.0 )

    {

      cerr << "\n";

      cerr << "R8CB_FA - Fatal error!\n";

      cerr << "  Zero pivot on step " << k << "\n";

      exit ( 1 );

    }

    lm = i4_min ( ml, n-k );

    for ( i = m+1; i <= m+lm; i++ )

    {

      a[i-1+(k-1)*(ml+mu+1)] = -a[i-1+(k-1)*(ml+mu+1)] / a[m-1+(k-1)*(ml+mu+1)];

    }

    ju = i4_max ( ju, mu + k );

    ju = i4_min ( ju, n );

    mm = m;

    for ( j = k+1; j <= ju; j++ )

    {

      mm = mm - 1;

      for ( i = 1; i <= lm; i++ )

      {

        a[mm+i-1+(j-1)*(ml+mu+1)] = a[mm+i-1+(j-1)*(ml+mu+1)] 

          + a[mm-1+(j-1)*(ml+mu+1)] * a[m+i-1+(k-1)*(ml+mu+1)];

      }

    }

  }

  if ( a[m-1+(n-1)*(ml+mu+1)] == 0.0 )

  {

    cerr << "\n";

    cerr << "R8CB_FA - Fatal error!\n";

    cerr << "  Zero pivot on step " << n << "\n";

    exit ( 1 );

  }

  return 0;

}

double *r8cb_np_sl ( int n, int ml, int mu, double a_lu[], double b[], int job )

{

  int i;

  int k;

  int la;

  int lb;

  int lm;

  int m;

  double *x;

  x = new double[n];

  m = mu + 1;

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  if ( job == 0 )

  {

    if ( 0 < ml )

    {

      for ( k = 1; k <= n-1; k++ )

      {

        lm = i4_min ( ml, n-k );

        for ( i = 0; i < lm; i++ )

        {

          x[k+i] = x[k+i] + x[k-1] * a_lu[m+i+(k-1)*(ml+mu+1)];

        }

      }

    }

    for ( k = n; 1 <= k; k-- )

    {

      x[k-1] = x[k-1] / a_lu[m-1+(k-1)*(ml+mu+1)];

      lm = i4_min ( k, m ) - 1;

      la = m - lm;

      lb = k - lm;

      for ( i = 0; i <= lm-1; i++ )

      {

        x[lb+i-1] = x[lb+i-1] - x[k-1] * a_lu[la+i-1+(k-1)*(ml+mu+1)];

      }

    }

  }

  else

  {

    for ( k = 1; k <= n; k++ )

    {

      lm = i4_min ( k, m ) - 1;

      la = m - lm;

      lb = k - lm;

      for ( i = 0; i <= lm-1; i++ )

      {

        x[k-1] = x[k-1] - a_lu[la+i-1+(k-1)*(ml+mu+1)] * x[lb+i-1];

      }

      x[k-1] = x[k-1] / a_lu[m-1+(k-1)*(ml+mu+1)];

    }

    if ( 0 < ml )

    {

      for ( k = n-1; 1 <= k; k-- )

      {

        lm = i4_min ( ml, n-k );

        for ( i = 0; i < lm; i++ )

        {

          x[k-1] = x[k-1] + a_lu[m+i+(k-1)*(ml+mu+1)] * x[k+i];

        }

      }

    }

  }

  return x;

}

void r8cb_print ( int m, int n, int ml, int mu, double a[], string title )

{

  r8cb_print_some ( m, n, ml, mu, a, 1, 1, m, n, title );

  return;

}

void r8cb_print_some ( int m, int n, int ml, int mu, double a[], int ilo, 

  int jlo, int ihi, int jhi, string title )

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

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2lo = i4_max ( i2lo, j2lo - mu );

    i2hi = i4_min ( ihi, m );

    i2hi = i4_min ( i2hi, j2hi + ml );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( ml < i-j || mu < j-i )

        {

          cout << "              ";

        }

        else

        {

          cout << setw(12) << a[i-j+mu+(j-1)*(ml+mu+1)] << "  ";

        }

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8cb_random ( int n, int ml, int mu, int *seed )

{

  double *a;

  int i;

  int ihi;

  int ilo;

  int j;

  a = new double[(ml+mu+1)*n];

  for ( j = 0; j < n; j++ )

  {

    ilo = i4_max ( 0, j - mu );

    ihi = i4_min ( n-1, j + ml );

    for ( i = j - mu; i < 0; i++ )

    {

      a[i-j+mu+j*(ml+mu+1)] = 0.0;

    }

    for ( i = ilo; i <= ihi; i++ )

    {

      a[i-j+mu+j*(ml+mu+1)] = r8_uniform_01 ( seed );

    }

    for ( i = n; i <= j+ml; i++ )

    {

      a[i-j+mu*j*(ml+mu+1)] = 0.0;

    }

  }

  return a;

}

double *r8cb_to_r8vec ( int m, int n, int ml, int mu, double *a )

{

  int i;

  int ihi;

  int ilo;

  int j;

  double *x;

  x = new double[(ml+mu+1)*n];

  for ( j = 1; j <= n; j++ )

  {

    ihi = i4_min ( mu, mu + 1 - j );

    for ( i = 1; i <= ihi; i++ )

    {

      x[i-1+(j-1)*(ml+mu+1)] = 0.0;

    }

    ilo = i4_max ( ihi + 1, 1 );

    ihi = i4_min ( ml+mu+1, mu+1+m-j );

    for ( i = ilo; i <= ihi; i++ )

    {

      x[i-1+(j-1)*(ml+mu+1)] = a[i-1+(j-1)*(ml+mu+1)];

    }

    ilo = ihi + 1;

    ihi = ml+mu+1;

    for ( i = ilo; i <= ihi; i++ )

    {

      x[i-1+(j-1)*(ml+mu+1)] = 0.0;

    }

  }

  return x;

}

double *r8cb_to_r8ge ( int n, int ml, int mu, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      if ( j-mu <= i && i <= j+ml )

      {

        b[i+j*n] = a[mu+i-j+j*(ml+mu+1)];

      }

      else

      {

        b[i+j*n] = 0.0;

      }

    }

  }

  return b;

}

double *r8cb_vxm ( int n, int ml, int mu, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  int jhi;

  int jlo;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

  }

  for ( i = 0; i < n; i++ )

  {

    jlo = i4_max ( 0, i - ml );

    jhi = i4_min ( n-1, i + mu );

    for ( j = jlo; j <= jhi; j++ )

    {

      b[j] = b[j] + x[i] * a[i-j+mu+j*(ml+mu+1)];

    }

  }

  return b;

}

double *r8cb_zero ( int n, int ml, int mu )

{

  double *a;

  int i;

  int j;

  a = new double[(ml+mu+1)*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < ml+mu+1; i++ )

    {

      a[i+j*(ml+mu+1)] = 0.0;

    }

  }

  return a;

}

void r8cbb_add ( int n1, int n2, int ml, int mu, double a[], int i, int j, 

  double value )

{

  int ij;

  if ( value == 0.0 )

  {

    return;

  }

  if ( i <= 0 || n1+n2 < i )

  {

    cerr << "\n";

    cerr << "R8CBB_ADD - Fatal error!\n";

    cerr << "  Illegal input value of row index I = " << i << "\n";

    exit ( 1 );

  }

  if ( j <= 0 || n1+n2 < j )

  {

    cerr << "\n";

    cerr << "R8CBB_ADD - Fatal error!\n";

    cerr << "  Illegal input value of column index J = " << j << "\n";

    exit ( 1 );

  }

  if ( i <= n1 && j <= n1 )

  {

    if ( mu < (j-i) || ml < (i-j) )

    {

      cout << "\n";

      cout << "R8CBB_ADD - Warning!\n";

      cout << "  Unable to add to entry (" << i << ", " << j << ").\n";

      return;

    }

    else

    {

      ij = (i-j+mu+1)+(j-1)*(ml+mu+1);

    }

  }

  else if ( i <= n1 && n1 < j )

  {

    ij = (ml+mu+1)*n1+(j-n1-1)*n1 + i;

  }

  else if ( n1 < i )

  {

    ij = (ml+mu+1)*n1+n2*n1+(j-1)*n2 + (i-n1);

  }

  a[ij-1] = a[ij-1] + value;

  return;

}

bool r8cbb_error ( int n1, int n2, int ml, int mu )

{

  if ( ml < 0 ) 

  {

    cout << "\n";

    cout << "R8CBB_ERROR - Illegal ML = " <<  ml << "\n";

    cout << "  but ML must be greater than or equal to 0.\n";

    return true;

  }

  if ( i4_max ( n1 - 1, 0 ) < ml )

  {

    cout << "\n";

    cout << "R8CBB_ERROR - Illegal ML = " << ml << "\n";

    cout << "  but ML must be <= Max ( N1 - 1, 0 ).\n";

    return true;

  }

  if ( mu < 0  )

  {

    cout << "\n";

    cout << "R8CBB_ERROR - Illegal MU = " << mu << "\n";

    cout << "  but MU must be greater than or equal to 0.\n";

    return true;

  }

  if ( i4_max ( n1 - 1, 0 ) < ml )

  {

    cout << "\n";

    cout << "R8CBB_ERROR - Illegal MU = " << mu << "\n";

    cout << "  but MU must be <= Max ( N1 - 1, 0 ).\n";

    return true;

  }

  if ( n1 < 0 )

  {

    cout << "\n";

    cout << "R8CBB_ERROR - Illegal N1 = " << n1 << "\n";

    return true;

  }

  if ( n2 < 0 )

  {

    cout << "\n";

    cout << "R8CBB_ERROR - Illegal N2 = " << n2 << "\n";

    return true;

  }

  if ( n1 + n2 <= 0 )

  {

    cout << "\n";

    cout << "R8CBB_ERROR - Illegal N1+N2 = " << n1 + n2 << "\n";

    return true;

  }

  return false;

}

int r8cbb_fa ( int n1, int n2, int ml, int mu, double a[] )

{

  double *b1;

  int i;

  int ij;

  int ik;

  int info;

  int j;

  int jk;

  int job;

  int k;

  int nband;

  double *x1;

  nband = (ml+mu+1)*n1;

  if ( 0 < n1 )

  {

    info = r8cb_np_fa ( n1, ml, mu, a );

    if ( info != 0 )

    {

      cerr << "\n";

      cerr << "R8CBB_FA - Fatal error!\n";

      cerr << "  R8CB_NP_FA returned INFO = " << info << "\n";

      cerr << "  Factoring failed for column INFO.\n";

      cerr << "  The band matrix A1 is singular.\n";

      cerr << "  This algorithm cannot continue!\n";

      exit ( 1 );

    }

  }

  if ( 0 < n1 && 0 < n2 )

  {

    for ( j = 0; j < n2; j++ )

    {

      for ( i = 0; i < n1; i++ )

      {

        a[nband+i+j*n1] = -a[nband+i+j*n1];

      }

    }

    b1 = new double[n1];

    x1 = new double[n1];

    job = 0;

    for ( j = 0; j < n2; j++ )

    {

      for ( i = 0; i < n1; i++ )

      {

        b1[i] = a[nband+i+j*n1];

      }

      x1 = r8cb_np_sl ( n1, ml, mu, a, b1, job );

      for ( i = 0; i < n1; i++ )

      {

        a[nband+i+j*n1] = x1[i];

      }

    }

    delete [] b1;

    delete [] x1;

    for ( i = 1; i <= n2; i++ )

    {

      for ( j = 1; j <= n1; j++ )

      {

        ij = nband + n1*n2 + (j-1)*n2 + i - 1;

        for ( k = 1; k <= n2; k++ )

        {

          ik = nband + 2*n1*n2 + (k-1)*n2 + i - 1;

          jk = nband + (k-1)*n1 + j - 1;

          a[ik] = a[ik] + a[ij] * a[jk];

        }

      }

    }

  }

  if ( 0 < n2 )

  {

    info = r8ge_np_fa ( n2, a+(nband+2*n1*n2) );

    if ( info != 0 )

    {

      cerr << "\n";

      cerr << "R8CBB_FA - Fatal error!\n";

      cerr << "  R8GE_NP_FA returned INFO = " << info << "\n";

      cerr << "  This indicates singularity in column " << n1+info << ".\n";

      cerr << "  The dense matrix A4 is singular.\n";

      cerr << "  This algorithm cannot continue!\n";

      exit ( 1 );

    }

  }

  return 0;

}

double r8cbb_get ( int n1, int n2, int ml, int mu, double a[], int i, int j )

{

  int ij;

  if ( i <= 0 || n1+n2 < i )

  {

    return 0.0;

  }

  if ( j <= 0 || n1+n2 < j )

  {

    return 0.0;

  }

  if ( i <= n1 && j <= n1 )

  {

    if ( mu < (j-i) || ml < (i-j) )

    {

      return 0.0;

    }

    else

    {

      ij = (i-j+mu+1)+(j-1)*(ml+mu+1);

    }

  }

  else if ( i <= n1 && n1 < j )

  {

    ij = (ml+mu+1)*n1+(j-n1-1)*n1 + i;

  }

  else if ( n1 < i )

  {

    ij = (ml+mu+1)*n1+n2*n1+(j-1)*n2 + (i-n1);

  }

  return a[ij-1];

}

double *r8cbb_indicator ( int n1, int n2, int ml, int mu )

{

  double *a;

  int base;

  int fac;

  int i;

  int j;

  int row;

  a = new double[(ml+mu+1)*n1+2*n1*n2+n2*n2];

  fac = i4_power ( 10, i4_log_10 ( n1 + n2 ) + 1 );

  for ( j = 1; j <= n1; j++ )

  {

    for ( row = 1; row <= ml + mu + 1; row++ )

    {

      i = row + j - mu - 1;

      if ( 1 <= i && i <= n1 )

      {

        a[row-1+(j-1)*(ml+mu+1)] = ( double ) ( fac * i + j );

      }

      else

      {

        a[row-1+(j-1)*(ml+mu+1)] = 0.0;

      }

    }

  }

  base = ( ml + mu + 1 ) * n1;

  for ( i = 1; i <= n1; i++ )

  {

    for ( j = n1 + 1; j <= n1 + n2; j++ )

    {

      a[base + i-1 + (j-n1-1)*n1 ] = ( double ) ( fac * i + j );

    }

  }

  base = ( ml + mu + 1 ) * n1 + n1 * n2;

  for ( i = n1 + 1; i <= n1 + n2; i++ )

  {

    for ( j = 1; j <= n1; j++ )

    {

      a[base + i-n1-1 + (j-1)*n2 ] = ( double ) ( fac * i + j );

    }

  }

  base = ( ml + mu + 1 ) * n1 + n1 * n2 + n2 * n1;

  for ( i = n1 + 1; i <= n1 + n2; i++ )

  {

    for ( j = n1 + 1; j <= n1 + n2; j++ )

    {

      a[base + i-n1-1 + (j-n1-1)*n2 ] = ( double ) ( fac * i + j );

    }

  }

  return a;

}

double *r8cbb_mxv ( int n1, int n2, int ml, int mu, double a[], double x[] )

{

  double *b;

  int i;

  int ihi;

  int ij;

  int ilo;

  int j;

  b = new double[n1+n2];

  for ( i = 0; i < n1+n2; i++ )

  {

    b[i] = 0.0;

  }

  for ( j = 1; j <= n1; j++ )

  {

    ilo = i4_max ( 1, j-mu );

    ihi = i4_min ( n1, j+ml );

    ij = (j-1)*(ml+mu+1)-j+mu+1;

    for ( i = ilo; i <= ihi; i++ )

    {

      b[i-1] = b[i-1] + a[ij+i-1] * x[j-1];

    }

  }

  for ( j = n1+1; j <= n1+n2; j++ )

  {

    ij = (ml+mu+1)*n1+(j-n1-1)*n1;

    for ( i = 1; i <= n1; i++ )

    {

      b[i-1] = b[i-1] + a[ij+i-1] * x[j-1];

    }

  }

  for ( j = 1; j <= n1+n2; j++ )

  {

    ij = (ml+mu+1)*n1+n1*n2+(j-1)*n2-n1;

    for ( i = n1+1; i <= n1+n2; i++ )

    {

      b[i-1] = b[i-1] + a[ij+i-1] * x[j-1];

    }

  }

  return b;

}

void r8cbb_print ( int n1, int n2, int ml, int mu, double a[], string title )

{

  r8cbb_print_some ( n1, n2, ml, mu, a, 1, 1, n1+n2, n1+n2, title );

  return;

}

void r8cbb_print_some ( int n1, int n2, int ml, int mu, double a[], int ilo, 

  int jlo, int ihi, int jhi, string title )

{

# define INCX 5

  double aij;

  int i;

  int i2hi;

  int i2lo;

  int ij;

  int j;

  int j2hi;

  int j2lo;

  cout << "\n";

  cout << title << "\n";

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n1+n2 );

    j2hi = i4_min ( j2hi, jhi );

    cout << "\n";

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, n1+n2 );

    for ( i = i2lo; i <= i2hi; i++ )

    {

    cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        aij = 0.0;

        if ( i <= n1 && j <= n1 )

        {

          if ( j - i <= mu && i - j <= ml )

          {

            ij = (i-j+mu+1)+(j-1)*(ml+mu+1);

            aij = a[ij-1];

          }

        }

        else if ( i <= n1 && n1 < j )

        {

          ij = (ml+mu+1)*n1+(j-n1-1)*n1+i;

          aij = a[ij-1];

        }

        else if ( n1 < i )

        {

          ij = (ml+mu+1)*n1+n2*n1+(j-1)*n2+(i-n1);

          aij = a[ij-1];

        }

        cout << setw(12) << aij << "  ";

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8cbb_random ( int n1, int n2, int ml, int mu, int *seed )

{

  double *a;

  int i;

  int j;

  double r;

  int row;

  a = new double[(ml+mu+1)*n1+2*n1*n2+n2*n2];

  for ( j = 1; j <= n1; j++ )

  {

    for ( row = 1; row <= ml+mu+1; row++ )

    {

      i = row + j - mu - 1;

      if ( 1 <= i && i <= n1 )

      {

        r = r8_uniform_01 ( seed );

      }

      else

      {

        r = 0.0;

      }

      a[row-1+(j-1)*(ml+mu+1)] = r;

    }

  }

  for ( i = (ml+mu+1)*n1+1; i <= (ml+mu+1)*n1+2*n1*n2+n2*n2; i++ )

  {

    a[i-1] = r8_uniform_01 ( seed );

  }

  return a;

}

void r8cbb_set ( int n1, int n2, int ml, int mu, double a[], int i, int j, 

  double value )

{

  int ij;

  if ( i <= 0 || n1+n2 < i )

  {

    cerr << "\n";

    cerr << "R8CBB_SET - Fatal error!\n";

    cerr << "  Illegal input value of row index I = " << i << "\n";

    exit ( 1 );

  }

  if ( j <= 0 || n1+n2 < j )

  {

    cerr << "\n";

    cerr << "R8CBB_SET - Fatal error!\n";

    cerr << "  Illegal input value of column index J = " << j << "\n";

    exit ( 1 );

  }

  if ( i <= n1 && j <= n1 )

  {

    if ( mu < (j-i) || ml < (i-j) )

    {

      cout << "\n";

      cout << "R8CBB_SET - Warning!\n";

      cout << "  Unable to set entry (" << i << ", " << j << ").\n";

      return;

    }

    else

    {

      ij = (i-j+mu+1)+(j-1)*(ml+mu+1);

    }

  }

  else if ( i <= n1 && n1 < j )

  {

    ij = (ml+mu+1)*n1+(j-n1-1)*n1 + i;

  }

  else if ( n1 < i )

  {

    ij = (ml+mu+1)*n1+n2*n1+(j-1)*n2 + (i-n1);

  }

  a[ij-1] = value;

  return;

}

double *r8cbb_sl ( int n1, int n2, int ml, int mu, double a_lu[], double b[] )

{

  double *b2;

  int i;

  int ij;

  int j;

  int job;

  int nband;

  double *x;

  double *x1;

  double *x2;

  nband = (ml+mu+1)*n1;

  if ( 0 < n1 )

  {

    job = 0;

    x1 = r8cb_np_sl ( n1, ml, mu, a_lu, b, job );

  }

  b2 = new double[n2];

  for ( i = 0; i < n2; i++ )

  {

    ij = nband + n1*n2 + j*n2 + i;

    b2[i] = b[n1+i];

  }

  for ( j = 0; j < n1; j++ )

  {

    for ( i = 0; i < n2; i++ )

    {

      ij = nband + n1*n2 + j*n2 + i;

      b2[i] = b2[i] - a_lu[ij] * x1[j];

    }

  }

  if ( 0 < n2 )

  {

    job = 0;

    x2 = r8ge_np_sl ( n2, a_lu+(nband+2*n1*n2), b2, job );

  }

  for ( i = 0; i < n1; i++ )

  {

    for ( j = 0; j < n2; j++ )

    {

      ij = nband + j*n1 + i;

      x1[i] = x1[i] + a_lu[ij] * x2[j];

    }

  }

  x = new double[n1+n2];

  for ( i = 0; i < n1; i++ )

  {

    x[i] = x1[i];

  }

  for ( i = 0; i < n2; i++ )

  {

    x[n1+i] = x2[i];

  }

  delete [] b2;

  delete [] x1;

  delete [] x2;

  return x;

}

double *r8cbb_to_r8ge ( int n1, int n2, int ml, int mu, double a[] )

{

  double *b;

  int i;

  int ij;

  int j;

  b = new double[(n1+n2)*(n1+n2)];

  for ( i = 1; i <= n1; i++ )

  {

    for ( j = 1; j <= n1; j++ )

    {

      if ( mu+ml < (j-i) || ml < (i-j) )

      {

        b[i-1+(j-1)*(n1+n2)] = 0.0;

      }

      else

      {

        ij = (i-j+mu+1)+(j-1)*(ml+mu+1);

        b[i-1+(j-1)*(n1+n2)] = a[ij-1];

      }

    }

  }

  for ( i = 1; i <= n1; i++ )

  {

    for ( j = n1+1; j <= n2; j++ )

    {

      ij = (ml+mu+1)*n1+(j-n1-1)*n1+i;

      b[i-1+(j-1)*(n1+n2)] = a[ij-1];

    }

  }

  for ( i = n1+1; i <= n2; i++ )

  {

    for ( j = 1; j <= n1+n2; j++)

    {

      ij = (ml+mu+1)*n1+n2*n1+(j-1)*n2+(i-n1);

      b[i-1+(j-1)*(n1+n2)] = a[ij-1];

    }

  }

  return b;

}

double *r8cbb_vxm ( int n1, int n2, int ml, int mu, double a[], double x[] )

{

  double *b;

  int i;

  int ihi;

  int ij;

  int ilo;

  int j;

  b = new double[n1+n2];

  for ( i = 0; i < n1+n2; i++ )

  {

    b[i] = 0.0;

  }

  for ( j = 1; j <= n1; j++ )

  {

    ilo = i4_max ( 1, j-mu );

    ihi = i4_min ( n1, j+ml );

    ij = (j-1)*(ml+mu+1)-j+mu+1;

    for ( i = ilo; i <= ihi; i++ )

    {

      b[j] = b[j] + x[i-1] * a[ij+i-1];

    }

  }

  for ( j = n1+1; j <= n1+n2; j++ )

  {

    ij = (ml+mu+1)*n1+(j-n1-1)*n1;

    for ( i = 1; i <= n1; i++ )

    {

      b[j] = b[j] + x[i-1] * a[ij+i-1];

    }

  }

  for ( j = 1; j <= n1+n2; j++ )

  {

    ij = (ml+mu+1)*n1+n1*n2+(j-1)*n2-n1;

    for ( i = n1+1; i <= n1+n2; i++ )

    {

      b[j-1] = b[j-1] + x[i-1] * a[ij+i-1];

    }

  }

  return b;

}

double *r8cbb_zero ( int n1, int n2, int ml, int mu )

{

  double *a;

  int i;

  a = new double[(ml+mu+1)*n1+2*n1*n2+n2*n2];

  for ( i = 0; i < (ml+mu+1)*n1+2*n1*n2+n2*n2; i++ )

  {

    a[i] = 0.0;

  }

  return a;

}

double r8cc_get ( int m, int n, int nz_num, int col[], int row[], 

  double a[], int i, int j )

{

  double aij;

  int k;

  k = r8cc_ijk ( m, n, nz_num, col, row, i, j );

  if ( k == -1 )

  {

    aij = 0.0;

  }

  else

  {

    aij = a[k-1];

  }

  return aij;

}

int r8cc_ijk ( int m, int n, int nz_num, int col[], int row[], int i, 

  int j )

{

  int k;

  int k1;

  int k2;

  k1 = col[j-1];

  k2 = col[j]-1;

  k = i4vec_search_binary_a ( k2+1-k1, row+k1-1, i );

  if ( k != -1 )

  {

    k = k + k1 - 1;

  }

  return k;

}

void r8cc_inc ( int m, int n, int nz_num, int col[], int row[], double a[], 

  int i, int j, double aij )

{

  int k;

  k = r8cc_ijk ( m, n, nz_num, col, row, i, j );

  if ( k == -1 )

  {

    cerr << "\n";

    cerr << "R8CC_INC - Fatal error!\n";

    cerr << "  R8CC_IJK could not find the entry.\n";

    cerr << "  Row I = " << i << "\n";

    cerr << "  Col J = " << j << "\n";

    exit ( 1 );

  }

  a[k-1] = a[k-1] + aij;

  return;

}

double *r8cc_indicator ( int m, int n, int nz_num, int col[], int row[] )

{

  double *a;

  int fac;

  int i;

  int j;

  int k;

  a = new double[nz_num];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( j = 1; j <= n; j++ )

  {

    for ( k = col[j-1]; k <= col[j] - 1; k++ )

    {

      i = row[k-1];

      a[k-1] = ( double ) ( fac * i + j );

    }

  }

  return a;

}

void r8cc_kij ( int m, int n, int nz_num, int col[], int row[], int k, 

  int *i, int *j )

{

  int jj;

  int k1;

  int k2;

  *i = -1;

  *j = -1;

  if ( k < 1 || nz_num < k )

  {

    return;

  }

  *i = row[k-1];

  for ( jj = 1; jj <= n; jj++ )

  {

    k1 = col[jj-1];

    k2 = col[jj]-1;

    if ( k1 <= k && k <= k2 )

    {

      *j = jj;

      break;

    }

  }

  if ( *j == -1 )

  {

    return;

  }

  return;

}

double *r8cc_mxv ( int m, int n, int nz_num, int col[], int row[], 

  double a[], double x[] )

{

  double *b;

  int i;

  int j;

  int k;

  b = new double[m];

  for ( i = 0; i < m; i++ )

  {

    b[i] = 0.0;

  }

  for ( j = 0; j < n; j++ )

  {

    for ( k = col[j]; k <= col[j+1] - 1; k++ )

    {

      i = row[k-1] - 1;

      b[i] = b[i] + a[k-1] * x[j];

    }

  }

  return b;

}

void r8cc_print ( int m, int n, int nz_num, int col[], int row[], 

  double a[], string title )

{

  r8cc_print_some ( m, n, nz_num, col, row, a, 1, 1, n, n, title );

  return;

}

void r8cc_print_some ( int m, int n, int nz_num, int col[], int row[], 

  double a[], int ilo, int jlo, int ihi, int jhi, string title )

{

# define INCX 5

  int i;

  int i2hi;

  int i2lo;

  int j;

  int j2hi;

  int j2lo;

  int k;

  double value;

  cout << "\n";

  cout << title << "\n";

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n );

    j2hi = i4_min ( j2hi, jhi );

    cout << "\n";

    cout << "  Col:  ";

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

      cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        value = 0.0;

        for ( k = col[j-1]; k <= col[j]-1; k++ )

        {

          if ( row[k-1] == i )

          {

            value = a[k-1];

          }

        }

        cout << setw(12) << value << "  ";

      }

      cout << "\n";

    }

  }

  return;

# undef INCX

}

double *r8cc_random ( int m, int n, int nz_num, int col[], int row[], 

  int *seed )

{

  double *a;

  int j;

  int k;

  a = new double[nz_num];

  for ( j = 0; j < n; j++ )

  {

    for ( k = col[j]; k <= col[j+1] - 1; k++ )

    {

      a[k-1] = r8_uniform_01 ( seed );

    }

  }

  return a;

}

void r8cc_read ( string col_file, string row_file, string a_file, int m, 

  int n, int nz_num, int col[], int row[], double a[] )

{

  ifstream input;

  int k;

  input.open ( col_file.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R8CC_READ - Fatal error!\n";

    cerr << "  Could not open the file \"" << col_file << "\".\n";

    exit ( 1 );

  }

  for ( k = 0; k < n+1; k++ )

  {

    input >> col[k];

  }

  input.close ( );

  input.open ( row_file.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R8CC_READ - Fatal error!\n";

    cerr << "  Could not open the file \"" << row_file << "\".\n";

    exit ( 1 );

  }

  for ( k = 0; k < nz_num; k++ )

  {

    input >> row[k];

  }

  input.close ( );

  input.open ( a_file.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R8CC_READ - Fatal error!\n";

    cerr << "  Could not open the file \"" << a_file << "\".\n";

    exit ( 1 );

  }

  for ( k = 0; k < nz_num; k++ )

  {

    input >> a[k];

  }

  input.close ( );

  return;

}

void r8cc_read_size ( string col_file, string row_file, int *m, int *n, 

  int *nz_num, int *base )

{

  int col;

  ifstream input;

  ifstream input2;

  int row;

  *m = -1;

  *n = -1;

  *nz_num = -1;

  *base = -1;

  input.open ( col_file.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R8CC_READ_SIZE - Fatal error!\n";

    cerr << "  Could not open the file \"" << col_file << "\".\n";

    exit ( 1 );

  }

  *n = -1;

  for ( ; ; )

  {

    input >> col;

    if ( input.eof( ) )

    {

      break;

    }

    *n = *n + 1;

  }

  input.close ( );

  input2.open ( row_file.c_str ( ) );

  if ( !input2 )

  {

    cerr << "\n";

    cerr << "R8CC_READ_SIZE - Fatal error!\n";

    cerr << "  Could not open the file \"" << row_file << "\".\n";

    exit ( 1 );

  }

  *base = 1;

  *m = 0;

  *nz_num = 0;

  

  for ( ; ; )

  {

    input2 >> row;

    if ( input2.eof ( ) )

    {

      break;

    }

    *nz_num = *nz_num + 1;

    *m = i4_max ( *m, row );

    if ( row == 0 )

    {

      *base = 0;

    }

  }

  input2.close ( );

  return;

}

void r8cc_set ( int m, int n, int nz_num, int col[], int row[], double a[], 

  int i, int j, double aij )

{

  int k;

  k = r8cc_ijk ( m, n, nz_num, col, row, i, j );

  if ( k == -1 )

  {

    cerr << "\n";

    cerr << "R8CC_SET - Fatal error!\n";

    cerr << "  R8CC_IJK could not find the entry.\n";

    cerr << "  Row I = " << i << "\n";

    cerr << "  Col J = " << j << "\n";

    exit ( 1 );

  }

  a[k-1] = aij;

  return;

}

double *r8cc_to_r8ge ( int m, int n, int nz_num, int col[], int row[], 

  double a[] )

{

  double *b;

  int i;

  int j;

  int k;

  b = new double[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      b[i+j*m] = 0.0;

    }

  }

  if ( col[0] < 0 || nz_num < col[0] )

  {

    cerr << "\n";

    cerr << "R8CC_TO_R8GE - Fatal error!\n";

    cerr << "  COL[" << j << "] = " << col[j] << "\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    if ( col[j+1] < 0 || nz_num < col[j+1] - 1 )

    {

      cerr << "\n";

      cerr << "R8CC_TO_R8GE - Fatal error!\n";

      cerr << "  COL[" << j+1 << "] = " << col[j+1] << "\n";

      exit ( 1 );

    }

    for ( k = col[j]; k <= col[j+1] - 1; k++ )

    {

      i = row[k-1] - 1;

      if ( i < 0 || m <= i )

      {

        cerr << "\n";

        cerr << "R8CC_TO_R8GE - Fatal error!\n";

        cerr << "  ROW[" << k-1 << "] = " << i << "\n";

        exit ( 1 );

      }

      b[i+j*m] = a[k-1];

    }

  }

  return b;

}

double *r8cc_vxm ( int m, int n, int nz_num, int col[], int row[], 

  double a[], double x[] )

{

  double *b;

  int i;

  int j;

  int k;

  b = new double[n];

  for ( j = 0; j < n; j++ )

  {

    b[j] = 0.0;

  }

  for ( j = 0; j < n; j++ )

  {

    for ( k = col[j]; k <= col[j+1] - 1; k++ )

    {

      i = row[k-1] - 1;

      b[j] = b[j] + a[k-1] * x[i];

    }

  }

  return b;

}

void r8cc_write ( string col_file, string row_file, string a_file, int m, int n,

  int nz_num, int col[], int row[], double a[] )

{

  ofstream output;

  int k;

  output.open ( col_file.c_str ( ) );

  if ( !output )

  {

    cerr << "\n";

    cerr << "R8CC_WRITE - Fatal error!\n";

    cerr << "  Could not open the file \"" << col_file << "\".\n";

    exit ( 1 );

  }

  for ( k = 0; k < n+1; k++ )

  {

    output << col[k] << "\n";

  }

  output.close ( );

  output.open ( row_file.c_str ( ) );

  if ( !output )

  {

    cerr << "\n";

    cerr << "R8CC_WRITE - Fatal error!\n";

    cerr << "  Could not open the file \"" << row_file << "\".\n";

    exit ( 1 );

  }

  for ( k = 0; k < nz_num; k++ )

  {

    output << row[k] << "\n";

  }

  output.close ( );

  output.open ( a_file.c_str ( ) );

  if ( !output )

  {

    cerr << "\n";

    cerr << "R8CC_WRITE - Fatal error!\n";

    cerr << "  Could not open the file \"" << a_file << "\".\n";

    exit ( 1 );

  }

  for ( k = 0; k < nz_num; k++ )

  {

    output << a[k] << "\n";

  }

  output.close ( );

  return;

}

double *r8cc_zero ( int m, int n, int nz_num, int col[], int row[] )

{

  double *a;

  int j;

  int k;

  a = new double[nz_num];

  for ( j = 0; j < n; j++ )

  {

    for ( k = col[j]; k <= col[j+1] - 1; k++ )

    {

      a[k-1] = 0.0;

    }

  }

  return a;

}

double *r8ci_eval ( int n, double a[] )

{

  int i;

  int j;

  double *lambda;

  double li;

  double lr;

  double *w;

  lambda = new double[2*n];

  w = c8vec_unity ( n );

  for ( i = 0; i < n; i++ )

  {

    lambda[0+i*2] = a[n-1];

    lambda[1+i*2] = 0.0;

  }

  for ( i = n-2; 0 <= i; i-- )

  {

    for ( j = 0; j < n; j++ )

    {

      lr = lambda[0+j*2] * w[0+j*2] 

         - lambda[1+j*2] * w[1+j*2] + a[i];

      li = lambda[0+j*2] * w[1+j*2]

         + lambda[1+j*2] * w[0+j*2];

      lambda[0+j*2] = lr;

      lambda[1+j*2] = li;

    }

  }

  c8vec_sort_a2 ( n, lambda );

  delete [] w;

  return lambda;

}

double *r8ci_indicator ( int n )

{

  double *a;

  int fac;

  int i;

  int j;

  a = new double[n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  i = 1;

  for ( j = 1; j <= n; j++ )

  {

    a[j-1] = ( double ) ( fac * i + j );

  }

  return a;

}

double *r8ci_mxv ( int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

    for ( j = 0; j <= i-1; j++ )

    {

      b[i] = b[i] + a[j-i+n] * x[j];

    }

    for ( j = i; j < n; j++ )

    {

      b[i] = b[i] + a[j-i] * x[j];

    }

  }

  return b;

}

void r8ci_print ( int n, double a[], string title )

{

  r8ci_print_some ( n, a, 1, 1, n, n, title );

  return;

}

void r8ci_print_some ( int n, double a[], int ilo, int jlo, int ihi, 

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

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, n );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(6) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( i <= j )

        {

          cout << setw(12) << a[j-i] << "  ";

        }

        else

        {

          cout << setw(12) << a[n+j-i] << "  ";

        }

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8ci_random ( int n, int *seed )

{

  double *a;

  int i;

  a = new double[n];

  for ( i = 0; i < n; i++ )

  {

    a[i] = r8_uniform_01 ( seed );

  }

  return a;

}

double *r8ci_sl ( int n, double a[], double b[], int job )

{

  int i;

  int nsub;

  double r1;

  double r2;

  double r3;

  double r5;

  double r6;

  double *work;

  double *x;

  work = new double[2*n-2];

  x = new double[n];

  if ( job == 0 )

  {

    r1 = a[0];

    x[0] = b[0] / r1;

    r2 = 0.0;

    for ( nsub = 2; nsub <= n; nsub++ )

    {

      r5 = a[n+2-nsub-1];

      r6 = a[nsub-1];

      if ( 2 < nsub )

      {

        work[nsub-2] = r2;

        for ( i = 1; i <= nsub - 2; i++ )

        {

          r5 = r5 + a[n-i] * work[nsub-i-1];

          r6 = r6 + a[i] * work[n-2+i];

        }

      }

      r2 = - r5 / r1;

      r3 = - r6 / r1;

      r1 = r1 + r5 * r3;

      if ( 2 < nsub )

      {

        r6 = work[n-1];

        work[n+nsub-3] = 0.0;

        for ( i = 2; i <= nsub - 1; i++ )

        {

          r5 = work[n-2+i];

          work[n-2+i] = work[i-1] * r3 + r6;

          work[i-1] = work[i-1] + r6 * r2;

          r6 = r5;

        }

      }

      work[n-1] = r3;

      r5 = 0.0;

      for ( i = 1; i <= nsub - 1; i++ )

      {

        r5 = r5 + a[n-i] * x[nsub-i-1];

      }

      r6 = ( b[nsub-1] - r5 ) / r1;

      for ( i = 1; i <= nsub-1; i++ )

      {

        x[i-1] = x[i-1] + work[n+i-2] * r6;

      }

      x[nsub-1] = r6;

    }

  }

  else

  {

    r1 = a[0];

    x[0] = b[0] / r1;

    r2 = 0.0;

    for ( nsub = 2; nsub <= n; nsub++ )

    {

      r5 = a[nsub-1];

      r6 = a[n+1-nsub];

      if ( 2 < nsub )

      {

        work[nsub-2] = r2;

        for ( i = 1; i <= nsub - 2; i++ )

        {

          r5 = r5 + a[i] * work[nsub-i-1];

          r6 = r6 + a[n-i] * work[n-2+i];

        }

      }

      r2 = - r5 / r1;

      r3 = - r6 / r1;

      r1 = r1 + r5 * r3;

      if ( 2 < nsub )

      {

        r6 = work[n-1];

        work[n+nsub-3] = 0.0;

        for ( i = 2; i <= nsub-1; i++ )

        {

          r5 = work[n-2+i];

          work[n-2+i] = work[i-1] * r3 + r6;

          work[i-1] = work[i-1] + r6 * r2;

          r6 = r5;

        }

      }

      work[n-1] = r3;

      r5 = 0.0;

      for ( i = 1; i <= nsub - 1; i++ )

      {

        r5 = r5 + a[i] * x[nsub-i-1];

      }

      r6 = ( b[nsub-1] - r5 ) / r1;

      for ( i = 1; i <= nsub - 1; i++ )

      {

        x[i-1] = x[i-1] + work[n-2+i] * r6;

      }

      x[nsub-1] = r6;

    }

  }

  delete [] work;

  return x;

}

double *r8ci_to_r8ge ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  int k;

  b = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 1; i < n; i++ )

    {

      k = i4_modp (  j - i, n );

      b[i+j*n] = a[k];

    }

  }

  return b;

}

double *r8ci_vxm ( int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

    for ( j = 0; j <= i; j++ )

    {

      b[i] = b[i] + a[i-j] * x[j];

    }

    for ( j = i+1; j < n; j++ )

    {

      b[i] = b[i] + a[n+i-j] * x[j];

    }

  }

  return b;

}

double *r8ci_zero ( int n )

{

  double *a;

  int i;

  a = new double[n];

  for ( i = 0; i < n; i++ )

  {

    a[i] = 0.0;

  }

  return a;

}

double r8gb_det ( int n, int ml, int mu, double a_lu[], int pivot[] )

{

  int col = 2 * ml + mu + 1;

  double det;

  int i;

  det = 1.0;

  for ( i = 0; i < n; i++ )

  {

    det = det * a_lu[ml+mu+i*col];

  }

  for ( i = 0; i < n; i++ )

  {

    if ( pivot[i] != i+1 ) 

    {

      det = -det;

    }

  }

  return det;

}

int r8gb_fa ( int n, int ml, int mu, double a[], int pivot[] )

{

  int col = 2 * ml + mu + 1;

  int i;

  int i0;

  int j;

  int j0;

  int j1;

  int ju;

  int jz;

  int k;

  int l;

  int lm;

  int m;

  int mm;

  double t;

  m = ml + mu + 1;

  j0 = mu + 2;

  j1 = i4_min ( n, m ) - 1;

  for ( jz = j0; jz <= j1; jz++ )

  {

    i0 = m + 1 - jz;

    for ( i = i0; i <= ml; i++ )

    {

      a[i-1+(jz-1)*col] = 0.0;

    }

  }

  jz = j1;

  ju = 0;

  for ( k = 1; k <= n-1; k++ )

  {

    jz = jz + 1;

    if ( jz <= n ) 

    {

      for ( i = 1; i <= ml; i++ )

      {

        a[i-1+(jz-1)*col] = 0.0;

      }

    }

    lm = i4_min ( ml, n-k );

    l = m;

    for ( j = m+1; j <= m + lm; j++ )

    {

      if ( r8_abs ( a[l-1+(k-1)*col] ) < r8_abs ( a[j-1+(k-1)*col] ) )

      {

        l = j;

      }

    }

    pivot[k-1] = l + k - m;

    if ( a[l-1+(k-1)*col] == 0.0 )

    {

      cerr << "\n";

      cerr << "R8GB_FA - Fatal error!\n";

      cerr << "  Zero pivot on step " << k << "\n";

      exit ( 1 );

    }

    t                = a[l-1+(k-1)*col];

    a[l-1+(k-1)*col] = a[m-1+(k-1)*col];

    a[m-1+(k-1)*col] = t;

    for ( i = m+1; i <= m+lm; i++ )

    {

      a[i-1+(k-1)*col] = - a[i-1+(k-1)*col] / a[m-1+(k-1)*col];

    }

    ju = i4_max ( ju, mu + pivot[k-1] );

    ju = i4_min ( ju, n );

    mm = m;

    for ( j = k+1; j <= ju; j++ )

    {

      l = l - 1;

      mm = mm - 1;

      if ( l != mm )

      {

        t                 = a[l-1+(j-1)*col];

        a[l-1+(j-1)*col]  = a[mm-1+(j-1)*col];

        a[mm-1+(j-1)*col] = t;

      }

      for ( i = 1; i <= lm; i++ )

      {

        a[mm+i-1+(j-1)*col] = a[mm+i-1+(j-1)*col] 

          + a[mm-1+(j-1)*col] * a[m+i-1+(k-1)*col];

      }

    }

  }

  pivot[n-1] = n;

  if ( a[m-1+(n-1)*col] == 0.0 )

  {

    cerr << "\n";

    cerr << "R8GB_FA - Fatal error!\n";

    cerr << "  Zero pivot on step " << n << "\n";

    exit ( 1 );

  }

  return 0;

}

double *r8gb_indicator ( int m, int n, int ml, int mu )

{

  double *a;

  int col = 2 * ml + mu + 1;

  int diag;

  int fac;

  int i;

  int j;

  int k;

  a = new double[(2*ml+mu+1)*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  k = 0;

  for ( j = 1; j <= n; j++ )

  {

    for ( diag = 1; diag <= 2 * ml + mu + 1; diag++ )

    {

      i = diag + j - ml - mu - 1;

      if ( 1 <= i && i <= m && i - ml <= j && j <= i + mu )

      {

        a[diag-1+(j-1)*col] = ( double ) ( fac * i + j );

      }

      else if ( 1 <= i && i <= m && i - ml <= j && j <= i + mu + ml )

      {

        a[diag-1+(j-1)*col] = 0.0;

      }

      else

      {

        k = k + 1;

        a[diag-1+(j-1)*col] = - ( double ) k;

      }

    }

  }

  return a;

}

double *r8gb_ml ( int n, int ml, int mu, double a_lu[], int pivot[], double x[], 

  int job )

{

  double *b;

  int col = 2 * ml + mu + 1;

  int i;

  int ihi;

  int ilo;

  int j;

  int jhi;

  int k;

  double temp;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = x[i];

  }

  if ( job == 0 )

  {

    for ( j = 1; j <= n; j++ )

    {

      ilo = i4_max ( 1, j - ml - mu );

      for ( i = ilo; i <= j-1; i++ )

      {

        b[i-1] = b[i-1] + a_lu[i-j+ml+mu+(j-1)*col] * b[j-1];

      }

      b[j-1] = a_lu[j-j+ml+mu+(j-1)*col] * b[j-1];

    }

    for ( j = n-1; 1 <= j; j-- )

    {

      ihi = i4_min ( n, j + ml );

      for ( i = j+1; i <= ihi; i++ )

      {

        b[i-1] = b[i-1] - a_lu[i-j+ml+mu+(j-1)*col] * b[j-1];

      }

      k = pivot[j-1];

      if ( k != j )

      {

        temp   = b[k-1];

        b[k-1] = b[j-1];

        b[j-1] = temp;

      }

    }

  }

  else

  {

    for ( j = 1; j <= n-1; j++ )

    {

      k = pivot[j-1];

      if ( k != j )

      {

        temp   = b[k-1];

        b[k-1] = b[j-1];

        b[j-1] = temp;

      }

      jhi = i4_min ( n, j + ml );

      for ( i = j+1; i <= jhi; i++ )

      {

        b[j-1] = b[j-1] - b[i-1] * a_lu[i-j+ml+mu+(j-1)*col];

      }

    }

    for ( i = n; 1 <= i; i-- )

    {

      jhi = i4_min ( n, i + ml + mu );

      for ( j = i+1; j <= jhi; j++ )

      {

        b[j-1] = b[j-1] + b[i-1] * a_lu[i-j+ml+mu+(j-1)*col];

      }

      b[i-1] = b[i-1] * a_lu[i-i+ml+mu+(i-1)*col];

    }

  }

  return b;

}

double *r8gb_mu ( int n, int ml, int mu, double a_lu[], int pivot[], double x[], 

  int job )

{

  double *b;

  int i;

  int ihi;

  int ilo;

  int j;

  int jhi;

  int k;

  double t;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = x[i];

  }

  if ( job == 0 )

  {

    for ( j = 1; j <= n; j++ )

    {

      ilo = i4_max ( 1, j - ml - mu );

      for ( i = ilo; i <= j - 1; i++ )

      {

        b[i-1] = b[i-1] + a_lu[i-j+ml+mu+(j-1)*(2*ml+mu+1)] * b[j-1];

      }

      b[j-1] = a_lu[j-j+ml+mu+(j-1)*(2*ml+mu+1)] * b[j-1];

    }

    for ( j = n-1; 1 <= j; j-- )

    {

      ihi = i4_min ( n, j + ml );

      for ( i = j+1; i <= ihi; i++ )

      {

        b[i-1] = b[i-1] + a_lu[i-j+ml+mu+(j-1)*(2*ml+mu+1)] * b[j-1];

      }

      k = pivot[j-1];

      if ( k != j )

      {

        t      = b[k-1];

        b[k-1] = b[j-1];

        b[j-1] = t;

      }

    }

  }

  else

  {

    for ( j = 1; j <= n-1; j++ )

    {

      k = pivot[j-1];

      if ( k != j )

      {

        t      = b[k-1];

        b[k-1] = b[j-1];

        b[j-1] = t;

      }

      jhi = i4_min ( n, j + ml );

      for ( i = j+1; i <= jhi; i++ )

      {

        b[j-1] = b[j-1] + b[i-1] * a_lu[i-j+ml+mu+(j-1)*(2*ml+mu+1)];

      }

    }

    for ( i = n; 1 <= i; i-- )

    {

      jhi = i4_min ( n, i + ml + mu );

      for ( j = i+1; j <= jhi; j++ )

      {

        b[j-1] = b[j-1] + b[i-1] * a_lu[i-j+ml+mu+(j-1)*(2*ml+mu+1)];

      }

      b[i-1] = b[i-1] * a_lu[i-i+ml+mu+(i-1)*(2*ml+mu+1)];

    }

  }

  return b;

}

double *r8gb_mxv ( int m, int n, int ml, int mu, double a[], double x[] )

{

  double *b;

  int col = 2 * ml + mu + 1;

  int i;

  int j;

  int jhi;

  int jlo;

  b = new double[m];

  for ( i = 1; i <= m; i++ )

  {

    b[i-1] = 0.0;

    jlo = i4_max ( 1, i - ml );

    jhi = i4_min ( n, i + mu );

    for ( j = jlo; j <= jhi; j++ )

    {

      b[i-1] = b[i-1] + a[i-j+ml+mu+(j-1)*col] * x[j-1];

    }

  }

  return b;

}

int r8gb_nz_num ( int m, int n, int ml, int mu, double a[] )

{

  int i;

  int j;

  int jhi;

  int jlo;

  int nz_num;

  nz_num = 0;

  for ( i = 0; i < m; i++ )

  {

    jlo = i4_max ( 0, i - ml );

    jhi = i4_min ( n-1, i + mu + ml );

    for ( j = jlo; j <= jhi; j++ )

    {

      if ( a[i-j+ml+mu+j*(2*ml+mu+1)] != 0.0 )

      {

        nz_num = nz_num + 1;

      }

    }

  }

  return nz_num;

}

void r8gb_print ( int m, int n, int ml, int mu, double a[], string title )

{

  r8gb_print_some ( m, n, ml, mu, a, 1, 1, m, n, title );

  return;

}

void r8gb_print_some ( int m, int n, int ml, int mu, double a[], int ilo, 

  int jlo, int ihi, int jhi, string title )

{

# define INCX 5

  int col = 2 * ml + mu + 1;

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

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2lo = i4_max ( i2lo, j2lo - mu - ml );

    i2hi = i4_min ( ihi, m );

    i2hi = i4_min ( i2hi, j2hi + ml );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(6) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( i < j - mu - ml || j + ml < i )

        {

          cout << "            ";

        }

        else

        {

          cout << setw(10) << a[i-j+ml+mu+(j-1)*col] << "  ";

        }

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8gb_random ( int m, int n, int ml, int mu, int *seed )

{

  double *a;

  int col = 2 * ml + mu + 1;

  int i;

  int j;

  int row;

  a = new double[col*n];

  for ( j = 1; j <= n; j++ )

  {

    for ( row = 1; row <= col; row++ )

    {

      i = row + j - ml - mu - 1;

      if ( ml < row && 1 <= i && i <= m )

      {

        a[row-1+(j-1)*col] = r8_uniform_01 ( seed );

      }

      else

      {

        a[(row-1)+(j-1)*col] = 0.0;

      }

    }

  }

  return a;

}

double *r8gb_sl ( int n, int ml, int mu, double a_lu[], int pivot[], 

  double b[], int job )

{

  int col = 2 * ml + mu + 1;

  int i;

  int k;

  int l;

  int la;

  int lb;

  int lm;

  int m;

  double t;

  double *x;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  m = mu + ml + 1;

  if ( job == 0 )

  {

    if ( 1 <= ml )

    {

      for ( k = 1; k <= n-1; k++ )

      {

        lm = i4_min ( ml, n-k );

        l = pivot[k-1];

        if ( l != k )

        {

          t      = x[l-1];

          x[l-1] = x[k-1];

          x[k-1] = t;

        }

        for ( i = 1; i <= lm; i++ )

        {

          x[k+i-1] = x[k+i-1] + x[k-1] * a_lu[m+i-1+(k-1)*col];

        }

      }

    }

    for ( k = n; 1 <= k; k-- )

    {

      x[k-1] = x[k-1] / a_lu[m-1+(k-1)*col];

      lm = i4_min ( k, m ) - 1;

      la = m - lm;

      lb = k - lm;

      for ( i = 0; i <= lm-1; i++ )

      {

        x[lb+i-1] = x[lb+i-1] - x[k-1] * a_lu[la+i-1+(k-1)*col];

      }

    }

  }

  else

  {

    for ( k = 1; k <= n; k++ )

    {

      lm = i4_min ( k, m ) - 1;

      la = m - lm;

      lb = k - lm;

      for ( i = 0; i <= lm-1; i++ )

      {

        x[k-1] = x[k-1] - x[lb+i-1] * a_lu[la+i-1+(k-1)*col];

      }

      x[k-1] = x[k-1] / a_lu[m-1+(k-1)*col];

    }

    if ( 1 <= ml )

    {

      for ( k = n-1; 1 <= k; k-- )

      {

        lm = i4_min ( ml, n-k );

        for ( i = 1; i <= lm; i++ )

        {

          x[k-1] = x[k-1] + x[k+i-1] * a_lu[m+i-1+(k-1)*col];

        }

        l = pivot[k-1];

        if ( l != k )

        {

          t      = x[l-1];

          x[l-1] = x[k-1];

          x[k-1] = t;

        }

      }

    }

  }

  return x;

}

void r8gb_to_r8s3 ( int m, int n, int ml, int mu, double a[], int nz_num, 

  int *isym, int row[], int col[], double b[] )

{

  int i;

  int j;

  int nz;

  *isym = 0;

  nz = 0;

  for ( i = 1; i <= m; i++ )

  {

    for ( j = 1; j <= n; j++ )

    {

      if ( i - ml <= j && j <= i + mu + ml )

      {

        if ( a[ml+mu+1+i-j-1+(j-1)*(2*ml+mu+1)] != 0.0 )

        {

          if ( nz_num <= nz )

          {

            cerr << "\n";

            cerr << "R8GB_TO_R8S3 - Fatal error!\n";

            cerr << "  NZ_NUM = " << nz_num << "\n";

            cerr << "  But the matrix has more nonzeros than that!\n";

            exit ( 1 );

          }

          row[nz] = i;

          col[nz] = j;

          b[nz] = a[ml+mu+1+i-j-1+(j-1)*(2*ml+mu+1)];

          nz = nz + 1;

        }

      }

    }

  }

  if ( nz < nz_num )

  {

    cout << "\n";

    cout << "R8GB_TO_R8S3 - Warning!\n";

    cout << "  NZ_NUM = " << nz_num << "\n";

    cout << "  But the number of nonzeros is " << nz << "\n";

  }

  return;

}

void r8gb_to_r8sp ( int m, int n, int ml, int mu, double a[], int nz_num, 

  int row[], int col[], double b[] )

{

  int i;

  int j;

  int jhi;

  int jlo;

  int nz;

  nz = 0;

  for ( i = 1; i <= m; i++ )

  {

    jlo = i4_max ( 1, i - ml );

    jhi = i4_min ( n, i + ml + mu );

    for ( j = jlo; j <= jhi; j++ )

    {

      if ( a[ml+mu+1+i-j-1+(j-1)*(2*ml+mu+1)] == 0.0 )

      {

        continue;

      }

      if ( nz_num <= nz )

      {

        cerr << "\n";

        cerr << "R8GB_TO_R8SP - Fatal error!\n";

        cerr << "  NZ_NUM = " << nz_num << "\n";

        cerr << "  But the matrix has more nonzeros than that!\n";

        exit ( 1 );

      }

      row[nz] = i;

      col[nz] = j;

      b[nz] = a[ml+mu+1+i-j-1+(j-1)*(2*ml+mu+1)];

      nz = nz + 1;

    }

  }

  if ( nz < nz_num )

  {

    cout << "\n";

    cout << "R8GB_TO_R8SP - Warning!\n";

    cout << "  NZ_NUM = " << nz_num << "\n";

    cout << "  But the number of nonzeros is " << nz << "\n";

  }

  return;

}

double *r8gb_to_r8vec ( int m, int n, int ml, int mu, double *a )

{

  int i;

  int ihi;

  int ilo;

  int j;

  double *x;

  x = new double[(2*ml+mu+1)*n];

  for ( j = 1; j <= n; j++ )

  {

    ihi = i4_min ( ml + mu, ml + mu + 1 - j );

    for ( i = 1; i <= ihi; i++ )

    {

      x[i-1+(j-1)*(2*ml+mu+1)] = 0.0;

    }

    ilo = i4_max ( ihi + 1, 1 );

    ihi = i4_min ( 2*ml+mu+1, ml+mu+m+1-j );

    for ( i = ilo; i <= ihi; i++ )

    {

      x[i-1+(j-1)*(2*ml+mu+1)] = a[i-1+(j-1)*(2*ml+mu+1)];

    }

    ilo = ihi + 1;

    ihi = 2*ml+mu+1;

    for ( i = ilo; i <= ihi; i++ )

    {

      x[i-1+(j-1)*(2*ml+mu+1)] = 0.0;

    }

  }

  return x;

}

double *r8gb_to_r8ge ( int m, int n, int ml, int mu, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[m*n];

  for ( i = 1; i <= m; i++ )

  {

    for ( j = 1; j <= n; j++ )

    {

      if ( i - ml <= j && j <= i + mu )

      {

        b[i-1+(j-1)*m] = a[ml+mu+i-j+(j-1)*(2*ml+mu+1)];

      }

      else

      {

        b[i-1+(j-1)*m] = 0.0;

      }

    }

  }

  return b;

}

int r8gb_trf ( int m, int n, int ml, int mu, double a[], int pivot[] )

{

  int i;

  int info;

  int j;

  int jp;

  int ju;

  int k;

  int km;

  int kv;

  double piv;

  double temp;

  info = 0;

  kv = mu + ml;

  for ( j = mu+2; j <= i4_min ( kv, n ); j++ )

  {

    for ( i = kv - j + 1; i <= ml; i++ )

    {

      a[i-1+(j-1)*(2*ml+mu+1)] = 0.0;

    }

  }

  ju = 1;

  for ( j = 1; j <= i4_min ( m, n ); j++ )

  {

    if ( j + kv <= n )

    {

      for ( i = 1; i <= ml; i++ )

      {

        a[i-1+(j+kv-1)*(2*ml+mu+1)] = 0.0;

      }

    }

    km = i4_min ( ml, m-j );

    piv = r8_abs ( a[kv+(j-1)*(2*ml+mu+1)] );

    jp = kv + 1;

    for ( i = kv + 2; i <= kv + km + 1; i++ )

    {

      if ( piv < r8_abs ( a[i-1+(j-1)*(2*ml+mu+1)] ) )

      {

        piv = r8_abs ( a[i-1+(j-1)*(2*ml+mu+1)] );

        jp = i;

      }

    }

    jp = jp - kv;

    pivot[j-1] = jp + j - 1;

    if ( a[kv+jp-1+(j-1)*(2*ml+mu+1)] != 0.0 )

    {

      ju = i4_max ( ju, i4_min ( j+mu+jp-1, n ) );

      if ( jp != 1 )

      {

        for ( i = 0; i <= ju - j; i++ )

        {

          temp = a[kv+jp-i-1+(j+i-1)*(2*ml+mu+1)];

          a[kv+jp-i-1+(j+i-1)*(2*ml+mu+1)] = a[kv+1-i-1+(j+i-1)*(2*ml+mu+1)];

          a[kv+1-i-1+(j+i-1)*(2*ml+mu+1)] = temp; 

        }

      }

      if ( 0 < km )

      {

        for ( i = kv+2; i <= kv+km+1; i++ )

        {

          a[i-1+(j-1)*(2*ml+mu+1)] = a[i-1+(j-1)*(2*ml+mu+1)] 

            / a[kv+(j-1)*(2*ml+mu+1)];

        }

        if ( j < ju )

        {

          for ( k = 1; k <= ju - j; k++ )

          {

            if ( a[kv-k+(j+k-1)*(2*ml+mu+1)] != 0.0 )

            {

              for ( i = 1; i <= km; i++ )

              {

                a[kv+i-k+(j+k-1)*(2*ml+mu+1)] = a[kv+i-k+(j+k-1)*(2*ml+mu+1)] 

                  - a[kv+i+(j-1)*(2*ml+mu+1)] * a[kv-k+(j+k-1)*(2*ml+mu+1)];

              }

            }

          }

        }

      }

    }

    else

    {

      if ( info == 0 )

      {

        info = j;

      }

    }

  }

  return info;

}

double *r8gb_trs ( int n, int ml, int mu, int nrhs, char trans, double a[], 

  int pivot[], double b[] )

{

  int i;

  int j;

  int k;

  int kd;

  int l;

  int lm;

  double temp;

  double *x;

  if ( trans != 'N' && trans != 'n' &&

       trans != 'T' && trans != 't' &&

       trans != 'C' && trans != 'c' )

  {

    return NULL;

  }

  else if ( n <= 0 )

  {

    return NULL;

  }

  else if ( ml < 0 )

  {

    return NULL;

  }

  else if ( mu < 0 )

  {

    return NULL;

  }

  else if ( nrhs <= 0 )

  {

    return NULL;

  }

  x = new double[n*nrhs];

  for ( k = 0; k < nrhs; k++ )

  {

    for ( i = 0; i < n; i++ )

    {

      x[i+k*n] = b[i+k*n];

    }

  }

  kd = mu + ml + 1;

  if ( trans == 'N' || trans == 'n' )

  {

    if ( 0 < ml )

    {

      for ( j = 1; j <= n-1; j++ )

      {

        lm = i4_min ( ml, n-j );

        l = pivot[j-1];

        for ( k = 0; k < nrhs; k++ )

        {

          temp       = x[l-1+k*n];

          x[l-1+k*n] = x[j-1+k*n];

          x[j-1+k*n] = temp;

        }

        for ( k = 0; k < nrhs; k++ )

        {

          if ( x[j-1+k*n] != 0.0 )

          {

            for ( i = 1; i <= lm; i++ )

            {

              x[j+i-1+k*n] = x[j+i-1+k*n] 

                - a[kd+i-1+(j-1)*(2*ml+mu+1)] * x[j-1+k*n];

            }

          }

        }

      }

    }

    for ( k = 0; k < nrhs; k++ )

    {

      for ( j = n; 1 <= j; j-- )

      {

        if ( x[j-1+k*n] != 0.0 )

        {

          l = ml + mu + 1 - j;

          x[j-1+k*n] = x[j-1+k*n] / a[ml+mu+(j-1)*(2*ml+mu+1)];

          for ( i = j - 1; i4_max ( 1, j - ml - mu ) <= i; i-- )

          {

            x[i-1+k*n] = x[i-1+k*n] 

              - a[l+i-1+(j-1)*(2*ml+mu+1)] * x[j-1+k*n];

          }

        }

      }

    }

  }

  else

  {

    for ( k = 0; k < nrhs; k++ )

    {

      for ( j = 1; j <= n; j++ )

      {

        temp = x[j-1+k*n];

        l = ml + mu + 1 - j;

        for ( i = i4_max ( 1, j - ml - mu ); i <= j - 1; i++ )

        {

          temp = temp - a[l+i-1+(j-1)*(2*ml+mu+1)] * x[i-1+k*n];

        }

        x[j-1+k*n] = temp / a[ml+mu+(j-1)*(2*ml+mu+1)];

      }

    }

    if ( 0 < ml )

    {

      for ( j = n-1; 1 <= j; j-- )

      {

        lm = i4_min ( ml, n-j );

        for ( k = 0; k < nrhs; k++ )

        {

          for ( i = 1; i <= lm; i++ )

          {

            x[j-1+k*n] = x[j-1+k*n] 

              - x[j+i-1+k*n] * a[kd+i-1+(j-1)*(2*ml+mu+1)];

          }

        }

        l = pivot[j-1];

        for ( k = 0; k < nrhs; k++ )

        {

          temp       = x[l-1+k*n];

          x[l-1+k*n] = x[j-1+k*n];

          x[j-1+k*n] = temp;

        }

      }

    }

  }

  return x;

}

double *r8gb_vxm ( int m, int n, int ml, int mu, double a[], double x[] )

{

  double *b;

  int col = 2 * ml + mu + 1;

  int i;

  int ihi;

  int ilo;

  int j;

  b = new double[n];

  for ( j = 1; j <= n; j++ )

  {

    b[j-1] = 0.0;

    ilo = i4_max ( 1, j - mu );

    ihi = i4_min ( m, j + ml );

    for ( i = ilo; i <= ihi; i++ )

    {

      b[j-1] = b[j-1] + x[i-1] * a[i-j+ml+mu+(j-1)*col];

    }

  }

  return b;

}

double *r8gb_zero ( int m, int n, int ml, int mu )

{

  double *a;

  int col = 2 * ml + mu + 1;

  int j;

  int row;

  a = new double[col*n];

  for ( j = 0; j < n; j++ )

  {

    for ( row = 0; row < col; row++ )

    {

      a[row+j*col] = 0.0;

    }

  }

  return a;

}

bool r8gd_error ( int n, int ndiag )

{

  if ( n < 1 )

  {

    cout << "\n";

    cout << "R8GD_ERROR - Illegal N = " << n << "\n";

    return true;

  }

  if ( ndiag < 1 || 2 * n - 1 < ndiag )

  {

    cout << "\n";

    cout << "R8GD_ERROR - Illegal NDIAG = " << ndiag << "\n";

    return true;

  }

  return false;

}

double *r8gd_indicator ( int n, int ndiag, int offset[] )

{

  double *a;

  int diag;

  int fac;

  int i;

  int j;

  a = new double[n*ndiag];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( i = 1; i <= n; i++ )

  {

    for ( diag = 1; diag <= ndiag; diag++ )

    {

      j = i + offset[diag-1];

      if ( 1 <= j && j <= n )

      {

        a[i-1+(diag-1)*n] = ( double ) ( fac * i + j );

      }

      else

      {

        a[i-1+(diag-1)*n] = 0.0;

      }

    }

  }

  return a;

}

double *r8gd_mxv ( int n, int ndiag, int offset[], double a[], double x[] )

{

  double *b;

  int diag;

  int i;

  int j;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

  }

  for ( i = 0; i < n; i++ )

  {

    for ( diag = 0; diag < ndiag; diag++ )

    {

      j = i + offset[diag];

      if ( 0 <= j && j < n )

      {

        b[i] = b[i] + a[i+diag*n] * x[j];

      }

    }

  }

  return b;

}

void r8gd_print ( int n, int ndiag, int offset[], double a[], string title )

{

  r8gd_print_some ( n, ndiag, offset, a, 1, 1, n, n, title );

  return;

}

void r8gd_print_some ( int n, int ndiag, int offset[], double a[], int ilo, 

  int jlo, int ihi, int jhi, string title )

{

# define INCX 5

  double aij;

  int diag;

  int i;

  int i2hi;

  int i2lo;

  int j;

  int j2;

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

    cout << "  Col:  ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, n );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j2 = j2lo; j2 <= j2hi; j2++ )

      {

        aij = 0.0;

        for ( diag = 0; diag < ndiag; diag++ )

        {

          if ( j2 - i == offset[diag] )

          {

            aij = a[i-1+diag*n];

          }

        }

        cout << setw(12) << aij << "  ";

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8gd_random ( int n, int ndiag, int offset[], int *seed )

{

  double *a;

  int diag;

  int i;

  int j;

  a = new double[n*ndiag];

  for ( i = 1; i <= n; i++ )

  {

    for ( diag = 0; diag < ndiag; diag++ )

    {

      j = i + offset[diag];

      if ( 1 <= j && j <= n )

      {

        a[i-1+diag*n] = r8_uniform_01 ( seed );

      }

      else

      {

        a[i-1+diag*n] = 0.0;

      }

    }

  }

  return a;

}

double *r8gd_to_r8ge ( int n, int ndiag, int offset[], double a[] )

{

  double *b;

  int diag;

  int i;

  int j;

  b = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      b[i+j*n] = 0.0;

    }

  }

  for ( i = 0; i < n; i++ )

  {

    for ( diag = 0; diag < ndiag; diag++ )

    {

      j = i + offset[diag];

      if ( 0 <= j && j <= n-1 )

      {

        b[i+j*n] = a[i+diag*n];

      }

    }

  }

  return b;

}

double *r8gd_vxm ( int n, int ndiag, int offset[], double a[], double x[] )

{

  double *b;

  int diag;

  int i;

  int j;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

  }

  for ( i = 0; i < n; i++ )

  {

    for ( diag = 0; diag < ndiag; diag++ )

    {

      j = i + offset[diag];

      if ( 0 <= j && j < n )

      {

        b[j] = b[j] + x[i] * a[i+diag*n];

      }

    }

  }

  return b;

}

double *r8gd_zero ( int n, int ndiag )

{

  double *a;

  int diag;

  int i;

  a = new double[n*ndiag];

  for ( diag = 0; diag < ndiag; diag++ )

  {

    for ( i = 0; i < n; i++ )

    {

      a[i+diag*n] = 0.0;

    }

  }

  return a;

}

double r8ge_co ( int n, double a[], int pivot[] )

{

  double anorm;

  double ek;

  int i;

  int info;

  int j;

  int k;

  int l;

  double rcond;

  double s;

  double sm;

  double t;

  double wk;

  double wkm;

  double ynorm;

  double *z;

  anorm = 0.0;

  for ( j = 0; j < n; j++ )

  {

    s = 0.0;

    for ( i = 0; i < n; i++ )

    {

      s = s + r8_abs ( a[i+j*n] );

    }

    anorm = r8_max ( anorm, s );

  }

  info = r8ge_fa ( n, a, pivot );

  if ( info != 0 ) 

  {

    rcond = 0.0;

    return rcond;

  }

  ek = 1.0;

  z = new double[n];

  for ( i = 0; i < n; i++ )

  {

    z[i] = 0.0;

  }

  for ( k = 0; k < n; k++ )

  {

    if ( z[k] != 0.0 ) 

    {

      ek = - r8_sign2 ( ek, z[k] );

    }

    if ( r8_abs ( a[k+k*n] ) < r8_abs ( ek - z[k] ) )

    {

      s = r8_abs ( a[k+k*n] ) / r8_abs ( ek - z[k] );

      for ( i = 0; i < n; i++ )

      {

        z[i] = s * z[i];

      }

      ek = s * ek;

    }

    wk = ek - z[k];

    wkm = -ek - z[k];

    s = r8_abs ( wk );

    sm = r8_abs ( wkm );

    if ( a[k+k*n] != 0.0 )

    {

      wk = wk / a[k+k*n];

      wkm = wkm / a[k+k*n];

    }

    else

    {

      wk = 1.0;

      wkm = 1.0;

    }

    if ( k + 2 <= n )

    {

      for ( j = k+1; j < n; j++ )

      {

        sm = sm + r8_abs ( z[j] + wkm * a[k+j*n] );

        z[j] = z[j] + wk * a[k+j*n];

        s = s + r8_abs ( z[j] );

      }

      if ( s < sm )

      {

        t = wkm - wk;

        wk = wkm;

        for ( j = k+1; j < n; j++ )

        {

          z[j] = z[j] + t * a[k+j*n];

        }

      }

    }

    z[k] = wk;

  }

  s = 0.0;

  for ( i = 0; i < n; i++ )

  {

    s = s + r8_abs ( z[i] );

  }

  for ( i = 0; i < n; i++ )

  {

    z[i] = z[i] / s;

  }

  for ( k = n-1; 0 <= k; k-- )

  {

    for ( i = k+1; i < n; i++ )

    {

      z[k] = z[k] + z[i] * a[i+k*n];

    }

    t = r8_abs ( z[k] );

    if ( 1.0 < t )

    {

      for ( i = 0; i < n; i++ )

      {

        z[i] = z[i] / t;

      }

    }

    l = pivot[k] - 1;

    t    = z[l];

    z[l] = z[k];

    z[k] = t;

  }

  t = 0.0;

  for ( i = 0; i < n; i++ )

  {

    t = t + r8_abs ( z[i] );

  }

  for ( i = 0; i < n; i++ )

  {

    z[i] = z[i] / t;

  }

  ynorm = 1.0;

  for ( k = 0; k < n; k++ )

  {

    l = pivot[k] - 1;

    t    = z[l];

    z[l] = z[k];

    z[k] = t;

    for ( i = k+1; i < n; i++ )

    {

      z[i] = z[i] + t * a[i+k*n];

    }

    t = r8_abs ( z[k] );

    if ( 1.0 < t )

    {

      ynorm = ynorm / t;

      for ( i = 0; i < n; i++ )

      {

        z[i] = z[i] / t;

      }

    }

  }

  s = 0.0;

  for ( i = 0; i < n; i++ )

  {

    s = s + r8_abs ( z[i] );

  }

  for ( i = 0; i < n; i++ )

  {

    z[i] = z[i] / s;

  }

  ynorm = ynorm / s;

  for ( k = n-1; 0 <= k; k-- )

  {

    if ( r8_abs ( a[k+k*n] ) < r8_abs ( z[k] ) )

    {

      s = r8_abs ( a[k+k*n] ) / r8_abs ( z[k] );

      for ( i = 0; i < n; i++ )

      {

        z[i] = s * z[i];

      }

      ynorm = s * ynorm;

    }

    if ( a[k+k*n] != 0.0 )

    {

      z[k] = z[k] / a[k+k*n];

    }

    else

    {

      z[k] = 1.0;

    }

    for ( i = 0; i < k; i++ )

    {

      z[i] = z[i] - a[i+k*n] * z[k];

    }

  }

  s = 0.0;

  for ( i = 0; i < n; i++ )

  {

    s = s + r8_abs ( z[i] );

  }

  s = 1.0 / s;

  for ( i = 0; i < n; i++ )

  {

    z[i] = s * z[i];

  }

  ynorm = s * ynorm;

  if ( anorm != 0.0 )

  {

    rcond = ynorm / anorm;

  }

  else

  {

    rcond = 0.0;

  }

  delete [] z;

  return rcond;

}

double r8ge_det ( int n, double a_lu[], int pivot[] )

{

  double det;

  int i;

  det = 1.0;

  for ( i = 1; i <= n; i++ )

  {

    det = det * a_lu[i-1+(i-1)*n];

    if ( pivot[i-1] != i )

    {

      det = -det;

    }

  }

  return det;

}

double *r8ge_dilu ( int m, int n, double a[] )

{

  double *d;

  int i;

  int j;

  d = new double[m];

  for ( i = 0; i < m; i++ )

  {

    if ( i < n ) 

    {

      d[i] = a[i+i*m];

    }

    else

    {

      d[i] = 0.0;

    }

  }

  for ( i = 0; i < m && i < n; i++ )

  {

    d[i] = 1.0 / d[i];

    for ( j = i+1; j < m && j < n; j++ )

    {

      d[j] = d[j] - a[j+i*m] * d[i] * a[i+j*m];

    }

  }

  return d;

}

int r8ge_fa ( int n, double a[], int pivot[] )

{

  int i;

  int j;

  int k;

  int l;

  double t;

  for ( k = 1; k <= n-1; k++ )

  {

    l = k;

    for ( i = k+1; i <= n; i++ )

    {

      if ( r8_abs ( a[l-1+(k-1)*n] ) < r8_abs ( a[i-1+(k-1)*n] ) )

      {

        l = i;

      }

    }

    pivot[k-1] = l;

    if ( a[l-1+(k-1)*n] == 0.0 )

    {

      cerr << "\n";

      cerr << "R8GE_FA - Fatal error!\n";

      cerr << "  Zero pivot on step " << k << "\n";

      exit ( 1 );

    }

    if ( l != k )

    {

      t              = a[l-1+(k-1)*n];

      a[l-1+(k-1)*n] = a[k-1+(k-1)*n];

      a[k-1+(k-1)*n] = t;

    }

    for ( i = k+1; i <= n; i++ )

    {

      a[i-1+(k-1)*n] = -a[i-1+(k-1)*n] / a[k-1+(k-1)*n];

    }

    for ( j = k+1; j <= n; j++ )

    {

      if ( l != k )

      {

        t              = a[l-1+(j-1)*n];

        a[l-1+(j-1)*n] = a[k-1+(j-1)*n];

        a[k-1+(j-1)*n] = t;

      }

      for ( i = k+1; i <= n; i++ )

      {

        a[i-1+(j-1)*n] = a[i-1+(j-1)*n] + a[i-1+(k-1)*n] * a[k-1+(j-1)*n];

      }

    }

  }

  pivot[n-1] = n;

  if ( a[n-1+(n-1)*n] == 0.0 )

  {

    cerr << "\n";

    cerr << "R8GE_FA - Fatal error!\n";

    cerr << "  Zero pivot on step " << n << "\n";

    exit ( 1 );

  }

  return 0;

}

void r8ge_fs ( int n, double a[], double x[] )

{

  int i;

  int ipiv;

  int j;

  int jcol;

  double piv;

  double t;

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

      cerr << "R8GE_FS - Fatal error!\n";

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

  return;

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

void r8ge_fss ( int n, double a[], int nb, double x[] )

{

  int i;

  int ipiv;

  int j;

  int jcol;

  double piv;

  double t;

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

      cerr << "R8GE_FSS - Fatal error!\n";

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

      for ( j = 0; j < nb; j++ )

      {

        t            = x[jcol-1+j*n];

        x[jcol-1+j*n] = x[ipiv-1+j*n];

        x[ipiv-1+j*n] = t;

      }

    }

    t = a[jcol-1+(jcol-1)*n];

    a[jcol-1+(jcol-1)*n] = 1.0;

    for ( j = jcol+1; j <= n; j++ )

    {

      a[jcol-1+(j-1)*n] = a[jcol-1+(j-1)*n] / t;

    }

    for ( j = 0; j < nb; j++ )

    {

      x[jcol-1+j*n] = x[jcol-1+j*n] / t;

    }

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

        for ( j = 0; j < nb; j++ )

        {

          x[i-1+j*n] = x[i-1+j*n] + t * x[jcol-1+j*n];

        }

      }

    }

  }

  for ( jcol = n; 2 <= jcol; jcol-- )

  {

    for ( i = 1; i < jcol; i++ )

    {

      for ( j = 0; j < nb; j++ )

      {

        x[i-1+j*n] = x[i-1+j*n] - a[i-1+(jcol-1)*n] * x[jcol-1+j*n];

      }

    }

  }

  return;

}

double *r8ge_fss_new ( int n, double a[], int nb, double b[] )

{

  int i;

  int ipiv;

  int j;

  int jcol;

  double piv;

  double t;

  double *x;

  x = new double[n*nb];

  for ( j = 0; j < nb; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      x[i+j*n] = b[i+j*n];

    }

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

      cerr << "R8GE_FSS_NEW - Fatal error!\n";

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

      for ( j = 0; j < nb; j++ )

      {

        t            = x[jcol-1+j*n];

        x[jcol-1+j*n] = x[ipiv-1+j*n];

        x[ipiv-1+j*n] = t;

      }

    }

    t = a[jcol-1+(jcol-1)*n];

    a[jcol-1+(jcol-1)*n] = 1.0;

    for ( j = jcol+1; j <= n; j++ )

    {

      a[jcol-1+(j-1)*n] = a[jcol-1+(j-1)*n] / t;

    }

    for ( j = 0; j < nb; j++ )

    {

      x[jcol-1+j*n] = x[jcol-1+j*n] / t;

    }

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

        for ( j = 0; j < nb; j++ )

        {

          x[i-1+j*n] = x[i-1+j*n] + t * x[jcol-1+j*n];

        }

      }

    }

  }

  for ( jcol = n; 2 <= jcol; jcol-- )

  {

    for ( i = 1; i < jcol; i++ )

    {

      for ( j = 0; j < nb; j++ )

      {

        x[i-1+j*n] = x[i-1+j*n] - a[i-1+(jcol-1)*n] * x[jcol-1+j*n];

      }

    }

  }

  return x;

}

double *r8ge_identity ( int n )

{

  double *a;

  int i;

  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      if ( i == j )

      {

        a[i+j*n] = 1.0;

      }

      else

      {

        a[i+j*n] = 0.0;

      }

    }

  }

  return a;

}

void r8ge_ilu ( int m, int n, double a[], double l[], double u[] )

{

  int i;

  int j;

  int jhi;

  int k;

  for ( j = 0; j < m; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      if ( i == j )

      {

        l[i+j*m] = 1.0;

      }

      else

      {

        l[i+j*m] = 0.0;

      }

    }

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      u[i+j*m] = a[i+j*m];

    }

  }

  jhi = i4_min ( m - 1, n );

  for ( j = 0; j < jhi; j++ )

  {

    for ( i = j+1; i < m; i++ )

    {

      if ( u[i+j*m] != 0.0 )

      {

        l[i+j*m] = u[i+j*m] / u[j+j*m];

        u[i+j*m] = 0.0;

        for ( k = j + 1; k < n; k++ )

        {

          if ( u[i+k*m] != 0.0 )

          {

            u[i+k*m] = u[i+k*m] - l[i+j*m] * u[j+k*m];

          }

        }

      }

    }

  }

  return;

}

double *r8ge_indicator ( int m, int n )

{

  double *a;

  int fac;

  int i;

  int j;

  a = new double[m*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( i = 1; i <= m; i++ )

  {

    for ( j = 1; j <= n; j++ )

    {

      a[i-1+(j-1)*m] = ( double ) ( fac * i + j );

    }

  }

  return a;

}

double *r8ge_inverse ( int n, double a[], int pivot[] )

{

  double *b;

  int i;

  int j;

  int k;

  double temp;

  b = new double[n*n];

  for ( k = 1; k <= n; k++ )

  {

    for ( i = 1; i <= k-1; i++ )

    {

      b[i-1+(k-1)*n] = -b[i-1+(k-1)*n] / a[k-1+(k-1)*n];

    }

    b[k-1+(k-1)*n] = 1.0 / a[k-1+(k-1)*n];

    for ( j = k+1; j <= n; j++ )

    {

      b[k-1+(j-1)*n] = 0.0;

      for ( i = 1; i <= k; i++ )

      {

        b[i-1+(j-1)*n] = b[i-1+(j-1)*n] + b[i-1+(k-1)*n] * a[k-1+(j-1)*n];

      }

    }

  }

  for ( k = n-1; 1 <= k; k-- )

  {

    for ( i = k+1; i <= n; i++ )

    {

      b[i-1+(k-1)*n] = 0.0;

    }

    for ( j = k+1; j <= n; j++ )

    {

      for ( i = 1; i <= n; i++ )

      {

        b[i-1+(k-1)*n] = b[i-1+(k-1)*n] + b[i-1+(j-1)*n] * a[j-1+(k-1)*n];

      }

    }

    if ( pivot[k-1] != k )

    {

      for ( i = 1; i <= n; i++ )

      {

        temp = b[i-1+(k-1)*n];

        b[i-1+(k-1)*n] = b[i-1+(pivot[k-1]-1)*n];

        b[i-1+(pivot[k-1]-1)*n] = temp;

      }

    }

  }

  return b;

}

double *r8ge_ml ( int n, double a_lu[], int pivot[], double x[], int job )

{

  double *b;

  int i;

  int j;

  int k;

  double temp;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = x[i];

  }

  if ( job == 0 )

  {

    for ( j = 1; j <= n; j++ )

    {

      for ( i = 1; i <= j-1; i++ )

      {

        b[i-1] = b[i-1] + a_lu[i-1+(j-1)*n] * b[j-1];

      }

      b[j-1] = a_lu[j-1+(j-1)*n] * b[j-1];

    }

    for ( j = n-1; 1 <= j; j-- )

    {

      for ( i = j+1; i <= n; i++ )

      {

        b[i-1] = b[i-1] - a_lu[i-1+(j-1)*n] * b[j-1];

      }

      k = pivot[j-1];

      if ( k != j )

      {

        temp   = b[k-1];

        b[k-1] = b[j-1];

        b[j-1] = temp;

      }

    }

  }

  else

  {

    for ( j = 1; j <= n-1; j++ )

    {

      k = pivot[j-1];

      if ( k != j )

      {

        temp   = b[k-1];

        b[k-1] = b[j-1];

        b[j-1] = temp;

      }

      temp = 0.0;

      for ( i = j+1; i <= n; i++ )

      {

        temp = temp + b[i-1] * a_lu[i-1+(j-1)*n];

      }

      b[j-1] = b[j-1] - temp;

    }

    for ( i = n; 1 <= i; i-- )

    {

      for ( j = i+1; j <= n; j++ )

      {

        b[j-1] = b[j-1] + b[i-1] * a_lu[i-1+(j-1)*n];

      }

      b[i-1] = b[i-1] * a_lu[i-1+(i-1)*n];

    }

  }

  return b;

}

double *r8ge_mu ( int m, int n, double a_lu[], char trans, int pivot[], 

  double x[] )

{

  double *b;

  int i;

  int j;

  int k;

  int mn_max;

  int npiv;

  double temp;

  double *y;

  npiv = i4_min ( m - 1, n );

  mn_max = i4_max ( m, n );

  y = new double[mn_max];

  if ( trans == 'n' || trans == 'N' )

  {

    b = new double[m];

    for ( i = 0; i < n; i++ )

    {

      y[i] = 0.0;

    }

    for ( j = 1; j <= n; j++ )

    {

      for ( i = 1; i <= i4_min ( j, m ); i++ )

      {

        y[i-1] = y[i-1] + a_lu[i-1+(j-1)*m] * x[j-1];

      }

    }

    for ( i = 0; i < m; i++ )

    {

      if ( i < n ) 

      {

        b[i] = y[i];

      }

      else

      {

        b[i] = 0.0;

      }

    }

    for ( j = i4_min ( m-1, n ); 1 <= j; j-- )

    {

      for ( i = j+1; i <= m; i++ )

      {

        b[i-1] = b[i-1] + a_lu[i-1+(j-1)*m] * y[j-1];

      }

    }

    for ( j = npiv; 1 <= j; j-- )

    {

      k = pivot[j-1];

      if ( k != j )

      {

        temp = b[k-1];

        b[k-1] = b[j-1];

        b[j-1] = temp;

      }

    }

  }

  else if ( trans == 't' || trans == 'T' ||

            trans == 'c' || trans == 'C' )

  {

    b = new double[n];

    for ( i = 1; i <= npiv; i++ )

    {

      k = pivot[i-1];

      if ( k != i )

      {

        temp = x[k-1];

        x[k-1] = x[i-1];

        x[i-1] = temp;

      }

    }

    for ( i = 0; i < n; i++ )

    {

      if ( i < m ) 

      {

        b[i] = x[i];

      }

      else

      {

        b[i] = 0.0;

      }

    }

    for ( j = 1; j <= i4_min ( m - 1, n ); j++ )

    {

      for ( i = j+1; i <= m; i++ )

      {

        b[j-1] = b[j-1] + x[i-1] * a_lu[i-1+(j-1)*m];

      }

    }

    for ( i = m; 1 <= i; i-- )

    {

      for ( j = i+1; j <= n; j++ )

      {

        b[j-1] = b[j-1] + b[i-1] * a_lu[i-1+(j-1)*m];

      }

      if ( i <= n )

      {

        b[i-1] = b[i-1] * a_lu[i-1+(i-1)*m];

      }

    }

    for ( i = npiv; 1 <= i; i-- )

    {

      k = pivot[i-1];

      if ( k != i )

      {

        temp = x[k-1];

        x[k-1] = x[i-1];

        x[i-1] = temp;

      }

    }

  }

  else

  {

    cerr << "\n";

    cerr << "R8GE_MU - Fatal error!\n";

    cerr << "  Illegal value of TRANS = \"" << trans << "\"\n";

    exit ( 1 );

  }

  delete [] y;

  return b;

}

double *r8ge_mxm ( int n, double a[], double b[] )

{

  double *c;

  int i;

  int j;

  int k;

  c = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      c[i+j*n] = 0.0;

      for ( k = 0; k < n; k++ )

      {

        c[i+j*n] = c[i+j*n] + a[i+k*n] * b[k+j*n];

      }

    }

  }

  return c;

}

double *r8ge_mxv ( int m, int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[m];

  for ( i = 0; i < m; i++ )

  {

    b[i] = 0.0;

    for ( j = 0; j < n; j++ )

    {

      b[i] = b[i] + a[i+j*m] * x[j];

    }

  }

  return b;

}

double r8ge_np_det ( int n, double a_lu[] )

{

  double det;

  int i;

  det = 1.0;

  for ( i = 0; i < n; i++ )

  {

    det = det * a_lu[i+i*n];

  }

  return det;

}

int r8ge_np_fa ( int n, double a[] )

{

  int i;

  int j;

  int k;

  for ( k = 1; k <= n-1; k++ )

  {

    if ( a[k-1+(k-1)*n] == 0.0 )

    {

      return k;

    }

    for ( i = k+1; i <= n; i++ )

    {

      a[i-1+(k-1)*n] = -a[i-1+(k-1)*n] / a[k-1+(k-1)*n];

    }

    for ( j = k+1; j <= n; j++ )

    {

      for ( i = k+1; i <= n; i++ )

      {

        a[i-1+(j-1)*n] = a[i-1+(j-1)*n] + a[i-1+(k-1)*n] * a[k-1+(j-1)*n];

      }

    }

  }

  if ( a[n-1+(n-1)*n] == 0.0 )

  {

    return n;

  }

  return 0;

}

double *r8ge_np_inverse ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  int k;

  double temp;

  double *work;

  b = new double[n*n];

  work = new double[n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      b[i+j*n] = a[i+j*n];

    }

  }

  for ( k = 1; k <= n; k++ )

  {

    b[k-1+(k-1)*n] = 1.0 / b[k-1+(k-1)*n];

    for ( i = 1; i <= k-1; i++ )

    {

      b[i-1+(k-1)*n] = -b[i-1+(k-1)*n] * b[k-1+(k-1)*n];

    }

    for ( j = k+1; j <= n; j++ )

    {

      temp = b[k-1+(j-1)*n];

      b[k-1+(j-1)*n] = 0.0;

      for ( i = 1; i <= k; i++ )

      {

        b[i-1+(j-1)*n] = b[i-1+(j-1)*n] + temp * b[i-1+(k-1)*n];

      }

    }

  }

  for ( k = n-1; 1 <= k; k-- )

  {

    for ( i = k+1; i <= n; i++ )

    {

      work[i-1] = b[i-1+(k-1)*n];

      b[i-1+(k-1)*n] = 0.0;

    }

    for ( j = k+1; j <= n; j++ )

    {

      for ( i = 1; i <= n; i++ )

      {

        b[i-1+(k-1)*n] = b[i-1+(k-1)*n] + b[i-1+(j-1)*n] * work[j-1];

      }

    }

  }

  delete [] work;

  return b;

}

double *r8ge_np_ml ( int n, double a_lu[], double x[], int job )

{

  double *b;

  int i;

  int j;

  double t;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = x[i];

  }

  if ( job == 0 )

  {

    for ( i = 0; i < n; i++ )

    {

      t = 0.0;

      for ( j = i; j < n; j++ )

      {

        t = t + a_lu[i+j*n] * b[j];

      }

      b[i] = t;

    }

    for ( j = n-2; 0 <= j; j-- )

    {

      for ( i = j+1; i < n; i++ )

      {

        b[i] = b[i] - a_lu[i+j*n] * b[j];

      }

    }

  }

  else

  {

    for ( j = 0; j < n-1; j++ )

    {

      for ( i = j+1; i < n; i++ )

      {

        b[j] = b[j] - b[i] * a_lu[i+j*n];

      }

    }

    for ( j = n-1; 0 <= j; j-- )

    {

      b[j] = b[j] * a_lu[j+j*n];

      for ( i = 0; i < j; i++ )

      {

        b[j] = b[j] + b[i] * a_lu[i+j*n];

      }

    }

  }

  return b;

}

double *r8ge_np_sl ( int n, double a_lu[], double b[], int job )

{

  int i;

  int k;

  double *x;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  if ( job == 0 )

  {

    for ( k = 0; k < n-1; k++ )

    {

      for ( i = k+1; i < n; i++ )

      {

        x[i] = x[i] + a_lu[i+k*n] * x[k];

      }

    }

    for ( k = n-1; 0 <= k; k-- )

    {

      x[k] = x[k] / a_lu[k+k*n];

      for ( i = 0; i <= k-1; i++ )

      {

        x[i] = x[i] - a_lu[i+k*n] * x[k];

      }

    }

  }

  else

  {

    for ( k = 0; k < n; k++ )

    {

      for ( i = 0; i <= k-1; i++ )

      {

        x[k] = x[k] - x[i] * a_lu[i+k*n];

      }

      x[k] = x[k] / a_lu[k+k*n];

    }

    for ( k = n-2; 0 <= k; k-- )

    {

      for ( i = k+1; i < n; i++ )

      {

        x[k] = x[k] + x[i] * a_lu[i+k*n];

      }

    }

  }

  return x;

}

int r8ge_np_trf ( int m, int n, double a[] )

{

  int i;

  int ii;

  int info;

  int j;

  info = 0;

  if ( m < 0 )

  {

    return (-1);

  }

  else if ( n < 0 )

  {

    return (-2);

  }

  if ( m == 0 || n == 0 )

  {

    return 0;

  }

  for ( j = 1; j <= i4_min ( m, n ); j++ )

  {

    if ( a[j-1+(j-1)*m] != 0.0 )

    {

      for ( i = j+1; i <= m; i++ )

      {

        a[i-1+(j-1)*m] = a[i-1+(j-1)*m] / a[j-1+(j-1)*m];

      }

    }

    else if ( info == 0 )

    {

      info = j;

    }

    if ( j < i4_min ( m, n ) )

    {

      for ( ii = j+1; ii <= m; ii++ )

      {

        for ( i = j+1; i <= n; i++ )

        {

          a[ii-1+(i-1)*m] = a[ii-1+(i-1)*m] - a[ii-1+(j-1)*m] * a[j-1+(i-1)*m];

        }

      }

    }

  }

  return info;

}

double *r8ge_np_trm ( int m, int n, double a[], double x[], int job )

{

  double *b;

  int i;

  int j;

  double temp;

  if ( job == 0 )

  {

    b = new double[m];

    for ( i = 0; i < m; i++ )

    {

      b[i] = 0.0;

    }

    for ( i = 0; i < i4_min ( m, n ); i++ )

    {

      for ( j = i; j < n; j++ )

      {

        b[i] = b[i] + a[i+j*m] * x[j];

      }

    }

    for ( i = i4_min ( m-1, n ); 1 <= i; i-- )

    {

      for ( j = 0; j < i; j++ )

      {

        b[i] = b[i] + a[i+j*m] * b[j];

      }

    }

  }

  else

  {

    b = new double[n];

    for ( i = 0; i < n; i++ )

    {

      b[i] = 0.0;

    }

    for ( i = 0; i < i4_min ( m, n ); i++ )

    {

      b[i] = x[i];

      for ( j = i+1; j < m; j++ )

      {

        b[i] = b[i] + a[j+i*m] * x[j];

      }

    }

    for ( i = i4_min ( m, n ) - 1; 0 <= i; i-- )

    {

      temp = 0.0;

      for ( j = 0; j <= i; j++ )

      {

        temp = temp + a[j+i*m] * b[j];

      }

      b[i] = temp;

    }

  }

  return b;

}

double *r8ge_np_trs ( int n, int nrhs, char trans, double a[], double b[] )

{

  int i;

  int j;

  int k;

  double *x;

  if ( trans != 'n' && trans != 'N' && 

       trans != 't' && trans != 'T' && 

       trans != 'c' && trans != 'C' )

  {

    return NULL;

  }

  if ( n < 0 )

  {

    return NULL;

  }

  if ( nrhs < 0 )

  {

    return NULL;

  }

  if ( n == 0 || nrhs == 0 )

  {

    return NULL;

  }

  x = new double[n*nrhs];

  for ( j = 0; j < nrhs; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      x[i+j*n] = b[i+j*n];

    }

  }

  if ( trans == 'n' || trans == 'N' )

  {

    for ( k = 0; k < nrhs; k++ )

    {

      for ( j = 1; j <= n-1; j++ )

      {

        for ( i = j+1; i <= n; i++ )

        {

          x[i-1+k*n] = x[i-1+k*n] - a[i-1+(j-1)*n] * x[j-1+k*n];

        }

      }

    }

    for ( k = 0; k < nrhs; k++ )

    {

      for ( j = n; 1 <= j; j-- )

      {

        x[j-1+k*n] = x[j-1+k*n] / a[j-1+(j-1)*n];

        for ( i = 1; i <= j-1; i++ )

        {

          x[i-1+k*n] = x[i-1+k*n] - a[i-1+(j-1)*n] * x[j-1+k*n];

        }

      }

    }

  }

  else

  {

    for ( k = 0; k < nrhs; k++ )

    {

      for ( j = 1; j <= n; j++ )

      {

        x[j-1+k*n] = x[j-1+k*n] / a[j-1+(j-1)*n];

        for ( i = j+1; i <= n; i++ )

        {

          x[i-1+k*n] = x[i-1+k*n] - a[j-1+(i-1)*n] * x[j-1+k*n];

        }

      }

    }

    for ( k = 0; k < nrhs; k++ )

    {

      for ( j = n; 2 <= j; j-- )

      {

        for ( i = 1; i <= j-1; i++ )

        {

          x[i-1+k*n] = x[i-1+k*n] - a[j-1+(i-1)*n] * x[j-1+k*n];

        }

      }

    }

  }

  return x;

}

void r8ge_plu ( int m, int n, double a[], double p[], double l[], double u[] )

{

  int i;

  int j;

  int k;

  int pivot_row;

  double pivot_value;

  double t;

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < m; j++ )

    {

      if ( i == j ) 

      {

        l[i+j*m] = 1.0;

        p[i+j*m] = 1.0;

      }

      else

      {

        l[i+j*m] = 0.0;

        p[i+j*m] = 0.0;

      }

    }

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      u[i+j*m] = a[i+j*m];

    }

  }

  for ( j = 0; j < i4_min ( m-2, n-1 ); j++ )

  {

    pivot_value = 0.0;

    pivot_row = -1;

    for ( i = j; i < m; i++ )

    {

      if ( pivot_value < r8_abs ( u[i+j*m] ) )

      {

        pivot_value = r8_abs ( u[i+j*m] );

        pivot_row = i;

      }

    }

    if ( pivot_row != -1 )

    {

      for ( k = 0; k < n; k++ )

      {

        t                = u[j+k*m];

        u[j+k*m]         = u[pivot_row+k*m];

        u[pivot_row+k*m] = t;

      }

      for ( k = 0; k < m; k++ )

      {

        t                = l[j+k*m];

        l[j+k*m]         = l[pivot_row+k*m];

        l[pivot_row+k*m] = t;

      }

      for ( k = 0; k < m; k++ )

      {

        t                = l[k+j*m];

        l[k+j*m]         = l[k+pivot_row*m];

        l[k+pivot_row*m] = t;

      }

      for ( k = 0; k < m; k++ )

      {

        t                = p[k+j*m];

        p[k+j*m]         = p[k+pivot_row*m];

        p[k+pivot_row*m] = t;

      }

      for ( i = j+1; i < m; i++ )

      {

        if ( u[i+j*m] != 0.0 )

        {

          l[i+j*m] = u[i+j*m] / u[j+j*m];

          u[i+j*m] = 0.0;

          for ( k = j+1; k < n; k++ )

          {

            u[i+k*m] = u[i+k*m] - l[i+j*m] * u[j+k*m];

          }

        }

      }

    }

  }

  return;

}

double *r8ge_poly ( int n, double a[] )

{

  int i;

  int j;

  int k;

  int order;

  double *p;

  double trace;

  double *work1;

  double *work2;

  p = new double[n+1];

  work2 = new double[n*n];

  work1 = r8ge_identity ( n );

  p[n] = 1.0;

  for ( order = n-1; 0 <= order; order-- )

  {

    for ( j = 0; j < n; j++ )

    {

      for ( i = 0; i < n; i++ )

      {

        work2[i+j*n] = 0.0;

        for ( k = 0; k < n; k++ )

        {

          work2[i+j*n] = work2[i+j*n] + a[i+k*n] * work1[k+j*n];

        }

      }

    }

    trace = 0.0;

    for ( i = 0; i < n; i++ )

    {

      trace = trace + work2[i+i*n];

    }

    p[order] = -trace / ( double ) ( n - order );

    for ( j = 0; j < n; j++ )

    {

      for ( i = 0; i < n; i++ )

      {

        work1[i+j*n] = work2[i+j*n];

      }

    }

    for ( j = 0; j < n; j++ )

    {

      work1[j+j*n] = work1[j+j*n] + p[order];

    }

  }

  delete [] work1;

  delete [] work2;

  return p;

}

void r8ge_print ( int m, int n, double a[], string title )

{

  r8ge_print_some ( m, n, a, 1, 1, m, n, title );

  return;

}

void r8ge_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi, 

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

double *r8ge_random ( int m, int n, int *seed )

{

  double *a;

  int i;

  int j;

  a = new double[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      a[i+j*m] = r8_uniform_01 ( seed );

    }

  }

  return a;

}

double *r8ge_res ( int m, int n, double a[], double x[], double b[] )

{

  double *r;

  int i;

  int j;

  r = new double[n];

  for ( i = 0; i < m; i++ )

  {

    r[i] = b[i];

    for ( j = 0; j < n; j++ )

    {

      r[i] = r[i] - a[i+j*m] * x[j];

    }

  }

  return r;

}

void r8ge_sl ( int n, double a_lu[], int pivot[], double x[], int job )

{

  int i;

  int k;

  int l;

  double t;

  if ( job == 0 )

  {

    for ( k = 1; k <= n-1; k++ )

    {

      l = pivot[k-1];

      if ( l != k )

      {

        t      = x[l-1];

        x[l-1] = x[k-1];

        x[k-1] = t;

      }

      for ( i = k+1; i <= n; i++ )

      {

        x[i-1] = x[i-1] + a_lu[i-1+(k-1)*n] * x[k-1];

      }

    }

    for ( k = n; 1 <= k; k-- )

    {

      x[k-1] = x[k-1] / a_lu[k-1+(k-1)*n];

      for ( i = 1; i <= k-1; i++ )

      {

        x[i-1] = x[i-1] - a_lu[i-1+(k-1)*n] * x[k-1];

      }

    }

  }

  else

  {

    for ( k = 1; k <= n; k++ )

    {

      t = 0.0;

      for ( i = 1; i <= k-1; i++ )

      {

        t = t + x[i-1] * a_lu[i-1+(k-1)*n];

      }

      x[k-1] = ( x[k-1] - t ) / a_lu[k-1+(k-1)*n];

    }

    for ( k = n-1; 1 <= k; k-- )

    {

      t = 0.0;

      for ( i = k+1; i <= n; i++ )

      {

        t = t + x[i-1] * a_lu[i-1+(k-1)*n];

      }

      x[k-1] = x[k-1] + t;

      l = pivot[k-1];

      if ( l != k )

      {

        t      = x[l-1];

        x[l-1] = x[k-1];

        x[k-1] = t;

      }

    }

  }

  return;

}

double *r8ge_sl_it ( int n, double a[], double a_lu[], int pivot[], double b[], 

  int job, double x[] )

{

  double *dx;

  int i;

  double *r;

  double *x_new;

  r = r8ge_res ( n, n, a, x, b );

  dx = r8ge_sl_new ( n, a_lu, pivot, r, job );

  x_new = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x_new[i] = x[i] + dx[i];

  }

  delete [] r;

  delete [] dx;

  return x_new;

}

double *r8ge_sl_new ( int n, double a_lu[], int pivot[], double b[], int job )

{

  int i;

  int k;

  int l;

  double t;

  double *x;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  if ( job == 0 )

  {

    for ( k = 1; k <= n-1; k++ )

    {

      l = pivot[k-1];

      if ( l != k )

      {

        t      = x[l-1];

        x[l-1] = x[k-1];

        x[k-1] = t;

      }

      for ( i = k+1; i <= n; i++ )

      {

        x[i-1] = x[i-1] + a_lu[i-1+(k-1)*n] * x[k-1];

      }

    }

    for ( k = n; 1 <= k; k-- )

    {

      x[k-1] = x[k-1] / a_lu[k-1+(k-1)*n];

      for ( i = 1; i <= k-1; i++ )

      {

        x[i-1] = x[i-1] - a_lu[i-1+(k-1)*n] * x[k-1];

      }

    }

  }

  else

  {

    for ( k = 1; k <= n; k++ )

    {

      t = 0.0;

      for ( i = 1; i <= k-1; i++ )

      {

        t = t + x[i-1] * a_lu[i-1+(k-1)*n];

      }

      x[k-1] = ( x[k-1] - t ) / a_lu[k-1+(k-1)*n];

    }

    for ( k = n-1; 1 <= k; k-- )

    {

      t = 0.0;

      for ( i = k+1; i <= n; i++ )

      {

        t = t + x[i-1] * a_lu[i-1+(k-1)*n];

      }

      x[k-1] = x[k-1] + t;

      l = pivot[k-1];

      if ( l != k )

      {

        t      = x[l-1];

        x[l-1] = x[k-1];

        x[k-1] = t;

      }

    }

  }

  return x;

}

double *r8ge_to_r8gb ( int m, int n, int ml, int mu, double a[] )

{

  double *b;

  int i;

  int j;

  int jhi;

  int jlo;

  int k;

  b = new double[(2*ml+mu+1)*n];

  for ( k = 0; k < (2*ml+mu+1)*n; k++ )

  {

    b[k] = 0.0;

  }

  for ( i = 1; i <= m; i++ )

  {

    jlo = i4_max ( i - ml, 1 );

    jhi = i4_min ( i + mu, n );

    for ( j = jlo; j <= jhi; j++ )

    {

      b[ml+mu+i-j+(j-1)*(2*ml+mu+1)] = a[i-1+(j-1)*m];

    }

  }

  return b;

}

void r8ge_to_r8ri ( int n, double a[], int nz, int ija[], double sa[] )

{

  int i;

  int im;

  int j;

  int k;

  int l;

  for ( k = 0; k < n; k++ )

  {

    i = k;

    j = k;

    sa[k] = a[i+j*n];

  }

  k = n;

  sa[k] = 0.0;

  for ( i = 0; i <= n; i++ )

  {

    ija[i] = 0;

  }

  im = 0;

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      if ( i != j )

      {

        if ( a[i+j*n] != 0.0 )

        {

          k = k + 1;

          if ( ija[i] == 0 )

          {

            for ( l = im; l <= i; l++ )

            {

              ija[l] = k;

            }

            im = i + 1;

          }

          ija[k] = j;

          sa[k] = a[i+j*n];

        }

      }

    }

  }

  ija[n] = k + 1;

  return;

}

int r8ge_to_r8ri_size ( int n, double a[] )

{

  int i;

  int j;

  int nz;

  nz = n + 1;

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      if ( i != j )

      {

        if ( a[i+j*n] != 0.0 )

        {

          nz = nz + 1;

        }

      }

    }

  }

  return nz;

}

double *r8ge_to_r8vec ( int m, int n, double *a )

{

  int i;

  int j;

  int k;

  double *x;

  x = new double[m*n];

  k = 0;

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      x[k] = a[i+j*m];

      k = k + 1;

    }

  }

  return x;

}

int r8ge_trf ( int m, int n, double a[], int pivot[] )

{

  int i;

  int ii;

  int info;

  int j;

  int jj;

  int jp;

  double temp;

  info = 0;

  if ( m < 0 )

  {

    return (-1);

  }

  else if ( n < 0 )

  {

    return (-2);

  }

  if ( m == 0 || n == 0 )

  {

    return 0;

  }

  for ( j = 1; j <= i4_min ( m, n ); j++ )

  {

    temp = r8_abs ( a[j-1+(j-1)*m] );

    jp = j;

    for ( i = j+1; i <= m; i++ )

    {

      if ( temp < r8_abs ( a[i-1+(j-1)*m] ) )

      {

        temp = r8_abs ( a[i-1+(j-1)*m] );

        jp = i;

      }

    }

    pivot[j-1] = jp;

    if ( a[jp-1+(j-1)*m] != 0.0 )

    {

      if ( jp != j )

      {

        for ( jj = 1; jj <= n; jj++ )

        {

          temp             = a[j-1+(jj-1)*m];

          a[j-1+(jj-1)*m]  = a[jp-1+(jj-1)*m];

          a[jp-1+(jj-1)*m] = temp;

        }

      }

      if ( j < m )

      {

        for ( i = j+1; i <= m; i++ )

        {

          a[i-1+(j-1)*m] = a[i-1+(j-1)*m] / a[j-1+(j-1)*m];

        }

      }

    }

    else if ( info == 0 )

    {

      info = j;

    }

    if ( j < i4_min ( m, n ) )

    {

      for ( ii = j+1; ii <= m; ii++ )

      {

        for ( i = j+1; i <= n; i++ )

        {

          a[ii-1+(i-1)*m] = a[ii-1+(i-1)*m] - a[ii-1+(j-1)*m] * a[j-1+(i-1)*m];

        }

      }

    }

  }

  return info;

}

double *r8ge_trs ( int n, int nrhs, char trans, double a[], int pivot[], 

  double b[] )

{

  int i;

  int j;

  int k;

  double temp;

  double *x;

  if ( trans != 'n' && trans != 'N' && 

       trans != 't' && trans != 'T' && 

       trans != 'c' && trans != 'C' )

  {

    return NULL;

  }

  if ( n < 0 )

  {

    return NULL;

  }

  if ( nrhs < 0 )

  {

    return NULL;

  }

  if ( n == 0 )

  {

    return NULL;

  }

  if ( nrhs == 0 )

  {

    return NULL;

  }

  x = new double[n*nrhs];

  for ( k = 0; k < nrhs; k++ )

  {

    for ( i = 0; i < n; i++ )

    {

      x[i+k*n] = b[i+k*n];

    }

  }

  if ( trans == 'n' || trans == 'N' )

  {

    for ( i = 1; i <= n; i++ )

    {

      if ( pivot[i-1] != i )

      {

        for ( k = 0; k < nrhs; k++ )

        {

          temp                = x[i-1+k*n];

          x[i-1+k*n]          = x[pivot[i-1]-1+k*n];

          x[pivot[i-1]-1+k*n] = temp;

        }

      }

    }

    for ( k = 0; k < nrhs; k++ )

    {

      for ( j = 1; j <= n-1; j++ )

      {

        for ( i = j+1; i <= n; i++ )

        {

          x[i-1+k*n] = x[i-1+k*n] - a[i-1+(j-1)*n] * x[j-1+k*n];

        }

      }

    }

    for ( k = 0; k < nrhs; k++ )

    {

      for ( j = n; 1 <= j; j-- )

      {

        x[j-1+k*n] = x[j-1+k*n] / a[j-1+(j-1)*n];

        for ( i = 1; i < j; i++ )

        {

          x[i-1+k*n] = x[i-1+k*n] - a[i-1+(j-1)*n] * x[j-1+k*n];

        }

      }

    }

  }

  else

  {

    for ( k = 0; k < nrhs; k++ )

    {

      for ( j = 1; j <= n; j++ )

      {

        x[j-1+k*n] = x[j-1+k*n] / a[j-1+(j-1)*n];

        for ( i = j+1; i <= n; i++ )

        {

          x[i-1+k*n] = x[i-1+k*n] - a[j-1+(i-1)*n] * x[j-1+k*n];

        }

      }

    }

    for ( k = 0; k < nrhs; k++ )

    {

      for ( j = n; 2 <= j; j-- )

      {

        for ( i = 1; i < j; i++ )

        {

          x[i-1+k*n] = x[i-1+k*n] - a[j-1+(i-1)*n] * x[j-1+k*n];

        }

      }

    }

    for ( i = n; 1 <= i; i-- )

    {

      if ( pivot[i-1] != i )

      {

        for ( k = 0; k < nrhs; k++ )

        {

          temp                = x[i-1+k*n];

          x[i-1+k*n]          = x[pivot[i-1]-1+k*n];

          x[pivot[i-1]-1+k*n] = temp;

        }

      }

    }

  }

  return x;

}

double *r8ge_vxm ( int m, int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

    for ( j = 0; j < m; j++ )

    {

      b[i] = b[i] + a[j+i*m] * x[j];

    }

  }

  return b;

}

double *r8ge_zero ( int m, int n )

{

  double *a;

  int i;

  int j;

  a = new double[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      a[i+j*m] = 0.0;

    }

  }

  return a;

}

double r8lt_det ( int n, double a[] )

{

  double det;

  int i;

  det = 1.0;

  for ( i = 0; i < n; i++ )

  {

    det = det * a[i+i*n];

  }

  return det;

}

double *r8lt_indicator ( int m, int n )

{

  double *a;

  int fac;

  int i;

  int j;

  a = new double[m*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( i = 1; i <= m; i++ )

  {

    for ( j = 1; j <= i4_min ( i, n ); j++ )

    {

      a[i-1+(j-1)*m] = ( double ) ( fac * i + j );

    }

    for ( j = i+1; j <= n; j++ )

    {

      a[i-1+(j-1)*m] = 0.0;

    }

  }

  return a;

}

double *r8lt_inverse ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  int k;

  double t;

  for ( i = 0; i < n; i++ )

  {

    if ( a[i+i*n] == 0.0 )

    {

      cerr << "\n";

      cerr << "R8LT_INVERSE - Fatal error!\n";

      cerr << "  Zero diagonal element.\n";

      exit ( 1 );

    }

  }

  b = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      b[i+j*n] = a[i+j*n];

    }

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      if ( i < j )

      {

        b[i+j*n] = 0.0;

      }

      else if ( i == j )

      {

        b[i+j*n] = 1.0 / b[i+j*n];

      }

      else if ( j < i )

      {

        t = 0.0;

        for ( k = j; k <= i-1; k++ )

        {

          t = t - b[i+k*n] * b[k+j*n];

        }

        b[i+j*n] = t / b[i+i*n];

      }

    }

  }

  return b;

}

double *r8lt_mxm ( int n, double a[], double b[] )

{

  double *c;

  int i;

  int j;

  int k;

  c = new double[n*n];

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      c[i+j*n] = 0.0;

      for ( k = j; k <= i; k++ )

      {

        c[i+j*n] = c[i+j*n] + a[i+k*n] * b[k+j*n];

      }

    }

  }

  return c;

}

double *r8lt_mxv ( int m, int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  int jmax;

  b = new double[m];

  for ( i = 0; i < m; i++ )

  {

    b[i] = 0.0;

    jmax = i4_min ( i, n-1 );

    for ( j = 0; j <= jmax; j++ )

    {

      b[i] = b[i] + a[i+j*m] * x[j];

    }

  }

  return b;

}

void r8lt_print ( int m, int n, double a[], string title )

{

  r8lt_print_some ( m, n, a, 1, 1, m, n, title );

  return;

}

void r8lt_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi, 

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

  if ( ilo < jlo )

  {

    return;

  }

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n );

    j2hi = i4_min ( j2hi, jhi );

    cout << "\n";

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2lo = i4_max ( i2lo, j2lo );

    i2hi = i4_min ( ihi, m );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( i < j )

        {

          cout << "              ";

        }

        else

        {

          cout << setw(12) << a[i-1+(j-1)*m] << "  ";

        }

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8lt_random ( int m, int n, int *seed )

{

  double *a;

  int i;

  int j;

  a = new double[m*n];

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j <= i4_min ( i, n-1); j++ )

    {

      a[i+j*m] = r8_uniform_01 ( seed );

    }

    for ( j = i+1; j < n; j++ )

    {

      a[i+j*m] = 0.0;

    }

  }

  return a;

}

double *r8lt_sl ( int n, double a[], double b[], int job )

{

  int i;

  int j;

  double *x;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  if ( job == 0 )

  {

    for ( j = 0; j < n; j++ )

    {

      x[j] = x[j] / a[j+j*n];

      for ( i = j+1; i < n; i++ )

      {

        x[i] = x[i] - a[i+j*n] * x[j];

      }

    }

  }

  else

  {

    for ( j = n-1; 0 <= j; j-- )

    {

      x[j] = x[j] / a[j+j*n];

      for ( i = 0; i < j; i++ )

      {

        x[i] = x[i] - a[j+i*n] * x[j];

      }

    }

  }

  return x;

}

double *r8lt_vxm ( int m, int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[n];

  for ( j = 0; j < n; j++)

  {

    b[j] = 0.0;

    for ( i = j; i < m; i++ )

    {

      b[j] = b[j] + x[i] * a[i+j*m];

    }

  }

  return b;

}

double *r8lt_zero ( int m, int n )

{

  double *a;

  int i;

  int j;

  a = new double[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      a[i+j*m] = 0.0;

    }

  }

  return a;

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

    j2hi = i4_min ( j2hi, n );

    j2hi = i4_min ( j2hi, jhi );

    cout << "\n";

    cout << "  Col:    ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j - 1 << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, m );

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

double *r8mat_uniform_01_new ( int m, int n, int &seed )

{

  int i;

  int j;

  int k;

  double *r;

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

double *r8ncf_indicator ( int m, int n, int nz_num, int rowcol[] )

{

  double *a;

  int fac;

  int i;

  int j;

  int k;

  a = new double[nz_num];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( k = 0; k < nz_num; k++ )

  {

    i = rowcol[0+k*2];

    j = rowcol[1+k*2];

    a[k] = ( double ) ( fac * i + j );

  }

  return a;

}

void r8ncf_print ( int m, int n, int nz_num, int rowcol[], 

  double a[], string title )

{

  r8ncf_print_some ( m, n, nz_num, rowcol, a, 1, 1, m, n, title );

  return;

}

void r8ncf_print_some ( int m, int n, int nz_num, int rowcol[], 

  double a[], int ilo, int jlo, int ihi, int jhi, string title )

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

  int k;

  bool nonzero;

  double temp[INCX];

  cout << "\n";

  cout << title << "\n";

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n );

    j2hi = i4_min ( j2hi, jhi );

    inc = j2hi + 1 - j2lo;

    cout << "\n";

    cout << "  Col:  ";

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

      nonzero = false;

      for ( j2 = 1; j2 <= INCX; j2++ )

      {

        temp[j2-1] = 0.0;

      }

      for ( k = 1; k <= nz_num; k++ )

      {

        if ( i == rowcol[0+(k-1)*2] && 

          j2lo <= rowcol[1+(k-1)*2] && 

          rowcol[1+(k-1)*2] <= j2hi )

        {

          j2 = rowcol[1+(k-1)*2] - j2lo + 1;

          if ( a[k-1] == 0.0 )

          {

            continue;

          }

          nonzero = true;

          temp[j2-1] = a[k-1];

        }

      }

      if ( nonzero )

      {

        cout << setw(6) << i;

        for ( j2 = 1; j2 <= inc; j2++ )

        {

          cout << setw(12) << temp[j2-1] << "  ";

        }

        cout << "\n";

      }

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double r8pbl_det ( int n, int mu, double a_lu[] )

{

  double det;

  int j;

  det = 1.0;

  for ( j = 0; j < n; j++ )

  {

    det = det * a_lu[0+j*(mu+1)] * a_lu[0+j*(mu+1)];

  }

  return det;

}

double *r8pbl_indicator ( int n, int mu )

{

  double *a;

  int fac;

  int i;

  int j;

  a = new double[(mu+1)*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( j = n - mu + 1; j <= n; j++ )

  {

    for ( i = n + 1; i <= j + mu; i++ )

    {

      a[i-j+(j-1)*(mu+1)] = 0.0;

    }

  }

  for ( i = 0; i <= n; i++ )

  {

    for ( j = i4_max ( 1, i - mu ); j <= i; j++ )

    {

      a[i-j+(j-1)*(mu+1)] = ( double ) ( fac * i + j );

    }

  }

  return a;

}

void r8pbl_print ( int n, int mu, double a[], string title )

{

  r8pbl_print_some ( n, mu, a, 1, 1, n, n, title );

  return;

}

void r8pbl_print_some ( int n, int mu, double a[], int ilo, int jlo, int ihi, 

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

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2lo = i4_max ( i2lo, j2lo - mu );

    i2hi = i4_min ( ihi, n );

    i2hi = i4_min ( i2hi, j2hi + mu );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( i <= j && j <= i + mu )

        {

          cout << setw(12) << a[j-i+(i-1)*(mu+1)] << "  ";

        }

        else if ( j <= i && i <= j + mu )

        {

          cout << setw(12) << a[i-j+(j-1)*(mu+1)] << "  ";

        }

        else

        {

          cout << "              ";

        }

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8pbl_random ( int n, int mu, int *seed )

{

  double *a;

  int i;

  int j;

  double r;

  double sum2;

  a = new double[(mu+1)*n];

  for ( j = n - mu; j <= n-1; j++ )

  {

    for ( i = n-j; i <= mu; i++ )

    {

      a[i+j*(mu+1)] = 0.0;

    }

  }

  for ( i = 0; i < n; i++ )

  {

    for ( j = i4_max ( 0, i - mu ); j <= i - 1; j++ )

    {

      a[i-j+j*(mu+1)] = r8_uniform_01 ( seed );

    }

  }

  for ( i = 0; i < n; i++ )

  {

    sum2 = 0.0;

    for ( j = i4_max ( 0, i - mu ); j <= i-1; j++ )

    {

      sum2 = sum2 + r8_abs ( a[i-j+j*(mu+1)] );

    }

    for ( j = i+1; j <= i4_min ( i + mu, n -1 ); j++ )

    {

      sum2 = sum2 + r8_abs ( a[j-i+i*(mu+1)] );

    }

    r = r8_uniform_01 ( seed );

    a[0+i*(mu+1)] = ( 1.0 + r ) * ( sum2 + 0.01 );

  }

  return a;

}

double *r8pbl_to_r8ge ( int n, int mu, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      if ( i <= j && j <= i + mu )

      {

        b[i+j*n] = a[j-i+i*(mu+1)];

      }

      else if ( i - mu <= j && j < i )

      {

        b[i+j*n] = a[i-j+j*(mu+1)];

      }

      else

      {

        b[i+j*n] = 0.0;

      }

    }

  }

  return b;

}

double *r8pbl_zero ( int n, int mu )

{

  double *a;

  int i;

  int j;

  a = new double[(mu+1)*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < mu+1; i++ )

    {

      a[i+j*(mu+1)] = 0.0;

    }

  }

  return a;

}

double *r8pbu_cg ( int n, int mu, double a[], double b[], double x[] )

{

  double alpha;

  double *ap;

  double beta;

  int i;

  int it;

  double *p;

  double pap;

  double pr;

  double *r;

  double rap;

  double *x2;

  ap = new double[n];

  p = new double[n];

  r = new double[n];

  x2 = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x2[i] = x[i];

  }

  ap = r8pbu_mxv ( n, mu, a, x2 );

  for ( i = 0; i < n; i++ )

  {

    r[i] = b[i] - ap[i];

  }

  for ( i = 0; i < n; i++ )

  {

    p[i] = b[i] - ap[i];

  }

  for ( it = 1; it <= n; it++ )

  {

    delete [] ap;

    ap = r8pbu_mxv ( n, mu, a, p );

    pap = 0.0;

    for ( i = 0; i < n; i++ )

    {

      pap = pap + p[i] * ap[i];

    }

    if ( pap == 0.0 )

    {

      break;

    }

    pr = 0.0;

    for ( i = 0; i < n; i++ )

    {

      pr = pr + p[i] * r[i];

    }

    alpha = pr / pap;

    for ( i = 0; i < n; i++ )

    {

      x2[i] = x2[i] + alpha * p[i];

    }

    for ( i = 0; i < n; i++ )

    {

      r[i] = r[i] - alpha * ap[i];

    }

    rap = 0.0;

    for ( i = 0; i < n; i++ )

    {

      rap = rap + r[i] * ap[i];

    }

    beta = - rap / pap;

    for ( i = 0; i < n; i++ )

    {

      p[i] = r[i] + beta * p[i];

    }

  }

  delete [] ap;

  delete [] p;

  delete [] r;

  return x2;

}

double r8pbu_det ( int n, int mu, double a_lu[] )

{

  double det;

  int j;

  det = 1.0;

  for ( j = 0; j < n; j++ )

  {

    det = det * a_lu[mu+j*(mu+1)] * a_lu[mu+j*(mu+1)];

  }

  return det;

}

double *r8pbu_fa ( int n, int mu, double a[] )

{

  double *b;

  int i;

  int ik;

  int j;

  int jk;

  int k;

  int mm;

  double s;

  double t;

  b = new double[(mu+1)*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < mu+1; i++ )

    {

      b[i+j*(mu+1)] = a[i+j*(mu+1)];

    }

  }

  for ( j = 1; j <= n; j++ )

  {

    ik = mu + 1;

    jk = i4_max ( j - mu, 1 );

    mm = i4_max ( mu + 2 - j, 1 );

    s = 0.0;

    for ( k = mm; k <= mu; k++ )

    {

      t = 0.0;

      for ( i = 0; i <= k-mm-1; i++ )

      {

        t = t + b[ik+i-1+(jk-1)*(mu+1)] * b[mm+i-1+(j-1)*(mu+1)];

      }

      b[k-1+(j-1)*(mu+1)] = ( b[k-1+(j-1)*(mu+1)] - t ) /

        b[mu+(jk-1)*(mu+1)];

      s = s + b[k-1+(j-1)*(mu+1)] * b[k-1+(j-1)*(mu+1)];

      ik = ik - 1;

      jk = jk + 1;

    }

    s = b[mu+(j-1)*(mu+1)] - s;

    if ( s <= 0.0 )

    {

      return NULL;

    }

    b[mu+(j-1)*(mu+1)] = sqrt ( s );

  }

  return b;

}

double *r8pbu_indicator ( int n, int mu )

{

  double *a;

  int fac;

  int i;

  int j;

  a = new double[(mu+1)*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( j = 0; j < mu; j++ )

  {

    for ( i = 0; i <= mu - j; i++ )

    {

      a[i+j*(mu+1)] = 0.0;

    }

  }

  for ( i = 1; i <= n; i++ )

  {

    for ( j = i; j <= i4_min ( i + mu, n ); j++ )

    {

      a[mu+i-j+(j-1)*(mu+1)] = ( double ) ( fac * i + j );

    }

  }

  return a;

}

double *r8pbu_ml ( int n, int mu, double a_lu[], double x[] )

{

  double *b;

  int i;

  int ilo;

  int j;

  int jhi;

  int k;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = x[i];

  }

  for ( k = 1; k <= n; k++ )

  {

    ilo = i4_max ( 1, k - mu );

    for ( i = ilo; i <= k - 1; i++ )

    {

      b[i-1] = b[i-1] + a_lu[mu+i-k+(k-1)*(mu+1)] * b[k-1];

    }

    b[k-1] = a_lu[mu+(k-1)*(mu+1)] * b[k-1];

  }

  for ( k = n; 1 <= k; k-- )

  {

    jhi = i4_min ( k + mu, n );

    for ( j = k+1; j <= jhi; j++ )

    {

      b[j-1] = b[j-1] + a_lu[mu+k-j+(j-1)*(mu+1)] * b[k-1];

    }

    b[k-1] = a_lu[mu+(k-1)*(mu+1)] * b[k-1];

  }

  return b;

}

double *r8pbu_mxv ( int n, int mu, double a[], double x[] )

{

  double *b;

  int i;

  int ieqn;

  int j;

  b = new double[n];

  for ( j = 0; j < n; j++ )

  {

    b[j] = a[mu+j*(mu+1)] * x[j];

  }

  for ( i = mu; 1 <= i; i-- )

  {

    for ( j = mu+2-i; j <= n; j++ )

    {

      ieqn = i + j - mu - 1;

      b[ieqn-1] = b[ieqn-1] + a[i-1+(j-1)*(mu+1)] * x[j-1];

      b[j-1] = b[j-1] + a[i-1+(j-1)*(mu+1)] * x[ieqn-1];

    }

  }

  return b;

}

void r8pbu_print ( int n, int mu, double a[], string title )

{

  r8pbu_print_some ( n, mu, a, 1, 1, n, n, title );

  return;

}

void r8pbu_print_some ( int n, int mu, double a[], int ilo, int jlo, int ihi, 

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

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2lo = i4_max ( i2lo, j2lo - mu );

    i2hi = i4_min ( ihi, n );

    i2hi = i4_min ( i2hi, j2hi + mu );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( mu < i-j || mu < j-i ) 

        {

          cout << "              ";

        }

        else if ( i <= j && j <= i + mu )

        {

          cout << setw(12) << a[mu+i-j+(j-1)*(mu+1)] << "  ";

        }

        else if ( i - mu <= j && j <= i )

        {

          cout << setw(12) << a[mu+j-i+(i-1)*(mu+1)] << "  ";

        }

      }

      cout << "\n";

    }

  }

  return;

# undef INCX

}

double *r8pbu_random ( int n, int mu, int *seed )

{

  double *a;

  int i;

  int j;

  int jhi;

  int jlo;

  double r;

  double sum2;

  a = new double[(mu+1)*n];

  for ( j = 0; j < mu; j++ )

  {

    for ( i = 0; i <= mu - j; i++ )

    {

      a[i+j*(mu+1)] = 0.0;

    }

  }

  for ( i = 0; i < n; i++ )

  {

    for ( j = i+1; j <= i4_min ( i + mu, n-1 ); j++ )

    {

      a[mu+i-j+j*(mu+1)] = r8_uniform_01 ( seed );

    }

  }

  for ( i = 1; i <= n; i++ )

  {

    sum2 = 0.0;

    jlo = i4_max ( 1, i - mu );

    for ( j = jlo; j <= i-1; j++ )

    {

      sum2 = sum2 + r8_abs ( a[(mu+j-i)+(i-1)*(mu+1)] );

    }

    jhi = i4_min ( i + mu, n );

    for ( j = i+1; j <= jhi; j++ )

    {

      sum2 = sum2 + r8_abs ( a[mu+i-j+(j-1)*(mu+1)] );

    }

    r = r8_uniform_01 ( seed );

    a[mu+(i-1)*(mu+1)] = ( 1.0 + r ) * ( sum2 + 0.01 );

  }

  return a;

}

double *r8pbu_sl ( int n, int mu, double a_lu[], double b[] )

{

  int i;

  int ilo;

  int k;

  double *x;

  x = new double[n];

  for ( k = 0; k < n; k++ )

  {

    ilo = i4_max ( 0, k - mu );

    x[k] = b[k];

    for ( i = ilo; i <= k-1; i++ )

    {

      x[k] = x[k] - x[i] * a_lu[mu+i-k+k*(mu+1)];

    }

    x[k] = x[k] / a_lu[mu+k*(mu+1)];

  }

  for ( k = n-1; 0 < k; k-- )

  {

    x[k] = x[k] / a_lu[mu+k*(mu+1)];

    ilo = i4_max ( 0, k - mu );

    for ( i = ilo; i <= k-1; i++ )

    {

      x[i] = x[i] - x[k] * a_lu[mu+i-k+k*(mu+1)];

    }

  }

  return x;

}

double *r8pbu_sor ( int n, int mu, double a[], double b[], double eps, int itchk, 

  int itmax, double omega, double x_init[] )

{

  double err;

  int i;

  int it;

  int itknt;

  double *x;

  double *xtemp;

  if ( itchk <= 0 || itmax < itchk )

  {

    cerr << "\n";

    cerr << "R8PBU_SOR - Fatal error!\n";

    cerr << "  Illegal ITCHK = " << itchk << "\n";

    exit ( 1 );

  }

  if ( itmax <= 0 )

  {

    cerr << "\n";

    cerr << "R8PBU_SOR - Fatal error!\n";

    cerr << "  Nonpositive ITMAX = " << itmax << "\n";

    exit ( 1 );

  }

  if ( omega <= 0.0 || 2.0 <= omega )

  {

    cerr << "\n";

    cerr << "R8PBU_SOR - Fatal error!\n";

    cerr << "  Illegal value of OMEGA = " << omega << "\n";

    exit ( 1 );

  }

  itknt = 0;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = x_init[i];

  }

  while ( itknt <= itmax )

  {

    for ( it = 1; it <= itchk; it++ )

    {

      xtemp = r8pbu_mxv ( n, mu, a, x );

      for ( i = 0; i < n; i++ )

      {

        xtemp[i] = x[i] + ( b[i] - xtemp[i] ) / a[mu+i*(mu+1)];

      }

      if ( omega != 1.0 )

      {

        for ( i = 0; i < n; i++ )

        {

          xtemp[i] = ( 1.0 - omega ) * x[i] + omega * xtemp[i];

        }

      }

      for ( i = 0; i < n; i++ )

      {

        x[i] = xtemp[i];

      }

    }

    delete [] xtemp;

    xtemp = r8pbu_mxv ( n, mu, a, x );

    err = 0.0;

    for ( i = 0; i < n; i++ )

    {

      err = r8_max ( err, r8_abs ( b[i] - xtemp[i] ) );

    }

    delete [] xtemp;

    if ( err <= eps )

    {

      return x;

    }

  }

  cout << "\n";

  cout << "R8PBU_SOR - Warning!\n";

  cout << "  The iteration did not converge.\n";

  return x;

}

double *r8pbu_to_r8ge ( int n, int mu, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      if ( i <= j && j <= i+mu )

      {

        b[i+j*n] = a[mu+i-j+j*(mu+1)];

      }

      else if ( i-mu <= j && j < i )

      {

        b[i+j*n] = a[mu+j-i+i*(mu+1)];

      }

      else

      {

        b[i+j*n] = 0.0;

      }

    }

  }

  return b;

}

double *r8pbu_zero ( int n, int mu )

{

  double *a;

  int i;

  int j;

  a = new double[(mu+1)*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < mu+1; i++ )

    {

      a[i+j*(mu+1)] = 0.0;

    }

  }

  return a;

}

double r8po_det ( int n, double a_lu[] )

{

  double det;

  int i;

  det = 1.0;

  for ( i = 0; i < n; i++ )

  {

    det = det * a_lu[i+i*n];

  }

  return det;

}

double *r8po_fa ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  int k;

  double s;

  b = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      b[i+j*n] = a[i+j*n];

    }

  }

  for ( j = 0; j < n; j++ )

  {

    for ( k = 0; k <= j-1; k++ )

    {

      for ( i = 0; i <= k-1; i++ )

      {

        b[k+j*n] = b[k+j*n] - b[i+k*n] * b[i+j*n];

      }

      b[k+j*n] = b[k+j*n] / b[k+k*n];

    }

    s = b[j+j*n];

    for ( i = 0; i <= j-1; i++ )

    {

      s = s - b[i+j*n] * b[i+j*n];

    }

    if ( s <= 0.0 )

    {

      delete [] b;

      return NULL;

    }

    b[j+j*n] = sqrt ( s );

  }

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < i; j++ )

    {

      b[i+j*n] = 0.0;

    }

  }

  return b;

}

double *r8po_indicator ( int n )

{

  double *a;

  int fac;

  int i;

  int j;

  a = new double[n*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( i = 1; i <= n; i++ )

  {

    for ( j = 1; j <= i-1; j++ )

    {

      a[i-1+(j-1)*n] = 0.0;

    }

    for ( j = i; j <= n; j++ )

    {

      a[i-1+(j-1)*n] = ( double ) ( fac * i + j );

    }

  }

  return a;

}

double *r8po_inverse ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  int k;

  double t;

  b = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      b[i+j*n] = a[i+j*n];

    }

  }

  for ( k = 0; k < n; k++ )

  {

    b[k+k*n] = 1.0 / b[k+k*n];

    for ( i = 0; i < k; i++ )

    {

      b[i+k*n] = -b[i+k*n] * b[k+k*n];

    }

    for ( j = k+1; j < n; j++ )

    {

      t = b[k+j*n];

      b[k+j*n] = 0.0;

      for ( i = 0; i <= k; i++ )

      {

        b[i+j*n] = b[i+j*n] + t * b[i+k*n];

      }

    }

  }

  for ( j = 0; j < n; j++ )

  {

    for ( k = 0; k < j; k++ )

    {

      t = b[k+j*n];

      for ( i = 0; i <= k; i++ )

      {

        b[i+k*n] = b[i+k*n] + t * b[i+j*n];

      }

    }

    t = b[j+j*n];

    for ( i = 0; i <= j; i++ )

    {

      b[i+j*n] = b[i+j*n] * t;

    }

  }

  return b;

}

double *r8po_ml ( int n, double a_lu[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = a_lu[i+i*n] * x[i];

    for ( j = i+1; j < n; j++ )

    {

      b[i] = b[i] + a_lu[i+j*n] * x[j];

    }

  }

  for ( j = n-1; 0 <= j; j-- )

  {

    b[j] = a_lu[j+j*n] * b[j];

    for ( i = 0; i < j; i++ )

    {

      b[j] = b[j] + b[i] * a_lu[i+j*n];

    }

  }

  return b;

}

double *r8po_mxm ( int n, double a[], double b[] )

{

  double aik;

  double bkj;

  double *c;

  int i;

  int j;

  int k;

  c = new double[n*n];

  for ( i = 1; i <= n; i++ )

  {

    for ( j = 1; j <= n; j++ )

    {

      c[i-1+(j-1)*n] = 0.0;

    }

  }

  for ( i = 1; i <= n; i++ )

  {

    for ( j = i; j <= n; j++ )

    {

      for ( k = 1; k <= n; k++ )

      {

        if ( i <= k )

        {

          aik = a[i-1+(k-1)*n];

        }

        else

        {

          aik = a[k-1+(i-1)*n];

        }

        if ( k <= j )

        {

          bkj = b[k-1+(j-1)*n];

        }

        else

        {

          bkj = b[j-1+(k-1)*n];

        }

        c[i-1+(j-1)*n] = c[i-1+(j-1)*n] + aik * bkj;

      }

    }

  }

  return c;

}

double *r8po_mxv ( int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

    for ( j = 0; j < i; j++ )

    {

      b[i] = b[i] + a[j+i*n] * x[j];

    }

    for ( j = i; j < n; j++ )

    {

      b[i] = b[i] + a[i+j*n] * x[j];

    }

  }

  return b;

}

void r8po_print ( int n, double a[], string title )

{

  r8po_print_some ( n, a, 1, 1, n, n, title );

  return;

}

void r8po_print_some ( int n, double a[], int ilo, int jlo, int ihi, 

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

    i2hi = i4_min ( ihi, n );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(5) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( i <= j )

        {

          cout << setw(12) << a[i-1+(j-1)*n] << "  ";

        }

        else

        {

          cout << setw(12) << a[j-1+(i-1)*n] << "  ";

        }

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8po_random ( int n, int *seed )

{

  double *a;

  int i;

  int j;

  int k;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      a[i+j*n] = 0.0;

    }

  }

  for ( i = n; 1 <= i; i-- )

  {

    for ( j = i; j <= n; j++ )

    {

      a[i-1+(j-1)*n] = r8_uniform_01 ( seed );

    }

    for ( j = n; i <= j; j-- )

    {

      for ( k = i+1; k <= j; k++ )

      {

        a[k-1+(j-1)*n] = a[k-1+(j-1)*n] + a[i-1+(k-1)*n] * a[i-1+(j-1)*n];

      }

      a[i-1+(j-1)*n] = a[i-1+(i-1)*n] * a[i-1+(j-1)*n];

    }

  }

  return a;

}

double *r8po_sl ( int n, double a_lu[], double b[] )

{

  int i;

  int k;

  double *x;

  x = new double[n];

  for ( k = 0; k < n; k++ )

  {

    x[k] = b[k];

  }

  for ( k = 0; k < n; k++ )

  {

    for ( i = 0; i < k; i++ )

    {

      x[k] = x[k] - x[i] * a_lu[i+k*n];

    }

    x[k] = x[k] / a_lu[k+k*n];

  }

  for ( k = n-1; 0 <= k; k-- )

  {

    x[k] = x[k] / a_lu[k+k*n];

    for ( i = 0; i < k; i++ )

    {

      x[i] = x[i] - a_lu[i+k*n] * x[k];

    }

  }

  return x;

}

double *r8po_to_r8ge ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      if ( i <= j )

      {

        b[i+j*n] = a[i+j*n];

      }

      else

      {

        b[i+j*n] = a[j+i*n];

      }

    }

  }

  return b;

}

double *r8po_zero ( int n )

{

  double *a;

  int i;

  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      a[i+j*n] = 0.0;

    }

  }

  return a;

}

double r8pp_det ( int n, double a_lu[] )

{

  double det;

  int i;

  int k;

  det = 1.0;

  k = 0;

  for ( i = 0; i < n; i++ )

  {

    k = k + i;

    det = det * a_lu[k];

  }

  return det;

}

double *r8pp_fa ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  int jj;

  int k;

  int kj;

  int kk;

  double s;

  double t;

  b = new double[(n*(n+1))/2];

  for ( i = 0; i < (n*(n+1))/2; i++ )

  {

    b[i] = a[i];

  }

  jj = 0;

  for ( j = 1; j <= n; j++ )

  {

    s = 0.0;

    kj = jj;

    kk = 0;

    for ( k = 1; k <= j-1; k++ )

    {

      kj = kj + 1;

      t = b[kj-1];

      for ( i = 1; i <= k-1; i++ )

      {

        t = t - b[kk+i-1] * b[jj+i-1];

      }

      kk = kk + k;

      t = t / b[kk-1];

      b[kj-1] = t;

      s = s + t * t;

    }

    jj = jj + j;

    s = b[jj-1] - s;

    if ( s <= 0.0 )

    {

      return NULL;

    }

    b[jj-1] = sqrt ( s );

  }

  return b;

}

double *r8pp_indicator ( int n )

{

  double *a;

  int fac;

  int i;

  int j;

  int k;

  a = new double[(n*(n+1))/2];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  k = 0;

  for ( j = 1; j <= n; j++ )

  {

    for ( i = 1; i <= j; i++ )

    {

      a[k] = ( double ) ( fac * i + j );

      k = k + 1;

    }

  }

  return a;

}

double *r8pp_mxv ( int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  int k;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

    for ( j = 0; j < i; j++ )

    {

      k = j + ( i * ( i + 1 ) ) / 2;

      b[i] = b[i] + a[k] * x[j];

    }

    for ( j = i; j < n; j++ )

    {

      k = i + ( j * ( j + 1 ) ) / 2;

      b[i] = b[i] + a[k] * x[j];

    }

  }

  return b;

}

void r8pp_print ( int n, double a[], string title )

{

  r8pp_print_some ( n, a, 1, 1, n, n, title );

  return;

}

void r8pp_print_some ( int n, double a[], int ilo, int jlo, int ihi, 

  int jhi, string title )

{

# define INCX 5

  double aij;

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

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, n );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(6) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( i <= j )

        {

          aij = a[i-1+(j*(j-1))/2];

        }

        else

        {

          aij = a[j-1+(i*(i-1))/2];

        }

        cout << setw(12) << aij << "  ";

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8pp_random ( int n, int *seed )

{

  double *a;

  int i;

  int ii;

  int ij;

  int ik;

  int j;

  int k;

  int kj;

  a = new double[(n*(n+1))/2];

  for ( i = 0; i < (n*(n+1))/2; i++ )

  {

    a[i] = 0.0;

  }

  for ( i = n; 1 <=i; i-- )

  {

    for ( j = i; j <= n; j++ )

    {

      ij = i + ( j * ( j - 1 ) ) / 2;

      a[ij-1] = r8_uniform_01 ( seed );

    }

    for ( j = n; i <= j; j-- )

    {

      ij = i + ( j * ( j - 1 ) ) / 2;

      for ( k = i+1; k <= j; k++ )

      {

        kj = k + (j*(j-1))/2;

        ik = i + (k*(k-1))/2;

        a[kj-1] = a[kj-1] + a[ik-1] * a[ij-1];

      }

      ii = i + (i*(i-1))/2;

      a[ij-1] = a[ii-1] * a[ij-1];

    }

  }

  return a;

}

double *r8pp_sl ( int n, double a_lu[], double b[] )

{

  int i;

  int k;

  int kk;

  double t;

  double *x;

  x = new double[n];

  kk = 0;

  for ( k = 1; k <= n; k++ )

  {

    t = 0.0;

    for ( i = 0; i < k-1; i++ )

    {

      t = t + a_lu[kk+i] * x[i];

    }

    kk = kk + k;

    x[k-1] = ( b[k-1] - t ) / a_lu[kk-1];

  }

  for ( k = n; 1 <= k; k-- )

  {

    x[k-1] = x[k-1] / a_lu[kk-1];

    kk = kk - k;

    t = -x[k-1];

    for ( i = 0; i < k-1; i++ )

    {

      x[i] = x[i] + t * a_lu[kk+i];

    }

  }

  return x;

}

double *r8pp_to_r8ge ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      if ( i <= j )

      {

        b[i+j*n] = a[i+(j*(j+1))/2];

      }

      else

      {

        b[i+j*n] = a[j+(i*(i+1))/2];

      }

    }

  }

  return b;

}

double *r8pp_zero ( int n )

{

  double *a;

  int k;

  a = new double[(n*(n+1))/2];

  for ( k = 0; k < (n*(n+1))/2; k++ )

  {

    a[k] = 0.0;

  }

  return a;

}

double *r8ri_to_r8ge ( int nz, int ija[], double sa[], int n )

{

  double *a;

  int i;

  int j;

  int k;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      a[i+j*n] = 0.0;

    }

  }

  for ( k = 0; k < n; k++ )

  {

    i = k;

    j = k;

    a[i+j*n] = sa[k];

  }

  for ( i = 0; i < n; i++ )

  {

    for ( k = ija[i]; k < ija[i+1]; k++ )

    {

      j = ija[k];

      a[i+j*n] = sa[k];

    }

  }

  return a;

}

void r8row_swap ( int m, int n, double a[], int row1, int row2 )

{

# define OFFSET 1

  int j;

  double t;

  if ( row1 < 0+OFFSET || m-1+OFFSET < row1 )

  {

    cerr << "\n";

    cerr << "R8ROW_SWAP - Fatal error!\n";

    cerr << "  ROW1 is out of range.\n";

    exit ( 1 );

  }

  if ( row2 < 0+OFFSET || m-1+OFFSET < row2 )

  {

    cerr << "\n";

    cerr << "R8ROW_SWAP - Fatal error!\n";

    cerr << "  ROW2 is out of range.\n";

    exit ( 1 );

  }

  if ( row1 == row2 )

  {

    return;

  }

  for ( j = 0; j < n; j++ )

  {

    t                  = a[row1-OFFSET+j*m];

    a[row1-OFFSET+j*m] = a[row2-OFFSET+j*m];

    a[row2-OFFSET+j*m] = t;

  }

  return;

# undef OFFSET

}

double *r8s3_indicator ( int n, int nz_num, int isym, int row[], int col[] )

{

  double *a;

  int fac;

  int i;

  int j;

  int k;

  a = new double[nz_num];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( k = 0; k < nz_num; k++ )

  {

    i = row[k];

    j = col[k];

    a[k] = ( double ) ( fac * i + j );

  }

  return a;

}

void r8s3_print ( int m, int n, int nz_num, int isym, int row[], int col[], 

  double a[], string title )

{

  r8s3_print_some ( m, n, nz_num, isym, row, col, a, 1, 1, m, n, title );

  return;

}

void r8s3_print_some ( int m, int n, int nz_num, int isym, int row[], int col[], 

  double a[], int ilo, int jlo, int ihi, int jhi, string title )

{

# define INCX 5

  double aij;

  int i;

  int i2hi;

  int i2lo;

  int inc;

  int index[INCX];

  int j;

  int j2;

  int j2hi;

  int j2lo;

  int k;

  bool nonzero;

  cout << "\n";

  cout << title << "\n";

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

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, m );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      nonzero = false;

 

      for ( j2 = 0; j2 < inc; j2++ )

      {

        index[j2] = -1;

      }

      for ( k = 0; k < nz_num; k++ )

      {

        if ( i == row[k] && j2lo <= col[k] && col[k] <= j2hi )

        {

          j2 = col[k] - j2lo + 1;

          if ( a[k] != 0.0 )

          {

            index[j2-1] = k;

            nonzero = true;

          }

        }

        else if ( isym == 1 && m == n &&

          i == col[k] && j2lo <= row[k] && row[k] <= j2hi )

        {

          j2 = row[k] - j2lo + 1;

          if ( a[k] != 0.0 )

          {

            index[j2-1] = k;

            nonzero = true;

          }

        }

      }

      if ( nonzero )

      {

        cout << setw(5) << i << " ";

        for ( j2 = 0; j2 < inc; j2++ )

        {

          if ( 0 <= index[j2] )

          {

            aij = a[index[j2]];

          }

          else

          {

            aij = 0.0;

          }

          cout << setw(14) << aij;

        }

        cout << "\n";

      }

    }

  }

  cout << "\n";

  return;

# undef INCX

}

void r8s3_read ( string input_file, int n, int nz_num, int row[], int col[], 

  double a[] )

{

  ifstream input;

  int k;

  input.open ( input_file.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R8S3_READ - Fatal error!\n";

    cerr << "  Could not open the input file: \"" << input_file << "\"\n";

    exit ( 1 );

  }

  for ( k = 0; k < nz_num; k++ )

  {

    input >> row[k] >> col[k] >> a[k];

  }

  input.close ( );

  return;

}

void r8s3_read_size ( string input_file, int *n, int *nz_num )

{

  double a_k;

  int col_k;

  ifstream input;

  int row_k;

  *nz_num = 0;

  *n = 0;

  input.open ( input_file.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R8S3_READ_SIZE - Fatal error!\n";

    cerr << "  Could not open the input file: \"" << input_file << "\"\n";

    exit ( 1 );

  }

  for ( ; ; )

  {

    input >> row_k >> col_k >> a_k;

    if ( input.eof ( ) )

    {

      break;

    }

    *nz_num = *nz_num + 1;

    *n = i4_max ( *n, row_k );

    *n = i4_max ( *n, col_k );

  }

  input.close ( );

  return;

}

void r8s3_write ( int n, int nz_num, int isym, int row[], int col[], 

  double a[], string output_file )

{

  int k;

  ofstream output;

  output.open ( output_file.c_str ( ) );

  if ( !output )

  {

    cerr << "\n";

    cerr << "R8S3_WRITE - Fatal error!\n";

    cerr << "  Could not open the output file.\n";

    exit ( 1 );

  }

  for ( k = 0; k < nz_num; k++ )

  {

    output << "  " << setw(8) << row[k]

           << "  " << setw(8) << col[k]

           << "  " << setw(16) << a[k] << "\n";

  }

  output.close ( );

  return;

}

double *r8sd_cg ( int n, int ndiag, int offset[], double a[], double b[], 

  double x[] )

{

  double alpha;

  double *ap;

  double beta;

  int i;

  int it;

  double *p;

  double pap;

  double pr;

  double *r;

  double rap;

  double *x_new;

  x_new = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x_new[i] = x[i];

  }

  ap = r8sd_mxv ( n, ndiag, offset, a, x_new );

  r = new double[n];

  for ( i = 0; i < n; i++ )

  {

    r[i] = b[i] - ap[i];

  }

  p = new double[n];

  for ( i = 0; i < n; i++ )

  {

    p[i] = b[i] - ap[i];

  }

  for ( it = 1; it < n; it++ )

  {

    delete [] ap;

    ap = r8sd_mxv ( n, ndiag, offset, a, p );

    pap = r8vec_dot_product ( n, p, ap );

    if ( pap == 0.0 )

    {

      break;

    }

    pr = r8vec_dot_product ( n, p, r );

    alpha = pr / pap;

    for ( i = 0; i < n; i++ )

    {

      x_new[i] = x_new[i] + alpha * p[i];

    }

    for ( i = 0; i < n; i++ )

    {

      r[i] = r[i] - alpha * ap[i];

    }

    rap = r8vec_dot_product ( n, r, ap );

    beta = -rap / pap;

    for ( i = 0; i < n; i++ )

    {

      p[i] = r[i] + beta * p[i];

    }

  }

  delete [] ap;

  delete [] p;

  delete [] r;

  return x_new;

}

double *r8sd_indicator ( int n, int ndiag, int offset[] )

{

  double *a;

  int diag;

  int fac;

  int i;

  int j;

  a = new double[n*ndiag];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( i = 1; i <= n; i++ )

  {

    for ( diag = 1; diag <= ndiag; diag++ )

    {

      j = i + offset[diag-1];

      if ( 1 <= j && j <= n )

      {

        a[i-1+(diag-1)*n] = ( double ) ( fac * i + j );

      }

      else

      {

        a[i-1+(diag-1)*n] = 0.0;

      }

    }

  }

  return a;

}

double *r8sd_mxv ( int n, int ndiag, int offset[], double a[], double x[] )

{

  double *b;

  int i;

  int j;

  int jdiag;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

  }

  for ( i = 0; i < n; i++ )

  {

    for ( jdiag = 0; jdiag < ndiag; jdiag++ )

    {

      j = i + offset[jdiag];

      if ( 0 <= j && j < n )

      {

        b[i] = b[i] + a[i+jdiag*n] * x[j];

        if ( offset[jdiag] != 0 )

        {

          b[j] = b[j] + a[i+jdiag*n] * x[i];

        }

      }

    }

  }

  return b;

}

void r8sd_print ( int n, int ndiag, int offset[], double a[], string title )

{

  r8sd_print_some ( n, ndiag, offset, a, 1, 1, n, n, title );

  return;

}

void r8sd_print_some ( int n, int ndiag, int offset[], double a[], int ilo, 

  int jlo, int ihi, int jhi, string title )

{

# define INCX 5

  double aij;

  int i;

  int i2hi;

  int i2lo;

  int j;

  int j2hi;

  int j2lo;

  int jdiag;

  cout << "\n";

  cout << title << "\n";

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n );

    j2hi = i4_min ( j2hi, jhi );

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, n );

    for ( i = i2lo; i <= i2hi; i++ )

    {

    cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        aij = 0.0;

        for ( jdiag = 0; jdiag < ndiag; jdiag++ )

        {

          if ( j - i == offset[jdiag] )

          {

            aij = a[i-1+jdiag*n];

          }

          else if ( j - i == - offset[jdiag] )

          {

            aij = a[j-1+jdiag*n];

          }

        }

        cout << setw(12) << aij << "  ";

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8sd_random ( int n, int ndiag, int offset[], int *seed )

{

  double *a;

  int i;

  int j;

  int jj;

  a = new double[n*ndiag];

  for ( i = 1; i <= n; i++ )

  {

    for ( j = 1; j <= ndiag; j++ )

    {

      jj = i + offset[j-1];

      if ( 1 <= jj && jj <= n )

      {

        a[i-1+(j-1)*n] = r8_uniform_01 ( seed );

      }

      else

      {

        a[i-1+(j-1)*n] = 0.0;

      }

    }

  }

  return a;

}

double *r8sd_to_r8ge ( int n, int ndiag, int offset[], double a[] )

{

  double *b;

  int i;

  int j;

  int jj;

  b = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      b[i+j*n] = 0.0;

    }

  }

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < ndiag; j++ )

    {

      jj = i + offset[j];

      if ( 0 <= jj && jj <= n-1 )

      {

        b[i+jj*n] = a[i+j*n];

        if ( i != jj )

        {

          b[jj+i*n] = a[i+j*n];

        }

      }

    }

  }

  return b;

}

double *r8sd_zero ( int n, int ndiag )

{

  double *a;

  int i;

  int j;

  a = new double[n*ndiag];

  for ( j = 0; j < ndiag; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      a[i+j*n] = 0.0;

    }

  }

  return a;

}

double *r8sm_ml ( int n, double a_lu[], double u[], double v[], int pivot[], 

  double x[], int job )

{

  double *b;

  int i;

  double ux;

  double vx;

  b = r8ge_ml ( n, a_lu, pivot, x, job );

  if ( job == 0 )

  {

    vx = 0.0;

    for ( i = 0; i < n; i++ )

    {

      vx = vx + v[i] * x[i];

    }

    for ( i = 0; i < n; i++ )

    {

      b[i] = b[i] - u[i] * vx;

    }

  }

  else

  {

    ux = 0.0;

    for ( i = 0; i < n; i++ )

    {

      ux = ux + u[i] * x[i];

    }

    for ( i = 0; i < n; i++ )

    {

      b[i] = b[i] - v[i] * ux;

    }

  }

  return b;

}

double *r8sm_mxv ( int m, int n, double a[], double u[], double v[], double x[] )

{

  double *b;

  int i;

  int j;

  double vx;

  b = new double[m];

  vx = 0.0;

  for ( j = 0; j < n; j++ )

  {

    vx = vx + v[j] * x[j];

  }

  for ( i = 0; i < m; i++ )

  {

    b[i] = 0.0;

    for ( j = 0; j < n; j++ )

    {

      b[i] = b[i] + a[i+j*m] * x[j];

    }

    b[i] = b[i] - u[i] * vx;

  }

  return b;

}

void r8sm_print ( int m, int n, double a[], double u[], double v[], string title )

{

  r8sm_print_some ( m, n, a, u, v, 1, 1, m, n, title );

  return;

}

void r8sm_print_some ( int m, int n, double a[], double u[], double v[], int ilo, 

  int jlo, int ihi, int jhi, string title )

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

    cout << "  Col: ";

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

      cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        cout << setw(12) << a[i-1+(j-1)*n] - u[i-1] * v[j-1] << "  ";

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

void r8sm_random ( int m, int n, double a[], double u[], double v[], int *seed )

{

  int i;

  int j;

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      a[i+j*m] = r8_uniform_01 ( seed );

    }

  }

  for ( i = 0; i < m; i++ )

  {

    u[i] = r8_uniform_01 ( seed );

  }

  for ( j = 0; j < n; j++ )

  {

    v[j] = r8_uniform_01 ( seed );

  }

  return;

}

double *r8sm_sl ( int n, double a_lu[], double u[], double v[], double b[], 

  int pivot[], int job )

{

  double alpha;

  double beta;

  int i;

  int job_local;

  double *w;

  double *x;

  x = new double[n];

  if ( job == 0 )

  {

    job_local = 1;

    w = r8ge_sl_new ( n, a_lu, pivot, v, job_local );

    beta = 0.0;

    for ( i = 0; i < n; i++ )

    {

      beta = beta + w[i] * b[i];

    }

    job_local = 0;

    x = r8ge_sl_new ( n, a_lu, pivot, b, job_local );

    job_local = 0;

    delete [] w;

    w = r8ge_sl_new ( n, a_lu, pivot, u, job_local );

    alpha = 1.0;

    for ( i = 0; i < n; i++ )

    {

      alpha = alpha - v[i] * w[i];

    }

  }

  else

  {

    job_local = 0;

    w = r8ge_sl_new ( n, a_lu, pivot, u, job_local );

    beta = 0.0;

    for ( i = 0; i < n; i++ )

    {

      beta = beta + w[i] * b[i];

    }

    job_local = 1;

    x = r8ge_sl_new ( n, a_lu, pivot, b, job_local );

    job_local = 1;

    delete [] w;

    w = r8ge_sl_new ( n, a_lu, pivot, v, job_local );

    alpha = 1.0;

    for ( i = 0; i < n; i++ ) 

    {

      alpha = alpha - u[i] * w[i];

    }

  }

  if ( alpha == 0.0 )

  {

    cerr << "\n";

    cerr << "R8SM_SL - Fatal error!\n";

    cerr << "  The divisor ALPHA is zero.\n";

    exit ( 1 );

  }

  alpha = 1.0 / alpha;

  for ( i = 0; i < n; i++ )

  {

    x[i] = x[i] + alpha * beta * w[i];

  }

  delete [] w;

  return x;

}

double *r8sm_to_r8ge ( int m, int n, double a[], double u[], double v[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      b[i+j*m] = a[i+j*m] - u[i] * v[j];

    }

  }

  return b;

}

double *r8sm_vxm ( int m, int n, double a[], double u[], double v[], double x[] )

{

  double *b;

  double dot;

  int i;

  int j;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

    for ( j = 0; j < m; j++ )

    {

      b[i] = b[i] + x[j] * a[j+i*m];

    }

    dot = 0.0;

    for ( j = 0; j < m; j++ )

    {

      dot = dot + u[j] * x[j];

    }

    b[i] = b[i] - v[i] * dot;

  }

  return b;

}

void r8sm_zero ( int m, int n, double a[], double u[], double v[] )

{

  int i;

  int j;

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      a[i+j*m] = 0.0;

    }

  }

  for ( i = 0; i < m; i++ )

  {

    u[i] = 0.0;

  }

  for ( i = 0; i < n; i++ )

  {

    v[i] = 0.0;

  }

  return;

}

bool r8sp_check ( int m, int n, int nz_num, int row[], int col[] )

{

  bool check;

  int k;

  check = true;

  for ( k = 0; k < nz_num; k++ )

  {

    if ( row[k] < 1 || m < row[k] )

    {

      check = false;

      return check;

    }

  }

  for ( k = 0; k < nz_num; k++ )

  {

    if ( col[k] < 1 || n < col[k] )

    {

      check = false;

      return check;

    }

  }

  for ( k = 0; k < nz_num - 1; k++ )

  {

    if ( row[k+1] < row[k] )

    {

      check = false;

      return check;

    }

  }

  for ( k = 0; k < nz_num - 1; k++ )

  {

    if ( row[k] == row[k+1] )

    {

      if ( col[k+1] <= col[k] )

      {

        check = false;

        return check;

      }

    }

  }

  return check;

}

int r8sp_ij_to_k ( int nz_num, int row[], int col[], int i, int j )

{

  int hi;

  int k;

  int lo;

  int md;

  lo = 1;

  hi = nz_num;

  for ( ; ; )

  {

    if ( hi < lo )

    {

      k = -1;

      break;

    }

    md = ( lo + hi ) / 2;

    if ( row[md-1] < i || ( row[md-1] == i && col[md-1] < j ) )

    {

      lo = md + 1;

    }

    else if ( i < row[md-1] || ( row[md-1] == i && j < col[md-1] ) )

    {

      hi = md - 1;

    }

    else

    {

      k = md;

      break;

    }

  }

  return k;

}

double *r8sp_indicator ( int m, int n, int nz_num, int row[], int col[] )

{

  double *a;

  int fac;

  int i;

  int j;

  int k;

  a = new double[nz_num];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( k = 0; k < nz_num; k++ )

  {

    i = row[k];

    j = col[k];

    a[k] = ( double ) ( fac * i + j );

  }

  return a;

}

double *r8sp_mxv ( int m, int n, int nz_num, int row[], int col[], 

  double a[], double x[] )

{

  double *b;

  int i;

  int j;

  int k;

  b = new double[m];

  for ( i = 0; i < m; i++ )

  {

    b[i] = 0.0;

  }

  for ( k = 0; k < nz_num; k++ )

  {

    i = row[k];

    j = col[k];

    b[i-1] = b[i-1] + a[k] * x[j-1];

  }

  return b;

}

void r8sp_print ( int m, int n, int nz_num, int row[], int col[], 

  double a[], string title )

{

  r8sp_print_some ( m, n, nz_num, row, col, a, 1, 1, m, n, title );

  return;

}

void r8sp_print_some ( int m, int n, int nz_num, int row[], int col[], 

  double a[], int ilo, int jlo, int ihi, int jhi, string title )

{

# define INCX 5

  double aij[INCX];

  int i;

  int i2hi;

  int i2lo;

  int inc;

  int j;

  int j2;

  int j2hi;

  int j2lo;

  int k;

  bool nonzero;

  cout << "\n";

  cout << title << "\n";

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n );

    j2hi = i4_min ( j2hi, jhi );

    inc = j2hi + 1 - j2lo;

    cout << "\n";

    cout << "  Col:  ";

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

      nonzero = false;

      for ( j2 = 0; j2 < INCX; j2++ )

      {

        aij[j2] = 0.0;

      }

      for ( k = 1; k <= nz_num; k++ )

      {

        if ( i == row[k-1] && j2lo <= col[k-1] && col[k-1] <= j2hi )

        {

          j2 = col[k-1] - j2lo;

          if ( a[k-1] == 0.0 )

          {

            continue;

          }

          nonzero = true;

          aij[j2] = aij[j2] + a[k-1];

        }

      }

      if ( nonzero )

      {

        cout << setw(6) << i;

        for ( j2 = 0; j2 < inc; j2++ )

        {

          cout << setw(12) << aij[j2] << "  ";

        }

        cout << "\n";

      }

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8sp_random ( int m, int n, int nz_num, int row[], int col[], 

  int *seed )

{

  return ( r8vec_random ( nz_num, 0.0, 1.0, seed ) );

}

void r8sp_read ( string input_file, int m, int n, int nz_num, int row[], 

  int col[], double a[] )

{

  ifstream input;

  int k;

  input.open ( input_file.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R8SP_READ - Fatal error!\n";

    cerr << "  Could not open the input file: \"" << input_file << "\"\n";

    exit ( 1 );

  }

  for ( k = 0; k < nz_num; k++ )

  {

    input >> row[k] >> col[k] >> a[k];

  }

  input.close ( );

  return;

}

void r8sp_read_size ( string input_file, int *m, int *n, int *nz_num )

{

  double a_k;

  int col_k;

  ifstream input;

  int row_k;

  *m = 0;

  *n = 0;

  *nz_num = 0;

  input.open ( input_file.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R8SP_READ_SIZE - Fatal error!\n";

    cerr << "  Could not open the input file: \"" << input_file << "\"\n";

    exit ( 1 );

  }

  for ( ; ; )

  {

    input >> row_k >> col_k >> a_k;

    if ( input.eof ( ) )

    {

      break;

    }

    *m = i4_max ( *m, row_k );

    *n = i4_max ( *n, col_k );

    *nz_num = *nz_num + 1;

  }

  input.close ( );

  return;

}

double *r8sp_to_r8ge ( int m, int n, int nz_num, int row[], int col[], 

  double a[] )

{

  double *b;

  int i;

  int j;

  int k;

  b = new double[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      b[i+j*m] = 0.0;

    }

  }

  for ( k = 0; k < nz_num; k++ )

  {

    b[row[k]-1+(col[k]-1)*m] = a[k];

  }

  return b;

}

void r8sp_to_r8ncf ( int m, int n, int nz_num, int row[], int col[], 

  double a[], int rowcol[] )

{

  int i;

  for ( i = 0; i < nz_num; i++ )

  {

    rowcol[0+i*2] = row[i];

    rowcol[1+i*2] = col[i];

  }

  return;

}

double *r8sp_vxm ( int m, int n, int nz_num, int row[], int col[], 

  double a[], double x[] )

{

  double *b;

  int i;

  int j;

  int k;

  b = new double[n];

  for ( j = 0; j < n; j++ )

  {

    b[j] = 0.0;

  }

  for ( k = 0; k < nz_num; k++ )

  {

    i = row[k];

    if ( i < 0 || m < i )

    {

      cerr << "\n";

      cerr << "R8SP_VXM - Fatal error!\n";

      cerr << "  I < 0 or " << m << " M < I.\n";

      exit ( 1 );

    }

    j = col[k];

    if ( j < 0 || n < j )

    {

      cerr << "\n";

      cerr << "R8SP_VXM - Fatal error!\n";

      cerr << "  J < 0 or " << n << " N < J.\n";

      exit ( 1 );

    }

    b[j-1] = b[j-1] + a[k] * x[i-1];

  }

  return b;

}

void r8sp_write ( int m, int n, int nz_num, int row[], int col[], double a[], 

  string output_file )

{

  int k;

  ofstream output;

  output.open ( output_file.c_str ( ) );

  if ( !output )

  {

    cerr << "\n";

    cerr << "R8SP_WRITE - Fatal error!\n";

    cerr << "  Could not open the output file.\n";

    exit ( 1 );

  }

  for ( k = 0; k < nz_num; k++ )

  {

    output << "  " << setw(8) << row[k]

           << "  " << setw(8) << col[k]

           << "  " << setw(16) << a[k] << "\n";

  }

  output.close ( );

  return;

}

double *r8sp_zero ( int m, int n, int nz_num, int row[], int col[] )

{

  double *a;

  int i;

  a = new double[nz_num];

  for ( i = 0; i < nz_num; i++ )

  {

    a[i] = 0.0;

  }

  return a;

}

void r8sr_indicator ( int n, int nz, int row[], int col[], double diag[], 

  double off[] )

{

  int fac;

  int i;

  int j;

  int k;

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( i = 1; i <= n; i++ )

  {

    j = i;

    diag[i-1] = ( double ) ( fac * i + j );

    for ( k = row[i-1]; k <= row[i]-1; k++ )

    {

      j = col[k-1];

      off[k-1] = ( double ) ( fac * i + j );

    }

  }

  return;

}

double *r8sr_mxv ( int n, int nz, int row[], int col[], double diag[], 

  double off[], double x[] )

{

  double *b;

  int i;

  int j;

  int k;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = diag[i] * x[i];

  }

  for ( i = 0; i < n; i++ )

  {

    for ( k = row[i]; k <= row[i+1] - 1; k++ )

    {

      j = col[k-1];

      b[i] = b[i] + off[k-1] * x[j-1];

    }

  }

  return b;

}

void r8sr_print ( int n, int nz, int row[], int col[], double diag[], 

  double off[], string title )

{

  r8sr_print_some ( n, nz, row, col, diag, off, 1, 1, n, n, title );

  return;

}

void r8sr_print_some ( int n, int nz, int row[], int col[], double diag[], 

  double off[], int ilo, int jlo, int ihi, int jhi, string title )

{

# define INCX 5

  double aij;

  int i;

  int i2hi;

  int i2lo;

  int j;

  int j2hi;

  int j2lo;

  int k;

  cout << "\n";

  cout << title << "\n";

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n );

    j2hi = i4_min ( j2hi, jhi );

    cout << "\n";

    cout << "  Col:  ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, n );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(6) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        aij = 0.0;

        if ( j == i )

        {

          aij = diag[i-1];

        }

        else

        {

          for ( k = row[i-1]; k <= row[i]-1; k++ )

          {

            if ( j == col[k-1] )

            {

              aij = off[k-1];

            }

          }

        }

        cout << setw(12) << aij << "  ";

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

void r8sr_random ( int n, int nz, int row[], int col[], double diag[], 

  double off[], int *seed )

{

  int i;

  int j;

  for ( i = 0; i < n; i++ )

  {

    diag[i] = r8_uniform_01 ( seed );

    for ( j = row[i]-1; j <= row[i+1]-2; j++ )

    {

      off[j] = r8_uniform_01 ( seed );

    }

  }

  return;

}

double *r8sr_to_r8ge ( int n, int nz, int row[], int col[], double diag[], 

  double off[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < n; i++ )

    {

      b[i+j*n] = 0.0;

    }

  }

  for ( i = 0; i < n; i++ )

  {

    b[i+i*n] = diag[i];

  }

  for ( i = 0; i < n; i++ )

  {

    for ( j = row[i]-1; j <= row[i+1]-2; j++ )

    {

      b[i+(col[j]-1)*n] = off[j];

    }

  }

  return b;

}

double *r8sr_vxm ( int n, int nz, int row[], int col[], double diag[], 

  double off[], double x[] )

{

  double *b;

  int i;

  int j;

  int k;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = diag[i] * x[i];

  }

  for ( i = 0; i < n; i++ )

  {

    for ( k = row[i]; k <= row[i+1] - 1; k++ )

    {

      j = col[k-1];

      b[j-1] = b[j-1] + off[k-1] * x[i];

    }

  }

  return b;

}

void r8sr_zero ( int n, int nz, int row[], int col[], double diag[], 

  double off[] )

{

  int i;

  int j;

  for ( i = 0; i < n; i++ )

  {

    diag[i] = 0.0;

    for ( j = row[i]-1; j <= row[i+1]-2; j++ )

    {

      off[j] = 0.0;

    }

  }

  return;

}

bool r8ss_error ( int diag[], int n, int na )

{

  int i;

  if ( n < 1 )

  {

    cout << "\n";

    cout << "R8SS_ERROR - Illegal N = " << n << "\n";

    return true;

  }

  if ( na < n )

  {

    cout << "\n";

    cout << "R8SS_ERROR - Illegal NA < N = " << n << "\n";

    return true;

  }

  if ( diag[0] != 1 )

  {

    cout << "\n";

    cout << "R8SS_ERROR - DIAG[0] != 1.\n";

    return true;

  }

  for ( i = 0; i < n-1; i++ )

  { 

    if ( diag[i+1] <= diag[i] ) 

    {

      cout << "\n";

      cout << "R8SS_ERROR - DIAG[I+1] <= DIAG[I].\n";

      return true;

    }

  }

  if ( na < diag[n-1] ) 

  {

    cout << "\n";

    cout << "R8SS_ERROR - NA < DIAG[N-1].\n";

    return true;

  }

  return false;

}

double *r8ss_indicator ( int n, int *na, int diag[] )

{

  double *a;

  int fac;

  int i;

  int j;

  a = new double[(n*(n+1))/2];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  *na = 0;

  for ( j = 1; j <= n; j++ )

  {

    for ( i = 1; i <= j; i++ )

    {

      a[*na] = ( double ) ( fac * i + j );

      *na = *na + 1;

    }

    diag[j-1] = *na;

  }

  return a;

}

double *r8ss_mxv ( int n, int na, int diag[], double a[], double x[] )

{

  double *b;

  int diagold;

  int i;

  int ilo;

  int j;

  int k;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

  }

  diagold = 0;

  k = 0;

  for ( j = 1; j <= n; j++ )

  {

    ilo = j + 1 + diagold - diag[j-1];

    for ( i = ilo; i < j; i++ )

    {

      b[i-1] = b[i-1] + a[k] * x[j-1];

      b[j-1] = b[j-1] + a[k] * x[i-1];

      k = k + 1;

    }

    b[j-1] = b[j-1] + a[k] * x[j-1];

    k = k + 1;

    diagold = diag[j-1];

  }

  return b;

}

void r8ss_print ( int n, int na, int diag[], double a[], string title )

{

  r8ss_print_some ( n, na, diag, a, 1, 1, n, n, title );

  return;

}

void r8ss_print_some ( int n, int na, int diag[], double a[], int ilo, int jlo, 

  int ihi, int jhi, string title )

{

# define INCX 5

  double aij;

  int i;

  int i2hi;

  int i2lo;

  int ij;

  int ijm1;

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

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, n );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        aij = 0.0;

        if ( j < i )

        {

          if ( i == 1 )

          {

            ijm1 = 0;

          }

          else

          {

            ijm1 = diag[i-2];

          }

          ij = diag[i-1];

          if ( ijm1 < ij+j-i )

          {

            aij = a[ij+j-i-1];

          }

        }

        else if ( j == i )

        {

          ij = diag[j-1];

          aij = a[ij-1];

        }

        else if ( i < j )

        {

          if ( j == 1 )

          {

            ijm1 = 0;

          }

          else

          {

            ijm1 = diag[j-2];

          }

          ij = diag[j-1];

          if ( ijm1 < ij+i-j )

          {

            aij = a[ij+i-j-1];

          }

        }

        cout << setw(12) << aij << "  ";

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

void r8ss_random ( int n, int *na, int diag[], double a[], int *seed )

{

  int diagold;

  int i;

  int ilo;

  int j;

  int k;

  diag[0] = 1;

  *na = 1;

  for ( i = 1; i < n; i++ )

  {

    k = i4_uniform ( 1, i, seed );

    diag[i] = diag[i-1] + k;

    *na = *na + k;

  }

  diagold = 0;

  k = 0;

  for ( j = 0; j < n; j++ )

  {

    ilo = j + diagold + 1 - diag[j];

    for ( i = ilo; i <= j; i++ )

    {

      a[k] = r8_uniform_01 ( seed );

      k = k + 1;

    }

    diagold = diag[j];

  }

  return;

}

double *r8ss_to_r8ge ( int n, int na, int diag[], double a[] )

{

  double *b;

  int diagold;

  int i;

  int ilo;

  int j;

  int k;

  b = new double[n*n];

  diagold = 0;

  k = 0;

  for ( j = 0; j < n; j++ )

  {

    ilo = j + diagold + 1 - diag[j];

    for ( i = 0; i < ilo; i++ )

    {

      b[i+j*n] = 0.0;

      b[j+i*n] = 0.0;

    }

    for ( i = ilo; i < j; i++ )

    {

      b[i+j*n] = a[k];

      b[j+i*n] = a[k];

      k = k + 1;

    }

    b[j+j*n] = a[k];

    k = k + 1;

    diagold = diag[j];

  }

  return b;

}

double *r8ss_zero ( int n, int na, int diag[] )

{

  double *a;

  int diagold;

  int i;

  int ihi;

  int ilo;

  int j;

  int k;

  a = new double[na];

  diagold = 0;

  k = 0;

  for ( j = 0; j < n; j++ )

  {

    ilo = j + diagold + 1 - diag[j];

    ihi = j;

    for ( i = ilo; i <= ihi; i++ )

    {

      a[k] = 0.0;

      k = k + 1;

    }

    diagold = diag[j];

  }

  return a;

}

double *r8sto_indicator ( int n )

{

  double *a;

  int fac;

  int i;

  int j;

  int k;

  a = new double[n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  i = 1;

  k = 0;

  for ( j = 1; j <= n; j++ )

  {

    a[k] = ( double ) ( fac * i + j );

    k = k + 1;

  }

  

  return a;

}

double *r8sto_inverse ( int n, double a[] )

{

  double *a2;

  double *b;

  int i;

  int j;

  double t;

  double *v;

  double vn;

  a2 = new double[n-1];

  b = new double[n*n];

  for ( i = 0; i < n-1; i++ )

  {

    a2[i] = a[i+1] / a[0];

  }

  v = r8sto_yw_sl ( n-1, a2 );

  t = 0.0;

  for ( i = 0; i < n-1; i++ )

  {

    t = t + a2[i] * v[i];

  }

  vn = 1.0 / ( 1.0 + t );

  for ( i = 0; i < (n-1)/2; i++ )

  {

    j = n - 2 - i;

    t    = v[i];

    v[i] = v[j];

    v[j] = t;

  }

  for ( i = 0; i < n-1; i++ )

  {

    v[i] = vn * v[i];

  }

  b[0+0*n] = vn;

  for ( j = 1; j < n; j++ )

  {

  b[0+j*n] = v[n-j-1];

  }

  for ( j = 0; j < n-1; j++ )

  {

    b[n-1+j*n] = v[j];

  }

  b[n-1+(n-1)*n] = vn;

  for ( i = 1; i < n-1; i++ )

  {

    b[i+0*n]     = v[n-1-i];

    b[i+(n-1)*n] = v[i];

  }

  for ( i = 2; i <= 1+(n-1)/2; i++ )

  {

    for ( j = i; j <= n - i + 1; j++ )

    {

      t = b[i-2+(j-2)*n] + ( v[n-j] * v[n-i] - v[i-2] * v[j-2] ) / vn;

      b[i-1+(j-1)*n] = t;

      b[j-1+(i-1)*n] = t;

      b[n-i+(n-j)*n] = t;

      b[n-j+(n-i)*n] = t;

    }

  }

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      b[i+j*n] = b[i+j*n] / a[0];

    }

  }

  delete [] a2;

  delete [] v;

  return b;

}

double *r8sto_mxv ( int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

    for ( j = 0; j <= i-1; j++ )

    {

      b[i] = b[i] + a[i-j] * x[j];

    }

    for ( j = i; j < n; j++ )

    {

      b[i] = b[i] + a[j-i] * x[j];

    }

  }

  return b;

}

void r8sto_print ( int n, double a[], string title )

{

  r8sto_print_some ( n, a, 1, 1, n, n, title );

  return;

}

void r8sto_print_some ( int n, double a[], int ilo, int jlo, int ihi, 

  int jhi, string title )

{

# define INCX 5

  double aij;

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

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, n );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( i <= j )

        {

          aij = a[j-i];

        }

        else

        {

          aij = a[i-j];

        }

        cout << setw(12) << aij << "  ";

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8sto_random ( int n, int *seed )

{

  return ( r8vec_random ( n, 0.0, 1.0, seed ) );

}

double *r8sto_sl ( int n, double a[], double b[] )

{

  double beta;

  int i;

  int k;

  double *x;

  double *y;

  x = new double[n];

  y = new double[n];

  k = 0;

  beta = 1.0;

  x[k] = b[k] / beta;

  if ( k < n-1 )

  {

    y[k] = -a[k+1] / beta;

  }

  for ( k = 1; k <= n-1; k++ )

  {

    beta = ( 1.0 - y[k-1] * y[k-1] ) * beta;

    x[k] = b[k];

    for ( i = 1; i <= k; i++ )

    {

      x[k] = x[k] - a[i] * x[k-i];

    }

    x[k] = x[k] / beta;

    for ( i = 1; i <= k; i++ )

    {

      x[i-1] = x[i-1] + x[k] * y[k-i]; 

    }

    if ( k < n - 1 )

    {

      y[k] = -a[k+1];

      for ( i = 1; i <= k; i++ )

      {

        y[k] = y[k] - a[i] * y[k-i];

      }

      y[k] = y[k] / beta;

      for ( i = 1; i <= k; i++ )

      {

        y[i-1] = y[i-1] + y[k] * y[k-i];

      }

    }

  }

  delete [] y;

  return x;

}

double *r8sto_to_r8ge ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < i; j++ )

    {

      b[i+j*n] = a[i-j];

    }

    for ( j = i; j < n; j++ )

    {

      b[i+j*n] = a[j-i];

    }

  }

  return b;

}

double *r8sto_yw_sl ( int n, double b[] )

{

  double alpha;

  double beta;

  int i;

  int j;

  double *x;

  double *x2;

  x = new double[n];

  x2 = new double[n];

  x[0] = -b[0];

  beta = 1.0;

  alpha = -b[0];

  for ( i = 1; i <= n-1; i++ )

  {

    beta = ( 1.0 - alpha * alpha ) * beta;

    alpha = b[i];

    for ( j = 1; j <= i; j++ )

    {

      alpha = alpha + b[i-j] * x[j-1];

    }

    alpha = -alpha / beta;

    for ( j = 1; j <= i; j++ )

    {

      x2[j-1] = x[j-1];

    }

    for ( j = 1; j <= i; j++ )

    {

      x[j-1] = x[j-1] + alpha * x2[i-j];

    }

    x[i] = alpha;

  }

  delete [] x2;

  return x;

}

double *r8sto_zero ( int n )

{

  double *a;

  int i;

  a = new double[n];

  for ( i = 0; i < n; i++ )

  {

    a[i] = 0.0;

  }

  return a;

}

double *r8to_indicator ( int n )

{

  double *a;

  int fac;

  int i;

  int j;

  int k;

  a = new double[2*n-1];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  i = 1;

  k = 0;

  for ( j = 1; j <= n; j++ )

  {

    a[k] = ( double ) ( fac * i + j );

    k = k + 1;

  }

  j = 1;

  for ( i = 2; i <= n; i++ )

  {

    a[k] = ( double ) ( fac * i + j );

    k = k + 1;

  }

  

  return a;

}

double *r8to_mxv ( int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

    for ( j = 0; j < i; j++ )

    {

      b[i] = b[i] + a[n+i-j-1] * x[j];

    }

    for ( j = i; j < n; j++ )

    {

      b[i] = b[i] + a[j-i] * x[j];

    }

  }

  return b;

}

void r8to_print ( int n, double a[], string title )

{

  r8to_print_some ( n, a, 1, 1, n, n, title );

  return;

}

void r8to_print_some ( int n, double a[], int ilo, int jlo, int ihi, 

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

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, n );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( i <= j ) 

        {

          cout << setw(12) << a[j-i] << "  ";

        }

        else

        {

          cout << setw(12) << a[n+i-j-1] << "  ";

        }

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8to_random ( int n, int *seed )

{

  double *a;

  int i;

  a = new double[2*n-1];

  for ( i = 0; i < 2*n-1; i++ )

  {

    a[i] = r8_uniform_01 ( seed );

  }

  return a;

}

double *r8to_sl ( int n, double a[], double b[], int job )

{

  double *c1;

  double *c2;

  int i;

  int nsub;

  double r1;

  double r2;

  double r3;

  double r5;

  double r6;

  double *x;

  if ( n < 1 )

  {

    return NULL;

  }

  x = new double[n];

  r1 = a[0];

  x[0] = b[0] / r1;

  if ( n == 1 )

  {

    return x;

  }

  c1 = new double[n-1];

  c2 = new double[n-1];

  for ( nsub = 2; nsub <= n; nsub++ )

  {

    if ( job == 0 )

    {

      r5 = a[n+nsub-2];

      r6 = a[nsub-1];

    }

    else

    {

      r5 = a[nsub-1];

      r6 = a[n+nsub-2];

    }

    if ( 2 < nsub )

    {

      c1[nsub-2] = r2;

      for ( i = 1; i <= nsub-2; i++ )

      {

        if ( job == 0 )

        {

          r5 = r5 + a[n+i-1] * c1[nsub-i-1];

          r6 = r6 + a[i] * c2[i-1];

        }

        else

        {

          r5 = r5 + a[i] * c1[nsub-i-1];

          r6 = r6 + a[n+i-1] * c2[i-1];

        }

      }

    }

    r2 = - r5 / r1;

    r3 = - r6 / r1;

    r1 = r1 + r5 * r3;

    if ( 2 < nsub )

    {

      r6 = c2[0];

      c2[nsub-2] = 0.0;

      for ( i = 2; i <= nsub-1; i++ )

      {

        r5 = c2[i-1];

        c2[i-1] = c1[i-1] * r3 + r6;

        c1[i-1] = c1[i-1] + r6 * r2;

        r6 = r5;

      }

    }

    c2[0] = r3;

    if ( job == 0 )

    {

      r5 = 0.0;

      for ( i = nsub-1; 1 <= i; i-- )

      {

        r5 = r5 + a[n+nsub-i-1] * x[i-1];

      }

    }

    else

    {

      r5 = 0.0;

      for ( i = nsub-1; 1 <= i; i-- )

      {

        r5 = r5 + a[nsub-i] * x[i-1];

      }

    }

    r6 = ( b[nsub-1] - r5 ) / r1;

    for ( i = 0; i < nsub-1; i++ )

    {

      x[i] = x[i] + c2[i] * r6;

    }

    x[nsub-1] = r6;

  }

  delete [] c1;

  delete [] c2;

  return x;

}

double *r8to_to_r8ge ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[n*n];

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < i; j++ )

    {

      b[i+j*n] = a[n+i-j-1];

    }

    for ( j = i; j < n; j++ )

    {

      b[i+j*n] = a[j-i];

    }

  }

  return b;

}

double *r8to_vxm ( int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = 0.0;

    for ( j = 0; j <= i; j++ )

    {

      b[i] = b[i] + a[i-j] * x[j];

    }

    for ( j = i+1; j < n; j++ )

    {

      b[i] = b[i] + a[n+j-i-1] * x[j];

    }

  }

  return b;

}

double *r8to_zero ( int n )

{

  double *a;

  int i;

  a = new double[2*n-1];

  for ( i = 0; i < 2*n-1; i++ )

  {

    a[i] = 0.0;

  }

  return a;

}

double r8ut_det ( int n, double a[] )

{

  double det;

  int i;

  det = 1.0;

  for ( i = 0; i < n; i++ )

  {

    det = det * a[i+i*n];

  }

  return det;

}

double *r8ut_indicator ( int m, int n )

{

  double *a;

  int fac;

  int i;

  int j;

  a = new double[m*n];

  fac = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( i = 1; i <= m; i++ )

  {

    for ( j = 1; j <= i4_min ( i-1, n ); j++ )

    {

      a[i-1+(j-1)*m] = 0.0;

    }

    for ( j = i; j <= n; j++ )

    {

      a[i-1+(j-1)*m] = ( double ) ( fac * i + j );

    }

  }

  return a;

}

double *r8ut_inverse ( int n, double a[] )

{

  double *b;

  int i;

  int j;

  int k;

  for ( i = 0; i < n; i++ )

  {

    if ( a[i+i*n] == 0.0 )

    {

      cerr << "\n";

      cerr << "R8UT_INVERSE - Fatal error!\n";

      cerr << "  Zero diagonal element.\n";

      exit ( 1 );

    }

  }

  b = new double[n*n];

  for ( j = n-1; 0 <= j; j-- )

  {

    for ( i = n-1; 0 <= i; i-- )

    {

      if ( j < i )

      {

        b[i+j*n] = 0.0;

      }

      else if ( i == j )

      {

        b[i+j*n] = 1.0 / a[i+j*n];

      }

      else if ( i < j )

      {

        b[i+j*n] = 0.0;

        for ( k = i+1; k <= j; k++ )

        {

          b[i+j*n] = b[i+j*n] - a[i+k*n] * b[k+j*n];

        }

        b[i+j*n] = b[i+j*n] / a[i+i*n];

      }

    }

  }

  return b;

}

double *r8ut_mxm ( int n, double a[], double b[] )

{

  double *c;

  int i;

  int j;

  int k;

  c = new double[n*n];

  for ( i = 0; i < n; i++ )

  {

    for ( j = i; j < n; j++ )

    {

      c[i+j*n] = 0.0;

      for ( k = i; k <= j; k++ )

      {

        c[i+j*n] = c[i+j*n] + a[i+k*n] * b[k+j*n];

      }

    }

  }

  return c;

}

double *r8ut_mxv ( int m, int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[m];

  for ( i = 0; i < m; i++ )

  {

    b[i] = 0.0;

    for ( j = i; j < n; j++ )

    {

      b[i] = b[i] + a[i+j*m] * x[j];

    }

  }

  return b;

}

void r8ut_print ( int m, int n, double a[], string title )

{

  r8ut_print_some ( m, n, a, 1, 1, m, n, title );

  return;

}

void r8ut_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi, 

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

  if ( ilo < jlo )

  {

    return;

  }

  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )

  {

    j2hi = j2lo + INCX - 1;

    j2hi = i4_min ( j2hi, n );

    j2hi = i4_min ( j2hi, jhi );

    cout << "\n";

    cout << "  Col: ";

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2lo = i4_max ( i2lo, j2lo );

    i2hi = i4_min ( ihi, m );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(4) << i << "  ";

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( j < i )

        {

          cout << "              ";

        }

        else

        {

          cout << setw(12) << a[i-1+(j-1)*m] << "  ";

        }

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8ut_random ( int m, int n, int *seed )

{

  double *a;

  int i;

  int j;

  a = new double[m*n];

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < i4_min ( i, n ); j++ )

    {

      a[i+j*m] = 0.0;

    }

    for ( j = i; j < n; j++ )

    {

      a[i+j*m] = r8_uniform_01 ( seed );

    }

  }

  return a;

}

double *r8ut_sl ( int n, double a[], double b[], int job )

{

  int i;

  int j;

  double *x;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  if ( job == 0 )

  {

    for ( j = n-1; 0 <= j; j-- )

    {

      x[j] = x[j] / a[j+j*n];

      for ( i = 0; i < j; i++ )

      {

        x[i] = x[i] - a[i+j*n] * x[j];

      }

    }

  }

  else

  {

    for ( j = 0; j < n; j++ )

    {

      x[j] = x[j] / a[j+j*n];

      for ( i = j+1; i < n; i++ )

      {

        x[i] = x[i] - a[j+i*n] * x[j];

      }

    }

  }

  return x;

}

double *r8ut_vxm ( int m, int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[n];

  for ( j = 0; j < n; j++ )

  {

    b[j] = 0.0;

    for ( i = 0; i <= j && i < m; i++ )

    {

      b[j] = b[j] + x[i] * a[i+j*m];

    }

  }

  return b;

}

double *r8ut_zero ( int m, int n )

{

  double *a;

  int i;

  int j;

  a = new double[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      a[i+j*m] = 0.0;

    }

  }

  return a;

}

double r8vec_dot_product ( int n, double x[], double y[] )

{

  double dot;

  int i;

  dot = 0.0;

  for ( i = 0; i < n; i++ ) 

  {

    dot = dot + x[i] * y[i];

  }

  return dot;

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

void r8vec_print ( int n, double a[], string title )

{

  int i;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  for ( i = 0; i < n; i++ ) 

  {

    cout << setw(6)  << i + 1 << "  " 

         << setw(14) << a[i]  << "\n";

  }

  return;

}

void r8vec_print_some ( int n, double a[], int i_lo, int i_hi, string title )

{

  int i;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  for ( i = i4_max ( 1, i_lo ); i <= i4_min ( n, i_hi ); i++ )

  {

    cout << "  " << setw(8)  << i

         << ": " << setw(14) << a[i-1]  << "\n";

  }

  return;

}

double *r8vec_random ( int n, double alo, double ahi, int *seed )

{

  double *a;

  int i;

  a = new double[n];

  for ( i = 0; i < n; i++ )

  {

    a[i] = r8_uniform ( alo, ahi, seed );

  }

  return a;

}

double *r8vec_read ( string input_file, int n )

{

  ifstream input;

  int k;

  double *r;

  input.open ( input_file.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R8VEC_READ - Fatal error!\n";

    cerr << "  Could not open the input file: \"" << input_file << "\"\n";

    exit ( 1 );

  }

  r = new double[n];

  for ( k = 0; k < n; k++ )

  {

    input >> r[k];

  }

  input.close ( );

  return r;

}

int r8vec_read_size ( string input_file )

{

  ifstream input;

  char line[100];

  int n;

  n = 0;

  input.open ( input_file.c_str ( ) );

  if ( !input )

  {

    cerr << "\n";

    cerr << "R8VEC_READ_SIZE - Fatal error!\n";

    cerr << "  Could not open the input file: \"" << input_file << "\"\n";

    exit ( 1 );

  }

  for ( ; ; )

  {

    input.getline ( line, sizeof ( line ) );

    if ( input.eof ( ) )

    {

      break;

    }

    n = n + 1;

  }

  input.close ( );

  return n;

}

double *r8vec_to_r8cb ( int m, int n, int ml, int mu, double *x )

{

  double *a;

  int i;

  int j;

  a = new double[(ml+mu+1)*n];

  for ( j = 1; j <= n; j++ )

  {

    for ( i = 1; i <= ml + mu + 1; i++ )

    {

      if ( 1 <= i + j - mu - 1 & i + j - mu - 1 <= m )

      {

        a[i-1+(j-1)*(ml+mu+1)] = x[i-1+(j-1)*(ml+mu+1)];

      }

      else

      {

        a[i-1+(j-1)*(ml+mu+1)] = 0.0;

      }

    }

  }

  return a;

}

double *r8vec_to_r8gb ( int m, int n, int ml, int mu, double *x )

{

  double *a;

  int i;

  int j;

  a = new double[(2*ml+mu+1)*n];

  for ( j = 1; j <= n; j++ )

  {

    for ( i = 1; i <= 2 * ml + mu + 1; i++ )

    {

      if ( 1 <= i + j - ml - mu - 1 & i + j - ml - mu - 1 <= m )

      {

        a[i-1+(j-1)*(2*ml+mu+1)] = x[i-1+(j-1)*(2*ml+mu+1)];

      }

      else

      {

        a[i-1+(j-1)*(2*ml+mu+1)] = 0.0;

      }

    }

  }

  return a;

}

double *r8vec_to_r8ge ( int m, int n, double *x )

{

  double *a;

  int i;

  int j;

  int k;

  a = new double[m*n];

  k = 0;

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      a[i+j*m] = x[k];

      k = k + 1;

    }

  }

  return a;

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

void r8vec2_print_some ( int n, double x1[], double x2[], int max_print, 

  string title )

{

  int i;

  if ( max_print <= 0 )

  {

    return;

  }

  if ( n <= 0 )

  {

    return;

  }

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  if ( n <= max_print )

  {

    for ( i = 0; i < n; i++ )

    {

      cout << setw(6)  << i + 1 << "  "

           << setw(14) << x1[i] << "  "

           << setw(14) << x2[i] << "\n";

    }

  }

  else if ( 3 <= max_print )

  {

    for ( i = 0; i < max_print-2; i++ )

    {

      cout << setw(6)  << i + 1 << "  "

           << setw(14) << x1[i] << "  "

           << setw(14) << x2[i] << "\n";

    }

    cout << "......  ..............  ..............\n";

    i = n - 1;

    cout << setw(6)  << i + 1 << "  "

         << setw(14) << x1[i] << "  "

         << setw(14) << x2[i] << "\n";

  }

  else

  {

    for ( i = 0; i < max_print - 1; i++ )

    {

      cout << setw(6)  << i + 1 << "  "

           << setw(14) << x1[i] << "  "

           << setw(14) << x2[i] << "\n";

    }

    i = max_print - 1;

    cout << setw(6)  << i + 1 << "  "

         << setw(14) << x1[i] << "  "

         << setw(14) << x2[i] << "...more entries...\n";

  }

  return;

}

double r8vm_det ( int n, double a[] )

{

  double det;

  int i;

  int j;

  det = 1.0;

  for ( j = 0; j < n; j++ )

  {

    for ( i = j+1; i < n; i++ )

    {

      det = det * ( a[i] - a[j] );

    }

  }

  return det;

}

double *r8vm_mxv ( int m, int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[m];

  for ( i = 0; i < m; i++ )

  {

    b[i] = 0.0;

    for ( j = 0; j < n; j++ )

    {

      if ( i == 0 )

      {

        b[i] = b[i] + x[j];

      }

      else

      {

        b[i] = b[i] + pow ( a[j], i ) * x[j];

      }

    }

  }

  return b;

}

void r8vm_print ( int m, int n, double a[], string title )

{

  r8vm_print_some ( m, n, a, 1, 1, m, n, title );

  return;

}

void r8vm_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi, 

  int jhi, string title )

{

# define INCX 5

  double aij;

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

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "  ---\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, m );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      for ( j = j2lo; j <= j2hi; j++ )

      {

        if ( i == 1 )

        {

          aij = 1.0;

        }

        else

        {

          aij = pow ( a[j-1], i-1 );

        }

        cout << setw(12) << aij << "  ";

      }

      cout << "\n";

    }

  }

  cout << "\n";

  return;

# undef INCX

}

double *r8vm_random ( int m, int n, int &seed )

{

  double *a;

  a = r8vec_uniform_01_new ( n, seed );

  return a;

}

void r8vm_sl ( int n, double a[], double b[], int job, double x[], int *info )

{

  int i;

  int j;

  *info = 0;

  for ( j = 0; j < n; j++ )

  {

    for ( i = j+1; i < n; i++ )

    {

      if ( a[i] == a[j] )

      {

        *info = 1;

        return;

      }

    }

  }

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  if ( job == 0 )

  {

    for ( j = 1; j <= n-1; j++ )

    {

      for ( i = n; j+1 <= i; i-- )

      {

        x[i-1] = x[i-1] - a[j-1] * x[i-2];

      }

    }

    for ( j = n-1; 1 <= j; j-- )

    {

      for ( i = j+1; i <= n; i++ )

      {

        x[i-1] = x[i-1] / ( a[i-1] - a[i-j-1] );

      }

      for ( i = j; i <= n-1; i++ )

      {

        x[i-1] = x[i-1] - x[i];

      }

    }

  }

  else

  {

    for ( j = 1; j <= n-1; j++ )

    {

      for ( i = n; j+1 <= i; i-- )

      {

        x[i-1] = ( x[i-1] - x[i-2] ) / ( a[i-1] - a[i-j-1] );

      }

    }

    for ( j = n-1; 1 <= j; j-- )

    {

      for ( i = j; i <= n-1; i++ )

      {

        x[i-1] = x[i-1] - x[i] * a[j-1];

      }

    }

  }

  return;

}

double *r8vm_sl_new ( int n, double a[], double b[], int job, int *info )

{

  int i;

  int j;

  double *x;

  *info = 0;

  for ( j = 0; j < n; j++ )

  {

    for ( i = j+1; i < n; i++ )

    {

      if ( a[i] == a[j] )

      {

        *info = 1;

        return NULL;

      }

    }

  }

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = b[i];

  }

  if ( job == 0 )

  {

    for ( j = 1; j <= n-1; j++ )

    {

      for ( i = n; j+1 <= i; i-- )

      {

        x[i-1] = x[i-1] - a[j-1] * x[i-2];

      }

    }

    for ( j = n-1; 1 <= j; j-- )

    {

      for ( i = j+1; i <= n; i++ )

      {

        x[i-1] = x[i-1] / ( a[i-1] - a[i-j-1] );

      }

      for ( i = j; i <= n-1; i++ )

      {

        x[i-1] = x[i-1] - x[i];

      }

    }

  }

  else

  {

    for ( j = 1; j <= n-1; j++ )

    {

      for ( i = n; j+1 <= i; i-- )

      {

        x[i-1] = ( x[i-1] - x[i-2] ) / ( a[i-1] - a[i-j-1] );

      }

    }

    for ( j = n-1; 1 <= j; j-- )

    {

      for ( i = j; i <= n-1; i++ )

      {

        x[i-1] = x[i-1] - x[i] * a[j-1];

      }

    }

  }

  return x;

}

double *r8vm_to_r8ge ( int m, int n, double a[] )

{

  double *b;

  int i;

  int j;

  b = new double[m*n];

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      if ( i == 0 )

      {

        b[i+j*m] = 1.0;

      }

      else

      {

        b[i+j*m] = b[i-1+j*m] * a[j];

      }

    }

  }

  return b;

}

double *r8vm_vxm ( int m, int n, double a[], double x[] )

{

  double *b;

  int i;

  int j;

  b = new double[n];

  for ( j = 0; j < n; j++ )

  {

    b[j] = 0.0;

    for ( i = 0; i < m; i++ )

    {

      if ( i == 0 )

      {

        b[j] = b[j] + x[i];

      }

      else

      {

        b[j] = b[j] + pow ( a[j], i ) * x[i];

      }

    }

  }

  return b;

}

double *r8vm_zero ( int m, int n )

{

  double *a;

  int i;

  int j;

  a = new double[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      a[i+j*m] = 0.0;

    }

  }

  return a;

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

  for ( ;; )

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