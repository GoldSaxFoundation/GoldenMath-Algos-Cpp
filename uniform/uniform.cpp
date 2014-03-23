
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <fstream>

# include <ctime>

# include <cmath>

# include <complex>

using namespace std;

# include "uniform.hpp"

complex <float> c4_uniform_01 ( int &seed )

{

  int i4_huge = 2147483647;

  int k;

  float pi = 3.1415926E+00;

  float r;

  float theta;

  complex <float> value;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "C4_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + i4_huge;

  }

  r = sqrt ( ( float ) ( seed ) * 4.656612875E-10 );

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + i4_huge;

  }

  theta = 2.0 * pi *

    ( ( float ) ( seed ) * 4.656612875E-10 );

  value = complex <float> ( r * cos ( theta ), r * sin ( theta ) );

  return value;

}

void c4mat_uniform_01 ( int m, int n, int seed, complex <float> c[] )

{

  int i;

  int i4_huge = 2147483647;

  int j;

  float r;

  int k;

  float pi = 3.1415926;

  float theta;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "C4MAT_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      r = sqrt ( ( float ) ( seed ) * 4.656612875E-10 );

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      theta = 2.0 * pi * ( ( float ) ( seed ) * 4.656612875E-10 );

      c[i+j*m] = r * complex <float> ( cos ( theta ), sin ( theta ) );

    }

  }

  return;

}

complex <float> *c4mat_uniform_01_new ( int m, int n, int &seed )

{

  complex <float> *c;

  int i;

  int i4_huge = 2147483647;

  int j;

  float r;

  int k;

  float pi = 3.1415926;

  float theta;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "C4MAT_UNIFORM_01_NEW - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  c = new complex <float>[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      r = sqrt ( ( float ) ( seed ) * 4.656612875E-10 );

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      theta = 2.0 * pi * ( ( float ) ( seed ) * 4.656612875E-10 );

      c[i+j*m] = r * complex <float> ( cos ( theta ), sin ( theta ) );

    }

  }

  return c;

}

void c4vec_uniform_01 ( int n, int &seed, complex <float> c[] )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  float pi = 3.1415926;

  float r;

  float theta;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "C4VEC_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    r = sqrt ( ( float ) ( seed ) * 4.656612875E-10 );

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    theta = 2.0 * pi * ( ( float ) ( seed ) * 4.656612875E-10 );

    c[i] = r * complex <float> ( cos ( theta ), sin ( theta ) );

  }

  return;

}

complex <float> *c4vec_uniform_01_new ( int n, int &seed )

{

  complex <float> *c;

  int i;

  int i4_huge = 2147483647;

  int k;

  float pi = 3.1415926;

  float r;

  float theta;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "C4VEC_UNIFORM_01_NEW - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  c = new complex <float> [n];

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    r = sqrt ( ( float ) ( seed ) * 4.656612875E-10 );

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    theta = 2.0 * pi * ( ( float ) ( seed ) * 4.656612875E-10 );

    c[i] = r * complex <float> ( cos ( theta ), sin ( theta ) );

  }

  return c;

}

complex <double> c8_uniform_01 ( int &seed )

{

  int i4_huge = 2147483647;

  int k;

  double pi = 3.141592653589793;

  double r;

  double theta;

  complex <double> value;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "C8_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + i4_huge;

  }

  r = sqrt ( ( ( double ) ( seed ) * 4.656612875E-10 ) );

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + i4_huge;

  }

  theta = 2.0 * pi * ( ( double ) ( seed ) * 4.656612875E-10 );

  value = complex <double> ( r * cos ( theta ), r * sin ( theta ) );

  return value;

}

void c8mat_uniform_01 ( int m, int n, int &seed, complex <double> c[] )

{

  int i;

  int i4_huge = 2147483647;

  int j;

  double r;

  int k;

  double pi = 3.141592653589793;

  double theta;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "C8MAT_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      r = sqrt ( ( double ) ( seed ) * 4.656612875E-10 );

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      theta = 2.0 * pi * ( ( double ) ( seed ) * 4.656612875E-10 );

      c[i+j*m] = r * complex <double> ( cos ( theta ), sin ( theta ) );

    }

  }

  return;

}

complex <double> *c8mat_uniform_01_new ( int m, int n, int &seed )

{

  complex <double> *c;

  int i;

  int i4_huge = 2147483647;

  int j;

  double r;

  int k;

  double pi = 3.141592653589793;

  double theta;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "C8MAT_UNIFORM_01_NEW - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  c = new complex <double>[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      r = sqrt ( ( double ) ( seed ) * 4.656612875E-10 );

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      theta = 2.0 * pi * ( ( double ) ( seed ) * 4.656612875E-10 );

      c[i+j*m] = r * complex <double> ( cos ( theta ), sin ( theta ) );

    }

  }

  return c;

}

void c8vec_uniform_01 ( int n, int &seed, complex <double> c[] )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  double pi = 3.141592653589793;

  double r;

  double theta;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "C8VEC_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    r = sqrt ( ( double ) ( seed ) * 4.656612875E-10 );

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    theta = 2.0 * pi * ( ( double ) ( seed ) * 4.656612875E-10 );

    c[i] = r * complex <double> ( cos ( theta ), sin ( theta ) );

  }

  return;

}

complex <double> *c8vec_uniform_01_new ( int n, int &seed )

{

  complex <double> *c;

  int i;

  int i4_huge = 2147483647;

  int k;

  double pi = 3.141592653589793;

  double r;

  double theta;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "C8VEC_UNIFORM_01_NEW - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  c = new complex <double> [n];

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    r = sqrt ( ( double ) ( seed ) * 4.656612875E-10 );

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    theta = 2.0 * pi * ( ( double ) ( seed ) * 4.656612875E-10 );

    c[i] = r * complex <double> ( cos ( theta ), sin ( theta ) );

  }

  return c;

}

char ch_uniform_ab ( char a, char b, int &seed )

{

  char c;

  float d;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "CH_UNIFORM_AB - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  d = r4_uniform_01 ( seed );

 

  c = a + ( char ) ( d * ( float ) ( b + 1 - a ) );

  return c;

}

int congruence ( int a, int b, int c, bool *error )

{

# define N_MAX 100

  int a_copy;

  int a_mag;

  int a_sign;

  int b_copy;

  int b_mag;

  int b_sign;

  int c_copy;

  int g;

  int k;

  int n;

  float norm_new;

  float norm_old;

  int q[N_MAX];

  bool swap;

  int temp;

  int x;

  int xnew;

  int y;

  int ynew;

  int z;

  *error = false;

  x = 0;

  y = 0;

  if ( a == 0 && b == 0 && c == 0 )

  {

    x = 0;

    return x;

  }

  else if ( a == 0 && b == 0 && c != 0 )

  {

    *error = true;

    x = 0;

    return x;

  }

  else if ( a == 0 && b != 0 && c == 0 )

  {

    x = 0;

    return x;

  }

  else if ( a == 0 && b != 0 && c != 0 )

  {

    x = 0;

    if ( ( c % b ) != 0 )

    {

      *error = true;

    }

    return x;

  }

  else if ( a != 0 && b == 0 && c == 0 )

  {

    x = 0;

    return x;

  }

  else if ( a != 0 && b == 0 && c != 0 )

  {

    x = c / a;

    if ( ( c % a ) != 0 )

    {

      *error = true;

    }

    return x;

  }

  else if ( a != 0 && b != 0 && c == 0 )

  {

    x = 0;

    return x;

  }

  g = i4_gcd ( a, b );

  if ( ( c % g ) != 0 )

  {

    *error = true;

    return x;

  }

  a_copy = a / g;

  b_copy = b / g;

  c_copy = c / g;

  a_mag = abs ( a_copy );

  a_sign = i4_sign ( a_copy );

  b_mag = abs ( b_copy );

  b_sign = i4_sign ( b_copy );

  if ( a_mag == 1 )

  {

    x = a_sign * c_copy;

    return x;

  }

  else if ( b_mag == 1 )

  {

    x = 0;

    return x;

  }

  if ( b_mag <= a_mag )

  {

    swap = false;

    q[0] = a_mag;

    q[1] = b_mag;

  }

  else

  {

    swap = true;

    q[0] = b_mag;

    q[1] = a_mag;

  }

  n = 3;

  for ( ; ; )

  {

    q[n-1] = ( q[n-3] % q[n-2] );

    if ( q[n-1] == 1 )

    {

      break;

    }

    n = n + 1;

    if ( N_MAX < n )

    {

      *error = true;

      cerr << "\n";

      cerr << "CONGRUENCE - Fatal error!\n";

      cerr << "  Exceeded number of iterations.\n";

      exit ( 1 );

    }

  }

  y = 0;

  for ( k = n; 2 <= k; k-- )

  {

    x = y;

    y = ( 1 - x * q[k-2] ) / q[k-1];

  }

  if ( swap )

  {

    z = x;

    x = y;

    y = z;

  }

  x = x * a_sign;

  x = x * c_copy;

  x = x % b;

  if ( x < 0 )

  {

    x = x + b;

  }

  return x;

# undef N_MAX

}

char digit_to_ch ( int i )

{

  char c;

  if ( 0 <= i && i <= 9 )

  {

    c = '0' + i;

  }

  else

  {

    c = '*';

  }

  return c;

}

int get_seed ( )

{

  time_t clock;

  int i;

  int i4_huge = 2147483647;

  int ihour;

  int imin;

  int isec;

  int seed;

  struct tm *lt;

  time_t tloc;

  clock = time ( &tloc );

  lt = localtime ( &clock );

  ihour = lt->tm_hour;

  if ( 12 < ihour )

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

    * ( ( double ) i4_huge ) / ( 60.0 * 60.0 * 12.0 ) );

  if ( seed == 0 )

  {

    seed = 1;

  }

  return seed;

}

int i4_gcd ( int i, int j )

{

  int ip;

  int iq;

  int ir;

  if ( i == 0 )

  {

    return i4_max ( 1, abs ( j ) );

  }

  else if ( j == 0 )

  {

    return i4_max ( 1, abs ( i ) );

  }

  ip = i4_max ( abs ( i ), abs ( j ) );

  iq = i4_min ( abs ( i ), abs ( j ) );

  for ( ; ; )

  {

    ir = ip % iq;

    if ( ir == 0 )

    {

      break;

    }

    ip = iq;

    iq = ir;

  }

  return iq;

}

int i4_huge ( )

{

  return 2147483647;

}

int i4_log_10 ( int i )

{

  int ten_pow;

  int value;

  i = abs ( i );

  ten_pow = 10;

  value = 0;

  while ( ten_pow <= i )

  {

    ten_pow = ten_pow * 10;

    value = value + 1;

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

int i4_seed_advance ( int seed )

{

  int i4_huge = 2147483647;

  int k;

  int seed_new;

  seed_new = seed;

  if ( seed_new < 0 )

  {

    seed_new = seed_new + i4_huge;

  }

  k = seed_new / 127773;

  seed_new = 16807 * ( seed_new - k * 127773 ) - k * 2836;

  if ( seed_new < 0 )

  {

    seed_new = seed_new + i4_huge;

  }

  return seed_new;

}

int i4_sign ( int i )

{

  int value;

  if ( i < 0 ) 

  {

    value = -1;

  }

  else

  {

    value = 1;

  }

  return value;

}

void i4_swap ( int *i, int *j )

{

  int k;

  k = *i;

  *i = *j;

  *j = k;

 

  return;

}

char *i4_to_s ( int i )

{

  int digit;

  int j;

  int length;

  int ten_power;

  char *s;

  length = i4_log_10 ( i );

  ten_power = ( int ) pow ( ( double ) 10, ( double ) length );

  if ( i < 0 )

  {

    length = length + 1;

  }

  length = length + 1;

  s = new char[length];

  if ( i == 0 )

  {

    s[0] = '0';

    s[1] = '\0';

    return s;

  }

  j = 0;

  if ( i < 0 )

  {

    s[j] = '-';

    j = j + 1;

    i = abs ( i );

  }

  while ( 0 < ten_power )

  {

    digit = i / ten_power;

    s[j] = digit_to_ch ( digit );

    j = j + 1;

    i = i - digit * ten_power;

    ten_power = ten_power / 10;

  }

  s[j] = '\0';

  j = j + 1;

  return s;

}

int i4_uniform_0i ( int &seed )

{

  int ia = 16807;

  int ib15 = 32768;

  int ib16 = 65536;

  int ip = 2147483647;

  int iprhi;

  int ixhi;

  int k;

  int leftlo;

  int loxa;

  int value;

  if ( seed == 0 )

  {

    seed = ip;

  }

  ixhi = seed / ib16;

  loxa = ( seed - ixhi * ib16 ) * ia;

  leftlo = loxa / ib16;

  iprhi = ixhi * ia + leftlo;

  k = iprhi / ib15;

  value = ( ( ( loxa - leftlo * ib16 ) - ip ) 

            + ( iprhi - k * ib15 ) * ib16 ) + k;

  if ( value < 0 )

  {

    value = value + ip;

  }

  seed = value;

  return value;

}

int i4_uniform_ab ( int a, int b, int &seed )

{

  int c;

  int i4_huge = 2147483647;

  int k;

  float r;

  int value;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "I4_UNIFORM_AB - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  if ( b < a )

  {

    c = a;

    a = b;

    b = c;

  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + i4_huge;

  }

  r = ( float ) ( seed ) * 4.656612875E-10;

  r = ( 1.0 - r ) * ( ( float ) a - 0.5 ) 

    +         r   * ( ( float ) b + 0.5 );

  value = round ( r );

  if ( value < a )

  {

    value = a;

  }

  if ( b < value )

  {

    value = b;

  }

  return value;

}

void i4mat_uniform_ab ( int m, int n, int a, int b, int &seed, int x[] )

{

  int c;

  int i;

  int i4_huge = 2147483647;

  int j;

  int k;

  float r;

  int value;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "I4MAT_UNIFORM_AB - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  if ( b < a )

  {

    c = a;

    a = b;

    b = c;

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      r = ( float ) ( seed ) * 4.656612875E-10;

      r = ( 1.0 - r ) * ( ( float ) a - 0.5 ) 

        +         r   * ( ( float ) b + 0.5 );

      value = round ( r );

      if ( value < a )

      {

        value = a;

      }

      if ( b < value )

      {

        value = b;

      }

      x[i+j*m] = value;

    }

  }

  return;

}

int *i4mat_uniform_ab_new ( int m, int n, int a, int b, int &seed )

{

  int c;

  int i;

  int i4_huge = 2147483647;

  int j;

  int k;

  float r;

  int value;

  int *x;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "I4MAT_UNIFORM_AB_NEW - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  if ( b < a )

  {

    c = a;

    a = b;

    b = c;

  }

  x = new int[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      r = ( float ) ( seed ) * 4.656612875E-10;

      r = ( 1.0 - r ) * ( ( float ) a - 0.5 ) 

        +         r   * ( ( float ) b + 0.5 );

      value = round ( r );

      if ( value < a )

      {

        value = a;

      }

      if ( b < value )

      {

        value = b;

      }

      x[i+j*m] = value;

    }

  }

  return x;

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

float i4vec_mean ( int n, int x[] )

{

  int i;

  float mean;

  mean = 0.0;

  for ( i = 0; i < n; i++ )

  {

    mean = mean + ( float ) x[i];

  }

  mean = mean / ( float ) n;

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

void i4vec_uniform_ab ( int n, int a, int b, int &seed, int x[] )

{

  int c;

  int i;

  int i4_huge = 2147483647;

  int k;

  float r;

  int value;

  

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "I4VEC_UNIFORM_AB - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  if ( b < a )

  {

    c = a;

    a = b;

    b = c;

  }

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    r = ( float ) ( seed ) * 4.656612875E-10;

    r = ( 1.0 - r ) * ( ( float ) a - 0.5 ) 

      +         r   * ( ( float ) b + 0.5 );

    value = round ( r );

    if ( value < a )

    {

      value = a;

    }

    if ( b < value )

    {

      value = b;

    }

    x[i] = value;

  }

  return;

}

int *i4vec_uniform_ab_new ( int n, int a, int b, int &seed )

{

  int c;

  int i;

  int i4_huge = 2147483647;

  int k;

  float r;

  int value;

  int *x;

  

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "I4VEC_UNIFORM_AB_NEW - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  if ( b < a )

  {

    c = a;

    a = b;

    b = c;

  }

  x = new int[n];

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    r = ( float ) ( seed ) * 4.656612875E-10;

    r = ( 1.0 - r ) * ( ( float ) a - 0.5 ) 

      +         r   * ( ( float ) b + 0.5 );

    value = round ( r );

    if ( value < a )

    {

      value = a;

    }

    if ( b < value )

    {

      value = b;

    }

    x[i] = value;

  }

  return x;

}

float i4vec_variance ( int n, int x[] )

{

  int i;

  float mean;

  float variance;

  mean = i4vec_mean ( n, x );

  variance = 0.0;

  for ( i = 0; i < n; i++ )

  {

    variance = variance + ( ( float ) x[i] - mean ) * ( ( float ) x[i] - mean );

  }

  if ( 1 < n )

  {

    variance = variance / ( float ) ( n - 1 );

  }

  else

  {

    variance = 0.0;

  }

  return variance;

}

long long int i8_huge ( )

{

  long long int value;

  value = 9223372036854775807LL;

  return value;

}

long long int i8_max ( long long int i1, long long int i2 )

{

  long long value;

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

long long int i8_min ( long long int i1, long long int i2 )

{

  long long int value;

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

long long int i8_uniform_ab ( long long int a, long long int b, int &seed )

{

  int i4_huge = 2147483647;

  long long int k;

  double r;

  long long int value;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "I8_UNIFORM_AB - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + i4_huge;

  }

  r = ( double ) ( seed ) * 4.656612875E-10;

  r = ( 1.0 - r ) * ( ( double ) ( i8_min ( a, b ) ) - 0.5 ) 

    +         r   * ( ( double ) ( i8_max ( a, b ) ) + 0.5 );

  value = ( long long int ) ( r );

  value = i8_max ( value, i8_min ( a, b ) );

  value = i8_min ( value, i8_max ( a, b ) );

  return value;

}

bool l_uniform ( int &seed )

{

  int i4_huge      = 2147483647;

  int i4_huge_half = 1073741823;

  int  k;

  bool value;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "L_UNIFORM - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 ) 

  {

    seed = seed + i4_huge;

  }

  value = ( i4_huge_half < seed );

  return value;

}

void lcrg_anbn ( int a, int b, int c, int n, int *an, int *bn )

{

  int am1;

  int anm1tb;

  bool ierror;

  if ( n < 0 )

  {

    cerr << "\n";

    cerr << "LCRG_ANBN - Fatal error!\n";

    cerr << "  Illegal input value of N = " << n << "\n";

    exit ( 1 );

  }

  if ( c <= 0 )

  {

    cerr << "\n";

    cerr << "LCRG_ANBN - Fatal error!\n";

    cerr << "  Illegal input value of C = " << c << "\n";

    exit ( 1 );

  }

  if ( n == 0 )

  {

    *an = 1;

    *bn = 0;

  }

  else if ( n == 1 )

  {

    *an = a;

    *bn = b;

  }

  else

  {

    *an = power_mod ( a, n, c );

    am1 = a - 1;

    anm1tb = ( *an - 1 ) * b;

    *bn = congruence ( am1, c, anm1tb, &ierror );

    if ( ierror )

    {

      cerr << "\n";

      cerr << "LCRG_ANBN - Fatal error!\n";

      cerr << "  An error occurred in the CONGRUENCE routine.\n";

      exit ( 1 );

    }

  }

  return;

}

int lcrg_evaluate ( int a, int b, int c, int x )

{

  long long int a8;

  long long int b8;

  long long int c8;

  long long int x8;

  int y;

  long long int y8;

  a8 = ( long long int ) a;

  b8 = ( long long int ) b;

  c8 = ( long long int ) c;

  x8 = ( long long int ) x;

  y8 = ( a8 * x8 + b8 ) % c8;

  y = ( int ) ( y8 );

  if ( y < 0 )

  {

    y = y + c;

  }

  return y;

}

int lcrg_seed ( int a, int b, int c, int n, int seed )

{

  int an;

  int bn;

  bool ierror;

  int value;

  long long int value2;

  if ( n < 0 )

  {

    cerr << "\n";

    cerr << "LCRG_SEED - Fatal error!\n";

    cerr << "  Illegal input value of N = " << n << "\n";

    exit ( 1 );

  }

  if ( c <= 0 )

  {

    cerr << "\n";

    cerr << "LCRG_SEED - Fatal error!\n";

    cerr << "  Illegal input value of C = " << c << "\n";

    exit ( 1 );

  }

  if ( n == 0 )

  {

    value = seed % c;

    if ( value < 0 )

    {

      value = value + c;

    }

    return value;

  }

  an = power_mod ( a, n, c );

  bn = congruence ( a-1, c, ( an - 1 ) * b, &ierror );

  if ( ierror )

  {

    cerr << "\n";

    cerr << "LCRG_SEED - Fatal error!\n";

    cerr << "  An error occurred in the CONGRUENCE routine.\n";

    exit ( 1 );

  }

  value2 = ( long long int ) ( an ) * ( long long int ) ( seed ) 

    + ( long long int ) ( bn );

  value2 = value2 % ( long long int ) ( c );

  if ( value2 < 0 )

  {

    value2 = value2 + ( long long int ) ( c );

  }

  value = ( int ) ( value2 );

  return value;

}

void lmat_uniform ( int m, int n, int &seed, bool lmat[] )

{

  int i4_huge      = 2147483647;

  int i4_huge_half = 1073741823;

  int i;

  int j;

  int k;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "LMAT_UNIFORM - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      lmat[i+j*m] = ( i4_huge_half < seed );

    }

  }

  return;

}

bool *lmat_uniform_new ( int m, int n, int &seed )

{

  int i4_huge      = 2147483647;

  int i4_huge_half = 1073741823;

  int i;

  int j;

  int k;

  bool *lmat;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "LMAT_UNIFORM_NEW - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  lmat = new bool[m*n];

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      lmat[i+j*m] = ( i4_huge_half < seed );

    }

  }

  return lmat;

}

bool *lvec_uniform_new ( int n, int &seed )

{

  int i4_huge      = 2147483647;

  int i4_huge_half = 1073741823;

  int i;

  int k;

  bool *lvec;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "LVEC_UNIFORM_NEW - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    return NULL;

  }

  lvec = new bool[n];

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    lvec[i] = ( i4_huge_half < seed );

  }

  return lvec;

}

int power_mod ( int a, int n, int m )

{

  long long int a_square2;

  int d;

  long long int m2;

  int x;

  long long int x2;

  if ( a < 0 )

  {

    return -1;

  }

  if ( m <= 0 )

  {

    return -1;

  }

  if ( n < 0 )

  {

    return -1;

  }

  a_square2 = ( long long int ) a;

  m2 = ( long long int ) m;

  x2 = ( long long int ) 1;

  while ( 0 < n )

  {

    d = n % 2;

    if ( d == 1 )

    {

      x2 = ( x2 * a_square2 ) % m2;

    }

    a_square2 = ( a_square2 * a_square2 ) % m2;

    n = ( n - d ) / 2;

  }

  while ( x2 < 0 )

  {

    x2 = x2 + m2;

  }

  x = ( int ) x2;

  return x;

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

float r4_uniform_ab ( float a, float b, int &seed )

{

  int i4_huge = 2147483647;

  int k;

  float value;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R4_UNIFORM_AB - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + i4_huge;

  }

  value = ( double ) ( seed ) * 4.656612875E-10;

  value = a + ( b - a ) * value;

  return value;

}

float r4_uniform_01 ( int &seed )

{

  int i4_huge = 2147483647;

  int k;

  float r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R4_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + i4_huge;

  }

  r = ( float ) ( seed ) * 4.656612875E-10;

  return r;

}

void r4mat_uniform_ab ( int m, int n, float b, float c, int &seed, float r[] )

{

  int i;

  int i4_huge = 2147483647;

  int j;

  int k;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R4MAT_UNIFORM_AB - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      r[i+j*m] = b + ( c - b ) * ( float ) ( seed ) * 4.656612875E-10;

    }

  }

  return;

}

float *r4mat_uniform_ab_new ( int m, int n, float b, float c, int &seed )

{

  int i;

  int i4_huge = 2147483647;

  int j;

  int k;

  float *r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R4MAT_UNIFORM_AB_NEW - Fatal error!\n";

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

        seed = seed + i4_huge;

      }

      r[i+j*m] = b + ( c - b ) * ( float ) ( seed ) * 4.656612875E-10;

    }

  }

  return r;

}

void r4mat_uniform_01 ( int m, int n, int &seed, float r[] )

{

  int i;

  int i4_huge = 2147483647;

  int j;

  int k;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R4MAT_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      r[i+j*m] = ( float ) ( seed ) * 4.656612875E-10;

    }

  }

  return;

}

float *r4mat_uniform_01_new ( int m, int n, int &seed )

{

  int i;

  int i4_huge = 2147483647;

  int j;

  int k;

  float *r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R4MAT_UNIFORM_01_NEW - Fatal error!\n";

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

        seed = seed + i4_huge;

      }

      r[i+j*m] = ( float ) ( seed ) * 4.656612875E-10;

    }

  }

  return r;

}

void r4vec_uniform_ab ( int n, float b, float c, int &seed, float r[] )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R4VEC_UNIFORM_AB - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    r[i] = b + ( c - b ) * ( float ) ( seed ) * 4.656612875E-10;

  }

  return;

}

float *r4vec_uniform_ab_new ( int n, float b, float c, int &seed )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  float *r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R4VEC_UNIFORM_AB_NEW - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  r = new float[n];

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    r[i] = b + ( c - b ) * ( float ) ( seed ) * 4.656612875E-10;

  }

  return r;

}

void r4vec_uniform_01 ( int n, int &seed, float r[] )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R4VEC_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    r[i] = ( float ) ( seed ) * 4.656612875E-10;

  }

  return;

}

float *r4vec_uniform_01_new ( int n, int &seed )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  float *r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R4VEC_UNIFORM_01_NEW - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  r = new float[n];

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    r[i] = ( float ) ( seed ) * 4.656612875E-10;

  }

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

    value = -x;

  }

  return value;

}

int r8_nint ( double x )

{

  int value;

  if ( x < 0.0 )

  {

    value = - ( int ) ( r8_abs ( x ) + 0.5 );

  }

  else

  {

    value =   ( int ) ( r8_abs ( x ) + 0.5 );

  }

  return value;

}

double r8_uniform_ab ( double a, double b, int &seed )

{

  int i4_huge = 2147483647;

  int k;

  double value;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8_UNIFORM_AB - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + i4_huge;

  }

  value = ( double ) ( seed ) * 4.656612875E-10;

  value = a + ( b - a ) * value;

  return value;

}

double r8_uniform_01 ( int &seed )

{

  int i4_huge = 2147483647;

  int k;

  double r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + i4_huge;

  }

  r = ( double ) ( seed ) * 4.656612875E-10;

  return r;

}

double *r8col_uniform_ab_new ( int m, int n, double a[], double b[], int &seed )

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

      r[i+j*m] = a[i] 

        + ( b[i] - a[i] ) * ( double ) ( seed ) * 4.656612875E-10;

    }

  }

  return r;

}

double r8i8_uniform_ab ( double a, double b, long long int &seed )

{

  long long int k;

  double value;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8I8_UNIFORM_AB - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = seed / 127773LL;

  seed = 16807LL * ( seed - k * 127773LL ) - k * 2836LL;

  if ( seed < 0 )

  {

    seed = seed + i8_huge ( );

  }

  value = a + ( b - a ) * ( double ) ( seed ) * 4.656612875E-10;

  return value;

}

double r8i8_uniform_01 ( long long int &seed )

{

  long long int k;

  double value;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8I8_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = seed / 127773LL;

  seed = 16807LL * ( seed - k * 127773LL ) - k * 2836LL;

  if ( seed < 0 )

  {

    seed = seed + i8_huge ( );

  }

  value = ( double ) ( seed ) * 4.656612875E-10;

  return value;

}

void r8mat_uniform_01 ( int m, int n, int &seed, double r[] )

{

  int i;

  int i4_huge = 2147483647;

  int j;

  int k;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8MAT_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      r[i+j*m] = ( double ) ( seed ) * 4.656612875E-10;

    }

  }

  return;

}

double *r8mat_uniform_01_new ( int m, int n, int &seed )

{

  int i;

  int i4_huge = 2147483647;

  int j;

  int k;

  double *r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8MAT_UNIFORM_01_NEW - Fatal error!\n";

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

        seed = seed + i4_huge;

      }

      r[i+j*m] = ( double ) ( seed ) * 4.656612875E-10;

    }

  }

  return r;

}

void r8mat_uniform_ab ( int m, int n, double a, double b, int &seed, double r[] )

{

  int i;

  int i4_huge = 2147483647;

  int j;

  int k;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8MAT_UNIFORM_AB - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      r[i+j*m] = a + ( b - a ) * ( double ) ( seed ) * 4.656612875E-10;

    }

  }

  return;

}

double *r8mat_uniform_ab_new ( int m, int n, double a, double b, int &seed )

{

  int i;

  int i4_huge = 2147483647;

  int j;

  int k;

  double *r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8MAT_UNIFORM_AB_NEW - Fatal error!\n";

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

        seed = seed + i4_huge;

      }

      r[i+j*m] = a + ( b - a ) * ( double ) ( seed ) * 4.656612875E-10;

    }

  }

  return r;

}

void r8mat_uniform_abvec ( int m, int n, double a[], double b[], int &seed, 

  double r[] )

{

  int i;

  int i4_huge = 2147483647;

  int j;

  int k;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8MAT_UNIFORM_ABVEC - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + i4_huge;

      }

      r[i+j*m] = a[i] + ( b[i] - a[i] ) * ( double ) ( seed ) * 4.656612875E-10;

    }

  }

  return;

}

double *r8mat_uniform_abvec_new ( int m, int n, double a[], double b[], 

  int &seed )

{

  int i;

  int i4_huge = 2147483647;

  int j;

  int k;

  double *r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8MAT_UNIFORM_ABVEC_NEW - Fatal error!\n";

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

        seed = seed + i4_huge;

      }

      r[i+j*m] = a[i] + ( b[i] - a[i] ) * ( double ) ( seed ) * 4.656612875E-10;

    }

  }

  return r;

}

double *r8row_uniform_ab_new ( int m, int n, double a[], double b[], int &seed )

{

  int i;

  int j;

  int k;

  double *r;

  r = new double[m*n];

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )

      {

        seed = seed + 2147483647;

      }

      r[i+j*m] = a[j] 

        + ( b[j] - a[j] ) * ( double ) ( seed ) * 4.656612875E-10;

    }

  }

  return r;

}

void r8vec_copy ( int n, double a1[], double a2[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    a2[i] = a1[i];

  }

  return;

}

double *r8vec_normal_01_new ( int n, int &seed )

{

# define R8_PI 3.141592653589793

  int i;

  int m;

  static int made = 0;

  double *r;

  static int saved = 0;

  double *x;

  int x_hi;

  int x_lo;

  static double y = 0.0;

  x = new double[n];

  if ( n < 0 )

  {

    made = 0;

    saved = 0;

    y = 0.0;

    return NULL;

  }

  else if ( n == 0 )

  {

    return NULL;

  }

  x_lo = 1;

  x_hi = n;

  if ( saved == 1 )

  {

    x[0] = y;

    saved = 0;

    x_lo = 2;

  }

  if ( x_hi - x_lo + 1 == 0 )

  {

  }

  else if ( x_hi - x_lo + 1 == 1 )

  {

    r = r8vec_uniform_01_new ( 2, seed );

    x[x_hi-1] = sqrt ( - 2.0 * log ( r[0] ) ) * cos ( 2.0 * R8_PI * r[1] );

    y =         sqrt ( - 2.0 * log ( r[0] ) ) * sin ( 2.0 * R8_PI * r[1] );

    saved = 1;

    made = made + 2;

    delete [] r;

  }

  else if ( ( x_hi - x_lo + 1 ) % 2 == 0 )

  {

    m = ( x_hi - x_lo + 1 ) / 2;

    r = r8vec_uniform_01_new ( 2*m, seed );

    for ( i = 0; i <= 2 * m - 2; i = i + 2 )

    {

      x[x_lo+i-1] = sqrt ( - 2.0 * log ( r[i] ) ) * cos ( 2.0 * R8_PI * r[i+1] );

      x[x_lo+i  ] = sqrt ( - 2.0 * log ( r[i] ) ) * sin ( 2.0 * R8_PI * r[i+1] );

    }

    made = made + x_hi - x_lo + 1;

    delete [] r;

  }

  else

  {

    x_hi = x_hi - 1;

    m = ( x_hi - x_lo + 1 ) / 2 + 1;

    r = r8vec_uniform_01_new ( 2*m, seed );

    for ( i = 0; i <= 2 * m - 4; i = i + 2 )

    {

      x[x_lo+i-1] = sqrt ( - 2.0 * log ( r[i] ) ) * cos ( 2.0 * R8_PI * r[i+1] );

      x[x_lo+i  ] = sqrt ( - 2.0 * log ( r[i] ) ) * sin ( 2.0 * R8_PI * r[i+1] );

    }

    i = 2*m - 2;

    x[x_lo+i-1] = sqrt ( - 2.0 * log ( r[i] ) ) * cos ( 2.0 * R8_PI * r[i+1] );

    y           = sqrt ( - 2.0 * log ( r[i] ) ) * sin ( 2.0 * R8_PI * r[i+1] );

    saved = 1;

    made = made + x_hi - x_lo + 2;

    delete [] r;

  }

  return x;

# undef R8_PI

}

void r8vec_uniform_01 ( int n, int &seed, double r[] )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8VEC_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

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

void r8vec_uniform_ab ( int n, double a, double b, int &seed, double x[] )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8VEC_UNIFORM_AB - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    x[i] = a + ( b - a ) * ( double ) ( seed ) * 4.656612875E-10;

  }

  return;

}

double *r8vec_uniform_ab_new ( int n, double a, double b, int &seed )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  double *r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8VEC_UNIFORM_AB_NEW - Fatal error!\n";

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

    r[i] = a + ( b - a ) * ( double ) ( seed ) * 4.656612875E-10;

  }

  return r;

}

void r8vec_uniform_abvec ( int n, double a[], double b[], int &seed, double x[] )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8VEC_UNIFORM_ABVEC - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + i4_huge;

    }

    x[i] = a[i] + ( b[i] - a[i] ) * ( double ) ( seed ) * 4.656612875E-10;

  }

  return;

}

double *r8vec_uniform_abvec_new ( int n, double a[], double b[], int &seed )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  double *r;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8VEC_UNIFORM_ABVEC_NEW - Fatal error!\n";

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

    r[i] = a[i] + ( b[i] - a[i] ) * ( double ) ( seed ) * 4.656612875E-10;

  }

  return r;

}

double *r8vec_uniform_unit_new ( int m, int &seed )

{

  double *a;

  int i;

  double norm;

  a = r8vec_normal_01_new ( m, seed );

  norm = 0.0;

  for ( i = 0; i < m; i++ )

  {

    norm = norm + a[i] * a[i];

  }

  norm = sqrt ( norm );

  for ( i = 0; i < m; i++ )

  {

    a[i] = a[i] / norm;

  }

  return a;

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