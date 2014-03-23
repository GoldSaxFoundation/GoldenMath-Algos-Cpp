
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <cmath>

# include <ctime>

# include <iostream>

# include <iomanip>

# include <fstream>

# include <cstring>

using namespace std;

# include "quality.hpp"

double alpha_measure ( int n, double z[], int triangle_order, int triangle_num,

  int triangle_node[] )

{

  double a_angle;

  int a_index;

  double a_x;

  double a_y;

  double ab_len;

  double alpha;

  double b_angle;

  int b_index;

  double b_x;

  double b_y;

  double bc_len;

  double c_angle;

  int c_index;

  double c_x;

  double c_y;

  double ca_len;

  double pi = 3.141592653589793;

  int triangle;

  double value;

  alpha = r8_huge ( );

  for ( triangle = 0; triangle < triangle_num; triangle++ )

  {

    a_index = triangle_node[0+triangle*3];

    b_index = triangle_node[1+triangle*3];

    c_index = triangle_node[2+triangle*3];

    a_x = z[0+(a_index-1)*2];

    a_y = z[1+(a_index-1)*2];

    b_x = z[0+(b_index-1)*2];

    b_y = z[1+(b_index-1)*2];

    c_x = z[0+(c_index-1)*2];

    c_y = z[1+(c_index-1)*2];

    ab_len = sqrt ( pow ( a_x - b_x, 2 ) + pow ( a_y - b_y, 2 ) );

    bc_len = sqrt ( pow ( b_x - c_x, 2 ) + pow ( b_y - c_y, 2 ) );

    ca_len = sqrt ( pow ( c_x - a_x, 2 ) + pow ( c_y - a_y, 2 ) );

    if ( ab_len == 0.0 && bc_len == 0.0 && ca_len == 0.0 )

    {

      a_angle = 2.0 * pi / 3.0;

      b_angle = 2.0 * pi / 3.0;

      c_angle = 2.0 * pi / 3.0;

    }

    else

    {

      if ( ca_len == 0.0 || ab_len == 0.0 )

      {

        a_angle = pi;

      }

      else

      {

        a_angle = arc_cosine (

          ( ca_len * ca_len + ab_len * ab_len - bc_len * bc_len )

          / ( 2.0 * ca_len * ab_len ) );

      }

      if ( ab_len == 0.0 || bc_len == 0.0 )

      {

        b_angle = pi;

      }

      else

      {

        b_angle = arc_cosine (

          ( ab_len * ab_len + bc_len * bc_len - ca_len * ca_len )

          / ( 2.0 * ab_len * bc_len ) );

      }

      if ( bc_len == 0.0 || ca_len == 0.0 )

      {

        c_angle = pi;

      }

      else

      {

        c_angle = arc_cosine (

          ( bc_len * bc_len + ca_len * ca_len - ab_len * ab_len )

          / ( 2.0 * bc_len * ca_len ) );

      }

    }

    alpha = r8_min ( alpha, a_angle );

    alpha = r8_min ( alpha, b_angle );

    alpha = r8_min ( alpha, c_angle );

  }

  value = alpha * 3.0 / pi;

  return value;

}

double arc_cosine ( double c )

{

# define PI 3.141592653589793

  if ( c <= -1.0 )

  {

    return PI;

  }

  else if ( 1.0 <= c )

  {

    return 0.0;

  }

  else

  {

    return acos ( c );

  }

# undef PI

}

double area_measure ( int n, double z[], int triangle_order, int triangle_num,

  int triangle_node[] )

{

  double area;

  double area_max;

  double area_min;

  int triangle;

  double value;

  double x1;

  double x2;

  double x3;

  double y1;

  double y2;

  double y3;

  area_max = 0.0;

  area_min = r8_huge ( );

  for ( triangle = 0; triangle < triangle_num; triangle++ )

  {

    x1 = z[0+(triangle_node[0+triangle*3]-1)*2];

    y1 = z[1+(triangle_node[0+triangle*3]-1)*2];

    x2 = z[0+(triangle_node[1+triangle*3]-1)*2];

    y2 = z[1+(triangle_node[1+triangle*3]-1)*2];

    x3 = z[0+(triangle_node[2+triangle*3]-1)*2];

    y3 = z[1+(triangle_node[2+triangle*3]-1)*2];

    area = 0.5 * fabs ( x1 * ( y2 - y3 )

                      + x2 * ( y3 - y1 )

                      + x3 * ( y1 - y2 ) );

    area_min = r8_min ( area_min, area );

    area_max = r8_max ( area_max, area );

  }

  if ( 0.0 < area_max )

  {

    value = area_min / area_max;

  }

  else

  {

    value = 0.0;

  }

  return value;

}

void bandwidth_mesh ( int element_order, int element_num, int element_node[],

  int *ml, int *mu, int *m )

{

  int element;

  int global_i;

  int global_j;

  int local_i;

  int local_j;

  *ml = 0;

  *mu = 0;

  for ( element = 0; element < element_num; element++ )

  {

    for ( local_i = 0; local_i < element_order; local_i++ )

    {

      global_i = element_node[local_i+element*element_order];

      for ( local_j = 0; local_j < element_order; local_j++ )

      {

        global_j = element_node[local_j+element*element_order];

        *mu = i4_max ( *mu, global_j - global_i );

        *ml = i4_max ( *ml, global_i - global_j );

      }

    }

  }

  *m = *ml + 1 + *mu;

  return;

}

double beta_measure ( int dim_num, int n, double z[] )

{

  double *gamma;

  double gamma_ave;

  double gamma_std;

  int i;

  double value;

  gamma = pointset_spacing ( dim_num, n, z );

  gamma_ave = 0.0;

  for ( i = 0; i < n; i++ )

  {

    gamma_ave = gamma_ave + gamma[i];

  }

  gamma_ave = gamma_ave / ( double ) ( n );

  if ( 1 < n )

  {

    gamma_std = 0.0;

    for ( i = 0; i < n; i++ )

    {

      gamma_std = gamma_std + pow ( gamma[i] - gamma_ave, 2 );

    }

    gamma_std = sqrt ( gamma_std / ( double ) ( n - 1 ) );

  }

  else

  {

    gamma_std = 0.0;

  }

  if ( 0.0 < gamma_ave )

  {

    value = gamma_std / gamma_ave;

  }

  else

  {

    value = 0.0;

  }

  delete [] gamma;

  return value;

}

char ch_cap ( char c )

{

  if ( 97 <= c && c <= 122 )

  {

    c = c - 32;

  }

  return c;

}

bool ch_eqi ( char c1, char c2 )

{

  if ( 97 <= c1 && c1 <= 122 )

  {

    c1 = c1 - 32;

  }

  if ( 97 <= c2 && c2 <= 122 )

  {

    c2 = c2 - 32;

  }

  return ( c1 == c2 );

}

int ch_to_digit ( char c )

{

  int digit;

  if ( '0' <= c && c <= '9' )

  {

    digit = c - '0';

  }

  else if ( c == ' ' )

  {

    digit = 0;

  }

  else

  {

    digit = -1;

  }

  return digit;

}

double chi_measure ( int dim_num, int n, double z[], int ns,

  double *sample_routine ( int dim_num, int n, int *seed ),

  int seed_init )

{

  double chi;

  double *chi_vec;

  int closest[1];

  double dist;

  double *gamma;

  double *h;

  int i;

  int j;

  int k;

  int seed;

  double *x;

  seed = seed_init;

  chi_vec = new double[n];

  h = new double[n];

  for ( j = 0; j < n; j++ )

  {

    h[j] = 0.0;

  }

  for ( k = 1; k <= ns; k++ )

  {

    x = sample_routine ( dim_num, 1, &seed );

    find_closest ( dim_num, n, 1, x, z, closest );

    dist = 0.0;

    for ( i = 0; i < dim_num; i++ )

    {

      dist = dist + pow ( x[i] - z[i+closest[0]*(dim_num)], 2 );

    }

    h[closest[0]] = r8_max ( h[closest[0]], dist );

    delete [] x;

  }

  gamma = pointset_spacing ( dim_num, n, z );

  chi = 0.0;

  for ( j = 0; j < n; j++ )

  {

    chi_vec[j] = 2.0 * sqrt ( h[j] ) / gamma[j];

    chi = r8_max ( chi, chi_vec[j] );

  }

  delete [] chi_vec;

  delete [] gamma;

  delete [] h;

  return chi;

}

double d_measure ( int dim_num, int n, double z[], int ns,

  double *sample_routine ( int dim_num, int n, int *seed ),

  int seed_init )

{

  double *a;

  double *centroid;

  int closest[1];

  double d;

  double di;

  int *hit;

  int i;

  int i1;

  int i2;

  int j;

  int k;

  double *moment;

  int seed;

  double *tri;

  double *x;

  a = new double[dim_num*dim_num];

  centroid = new double[dim_num*n];

  hit = new int[n];

  moment = new double[dim_num*dim_num*n];

  tri = new double[n];

  seed = seed_init;

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < dim_num; i++ )

    {

      centroid[i+j*dim_num] = 0.0;

    }

  }

  for ( j = 0; j < n; j++ )

  {

    hit[j] = 0;

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i2 = 0; i2 < dim_num; i2++ )

    {

      for ( i1 = 0; i1 < dim_num; i1++ )

      {

        moment[i1+i2*dim_num+j*dim_num*dim_num] = 0.0;

      }

    }

  }

  for ( k = 1; k <= ns; k++ )

  {

    x = sample_routine ( dim_num, 1, &seed );

    find_closest ( dim_num, n, 1, x, z, closest );

    hit[closest[0]] = hit[closest[0]] + 1;

    for ( i = 0; i < dim_num; i++ )

    {

      centroid[i+closest[0]*dim_num] = centroid[i+closest[0]*dim_num] + x[i];

    }

    for ( i1 = 0; i1 < dim_num; i1++ )

    {

      for ( i2 = 0; i2 < dim_num; i2++ )

      {

        moment[i1+i2*dim_num+closest[0]*dim_num*dim_num]

        = moment[i1+i2*dim_num+closest[0]*dim_num*dim_num] + x[i1] * x[i2];

      }

    }

    delete [] x;

  }

  for ( j = 0; j < n; j++ )

  {

    if ( 0 < hit[j] )

    {

      for ( i = 0; i < dim_num; i++ )

      {

        centroid[i+j*dim_num] = centroid[i+j*dim_num] / ( double ) ( hit[j] );

      }

      for ( i1 = 0; i1 < dim_num; i1++ )

      {

        for ( i2 = 0; i2 < dim_num; i2++ )

        {

          moment[i1+i2*dim_num+j*dim_num*dim_num]

            = moment[i1+i2*dim_num+j*dim_num*dim_num] / ( double ) ( hit[j] );

        }

      }

      for ( i1 = 0; i1 < dim_num; i1++ )

      {

        for ( i2 = 0; i2 < dim_num; i2++ )

        {

          moment[i1+i2*dim_num+j*dim_num*dim_num] =

          moment[i1+i2*dim_num+j*dim_num*dim_num]

            - centroid[i1+j*dim_num] * centroid[i2+j*dim_num];

        }

      }

    }

  }

  for ( j = 0; j < n; j++ )

  {

    tri[j] = 0.0;

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < dim_num; i++ )

    {

      tri[j] = tri[j] + moment[i+i*dim_num+j*dim_num*dim_num];

    }

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < dim_num; i++ )

    {

      moment[i+i*dim_num+j*dim_num*dim_num] =

      moment[i+i*dim_num+j*dim_num*dim_num]

        - tri[j] / ( double ) ( dim_num );

    }

  }

  d = 0.0;

  for ( j = 0; j < n; j++ )

  {

    for ( i2 = 0; i2 < dim_num; i2++ )

    {

      for ( i1 = 0; i1 < dim_num; i1++ )

      {

        a[i1+i2*dim_num] = moment[i1+i2*dim_num+j*dim_num*dim_num];

      }

    }

    di = dge_det ( dim_num, a );

    d = r8_max ( d, di );

  }

  delete [] a;

  delete [] centroid;

  delete [] hit;

  delete [] moment;

  delete [] tri;

  return d;

}

double dge_det ( int n, double a[] )

{

  double det;

  int i;

  int j;

  int k;

  int l;

  double t;

  det = 1.0;

  for ( k = 1; k <= n-1; k++ )

  {

    l = k;

    for ( i = k+1; i <= n; i++ )

    {

      if ( fabs ( a[(l-1)+(k-1)*n] ) < fabs ( a[(i-1)+(k-1)*n] ) )

      {

        l = i;

      }

    }

    det = det * a[(l-1)+(k-1)*n];

    if ( a[(l-1)+(k-1)*n] == 0.0 )

    {

      return det;

    }

    if ( l != k )

    {

      t                = a[(l-1)+(k-1)*n];

      a[(l-1)+(k-1)*n] = a[(k-1)+(k-1)*n];

      a[(k-1)+(k-1)*n] = t;

    }

    for ( i = k+1; i <= n; i++ )

    {

      a[(i-1)+(k-1)*n] = -a[(i-1)+(k-1)*n] / a[(k-1)+(k-1)*n];

    }

    for ( j = k+1; j <= n; j++ )

    {

      if ( l != k )

      {

        t                = a[(l-1)+(j-1)*n];

        a[(l-1)+(j-1)*n] = a[(k-1)+(j-1)*n];

        a[(k-1)+(j-1)*n] = t;

      }

      for ( i = k+1; i <= n; i++ )

      {

        a[(i-1)+(j-1)*n] = a[(i-1)+(j-1)*n]

          + a[(i-1)+(k-1)*n] * a[(k-1)+(j-1)*n];

      }

    }

  }

  det = det * a[(n-1)+(n-1)*n];

  return det;

}

int diaedg ( double x0, double y0, double x1, double y1, double x2, double y2,

  double x3, double y3 )

{

  double ca;

  double cb;

  double dx10;

  double dx12;

  double dx30;

  double dx32;

  double dy10;

  double dy12;

  double dy30;

  double dy32;

  double s;

  double tol;

  double tola;

  double tolb;

  int value;

  tol = 100.0 * r8_epsilon ( );

  dx10 = x1 - x0;

  dy10 = y1 - y0;

  dx12 = x1 - x2;

  dy12 = y1 - y2;

  dx30 = x3 - x0;

  dy30 = y3 - y0;

  dx32 = x3 - x2;

  dy32 = y3 - y2;

  tola = tol * r8_max ( fabs ( dx10 ),

               r8_max ( fabs ( dy10 ),

               r8_max ( fabs ( dx30 ), fabs ( dy30 ) ) ) );

  tolb = tol * r8_max ( fabs ( dx12 ),

               r8_max ( fabs ( dy12 ),

               r8_max ( fabs ( dx32 ), fabs ( dy32 ) ) ) );

  ca = dx10 * dx30 + dy10 * dy30;

  cb = dx12 * dx32 + dy12 * dy32;

  if ( tola < ca && tolb < cb )

  {

    value = -1;

  }

  else if ( ca < -tola && cb < -tolb )

  {

    value = 1;

  }

  else

  {

    tola = r8_max ( tola, tolb );

    s = ( dx10 * dy30 - dx30 * dy10 ) * cb

      + ( dx32 * dy12 - dx12 * dy32 ) * ca;

    if ( tola < s )

    {

      value = -1;

    }

    else if ( s < -tola )

    {

      value = 1;

    }

    else

    {

      value = 0;

    }

  }

  return value;

}

double *dtable_data_read ( char *input_filename, int m, int n )

{

  bool error;

  ifstream input;

  int i;

  int j;

  char line[255];

  double *table;

  double *x;

  input.open ( input_filename );

  if ( !input )

  {

    cout << "\n";

    cout << "DTABLE_DATA_READ - Fatal error!\n";

    cout << "  Could not open the input file: \"" << input_filename << "\"\n";

    exit ( 1 );

  }

  table = new double[m*n];

  x = new double[m];

  j = 0;

  while ( j < n )

  {

    input.getline ( line, sizeof ( line ) );

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

void dtable_header_read ( char *input_filename, int *m, int *n )

{

  *m = file_column_count ( input_filename );

  if ( *m <= 0 )

  {

    cout << "\n";

    cout << "DTABLE_HEADER_READ - Fatal error!\n";

    cout << "  FILE_COLUMN_COUNT failed.\n";

    *n = -1;

    return;

  }

  *n = file_row_count ( input_filename );

  if ( *n <= 0 )

  {

    cout << "\n";

    cout << "DTABLE_HEADER_READ - Fatal error!\n";

    cout << "  FILE_ROW_COUNT failed.\n";

    return;

  }

  return;

}

int dtris2 ( int point_num, double point_xy[], int *tri_num,

  int tri_vert[], int tri_nabe[] )

{

  double cmax;

  int e;

  int error;

  int i;

  int *indx;

  int j;

  int k;

  int l;

  int ledg;

  int lr;

  int ltri;

  int m;

  int m1;

  int m2;

  int n;

  int redg;

  int rtri;

  int *stack;

  int t;

  double tol;

  int top;

  stack = new int[point_num];

  tol = 100.0 * r8_epsilon ( );

  indx = r82vec_sort_heap_index_a ( point_num, point_xy );

  r82vec_permute ( point_num, point_xy, indx );

  m1 = 1;

  for ( i = 2; i <= point_num; i++ )

  {

    m = m1;

    m1 = i;

    k = -1;

    for ( j = 0; j <= 1; j++ )

    {

      cmax = r8_max ( fabs ( point_xy[2*(m-1)+j] ),

                     fabs ( point_xy[2*(m1-1)+j] ) );

      if ( tol * ( cmax + 1.0 )

           < fabs ( point_xy[2*(m-1)+j] - point_xy[2*(m1-1)+j] ) )

      {

        k = j;

        break;

      }

    }

    if ( k == -1 )

    {

      cout << "\n";

      cout << "DTRIS2 - Fatal error!\n";

      cout << "  Fails for point number I = " << i << "\n";

      cout << "  M =  " << m  << "\n";

      cout << "  M1 = " << m1 << "\n";

      cout << "  X,Y(M)  = " << point_xy[2*(m-1)+0] << "  "

                             << point_xy[2*(m-1)+1] << "\n";

      cout << "  X,Y(M1) = " << point_xy[2*(m1-1)+0] << "  "

                             << point_xy[2*(m1-1)+1] << "\n";

      delete [] stack;

      return 224;

    }

  }

  m1 = 1;

  m2 = 2;

  j = 3;

  for ( ; ; )

  {

    if ( point_num < j )

    {

      cout << "\n";

      cout << "DTRIS2 - Fatal error!\n";

      delete [] stack;

      return 225;

    }

    m = j;

    lr = lrline ( point_xy[2*(m-1)+0], point_xy[2*(m-1)+1],

      point_xy[2*(m1-1)+0], point_xy[2*(m1-1)+1],

      point_xy[2*(m2-1)+0], point_xy[2*(m2-1)+1], 0.0 );

    if ( lr != 0 )

    {

      break;

    }

    j = j + 1;

  }

  *tri_num = j - 2;

  if ( lr == -1 )

  {

    tri_vert[3*0+0] = m1;

    tri_vert[3*0+1] = m2;

    tri_vert[3*0+2] = m;

    tri_nabe[3*0+2] = -3;

    for ( i = 2; i <= *tri_num; i++ )

    {

      m1 = m2;

      m2 = i+1;

      tri_vert[3*(i-1)+0] = m1;

      tri_vert[3*(i-1)+1] = m2;

      tri_vert[3*(i-1)+2] = m;

      tri_nabe[3*(i-1)+0] = -3 * i;

      tri_nabe[3*(i-1)+1] = i;

      tri_nabe[3*(i-1)+2] = i - 1;

    }

    tri_nabe[3*(*tri_num-1)+0] = -3 * (*tri_num) - 1;

    tri_nabe[3*(*tri_num-1)+1] = -5;

    ledg = 2;

    ltri = *tri_num;

  }

  else

  {

    tri_vert[3*0+0] = m2;

    tri_vert[3*0+1] = m1;

    tri_vert[3*0+2] = m;

    tri_nabe[3*0+0] = -4;

    for ( i = 2; i <= *tri_num; i++ )

    {

      m1 = m2;

      m2 = i+1;

      tri_vert[3*(i-1)+0] = m2;

      tri_vert[3*(i-1)+1] = m1;

      tri_vert[3*(i-1)+2] = m;

      tri_nabe[3*(i-2)+2] = i;

      tri_nabe[3*(i-1)+0] = -3 * i - 3;

      tri_nabe[3*(i-1)+1] = i - 1;

    }

    tri_nabe[3*(*tri_num-1)+2] = -3 * (*tri_num);

    tri_nabe[3*0+1] = -3 * (*tri_num) - 2;

    ledg = 2;

    ltri = 1;

  }

  top = 0;

  for ( i = j+1; i <= point_num; i++ )

  {

    m = i;

    m1 = tri_vert[3*(ltri-1)+ledg-1];

    if ( ledg <= 2 )

    {

      m2 = tri_vert[3*(ltri-1)+ledg];

    }

    else

    {

      m2 = tri_vert[3*(ltri-1)+0];

    }

    lr = lrline ( point_xy[2*(m-1)+0], point_xy[2*(m-1)+1],

      point_xy[2*(m1-1)+0], point_xy[2*(m1-1)+1],

      point_xy[2*(m2-1)+0], point_xy[2*(m2-1)+1], 0.0 );

    if ( 0 < lr )

    {

      rtri = ltri;

      redg = ledg;

      ltri = 0;

    }

    else

    {

      l = -tri_nabe[3*(ltri-1)+ledg-1];

      rtri = l / 3;

      redg = (l % 3) + 1;

    }

    vbedg ( point_xy[2*(m-1)+0], point_xy[2*(m-1)+1], point_num,

      point_xy, *tri_num, tri_vert, tri_nabe, &ltri, &ledg, &rtri, &redg );

    n = *tri_num + 1;

    l = -tri_nabe[3*(ltri-1)+ledg-1];

    for ( ; ; )

    {

      t = l / 3;

      e = ( l % 3 ) + 1;

      l = -tri_nabe[3*(t-1)+e-1];

      m2 = tri_vert[3*(t-1)+e-1];

      if ( e <= 2 )

      {

        m1 = tri_vert[3*(t-1)+e];

      }

      else

      {

        m1 = tri_vert[3*(t-1)+0];

      }

      *tri_num = *tri_num + 1;

      tri_nabe[3*(t-1)+e-1] = *tri_num;

      tri_vert[3*(*tri_num-1)+0] = m1;

      tri_vert[3*(*tri_num-1)+1] = m2;

      tri_vert[3*(*tri_num-1)+2] = m;

      tri_nabe[3*(*tri_num-1)+0] = t;

      tri_nabe[3*(*tri_num-1)+1] = *tri_num - 1;

      tri_nabe[3*(*tri_num-1)+2] = *tri_num + 1;

      top = top + 1;

      if ( point_num < top )

      {

        cout << "\n";

        cout << "DTRIS2 - Fatal error!\n";

        cout << "  Stack overflow.\n";

        delete [] stack;

        return 8;

      }

      stack[top-1] = *tri_num;

      if ( t == rtri && e == redg )

      {

        break;

      }

    }

    tri_nabe[3*(ltri-1)+ledg-1] = -3 * n - 1;

    tri_nabe[3*(n-1)+1] = -3 * (*tri_num) - 2;

    tri_nabe[3*(*tri_num-1)+2] = -l;

    ltri = n;

    ledg = 2;

    error = swapec ( m, &top, &ltri, &ledg, point_num, point_xy, *tri_num,

      tri_vert, tri_nabe, stack );

    if ( error != 0 )

    {

      cout << "\n";

      cout << "DTRIS2 - Fatal error!\n";

      cout << "  Error return from SWAPEC.\n";

      delete [] stack;

      return error;

    }

  }

  for ( i = 0; i < 3; i++ )

  {

    for ( j = 0; j < *tri_num; j++ )

    {

      tri_vert[i+j*3] = indx [ tri_vert[i+j*3] - 1 ];

    }

  }

  perm_inv ( point_num, indx );

  r82vec_permute ( point_num, point_xy, indx );

  delete [] indx;

  delete [] stack;

  return 0;

}

double e_measure ( int dim_num, int n, double z[], int ns,

  double *sample_routine ( int dim_num, int n, int *seed ),

  int seed_init )

{

  int closest[1];

  double dist;

  double e;

  double *e_vec;

  int i;

  int j;

  int k;

  int seed;

  double *x;

  seed = seed_init;

  e_vec = new double[n];

  for ( j = 0; j < n; j++ )

  {

    e_vec[j] = 0.0;

  }

  for ( k = 1; k <= ns; k++ )

  {

    x = sample_routine ( dim_num, 1, &seed );

    find_closest ( dim_num, n, 1, x, z, closest );

    dist = 0.0;

    for ( i = 0; i < dim_num; i++ )

    {

      dist = dist + pow ( x[i] - z[i+closest[0]*(dim_num)], 2 );

    }

    e_vec[closest[0]] = e_vec[closest[0]] + dist;

    delete [] x;

  }

  e = 0.0;

  for ( j = 0; j < n; j++ )

  {

    e = e + e_vec[j];

  }

  e = e / double ( ns );

  delete [] e_vec;

  return e;

}

int file_column_count ( char *input_filename )

{

  int column_num;

  ifstream input;

  bool got_one;

  char line[256];

  input.open ( input_filename );

  if ( !input )

  {

    column_num = -1;

    cout << "\n";

    cout << "FILE_COLUMN_COUNT - Fatal error!\n";

    cout << "  Could not open the file:\n";

    cout << "  \"" << input_filename << "\"\n";

    return column_num;

  }

  got_one = false;

  for ( ; ; )

  {

    input.getline ( line, sizeof ( line ) );

    if ( input.eof ( ) )

    {

      break;

    }

    if ( s_len_trim ( line ) == 0 )

    {

      continue;

    }

    if ( line[0] == '#' )

    {

      continue;

    }

    got_one = true;

    break;

  }

  if ( !got_one )

  {

    input.close ( );

    input.open ( input_filename );

    for ( ; ; )

    {

      input.getline ( line, sizeof ( line ) );

      if ( input.eof ( ) )

      {

        break;

      }

      if ( s_len_trim ( line ) == 0 )

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

    cout << "\n";

    cout << "FILE_COLUMN_COUNT - Warning!\n";

    cout << "  The file does not seem to contain any data.\n";

    return -1;

  }

  column_num = s_word_count ( line );

  return column_num;

}

int file_row_count ( char *input_filename )

{

  int bad_num;

  int comment_num;

  ifstream input;

  int i;

  char line[100];

  int record_num;

  int row_num;

  row_num = 0;

  comment_num = 0;

  record_num = 0;

  bad_num = 0;

  input.open ( input_filename );

  if ( !input )

  {

    cout << "\n";

    cout << "FILE_ROW_COUNT - Fatal error!\n";

    cout << "  Could not open the input file: \"" << input_filename << "\"\n";

    exit ( 1 );

  }

  for ( ; ; )

  {

    input.getline ( line, sizeof ( line ) );

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

void find_closest ( int dim_num, int n, int sample_num, double s[], double r[],

  int nearest[] )

{

  double dist_sq_min;

  double dist_sq;

  int i;

  int jr;

  int js;

  for ( js = 0; js < sample_num; js++ )

  {

    dist_sq_min = r8_huge ( );

    nearest[js] = -1;

    for ( jr = 0; jr < n; jr++ )

    {

      dist_sq = 0.0;

      for ( i = 0; i < dim_num; i++ )

      {

        dist_sq = dist_sq + ( s[i+js*dim_num] - r[i+jr*dim_num] )

                          * ( s[i+js*dim_num] - r[i+jr*dim_num] );

      }

      if ( jr == 0 || dist_sq < dist_sq_min )

      {

        dist_sq_min = dist_sq;

        nearest[js] = jr;

      }

    }

  }

  return;

}

double gamma_measure ( int dim_num, int n, double z[] )

{

  int i;

  int j1;

  int j2;

  double dist_sq;

  double dist_sq_min;

  double gamma;

  double gamma_sq_max;

  double gamma_sq_min;

  if ( n <= 1 )

  {

    gamma = 0.0;

    return gamma;

  }

  gamma_sq_max = 0.0;

  gamma_sq_min = r8_huge ( );

  for ( j1 = 0; j1 < n; j1++ )

  {

    dist_sq_min = r8_huge ( );

    for ( j2 = 0; j2 < n; j2++ )

    {

      if ( j2 != j1 )

      {

        dist_sq = 0.0;

        for ( i = 0; i < dim_num; i++ )

        {

          dist_sq = dist_sq + pow ( z[i+j1*dim_num] - z[i+j2*dim_num], 2 );

        }

        if ( dist_sq < dist_sq_min )

        {

          dist_sq_min = dist_sq;

        }

      }

    }

    gamma_sq_max = r8_max ( gamma_sq_max, dist_sq_min );

    gamma_sq_min = r8_min ( gamma_sq_min, dist_sq_min );

  }

  if ( gamma_sq_min <= 0.0 )

  {

    gamma = r8_huge ( );

  }

  else

  {

    gamma = sqrt ( gamma_sq_max / gamma_sq_min );

  }

  return gamma;

}

double h_measure ( int dim_num, int n, double z[], int ns,

  double *sample_routine ( int dim_num, int n, int *seed ),

  int seed_init )

{

  int closest[1];

  double dist;

  double h;

  int i;

  int k;

  int seed;

  double *x;

  seed = seed_init;

  h = 0.0;

  for ( k = 1; k <= ns; k++ )

  {

    x = sample_routine ( dim_num, 1, &seed );

    find_closest ( dim_num, n, 1, x, z, closest );

    dist = 0.0;

    for ( i = 0; i < dim_num; i++ )

    {

      dist = dist + pow ( x[i] - z[i+closest[0]*(dim_num)], 2 );

    }

    h = r8_max ( h, dist );

    delete [] x;

  }

  h = sqrt ( h );

  return h;

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

    cout << "\n";

    cout << "I4_MODP - Fatal error!\n";

    cout << "  I4_MODP ( I, J ) called with J = " << j << "\n";

    exit ( 1 );

  }

  value = i % j;

  if ( value < 0 )

  {

    value = value + abs ( j );

  }

  return value;

}

int i4_sign ( int i )

{

  if ( i < 0 )

  {

    return (-1);

  }

  else

  {

    return 1;

  }

}

int i4_wrap ( int ival, int ilo, int ihi )

{

  int jhi;

  int jlo;

  int value;

  int wide;

  jlo = i4_min ( ilo, ihi );

  jhi = i4_max ( ilo, ihi );

  wide = jhi + 1 - jlo;

  if ( wide == 1 )

  {

    value = jlo;

  }

  else

  {

    value = jlo + i4_modp ( ival - jlo, wide );

  }

  return value;

}

int *i4vec_indicator ( int n )

{

  int *a;

  int i;

  a = new int[n];

  for ( i = 0; i < n; i++ )

  {

    a[i] = i + 1;

  }

  return a;

}

void i4vec_print ( int n, int a[], char *title )

{

  int i;

  if ( 0 < s_len_trim ( title ) )

  {

    cout << "\n";

    cout << title << "\n";

  }

  cout << "\n";

  for ( i = 0; i <= n-1; i++ )

  {

    cout << setw(6) << i + 1 << "  "

         << setw(8) << a[i]  << "\n";

  }

  return;

}

double lambda_measure ( int dim_num, int n, double z[] )

{

  int i;

  int j;

  double dist;

  double *gamma;

  double gamma_ave;

  double lambda;

  if ( n <= 1 )

  {

    lambda = 0.0;

    return lambda;

  }

  gamma = pointset_spacing ( dim_num, n, z );

  gamma_ave = 0.0;

  for ( j = 0; j < n; j++ )

  {

    gamma_ave = gamma_ave + gamma[j];

  }

  gamma_ave = gamma_ave / ( double ) ( n );

  if ( gamma_ave <= 0.0 )

  {

    lambda = r8_huge ( );

  }

  else

  {

    lambda = 0.0;

    for ( j = 0; j < n; j++ )

    {

      lambda = lambda + pow ( gamma[j] - gamma_ave, 2 );

    }

    lambda = sqrt ( lambda / ( double ) n );

    lambda = lambda / gamma_ave;

  }

  delete [] gamma;

  return lambda;

}

int lrline ( double xu, double yu, double xv1, double yv1, double xv2,

  double yv2, double dv )

{

  double dx;

  double dxu;

  double dy;

  double dyu;

  double t;

  double tol = 0.0000001;

  double tolabs;

  int value;

  dx = xv2 - xv1;

  dy = yv2 - yv1;

  dxu = xu - xv1;

  dyu = yu - yv1;

  tolabs = tol * r8_max ( fabs ( dx ),

                 r8_max ( fabs ( dy ),

                 r8_max ( fabs ( dxu ),

                 r8_max ( fabs ( dyu ), fabs ( dv ) ) ) ) );

  t = dy * dxu - dx * dyu + dv * sqrt ( dx * dx + dy * dy );

  if ( tolabs < t )

  {

    value = 1;

  }

  else if ( -tolabs <= t )

  {

    value = 0;

  }

  else if ( t < -tolabs )

  {

    value = -1;

  }

  return value;

}

double mu_measure ( int dim_num, int n, double z[], int ns,

  double *sample_routine ( int dim_num, int n, int *seed ),

  int seed_init )

{

  int k;

  int closest[1];

  double dist;

  double *h;

  double h_max;

  double h_min;

  int i;

  int j;

  double mu;

  int seed;

  double *x;

  h = new double[n];

  seed = seed_init;

  for ( j = 0; j < n; j++ )

  {

    h[j] = 0.0;

  }

  for ( k = 1; k <= ns; k++ )

  {

    x = sample_routine ( dim_num, 1, &seed );

    find_closest ( dim_num, n, 1, x, z, closest );

    dist = 0.0;

    for ( i = 0; i < dim_num; i++ )

    {

      dist = dist + pow ( x[i] - z[i+closest[0]*dim_num], 2 );

    }

    h[closest[0]] = r8_max ( h[closest[0]], dist );

    delete [] x;

  }

  h_max = h[0];

  for ( j = 1; j < n; j++ )

  {

    h_max = r8_max ( h_max, h[j] );

  }

  h_max = sqrt ( h_max );

  h_min = h[0];

  for ( j = 1; j < n; j++ )

  {

    h_min = r8_min ( h_min, h[j] );

  }

  h_min = sqrt ( h_min );

  if ( h_min == 0.0 )

  {

    mu = r8_huge ( );

  }

  else

  {

    mu = h_max / h_min;

  }

  delete [] h;

  return mu;

}

double nu_measure ( int dim_num, int n, double z[], int ns,

  double *sample_routine ( int dim_num, int n, int *seed ),

  int seed_init )

{

  int closest[1];

  int *hit;

  int j;

  int k;

  double nu;

  int seed;

  double *volume;

  double volume_max;

  double volume_min;

  double *x;

  hit = new int[n];

  volume = new double[n];

  seed = seed_init;

  for ( j = 0; j < n; j++ )

  {

    hit[j] = 0;

  }

  for ( k = 1; k <= ns; k++ )

  {

    x = sample_routine ( dim_num, 1, &seed );

    find_closest ( dim_num, n, 1, x, z, closest );

    hit[closest[0]] = hit[closest[0]] + 1;

    delete [] x;

  }

  for ( j = 0; j < n; j++ )

  {

    volume[j] = ( double ) ( hit[j] ) / ( double ) ( ns );

  }

  volume_max = 0.0;

  for ( j = 0; j < n; j++ )

  {

    volume_max = r8_max ( volume_max, volume[j] );

  }

  volume_min = r8_huge ( );

  for ( j = 0; j < n; j++ )

  {

    volume_min = r8_min ( volume_min, volume[j] );

  }

  if ( volume_min == 0.0 )

  {

    nu = r8_huge ( );

  }

  else

  {

    nu = volume_max / volume_min;

  }

  delete [] hit;

  delete [] volume;

  return nu;

}

void perm_inv ( int n, int p[] )

{

  int i;

  int i0;

  int i1;

  int i2;

  int is;

  if ( n <= 0 )

  {

    cout << "\n";

    cout << "PERM_INV - Fatal error!\n";

    cout << "  Input value of N = " << n << "\n";

    exit ( 1 );

  }

  is = 1;

  for ( i = 1; i <= n; i++ )

  {

    i1 = p[i-1];

    while ( i < i1 )

    {

      i2 = p[i1-1];

      p[i1-1] = -i2;

      i1 = i2;

    }

    is = - i4_sign ( p[i-1] );

    p[i-1] = i4_sign ( is ) * abs ( p[i-1] );

  }

  for ( i = 1; i <= n; i++ )

  {

    i1 = -p[i-1];

    if ( 0 <= i1 )

    {

      i0 = i;

      for ( ; ; )

      {

        i2 = p[i1-1];

        p[i1-1] = i0;

        if ( i2 < 0 )

        {

          break;

        }

        i0 = i1;

        i1 = i2;

      }

    }

  }

  return;

}

double *pointset_spacing ( int dim_num, int n, double z[] )

{

  double dist;

  int i;

  int j1;

  int j2;

  double *gamma;

  gamma = new double[n];

  for ( j1 = 0; j1 < n; j1++ )

  {

    gamma[j1] = r8_huge ( );

    for ( j2 = 0; j2 < n; j2++ )

    {

      if ( j2 != j1 )

      {

        dist = 0.0;

        for ( i = 0; i < dim_num; i++ )

        {

          dist = dist + pow ( z[i+j1*dim_num] - z[i+j2*dim_num], 2 );

        }

        gamma[j1] = r8_min ( gamma[j1], dist );

      }

    }

  }

  for ( j1 = 0; j1 < n; j1++ )

  {

    gamma[j1] = sqrt ( gamma[j1] );

  }

  return gamma;

}

double q_measure ( int n, double z[], int triangle_order, int triangle_num,

  int triangle_node[] )

{

  int a_index;

  double ab_length;

  int b_index;

  double bc_length;

  int c_index;

  double ca_length;

  double q;

  double q_min;

  int triangle;

  double value;

  if ( triangle_num < 1 )

  {

    value = -1.0;

    return value;

  }

  q_min = r8_huge ( );

  for ( triangle = 0; triangle < triangle_num; triangle++ )

  {

    a_index = triangle_node[0+triangle*3];

    b_index = triangle_node[1+triangle*3];

    c_index = triangle_node[2+triangle*3];

    ab_length = sqrt (

        pow ( z[0+(a_index-1)*2] - z[0+(b_index-1)*2], 2 )

      + pow ( z[1+(a_index-1)*2] - z[1+(b_index-1)*2], 2 ) );

    bc_length = sqrt (

        pow ( z[0+(b_index-1)*2] - z[0+(c_index-1)*2], 2 )

      + pow ( z[1+(b_index-1)*2] - z[1+(c_index-1)*2], 2 ) );

    ca_length = sqrt (

        pow ( z[0+(c_index-1)*2] - z[0+(a_index-1)*2], 2 )

      + pow ( z[1+(c_index-1)*2] - z[1+(a_index-1)*2], 2 ) );

    q = ( bc_length + ca_length - ab_length )

      * ( ca_length + ab_length - bc_length )

      * ( ab_length + bc_length - ca_length )

      / ( ab_length * bc_length * ca_length );

    q_min = r8_min ( q_min, q );

  }

  value = q_min;

  return value;

}

double r0_measure ( int dim_num, int n, double z[] )

{

  double dist;

  int i;

  int j1;

  int j2;

  double value;

  if ( n <= 1 )

  {

    value = r8_huge ( );

    return value;

  }

  value = 0.0;

  for ( j1 = 0; j1 < n; j1++ )

  {

    for ( j2 = 0; j2 < n; j2++ )

    {

      if ( j2 != j1 )

      {

        dist = 0.0;

        for ( i = 0; i < dim_num; i++ )

        {

          dist = dist + pow ( z[i+j1*dim_num] - z[i+j2*dim_num], 2 );

        }

        dist = sqrt ( dist );

        if ( dist == 0.0 )

        {

          value = r8_huge ( );

          return value;

        }

        value = value + log ( 1.0 / dist );

      }

    }

  }

  value = value / ( double ) ( n * ( n - 1 ) );

  return value;

}

double r8_epsilon ( )

{

  double r;

  r = 1.0;

  while ( 1.0 < ( double ) ( 1.0 + r )  )

  {

    r = r / 2.0;

  }

  return ( 2.0 * r );

}

double r8_huge ( )

{

  double value;

  value = 1.0E+30;

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

void r82vec_permute ( int n, double a[], int p[] )

{

  double a_temp[2];

  int i;

  int iget;

  int iput;

  int istart;

  for ( istart = 1; istart <= n; istart++ )

  {

    if ( p[istart-1] < 0 )

    {

      continue;

    }

    else if ( p[istart-1] == istart )

    {

      p[istart-1] = -p[istart-1];

      continue;

    }

    else

    {

      a_temp[0] = a[0+(istart-1)*2];

      a_temp[1] = a[1+(istart-1)*2];

      iget = istart;

      for ( ; ; )

      {

        iput = iget;

        iget = p[iget-1];

        p[iput-1] = -p[iput-1];

        if ( iget < 1 || n < iget )

        {

          cout << "\n";

          cout << "R82VEC_PERMUTE - Fatal error!\n";

          cout << "  IGET = " << iget << "\n";

          cout << "  N =    " << n << "\n";

          exit ( 1 );

        }

        if ( iget == istart )

        {

          a[0+(iput-1)*2] = a_temp[0];

          a[1+(iput-1)*2] = a_temp[1];

          break;

        }

        a[0+(iput-1)*2] = a[0+(iget-1)*2];

        a[1+(iput-1)*2] = a[1+(iget-1)*2];

      }

    }

  }

  for ( i = 0; i < n; i++ )

  {

    p[i] = -p[i];

  }

  return;

}

int *r82vec_sort_heap_index_a ( int n, double a[] )

{

  double aval[2];

  int i;

  int *indx;

  int indxt;

  int ir;

  int j;

  int l;

  if ( n < 1 )

  {

    return NULL;

  }

  if ( n == 1 )

  {

    indx = new int[1];

    indx[0] = 1;

    return indx;

  }

  indx = i4vec_indicator ( n );

  l = n / 2 + 1;

  ir = n;

  for ( ; ; )

  {

    if ( 1 < l )

    {

      l = l - 1;

      indxt = indx[l-1];

      aval[0] = a[0+(indxt-1)*2];

      aval[1] = a[1+(indxt-1)*2];

    }

    else

    {

      indxt = indx[ir-1];

      aval[0] = a[0+(indxt-1)*2];

      aval[1] = a[1+(indxt-1)*2];

      indx[ir-1] = indx[0];

      ir = ir - 1;

      if ( ir == 1 )

      {

        indx[0] = indxt;

        break;

      }

    }

    i = l;

    j = l + l;

    while ( j <= ir )

    {

      if ( j < ir )

      {

        if (   a[0+(indx[j-1]-1)*2] <  a[0+(indx[j]-1)*2] ||

             ( a[0+(indx[j-1]-1)*2] == a[0+(indx[j]-1)*2] &&

               a[1+(indx[j-1]-1)*2] <  a[1+(indx[j]-1)*2] ) )

        {

          j = j + 1;

        }

      }

      if (   aval[0] <  a[0+(indx[j-1]-1)*2] ||

           ( aval[0] == a[0+(indx[j-1]-1)*2] &&

             aval[1] <  a[1+(indx[j-1]-1)*2] ) )

      {

        indx[i-1] = indx[j-1];

        i = j;

        j = j + j;

      }

      else

      {

        j = ir + 1;

      }

    }

    indx[i-1] = indxt;

  }

  return indx;

}

bool r8mat_in_01 ( int m, int n, double a[] )

{

  int i;

  int j;

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      if ( a[i+j*m] < 0.0 || 1.0 < a[i+j*m] )

      {

        return false;

      }

    }

  }

  return true;

}

void r8mat_transpose_print ( int m, int n, double a[], char *title )

{

  r8mat_transpose_print_some ( m, n, a, 1, 1, m, n, title );

  return;

}

void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo,

  int ihi, int jhi, char *title )

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

double r8vec_max ( int n, double r8vec[] )

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

    if ( value < r8vec[i] )

    {

      value = r8vec[i];

    }

  }

  return value;

}

double r8vec_min ( int n, double r8vec[] )

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

    if ( r8vec[i] < value )

    {

      value = r8vec[i];

    }

  }

  return value;

}

double *r8vec_normal_01 ( int n, int *seed )

{

# define PI 3.141592653589793

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

    r = r8vec_uniform_01 ( 2, seed );

    x[x_hi-1] = sqrt ( -2.0 * log ( r[0] ) ) * cos ( 2.0 * PI * r[1] );

    y =         sqrt ( -2.0 * log ( r[0] ) ) * sin ( 2.0 * PI * r[1] );

    saved = 1;

    made = made + 2;

    delete [] r;

  }

  else if ( ( x_hi - x_lo + 1 ) % 2 == 0 )

  {

    m = ( x_hi - x_lo + 1 ) / 2;

    r = r8vec_uniform_01 ( 2*m, seed );

    for ( i = 0; i <= 2*m-2; i = i + 2 )

    {

      x[x_lo+i-1] = sqrt ( -2.0 * log ( r[i] ) ) * cos ( 2.0 * PI * r[i+1] );

      x[x_lo+i  ] = sqrt ( -2.0 * log ( r[i] ) ) * sin ( 2.0 * PI * r[i+1] );

    }

    made = made + x_hi - x_lo + 1;

    delete [] r;

  }

  else

  {

    x_hi = x_hi - 1;

    m = ( x_hi - x_lo + 1 ) / 2 + 1;

    r = r8vec_uniform_01 ( 2*m, seed );

    for ( i = 0; i <= 2*m-4; i = i + 2 )

    {

      x[x_lo+i-1] = sqrt ( -2.0 * log ( r[i] ) ) * cos ( 2.0 * PI * r[i+1] );

      x[x_lo+i  ] = sqrt ( -2.0 * log ( r[i] ) ) * sin ( 2.0 * PI * r[i+1] );

    }

    i = 2*m - 2;

    x[x_lo+i-1] = sqrt ( -2.0 * log ( r[i] ) ) * cos ( 2.0 * PI * r[i+1] );

    y           = sqrt ( -2.0 * log ( r[i] ) ) * sin ( 2.0 * PI * r[i+1] );

    saved = 1;

    made = made + x_hi - x_lo + 2;

    delete [] r;

  }

  return x;

# undef PI

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

double *radius_maximus ( int dim_num, int n, double z[], bool walls )

{

  double distance_j;

  double distance_min;

  bool done;

  int FIXED = 0;

  int FREE = 1;

  int i;

  int j;

  int j1;

  int j2;

  int next;

  double *radius;

  double radius_i;

  double radius_min;

  int *status;

  radius = new double[n];

  status = new int[n];

  if ( walls )

  {

    for ( j = 0; j < n; j++ )

    {

      for ( i = 0; i < dim_num; i++ )

      {

        if ( z[i+j*dim_num] < 0.0 )

        {

          cout << "\n";

          cout << "RADIUS_MAXIMUS - Fatal error!\n";

          cout << "  Some coordinate is less than 0.\n";

          exit ( 1 );

        }

        else if ( 1.0 < z[i+j*dim_num] )

        {

          cout << "\n";

          cout << "RADIUS_MAXIMUS - Fatal error!\n";

          cout << "  Some coordinate is greater than 1.\n";

          exit ( 1 );

        }

      }

    }

  }

  for ( j = 0; j < n; j++ )

  {

    radius[j] = 0.0;

  }

  for ( j = 0; j < n; j++ )

  {

    status[j] = FREE;

  }

  for ( ; ; )

  {

    done = true;

    for ( j = 0; j < n; j++ )

    {

      if ( status[j] != FIXED )

      {

        done = false;

        break;

      }

    }

    if ( done )

    {

      break;

    }

    next = -1;

    radius_min = r8_huge ( );

    for ( j1 = 0; j1 < n; j1++ )

    {

      if ( status[j1] == FREE )

      {

        if ( walls )

        {

          radius_i = r8_huge ( );

          for ( i = 0; i < dim_num; i++ )

          {

            radius_i = r8_min ( radius_i, z[i+j1*dim_num] );

          }

          for ( i = 0; i < dim_num; i++ )

          {

            radius_i = r8_min ( radius_i, 1.0 - z[i+j1*dim_num] );

          }

        }

        else

        {

          radius_i = r8_huge ( );

        }

        for ( j2 = 0; j2 < n; j2++ )

        {

          if ( j2 != j1 )

          {

            distance_j = 0.0;

            for ( i = 0; i < dim_num; i++ )

            {

              distance_j = distance_j

                + pow ( z[i+j1*dim_num] - z[i+j2*dim_num], 2 );

            }

            distance_j = sqrt ( distance_j );

            if ( status[j2] == FREE )

            {

              radius_i = r8_min ( radius_i, distance_j / 2.0 );

            }

            else

            {

              radius_i = r8_min ( radius_i, distance_j - radius[j2] );

            }

          }

        }

        if ( radius_i < radius_min )

        {

          next = j1;

          radius_min = radius_i;

        }

      }

    }

    if ( next == -1 )

    {

      cout << "\n";

      cout << "RADIUS_MAXIMUS - Fatal error!\n";

      cout << "  There were points left to handle, but could\n";

      cout << "  not choose the next one to work on.\n";

      exit ( 1 );

    }

    radius[next] = radius_min;

    status[next] = FIXED;

  }

  return radius;

}

int s_len_trim ( char *s )

{

  int n;

  char *t;

  n = strlen ( s );

  t = s + strlen ( s ) - 1;

  while ( 0 < n )

  {

    if ( *t != ' ' )

    {

      return n;

    }

    t--;

    n--;

  }

  return n;

}

double s_to_r8 ( char *s, int *lchar, bool *error )

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

bool s_to_r8vec ( char *s, int n, double rvec[] )

{

  bool error;

  int i;

  int lchar;

  double x;

  for ( i = 0; i < n; i++ )

  {

    rvec[i] = s_to_r8 ( s, &lchar, &error );

    if ( error )

    {

      return error;

    }

    s = s + lchar;

  }

  return error;

}

int s_word_count ( char *s )

{

  bool blank;

  int i;

  int nword;

  nword = 0;

  blank = true;

  while ( *s )

  {

    if ( *s == ' ' )

    {

      blank = true;

    }

    else if ( blank )

    {

      nword = nword + 1;

      blank = false;

    }

    *s++;

  }

  return nword;

}

double *sample_hypercube_uniform ( int dim_num, int n, int *seed )

{

  double *x;

  x = r8mat_uniform_01 ( dim_num, n, seed );

  return x;

}

double *sample_sphere_uniform ( int m, int n, int *seed )

{

  double exponent;

  int i;

  int j;

  double norm;

  double r;

  double *x;

  double *y;

  x = new double[m*n];

  y = new double[m];

  exponent = 1.0 / ( double ) ( m );

  for ( j = 0; j < n; j++ )

  {

    y = r8vec_normal_01 ( m, seed );

    norm = 0.0;

    for ( i = 0; i < m; i++ )

    {

      norm = norm + y[i] * y[i];

    }

    norm = sqrt ( norm );

    for ( i = 0; i < m; i++ )

    {

      y[i] = y[i] / norm;

    }

    r = r8_uniform_01 ( seed );

    r = pow ( r, exponent );

    for ( i = 0; i < m; i++ )

    {

      x[i+j*m] = r * y[i];

    }

  }

  return x;

}

double sphere_measure ( int dim_num, int n, double z[] )

{

  int i;

  int j;

  double *radius;

  double radius_ave;

  double radius_max;

  double radius_min;

  double sphere;

  bool verbose = false;

  double volume;

  bool walls = true;

  if ( !r8mat_in_01 ( dim_num, n, z ) )

  {

    cout << "\n";

    cout << "SPHERE_MEASURE - Fatal error!\n";

    cout << "  Some of the data is not inside the unit hypercube.\n";

    return r8_huge ( );

  }

  radius = radius_maximus ( dim_num, n, z, walls );

  sphere = 0.0;

  for ( i = 0; i < n; i++ )

  {

    volume = sphere_volume_nd ( dim_num, radius[i] );

    sphere = sphere + volume;

  }

  if ( verbose )

  {

    radius_ave = 0.0;

    radius_min = r8_huge ( );

    radius_max = 0.0;

    for ( j = 0; j < n; j++ )

    {

      radius_ave = radius_ave + radius[j];

      radius_min = r8_min ( radius_min, radius[j] );

      radius_max = r8_max ( radius_max, radius[j] );

    }

    cout << "\n";

    cout << "  Number of dimensions is " << dim_num << "\n";

    cout << "  Number of points is " << n << "\n";

    if ( walls )

    {

      cout << "  Spheres are required to stay in the unit hypercube.\n";

    }

    else

    {

      cout << "  Spheres are NOT required to stay in the unit hypercube.\n";

    }

    cout << "\n";

    cout << "  Average radius = " << radius_ave << "\n";

    cout << "  Minimum radius = " << radius_min << "\n";

    cout << "  Maximum radius = " << radius_max << "\n";

    cout << "  Sphere volume =  " << sphere     << "\n";

  }

  delete [] radius;

  return sphere;

}

double sphere_volume_nd ( int dim_num, double r )

{

# define PI 3.141592653589793

  int i;

  int m;

  double volume;

  if ( ( dim_num % 2 ) == 0 )

  {

    m = dim_num / 2;

    volume = pow ( PI, m );

    for ( i = 1; i <= m; i++ )

    {

      volume = volume / ( double ) ( i );

    }

  }

  else

  {

    m = ( dim_num - 1 ) / 2;

    volume = pow ( PI, m ) * pow ( 2.0, dim_num );

    for ( i = m+1; i <= 2*m+1; i++ )

    {

      volume = volume / ( double ) ( i );

    }

  }

  volume = volume * pow ( r, dim_num );

  return volume;

# undef PI

}

int swapec ( int i, int *top, int *btri, int *bedg, int point_num,

  double point_xy[], int tri_num, int tri_vert[], int tri_nabe[],

  int stack[] )

{

  int a;

  int b;

  int c;

  int e;

  int ee;

  int em1;

  int ep1;

  int f;

  int fm1;

  int fp1;

  int l;

  int r;

  int s;

  int swap;

  int t;

  int tt;

  int u;

  double x;

  double y;

  x = point_xy[2*(i-1)+0];

  y = point_xy[2*(i-1)+1];

  for ( ; ; )

  {

    if ( *top <= 0 )

    {

      break;

    }

    t = stack[(*top)-1];

    *top = *top - 1;

    if ( tri_vert[3*(t-1)+0] == i )

    {

      e = 2;

      b = tri_vert[3*(t-1)+2];

    }

    else if ( tri_vert[3*(t-1)+1] == i )

    {

      e = 3;

      b = tri_vert[3*(t-1)+0];

    }

    else

    {

      e = 1;

      b = tri_vert[3*(t-1)+1];

    }

    a = tri_vert[3*(t-1)+e-1];

    u = tri_nabe[3*(t-1)+e-1];

    if ( tri_nabe[3*(u-1)+0] == t )

    {

      f = 1;

      c = tri_vert[3*(u-1)+2];

    }

    else if ( tri_nabe[3*(u-1)+1] == t )

    {

      f = 2;

      c = tri_vert[3*(u-1)+0];

    }

    else

    {

      f = 3;

      c = tri_vert[3*(u-1)+1];

    }

    swap = diaedg ( x, y,

      point_xy[2*(a-1)+0], point_xy[2*(a-1)+1],

      point_xy[2*(c-1)+0], point_xy[2*(c-1)+1],

      point_xy[2*(b-1)+0], point_xy[2*(b-1)+1] );

    if ( swap == 1 )

    {

      em1 = i4_wrap ( e - 1, 1, 3 );

      ep1 = i4_wrap ( e + 1, 1, 3 );

      fm1 = i4_wrap ( f - 1, 1, 3 );

      fp1 = i4_wrap ( f + 1, 1, 3 );

      tri_vert[3*(t-1)+ep1-1] = c;

      tri_vert[3*(u-1)+fp1-1] = i;

      r = tri_nabe[3*(t-1)+ep1-1];

      s = tri_nabe[3*(u-1)+fp1-1];

      tri_nabe[3*(t-1)+ep1-1] = u;

      tri_nabe[3*(u-1)+fp1-1] = t;

      tri_nabe[3*(t-1)+e-1] = s;

      tri_nabe[3*(u-1)+f-1] = r;

      if ( 0 < tri_nabe[3*(u-1)+fm1-1] )

      {

        *top = *top + 1;

        stack[(*top)-1] = u;

      }

      if ( 0 < s )

      {

        if ( tri_nabe[3*(s-1)+0] == u )

        {

          tri_nabe[3*(s-1)+0] = t;

        }

        else if ( tri_nabe[3*(s-1)+1] == u )

        {

          tri_nabe[3*(s-1)+1] = t;

        }

        else

        {

          tri_nabe[3*(s-1)+2] = t;

        }

        *top = *top + 1;

        if ( point_num < *top )

        {

          return 8;

        }

        stack[(*top)-1] = t;

      }

      else

      {

        if ( u == *btri && fp1 == *bedg )

        {

          *btri = t;

          *bedg = e;

        }

        l = - ( 3 * t + e - 1 );

        tt = t;

        ee = em1;

        while ( 0 < tri_nabe[3*(tt-1)+ee-1] )

        {

          tt = tri_nabe[3*(tt-1)+ee-1];

          if ( tri_vert[3*(tt-1)+0] == a )

          {

            ee = 3;

          }

          else if ( tri_vert[3*(tt-1)+1] == a )

          {

            ee = 1;

          }

          else

          {

            ee = 2;

          }

        }

        tri_nabe[3*(tt-1)+ee-1] = l;

      }

      if ( 0 < r )

      {

        if ( tri_nabe[3*(r-1)+0] == t )

        {

          tri_nabe[3*(r-1)+0] = u;

        }

        else if ( tri_nabe[3*(r-1)+1] == t )

        {

          tri_nabe[3*(r-1)+1] = u;

        }

        else

        {

          tri_nabe[3*(r-1)+2] = u;

        }

      }

      else

      {

        if ( t == *btri && ep1 == *bedg )

        {

          *btri = u;

          *bedg = f;

        }

        l = - ( 3 * u + f - 1 );

        tt = u;

        ee = fm1;

        while ( 0 < tri_nabe[3*(tt-1)+ee-1] )

        {

          tt = tri_nabe[3*(tt-1)+ee-1];

          if ( tri_vert[3*(tt-1)+0] == b )

          {

            ee = 3;

          }

          else if ( tri_vert[3*(tt-1)+1] == b )

          {

            ee = 1;

          }

          else

          {

            ee = 2;

          }

        }

        tri_nabe[3*(tt-1)+ee-1] = l;

      }

    }

  }

  return 0;

}

double tau_measure ( int dim_num, int n, double z[], int ns,

  double *sample_routine ( int dim_num, int n, int *seed ),

  int seed_init )

{

  double *centroid;

  int closest[1];

  int *hit;

  int i;

  int i1;

  int i2;

  int j;

  int k;

  double *moment;

  int seed;

  double *t;

  double t_bar;

  double tau;

  double *x;

  centroid = new double[dim_num*n];

  hit = new int[n];

  moment = new double[dim_num*dim_num*n];

  t = new double[n];

  seed = seed_init;

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < dim_num; i++ )

    {

      centroid[i+j*dim_num] = 0.0;

    }

  }

  for ( j = 0; j < n; j++ )

  {

    hit[j] = 0;

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i2 = 0; i2 < dim_num; i2++ )

    {

      for ( i1 = 0; i1 < dim_num; i1++ )

      {

        moment[i1+i2*dim_num+j*dim_num*dim_num] = 0.0;

      }

    }

  }

  for ( k = 1; k <= ns; k++ )

  {

    x = sample_routine ( dim_num, 1, &seed );

    find_closest ( dim_num, n, 1, x, z, closest );

    hit[closest[0]] = hit[closest[0]] + 1;

    for ( i = 0; i < dim_num; i++ )

    {

      centroid[i+closest[0]*dim_num] = centroid[i+closest[0]*dim_num] + x[i];

    }

    for ( i1 = 0; i1 < dim_num; i1++ )

    {

      for ( i2 = 0; i2 < dim_num; i2++ )

      {

        moment[i1+i2*dim_num+closest[0]*dim_num*dim_num]

        = moment[i1+i2*dim_num+closest[0]*dim_num*dim_num] + x[i1] * x[i2];

      }

    }

    delete [] x;

  }

  for ( j = 0; j < n; j++ )

  {

    if ( 0 < hit[j] )

    {

      for ( i = 0; i < dim_num; i++ )

      {

        centroid[i+j*dim_num] = centroid[i+j*dim_num] / ( double ) ( hit[j] );

      }

      for ( i1 = 0; i1 < dim_num; i1++ )

      {

        for ( i2 = 0; i2 < dim_num; i2++ )

        {

          moment[i1+i2*dim_num+j*dim_num*dim_num]

            = moment[i1+i2*dim_num+j*dim_num*dim_num] / ( double ) ( hit[j] );

        }

      }

      for ( i1 = 0; i1 < dim_num; i1++ )

      {

        for ( i2 = 0; i2 < dim_num; i2++ )

        {

            moment[i1+i2*dim_num+j*dim_num*dim_num] =

            moment[i1+i2*dim_num+j*dim_num*dim_num]

              - centroid[i1+j*dim_num] * centroid[i2+j*dim_num];

        }

      }

    }

  }

  for ( j = 0; j < n; j++ )

  {

    t[j] = 0.0;

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < dim_num; i++ )

    {

      t[j] = t[j] + moment[i+i*dim_num+j*dim_num*dim_num];

    }

  }

  t_bar = 0.0;

  for ( j = 0; j < n; j++ )

  {

    t_bar = t_bar + t[j];

  }

  t_bar = t_bar / ( double ) ( n );

  tau = 0.0;

  for ( j = 0; j < n; j++ )

  {

    tau = r8_max ( tau, fabs ( t[j] - t_bar ) );

  }

  delete [] centroid;

  delete [] hit;

  delete [] moment;

  delete [] t;

  return tau;

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

char *timestring ( )

{

# define TIME_SIZE 40

  const struct tm *tm;

  size_t len;

  time_t now;

  char *s;

  now = time ( NULL );

  tm = localtime ( &now );

  s = new char[TIME_SIZE];

  len = strftime ( s, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  return s;

# undef TIME_SIZE

}

void vbedg ( double x, double y, int point_num, double point_xy[], int tri_num,

  int tri_vert[], int tri_nabe[], int *ltri, int *ledg, int *rtri, int *redg )

{

  int a;

  double ax;

  double ay;

  int b;

  double bx;

  double by;

  bool done;

  int e;

  int l;

  int lr;

  int t;

  if ( *ltri == 0 )

  {

    done = false;

    *ltri = *rtri;

    *ledg = *redg;

  }

  else

  {

    done = true;

  }

  for ( ; ; )

  {

    l = -tri_nabe[3*((*rtri)-1)+(*redg)-1];

    t = l / 3;

    e = 1 + l % 3;

    a = tri_vert[3*(t-1)+e-1];

    if ( e <= 2 )

    {

      b = tri_vert[3*(t-1)+e];

    }

    else

    {

      b = tri_vert[3*(t-1)+0];

    }

    ax = point_xy[2*(a-1)+0];

    ay = point_xy[2*(a-1)+1];

    bx = point_xy[2*(b-1)+0];

    by = point_xy[2*(b-1)+1];

    lr = lrline ( x, y, ax, ay, bx, by, 0.0 );

    if ( lr <= 0 )

    {

      break;

    }

    *rtri = t;

    *redg = e;

  }

  if ( done )

  {

    return;

  }

  t = *ltri;

  e = *ledg;

  for ( ; ; )

  {

    b = tri_vert[3*(t-1)+e-1];

    e = i4_wrap ( e-1, 1, 3 );

    while ( 0 < tri_nabe[3*(t-1)+e-1] )

    {

      t = tri_nabe[3*(t-1)+e-1];

      if ( tri_vert[3*(t-1)+0] == b )

      {

        e = 3;

      }

      else if ( tri_vert[3*(t-1)+1] == b )

      {

        e = 1;

      }

      else

      {

        e = 2;

      }

    }

    a = tri_vert[3*(t-1)+e-1];

    ax = point_xy[2*(a-1)+0];

    ay = point_xy[2*(a-1)+1];

    bx = point_xy[2*(b-1)+0];

    by = point_xy[2*(b-1)+1];

    lr = lrline ( x, y, ax, ay, bx, by, 0.0 );

    if ( lr <= 0 )

    {

      break;

    }

  }

  *ltri = t;

  *ledg = e;

  return;

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/