
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <cmath>

# include <ctime>

# include <string>

using namespace std;

# include "wavelet.hpp"

double *cascade ( int n, int t_length, double t[], int c_length, double c[] )

{

  int i;

  int j;

  double *s;

  int s_length;

  int x_length;

  double *x;

  s_length = t_length;

  s = r8vec_copy_new ( t_length, t );

  for ( i = 0; i < n; i++ )

  {

    x_length = s_length * 2 - 1;

    x = new double[x_length];

    

    j = 0;

    for ( i = 0; i < x_length; i = i + 2 )

    {

      x[i] = s[j];

      j = j + 1;

    }

    for ( i = 1; i < x_length - 1; i = i + 2 )

    {

      x[i] = 0.0;

    }

    delete [] s;

    s = r8vec_convolution ( x_length, x, c_length, c );

    delete [] x;

    s_length = x_length + c_length - 1;

  }

  return s;

}

double *daub_coefficients ( int n )

{

  double *c;

  static double c02[2] = {

      7.071067811865475E-01, 

      7.071067811865475E-01 };

  static double c04[4] = {

      0.4829629131445341E+00, 

      0.8365163037378079E+00, 

      0.2241438680420133E+00, 

    - 0.1294095225512603E+00 };

  static double c06[6] = {

      0.3326705529500826E+00, 

      0.8068915093110925E+00, 

      0.4598775021184915E+00, 

    - 0.1350110200102545E+00, 

    - 0.8544127388202666E-01, 

      0.3522629188570953E-01 };

  static double c08[8] = {

      0.2303778133088965E+00, 

      0.7148465705529156E+00, 

      0.6308807679298589E+00, 

     -0.2798376941685985E-01, 

     -0.1870348117190930E+00, 

      0.3084138183556076E-01, 

      0.3288301166688519E-01, 

     -0.1059740178506903E-01 };

  static double c10[10] = {

      0.1601023979741929E+00, 

      0.6038292697971896E+00, 

      0.7243085284377729E+00, 

      0.1384281459013207E+00, 

     -0.2422948870663820E+00, 

     -0.3224486958463837E-01, 

      0.7757149384004571E-01, 

     -0.6241490212798274E-02, 

     -0.1258075199908199E-01, 

      0.3335725285473771E-02 };

  static double c12[12] = {

      0.1115407433501094E+00, 

      0.4946238903984530E+00, 

      0.7511339080210953E+00, 

      0.3152503517091976E+00, 

     -0.2262646939654398E+00, 

     -0.1297668675672619E+00, 

      0.9750160558732304E-01, 

      0.2752286553030572E-01, 

     -0.3158203931748602E-01, 

      0.5538422011614961E-03, 

      0.4777257510945510E-02, 

     -0.1077301085308479E-02 };

  static double c14[14] = {

       7.785205408500917E-02, 

       3.965393194819173E-01, 

       7.291320908462351E-01, 

       4.697822874051931E-01, 

      -1.439060039285649E-01, 

      -2.240361849938749E-01, 

       7.130921926683026E-02, 

       8.061260915108307E-02, 

      -3.802993693501441E-02, 

      -1.657454163066688E-02, 

       1.255099855609984E-02, 

       4.295779729213665E-04, 

      -1.801640704047490E-03, 

       3.537137999745202E-04 };

  static double c16[16] = {

       5.441584224310400E-02, 

       3.128715909142999E-01, 

       6.756307362972898E-01, 

       5.853546836542067E-01, 

      -1.582910525634930E-02, 

      -2.840155429615469E-01, 

       4.724845739132827E-04, 

       1.287474266204784E-01, 

      -1.736930100180754E-02, 

      -4.408825393079475E-02, 

       1.398102791739828E-02, 

       8.746094047405776E-03, 

      -4.870352993451574E-03, 

      -3.917403733769470E-04, 

       6.754494064505693E-04, 

      -1.174767841247695E-04 };

  static double c18[18] = {

      3.807794736387834E-02, 

       2.438346746125903E-01, 

       6.048231236901111E-01, 

       6.572880780513005E-01, 

       1.331973858250075E-01, 

      -2.932737832791749E-01, 

      -9.684078322297646E-02, 

       1.485407493381063E-01, 

       3.072568147933337E-02, 

      -6.763282906132997E-02, 

       2.509471148314519E-04, 

       2.236166212367909E-02, 

      -4.723204757751397E-03, 

      -4.281503682463429E-03, 

       1.847646883056226E-03, 

       2.303857635231959E-04, 

      -2.519631889427101E-04, 

       3.934732031627159E-05 };

  static double c20[20] = {

       2.667005790055555E-02, 

       1.881768000776914E-01, 

       5.272011889317255E-01, 

       6.884590394536035E-01, 

       2.811723436605774E-01, 

      -2.498464243273153E-01, 

      -1.959462743773770E-01, 

       1.273693403357932E-01, 

       9.305736460357235E-02, 

      -7.139414716639708E-02, 

      -2.945753682187581E-02, 

       3.321267405934100E-02, 

       3.606553566956169E-03, 

      -1.073317548333057E-02, 

       1.395351747052901E-03, 

       1.992405295185056E-03, 

      -6.858566949597116E-04, 

      -1.164668551292854E-04, 

       9.358867032006959E-05, 

      -1.326420289452124E-05 };

  if ( n == 2 )

  {

    c = r8vec_copy_new ( n, c02 );

  }

  else if ( n == 4 )

  {

    c = r8vec_copy_new ( n, c04 );

  }

  else if ( n == 6 )

  {

    c = r8vec_copy_new ( n, c06 );

  }

  else if ( n == 8 )

  {

    c = r8vec_copy_new ( n, c08 );

  }

  else if ( n == 10 )

  {

    c = r8vec_copy_new ( n, c10 );

  }

  else if ( n == 12 )

  {

    c = r8vec_copy_new ( n, c12 );

  }

  else if ( n == 14 )

  {

    c = r8vec_copy_new ( n, c14 );

  }

  else if ( n == 16 )

  {

    c = r8vec_copy_new ( n, c16 );

  }

  else if ( n == 18 )

  {

    c = r8vec_copy_new ( n, c18 );

  }

  else if ( n == 20 )

  {

    c = r8vec_copy_new ( n, c20 );

  }

  else

  {

    cerr << "\n";

    cerr << "DAUB_COEFFICIENTS - Fatal error!\n";

    cerr << "  Value of N = " << n << "\n";

    cerr << "  Legal values are 2, 4, 6, 8, 10, 12, 14, 16, 18, 20.\n";

    exit ( 1 );

  }

  return c;

}

double *daub2_matrix ( int n )

{

  double *a;

  double *c;

  int i;

  int m;

  if ( n < 2 || ( n % 2 ) != 0 )

  {

    cerr << "\n";

    cerr << "DAUB2_MATRIX - Fatal error!\n";

    cerr << "  Order N must be at least 2 and a multiple of 2.\n";

    exit ( 1 );

  }

  a = r8mat_zero_new ( n, n );

  c = daub_coefficients ( 2 );

  for ( i = 0; i < n - 1; i = i + 2 )

  {

    a[i+i*n]       =   c[0];

    a[i+(i+1)*n]   =   c[1];

    a[i+1+i*n]     =   c[1];

    a[i+1+(i+1)*n] = - c[0];

  }

  delete [] c;

  return a;

}

double daub2_scale ( int n, double x )

{

  double c[2] = {

    7.071067811865475E-01, 

    7.071067811865475E-01 };

  double y;

  if ( 0 < n )

  {

    y = sqrt ( 2.0 ) * 

        ( c[0] * daub2_scale ( n - 1, 2.0 * x       ) 

        + c[1] * daub2_scale ( n - 1, 2.0 * x - 1.0 ) );

  }

  else if ( 0.0 <= x && x < 1.0 )

  {

    y = 1.0;

  }

  else

  {

    y = 0.0;

  }

  return y;

}

double *daub2_transform ( int n, double x[] )

{

  double c[2] = {

    7.071067811865475E-01, 

    7.071067811865475E-01 };

  int i;

  int m;

  double *y;

  double *z;

  y = r8vec_copy_new ( n, x );

 

  z = new double[n];

  for ( i = 0; i < n; i++ )

  {

    z[i] = 0.0;

  }

  m = n;

  while ( 2 <= m )

  {

    m = m / 2;

    for ( i = 0; i < m; i++ )

    {

      z[i]   = c[0] * ( y[2*i] + y[2*i+1] );

      z[i+m] = c[1] * ( y[2*i] - y[2*i+1] );

    }

    for ( i = 0; i < 2 * m; i++ )

    {

      y[i] = z[i];

    }

  }

  delete [] z;

  return y;

}

double *daub2_transform_inverse ( int n, double y[] )

{

  double c[2] = {

    7.071067811865475E-01, 

    7.071067811865475E-01 };

  int i;

  int m;

  double *x;

  double *z;

  x = r8vec_copy_new ( n, y );

  z = new double[n];

  for ( i = 0; i < n; i++ )

  {

    z[i] = 0.0;

  } 

  m = 1;

  while ( m * 2 <= n )

  {

    for ( i = 0; i < m; i++ )

    {

      z[2*i]   = c[0] * ( x[i] + x[i+m] );

      z[2*i+1] = c[1] * ( x[i] - x[i+m] );

    }

    for ( i = 0; i < 2 * m; i++ )

    {

      x[i] = z[i];

    }

    m = m * 2;

  }

  delete [] z;

  return x;

}

double *daub4_matrix ( int n )

{

  double *a;

  double *c;

  int i;

  int j;

  if ( n < 4 || ( n % 2 ) != 0 )

  {

    cerr << "\n";

    cerr << "DAUB4_MATRIX - Fatal error!\n";

    cerr << "  Order N must be at least 4 and a multiple of 2.\n";

    exit ( 1 );

  }

  a = r8mat_zero_new ( n, n );

  c = daub_coefficients ( 4 );

  for ( i = 0; i < n - 1; i = i + 2 )

  {

    j = i;

    a[i+j*n] = c[0];

    j = i + 1;

    a[i+j*n] = c[1];

    j = i4_wrap ( i + 2, 0, n - 1 );

    a[i+j*n] = c[2];

    j = i4_wrap ( i + 3, 0, n - 1 );

    a[i+j*n] = c[3];

    j = i;

    a[i+1+j*n] =   c[3];

    j = i + 1;

    a[i+1+j*n] = - c[2];

    j = i4_wrap ( i + 2, 0, n - 1 );

    a[i+1+j*n] =   c[1];

    j = i4_wrap ( i + 3, 0, n - 1 );

    a[i+1+j*n] = - c[0];

  }

  delete [] c;

  return a;

}

double daub4_scale ( int n, double x )

{

  double c[4] = {

     0.4829629131445341E+00, 

     0.8365163037378079E+00, 

     0.2241438680420133E+00, 

    -0.1294095225512603E+00 };

  double y;

  if ( 0 < n )

  {

    y = sqrt ( 2.0 ) * 

        ( c[0] * daub4_scale ( n - 1, 2.0 * x       ) 

        + c[1] * daub4_scale ( n - 1, 2.0 * x - 1.0 ) 

        + c[2] * daub4_scale ( n - 1, 2.0 * x - 2.0 ) 

        + c[3] * daub4_scale ( n - 1, 2.0 * x - 3.0 ) );

  }

  else if ( 0.0 <= x && x < 1.0 )

  {

    y = 1.0;

  }

  else

  {

    y = 0.0;

  }

  return y;

}

double *daub4_transform ( int n, double x[] )

{

  double c[4] = {

     0.4829629131445341, 

     0.8365163037378079, 

     0.2241438680420133, 

    -0.1294095225512603 };

  int i;

  int j;

  int j0;

  int j1;

  int j2;

  int j3;

  int m;

  double *y;

  double *z;

  y = r8vec_copy_new ( n, x );

  z = new double[n];

  for ( i = 0; i < n; i++ )

  {

    z[i] = 0.0;

  }

  m = n;

  while ( 4 <= m )

  {

    i = 0;

    for ( j = 0; j < m - 1; j = j + 2 )

    {

      j0 = i4_wrap ( j,     0, m - 1 );

      j1 = i4_wrap ( j + 1, 0, m - 1 );

      j2 = i4_wrap ( j + 2, 0, m - 1 );

      j3 = i4_wrap ( j + 3, 0, m - 1 );

      z[i]     = c[0] * y[j0] + c[1] * y[j1] 

               + c[2] * y[j2] + c[3] * y[j3];

      z[i+m/2] = c[3] * y[j0] - c[2] * y[j1] 

               + c[1] * y[j2] - c[0] * y[j3];

      i = i + 1;

    }

    for ( i = 0; i < m; i++ )

    {

      y[i] = z[i];

    }

    m = m / 2;

  }

  delete [] z;

  return y;

}

double *daub4_transform_inverse ( int n, double y[] )

{

  double c[4] = {

     0.4829629131445341, 

     0.8365163037378079, 

     0.2241438680420133, 

    -0.1294095225512603 };

  int i;

  int i0;

  int i1;

  int i2;

  int i3;

  int j;

  int m;

  double *x;

  double *z;

  x = r8vec_copy_new ( n, y );

  z = new double[n];

  for ( i = 0; i < n; i++ )

  {

    z[i] = 0.0;

  }

  m = 4;

  while ( m <= n )

  {

    j = 0;

    for ( i = 0; i < m / 2; i++ )

    { 

      i0 = i4_wrap ( i - 1,          0,     m / 2 - 1 );

      i2 = i4_wrap ( i,              0,     m / 2 - 1 );

      i1 = i4_wrap ( i + m / 2 - 1,  m / 2, m - 1 );

      i3 = i4_wrap ( i + m / 2,      m / 2, m - 1 );

      z[j]   = c[2] * x[i0] + c[1] * x[i1] 

             + c[0] * x[i2] + c[3] * x[i3];

      z[j+1] = c[3] * x[i0] - c[0] * x[i1] 

             + c[1] * x[i2] - c[2] * x[i3];

      j = j + 2;

    }

    for ( i = 0; i < m; i++ )

    {

      x[i] = z[i];

    }

    m = m * 2;

  }

  delete [] z;

  return x;

}

double *daub6_matrix ( int n )

{

  double *a;

  double *c;

  int i;

  int j;

  if ( n < 6 || ( n % 2 ) != 0 )

  {

    cerr << "\n";

    cerr << "DAUB6_MATRIX - Fatal error!\n";

    cerr << "  Order N must be at least 6 and a multiple of 2.\n";

    exit ( 1 );

  }

  a = r8mat_zero_new ( n, n );

  c = daub_coefficients ( 6 );

  for ( i = 0; i < n - 1; i = i + 2 )

  {

    j = i;

    a[i+j*n] = c[0];

    j = i + 1;

    a[i+j*n] = c[1];

    j = i4_wrap ( i + 2, 0, n - 1 );

    a[i+j*n] = c[2];

    j = i4_wrap ( i + 3, 0, n - 1 );

    a[i+j*n] = c[3];

    j = i4_wrap ( i + 4, 0, n - 1 );

    a[i+j*n] = c[4];

    j = i4_wrap ( i + 5, 0, n - 1 );

    a[i+j*n] = c[5];

    j = i;

    a[i+1+j*n] =   c[5];

    j = i + 1;

    a[i+1+j*n] = - c[4];

    j = i4_wrap ( i + 2, 0, n - 1 );

    a[i+1+j*n] =   c[3];

    j = i4_wrap ( i + 3, 0, n - 1 );

    a[i+1+j*n] = - c[2];

    j = i4_wrap ( i + 4, 0, n - 1 );

    a[i+1+j*n] =   c[1];

    j = i4_wrap ( i + 5, 0, n - 1 );

    a[i+1+j*n] = - c[0];

  }

  delete [] c;

  return a;

}

double daub6_scale ( int n, double x )

{

  double c[6] = {

     0.3326705529500826E+00, 

     0.8068915093110925E+00, 

     0.4598775021184915E+00, 

   - 0.1350110200102545E+00, 

   - 0.08544127388202666E+00, 

     0.03522629188570953E+00 };

  double y;

  if ( 0 < n )

  {

    y = sqrt ( 2.0 ) * 

        ( c[0] * daub6_scale ( n - 1, 2.0 * x       ) 

        + c[1] * daub6_scale ( n - 1, 2.0 * x - 1.0 ) 

        + c[2] * daub6_scale ( n - 1, 2.0 * x - 2.0 ) 

        + c[3] * daub6_scale ( n - 1, 2.0 * x - 3.0 ) 

        + c[4] * daub6_scale ( n - 1, 2.0 * x - 4.0 ) 

        + c[5] * daub6_scale ( n - 1, 2.0 * x - 5.0 ) );

  }

  else if ( 0.0 <= x && x < 1.0 )

  {

    y = 1.0;

  }

  else

  {

    y = 0.0;

  }

  return y;

}

double *daub6_transform ( int n, double x[] )

{

  double c[6] = {

     0.3326705529500826, 

     0.8068915093110925, 

     0.4598775021184915, 

   - 0.1350110200102545, 

   - 0.08544127388202666, 

     0.03522629188570953 };

  int i;

  int j;

  int j0;

  int j1;

  int k;

  int m;

  int p = 5;

  int q;

  double *y;

  double *z;

  y = r8vec_copy_new ( n, x );

  z = new double[n];

  m = n;

  q = ( p - 1 ) / 2;

  while ( 4 <= m )

  {

    for ( i = 0; i < m; i++ )

    {

      z[i] = 0.0;

    }

    i = 0;

    for ( j = 0; j < m - 1; j = j + 2 )

    {

      for ( k = 0; k < p; k = k + 2 )

      {

        j0 = i4_wrap ( j + k,     0, m - 1 );

        j1 = i4_wrap ( j + k + 1, 0, m - 1 );

        z[i]     = z[i]     + c[  k] * y[j0] + c[  k+1] * y[j1];

        z[i+m/2] = z[i+m/2] + c[p-k] * y[j0] - c[p-k-1] * y[j1];

      }

      i = i + 1;

    }

    for ( i = 0; i < m; i++ )

    {

      y[i] = z[i];

    }

    m = m / 2;

  }

  delete [] z;

  return y;

}

double *daub6_transform_inverse ( int n, double y[] )

{

  double c[6] = {

     0.3326705529500826, 

     0.8068915093110925, 

     0.4598775021184915, 

   - 0.1350110200102545, 

   - 0.08544127388202666, 

     0.03522629188570953 };

  int i;

  int i0;

  int i1;

  int j;

  int k;

  int m;

  int p = 5;

  int q;

  double *x;

  double *z;

  x = r8vec_copy_new ( n, y );

  z = new double[n];

  m = 4;

  q = ( p - 1 ) / 2;

  while ( m <= n )

  {

    for ( i = 0; i < n; i++ )

    {

      z[i] = 0.0;

    }

    j = 0;

    for ( i = - q; i < m / 2 - q; i++ )

    {

      for ( k = 0; k < p; k = k + 2 )

      {      

        i0 = i4_wrap ( i         + k / 2,     0,     m / 2 - 1 );

        i1 = i4_wrap ( i + m / 2 + k / 2,     m / 2, m     - 1 );

        z[j]   = z[j]   + c[p-k-1] * x[i0] + c[k+1] * x[i1];

        z[j+1] = z[j+1] + c[p-k]   * x[i0] - c[k]   * x[i1];

      }

      j = j + 2;

    }

    for ( i = 0; i < m; i++ )

    {

      x[i] = z[i];

    }

    m = m * 2;

  }

  delete [] z;

  return x;

}

double *daub8_matrix ( int n )

{

  double *a;

  double *c;

  int i;

  int j;

  if ( n < 8 || ( n % 2 ) != 0 )

  {

    cerr << "\n";

    cerr << "DAUB8_MATRIX - Fatal error!\n";

    cerr << "  Order N must be at least 8 and a multiple of 2.\n";

    exit ( 1 );

  }

  a = r8mat_zero_new ( n, n );

  c = daub_coefficients ( 8 );

  for ( i = 0; i < n - 1; i = i + 2 )

  {

    j = i;

    a[i+j*n] = c[0];

    j = i + 1;

    a[i+j*n] = c[1];

    j = i4_wrap ( i + 2, 0, n - 1 );

    a[i+j*n] = c[2];

    j = i4_wrap ( i + 3, 0, n - 1 );

    a[i+j*n] = c[3];

    j = i4_wrap ( i + 4, 0, n - 1 );

    a[i+j*n] = c[4];

    j = i4_wrap ( i + 5, 0, n - 1 );

    a[i+j*n] = c[5];

    j = i4_wrap ( i + 6, 0, n - 1 );

    a[i+j*n] = c[6];

    j = i4_wrap ( i + 7, 0, n - 1 );

    a[i+j*n] = c[7];

    j = i;

    a[i+1+j*n] =   c[7];

    j = i + 1;

    a[i+1+j*n] = - c[6];

    j = i4_wrap ( i + 2, 0, n - 1 );

    a[i+1+j*n] =   c[5];

    j = i4_wrap ( i + 3, 0, n - 1 );

    a[i+1+j*n] = - c[4];

    j = i4_wrap ( i + 4, 0, n - 1 );

    a[i+1+j*n] =   c[3];

    j = i4_wrap ( i + 5, 0, n - 1 );

    a[i+1+j*n] = - c[2];

    j = i4_wrap ( i + 6, 0, n - 1 );

    a[i+1+j*n] =   c[1];

    j = i4_wrap ( i + 7, 0, n - 1 );

    a[i+1+j*n] = - c[0];

  }

  delete [] c;

  return a;

}

double daub8_scale ( int n, double x )

{

  double c[8] = {

    0.2303778133088964E+00, 

    0.7148465705529154E+00, 

    0.6308807679298587E+00, 

   -0.0279837694168599E+00, 

   -0.1870348117190931E+00, 

    0.0308413818355607E+00, 

    0.0328830116668852E+00, 

   -0.0105974017850690E+00  };

  double y;

  if ( 0 < n )

  {

    y = sqrt ( 2.0 ) * 

        ( c[0] * daub8_scale ( n - 1, 2.0 * x       ) 

        + c[1] * daub8_scale ( n - 1, 2.0 * x - 1.0 ) 

        + c[2] * daub8_scale ( n - 1, 2.0 * x - 2.0 ) 

        + c[3] * daub8_scale ( n - 1, 2.0 * x - 3.0 ) 

        + c[4] * daub8_scale ( n - 1, 2.0 * x - 4.0 ) 

        + c[5] * daub8_scale ( n - 1, 2.0 * x - 5.0 ) 

        + c[6] * daub8_scale ( n - 1, 2.0 * x - 6.0 ) 

        + c[7] * daub8_scale ( n - 1, 2.0 * x - 7.0 ) );

  }

  else if ( 0.0 <= x && x < 1.0 )

  {

    y = 1.0;

  }

  else

  {

    y = 0.0;

  }

  return y;

}

double *daub8_transform ( int n, double x[] )

{

  double c[8] = {

     0.2303778133088964, 

     0.7148465705529154, 

     0.6308807679298587, 

    -0.02798376941685985, 

    -0.1870348117190931, 

     0.03084138183556076, 

     0.03288301166688519, 

    -0.01059740178506903 };

  int i;

  int j;

  int j0;

  int j1;

  int k;

  int m;

  int p = 7;

  int q;

  double *y;

  double *z;

  y = r8vec_copy_new ( n, x );

  z = new double[n];

  m = n;

  q = ( p - 1 ) / 2;

  while ( 4 <= m )

  {

    for ( i = 0; i < m; i++ )

    {

      z[i] = 0.0;

    }

    i = 0;

    for ( j = 0; j < m - 1; j = j + 2 )

    {

      for ( k = 0; k < p; k = k + 2 )

      {

        j0 = i4_wrap ( j + k,     0, m - 1 );

        j1 = i4_wrap ( j + k + 1, 0, m - 1 );

        z[i]     = z[i]     + c[  k] * y[j0] + c[  k+1] * y[j1];

        z[i+m/2] = z[i+m/2] + c[p-k] * y[j0] - c[p-k-1] * y[j1];

      }

      i = i + 1;

    }

    for ( i = 0; i < m; i++ )

    {

      y[i] = z[i];

    }

    m = m / 2;

  }

  delete [] z;

  return y;

}

double *daub8_transform_inverse ( int n, double y[] )

{

  double c[8] = {

     0.2303778133088964, 

     0.7148465705529154, 

     0.6308807679298587, 

    -0.02798376941685985, 

    -0.1870348117190931, 

     0.03084138183556076, 

     0.03288301166688519, 

    -0.01059740178506903 };

  int i;

  int i0;

  int i1;

  int j;

  int k;

  int m;

  int p = 7;

  int q;

  double *x;

  double *z;

  x = r8vec_copy_new ( n, y );

  z = new double[n];

  m = 4;

  q = ( p - 1 ) / 2;

  while ( m <= n )

  {

    for ( i = 0; i < n; i++ )

    {

      z[i] = 0.0;

    }

    j = 0;

    for ( i = - q; i < m / 2 - q; i++ )

    {

      for ( k = 0; k < p; k = k + 2 )

      {      

        i0 = i4_wrap ( i         + k / 2,     0,     m / 2 - 1 );

        i1 = i4_wrap ( i + m / 2 + k / 2,     m / 2, m     - 1 );

        z[j]   = z[j]   + c[p-k-1] * x[i0] + c[k+1] * x[i1];

        z[j+1] = z[j+1] + c[p-k]   * x[i0] - c[k]   * x[i1];

      }

      j = j + 2;

    }

    for ( i = 0; i < m; i++ )

    {

      x[i] = z[i];

    }

    m = m * 2;

  }

  delete [] z;

  return x;

}

double *daub10_matrix ( int n )

{

  double *a;

  double *c;

  int i;

  int j;

  if ( n < 10 || ( n % 2 ) != 0 )

  {

    cerr << "\n";

    cerr << "DAUB10_MATRIX - Fatal error!\n";

    cerr << "  Order N must be at least 10 and a multiple of 2.\n";

    exit ( 1 );

  }

  a = r8mat_zero_new ( n, n );

  c = daub_coefficients ( 10 );

  for ( i = 0; i < n - 1; i = i + 2 )

  {

    j = i;

    a[i+j*n] = c[0];

    j = i + 1;

    a[i+j*n] = c[1];

    j = i4_wrap ( i + 2, 0, n - 1 );

    a[i+j*n] = c[2];

    j = i4_wrap ( i + 3, 0, n - 1 );

    a[i+j*n] = c[3];

    j = i4_wrap ( i + 4, 0, n - 1 );

    a[i+j*n] = c[4];

    j = i4_wrap ( i + 5, 0, n - 1 );

    a[i+j*n] = c[5];

    j = i4_wrap ( i + 6, 0, n - 1 );

    a[i+j*n] = c[6];

    j = i4_wrap ( i + 7, 0, n - 1 );

    a[i+j*n] = c[7];

    j = i4_wrap ( i + 8, 0, n - 1 );

    a[i+j*n] = c[8];

    j = i4_wrap ( i + 9, 0, n - 1 );

    a[i+j*n] = c[9];

    j = i;

    a[i+1+j*n] =   c[9];

    j = i + 1;

    a[i+1+j*n] = - c[8];

    j = i4_wrap ( i + 2, 0, n - 1 );

    a[i+1+j*n] =   c[7];

    j = i4_wrap ( i + 3, 0, n - 1 );

    a[i+1+j*n] = - c[6];

    j = i4_wrap ( i + 4, 0, n - 1 );

    a[i+1+j*n] =   c[5];

    j = i4_wrap ( i + 5, 0, n - 1 );

    a[i+1+j*n] = - c[4];

    j = i4_wrap ( i + 6, 0, n - 1 );

    a[i+1+j*n] =   c[3];

    j = i4_wrap ( i + 7, 0, n - 1 );

    a[i+1+j*n] = - c[2];

    j = i4_wrap ( i + 8, 0, n - 1 );

    a[i+1+j*n] =   c[1];

    j = i4_wrap ( i + 9, 0, n - 1 );

    a[i+1+j*n] = - c[0];

  }

  delete [] c;

  return a;

}

double daub10_scale ( int n, double x )

{

  double c[10] = {

    0.1601023979741929E+00, 

    0.6038292697971895E+00, 

    0.7243085284377726E+00, 

    0.1384281459013203E+00, 

   -0.2422948870663823E+00, 

   -0.0322448695846381E+00, 

    0.0775714938400459E+00, 

   -0.0062414902127983E+00, 

   -0.0125807519990820E+00, 

    0.0033357252854738E+00   };

  double y;

  if ( 0 < n )

  {

    y = sqrt ( 2.0 ) * 

        ( c[0] * daub10_scale ( n - 1, 2.0 * x       ) 

        + c[1] * daub10_scale ( n - 1, 2.0 * x - 1.0 ) 

        + c[2] * daub10_scale ( n - 1, 2.0 * x - 2.0 ) 

        + c[3] * daub10_scale ( n - 1, 2.0 * x - 3.0 ) 

        + c[4] * daub10_scale ( n - 1, 2.0 * x - 4.0 ) 

        + c[5] * daub10_scale ( n - 1, 2.0 * x - 5.0 ) 

        + c[6] * daub10_scale ( n - 1, 2.0 * x - 6.0 ) 

        + c[7] * daub10_scale ( n - 1, 2.0 * x - 7.0 ) 

        + c[8] * daub10_scale ( n - 1, 2.0 * x - 8.0 ) 

        + c[9] * daub10_scale ( n - 1, 2.0 * x - 9.0 ) );

  }

  else if ( 0.0 <= x && x < 1.0 )

  {

    y = 1.0;

  }

  else

  {

    y = 0.0;

  }

  return y;

}

double *daub10_transform ( int n, double x[] )

{

  double c[10] = {

     1.601023979741929E-01, 

     6.038292697971896E-01, 

     7.243085284377729E-01, 

     1.384281459013207E-01, 

    -2.422948870663820E-01, 

    -3.224486958463837E-02, 

     7.757149384004571E-02, 

    -6.241490212798274E-03, 

    -1.258075199908199E-02, 

     3.335725285473771E-03 };

  int i;

  int j;

  int j0;

  int j1;

  int k;

  int m;

  int p = 9;

  int q;

  double *y;

  double *z;

  y = r8vec_copy_new ( n, x );

  z = new double[n];

  m = n;

  q = ( p - 1 ) / 2;

  while ( 4 <= m )

  {

    for ( i = 0; i < m; i++ )

    {

      z[i] = 0.0;

    }

    i = 0;

    for ( j = 0; j < m - 1; j = j + 2 )

    {

      for ( k = 0; k < p; k = k + 2 )

      {

        j0 = i4_wrap ( j + k,     0, m - 1 );

        j1 = i4_wrap ( j + k + 1, 0, m - 1 );

        z[i]     = z[i]     + c[  k] * y[j0] + c[  k+1] * y[j1];

        z[i+m/2] = z[i+m/2] + c[p-k] * y[j0] - c[p-k-1] * y[j1];

      }

      i = i + 1;

    }

    for ( i = 0; i < m; i++ )

    {

      y[i] = z[i];

    }

    m = m / 2;

  }

  delete [] z;

  return y;

}

double *daub10_transform_inverse ( int n, double y[] )

{

  double c[10] = {

     1.601023979741929E-01, 

     6.038292697971896E-01, 

     7.243085284377729E-01, 

     1.384281459013207E-01, 

    -2.422948870663820E-01, 

    -3.224486958463837E-02, 

     7.757149384004571E-02, 

    -6.241490212798274E-03, 

    -1.258075199908199E-02, 

     3.335725285473771E-03 };

  int i;

  int i0;

  int i1;

  int j;

  int k;

  int m;

  int p = 9;

  int q;

  double *x;

  double *z;

  x = r8vec_copy_new ( n, y );

  z = new double[n];

  m = 4;

  q = ( p - 1 ) / 2;

  while ( m <= n )

  {

    for ( i = 0; i < n; i++ )

    {

      z[i] = 0.0;

    }

    j = 0;

    for ( i = - q; i < m / 2 - q; i++ )

    {

      for ( k = 0; k < p; k = k + 2 )

      {      

        i0 = i4_wrap ( i         + k / 2,     0,     m / 2 - 1 );

        i1 = i4_wrap ( i + m / 2 + k / 2,     m / 2, m     - 1 );

        z[j]   = z[j]   + c[p-k-1] * x[i0] + c[k+1] * x[i1];

        z[j+1] = z[j+1] + c[p-k]   * x[i0] - c[k]   * x[i1];

      }

      j = j + 2;

    }

    for ( i = 0; i < m; i++ )

    {

      x[i] = z[i];

    }

    m = m * 2;

  }

  delete [] z;

  return x;

}

double *daub12_matrix ( int n )

{

  double *a;

  double *c;

  int i;

  int j;

  if ( n < 12 || ( n % 2 ) != 0 )

  {

    cerr << "\n";

    cerr << "DAUB12_MATRIX - Fatal error!\n";

    cerr << "  Order N must be at least 12 and a multiple of 2.\n";

    exit ( 1 );

  }

  a = r8mat_zero_new ( n, n );

  c = daub_coefficients ( 12 );

  for ( i = 0; i < n - 1; i = i + 2 )

  {

    j = i;

    a[i+j*n] = c[0];

    j = i + 1;

    a[i+j*n] = c[1];

    j = i4_wrap ( i + 2, 0, n - 1 );

    a[i+j*n] = c[2];

    j = i4_wrap ( i + 3, 0, n - 1 );

    a[i+j*n] = c[3];

    j = i4_wrap ( i + 4, 0, n - 1 );

    a[i+j*n] = c[4];

    j = i4_wrap ( i + 5, 0, n - 1 );

    a[i+j*n] = c[5];

    j = i4_wrap ( i + 6, 0, n - 1 );

    a[i+j*n] = c[6];

    j = i4_wrap ( i + 7, 0, n - 1 );

    a[i+j*n] = c[7];

    j = i4_wrap ( i + 8, 0, n - 1 );

    a[i+j*n] = c[8];

    j = i4_wrap ( i + 9, 0, n - 1 );

    a[i+j*n] = c[9];

    j = i4_wrap ( i + 10, 0, n - 1 );

    a[i+j*n] = c[10];

    j = i4_wrap ( i + 11, 0, n - 1 );

    a[i+j*n] = c[11];

    j = i;

    a[i+1+j*n] =   c[11];

    j = i + 1;

    a[i+1+j*n] = - c[10];

    j = i4_wrap ( i + 2, 0, n - 1 );

    a[i+1+j*n] =   c[9];

    j = i4_wrap ( i + 3, 0, n - 1 );

    a[i+1+j*n] = - c[8];

    j = i4_wrap ( i + 4, 0, n - 1 );

    a[i+1+j*n] =   c[7];

    j = i4_wrap ( i + 5, 0, n - 1 );

    a[i+1+j*n] = - c[6];

    j = i4_wrap ( i + 6, 0, n - 1 );

    a[i+1+j*n] =   c[5];

    j = i4_wrap ( i + 7, 0, n - 1 );

    a[i+1+j*n] = - c[4];

    j = i4_wrap ( i + 8, 0, n - 1 );

    a[i+1+j*n] =   c[3];

    j = i4_wrap ( i + 9, 0, n - 1 );

    a[i+1+j*n] = - c[2];

    j = i4_wrap ( i + 10, 0, n - 1 );

    a[i+1+j*n] =   c[1];

    j = i4_wrap ( i + 11, 0, n - 1 );

    a[i+1+j*n] = - c[0];

  }

  delete [] c;

  return a;

}

double *daub12_transform ( int n, double x[] )

{

  double c[12] = {

    0.1115407433501095E+00, 

    0.4946238903984533E+00, 

    0.7511339080210959E+00, 

    0.3152503517091982E+00, 

   -0.2262646939654400E+00, 

   -0.1297668675672625E+00, 

    0.0975016055873225E+00, 

    0.0275228655303053E+00, 

   -0.0315820393174862E+00, 

    0.0005538422011614E+00, 

    0.0047772575109455E+00, 

   -0.0010773010853085E+00 };

  int i;

  int j;

  int j0;

  int j1;

  int k;

  int m;

  int p = 11;

  int q;

  double *y;

  double *z;

  y = r8vec_copy_new ( n, x );

  z = new double[n];

  m = n;

  q = ( p - 1 ) / 2;

  while ( 4 <= m )

  {

    for ( i = 0; i < m; i++ )

    {

      z[i] = 0.0;

    }

    i = 0;

    for ( j = 0; j < m - 1; j = j + 2 )

    {

      for ( k = 0; k < p; k = k + 2 )

      {

        j0 = i4_wrap ( j + k,     0, m - 1 );

        j1 = i4_wrap ( j + k + 1, 0, m - 1 );

        z[i]     = z[i]     + c[  k] * y[j0] + c[  k+1] * y[j1];

        z[i+m/2] = z[i+m/2] + c[p-k] * y[j0] - c[p-k-1] * y[j1];

      }

      i = i + 1;

    }

    for ( i = 0; i < m; i++ )

    {

      y[i] = z[i];

    }

    m = m / 2;

  }

  delete [] z;

  return y;

}

double *daub12_transform_inverse ( int n, double y[] )

{

  double c[12] = {

    0.1115407433501095E+00, 

    0.4946238903984533E+00, 

    0.7511339080210959E+00, 

    0.3152503517091982E+00, 

   -0.2262646939654400E+00, 

   -0.1297668675672625E+00, 

    0.0975016055873225E+00, 

    0.0275228655303053E+00, 

   -0.0315820393174862E+00, 

    0.0005538422011614E+00, 

    0.0047772575109455E+00, 

   -0.0010773010853085E+00 };

  int i;

  int i0;

  int i1;

  int j;

  int k;

  int m;

  int p = 11;

  int q;

  double *x;

  double *z;

  x = r8vec_copy_new ( n, y );

  z = new double[n];

  m = 4;

  q = ( p - 1 ) / 2;

  while ( m <= n )

  {

    for ( i = 0; i < n; i++ )

    {

      z[i] = 0.0;

    }

    j = 0;

    for ( i = - q; i < m / 2 - q; i++ )

    {

      for ( k = 0; k < p; k = k + 2 )

      {      

        i0 = i4_wrap ( i         + k / 2,     0,     m / 2 - 1 );

        i1 = i4_wrap ( i + m / 2 + k / 2,     m / 2, m     - 1 );

        z[j]   = z[j]   + c[p-k-1] * x[i0] + c[k+1] * x[i1];

        z[j+1] = z[j+1] + c[p-k]   * x[i0] - c[k]   * x[i1];

      }

      j = j + 2;

    }

    for ( i = 0; i < m; i++ )

    {

      x[i] = z[i];

    }

    m = m * 2;

  }

  delete [] z;

  return x;

}

double *daub14_transform ( int n, double x[] )

{

  double c[14] = {

     7.785205408500917E-02, 

     3.965393194819173E-01, 

     7.291320908462351E-01, 

     4.697822874051931E-01, 

    -1.439060039285649E-01, 

    -2.240361849938749E-01, 

     7.130921926683026E-02, 

     8.061260915108307E-02, 

    -3.802993693501441E-02, 

    -1.657454163066688E-02, 

     1.255099855609984E-02, 

     4.295779729213665E-04, 

    -1.801640704047490E-03, 

     3.537137999745202E-04 };

  int i;

  int j;

  int j0;

  int j1;

  int k;

  int m;

  int p = 13;

  int q;

  double *y;

  double *z;

  y = r8vec_copy_new ( n, x );

  z = new double[n];

  m = n;

  q = ( p - 1 ) / 2;

  while ( 4 <= m )

  {

    for ( i = 0; i < m; i++ )

    {

      z[i] = 0.0;

    }

    i = 0;

    for ( j = 0; j < m - 1; j = j + 2 )

    {

      for ( k = 0; k < p; k = k + 2 )

      {

        j0 = i4_wrap ( j + k,     0, m - 1 );

        j1 = i4_wrap ( j + k + 1, 0, m - 1 );

        z[i]     = z[i]     + c[  k] * y[j0] + c[  k+1] * y[j1];

        z[i+m/2] = z[i+m/2] + c[p-k] * y[j0] - c[p-k-1] * y[j1];

      }

      i = i + 1;

    }

    for ( i = 0; i < m; i++ )

    {

      y[i] = z[i];

    }

    m = m / 2;

  }

  delete [] z;

  return y;

}

double *daub14_transform_inverse ( int n, double y[] )

{

  double c[14] = {

     7.785205408500917E-02, 

     3.965393194819173E-01, 

     7.291320908462351E-01, 

     4.697822874051931E-01, 

    -1.439060039285649E-01, 

    -2.240361849938749E-01, 

     7.130921926683026E-02, 

     8.061260915108307E-02, 

    -3.802993693501441E-02, 

    -1.657454163066688E-02, 

     1.255099855609984E-02, 

     4.295779729213665E-04, 

    -1.801640704047490E-03, 

     3.537137999745202E-04 };

  int i;

  int i0;

  int i1;

  int j;

  int k;

  int m;

  int p = 13;

  int q;

  double *x;

  double *z;

  x = r8vec_copy_new ( n, y );

  z = new double[n];

  m = 4;

  q = ( p - 1 ) / 2;

  while ( m <= n )

  {

    for ( i = 0; i < n; i++ )

    {

      z[i] = 0.0;

    }

    j = 0;

    for ( i = - q; i < m / 2 - q; i++ )

    {

      for ( k = 0; k < p; k = k + 2 )

      {      

        i0 = i4_wrap ( i         + k / 2,     0,     m / 2 - 1 );

        i1 = i4_wrap ( i + m / 2 + k / 2,     m / 2, m     - 1 );

        z[j]   = z[j]   + c[p-k-1] * x[i0] + c[k+1] * x[i1];

        z[j+1] = z[j+1] + c[p-k]   * x[i0] - c[k]   * x[i1];

      }

      j = j + 2;

    }

    for ( i = 0; i < m; i++ )

    {

      x[i] = z[i];

    }

    m = m * 2;

  }

  delete [] z;

  return x;

}

double *daub16_transform ( int n, double x[] )

{

  double c[16] = {

     5.441584224310400E-02, 

     3.128715909142999E-01, 

     6.756307362972898E-01, 

     5.853546836542067E-01, 

    -1.582910525634930E-02, 

    -2.840155429615469E-01, 

     4.724845739132827E-04, 

     1.287474266204784E-01, 

    -1.736930100180754E-02, 

    -4.408825393079475E-02, 

     1.398102791739828E-02, 

     8.746094047405776E-03, 

    -4.870352993451574E-03, 

    -3.917403733769470E-04, 

     6.754494064505693E-04, 

    -1.174767841247695E-04 };

  int i;

  int j;

  int j0;

  int j1;

  int k;

  int m;

  int p = 15;

  int q;

  double *y;

  double *z;

  y = r8vec_copy_new ( n, x );

  z = new double[n];

  m = n;

  q = ( p - 1 ) / 2;

  while ( 4 <= m )

  {

    for ( i = 0; i < m; i++ )

    {

      z[i] = 0.0;

    }

    i = 0;

    for ( j = 0; j < m - 1; j = j + 2 )

    {

      for ( k = 0; k < p; k = k + 2 )

      {

        j0 = i4_wrap ( j + k,     0, m - 1 );

        j1 = i4_wrap ( j + k + 1, 0, m - 1 );

        z[i]     = z[i]     + c[  k] * y[j0] + c[  k+1] * y[j1];

        z[i+m/2] = z[i+m/2] + c[p-k] * y[j0] - c[p-k-1] * y[j1];

      }

      i = i + 1;

    }

    for ( i = 0; i < m; i++ )

    {

      y[i] = z[i];

    }

    m = m / 2;

  }

  delete [] z;

  return y;

}

double *daub16_transform_inverse ( int n, double y[] )

{

  double c[16] = {

     5.441584224310400E-02, 

     3.128715909142999E-01, 

     6.756307362972898E-01, 

     5.853546836542067E-01, 

    -1.582910525634930E-02, 

    -2.840155429615469E-01, 

     4.724845739132827E-04, 

     1.287474266204784E-01, 

    -1.736930100180754E-02, 

    -4.408825393079475E-02, 

     1.398102791739828E-02, 

     8.746094047405776E-03, 

    -4.870352993451574E-03, 

    -3.917403733769470E-04, 

     6.754494064505693E-04, 

    -1.174767841247695E-04 };

  int i;

  int i0;

  int i1;

  int j;

  int k;

  int m;

  int p = 15;

  int q;

  double *x;

  double *z;

  x = r8vec_copy_new ( n, y );

  z = new double[n];

  m = 4;

  q = ( p - 1 ) / 2;

  while ( m <= n )

  {

    for ( i = 0; i < n; i++ )

    {

      z[i] = 0.0;

    }

    j = 0;

    for ( i = - q; i < m / 2 - q; i++ )

    {

      for ( k = 0; k < p; k = k + 2 )

      {      

        i0 = i4_wrap ( i         + k / 2,     0,     m / 2 - 1 );

        i1 = i4_wrap ( i + m / 2 + k / 2,     m / 2, m     - 1 );

        z[j]   = z[j]   + c[p-k-1] * x[i0] + c[k+1] * x[i1];

        z[j+1] = z[j+1] + c[p-k]   * x[i0] - c[k]   * x[i1];

      }

      j = j + 2;

    }

    for ( i = 0; i < m; i++ )

    {

      x[i] = z[i];

    }

    m = m * 2;

  }

  delete [] z;

  return x;

}

double *daub18_transform ( int n, double x[] )

{

  double c[18] = {

     3.807794736387834E-02, 

     2.438346746125903E-01, 

     6.048231236901111E-01, 

     6.572880780513005E-01, 

     1.331973858250075E-01, 

    -2.932737832791749E-01, 

    -9.684078322297646E-02, 

     1.485407493381063E-01, 

     3.072568147933337E-02, 

    -6.763282906132997E-02, 

     2.509471148314519E-04, 

     2.236166212367909E-02, 

    -4.723204757751397E-03, 

    -4.281503682463429E-03, 

     1.847646883056226E-03, 

     2.303857635231959E-04, 

    -2.519631889427101E-04, 

     3.934732031627159E-05 };

  int i;

  int j;

  int j0;

  int j1;

  int k;

  int m;

  int p = 17;

  int q;

  double *y;

  double *z;

  y = r8vec_copy_new ( n, x );

  z = new double[n];

  m = n;

  q = ( p - 1 ) / 2;

  while ( 4 <= m )

  {

    for ( i = 0; i < m; i++ )

    {

      z[i] = 0.0;

    }

    i = 0;

    for ( j = 0; j < m - 1; j = j + 2 )

    {

      for ( k = 0; k < p; k = k + 2 )

      {

        j0 = i4_wrap ( j + k,     0, m - 1 );

        j1 = i4_wrap ( j + k + 1, 0, m - 1 );

        z[i]     = z[i]     + c[  k] * y[j0] + c[  k+1] * y[j1];

        z[i+m/2] = z[i+m/2] + c[p-k] * y[j0] - c[p-k-1] * y[j1];

      }

      i = i + 1;

    }

    for ( i = 0; i < m; i++ )

    {

      y[i] = z[i];

    }

    m = m / 2;

  }

  delete [] z;

  return y;

}

double *daub18_transform_inverse ( int n, double y[] )

{

  double c[18] = {

     3.807794736387834E-02, 

     2.438346746125903E-01, 

     6.048231236901111E-01, 

     6.572880780513005E-01, 

     1.331973858250075E-01, 

    -2.932737832791749E-01, 

    -9.684078322297646E-02, 

     1.485407493381063E-01, 

     3.072568147933337E-02, 

    -6.763282906132997E-02, 

     2.509471148314519E-04, 

     2.236166212367909E-02, 

    -4.723204757751397E-03, 

    -4.281503682463429E-03, 

     1.847646883056226E-03, 

     2.303857635231959E-04, 

    -2.519631889427101E-04, 

     3.934732031627159E-05 };

  int i;

  int i0;

  int i1;

  int j;

  int k;

  int m;

  int p = 17;

  int q;

  double *x;

  double *z;

  x = r8vec_copy_new ( n, y );

  z = new double[n];

  m = 4;

  q = ( p - 1 ) / 2;

  while ( m <= n )

  {

    for ( i = 0; i < n; i++ )

    {

      z[i] = 0.0;

    }

    j = 0;

    for ( i = - q; i < m / 2 - q; i++ )

    {

      for ( k = 0; k < p; k = k + 2 )

      {      

        i0 = i4_wrap ( i         + k / 2,     0,     m / 2 - 1 );

        i1 = i4_wrap ( i + m / 2 + k / 2,     m / 2, m     - 1 );

        z[j]   = z[j]   + c[p-k-1] * x[i0] + c[k+1] * x[i1];

        z[j+1] = z[j+1] + c[p-k]   * x[i0] - c[k]   * x[i1];

      }

      j = j + 2;

    }

    for ( i = 0; i < m; i++ )

    {

      x[i] = z[i];

    }

    m = m * 2;

  }

  delete [] z;

  return x;

}

double *daub20_transform ( int n, double x[] )

{

  double c[20] = {

     2.667005790055555E-02, 

     1.881768000776914E-01, 

     5.272011889317255E-01, 

     6.884590394536035E-01, 

     2.811723436605774E-01, 

    -2.498464243273153E-01, 

    -1.959462743773770E-01, 

     1.273693403357932E-01, 

     9.305736460357235E-02, 

    -7.139414716639708E-02, 

    -2.945753682187581E-02, 

     3.321267405934100E-02, 

     3.606553566956169E-03, 

    -1.073317548333057E-02, 

     1.395351747052901E-03, 

     1.992405295185056E-03, 

    -6.858566949597116E-04, 

    -1.164668551292854E-04, 

     9.358867032006959E-05, 

    -1.326420289452124E-05 };

  int i;

  int j;

  int j0;

  int j1;

  int k;

  int m;

  int p = 19;

  int q;

  double *y;

  double *z;

  y = r8vec_copy_new ( n, x );

  z = new double[n];

  m = n;

  q = ( p - 1 ) / 2;

  while ( 4 <= m )

  {

    for ( i = 0; i < m; i++ )

    {

      z[i] = 0.0;

    }

    i = 0;

    for ( j = 0; j < m - 1; j = j + 2 )

    {

      for ( k = 0; k < p; k = k + 2 )

      {

        j0 = i4_wrap ( j + k,     0, m - 1 );

        j1 = i4_wrap ( j + k + 1, 0, m - 1 );

        z[i]     = z[i]     + c[  k] * y[j0] + c[  k+1] * y[j1];

        z[i+m/2] = z[i+m/2] + c[p-k] * y[j0] - c[p-k-1] * y[j1];

      }

      i = i + 1;

    }

    for ( i = 0; i < m; i++ )

    {

      y[i] = z[i];

    }

    m = m / 2;

  }

  delete [] z;

  return y;

}

double *daub20_transform_inverse ( int n, double y[] )

{

  double c[20] = {

     2.667005790055555E-02, 

     1.881768000776914E-01, 

     5.272011889317255E-01, 

     6.884590394536035E-01, 

     2.811723436605774E-01, 

    -2.498464243273153E-01, 

    -1.959462743773770E-01, 

     1.273693403357932E-01, 

     9.305736460357235E-02, 

    -7.139414716639708E-02, 

    -2.945753682187581E-02, 

     3.321267405934100E-02, 

     3.606553566956169E-03, 

    -1.073317548333057E-02, 

     1.395351747052901E-03, 

     1.992405295185056E-03, 

    -6.858566949597116E-04, 

    -1.164668551292854E-04, 

     9.358867032006959E-05, 

    -1.326420289452124E-05 };

  int i;

  int i0;

  int i1;

  int j;

  int k;

  int m;

  int p = 19;

  int q;

  double *x;

  double *z;

  x = r8vec_copy_new ( n, y );

  z = new double[n];

  m = 4;

  q = ( p - 1 ) / 2;

  while ( m <= n )

  {

    for ( i = 0; i < n; i++ )

    {

      z[i] = 0.0;

    }

    j = 0;

    for ( i = - q; i < m / 2 - q; i++ )

    {

      for ( k = 0; k < p; k = k + 2 )

      {      

        i0 = i4_wrap ( i         + k / 2,     0,     m / 2 - 1 );

        i1 = i4_wrap ( i + m / 2 + k / 2,     m / 2, m     - 1 );

        z[j]   = z[j]   + c[p-k-1] * x[i0] + c[k+1] * x[i1];

        z[j+1] = z[j+1] + c[p-k]   * x[i0] - c[k]   * x[i1];

      }

      j = j + 2;

    }

    for ( i = 0; i < m; i++ )

    {

      x[i] = z[i];

    }

    m = m * 2;

  }

  delete [] z;

  return x;

}

bool i4_is_power_of_2 ( int n )

{

  if ( n <= 0 )

  {

    return false;

  }

  while ( n != 1 )

  {

    if ( ( n % 2 ) == 1 )

    {

      return false;

    }

    n = n / 2;

  }

  return true;

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

double r8mat_is_identity ( int n, double a[] )

{

  double error_frobenius;

  int i;

  int j;

  double t;

  error_frobenius = 0.0;

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      if ( i == j )

      {

        t = a[i+j*n] - 1.0;

      }

      else

      {

        t = a[i+j*n];

      }

      error_frobenius = error_frobenius + t * t;

    }

  }

  error_frobenius = sqrt ( error_frobenius );

  return error_frobenius;

}

double *r8mat_zero_new ( int m, int n )

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

double *r8vec_conjugate ( int n, double c[] )

{

  double *d;

  int i;

  d = new double[n];

  for ( i = 0; i < n; i++ )

  {

    d[i] = c[n-1-i];

  }

  for ( i = 1; i < n; i = i + 2 )

  {

    d[i] = - d[i];

  }

  return d;

}

double *r8vec_convolution ( int m, double x[], int n, double y[] )

{

  int i;

  int j;

  double *z;

  z = new double[m+n-1];

  for ( i = 0; i < m + n - 1; i++ )

  {

    z[i] = 0.0;

  }

  for ( j = 0; j < n; j++ )

  {

    for ( i = 0; i < m; i++ )

    {

      z[j+i] = z[j+i] + x[i] * y[j];

    }

  }

  return z;

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

double *r8vec_linspace_new ( int n, double a_first, double a_last )

{

  double *a;

  int i;

  a = new double[n];

  if ( n == 1 )

  {

    a[0] = ( a_first + a_last ) / 2.0;

  }

  else

  {

    for ( i = 0; i < n; i++ )

    {

      a[i] = ( ( double ) ( n - 1 - i ) * a_first 

             + ( double ) (         i ) * a_last ) 

             / ( double ) ( n - 1     );

    }

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

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/