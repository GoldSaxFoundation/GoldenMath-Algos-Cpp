
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <fstream>

# include <iomanip>

# include <cmath>

# include <ctime>

using namespace std;

# include "tet_mesh.hpp"

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

void i4_swap ( int *i, int *j )

{

  int k;

  k = *i;

  *i = *j;

  *j = k;

 

  return;

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

        temp         = a[i-1+col*m];

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

void i4i4i4_sort_a ( int i1, int i2, int i3, int *j1, int *j2, int *j3 )

{

  int k1;

  int k2;

  int k3;

  k1 = i1;

  k2 = i2;

  k3 = i3;

  *j1 = i4_min ( i4_min ( k1, k2 ), i4_min ( k2, k3 ) );

  *j2 = i4_min ( i4_max ( k1, k2 ), 

        i4_min ( i4_max ( k2, k3 ), i4_max ( k3, k1 ) ) );

  *j3 = i4_max ( i4_max ( k1, k2 ), i4_max ( k2, k3 ) );

  return;

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

void i4vec_print ( int n, int a[], string title )

{

  int i;

  if ( 0 < s_len_trim ( title ) )

  {

    cout << "\n";

    cout << title << "\n";

  }

  cout << "\n";

  for ( i = 0; i < n; i++ ) 

  {

    cout << "  " << setw(8) << i 

         << "  " << setw(8) << a[i]  << "\n";

  }

  return;

}

int i4vec_sum ( int n, int a[] )

{

  int i;

  int sum;

  sum = 0;

  for ( i = 0; i < n; i++ )

  {

    sum = sum + a[i];

  }

  return sum;

}

void i4vec_zero ( int n, int a[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    a[i] = 0;

  }

  return;

}

void mesh_base_zero ( int node_num, int element_order, int element_num, 

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

    cout << "MESH_BASE_ZERO:\n";

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

    cout << "MESH_BASE_ZERO:\n";

    cout << "  The element indexing appears to be 0-based!\n";

    cout << "  No conversion is necessary.\n";

  }

  else

  {

    cout << "\n";

    cout << "MESH_BASE_ZERO - Warning!\n";

    cout << "  The element indexing is not of a recognized type.\n";

    cout << "  NODE_MIN = " << node_min << "\n";

    cout << "  NODE_MAX = " << node_max << "\n";

    cout << "  NODE_NUM = " << node_num << "\n";

  }

  return;

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

double r8_huge ( )

{

  return HUGE_VAL;

}

double r8_max ( double x, double y )

{

  double value;

  if ( y < x )

  {

    value = x;

  } 

  else

  {

    value = y;

  }

  return value;

}

double r8_min ( double x, double y )

{

  double value;

  if ( y < x )

  {

    value = y;

  } 

  else

  {

    value = x;

  }

  return value;

}

void r8_swap ( double *x, double *y )

{

  double z;

  z = *x;

  *x = *y;

  *y = z;

 

  return;

}

double r8_uniform_01 ( int *seed )

{

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

    *seed = *seed + 2147483647;

  }

  r = ( double ) ( *seed ) * 4.656612875E-10;

  return r;

}

double r8mat_det_4d ( double a[4*4] )

{

  double det;

  det =

      a[0+0*4] * (

          a[1+1*4] * ( a[2+2*4] * a[3+3*4] - a[2+3*4] * a[3+2*4] )

        - a[1+2*4] * ( a[2+1*4] * a[3+3*4] - a[2+3*4] * a[3+1*4] )

        + a[1+3*4] * ( a[2+1*4] * a[3+2*4] - a[2+2*4] * a[3+1*4] ) )

    - a[0+1*4] * (

          a[1+0*4] * ( a[2+2*4] * a[3+3*4] - a[2+3*4] * a[3+2*4] )

        - a[1+2*4] * ( a[2+0*4] * a[3+3*4] - a[2+3*4] * a[3+0*4] )

        + a[1+3*4] * ( a[2+0*4] * a[3+2*4] - a[2+2*4] * a[3+0*4] ) )

    + a[0+2*4] * (

          a[1+0*4] * ( a[2+1*4] * a[3+3*4] - a[2+3*4] * a[3+1*4] )

        - a[1+1*4] * ( a[2+0*4] * a[3+3*4] - a[2+3*4] * a[3+0*4] )

        + a[1+3*4] * ( a[2+0*4] * a[3+1*4] - a[2+1*4] * a[3+0*4] ) )

    - a[0+3*4] * (

          a[1+0*4] * ( a[2+1*4] * a[3+2*4] - a[2+2*4] * a[3+1*4] )

        - a[1+1*4] * ( a[2+0*4] * a[3+2*4] - a[2+2*4] * a[3+0*4] )

        + a[1+2*4] * ( a[2+0*4] * a[3+1*4] - a[2+1*4] * a[3+0*4] ) );

  return det;

}

double *r8mat_mv ( int m, int n, double a[], double x[] )

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

  if ( 0 < s_len_trim ( title ) )

  {

    cout << "\n";

    cout << title << "\n";

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

      cout << setw(7) << j << "       ";

    }

    cout << "\n";

    cout << "  Row\n";

    cout << "\n";

    i2lo = i4_max ( ilo, 1 );

    i2hi = i4_min ( ihi, m );

    for ( i = i2lo; i <= i2hi; i++ )

    {

      cout << setw(5) << i;

      for ( j = j2lo; j <= j2hi; j++ )

      {

        cout << "  " << setprecision(6) << setw(12) << a[i-1+(j-1)*m];

      }

      cout << "\n";

    }

  }

  return;

# undef INCX

}

int r8mat_solve ( int n, int rhs_num, double a[] )

{

  double apivot;

  double factor;

  int i;

  int ipivot;

  int j;

  int k;

  double temp;

  for ( j = 0; j < n; j++ )

  {

    ipivot = j;

    apivot = a[j+j*n];

    for ( i = j; i < n; i++ )

    {

      if ( fabs ( apivot ) < fabs ( a[i+j*n] ) )

      {

        apivot = a[i+j*n];

        ipivot = i;

      }

    }

    if ( apivot == 0.0 )

    {

      return j;

    }

    for ( i = 0; i < n + rhs_num; i++ )

    {

      temp          = a[ipivot+i*n];

      a[ipivot+i*n] = a[j+i*n];

      a[j+i*n]      = temp;

    }

    a[j+j*n] = 1.0;

    for ( k = j; k < n + rhs_num; k++ )

    {

      a[j+k*n] = a[j+k*n] / apivot;

    }

    for ( i = 0; i < n; i++ )

    {

      if ( i != j )

      {

        factor = a[i+j*n];

        a[i+j*n] = 0.0;

        for ( k = j; k < n + rhs_num; k++ )

        {

          a[i+k*n] = a[i+k*n] - factor * a[j+k*n];

        }

      }

    }

  }

  return 0;

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

        cout << setprecision ( 6 ) << setw(14) << a[(i-1)+(j-1)*m];

      }

      cout << "\n";

    }

  }

  return;

# undef INCX

}

double *r8mat_uniform_01 ( int m, int n, int *seed )

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

      k = *seed / 127773;

      *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

      if ( *seed < 0 )

      {

        *seed = *seed + 2147483647;

      }

      r[i+j*m] = ( double ) ( *seed ) * 4.656612875E-10;

    }

  }

  return r;

}

double *r8vec_cross_3d ( double v1[3], double v2[3] )

{

  double *v3;

  v3 = new double[3];

  v3[0] = v1[1] * v2[2] - v1[2] * v2[1];

  v3[1] = v1[2] * v2[0] - v1[0] * v2[2];

  v3[2] = v1[0] * v2[1] - v1[1] * v2[0];

  return v3;

}

bool r8vec_is_nonnegative ( int n, double x[] )

{

  int i;

  for ( i = 0; i < n; i++ ) 

  {

    if ( x[i] < 0.0 ) 

    {

      return false;

    }

  }

  return true;

}

bool r8vec_is_zero ( int n, double x[] )

{

  int i;

  for ( i = 0; i < n; i++ ) 

  {

    if ( x[i] != 0.0 ) 

    {

      return false;

    }

  }

  return true;

}

double r8vec_length ( int dim_num, double x[] )

{

  int i;

  double value;

  value = 0.0;

  for ( i = 0; i < dim_num; i++ )

  {

    value = value + pow ( x[i], 2 );

  }

  value = sqrt ( value );

  return value;

}

double r8vec_max ( int n, double dvec[] )

{

  int i;

  double *r8vec_pointer;

  double value;

  value = - r8_huge ( );

  if ( n <= 0 ) 

  {

    return value;

  }

  for ( i = 0; i < n; i++ ) 

  {

    if ( value < dvec[i] )

    {

      value = dvec[i];

    }

  }

  return value;

}

double r8vec_mean ( int n, double x[] )

{

  int i;

  double mean;

  mean = 0.0;

  for ( i = 0; i < n; i++ ) 

  {

    mean = mean + x[i];

  }

  mean = mean / ( double ) n;

  return mean;

}

double r8vec_min ( int n, double dvec[] )

{

  int i;

  double *r8vec_pointer;

  double value;

  value = r8_huge ( );

  if ( n <= 0 ) 

  {

    return value;

  }

  for ( i = 0; i < n; i++ ) 

  {

    if ( dvec[i] < value )

    {

      value = dvec[i];

    }

  }

  return value;

}

void r8vec_print ( int n, double a[], string title )

{

  int i;

  if ( 0 < s_len_trim ( title ) )

  {

    cout << "\n";

    cout << title << "\n";

  }

  cout << "\n";

  for ( i = 0; i < n; i++ ) 

  {

    cout << "  " << setw(8)  << i

         << "  " << setw(14) << a[i]  << "\n";

  }

  return;

}

double r8vec_sum ( int n, double a[] )

{

  int i;

  double value;

  value = 0.0;

  for ( i = 0; i < n; i++ )

  {

    value = value + a[i];

  }

  return value;

}

double *r8vec_uniform_01 ( int n, int *seed )

{

  int i;

  int k;

  double *r;

  r = new double[n];

  for ( i = 0; i < n; i++ )

  {

    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )

    {

      *seed = *seed + 2147483647;

    }

    r[i] = ( double ) ( *seed ) * 4.656612875E-10;

  }

  return r;

}

double r8vec_variance ( int n, double x[] )

{

  int i;

  double mean;

  double variance;

  mean = r8vec_mean ( n, x );

  variance = 0.0;

  for ( i = 0; i < n; i++ ) 

  {

    variance = variance + ( x[i] - mean ) * ( x[i] - mean );

  }

  if ( 1 < n ) 

  {

    variance = variance / ( double ) ( n - 1 );

  }

  else

  {

    variance = 0.0;

  }

  return variance;

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

int *tet_mesh_neighbor_tets ( int tetra_order, int tetra_num, 

  int tetra_node[] )

{

  int a;

  int b;

  int c;

  int face;

  int face1;

  int face2;

  int *faces;

  int i;

  int j;

  int k;

  int l;

  int tetra;

  int *tetra_neighbor;

  int tetra1;

  int tetra2;

  faces = new int[5*(4*tetra_num)];

  tetra_neighbor = new int[4*tetra_num];

  for ( tetra = 0; tetra < tetra_num; tetra++ )

  {

    i = tetra_node[0+tetra*tetra_order];

    j = tetra_node[1+tetra*tetra_order];

    k = tetra_node[2+tetra*tetra_order];

    l = tetra_node[3+tetra*tetra_order];

    i4i4i4_sort_a ( j, k, l, &a, &b, &c );

    faces[0+0*5+tetra*5*4] = a;

    faces[1+0*5+tetra*5*4] = b;

    faces[2+0*5+tetra*5*4] = c;

    faces[3+0*5+tetra*5*4] = 0;

    faces[4+0*5+tetra*5*4] = tetra;

    i4i4i4_sort_a ( i, k, l, &a, &b, &c );

    faces[0+1*5+tetra*5*4] = a;

    faces[1+1*5+tetra*5*4] = b;

    faces[2+1*5+tetra*5*4] = c;

    faces[3+1*5+tetra*5*4] = 1;

    faces[4+1*5+tetra*5*4] = tetra;

    i4i4i4_sort_a ( i, j, l, &a, &b, &c );

    faces[0+2*5+tetra*5*4] = a;

    faces[1+2*5+tetra*5*4] = b;

    faces[2+2*5+tetra*5*4] = c;

    faces[3+2*5+tetra*5*4] = 2;

    faces[4+2*5+tetra*5*4] = tetra;

    i4i4i4_sort_a ( i, j, k, &a, &b, &c );

    faces[0+3*5+tetra*5*4] = a;

    faces[1+3*5+tetra*5*4] = b;

    faces[2+3*5+tetra*5*4] = c;

    faces[3+3*5+tetra*5*4] = 3;

    faces[4+3*5+tetra*5*4] = tetra;

  }

  i4col_sort_a ( 5, 4*tetra_num, faces );

  for ( j = 0; j < tetra_num; j++ )

  {

    for ( i = 0; i < 4; i++ )

    {

      tetra_neighbor[i+j*4] = -1;

    }

  }

  face = 0;

  for ( ; ; )

  {

    if ( 4 * tetra_num - 1 <= face )

    {

      break;

    }

    if ( faces[0+face*5] == faces[0+(face+1)*5] &&

         faces[1+face*5] == faces[1+(face+1)*5] &&

         faces[2+face*5] == faces[2+(face+1)*5] )

    {

      face1 = faces[3+face*5];

      tetra1 = faces[4+face*5];

      face2 = faces[3+(face+1)*5];

      tetra2 = faces[4+(face+1)*5];

      tetra_neighbor[face1+tetra1*4] = tetra2;

      tetra_neighbor[face2+tetra2*4] = tetra1;

      face = face + 2;

    }

    else

    {

      face = face + 1;

    }

  }

  delete [] faces;

  return tetra_neighbor;

}

int *tet_mesh_node_order ( int tetra_order, int tetra_num, int tetra_node[], 

  int node_num )

{

  int i;

  int node;

  int *node_order;

  int tetra;

  node_order = new int[node_num];

  i4vec_zero ( node_num, node_order );

  for ( tetra = 0; tetra < tetra_num; tetra++ )

  {

    for ( i = 0; i < tetra_order; i++ )

    {

      node = tetra_node[i+tetra*tetra_order];

      if ( node < 0 || node_num <= node )

      {

        cout << "\n";

        cout << "TET_MESH_NODE_ORDER - Fatal error!\n";

        cout << "  Illegal entry in TETRA_NODE.\n";

        exit ( 1 );

      }

      else

      {

        node_order[node] = node_order[node] + 1;

      }

    }

  }

  return node_order;

}

void tet_mesh_order4_adj_count ( int node_num, int tetra_num, 

  int tetra_node[], int *adj_num, int adj_row[] )

{

  int i;

  int j;

  int k;

  int node;

  int *pair;

  int pair_num;

  int pair_unique_num;

  int tetra;

  pair = new int[2*6*tetra_num];

  for ( tetra = 0; tetra < tetra_num; tetra++ )

  {

    pair[0+             tetra *2] = tetra_node[0+tetra*4];

    pair[1+             tetra *2] = tetra_node[1+tetra*4];

    pair[0+(  tetra_num+tetra)*2] = tetra_node[0+tetra*4];

    pair[1+(  tetra_num+tetra)*2] = tetra_node[2+tetra*4];

    pair[0+(2*tetra_num+tetra)*2] = tetra_node[0+tetra*4];

    pair[1+(2*tetra_num+tetra)*2] = tetra_node[3+tetra*4];

    pair[0+(3*tetra_num+tetra)*2] = tetra_node[1+tetra*4];

    pair[1+(3*tetra_num+tetra)*2] = tetra_node[2+tetra*4];

    pair[0+(4*tetra_num+tetra)*2] = tetra_node[1+tetra*4];

    pair[1+(4*tetra_num+tetra)*2] = tetra_node[3+tetra*4];

    pair[0+(5*tetra_num+tetra)*2] = tetra_node[2+tetra*4];

    pair[1+(5*tetra_num+tetra)*2] = tetra_node[3+tetra*4];

  }

  pair_num = 6 * tetra_num;

  i4mat_transpose_print_some ( 2, pair_num, pair, 1, 1, 2, pair_num,

    "DEBUG: PAIR before first sort" );

  i4col_sort2_a ( 2, pair_num, pair );

  i4mat_transpose_print_some ( 2, pair_num, pair, 1, 1, 2, pair_num,

    "DEBUG: PAIR after first sort" );

  i4col_sort_a ( 2, pair_num, pair );

  pair_unique_num = i4col_sorted_unique_count ( 2, pair_num, pair );

  *adj_num = 2 * pair_unique_num;

  for ( node = 0; node < node_num; node++ )

  {

    adj_row[node] = 0;

  }

  for ( k = 0; k < pair_num; k++ )

  {

    if ( 0 < k )

    {

      if ( pair[0+(k-1)*2] == pair[0+k*2] &&

           pair[1+(k-1)*2] == pair[1+k*2] )

      {

        continue;

      }

    }

    i = pair[0+k*2];

    j = pair[1+k*2];

    adj_row[i-1] = adj_row[i-1] + 1;

    adj_row[j-1] = adj_row[j-1] + 1;

  }

  for ( node = node_num-1; 0 <= node; node-- )

  {

    adj_row[node] = adj_row[node+1];

  }

  adj_row[0] = 1;

  for ( node = 1; node <= node_num; node++ )

  {

    adj_row[node] = adj_row[node-1] + adj_row[i];

  }

  delete [] pair;

  return;

}

int *tet_mesh_order4_adj_set ( int node_num, int element_num, 

  int element_node[], int adj_num, int adj_row[] )

{

  int *adj;

  int *adj_row_copy;

  int i;

  int j;

  int k;

  int node;

  int *pair;

  int pair_num;

  int tetra;

  pair = new int[2*6*element_num];

  for ( tetra = 0; tetra < element_num; tetra++ )

  {

    pair[0+             tetra *2] = element_node[0+tetra*4];

    pair[1+             tetra *2] = element_node[1+tetra*4];

    pair[0+(  element_num+tetra)*2] = element_node[0+tetra*4];

    pair[1+(  element_num+tetra)*2] = element_node[2+tetra*4];

    pair[0+(2*element_num+tetra)*2] = element_node[0+tetra*4];

    pair[1+(2*element_num+tetra)*2] = element_node[3+tetra*4];

    pair[0+(3*element_num+tetra)*2] = element_node[1+tetra*4];

    pair[1+(3*element_num+tetra)*2] = element_node[2+tetra*4];

    pair[0+(4*element_num+tetra)*2] = element_node[1+tetra*4];

    pair[1+(4*element_num+tetra)*2] = element_node[3+tetra*4];

    pair[0+(5*element_num+tetra)*2] = element_node[2+tetra*4];

    pair[1+(5*element_num+tetra)*2] = element_node[3+tetra*4];

  }

  pair_num = 6 * element_num;

  i4col_sort2_a ( 2, pair_num, pair );

  i4col_sort_a ( 2, pair_num, pair );

  adj = new int[adj_num];

  for ( i = 0; i < adj_num; i++ )

  {

    adj[i] = -1;

  }

  adj_row_copy = new int[node_num];

  for ( node = 0; node < node_num; node++ )

  {

    adj_row_copy[node] = adj_row[node];

  }

  for ( k = 0; k < pair_num; k++ )

  {

    if ( 0 < k )

    {

      if ( pair[0+(k-1)*2] == pair[0+k*2] &&

           pair[1+(k-1)*2] == pair[1+k*2] )

      {

        continue;

      }

    }

    i = pair[0+k*2];

    j = pair[1+k*2];

    adj[adj_row_copy[i]] = j;

    adj_row_copy[i] = adj_row_copy[i] + 1;

    adj[adj_row_copy[j]] = i;

    adj_row_copy[j] = adj_row_copy[j] + 1;

  }

  delete [] adj_row_copy;

  delete [] pair;

  return adj;

}

int tet_mesh_order4_boundary_face_count ( int tetra_num, int tetra_node[] )

{

  int boundary_face_num;

  int *face;

  int face_num;

  int interior_face_num;

  int m;

  int tet;

  int unique_face_num;

  face = new int[3*4*tetra_num];

  m = 3;

  face_num = 4 * tetra_num;

  for ( tet = 0; tet < tetra_num; tet++ )

  {

    face[0+(            tet)*3] = tetra_node[1+tet*4];

    face[1+(            tet)*3] = tetra_node[2+tet*4];

    face[2+(            tet)*3] = tetra_node[3+tet*4];

    face[0+(  tetra_num+tet)*3] = tetra_node[0+tet*4];

    face[1+(  tetra_num+tet)*3] = tetra_node[2+tet*4];

    face[2+(  tetra_num+tet)*3] = tetra_node[3+tet*4];

    face[0+(2*tetra_num+tet)*3] = tetra_node[0+tet*4];

    face[1+(2*tetra_num+tet)*3] = tetra_node[1+tet*4];

    face[2+(2*tetra_num+tet)*3] = tetra_node[3+tet*4];

    

    face[0+(3*tetra_num+tet)*3] = tetra_node[0+tet*4];

    face[1+(3*tetra_num+tet)*3] = tetra_node[1+tet*4];

    face[2+(3*tetra_num+tet)*3] = tetra_node[2+tet*4];

  }

  i4col_sort2_a ( m, face_num, face );

  i4col_sort_a ( m, face_num, face );

  unique_face_num = i4col_sorted_unique_count ( m, face_num, face );

  interior_face_num = 4 * tetra_num - unique_face_num;

  boundary_face_num = 4 * tetra_num - 2 * interior_face_num;

  delete [] face;

  return boundary_face_num;

}

int tet_mesh_order4_edge_count ( int tetra_num, int tetra_node[] )

{

  int *edge;

  int edge_num;

  int edge_num_raw;

  int m;

  int tet;

  edge = new int[2*6*tetra_num];

  m = 3;

  edge_num_raw = 6 * tetra_num;

  for ( tet = 0; tet < tetra_num; tet++ )

  {

    edge[0+             tet *2] = tetra_node[0+tet*4];

    edge[1+             tet *2] = tetra_node[1+tet*4];

    edge[0+(  tetra_num+tet)*2] = tetra_node[0+tet*4];

    edge[1+(  tetra_num+tet)*2] = tetra_node[2+tet*4];

    edge[0+(2*tetra_num+tet)*2] = tetra_node[0+tet*4];

    edge[1+(2*tetra_num+tet)*2] = tetra_node[3+tet*4];

    edge[0+(3*tetra_num+tet)*2] = tetra_node[1+tet*4];

    edge[1+(3*tetra_num+tet)*2] = tetra_node[2+tet*4];

    edge[0+(4*tetra_num+tet)*2] = tetra_node[1+tet*4];

    edge[1+(4*tetra_num+tet)*2] = tetra_node[3+tet*4];

    edge[0+(5*tetra_num+tet)*2] = tetra_node[2+tet*4];

    edge[1+(5*tetra_num+tet)*2] = tetra_node[3+tet*4];

  }

  i4col_sort2_a ( m, edge_num_raw, edge );

  i4col_sort_a ( m, edge_num_raw, edge );

  edge_num = i4col_sorted_unique_count ( m, edge_num_raw, edge );

  delete [] edge;

  return edge_num;

}

void tet_mesh_order4_example_set ( int node_num, int tetra_num, 

  double node_xyz[], int tetra_node[] )

{

  int i;

  int j;

  double node_xyz_save[3*63] = {

  0.0,  0.0,  0.0, 

  0.0,  0.0,  0.5, 

  0.0,  0.0,  1.0, 

  0.0,  0.5,  0.0, 

  0.0,  0.5,  0.5, 

  0.0,  0.5,  1.0, 

  0.0,  1.0,  0.0, 

  0.0,  1.0,  0.5, 

  0.0,  1.0,  1.0, 

  0.5,  0.0,  0.0, 

  0.5,  0.0,  0.5, 

  0.5,  0.0,  1.0, 

  0.5,  0.5,  0.0, 

  0.5,  0.5,  0.5, 

  0.5,  0.5,  1.0, 

  0.5,  1.0,  0.0, 

  0.5,  1.0,  0.5, 

  0.5,  1.0,  1.0, 

  1.0,  0.0,  0.0, 

  1.0,  0.0,  0.5, 

  1.0,  0.0,  1.0, 

  1.0,  0.5,  0.0, 

  1.0,  0.5,  0.5, 

  1.0,  0.5,  1.0, 

  1.0,  1.0,  0.0, 

  1.0,  1.0,  0.5, 

  1.0,  1.0,  1.0, 

  1.5,  0.0,  0.0, 

  1.5,  0.0,  0.5, 

  1.5,  0.0,  1.0, 

  1.5,  0.5,  0.0, 

  1.5,  0.5,  0.5, 

  1.5,  0.5,  1.0, 

  1.5,  1.0,  0.0, 

  1.5,  1.0,  0.5, 

  1.5,  1.0,  1.0, 

  2.0,  0.0,  0.0, 

  2.0,  0.0,  0.5, 

  2.0,  0.0,  1.0, 

  2.0,  0.5,  0.0, 

  2.0,  0.5,  0.5, 

  2.0,  0.5,  1.0, 

  2.0,  1.0,  0.0, 

  2.0,  1.0,  0.5, 

  2.0,  1.0,  1.0, 

  2.5,  0.0,  0.0, 

  2.5,  0.0,  0.5, 

  2.5,  0.0,  1.0, 

  2.5,  0.5,  0.0, 

  2.5,  0.5,  0.5, 

  2.5,  0.5,  1.0, 

  2.5,  1.0,  0.0, 

  2.5,  1.0,  0.5, 

  2.5,  1.0,  1.0, 

  3.0,  0.0,  0.0, 

  3.0,  0.0,  0.5, 

  3.0,  0.0,  1.0, 

  3.0,  0.5,  0.0, 

  3.0,  0.5,  0.5, 

  3.0,  0.5,  1.0, 

  3.0,  1.0,  0.0, 

  3.0,  1.0,  0.5, 

  3.0,  1.0,  1.0 };

  int tetra_node_save[4*144] = {

     1,   2,   4,  10, 

     2,   4,   5,  10, 

     2,   5,  10,  11, 

     2,   3,   5,  11, 

     4,   5,  10,  13, 

     3,   5,   6,  11, 

     5,  10,  11,  13, 

     4,   5,   7,  13, 

     5,   6,   8,  14, 

     5,   7,   8,  13, 

     6,   8,   9,  14, 

    11,  13,  14,  19, 

    12,  14,  15,  20, 

     3,   6,  11,  12, 

     5,   6,  11,  14, 

     6,   9,  14,  15, 

     6,  11,  12,  14, 

     6,  12,  14,  15, 

     7,   8,  13,  16, 

     5,   8,  13,  14, 

    10,  11,  13,  19, 

     8,   9,  14,  17, 

    11,  12,  14,  20, 

     5,  11,  13,  14, 

     8,  13,  14,  16, 

     9,  14,  15,  17, 

    13,  14,  16,  22, 

     8,  14,  16,  17, 

    14,  15,  17,  23, 

    14,  16,  17,  22, 

     9,  15,  17,  18, 

    15,  17,  18,  23, 

    14,  17,  22,  23, 

    13,  14,  19,  22, 

    11,  14,  19,  20, 

    14,  15,  20,  23, 

    15,  20,  21,  23, 

    21,  23,  24,  29, 

    20,  22,  23,  28, 

    14,  19,  20,  22, 

    15,  18,  23,  24, 

    12,  15,  20,  21, 

    15,  21,  23,  24, 

    16,  17,  22,  25, 

    19,  20,  22,  28, 

    17,  18,  23,  26, 

    20,  21,  23,  29, 

    14,  20,  22,  23, 

    17,  22,  23,  25, 

    18,  23,  24,  26, 

    22,  23,  25,  31, 

    17,  23,  25,  26, 

    23,  24,  26,  32, 

    23,  25,  26,  31, 

    18,  24,  26,  27, 

    24,  26,  27,  32, 

    23,  26,  31,  32, 

    22,  23,  28,  31, 

    20,  23,  28,  29, 

    23,  24,  29,  32, 

    24,  29,  30,  32, 

    30,  32,  33,  38, 

    29,  31,  32,  37, 

    23,  28,  29,  31, 

    24,  27,  32,  33, 

    21,  24,  29,  30, 

    24,  30,  32,  33, 

    25,  26,  31,  34, 

    28,  29,  31,  37, 

    26,  27,  32,  35, 

    29,  30,  32,  38, 

    23,  29,  31,  32, 

    26,  31,  32,  34, 

    27,  32,  33,  35, 

    31,  32,  34,  40, 

    26,  32,  34,  35, 

    32,  33,  35,  41, 

    32,  34,  35,  40, 

    27,  33,  35,  36, 

    33,  35,  36,  41, 

    32,  35,  40,  41, 

    31,  32,  37,  40, 

    29,  32,  37,  38, 

    32,  33,  38,  41, 

    33,  38,  39,  41, 

    39,  41,  42,  47, 

    38,  40,  41,  46, 

    32,  37,  38,  40, 

    33,  36,  41,  42, 

    30,  33,  38,  39, 

    33,  39,  41,  42, 

    34,  35,  40,  43, 

    37,  38,  40,  46, 

    35,  36,  41,  44, 

    38,  39,  41,  47, 

    32,  38,  40,  41, 

    35,  40,  41,  43, 

    36,  41,  42,  44, 

    40,  41,  43,  49, 

    35,  41,  43,  44, 

    41,  42,  44,  50, 

    41,  43,  44,  49, 

    36,  42,  44,  45, 

    42,  44,  45,  50, 

    41,  44,  49,  50, 

    40,  41,  46,  49, 

    38,  41,  46,  47, 

    41,  42,  47,  50, 

    42,  47,  48,  50, 

    48,  50,  51,  56, 

    47,  49,  50,  55, 

    41,  46,  47,  49, 

    42,  45,  50,  51, 

    39,  42,  47,  48, 

    42,  48,  50,  51, 

    43,  44,  49,  52, 

    46,  47,  49,  55, 

    44,  45,  50,  53, 

    47,  48,  50,  56, 

    41,  47,  49,  50, 

    44,  49,  50,  52, 

    45,  50,  51,  53, 

    49,  50,  52,  58, 

    44,  50,  52,  53, 

    50,  51,  53,  59, 

    50,  52,  53,  58, 

    45,  51,  53,  54, 

    51,  53,  54,  59, 

    50,  53,  58,  59, 

    49,  50,  55,  58, 

    47,  50,  55,  56, 

    50,  51,  56,  59, 

    51,  56,  57,  59, 

    50,  55,  56,  58, 

    51,  54,  59,  60, 

    48,  51,  56,  57, 

    51,  57,  59,  60, 

    52,  53,  58,  61, 

    53,  54,  59,  62, 

    50,  56,  58,  59, 

    53,  58,  59,  61, 

    54,  59,  60,  62, 

    53,  59,  61,  62, 

    54,  60,  62,  63 };

  for ( j = 0; j < node_num; j++ )

  {

    for ( i = 0; i < 3; i++ )

    {

      node_xyz[i+j*3] = node_xyz_save[i+j*3];

    }

  }

  for ( j = 0; j < tetra_num; j++ )

  {

    for ( i = 0; i < 4; i++ )

    {

      tetra_node[i+j*4] = tetra_node_save[i+j*4] - 1;

    }

  }

  return;

}

void tet_mesh_order4_example_size ( int *node_num, int *tetra_num )

{

  *node_num = 63;

  *tetra_num = 144;

  return;

}

void tet_mesh_order4_refine_compute ( int node_num1, int tetra_num1, 

  double node_xyz1[], int tetra_node1[], int node_num2, int tetra_num2,

   int edge_data[], double node_xyz2[], int tetra_node2[] )

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

  int tetra_order = 4;

  int tetra1;

  int tetra2;

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

  for ( j = 0; j < tetra_num2; j++ )

  {

    for ( i = 0; i < tetra_order; i++ )

    {

      tetra_node2[i+j*tetra_order] = -1;

    }

  }

  for ( tetra1 = 0; tetra1 < tetra_num1; tetra1++ )

  {

    tetra_node2[0+(tetra1*8+0)*tetra_order] = tetra_node1[0+tetra1*tetra_order];

    tetra_node2[0+(tetra1*8+1)*tetra_order] = tetra_node1[1+tetra1*tetra_order];

    tetra_node2[0+(tetra1*8+2)*tetra_order] = tetra_node1[2+tetra1*tetra_order];

    tetra_node2[0+(tetra1*8+3)*tetra_order] = tetra_node1[3+tetra1*tetra_order];

  }

  node = node_num1;

  n1_old = -1;

  n2_old = -1;

  for ( edge = 0; edge < 6 * tetra_num1; edge++ )

  {

    n1 = edge_data[0+edge*5];

    n2 = edge_data[1+edge*5];

    if ( n1 != n1_old || n2 != n2_old )

    {

      if ( node_num2 <= node )

      {

        cout << "\n";

        cout << "TET_MESH_ORDER4_REFINE_COMPUTE - Fatal error!\n";

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

    tetra1 = edge_data[4+edge*5];

    if ( v1 == 1 && v2 == 2 )

    {

      tetra_node2[1+(tetra1*8+0)*tetra_order] = node;

      tetra_node2[1+(tetra1*8+1)*tetra_order] = node;

      tetra_node2[0+(tetra1*8+4)*tetra_order] = node;

      tetra_node2[0+(tetra1*8+5)*tetra_order] = node;

    }

    else if ( v1 == 1 && v2 == 3 )

    {

      tetra_node2[2+(tetra1*8+0)*tetra_order] = node;

      tetra_node2[1+(tetra1*8+2)*tetra_order] = node;

      tetra_node2[1+(tetra1*8+4)*tetra_order] = node;

      tetra_node2[1+(tetra1*8+5)*tetra_order] = node;

      tetra_node2[0+(tetra1*8+6)*tetra_order] = node;

      tetra_node2[0+(tetra1*8+7)*tetra_order] = node;

    }

    else if ( v1 == 1 && v2 == 4 )

    {

      tetra_node2[3+(tetra1*8+0)*tetra_order] = node;

      tetra_node2[1+(tetra1*8+3)*tetra_order] = node;

      tetra_node2[2+(tetra1*8+4)*tetra_order] = node;

      tetra_node2[1+(tetra1*8+6)*tetra_order] = node;

    }

    else if ( v1 == 2 && v2 == 3 )

    {

      tetra_node2[2+(tetra1*8+1)*tetra_order] = node;

      tetra_node2[2+(tetra1*8+2)*tetra_order] = node;

      tetra_node2[2+(tetra1*8+5)*tetra_order] = node;

      tetra_node2[1+(tetra1*8+7)*tetra_order] = node;

    }

    else if ( v1 == 2 && v2 == 4 )

    {

      tetra_node2[3+(tetra1*8+1)*tetra_order] = node;

      tetra_node2[3+(tetra1*8+2)*tetra_order] = node;

      tetra_node2[2+(tetra1*8+3)*tetra_order] = node;

      tetra_node2[3+(tetra1*8+4)*tetra_order] = node;

      tetra_node2[3+(tetra1*8+5)*tetra_order] = node;

      tetra_node2[2+(tetra1*8+6)*tetra_order] = node;

      tetra_node2[2+(tetra1*8+7)*tetra_order] = node;

    }

    else if ( v1 == 3 && v2 == 4 )

    {

      tetra_node2[3+(tetra1*8+3)*tetra_order] = node;

      tetra_node2[3+(tetra1*8+6)*tetra_order] = node;

      tetra_node2[3+(tetra1*8+7)*tetra_order] = node;

    }

  }

  return;

}

void tet_mesh_order4_refine_size ( int node_num1, int tetra_num1, 

  int tetra_node1[], int *node_num2, int *tetra_num2, int edge_data[] )

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

  int tetra_order = 4;

  for ( tetra = 0; tetra < tetra_num1; tetra++ )

  {

    i = tetra_node1[0+tetra*tetra_order];

    j = tetra_node1[1+tetra*tetra_order];

    k = tetra_node1[2+tetra*tetra_order];

    l = tetra_node1[3+tetra*tetra_order];

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

  i4col_sort_a ( 5, 6*tetra_num1, edge_data );

  *node_num2 = node_num1;

  n1_old = -1;

  n2_old = -1;

  for ( edge = 0; edge < 6 * tetra_num1; edge++ )

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

  *tetra_num2 = 8 * tetra_num1;

  return;

}

void tet_mesh_order4_to_order10_compute ( int tetra_num, int tetra_node1[], 

  int node_num1, double node_xyz1[], int edge_data[], int tetra_node2[], 

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

  int tetra_order1 = 4;

  int tetra_order2 = 10;

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

  for ( j = 0; j < tetra_num; j++ )

  {

    for ( i = 0; i < tetra_order1; i++ )

    {

      tetra_node2[i+j*tetra_order2] = tetra_node1[i+j*tetra_order1];

    }

  }

  node = node_num1;

  n1_old = -1;

  n2_old = -1;

  for ( edge = 0; edge < 6 * tetra_num; edge++ )

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

    tetra_node2[v-1+tetra*tetra_order2] = node;

  }

  return;

}

void tet_mesh_order4_to_order10_size ( int tetra_num, int tetra_node1[], 

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

  int tetra_order1 = 4;

  for ( tetra = 0; tetra < tetra_num; tetra++ )

  {

    i = tetra_node1[0+tetra*tetra_order1];

    j = tetra_node1[1+tetra*tetra_order1];

    k = tetra_node1[2+tetra*tetra_order1];

    l = tetra_node1[3+tetra*tetra_order1];

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

  i4col_sort_a ( 5, 6*tetra_num, edge_data );

  *node_num2 = node_num1;

  n1_old = -1;

  n2_old = -1;

  for ( edge = 0; edge < 6 * tetra_num; edge++ )

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

void tet_mesh_order10_adj_count ( int node_num, int tet_num, 

  int tet_node[], int *adj_num, int adj_row[] )

{

  int i;

  int j;

  int k;

  int l;

  int node;

  int *pair;

  int pair_num;

  int pair_unique_num;

  pair = new int[2*45*tet_num];

  k = 0;

  for ( i = 0; i < 9; i++ )

  {

    for ( j = i + 1; j < 10; j++ )

    {

      for ( l = 0; l < tet_num; l++ )

      {

        pair[0+(k*tet_num+l)*2] = tet_node[i+l*10];

        pair[1+(k*tet_num+l)*2] = tet_node[j+l*10];

      }

      k = k + 1;

    }

  }

  pair_num = 45 * tet_num;

  i4col_sort2_a ( 2, pair_num, pair );

  i4col_sort_a ( 2, pair_num, pair );

  pair_unique_num = i4col_sorted_unique_count ( 2, pair_num, pair );

  *adj_num = 2 * pair_unique_num;

  for ( node = 0; node < node_num; node++ )

  {

    adj_row[node] = 0;

  }

  for ( k = 0; k < pair_num; k++ )

  {

    if ( 0 < k )

    {

      if ( pair[0+(k-1)*2] == pair[0+k*2] &&

           pair[1+(k-1)*2] == pair[1+k*2] )

      {

        continue;

      }

    }

    i = pair[0+k*2];

    j = pair[1+k*2];

    adj_row[i-1] = adj_row[i-1] + 1;

    adj_row[j-1] = adj_row[j-1] + 1;

  }

  for ( node = node_num-1; 0 <= node; node-- )

  {

    adj_row[node] = adj_row[node+1];

  }

  adj_row[0] = 1;

  for ( node = 1; node <= node_num; node++ )

  {

    adj_row[node] = adj_row[node-1] + adj_row[i];

  }

  delete [] pair;

  return;

}

int *tet_mesh_order10_adj_set ( int node_num, int tet_num, 

  int tet_node[], int adj_num, int adj_row[] )

{

  int *adj;

  int *adj_row_copy;

  int i;

  int j;

  int k;

  int l;

  int node;

  int *pair;

  int pair_num;

  pair = new int[2*45*tet_num];

  k = 0;

  for ( i = 0; i < 9; i++ )

  {

    for ( j = i + 1; j < 10; j++ )

    {

      for ( l = 0; l < tet_num; l++ )

      {

        pair[0+(k*tet_num+l)*2] = tet_node[i+l*10];

        pair[1+(k*tet_num+l)*2] = tet_node[j+l*10];

      }

      k = k + 1;

    }

  }

  pair_num = 45 * tet_num;

  i4col_sort2_a ( 2, pair_num, pair );

  i4col_sort_a ( 2, pair_num, pair );

  adj = new int[adj_num];

  for ( i = 0; i < adj_num; i++ )

  {

    adj[i] = -1;

  }

  adj_row_copy = new int[node_num];

  for ( node = 0; node < node_num; node++ )

  {

    adj_row_copy[node] = adj_row[node];

  }

  for ( k = 0; k < pair_num; k++ )

  {

    if ( 0 < k )

    {

      if ( pair[0+(k-1)*2] == pair[0+k*2] &&

           pair[1+(k-1)*2] == pair[1+k*2] )

      {

        continue;

      }

    }

    i = pair[0+k*2];

    j = pair[1+k*2];

    adj[adj_row_copy[i]] = j;

    adj_row_copy[i] = adj_row_copy[i] + 1;

    adj[adj_row_copy[j]] = i;

    adj_row_copy[j] = adj_row_copy[j] + 1;

  }

  delete [] adj_row_copy;

  delete [] pair;

  return adj;

}

void tet_mesh_order10_example_set ( int node_num, int tetra_num, 

  double node_xyz[], int tetra_node[] )

{

  int i;

  int j;

  double node_xyz_save[3*27] = {

   0.0,  0.0,  0.0, 

   0.0,  0.0,  1.0, 

   0.0,  1.0,  0.0, 

   0.0,  1.0,  1.0, 

   1.0,  0.0,  0.0, 

   1.0,  0.0,  1.0, 

   1.0,  1.0,  0.0, 

   1.0,  1.0,  1.0, 

   0.0,  0.0,  0.5, 

   0.0,  0.5,  0.0, 

   0.0,  0.5,  0.5, 

   0.5,  0.0,  0.0, 

   0.0,  0.5,  1.0, 

   0.5,  0.0,  0.5, 

   0.5,  0.0,  1.0, 

   0.0,  1.0,  0.5, 

   0.5,  0.5,  0.0, 

   0.5,  1.0,  0.0, 

   0.5,  0.5,  0.5, 

   0.5,  0.5,  1.0, 

   0.5,  1.0,  0.5, 

   0.5,  1.0,  1.0, 

   1.0,  0.0,  0.5, 

   1.0,  0.5,  0.0, 

   1.0,  0.5,  0.5, 

   1.0,  0.5,  1.0, 

   1.0,  1.0,  0.5  };

  int tetra_node_save[10*6] = {

    4,   3,   5,   1,  16,  19,  17,  11,  10,  12, 

    4,   2,   5,   1,  13,  19,  14,  11,   9,  12, 

    4,   7,   3,   5,  21,  16,  18,  19,  24,  17, 

    4,   7,   8,   5,  21,  22,  27,  19,  24,  25, 

    4,   6,   2,   5,  20,  13,  15,  19,  23,  14, 

    4,   6,   8,   5,  20,  22,  26,  19,  23,  25 };

  for ( j = 0; j < node_num; j++ )

  {

    for ( i = 0; i < 3; i++ )

    {

      node_xyz[i+j*3] = node_xyz_save[i+j*3];

    }

  }

  for ( j = 0; j < tetra_num; j++ )

  {

    for ( i = 0; i < 10; i++ )

    {

      tetra_node[i+j*10] = tetra_node_save[i+j*10] - 1;

    }

  }

  return;

}

void tet_mesh_order10_example_size ( int *node_num, int *tetra_num )

{

  *node_num = 27;

  *tetra_num = 6;

  return;

}

void tet_mesh_order10_to_order4_compute ( int tetra_num1, int tetra_node1[], 

  int tetra_num2, int tetra_node2[] )

{

  int n1;

  int n2;

  int n3;

  int n4;

  int n5;

  int n6;

  int n7;

  int n8;

  int n9;

  int nx;

  int tetra1;

  int tetra2;

  tetra2 = 0;

  for ( tetra1 = 0; tetra1 < tetra_num1; tetra1++ )

  {

    n1 = tetra_node1[0+tetra1*10];

    n2 = tetra_node1[1+tetra1*10];

    n3 = tetra_node1[2+tetra1*10];

    n4 = tetra_node1[3+tetra1*10];

    n5 = tetra_node1[4+tetra1*10];

    n6 = tetra_node1[5+tetra1*10];

    n7 = tetra_node1[6+tetra1*10];

    n8 = tetra_node1[7+tetra1*10];

    n9 = tetra_node1[8+tetra1*10];

    nx = tetra_node1[9+tetra1*10];

    tetra_node2[0+tetra2*4] = n1;

    tetra_node2[1+tetra2*4] = n5;

    tetra_node2[2+tetra2*4] = n6;

    tetra_node2[3+tetra2*4] = n7;

    tetra2 = tetra2 + 1;

    tetra_node2[0+tetra2*4] = n2;

    tetra_node2[1+tetra2*4] = n5;

    tetra_node2[2+tetra2*4] = n8;

    tetra_node2[3+tetra2*4] = n9;

    tetra2 = tetra2 + 1;

    tetra_node2[0+tetra2*4] = n3;

    tetra_node2[1+tetra2*4] = n6;

    tetra_node2[2+tetra2*4] = n8;

    tetra_node2[3+tetra2*4] = n9;

    tetra2 = tetra2 + 1;

    tetra_node2[0+tetra2*4] = n4;

    tetra_node2[1+tetra2*4] = n7;

    tetra_node2[2+tetra2*4] = n9;

    tetra_node2[3+tetra2*4] = nx;

    tetra2 = tetra2 + 1;

    tetra_node2[0+tetra2*4] = n5;

    tetra_node2[1+tetra2*4] = n6;

    tetra_node2[2+tetra2*4] = n7;

    tetra_node2[3+tetra2*4] = n9;

    tetra2 = tetra2 + 1;

    tetra_node2[0+tetra2*4] = n5;

    tetra_node2[1+tetra2*4] = n6;

    tetra_node2[2+tetra2*4] = n8;

    tetra_node2[3+tetra2*4] = n9;

    tetra2 = tetra2 + 1;

    tetra_node2[0+tetra2*4] = n6;

    tetra_node2[1+tetra2*4] = n7;

    tetra_node2[2+tetra2*4] = n9;

    tetra_node2[3+tetra2*4] = nx;

    tetra2 = tetra2 + 1;

    tetra_node2[0+tetra2*4] = n6;

    tetra_node2[1+tetra2*4] = n8;

    tetra_node2[2+tetra2*4] = n9;

    tetra_node2[3+tetra2*4] = nx;

    tetra2 = tetra2 + 1;

  }

  return;

}

void tet_mesh_order10_to_order4_size ( int node_num1, int tetra_num1,

  int *node_num2, int *tetra_num2 )

{

  *node_num2 = node_num1;

  *tetra_num2 = 8 * tetra_num1;

  return;

}

void tet_mesh_quad ( int node_num, double node_xyz[], int tetra_order, 

  int tetra_num, int tetra_node[], 

  void quad_fun ( int n, double xyz_vec[], double fvec[] ), 

  int quad_num, double quad_xyz[], double quad_w[], double *quad_value, 

  double *region_volume )

{

  int i;

  int j;

  int quad;

  double quad_f[quad_num];

  double quad2_xyz[3*quad_num];

  double temp;

  int tet;

  double tetra_volume;

  double tetra_xyz[3*4];

  *quad_value = 0.0;

  *region_volume = 0.0;

  for ( tet = 0; tet < tetra_num; tet++ )

  {

    for ( j = 0; j < 4; j++ )

    {

      for ( i = 0; i < 3; i++ )

      {

        tetra_xyz[i+j*3] = node_xyz[i+(tetra_node[j+tet*4]-1)*3];

      }

    }

    tetra_volume = tetrahedron_volume ( tetra_xyz );

    tetrahedron_order4_reference_to_physical ( tetra_xyz, quad_num, 

      quad_xyz, quad2_xyz );

    quad_fun ( quad_num, quad2_xyz, quad_f );

    temp = 0.0;

    for ( quad = 0; quad < quad_num; quad++ )

    {

      temp = temp + quad_w[quad] * quad_f[quad];

    }

    *quad_value = *quad_value + tetra_volume * temp;

    *region_volume = *region_volume + tetra_volume;

  }

  return;

}

void tet_mesh_quality1 ( int node_num, double node_xyz[], 

  int tetra_order, int tetra_num, int tetra_node[], double *value_min, 

  double *value_mean, double *value_max, double *value_var )

{

# define DIM_NUM 3

  int i;

  int j;

  int node;

  int tetra;

  double tetrahedron[DIM_NUM*4];

  double *tetrahedron_quality;

  tetrahedron_quality = new double[tetra_num];

  for ( tetra = 0; tetra < tetra_num; tetra++ )

  {

    for ( j = 0; j < 4; j++ )

    {

      node = tetra_node[j+tetra*tetra_order];

      for ( i = 0; i < DIM_NUM; i++ )

      {

        tetrahedron[i+j*DIM_NUM] = node_xyz[i+(node-1)*DIM_NUM];

      }

    }

    tetrahedron_quality[tetra] = tetrahedron_quality1_3d ( tetrahedron );

  }

  *value_max = r8vec_max ( tetra_num, tetrahedron_quality );

  *value_min = r8vec_min ( tetra_num, tetrahedron_quality );

  *value_mean = r8vec_mean ( tetra_num, tetrahedron_quality );

  *value_var = r8vec_variance ( tetra_num, tetrahedron_quality );

  delete [] tetrahedron_quality;

  return;

# undef DIM_NUM

}

void tet_mesh_quality2 ( int node_num, double node_xyz[], int tetra_order, 

  int tetra_num, int tetra_node[], double *value_min, double *value_mean, 

  double *value_max, double *value_var )

{

# define DIM_NUM 3

  int i;

  int j;

  int node;

  int tetra;

  double tetrahedron[DIM_NUM*4];

  double *tetrahedron_quality;

  tetrahedron_quality = new double[tetra_num];

  for ( tetra = 0; tetra < tetra_num; tetra++ )

  {

    for ( j = 0; j < 4; j++ )

    {

      node = tetra_node[j+tetra*tetra_order];

      for ( i = 0; i < DIM_NUM; i++ )

      {

        tetrahedron[i+j*DIM_NUM] = node_xyz[i+(node-1)*DIM_NUM];

      }

    }

    tetrahedron_quality[tetra] = tetrahedron_quality2_3d ( tetrahedron );

  }

  *value_max = r8vec_max ( tetra_num, tetrahedron_quality );

  *value_min = r8vec_min ( tetra_num, tetrahedron_quality );

  *value_mean = r8vec_mean ( tetra_num, tetrahedron_quality );

  *value_var = r8vec_variance ( tetra_num, tetrahedron_quality );

  delete [] tetrahedron_quality;

  return;

# undef DIM_NUM

}

void tet_mesh_quality3 ( int node_num, double node_xyz[], int tetra_order, 

  int tetra_num, int tetra_node[], double *value_min, double *value_mean, 

  double *value_max, double *value_var )

{

# define DIM_NUM 3

  int i;

  int j;

  int node;

  int tetra;

  double tetrahedron[DIM_NUM*4];

  double *tetrahedron_quality;

  tetrahedron_quality = new double[tetra_num];

  for ( tetra = 0; tetra < tetra_num; tetra++ )

  {

    for ( j = 0; j < 4; j++ )

    {

      node = tetra_node[j+tetra*tetra_order];

      for ( i = 0; i < DIM_NUM; i++ )

      {

        tetrahedron[i+j*DIM_NUM] = node_xyz[i+(node-1)*DIM_NUM];

      }

    }

    tetrahedron_quality[tetra] = tetrahedron_quality3_3d ( tetrahedron );

  }

  *value_max = r8vec_max ( tetra_num, tetrahedron_quality );

  *value_min = r8vec_min ( tetra_num, tetrahedron_quality );

  *value_mean = r8vec_mean ( tetra_num, tetrahedron_quality );

  *value_var = r8vec_variance ( tetra_num, tetrahedron_quality );

  delete [] tetrahedron_quality;

  return;

# undef DIM_NUM

}

void tet_mesh_quality4 ( int node_num, double node_xyz[], int tetra_order, 

  int tetra_num, int tetra_node[], double *value_min, double *value_mean, 

  double *value_max, double *value_var )

{

# define DIM_NUM 3

  int i;

  int j;

  int node;

  int tetra;

  double tetrahedron[DIM_NUM*4];

  double *tetrahedron_quality;

  tetrahedron_quality = new double[tetra_num];

  for ( tetra = 0; tetra < tetra_num; tetra++ )

  {

    for ( j = 0; j < 4; j++ )

    {

      node = tetra_node[j+tetra*tetra_order];

      for ( i = 0; i < DIM_NUM; i++ )

      {

        tetrahedron[i+j*DIM_NUM] = node_xyz[i+(node-1)*DIM_NUM];

      }

    }

    tetrahedron_quality[tetra] = tetrahedron_quality4_3d ( tetrahedron );

  }

  *value_max = r8vec_max ( tetra_num, tetrahedron_quality );

  *value_min = r8vec_min ( tetra_num, tetrahedron_quality );

  *value_mean = r8vec_mean ( tetra_num, tetrahedron_quality );

  *value_var = r8vec_variance ( tetra_num, tetrahedron_quality );

  delete [] tetrahedron_quality;

  return;

# undef DIM_NUM

}

void tet_mesh_quality5 ( int node_num, double node_xyz[], int tetra_order, 

  int tetra_num, int tetra_node[], double *value_min, double *value_mean, 

  double *value_max, double *value_var )

{

# define DIM_NUM 3

  int i;

  int j;

  int node;

  double quality;

  int tetra;

  double tetrahedron[DIM_NUM*4];

  double *tetrahedron_quality;

  double volume_max;

  tetrahedron_quality = new double[tetra_num];

  for ( tetra = 0; tetra < tetra_num; tetra++ )

  {

    for ( j = 0; j < 4; j++ )

    {

      node = tetra_node[j+tetra*tetra_order];

      for ( i = 0; i < DIM_NUM; i++ )

      {

        tetrahedron[i+j*DIM_NUM] = node_xyz[i+(node-1)*DIM_NUM];

      }

    }

    tetrahedron_quality[tetra] = tetrahedron_volume ( tetrahedron );

  }

  volume_max = r8vec_max ( tetra_num, tetrahedron_quality );

  for ( tetra = 0; tetra < tetra_num; tetra++ )

  {

    tetrahedron_quality[tetra] = tetrahedron_quality[tetra] / volume_max;

  }

  *value_max = r8vec_max ( tetra_num, tetrahedron_quality );

  *value_min = r8vec_min ( tetra_num, tetrahedron_quality );

  *value_mean = r8vec_mean ( tetra_num, tetrahedron_quality );

  *value_var = r8vec_variance ( tetra_num, tetrahedron_quality );

  delete [] tetrahedron_quality;

  return;

# undef DIM_NUM

}

int tet_mesh_search_delaunay ( int node_num, double node_xyz[], int tet_order, 

  int tet_num, int tet_node[], int tet_neighbor[], double p[], int *face, 

  int *step_num )

{

  double *alpha;

  int i;

  int j;

  int k;

  int tet_index;

  double tet_xyz[3*4];

  static int tet_index_save = -1;

  if ( tet_index_save < 1 || tet_num < tet_index_save )

  {

    tet_index = ( tet_num + 1 ) / 2;

  }

  else

  {

    tet_index = tet_index_save;

  }

  *step_num = -1;

  *face = 0;

  for ( ; ; )

  {

    *step_num = *step_num + 1;

    if ( tet_num < *step_num )

    {

      cerr << "\n";

      cerr << "TET_MESH_SEARCH_DELAUNAY - Fatal error!\n";

      cerr << "  The algorithm seems to be cycling.\n";

      tet_index = -1;

      *face = -1;

      exit ( 1 );

    }

    for ( j = 0; j < 4; j++ )

    {

      k = tet_node[j+tet_index*4];

      for ( i = 0; i < 3; i++ )

      {

        tet_xyz[i+j*3] = node_xyz[i+k*3];

      }

    }

    alpha = tetrahedron_barycentric ( tet_xyz, p );

    if ( 0.0 <= alpha[0] && 0.0 <= alpha[1] && 0.0 <= alpha[2] && 0.0 <= alpha[3] )

    {

      break;

    }

    if ( alpha[0] < 0.0 && 0 < tet_neighbor[0+tet_index*4] )

    {

      tet_index = tet_neighbor[0+tet_index*4];

      continue;

    }

    else if ( alpha[1] < 0.0 && 0 < tet_neighbor[1+tet_index*4] )

    {

      tet_index = tet_neighbor[1+tet_index*4];

      continue;

    }

    else if ( alpha[2] < 0.0 && 0 < tet_neighbor[2+tet_index*4] )

    {

      tet_index = tet_neighbor[2+tet_index*4];

      continue;

    }

    else if ( alpha[3] < 0.0 && 0 < tet_neighbor[3+tet_index*4] )

    {

      tet_index = tet_neighbor[3+tet_index*4];

      continue;

    }

    if ( alpha[0] < 0.0 )

    {

      *face = -1;

      break;

    }

    else if ( alpha[1] < 0.0 )

    {

      *face = -2;

      break;

    }

    else if ( alpha[2] < 0.0 )

    {

      *face = -3;

      break;

    }

    else if ( alpha[3] < 0.0 )

    {

      *face = -4;

      break;

    }

  }

  tet_index_save = tet_index;

  return tet_index;

}

int tet_mesh_search_naive ( int node_num, double node_xyz[],

  int tet_order, int tet_num, int tet_node[], double p[], int *step_num )

{

  double *alpha;

  int i;

  int j;

  int tet;

  int tet_index;

  double tet_xyz[3*4];

  tet_index = -1;

  *step_num = 0;

  for ( tet = 0; tet < tet_num; tet++ )

  {

    for ( j = 0; j < 4; j++ )

    {

      for ( i = 0; i < 3; i++ )

      {

        tet_xyz[i+j*3] = node_xyz[i+tet_node[j+tet*4]*3];

      }

    }

    alpha = tetrahedron_barycentric ( tet_xyz, p );

    if ( r8vec_is_nonnegative ( 4, alpha ) )

    {

      tet_index = tet;

      *step_num = tet;

      return tet_index;

    }

    delete [] alpha;

  }

  return tet_index;

}

double *tetrahedron_barycentric ( double tetra[3*4], double p[3] )

{

# define N 3

# define RHS_NUM 1

  double a[N*(N+RHS_NUM)];

  double *c;

  int info;

  a[0+0*N] = tetra[0+1*3] - tetra[0+0*3];

  a[1+0*N] = tetra[1+1*3] - tetra[1+0*3];

  a[2+0*N] = tetra[2+1*3] - tetra[2+0*3];

  a[0+1*N] = tetra[0+2*3] - tetra[0+0*3];

  a[1+1*N] = tetra[1+2*3] - tetra[1+0*3];

  a[2+1*N] = tetra[2+2*3] - tetra[2+0*3];

  a[0+2*N] = tetra[0+3*3] - tetra[0+0*3];

  a[1+2*N] = tetra[1+3*3] - tetra[1+0*3];

  a[2+2*N] = tetra[2+3*3] - tetra[2+0*3];

  a[0+3*N] = p[0]         - tetra[0+0*3];

  a[1+3*N] = p[1]         - tetra[1+0*3];

  a[2+3*N] = p[2]         - tetra[2+0*3];

  info = r8mat_solve ( N, RHS_NUM, a );

  if ( info != 0 )

  {

    cout << "\n";

    cout << "TETRAHEDRON_BARYCENTRIC - Fatal error!\n";

    cout << "  The linear system is singular.\n";

    cout << "  The input data does not form a proper tetrahedron.\n";

    exit ( 1 );

  }

  c = new double[4];

  c[1] = a[0+3*N];

  c[2] = a[1+3*N];

  c[3] = a[2+3*N];

  c[0] = 1.0 - c[1] - c[2] - c[3];

  return c;

# undef N

# undef RHS_NUM

}

void tetrahedron_circumsphere_3d ( double tetra[3*4], double *r, double pc[3] )

{

# define DIM_NUM 3

# define RHS_NUM 1

  double a[DIM_NUM*(DIM_NUM+RHS_NUM)];

  int info;

  a[0+0*3] = tetra[0+1*3] - tetra[0+0*3];

  a[0+1*3] = tetra[1+1*3] - tetra[1+0*3];

  a[0+2*3] = tetra[2+1*3] - tetra[2+0*3];

  a[0+3*3] = pow ( tetra[0+1*3] - tetra[0+0*3], 2 ) 

           + pow ( tetra[1+1*3] - tetra[1+0*3], 2 ) 

           + pow ( tetra[2+1*3] - tetra[2+0*3], 2 );

  a[1+0*3] = tetra[0+2*3] - tetra[0+0*3];

  a[1+1*3] = tetra[1+2*3] - tetra[1+0*3];

  a[1+2*3] = tetra[2+2*3] - tetra[2+0*3];

  a[1+3*3] = pow ( tetra[0+2*3] - tetra[0+0*3], 2 ) 

           + pow ( tetra[1+2*3] - tetra[1+0*3], 2 ) 

           + pow ( tetra[2+2*3] - tetra[2+0*3], 2 );

  a[2+0*3] = tetra[0+3*3] - tetra[0+0*3];

  a[2+1*3] = tetra[1+3*3] - tetra[1+0*3];

  a[2+2*3] = tetra[2+3*3] - tetra[2+0*3];

  a[2+3*3] = pow ( tetra[0+3*3] - tetra[0+0*3], 2 ) 

           + pow ( tetra[1+3*3] - tetra[1+0*3], 2 ) 

           + pow ( tetra[2+3*3] - tetra[2+0*3], 2 );

  info = r8mat_solve ( DIM_NUM, RHS_NUM, a );

  if ( info != 0 )

  {

    *r = -1.0;

    r8vec_zero ( DIM_NUM, pc );

    return;

  }

  *r = 0.5 * sqrt 

    ( a[0+3*3] * a[0+3*3] 

    + a[1+3*3] * a[1+3*3] 

    + a[2+3*3] * a[2+3*3] );

  pc[0] = tetra[0+0*3] + 0.5 * a[0+3*3];

  pc[1] = tetra[1+0*3] + 0.5 * a[1+3*3];

  pc[2] = tetra[2+0*3] + 0.5 * a[2+3*3];

  return;

# undef DIM_NUM

# undef RHS_NUM

}

double *tetrahedron_edge_length_3d ( double tetra[3*4] )

{

# define DIM_NUM 3

  double *edge_length;

  int i;

  int j1;

  int j2;

  int k;

  double v[DIM_NUM];

  edge_length = new double[6];

  k = 0;

  for ( j1 = 0; j1 < 3; j1++ )

  {

    for ( j2 = j1 + 1; j2 < 4; j2++ )

    {

      for ( i = 0; i < DIM_NUM; i++ )

      {

        v[i] = tetra[i+j2*DIM_NUM] - tetra[i+j1*DIM_NUM];

      }

      edge_length[k] = r8vec_length ( DIM_NUM, v );

      k = k + 1;

    }

  }

  return edge_length;

# undef DIM_NUM

}

void tetrahedron_insphere_3d ( double tetra[3*4], double *r, double pc[3] )

{

# define DIM_NUM 3

  double b[4*4];

  double gamma;

  int i;

  int j;

  double l123;

  double l124;

  double l134;

  double l234;

  double *n123;

  double *n124;

  double *n134;

  double *n234;

  double v21[DIM_NUM];

  double v31[DIM_NUM];

  double v41[DIM_NUM];

  double v32[DIM_NUM];

  double v42[DIM_NUM];

  double v43[DIM_NUM];

  for ( i = 0; i < DIM_NUM; i++ )

  {

    v21[i] = tetra[i+1*DIM_NUM] - tetra[i+0*DIM_NUM];

  }

  for ( i = 0; i < DIM_NUM; i++ )

  {

    v31[i] = tetra[i+2*DIM_NUM] - tetra[i+0*DIM_NUM];

  }

  for ( i = 0; i < DIM_NUM; i++ )

  {

    v41[i] = tetra[i+3*DIM_NUM] - tetra[i+0*DIM_NUM];

  }

  for ( i = 0; i < DIM_NUM; i++ )

  {

    v32[i] = tetra[i+2*DIM_NUM] - tetra[i+1*DIM_NUM];

  }

  for ( i = 0; i < DIM_NUM; i++ )

  {

    v42[i] = tetra[i+3*DIM_NUM] - tetra[i+1*DIM_NUM];

  }

  for ( i = 0; i < DIM_NUM; i++ )

  {

    v43[i] = tetra[i+3*DIM_NUM] - tetra[i+2*DIM_NUM];

  }

  n123 = r8vec_cross_3d ( v21, v31 );

  n124 = r8vec_cross_3d ( v41, v21 );

  n134 = r8vec_cross_3d ( v31, v41 );

  n234 = r8vec_cross_3d ( v42, v32 );

  l123 = r8vec_length ( DIM_NUM, n123 );

  l124 = r8vec_length ( DIM_NUM, n124 );

  l134 = r8vec_length ( DIM_NUM, n134 );

  l234 = r8vec_length ( DIM_NUM, n234 );

  delete [] n123;

  delete [] n124;

  delete [] n134;

  delete [] n234;

  for ( i = 0; i < DIM_NUM; i++ )

  {

    pc[i] = ( l234 * tetra[i+0*DIM_NUM]

            + l134 * tetra[i+1*DIM_NUM]

            + l124 * tetra[i+2*DIM_NUM]

            + l123 * tetra[i+3*DIM_NUM] )

            / ( l234 + l134 + l124 + l123 );

  }

  for ( j = 0; j < 4; j++ )

  {

    for ( i = 0; i < DIM_NUM; i++ )

    {

      b[i+j*4] = tetra[i+j*DIM_NUM];

    }

    b[3+j*4] = 1.0;

  }

  

  gamma = fabs ( r8mat_det_4d ( b ) );

  *r = gamma / ( l234 + l134 + l124 + l123 );

  return;

# undef DIM_NUM

}

void tetrahedron_order4_physical_to_reference ( double tetra[], int n, 

  double phy[], double ref[] )

{

  double a[3*3];

  double det;

  int i;

  int j;

  for ( i = 0; i < 3; i++ )

  {

    a[i+0*3] = tetra[i+1*3] - tetra[i+0*3];

    a[i+1*3] = tetra[i+2*3] - tetra[i+0*3];

    a[i+2*3] = tetra[i+3*3] - tetra[i+0*3];

  }

  det =  a[0+0*3] * ( a[1+1*3] * a[2+2*3] - a[1+2*3] * a[2+1*3] ) 

       + a[0+1*3] * ( a[1+2*3] * a[2+0*3] - a[1+0*3] * a[2+2*3] ) 

       + a[0+2*3] * ( a[1+0*3] * a[2+1*3] - a[1+1*3] * a[2+0*3] );

  if ( det == 0.0 )

  {

    for ( j = 0; j < n; j++ )

    {

      for ( i = 0; i < 3; i++ )

      {

        ref[i+j*3] = 0.0;

      }

    }

    return;

  }

  for ( j = 0; j < n; j++ )

  {

    ref[0+j*3] = (   ( a[1+1*3] * a[2+2*3] - a[1+2*3] * a[2+1*3] ) 

                     * ( phy[0+j*3] - tetra[0+0*3] ) 

                   - ( a[0+1*3] * a[2+2*3] - a[0+2*3] * a[2+1*3] ) 

                     * ( phy[1+j*3] - tetra[1+0*3] ) 

                   + ( a[0+1*3] * a[1+2*3] - a[0+2*3] * a[1+1*3] ) 

                     * ( phy[2+j*3] - tetra[2+0*3] ) 

                 ) / det;

    ref[1+j*3] = ( - ( a[1+0*3] * a[2+2*3] - a[1+2*3] * a[2+0*3] ) 

                     * ( phy[0+j*3] - tetra[0+0*3] ) 

                   + ( a[0+0*3] * a[2+2*3] - a[0+2*3] * a[2+0*3] ) 

                     * ( phy[1+j*3] - tetra[1+0*3] ) 

                   - ( a[0+0*3] * a[1+2*3] - a[0+2*3] * a[1+0*3] ) 

                     * ( phy[2+j*3] - tetra[2+0*3] ) 

                 ) / det;

    ref[2+j*3] = (   ( a[1+0*3] * a[2+1*3] - a[1+1*3] * a[2+0*3] ) 

                     * ( phy[0+j*3] - tetra[0+0*3] ) 

                   - ( a[0+0*3] * a[2+1*3] - a[0+1*3] * a[2+0*3] ) 

                     * ( phy[1+j*3] - tetra[1+0*3] ) 

                   + ( a[0+0*3] * a[1+1*3] - a[0+1*3] * a[1+0*3] ) 

                     * ( phy[2+j*3] - tetra[2+0*3] ) 

                 ) / det;

  }

  return;

}

void tetrahedron_order4_reference_to_physical ( double tetra[], int n, 

  double ref[], double phy[] )

{

  int i;

  int j;

  for ( i = 0; i < 3; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      phy[i+j*3] = tetra[i+0*3] * ( 1.0 - ref[0+j*3] - ref[1+j*3] - ref[2+j*3] ) 

                 + tetra[i+1*3] *       + ref[0+j*3]                

                 + tetra[i+2*3] *                    + ref[1+j*3]

                 + tetra[i+3*3] *                                 + ref[2+j*3];

    }

  }

  return;

}

double tetrahedron_quality1_3d ( double tetra[3*4] )

{

# define DIM_NUM 3

  double pc[DIM_NUM];

  double quality;

  double r_in;

  double r_out;

  tetrahedron_circumsphere_3d ( tetra, &r_out, pc );

  tetrahedron_insphere_3d ( tetra, &r_in, pc );

  quality = 3.0 * r_in / r_out;

  return quality;

# undef DIM_NUM

}

double tetrahedron_quality2_3d ( double tetra[3*4] )

{

# define DIM_NUM 3

  double *edge_length;

  double l_max;

  double pc[DIM_NUM];

  double quality2;

  double r_in;

  edge_length = tetrahedron_edge_length_3d ( tetra );

  l_max = r8vec_max ( 6, edge_length );

  tetrahedron_insphere_3d ( tetra, &r_in, pc );

  quality2 = 2.0 * sqrt ( 6.0 ) * r_in / l_max;

  delete [] edge_length;

  return quality2;

# undef DIM_NUM

}

double tetrahedron_quality3_3d ( double tetra[3*4] )

{

# define DIM_NUM 3

  double ab[DIM_NUM];

  double ac[DIM_NUM];

  double ad[DIM_NUM];

  double bc[DIM_NUM];

  double bd[DIM_NUM];

  double cd[DIM_NUM];

  double denom;

  int i;

  double lab;

  double lac;

  double lad;

  double lbc;

  double lbd;

  double lcd;

  double quality3;

  double volume;

  for ( i = 0; i < DIM_NUM; i++ )

  {

    ab[i] = tetra[i+1*DIM_NUM] - tetra[i+0*DIM_NUM];

    ac[i] = tetra[i+2*DIM_NUM] - tetra[i+0*DIM_NUM];

    ad[i] = tetra[i+3*DIM_NUM] - tetra[i+0*DIM_NUM];

    bc[i] = tetra[i+2*DIM_NUM] - tetra[i+1*DIM_NUM];

    bd[i] = tetra[i+3*DIM_NUM] - tetra[i+1*DIM_NUM];

    cd[i] = tetra[i+3*DIM_NUM] - tetra[i+2*DIM_NUM];

  }

  lab = pow ( ab[0], 2 ) + pow ( ab[1], 2 ) + pow ( ab[2], 2 );

  lac = pow ( ac[0], 2 ) + pow ( ac[1], 2 ) + pow ( ac[2], 2 );

  lad = pow ( ad[0], 2 ) + pow ( ad[1], 2 ) + pow ( ad[2], 2 );

  lbc = pow ( bc[0], 2 ) + pow ( bc[1], 2 ) + pow ( bc[2], 2 );

  lbd = pow ( bd[0], 2 ) + pow ( bd[1], 2 ) + pow ( bd[2], 2 );

  lcd = pow ( cd[0], 2 ) + pow ( cd[1], 2 ) + pow ( cd[2], 2 );

  volume = fabs ( 

      ab[0] * ( ac[1] * ad[2] - ac[2] * ad[1] ) 

    + ab[1] * ( ac[2] * ad[0] - ac[0] * ad[2] ) 

    + ab[2] * ( ac[0] * ad[1] - ac[1] * ad[0] ) ) / 6.0;

  denom = lab + lac + lad + lbc + lbd + lcd;

  if ( denom == 0.0 )

  {

    quality3 = 0.0;

  }

  else

  {

    quality3 = 12.0 * pow ( 3.0 * volume, 2.0 / 3.0 ) / denom;

  }

  return quality3;

# undef DIM_NUM

}

double tetrahedron_quality4_3d ( double tetra[3*4] )

{

# define DIM_NUM 3

  double ab[DIM_NUM];

  double ac[DIM_NUM];

  double ad[DIM_NUM];

  double bc[DIM_NUM];

  double bd[DIM_NUM];

  double cd[DIM_NUM];

  double denom;

  int i;

  double l1;

  double l2;

  double l3;

  double lab;

  double lac;

  double lad;

  double lbc;

  double lbd;

  double lcd;

  double quality4;

  double volume;

  for ( i = 0; i < DIM_NUM; i++ )

  {

    ab[i] = tetra[i+1*DIM_NUM] - tetra[i+0*DIM_NUM];

    ac[i] = tetra[i+2*DIM_NUM] - tetra[i+0*DIM_NUM];

    ad[i] = tetra[i+3*DIM_NUM] - tetra[i+0*DIM_NUM];

    bc[i] = tetra[i+2*DIM_NUM] - tetra[i+1*DIM_NUM];

    bd[i] = tetra[i+3*DIM_NUM] - tetra[i+1*DIM_NUM];

    cd[i] = tetra[i+3*DIM_NUM] - tetra[i+2*DIM_NUM];

  }

  lab = r8vec_length ( DIM_NUM, ab );

  lac = r8vec_length ( DIM_NUM, ac );

  lad = r8vec_length ( DIM_NUM, ad );

  lbc = r8vec_length ( DIM_NUM, bc );

  lbd = r8vec_length ( DIM_NUM, bd );

  lcd = r8vec_length ( DIM_NUM, cd );

  volume = fabs ( 

      ab[0] * ( ac[1] * ad[2] - ac[2] * ad[1] ) 

    + ab[1] * ( ac[2] * ad[0] - ac[0] * ad[2] ) 

    + ab[2] * ( ac[0] * ad[1] - ac[1] * ad[0] ) ) / 6.0;

  quality4 = 1.0;

  l1 = lab + lac;

  l2 = lab + lad;

  l3 = lac + lad;

  denom = ( l1 + lbc ) * ( l1 - lbc ) 

        * ( l2 + lbd ) * ( l2 - lbd ) 

        * ( l3 + lcd ) * ( l3 - lcd );

  if ( denom <= 0.0 )

  {

    quality4 = 0.0;

  }

  else

  {

    quality4 = r8_min ( quality4, 12.0 * volume / sqrt ( denom ) );

  }

  l1 = lab + lbc;

  l2 = lab + lbd;

  l3 = lbc + lbd;

  denom = ( l1 + lac ) * ( l1 - lac ) 

        * ( l2 + lad ) * ( l2 - lad ) 

        * ( l3 + lcd ) * ( l3 - lcd );

  if ( denom <= 0.0 )

  {

    quality4 = 0.0;

  }

  else

  {

    quality4 = r8_min ( quality4, 12.0 * volume / sqrt ( denom ) );

  }

  l1 = lac + lbc;

  l2 = lac + lcd;

  l3 = lbc + lcd;

  denom = ( l1 + lab ) * ( l1 - lab ) 

        * ( l2 + lad ) * ( l2 - lad ) 

        * ( l3 + lbd ) * ( l3 - lbd );

  if ( denom <= 0.0 )

  {

    quality4 = 0.0;

  }

  else

  {

    quality4 = r8_min ( quality4, 12.0 * volume / sqrt ( denom ) );

  }

  l1 = lad + lbd;

  l2 = lad + lcd;

  l3 = lbd + lcd;

  denom = ( l1 + lab ) * ( l1 - lab ) 

        * ( l2 + lac ) * ( l2 - lac ) 

        * ( l3 + lbc ) * ( l3 - lbc );

  if ( denom <= 0.0 )

  {

    quality4 = 0.0;

  }

  else

  {

    quality4 = r8_min ( quality4, 12.0 * volume / sqrt ( denom ) );

  }

  quality4 = quality4 * 1.5 * sqrt ( 6.0 );

  return quality4;

# undef DIM_NUM

}

void tetrahedron_reference_sample ( int n, int *seed, double p[] )

{

  double alpha;

  double beta;

  double gamma;

  int j;

  double r;

  for ( j = 0; j < n; j++ )

  {

    r = r8_uniform_01 ( seed );

    alpha = pow ( r, 1.0 / 3.0 );

    r = r8_uniform_01 ( seed );

    beta = sqrt ( r );

    gamma = r8_uniform_01 ( seed );

    p[0+j*3] = alpha * ( 1.0 - beta ) *         gamma;

    p[1+j*3] = alpha *         beta   * ( 1.0 - gamma );

    p[2+j*3] = alpha *         beta   *         gamma;

  }

  return;

}

void tetrahedron_sample ( double tetra[3*4], int n, int *seed, double p[] )

{

# define DIM_NUM 3

  double alpha;

  double beta;

  double gamma;

  int i;

  int j;

  int k;

  double *p12;

  double *p13;

  double r;

  double *t;

  p12 = new double[DIM_NUM];

  p13 = new double[DIM_NUM];

  t = new double[DIM_NUM*3];

  for ( k = 0; k < n; k++ )

  {

    r = r8_uniform_01 ( seed );

    alpha = pow ( r, 1.0 / 3.0 );

    for ( i = 0; i < DIM_NUM; i++ )

    {

      for ( j = 0; j < 3; j++ )

      {

        t[i+j*3] = ( 1.0 - alpha ) * tetra[i+0*3] 

                 +         alpha   * tetra[i+(j+1)*3];

      }

    }

    r = r8_uniform_01 ( seed );

    beta = sqrt ( r );

    for ( i = 0; i < DIM_NUM; i++ )

    {

      p12[i] = ( 1.0 - beta ) * t[i+0*3] 

             +         beta   * t[i+1*3];

      p13[i] = ( 1.0 - beta ) * t[i+0*3] 

             +         beta   * t[i+2*3];

    }

    gamma = r8_uniform_01 ( seed );

    for ( i = 0; i < DIM_NUM; i++ )

    {

      p[i+k*3] = gamma * p12[i] + ( 1.0 - gamma ) * p13[i];

    }

  }

  delete [] p12;

  delete [] p13;

  delete [] t;

  return;

# undef DIM_NUM

}

double tetrahedron_volume ( double tetra[3*4] )

{

  double a[4*4];

  int i;

  int j;

  double volume;

  for ( i = 0; i < 3; i++ )

  {

    for ( j = 0; j < 4; j++ )

    { 

      a[i+j*4] = tetra[i+j*3];

    }

  }

  i = 3;

  for ( j = 0; j < 4; j++ )

  {

    a[i+j*4] = 1.0;

  }

  volume = fabs ( r8mat_det_4d ( a ) ) / 6.0;

  return volume;

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