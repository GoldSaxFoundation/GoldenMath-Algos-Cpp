
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <cmath>

# include <ctime>

# include <cstring>

using namespace std;

# include "subset.hpp"

int asm_enum ( int n )

{

  int *a;

  int asm_num;

  int *b;

  int *c;

  int i;

  int nn;

  if ( n + 1 <= 0 )

  {

    return 0;

  }

  if ( n + 1 == 1 )

  {

    return 1;

  }

  if ( n + 1 == 2 )

  {

    return 1;

  }

  a = new int[n+1];

  b = new int[n+1];

  c = new int[n+1];

  b[0] = 2;

  c[0] = 2;

  a[0] = 1;

  a[1] = 1;

  for ( nn = 3; nn <= n; nn++ )

  {

    b[nn-2] = nn;

    for ( i = nn-2; 2 <= i; i-- )

    {

      b[i-1] = b[i-1] + b[i-2];

    }

    b[0] = 2;

    c[nn-2] = 2;

    for ( i = nn-2; 2 <= i; i--)

    {

      c[i-1] = c[i-1] + c[i-2];

    }

    c[0] = nn;

    for ( i = 2; i <= nn-1; i++ )

    {

      a[0] = a[0] + a[i-1];

    }

    for  ( i = 2; i <= nn; i++ )

    {

      a[i-1] = a[i-2] * c[i-2] / b[i-2];

    }

  }

  asm_num = 0;

  for ( i = 0; i < n; i++ )

  {

    asm_num = asm_num + a[i];

  }

  delete [] a;

  delete [] b;

  delete [] c;

  return asm_num;

}

void asm_triangle ( int n, int a[] )

{

  int *b;

  int *c;

  int i;

  int nn;

  if ( n + 1 <= 0 )

  {

    return;

  }

  a[0] = 1;

  if ( n + 1 == 1 )

  {

    return;

  }

  a[0] = 1;

  a[1] = 1;

  if ( n + 1 == 2 )

  {

    return;

  }

  b = new int[n+1];

  c = new int[n+1];

  b[0] = 2;

  c[0] = 2;

  for ( nn = 3; nn <= n+1; nn++ )

  {

    b[nn-2] = nn;

    for ( i = nn-2; 2 <= i; i-- )

    {

      b[i-1] = b[i-1] + b[i-2];

    }

    b[0] = 2;

    c[nn-2] = 2;

    for ( i = nn-2; 2 <= i; i-- )

    {

      c[i-1] = c[i-1] + c[i-2];

    }

    c[0] = nn;

    for ( i = 2; i <= nn-1; i++ )

    {

      a[0] = a[0] + a[i-1];

    }

    for ( i = 2; i <= nn; i++ )

    {

      a[i-1] = a[i-2] * c[i-2] / b[i-2];

    }

  }

  delete [] b;

  delete [] c;

  return;

}

void bell ( int n, int b[] )

{

  int i;

  int j;

  b[0] = 1;

  for ( i = 1; i <= n; i++ )

  {

    b[i] = 0;

    for ( j = 1; j <= i; j++ )

    {

      b[i] = b[i] + b[i-j] * i4_choose ( i-1, j-1 );

    }

  }

  return;

}

void bell_values ( int &n_data, int &n, int &c )

{

# define N_MAX 11

  int c_vec[N_MAX] = { 1, 1, 2, 5, 15, 52, 203, 877, 4140, 21147, 115975 };

  int n_vec[N_MAX] = { 0,  1,  2,  3,  4, 5,  6,  7,  8,  9,  10};

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  if ( N_MAX <= n_data )

  {

    n_data = 0;

    n = 0;

    c = 0;

  }

  else

  {

    n = n_vec[n_data];

    c = c_vec[n_data];

    n_data = n_data + 1;

  }

  return;

# undef N_MAX

}

void binary_vector_next ( int n, int bvec[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {  

    if ( bvec[i] == 1 )

    {

      bvec[i] = 0;

    }

    else 

    {

      bvec[i] = 1;

      break;

    }

  }

  return;

}

bool bvec_add ( int n, int bvec1[], int bvec2[], int bvec3[] )

{

  int base = 2;

  int i;

  bool overflow;

  overflow = false;

  for ( i = 0; i < n; i++ )

  {

    bvec3[i] = bvec1[i] + bvec2[i];

  }

  for ( i = n - 1; 0 <= i; i-- )

  {

    while ( base <= bvec3[i] )

    {

      bvec3[i] = bvec3[i] - base;

      if ( 0 < i )

      {

        bvec3[i-1] = bvec3[i-1] + 1;

      }

      else

      {

        overflow = true;

      }

    }

  }

  return overflow;

}

void bvec_and ( int n, int bvec1[], int bvec2[], int bvec3[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    bvec3[i] = i4_min ( bvec1[i], bvec2[i] );

  }

  return;

}

bool bvec_check ( int n, int bvec[] )

{

  int base = 2;

  int i;

  for ( i = 0; i < n; i++ )

  {

    if ( bvec[i] < 0 || base <= bvec[i] )

    {

      return true;

    }

  }

  return false;

}

void bvec_complement2 ( int n, int bvec1[], int bvec2[] )

{

  int base = 2;

  bool error;

  int i;

  int *bvec3;

  int *bvec4;

  bvec3 = new int[n];

  bvec4 = new int[n];

  

  for ( i = 0; i < n; i++ )

  {

    bvec3[i] = ( base - 1 ) - bvec1[i];

  }

  for ( i = 0; i < n - 1; i++ )

  {

    bvec4[i] = 0;

  }

  bvec4[n-1] = 1;

  error = bvec_add ( n, bvec3, bvec4, bvec2 );

  delete [] bvec3;

  delete [] bvec4;

  

  return;

}

void bvec_mul ( int n, int bvec1[], int bvec2[], int bvec3[] )

{

  int base = 2;

  int *bveca;

  int *bvecb;

  int *bvecc;

  int carry;

  int i;

  int j;

  int product_sign;

  bveca = new int[n];

  bvecb = new int[n];

  bvecc = new int[n];

  for ( i = 0; i < n; i++ )

  {

    bveca[i] = bvec1[i];

  }

  for ( i = 0; i < n; i++ )

  {

    bvecb[i] = bvec2[i];

  }

  product_sign = 1;

  if ( bveca[0] != 0 )

  {

    product_sign = - product_sign;

    bvec_complement2 ( n, bveca, bveca );

  }

  if ( bvecb[0] != 0 )

  {

    product_sign = - product_sign;

    bvec_complement2 ( n, bvecb, bvecb );

  }

  for ( i = 0; i < n; i++ )

  {

    bvecc[i] = 0;

  }

  for ( i = 1; i <= n - 1; i++ )

  {

    for ( j = 1; j <= n - i; j++ )

    {

      bvecc[j] = bvecc[j] + bveca[n-i] * bvecb[j+i-1];

    }

  }

  for ( i = n - 1; 1 <= i; i--)

  {

    carry = bvecc[i] / base;

    bvecc[i] = bvecc[i] - carry * base;

    if ( 1 < i )

    {

      bvecc[i-1] = bvecc[i-1] + carry;

    }

  }

  if ( product_sign < 0 )

  {

    bvec_complement2 ( n, bvecc, bvecc );

  }

  for ( i = 0; i < n; i++ )

  {

    bvec3[i] = bvecc[i];

  }

  delete [] bveca;

  delete [] bvecb;

  delete [] bvecc;

  return;

}

void bvec_next ( int n, int bvec[] )

{

  int i;

  for ( i = n - 1; 0 <= i; i-- )

  {

    if ( bvec[i] == 0 )

    {

      bvec[i] = 1;

      return;

    }

    bvec[i] = 0;

  }

  return;

}

void bvec_not ( int n, int bvec1[], int bvec2[] )

{

  int base = 2;

  int i;

  for ( i = 0; i < n; i++ )

  {

    bvec2[i] = ( base - 1 ) - bvec1[i];

  }

  return;

}

void bvec_or ( int n, int bvec1[], int bvec2[], int bvec3[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    bvec3[i] = i4_max ( bvec1[i], bvec2[i] );

  }

  return;

}

void bvec_print ( int n, int bvec[], string title )

{

  int i;

  int ihi;

  int ilo;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  for ( ilo = 0; ilo < n; ilo = ilo + 70 )

  {

    ihi = i4_min ( ilo + 70 - 1, n - 1 );

    cout << "   ";

    for ( i = ilo; i <= ihi; i++ )

    {

      cout << bvec[i];

    }

    cout << "\n";

  }

  return;

}

void bvec_reverse ( int n, int bvec1[], int bvec2[] )

{

  int *bvec3;

  int i;

  for ( i = 0; i < n; i++ )

  {

    bvec3[i] = bvec1[n-1-i];

  }

  for ( i = 0; i < n; i++ )

  {

    bvec2[i] = bvec3[i];

  }

  return;

}

void bvec_sub ( int n, int bvec1[], int bvec2[], int bvec3[] )

{

  int *bvec4;

  int i;

  bvec4 = new int[n];

  bvec_complement2 ( n, bvec2, bvec4 );

  bvec_add ( n, bvec1, bvec4, bvec3 );

  delete [] bvec4;

  return;

}

int bvec_to_i4 ( int n, int bvec[] )

{

  int base = 2;

  int *bvec2;

  int i;

  int i4;

  int i4_sign;

  bvec2 = new int[n];

  for ( i = 0; i < n; i++ )

  {

    bvec2[i] = bvec[i];

  }

  if ( bvec2[0] == base - 1 )

  {

    i4_sign = -1;

    bvec2[0] = 0;

    bvec_complement2 ( n-1, bvec2+1, bvec2+1 );

  }

  else

  {

    i4_sign = 1;

  }

  i4 = 0;

  for ( i = 1; i < n; i++ )

  {

    i4 = base * i4 + bvec2[i];

  }

  i4 = i4_sign * i4;

  delete [] bvec2;

  return i4;

}

void bvec_xor ( int n, int bvec1[], int bvec2[], int bvec3[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    bvec3[i] = ( bvec1[i] + bvec2[i] ) % 2;

  }

  return;

}

void catalan ( int n, int c[] )

{

  int i;

  if ( n < 0 )

  {

    return;

  }

  c[0] = 1;

  for ( i = 1; i <= n; i++ )

  {

    c[i] = ( c[i-1] * 2 * ( 2 * i - 1 ) ) / ( i + 1 );

  }

  return;

}

void catalan_row_next ( bool next, int n, int irow[] )

{

  int i;

  int j;

  if ( n < 0 )

  {

    return;

  }

  if ( !next )

  {

    irow[0] = 1;

    for ( i = 1; i <= n; i++ )

    {

      irow[i] = 0;

    }

    for ( i = 1; i <= n; i++ )

    {

      irow[0] = 1;

      for ( j = 1; j <= i-1; j++ )

      {

        irow[j] = irow[j] + irow[j-1];

      }

      irow[i] = irow[i-1];

    }

  }

  else

  {

    irow[0] = 1;

    for ( j = 1; j <= n-1; j++ )

    {

      irow[j] = irow[j] + irow[j-1];

    }

    if ( 1 <= n )

   {

      irow[n] = irow[n-1];

    }

  }

  return;

}

void catalan_values ( int &n_data, int &n, int &c )

{

# define N_MAX 11

  int c_vec[N_MAX] = { 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796 };

  int n_vec[N_MAX] = { 0,  1,  2,  3,  4, 5,  6,  7,  8,  9,  10 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  if ( N_MAX <= n_data )

  {

    n_data = 0;

    n = 0;

    c = 0;

  }

  else

  {

    n = n_vec[n_data];

    c = c_vec[n_data];

    n_data = n_data + 1;

  }

  return;

# undef N_MAX

}

void cfrac_to_rat ( int n, int a[], int p[], int q[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    if ( i == 0 )

    {

      p[i] = a[i] * 1 + 0;

      q[i] = a[i] * 0 + 1;

    }

    else if ( i == 1 )

    {

      p[i] = a[i] * p[i-1] + 1;

      q[i] = a[i] * q[i-1] + 0;

    }

    else

    {

      p[i] = a[i] * p[i-1] + p[i-2];

      q[i] = a[i] * q[i-1] + q[i-2];

    }

  }

  return;

}

void cfrac_to_rfrac ( int m, double g[], double h[], double p[], double q[] )

{

  double *a;

  int i;

  int j;

  if ( m == 1 )

  {

    p[0] = g[0];

    q[0] = h[0];

    return;

  }

  a = new double[m*((m+2)/2)];

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < (m+2)/2; j++ )

    {

      a[i+j*m] = 0.0;

    }

  }

  a[0+0*m] = g[0];

  a[1+0*m] = g[0] * h[1];

  for ( i = 2; i < m; i++ )

  {

    a[i+0*m] = h[i] * a[i-1+0*m];

    for ( j = 1; j < (i+2)/2; j++ )

    {

      a[i+j*m] = h[i] * a[i-1+j*m] + g[i] * a[i-2+(j-1)*m];

    }

  }

  for ( j = 0; j < (m+1)/2; j++ )

  {

    p[j] = a[m-1+j*m];

  }

  a[0+0*m] = h[0];

  a[1+0*m] = h[0] * h[1];

  a[1+1*m] = g[1];

  for ( i = 2; i < m; i++ )

  {

    a[i+0*m] = h[i] * a[i-1+0*m];

    for ( j = 1; j < (i+3)/2; j++ )

    {

      a[i+j*m] = h[i] * a[i-1+j*m] + g[i] * a[i-2+(j-1)*m];

    }

  }

  for ( j = 0; j < (m+2)/2; j++ )

  {

    q[j] = a[m-1+j*m];

  }

  delete [] a;

  return;

}

char ch_cap ( char c )

{

  if ( 97 <= c && c <= 122 ) 

  {

    c = c - 32;

  }   

  return c;

}

void change_greedy ( int total, int coin_num, int coin_value[], int &change_num, 

  int change[] )

{

  int j;

  change_num = 0;

  j = coin_num - 1;

  while ( 0 <= j )

  {

    if ( coin_value[j] <= total )

    {

      break;

    }

    j = j - 1;

  }

  if ( j < 0 )

  {

    return;

  }

  while ( 0 < total )

  {

    if ( coin_value[j] <= total )

    {

      total = total - coin_value[j];

      change[change_num] = j;

      change_num = change_num + 1;

    }

    else

    {

      j = j - 1;

      if ( j < 0 )

      {

        break;

      }

    }

  }

  return;

}

void change_next ( int total, int coin_num, int coin_value[], int &change_num, 

  int change[], bool &done  )

{

  int change_num2;

  int coin_num2;

  int i;

  int last;

  int total2;

  if ( done )

  {

    if ( !i4vec_ascends ( coin_num, coin_value ) )

    {

      cerr << "\n";

      cerr << "CHANGE_NEXT - Fatal error!\n";

      cerr << "  COIN_VALUE array is not in ascending order.\n";

      exit ( 1 );

    }

    change_greedy ( total, coin_num, coin_value, change_num, change );

    if ( change_num == total )

    {

      done = true;

    }

    else

    {

      done = false;

    }

    return;

  }

  last = -1;

  for ( i = change_num-1; 0 <= i; i-- )

  {

    if ( change[i] != 0 )

    {

      last = i;

      break;

    }

  }

  if ( last == -1 )

  {

    done = true;

    return;

  }

  total2 = 0;

  for ( i = last; i <= change_num-1; i++ )

  {

    total2 = total2 + coin_value [ change[i] ];

  }

  coin_num2 = change[last];

  change_greedy ( total2, coin_num2, coin_value, change_num2,

    change+last );

  change_num = last + change_num2;

  return;

}

bool chinese_check ( int n, int m[] )

{

  int i;

  int j;

  for ( i = 0; i < n; i++ )

  {

    if ( m[i] <= 0 )

    {

      return true;

    }

  }

  for ( i = 0; i < n; i++ )

  {

    for ( j = i+1; j < n; j++ )

    {

      if ( m[i] == 1 && m[j] == 1 )

      {

        return true;

      }

    }

  }

  if ( !i4vec_pairwise_prime ( n, m ) )

  {

    return true;

  }

  return false;

}

int chinese_to_i4 ( int n, int m[], int r[] )

{

  int a;

  int *b;

  int big_m;

  int c;

  bool error;

  int i;

  int j;

  error = chinese_check ( n, m );

  if ( error )

  {

    cerr << "\n";

    cerr << "CHINESE_TO_I4 - Fatal error!\n";

    cerr << "  The moduluses are not legal.\n";

    exit ( 1 );

  }

  b = new int[n];

  big_m = 1;

  for ( i = 0; i < n; i++ )

  {

    big_m = big_m * m[i];

  }

  for ( i = 0; i < n; i++ )

  {

    a = big_m / m[i];

    c = 1;

    b[i] = congruence ( a, m[i], c, error );

  }

  j = 0;

  for ( i = 0; i < n; i++ )

  {

    j = ( j + r[i] * b[i] * ( big_m / m[i] ) ) % big_m;

  }

  delete [] b;

  return j;

}

void comb_next ( int n, int k, int a[], bool &done )

{

  int i;

  int j;

  if ( done )

  {

    if ( k <= 0 )

    {

      return;

    }

    i4vec_indicator ( k, a );

    done = false; 

  }

  else

  {

    if ( a[k-1] < n )

    {

      a[k-1] = a[k-1] + 1;

      return;

    }

    for ( i = k; 2 <= i; i-- )

    {

      if ( a[i-2] < n-k+i-1 )

      {

        a[i-2] = a[i-2] + 1;

        for ( j = i; j <= k; j++ )

        {

          a[j-1] = a[i-2] + j - ( i-1 );

        }

        return;

      }

    }

    done = true;

  }

  return;

}

void comb_row ( bool next, int n, int row[] )

{

  int i;

  int j;

  if ( n < 0 )

  {

    return;

  }

  if ( next )

  {

    for ( i = n-1; 1 <= i; i-- )

    {

      row[i] = row[i] + row[i-1];

    }

    row[n] = 1;

  }

  else

  {

    row[0] = 1;

    for ( i = 1; i <= n; i++ )

    {

      row[i] = 0;

    }

    for ( j = 1; j <= n; j++ )

    {

      for ( i = j; 1 <= i; i-- )

      {

        row[i] = row[i] + row[i-1];

      }

    }

  }

  return;

}

void comb_unrank ( int m, int n, int rank, int a[] )

{

  int i;

  int j;

  int k;

  k = 0;

  for ( i = 1; i <= n-1; i++ )

  {

    a[i-1] = 0;

    if ( 1 < i )

    {

      a[i-1] = a[i-2];

    }

    for ( ; ; )

    {

      a[i-1] = a[i-1] + 1;

      j = i4_choose ( m-a[i-1], n-i );

      k = k + j;

      if ( rank <= k )

      {

        break;

      }

    }

    k = k - j;

  }

  a[n-1] = a[n-2] + rank - k;

  return;

}

int comp_enum ( int n, int k )

{

  int number;

  number = i4_choose ( n + k - 1, n );

  return number;

}

void comp_next ( int n, int k, int a[], bool &more, int &h, int &t )

{

  int i;

  if ( !( more ) )

  {

    t = n;

    h = 0;

    a[0] = n;

    for ( i = 1; i < k; i++ )

    {

       a[i] = 0;

    }

  }

  else

  {

    if ( 1 < t )

    {

      h = 0;

    }

    h = h + 1;

    t = a[h-1];

    a[h-1] = 0;

    a[0] = t - 1;

    a[h] = a[h] + 1;

  }

  more = ( a[k-1] != n );

  return;

}

void comp_next_grlex ( int kc, int xc[] )

{

  int i;

  int im1;

  int j;

  int t;

  if ( kc < 1 )

  {

    cerr << "\n";

    cerr << "COMP_NEXT_GRLEX - Fatal error!\n";

    cerr << "  KC < 1\n";

    exit ( 1 );

  }

  for ( i = 0; i < kc; i++ )

  {

    if ( xc[i] < 0 )

    {

      cerr << "\n";

      cerr << "COMP_NEXT_GRLEX - Fatal error!\n";

      cerr << "  XC[I] < 0\n";

      exit ( 1 );

    }

  }

  i = 0;

  for ( j = kc; 1 <= j; j-- )

  {

    if ( 0 < xc[j-1] )

    {

      i = j;

      break;

    }

  }

  if ( i == 0 )

  {

    xc[kc-1] = 1;

    return;

  }

  else if ( i == 1 )

  {

    t = xc[0] + 1;

    im1 = kc;

  }

  else if ( 1 < i )

  {

    t = xc[i-1];

    im1 = i - 1;

  }

  xc[i-1] = 0;

  xc[im1-1] = xc[im1-1] + 1;

  xc[kc-1] = xc[kc-1] + t - 1;

  return;

}

void comp_random ( int n, int k, int &seed, int a[] )

{

  int i;

  int l;

  int m;

  ksub_random ( n+k-1, k-1, seed, a );

  a[k-1] = n + k;

  l = 0;

  for ( i = 0; i < k; i++ )

  {

    m = a[i];

    a[i] = a[i] - l - 1;

    l = m;

  }

  return;

}

int *comp_random_grlex ( int kc, int nc, int &seed, int &rank )

{

  int rank_max;

  int rank_min;

  int *xc;

  rank_min = 1;

  rank_max = i4_choose ( nc + kc, nc );

  rank = i4_uniform_ab ( rank_min, rank_max, seed );

  xc = comp_unrank_grlex ( kc, rank );

  return xc;

}

int comp_rank_grlex ( int kc, int xc[] )

{

  int i;

  int j;

  int ks;

  int n;

  int nc;

  int ns;

  int rank;

  int tim1;

  int *xs;

  if ( kc < 1 )

  {

    cerr << "\n";

    cerr << "COMP_RANK_GRLEX - Fatal error!\n";

    cerr << "  KC < 1\n";

    exit ( 1 );

  }

  for ( i = 0; i < kc; i++ )

  {

    if ( xc[i] < 0 )

    {

      cerr << "\n";

      cerr << "COMP_RANK_GRLEX - Fatal error!\n";

      cerr << "  XC[I] < 0\n";

      exit ( 1 );

    }

  }

  nc = i4vec_sum ( kc, xc );

  ns = nc + kc - 1;

  ks = kc - 1;

  xs = new int[ks];

  xs[0] = xc[0] + 1;

  for ( i = 2; i < kc; i++ )

  {

    xs[i-1] = xs[i-2] + xc[i-1] + 1;

  }

  rank = 1;

  for ( i = 1; i <= ks; i++ )

  {

    if ( i == 1 )

    {

      tim1 = 0;

    }

    else

    {

      tim1 = xs[i-2];

    }

    if ( tim1 + 1 <= xs[i-1] - 1 )

    {

      for ( j = tim1 + 1; j <= xs[i-1] - 1; j++ )

      {

        rank = rank + i4_choose ( ns - j, ks - i );

      }

    }

  }

  for ( n = 0; n < nc; n++ )

  {

    rank = rank + i4_choose ( n + kc - 1, n );

  }

  delete [] xs;

  return rank;

}

void comp_to_ksub ( int nc, int kc, int ac[], int &ns, int &ks, int as[] )

{

  int i;

  ns = nc + kc - 1;

  ks = kc - 1;

  as[0] = ac[0] + 1;

  for ( i = 1; i < kc - 1; i++ )

  {

    as[i] = as[i-1] + ac[i] + 1;

  }

  return;

}

/******************************************************************************/

int *comp_unrank_grlex ( int kc, int rank )

/******************************************************************************/

{

  int i;

  int j;

  int ks;

  int nc;

  int nksub;

  int ns;

  int r;

  int rank1;

  int rank2;

  int *xc;

  int *xs;

  if ( kc < 1 )

  {

    cerr << "\n";

    cerr << "COMP_UNRANK_GRLEX - Fatal error!\n";

    cerr << "  KC < 1\n";

    exit ( 1 );

  }

  if ( rank < 1 )

  {

    cerr << "\n";

    cerr << "COMP_UNRANK_GRLEX - Fatal error!\n";

    cerr << "  RANK < 1\n";

    exit ( 1 );

  }

  rank1 = 1;

  nc = -1;

  for ( ; ; )

  {

    nc = nc + 1;

    r = i4_choose ( nc + kc - 1, nc );

    if ( rank < rank1 + r )

    {

      break;

    }

    rank1 = rank1 + r;

  }

  rank2 = rank - rank1;

  ks = kc - 1;

  ns = nc + kc - 1;

  xs = new int[ks];

  nksub = i4_choose ( ns, ks );

  j = 1;

  for ( i = 1; i <= ks; i++ )

  {

    r = i4_choose ( ns - j, ks - i );

    while ( r <= rank2 && 0 < r )

    {

      rank2 = rank2 - r;

      j = j + 1;

      r = i4_choose ( ns - j, ks - i );

    }

    xs[i-1] = j;

    j = j + 1;

  }

  xc = new int[kc];

  xc[0] = xs[0] - 1;

  for ( i = 2; i < kc; i++ )

  {

    xc[i-1] = xs[i-1] - xs[i-2] - 1;

  }

  xc[kc-1] = ns - xs[ks-1];

  delete [] xs;

  return xc;

}

/******************************************************************************/

int compnz_enum ( int n, int k )

/******************************************************************************/

/*

  Purpose:

    COMPNZ_ENUM returns the number of nonzero compositions of the N into K parts.

  Discussion:

    A composition of the integer N into K nonzero parts is an ordered sequence

    of K positive integers which sum to N.  The compositions (1,2,1)

    and (1,1,2) are considered to be distinct.

    The 10 compositions of 6 into three nonzero parts are:

      4 1 1,  3 2 1,  3 1 2,  2 3 1,  2 2 2,  2 1 3,

      1 4 1,  1 3 2,  1 2 3,  1 1 4.

    The formula for the number of compositions of N into K nonzero

    parts is

      Number = ( N - 1 )! / ( ( N - K )! * ( K - 1 )! )

    (Describe the composition using N-K '1's and K-1 dividing lines '|'.

    The number of distinct permutations of these symbols is the number

    of compositions into nonzero parts.  This is equal to the number of

    permutations of  N-1 things, with N-K identical of one kind

    and K-1 identical of another.)

    Thus, for the above example, we have:

      Number = ( 6 - 1 )! / ( ( 6 - 3 )! * ( 3 - 1 )! ) = 10

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    05 December 2013

  Author:

    John Burkardt

  Reference:

    Albert Nijenhuis, Herbert Wilf,

    Combinatorial Algorithms for Computers and Calculators,

    Second Edition,

    Academic Press, 1978,

    ISBN: 0-12-519260-6,

    LC: QA164.N54.

  Parameters:

    Input, int N, the integer whose compositions are desired.

    Input, int K, the number of parts in the composition.

    Output, int COMPNZ_ENUM, the number of compositions of N into

    K nonzero parts.

*/

{

  int number;

  number = i4_choose ( n - 1, n - k );

  return number;

}

void compnz_next ( int n, int k, int a[], bool &more )

{

  int i;

  static int h = 0;

  static int t = 0;

  if ( n < k )

  {

    more = false;

    for ( i = 0; i < k; i++ )

    {

      a[i] = -1;

    }

    return;

  }

  if ( !( more ) )

  {

    t = n - k;

    h = 0;

    a[0] = n - k;

    for ( i = 1; i < k; i++ )

    {

       a[i] = 0;

    }

  }

  else

  {

    for ( i = 0; i < k; i++ )

    {

      a[i] = a[i] - 1;

    }

    if ( 1 < t )

    {

      h = 0;

    }

    h = h + 1;

    t = a[h-1];

    a[h-1] = 0;

    a[0] = t - 1;

    a[h] = a[h] + 1;

  }

  more = ( a[k-1] != ( n - k ) );

  for ( i = 0; i < k; i++ )

  {

    a[i] = a[i] + 1;

  }

  return;

}

void compnz_random ( int n, int k, int &seed, int a[] )

{

  int i;

  int l;

  int m;

  if ( n < k )

  {

    for ( i = 0; i < k; i++ )

    {

      a[i] = -1;

    }

    return;

  }

  ksub_random ( n-1, k-1, seed, a );

  a[k-1] = n;

  l = 0;

  for ( i = 0; i < k; i++ )

  {

    m = a[i];

    a[i] = a[i] - l - 1;

    l = m;

  }

  for ( i = 0; i < k; i++ )

  {

    a[i] = a[i] + 1;

  }

  return;

}

void compnz_to_ksub ( int nc, int kc, int ac[], int &ns, int &ks, int as[] )

{

  int i;

  ns = nc;

  ks = kc - 1;

  as[0] = ac[0];

  for ( i = 1; i < kc - 1; i++ )

  {

    as[i] = as[i-1] + ac[i];

  }

  return;

}

int congruence ( int a, int b, int c, bool &error )

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

  error = false;

  x = 0;

  y = 0;

  if ( a == 0 && b == 0 && c == 0 )

  {

    x = 0;

    return x;

  }

  else if ( a == 0 && b == 0 && c != 0 )

  {

    error = true;

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

      error = true;

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

      error = true;

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

    error = true;

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

      error = true;

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

void count_pose_random ( int &seed, int blocks[], int &goal )

{

  int i;

  int ind[6];

  static int stuff[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 50, 75, 100 };

  goal = i4_uniform_ab ( 100, 999, seed );

  ksub_random ( 14, 6, seed, ind );

  for ( i = 0; i < 6; i++ )

  {

    blocks[i] = stuff[ind[i]-1];

  }

  return;

}

void debruijn ( int m, int n, int string[] )

{

  int i;

  int iedge;

  int *inode;

  int *ivec;

  int j;

  int *jnode;

  int *jvec;

  int k;

  int *knode;

  int nedge;

  int nnode;

  bool success;

  int *trail;

  nnode = i4_power ( m, n-1 );

  nedge = i4_power ( m, n );

  inode = new int[nedge];

  ivec = new int[n-1];

  jnode = new int[nedge];

  jvec = new int[n-1];

  knode = new int[nedge];

  iedge = 0;

  for ( i = 1; i <= nnode; i++ )

  {

    index_unrank0 ( n-1, m, i, ivec );

    for ( k = 1; k <= m; k++ )

    {

      for ( j = 0; j < n-2; j++ )

      {

        jvec[j] = ivec[j+1];

      }

      jvec[n-2] = k;

      j = index_rank0 ( n-1, m, jvec );

      inode[iedge] = i;

      jnode[iedge] = j;

      knode[iedge] = k;

      iedge = iedge + 1;

    }

  }

  delete [] ivec;

  delete [] jvec;

  trail = new int[nedge];

  digraph_arc_euler ( nnode, nedge, inode, jnode, success, trail );

  for ( i = 0; i < nedge; i++ )

  {

    string[i] = knode[trail[i]-1];

  }

  delete [] inode;

  delete [] jnode;

  delete [] knode;

  delete [] trail;

  return;

}

void dec_add ( int mantissa1, int exponent1, int mantissa2, int exponent2, 

  int dec_digit, int &mantissa, int &exponent )

{

  if ( mantissa1 == 0 )

  {

    mantissa = mantissa2;

    exponent = exponent2;

    dec_round ( mantissa, exponent, dec_digit, mantissa, exponent );

    return;

  }

  else if ( mantissa2 == 0 )

  {

    mantissa = mantissa1;

    exponent = exponent1;

    dec_round ( mantissa, exponent, dec_digit, mantissa, exponent );

    return;

  }

  if ( exponent1 < exponent2 )

  {

    mantissa2 = mantissa2 * i4_power ( 10, exponent2 - exponent1 );

    exponent2 = exponent1;

    mantissa = mantissa1 + mantissa2;

    exponent = exponent1;

  }

  else if ( exponent1 == exponent2 ) 

  {

    mantissa = mantissa1 + mantissa2;

    exponent = exponent1;

  }

  else if ( exponent2 < exponent1 )

  {

    mantissa1 = mantissa1 * i4_power ( 10, exponent1 - exponent2 );

    exponent1 = exponent2;

    mantissa = mantissa1 + mantissa2;

    exponent = exponent2;

  }

  dec_round ( mantissa, exponent, dec_digit, mantissa, exponent );

  return;

}

void dec_div ( int mantissa1, int exponent1, int mantissa2, int exponent2,

  int dec_digit, int &mantissa, int &exponent, bool &error )

{

  double dval;

  int exponent3;

  int mantissa3;

  error = false;

  if ( mantissa1 == 0 )

  {

    mantissa = 0;

    exponent = 0;

    return;

  }

  if ( mantissa2 == 0 )

  {

    error = true;

    mantissa = 0;

    exponent = 0;

    return;

  }

  if ( mantissa1 == mantissa2 && exponent1 == exponent2 )

  {

    mantissa = 1;

    exponent = 0;

    return;

  }

  if ( mantissa1 == mantissa2 )

  {

    mantissa = 1;

    exponent = exponent1 - exponent2;

    return;

  }

  if ( ( mantissa1 / mantissa2 ) * mantissa2 == mantissa1 )

  {

    mantissa = mantissa1 / mantissa2;

    exponent = exponent1 - exponent2;

    return;

  }

  dval = ( double ) mantissa1 / ( double ) mantissa2;

  r8_to_dec ( dval, dec_digit, mantissa3, exponent3 );

  mantissa = mantissa3;

  exponent = exponent3 + exponent1 - exponent2;

  return;

}

void dec_mul ( int mantissa1, int exponent1, int mantissa2, int exponent2, 

  int dec_digit, int &mantissa, int &exponent )

{

  double dval;

  int exponent3;

  int mantissa3;

  double temp;

  if ( mantissa1 == 0 || mantissa2 == 0 )

  {

    mantissa = 0;

    exponent = 0;

    return;

  }

  if ( abs ( mantissa1 ) == 1 || abs ( mantissa2 ) == 1 )

  {

    mantissa = mantissa1 * mantissa2;

    exponent = exponent1 + exponent2;

    return;

  }

  temp = log ( ( double ) abs ( mantissa1 ) ) 

       + log ( ( double ) abs ( mantissa2 ) );

  if ( temp < log ( ( double ) i4_huge ( ) ) )

  {

    mantissa = mantissa1 * mantissa2;

    exponent = exponent1 + exponent2;

  }

  else

  {

    dval = ( double ) mantissa1 * ( double ) mantissa2;

    r8_to_dec ( dval, dec_digit, mantissa3, exponent3 );

    mantissa = mantissa3;

    exponent = exponent3 + ( exponent1 + exponent2 );

  }

  dec_round ( mantissa, exponent, dec_digit, mantissa, exponent );

  return;

}

void dec_round ( int mantissa1, int exponent1, int dec_digit, 

  int &mantissa2, int &exponent2 )

{

  int i;

  int limit;

  int sgn;

  mantissa2 = mantissa1;

  exponent2 = exponent1;

  if ( mantissa2 == 0 )

  {

    exponent2 = 0;

    return;

  }

  sgn = 1;

  if ( mantissa2 < 0 ) 

  {

    mantissa2 = - ( mantissa2 );

    sgn = - sgn;

  }

  limit = 1;

  for ( i = 1; i <= dec_digit; i++ )

  {

    limit = limit * 10;

  }

  while ( limit <= abs ( mantissa2 ) )

  {

    mantissa2 = ( mantissa2 + 5 ) / 10;

    exponent2 = exponent2 + 1;

  }

  if ( 0 < mantissa )

  {

    while ( ( mantissa2 / 10 ) * 10 == mantissa2 )

    {

      mantissa2 = mantissa2 / 10;

      exponent2 = exponent2 + 1;

    }

  }

  mantissa2 = sgn * ( mantissa2 );

  return;

}

double dec_to_r8 ( int mantissa, int exponent )

{

  double value;

  value = mantissa * pow ( 10.0, exponent );

  return value;

}

void dec_to_rat ( int mantissa, int exponent, int &rat_top, int &rat_bot )

{

  int gcd;

  int i;

  if ( exponent == 0 )

  {

    rat_top = mantissa;

    rat_bot = 1;

  }

  else if ( 0 < exponent )

  {

    rat_top = mantissa;

    for ( i = 1; i <= exponent; i++ )

    {

      rat_top = rat_top * 10;

    }

    rat_bot = 1;

  }

  else

  {

    rat_top = mantissa;

    rat_bot = 1;

    for ( i = 1; i <= -exponent; i++ )

    {

      rat_bot = rat_bot * 10;

    }

    gcd = i4_gcd ( rat_top, rat_bot );

    rat_top = rat_top / gcd;

    rat_bot = rat_bot / gcd;

  }

  return;

}

char *dec_to_s ( int mantissa, int exponent )

{

  int digit;

  int i;

  int last;

  int mantissa_exponent;

  int mantissa_exponent_copy;

  int mantissa_10;

  int pos;

  char *s;

  int s_length;

  int sign;

  s_length = dec_width ( mantissa, exponent ) + 1;

  s = new char[s_length];

  for ( i = 0; i < s_length - 1; i++ )

  {

    s[i] = '0';

  }

  s[s_length-1] = '\0';

  if ( mantissa == 0 )

  {

    return s;

  }

  pos = 0;

  if ( mantissa < 0 )

  {

    s[pos] = '-';

    pos = pos + 1;

    mantissa = -mantissa;

  }

  mantissa_exponent = i4_log_10 ( mantissa ) + 1;

  mantissa_10 = i4_power ( 10, mantissa_exponent - 1 );

  if ( mantissa_exponent + exponent <= 0 ) 

  {

    s[pos] = '0';

    pos = pos + 1;

    s[pos] = '.';

    pos = pos + 1;

    for ( i = mantissa_exponent + exponent; i < 0; i++ )

    {

      s[pos] = '0';

      pos = pos + 1;

    }

  }

  mantissa_exponent_copy = mantissa_exponent;

  for ( i = 0; i < mantissa_exponent; i++ )

  {

    digit = mantissa / mantissa_10;

    mantissa = mantissa % mantissa_10;

    s[pos] = digit_to_ch ( digit );

    pos = pos + 1;

    mantissa_10 = mantissa_10 / 10;

    mantissa_exponent_copy = mantissa_exponent_copy - 1;

    if ( exponent < 0 )

    {

      if ( mantissa_exponent_copy + exponent == 0 )

      {

        s[pos] = '.';

        pos = pos + 1;

      }

    }

  }

  if ( 0 < exponent )

  {

    for ( i = exponent; 0 < i; i-- )

    {

      s[pos] = '0';

      pos = pos + 1;

    }

  }

  return s;

}

int dec_width ( int mantissa, int exponent )

{

  int mantissa_abs;

  int ten_pow;

  int value;

  value = 1;

  if ( mantissa == 0 )

  {

    return value;

  }

  ten_pow = 10;

  mantissa_abs = abs ( mantissa );

  while ( ten_pow <= mantissa_abs )

  {

    value = value + 1;

    ten_pow = ten_pow * 10;

  }

  if ( 0 <= exponent )

  {

    value = value + exponent;

  }

  else if ( -value < exponent )

  {

    value = value + 1;

  }

  else if ( exponent <= -value )

  {

    value = 2 - exponent;

  }

  if ( mantissa < 0 )

  {

    value = value + 1;

  }

  return value;

}

void decmat_det ( int n, int atop[], int abot[], int dec_digit, 

  int &dtop, int &dbot )

{

  bool even;

  int i;

  int *iarray;

  int ibot;

  int ibot1;

  int ibot2;

  int itop;

  int itop1;

  int itop2;

  bool more;

  dtop = 0;

  dbot = 1;

  iarray = new int[n];

  more = false;

  for ( ; ; )

  {

    perm_next ( n, iarray, more, even );

    if ( even )

    {

      itop = 1;

    }

    else

    {

      itop = -1;

    }

    ibot = 0;

    for ( i = 0; i < n; i++ )

    {

      itop1 = itop;

      ibot1 = ibot;

      itop2 = atop[i+(iarray[i]-1)*n];

      ibot2 = abot[i+(iarray[i]-1)*n];

      dec_mul ( itop1, ibot1, itop2, ibot2, dec_digit, itop, ibot );

    }

    dec_add ( itop, ibot, dtop, dbot, dec_digit, dtop, dbot );

    if ( !more )

    {

      break;

    }

  }

  delete [] iarray;

  return;

}

void decmat_print ( int m, int n, int a[], int b[], string title )

{

  int exponent;

  int i;

  int j;

  int jmax;

  int jmin;

  int kmax;

  int mantissa;

  int ncolum = 80;

  int npline;

  char *s;

  kmax = 0;

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      kmax = i4_max ( kmax, dec_width ( a[i+j*m], b[i+j*m] ) );

    }

  }

  s = new char[kmax];

  kmax = kmax + 2;

  npline = ncolum / kmax;

  for ( jmin = 0; jmin < n; jmin = jmin + npline )

  {

    jmax = i4_min ( jmin+npline-1, n-1 );

    cout << "\n";

    cout << title << "\n";

    cout << "\n";

    if ( 0 < jmin || jmax < n-1 )

    {

      cout << "Columns " << jmin << " to " << jmax << "\n";

      cout << "\n";

    }

    for ( i = 0; i < m; i++ )

    {

      for ( j = jmin; j <= jmax; j++ )

      {

        mantissa = a[i+j*m];

        exponent = b[i+j*m];

        s = dec_to_s ( mantissa, exponent );

        cout << setw(kmax) << s << "  ";

      }

      cout << "\n";

    }

  }

  delete [] s;

  return;

}

void derange_back_candidate ( int n, int a[], int k, int &nstack, int stack[], 

  int ncan[] )

{

  int ican;

  int *ifree;

  int nfree;

  nfree = n - k + 1;

  ifree = new int[n];

  perm_free ( k-1, a, nfree, ifree );

  ncan[k-1] = 0;

  for ( ican = 0; ican < nfree; ican++ )

  {

    if ( ifree[ican] != k )

    {

      ncan[k-1] = ncan[k-1] + 1;

      stack[nstack] = ifree[ican];

      nstack = nstack + 1;

    }

  }

  delete [] ifree;

  return;

}

void derange_back_next ( int n, int a[], bool &more )

{

  int i;

  static int indx = -1;

  static int k = -1;

  static int *ncan = NULL;

  static int *stack = NULL;

  static int stack_max = -1;

  static int stack_num = -1;

  if ( !( more ) )

  {

    if ( n < 2 )

    {

      more = false;

      return;

    }

    indx = 0;

    k = 0;

    stack_max = ( n * ( n + 1 ) ) / 2;

    stack_num = 0;

    if ( stack )

    {

      delete [] stack;

    }

    stack = new int[stack_max];

    for ( i = 0; i < stack_max; i++ )

    {

      stack[i] = 0;

    }

    if ( ncan )

    {

      delete [] ncan;

    }

    ncan = new int[n];

    for ( i = 0; i < n; i++ )

    {

      ncan[i] = 0;

    }

    more = true;

  }

  for ( ; ; )

  {

    i4vec_backtrack ( n, stack_max, stack, a, indx, k, stack_num, ncan );

    if ( indx == 1 )

    {

      break;

    }

    else if ( indx == 2 )

    {

      derange_back_candidate ( n, a, k, stack_num, stack, ncan );

    }

    else

    {

      more = false;

      delete [] ncan;

      ncan = NULL;

      delete [] stack;

      stack = NULL;

      break;

    }

  }

  return;

}

bool derange_check ( int n, int a[] )

{

  int i;

  for ( i = 1; i <= n; i++ )

  {

    if ( a[i-1] == i )

    {

      return false;

    }

  }

  return true;

}

int derange_enum ( int n )

{

  int i;

  int value;

  int value1;

  int value2;

  if ( n < 0 )

  {

    value = 0;

  }

  else if ( n == 0 )

  {

    value = 1;

  }

  else if ( n == 1 )

  {

    value = 0;

  }

  else if ( n == 2 )

  {

    value = 1;

  }

  else

  {

    value1 = 0;

    value = 1;

    for ( i = 3; i <= n; i++ )

    {

      value2 = value1;

      value1 = value;

      value = ( i - 1 ) * ( value1 + value2 );

    }

  }

  return value;

}

void derange_enum2 ( int n, int d[] )

{

  int i;

  d[0] = 1;

  d[1] = 0;

  for ( i = 2; i <= n; i++ )

  {

    d[i] = ( i - 1 ) * ( d[i-1] + d[i-2] );

  }

  return;

}

int derange_enum3 ( int n )

{

# define E 2.718281828459045

  int value;

  if ( n < 0 )

  {

    value = -1;

  }

  else if ( n == 0 )

  {

    value = 1;

  }

  else if ( n == 1 )

  {

    value = 0;

  }

  else

  {

    value = ( int ) ( 0.5 + ( r8_factorial ( n ) / E ) );

  }

  return value;

# undef E

}

void derange_weed_next ( int n, int a[], bool &more )

{

  bool deranged;

  static int maxder = 0;

  static int numder = 0;

  if ( !( more ) )

  {

    maxder = derange_enum ( n );

    numder = 0;

  }

  if ( maxder == 0 )

  {

    more = false;

    return;

  }

  for ( ; ; )

  {

    perm_lex_next ( n, a, more );

    deranged = derange_check ( n, a );

    if ( deranged )

    {

      break;

    }

  }

  numder = numder + 1;

  if ( maxder <= numder )

  {

    more = false;

  }

  return;

}

char digit_to_ch ( int digit )

{

  if ( 0 <= digit && digit <= 9 )

  {

    return ( digit + 48 );

  }

  else

  {

    return '*';

  }

}

void digraph_arc_euler ( int nnode, int nedge, int inode[], int jnode[], 

  bool &success, int trail[] )

{

  bool *candid;

  int *endnod;

  int i;

  int istak;

  int j;

  int k;

  int l;

  int len;

  int lensol;

  int lenstk;

  int *stack;

  for ( i = 0; i < nedge; i++ )

  {

    trail[i] = 0;

  }

  endnod = new int[nedge];

  for ( i = 0; i < nedge; i++ )

  {

    endnod[i] = 0;

  }

  for ( i = 1; i <= nedge; i++ )

  {

    j = inode[i-1];

    trail[j-1] = trail[j-1] + 1;

    j = jnode[i-1];

    endnod[j-1] = endnod[j-1] + 1;

  }

  for ( i = 1; i <= nnode; i++ )

  {

    if ( trail[i-1] != endnod[i-1] )

    {

      success = false;

      delete [] endnod;

      return;

    }

  }

  success = true;

  lensol = 1;

  lenstk = 0;

  candid = new bool[nedge];

  stack = new int[2*nedge];

  for ( ; ; )

  {

    if ( lensol == 1 )

    {

      endnod[0] = inode[0];

      stack[0] = 1;

      stack[1] = 1;

      lenstk = 2;

    }

    else

    {

      l = lensol - 1;

      if ( lensol != 2 )

      {

        endnod[l-1] = inode[trail[l-1]-1] + jnode[trail[l-1]-1] - endnod[l-2];

      }

      k = endnod[l-1];

      for ( i = 1; i <= nedge; i++ )

      {

        candid[i-1] = ( k == jnode[i-1] );

      }

      for ( i = 1; i <= l; i++ )

      {

        candid[trail[i-1]-1] = false;

      }

      len = lenstk;

      for ( i = 1; i <= nedge; i++ )

      {

        if ( candid[i-1] )

        {

          len = len + 1;

          stack[len-1] = i;

        }

      }

      stack[len] = len - lenstk;

      lenstk = len + 1;

    }

    for ( ; ; )

    {

      istak = stack[lenstk-1];

      lenstk = lenstk - 1;

      if ( istak != 0 )

      {

        break;

      }

      lensol = lensol - 1;

      if ( lensol == 0 )

      {

        i4vec_reverse ( nedge, trail );

        delete [] candid;

        delete [] endnod;

        delete [] stack;

        return;

      }

    }

    trail[lensol-1] = stack[lenstk-1];

    stack[lenstk-1] = istak - 1;

    if ( lensol == nedge )

    {

      break;

    }

    lensol = lensol + 1;

  }

  i4vec_reverse ( nedge, trail );

  delete [] candid;

  delete [] endnod;

  delete [] stack;

  return;

}

void digraph_arc_print ( int nedge, int inode[], int jnode[], string title )

{

  int i;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  for ( i = 0; i < nedge; i++ )

  {

    cout << setw(6) << i+1 << "  "

         << setw(6) << inode[i] << "  "

         << setw(6) << jnode[i] << "\n";

  }

  return;

}

void diophantine ( int a, int b, int c, bool &error, int &x, int &y )

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

  double norm_new;

  double norm_old;

  int q[N_MAX];

  bool swap;

  int temp;

  int xnew;

  int ynew;

  error = false;

  x = 0;

  y = 0;

  if ( a == 0 && b == 0 && c == 0 )

  {

    x = 0;

    y = 0;

    return;

  }

  else if ( a == 0 && b == 0 && c != 0 )

  {

    error = true;

    x = 0;

    y = 0;

    return;

  }

  else if ( a == 0 && b != 0 && c == 0 )

  {

    x = 0;

    y = 0;

    return;

  }

  else if ( a == 0 && b != 0 && c != 0 )

  {

    x = 0;

    y = c / b;

    if ( ( c % b ) != 0 )

    {

      error = true;

    }

    return;

  }

  else if ( a != 0 && b == 0 && c == 0 )

  {

    x = 0;

    y = 0;

    return;

  }

  else if ( a != 0 && b == 0 && c != 0 )

  {

    x = c / a;

    y = 0;

    if ( ( c % a ) != 0 )

    {

      error = true;

    }

    return;

  }

  else if ( a != 0 && b != 0 && c == 0 )

  {

    g = i4_gcd ( a, b );

    x = b / g;

    y = - a / g;

    return;

  }

  g = i4_gcd ( a, b );

  if ( ( c % g ) != 0 )

  {

    error = true;

    return;

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

    y = 0;

    return;

  }

  else if ( b_mag == 1 )

  {

    x = 0;

    y = b_sign * c_copy;

    return;

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

    q[n-1] = q[n-3] % q[n-2];

    if ( q[n-1] == 1 )

    {

      break;

    }

    n = n + 1;

    if ( N_MAX < n )

    {

      error = true;

      cerr << "\n";

      cerr << "DIOPHANTINE - Fatal error!\n";

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

    i4_swap ( x, y );

  }

  x = x * a_sign;

  y = y * b_sign;

  x = x * c_copy;

  y = y * c_copy;

  diophantine_solution_minimize ( a_copy, b_copy, x, y );

  return;

# undef N_MAX

}

void diophantine_solution_minimize ( int a, int b, int &x, int &y )

{

  double fa;

  double fb;

  double fx;

  double fy;

  double norm;

  double norm_new;

  double t;

  int xnew;

  int ynew;

  fa = ( double ) a;

  fb = ( double ) b;

  fx = ( double ) x;

  fy = ( double ) y;

  t = ( - fb * fx + fa * fy ) / ( fa * fa + fb * fb );

  x = x + r8_nint ( t ) * b;

  y = y - r8_nint ( t ) * a;

  norm = ( fx * fx + fy * fy );

  for ( ; ; )

  {

    xnew = x + b;

    ynew = y - a;

    fx = ( double ) xnew;

    fy = ( double ) ynew;

    norm_new = ( fx * fx + fy * fy );

    if ( norm <= norm_new )

    {

      break;

    }

    x = xnew;

    y = ynew;

    norm = norm_new;

  }

  for ( ; ; )

  {

    xnew = x - b;

    ynew = y + a;

    fx = ( double ) xnew;

    fy = ( double ) ynew;

    norm_new = ( fx * fx + fy * fy );

    if ( norm <= norm_new )

    {

      break;

    }

    x = xnew;

    y = ynew;

    norm = norm_new;

  }

  return;

}

void dvec_add ( int n, int dvec1[], int dvec2[], int dvec3[] )

{

  int base = 10;

  int i;

  bool overflow;

  overflow = false;

  for ( i = 0; i < n; i++ )

  {

    dvec3[i] = dvec1[i] + dvec2[i];

  }

  for ( i = 0; i < n; i++ )

  {

    while ( base <= dvec3[i] )

    {

      dvec3[i] = dvec3[i] - base;

      if ( i < n-1 )

      {

        dvec3[i+1] = dvec3[i+1] + 1;

      }

      else

      {

        overflow = true;

        return;

      }

    }

  }

  return;

}

void dvec_complementx ( int n, int dvec1[], int dvec2[] )

{

  int base = 10;

  int *dvec3;

  int *dvec4;

  int i;

  dvec3 = new int[n];

  dvec4 = new int[n];

  

  for ( i = 0; i < n; i++ )

  {

    dvec3[i] = ( base - 1 ) - dvec1[i];

  }

  dvec4[0] = 1;

  for ( i = 1; i < n; i++ )

  {

    dvec4[i] = 0;

  }

  dvec_add ( n, dvec3, dvec4, dvec2 );

  delete [] dvec3;

  delete [] dvec4;

  return;

}

void dvec_mul ( int n, int dvec1[], int dvec2[], int dvec3[] )

{

  int base = 10;

  int carry;

  int *dveca;

  int *dvecb;

  int *dvecc;

  int i;

  int j;

  int product_sign;

  dveca = new int[n];

  dvecb = new int[n];

  dvecc = new int[n];

  for ( i = 0; i < n; i++ )

  {

    dveca[i] = dvec1[i];

  }

  for ( i = 0; i < n; i++ )

  {

    dvecb[i] = dvec2[i];

  }

  product_sign = 1;

  if ( dveca[n-1] != 0 )

  {

    product_sign = - product_sign;

    dvec_complementx ( n, dveca, dveca );

  }

  if ( dvecb[n-1] != 0 )

  {

    product_sign = - product_sign;

    dvec_complementx ( n, dvecb, dvecb );

  }

  for ( i = 0; i < n; i++ )

  {

    dvecc[i] = 0;

  }

  for ( i = 1; i <= n-1; i++ )

  {

    for ( j = i; j <= n-1; j++ )

    {

      dvecc[j-1] = dvecc[j-1] + dveca[i-1] * dvecb[j-i];

    }

  }

  for ( i = 0; i < n-1; i++ )

  {

    carry = dvecc[i] / base;

    dvecc[i] = dvecc[i] - carry * base;

    if ( i < n - 2 )

    {

      dvecc[i+1] = dvecc[i+1] + carry;

    }

  }

  if ( product_sign < 0 )

  {

    dvec_complementx ( n, dvecc, dvecc );

  }

  for ( i = 0; i < n; i++ )

  {

    dvec3[i] = dvecc[i];

  }

  delete [] dveca;

  delete [] dvecb;

  delete [] dvecc;

  return;

}

void dvec_print ( int n, int dvec[], string title )

{

  int i;

  int ihi;

  int ilo;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  for ( ihi = n; 1 <= ihi; ihi = ihi - 80 )

  {

    cout << "  ";

    ilo = i4_max ( ihi - 80 + 1, 1 );

    for ( i = ihi; ilo <= i; i-- )

    {

      cout << dvec[i-1];

    }

    cout << "\n";

  }

  return;

}

void dvec_sub ( int n, int dvec1[], int dvec2[], int dvec3[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    dvec3[i] = dvec2[i];

  }

  dvec_complementx ( n, dvec3, dvec3 );

  dvec_add ( n, dvec1, dvec3, dvec3 );

  return;

}

int dvec_to_i4 ( int n, int dvec[] )

{

  int base = 10;

  int *dvec2;

  int i;

  int i_sign;

  int i4;

  dvec2 = new int[n];

  for ( i = 0; i < n; i++ )

  {

    dvec2[i] = dvec[i];

  }

  i_sign = 1;

  if ( dvec2[n-1] == base - 1 )

  {

    i_sign = -1;

    dvec_complementx ( n-1, dvec2, dvec2 );

  }

  i4 = 0;

  for ( i = n-2; 0 <= i4; i4-- )

  {

    i4 = base * i4 + dvec2[i];

  }

  i4 = i_sign * i4;

  delete [] dvec2;

  return i4;

}

void equiv_next ( int n, int &npart, int jarray[], int iarray[], bool &more )

{

  int i;

  int l;

  int m;

  if ( !more )

  {

    npart = 1;

    for ( i = 0; i < n; i++ )

    {

      iarray[i] = 1;

    }

    jarray[0] = n;

  }

  else

  {

    m = n;

    while ( jarray[iarray[m-1]-1] == 1 )

    {

      iarray[m-1] = 1;

      m = m - 1;

    }

    l = iarray[m-1];

    npart = npart + m - n;

    jarray[0] = jarray[0] + n - m;

    if ( l == npart )

    {

      npart = npart + 1;

      jarray[npart-1] = 0;

    }

    iarray[m-1] = l + 1;

    jarray[l-1] = jarray[l-1] - 1;

    jarray[l] = jarray[l] + 1;

  }

  more = ( npart != n );

  return;

}

void equiv_next2 ( bool &done, int iarray[], int n )

{

  int i;

  int imax;

  int j;

  int jmax;

  if ( done )

  {

    done = false;

    for ( i = 0; i < n; i++ )

    {

      iarray[i] = 1;

    }

  }

  else

  {

    jmax = iarray[0];

    imax = 1;

    for ( j = 2; j <= n; j++ )

    {

      if ( jmax < iarray[j-1] )

      {

        jmax = iarray[j-1];

      }

      else

      {

        imax = j;

      }

    }

    if ( imax == 1 )

    {

      done = true;

      return;

    }

    done = false;

    iarray[imax-1] = iarray[imax-1] + 1;

    for ( i = imax; i < n; i++ )

    {

      iarray[i] = 1;

    }

  }

  return;

}

void equiv_print ( int n, int iarray[], string title )

{

  int *karray;

  int j;

  int k;

  int kk;

  int s;

  int s_max;

  int s_min;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  cout << "  Set    Size  Elements\n";

  karray = new int[n];

  s_min = i4vec_min ( n, iarray );

  s_max = i4vec_max ( n, iarray );

  for ( s = s_min; s <= s_max; s++ )

  {

    k = 0;

    for ( j = 0; j < n; j++ )

    {

      if ( iarray[j] == s )

      {

        karray[k] = j+1;

        k = k + 1;

      }

    }

    if ( 0 < k )

    {

      cout                 << "  "

           << setw(4) << s << "  "

           << setw(4) << k << " :: ";

      for ( kk = 0; kk < k; kk++ )

      {

        cout << setw(4) << karray[kk] << "  ";

      }

      cout << "\n";

    }

  }

  delete [] karray;

  return;

}

void equiv_print2 ( int n, int s[], string title )

{

  int i;

  int j;

  int s_max;

  int s_min;

  int size;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  s_min = i4vec_min ( n, s );

  s_max = i4vec_max ( n, s );

  for ( j = s_min; j <= s_max; j++ )

  {

    cout << "(";

    size = 0;

    for ( i = 0; i < n; i++ )

    {

      if ( s[i] == j )

      {

        if ( 0 < size )

        {

          cout << ",";

        }

        cout << i;

        size = size + 1;

      }

    }

    cout << ")";

  }

  cout << "\n";

  return;

}

void equiv_random ( int n, int &seed, int &npart, int a[], double b[] )

{

  int k;

  int l;

  int m;

  double sum1;

  double z;

  double zhi = 1.0;

  double zlo = 0.0;

  b[0] = 1.0;

  for ( l = 1; l <= n-1; l++ )

  {

    sum1 = 1.0 / ( double ) l;

    for ( k = 1; k <= l-1; k++ )

    {

      sum1 = ( sum1 + b[k-1] ) / ( double ) ( l - k );

    }

    b[l] = ( sum1 + b[l-1] ) / ( double ) ( l + 1 );

  }

  m = n;

  npart = 0;

  for ( ; ; )

  {

    z = r8_uniform ( zlo, zhi, seed );

    z = ( double ) ( m ) * b[m-1] * z;

    k = 0;

    npart = npart + 1;

    while ( 0.0 <= z )

    {

      a[m-1] = npart;

      m = m - 1;

      if ( m == 0 )

      {

        break;

      }

      z = z - b[m-1];

      k = k + 1;

      z = z * k;

    }

    if ( m == 0 )

    {

      break;

    }

  }

  perm_random2 ( n, seed, a );

  return;

}

void euler ( int n, int ieuler[] )

{

  int irow;

  int k;

  ieuler[0] = 1;

  if ( 0 < n )

  {

    ieuler[1] = 0;

    for ( irow = 2; irow <= n; irow++ )

    {

      ieuler[irow] = 0;

      for ( k = irow-1; 1 <= k; k-- )

      {

        ieuler[k] = ( k + 1 ) * ieuler[k] + ( irow - k ) * ieuler[k-1];

      }

      ieuler[0] = 1;

    }

  }

  return;

}

int frobenius_number_order2 ( int c1, int c2 )

{

  int value;

  if ( c1 <= 0 )

  {

    value = i4_huge ( );

  }

  else if ( c2 <= 0 )

  {

    value = i4_huge ( );

  }

  else if ( i4_gcd ( c1, c2 ) != 1 )

  {

    value = i4_huge ( );

  }

  else

  {

    value = c1 * c2 - c1 - c2;

  }

  return value;

}

void frobenius_number_order2_values ( int &n_data, int &c1, int &c2, int &f )

{

# define N_MAX 6

  int c1_vec[N_MAX] = {

     2, 

     3, 

     4, 

     5, 

    12, 

    99 };

  int c2_vec[N_MAX] = {

      5, 

     17, 

     19, 

     13, 

     11, 

    100 };

  int f_vec[N_MAX] = {

    3, 

    31, 

    23, 

    47, 

    109, 

    9701 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    c1 = 0;

    c2 = 0;

    f = 0;

  }

  else

  {

    c1 = c1_vec[n_data-1];

    c2 = c2_vec[n_data-1];

    f = f_vec[n_data-1];

  }

  return;

# undef N_MAX

}

void gamma_log_values ( int &n_data, double &x, double &fx )

{

# define N_MAX 18

  double bvec[N_MAX] = {

     1.524064183E+00,    0.7966780066E+00,   0.3982337117E+00,  

     0.1520599127E+00,   0.000000000E+00,   -0.04987246543E+00, 

    -0.08537410945E+00, -0.1081747934E+00,  -0.1196128950E+00,  

    -0.1207822040E+00,  -0.1125917658E+00,  -0.09580771625E+00, 

    -0.07108385116E+00, -0.03898428380E+00,  0.000000000E+00,   

    12.80182743E+00,    39.33988571E+00,    71.25704193E+00 };

  double xvec[N_MAX] = {

    0.2E+00,  0.4E+00,  0.6E+00,  0.8E+00, 

    1.0E+00,  1.1E+00,  1.2E+00,  1.3E+00, 

    1.4E+00,  1.5E+00,  1.6E+00,  1.7E+00, 

    1.8E+00,  1.9E+00,  2.0E+00, 10.0E+00, 

   20.0E+00, 30.0E+00 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  if ( N_MAX <= n_data )

  {

    n_data = 0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    x = xvec[n_data];

    fx = bvec[n_data];

    n_data = n_data + 1;

  }

  return;

# undef N_MAX

}

unsigned long get_seed ( )

{

# define ULONG_MAX2 4294967295UL

  time_t clock;

  int i;

  int hours;

  int minutes;

  int seconds;

  struct tm *lt;

  static unsigned long seed = 0;

  time_t tloc;

  if ( seed == 0 )

  {

    clock = time ( &tloc );

    lt = localtime ( &clock );

    hours = lt->tm_hour;

    if ( 12 < hours )

    {

      hours = hours - 12;

    }

    hours = hours - 1;

    minutes = lt->tm_min;

    seconds = lt->tm_sec;

    seed = seconds + 60 * ( minutes + 60 * hours );

    seed = seed + 1;

    seed = ( unsigned long ) 

      ( ( ( double ) seed )

      * ( ( double ) ULONG_MAX2 ) / ( 60.0 * 60.0 * 12.0 ) );

  }

  if ( seed == 0 )

  {

    seed = 1;

  }

  return seed;

# undef ULONG_MAX2

}

void gray_next ( int n, int &change )

{

  static int *a = NULL;

  int i;

  static int k = 0;

  static int n_save = -1;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "GRAY_NEXT - Fatal error!\n";

    cerr << "  Input value of N <= 0.\n";

    exit ( 1 );

  }

  if ( change == -n )

  {

    if ( a )

    {

      delete [] a;

    }

    a = new int[n];

    for ( i = 0; i < n; i++ )

    {

      a[i] = 0;

    }

    n_save = n;

    k = 1;

    change = 0;

    return;

  }

  if ( n != n_save )

  {

    cerr << "\n";

    cerr << "GRAY_NEXT - Fatal error!\n";

    cerr << "  Input value of N has changed from definition value.\n";

    exit ( 1 );

  }

  if ( ( k % 2 ) == 1 )

  {

    change = 1;

  }

  else

  {

    for ( i = 1; i <= n_save; i++ )

    {

      if ( a[i-1] == 1 )

      {

        change = i + 1;

        break;

      }

    }

  }

  if ( change == n + 1 )

  {

    change = n;

  }

  if ( a[change-1] == 0 )

  {

    a[change-1] = 1;

  }

  else if ( a[change-1] == 1 )

  {

    a[change-1] = 0;

    change = -( change );

  }

  k = k + 1;

  if ( change == -n_save )

  {

    delete [] a;

    a = NULL;

    n_save = 0;

    k = 0;

  }

  return;

}

int gray_rank ( int gray )

{

  int i;

  int nbits = 32;

  int rank;

  rank = 0;

  if ( i4_btest ( gray, nbits - 1 ) )

  {

    rank = i4_bset ( rank, nbits - 1 );

  }

  for ( i = nbits-2; 0 <= i; i-- )

  {

    if ( i4_btest ( rank, i + 1 ) != i4_btest ( gray, i ) )

    {

      rank = i4_bset ( rank, i );

    }

  }

  return rank;

}

int gray_rank2 ( int gray )

{

  int k;

  bool last;

  bool next;

  int rank;

  int two_k;

  if ( gray < 0 )

  {

    cerr << "\n";

    cerr << "GRAY_RANK2 - Fatal error!\n";

    cerr << "  Input value of GRAY < 0.\n";

    exit ( 1 );

  }

  if ( gray == 0 )

  {

    rank = 0;

    return rank;

  }

  k = 0;

  two_k = 1;

  while ( 2 * two_k <= gray )

  {

    two_k = two_k * 2;

    k = k + 1;

  }

  rank = two_k;

  last = true;

  gray = gray - two_k;

  while ( 0 < k )

  {

    two_k = two_k / 2;

    k = k - 1;

    next = ( two_k <= gray && gray < two_k * 2 );

    if ( next )

    {

      gray = gray - two_k;

    }

    if ( next != last )

    {

      rank = rank + two_k;

      last = true;

    }

    else

    {

      last = false;

    }

  }

  return rank;

}

int gray_unrank ( int rank )

{

  int gray;

  int i;

  int nbits = 32;

  gray = 0;

  if ( i4_btest ( rank, nbits-1 ) )

  {

    gray = i4_bset ( gray, nbits-1 );

  }

  for ( i = nbits-2; 0 <= i; i-- )

  {

    if ( i4_btest ( rank, i+1 ) !=  i4_btest ( rank, i ) )

    {

      gray = i4_bset ( gray, i );

    }

  }

  return gray;

}

int gray_unrank2 ( int rank )

{

  int gray;

  int k;

  bool last;

  bool next;

  int two_k;

  if ( rank <= 0 )

  {

    gray = 0;

    return gray;

  }

  k = 0;

  two_k = 1;

  while ( 2 * two_k <= rank )

  {

    two_k = two_k * 2;

    k = k + 1;

  }

  gray = two_k;

  rank = rank - two_k;

  next = true;

  while ( 0 < k )

  {

    two_k = two_k / 2;

    k = k - 1;

    last = next;

    next = ( two_k <= rank && rank <= two_k * 2 );

    if ( next != last )

    {

      gray = gray + two_k;

    }

    if ( next )

    {

      rank = rank - two_k;

    }

  }

  return gray;

}

int i4_bclr ( int i4, int pos )

{

  int j;

  int k;

  int sub;

  int value;

  value = i4;

  if ( pos < 0 )

  {

  }

  else if ( pos < 31 )

  {

    sub = 1;

    if ( 0 <= i4 )

    {

      j = i4;

    }

    else

    {

      j = ( i4_huge ( ) + i4 ) + 1;

    }

    for ( k = 1; k <= pos; k++ )

    {

      j = j / 2;

      sub = sub * 2;

    }

    if ( ( j % 2 ) == 1 )

    {

      value = i4 - sub;

    }

  }

  else if ( pos == 31 )

  {

    if ( i4 < 0 )

    {

      value = ( i4_huge ( ) + i4 ) + 1;

    }

  }

  else if ( 31 < pos )

  {

    value = i4;

  }

  return value;

}

int i4_bset ( int i4, int pos )

{

  int add;

  int j;

  int k;

  int value;

  value = i4;

  if ( pos < 0 )

  {

  }

  else if ( pos < 31 )

  {

    add = 1;

    if ( 0 <= i4 )

    {

      j = i4;

    }

    else

    {

      j = ( i4_huge ( ) + i4 ) + 1;

    }

    for ( k = 1; k <= pos; k++ )

    {

      j = j / 2;

      add = add * 2;

    }

    if ( ( j % 2 ) == 0 )

    {

      value = i4 + add;

    }

  }

  else if ( pos == 31 )

  {

    if ( 0 < i4 )

    {

      value = - ( i4_huge ( ) - i4 ) - 1;

    }

  }

  else if ( 31 < pos )

  {

    value = i4;

  }

  return value;

}

bool i4_btest ( int i4, int pos )

{

  int j;

  int k;

  bool value;

  if ( pos < 0 )

  {

    cerr << "\n";

    cerr << "I4_BTEST - Fatal error!\n";

    cerr << "  POS < 0.\n";

    exit ( 1 );

  }

  else if ( pos < 31 )

  {

    if ( 0 <= i4 )

    {

      j = i4;

    }

    else

    {

      j = ( i4_huge ( ) + i4 ) + 1;

    }

    for ( k = 1; k <= pos; k++ )

    {

      j = j / 2;

    }

    if ( ( j % 2 ) == 0 )

    {

      value = false;

    }

    else

    {

      value = true;

    }

  }

  else if ( pos == 31 )

  {

    if ( i4 < 0 )

    {

      value = true;

    }

    else

    {

      value = false;

    }

  }

  else if ( 31 < pos )

  {

    cerr << "\n";

    cerr << "I4_BTEST - Fatal error!\n";

    cerr << "  31 < POS.\n";

    exit ( 1 );

  }

  return value;

}

int i4_choose ( int n, int k )

{

  int i;

  int mn;

  int mx;

  int value;

  mn = i4_min ( k, n - k );

  if ( mn < 0 )

  {

    value = 0;

  }

  else if ( mn == 0 )

  {

    value = 1;

  }

  else

  {

    mx = i4_max ( k, n - k );

    value = mx + 1;

    for ( i = 2; i <= mn; i++ )

    {

      value = ( value * ( mx + i ) ) / i;

    }

  }

  return value;

}

void i4_factor ( int n, int maxfactor, int &nfactor, int factor[], 

  int exponent[], int &nleft )

{

  int i;

  int maxprime;

  int p;

  nfactor = 0;

  for ( i = 0; i < maxfactor; i++ )

  {

    factor[i] = 0;

  }

  for ( i = 0; i < maxfactor; i++ )

  {

    exponent[i] = 0;

  }

  nleft = n;

  if ( n == 0 )

  {

    return;

  }

  if ( abs ( n ) == 1 )

  {

    nfactor = 1;

    factor[0] = 1;

    exponent[0] = 1;

    return;

  }

  maxprime = prime ( -1 );

  for ( i = 1; i <= maxprime; i++ )

  {

    p = prime ( i );

    if ( abs ( nleft ) % p == 0 )

    {

      if ( nfactor < maxfactor )

      {

        nfactor = nfactor + 1;

        factor[nfactor-1] = p;

        exponent[nfactor-1] = 0;

        for ( ; ; )

        {

          exponent[nfactor-1] = exponent[nfactor-1] + 1;

          nleft = nleft / p;

          if ( abs ( nleft ) % p != 0 )

          {

            break;

          }

        }

        if ( abs ( nleft ) == 1 )

        {

          break;

        }

      }

    }

  }

  return;

}

int i4_factorial ( int n )

{

  int i;

  int value;

  value = 1;

  if ( 13 < n ) 

  {

    value = - 1;

    cerr << "I4_FACTORIAL - Fatal error!\n";

    cerr << "  I4_FACTORIAL(N) cannot be computed as an integer\n";

    cerr << "  for 13 < N.\n";

    cerr << "  Input value N = " << n << "\n";

    exit ( 1 );

  }

  for ( i = 1; i <= n; i++ )

  {

    value = value * i;

  }

  return value;

}

int i4_fall ( int x, int n )

{

  int i;

  int value;

  value = 1;

  if ( 0 < n )

  {

    for ( i = 1; i <= n; i++ )

    {

      value = value * x;

      x = x - 1;

    }

  }

  else if ( n < 0 )

  {

    for ( i = -1; n <= i; i-- )

    {

      value = value * x;

      x = x + 1;

    }

  }

  return value;

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

int i4_moebius ( int n )

{

# define FACTOR_MAX 20

  int exponent[FACTOR_MAX];

  int factor[FACTOR_MAX];

  int i;

  int mu;

  int nfactor;

  int nleft;

  if ( n <= 0 )

  {

    mu = -2;

    return mu;

  }

  if ( n == 1 )

  {

    mu = 1;

    return mu;

  }

  i4_factor ( n, FACTOR_MAX, nfactor, factor, exponent, nleft );

  if ( nleft != 1 )

  {

    cerr << "\n";

    cerr << "I4_MOEBIUS - Fatal error!\n";

    cerr << "  Not enough factorization space.\n";

    mu = -3;

    exit ( 1 );

  }

  mu = 1;

  for ( i = 0; i < nfactor; i++ )

  {

    mu = -mu;

    if ( 1 < exponent[i] )

    {

      mu = 0;

      return mu;

    }

  }

  return mu;

# undef FACTOR_MAX

}

void i4_partition_conj ( int n, int iarray1[], int mult1[], int npart1, 

  int iarray2[], int mult2[], int &npart2 )

{

  int i;

  int itemp;

  int itest;

  for ( i = 0; i < n; i++ )

  {

    iarray2[i] = 0;

  }

  for ( i = 0; i < n; i++ )

  {

    mult2[i] = 0;

  }

  npart2 = 0;

  itest = 0;

  for ( ; ; )

  {

    itest = itest + 1;

    itemp = 0;

    for ( i = 0; i < npart1; i++ )

    {

      if ( itest <= iarray1[i] )

      {

        itemp = itemp + mult1[i];

      }

    }

    if ( itemp <= 0 )

    {

      break;

    }

    if ( 0 < npart2 )

    {

      if ( itemp == iarray2[npart2-1] )

      {

        mult2[npart2-1] = mult2[npart2-1] + 1;

      }

      else

      {

        npart2 = npart2 + 1;

        iarray2[npart2-1] = itemp;

        mult2[npart2-1] = 1;

      }

    }

    else

    {

      npart2 = npart2 + 1;

      iarray2[npart2-1] = itemp;

      mult2[npart2-1] = 1;

    }

  }

  return;

}

void i4_partition_count ( int n, int p[] )

{

  int i;

  int j;

  int pj;

  int sgn;

  p[0] = 1;

  for ( i = 1; i <= n; i++ )

  {

    p[i] = 0;

    j = 0;

    sgn = 1;

    for ( ; ; )

    {

      j = j + 1;

      pj = pent_enum ( j );

      if ( i < pj )

      {

        break;

      }

      p[i] = p[i] + sgn * p[i-pj];

      sgn = -sgn;

    }

    j = 0;

    sgn = 1;

    for ( ; ; )

    {

      j = j - 1;

      pj = pent_enum ( j );

      if ( i < pj )

      {

        break;

      }

      p[i] = p[i] + sgn * p[i-pj];

      sgn = -sgn;

    }

  }

  return;

}

int *i4_partition_count2 ( int n )

{

  int i;

  int j;

  int *p;

  int s;

  int t;

  int total;

  if ( n < 0 )

  {

    return NULL;

  }

  p = new int[n+1];

  p[0] = 1;

  if ( n < 1 )

  {

    return p;

  }

  p[1] = 1;

  for ( i = 2; i <= n; i++ )

  {

    total = 0;

    for ( t = 1; t <= i; t++ )

    {

      s = 0;

      j = i;

      for ( ; ; )

      {

        j = j - t;

        if ( 0 < j )

        {

          s = s + p[j];

        }

        else

        {

          if ( j == 0 )

          {

            s = s + 1;

          }

          break;

        }

      }

      total = total + s * t;

    }

    p[i] = ( int ) ( total / i );

  }

  return p;

}

void i4_partition_count_values ( int &n_data, int &n, int &c )

{

# define N_MAX 21

  int c_vec[N_MAX] = {

      1,

      1,   2,   3,   5,   7,  11,  15,  22,  30,  42, 

     56,  77, 101, 135, 176, 231, 297, 385, 490, 627 };

  int n_vec[N_MAX] = {

     0,  

     1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 

    11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  if ( N_MAX <= n_data )

  {

    n_data = 0;

    n = 0;

    c = 0;

  }

  else

  {

    n = n_vec[n_data];

    c = c_vec[n_data];

    n_data = n_data + 1;

  }

  return;

# undef N_MAX

}

void i4_partition_next ( bool &done, int a[], int mult[], int n, int &npart )

{

  int i;

  int is;

  int iu;

  int iv;

  int iw;

  int k;

  int k1;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "I4_PARTITION_NEXT - Fatal error!\n";

    cerr << "  N must be positive.\n";

    cerr << "  The input value of N was " << n << "\n";

    exit ( 1 );

  }

  if ( done )

  {

    a[0] = n;

    for ( i = 1; i < n; i++ )

    {

      a[i] = 0;

    }

    mult[0] = 1;

    for ( i = 1; i < n; i++ )

    {

      mult[i] = 0;

    }

    npart = 1;

    done = false;

  }

  else

  {

    if ( 1 < a[(npart)-1] || 1 < npart )

    {

      done = false;

      if ( a[(npart)-1] == 1 )

      {

        is = a[npart-2] + mult[npart-1];

        k = npart - 1;

      }

      else

      {

        is = a[npart-1];

        k = npart;

      }

      iw = a[k-1] - 1;

      iu = is / iw;

      iv = is % iw;

      mult[k-1] = mult[k-1] - 1;

      if ( mult[k-1] == 0 )

      {

        k1 = k;

      }

      else

      {

        k1 = k + 1;

      }

      mult[k1-1] = iu;

      a[k1-1] = iw;

      if ( iv == 0 )

      {

        npart = k1;

      }

      else

      {

        mult[k1] = 1;

        a[k1] = iv;

        npart = k1 + 1;

      }

    }

    else

    {

      done = true;

    }

  }

  return;

}

void i4_partition_next2 ( int n, int a[], int mult[], int &npart, bool &more )

{

  int iff;

  int is;

  int isum;

  static int nlast = 0;

  if ( !more )

  {

    nlast = 0;

  }

  if ( n != nlast || ( !more ) )

  {

    nlast = n;

    npart = 1;

    a[npart-1] = n;

    mult[npart-1] = 1;

    more = mult[npart-1] != n;

    return;

  }

  isum = 1;

  if ( a[npart-1] <= 1 )

  {

    isum = mult[npart-1] + 1;

    npart = npart - 1;

  }

  iff = a[npart-1] - 1;

  if ( mult[npart-1] != 1 )

  {

    mult[npart-1] = mult[npart-1] - 1;

    npart = npart + 1;

  }

  a[npart-1] = iff;

  mult[npart-1] = 1 + ( isum / iff );

  is = isum % iff;

  if ( 0 < is )

  {

    npart = npart + 1;

    a[npart-1] = is;

    mult[npart-1] = 1;

  }

  more = mult[npart-1] != n;

  return;

}

void i4_partition_print ( int n, int npart, int a[], int mult[] )

{

  int i;

  cout << "  " << n << " = ";

  for ( i = 0; i < npart; i++ )

  {

    if ( 0 < i )

    {

      cout << " + ";

    }

    cout << mult[i] << " * " << a[i];

  }

  cout << "\n";

  return;

}

void i4_partition_random ( int n, int table[], int &seed, int a[], int mult[], 

  int &npart )

{

  int i;

  int i1;

  int id;

  int j;

  int m;

  double z;

  m = n;

  npart = 0;

  for ( i = 0; i < n; i++ )

  {

    mult[i] = 0;

  }

  while ( 0 < m )

  {

    z = r8_uniform_01 ( seed );

    z = m * table[m-1] * z;

    id = 1;

    i1 = m;

    j = 0;

    for ( ; ; )

    {

      j = j + 1;

      i1 = i1 - id;

      if ( i1 < 0 )

      {

        id = id + 1;

        i1 = m;

        j = 0;

        continue;

      }

      if ( i1 == 0 )

      {

        z = z - id;

        if ( 0.0 < z )

        {

          id = id + 1;

          i1 = m;

          j = 0;

          continue;

        }

        else

        {

          break;

        }

      }

      if ( 0 < i1 )

      {

        z = z - id * table[i1-1];

        if ( z <= 0.0 )

        {

          break;

        }

      }

    }

    mult[id-1] = mult[id-1] + j;

    npart = npart + j;

    m = i1;

  }

  npart = 0;

  for ( i = 1; i <= n; i++ )

  {

    if ( mult[i-1] != 0 )

    {

      npart = npart + 1;

      a[npart-1] = i;

      mult[npart-1] = mult[i-1];

    }

  }

  for ( i = npart + 1; i <= n; i++ )

  {

    mult[i-1] = 0;

  }

  return;

}

void i4_partitions_next ( int s, int m[] )

{

  int i;

  int j;

  int msum;

  msum = m[0];

  for ( i = 1; i < s; i++ )

  {

    msum = msum + m[i];

    if ( m[0] <= m[i] + 1 )

    {

      m[i] = 0;

    }

    else

    {

      m[0] = msum - i * ( m[i] + 1 );

      for ( j = 1; j <= i; j++ )

      {

        m[j] = m[i] + 1;

      }

      return;

    }

  }

  m[0] = msum + 1;

  return;

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

int i4_rise ( int x, int n )

{

  int i;

  int value;

  value = 1;

  if ( 0 < n )

  {

    for ( i = 1; i <= n; i++ )

    {

      value = value * x;

      x = x + 1;

    }

  }

  else if ( n < 0 )

  {

    for ( i = -1; n <= i; i-- )

    {

      value = value * x;

      x = x - 1;

    }

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

void i4_sqrt ( int n, int &q, int &r )

{

  n = abs ( n );

  q = n;

  if ( 0 < n )

  {

    while ( ( n / q ) < q )

    {

      q = ( q + ( n / q ) ) / 2;

    }

  }

  r = n - q * q;

  return;

}

void i4_sqrt_cf ( int n, int max_term, int &n_term, int b[] )

{

  int k;

  int p;

  int q;

  int r;

  int s;

  n_term = 0;

  i4_sqrt ( n, s, r );

  b[0] = s;

  if ( 0 < r )

  {

    p = 0;

    q = 1;

    for ( ; ; )

    {

      p = b[n_term] * q - p;

      q = ( n - p * p ) / q;

      if ( max_term <= n_term )

      {

        return;

      }

      n_term = n_term + 1;

      b[n_term] = ( p + s ) / q;

      if ( q == 1 )

      {

        break;

      }

    }

  }

  return;

}

void i4_swap ( int &i, int &j )

{

  int k;

  k = i;

  i = j;

  j = k;

 

  return;

}

void i4_to_bvec ( int i4, int n, int bvec[] )

{

  int base = 2;

  int i4_copy;

  int j;

  i4_copy = abs ( i4 );

  for ( j = n - 1; 1 <= j; j-- )

  {

    bvec[j] = ( i4_copy % base );

    i4_copy = i4_copy / base;

  }

  bvec[0] = 0;

  if ( i4 < 0 )

  {

    bvec_complement2 ( n, bvec, bvec );

  }

  return;

}

void i4_to_chinese ( int j, int n, int m[], int r[] )

{

  bool error;

  int i;

  error = chinese_check ( n, m );

  if ( error )

  {

    cerr << "\n";

    cerr << "I4_TO_CHINESE - Fatal error!\n";

    cerr << "  The moduluses are not legal.\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    r[i] = i4_modp ( j, m[i] );

  }

  return;

}

void i4_to_dvec ( int i4, int n, int dvec[] )

{

  int base = 10;

  int i;

  int i4_copy;

  i4_copy = abs ( i4 );

  for ( i = 0; i < n-1; i++ )

  {

    dvec[i] = i4_copy % base;

    i4_copy = i4_copy / base;

  }

  dvec[n-1] = 0;

  if ( i4 < 0 )

  {

    dvec_complementx ( n, dvec, dvec );

  }

  return;

}

void i4_to_i4poly ( int intval, int base, int degree_max, int &degree, int a[] )

{

  int i;

  int j;

  for ( i = 0; i <= degree_max; i++ )

  {

    a[i] = 0;

  }

  j = abs ( intval );

  degree = 0;

  a[degree] = j % base;

  j = j - a[degree];

  j = j / base;

  while ( 0 < j )

  {

    degree = degree + 1;

    if ( degree < degree_max )

    {

      a[degree] = j % base;

    }

    j = j - a[degree];

    j = j / base;

  }

  if ( intval < 0 )

  {

    for ( i = 0; i <= degree_max; i++ )

    {

      a[i] = -a[i];

    }

  }

  return;

}

double i4_to_van_der_corput ( int seed, int base )

{

  double base_inv;

  int digit;

  double r;

  if ( base <= 1 )

  {

    cerr << "\n";

    cerr << "I4_TO_VAN_DER_CORPUT - Fatal error!\n";

    cerr << "  The input base BASE is <= 1!\n";

    cerr << "  BASE = " << base << "\n";

    exit ( 1 );

  }

  if ( seed < 0 ) 

  {

    cerr << "\n";

    cerr << "I4_TO_VAN_DER_CORPUT - Fatal error!\n";

    cerr << "  SEED < 0.";

    cerr << "  SEED = " << seed << "\n";

    exit ( 1 );

  }

  r = 0.0;

  base_inv = 1.0 / ( ( double ) base );

  while ( seed != 0 )

  {

    digit = seed % base;

    r = r + ( ( double ) digit ) * base_inv;

    base_inv = base_inv / ( ( double ) base );

    seed = seed / base;

  }

  return r;

}

int i4_uniform_ab ( int a, int b, int &seed )

{

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

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + 2147483647;

  }

  r = ( float ) ( seed ) * 4.656612875E-10;

  r = ( 1.0 - r ) * ( ( float ) ( i4_min ( a, b ) ) - 0.5 ) 

    +         r   * ( ( float ) ( i4_max ( a, b ) ) + 0.5 );

  value = r4_nint ( r );

  value = i4_max ( value, i4_min ( a, b ) );

  value = i4_min ( value, i4_max ( a, b ) );

  return value;

}

void i4mat_01_rowcolsum ( int m, int n, int r[], int c[], int a[], bool &error )

{

  int c_sum;

  int i;

  int j;

  int k;

  int *r_conj;

  int r_sum;

  int *r2;

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      a[i+j*m] = 0;

    }

  }

  error = false;

  if ( i4vec_sum ( m, r ) != i4vec_sum ( n, c ) )

  {

    cerr << "\n";

    cerr << "I4MAT_01_ROWCOLSUM - Fatal error!\n";

    cerr << "  Row sums R and column sums C don't have the same sum!\n";

    error = true;

    exit ( 1 );

  }

  if ( !i4vec_descends ( m, r ) )

  {

    cerr << "\n";

    cerr << "I4MAT_01_ROWCOLSUM - Fatal error!\n";

    cerr << "  Row sum vector R is not descending!\n";

    error = true;

    exit ( 1 );

  }

  if ( n < r[0] || r[m-1] < 0 )

  {

    error = true;

    return;

  }

  if ( !i4vec_descends ( n, c ) )

  {

    cerr << "\n";

    cerr << "I4MAT_01_ROWCOLSUM - Fatal error!\n";

    cerr << "  Column sum vector C is not descending!\n";

    error = true;

    exit ( 1 );

  }

  if ( m < c[0] || c[n-1] < 0 )

  {

    error = true;

    return;

  }

  r_conj = new int[n];

  for ( i = 0; i < n; i++ )

  {

    r_conj[i] = 0;

  }

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < r[i]; j++ )

    {

      r_conj[j] = r_conj[j] + 1;

    }

  }

  r_sum = 0;

  c_sum = 0;

  for ( i = 0; i < n; i++ )

  {

    r_sum = r_sum + r_conj[i];

    c_sum = c_sum + c[i];

    if ( r_sum < c_sum )

    {

      error = true;

      return;

    }

  }

  delete [] r_conj;

  if ( error )

  {

    return;

  }

  r2 = new int[m];

  for ( i = 0; i < m; i++ )

  {

    r2[i] = r[i];

  }

  for ( j = n-1; 0 <= j; j-- )

  {

    i = i4vec_maxloc_last ( m, r2 );

    for ( k = 1; k <= c[j]; k++ )

    {

      a[i+j*m] = a[i+j*m] + 1;

      r2[i] = r2[i] - 1;

      if ( 0 < i )

      {

        i = i - 1;

      }

      else

      {

        i = i4vec_maxloc_last ( m, r2 );

        if ( i == 0 && k < c[j] )

        {

          i = 1 + i4vec_maxloc_last ( m-1, r2 + 1 );

        }

      }

    }

  }

  delete [] r2;

  return;

}

void i4mat_01_rowcolsum2 ( int m, int n, int r[], int c[], int a[], 

  bool &error )

{

  int *capflo;

  int i;

  int *icut;

  int *iendpt;

  int isink;

  int j;

  int k;

  int nedge;

  int nnode;

  int *node_flow;

  int source;

  error = false;

  capflo = new int[2*2*(m+m*n+n)];

  icut = new int[m+n+2];

  iendpt = new int[2*2*(m+m*n+n)];

  node_flow = new int[m+n+2];

  source = m + n + 1;

  isink = m + n + 2;

  nnode = m + n + 2;

  k = 0;

  for ( i = 0; i < m; i++ )

  {

    iendpt[0+2*k] = source;

    iendpt[1+2*k] = i+1;

    capflo[0+2*k] = r[i];

    capflo[1+2*k] = 0;

    k = k + 1;

    iendpt[0+2*k] = i+1;

    iendpt[1+2*k] = source;

    capflo[0+2*k] = r[i];

    capflo[1+2*k] = 0;

    k = k + 1;

  }

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      iendpt[0+2*k] = i+1;

      iendpt[1+2*k] = j+1+m;

      capflo[0+2*k] = 1;

      capflo[1+2*k] = 0;

      k = k + 1;

      iendpt[0+2*k] = j+1+m;

      iendpt[1+2*k] = i+1;

      capflo[0+2*k] = 1;

      capflo[1+2*k] = 0;

      k = k + 1;

    }

  }

  for ( j = 0; j < n; j++ )

  {

    iendpt[0+2*k] = j+1+m;

    iendpt[1+2*k] = isink;

    capflo[0+2*k] = c[j];

    capflo[1+2*k] = 0;

    k = k + 1;

    iendpt[0+2*k] = isink;

    iendpt[1+2*k] = j+1+m;

    capflo[0+2*k] = c[j];

    capflo[1+2*k] = 0;

    k = k + 1;

  }

  nedge = k;

  network_flow_max ( nnode, nedge, iendpt, capflo, source, isink, 

    icut, node_flow );

  for ( k = 0; k < nedge; k++ )

  {

    i = iendpt[0+2*k];

    j = iendpt[1+2*k] - m;

    if ( i <= m && 1 <= j && j <= n )

    {

      if ( capflo[1+2*k] != 0 && capflo[1+2*k] != 1 )

      {

        error = true;

      }

    }

    if ( iendpt[0+2*k] == source )

    {

      if ( capflo[0+2*k] != capflo[1+2*k] )

      {

        error = true;

      }

    }

    if ( iendpt[1+2*k] == isink )

    {

      if ( capflo[0+2*k] != capflo[1+2*k] )

      {

        error = true;

      }

    }

  }

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      a[i+j*m] = 0;

    }

  }

  for ( k = 0; k < nedge; k++ )

  {

    i = iendpt[0+2*k];

    j = iendpt[1+2*k] - m;

    if ( i <= m && 1 <= j && j <= n )

    {

      a[i+j*m] = capflo[1+2*k];

    }

  }

  delete [] icut;

  delete [] iendpt;

  delete [] node_flow;

  return;

}

void i4mat_perm ( int n, int a[], int p[] )

{

  int i;

  int i1;

  int is;

  int it;

  int j;

  int j1;

  int j2;

  int k;

  int lc;

  int nc;

  int temp;

  perm_cycle ( n, p, is, nc, 1 );

  for ( i = 1; i <= n; i++ )

  {

    i1 = - p[i-1];

    if ( 0 < i1 )

    {

      lc = 0;

      for ( ; ; )

      {

        i1 = p[i1-1];

        lc = lc + 1;

        if ( i1 <= 0 )

        {

          break;

        }

      }

      i1 = i;

      for ( j = 1; j <= n; j++ )

      {

        if ( p[j-1] <= 0 )

        {

          j2 = j;

          k = lc;

          for ( ; ; )

          {

            j1 = j2;

            it = a[i1-1+(j1-1)*n];

            for ( ; ; )

            {

              i1 = abs ( p[i1-1] );

              j1 = abs ( p[j1-1] );

              temp = a[i1-1+(j1-1)*n];

              a[i1-1+(j1-1)*n] = it;

              it = temp;

              if ( j1 != j2 )

              {

                continue;

              }

              k = k - 1;

              if ( i1 == i )

              {

                break;

              }

            }

            j2 = abs ( p[j2-1] );

            if ( k == 0 )

            {

              break;

            }

          }

        }

      }

    }

  }

  for ( i = 0; i < n; i++ )

  {

    p[i] = abs ( p[i] );

  }

  return;

}

void i4mat_perm2 ( int m, int n, int a[], int p[], int q[] )

{

  int i;

  int i1;

  int is;

  int it;

  int j;

  int j1;

  int j2;

  int k;

  int lc;

  int nc;

  int temp;

  perm_cycle ( m, p, is, nc, 1 );

  if ( 0 < q[0] )

  {

    perm_cycle ( n, q, is, nc, 1 );

  }

  for ( i = 1; i <= m; i++ )

  {

    i1 = -p[i-1];

    if ( 0 < i1 )

    {

      lc = 0;

      for ( ; ; )

      {

        i1 = p[i1-1];

        lc = lc + 1;

        if ( i1 <= 0 )

        {

          break;

        }

      }

      i1 = i;

      for ( j = 1; j <= n; j++ )

      {

        if ( q[j-1] <= 0 )

        {

          j2 = j;

          k = lc;

          for ( ; ; )

          {

            j1 = j2;

            it = a[i1-1+(j1-1)*m];

            for ( ; ; )

            {

              i1 = abs ( p[i1-1] );

              j1 = abs ( q[j1-1] );

              temp = it;

              it = a[i1-1+(j1-1)*m];

              a[i1-1+(j1-1)*m] = temp;

              if ( j1 != j2 )

              {

                continue;

              }

              k = k - 1;

              if ( i1 == i )

              {

                break;

              }

            }

            j2 = abs ( q[j2-1] );

            if ( k == 0 )

            {

              break;

            }

          }

        }

      }

    }

  }

  for ( i = 0; i < m; i++ )

  {

    p[i] = abs ( p[i] );

  }

  if ( q[0] <= 0 )

  {

    for ( j = 0; j < n; j++ )

    {

      q[j] = abs ( q[j] );

    }

  }

  return;

}

void i4mat_print ( int m, int n, int a[], string title )

{

  i4mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;

}

void i4mat_print_some ( int m, int n, int a[], int ilo, int jlo, int ihi, 

  int jhi, string title )

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

        cout << setw(6) << a[i-1+(j-1)*m] << "  ";

      }

      cout << "\n";

    }

  }

  return;

# undef INCX

}

void i4mat_u1_inverse ( int n, int a[], int b[] )

{

  int i;

  int isum;

  int j;

  int k;

  for ( j = n; 1 <= j; j-- )

  {

    for ( i = n; 1 <= i; i-- )

    {

      if ( i == j )

      {

        isum = 1;

      }

      else

      {

        isum = 0;

      }

      for ( k = i+1; k <= j; k++ )

      {

        isum = isum - a[i-1+(k-1)*n] * b[k-1+(j-1)*n];

      }

      b[i-1+(j-1)*n] = isum;

    }

  }

  return;

}

void i4poly ( int n, int a[], int x0, int iopt, int &val )

{

  int eps;

  int i;

  int m;

  int n1;

  int w;

  int z;

  n1 = i4_min ( n, iopt );

  n1 = i4_max ( 1, n1 );

  if ( iopt < -1 )

  {

    n1 = n;

  }

  eps = i4_max ( -iopt, 0 ) % 2;

  w = - n * eps;

  if ( -2 < iopt )

  {

    w = w + x0;

  }

  for ( m = 1; m <= n1; m++ )

  {

    val = 0;

    z = w;

    for ( i = m; i <= n; i++ )

    {

      z = z + eps;

      val = a[n+m-i-1] + z * val;

      if ( iopt != 0 && iopt != -1 )

      {

        a[n+m-i-1] = val;

      }

    }

    if ( iopt < 0 )

    {

      w = w + 1;

    }

  }

  return;

}

int *i4poly_add ( int na, int a[], int nb, int b[] )

{

  int i;

  int *c;

  c = new int[i4_max(na,nb)+1];

  if ( nb == na )

  {

    for ( i = 0; i <= na; i++ )

    {

      c[i] = a[i] + b[i];

    }

  }

  else if ( nb < na )

  {

    for ( i = 0; i <= nb; i++ )

    {

      c[i] = a[i] + b[i];

    }

    for ( i = nb + 1; i <= na; i++ )

    {

      c[i] = a[i];

    }

  }

  else if ( na < nb )

  {

    for ( i = 0; i <= na; i++ )

    {

      c[i] = a[i] + b[i];

    }

    for ( i = na + 1; i <= nb; i++ )

    {

      c[i] = b[i];

    }

  }

  return c;

}

void i4poly_cyclo ( int n, int phi[] )

{

# define POLY_MAX 100

  int d;

  int den[POLY_MAX+1];

  int den_n;

  int *factor;

  int i;

  int j;

  int mu;

  int nq;

  int nr;

  int num[POLY_MAX+1];

  int num_n;

  int *rem;

  factor = new int[n+1];

  rem = new int[n+1];

  num[0] = 1;

  for ( i = 1; i <= POLY_MAX; i++ )

  {

    num[i] = 0;

  }

  num_n = 0;

  den[0] = 1;

  for ( i = 1; i <= POLY_MAX; i++ )

  {

    den[i] = 0;

  }

  den_n = 0;

  for ( i = 0; i <= n; i++ )

  {

    phi[i] = 0;

  }

  for ( d = 1; d <= n; d++ )

  {

    if ( ( n % d ) == 0 )

    {

      mu = i4_moebius ( n / d );

      factor[0] = -1;

      for ( j = 1; j <= d-1; j++ )

      {

        factor[j] = 0;

      }

      factor[d] = 1;

      if ( mu == +1 )

      {

        if ( POLY_MAX < num_n + d )

        {

          cerr << "\n";

          cerr << "I4POLY_CYCLO - Fatal error!\n";

          cerr << "  Numerator polynomial degree too high.\n";

          exit ( 1 );

        }

        i4poly_mul ( num_n, num, d, factor, num );

        num_n = num_n + d;

      }

      else if ( mu == -1 )

      {

        if ( POLY_MAX < den_n + d )

        {

          cerr << "\n";

          cerr << "I4POLY_CYCLO - Fatal error!\n";

          cerr << "  Denominator polynomial degree too high.\n";

          exit ( 1 );

        }

        i4poly_mul ( den_n, den, d, factor, den );

        den_n = den_n + d;

      }

    }

  }

  i4poly_div ( num_n, num, den_n, den, nq, phi, nr, rem );

  delete [] factor;

  delete [] rem;

  return;

# undef POLY_MAX

}

int i4poly_degree ( int na, int a[] )

{

  int degree;

  degree = na;

  while ( 0 < degree )

  {

    if ( a[degree] != 0 )

    {

      return degree;

    }

    degree = degree - 1;

  }

  return degree;

}

int *i4poly_dif ( int na, int a[], int d )

{

  int *b;

  int i;

  if ( na < d )

  {

    b = new int[1];

    b[0] = 0;

    return b;

  }

  b = new int[na-d+1];

  for ( i = 0; i <= na - d; i++ )

  {

    b[i] = a[i+d] * i4_fall ( i + d, d );

  }

  return b;

}

void i4poly_div ( int na, int a[], int nb, int b[], int &nq, int q[], 

  int &nr, int r[] )

{

  int *a2;

  int i;

  int j;

  int na2;

  int nb2;

  na2 = i4poly_degree ( na, a );

  nb2 = i4poly_degree ( nb, b );

  if ( b[nb2] == 0 )

  {

    nq = -1;

    nr = -1;

    return;

  }

  a2 = new int[na+1];

  for ( i = 0; i <= na2; i++ )

  {

    a2[i] = a[i];

  }

  nq = na2 - nb2;

  nr = nb2 - 1;

  for ( i = nq; 0 <= i; i-- )

  {

    q[i] = a2[i+nb2] / b[nb2];

    a2[i+nb2] = 0;

    for ( j = 0; j < nb2; j++ )

    {

      a2[i+j] = a2[i+j] - q[i] * b[j];

    }

  }

  for ( i = 0; i <= nr; i++ )

  {

    r[i] = a2[i];

  }

  delete [] a2;

  return;

}

void i4poly_mul ( int na, int a[], int nb, int b[], int c[] )

{

  int *d;

  int i;

  int j;

  d = new int[na+nb+1];

  for ( i = 0; i <= na+nb; i++ )

  {

    d[i] = 0;

  }

  for ( i = 0; i <= na; i++ )

  {

    for ( j = 0; j <= nb; j++ )

    {

      d[i+j] = d[i+j] + a[i] * b[j];

    }

  }

  for ( i = 0; i <= na+nb; i++ )

  {

    c[i] = d[i];

  }

  delete [] d;

  return;

}

void i4poly_print ( int n, int a[], string title )

{

  int i;

  int mag;

  int n2;

  char plus_minus;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  n2 = i4poly_degree ( n, a );

  if ( a[n2] < 0 )

  {

    plus_minus = '-';

  }

  else

  {

    plus_minus = ' ';

  }

  mag = abs ( a[n2] );

  if ( 2 <= n2 )

  {

    cout << "p(x) = " << plus_minus << mag << " * x^" << n2 << "\n";

  }

  else if ( n2 == 1 )

  {

    cout << "p(x) = " << plus_minus << mag << " * x" << "\n";

  }

  else if ( n2 == 0 )

  {

    cout << "p(x) = " << plus_minus << mag << "\n";

  }

  for ( i = n2-1; 0 <= i; i-- )

  {

    if ( a[i] < 0.0 )

    {

      plus_minus = '-';

    }

    else

    {

      plus_minus = '+';

    }

    mag = abs ( a[i] );

    if ( mag != 0 )

    {

      if ( 2 <= i )

      {

        cout << "       " << plus_minus << mag << " * x^" << i << "\n";

      }

      else if ( i == 1 )

      {

        cout << "       " << plus_minus << mag << " * x" << "\n";

      }

      else if ( i == 0 )

      {

        cout << "       " << plus_minus << mag << "\n";

      }

    }

  }

  return;

}

int i4poly_to_i4 ( int n, int a[], int x )

{

  int i;

  int value;

  value = 0;

  for ( i = n; 0 <= i; i-- )

  {

    value = value * x + a[i];

  }

  return value;

}

bool i4vec_ascends ( int n, int x[] )

{

  int i;

  for ( i = 1; i <= n-1; i++ )

  {

    if ( x[i] < x[i-1] )

    {

      return false;

    }

  }

  return true;

}

void i4vec_backtrack ( int n, int maxstack, int stack[], int x[], int &indx, 

  int &k, int &nstack, int ncan[] )

{

  if ( indx == 0 )

  {

    k = 1;

    nstack = 0;

    indx = 2;

    return;

  }

  for ( ; ; )

  {

    if ( 0 < ncan[k-1] )

    {

      x[k-1] = stack[(nstack)-1];

      nstack = nstack - 1;

      ncan[k-1] = ncan[k-1] - 1;

      if ( k != n )

      {

        k = k + 1;

        indx = 2;

      }

      else

      {

        indx = 1;

      }

      break;

    }

    else

    {

      k = k - 1;

      if ( k <= 0 )

      {

        indx = 3;

        break;

      }

    }

  }

  return;

}

bool i4vec_descends ( int n, int x[] )

{

  int i;

  for ( i = 0; i < n-1; i++ )

  {

    if ( x[i] < x[i+1] )

    {

      return false;

    }

  }

  return true;

}

int i4vec_frac ( int n, int a[], int k )

{

  int afrac;

  int i;

  int iryt;

  int j;

  int left;

  int temp;

  int x;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "I4VEC_FRAC - Fatal error!\n";

    cerr << "  Illegal nonpositive value of N = " << n << "\n";

    exit ( 1 );

  }

  if ( k <= 0 )

  {

    cerr << "\n";

    cerr << "I4VEC_FRAC - Fatal error!\n";

    cerr << "  Illegal nonpositive value of K = " << k << "\n";

    exit ( 1 );

  }

  if ( n < k )

  {

    cerr << "\n";

    cerr << "I4VEC_FRAC - Fatal error!\n";

    cerr << "  Illegal N < K, K = " << k << "\n";

    exit ( 1 );

  }

  left = 1;

  iryt = n;

  for ( ; ; )

  {

    if ( iryt <= left )

    {

      afrac = a[k-1];

      break;

    }

    x = a[k-1];

    i = left;

    j = iryt;

    for ( ; ; )

    {

      if ( j < i )

      {

        if ( j < k )

        {

          left = i;

        }

        if ( k < i )

        {

          iryt = j;

        }

        break;

      }

      while ( a[i-1] < x )

      {

        i = i + 1;

      }

      while ( x < a[j-1] )

      {

        j = j - 1;

      }

      if ( i <= j )

      {

        temp = a[i-1];

        a[i-1] = a[j-1];

        a[j-1] = temp;

        i = i + 1;

        j = j - 1;

      }

    }

  }

  return afrac;

}

void i4vec_heap_d ( int n, int a[] )

{

  int i;

  int ifree;

  int key;

  int m;

  for ( i = (n/2)-1; 0 <= i; i-- )

  { 

    key = a[i];

    ifree = i;

    for ( ; ; )

    {

      m = 2 * ifree + 1;

      if ( n <= m )

      {

        break;

      }

      else

      {

        if ( m + 1 < n )

        {

          if ( a[m] < a[m+1] )

          {

            m = m + 1;

          }

        }

        if ( key < a[m] )

        {

          a[ifree] = a[m];

          ifree = m;

        }

        else

        {

          break;

        }

      }

    }

    a[ifree] = key;

  }

  return;

}

int i4vec_index ( int n, int a[], int aval )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    if ( a[i] == aval )

    {

      return i;

    }

  }

  return -1;

}

void i4vec_indicator ( int n, int a[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    a[i] = i + 1;

  }

  return;

}

int *i4vec_indicator_new ( int n )

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

int i4vec_maxloc_last ( int n, int x[] )

{

  int i;

  int index;

  int value;

  index = 0;

  value = x[0];

  for ( i = 1; i < n; i++ )

  {

    if ( value <= x[i] )

    {

      index = i;

      value = x[i];

    }

  }

  return index;

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

bool i4vec_pairwise_prime ( int n, int a[] )

{

  int i;

  int j;

  for ( i = 0; i < n; i++ )

  {

    for ( j = i+1; j < n; j++ )

    {

      if ( i4_gcd ( a[i], a[j] ) != 1 ) 

      {

        return false;

      }

    }

  }

  return true;

}

int i4vec_product ( int n, int a[] )

{

  int i;

  int product;

  product = 1;

  for ( i = 0; i < n; i++ )

  {

    product = product * a[i];

  }

  return product;

}

void i4vec_reverse ( int n, int a[] )

{

  int i;

  int temp;

  for ( i = 0; i < n/2; i++ )

  {

    temp = a[i];

    a[i] = a[n-1-i];

    a[n-1-i] = temp;

  }

  return;

}

void i4vec_sort_bubble_a ( int n, int a[] )

{

  int i;

  int j;

  int k;

  for ( i = 0; i < n-1; i++ )

  {

    for ( j = i+1; j < n; j++ )

    {

      if ( a[j] < a[i] )

      {

        k = a[i];

        a[i] = a[j];

        a[j] = k;

      }

    }

  }

  return;

}

void i4vec_sort_heap_a ( int n, int a[] )

{

  int n1;

  int temp;

  if ( n <= 1 )

  {

    return;

  }

  i4vec_heap_d ( n, a );

  temp = a[0];

  a[0] = a[n-1];

  a[n-1] = temp;

  for ( n1 = n-1; 2 <= n1; n1-- )

  {

    i4vec_heap_d ( n1, a );

    temp = a[0];

    a[0] = a[n1-1];

    a[n1-1] = temp;

  }

  return;

}

int *i4vec_sort_heap_index_a ( int n, int a[] )

{

  int aval;

  int i;

  int *indx;

  int indxt;

  int ir;

  int j;

  int l;

  indx = i4vec_indicator_new ( n );

  l = n / 2 + 1;

  ir = n;

  for ( ; ; )

  {

    if ( 1 < l )

    {

      l = l - 1;

      indxt = indx[l-1];

      aval = a[indxt-1];

    }

    else

    {

      indxt = indx[ir-1];

      aval = a[indxt-1];

      indx[ir-1] = indx[0];

      ir = ir - 1;

      if ( ir == 1 )

      {

        indx[0] = indxt;

        for ( i = 0; i < n; i++ )

        {

          indx[i] = indx[i] - 1;

        }

        return indx;

      }

    }

    i = l;

    j = l + l;

    while ( j <= ir )

    {

      if ( j < ir )

      {

        if ( a[indx[j-1]-1] < a[indx[j]-1] )

        {

          j = j + 1;

        }

      }

      if ( aval < a[indx[j-1]-1] )

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

}

int *i4vec_sort_heap_index_d ( int n, int a[] )

{

  int aval;

  int i;

  int *indx;

  int indxt;

  int ir;

  int j;

  int l;

  indx = i4vec_indicator_new ( n );

  l = n / 2 + 1;

  ir = n;

  for ( ; ; )

  {

    if ( 1 < l )

    {

      l = l - 1;

      indxt = indx[l-1];

      aval = a[indxt-1];

    }

    else

    {

      indxt = indx[ir-1];

      aval = a[indxt-1];

      indx[ir-1] = indx[0];

      ir = ir - 1;

      if ( ir == 1 )

      {

        indx[0] = indxt;

        for ( i = 0; i < n; i++ )

        {

          indx[i] = indx[i] - 1;

        }

        return indx;

      }

    }

    i = l;

    j = l + l;

    while ( j <= ir )

    {

      if ( j < ir )

      {

        if ( a[indx[j]-1] < a[indx[j-1]-1] )

        {

          j = j + 1;

        }

      }

      if ( a[indx[j-1]-1] < aval )

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

int *i4vec_uniform ( int n, int a, int b, int &seed )

{

  int i;

  int k;

  float r;

  int value;

  int *x;

  

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "I4VEC_UNIFORM - Fatal error!\n";

    cerr << "  Input value of SEED = 0.\n";

    exit ( 1 );

  }

  x = new int[n];

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + 2147483647;

    }

    r = ( float ) ( seed ) * 4.656612875E-10;

    r = ( 1.0 - r ) * ( ( float ) ( i4_min ( a, b ) ) - 0.5 ) 

      +         r   * ( ( float ) ( i4_max ( a, b ) ) + 0.5 );

    value = r4_nint ( r );

    value = i4_max ( value, i4_min ( a, b ) );

    value = i4_min ( value, i4_max ( a, b ) );

    x[i] = value;

  }

  return x;

}

void i4vec0_print ( int n, int a[], string title )

{

  int i;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  for ( i = 0; i <= n-1; i++ ) 

  {

    cout << setw(6) << i    << "  " 

         << setw(8) << a[i] << "\n";

  }

  return;

}

void i4vec1_print ( int n, int a[], string title )

{

  int i;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  for ( i = 0; i <= n-1; i++ ) 

  {

    cout                    << "  "

         << setw(6) << i+1  << "  " 

         << setw(8) << a[i] << "\n";

  }

  return;

}

void index_box2_next_2d ( int n1, int n2, int ic, int jc, int &i, int &j, 

  bool &more )

{

  if ( !( more ) )

  {

    more = true;

    i = ic - n1;

    j = jc - n2;

    return;

  }

  if ( i == ic + n1 && j == jc + n2 )

  {

    more = false;

    return;

  }

  j = j + 1;

  if ( jc + n2 < j )

  {

    j = jc - n2;

    i = i + 1;

  }

  else if ( j < jc + n2 && ( i == ic - n1 || i == ic + n1 ) )

  {

    return;

  }

  else

  {

    j = jc + n2;

    return;

  }

  return;

}

void index_box2_next_3d ( int n1, int n2, int n3, int ic, int jc, int kc, 

  int &i, int &j, int &k, bool &more )

{

  if ( !more )

  {

    more = true;

    i = ic - n1;

    j = jc - n2;

    k = kc - n3;

    return;

  }

  if ( i == ic + n1 && j == jc + n2 && k == kc + n3 ) 

  {

    more = false;

    return;

  }

  k = k + 1;

  if ( kc + n3 < k )

  {

    k = kc - n3;

    j = j + 1;

  }

  else if ( k < kc + n3 &&

    ( i == ic - n1 || i == ic + n1 ||

      j == jc - n2 || j == jc + n2 ) )

  {

    return;

  }

  else

  {

    k = kc + n3;

    return;

  }

  if ( jc + n2 < j )

  {

    j = jc - n2;

    i = i + 1;

  }

  else if ( j < jc + n2 &&

    ( i == ic - n1 || i == ic + n1 || 

      k == kc - n3 || k == kc + n3 ) )

  {

    return;

  }

  else

  {

    j = jc + n2;

    return;

  }

  return;

}

void index_box_next_2d ( int n1, int n2, int &i, int &j, bool &more )

{

  if ( !more )

  {

    more = true;

    i = 1;

    j = 1;

    return;

  }

  if ( i == n1 && j == n2 )

  {

    more = false;

    return;

  }

  j = j + 1;

  if ( n2 < j )

  {

    j = 1;

    i = i + 1;

  }

  else if ( j < n2 && ( i == 1 || i == n1 ) )

  {

    return;

  }

  else

  {

    j = n2;

    return;

  }

  return;

}

void index_box_next_3d ( int n1, int n2, int n3, int &i, int &j, int &k, 

  bool &more )

{

  if ( !more )

  {

    more = true;

    i = 1;

    j = 1;

    k = 1;

    return;

  }

  if ( i == n1 && j == n2 && k == n3 )

  {

    more = false;

    return;

  }

  k = k + 1;

  if ( n3 < k )

  {

    k = 1;

    j = j + 1;

  }

  else if ( k < n3 && ( i == 1 || i == n1 || j == 1 || j == n2 ) )

  {

    return;

  }

  else

  {

    k = n3;

    return;

  }

  if ( n2 < j )

  {

    j = 1;

    i = i + 1;

  }

  else if ( j < n2 && ( i == 1 || i == n1 || k == 1 || k == n3 ) )

  {

    return;

  }

  else

  {

    j = n2;

    return;

  }

  return;

}

void index_next0 ( int n, int hi, int a[], bool &more )

{

  int i;

  int inc;

  if ( !more )

  {

    for ( i = 0; i < n; i++ )

    {

      a[i] = 1;

    }

    if ( hi < 1 )

    {

      more = false;

      cerr << "\n";

      cerr << "INDEX_NEXT0 - Fatal error!\n";

      cerr << "  HI is " << hi << "\n";

      cerr << "  but HI must be at least 1.\n";

      exit ( 1 );

    }

  }

  else

  {

    inc = 0;

    while ( hi <= a[inc] )

    {

      a[inc] = 1;

      inc = inc + 1;

    }

    a[inc] = a[inc] + 1;

  }

  more = false;

  for ( i = 0; i < n; i++ )

  {

    if ( a[i] < hi )

    {

      more = true;

    }

  }

  return;

}

void index_next1 ( int n, int hi[], int a[], bool &more )

{

  int i;

  int inc;

  if ( !more )

  {

    for ( i = 0; i < n; i++ )

    {

      a[i] = 1;

    }

    for ( i = 0; i < n; i++ )

    {

      if ( hi[i] < 1 )

      {

        more = false;

        cerr << "\n";

        cerr << "INDEX_NEXT1 - Fatal error!\n";

        cerr << "  Entry " << i << " of HI is " << hi[i] << "\n";

        cerr << "  but all entries must be at least 1.\n";

        exit ( 1 );

      }

    }

  }

  else

  {

    inc = 0;

    while ( hi[inc] <= a[inc] )

    {

      a[inc] = 1;

      inc = inc + 1;

    }

    a[inc] = a[inc] + 1;

  }

  more = false;

  for ( i = 0; i < n; i++ )

  {

    if ( a[i] < hi[i] )

    {

      more = true;

    }

  }

  return;

}

void index_next2 ( int n, int lo[], int hi[], int a[], bool &more )

{

  int i;

  int inc;

  if ( !more )

  {

    for ( i = 0; i < n; i++ )

    {

      a[i] = lo[i];

    }

    for ( i = 0; i < n; i++ )

    {

      if ( hi[i] < lo[i] )

      {

        more = false;

        cerr << "\n";

        cerr << "INDEX_NEXT2 - Fatal error!\n";

        cerr << "  Entry " << i << " of HI is " << hi[i] << "\n";

        cerr << "  Entry " << i << " of LO is " << lo[i] << "\n";

        cerr << "  but LO(I) <= HI(I) is required.\n";

        exit ( 1 );

      }

    }

  }

  else

  {

    inc = 0;

    while ( hi[inc] <= a[inc] )

    {

      a[inc] = lo[inc];

      inc = inc + 1;

    }

    a[inc] = a[inc] + 1;

  }

  more = false;

  for ( i = 0; i < n; i++ )

  {

    if ( a[i] < hi[i] )

    {

      more = true;

    }

  }

  return;

}

int index_rank0 ( int n, int hi, int a[] )

{

  int i;

  int range;

  int rank;

  rank = -1;

  for ( i = 0; i < n; i++ )

  {

    if ( a[i] < 1 || hi < a[i] )

    {

      return rank;

    }

  }

  rank = 0;

  for ( i = n-1; 0 <= i; i-- )

  {

    rank = hi * rank + a[i];

  }

  rank = 1;

  range = 1;

  for ( i = 0; i < n; i++ )

  {

    rank = rank + ( a[i] - 1 ) * range;

    range = range * hi;

  }

  return rank;

}

int index_rank1 ( int n, int hi[], int a[] )

{

  int i;

  int range;

  int rank;

  rank = -1;

  for ( i = 0; i < n; i++ )

  {

    if ( a[i] < 1 || hi[i] < a[i] )

    {

      return rank;

    }

  }

  rank = 0;

  for ( i = n-1; 0 <= i; i-- )

  {

    rank = hi[i] * rank + a[i];

  }

  rank = 1;

  range = 1;

  for ( i = 0; i < n; i++ )

  {

    rank = rank + ( a[i] - 1 ) * range;

    range = range * hi[i];

  }

  return rank;

}

int index_rank2 ( int n, int lo[], int hi[], int a[] )

{

  int i;

  int range;

  int rank;

  for ( i = 0; i < n; i++ )

  {

    if ( a[i] < lo[i] || hi[i] < a[i] )

    {

      rank = -1;

      return rank;

    }

  }

  rank = 1;

  range = 1;

  for ( i = 0; i < n; i++ )

  {

    rank = rank + ( a[i] - lo[i] ) * range;

    range = range * ( hi[i] + 1 - lo[i] );

  }

  return rank;

}

void index_unrank0 ( int n, int hi, int rank, int a[] )

{

  int i;

  int j;

  int k;

  int range;

  for ( i = 0; i < n; i++ )

  {

    a[i] = 0;

  }

  if ( rank < 1 )

  {

    return;

  }

  range = i4_power ( hi, n );

  if ( range < rank )

  {

    return;

  }

  k = rank - 1;

  for ( i = n-1; 0 <= i; i-- )

  {

    range = range / hi;

    j = k / range;

    a[i] = j + 1;

    k = k - j * range;

  }

  return;

}

void index_unrank1 ( int n, int hi[], int rank, int a[] )

{

  int i;

  int j;

  int k;

  int range;

  for ( i = 0; i < n; i++ )

  {

    a[i] = 0;

  }

  if ( rank < 1 )

  {

    return;

  }

  range = i4vec_product ( n, hi );

  if ( range < rank )

  {

    return;

  }

  k = rank - 1;

  for ( i = n-1; 0 <= i; i-- )

  {

    range = range / hi[i];

    j = k / range;

    a[i] = j + 1;

    k = k - j * range;

  }

  return;

}

void index_unrank2 ( int n, int lo[], int hi[], int rank, int a[] )

{

  int i;

  int j;

  int k;

  int range;

  for ( i = 0; i < n; i++ )

  {

    a[i] = 0;

  }

  if ( rank < 1 )

  {

    return;

  }

  range = 1;

  for ( i = 0; i < n; i++ )

  {

    range = range * ( hi[i] + 1 - lo[i] );

  }

  if ( range < rank )

  {

    return;

  }

  k = rank - 1;

  for ( i = n-1; 0 <= i; i-- )

  {

    range = range / ( hi[i] + 1 - lo[i] );

    j = k / range;

    a[i] = j + lo[i];

    k = k - j * range;

  }

  return;

}

void ins_perm ( int n, int ins[], int p[] )

{

  int i;

  int itemp;

  int j;

  i4vec_indicator ( n, p );

  for ( i = n-1; 1 <= i; i-- )

  {

    itemp = p[i-ins[i]];

    for ( j = i-ins[i]; j <= i-1; j++ )

    {

      p[j] = p[j+1];

    }

    p[i] = itemp;

  }

  return;

}

int inverse_mod_n ( int b, int n )

{

  int b0;

  int n0;

  int q;

  int r;

  int t;

  int t0;

  int temp;

  int y;

  n0 = n;

  b0 = b;

  t0 = 0;

  t = 1;

  q = n / b;

  r = n - q * b;

  while ( 0 < r )

  {

    temp = t0 - q * t;

    if ( 0 <= temp )

    {

      temp = ( temp % n );

    }

    if ( temp < 0 )

    {

      temp = n - ( ( - temp ) % n );

    }

    t0 = t;

    t = temp;

    n0 = b0;

    b0 = r;

    q = n0 / b0;

    r = n0 - q * b0;

  }

  if ( b0 != 1 )

  {

    y = 0;

    return y;

  }

  y = ( t % n );

  return y;

}

void involute_enum ( int n, int s[] )

{

  int i;

  if ( n < 0 )

  {

    return;

  }

  s[0] = 1;

  if ( n <= 0 )

  {

    return;

  }

  s[1] = 1;

  for ( i = 2; i <= n; i++ )

  {

    s[i] = s[i-1] + ( i - 1 ) * s[i-2];

  }

  return;

}

void jfrac_to_rfrac ( int m, double r[], double s[], double p[], double q[] )

{

  double *a;

  double *b;

  int i;

  int k;

  a = new double[m*m];

  b = new double[m*m];

  a[0+0*m] = r[0];

  b[0+0*m] = s[0];

  if ( 1 < m )

  {

    for ( k = 1; k < m; k++ )

    {

      a[k+k*m] = r[0];

      b[k+k*m] = b[k-1+(k-1)*m] + s[k];

    }

    a[0+1*m] = r[0] * s[1];

    b[0+1*m] = r[1] + s[0] * s[1];

    for ( k = 2; k < m; k++ )

    {

      a[0  +k*m] = s[k] * a[0+(k-1)*m]   + r[k] * a[0+(k-2)*m];

      a[k-1+k*m] =        a[k-2+(k-1)*m] + s[k] * r[0];

      b[0  +k*m] = s[k] * b[0+(k-1)*m]   + r[k] * b[0+(k-2)*m];

      b[k-1+k*m] =        b[k-2+(k-1)*m] + s[k] * b[k-1+(k-1)*m] + r[k];

    }

    for ( k = 2; k < m; k++ )

    {

      for ( i = 1; i < k-1; i++ )

      {

        a[i+k*m] = a[i-1+(k-1)*m] + s[k] * a[i+(k-1)*m] 

                                  + r[k] * a[i+(k-2)*m];

        b[i+k*m] = b[i-1+(k-1)*m] + s[k] * b[i+(k-1)*m] 

                                  + r[k] * b[i+(k-2)*m];

      }

    }

  }

  for ( i = 0; i < m; i++ )

  {

    p[i] = a[i+(m-1)*m];

  }

  for ( i = 0; i < m; i++ )

  {

    q[i] = b[i+(m-1)*m];

  }

  q[m] = 1.0;

  delete [] a;

  delete [] b;

  return;

}

int josephus ( int n, int m, int k )

{

  int m2;

  int x;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "JOSEPHUS - Fatal error!\n";

    cerr << "  N <= 0.\n";

    exit ( 1 );

  }

  if ( m == 0 )

  {

    cerr << "\n";

    cerr << "JOSEPHUS - Fatal error!\n";

    cerr << "  M = 0.\n";

    exit ( 1 );

  }

  if ( k <= 0 || n < k )

  {

    cerr << "\n";

    cerr << "JOSEPHUS - Fatal error!\n";

    cerr << "  J <= 0 or N < K.\n";

    exit ( 1 );

  }

  m2 = i4_modp ( m, n );

  x = k * m2;

  while ( n < x )

  {

    x = ( m2 * ( x - n ) - 1 ) / ( m2 - 1 );

  }

  return x;

}

void ksub_next ( int n, int k, int a[], bool &more )

{

  int j;

  static int m = 0;

  static int m2 = 0;

  if ( k < 0 || n < k )

  {

    cerr << "\n";

    cerr << "KSUB_NEXT - Fatal error!\n";

    cerr << "  N = " << n << "\n";

    cerr << "  K = " << k << "\n";

    cerr << "  but 0 <= K <= N is required!\n";

    exit ( 1 );

  }

  if ( !more )

  {

    m2 = 0;

    m = k;

  }

  else

  {

    if ( m2 < n-m )

    {

      m = 0;

    }

    m = m + 1;

    m2 = a[k-m];

  }

  for ( j = 1; j <= m; j++ )

  {

    a[k+j-m-1] = m2 + j;

  }

  more = ( a[0] != (n-k+1) );

  return;

}

void ksub_next2 ( int n, int k, int a[], int &in, int &iout )

{

  int j;

  int m;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "KSUB_NEXT2 - Fatal error!\n";

    cerr << "  N = " << n << "\n";

    cerr << "  but 0 < N is required!\n";

    exit ( 1 );

  }

  if ( k < 0 || n < k )

  {

    cerr << "\n";

    cerr << "KSUB_NEXT2 - Fatal error!\n";

    cerr << "  N = " << n << "\n";

    cerr << "  K = " << k << "\n";

    cerr << "  but 0 <= K <= N is required!\n";

    exit ( 1 );

  }

  j = 0;

  for ( ; ; )

  {

    if ( 0 < j || ( k % 2 ) == 0 )

    {

      j = j + 1;

      if ( k < j )

      {

        a[k-1] = k;

        in = k;

        iout = n;

        return;

      }

      if ( a[j-1] != j )

      {

        iout = a[j-1];

        in = iout - 1;

        a[j-1] = in;

        if ( j != 1 )

        {

          in = j - 1;

          a[j-2] = in;

        }

        return;

      }

    }

    j = j + 1;

    m = n;

    if ( j < k )

    {

      m = a[j] - 1;

    }

    if ( m != a[j-1] )

    {

      break;

    }

  }

  in = a[j-1] + 1;

  a[j-1] = in;

  iout = in - 1;

  if ( j != 1 )

  {

    a[j-2] = iout;

    iout = j - 1;

  }

  return;

}

void ksub_next3 ( int n, int k, int a[], bool &more, int &in, int &iout )

{

  int i;

  int j;

  int m;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "KSUB_NEXT3 - Fatal error!\n";

    cerr << "  N = " << n << "\n";

    cerr << "  but 0 < N is required!\n";

    exit ( 1 );

  }

  if ( k < 0 || n < k )

  {

    cerr << "\n";

    cerr << "KSUB_NEXT3 - Fatal error!\n";

    cerr << "  N = " << n << "\n";

    cerr << "  K = " << k << "\n";

    cerr << "  but 0 <= K <= N is required!\n";

    exit ( 1 );

  }

  if ( !more )

  {

    in = 0;

    iout = 0;

    i4vec_indicator ( k, a );

    more = ( k != n );

    return;

  }

  j = 0;

  for ( ; ; )

  {

    if ( 0 < j || ( k % 2 ) == 0 )

    {

      j = j + 1;

      if ( a[j-1] != j )

      {

        iout = a[j-1];

        in = iout - 1;

        a[j-1] = in;

        if ( j != 1 )

        {

          in = j - 1;

          a[j-2] = in;

        }

        if ( k != 1 )

        {

          more = ( a[k-2] == k-1 );

        }

        more = ( !more ) || ( a[k-1] != n );

        return;

      }

    }

    j = j + 1;

    m = n;

    if ( j < k )

    {

      m = a[j] - 1;

    }

    if ( m != a[j-1] )

    {

      break;

    }

  }

  in = a[j-1] + 1;

  a[j-1] = in;

  iout = in - 1;

  if ( j != 1 )

  {

    a[j-2] = iout;

    iout = j - 1;

  }

  if ( k != 1 )

  {

    more = ( a[k-2] == k-1 );

  }

  more = ( !more ) || ( a[k-1] != n );

  return;

}

void ksub_next4 ( int n, int k, int a[], bool &done )

{

  int i;

  int j;

  int jsave;

  if ( k < 0 || n < k )

  {

    cerr << "\n";

    cerr << "KSUB_NEXT4 - Fatal error!\n";

    cerr << "  N = " << n << "\n";

    cerr << "  K = " << k << "\n";

    cerr << "  but 0 <= K <= N is required!\n";

    exit ( 1 );

  }

  if ( done )

  {

    i4vec_indicator ( k, a );

    if ( 0 < n )

    {

      done = false;

    }

    else

    {

      done = true;

    }

  }

  else

  {

    if ( a[0] < n-k+1 )

    {

      done = false;

      jsave = k-1;

      for ( j = 0; j < k-1; j++ )

      {

        if ( a[j] + 1 < a[j+1] )

        {

          jsave = j;

          break;

        }

      }

      i4vec_indicator ( jsave, a );

      a[jsave] = a[jsave] + 1;

    }

    else

    {

      done = true;

    }

  }

  return;

}

void ksub_random ( int n, int k, int &seed, int a[] )

{

  int i;

  int ids;

  int ihi;

  int ip;

  int ir;

  int is;

  int ix;

  int l;

  int ll;

  int m;

  int m0;

  double r;

  if ( k < 0 )

  {

    cerr << "\n";

    cerr << "KSUB_RANDOM - Fatal error!\n";

    cerr << "  K = " << k << "\n";

    cerr << "  but 0 <= K is required!\n";

    exit ( 1 );

  }

  else if ( n < k )

  {

    cerr << "\n";

    cerr << "KSUB_RANDOM - Fatal error!\n";

    cerr << "  N = " << n << "\n";

    cerr << "  K = " << k << "\n";

    cerr << "  K <= N is required!\n";

    exit ( 1 );

  }

  if ( k == 0 )

  {

    return;

  }

  for ( i = 1; i <= k; i++ )

  {

    a[i-1] = ( ( i - 1 ) * n ) / k;

  }

  for ( i = 1; i <= k; i++ )

  {

    for ( ; ; )

    {

      ix = i4_uniform_ab ( 1, n, seed );

      l = 1 + ( ix * k - 1 ) / n;

      if ( a[l-1] < ix )

      {

        break;

      }

    }

    a[l-1] = a[l-1] + 1;

  }

  ip = 0;

  is = k;

  for ( i = 1; i <= k; i++ )

  {

    m = a[i-1];

    a[i-1] = 0;

    if ( m != ( ( i - 1 ) * n ) / k )

    {

      ip = ip + 1;

      a[ip-1] = m;

    }

  }

  ihi = ip;

  for ( i = 1; i <= ihi; i++ )

  {

    ip = ihi + 1 - i;

    l = 1 + ( a[ip-1] * k - 1 ) / n;

    ids = a[ip-1] - ( ( l - 1 ) * n ) / k;

    a[ip-1] = 0;

    a[is-1] = l;

    is = is - ids;

  }

  for ( ll = 1; ll <= k; ll++ )

  {

    l = k + 1 - ll;

    if ( a[l-1] != 0 )

    {

      ir = l;

      m0 = 1 + ( ( a[l-1] - 1 ) * n ) / k;

      m = ( a[l-1] * n ) / k - m0 + 1;

    }

    ix = i4_uniform_ab ( m0, m0 + m - 1, seed );

    i = l + 1;

    while ( i <= ir )

    {

      if ( ix < a[i-1] )

      {

        break;

      }

      ix = ix + 1;

      a[i-2] = a[i-1];

      i = i + 1;

    }

    a[i-2] = ix;

    m = m - 1;

  }

  return;

}

void ksub_random2 ( int n, int k, int &seed, int a[] )

{

  int available;

  int candidate;

  int have;

  int need;

  double r;

  if ( k < 0 || n < k )

  {

    cerr << "\n";

    cerr << "KSUB_RANDOM2 - Fatal error!\n";

    cerr << "  N = " << n << "\n";

    cerr << "  K = " << k << "\n";

    cerr << "  but 0 <= K <= N is required!\n";

    exit ( 1 );

  }

  if ( k == 0 )

  {

    return;

  }

  need = k;

  have = 0;

  available = n;

  candidate = 0;

  for ( ; ; )

  {

    candidate = candidate + 1;

    r = r8_uniform_01 ( seed );

    if ( r * ( double ) available <= ( double ) need )

    {

      need = need - 1;

      a[have] = candidate;

      have = have + 1;

      if ( need <= 0 )

      {

        break;

      }

    }

    available = available - 1;

  }

  return;

}

void ksub_random3 ( int n, int k, int &seed, int a[] )

{

  int i;

  int j;

  double r;

  if ( k < 0 || n < k )

  {

    cerr << "\n";

    cerr << "KSUB_RANDOM3 - Fatal error!\n";

    cerr << "  N = " << n << "\n";

    cerr << "  K = " << k << "\n";

    cerr << "  but 0 <= K <= N is required!\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    a[i] = 0;

  }

  if ( k == 0 )

  {

    return;

  }

  for ( i = n - k + 1; i <= n; i++ )

  {

    j = i4_uniform_ab ( 1, i, seed );

    if ( a[j-1] == 0 )

    {

      a[j-1] = 1;

    }

    else

    {

      a[i-1] = 1;

    }

  }

  return;

}

void ksub_random4 ( int n, int k, int &seed, int a[] )

{

  int i;

  int next;

  double r;

  next = 0;

  while ( next < n )

  {

    next = next + 1;

    if ( next <= k )

    {

      i = next;

      a[i-1] = next;

    }

    else

    {

      r = r8_uniform_01 ( seed );

      if ( r * ( double ) next <= ( double ) k )

      {

        i = i4_uniform_ab ( 1, k, seed );

        a[i-1] = next;

      }

    }

  }

  return;

}

int *ksub_random5 ( int n, int k, int &seed )

{

  int *a;

  int *b;

  static int base = 1;

  int i;

  int j;

  int t;

  b = new int[n];

  for ( i = 0; i < n; i++ )

  {

    b[i] = i + base;

  }

  for ( i = 0; i < k; i++)

  {

    j = i4_uniform_ab ( i, n - 1, seed );

    t    = b[i];

    b[i] = b[j];

    b[j] = t;

  }

  a = new int[k];

  for ( i = 0; i < k; i++ )

  {

    a[i] = b[i];

  }

  delete [] b;

  i4vec_sort_heap_a ( k, a );

  return a;

}

void ksub_rank ( int k, int a[], int &rank )

{

  int i;

  int iprod;

  int j;

  rank = 0;

  for ( i = 1; i <= k; i++ )

  {

    iprod = 1;

    for ( j = i+1; j <= a[i-1]-1; j++ )

    {

      iprod = iprod * j;

    }

    for ( j = 1; j <= a[i-1]-i-1; j++ )

    {

      iprod = iprod / j;

    }

    if ( a[i-1] == 1 )

    {

      iprod = 0;

    }

    rank = rank + iprod;

  }

  rank = rank + 1;

  return; 

}

void ksub_to_comp ( int ns, int ks, int as[], int &nc, int &kc, int ac[] )

{

  int i;

  nc = ns - ks;

  kc = ks + 1;

  ac[0] = as[0] - 1;

  for ( i = 1; i < kc - 1; i++ )

  {

    ac[i] = as[i] - as[i-1] - 1;

  }

  ac[kc-1] = ns - as[ks-1];

  return;

}

void ksub_to_compnz ( int ns, int ks, int as[], int &nc, int &kc, int ac[] )

{

  int i;

  nc = ns;

  kc = ks + 1;

  ac[0] = as[0];

  for ( i = 1; i < kc - 1; i++ )

  {

    ac[i] = as[i] - as[i-1];

  }

  ac[kc-1] = ns - as[ks-1];

  return;

}

void ksub_unrank ( int k, int rank, int a[] )

{

  int i;

  int ii;

  int ip;

  int iprod;

  int jrank;

  jrank = rank - 1;

  for ( i = k; 1 <= i; i-- )

  {

    ip = i - 1;

    iprod = 1;

    for ( ; ; )

    {

      ip = ip + 1;

      if ( ip != i )

      {

        iprod = ( ip * iprod ) / ( ip - i );

      }

      if ( jrank < iprod )

      {

        break;

      }

    }

    if ( ip != i )

    {

      iprod = ( ( ip - i ) * iprod ) / ip;

    }

    jrank = jrank - iprod;

    a[i-1] = ip;

  }

  return;

}

void lvec_next ( int n, bool lvec[] )

{

  int i;

  for ( i = n - 1; 0 <= i; i-- )

  {

    if ( !lvec[i] )

    {

      lvec[i] = true;

      return;

    }

    lvec[i] = false;

  }

  return;

}

void matrix_product_opt ( int n, int rank[], int &cost, int order[] )

{

# define STACK_MAX 100

  int *best;

  int *cost2;

  int cost3;

  int i;

  int i_inf;

  int i1;

  int i2;

  int i3;

  int j;

  int k;

  int stack[STACK_MAX];

  int stack_num;

  int step;

  best = new int[n*n];

  cost2 = new int[n*n];

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j <= i; j++ )

    {

      cost2[i+j*n] = 0;

    }

    for ( j = i+1; j < n; j++ )

    {

      cost2[i+j*n] = i4_huge ( );

    }

  }

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      best[i+j*n] = 0;

    }

  }

  for ( j = 1; j <= n-1; j++ )

  {

    for ( i = 1; i <= n-j; i++ )

    {

      for ( k = i+1; k <= i+j; k++ )

      {

        cost3 = cost2[i-1+(k-2)*n] + cost2[k-1+(i+j-1)*n] 

          + rank[i-1] * rank[k-1] * rank[i+j];

        if ( cost3 < cost2[i-1+(i+j-1)*n] )

        {

          cost2[i-1+(i+j-1)*n] = cost3;

          best[i-1+(i+j-1)*n] = k;

        }

      }

    }

  }

  cost = cost2[0+(n-1)*n];

  stack_num = 0;

  i1 = 1;

  i2 = n;

  if ( i1+1 < i2 )

  {

    stack[stack_num] = i1;

    stack_num = stack_num + 1;

    stack[stack_num] = i2;

    stack_num = stack_num + 1;

  }

  step = n - 1;

  while ( 0 < stack_num )

  {

    stack_num = stack_num - 1;

    i3 = stack[stack_num];

    stack_num = stack_num - 1;

    i1 = stack[stack_num];

    i2 = best[i1-1+(i3-1)*n];

    step = step - 1;

    order[step] = i2 - 1;

    if ( i1 == i2-1 )

    {

    }

    else if ( i1+1 == i2-1 )

    {

      step = step - 1;

      order[step] = i2 - 2;

    }

    else

    {

      stack[stack_num] = i1;

      stack_num = stack_num + 1;

      stack[stack_num] = i2 - 1;

      stack_num = stack_num + 1;

    }

    if ( i2 == i3 )

    {

    }

    else if ( i2+1 == i3 )

    {

      step = step - 1;

      order[step] = i2;

    }

    else

    {

      stack[stack_num] = i2;

      stack_num = stack_num + 1;

      stack[stack_num] = i3;

      stack_num = stack_num + 1;

    }

  }

  delete [] best;

  delete [] cost2;

  return;

# undef STACK_MAX

}

void moebius_matrix ( int n, int a[], int mu[] )

{

  int i;

  int j;

  int *p;

  p = new int[n];

  triang ( n, a, p );

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      mu[i+j*n] = a[i+j*n];

    }

  }

  i4mat_perm2 ( n, n, mu, p, p );

  for ( i = 0; i < n-1; i++ )

  {

    for ( j = i+1; j < n; j++ )

    {

      mu[i+j*n] = - mu[i+j*n];

    }

  }

  i4mat_u1_inverse ( n, mu, mu );

  for ( i = 0; i < n; i++ )

  {

    for ( j = i; j < n; j++ )

    {

      if ( mu[i+j*n] != 0 )

      {

        mu[i+j*n] = 1;

      }

    }

  }

  i4mat_u1_inverse ( n, mu, mu );

  perm_inverse ( n, p );

  i4mat_perm2 ( n, n, mu, p, p );

  delete [] p;

  return;

}

int monomial_count ( int degree_max, int dim )

{

  int bot;

  int top;

  int total;

  total = 1;

  if ( degree_max < dim )

  {

    top = dim + 1;

    for ( bot = 1; bot <= degree_max; bot++ )

    {

      total = ( total * top ) / bot;

      top = top + 1;

    }

  }

  else

  {

    top = degree_max + 1;

    for ( bot = 1; bot <= dim; bot++ )

    {

      total = ( total * top ) / bot;

      top = top + 1;

    }

  }

  return total;

}

int *monomial_counts ( int degree_max, int dim )

{

  int *counts;

  int degree;

  counts = new int[degree_max+1];

  degree = 0;

  counts[degree] = 1;

  for ( degree = 1; degree <= degree_max; degree++ )

  {

    counts[degree] = ( counts[degree-1] * ( dim - 1 + degree ) ) / degree;

  }

  return counts;

}

int morse_thue ( int i )

{

# define NBITS 32

  int b[NBITS];

  int s;

  i = abs ( i );

  ui4_to_ubvec ( i, NBITS, b );

  s = 0;

  for ( i = 0; i < NBITS; i++ )

  {

    s = s + b[i];

  }

  s = s % 2;

  return s;

# undef NBITS

}

int multinomial_coef1 ( int nfactor, int factor[] )

{

  double arg;

  double fack;

  double facn;

  int i;

  int n;

  int value;

  for ( i = 0; i < nfactor; i++ )

  {

    if ( factor[i] < 0 )

    {

      cerr << "\n";

      cerr << "MULTINOMIAL_COEF1 - Fatal error\n";

      cerr << "  Factor " << i << " = " << factor[i] << "\n";

      cerr << "  But this value must be nonnegative.\n";

      exit ( 1 );

    }

  }

  n = i4vec_sum ( nfactor, factor );

  arg = ( double ) ( n + 1 );

  facn = r8_gamma_log ( arg );

  for ( i = 0; i < nfactor; i++ )

  {

    arg = ( double ) ( factor[i] + 1 );

    fack = r8_gamma_log ( arg );

    facn = facn - fack;

  }

  value = r8_nint ( exp ( facn ) );

  return value;

}

int multinomial_coef2 ( int nfactor, int factor[] )

{

  int i;

  int j;

  int k;

  int value;

  for ( i = 0; i < nfactor; i++ )

  {

    if ( factor[i] < 0 )

    {

      cerr << "\n";

      cerr << "MULTINOMIAL_COEF2 - Fatal error!\n";

      cerr << "  Factor " << i << " = " << factor[i] << "\n";

      cerr << "  But this value must be nonnegative.\n";

      exit ( 1 );

    }

  }

  value = 1;

  k = 0;

  for ( i = 0; i < nfactor; i++ )

  {

    for ( j = 1; j <= factor[i]; j++ )

    {

      k = k + 1;

      value = ( value * k ) / j;

    }

  }

  return value;

}

int multiperm_enum ( int n, int k, int counts[] )

{

  int i;

  int j;

  int number;

  int sum;

  int top;

  if ( n < 0 )

  {

    number = -1;

    return number;

  }

  if ( n == 0 )

  {

    number = 1;

    return number;

  }

  if ( k < 1 )

  {

    number = -1;

    return number;

  }

  for ( i = 0; i < k; i++ )

  {

    if ( counts[i] < 0 )

    {

      number = -1;

      return number;

    }

  }

  sum = 0;

  for ( i = 0; i < k; i++ )

  {

    sum = sum + counts[i];

  }

  if ( sum != n )

  {

    number = -1;

    return number;

  }

  top = 0;

  number = 1;

  for ( i = 0; i < k; i++ )

  {

    for ( j = 1; j <= counts[i]; j++ )

    {

      top = top + 1;

      number = ( number * top ) / j;

    }

  }

  return number;

}

void multiperm_next ( int n, int a[], bool &more )

{

  int i;

  int m;

  int temp;

  m = 0;

  for ( i = 1; i <= n-1; i++ )

  {

    if ( a[i-1] < a[i] )

    {

      m = i;

    }

  }

  if ( m == 0 )

  {

    more = false;

    i4vec_sort_heap_a ( n, a );

    return;

  }

  else

  {

    more = true;

  }

  if ( m + 1 < n )

  {

    i4vec_sort_heap_a ( n - m, a + m );

  }

  i = 1;

  for ( ; ; )

  {

    if ( a[m-1] < a[m+i-1] )

    {

      break;

    }

    i = i + 1;

  }

  temp = a[m-1];

  a[m-1] = a[m+i-1];

  a[m+i-1] = temp;

  return;

}

void network_flow_max ( int nnode, int nedge, int iendpt[], int icpflo[], 

  int source, int sink, int cut[], int node_flow[] )

{

  return;

}

unsigned int nim_sum ( int i, int j )

{

# define NBITS 32

  int bvec1[NBITS];

  int bvec2[NBITS];

  int bvec3[NBITS];

  unsigned int value;

  ui4_to_ubvec ( i, NBITS, bvec1 );

  ui4_to_ubvec ( j, NBITS, bvec2 );

  bvec_xor ( NBITS, bvec1, bvec2, bvec3 );

  value = ubvec_to_ui4 ( NBITS, bvec3 );

  return value;

# undef NBITS

}

void padovan ( int n, int p[] )

{

  int i;

  if ( n < 1 )

  {

    return;

  }

  p[0] = 1;

  if ( n < 2 )

  {

    return;

  }

  p[1] = 1;

  if ( n < 3 )

  {

    return;

  }

 

  p[2] = 1;

  for ( i = 4; i <= n; i++ )

  {

    p[i-1] = p[i-3] + p[i-4];

  }

  return;

}

void pell_basic ( int d, int &x0, int &y0 )

{

# define TERM_MAX 100

  int b[TERM_MAX+1];

  int i;

  int p;

  int pm1;

  int pm2;

  int q;

  int qm1;

  int qm2;

  int r;

  int term_num;

  if ( d <= 0 )

  {

    cerr << "\n";

    cerr << "PELL_BASIC - Fatal error!\n";

    cerr << "  Pell coefficient D <= 0.\n";

    x0 = 0;

    y0 = 0;

    exit ( 1 );

  }

  i4_sqrt ( d, q, r );

  if ( r == 0 )

  {

    cerr << "\n";

    cerr << "PELL_BASIC - Fatal error!\n";

    cerr << "  Pell coefficient is a perfect square.\n";

    x0 = 0;

    y0 = 0;

    exit ( 1 );

  }

  i4_sqrt_cf ( d, TERM_MAX, term_num, b );

  if ( ( term_num % 2 ) == 1 )

  {

    for ( i = term_num+1; i <= 2 * term_num; i++ )

    {

      b[i] = b[i-term_num];

    }

    term_num = 2 * term_num;

  }

  pm2 = 0;

  pm1 = 1;

  qm2 = 1;

  qm1 = 0;

  for ( i = 0; i < term_num; i++ )

  {

    p = b[i] * pm1 + pm2;

    q = b[i] * qm1 + qm2;

    pm2 = pm1;

    pm1 = p;

    qm2 = qm1;

    qm1 = q;

  }

  x0 = p;

  y0 = q;

  return;

# undef TERM_MAX

}

void pell_next ( int d, int x0, int y0, int xn, int yn, int &xnp1, int &ynp1 )

{

  xnp1 = x0 * xn + d * y0 * yn;

  ynp1 = x0 * yn +     y0 * xn;

  return;

}

int pent_enum ( int n )

{

  int p;

  p = ( n * ( 3 * n - 1 ) ) / 2;

  return p;

}

void perm_ascend ( int n, int a[], int &length, int sub[] )

{

  int a1;

  int a2;

  int i;

  int j;

  int k;

  int *top;

  int *top_prev;

  if ( n <= 0 )

  {

    length = 0;

    return;

  }

  top = new int[n];

  for ( i = 0; i < n; i++ )

  {

    top[i] = 0;

  }

  top_prev = new int[n];

  for ( i = 0; i < n; i++ )

  {

    top_prev[i] = 0;

  }

  for ( i = 0; i < n; i++ )

  {

    sub[i] = 0;

  }

  length = 0;

  for ( i = 1; i <= n; i++ )

  {

    k = 0;

    for ( j = 1; j <= length; j++ )

    {

      if ( a[i-1] <= a[top[j-1]-1] )

      {

        k = j;

        break;

      }

    }

    if ( k == 0 )

    {

      length = length + 1;

      k = length;

    }

    top[k-1] = i;

    if ( 1 < k )

    {

      top_prev[i-1] = top[k-2];

    }

    else

    {

      top_prev[i-1] = 0;

    }

  }

  j = top[length-1];

  sub[length-1] = a[j-1];

  for ( i = length-1; 1 <= i; i-- )

  {

    j = top_prev[j-1];

    sub[i-1] = a[j-1];

  }

  delete [] top;

  delete [] top_prev;

  return;

}

int perm_break_count ( int n, int p[] )

{

  bool error;

  int i;

  int value;

  value = 0;

  error = perm_check ( n, p );

  if ( error )

  {

    cerr << "\n";

    cerr << "PERM_BREAK_COUNT - Fatal error!\n";

    cerr << "  The input array does not represent\n";

    cerr << "  a proper permutation.\n";

    exit ( 1 );

  }

  if ( p[0] != 1 )

  {

    value = value + 1;

  }

  for ( i = 1; i <= n-1; i++ )

  {

    if ( abs ( p[i] - p[i-1] ) != 1 )

    {

      value = value + 1;

    }

  }

  if ( p[n-1] != n )

  {

    value = value + 1;

  }

  return value;

}

void perm_canon_to_cycle ( int n, int p1[], int p2[] )

{

  int i;

  int pmin;

  for ( i = 0; i < n; i++ )

  {

    p2[i] = p1[i];

  }

  pmin = p2[0] + 1;

  for ( i = 0; i < n; i++ )

  {

    if ( p2[i] < pmin )

    {

      pmin = p2[i];

      p2[i] = -p2[i];

    }

  }

  return;

}

bool perm_check ( int n, int p[] )

{

  bool error;

  int ifind;

  int iseek;

  for ( iseek = 1; iseek <= n; iseek++ )

  {

    error = true;

    for ( ifind = 1; ifind <= n; ifind++ )

    {

      if ( p[ifind-1] == iseek )

      {

        error = false;

        break;

      }

    }

    if ( error )

    {

      return true;

    }

  }

  return false;

}

void perm_cycle ( int n, int p[], int &isgn, int &ncycle, int iopt )

{

  bool error;

  int i;

  int i1;

  int i2;

  int is;

  error = perm_check ( n, p );

  if ( error )

  {

    cerr << "\n";

    cerr << "PERM_CYCLE - Fatal error!\n";

    cerr << "  The input array does not represent\n";

    cerr << "  a proper permutation.\n";

    exit ( 1 );

  }

  is = 1;

  ncycle = n;

  for ( i = 1; i <= n; i++ )

  {

    i1 = p[i-1];

    while ( i < i1 )

    {

      ncycle = ncycle - 1;

      i2 = p[i1-1];

      p[i1-1] = -i2;

      i1 = i2;

    }

    if ( iopt != 0 )

    {

      is = - i4_sign ( p[i-1] );

    }

    p[i-1] = abs ( p[i-1] ) * i4_sign ( is );

  }

  isgn = 1 - 2 * ( ( n - ncycle ) % 2 );

  return;

}

void perm_cycle_to_canon ( int n, int p1[], int p2[] )

{

  int *hi;

  int i;

  int *indx;

  int j;

  int k;

  int *lo;

  int ncycle;

  int next;

  int nhi;

  int nlo;

  int nmin;

  int *pmin;

  int *ptemp;

  hi = new int[n];

  lo = new int[n];

  pmin = new int[n];

  ptemp = new int[n];

  for ( i = 0; i < n; i++ )

  {

    p2[i] = p1[i];

  }

  nlo = 1;

  ncycle = 0;

  while ( nlo <= n )

  {

    ncycle = ncycle + 1;

    nhi = nlo;

    while ( nhi < n )

    {

      if ( p2[nhi] < 0 )

      {

        break;

      }

      nhi = nhi + 1;

    }

    p2[nlo-1] = -p2[nlo-1];

    pmin[ncycle-1] = p2[nlo-1];

    nmin = nlo;

    for ( i = nlo+1; i <= nhi; i++ )

    {

      if ( p2[i-1] < pmin[ncycle-1] )

      {

        pmin[ncycle-1] = p2[i-1];

        nmin = i;

      }

    }

    for ( i = nlo; i <= nmin-1; i++ )

    {

      ptemp[i+nhi-nmin] = p2[i-1];

    }

    for ( i = nmin; i <= nhi; i++ )

    {

      ptemp[i+nlo-nmin-1] = p2[i-1];

    }

    lo[ncycle-1] = nlo;

    hi[ncycle-1] = nhi;

    nlo = nhi + 1;

  }

  indx = i4vec_sort_heap_index_d ( ncycle, pmin );

  j = 0;

  for ( i = 0; i < ncycle; i++ )

  {

    next = indx[i];

    nlo = lo[next];

    nhi = hi[next];

 

    for ( k = nlo; k <= nhi; k++ )

    {

      j = j + 1;

      p2[j-1] = ptemp[k-1];

    }

  }

  delete [] hi;

  delete [] indx;

  delete [] lo;

  delete [] pmin;

  delete [] ptemp;

  return;

}

void perm_cycle_to_index ( int n, int p1[], int p2[] )

{

  int j;

  int k1;

  int k2;

  int k3;

  for ( j = 1; j <= n; j++ )

  {

    k1 = p1[j-1];

    if ( k1 < 0 )

    {

      k1 = -k1;

      k3 = k1;

    }

    if ( j + 1 <= n )

    {

      k2 = p1[j];

      if ( k2 < 0 )

      {

        k2 = k3;

      }

    }

    else

    {

      k2 = k3;

    }

    p2[k1-1] = k2;

  }

  return;

}

int perm_distance ( int n, int a[], int b[] )

{

  int *binv;

  int *c;

  int i;

  int length;

  int *sub;

  binv = new int[n];

  c = new int[n];

  sub = new int[n];

  for ( i = 0; i < n; i++ )

  {

    binv[i] = b[i];

  }

  perm_inverse ( n, binv );

  perm_mul ( n, a, binv, c );

  perm_ascend ( n, c, length, sub );

  delete [] binv;

  delete [] c;

  delete [] sub;

  return ( n - length );

}

int perm_fixed_enum ( int n, int m )

{

  int fnm;

  if ( n <= 0 )

  {

    fnm = 1;

  }

  else if ( m < 0 )

  {

    fnm = 0;

  }

  else if ( n < m )

  {

    fnm = 0;

  }

  else if ( m == n )

  {

    fnm = 1;

  }

  else if ( n == 1 )

  {

    if ( m == 1 )

    {

      fnm = 1;

    }

    else

    {

      fnm = 0;

    }

  }

  else

  {

    fnm = i4_choose ( n, m ) * derange_enum ( n - m );

  }

  return fnm;

}

void perm_free ( int npart, int ipart[], int nfree, int ifree[] )

{

  int i;

  int j;

  int k;

  int match;

  int n;

  n = npart + nfree;

  if ( npart < 0 )

  {

    cerr << "\n";

    cerr << "PERM_FREE - Fatal error!\n";

    cerr << "  NPART < 0.\n";

    exit ( 1 );

  }

  else if ( npart == 0 )

  {

    i4vec_indicator ( n, ifree );

  }

  else if ( nfree < 0 )

  {

    cerr << "\n";

    cerr << "PERM_FREE - Fatal error!\n";

    cerr << "  NFREE < 0.\n";

    exit ( 1 );

  }

  else if ( nfree == 0 )

  {

    return;

  }

  else

  {

    k = 0;

    for ( i = 1; i <= n; i++ )

    {

      match = -1;

      for ( j = 0; j < npart; j++ )

      {

        if ( ipart[j] == i )

        {

          match = j;

          break;

        }

      }

      if ( match == -1 )

      {

        k = k + 1;

        if ( nfree < k )

        {

          cerr << "\n";

          cerr << "PERM_FREE - Fatal error!\n";

          cerr << "  The partial permutation is illegal.\n";

          cerr << "  Technically, because NFREE < K.\n";

          cerr << "  N     = " << n << "\n";

          cerr << "  NPART = " << npart << "\n";

          cerr << "  NFREE = " << nfree << "\n";

          cerr << "  K =     " << k << "\n";

          cerr << "\n";

          cerr << "  The partial permutation:\n";

          cerr << "\n";

          for ( i = 0; i < npart; i++ )

          {

            cerr << setw(2) << ipart[i] << "  ";

          }

          cerr << "\n";

          exit ( 1 );

        }

        ifree[k-1] = i;

      }

    }

  }

  return;

}

void perm_index_to_cycle ( int n, int p1[], int p2[] )

{

  int i;

  int j;

  int k;

  i = 0;

  j = 1;

  while ( j <= n )

  {

    if ( p1[j-1] < 0 )

    {

      j = j + 1;

    }

    else

    {

      k = j;

      i = i + 1;

      p2[i-1] = - k;

      while ( p1[k-1] != j )

      {

        i = i + 1;

        p2[i-1] = p1[k-1];

        p1[k-1] = - p1[k-1];

        k = abs ( p1[k-1] );

      }

      p1[k-1] = - p1[k-1];

    }

  }

  for ( i = 0; i < n; i++ )

  {

    p1[i] = abs ( p1[i] );

  }

  return;

}

void perm_ins ( int n, int p[], int ins[] )

{

  bool error;

  int i;

  int j;

  error = perm_check ( n, p );

  if ( error )

  {

    cerr << "\n";

    cerr << "PERM_INS - Fatal error!\n";

    cerr << "  The input array does not represent\n";

    cerr << "  a proper permutation.\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    ins[i] = 0;

  }

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < i; j++ )

    {

      if ( p[i] < p[j] )

      {

        ins[i] = ins[i] + 1;

      }

    }

  }

  return;

}

void perm_inverse ( int n, int p[] )

{

  bool error;

  int i;

  int i0;

  int i1;

  int i2;

  int is;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "PERM_INVERSE - Fatal error!\n";

    cerr << "  Input value of N = " << n << "\n";

    exit ( 1 );

  }

  error = perm_check ( n, p );

  if ( error )

  {

    cerr << "\n";

    cerr << "PERM_INVERSE - Fatal error!\n";

    cerr << "  The input array does not represent\n";

    cerr << "  a proper permutation.\n";

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

    is = -i4_sign ( p[i-1] );

    p[i-1] = abs ( p[i-1] ) * i4_sign ( is );

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

void perm_inverse2 ( int n, int p[] )

{

  bool error;

  int i;

  int ii;

  int j;

  int k;

  int m;

  error = perm_check ( n, p );

  if ( error )

  {

    cerr << "\n";

    cerr << "PERM_INVERSE2 - Fatal error!\n";

    cerr << "  The input array does not represent\n";

    cerr << "  a proper permutation.\n";

    exit ( 1 );

  }

  for ( ii = 1; ii <= n; ii++ )

  {

    m = n + 1 - ii;

    i = p[m-1];

    if ( i < 0 )

    {

      p[m-1] = -i;

    }

    else if ( i != m )

    {

      k = m;

      for ( ; ; )

      {

        j = p[i-1];

        p[i-1] = -k;

        if ( j == m )

        {

          p[m-1] = i;

          break;

        }

        k = i;

        i = j;

      }

    }

  }

  return;

}

int *perm_inverse3_new ( int n, int perm[] )

{

  int i;

  int *perm_inv;

  perm_inv = new int[n];

  for ( i = 0; i < n; i++ )

  {

    perm_inv[perm[i]] = i;

  }

  return perm_inv;

}

void perm_lex_next ( int n, int p[], bool &more )

{

  int i;

  int j;

  int k;

  int temp;

  int u;

  int w;

  if ( !more )

  {

    i4vec_indicator ( n, p );

    more = true;

  }

  else

  {

    if ( n <= 1 )

    {

      more = false;

      return;

    }

    w = n;

    while ( p[w-1] < p[w-2] )

    {

      if ( w == 2 )

      {

        more = false;

        return;

      }

      w = w - 1;

    }

    u = p[w-2];

    for ( j = n; w <= j; j-- )

    {

      if ( u < p[j-1] )

      {

        p[w-2] = p[j-1];

        p[j-1] = u;

        for ( k = 0; k <= ( n - w - 1 ) / 2; k++ )

        {

          temp = p[n-k-1];

          p[n-k-1] = p[w+k-1];

          p[w+k-1] = temp;

        }

        return;

      }

    }

  }

  return;

}

void perm_mul ( int n, int p1[], int p2[], int p3[] )

{

  bool error;

  int i;

  error = perm_check ( n, p1 );

  if ( error )

  {

    cerr << "\n";

    cerr << "PERM_MUL - Fatal error!\n";

    cerr << "  The input array P1 does not represent\n";

    cerr << "  a proper permutation.\n";

    exit ( 1 );

  }

  error = perm_check ( n, p2 );

  if ( error )

  {

    cerr << "\n";

    cerr << "PERM_MUL - Fatal error!\n";

    cerr << "  The input array P2 does not represent\n";

    cerr << "  a proper permutation.\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    p3[i] = p2[p1[i]-1];

  }

  return;

}

void perm_next ( int n, int p[], bool &more, bool &even )

{

  int i;

  int i1;

  int ia;

  int id;

  int is;

  int j;

  int l;

  int m;

  if ( !more )

  {

    i4vec_indicator ( n, p );

    more = true;

    even = true;

    if ( n == 1 )

    {

      more = false;

      return;

    }

    if ( p[n-1] != 1 || p[0] != 2 + ( n % 2 ) )

    {

      return;

    }

    for ( i = 1; i <= n-3; i++ )

    {

      if ( p[i] != p[i-1] + 1 )

      {

        return;

      }

    }

    more = false;

  }

  else

  {

    if ( n == 1 )

    {

      p[0] = 0;

      more = false;

      return;

    }

    if ( even )

    {

      ia = p[0];

      p[0] = p[1];

      p[1] = ia;

      even = false;

      if ( p[n-1] != 1 || p[0] != 2 + ( n % 2 ) )

      {

        return;

      }

      for ( i = 1; i <= n-3; i++ )

      {

        if ( p[i] != p[i-1] + 1 )

        {

          return;

        }

      }

      more = false;

      return;

    }

    else

    {

      more = false;

      is = 0;

      for ( i1 = 2; i1 <= n; i1++ )

      {

        ia = p[i1-1];

        i = i1 - 1;

        id = 0;

        for ( j = 1; j <= i; j++ )

        {

          if ( ia < p[j-1] )

          {

            id = id + 1;

          }

        }

        is = id + is;

        if ( id != i * ( is % 2 ) )

        {

          more = true;

          break;

        }

      }

      if ( !more )

      {

        p[0] = 0;

        return;

      }

    }

    m = ( ( is + 1 ) % 2 ) * ( n + 1 );

    for ( j = 1; j <= i; j++ )

    {

      if ( i4_sign ( p[j-1] - ia ) != i4_sign ( p[j-1] - m ) )

      {

        m = p[j-1];

        l = j;

      }

    }

    p[l-1] = ia;

    p[i1-1] = m;

    even = true;

  }

  return;

}

void perm_next2 ( int n, int p[], bool &done )

{

  static int *active = NULL;

  int i;

  static int *idir = NULL;

  static int *invers = NULL;

  int j;

  int nactiv;

  if ( done )

  {

    i4vec_indicator ( n, p );

    if ( active )

    {

      delete [] active;

    }

    active = new int[n];

    if ( idir )

    {

      delete [] idir;

    }

    idir = new int[n];

    if ( invers )

    {

      delete [] invers;

    }

    invers = new int[n];

    for ( i = 0; i < n; i++ )

    {

      invers[i] = p[i];

    }

    for ( i = 0; i < n; i++ )

    {

      idir[i] = -1;

    }

    active[0] = 0;

    for ( i = 1; i < n; i++ )

    {

      active[i] = 1;

    }

    if ( 1 < n )

    {

      done = false;

    }

    else

    {

      done = true;

    }

  }

  else

  {

    nactiv = 0;

    for ( i = 1; i <= n; i++ )

    {

      if ( active[i-1] != 0 )

      {

        nactiv = i;

      }

    }

    if ( nactiv <= 0 )

    {

      done = true;

    }

    else

    {

      j = invers[nactiv-1];

      p[j-1] = p[j+idir[nactiv-1]-1];

      p[j+idir[nactiv-1]-1] = nactiv;

      invers[nactiv-1] = invers[nactiv-1] + idir[nactiv-1];

      invers[p[j-1]-1] = j;

      if ( j + 2 * idir[nactiv-1] < 1 || n < j + 2 * idir[nactiv-1] )

      {

        idir[nactiv-1] = - idir[nactiv-1];

        active[nactiv-1] = 0;

      }

      else if ( nactiv < p[j+2*idir[nactiv-1]-1] )

      {

        idir[nactiv-1] = - idir[nactiv-1];

        active[nactiv-1] = 0;

      }

      for ( i = nactiv; i < n; i++ )

      {

        active[i] = 1;

      }

    }

  }

  if ( done )

  {

    delete [] active;

    active = NULL;

    delete [] idir;

    idir = NULL;

    delete [] invers;

    invers = NULL;

  }

  return;

}

void perm_next3 ( int n, int p[], bool &more )

{

  int i;

  int m2;

  int n2;

  static int nfact = 0;

  int q;

  static int rank = 0;

  int s;

  int t;

  int temp;

  if ( !more )

  {

    for ( i = 0; i < n; i++ )

    {

      p[i] = i + 1;

    }

    more = true;

    rank = 1;

    nfact = 1;

    for ( i = 1; i <= n; i++ )

    {

      nfact = nfact * i;

    }

  }

  else

  {

    n2 = n;

    m2 = rank;

    s = n;

    for ( ; ; )

    {

      q = m2 % n2;

      t = m2 % ( 2 * n2 );

      if ( q != 0 )

      {

        break;

      }

      if ( t == 0 )

      {

        s = s - 1;

      }

      m2 = m2 / n2;

      n2 = n2 - 1;

    }

    if ( q == t )

    {

      s = s - q;

    }

    else

    {

      s = s + q - n2;

    }

    temp = p[s-1];

    p[s-1] = p[s];

    p[s] = temp;

    rank = rank + 1;

    if ( rank == nfact )

    {

      more = false;

    }

  }

  return;

}

void perm_print ( int n, int p[], string title )

{

  int i;

  int ihi;

  int ilo;

  int inc = 20;

  if ( s_len_trim ( title ) != 0 )

  {

    cout << "\n";

    cout << title << "\n";

    for ( ilo = 0; ilo < n; ilo = ilo + inc )

    {

      ihi = ilo + inc;

      if ( n < ihi ) 

      {

        ihi = n;

      }

      cout << "\n";

      cout << "  ";

      for ( i = ilo; i < ihi; i++ )

      {

        cout << setw(4) << i;

      }

      cout << "\n";

      cout << "  ";

      for ( i = ilo; i < ihi; i++ )

      {

        cout << setw(4) << p[i];

      }

      cout << "\n";

    }

  }

  else

  {

    for ( ilo = 0; ilo < n; ilo = ilo + inc )

    {

      ihi = ilo + inc;

      if ( n < ihi ) 

      {

        ihi = n;

      }

      cout << "  ";

      for ( i = ilo; i < ihi; i++ )

      {

        cout << setw(4) << p[i];

      }

      cout << "\n";

    }

  }

  return;

}

void perm_random ( int n, int &seed, int p[] )

{

  int i;

  int j;

  int k;

 

  for ( i = 0; i < n; i++ )

  {

    p[i] = i + 1;

  }

  for ( i = 1; i < n; i++ )

  {

    j = i4_uniform_ab ( i, n, seed );

    k = p[i-1];

    p[i-1] = p[j-1];

    p[j-1] = k;

  }

 

  return;

}

void perm_random2 ( int n, int &seed, int p[] )

{

  int i;

  int j;

  int k;

  for ( i = 1; i < n; i++ )

  {

    j = i4_uniform_ab ( i, n, seed );

    k = p[i-1];

    p[i-1] = p[j-1];

    p[j-1] = k;

  }

 

  return;

}

void perm_random3 ( int n, int &seed, int p[] )

{

  int i;

  int j;

  int temp;

  if ( n < 1 )

  {

    cerr << "\n";

    cerr << "PERM_RANDOM3 - Fatal error!\n";

    cerr << "  Illegal input value of N  = " << n << "\n";

    cerr << "  N must be at least 1!\n";

    exit ( 1 );

  }

  if ( n == 1 )

  {

    p[0] = 1;

    return;

  }

  i4vec_indicator ( n, p );

  for ( i = 1; i <= n; i++ )

  {

    j = i + i4_uniform_ab ( 1, n, seed );

    if ( n < j )

    {

      j = j - n;

    }

    if ( i != j )

    {

      temp = p[j-1];

      p[j-1] = p[i-1];

      p[i-1] = temp;

    }

  }

  return;

}

int perm_rank ( int n, int p[], int invers[] )

{

  int count;

  bool error;

  int i;

  int j;

  int rank;

  int rem;

  error = perm_check ( n, p );

  if ( error )

  {

    cerr << "\n";

    cerr << "PERM_RANK - Fatal error!\n";

    cerr << "  The input array does not represent\n";

    cerr << "  a proper permutation.\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    invers[i] = p[i];

  }

  perm_inverse2 ( n, invers );

  rank = 0;

  for ( i = 1; i <= n; i++)

  {

    count = 0;

    for ( j = 0; j < invers[i-1]; j++ )

    {

      if ( p[j] < i )

      {

        count = count + 1;

      }

    }

    if ( ( rank % 2 ) == 1 )

    {

      rem = count;

    }

    else

    {

      rem = i - 1 - count;

    }

    rank = i * rank + rem;

  }

  rank = rank + 1;

  return rank;

}

int perm_sign ( int n, int p[] )

{

  bool error;

  int i;

  int j;

  int p_sign;

  int *q;

  int temp;

  error = perm_check ( n, p );

  if ( error )

  {

    cerr << "\n";

    cerr << "PERM_SIGN - Fatal error!\n";

    cerr << "  The input array does not represent\n";

    cerr << "  a proper permutation.\n";

    exit ( 1 );

  }

  q = new int[n];

  for ( i = 0; i < n; i++ )

  {

    q[i] = p[i];

  }

  p_sign = 1;

  for ( i = 1; i <= n - 1; i++ )

  {

    j = i4vec_index ( n, q, i );

    if ( j != i - 1 )

    {

      temp = q[i-1];

      q[i-1] = q[j];

      q[j] = temp;

      p_sign = - p_sign;

    }

  }

  

  delete [] q;

  

  return p_sign;

}

void perm_to_equiv ( int n, int p[], int &npart, int jarray[], int iarray[] )

{

  bool error;

  int i;

  int j;

  int k;

  error = perm_check ( n, p );

  if ( error )

  {

    cerr << "\n";

    cerr << "PERM_TO_EQUIV - Fatal error!\n";

    cerr << "  The input array does not represent\n";

    cerr << "  a proper permutation.\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    iarray[i] = 0;

  }

  

  for ( i = 0; i < n; i++ )

  {

    jarray[i] = 0;

  }

  npart = 0;

  for ( j = 1; j <= n; j++ )

  {

    if ( iarray[j-1] != 0 )

    {

      continue;

    }

    npart = npart + 1;

    k = j;

    for ( ; ; )

    {

      jarray[npart-1] = jarray[npart-1] + 1;

      iarray[k-1] = npart;

      k = p[k-1];

      if ( iarray[k-1] != 0 )

      {

        break;

      }

    }

  }

  return;

}

void perm_to_ytb ( int n, int p[], int lambda[], int a[] )

{

  bool another;

  int compare;

  int i;

  int put_index;

  int put_row;

  int put_value;

  for ( i = 0; i < n; i++ )

  {

    lambda[i] = 0;

  }

  for ( i = 0; i < n; i++ )

  {

    a[i] = 0;

  }

  for ( put_index = 1; put_index <= n; put_index++ )

  {

    put_value = p[put_index-1];

    put_row = 1;

    for ( ; ; )

    {

      another = false;

      for ( compare = put_value+1; compare <= n; compare++ )

      {

        if ( a[compare-1] == put_row )

        {

          another = true;

          a[put_value-1] = put_row;

          a[compare-1] = 0;

          put_value = compare;

          put_row = put_row + 1;

          break;

        }

      }

      if ( !another )

      {

        break;

      }

    }

    a[put_value-1] = put_row;

    lambda[put_row-1] = lambda[put_row-1] + 1;

  }

  return;

}

void perm_unrank ( int n, int rank, int p[] )

{

  int i;

  int icount;

  int iprev;

  int irem;

  int j;

  int jdir;

  int jrank;

  for ( i = 0; i < n; i++ )

  {

    p[i] = 0;

  }

  if ( rank < 1 || i4_factorial ( n ) < rank )

  {

    cerr << "\n";

    cerr << "PERM_UNRANK - Fatal error!\n";

    cerr << "  Illegal input value for RANK.\n";

    cerr << "  RANK must be between 1 and N!,\n";

    cerr << "  but the input value is " << rank << "\n";

    exit ( 1 );

  }

  jrank = rank - 1;

  for ( i = 1; i <= n; i++ )

  {

    iprev = n + 1 - i;

    irem = jrank % iprev;

    jrank = jrank / iprev;

    if ( ( jrank % 2 ) == 1 )

    {

      j = 0;

      jdir = 1;

    }

    else

    {

      j = n + 1;

      jdir = -1;

    }

    icount = 0;

    for ( ; ; )

    {

      j = j + jdir;

      if ( p[j-1] == 0 )

      {

        icount = icount + 1;

      }

      if ( irem < icount )

      {

        break;

      }

    }

    p[j-1] = iprev;

  }

  return;

}

void perrin ( int n, int p[] )

{

  int i;

  if ( n < 1 )

  {

    return;

  }

  p[0] = 3;

  if ( n < 2 )

  {

    return;

  }

  p[1] = 0;

  if ( n < 3 )

  {

    return;

  }

 

  p[2] = 2;

  for ( i = 4; i <= n; i++ )

  {

    p[i-1] = p[i-3] + p[i-4];

  }

  return;

}

bool pord_check ( int n, int a[] )

{

  int i;

  int j;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "PORD_CHECK - Fatal error!\n";

    cerr << "  N must be positive, but N = " << n << "\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    for ( j = i + 1; j < n; j++ )

    {

      if ( 0 < a[i+j*n] )

      {

        if ( 0 < a[j+i*n] )

        {

          cerr << "\n";

          cerr << "PORD_CHECK - Fatal error!\n";

          cerr << "  For indices I = " << i << "\n";

          cerr << "  and J = " << j << "\n";

          cerr << "  A(I,J) = " << a[i+j*n] << "\n";

          cerr << "  A(J,I) = " << a[j+i*n] << "\n";

          exit ( 1 );

        }

      }

    }

  }

  return false;

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

void power_series1 ( int n, double alpha, double a[], double b[] )

{

  int i;

  int j;

  double v;

  for ( j = 1; j <= n; j++ )

  {

    v = 0.0;

    for ( i = 1; i <= j-1; i++ )

    {

      v = v + b[i-1] * a[j-i-1] * ( alpha * ( j - i ) - i );

    }

    b[j-1] = alpha * a[j-1] + v / ( ( double ) j );

  }

  return;

}

void power_series2 ( int n, double a[], double b[] )

{

  int i;

  int j;

  double v;

  for ( j = 1; j <= n; j++ )

  {

    v = 0.0;

    for ( i = 1; i <= j-1; i++ )

    {

      v = v + b[i-1] * a[j-i-1] * ( double ) ( j - i );

    }

    b[j-1] = a[j-1] + v / ( double ) j;

  }

  return;

}

void power_series3 ( int n, double a[], double b[], double c[] )

{

  int i;

  int iq;

  int j;

  int m;

  double r;

  double v;

  double *work;

  work = new double[n];

  for ( i = 0; i < n; i++ )

  {

    work[i] = b[0] * a[i];

  }

  iq = 0;

  for ( i = 1; i <= n; i++ )

  {

    if ( a[i-1] != 0.0 )

    {

      iq = i;

      break;

    }

  }

  if ( iq != 0 )

  {

    m = 1;

    for ( ; ; )

    {

      m = m + 1;

      if ( n < m * iq )

      {

        break;

      }

      if ( b[m-1] == 0.0 )

      {

        continue;

      }

      r = b[m-1] * pow ( a[iq-1], m );

      work[m*iq-1] = work[m*iq-1] + r;

      for ( j = 1; j <= n-m*iq; j++ )

      {

        v = 0.0;

        for ( i = 1; i <= j-1; i++ )

        {

          v = v + c[i-1] * a[j-i+iq-1] * ( double ) ( m * ( j - i ) - i );

        }

        c[j-1] = ( ( double ) m * a[j-1] + v / ( double ) j ) / a[iq-1];

      }

      for ( i = 1; i <= n-m*iq; i++ )

      {

        work[i+m*iq-1] = work[i+m*iq-1] + c[i-1] * r;

      }

    }

  }

  for ( i = 0; i < n; i++ )

  {

    c[i] = work[i];

  }

  delete [] work;

  return;

}

void power_series4 ( int n, double a[], double b[], double c[] )

{

  int i;

  int l;

  int m;

  double s;

  double t;

  double *work;

  if ( a[0] == 0.0 )

  {

    cerr << "\n";

    cerr << "POWER_SERIES4 - Fatal error!\n";

    cerr << "  First entry of A is zero.\n";

    exit ( 1 );

  }

  work = new double[n];

  t = 1.0;

  for ( i = 0; i < n; i++ )

  {

    t = t / a[0];

    c[i] = b[i] * t;

    work[i] = a[i] * t;

  }

  for ( m = 2; m <= n; m++ )

  {

    s = -work[m-1];

    for ( i = m; i <= n; i++ )

    {

      for ( l = i; l <= n; l++ )

      {

        c[l-1] = c[l-1] + s * c[l-m];

        work[l-1] = work[l-1] + s * work[l-m];

      }

    }

  }

  delete [] work;

  return;

}

int prime ( int n )

{

# define PRIME_MAX 1600

  int npvec[PRIME_MAX] = {

        2,    3,    5,    7,   11,   13,   17,   19,   23,   29,

       31,   37,   41,   43,   47,   53,   59,   61,   67,   71,

       73,   79,   83,   89,   97,  101,  103,  107,  109,  113,

      127,  131,  137,  139,  149,  151,  157,  163,  167,  173,

      179,  181,  191,  193,  197,  199,  211,  223,  227,  229,

      233,  239,  241,  251,  257,  263,  269,  271,  277,  281,

      283,  293,  307,  311,  313,  317,  331,  337,  347,  349,

      353,  359,  367,  373,  379,  383,  389,  397,  401,  409,

      419,  421,  431,  433,  439,  443,  449,  457,  461,  463,

      467,  479,  487,  491,  499,  503,  509,  521,  523,  541,

      547,  557,  563,  569,  571,  577,  587,  593,  599,  601,

      607,  613,  617,  619,  631,  641,  643,  647,  653,  659,

      661,  673,  677,  683,  691,  701,  709,  719,  727,  733,

      739,  743,  751,  757,  761,  769,  773,  787,  797,  809,

      811,  821,  823,  827,  829,  839,  853,  857,  859,  863,

      877,  881,  883,  887,  907,  911,  919,  929,  937,  941,

      947,  953,  967,  971,  977,  983,  991,  997, 1009, 1013,

     1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069,

     1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151,

     1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223,

     1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 

     1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 

     1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 

     1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 

     1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 

     1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 

     1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 

     1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 

     1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889,

     1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987,

     1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053,

     2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129,

     2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213,

     2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287,

     2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 

     2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 

     2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 

     2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 

     2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 

     2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741,

     2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 

     2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 

     2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 

     3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 

     3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 

     3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 

     3259, 3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 

     3343, 3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 

     3433, 3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 

     3517, 3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571,

     3581, 3583, 3593, 3607, 3613, 3617, 3623, 3631, 3637, 3643,

     3659, 3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727,

     3733, 3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821,

     3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 3907,

     3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989,

     4001, 4003, 4007, 4013, 4019, 4021, 4027, 4049, 4051, 4057,

     4073, 4079, 4091, 4093, 4099, 4111, 4127, 4129, 4133, 4139,

     4153, 4157, 4159, 4177, 4201, 4211, 4217, 4219, 4229, 4231,

     4241, 4243, 4253, 4259, 4261, 4271, 4273, 4283, 4289, 4297,

     4327, 4337, 4339, 4349, 4357, 4363, 4373, 4391, 4397, 4409,

     4421, 4423, 4441, 4447, 4451, 4457, 4463, 4481, 4483, 4493, 

     4507, 4513, 4517, 4519, 4523, 4547, 4549, 4561, 4567, 4583, 

     4591, 4597, 4603, 4621, 4637, 4639, 4643, 4649, 4651, 4657, 

     4663, 4673, 4679, 4691, 4703, 4721, 4723, 4729, 4733, 4751, 

     4759, 4783, 4787, 4789, 4793, 4799, 4801, 4813, 4817, 4831, 

     4861, 4871, 4877, 4889, 4903, 4909, 4919, 4931, 4933, 4937, 

     4943, 4951, 4957, 4967, 4969, 4973, 4987, 4993, 4999, 5003, 

     5009, 5011, 5021, 5023, 5039, 5051, 5059, 5077, 5081, 5087, 

     5099, 5101, 5107, 5113, 5119, 5147, 5153, 5167, 5171, 5179, 

     5189, 5197, 5209, 5227, 5231, 5233, 5237, 5261, 5273, 5279,

     5281, 5297, 5303, 5309, 5323, 5333, 5347, 5351, 5381, 5387,

     5393, 5399, 5407, 5413, 5417, 5419, 5431, 5437, 5441, 5443,

     5449, 5471, 5477, 5479, 5483, 5501, 5503, 5507, 5519, 5521,

     5527, 5531, 5557, 5563, 5569, 5573, 5581, 5591, 5623, 5639,

     5641, 5647, 5651, 5653, 5657, 5659, 5669, 5683, 5689, 5693,

     5701, 5711, 5717, 5737, 5741, 5743, 5749, 5779, 5783, 5791,

     5801, 5807, 5813, 5821, 5827, 5839, 5843, 5849, 5851, 5857,

     5861, 5867, 5869, 5879, 5881, 5897, 5903, 5923, 5927, 5939,

     5953, 5981, 5987, 6007, 6011, 6029, 6037, 6043, 6047, 6053,

     6067, 6073, 6079, 6089, 6091, 6101, 6113, 6121, 6131, 6133,

     6143, 6151, 6163, 6173, 6197, 6199, 6203, 6211, 6217, 6221,

     6229, 6247, 6257, 6263, 6269, 6271, 6277, 6287, 6299, 6301,

     6311, 6317, 6323, 6329, 6337, 6343, 6353, 6359, 6361, 6367, 

     6373, 6379, 6389, 6397, 6421, 6427, 6449, 6451, 6469, 6473, 

     6481, 6491, 6521, 6529, 6547, 6551, 6553, 6563, 6569, 6571, 

     6577, 6581, 6599, 6607, 6619, 6637, 6653, 6659, 6661, 6673, 

     6679, 6689, 6691, 6701, 6703, 6709, 6719, 6733, 6737, 6761, 

     6763, 6779, 6781, 6791, 6793, 6803, 6823, 6827, 6829, 6833, 

     6841, 6857, 6863, 6869, 6871, 6883, 6899, 6907, 6911, 6917, 

     6947, 6949, 6959, 6961, 6967, 6971, 6977, 6983, 6991, 6997,

     7001, 7013, 7019, 7027, 7039, 7043, 7057, 7069, 7079, 7103, 

     7109, 7121, 7127, 7129, 7151, 7159, 7177, 7187, 7193, 7207, 

     7211, 7213, 7219, 7229, 7237, 7243, 7247, 7253, 7283, 7297, 

     7307, 7309, 7321, 7331, 7333, 7349, 7351, 7369, 7393, 7411, 

     7417, 7433, 7451, 7457, 7459, 7477, 7481, 7487, 7489, 7499, 

     7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 

     7573, 7577, 7583, 7589, 7591, 7603, 7607, 7621, 7639, 7643, 

     7649, 7669, 7673, 7681, 7687, 7691, 7699, 7703, 7717, 7723, 

     7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823, 7829, 

     7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919,

     7927, 7933, 7937, 7949, 7951, 7963, 7993, 8009, 8011, 8017,

     8039, 8053, 8059, 8069, 8081, 8087, 8089, 8093, 8101, 8111,

     8117, 8123, 8147, 8161, 8167, 8171, 8179, 8191, 8209, 8219,

     8221, 8231, 8233, 8237, 8243, 8263, 8269, 8273, 8287, 8291,

     8293, 8297, 8311, 8317, 8329, 8353, 8363, 8369, 8377, 8387,

     8389, 8419, 8423, 8429, 8431, 8443, 8447, 8461, 8467, 8501,

     8513, 8521, 8527, 8537, 8539, 8543, 8563, 8573, 8581, 8597,

     8599, 8609, 8623, 8627, 8629, 8641, 8647, 8663, 8669, 8677,

     8681, 8689, 8693, 8699, 8707, 8713, 8719, 8731, 8737, 8741, 

     8747, 8753, 8761, 8779, 8783, 8803, 8807, 8819, 8821, 8831,

     8837, 8839, 8849, 8861, 8863, 8867, 8887, 8893, 8923, 8929,

     8933, 8941, 8951, 8963, 8969, 8971, 8999, 9001, 9007, 9011,

     9013, 9029, 9041, 9043, 9049, 9059, 9067, 9091, 9103, 9109,

     9127, 9133, 9137, 9151, 9157, 9161, 9173, 9181, 9187, 9199,

     9203, 9209, 9221, 9227, 9239, 9241, 9257, 9277, 9281, 9283,

     9293, 9311, 9319, 9323, 9337, 9341, 9343, 9349, 9371, 9377,

     9391, 9397, 9403, 9413, 9419, 9421, 9431, 9433, 9437, 9439,

     9461, 9463, 9467, 9473, 9479, 9491, 9497, 9511, 9521, 9533,

     9539, 9547, 9551, 9587, 9601, 9613, 9619, 9623, 9629, 9631,

     9643, 9649, 9661, 9677, 9679, 9689, 9697, 9719, 9721, 9733,

     9739, 9743, 9749, 9767, 9769, 9781, 9787, 9791, 9803, 9811,

     9817, 9829, 9833, 9839, 9851, 9857, 9859, 9871, 9883, 9887,

     9901, 9907, 9923, 9929, 9931, 9941, 9949, 9967, 9973,10007,

    10009,10037,10039,10061,10067,10069,10079,10091,10093,10099,

    10103,10111,10133,10139,10141,10151,10159,10163,10169,10177,

    10181,10193,10211,10223,10243,10247,10253,10259,10267,10271,

    10273,10289,10301,10303,10313,10321,10331,10333,10337,10343,

    10357,10369,10391,10399,10427,10429,10433,10453,10457,10459,

    10463,10477,10487,10499,10501,10513,10529,10531,10559,10567,

    10589,10597,10601,10607,10613,10627,10631,10639,10651,10657,

    10663,10667,10687,10691,10709,10711,10723,10729,10733,10739,

    10753,10771,10781,10789,10799,10831,10837,10847,10853,10859,

    10861,10867,10883,10889,10891,10903,10909,10937,10939,10949,

    10957,10973,10979,10987,10993,11003,11027,11047,11057,11059,

    11069,11071,11083,11087,11093,11113,11117,11119,11131,11149,

    11159,11161,11171,11173,11177,11197,11213,11239,11243,11251,

    11257,11261,11273,11279,11287,11299,11311,11317,11321,11329,

    11351,11353,11369,11383,11393,11399,11411,11423,11437,11443,

    11447,11467,11471,11483,11489,11491,11497,11503,11519,11527,

    11549,11551,11579,11587,11593,11597,11617,11621,11633,11657,

    11677,11681,11689,11699,11701,11717,11719,11731,11743,11777,

    11779,11783,11789,11801,11807,11813,11821,11827,11831,11833,

    11839,11863,11867,11887,11897,11903,11909,11923,11927,11933,

    11939,11941,11953,11959,11969,11971,11981,11987,12007,12011,

    12037,12041,12043,12049,12071,12073,12097,12101,12107,12109,

    12113,12119,12143,12149,12157,12161,12163,12197,12203,12211,

    12227,12239,12241,12251,12253,12263,12269,12277,12281,12289,

    12301,12323,12329,12343,12347,12373,12377,12379,12391,12401,

    12409,12413,12421,12433,12437,12451,12457,12473,12479,12487,

    12491,12497,12503,12511,12517,12527,12539,12541,12547,12553,

    12569,12577,12583,12589,12601,12611,12613,12619,12637,12641, 

    12647,12653,12659,12671,12689,12697,12703,12713,12721,12739, 

    12743,12757,12763,12781,12791,12799,12809,12821,12823,12829, 

    12841,12853,12889,12893,12899,12907,12911,12917,12919,12923, 

    12941,12953,12959,12967,12973,12979,12983,13001,13003,13007, 

    13009,13033,13037,13043,13049,13063,13093,13099,13103,13109, 

    13121,13127,13147,13151,13159,13163,13171,13177,13183,13187, 

    13217,13219,13229,13241,13249,13259,13267,13291,13297,13309, 

    13313,13327,13331,13337,13339,13367,13381,13397,13399,13411, 

    13417,13421,13441,13451,13457,13463,13469,13477,13487,13499 };

  if ( n == -1 )

  {

    return PRIME_MAX;

  }

  else if ( n == 0 )

  {

    return 1;

  }

  else if ( n <= PRIME_MAX )

  {

    return npvec[n-1];

  }

  else

  {

    cerr << "\n";

    cerr << "PRIME - Fatal error!\n";

    cerr << "  Unexpected input value of n = " << n << "\n";

    exit ( 1 );

  }

  return 0;

# undef PRIME_MAX

}

void pythag_triple_next ( int &i, int &j, int &a, int &b, int &c )

{

  

  if ( i == 0 && j == 0 )

  {

    i = 2;

    j = 1;

  }

  else if ( j + 2 < i )

  {

    j = j + 2;

  }

  else

  {

    i = i + 1;

    j = ( i % 2 ) + 1;

  }

  a = i * i - j * j;

  b = 2 * i * j;

  c = i * i + j * j;

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

double r8_agm ( double a, double b )

{

  double a1;

  double a2;

  double b1;

  double b2;

  double tol;

  if ( a < 0.0 )

  {

    return -1.0;

  }

  if ( b < 0.0 )

  {

    return -1.0;

  }

  if ( a == 0.0 || b == 0.0 )

  {

    return 0.0;

  }

  if ( a == b )

  {

    return a;

  }

  tol = r8_epsilon ( ) * ( a + b + 1.0 );

  a1 = a;

  b1 = b;

  for ( ; ; )

  {

    a2 = ( a1 + b1 ) / 2.0;

    b2 = sqrt ( a1 * b1 );

    if ( fabs ( a2 - b2 ) <= tol )

    {

      return ( ( a2 + b2 ) / 2.0 );

    }

    a1 = a2;

    b1 = b2;

  }

}

double r8_choose ( int n, int k )

{

  double arg;

  double fack;

  double facn;

  double facnmk;

  double value;

  if ( n < 0 )

  {

    value = 0.0;

  }

  else if ( k == 0 )

  {

    value = 1.0;

  }

  else if ( k == 1 )

  {

    value = ( double ) n;

  }

  else if ( 1 < k && k < n-1 )

  {

    arg = ( double ) ( n + 1 );

    facn = r8_gamma_log ( arg );

    arg = ( double ) ( k + 1 );

    fack = r8_gamma_log ( arg );

    arg = ( double ) ( n - k + 1 );

    facnmk = r8_gamma_log ( arg );

    value = ( int ) ( 0.5 + exp ( facn - fack - facnmk ) );

  }

  else if ( k == n-1 )

  {

    value = ( double ) n;

  }

  else if ( k == n )

  {

    value = 1.0;

  }

  else

  {

    value = 0.0;

  }

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

double r8_factorial ( int n )

{

  int i;

  double value;

  value = 1.0;

  for ( i = 1; i <= n; i++ )

  {

    value = value * ( double ) ( i );

  }

  return value;

}

double r8_fall ( double x, int n )

{

  int i;

  double value;

  value = 1.0;

  if ( 0 < n )

  {

    for ( i = 1; i <= n; i++ )

    {

      value = value * x;

      x = x - 1.0;

    }

  }

  else if ( n < 0 )

  {

    for ( i = -1; n <= i; i-- )

    {

      value = value * x;

      x = x + 1.0;

    }

  }

  return value;

}

double r8_gamma_log ( double x )

{

  double c[7] = {

    -1.910444077728E-03, 

     8.4171387781295E-04, 

    -5.952379913043012E-04, 

     7.93650793500350248E-04, 

    -2.777777777777681622553E-03, 

     8.333333333333333331554247E-02, 

     5.7083835261E-03 };

  double corr;

  double d1 = - 5.772156649015328605195174E-01;

  double d2 =   4.227843350984671393993777E-01;

  double d4 =   1.791759469228055000094023E+00;

  double frtbig = 1.42E+09;

  int i;

  double p1[8] = {

    4.945235359296727046734888E+00, 

    2.018112620856775083915565E+02, 

    2.290838373831346393026739E+03, 

    1.131967205903380828685045E+04, 

    2.855724635671635335736389E+04, 

    3.848496228443793359990269E+04, 

    2.637748787624195437963534E+04, 

    7.225813979700288197698961E+03 };

  double p2[8] = {

    4.974607845568932035012064E+00, 

    5.424138599891070494101986E+02, 

    1.550693864978364947665077E+04, 

    1.847932904445632425417223E+05, 

    1.088204769468828767498470E+06, 

    3.338152967987029735917223E+06, 

    5.106661678927352456275255E+06, 

    3.074109054850539556250927E+06 };

  double p4[8] = {

    1.474502166059939948905062E+04, 

    2.426813369486704502836312E+06, 

    1.214755574045093227939592E+08, 

    2.663432449630976949898078E+09, 

    2.940378956634553899906876E+010,

    1.702665737765398868392998E+011,

    4.926125793377430887588120E+011, 

    5.606251856223951465078242E+011 };

  double pnt68 = 0.6796875E+00;

  double q1[8] = {

    6.748212550303777196073036E+01, 

    1.113332393857199323513008E+03, 

    7.738757056935398733233834E+03, 

    2.763987074403340708898585E+04, 

    5.499310206226157329794414E+04, 

    6.161122180066002127833352E+04, 

    3.635127591501940507276287E+04, 

    8.785536302431013170870835E+03 };

  double q2[8] = {

    1.830328399370592604055942E+02, 

    7.765049321445005871323047E+03, 

    1.331903827966074194402448E+05, 

    1.136705821321969608938755E+06, 

    5.267964117437946917577538E+06, 

    1.346701454311101692290052E+07, 

    1.782736530353274213975932E+07, 

    9.533095591844353613395747E+06 };

  double q4[8] = {

    2.690530175870899333379843E+03, 

    6.393885654300092398984238E+05, 

    4.135599930241388052042842E+07, 

    1.120872109616147941376570E+09, 

    1.488613728678813811542398E+010, 

    1.016803586272438228077304E+011, 

    3.417476345507377132798597E+011, 

    4.463158187419713286462081E+011 };

  double res;

  double sqrtpi = 0.9189385332046727417803297E+00;

  double xbig = 4.08E+36;

  double xden;

  double xm1;

  double xm2;

  double xm4;

  double xnum;

  double xsq;

  if ( x <= 0.0 || xbig < x )

  {

    return r8_huge ( );

  }

  if ( x <= r8_epsilon ( ) )

  {

    res = -log ( x );

  }

  else if ( x <= 1.5 )

  {

    if ( x < pnt68 )

    {

      corr = - log ( x );

      xm1 = x;

    }

    else

    {

      corr = 0.0;

      xm1 = ( x - 0.5 ) - 0.5;

    }

    if ( x <= 0.5 || pnt68 <= x )

    {

      xden = 1.0;

      xnum = 0.0;

      for ( i = 0; i < 8; i++ )

      {

        xnum = xnum * xm1 + p1[i];

        xden = xden * xm1 + q1[i];

      }

      res = corr + ( xm1 * ( d1 + xm1 * ( xnum / xden ) ) );

    }

    else

    {

      xm2 = ( x - 0.5 ) - 0.5;

      xden = 1.0;

      xnum = 0.0;

      for ( i = 0; i < 8; i++ )

      {

        xnum = xnum * xm2 + p2[i];

        xden = xden * xm2 + q2[i];

      }

      res = corr + xm2 * ( d2 + xm2 * ( xnum / xden ) );

    }

  }

  else if ( x <= 4.0 )

  {

    xm2 = x - 2.0;

    xden = 1.0;

    xnum = 0.0;

    for ( i = 0; i < 8; i++ )

    {

      xnum = xnum * xm2 + p2[i];

      xden = xden * xm2 + q2[i];

    }

    res = xm2 * ( d2 + xm2 * ( xnum / xden ) );

  }

  else if ( x <= 12.0 )

  {

    xm4 = x - 4.0;

    xden = - 1.0;

    xnum = 0.0;

    for ( i = 0; i < 8; i++ )

    {

      xnum = xnum * xm4 + p4[i];

      xden = xden * xm4 + q4[i];

    }

    res = d4 + xm4 * ( xnum / xden );

  }

  else

  {

    res = 0.0;

    if ( x <= frtbig )

    {

      res = c[6];

      xsq = x * x;

      for ( i = 0; i < 6; i++ )

      {

        res = res / xsq + c[i];

      }

    }

    res = res / x;

    corr = log ( x );

    res = res + sqrtpi - 0.5 * corr;

    res = res + x * ( corr - 1.0 );

  }

  return res;

}

double r8_huge ( )

{

  return HUGE_VAL;

}

int r8_nint ( double x )

{

  double d;

  int i;

  i = int ( x );

  d = x - i;

  if ( fabs ( d ) <= 0.5 )

  {

    return i;

  }

  else if ( x < i ) 

  {

    return (i-1);

  }

  else

  {

    return (i+1);

  }

}

double r8_pi ( )

{

  return ( double ) 3.14159265358979323846264338327950288419716939937510;

}

double r8_rise ( double x, int n )

{

  int i;

  double value;

  value = 1.0;

  if ( 0 < n )

  {

    for ( i = 1; i <= n; i++ )

    {

      value = value * x;

      x = x + 1.0;

    }

  }

  else if ( n < 0 )

  {

    for ( i = -1; n <= i; i-- )

    {

      value = value * x;

      x = x - 1.0;

    }

  }

  return value;

}

void r8_swap ( double &x, double &y )

{

  double z;

  z = x;

  x = y;

  y = z;

 

  return;

}

void r8_to_cfrac ( double r, int n, int a[], int p[], int q[] )

{

  int i;

  double r_copy;

  double *x;

  if ( r == 0.0 )

  {

    for ( i = 0; i <= n; i++ )

    {

      a[i] = 0;

    }

    for ( i = 0; i <= n+1; i++ )

    {

      p[i] = 0;

    }

    for ( i = 0; i <= n+1; i++ )

    {

      q[i] = 0;

    }

    return;

  }

  x = new double[n+1];

  r_copy = fabs ( r );

  p[0] = 1;

  q[0] = 0;

  p[1] = ( int ) r_copy;

  q[1] = 1;

  x[0] = r_copy;

  a[0] = ( int ) x[0];

  for ( i = 1; i <= n; i++ )

  {

    x[i] = 1.0 / ( x[i-1] - ( double ) a[i-1] );

    a[i] = ( int ) x[i];

    p[i+1] = a[i] * p[i] + p[i-1];

    q[i+1] = a[i] * q[i] + q[i-1];

  }

  if ( r < 0.0 )

  {

    for ( i = 0; i <= n+1; i++ )

    {

      p[i] = -p[i];

    }

  }

  delete [] x;

  return;

}

void r8_to_dec ( double dval, int dec_digit, int &mantissa, int &exponent )

{

  double mantissa_double;

  double ten1;

  double ten2;

  if ( dval == 0.0 )

  {

    mantissa = 0;

    exponent = 0;

    return;

  }

  mantissa_double = dval;

  exponent = 0;

  ten1 = pow ( 10.0, dec_digit - 1 );

  ten2 = 10.0 * ten1;

  while ( fabs ( mantissa_double ) < ten1 )

  {

    mantissa_double = mantissa_double * 10.0;

    exponent = exponent - 1;

  }

  while ( ten2 <= fabs ( mantissa_double ) )

  {

    mantissa_double = mantissa_double / 10.0;

    exponent = exponent + 1;

  }

  mantissa = r8_nint ( mantissa_double );

  if ( mantissa != 0 )

  {

    while ( 10 * ( mantissa / 10 ) == mantissa )

    {

      mantissa = mantissa / 10;

      exponent = exponent + 1;

    }

  }

  return;

}

void r8_to_rat ( double a, int ndig, int &iatop, int &iabot )

{

  double factor;

  int i;

  int ifac;

  int itemp;

  int jfac;

  factor = pow ( 10.0, ndig );

  if ( 0 < ndig )

  {

    iabot = 1;

    for ( i = 1; i <= ndig; i++ )

    {

      iabot = iabot * 10;

    }

    iatop = 1;

  }

  else

  {

    iabot = 1;

    iatop = 1;

    for ( i = 1; i <= -ndig; i++ )

    {

      iatop = iatop * 10;

    }

  }

  iatop = r8_nint ( a * factor ) * iatop;

  iabot = iabot;

  itemp = i4_gcd ( iatop, iabot );

  iatop = iatop / itemp;

  iabot = iabot / itemp;

  return;

}

double r8_uniform ( double rlo, double rhi, int &seed )

{

  double t;

  t = r8_uniform_01 ( seed );

  return ( 1.0 - t ) * rlo + t * rhi;

}

double r8_uniform_01 ( int &seed )

{

  int k;

  double r;

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + 2147483647;

  }

  r = ( double ) ( seed ) * 4.656612875E-10;

  return r;

}

double r8mat_det ( int n, double a[] )

{

  double det;

  bool even;

  int i;

  bool more;

  int *perm;

  double term;

  more = false;

  det = 0.0;

  perm = new int[n];

  for ( ; ; )

  {

    perm_next ( n, perm, more, even );

    if ( even )

    {

      term = 1.0;

    }

    else

    {

      term = -1.0;

    }

    for ( i = 1; i <= n; i++ )

    {

      term = term * a[i-1+(perm[i-1]-1)*n];

    }

    det = det + term;

    if ( !more )

    {

      break;

    }

  }

  delete [] perm;

  return det;

}

void r8mat_perm ( int n, double a[], int p[] )

{

  int i;

  int i1;

  int iopt = 1;

  int isgn;

  double it;

  int j;

  int j1;

  int j2;

  int k;

  int lc;

  int ncycle;

  double temp;

  perm_cycle ( n, p, isgn, ncycle, iopt );

  for ( i = 1; i <= n; i++ )

  {

    i1 = - p[i-1];

    if ( 0 < i1 )

    {

      lc = 0;

      for ( ; ; )

      {

        i1 = p[i1-1];

        lc = lc + 1;

        if ( i1 <= 0 )

        {

          break;

        }

      }

      i1 = i;

      for ( j = 1; j <= n; j++ )

      {

        if ( p[j-1] <= 0 )

        {

          j2 = j;

          k = lc;

          for ( ; ; )

          {

            j1 = j2;

            it = a[i1-1+(j1-1)*n];

            for ( ; ; )

            {

              i1 = abs ( p[i1-1] );

              j1 = abs ( p[j1-1] );

              temp = a[i1-1+(j1-1)*n];

              a[i1-1+(j1-1)*n] = it;

              it = temp;

              if ( j1 != j2 )

              {

                continue;

              }

              k = k - 1;

              if ( i1 == i )

              {

                break;

              }

            }

            j2 = abs ( p[j2-1] );

            if ( k == 0 ) 

            {

              break;

            }

          }

        }

      }

    }

  }

  for ( i = 0; i < n; i++ )

  {

    p[i] = abs ( p[i] );

  }

  return;

}

void r8mat_perm2 ( int m, int n, double a[], int p[], int q[] )

{

  int i;

  int i1;

  int is;

  int j;

  int j1;

  int j2;

  int k;

  int lc;

  int nc;

  double t;

  double temp;

  perm_cycle ( m, p, is, nc, 1 );

  perm_cycle ( n, q, is, nc, 1 );

  for ( i = 1; i <= m; i++ )

  {

    i1 = - p[i-1];

    if ( 0 < i1 )

    {

      lc = 0;

      for ( ; ; )

      {

        i1 = p[i1-1];

        lc = lc + 1;

        if ( i1 <= 0 )

        {

          break;

        }

      }

      i1 = i;

      for ( j = 1; j <= n; j++ )

      {

        if ( q[j-1] <= 0 )

        {

          j2 = j;

          k = lc;

          for ( ; ; )

          {

            j1 = j2;

            t = a[i1-1+(j1-1)*n];

            for ( ; ; )

            {

              i1 = abs ( p[i1-1] );

              j1 = abs ( q[j1-1] );

              temp = a[i1-1+(j1-1)*n];

              a[i1-1+(j1-1)*n] = t;

              t = temp;

 

              if ( j1 != j2 )

              {

                continue;

              }

              k = k - 1;

              if ( i1 == i )

              {

                break;

              }

            }

            j2 = abs ( q[j2-1] );

            if ( k == 0 )

            {

              break;

            }

          }

        }

      }

    }

  }

  for ( i = 0; i < m; i++ )

  {

    p[i] = abs ( p[i] );

  }

  for ( i = 0; i < n; i++ )

  {

    q[i] = abs ( q[i] );

  }

  return;

}

double r8mat_permanent ( int n, double a[] )

{

  int i;

  int iadd;

  int *iwork;

  int j;

  bool more;

  int ncard;

  double p;

  double perm;

  double prod;

  double sgn;

  double *work;

  double z;

  more = false;

  iwork = new int[n];

  work = new double[n];

  for ( i = 1; i <= n; i++ )

  {

    work[i-1] = a[i-1+(n-1)*n];

    for ( j = 1; j <= n; j++ )

    {

      work[i-1] = work[i-1] - 0.5 * a[i-1+(j-1)*n];

    }

  }

  p = 0.0;

  sgn = -1.0;

  for ( ; ; )

  {

    sgn = -sgn;

    subset_gray_next ( n-1, iwork, more, ncard, iadd );

    if ( ncard != 0 )

    {

      z = ( double ) ( 2 * iwork[iadd-1] - 1 );

      for ( i = 1; i <= n; i++ )

      {

        work[i-1] = work[i-1] + z * a[i-1+(iadd-1)*n];

      }

    }

    prod = 1.0;

    for ( i = 0; i < n; i++ )

    {

      prod = prod * work[i];

    }

    p = p + sgn * prod;

    if ( !more )

    {

      break;

    }

  }

  delete [] iwork;

  delete [] work;

  perm = p * ( double ) ( 4 * ( n % 2 ) - 2 );

  return perm;

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

        cout << setw(14) << a[(i-1)+(j-1)*m];

      }

      cout << "\n";

    }

  }

  return;

# undef INCX

}

void r8poly ( int n, double a[], double x0, int iopt, double &val )

{

  double eps;

  int i;

  int m;

  int n1;

  double w;

  double z;

  n1 = i4_min ( n, iopt );

  n1 = i4_max ( 1, n1 );

  if ( iopt < -1 )

  {

    n1 = n;

  }

  eps = ( double ) ( i4_max ( -iopt, 0 ) % 2 );

  w = - ( double ) n * eps;

  if ( -2 < iopt )

  {

    w = w + x0;

  }

  for ( m = 1; m <= n1; m++ )

  {

    val = 0.0;

    z = w;

    for ( i = m; i <= n; i++ )

    {

      z = z + eps;

      val = a[n+m-i-1] + z * val;

      if ( iopt != 0 && iopt != -1 )

      {

        a[n+m-i-1] = val;

      }

    }

    if ( iopt < 0 )

    {

      w = w + 1.0;

    }

  }

  return;

}

double *r8poly_add ( int na, double a[], int nb, double b[] )

{

  int i;

  double *c;

  c = new double[i4_max(na,nb)+1];

  if ( nb == na )

  {

    for ( i = 0; i <= na; i++ )

    {

      c[i] = a[i] + b[i];

    }

  }

  else if ( nb < na )

  {

    for ( i = 0; i <= nb; i++ )

    {

      c[i] = a[i] + b[i];

    }

    for ( i = nb + 1; i <= na; i++ )

    {

      c[i] = a[i];

    }

  }

  else if ( na < nb )

  {

    for ( i = 0; i <= na; i++ )

    {

      c[i] = a[i] + b[i];

    }

    for ( i = na + 1; i <= nb; i++ )

    {

      c[i] = b[i];

    }

  }

  return c;

}

int r8poly_degree ( int na, double a[] )

{

  int degree;

  degree = na;

  while ( 0 < degree )

  {

    if ( a[degree] != 0.0 )

    {

      return degree;

    }

    degree = degree - 1;

  }

  return degree;

}

double *r8poly_dif ( int na, double a[], int d )

{

  double *b;

  int i;

  if ( na < d )

  {

    b = new double[1];

    b[0] = 0.0;

    return b;

  }

  b = new double[na-d+1];

  for ( i = 0; i <= na - d; i++ )

  {

    b[i] = a[i+d] * ( double ) i4_fall ( i + d, d );

  }

  return b;

}

void r8poly_div ( int na, double a[], int nb, double b[], int &nq, double q[], 

  int &nr, double r[] )

{

  double *a2;

  int i;

  int j;

  int na2;

  int nb2;

  na2 = r8poly_degree ( na, a );

  nb2 = r8poly_degree ( nb, b );

  if ( b[nb2] == 0.0 )

  {

    nq = -1;

    nr = -1;

    return;

  }

  a2 = new double[na+1];

  for ( i = 0; i <= na; i++ )

  {

    a2[i] = a[i];

  }

  nq = na2 - nb2;

  nr = nb2 - 1;

  for ( i = nq; 0 <= i; i-- )

  {

    q[i] = a2[i+nb2] / b[nb2];

    a2[i+nb2] = 0.0;

    for ( j = 0; j <= nb2-1; j++ )

    {

      a2[i+j] = a2[i+j] - q[i] * b[j];

    }

  }

  for ( i = 0; i <= nr; i++ )

  {

    r[i] = a2[i];

  }

  delete [] a2;

  return;

}

void r8poly_f2p ( int n, double a[] )

{

  int i;

  int m;

  double val;

  double w;

  double z;

  w = - ( double ) n;

  for ( m = 1; m <= n; m++ )

  {

    val = 0.0;

    z = w;

    for ( i = m; i <= n; i++ )

    {

      z = z + 1.0;

      val = a[n+m-i-1] + z * val;

      a[n+m-i-1] = val;

    }

    w = w + 1.0;

  }

  return;

}

double r8poly_fval ( int n, double a[], double x )

{

  int i;

  double value;

  value = 0.0;

  for ( i = 1; i <= n; i++ )

  {

    value = a[n-i] + ( x - n + i ) * value;

  }

  return value;

}

void r8poly_mul ( int na, double a[], int nb, double b[], double c[] )

{

  double *d;

  int i;

  int j;

  d = new double[na+nb+1];

  for ( i = 0; i <= na + nb; i++ )

  {

    d[i] = 0.0;

  }

  for ( i = 0; i <= na; i++ )

  {

    for ( j = 0; j <= nb; j++ )

    {

      d[i+j] = d[i+j] + a[i] * b[j];

    }

  }

  for ( i = 0; i <= na + nb; i++ )

  {

    c[i] = d[i];

  }

  delete [] d;

  return;

}

void r8poly_n2p ( int n, double a[], double xarray[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    r8poly_nx ( n, a, xarray, 0.0 );

  }

  return;

}

double r8poly_nval ( int n, double a[], double xarray[], double x )

{

  int i;

  double value;

  value = a[n-1];

  for ( i = n-2; 0 <= i; i-- )

  {

    value = a[i] + ( x - xarray[i] ) * value;

  }

  return value;

}

void r8poly_nx ( int n, double a[], double xarray[], double x )

{

  int i;

  for ( i = n - 2; 0 <= i; i-- )

  {

    a[i] = a[i] + ( x - xarray[i] ) * a[i+1];

  }

  for ( i = n - 1; 0 < i; i-- )

  {

    xarray[i] = xarray[i-1];

  }

  xarray[0] = x;

  return;

}

void r8poly_p2f ( int n, double a[] )

{

  int i;

  int m;

  double val;

  for ( m = 1; m <= n; m++ )

  {

    val = 0.0;

    for ( i = m; i <= n; i++ )

    {

      val = a[n+m-i-1] + ( double ) ( m - 1 ) * val;

      a[n+m-i-1] = val;

    }

  }

  return;

}

void r8poly_p2n ( int n, double a[], double xarray[] )

{

  int i;

  double *work;

  double x;

  work = new double[n];

  for ( i = 0; i < n; i++ )

  {

    work[i] = 0.0;

  }

  for ( i = n - 1; 0 <= i; i-- )

  {

    x = xarray[i];

    r8poly_nx ( n, a, work, x );

  }

  delete [] work;

  return;

}

void r8poly_p2t ( int n, double a[], double x )

{

  int i;

  int m;

  double val;

  for ( m = 1; m <= n; m++ )

  {

    val = 0.0;

    for ( i = m; i <= n; i++ )

    {

      val = a[n+m-i-1] + x * val;

      a[n+m-i-1] = val;

    }

  }

  return;

}

void r8poly_power ( int na, double a[], int p, double b[] )

{

  int i;

  int j;

  int nonzer;

  for ( i = 0; i <= p * na; i++ )

  {

    b[i] = 0.0;

  }

  nonzer = 0;

  for ( i = 0; i <= na; i++ )

  {

    if ( a[i] != 0.0 )

    {

      nonzer = i;

      break;

    }

  }

  if ( nonzer == 0 )

  {

    return;

  }

  b[0] = pow ( a[nonzer], p );

  for ( i = 1; i <= p * ( na - nonzer ); i++ )

  {

    if ( i + nonzer <= na )

    {

      b[i] = ( double ) ( i * p ) * b[0] * a[i+nonzer];

    }

    else

    {

      b[i] = 0.0;

    }

    for ( j = 1; j <= i-1; j++ )

    {

      if ( j+nonzer <= na )

      {

        b[i] = b[i] - ( double ) ( i - j ) * a[j+nonzer] * b[i-j];

      }

      if ( i-j+nonzer <= na )

      {

        b[i] = b[i] + ( double ) ( i - j ) * ( double ) p * b[j] * a[i-j+nonzer];

      }

    }

    b[i] = b[i] / ( ( double ) i  * a[nonzer] );

  }

  for ( i = p*nonzer; i <= p*na; i++ )

  {

    b[i] = b[i-p*nonzer];

  }

  for ( i = 0; i <= p * nonzer-1; i++ )

  {

    b[i] = 0.0;

  }

  return;

}

void r8poly_print ( int n, double a[], string title )

{

  int i;

  double mag;

  int n2;

  char plus_minus;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  n2 = r8poly_degree ( n, a );

  if ( a[n2] < 0.0 )

  {

    plus_minus = '-';

  }

  else

  {

    plus_minus = ' ';

  }

  mag = fabs ( a[n2] );

  if ( 2 <= n2 )

  {

    cout << "  p(x) = " << plus_minus << mag << " * x^" << n2 << "\n";

  }

  else if ( n2 == 1 )

  {

    cout << "  p(x) = " << plus_minus << mag << " * x" << "\n";

  }

  else if ( n2 == 0 )

  {

    cout << "  p(x) = " << plus_minus << mag << "\n";

  }

  for ( i = n2-1; 0 <= i; i-- )

  {

    if ( a[i] < 0.0 )

    {

      plus_minus = '-';

    }

    else

    {

      plus_minus = '+';

    }

    mag = fabs ( a[i] );

    if ( mag != 0.0 )

    {

      if ( 2 <= i )

      {

        cout << "         " << plus_minus << mag << " * x^" << i << "\n";

      }

      else if ( i == 1 )

      {

        cout << "         " << plus_minus << mag << " * x" << "\n";

      }

      else if ( i == 0 )

      {

        cout << "         " << plus_minus << mag << "\n";

      }

    }

  }

  return;

}

double r8poly_pval ( int n, double a[], double x )

{

  int i;

  double value;

  value = 0.0;

  for ( i = n; 0 <= i; i-- )

  {

    value = value * x + a[i];

  }

  return value;

}

void r8poly_t2p ( int n, double a[], double x )

{

  int i;

  int j;

  for ( i = n; 1 <= i; i-- )

  {

    for ( j = i; j <= n-1; j++ )

    {

      a[j-1] = a[j-1] - a[j] * x;

    }

  }

  return;

}

void r8vec_backtrack ( int n, int maxstack, int stack[], double x[], int &indx, 

  int &k, int &nstack, int ncan[] )

{

  if ( indx == 0 )

  {

    k = 1;

    nstack = 0;

    indx = 2;

    return;

  }

  for ( ; ; )

  {

    if ( 0 < ncan[k-1] )

    {

      x[k-1] = stack[nstack-1];

      nstack = nstack - 1;

      ncan[k-1] = ncan[k-1] - 1;

      if ( k != n )

      {

        k = k + 1;

        indx = 2;

      }

      else

      {

        indx = 1;

      }

      break;

    }

    else

    {

      k = k - 1;

      if ( k <= 0 )

      {

        indx = 3;

        break;

      }

    }

  }

  return;

}

double r8vec_frac ( int n, double a[], int k )

{

  double afrac;

  int i;

  int iryt;

  int j;

  int left;

  double temp;

  double x;

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "R8VEC_FRAC - Fatal error!\n";

    cerr << "  Illegal nonpositive value of N = " << n << "\n";

    exit ( 1 );

  }

  if ( k <= 0 )

  {

    cerr << "\n";

    cerr << "R8VEC_FRAC - Fatal error!\n";

    cerr << "  Illegal nonpositive value of K = " << k << "\n";

    exit ( 1 );

  }

  if ( n < k )

  {

    cerr << "\n";

    cerr << "R8VEC_FRAC - Fatal error!\n";

    cerr << "  Illegal N < K, K = " << k << "\n";

    exit ( 1 );

  }

  left = 1;

  iryt = n;

  for ( ; ; )

  {

    if ( iryt <= left )

    {

      afrac = a[k-1];

      break;

    }

    x = a[k-1];

    i = left;

    j = iryt;

    for ( ; ; )

    {

      if ( j < i )

      {

        if ( j < k )

        {

          left = i;

        }

        if ( k < i )

        {

          iryt = j;

        }

        break;

      }

      while ( a[i-1] < x )

      {

        i = i + 1;

      }

      while ( x < a[j-1] )

      {

        j = j - 1;

      }

      if ( i <= j )

      {

        temp = a[i-1];

        a[i-1] = a[j-1];

        a[j-1] = temp;

        i = i + 1;

        j = j - 1;

      }

    }

  }

  return afrac;

}

void r8vec_indicator ( int n, double a[] )

{

  int i;

  for ( i = 0; i < n; i++ ) 

  {

    a[i] = ( double ) ( i + 1 );

  }

  return;

}

bool r8vec_mirror_next ( int n, double a[] )

{

  int i;

  int positive;

  positive = 0;

  for ( i = 1; i <= n; i++ )

  {

    if ( 0.0 < a[i-1] )

    {

      positive = i;

      break;

    }

  }

  if ( positive == 0 )

  {

    for ( i = 1; i <= n; i++ )

    {

      a[i-1] = -a[i-1];

    }

    return true;

  }

  for ( i = 1; i <= positive; i++ )

  {

    a[i-1] = -a[i-1];

  }

  return false;

}

void r8vec_print ( int n, double a[], string title )

{

  int i;

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  for ( i = 0; i <= n-1; i++ ) 

  {

    cout << "  " << setw(8)  << i 

         << "  " << setw(12) << a[i] << "\n";

  }

  return;

}

void r8vec_uniform ( int n, double b, double c, int &seed, double x[] )

{

  int i;

  int i4_huge = 2147483647;

  int k;

  if ( seed == 0 )

  {

    cerr << "\n";

    cerr << "R8VEC_UNIFORM - Fatal error!\n";

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

    x[i] = b + ( c - b ) * ( double ) ( seed ) * 4.656612875E-10;

  }

  return;

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

unsigned long rand_initialize ( unsigned long seed )

{

  if ( seed != 0 )

  {

    cout << "\n";

    cout << "RAND_INITIALIZE\n";

    cout << "  Initialize RAND with user SEED = " << seed << "\n";

  }

  else

  {

    seed = get_seed ( );

    cout << "\n";

    cout << "RAND_INITIALIZE\n";

    cout << "  Initialize RAND with arbitrary SEED = " << seed << "\n";

  }

  srand ( seed );

  return seed;

}

unsigned long random_initialize ( unsigned long seed )

{

  if ( seed != 0 )

  {

    cout << "\n";

    cout << "RANDOM_INITIALIZE\n";

    cout << "  Initialize RANDOM with user SEED = " << seed << "\n";

  }

  else

  {

    seed = get_seed ( );

    cout << "\n";

    cout << "RANDOM_INITIALIZE\n";

    cout << "  Initialize RANDOM with arbitrary SEED = " << seed << "\n";

  }

  srandom ( seed );

  return seed;

}

void rat_add ( int itop1, int ibot1, int itop2, int ibot2, int &itop, int &ibot, 

  bool &error )

{

  int i_max;

  int itemp;

  int ibot3;

  i_max = i4_huge ( );

  error = false;

  if ( itop1 == 0 )

  {

    itop = itop2;

    ibot = ibot2;

    return;

  }

  else if ( itop2 == 0 )

  {

    itop = itop1;

    ibot = ibot1;

    return;

  }

  ibot3 = i4_gcd ( ibot1, ibot2 );

  ibot1 = ibot1 / ibot3;

  ibot2 = ibot2 / ibot3;

  if ( ( double ) ( i_max ) < fabs ( ( double ) ( itop1 ) * ( double ) ( ibot2 ) ) )

  {

    error = true;

    cerr << "\n";

    cerr << "RAT_ADD - Fatal error!\n";

    cerr << "  Overflow of top of rational sum.\n";

    itop = 0;

    ibot = 1;

    exit ( 1 );

  }

  itop1 = itop1 * ibot2;

  if ( ( double ) ( i_max ) < fabs ( ( double ) ( itop2 ) * ( double ) ( ibot1 ) ) )

  {

    error = true;

    cerr << "\n";

    cerr << "RAT_ADD - Fatal error!\n";

    cerr << "  Overflow of top of rational sum.\n";

    itop = 0;

    ibot = 1;

    exit ( 1 );

  }

  itop2 = itop2 * ibot1;

  if ( ( double ) ( i_max ) < fabs ( ( double ) ( itop1 ) + ( double ) ( itop2 ) ) )

  {

    error = true;

    cerr << "\n";

    cerr << "RAT_ADD - Fatal error!\n";

    cerr << "  Overflow of top of rational sum.\n";

    itop = 0;

    ibot = 1;

    exit ( 1 );

  }

  itop = itop1 + itop2;

  if ( ( double ) ( i_max ) < 

    fabs ( ( double ) ( ibot1 ) * ( double ) ( ibot2 ) * ( double ) ( ibot3 ) ) )

  {

    error = true;

    cerr << "\n";

    cerr << "RAT_ADD - Fatal error!\n";

    cerr << "  Overflow of bottom of rational sum.\n";

    itop = 0;

    ibot = 1;

    exit ( 1 );

  }

  ibot = ibot1 * ibot2 * ibot3;

  itemp = i4_gcd ( itop, ibot );

  itop = itop / itemp;

  ibot = ibot / itemp;

  if ( ibot < 0 )

  {

    ibot = -ibot;

    itop = -itop;

  }

  return;

}

void rat_div ( int itop1, int ibot1, int itop2, int ibot2, int &itop, 

  int &ibot, bool &error )

{

  int i_max;

  int itemp;

  error = false;

  i_max = i4_huge ( );

  if ( ibot1 == 0 || itop2 == 0 || ibot2 == 0 )

  {

    error = true;

    return;

  }

  if ( itop1 == 0 )

  {

    itop = 0;

    ibot = 1;

    return;

  }

  itemp = i4_gcd ( itop1, ibot1 );

  itop1 = itop1 / itemp;

  ibot1 = ibot1 / itemp;

  itemp = i4_gcd ( itop1, itop2 );

  itop1 = itop1 / itemp;

  itop2 = itop2 / itemp;

  itemp = i4_gcd ( ibot2, ibot1 );

  ibot2 = ibot2 / itemp;

  ibot1 = ibot1 / itemp;

  itemp = i4_gcd ( ibot2, itop2 );

  ibot2 = ibot2 / itemp;

  itop2 = itop2 / itemp;

  if ( ( double ) i_max < fabs ( ( double ) itop1 * ( double ) ibot2 ) )

  {

    error = true;

    cerr << "\n";

    cerr << "RAT_DIV - Fatal error!\n";

    cerr << "  Overflow of top of rational fraction.\n";

    itop = 0;

    ibot = 0;

    exit ( 1 );

  }

  itop = itop1 * ibot2;

  if ( ( double ) i_max < fabs ( ( double ) ibot1 * ( double ) itop2 ) )

  {

    error = true;

    cerr << "\n";

    cerr << "RAT_DIV - Fatal error!\n";

    cerr << "  Overflow of bottom of rational fraction.\n";

    itop = 0;

    ibot = 1;

    exit ( 1 );

  }

  ibot = ibot1 * itop2;

  if ( ibot < 0 )

  {

    ibot = - ibot;

    itop = - itop;

  }

  return;

}

void rat_farey ( int n, int max_frac, int &num_frac, int a[], int b[] )

{

  int c;

  int k;

  if ( n <= 0 )

  {

    num_frac = 0;

    return;

  }

  k = 0;

  if ( max_frac <= 0 )

  {

    num_frac = k;

    return;

  }

  a[k] = 0;

  b[k] = 1;

  k = 1;

  if ( max_frac <= 1 )

  {

    num_frac = k;

    return;

  }

  a[k] = 1;

  b[k] = n;

  k = 2;

  while ( k < max_frac )

  {

    if ( a[k-1] == 1 && b[k-1] == 1 )

    {

      break;

    }

    c = ( b[k-2] + n ) / b[k-1];

    a[k] = c * a[k-1] - a[k-2];

    b[k] = c * b[k-1] - b[k-2];

    k = k + 1;

  }

  num_frac = k;

  return;

}

void rat_farey2 ( int n, int a[], int b[] )

{

  int i;

  int ihi;

  if ( n == 0 )

  {

    a[0] = 0;

    b[0] = 1;

    a[1] = 1;

    b[1] = 1;

    return;

  }

  ihi = i4_power ( 2, n - 1 );

  for ( i = ihi; 0 <= i; i-- )

  {

    a[2*i] = a[i];

    b[2*i] = b[i];

  }

  ihi = i4_power ( 2, n ) - 1;

  for ( i = 1; i <= ihi; i = i + 2 )

  {

    a[i] = a[i-1] + a[i+1];

    b[i] = b[i-1] + b[i+1];

  }

  return;

}

void rat_mul ( int itop1, int ibot1, int itop2, int ibot2, int &itop, 

  int &ibot, bool &error )

{

  int i_max;

  int itemp;

  error = false;

  i_max = i4_huge ( );

  if ( itop1 == 0 || itop2 == 0 )

  {

    itop = 0;

    ibot = 1;

    return;

  }

  itemp = i4_gcd ( itop1, ibot1 );

  itop1 = itop1 / itemp;

  ibot1 = ibot1 / itemp;

  itemp = i4_gcd ( itop1, ibot2 );

  itop1 = itop1 / itemp;

  ibot2 = ibot2 / itemp;

  itemp = i4_gcd ( itop2, ibot1 );

  itop2 = itop2 / itemp;

  ibot1 = ibot1 / itemp;

  itemp = i4_gcd ( itop2, ibot2 );

  itop2 = itop2 / itemp;

  ibot2 = ibot2 / itemp;

  if ( ( double ) ( i_max ) < fabs ( ( double ) itop1 * ( double ) itop2 ) )

  {

    error = true;

    cerr << "\n";

    cerr << "RAT_MUL - Fatal error!\n";

    cerr << "  Overflow of top of rational product.\n";

    itop = 0;

    exit ( 1 );

  }

  itop = itop1 * itop2;

  if ( ( double ) ( i_max ) < fabs ( ( double ) ibot1 * ( double ) ibot2 ) )

  {

    error = true;

    cerr << "\n";

    cerr << "RAT_MUL - Fatal error!\n";

    cerr << "  Overflow of bottom of rational product.\n";

    ibot = 1;

    exit ( 1 );

  }

  ibot = ibot1 * ibot2;

  if ( ibot < 0 )

  {

    ibot = -ibot;

    itop = -itop;

  }

  return;

}

void rat_normalize ( int &a, int &b )

{

  int c;

  if ( a == 0 && b == 0 )

  {

    return;

  }

  else if ( a == 0 && b != 0 )

  {

    b = 1;

    return;

  }

  else if ( a != 0 && b == 0 )

  {

    a = 1;

    return;

  }

  if ( a == b )

  {

    a = 1;

    b = 1;

    return;

  }

  if ( b < 0 )

  {

    a = -a;

    b = -b;

  }

  c = i4_gcd ( abs ( a ), abs ( b ) );

  if ( 1 < c )

  {

    a = a / c;

    b = b / c;

  }

  return;

}

void rat_sum_formula ( int n, int a[], int b[] )

{

  int asum;

  int aval;

  int bsum;

  int bval;

  bool error;

  int i;

  int j;

  a[0+0*(n+1)] = 1;

  for ( j = 1; j < n+1; j++ )

  {

    a[0+j*(n+1)] = 0;

  }

  b[0+0*(n+1)] = 1;

  for ( j = 1; j < n+1; j++ )

  {

    b[0+j*(n+1)] = 1;

  }

  for ( i = 1; i <= n; i++ )

  {

    asum = 0;

    bsum = 0;

    for ( j = 0; j < i; j++ )

    {

      aval = a[i-1+j*(n+1)];

      bval = b[i-1+j*(n+1)];

      rat_mul ( aval, bval, i, i+1-j, aval, bval, error );

      a[i+j*(n+1)] = aval;

      b[i+j*(n+1)] = bval;

      rat_add ( asum, bsum, aval, bval, asum, bsum, error );

    }

    asum = -asum;

    rat_add ( 1, 1, asum, bsum, aval, bval, error );

    a[i+i*(n+1)] = aval;

    b[i+i*(n+1)] = bval;

    for ( j = i+1; j < n+1; j++ )

    { 

      a[i+j*(n+1)] = 0;

    }

    for ( j = i+1; j <= n; j++ )

    { 

      b[i+j*(n+1)] = 1;

    }

  }

  return;

}

void rat_to_cfrac ( int ip, int iq, int m, int &n, int a[], bool &error )

{

  error = false;

  n = 0;

  for ( ; ; )

  {

    if ( m <= n )

    {

      error = true;

      return;

    }

    a[n] = ip / iq;

    n = n + 1;

    ip = ip % iq;

    if ( ip == 0 )

    {

      return;

    }

    if ( m <= n )

    {

      error = true;

      return;

    }

    a[n] = iq / ip;

    n = n + 1;

    iq = iq % ip;

    if ( iq == 0 )

    {

      break;

    }

  }

  return;

}

void rat_to_dec ( int rat_top, int rat_bot, int &mantissa, int &exponent )

{

  int gcd;

  double r;

  double r_max;

  int s;

  if ( rat_top == 0 ) 

  {

    mantissa = 0;

    exponent = 0;

    return;

  }

  gcd = i4_gcd ( rat_top, rat_bot );

  rat_top = rat_top / gcd;

  rat_bot = rat_bot / gcd;

  if ( rat_bot < 0 )

  {

    rat_top = -rat_top;

    rat_bot = -rat_bot;

  }

  if ( rat_bot == 1 )

  {

    mantissa = rat_top;

    exponent = 0;

    return;

  }

  exponent = 0;

  while ( ( rat_bot % 10 ) == 0 )

  {

    exponent = exponent - 1;

    rat_bot = rat_bot / 10;

  }

  while ( ( rat_top % 10 ) == 0 )

  {

    exponent = exponent + 1;

    rat_top = rat_top / 10;

  }

  r = ( double ) rat_top / ( double ) rat_bot;

  if ( r < 0 )

  {

    s = -1;

    r = -r;

  }

  else

  {

    s = 1;

  }

  r_max = ( ( double ) i4_huge ( ) ) / 10.0;

  while ( r != ( double ) ( ( int ) r ) && r < r_max )

  {

    r = r * 10.0;

    exponent = exponent - 1;

  }

  mantissa = s * ( int ) r;

  return;

}

double rat_to_r8 ( int top, int bot )

{

  return ( ( double ) top / ( double ) bot );

}

int rat_width ( int a, int b )

{

  int abs_a;

  int abs_b;

  int ten_pow;

  int value;

  value = 1;

  ten_pow = 10;

  if ( a == 0 )

  {

    return value;

  }

  

  abs_a = abs ( a );

  while ( ten_pow <= abs_a )

  {

    value = value + 1;

    ten_pow = ten_pow * 10;

  }

  if ( a * b < 0 )

  {

    value = value + 1;

    ten_pow = ten_pow * 10;

  }

  abs_b = abs ( b );

  while ( ten_pow <= abs_b )

  {

    value = value + 1;

    ten_pow = ten_pow * 10;

  }

  return value;

}

void ratmat_det ( int n, int iatop[], int iabot[], int &idtop, int &idbot, 

  bool &error )

{

  bool even;

  int i;

  int *iarray;

  int ibot;

  int ibot2;

  int itop;

  int itop2;

  bool more;

  error = false;

  more = false;

  idtop = 0;

  idbot = 1;

  iarray = new int[n];

  for ( ; ; )

  {

    perm_next ( n, iarray, more, even );

    if ( even )

    {

      itop = 1;

    }

    else

    {

      itop = -1;

    }

    ibot = 1;

    for ( i = 1; i <= n; i++ )

    {

      itop2 = iatop[i-1+(iarray[i-1]-1)*n];

      ibot2 = iabot[i-1+(iarray[i-1]-1)*n];

      rat_mul ( itop, ibot, itop2, ibot2, itop, ibot, error );

      if ( error )

      {

        cerr << "\n";

        cerr << "RATMAT_DET - Fatal error!\n";

        cerr << "  An overflow occurred.\n";

        cerr << "  The determinant calculation cannot be done\n";

        cerr << "  for this matrix.\n";

        idtop = 0;

        idbot = 1;

        delete [] iarray;

        exit ( 1 );

      }

    }

    rat_add ( itop, ibot, idtop, idbot, idtop, idbot, error );

    if ( error )

    {

      cerr << "\n";

      cerr << "RATMAT_DET - Fatal error!\n";

      cerr << "  An overflow occurred.\n";

      cerr << "  The determinant calculation cannot be done\n";

      cerr << "  for this matrix.\n";

      idtop = 0;

      idbot = 1;

      delete [] iarray;

      exit ( 1 );

    }

    if ( !more )

    {

      break;

    }

  }

  delete [] iarray;

  if ( idbot < 0 )

  {

    idbot = -idbot;

    idtop = -idtop;

  }

  return;

}

void ratmat_print ( int m, int n, int a[], int b[], string title )

{

  bool all_ones;

  int i;

  int j;

  int jmax;

  int jmin;

  int kmax;

  int ncolum = 80;

  int npline;

  kmax = 0;

  for ( i = 0; i < m; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      kmax = i4_max ( kmax, rat_width ( a[i+j*m], b[i+j*m] ) );

    }

  }

  kmax = kmax + 2;

  npline = ncolum / kmax;

  for ( jmin = 0; jmin < n; jmin = jmin + npline )

  {

    jmax = i4_min ( jmin+npline-1, n-1 );

    cout << "\n";

    if ( jmin == 0 )

    {

      cout << title << "\n";

      cout << "\n";

    }

    if ( 0 < jmin || jmax < n-1 )

    {

      cout << "Columns " << jmin << " to " << jmax << "\n";

      cout << "\n";

    }

    for ( i = 0; i < m; i++ )

    {

      for ( j = jmin; j <= jmax; j++ )

      {

        cout << setw(kmax) << a[i+j*m] << "  ";

      }

      cout << "\n";

      all_ones = true;

      for ( j = jmin; j <= jmax; j++ )

      {

        if ( b[i+j*m] != 1 )

        {

          all_ones = false;

        }

      }

      if ( !all_ones )

      {

        for ( j = jmin; j <= jmax; j++ )

        {

          cout << setw(kmax) << b[i+j*m] << "  ";

        }

        cout << "\n";

      }

      if ( jmax == n - 1 && i == m - 1 )

      {

      }

      else

      {

        cout << "\n";

      }

    }

  }

  return;

}

void regro_next ( bool &done, int n, int v[], int vmax[] )

{

  int i;

  int j;

  if ( done )

  {

    for ( i = 0; i < n; i++ )

    {

      v[i] = 1;

    }

    vmax[0] = 1;

    for ( i = 1; i < n; i++ )

    {

      vmax[i] = 2;

    }

    done = false;

  }

  else

  {

    j = n;

    for ( ; ; )

    {

      if ( j == 1 )

      {

        done = true;

        return;

      }

      if ( v[j-1] != vmax[j-1] )

      {

        break;

      }

      j = j - 1;

    }

    v[j-1] = v[j-1] + 1;

    for ( i = j + 1; i <= n; i++ )

    {

      v[i-1] = 1;

      if ( v[j-1] == vmax[j-1] )

      {

        vmax[i-1] = vmax[j-1] + 1;

      }

      else

      {

        vmax[i-1] = vmax[j-1];

      }

    }

  }

  return;

}

void rfrac_to_cfrac ( int m, double p[], double q[], double t[], bool &error )

{

  double *a;

  int i;

  int k;

  double ta;

  a = new double[(m+1)*(2*m+1)];

  error = false;

  for ( i = 0; i <= m; i++ )

  {

    a[i+0*(m+1)] = q[i];

  }

  for ( i = 0; i < m; i++ )

  {

    a[i+1*(m+1)] = p[i];

  }

  t[0] = a[0+0*(m+1)] / a[0+1*(m+1)];

  ta = a[m+0*(m+1)];

  for ( i = 1; i <= m; i++ )

  {

    a[m-i+(2*i)*(m+1)] = ta;

  }

  for ( k = 1; k <= 2*m-2; k++ )

  {

    for ( i = 1; i <= (2*m-k)/2; i++ )

    {

      a[i-1+(k+1)*(m+1)] = a[i+(k-1)*(m+1)] - t[k-1] * a[i+k*(m+1)];

    }

    if ( a[0+(k+1)*(m+1)] == 0.0 )

    {

      error = true;

      cerr << "\n";

      cerr << "RFRAC_TO_CFRAC - Fatal error!\n";

      cerr << "  A[0,K+1] is zero for K = " << k << "\n";

      exit ( 1 );

    }

    t[k] = a[0+k*(m+1)] / a[0+(k+1)*(m+1)];

  }

  t[2*m-1] = a[0+(2*m-1)*(m+1)] / a[0+(2*m)*(m+1)];

  delete [] a;

  return;

}

void rfrac_to_jfrac ( int m, double p[], double q[], double r[], double s[] )

{

  double *a;

  int i;

  int k;

  if ( m < 1 )

  {

    cerr << "\n";

    cerr << "RFRAC_TO_JFRAC - Fatal error!\n";

    cerr << "  Input M < 1.\n";

    exit ( 1 );

  }

  a = new double[(m+1)*(m+1)];

  for ( i = 0; i <= m; i++ )

  {

    a[i+0*(m+1)] = q[i];

  }

  for ( i = 0; i < m; i++ )

  {

    a[i+1*(m+1)] = p[i];

  }

  if ( 1 < m )

  {

    r[0] = a[m-1+1*(m+1)] / a[m+0*(m+1)];

    s[0] = ( r[0] * a[m-1+0*(m+1)] - a[m-2+1*(m+1)] ) / a[m-1+1*(m+1)];

    for ( k = 0; k < m - 2; k++ )

    {

      a[0+(k+2)*(m+1)] = r[k] * a[0+k*(m+1)] - s[k] * a[0+(k+1)*(m+1)];

      for ( i = 1; i < m - k; i++ )

      {

        a[i+(k+2)*(m+1)] = r[k] * a[i+k*(m+1)] 

          - a[i-1+(k+1)*(m+1)] - s[k] * a[i+(k+1)*(m+1)];

      }

      if ( a[m-2-k+(k+2)*(m+1)] == 0.0 )

      {

        cerr << "\n";

        cerr << "RFRAC_TO_JFRAC - Fatal error!\n";

        cerr << "  A[M-2-K,K+2] = 0 for K = " << k << "\n";

        exit ( 1 );

      }

      r[k+1] = a[m-k-2+(k+2)*(m+1)] / a[m-2-k+1+(k+1)*(m+1)];

      s[k+1] = ( r[k+1] * a[m-2-k+(k+1)*(m+1)] 

        - a[m-2-k-1+(k+2)*(m+1)] ) / a[m-2-k+(k+2)*(m+1)];

    }

    a[0+m*(m+1)] = r[m-2] * a[0+(m-2)*(m+1)] - s[m-2] * a[0+(m-1)*(m+1)];

  }

  r[m-1] = a[0+m*(m+1)] / a[1+(m-1)*(m+1)];

  s[m-1] = a[0+(m-1)*(m+1)] / a[1+(m-1)*(m+1)];

  delete [] a;

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

void schroeder ( int n, int s[] )

{

  int i;

  if ( n <= 0 )

  {

    return;

  }

  s[0] = 1;

  if ( n <= 1 )

  {

    return;

  }

  s[1] = 1;

  if ( n <= 2 )

  {

    return;

  }

  for ( i = 3; i <= n; i++ )

  {

    s[i-1] = ( ( 6 * i - 9 ) * s[i-2] - ( i - 3 ) * s[i-3] ) / i;

  }

  return;

}

void sort_heap_external ( int n, int &indx, int &i, int &j, int isgn )

{

  static int i_save = 0;

  static int j_save = 0;

  static int k = 0;

  static int k1 = 0;

  static int n1 = 0;

  if ( indx == 0 )

  {

    i_save = 0;

    j_save = 0;

    k = n / 2;

    k1 = k;

    n1 = n;

  }

  else if ( indx < 0 )

  {

    if ( indx == -2 ) 

    {

      if ( isgn < 0 ) 

      {

        i_save = i_save + 1;

      }

      j_save = k1;

      k1 = i_save;

      indx = -1;

      i = i_save;

      j = j_save;

      return;

    }

    if ( 0 < isgn ) 

    {

      indx = 2;

      i = i_save;

      j = j_save;

      return;

    }

    if ( k <= 1 ) 

    {

      if ( n1 == 1 ) 

      {

        i_save = 0;

        j_save = 0;

        indx = 0;

      }

      else 

      {

        i_save = n1;

        j_save = 1;

        n1 = n1 - 1;

        indx = 1;

      }

      i = i_save;

      j = j_save;

      return;

    }

    k = k - 1;

    k1 = k;

  }

  else if ( indx == 1 ) 

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

      indx = -1;

      i = i_save;

      j = j_save;

      return;

    }

    else if ( i_save <= n1 ) 

    {

      j_save = i_save + 1;

      indx = -2;

      i = i_save;

      j = j_save;

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

    indx = 0;

    i = i_save;

    j = j_save;

  }

  else 

  {

    i_save = n1;

    j_save = 1;

    n1 = n1 - 1;

    indx = 1;

    i = i_save;

    j = j_save;

  }

  return;

}

void subcomp_next ( int n, int k, int a[], bool &more, int &h, int &t )

{

  int i;

  static bool more2 = false;

  static int n2 = 0;

  if ( !more )

  {

    n2 = 0;

    for ( i = 0; i < k; i++ )

    {

      a[i] = 0;

    }

    more2 = false;

    h = 0;

    t = 0;

    more = true;

  }

  else if ( more2 )

  {

    comp_next ( n2, k, a, more2, h, t );

  }

  else

  {

    more2 = false;

    n2 = n2 + 1;

    comp_next ( n2, k, a, more2, h, t );

  }

  if ( !more2 && n2 == n )

  {

    more = false;

  }

  return;

}

void subcompnz_next ( int n, int k, int a[], bool &more )

{

  int i;

  static bool more2 = false;

  static int n2 = 0;

  if ( n < k )

  {

    for ( i = 0; i < k; i++ )

    {

      a[i] = -1;

    }

    return;

  }

  if ( !more )

  {

    more = true;

    for ( i = 0; i < k; i++ )

    {

      a[i] = 1;

    }

    n2 = k;

    more2 = false;

  }

  else if ( more2 )

  {

    compnz_next ( n2, k, a, more2 );

  }

  else

  {

    more2 = false;

    n2 = n2 + 1;

    compnz_next ( n2, k, a, more2 );

  }

  if ( !more2 && n2 == n )

  {

    more = false;

  }

  return;

}

void subcompnz2_next ( int n_lo, int n_hi, int k, int a[], bool &more )

{

  int i;

  static bool more2 = false;

  static int n2 = 0;

  if ( n_hi < k )

  {

    for ( i = 0; i < k; i++ )

    {

      a[i] = -1;

    }

    return;

  }

  if ( n_hi < n_lo )

  {

    for ( i = 0; i < k; i++ )

    {

      a[i] = -1;

    }

    return;

  }

  if ( !more )

  {

    more = true;

    n2 = i4_max ( k, n_lo );

    more2 = false;

    compnz_next ( n2, k, a, more2 );

  }

  else if ( more2 )

  {

    compnz_next ( n2, k, a, more2 );

  }

  else

  {

    n2 = n2 + 1;

    compnz_next ( n2, k, a, more2 );

  }

  if ( !more2 && n2 == n_hi )

  {

    more = false;

  }

  return;

}

void subset_by_size_next ( int n, int a[], int &size, bool &more )

{

  static bool more2 = false;

  if ( !more )

  {

    more = true;

    more2 = false;

    size = n;

  }

  else if ( !more2 )

  {

    size = size - 1;

  }

  if ( 0 < size )

  {

    ksub_next ( n, size, a, more2 );

  }

  else if ( size == 0 )

  {

    more = false;

  }

  return;

}

void subset_gray_next ( int n, int a[], bool &more, int &ncard, int &iadd )

{

  int i;

  if ( !more )

  {

    for ( i = 0; i < n; i++ )

    {

      a[i] = 0;

    }

    iadd = 0;

    ncard = 0;

    more = true;

  }

  else

  {

    iadd = 1;

    if ( ( ncard % 2 ) != 0 )

    {

      for ( ; ; )

      {

        iadd = iadd + 1;

        if ( a[iadd-2] != 0 )

        {

          break;

        }

      }

    }

    a[iadd-1] = 1 - a[iadd-1];

    ncard = ncard + 2 * a[iadd-1] - 1;

    if ( ncard == a[n-1] )

    {

      more = false;

    }

  }

  return;

}

int subset_gray_rank ( int n, int a[] )

{

  int gray;

  int rank;

  gray = ( int ) ubvec_to_ui4 ( n, a );

  rank = gray_rank ( gray );

  rank = rank + 1;

  return rank;

}

void subset_gray_unrank ( int rank, int n, int a[] )

{

  int gray;

  gray = ( unsigned int ) gray_unrank ( rank-1 );

  ui4_to_ubvec ( gray, n, a );

  return;

}

void subset_lex_next ( int n, bool jmp, int ndim, int &k, int a[] )

{

  int is;

  if ( k <= 0 )

  {

    if ( jmp )

    {

      return;

    }

    is = 0;

    k = 1;

    a[0] = 1;

  }

  else if ( a[k-1] != n )

  {

    is = a[k-1];

    if ( !jmp )

    {

      k = k + 1;

    }

    a[k-1] = is + 1;

  }

  else

  {

    k = k - 1;

    if ( k != 0 )

    {

      a[k-1] = a[k-1] + 1;

    }

  }

  return;

}

void subset_random ( int n, int &seed, int a[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    a[i] = i4_uniform_ab ( 0, 1, seed );

  }

  return;

}

void subtriangle_next ( int n, bool &more, int &i1, int &j1, int &i2, int &j2, 

  int &i3, int &j3 )

{

  if ( n <= 0 )

  {

    more = false;

    return;

  }

  if ( !more )

  {

    i1 = 0;

    j1 = 0;

    i2 = 1;

    j2 = 0;

    i3 = 0;

    j3 = 1;

    if ( n == 1 )

    {

      more = false;

    }

    else

    {

      more = true;

    }

  }

  else if ( i2 < i3 )

  {

    i1 = i3;

    j1 = j3;

    i2 = i1 + 1;

    j2 = j1;

    i3 = i1;

    j3 = j1 + 1;

  }

  else if ( i1 + 1 + j1 + 1 <= n )

  {

    i1 = i1 + 1;

    j1 = j1 + 1;

    i2 = i1 - 1;

    j2 = j1;

    i3 = i1;

    j3 = j1 - 1;

  }

  else

  {

    i1 = 0;

    j1 = j1 + 1;

    i2 = i1 + 1;

    j2 = j1;

    i3 = i1;

    j3 = j1 + 1;

    if ( n <= j1 + 1 )

    {

      more = false;

    }

  }

  return;

}

void thue_binary_next ( int &n, int thue[] )

{

  int i;

  int n_out;

  int *thue_out;

  n_out = 0;

  thue_out = new int[2 * n ];

  for ( i = 0; i < n; i++ )

  {

    if ( thue[i] == 0 )

    {

      thue_out[n_out] = 0;

      n_out = n_out + 1;

      thue_out[n_out] = 1;

      n_out = n_out + 1;

    }

    else if ( thue[i] == 1 )

    {

      thue_out[n_out] = 1;

      n_out = n_out + 1;

      thue_out[n_out] = 0;

      n_out = n_out + 1;

    }

    else

    {

      cerr << "\n";

      cerr << "THUE_BINARY_NEXT - Fatal error!\n";

      cerr << "  The input sequence contains a non-binary digit\n";

      cerr << "  THUE[" << i << "] = " << thue[i] << "\n";

      exit ( 1 );

    }

  }

  n = n_out;

  for ( i = 0; i < n; i++ )

  {

    thue[i] = thue_out[i];

  }

  delete [] thue_out;

  return;

}

void thue_ternary_next ( int &n, int thue[] )

{

  int i;

  int n_out;

  int *thue_out;

  n_out = 0;

  thue_out = new int[ 3 * n ];

  for ( i = 0; i < n; i++ )

  {

    if ( thue[i] == 0 )

    {

      thue_out[n_out] = 1;

      n_out = n_out + 1;

      thue_out[n_out] = 2;

      n_out = n_out + 1;

    }

    else if ( thue[i] == 1 )

    {

      thue_out[n_out] = 1;

      n_out = n_out + 1;

      thue_out[n_out] = 0;

      n_out = n_out + 1;

      thue_out[n_out] = 2;

      n_out = n_out + 1;

    }

    else if ( thue[i] == 2 )

    {

      thue_out[n_out] = 0;

      n_out = n_out + 1;

    }

    else

    {

      cerr << "\n";

      cerr << "THUE_TERNARY_NEXT - Fatal error!\n";

      cerr << "  The input sequence contains a non-ternary digit\n";

      cerr << "  THUE[" << i << "] = " << thue[i] << "\n";

      exit ( 1 );

    }

  }

  n = n_out;

  for ( i = 0; i < n_out; i++ )

  {

    thue[i] = thue_out[i];

  }

  delete [] thue_out;

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

void triang ( int n, int zeta[], int p[] )

{

  int i;

  bool error;

  int iq;

  int ir;

  int it;

  int l;

  int m;

  error = pord_check ( n, zeta );

  if ( error )

  {

    cerr << "\n";

    cerr << "TRIANG - Fatal error!\n";

    cerr << "  The matrix ZETA does not represent a\n";

    cerr << "  partial ordering.\n";

    exit ( 1 );

  }

  m = 0;

  l = 0;

  for ( i = 0; i < n; i++ )

  {

    p[i] = 0;

  }

  for ( ; ; )

  {

    m = m + 1;

    if ( p[m-1] == 0 ) 

    {

      break;

    }

    if ( m == n )

    {

      return;

    }

  }

  it = m + 1;

  ir = m + 1;

  for ( ; ; )

  {

    if ( ir <= n )

    {

      if ( p[ir-1] == 0 && zeta[(ir-1)+(m-1)*n] != 0 )

      {

        p[ir-1] = m;

        m = ir;

        ir = it;

      }

      else

      {

        ir = ir + 1;

      }

    }

    else

    {

      l = l + 1;

      iq = p[m-1];

      p[m-1] = l;

      if ( iq != 0 )

      {

        ir = m + 1;

        m = iq;

      }

      else if ( m == n )

      {

        break;

      }

      else

      {

        for ( ; ; )

        {

          m = m + 1;

          if ( p[m-1] == 0 )

          {

            break;

          }

          if ( m == n )

          {

            return;

          }

        }

        it = m + 1;

        ir = m + 1;

      }

    }

  }

  return;

}

void tuple_next ( int m1, int m2, int n, int &rank, int x[] )

{

  int i;

  int j;

  if ( m2 < m1 )

  {

    rank = 0;

    return;

  }

  if ( rank <= 0 )

  {

    for ( i = 0; i < n; i++ )

    {

      x[i] = m1;

    }

    rank = 1;

  }

  else

  {

    rank = rank + 1;

    i = n - 1;

    for ( ; ; )

    {

      if ( x[i] < m2 )

      {

        x[i] = x[i] + 1;

        break;

      }

      x[i] = m1;

      if ( i == 0 )

      {

        rank = 0;

        for ( j = 0; j < n; j++ )

        {

          x[j] = m1;

        }

        break;

      }

      i = i - 1;

    }

  }

  return;

}

void tuple_next_fast ( int m, int n, int rank, int x[] )

{

  static int *base = NULL;

  int i;

  if ( rank < 0 )

  {

    if ( m <= 0 )

    {

      cerr << "\n";

      cerr << "TUPLE_NEXT_FAST - Fatal error!\n";

      cerr << "  The value M <= 0 is not legal.\n";

      cerr << "  M = " << m << "\n";

      exit ( 1 );

    }

    if ( n <= 0 )

    {

      cerr << "\n";

      cerr << "TUPLE_NEXT_FAST - Fatal error!\n";

      cerr << "  The value N <= 0 is not legal.\n";

      cerr << "  N = " << n << "\n";

      exit ( 1 );

    }

    if ( base )

    {

      delete [] base;

    }

    base = new int[n];

    base[n-1] = 1;

    for ( i = n-2; 0 <= i; i-- )

    {

      base[i] = base[i+1] * m;

    }

    for ( i = 0; i < n; i++ )

    {

      x[i] = -1;

    }

  }

  else

  {

    for ( i = 0; i < n; i++ )

    {

      x[i] = ( ( rank / base[i] ) % m ) + 1;

    }

  }

  return;

}

void tuple_next_ge ( int m, int n, int &k, int x[] )

{

  int i;

  int j;

  if ( m < 1 )

  {

    return;

  }

  if ( k <= 0 )

  {

    for ( j = 0; j < n; j++ )

    {

      x[j] = 1;

    }

    k = 1;

    return;

  }

  for ( i = n-1; 0 <= i; i-- )

  {

    if ( x[i] < m )

    {

      x[i] = x[i] + 1;

      for ( j = i+1; j < n; j++ )

      {

        x[j] = x[i];

      }

      k = k + 1;

      return;

    }

  }

  k = 0;

  for ( j = 0; j < n; j++ )

  {

    x[j] = 0;

  }

  return;

}

void tuple_next2 ( int n, int xmin[], int xmax[], int x[], int &rank )

{

  int i;

  int test;

  if ( rank < 0 )

  {

    cerr << "\n";

    cerr << "TUPLE_NEXT2 - Fatal error!\n";

    cerr << "  Illegal value of RANK = " << rank << "\n";

    exit ( 1 );

  }

  test = 1;

  for ( i = 0; i < n; i++ )

  {

    test = test * ( 1 + abs ( xmax[i] - xmin[i] ) );

  }

  if ( test < rank )

  {

    cerr << "\n";

    cerr << "TUPLE_NEXT2 - Fatal error!\n";

    cerr << "  Illegal value of RANK = " << rank << "\n";

    exit ( 1 );

  }

  if ( rank == 0 )

  {

    for ( i = 0; i < n; i++ )

    {

      x[i] = xmin[i];

    }

    rank = 1;

    return;

  }

  rank = rank + 1;

  i = n - 1;

  for ( ; ; )

  {

    if ( x[i] != xmax[i] )

    {

      if ( xmin[i] < xmax[i] )

      {

        x[i] = x[i] + 1;

      }

      else

      {

        x[i] = x[i] - 1;

      }

      break;

    }

    x[i] = xmin[i];

    if ( i == 0 )

    {

      rank = 0;

      break;

    }

    i = i - 1;

  }

  return;

}

bool ubvec_add ( int n, int bvec1[], int bvec2[], int bvec3[] )

{

  int base = 2;

  int i;

  bool overflow;

  overflow = false;

  for ( i = 0; i < n; i++ )

  {

    bvec3[i] = bvec1[i] + bvec2[i];

  }

  for ( i = n - 1; 0 <= i; i-- )

  {

    while ( base <= bvec3[i] )

    {

      bvec3[i] = bvec3[i] - base;

      if ( 0 < i )

      {

        bvec3[i-1] = bvec3[i-1] + 1;

      }

      else

      {

        overflow = true;

      }

    }

  }

  return overflow;

}

unsigned int ubvec_to_ui4 ( int n, int bvec[] )

{

  int base = 2;

  int i;

  unsigned int ui4;

  ui4 = 0;

  for ( i = 0; i < n; i++ )

  {

    ui4 = base * ui4 + bvec[i];

  }

  return ui4;

}

void ui4_to_ubvec ( unsigned int ui4, int n, int bvec[] )

{

  int base = 2;

  int i;

  for ( i = n - 1; 0 <= i; i-- )

  {

    bvec[i] = ui4 % base;

    ui4 = ui4 / base;

  }

  return;

}

void vec_colex_next ( int dim_num, int base, int a[], bool &more )

{

  int i;

  if ( !more )

  {

    for ( i = 0; i < dim_num; i++ )

    {

      a[i] = 0;

    }

    more = true;

  }

  else

  {

    for ( i = 0; i < dim_num; i++ )

    {

      a[i] = a[i] + 1;

      if ( a[i] < base )

      {

        return;

      }

      a[i] = 0;

    }

    more = false;

  }

  return;

}

void vec_colex_next2 ( int dim_num, int base[], int a[], bool &more )

{

  int i;

  if ( !more )

  {

    for ( i = 0; i < dim_num; i++ )

    {

      a[i] = 0;

    }

    more = true;

  }

  else

  {

    for ( i = 0; i < dim_num; i++ )

    {

      a[i] = a[i] + 1;

      if ( a[i] < base[i] )

      {

        return;

      }

      a[i] = 0;

    }

    more = false;

  }

  return;

}

void vec_colex_next3 ( int dim_num, int base[], int a[], bool &more )

{

  int i;

  if ( !more )

  {

    for ( i = 0; i < dim_num; i++ )

    {

      a[i] = 1;

    }

    more = true;

  }

  else

  {

    for ( i = 0; i < dim_num; i++ )

    {

      a[i] = a[i] + 1;

      if ( a[i] <= base[i] )

      {

        return;

      }

      a[i] = 1;

    }

    more = false;

  }

  return;

}

void vec_gray_next ( int n, int base[], int a[], bool &done, int &change )

{

  static int *active = NULL;

  int i;

  static int *dir = NULL;

  if ( done )

  {

    done = false;

    for ( i = 0; i < n; i++ )

    {

      a[i] = 0;

    }

    if ( active )

    {

      delete [] active;

    }

    active = new int[n];

    if ( dir )

    {

      delete [] dir;

    }

    dir = new int[n];

    for ( i = 0; i < n; i++ )

    {

      dir[i] = 1;

    }

    for ( i = 0; i < n; i++ )

    {

      active[i] = 1;

    }

    for ( i = 0; i < n; i++ )

    {

      if ( base[i] < 1 )

      {

        cerr << "\n";

        cerr << "VEC_GRAY_NEXT - Warning\n";

        cerr << "  For index I = " << i << "\n";

        cerr << "  the nonpositive value of BASE[I] = " << base[i] << "\n";

        cerr << "  which was reset to 1!\n";

        base[i] = 1;

        active[i] = 0;

      }

      else if ( base[i] == 1 )

      {

        active[i] = 0;

      }

    }

    change = 0;

    return;

  }

  change = -1;

  for ( i = 0; i < n; i++ )

  {

    if ( active[i] != 0 )

    {

      change = i;

    }

  }

  if ( change == -1 )

  {

    delete [] dir;

    dir = NULL;

    delete [] active;

    active = NULL;

    done = true;

    return;

  }

  a[change] = a[change] + dir[change];

  if ( a[change] == 0 || a[change] == base[change] - 1 )

  {

    dir[change] = -dir[change];

    active[change] = 0;

  }

  for ( i = change + 1; i < n; i++ )

  {

    if ( 1 < base[i] )

    {

      active[i] = 1;

    }

  }

  return;

}

int vec_gray_rank ( int n, int base[], int a[] )

{

  int c;

  int i;

  int rank;

  rank = 0;

  for ( i = 0; i < n; i++ )

  {

    if ( ( rank % 2 ) == 1 )

    {

      c = base[i] - a[i] - 1;

    }

    else

    {

      c = a[i];

    }

    rank = base[i] * rank + c;

  }

  rank = rank + 1;

  return rank;

}

void vec_gray_unrank ( int n, int base[], int rank, int a[] )

{

  int i;

  int s;

  s = rank - 1;

  for ( i = n-1; 0 <= i; i-- )

  {

    a[i] = s % base[i];

    s = s / base[i];

    if ( ( s % 2 ) == 1 )

    {

      a[i] = base[i] - a[i] - 1;

    }

  }

  return;

}

void vec_lex_next ( int dim_num, int base, int a[], bool &more )

{

  int i;

  if ( !more )

  {

    for ( i = 0; i < dim_num; i++ )

    {

      a[i] = 0;

    }

    more = true;

  }

  else

  {

    for ( i = dim_num - 1; 0 <= i; i-- )

    {

      a[i] = a[i] + 1;

      if ( a[i] < base )

      {

        return;

      }

      a[i] = 0;

    }

    more = false;

  }

  return;

}

void vec_random ( int n, int base, int &seed, int a[] )

{

  int i;

  for ( i = 0; i < n; i++ )

  {

    a[i] = i4_uniform_ab ( 0, base-1, seed );

  }

  return;

}

void vector_constrained_next ( int n, int x_min[], int x_max[], int x[], 

  int &constraint, bool &more )

{

  int i;

  int j;

  static int x_prod = -1;

  if ( !more )

  {

    for ( j = 0; j < n; j++ )

    {

      x[j] = x_min[j];

    }

    x_prod = 1;

    for ( j = 0; j < n; j++ )

    {

      x_prod = x_prod * x_max[j];

    }

    constraint = 0;

    for ( j = 0; j < n; j++ )

    {

      constraint = constraint + ( ( x[j] - 1 ) * ( x_prod / x_max[j] ) );

    }

    if ( x_prod < constraint )

    {

      more = false;

    }

    else

    {

      more = true;

    }

    return;

  }

  else

  {

    i = 0;

    for ( ; ; )

    {

      if ( x[i] < x_max[i] )

      {

        x[i] = x[i] + 1;

        constraint = 0;

        for ( j = 0; j < n; j++ )

        {

          constraint = constraint + ( ( x[j] - 1 ) * ( x_prod / x_max[j] ) );

        }

        if ( constraint <= x_prod )

        {

          break;

        }

      }

      x[i] = x_min[i];

      i = i + 1;

      if ( n <= i )

      {

        more = false;

        break;

      }

    }

  }

  return;

}

void vector_constrained_next2 ( int n, int x_min[], int x_max[], int x[], 

  int &constraint, bool &more )

{

  int i;

  int j;

  static int x_prod = -1;

  if ( !more )

  {

    for ( j = 0; j < n; j++ )

    {

      x[j] = x_min[j];

    }

    x_prod = 1;

    for ( j = 0; j < n; j++ )

    {

      x_prod = x_prod * x_max[j];

    }

    constraint = 0;

    for ( j = 0; j < n; j++ )

    {

      constraint = constraint + ( x[j] * ( x_prod / x_max[j] ) );

    }

    if ( x_prod < constraint )

    {

      more = false;

    }

    else

    {

      more = true;

    }

    return;

  }

  else

  {

    i = 0;

    for ( ; ; )

    {

      if ( x[i] < x_max[i] )

      {

        x[i] = x[i] + 1;

        constraint = 0;

        for ( j = 0; j < n; j++ )

        {

          constraint = constraint + ( x[j] * ( x_prod / x_max[j] ) );

        }

        if ( constraint <= x_prod )

        {

          break;

        }

      }

      x[i] = x_min[i];

      i = i + 1;

      if ( n <= i )

      {

        more = false;

        break;

      }

    }

  }

  return;

}

void vector_constrained_next3 ( int n, int x_min[], int x_max[], int x[], 

  double &constraint, bool &more )

{

  int i;

  int j;

  if ( !more )

  {

    for ( j = 0; j < n; j++ )

    {

      x[j] = x_min[j];

    }

    constraint = 0.0;

    for ( j = 0; j < n; j++ )

    {

      constraint = constraint + ( double ) x[j] / ( double ) x_max[j];

    }

    if ( 1.0 < constraint )

    {

      more = false;

    }

    else

    {

      more = true;

    }

    return;

  }

  else

  {

    i = 0;

    for ( ; ; )

    {

      if ( x[i] < x_max[i] )

      {

        x[i] = x[i] + 1;

        constraint = 0;

        for ( j = 0; j < n; j++ )

        {

          constraint = constraint + ( double ) x[j] / ( double ) x_max[j];

        }

        if ( constraint <= 1.0 )

        {

          break;

        }

      }

      x[i] = x_min[i];

      i = i + 1;

      if ( n <= i )

      {

        more = false;

        break;

      }

    }

  }

  return;

}

void vector_constrained_next4 ( int n, double alpha[], int x_min[], 

  int x_max[], int x[], double q, bool &more )

{

  int i;

  int j;

  double total;

  if ( !more )

  {

    for ( j = 0; j < n; j++ )

    {

      x[j] = x_min[j];

    }

    total = 0.0;

    for ( j = 0; j < n; j++ )

    {

      total = total + alpha[j] * ( double ) x[j];

    }

    if ( q < total )

    {

      more = false;

    }

    else

    {

      more = true;

    }

    return;

  }

  else

  {

    i = 0;

    for ( ; ; )

    {

      if ( x[i] < x_max[i] )

      {

        x[i] = x[i] + 1;

        total = 0;

        for ( j = 0; j < n; j++ )

        {

          total = total + alpha[j] * ( double ) x[j];

        }

        if ( total <= q )

        {

          break;

        }

      }

      x[i] = x_min[i];

      i = i + 1;

      if ( n <= i )

      {

        more = false;

        break;

      }

    }

  }

  return;

}

void vector_constrained_next5 ( int n, int x[], int sum_min, int sum_max, 

  bool &more )

{

  static int base = 0;

  int i;

  int j;

  if ( !more )

  {

    if ( sum_max < n )

    {

      more = false;

      return;

    }

    if ( sum_max < sum_min )

    {

      more = false;

      return;

    }

    more = true;

    base = sum_min;

    if ( base < n )

    {

      base = n;

    }

    x[0] = base - n + 1;

    for ( i = 1; i < n; i++ )

    {

      x[i] = 1;

    }

    return;

  }

  else

  {

    for ( i = n-2; 0 <= i; i-- )

    {

      if ( 1 < x[i] )

      {

        x[i]   = x[i]   - 1;

        x[i+1] = x[i+1] + 1;

        for ( j = i+2; j < n; j++ )

        {

          if ( 1 < x[j] ) 

          {

            x[i+1] = x[i+1] + x[j] - 1;

            x[j] = 1;

          }

        }

        return;

      }

    }

    if ( base < sum_max )

    {

      base = base + 1;

      x[0] = base - n + 1;

      for ( i = 1; i < n; i++ )

      {

        x[i] = 1;

      }

      return;

    }

    more = false;

  }

  return;

}

void vector_constrained_next6 ( int n, double alpha[], int x_min[], 

  int x_max[], int x[], double q_min, double q_max, bool &more )

{

  int i;

  int j;

  double total;

  if ( !more )

  {

    more = true;

    for ( i = 0; i < n; i++ )

    {

      x[i] = x_min[i];

    }

    total = 0.0;

    for ( i = 0; i < n; i++ )

    {

      total = total + alpha[i] * ( double ) ( x[i] );

    }

    if ( q_min <= total && total <= q_max )

    {

      return;

    }

  }

  for ( ; ; )

  {

    j = n - 1;

    for ( ; ; )

    {

      if ( x[j] < x_max[j] )

      {

        break;

      }

      if ( j <= 0 )

      {

        more = false;

        return;

      }

      j = j - 1;

    }

    x[j] = x[j] + 1;

    for ( i = j + 1; i < n; i++ )

    {

      x[i] = x_min[i];

    }

    total = 0.0;

    for ( i = 0; i < n; i++ )

    {

      total = total + alpha[i] * ( double ) ( x[i] );

    }

    if ( q_min <= total && total <= q_max )

    {

      break;

    }

  }

  return;

}

void vector_constrained_next7 ( int n, double level_weight[], int x_max[], 

  int x[], double q_min, double q_max, bool &more )

{

  int i;

  int j;

  double total;

  if ( !more )

  {

    more = true;

    for ( i = 0; i < n; i++ )

    {

      x[i] = 0;

    }

    total = 0.0;

    for ( i = 0; i < n; i++ )

    {

      total = total + level_weight[i] * ( double ) ( x[i] );

    }

    if ( q_min < total && total <= q_max )

    {

      return;

    }

  }

  for ( ; ; )

  {

    j = n - 1;

    for ( ; ; )

    {

      if ( x[j] < x_max[j] )

      {

        break;

      }

      if ( j <= 0 )

      {

        more = false;

        return;

      }

      j = j - 1;

    }

    x[j] = x[j] + 1;

    for ( i = j + 1; i < n; i++ )

    {

      x[i] = 0;

    }

    total = 0.0;

    for ( i = 0; i < n; i++ )

    {

      total = total + level_weight[i] * ( double ) ( x[i] );

    }

    if ( q_min < total && total <= q_max )

    {

      break;

    }

  }

  return;

}

void vector_next ( int n, int x_min[], int x_max[], int x[], bool &more )

{

  int i;

  if ( !more )

  {

    for ( i = 0; i < n; i++ )

    {

      x[i] = x_min[i];

    }

    more = true;

  }

  else

  {

    i = 0;

    for ( ; ; )

    {

      if ( x[i] < x_max[i] )

      {

        x[i] = x[i] + 1;

        break;

      }

      x[i] = x_min[i];

      i = i + 1;

      if ( n <= i )

      {

        more = false;

        break;

      }

    }

  }

  return;

}

int ytb_enum ( int n )

{

  int a1;

  int a2;

  int a3;

  int i;

  int num;

  if ( n <= 0 )

  {

    num = 0;

  }

  else if ( n == 1 )

  {

    num = 1;

  }

  else if ( n == 2 )

  {

    num = 2;

  }

  else

  {

    a2 = 1;

    a3 = 2;

    for ( i = 3; i <= n; i++ )

    {

      a1 = a2;

      a2 = a3;

      a3 = a2 + ( i - 1 ) * a1;

    }

    num = a3;

  }

  return num;

}

void ytb_next ( int n, int lambda[], int a[], bool &more )

{

  int i;

  int ir;

  int it;

  int j;

  int k;

  int isave;

  it = n;

  if ( more )

  {

    lambda[0] = 1;

    for ( i = 1; i < n; i++ )

    {

      lambda[i] = 0;

    }

    isave = 0;

    for ( i = 2; i <= n; i++ )

    {

      lambda[a[i-1]-1] = lambda[a[i-1]-1] + 1;

      if ( a[i-1] < a[i-2] )

      {

        isave = i;

        break;

      }

    }

    if ( isave == 0 )

    {

      more = false;

      return;

    }

    it = lambda[a[isave-1]];

    for ( i = n; 1 <= i; i-- )

    {

      if ( lambda[i-1] == it )

      {

        a[isave-1] = i;

        lambda[i-1] = lambda[i-1] - 1;

        it = isave - 1;

        break;

      }

    }

  }

  k = 1;

  ir = 1;

  for ( ; ; )

  {

    if ( n < ir )

    {

      break;

    }

    if ( lambda[ir-1] != 0 )

    {

      a[k-1] = ir;

      lambda[ir-1] = lambda[ir-1] - 1;

      k = k + 1;

      ir = ir + 1;

      continue;

    }

    if ( it < k )

    {

      break;

    }

    ir = 1;

  }

  if ( n == 1 )

  {

    more = false;

    return;

  }

  for ( j = 1; j < n; j++ )

  {

    if ( a[j] < a[j-1] )

    {

      more = true;

      return;

    }

  }

  more = false;

  return;

}

void ytb_print ( int n, int a[], string title )

{

  int j;

  int *jarray;

  int row_i;

  int row_length;

  jarray = new int[n];

  cout << "\n";

  cout << title << "\n";

  cout << "\n";

  row_i = 0;

  for ( ; ; )

  {

    row_i = row_i + 1;

    row_length = 0;

    for ( j = 0; j < n; j++ )

    {

      if ( a[j] == row_i )

      {

        jarray[row_length] = j;

        row_length = row_length + 1;

      }

    }

    if ( row_length <= 0 )

    {

      break;

    }

    for ( j = 0; j < row_length; j++ )

    {

      cout << setw(6) << jarray[j]+1 << "  ";

    }

    cout << "\n";

  }

  delete [] jarray;

  return;

}

void ytb_random ( int n, int lambda[], int &seed, int a[] )

{

  int i;

  int ih;

  int j;

  int k;

  int m;

  for ( i = 0; i < n; i++ )

  {

    a[i] = 0;

  }

  i = 0;

  k = 0;

  for ( ; ; )

  {

    i = i + 1;

    for ( j = 0; j < lambda[i-1]; j++ )

    {

      a[j] = a[j] + 1;

      k = k + 1;

    }

    if ( n <= k )

    {

      break;

    }

  }

  for ( m = 1; m <= n; m++ )

  {

    for ( ; ; )

    {

      i = i4_uniform_ab ( 1, a[0], seed );

      j = i4_uniform_ab ( 1, lambda[0], seed );

      if ( i <= a[j-1] && j <= lambda[i-1] )

      {

        break;

      }

    }

    for ( ; ; )

    {

      ih = a[j-1] + lambda[i-1] - i - j;

      if ( ih == 0 )

      {

        break;

      }

      k = i4_uniform_ab ( 1, ih, seed );

      if ( k <= lambda[i-1] - j )

      {

        j = j + k;

      }

      else

      {

        i = k - lambda[i-1] + i + j;

      }

    }

    lambda[i-1] = lambda[i-1] - 1;

    a[j-1] = a[j-1] - 1;

    a[n-m] = i;

  }

  for ( i = 0; i < n; i++ )

  {

    lambda[a[i]-1] = lambda[a[i]-1] + 1;

  }

  return;

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/