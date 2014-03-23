
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <fstream>

# include <iomanip>

# include <cmath>

# include <ctime>

# include <cstring>

using namespace std;

# include "sphere_grid.hpp"

double arc_cosine ( double c )

{

  double angle;

  double pi = 3.141592653589793;

  if ( c <= -1.0 )

  {

    angle = pi;

  } 

  else if ( 1.0 <= c )

  {

    angle = 0.0;

  }

  else

  {

    angle = acos ( c );

  }

  return angle;

}

double arc_sine ( double s )

{

  double angle;

  double pi = 3.141592653589793;

  if ( s <= -1.0 )

  {

    angle = - pi / 2.0;

  } 

  else if ( 1.0 <= s )

  {

    angle = pi / 2.0;

  }

  else

  {

    angle = asin ( s );

  }

  return angle;

}

double atan4 ( double y, double x )

{

  double pi = 3.141592653589793;

  if ( x == 0.0 )

  {

    if ( 0.0 < y )

    {

      return ( pi / 2.0 );

    } 

    else if ( y < 0.0 )

    {

      return ( 3.0 * pi / 2.0 );

    } 

    else if ( y == 0.0 )

    {

      return ( 0.0 );

    }

  } 

  else if ( y == 0.0 )

  {

    if ( 0.0 < x )

    {

      return 0.0;

    } 

    else if ( x < 0.0 )

    {

      return pi;

    }

  }

  if        ( 0.0 < x && 0.0 < y )

  {

    return                  atan2 (  y,  x );

  }

  else if ( x < 0.0 && 0.0 < y )

  {

    return (           pi - atan2 (  y, -x ) );

  }

  else if ( x < 0.0 && y < 0.0 )

  {

    return (           pi + atan2 ( -y, -x ) );

  }

  else if ( 0.0 < x && y < 0.0 )

  {

    return ( 2.0 * pi - atan2 ( -y,  x ) );

  }

  return 0.0;

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

string i4_to_string ( int i4, string format )

{

  char i4_char[80];

  string i4_string;

  sprintf ( i4_char, format.c_str ( ), i4 );

  i4_string = string ( i4_char );

  return i4_string;

}

void i4mat_transpose_print ( int m, int n, int a[], string title )

{

  i4mat_transpose_print_some ( m, n, a, 1, 1, m, n, title );

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

  cout << "\n";

  cout << title << "\n";

  for ( i2lo = ilo; i2lo <= ihi; i2lo = i2lo + INCX )

  {

    i2hi = i2lo + INCX - 1;

    i2hi = i4_min ( i2hi, m );

    i2hi = i4_min ( i2hi, ihi );

    cout << "\n";

    cout << "  Row: ";

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(6) << i - 1 << "  ";

    }

    cout << "\n";

    cout << "  Col\n";

    cout << "\n";

    j2lo = i4_max ( jlo, 1 );

    j2hi = i4_min ( jhi, n );

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(5) << j - 1 << ":";

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

void i4vec_copy ( int n, int a1[], int a2[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    a2[i] = a1[i];

  }

  return;

}

void icos_shape ( int point_num, int edge_num, int face_num, 

  int face_order_max, double point_coord[], int edge_point[], int face_order[],

  int face_point[] )

{

# define DIM_NUM 3

# define EDGE_NUM 30

# define EDGE_ORDER 2

# define FACE_NUM 20

# define POINT_NUM 12

  double phi = 0.5 * ( sqrt ( 5.0 ) + 1.0 );

  double a = phi / sqrt ( 1.0 + phi * phi );

  double b = 1.0 / sqrt ( 1.0 + phi * phi );

  double z = 0.0;

  static int edge_point_save[EDGE_ORDER*EDGE_NUM] = {

     0,  1,

     0,  2,

     0,  3,

     0,  4,

     0,  5,

     1,  2,

     1,  3,

     1,  6,

     1,  7,

     2,  4,

     2,  6,

     2,  8,

     3,  5,

     3,  7,

     3,  9,

     4,  5,

     4,  8,

     4, 10,

     5,  9,

     5, 10,

     6,  7,

     6,  8,

     6, 11,

     7,  9,

     7, 11,

     8, 10,

     8, 11,

     9, 10,

     9, 11,

    10, 11 };

  static int face_order_save[FACE_NUM] = {

    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 

    3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

  static int face_point_save[3*FACE_NUM] = {

     0,  1,  3,

     0,  2,  1,

     0,  3,  5,

     0,  4,  2,

     0,  5,  4,

     1,  2,  6,

     1,  6,  7,

     1,  7,  3,

     2,  4,  8,

     2,  8,  6,

     3,  7,  9,

     3,  9,  5,

     4,  5, 10,

     4, 10,  8,

     5,  9, 10,

     6,  8, 11,

     6, 11,  7,

     7, 11,  9,

     8, 10, 11,

     9, 11, 10 };

  static double point_coord_save[DIM_NUM*POINT_NUM] = {

      a,  b,  z,

      a, -b,  z,

      b,  z,  a,

      b,  z, -a,

      z,  a,  b,

      z,  a, -b,

      z, -a,  b,

      z, -a, -b,

     -b,  z,  a,

     -b,  z, -a,

     -a,  b,  z,

     -a, -b,  z };

  r8vec_copy ( DIM_NUM * point_num,       point_coord_save, point_coord );

  i4vec_copy ( EDGE_ORDER * edge_num,     edge_point_save,  edge_point );

  i4vec_copy ( face_num,                  face_order_save,  face_order );

  i4vec_copy ( face_order_max * face_num, face_point_save,  face_point );

  return;

# undef DIM_NUM

# undef EDGE_NUM

# undef EDGE_ORDER

# undef FACE_NUM

# undef POINT_NUM

}

void icos_num ( int *point_num, int *edge_num, int *face_num, 

  int *face_order_max )

{

  *point_num = 12;

  *edge_num = 30;

  *face_num = 20;

  *face_order_max = 3;

  return;

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

double r8_modp ( double x, double y )

{

  double value;

  if ( y == 0.0 )

  {

    cerr << "\n";

    cerr << "R8_MODP - Fatal error!\n";

    cerr << "  R8_MODP ( X, Y ) called with Y = " << y << "\n";

    exit ( 1 );

  }

  value = x - ( ( double ) ( ( int ) ( x / y ) ) ) * y;

  if ( value < 0.0 )

  {

    value = value + r8_abs ( y );

  }

  return value;

}

double r8_uniform_01 ( int *seed )

{

  int i4_huge = 2147483647;

  int k;

  double r;

  if ( *seed == 0 )

  {

    cerr << "\n";

    cerr << "R8_UNIFORM_01 - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )

  {

    *seed = *seed + i4_huge;

  }

  r = ( double ) ( *seed ) * 4.656612875E-10;

  return r;

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

      cout << setw(7) << i - 1 << "       ";

    }

    cout << "\n";

    cout << "  Col\n";

    cout << "\n";

    j2lo = i4_max ( jlo, 1 );

    j2hi = i4_min ( jhi, n );

    for ( j = j2lo; j <= j2hi; j++ )

    {

      cout << setw(5) << j - 1 << ":";

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

void r8vec_copy ( int n, double a1[], double a2[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    a2[i] = a1[i];

  }

  return;

}

double r8vec_diff_norm ( int n, double a[], double b[] )

{

  int i;

  double value;

  value = 0.0;

  for ( i = 0; i < n; i++ )

  {

    value = value + ( a[i] + b[i] ) * ( a[i] - b[i] );

  }

  value = sqrt ( value );

  return value;

}

double r8vec_dot_product ( int n, double a1[], double a2[] )

{

  int i;

  double value;

  value = 0.0;

  for ( i = 0; i < n; i++ )

  {

    value = value + a1[i] * a2[i];

  }

  return value;

}

bool r8vec_eq ( int n, double a1[], double a2[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    if ( a1[i] != a2[i] )

    {

      return false;

    }

  }

  return true;

}

double r8vec_norm ( int n, double a[] )

{

  int i;

  double v;

  v = 0.0;

  for ( i = 0; i < n; i++ )

  {

    v = v + a[i] * a[i];

  }

  v = sqrt ( v );

  return v;

}

void r8vec_polarize ( int n, double a[], double p[], double a_normal[], 

  double a_parallel[] )

{

  double a_dot_p;

  int i;

  double p_norm;

  p_norm = r8vec_norm ( n, p );

  if ( p_norm == 0.0 )

  {

    for ( i = 0; i < n; i++ )

    {

      a_normal[i] = a[i];

    }

    for ( i = 0; i < n; i++ )

    {

      a_parallel[i] = 0.0;

    }

    return;

  }

  a_dot_p = r8vec_dot_product ( n, a, p ) / p_norm;

  for ( i = 0; i < n; i++ )

  {

    a_parallel[i] = a_dot_p * p[i] / p_norm;

  }

  for ( i = 0; i < n; i++ )

  {

    a_normal[i] = a[i] - a_parallel[i];

  }

  return;

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

double *sphere_cubed_ijk_to_xyz_old ( int n, int i, int j, int k )

{

  double pi = 3.141592653589793;

  double xc;

  double *xyz;

  double xyzn;

  double yc;

  double zc;

  xyz = new double[3];

  if ( i == 0 )

  {

    xc = -1.0;

  }

  else if ( i == n )

  {

    xc = +1.0;

  }

  else

  {

    xc = tan ( ( double ) ( 2 * i - n ) * 0.25 * pi / ( double ) ( n ) );

  }

  if ( j == 0 )

  {

    yc = -1.0;

  }

  else if ( j == n )

  {

    yc = +1.0;

  }

  else

  {

    yc = tan ( ( double ) ( 2 * j - n ) * 0.25 * pi / ( double ) ( n ) );

  }

  if ( k == 0 )

  {

    zc = -1.0;

  }

  else if ( k == n )

  {

    zc = +1.0;

  }

  else

  {

    zc = tan ( ( double ) ( 2 * k - n ) * 0.25 * pi / ( double ) ( n ) );

  }

  xyzn = sqrt ( xc * xc + yc * yc + zc * zc );

  xyz[0] = xc / xyzn;

  xyz[1] = yc / xyzn;

  xyz[2] = zc / xyzn;

  return xyz;

}

void sphere_cubed_ijk_to_xyz ( int n, int i, int j, int k, double *xyz )

{

  double pi = 3.141592653589793;

  double xc;

  double xyzn;

  double yc;

  double zc;

  if ( i == 0 )

  {

    xc = -1.0;

  }

  else if ( i == n )

  {

    xc = +1.0;

  }

  else

  {

    xc = tan ( ( double ) ( 2 * i - n ) * 0.25 * pi / ( double ) ( n ) );

  }

  if ( j == 0 )

  {

    yc = -1.0;

  }

  else if ( j == n )

  {

    yc = +1.0;

  }

  else

  {

    yc = tan ( ( double ) ( 2 * j - n ) * 0.25 * pi / ( double ) ( n ) );

  }

  if ( k == 0 )

  {

    zc = -1.0;

  }

  else if ( k == n )

  {

    zc = +1.0;

  }

  else

  {

    zc = tan ( ( double ) ( 2 * k - n ) * 0.25 * pi / ( double ) ( n ) );

  }

  xyzn = sqrt ( xc * xc + yc * yc + zc * zc );

  xyz[0] = xc / xyzn;

  xyz[1] = yc / xyzn;

  xyz[2] = zc / xyzn;

  return;

}

int sphere_cubed_line_num ( int n )

{

  int line_num;

  line_num = 0;

  if ( n == 1 )

  {

    line_num = 12;

    return line_num;

  }

  else

  {

    line_num = line_num + 8 * 3;

  }

  if ( 2 < n )

  {

    line_num = line_num + 12 * ( n - 2 );

  }

  if ( 1 < n )

  {

    line_num = line_num + 6 * 2 * n * ( n - 1 );

  }

  return line_num;

}

double *sphere_cubed_lines ( int n, int line_num )

{

  int i;

  int j;

  int l;

  double *line_data;

  line_data = new double[3*2*line_num];

  l = 0;

  if ( n == 1 )

  {

    sphere_cubed_ijk_to_xyz ( n, 0, 0, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, 0, 0, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, 0, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, n, 0, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, n, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, n, 0, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, n, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, 0, 0, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, 0, n, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, 0, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, 0, n, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, n, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, n, n, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, n, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, n, n, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, 0, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, 0, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, 0, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, 0, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, 0, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, n, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, n, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, n, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, n, n, line_data+0+1*3+l*6 );

    l = l + 1;

    return line_data;

  }

  else

  {

    sphere_cubed_ijk_to_xyz ( n, 0, 0, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 1, 0, 0, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, 0, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, 1, 0, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, 0, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, 0, 1, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n,   0, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n-1, 0, 0, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, 0, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, 1, 0, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, 0, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, 0, 1, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n,   n, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n-1, n, 0, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, n,   0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, n-1, 0, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, n, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, n, 1, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, n, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 1, n, 0, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, n,   0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, n-1, 0, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, n, 0, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, n, 1, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, 0, n, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 1, 0, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, 0, n, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, 1, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, 0, n,   line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, 0, n-1, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n,   0, n, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n-1, 0, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, 0, n, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, 1, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, 0, n,   line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, 0, n-1, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n,   n, n, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n-1, n, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, n,   n, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, n-1, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, n, n, n,   line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, n, n, n-1, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, n, n, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 1, n, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, n,   n, line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, n-1, n, line_data+0+1*3+l*6 );

    l = l + 1;

    sphere_cubed_ijk_to_xyz ( n, 0, n, n,   line_data+0+0*3+l*6 );

    sphere_cubed_ijk_to_xyz ( n, 0, n, n-1, line_data+0+1*3+l*6 );

    l = l + 1;

  }

  if ( 2 < n )

  {

    for ( i = 1; i <= n - 2; i++ )

    {

      sphere_cubed_ijk_to_xyz ( n, i,   0, 0, line_data+0+0*3+l*6 );

      sphere_cubed_ijk_to_xyz ( n, i+1, 0, 0, line_data+0+1*3+l*6 );

      l = l + 1;

    }

    for ( i = 1; i <= n - 2; i++ )

    {

      sphere_cubed_ijk_to_xyz ( n, n,   i, 0, line_data+0+0*3+l*6 );

      sphere_cubed_ijk_to_xyz ( n, n, i+1, 0, line_data+0+1*3+l*6 );

      l = l + 1;

    }

    for ( i = 1; i <= n - 2; i++ )

    {

      sphere_cubed_ijk_to_xyz ( n, n-i,   n, 0, line_data+0+0*3+l*6 );

      sphere_cubed_ijk_to_xyz ( n, n-i-1, n, 0, line_data+0+1*3+l*6 );

      l = l + 1;

    }

    for ( i = 1; i <= n - 2; i++ )

    {

      sphere_cubed_ijk_to_xyz ( n, 0, n-i,   0, line_data+0+0*3+l*6 );

      sphere_cubed_ijk_to_xyz ( n, 0, n-i-1, 0, line_data+0+1*3+l*6 );

      l = l + 1;

    }

    for ( i = 1; i <= n - 2; i++ )

    {

      sphere_cubed_ijk_to_xyz ( n, i,   0, n, line_data+0+0*3+l*6 );

      sphere_cubed_ijk_to_xyz ( n, i+1, 0, n, line_data+0+1*3+l*6 );

      l = l + 1;

    }

    for ( i = 1; i <= n - 2; i++ )

    {

      sphere_cubed_ijk_to_xyz ( n, n,   i, n, line_data+0+0*3+l*6 );

      sphere_cubed_ijk_to_xyz ( n, n, i+1, n, line_data+0+1*3+l*6 );

      l = l + 1;

    }

    for ( i = 1; i <= n - 2; i++ )

    {

      sphere_cubed_ijk_to_xyz ( n, n-i,   n, n, line_data+0+0*3+l*6 );

      sphere_cubed_ijk_to_xyz ( n, n-i-1, n, n, line_data+0+1*3+l*6 );

      l = l + 1;

    }

    for ( i = 1; i <= n - 2; i++ )

    {

      sphere_cubed_ijk_to_xyz ( n, 0, n-i,   n, line_data+0+0*3+l*6 );

      sphere_cubed_ijk_to_xyz ( n, 0, n-i-1, n, line_data+0+1*3+l*6 );

      l = l + 1;

    }

    for ( i = 1; i <= n - 2; i++ )

    {

      sphere_cubed_ijk_to_xyz ( n, 0, 0, i,   line_data+0+0*3+l*6 );

      sphere_cubed_ijk_to_xyz ( n, 0, 0, i+1, line_data+0+1*3+l*6 );

      l = l + 1;

    }

    for ( i = 1; i <= n - 2; i++ )

    {

      sphere_cubed_ijk_to_xyz ( n, n, 0, i,   line_data+0+0*3+l*6 );

      sphere_cubed_ijk_to_xyz ( n, n, 0, i+1, line_data+0+1*3+l*6 );

      l = l + 1;

    }

    for ( i = 1; i <= n - 2; i++ )

    {

      sphere_cubed_ijk_to_xyz ( n, n, n, i,   line_data+0+0*3+l*6 );

      sphere_cubed_ijk_to_xyz ( n, n, n, i+1, line_data+0+1*3+l*6 );

      l = l + 1;

    }

    for ( i = 1; i <= n - 2; i++ )

    {

      sphere_cubed_ijk_to_xyz ( n, 0, n, i,   line_data+0+0*3+l*6 );

      sphere_cubed_ijk_to_xyz ( n, 0, n, i+1, line_data+0+1*3+l*6 );

      l = l + 1;

    }

  }

  if ( 1 < n )

  {

    for ( i = 1; i <= n - 1; i++ )

    {

      for ( j = 0; j <= n - 1; j++ )

      {

        sphere_cubed_ijk_to_xyz ( n, i, j,   0, line_data+0+0*3+l*6 );

        sphere_cubed_ijk_to_xyz ( n, i, j+1, 0, line_data+0+1*3+l*6 );

        l = l + 1;

      }

    }

    for ( j = 1; j <= n - 1; j++ )

    {

      for ( i = 0; i <= n - 1; i++ )

      {

        sphere_cubed_ijk_to_xyz ( n, i,   j, 0, line_data+0+0*3+l*6 );

        sphere_cubed_ijk_to_xyz ( n, i+1, j, 0, line_data+0+1*3+l*6 );

        l = l + 1;

      }

    }

    for ( i = 1; i <= n - 1; i++ )

    {

      for ( j = 0; j <= n - 1; j++ )

      {

        sphere_cubed_ijk_to_xyz ( n, i, j,   n, line_data+0+0*3+l*6 );

        sphere_cubed_ijk_to_xyz ( n, i, j+1, n, line_data+0+1*3+l*6 );

        l = l + 1;

      }

    }

    for ( j = 1; j <= n - 1; j++ )

    {

      for ( i = 0; i <= n - 1; i++ )

      {

        sphere_cubed_ijk_to_xyz ( n, i,   j, n, line_data+0+0*3+l*6 );

        sphere_cubed_ijk_to_xyz ( n, i+1, j, n, line_data+0+1*3+l*6 );

        l = l + 1;

      }

    }

    for ( i = 1; i <= n - 1; i++ )

    {

      for ( j = 0; j <= n - 1; j++ )

      {

        sphere_cubed_ijk_to_xyz ( n, i, 0, j,   line_data+0+0*3+l*6 );

        sphere_cubed_ijk_to_xyz ( n, i, 0, j+1, line_data+0+1*3+l*6 );

        l = l + 1;

      }

    }

    for ( j = 1; j <= n - 1; j++ )

    {

      for ( i = 0; i <= n - 1; i++ )

      {

        sphere_cubed_ijk_to_xyz ( n, i,   0, j, line_data+0+0*3+l*6 );

        sphere_cubed_ijk_to_xyz ( n, i+1, 0, j, line_data+0+1*3+l*6 );

        l = l + 1;

      }

    }

    for ( i = 1; i <= n - 1; i++ )

    {

      for ( j = 0; j <= n - 1; j++ )

      {

        sphere_cubed_ijk_to_xyz ( n, i, n, j,   line_data+0+0*3+l*6 );

        sphere_cubed_ijk_to_xyz ( n, i, n, j+1, line_data+0+1*3+l*6 );

        l = l + 1;

      }

    }

    for ( j = 1; j <= n - 1; j++ )

    {

      for ( i = 0; i <= n - 1; i++ )

      {

        sphere_cubed_ijk_to_xyz ( n, i,   n, j, line_data+0+0*3+l*6 );

        sphere_cubed_ijk_to_xyz ( n, i+1, n, j, line_data+0+1*3+l*6 );

        l = l + 1;

      }

    }

    for ( i = 1; i <= n - 1; i++ )

    {

      for ( j = 0; j <= n - 1; j++ )

      {

        sphere_cubed_ijk_to_xyz ( n, 0, i, j,   line_data+0+0*3+l*6 );

        sphere_cubed_ijk_to_xyz ( n, 0, i, j+1, line_data+0+1*3+l*6 );

        l = l + 1;

      }

    }

    for ( j = 1; j <= n - 1; j++ )

    {

      for ( i = 0; i <= n - 1; i++ )

      {

        sphere_cubed_ijk_to_xyz ( n, 0, i,   j, line_data+0+0*3+l*6 );

        sphere_cubed_ijk_to_xyz ( n, 0, i+1, j, line_data+0+1*3+l*6 );

        l = l + 1;

      }

    }

    for ( i = 1; i <= n - 1; i++ )

    {

      for ( j = 0; j <= n - 1; j++ )

      {

        sphere_cubed_ijk_to_xyz ( n, n, i, j,   line_data+0+0*3+l*6 );

        sphere_cubed_ijk_to_xyz ( n, n, i, j+1, line_data+0+1*3+l*6 );

        l = l + 1;

      }

    }

    for ( j = 1; j <= n - 1; j++ )

    {

      for ( i = 0; i <= n - 1; i++ )

      {

        sphere_cubed_ijk_to_xyz ( n, n, i,   j, line_data+0+0*3+l*6 );

        sphere_cubed_ijk_to_xyz ( n, n, i+1, j, line_data+0+1*3+l*6 );

        l = l + 1;

      }

    }

  }

  if ( l != line_num )

  {

    cerr << "\n";

    cerr << "SPHERE_CUBED_LINES - Fatal error!\n";

    cerr << "  LINE_NUM = " << line_num << "\n";

    cerr << "  L = " << l << "n";

    exit ( 1 );

  }

  return line_data;

}

double *sphere_cubed_points ( int n, int ns )

{

  int ns2;

  double *xyz;

  xyz = new double[3*ns];

  ns2 = 0;

  sphere_cubed_points_face ( n, 0, 0, 0, n, n, 0, ns2, xyz );

  sphere_cubed_points_face ( n, 0, 0, 1, 0,   n-1, n-1, ns2, xyz );

  sphere_cubed_points_face ( n, 0, n, 1, n-1, n,   n-1, ns2, xyz );

  sphere_cubed_points_face ( n, n, 1, 1, n,   n,   n-1, ns2, xyz );

  sphere_cubed_points_face ( n, 1, 0, 1, n,   0,   n-1, ns2, xyz );

  sphere_cubed_points_face ( n, 0, 0, n, n, n, n, ns2, xyz );

  

  if ( ns2 != ns )

  {

    cerr << "\n";

    cerr << "SPHERE_CUBED_POINTS - Fatal error\n";

    cerr << "  Expected to generated NS = " << ns << " points.\n";

    cerr << "  Generated " << ns2 << " points.\n";

    exit ( 1 );

  }

  return xyz;

}

void sphere_cubed_points_face ( int n, int i1, int j1, int k1, int i2, int j2, 

  int k2, int &ns, double xyz[] )

{

  int i;

  int j;

  int k;

  double pi = 3.141592653589793;

  double xyzn;

  double xc;

  double yc;

  double zc;

  for ( i = i1; i <= i2; i++ )

  {

    if ( i1 < i2 )

    {

      xc = tan ( ( double ) ( 2 * i - n ) * 0.25 * pi / ( double ) ( n ) );

    }

    else if ( i1 == 0 )

    {

      xc = -1.0;

    }

    else if ( i1 == n )

    {

      xc = +1.0;

    }

    else

    {

      xc = 0.0;

    }

    for ( j = j1; j <= j2; j++ )

    {

      if ( j1 < j2 )

      {

        yc = tan ( ( double ) ( 2 * j - n ) * 0.25 * pi / ( double ) ( n ) );

      }

      else if ( j1 == 0 )

      {

        yc = -1.0;

      }

      else if ( j1 == n )

      {

        yc = +1.0;

      }

      else

      {

        yc = 0.0;

      }

      for ( k = k1; k <= k2; k++ )

      {

        if ( k1 < k2 )

        {

          zc = tan ( ( double ) ( 2 * k - n ) * 0.25 * pi / ( double ) ( n ) );

        }

        else if ( k1 == 0 )

        {

          zc = -1.0;

        }

        else if ( k1 == n )

        {

          zc = +1.0;

        }

        else

        {

          zc = 0.0;

        }

        xyzn = sqrt ( xc * xc + yc * yc + zc * zc );

        xyz[0+ns*3] = xc / xyzn;

        xyz[1+ns*3] = yc / xyzn;

        xyz[2+ns*3] = zc / xyzn;

        ns = ns + 1;

      }

    }

  }

  return;

}

int sphere_cubed_point_num ( int n )

{

  int ns;

  ns = i4_power ( n + 1, 3 ) - i4_power ( n - 1, 3 );

  return ns;

}

double sphere_distance_xyz ( double xyz1[3], double xyz2[3] )

{

  double bot;

  double dist;

  double lat1;

  double lat2;

  double lon1;

  double lon2;

  double r;

  double top;

  r = r8vec_norm ( 3, xyz1 );

  lat1 = arc_sine ( xyz1[2] );

  lon1 = atan4 ( xyz1[1], xyz1[0] );

  lat2 = arc_sine ( xyz2[2] );

  lon2 = atan4 ( xyz2[1], xyz2[0] );

  top = pow ( cos ( lat2 ) * sin ( lon1 - lon2 ), 2 )

      + pow ( cos ( lat1 ) * sin ( lat2 ) 

            - sin ( lat1 ) * cos ( lat2 ) * cos ( lon1 - lon2 ), 2 );

  top = sqrt ( top );

  bot = sin ( lat1 ) * sin ( lat2 ) 

      + cos ( lat1 ) * cos ( lat2 ) * cos ( lon1 - lon2 );

  dist = r * atan2 ( top, bot );

  return dist;

}

double *sphere_fibonacci_points ( int n )

{

  double cphi;

  int i;

  double i_r8;

  int j;

  double n_r8;

  double phi;

  const double pi = 3.141592653589793;

  double sphi;

  double theta;

  double *xyz;

  phi = ( 1.0 + sqrt ( 5.0 ) ) / 2.0;

  n_r8 = ( double ) ( n );

  xyz = new double[3*n];

  for ( j = 0; j < n; j++ )

  {

    i_r8 = ( double ) ( - n + 1 + 2 * j );

    theta = 2.0 * pi * i_r8 / phi;

    sphi = i_r8 / n_r8;

    cphi = sqrt ( ( n_r8 + i_r8 ) * ( n_r8 - i_r8 ) ) / n_r8;

    xyz[0+j*3] = cphi * sin ( theta );

    xyz[1+j*3] = cphi * cos ( theta );

    xyz[2+j*3] = sphi;

  }

  return xyz;

}

int *sphere_grid_q4 ( int lat_num, int long_num )

{

  int i;

  int j;

  int n;

  int n_max;

  int n_min;

  int ne;

  int nw;

  int s;

  int s_max;

  int s_min;

  int se;

  int sw;

  int *rectangle_node;

  int rectangle_num;

  rectangle_node = new int[4*(lat_num*long_num)];

  rectangle_num = 0;

  n = 0;

  sw = 1;

  se = sw + 1;

  s_min = 1;

  s_max = long_num;

  for ( j = 1; j <= long_num; j++ )

  {

    rectangle_node[0+rectangle_num*4] = sw;

    rectangle_node[1+rectangle_num*4] = se;

    rectangle_node[2+rectangle_num*4] = n;

    rectangle_node[3+rectangle_num*4] = n;

    rectangle_num = rectangle_num + 1;

    sw = se;

    if ( se == s_max )

    {

      se = s_min;

    }

    else

    {

      se = se + 1;

    }

  }

  for ( i = 2; i < lat_num; i++ )

  {

    n_max = s_max;

    n_min = s_min;

    s_max = s_max + long_num;

    s_min = s_min + long_num;

    nw = n_min;

    ne = nw + 1;

    sw = s_min;

    se = sw + 1;

    for ( j = 1; j <= long_num; j++ )

    {

      rectangle_node[0+rectangle_num*4] = sw;

      rectangle_node[1+rectangle_num*4] = se;

      rectangle_node[2+rectangle_num*4] = ne;

      rectangle_node[3+rectangle_num*4] = nw;

      rectangle_num = rectangle_num + 1;

      sw = se;

      nw = ne;

      if ( se == s_max )

      {

        se = s_min;

      }

      else

      {

        se = se + 1;

      }

      if ( ne == n_max )

      {

        ne = n_min;

      }

      else

      {

        ne = ne + 1;

      }

    }

  }

  n_max = s_max;

  n_min = s_min;

  s = n_max + 1;

  nw = n_min;

  ne = nw + 1;

  for ( j = 1; j <= long_num; j++ )

  {

    rectangle_node[0+rectangle_num*4] = ne;

    rectangle_node[1+rectangle_num*4] = nw;

    rectangle_node[2+rectangle_num*4] = s;

    rectangle_node[3+rectangle_num*4] = s;

    rectangle_num = rectangle_num + 1;

    nw = ne;

    if ( ne == n_max )

    {

      ne = n_min;

    }

    else

    {

      ne = ne + 1;

    }

  }

  return rectangle_node;

}

int *sphere_grid_t3 ( int lat_num, int long_num )

{

  int i;

  int j;

  int n;

  int n_max;

  int n_min;

  int ne;

  int nw;

  int s;

  int s_max;

  int s_min;

  int se;

  int sw;

  int *triangle_node;

  int triangle_num;

  triangle_node = new int[3*2*(lat_num+1)*long_num];

  triangle_num = 0;

  n = 1;

  sw = 2;

  se = sw + 1;

  s_min = 2;

  s_max = long_num + 1;

  for ( j = 0; j < long_num; j++ )

  {

    triangle_node[0+triangle_num*3] = sw - 1;

    triangle_node[1+triangle_num*3] = se - 1;

    triangle_node[2+triangle_num*3] = n - 1;

    triangle_num = triangle_num + 1;

    sw = se;

    if ( se == s_max )

    {

      se = s_min;

    }

    else

    {

      se = se + 1;

    }

  }

  for ( i = 1; i <= lat_num; i++ )

  {

    n_max = s_max;

    n_min = s_min;

    s_max = s_max + long_num;

    s_min = s_min + long_num;

    nw = n_min;

    ne = nw + 1;

    sw = s_min;

    se = sw + 1;

    for ( j = 0; j < long_num; j++ )

    {

      triangle_node[0+triangle_num*3] = sw - 1;

      triangle_node[1+triangle_num*3] = se - 1;

      triangle_node[2+triangle_num*3] = nw - 1;

      triangle_num = triangle_num + 1;

      triangle_node[0+triangle_num*3] = ne - 1;

      triangle_node[1+triangle_num*3] = nw - 1;

      triangle_node[2+triangle_num*3] = se - 1;

      triangle_num = triangle_num + 1;

      sw = se;

      nw = ne;

      if ( se == s_max )

      {

        se = s_min;

      }

      else

      {

        se = se + 1;

      }

      if ( ne == n_max )

      {

        ne = n_min;

      }

      else

      {

        ne = ne + 1;

      }

    }

  }

  n_max = s_max;

  n_min = s_min;

  s = n_max + 1;

  nw = n_min;

  ne = nw + 1;

  for ( j = 0; j < long_num; j++ )

  {

    triangle_node[0+triangle_num*3] = ne - 1;

    triangle_node[1+triangle_num*3] = nw - 1;

    triangle_node[2+triangle_num*3] = s - 1;

    triangle_num = triangle_num + 1;

    nw = ne;

    if ( ne == n_max )

    {

      ne = n_min;

    }

    else

    {

      ne = ne + 1;

    }

  }

  return triangle_node;

}

int sphere_icos_edge_num ( int factor )

{

  int edge_num;

  edge_num = 30 * factor * factor;

  return edge_num;

}

int sphere_icos_face_num ( int factor )

{

  int face_num;

  face_num = 20 * factor * factor;

  return face_num;

}

int sphere_icos_point_num ( int factor )

{

  int point_num;

  point_num = 12                                   

            + 10 * 3              * ( factor - 1 ) 

            + 10 * ( factor - 2 ) * ( factor - 1 );

  return point_num;

}

double *sphere_icos1_points ( int factor, int node_num )

{

  int a;

  int b;

  int c;

  int dim;

  int edge;

  int edge_num;

  int *edge_point;

  int f;

  int f1;

  int f2;

  int face;

  int face_num;

  int *face_order;

  int *face_point;

  int face_order_max;

  int node;

  double node_norm;

  double *node_xyz;

  int point;

  double *point_coord;

  int point_num;

  node_xyz = new double[3*node_num];

  icos_num ( &point_num, &edge_num, &face_num, &face_order_max );

  point_coord = new double[3*point_num];

  edge_point = new int[2*edge_num];

  face_order = new int[face_num];

  face_point = new int[face_order_max*face_num];

  icos_shape ( point_num, edge_num, face_num, face_order_max, 

    point_coord, edge_point, face_order, face_point );

  node = 0;

  for ( point = 0; point < point_num; point++ )

  {

    for ( dim = 0; dim < 3; dim++ )

    {

      node_xyz[dim+node*3] = point_coord[dim+point*3];

    }

    node = node + 1;

  }

  for ( edge = 0; edge < edge_num; edge++ )

  {

    a = edge_point[0+edge*2];

    b = edge_point[1+edge*2];

    for ( f = 1; f < factor; f++ )

    {

      for ( dim = 0; dim < 3; dim++ )

      {

        node_xyz[dim+node*3] = 

          ( ( double ) ( factor - f ) * point_coord[dim+a*3]

          + ( double ) (          f ) * point_coord[dim+b*3] ) 

          / ( double ) ( factor     );

      }

      node_norm = r8vec_norm ( 3, node_xyz+node*3 );

      for ( dim = 0; dim < 3; dim++ )

      {

        node_xyz[dim+node*3] = node_xyz[dim+node*3] / node_norm;

      }

      node = node + 1;

    }

  }

  for ( face = 0; face < face_num; face++ )

  {

    a = face_point[0+face*3];

    b = face_point[1+face*3];

    c = face_point[2+face*3];

    for ( f1 = 1; f1 < factor; f1++ )

    {

      for ( f2 = 1; f2 < factor - f1; f2++ )

      {

        for ( dim = 0; dim < 3; dim++ )

        {

          node_xyz[dim+node*3] = 

            ( ( double ) ( factor - f1 - f2 ) * point_coord[dim+a*3]  

            + ( double ) (          f1      ) * point_coord[dim+b*3] 

            + ( double ) (               f2 ) * point_coord[dim+c*3] ) 

            / ( double ) ( factor           );

        }

        node_norm = r8vec_norm ( 3, node_xyz+node*3 );

        for ( dim = 0; dim < 3; dim++ )

        {

          node_xyz[dim+node*3] = node_xyz[dim+node*3] / node_norm;

        }

        node = node + 1;

      }

    }

  }

  delete [] edge_point;

  delete [] face_order;

  delete [] face_point;

  delete [] point_coord;

  return node_xyz;

}

double *sphere_icos2_points ( int factor, int node_num )

{

  int a;

  double angle;

  double ab[3];

  double ac[3];

  double acn[3];

  double acn_norm;

  double acp[3];

  int b;

  double bn[3];

  double bn_norm;

  double bp[3];

  int c;

  double cn[3];

  double cn_norm;

  double cp[3];

  int edge;

  int edge_num;

  int *edge_point;

  int f;

  int fa;

  int fbc;

  int face;

  int face_num;

  int *face_order;

  int *face_point;

  int face_order_max;

  int i;

  int j;

  int node;

  double *node_xyz;

  double p;

  int point;

  double *point_coord;

  int point_num;

  double theta;

  double theta_ab;

  double theta_ac;

  double theta_bc;

  node_xyz = new double[3*node_num];

  icos_num ( &point_num, &edge_num, &face_num, &face_order_max );

  point_coord = new double[3*point_num];

  edge_point = new int[2*edge_num];

  face_order = new int[face_num];

  face_point = new int[face_order_max*face_num];

  icos_shape ( point_num, edge_num, face_num, face_order_max, 

    point_coord, edge_point, face_order, face_point );

  node = 0;

  for ( j = 0; j < point_num; j++ )

  {

    for ( i = 0; i < 3; i++ )

    {

      node_xyz[i+j*3] = point_coord[i+j*3];

    }

    node = node + 1;

  }

  for ( edge = 0; edge < edge_num; edge++ )

  {

    a = edge_point[0+edge*2];

    b = edge_point[1+edge*2];

    theta = sphere_distance_xyz ( point_coord+a*3, point_coord+b*3 );

    r8vec_polarize ( 3, point_coord+b*3, point_coord+a*3, bn, bp );

    bn_norm = r8vec_norm ( 3, bn );

    for ( i = 0; i < 3; i++ )

    {

      bn[i] = bn[i] / bn_norm;

    }

    for ( f = 1; f < factor; f++ )

    {

      angle = ( ( double ) ( f ) * theta ) / ( double ) ( factor );

     

      for ( i = 0; i < 3; i++ )

      {

        node_xyz[i+node*3] = cos ( angle ) * point_coord[i+a*3]

                           + sin ( angle ) * bn[i];

      }

      node = node + 1;

    }

  }

  for ( face = 0; face < face_num; face++ )

  {

    a = face_point[0+face*3];

    b = face_point[1+face*3];

    c = face_point[2+face*3];

    theta_ab = sphere_distance_xyz ( point_coord+a*3, point_coord+b*3 );

    theta_ac = sphere_distance_xyz ( point_coord+a*3, point_coord+c*3 );

    r8vec_polarize ( 3, point_coord+b*3, point_coord+a*3, bn, bp );

    bn_norm = r8vec_norm ( 3, bn );

    for ( i = 0; i < 3; i++ )

    {

      bn[i] = bn[i] / bn_norm;

    }

    r8vec_polarize ( 3, point_coord+c*3, point_coord+a*3, cn, cp );

    cn_norm = r8vec_norm ( 3, cn );

    for ( i = 0; i < 3; i++ )

    {

      cn[i] = cn[i] / cn_norm;

    }

    for ( fa = 2; fa < factor; fa++ )

    {

      angle = ( (double ) ( fa ) * theta_ab ) / ( double ) ( factor );

      for ( i = 0; i < 3; i++ )

      {

        ab[i] = cos ( angle ) * point_coord[i+a*3] + sin ( angle ) * bn[i];

      }

      angle = ( ( double ) ( fa ) * theta_ac ) / ( double ) ( factor );

      for ( i = 0; i < 3; i++ )

      {

        ac[i] = cos ( angle ) * point_coord[i+a*3] + sin ( angle ) * cn[i];

      }

      theta_bc = sphere_distance_xyz ( ab, ac );

      r8vec_polarize ( 3, ac, ab, acn, acp );

      acn_norm = r8vec_norm ( 3, acn );

      for ( i = 0; i < 3; i++ )

      {

        acn[i] = acn[i] / acn_norm;

      }

      for ( fbc = 1; fbc < fa; fbc++ )

      {

        angle = ( ( double ) ( fbc ) * theta_bc ) / ( double ) ( fa );

        for ( i = 0; i < 3; i++ )

        {

          node_xyz[i+node*3] = cos ( angle ) * ab[i] + sin ( angle ) * acn[i];

        }

        node = node + 1;

      }

    }

  }

  delete [] edge_point;

  delete [] face_order;

  delete [] face_point;

  delete [] point_coord;

  return node_xyz;

}

int sphere_line_project ( double r, double pc[3], int n, double p[], 

  int maxpnt2, double pp[], double thetamin, double thetamax )

{

# define DIM_NUM 3

  double alpha;

  double ang3d;

  double dot;

  int i;

  int j;

  int nfill;

  int n2;

  double tnorm;

  double p1[DIM_NUM];

  double p2[DIM_NUM];

  double pi[DIM_NUM];

  if ( r == 0.0 )

  {

    n2 = 0;

    return n2;

  }

  r8vec_copy ( DIM_NUM, pc, p1 );

  r8vec_copy ( DIM_NUM, pc, p2 );

  n2 = 0;

  for ( i = 0; i < n; i++ )

  {

    if ( r8vec_eq ( DIM_NUM, p, pc ) )

    {

    }

    else

    {

      r8vec_copy ( DIM_NUM, p2, p1 );

      alpha = sqrt ( pow ( p[0+i*3] - pc[0], 2 )

                   + pow ( p[1+i*3] - pc[1], 2 )

                   + pow ( p[2+i*3] - pc[2], 2 ) );

      p2[0] = pc[0] + r * ( p[0+i*3] - pc[0] ) / alpha;

      p2[1] = pc[1] + r * ( p[1+i*3] - pc[1] ) / alpha;

      p2[2] = pc[2] + r * ( p[2+i*3] - pc[2] ) / alpha;

      if ( n2 == 0 )

      {

        pp[0+n2*3] = p2[0];

        pp[1+n2*3] = p2[1];

        pp[2+n2*3] = p2[2];

        n2 = n2 + 1;

      }

      else if ( 1 <= n2 )

      {

        dot = ( p1[0] - pc[0] ) * ( p2[0] - pc[0] ) 

            + ( p1[1] - pc[1] ) * ( p2[1] - pc[1] ) 

            + ( p1[2] - pc[2] ) * ( p2[2] - pc[2] );

        ang3d = arc_cosine (  dot / ( r * r ) );

        if ( thetamin < r8_abs ( ang3d ) || i == n )

        {

          if ( thetamax < r8_abs ( ang3d ) )

          {

            nfill = ( int ) ( r8_abs ( ang3d ) / thetamax );

            for ( j = 1; j < nfill; j++ )

            {

              pi[0] = ( ( double ) ( nfill - j ) * ( p1[0] - pc[0] ) 

                      + ( double ) (         j ) * ( p2[0] - pc[0] ) );

              pi[1] = ( ( double ) ( nfill - j ) * ( p1[1] - pc[1] ) 

                      + ( double ) (         j ) * ( p2[1] - pc[1] ) );

              pi[2] = ( ( double ) ( nfill - j ) * ( p1[2] - pc[2] ) 

                      + ( double ) (         j ) * ( p2[2] - pc[2] ) );

              tnorm = r8vec_norm ( DIM_NUM, pi );

              if ( tnorm != 0.0 )

              {

                pi[0] = pc[0] + r * pi[0] / tnorm;

                pi[1] = pc[1] + r * pi[1] / tnorm;

                pi[2] = pc[2] + r * pi[2] / tnorm;

                pp[0+n2*3] = pi[0];

                pp[1+n2*3] = pi[1];

                pp[2+n2*3] = pi[2];

                n2 = n2 + 1;

              }

            }

          }

          pp[0+n2*3] = p2[0];

          pp[1+n2*3] = p2[1];

          pp[2+n2*3] = p2[2];

          n2 = n2 + 1;

        }

      }

    }

  }

  return n2;

# undef DIM_NUM

}

int *sphere_ll_lines ( int nlat, int nlong, int line_num )

{

  int i;

  int j;

  int l;

  int *line;

  int next;

  int newcol;

  int old;

  line = ( int * ) malloc ( 2 * line_num * sizeof ( int ) );

  l = 0;

  for ( j = 0; j <= nlong - 1; j++ )

  {

    old = 1;

    next = j + 2;

    line[0+l*2] = old;

    line[1+l*2] = next;

    l = l + 1;

    for ( i = 1; i <= nlat-1; i++ )

    {

      old = next;

      next = old + nlong;

      line[0+l*2] = old;

      line[1+l*2] = next;

      l = l + 1;

    }

    old = next;

    line[0+l*2] = old;

    line[1+l*2] = 1 + nlat * nlong + 1;

    l = l + 1;

  }

  for ( i = 1; i <= nlat; i++ )

  {

    next = 1 + ( i - 1 ) * nlong + 1;

    for ( j = 0; j <= nlong-2; j++ )

    {

      old = next;

      next = old + 1;

      line[0+l*2] = old;

      line[1+l*2] = next;

      l = l + 1;

    }

    old = next;

    next = 1 + ( i - 1 ) * nlong + 1;

    line[0+l*2] = old;

    line[1+l*2] = next;

    l = l + 1;

  }

  for ( j = 0; j <= nlong-1; j++ )

  {

    old = 1;

    next = j + 2;

    newcol = j;

    for ( i = 1; i <= nlat - 1; i++ )

    {

      old = next;

      next = old + nlong + 1;

      newcol = newcol + 1;

      if ( nlong - 1 < newcol )

      {

        newcol = 0;

        next = next - nlong;

      }

      line[0+l*2] = old;

      line[1+l*2] = next;

      l = l + 1;

    }

  }

  return line;

}

int sphere_ll_line_num ( int lat_num, int long_num )

{

  int line_num;

  line_num = long_num * ( lat_num + 1 ) 

           + lat_num * long_num 

           + long_num * ( lat_num - 1 );

  return line_num;

}

double *sphere_ll_points ( double r, double pc[3], int lat_num, int lon_num,

  int point_num )

{

  int lat;

  int lon;

  int n;

  double *p;

  double phi;

  double pi = 3.141592653589793;

  double theta;

  p = new double[3*point_num];

  n = 0;

  theta = 0.0;

  phi = 0.0;

  p[0+n*3] = pc[0] + r * sin ( phi ) * cos ( theta );

  p[1+n*3] = pc[1] + r * sin ( phi ) * sin ( theta );

  p[2+n*3] = pc[2] + r * cos ( phi );

  n = n + 1;

  for ( lat = 1; lat <= lat_num; lat++ )

  {

    phi = ( double ) ( lat ) * pi / ( double ) ( lat_num + 1 );

    for ( lon = 0; lon < lon_num; lon++ )

    {

      theta = ( double ) ( lon ) * 2.0 * pi / ( double ) ( lon_num );

      p[0+n*3] = pc[0] + r * sin ( phi ) * cos ( theta );

      p[1+n*3] = pc[1] + r * sin ( phi ) * sin ( theta );

      p[2+n*3] = pc[2] + r * cos ( phi );

      n = n + 1;

    }

  }

  theta = 0.0;

  phi = pi;

  p[0+n*3] = pc[0] + r * sin ( phi ) * cos ( theta );

  p[1+n*3] = pc[1] + r * sin ( phi ) * sin ( theta );

  p[2+n*3] = pc[2] + r * cos ( phi );

  n = n + 1;

  return p;

}

int sphere_ll_point_num ( int lat_num, int long_num )

{

  int point_num;

  point_num = 2 + lat_num * long_num;

  return point_num;

}

int *sphere_llq_lines ( int nlat, int nlong, int line_num )

{

  int i;

  int j;

  int l;

  int *line;

  int next;

  int newcol;

  int old;

  line = ( int * ) malloc ( 2 * line_num * sizeof ( int ) );

  l = 0;

  for ( j = 0; j <= nlong - 1; j++ )

  {

    old = 1;

    next = j + 2;

    line[0+l*2] = old;

    line[1+l*2] = next;

    l = l + 1;

    for ( i = 1; i <= nlat-1; i++ )

    {

      old = next;

      next = old + nlong;

      line[0+l*2] = old;

      line[1+l*2] = next;

      l = l + 1;

    }

    old = next;

    line[0+l*2] = old;

    line[1+l*2] = 1 + nlat * nlong + 1;

    l = l + 1;

  }

  for ( i = 1; i <= nlat; i++ )

  {

    next = 1 + ( i - 1 ) * nlong + 1;

    for ( j = 0; j <= nlong-2; j++ )

    {

      old = next;

      next = old + 1;

      line[0+l*2] = old;

      line[1+l*2] = next;

      l = l + 1;

    }

    old = next;

    next = 1 + ( i - 1 ) * nlong + 1;

    line[0+l*2] = old;

    line[1+l*2] = next;

    l = l + 1;

  }

  return line;

}

int sphere_llq_line_num ( int lat_num, int long_num )

{

  int line_num;

  line_num = long_num * ( lat_num + 1 ) 

           + lat_num * long_num;

  return line_num;

}

double *sphere_spiralpoints ( double r, double pc[3], int n )

{

  double cosphi = 0.0;

  int i;

  double *p;

  double pi = 3.141592653589793;

  double sinphi = 0.0;

  double theta = 0.0;

  p = new double[3*n];

  for ( i = 0; i < n; i++ )

  {

    cosphi = ( ( double ) ( n - i - 1 ) * ( -1.0 ) 

             + ( double ) (     i     ) * (  1.0 ) ) 

             / ( double ) ( n     - 1 );

    sinphi = sqrt ( 1.0 - cosphi * cosphi );

    if ( i == 0 || i == n - 1 )

    {

      theta = 0.0;

    }

    else

    {

      theta = theta + 3.6 / ( sinphi * sqrt ( ( double ) n ) );

      theta = r8_modp ( theta, 2.0 * pi );

    }

    p[0+i*3] = pc[0] + r * sinphi * cos ( theta );

    p[1+i*3] = pc[1] + r * sinphi * sin ( theta );

    p[2+i*3] = pc[2] + r * cosphi;

  }

  return p;

}

double *sphere_unit_sample ( int n, int *seed )

{

  int j;

  double phi;

  double pi = 3.141592653589793;

  double theta;

  double vdot;

  double *x;

  x = new double[3*n];

  for ( j = 0; j < n; j++ )

  {

    vdot = 2.0 * r8_uniform_01 ( seed ) - 1.0;

    phi = arc_cosine ( vdot );

    theta = 2.0 * pi * r8_uniform_01 ( seed );

    x[0+j*3] = cos ( theta ) * sin ( phi );

    x[1+j*3] = sin ( theta ) * sin ( phi );

    x[2+j*3] = cos ( phi );

  }

  return x;

}

void timestamp ( )

{

# define TIME_NUM 40

  static char time_buffer[TIME_NUM];

  const struct std::tm *tm_ptr;

  size_t len;

  std::time_t now;

  now = std::time ( NULL );

  tm_ptr = std::localtime ( &now );

  len = std::strftime ( time_buffer, TIME_NUM, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;

# undef TIME_NUM

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/