
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <cmath>

# include <ctime>

# include <cstring>

using namespace std;

# include "prob.hpp"

double angle_cdf ( double x, int n )

{

  double cdf;

  const double pi = 3.14159265358979323;

  double zero = 0.0;

  if ( n < 2 )

  {

    cerr << "\n";

    cerr << "ANGLE_CDF - Fatal error!\n";

    cerr << "  N must be at least 2.\n";

    cerr << "  The input value of N = " << n << "\n";

    exit ( 1 );

  }

  if ( x < 0.0 )

  {

    cdf = 0.0;

  }

  else if ( pi < x )

  {

    cdf = 1.0;

  }

  else if ( n == 2 )

  {

    cdf = x / pi;

  }

  else

  {

    cdf = sin_power_int ( zero, x, n-2 )

      * r8_gamma ( ( double ) ( n ) / 2.0 )

      / ( sqrt ( pi ) * r8_gamma ( ( double ) ( n - 1 ) / 2.0 ) );

  }

  return cdf;

}

double angle_mean ( int n )

{

  double mean;

  const double pi = 3.14159265358979323;

  mean = pi / 2.0;

  return mean;

}

double angle_pdf ( double x, int n )

{

  double pdf;

  const double pi = 3.14159265358979323;

  if ( n < 2 )

  {

    cerr << "\n";

    cerr << "ANGLE_PDF - Fatal error!\n";

    cerr << "  N must be at least 2.\n";

    cerr << "  The input value of N = " << n << "\n";

    exit ( 1 );

  }

  if ( x < 0.0 || pi < x )

  {

    pdf = 0.0;

  }

  else if ( n == 2 )

  {

    pdf = 1.0 / pi;

  }

  else

  {

    pdf = pow ( ( sin ( x ) ), ( n - 2 ) )

      * r8_gamma ( ( double ) ( n ) / 2.0 )

      / ( sqrt ( pi ) * r8_gamma ( ( double ) ( n - 1 ) / 2.0 ) );

  }

  return pdf;

}

double anglit_cdf ( double x )

{

  double cdf;

  const double pi = 3.14159265358979323;

  if ( x <  - 0.25 * pi )

  {

    cdf = 0.0;

  }

  else if ( x < 0.25 * pi )

  {

    cdf = 0.5 - 0.5 * cos ( 2.0 * x + pi / 2.0 );

  }

  else

  {

    cdf = 1.0;

  }

  return cdf;

}

double anglit_cdf_inv ( double cdf )

{

  const double pi = 3.14159265358979323;

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "ANGLIT_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = 0.5 * ( acos ( 1.0 - 2.0 * cdf ) - pi / 2.0 );

  return x;

}

double anglit_mean ( )

{

  return 0.0;

}

double anglit_pdf ( double x )

{

  double pdf;

  const double pi = 3.14159265358979323;

  if ( x <= - 0.25 * pi || 0.25 * pi <= x )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = sin ( 2.0 * x + 0.25 * pi );

  }

  return pdf;

}

double anglit_sample ( int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = anglit_cdf_inv ( cdf );

  return x;

}

double anglit_variance ( )

{

  const double pi = 3.14159265358979323;

  double variance;

  variance = 0.0625 * pi * pi - 0.5;

  return variance;

}

double arcsin_cdf ( double x, double a )

{

  double cdf;

  const double pi = 3.14159265358979323;

  if ( x <= -a )

  {

    cdf = 0.0;

  }

  else if ( x < a )

  {

    cdf = 0.5 + asin ( x / a ) / pi;

  }

  else

  {

    cdf = 1.0;

  }

  return cdf;

}

double arcsin_cdf_inv ( double cdf, double a )

{

  const double pi = 3.14159265358979323;

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "ARCSIN_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = a * sin ( pi * ( cdf - 0.5 ) );

  return x;

}

bool arcsin_check ( double a )

{

  if ( a <= 0.0 )

  {

    return false;

  }

  else

  {

    return true;

  }

}

double arcsin_mean ( double a )

{

  double mean = 0.0;

  return mean;

}

double arcsin_pdf ( double x, double a )

{

  double pdf;

  const double pi = 3.14159265358979323;

  if ( a <= 0 )

  {

    cerr << "\n";

    cerr << "ARCSIN_PDF - Fatal error!\n";

    cerr << "  Parameter A <= 0.\n";

    exit ( 1 );

  }

  if ( x <= -a || a <= x )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = 1.0 / ( pi * sqrt ( a * a - x * x ) );

  }

  return pdf;

}

double arcsin_sample ( double a, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = arcsin_cdf_inv ( cdf, a );

  return x;

}

double arcsin_variance ( double a )

{

  double variance = a * a / 2.0;

  return variance;

}

double benford_pdf ( double x )

{

  double pdf;

  if ( x <= 0 )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = log10 ( ( double ) ( x + 1 ) / ( double ) ( x ) );

  }

  return pdf;

}

double bernoulli_cdf ( int x, double a )

{

  double cdf;

  if ( x < 0 )

  {

    cdf = 0.0;

  }

  else if ( x == 0 )

  {

    cdf = 1.0 - a;

  }

  else

  {

    cdf = 1.0;

  }

  return cdf;

}

int bernoulli_cdf_inv ( double cdf, double a )

{

  int x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "BERNOULLI_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf <= 1.0 - a )

  {

    x = 0;

  }

  else

  {

    x = 1;

  }

  return x;

}

bool bernoulli_check ( double a )

{

  if ( a < 0.0 || 1.0 < a )

  {

    return false;

  }

  else

  {

    return true;

  }

}

double bernoulli_mean ( double a )

{

  double mean;

  mean = a;

  return mean;

}

double bernoulli_pdf ( int x, double a )

{

  double pdf;

  if ( x < 0 )

  {

    pdf = 0.0;

  }

  else if ( x == 0 )

  {

    pdf = 1.0 - a;

  }

  else if ( x == 1 )

  {

    pdf = a;

  }

  else

  {

    pdf = 0.0;

  }

  return pdf;

}

int bernoulli_sample ( double a, int &seed )

{

  double cdf;

  int x;

  cdf = r8_uniform_01 ( seed );

  x = bernoulli_cdf_inv ( cdf, a );

  return x;

}

double bernoulli_variance ( double a )

{

  double variance;

  variance = a * ( 1.0 - a );

  return variance;

}

double bessel_i0 ( double arg )

{

  double a;

  double b;

  double exp40 = 2.353852668370199854E+17;

  int i;

  double p[15] = {

    -5.2487866627945699800E-18,

    -1.5982226675653184646E-14,

    -2.6843448573468483278E-11,

    -3.0517226450451067446E-08,

    -2.5172644670688975051E-05,

    -1.5453977791786851041E-02,

    -7.0935347449210549190,

    -2.4125195876041896775E+03,

    -5.9545626019847898221E+05,

    -1.0313066708737980747E+08,

    -1.1912746104985237192E+10,

    -8.4925101247114157499E+11,

    -3.2940087627407749166E+13,

    -5.5050369673018427753E+14,

    -2.2335582639474375249E+15 };

  double pp[8] = {

    -3.9843750000000000000E-01,

     2.9205384596336793945,

    -2.4708469169133954315,

     4.7914889422856814203E-01,

    -3.7384991926068969150E-03,

    -2.6801520353328635310E-03,

     9.9168777670983678974E-05,

    -2.1877128189032726730E-06 };

  double q[5] = {

    -3.7277560179962773046E+03,

     6.5158506418655165707E+06,

    -6.5626560740833869295E+09,

     3.7604188704092954661E+12,

    -9.7087946179594019126E+14 };

  double qq[7] = {

    -3.1446690275135491500E+01,

     8.5539563258012929600E+01,

    -6.0228002066743340583E+01,

     1.3982595353892851542E+01,

    -1.1151759188741312645,

     3.2547697594819615062E-02,

    -5.5194330231005480228E-04 };

  double rec15 = 6.6666666666666666666E-02;

  double sump;

  double sumq;

  double value;

  double x;

  double xmax = 91.9;

  double xsmall = 2.98E-08;

  double xx;

  x = r8_abs ( arg );

  if ( x < xsmall )

  {

    value = 1.0;

  }

  else if ( x < 15.0 )

  {

    xx = x * x;

    sump = p[0];

    for ( i = 1; i < 15; i++ )

    {

      sump = sump * xx + p[i];

    }

    xx = xx - 225.0;

    sumq = ((((

           xx + q[0] )

         * xx + q[1] )

         * xx + q[2] )

         * xx + q[3] )

         * xx + q[4];

    value = sump / sumq;

  }

  else if ( 15.0 <= x )

  {

    if ( xmax < x )

    {

      value = r8_huge ( );

    }

    else

    {

      xx = 1.0 / x - rec15;

      sump = ((((((

                  pp[0]

           * xx + pp[1] )

           * xx + pp[2] )

           * xx + pp[3] )

           * xx + pp[4] )

           * xx + pp[5] )

           * xx + pp[6] )

           * xx + pp[7];

      sumq = ((((((

             xx + qq[0] )

           * xx + qq[1] )

           * xx + qq[2] )

           * xx + qq[3] )

           * xx + qq[4] )

           * xx + qq[5] )

           * xx + qq[6];

      value = sump / sumq;

      if ( x <= xmax - 15.0 )

      {

        a = exp ( x );

        b = 1.0;

      }

      else

      {

        a = exp ( x - 40.0 );

        b = exp40;

      }

      value = ( ( value * a - pp[0] * a ) / sqrt ( x ) ) * b;

    }

  }

  return value;

}

void bessel_i0_values ( int &n_data, double &x, double &fx )

{

# define N_MAX 20

  static double fx_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.1010025027795146E+01,

     0.1040401782229341E+01,

     0.1092045364317340E+01,

     0.1166514922869803E+01,

     0.1266065877752008E+01,

     0.1393725584134064E+01,

     0.1553395099731217E+01,

     0.1749980639738909E+01,

     0.1989559356618051E+01,

     0.2279585302336067E+01,

     0.3289839144050123E+01,

     0.4880792585865024E+01,

     0.7378203432225480E+01,

     0.1130192195213633E+02,

     0.1748117185560928E+02,

     0.2723987182360445E+02,

     0.6723440697647798E+02,

     0.4275641157218048E+03,

     0.2815716628466254E+04 };

  static double x_vec[N_MAX] = {

     0.00E+00,

     0.20E+00,

     0.40E+00,

     0.60E+00,

     0.80E+00,

     0.10E+01,

     0.12E+01,

     0.14E+01,

     0.16E+01,

     0.18E+01,

     0.20E+01,

     0.25E+01,

     0.30E+01,

     0.35E+01,

     0.40E+01,

     0.45E+01,

     0.50E+01,

     0.60E+01,

     0.80E+01,

     0.10E+02 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

double bessel_i1 ( double arg )

{

  double a;

  double b;

  double exp40 = 2.353852668370199854E+17;

  double forty = 40.0;

  double half = 0.5;

  int j;

  double one = 1.0;

  double one5 = 15.0;

  double p[15] = {

    -1.9705291802535139930E-19,

    -6.5245515583151902910E-16,

    -1.1928788903603238754E-12,

    -1.4831904935994647675E-09,

    -1.3466829827635152875E-06,

    -9.1746443287817501309E-04,

    -4.7207090827310162436E-01,

    -1.8225946631657315931E+02,

    -5.1894091982308017540E+04,

    -1.0588550724769347106E+07,

    -1.4828267606612366099E+09,

    -1.3357437682275493024E+11,

    -6.9876779648010090070E+12,

    -1.7732037840791591320E+14,

    -1.4577180278143463643E+15 };

  double pbar = 3.98437500E-01;

  double pp[8] = {

    -6.0437159056137600000E-02,

     4.5748122901933459000E-01,

    -4.2843766903304806403E-01,

     9.7356000150886612134E-02,

    -3.2457723974465568321E-03,

    -3.6395264712121795296E-04,

     1.6258661867440836395E-05,

    -3.6347578404608223492E-07 };

  double q[5] = {

    -4.0076864679904189921E+03,

     7.4810580356655069138E+06,

    -8.0059518998619764991E+09,

     4.8544714258273622913E+12,

    -1.3218168307321442305E+15 };

  double qq[6] = {

    -3.8806586721556593450,

     3.2593714889036996297,

    -8.5017476463217924408E-01,

     7.4212010813186530069E-02,

    -2.2835624489492512649E-03,

     3.7510433111922824643E-05 };

  double rec15 = 6.6666666666666666666E-02;

  double sump;

  double sumq;

  double two25 = 225.0;

  double value;

  double x;

  double xmax = 713.987;

  double xx;

  double zero = 0.0;

  x = r8_abs ( arg );

  if ( x < r8_epsilon ( ) )

  {

    value = half * x;

  }

  else if ( x < one5 )

  {

    xx = x * x;

    sump = p[0];

    for ( j = 1; j < 15; j++ )

    {

      sump = sump * xx + p[j];

    }

    xx = xx - two25;

    sumq = ((((

          xx + q[0]

      ) * xx + q[1]

      ) * xx + q[2]

      ) * xx + q[3]

      ) * xx + q[4];

    value = ( sump / sumq ) * x;

  }

  else if ( xmax < x )

  {

    value = r8_huge ( );

  }

  else

  {

    xx = one / x - rec15;

    sump = ((((((

               pp[0]

        * xx + pp[1]

      ) * xx + pp[2]

      ) * xx + pp[3]

      ) * xx + pp[4]

      ) * xx + pp[5]

      ) * xx + pp[6]

      ) * xx + pp[7];

    sumq = (((((

          xx + qq[0]

      ) * xx + qq[1]

      ) * xx + qq[2]

      ) * xx + qq[3]

      ) * xx + qq[4]

      ) * xx + qq[5];

    value = sump / sumq;

    if ( xmax - one5 < x )

    {

      a = exp ( x - forty );

      b = exp40;

    }

    else

    {

      a = exp ( x );

      b = one;

    }

    value = ( ( value * a + pbar * a ) / sqrt ( x ) ) * b;

  }

  if ( arg < zero )

  {

    value = -value;

  }

  return value;

}

void bessel_i1_values ( int &n_data, double &x, double &fx )

{

# define N_MAX 20

  static double fx_vec[N_MAX] = {

     0.0000000000000000E+00,

     0.1005008340281251E+00,

     0.2040267557335706E+00,

     0.3137040256049221E+00,

     0.4328648026206398E+00,

     0.5651591039924850E+00,

     0.7146779415526431E+00,

     0.8860919814143274E+00,

     0.1084810635129880E+01,

     0.1317167230391899E+01,

     0.1590636854637329E+01,

     0.2516716245288698E+01,

     0.3953370217402609E+01,

     0.6205834922258365E+01,

     0.9759465153704450E+01,

     0.1538922275373592E+02,

     0.2433564214245053E+02,

     0.6134193677764024E+02,

     0.3998731367825601E+03,

     0.2670988303701255E+04 };

  static double x_vec[N_MAX] = {

     0.00E+00,

     0.20E+00,

     0.40E+00,

     0.60E+00,

     0.80E+00,

     0.10E+01,

     0.12E+01,

     0.14E+01,

     0.16E+01,

     0.18E+01,

     0.20E+01,

     0.25E+01,

     0.30E+01,

     0.35E+01,

     0.40E+01,

     0.45E+01,

     0.50E+01,

     0.60E+01,

     0.80E+01,

     0.10E+02 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

void bessel_ix_values ( int &n_data, double &nu, double &x, double &fx )

{

# define N_MAX 28

  static double fx_vec[N_MAX] = {

    0.3592084175833614E+00,

    0.9376748882454876E+00,

    2.046236863089055E+00,

    3.053093538196718E+00,

    4.614822903407601E+00,

    26.47754749755907E+00,

    2778.784603874571E+00,

    4.327974627242893E+07,

    0.2935253263474798E+00,

    1.099473188633110E+00,

    21.18444226479414E+00,

    2500.906154942118E+00,

    2.866653715931464E+20,

    0.05709890920304825E+00,

    0.3970270801393905E+00,

    13.76688213868258E+00,

    2028.512757391936E+00,

    2.753157630035402E+20,

    0.4139416015642352E+00,

    1.340196758982897E+00,

    22.85715510364670E+00,

    2593.006763432002E+00,

    2.886630075077766E+20,

    0.03590910483251082E+00,

    0.2931108636266483E+00,

    11.99397010023068E+00,

    1894.575731562383E+00,

    2.716911375760483E+20 };

  static double nu_vec[N_MAX] = {

    0.50E+00,

    0.50E+00,

    0.50E+00,

    0.50E+00,

    0.50E+00,

    0.50E+00,

    0.50E+00,

    0.50E+00,

    1.50E+00,

    1.50E+00,

    1.50E+00,

    1.50E+00,

    1.50E+00,

    2.50E+00,

    2.50E+00,

    2.50E+00,

    2.50E+00,

    2.50E+00,

    1.25E+00,

    1.25E+00,

    1.25E+00,

    1.25E+00,

    1.25E+00,

    2.75E+00,

    2.75E+00,

    2.75E+00,

    2.75E+00,

    2.75E+00 };

  static double x_vec[N_MAX] = {

      0.2E+00,

      1.0E+00,

      2.0E+00,

      2.5E+00,

      3.0E+00,

      5.0E+00,

     10.0E+00,

     20.0E+00,

      1.0E+00,

      2.0E+00,

      5.0E+00,

     10.0E+00,

     50.0E+00,

      1.0E+00,

      2.0E+00,

      5.0E+00,

     10.0E+00,

     50.0E+00,

      1.0E+00,

      2.0E+00,

      5.0E+00,

     10.0E+00,

     50.0E+00,

      1.0E+00,

      2.0E+00,

      5.0E+00,

     10.0E+00,

     50.0E+00 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    nu = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    nu = nu_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

double beta ( double x, double y )

{

  if ( x <= 0.0 || y <= 0.0 )

  {

    cerr << "\n";

    cerr << "BETA - Fatal error!\n";

    cerr << "  Both X and Y must be greater than 0.\n";

    exit ( 1 );

  }

  return ( exp ( gamma_log ( x ) + gamma_log ( y ) - gamma_log ( x + y ) ) );

}

double beta_binomial_cdf ( int x, double a, double b, int c )

{

  double cdf;

  double pdf;

  int y;

  if ( x < 0 )

  {

    cdf = 0.0;

  }

  else if ( x < c )

  {

    cdf = 0.0;

    for ( y = 0; y <= x; y++ )

    {

      pdf = beta ( a + ( double ) y, b + ( double ) ( c - y) )

        / ( ( double ) ( c + 1 )

         * beta ( ( double ) ( y + 1 ), ( double ) ( c - y + 1 ) )

         * beta ( a, b ) );

      cdf = cdf + pdf;

    }

  }

  else if ( c <= x )

  {

    cdf = 1.0;

  }

  return cdf;

}

int beta_binomial_cdf_inv ( double cdf, double a, double b, int c )

{

  double cum;

  double pdf;

  int x;

  int y;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "BETA_BINOMIAL_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  cum = 0.0;

  for ( y = 0; y <= c; y++ )

  {

    pdf = beta ( a + ( double ) ( y ),

      b + ( double ) ( c - y ) ) / ( ( double ) ( c + 1 )

      * beta ( ( double ) ( y + 1 ),

      ( double ) ( c - y + 1 ) ) * beta ( a, b ) );

    cum = cum + pdf;

    if ( cdf <= cum )

    {

      x = y;

      return x;

    }

  }

  x = c;

  return x;

}

bool beta_binomial_check ( double a, double b, int c )

{

  if ( a <= 0.0 )

  {

    cerr << "\n";

    cerr << "BETA_BINOMIAL_CHECK - Fatal error!\n";

    cerr << "  A <= 0.\n";

    return false;

  }

  if ( b <= 0.0 )

  {

    cerr << "\n";

    cerr << "BETA_BINOMIAL_CHECK - Fatal error!\n";

    cerr << "  B <= 0.\n";

    return false;

  }

  if ( c < 0 )

  {

    cerr << "\n";

    cerr << "BETA_BINOMIAL_CHECK - Fatal error!\n";

    cerr << "  C < 0.\n";

    return false;

  }

  return true;

}

double beta_binomial_mean ( double a, double b, int c )

{

  double mean;

  mean = ( double ) ( c ) * a / ( a + b );

  return mean;

}

double beta_binomial_pdf ( int x, double a, double b, int c )

{

  double pdf;

  if ( x < 0 )

  {

    pdf = 0.0;

  }

  else if ( x <= c )

  {

    pdf = beta ( a + ( double ) ( x ), b + ( double ) ( c - x ) )

      / ( ( double ) ( c + 1 )

      * beta ( ( double ) ( x + 1 ),

      ( double ) ( c - x + 1 ) ) * beta ( a, b ) );

  }

  else if ( c < x )

  {

    pdf = 0.0;

  }

  return pdf;

}

int beta_binomial_sample ( double a, double b, int c, int &seed )

{

  double cdf;

  int x;

  cdf = r8_uniform_01 ( seed );

  x = beta_binomial_cdf_inv ( cdf, a, b, c );

  return x;

}

double beta_binomial_variance ( double a, double b, int c )

{

  double variance;

  variance = ( ( double ) ( c ) * a * b )

    * ( a + b + ( double ) ( c ) )

    / ( ( a + b ) * ( a + b ) * ( a + b + 1.0 ) );

  return variance;

}

double beta_cdf ( double x, double a, double b )

{

  double cdf;

  if ( x <= 0.0 )

  {

    cdf = 0.0;

  }

  else if ( x <= 1.0 )

  {

    cdf = beta_inc ( a, b, x );

  }

  else

  {

    cdf = 1.0;

  }

  return cdf;

}

double beta_cdf_inv ( double cdf, double p, double q )

{

  double a;

  double acu;

  double adj;

  double beta_log;

  double fpu;

  double g;

  double h;

  int iex;

  bool indx;

  double pp;

  double prev;

  double qq;

  double r;

  double s;

  double sae = -37.0;

  double sq;

  double t;

  double tx;

  double value;

  double w;

  double xin;

  double y;

  double yprev;

  fpu = pow ( 10.0, sae );

  if ( p <= 0.0 )

  {

    cerr << "\n";

    cerr << "BETA_CDF_INV - Fatal error!\n";

    cerr << "  P <= 0.0\n";

    value = -1.0;

    return value;

  }

  if ( q <= 0.0 )

  {

    cerr << "\n";

    cerr << "BETA_CDF_INV - Fatal error!\n";

    cerr << "  Q <= 0.0\n";

    value = -1.0;

    return value;

  }

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "BETA_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0.0 or 1.0 < CDF\n";

    value = -1.0;

    return value;

  }

  if ( cdf == 0.0 )

  {

    value = 0.0;

    return value;

  }

  if ( cdf == 1.0 )

  {

    value = 1.0;

    return value;

  }

  if ( 0.5 < cdf )

  {

    a = 1.0 - cdf;

    pp = q;

    qq = p;

    indx = true;

  }

  else

  {

    a = cdf;

    pp = p;

    qq = q;

    indx = false;

  }

  r = sqrt ( - log ( a * a ) );

  y = r - ( 2.30753 + 0.27061 * r ) 

    / ( 1.0 + ( 0.99229 + 0.04481 * r ) * r );

  if ( 1.0 < pp && 1.0 < qq )

  {

    r = ( y * y - 3.0 ) / 6.0;

    s = 1.0 / ( pp + pp - 1.0 );

    t = 1.0 / ( qq + qq - 1.0 );

    h = 2.0 / ( s + t );

    w = y * sqrt ( h + r ) / h - ( t - s ) 

      * ( r + 5.0 / 6.0 - 2.0 / ( 3.0 * h ) );

    value = pp / ( pp + qq * exp ( w + w ) );

  }

  else

  {

    r = qq + qq;

    t = 1.0 / ( 9.0 * qq );

    t = r * pow ( 1.0 - t + y * sqrt ( t ), 3 );

    if ( t <= 0.0 )

    {

      value = 1.0 - exp ( ( log ( ( 1.0 - a ) * qq ) + beta_log ) / qq );

    }

    else

    {

      t = ( 4.0 * pp + r - 2.0 ) / t;

      if ( t <= 1.0 )

      {

        value = exp ( ( log ( a * pp ) + beta_log ) / pp );

      }

      else

      {

        value = 1.0 - 2.0 / ( t + 1.0 );

      }

    }

  }

  r = 1.0 - pp;

  t = 1.0 - qq;

  yprev = 0.0;

  sq = 1.0;

  prev = 1.0;

  if ( value < 0.0001 )

  {

    value = 0.0001;

  }

  if ( 0.9999 < value )

  {

    value = 0.9999;

  }

  iex = r8_max ( - 5.0 / pp / pp - 1.0 / pow ( a, 0.2 ) - 13.0, sae );

  acu = pow ( 10.0, iex );

  for ( ; ; )

  {

    y = beta_inc ( pp, qq, value );

    xin = value;

    y = ( y - a ) * exp ( beta_log + r * log ( xin ) + t * log ( 1.0 - xin ) );

    if ( y * yprev <= 0.0 )

    {

      prev = r8_max ( sq, fpu );

    }

    g = 1.0;

    for ( ; ; )

    {

      for ( ; ; )

      {

        adj = g * y;

        sq = adj * adj;

        if ( sq < prev )

        {

          tx = value - adj;

          if ( 0.0 <= tx && tx <= 1.0 )

          {

            break;

          }

        }

        g = g / 3.0;

      }

      if ( prev <= acu )

      {

        if ( indx )

        {

          value = 1.0 - value;

        }

        return value;

      }

      if ( y * y <= acu )

      {

        if ( indx )

        {

          value = 1.0 - value;

        }

        return value;

      }

      if ( tx != 0.0 && tx != 1.0 )

      {

        break;

      }

      g = g / 3.0;

    }

    if ( tx == value )

    {

      break;

    }

    value = tx;

    yprev = y;

  }

  if ( indx )

  {

    value = 1.0 - value;

  }

  return value;

}

double beta_cdf_inv_old ( double cdf, double a, double b )

{

# define MAXK 20

  double bcoeff;

  double cdf_x;

  double d[MAXK * (MAXK-1)];

  double error = 0.0001;

  double errapp = 0.01;

  int i;

  int j;

  int k;

  int loopct;

  double pdf_x;

  double q;

  double s1;

  double s2;

  double sum2;

  double t;

  double tail;

  double x;

  double xold;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "BETA_CDF_INV_OLD - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = a / ( a + b );

  xold = 0.0;

  loopct = 2;

  while ( errapp <= r8_abs ( ( x - xold ) / x ) && loopct != 0 )

  {

    xold = x;

    loopct = loopct - 1;

    cdf_x = beta_cdf ( x, a, b );

    pdf_x = beta_pdf ( x, a, b );

    q = ( cdf - cdf_x ) / pdf_x;

    t = 1.0 - x;

    s1 = q * ( b - 1.0 ) / t;

    s2 = q * ( 1.0 - a ) / x;

    d[2-1+0*MAXK] = s1 + s2;

    tail = d[2-1+0*MAXK] * q / 2.0;

    x = x + q + tail;

    k = 3;

    while ( error < r8_abs ( tail / x ) && k <= MAXK )

    {

      s1 = q * ( ( double ) ( k ) - 2.0 ) * s1 / t;

      s2 = q * ( 2.0 - ( double ) ( k ) ) * s2 / x;

      d[2-1+(k-2)*MAXK] = s1 + s2;

      for ( i = 3; i <= k-1; i++ )

      {

        sum2 = d[2-1+0*MAXK] * d[i-2+(k-i)*MAXK];

        bcoeff = 1.0;

        for ( j = 1; j <= k - i; j++ )

        {

          bcoeff = ( bcoeff * ( double ) ( k - i - j + 1 ) )

            / ( double ) ( j );

          sum2 = sum2 + bcoeff * d[2-1+j*MAXK] * d[i-2+(k-i-j)*MAXK];

        }

        d[i-1+(k-i)*MAXK] = sum2 + d[i-2+(k-i+1)*MAXK] / ( double ) ( i - 1 );

      }

      d[k-1+0*MAXK] = d[2-1+0*MAXK] * d[k-2+0*MAXK] + d[k-2+1*MAXK]

        / ( double ) ( k - 1 );

      tail = d[k-1+0*MAXK] * q / ( double ) ( k );

      x = x + tail;

      if ( x <= 0.0 || 1.0 <= x )

      {

        cerr << " \n";

        cerr << "BETA_CDF_INV_OLD - Fatal error!\n";

        cerr << "  The series has diverged.\n";

        x = -1.0;

        return x;

      }

      k = k + 1;

    }

  }

  return x;

# undef MAXK

}

bool beta_check ( double a, double b )

{

  if ( a <= 0.0 )

  {

    cerr << "\n";

    cerr << "BETA_CHECK - Fatal error!\n";

    cerr << "  A <= 0.\n";

    return false;

  }

  if ( b <= 0.0 )

  {

    cerr << "\n";

    cerr << "BETA_CHECK - Fatal error!\n";

    cerr << "  B <= 0.\n";

    return false;

  }

  return true;

}

void beta_cdf_values ( int &n_data, double &a, double &b, double &x,

  double &fx )

{

# define N_MAX 45

  static double a_vec[N_MAX] = {

      0.5E+00,

      0.5E+00,

      0.5E+00,

      1.0E+00,

      1.0E+00,

      1.0E+00,

      1.0E+00,

      1.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      5.5E+00,

     10.0E+00,

     10.0E+00,

     10.0E+00,

     10.0E+00,

     20.0E+00,

     20.0E+00,

     20.0E+00,

     20.0E+00,

     20.0E+00,

     30.0E+00,

     30.0E+00,

     40.0E+00,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.2E+01,

      0.3E+01,

      0.4E+01,

      0.5E+01,

      1.30625,

      1.30625,

      1.30625 };

  static double b_vec[N_MAX] = {

      0.5E+00,

      0.5E+00,

      0.5E+00,

      0.5E+00,

      0.5E+00,

      0.5E+00,

      0.5E+00,

      1.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      5.0E+00,

      0.5E+00,

      5.0E+00,

      5.0E+00,

     10.0E+00,

      5.0E+00,

     10.0E+00,

     10.0E+00,

     20.0E+00,

     20.0E+00,

     10.0E+00,

     10.0E+00,

     20.0E+00,

      0.5E+00,

      0.5E+00,

      0.5E+00,

      0.5E+00,

      0.2E+01,

      0.3E+01,

      0.4E+01,

      0.5E+01,

      0.2E+01,

      0.2E+01,

      0.2E+01,

      0.2E+01,

     11.7562, 

     11.7562, 

     11.7562 };

  static double fx_vec[N_MAX] = {

     0.6376856085851985E-01,

     0.2048327646991335E+00,

     0.1000000000000000E+01,

     0.0000000000000000E+00,

     0.5012562893380045E-02,

     0.5131670194948620E-01,

     0.2928932188134525E+00,

     0.5000000000000000E+00,

     0.2800000000000000E-01,

     0.1040000000000000E+00,

     0.2160000000000000E+00,

     0.3520000000000000E+00,

     0.5000000000000000E+00,

     0.6480000000000000E+00,

     0.7840000000000000E+00,

     0.8960000000000000E+00,

     0.9720000000000000E+00,

     0.4361908850559777E+00,

     0.1516409096347099E+00,

     0.8978271484375000E-01,

     0.1000000000000000E+01,

     0.5000000000000000E+00,

     0.4598773297575791E+00,

     0.2146816102371739E+00,

     0.9507364826957875E+00,

     0.5000000000000000E+00,

     0.8979413687105918E+00,

     0.2241297491808366E+00,

     0.7586405487192086E+00,

     0.7001783247477069E+00,

     0.5131670194948620E-01,

     0.1055728090000841E+00,

     0.1633399734659245E+00,

     0.2254033307585166E+00,

     0.3600000000000000E+00,

     0.4880000000000000E+00,

     0.5904000000000000E+00,

     0.6723200000000000E+00,

     0.2160000000000000E+00,

     0.8370000000000000E-01,

     0.3078000000000000E-01,

     0.1093500000000000E-01,

     0.918885,

     0.21053,

     0.182413 };

  static double x_vec[N_MAX] = {

     0.01E+00,

     0.10E+00,

     1.00E+00,

     0.00E+00,

     0.01E+00,

     0.10E+00,

     0.50E+00,

     0.50E+00,

     0.10E+00,

     0.20E+00,

     0.30E+00,

     0.40E+00,

     0.50E+00,

     0.60E+00,

     0.70E+00,

     0.80E+00,

     0.90E+00,

     0.50E+00,

     0.90E+00,

     0.50E+00,

     1.00E+00,

     0.50E+00,

     0.80E+00,

     0.60E+00,

     0.80E+00,

     0.50E+00,

     0.60E+00,

     0.70E+00,

     0.80E+00,

     0.70E+00,

     0.10E+00,

     0.20E+00,

     0.30E+00,

     0.40E+00,

     0.20E+00,

     0.20E+00,

     0.20E+00,

     0.20E+00,

     0.30E+00,

     0.30E+00,

     0.30E+00,

     0.30E+00,

     0.225609,

     0.0335568,

     0.0295222 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    a = 0.0;

    b = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    a = a_vec[n_data-1];

    b = b_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

double beta_inc ( double a, double b, double x )

{

  double cx;

  int i;

  int it;

  int it_max = 1000;

  bool indx;

  int ns;

  double pp;

  double psq;

  double qq;

  double rx;

  double temp;

  double term;

  double tol = 1.0E-07;

  double value;

  double xx;

  if ( a <= 0.0 )

  {

    cerr << "\n";

    cerr << "BETA_INC - Fatal error!\n";

    cerr << "  A <= 0.\n";

    exit ( 1 );

  }

  if ( b <= 0.0 )

  {

    cerr << "\n";

    cerr << "BETA_INC - Fatal error!\n";

    cerr << "  B <= 0.\n";

    exit ( 1 );

  }

  if ( x <= 0.0 )

  {

    value = 0.0;

    return value;

  }

  else if ( 1.0 <= x )

  {

    value = 1.0;

    return value;

  }

  psq = a + b;

  if ( a < ( a + b ) * x )

  {

    xx = 1.0 - x;

    cx = x;

    pp = b;

    qq = a;

    indx = true;

  }

  else

  {

    xx = x;

    cx = 1.0 - x;

    pp = a;

    qq = b;

    indx = false;

  }

  term = 1.0;

  i = 1;

  value = 1.0;

  ns = ( int ) ( qq + cx * ( a + b ) );

  rx = xx / cx;

  temp = qq - ( double ) i;

  if ( ns == 0 )

  {

    rx = xx;

  }

  it = 0;

  for ( ; ; )

  {

    it = it + 1;

    if ( it_max < it )

    {

      cerr << "\n";

      cerr << "BETA_INC - Fatal error!\n";

      cerr << "  Maximum number of iterations exceeded!\n";

      cerr << "  IT_MAX = " << it_max << "\n";

      exit ( 1 );

    }

    term = term * temp * rx / ( pp + ( double ) ( i ) );

    value = value + term;

    temp = r8_abs ( term );

    if ( temp <= tol && temp <= tol * value )

    {

      break;

    }

    i = i + 1;

    ns = ns - 1;

    if ( 0 <= ns )

    {

      temp = qq - ( double ) i;

      if ( ns == 0 )

      {

        rx = xx;

      }

    }

    else

    {

      temp = psq;

      psq = psq + 1.0;

    }

  }

  value = value * exp ( pp * log ( xx )

    + ( qq - 1.0 ) * log ( cx ) ) / ( beta ( a, b ) * pp );

  if ( indx )

  {

    value = 1.0 - value;

  }

  return value;

}

void beta_inc_values ( int &n_data, double &a, double &b, double &x,

  double &fx )

{

# define N_MAX 45

  static double a_vec[N_MAX] = {

      0.5E+00,

      0.5E+00,

      0.5E+00,

      1.0E+00,

      1.0E+00,

      1.0E+00,

      1.0E+00,

      1.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      5.5E+00,

     10.0E+00,

     10.0E+00,

     10.0E+00,

     10.0E+00,

     20.0E+00,

     20.0E+00,

     20.0E+00,

     20.0E+00,

     20.0E+00,

     30.0E+00,

     30.0E+00,

     40.0E+00,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.2E+01,

      0.3E+01,

      0.4E+01,

      0.5E+01,

      1.30625,

      1.30625,

      1.30625 };

  static double b_vec[N_MAX] = {

      0.5E+00,

      0.5E+00,

      0.5E+00,

      0.5E+00,

      0.5E+00,

      0.5E+00,

      0.5E+00,

      1.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      2.0E+00,

      5.0E+00,

      0.5E+00,

      5.0E+00,

      5.0E+00,

     10.0E+00,

      5.0E+00,

     10.0E+00,

     10.0E+00,

     20.0E+00,

     20.0E+00,

     10.0E+00,

     10.0E+00,

     20.0E+00,

      0.5E+00,

      0.5E+00,

      0.5E+00,

      0.5E+00,

      0.2E+01,

      0.3E+01,

      0.4E+01,

      0.5E+01,

      0.2E+01,

      0.2E+01,

      0.2E+01,

      0.2E+01,

     11.7562, 

     11.7562, 

     11.7562 };

  static double fx_vec[N_MAX] = {

     0.6376856085851985E-01,

     0.2048327646991335E+00,

     0.1000000000000000E+01,

     0.0000000000000000E+00,

     0.5012562893380045E-02,

     0.5131670194948620E-01,

     0.2928932188134525E+00,

     0.5000000000000000E+00,

     0.2800000000000000E-01,

     0.1040000000000000E+00,

     0.2160000000000000E+00,

     0.3520000000000000E+00,

     0.5000000000000000E+00,

     0.6480000000000000E+00,

     0.7840000000000000E+00,

     0.8960000000000000E+00,

     0.9720000000000000E+00,

     0.4361908850559777E+00,

     0.1516409096347099E+00,

     0.8978271484375000E-01,

     0.1000000000000000E+01,

     0.5000000000000000E+00,

     0.4598773297575791E+00,

     0.2146816102371739E+00,

     0.9507364826957875E+00,

     0.5000000000000000E+00,

     0.8979413687105918E+00,

     0.2241297491808366E+00,

     0.7586405487192086E+00,

     0.7001783247477069E+00,

     0.5131670194948620E-01,

     0.1055728090000841E+00,

     0.1633399734659245E+00,

     0.2254033307585166E+00,

     0.3600000000000000E+00,

     0.4880000000000000E+00,

     0.5904000000000000E+00,

     0.6723200000000000E+00,

     0.2160000000000000E+00,

     0.8370000000000000E-01,

     0.3078000000000000E-01,

     0.1093500000000000E-01,

     0.918885,

     0.21053,

     0.182413 };

  static double x_vec[N_MAX] = {

     0.01E+00,

     0.10E+00,

     1.00E+00,

     0.00E+00,

     0.01E+00,

     0.10E+00,

     0.50E+00,

     0.50E+00,

     0.10E+00,

     0.20E+00,

     0.30E+00,

     0.40E+00,

     0.50E+00,

     0.60E+00,

     0.70E+00,

     0.80E+00,

     0.90E+00,

     0.50E+00,

     0.90E+00,

     0.50E+00,

     1.00E+00,

     0.50E+00,

     0.80E+00,

     0.60E+00,

     0.80E+00,

     0.50E+00,

     0.60E+00,

     0.70E+00,

     0.80E+00,

     0.70E+00,

     0.10E+00,

     0.20E+00,

     0.30E+00,

     0.40E+00,

     0.20E+00,

     0.20E+00,

     0.20E+00,

     0.20E+00,

     0.30E+00,

     0.30E+00,

     0.30E+00,

     0.30E+00,

     0.225609,

     0.0335568,

     0.0295222 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    a = 0.0;

    b = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    a = a_vec[n_data-1];

    b = b_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

double beta_mean ( double a, double b )

{

  double mean;

  mean = a / ( a + b );

  return mean;

}

double beta_pdf ( double x, double a, double b )

{

  double pdf;

  if ( x < 0.0 || 1.0 < x )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = pow ( x, ( a - 1.0 ) ) * pow ( ( 1.0 - x ), ( b - 1.0 ) ) / beta ( a, b );

  }

  return pdf;

}

double beta_sample ( double a, double b, int &seed )

{

  double mu;

  double stdev;

  double test;

  double u;

  double x;

  double y;

  mu = ( a - 1.0 ) / ( a + b - 2.0 );

  stdev = 0.5 / sqrt ( a + b - 2.0 );

  for ( ; ; )

  {

    y = normal_01_sample ( seed );

    x = mu + stdev * y;

    if ( x < 0.0 || 1.0 < x )

    {

      continue;

    }

    u = r8_uniform_01 ( seed );

    test =     ( a - 1.0 )     * log (         x   / ( a - 1.0 ) )

             + ( b - 1.0 )     * log ( ( 1.0 - x ) / ( b - 1.0 ) )

             + ( a + b - 2.0 ) * log ( a + b - 2.0 ) + 0.5 * y * y;

    if ( log ( u ) <= test )

    {

      break;

    }

  }

  return x;

}

double beta_variance ( double a, double b )

{

  double variance;

  variance = ( a * b ) / ( ( a + b ) * ( a + b ) * ( 1.0 + a + b ) );

  return variance;

}

double binomial_cdf ( double x, int a, double b )

{

  int cnk;

  double cdf;

  int j;

  double pr;

  if ( x < 0 )

  {

    cdf = 0.0;

  }

  else if ( a <= x )

  {

    cdf = 1.0;

  }

  else if ( b == 0.0 )

  {

    cdf = 1.0;

  }

  else if ( b == 1.0 )

  {

    cdf = 0.0;

  }

  else

  {

    cdf = 0.0;

    for ( j = 0; j <= x; j++ )

    {

      cnk = binomial_coef ( a, j );

      pr = ( double ) ( cnk ) * pow ( b, j ) * pow ( ( 1.0 - b ), ( a - j ) );

      cdf = cdf + pr;

    }

  }

  return cdf;

}

void binomial_cdf_values ( int &n_data, int &a, double &b, int &x, double &fx )

{

# define N_MAX 17

  static int a_vec[N_MAX] = {

     2,  2,  2,  2,

     2,  4,  4,  4,

     4, 10, 10, 10,

    10, 10, 10, 10,

    10 };

  static double b_vec[N_MAX] = {

     0.05E+00,

     0.05E+00,

     0.05E+00,

     0.50E+00,

     0.50E+00,

     0.25E+00,

     0.25E+00,

     0.25E+00,

     0.25E+00,

     0.05E+00,

     0.10E+00,

     0.15E+00,

     0.20E+00,

     0.25E+00,

     0.30E+00,

     0.40E+00,

     0.50E+00  };

  static double fx_vec[N_MAX] = {

     0.9025000000000000E+00,

     0.9975000000000000E+00,

     0.1000000000000000E+01,

     0.2500000000000000E+00,

     0.7500000000000000E+00,

     0.3164062500000000E+00,

     0.7382812500000000E+00,

     0.9492187500000000E+00,

     0.9960937500000000E+00,

     0.9999363101685547E+00,

     0.9983650626000000E+00,

     0.9901259090013672E+00,

     0.9672065024000000E+00,

     0.9218730926513672E+00,

     0.8497316674000000E+00,

     0.6331032576000000E+00,

     0.3769531250000000E+00 };

  static int x_vec[N_MAX] = {

     0, 1, 2, 0,

     1, 0, 1, 2,

     3, 4, 4, 4,

     4, 4, 4, 4,

     4 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    a = 0;

    b = 0.0;

    x = 0;

    fx = 0.0;

  }

  else

  {

    a = a_vec[n_data-1];

    b = b_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

int binomial_cdf_inv ( double cdf, int a, double b )

{

  double cdf2;

  double pdf;

  int x;

  int x2;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "BINOMIAL_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  cdf2 = 0.0;

  for ( x2 = 0; x2 <= a; x2++ )

  {

    pdf = binomial_pdf ( x2, a, b );

    cdf2 = cdf2 + pdf;

    if ( cdf <= cdf2 )

    {

      x = x2;

      return x;

    }

  }

  return x;

}

bool binomial_check ( int a, double b )

{

  if ( a < 1 )

  {

    cerr << "\n";

    cerr << "BINOMIAL_CHECK - Fatal error!\n";

    cerr << "  A < 1.\n";

    return false;

  }

  if ( b < 0.0 || 1.0 < b )

  {

    cerr << "\n";

    cerr << "BINOMIAL_CHECK - Fatal error!\n";

    cerr << "  B < 0 or 1 < B.\n";

    return false;

  }

  return true;

}

int binomial_coef ( int n, int k )

{

  int cnk;

  int i;

  int mn;

  int mx;

  mn = i4_min ( k, n-k );

  if ( mn < 0 )

  {

    cnk = 0;

  }

  else if ( mn == 0 )

  {

    cnk = 1;

  }

  else

  {

    mx = i4_max ( k, n-k );

    cnk = mx + 1;

    for ( i = 2; i <= mn; i++ )

    {

      cnk = ( cnk * ( mx + i ) ) / i;

    }

  }

  return cnk;

}

double binomial_coef_log ( int n, int k )

{

  double cnk_log;

  cnk_log = factorial_log ( n ) - factorial_log ( k ) - factorial_log ( n - k );

  return cnk_log;

}

double binomial_mean ( int a, double b )

{

  double mean;

  mean = ( double ) ( a ) * b;

  return mean;

}

double binomial_pdf ( int x, int a, double b )

{

  int cnk;

  double pdf;

  if ( a < 1 )

  {

    pdf = 0.0;

  }

  else if ( x < 0 || a < x )

  {

    pdf = 0.0;

  }

  else if ( b == 0.0 )

  {

    if ( x == 0 )

    {

      pdf = 1.0;

    }

    else

    {

      pdf = 0.0;

    }

  }

  else if ( b == 1.0 )

  {

    if ( x == a )

    {

      pdf = 1.0;

    }

    else

    {

      pdf = 0.0;

    }

  }

  else

  {

    cnk = binomial_coef ( a, x );

    pdf = ( double ) ( cnk ) * pow ( b, x ) * pow ( ( 1.0 - b ), ( a - x ) );

  }

  return pdf;

}

int binomial_sample ( int a, double b, int &seed )

{

  int i;

  double u;

  int x;

  x = 0;

  for ( i = 1; i <= a; i++ )

  {

    u = r8_uniform_01 ( seed );

    if ( u <= b )

    {

      x = x + 1;

    }

  }

  return x;

}

double binomial_variance ( int a, double b )

{

  double variance;

  variance = ( double ) ( a ) * b * ( 1.0 - b );

  return variance;

}

double birthday_cdf ( int n )

{

  double cdf;

  int i;

  if ( n < 1 )

  {

    cdf = 0.0;

    return cdf;

  }

  else if ( 365 < n )

  {

    cdf = 1.0;

    return cdf;

  }

  cdf = 1.0;

  for ( i = 1; i <= n; i++ )

  {

    cdf = cdf * ( double ) ( 365 + 1 - i ) / 365.0;

  }

  cdf = 1.0 - cdf;

  return cdf;

}

int birthday_cdf_inv ( double cdf )

{

  double cdf_not;

  int i;

  int n;

  if ( cdf <= 0.0 )

  {

    n = 0;

    return n;

  }

  else if ( 1.0 <= cdf )

  {

    n = 365;

    return n;

  }

  cdf_not = 1.0;

  for ( i = 1; i <= 365; i++ )

  {

    cdf_not = cdf_not * ( double ) ( 365 + 1 - i ) / 365.0;

    if ( cdf <= 1.0 - cdf_not )

    {

      n = i;

      return n;

    }

  }

  n = 365;

  return n;

}

double birthday_pdf ( int n )

{

  int i;

  double pdf;

  if ( n < 1 || 365 < n )

  {

    pdf = 0.0;

    return pdf;

  }

  pdf = 1.0;

  for ( i = 1; i <= n-1; i++ )

  {

    pdf = pdf * ( double ) ( 365 + 1 - i ) / 365.0;

  }

  pdf = pdf * ( double ) ( n - 1 ) / 365.0;

  return pdf;

}

double bradford_cdf ( double x, double a, double b, double c )

{

  double cdf;

  if ( x <= a )

  {

    cdf = 0.0;

  }

  else if ( x <= b )

  {

    cdf = log ( 1.0 + c * ( x - a ) / ( b - a ) ) / log ( c + 1.0 );

  }

  else if ( b < x )

  {

    cdf = 1.0;

  }

  return cdf;

}

double bradford_cdf_inv ( double cdf, double a, double b, double c )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "BRADFORD_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf <= 0.0 )

  {

    x = a;

  }

  else if ( cdf < 1.0 )

  {

    x = a + ( b - a ) * ( pow ( ( c + 1.0 ), cdf ) - 1.0 ) / c;

  }

  else if ( 1.0 <= cdf )

  {

    x = b;

  }

  return x;

}

bool bradford_check ( double a, double b, double c )

{

  if ( b <= a )

  {

    cerr << " \n";

    cerr << "BRADFORD_CHECK - Fatal error!\n";

    cerr << "  B <= A.\n";

    return false;

  }

  if ( c <= 0.0 )

  {

    cerr << " \n";

    cerr << "BRADFORD_CHECK - Fatal error!\n";

    cerr << "  C <= 0.\n";

    return false;

  }

  return true;

}

double bradford_mean ( double a, double b, double c )

{

  double mean;

  mean = ( c * ( b - a ) + log ( c + 1.0 ) * ( a * ( c + 1.0 ) - b ) )

    / ( c * log ( c + 1.0 ) );

  return mean;

}

double bradford_pdf ( double x, double a, double b, double c )

{

  double pdf;

  if ( x <= a )

  {

    pdf = 0.0;

  }

  else if ( x <= b )

  {

    pdf = c / ( ( c * ( x - a ) + b - a ) * log ( c + 1.0 ) );

  }

  else if ( b < x )

  {

    pdf = 0.0;

  }

  return pdf;

}

double bradford_sample ( double a, double b, double c, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = a + ( b - a ) * ( pow ( ( c + 1.0 ), cdf ) - 1.0 ) / c;

  return x;

}

double bradford_variance ( double a, double b, double c )

{

  double variance;

  variance = ( b - a ) * ( b - a ) *

    ( c * ( log ( c + 1.0 ) - 2.0 ) + 2.0 * log ( c + 1.0 ) )

    / ( 2.0 * c * pow ( ( log ( c + 1.0 ) ), 2 ) );

  return variance;

}

double buffon_laplace_pdf ( double a, double b, double l )

{

  double pdf;

  double pi = 3.141592653589793238462643;

  if ( a < 0.0 )

  {

    cerr << "\n";

    cerr << "BUFFON_LAPLACE_PDF - Fatal error!\n";

    cerr << "  Input A < 0.\n";

    exit ( 1 );

  }

  else if ( a == 0.0 )

  {

    pdf = 1.0;

    return pdf;

  }

  if ( b < 0.0 )

  {

    cerr << "\n";

    cerr << "BUFFON_LAPLACE_PDF - Fatal error!\n";

    cerr << "  Input B < 0.\n";

    exit ( 1 );

  }

  else if ( b == 0.0 )

  {

    pdf = 1.0;

    return pdf;

  }

  if ( l < 0.0 )

  {

    cerr << "\n";

    cerr << "BUFFON_LAPLACE_PDF - Fatal error!\n";

    cerr << "  Input L < 0.\n";

    exit ( 1 );

  }

  else if ( l == 0.0 )

  {

    pdf = 0.0;

    return pdf;

  }

  else if ( r8_min ( a, b ) < l )

  {

    cerr << "\n";

    cerr << "BUFFON_LAPLACE_PDF - Fatal error!\n";

    cerr << "  min ( A, B ) < L.\n";

    exit ( 1 );

  }

  pdf = ( 2.0 * l * ( a + b ) - l * l ) / ( pi * a * b );

  return pdf;

}

int buffon_laplace_simulate ( double a, double b, double l, int trial_num )

{

  double angle;

  int hits;

  double pi = 3.141592653589793238462643;

  int trial;

  double x1;

  double x2;

  double y1;

  double y2;

  hits = 0;

  for ( trial = 1; trial <= trial_num; trial++ )

  {

    x1 = a * ( double ) rand ( ) / ( double ) RAND_MAX;

    y1 = b * ( double ) rand ( ) / ( double ) RAND_MAX;

    angle = 2.0 * pi * ( double ) rand ( ) / ( double ) RAND_MAX;

    x2 = x1 + l * cos ( angle );

    y2 = y1 + l * sin ( angle );

    if ( x2 <= 0.0 || a <= x2 || y2 <= 0.0 || b <= y2 )

    {

      hits = hits + 1;

    }

  }

  return hits;

}

double buffon_pdf ( double a, double l )

{

  double pdf;

  double pi = 3.141592653589793238462643;

  if ( a < 0.0 )

  {

    cerr << "\n";

    cerr << "BUFFON_PDF - Fatal error!\n";

    cerr << "  Input A < 0.\n";

    exit ( 1 );

  }

  else if ( a == 0.0 )

  {

    pdf = 1.0;

    return pdf;

  }

  if ( l < 0.0 )

  {

    cerr << "\n";

    cerr << "BUFFON_PDF - Fatal error!\n";

    cerr << "  Input L < 0.\n";

    exit ( 1 );

  }

  else if ( l == 0.0 )

  {

    pdf = 0.0;

    return pdf;

  }

  pdf = ( 2.0 * l ) / ( pi * a );

  return pdf;

}

int buffon_simulate ( double a, double l, int trial_num )

{

  double angle;

  int hits;

  double pi = 3.141592653589793238462643;

  int trial;

  double x1;

  double x2;

  hits = 0;

  for ( trial = 1; trial <= trial_num; trial++ )

  {

    x1 = a * ( double ) rand ( ) / ( double ) RAND_MAX;

    angle = 2.0 * pi * ( double ) rand ( ) / ( double ) RAND_MAX;

    x2 = x1 + l * cos ( angle );

    if ( x2 <= 0.0 || a <= x2 )

    {

       hits = hits + 1;

    }

  }

  return hits;

}

double burr_cdf ( double x, double a, double b, double c, double d )

{

  double cdf;

  if ( x <= a )

  {

    cdf = 0.0;

  }

  else

  {

    cdf = 1.0 / pow ( ( 1.0 + pow ( ( b / ( x - a ) ), c )  ), d );

  }

  return cdf;

}

double burr_cdf_inv ( double cdf, double a, double b, double c, double d )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "BURR_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = a + b / pow ( ( pow ( ( 1.0 / cdf ), (1.0 / d ) ) - 1.0 ), ( 1.0 / c ) );

  return x;

}

bool burr_check ( double a, double b, double c, double d )

{

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "BURR_CHECK - Fatal error!\n";

    cerr << "  B <= 0.\n";

    return false;

  }

  if ( c <= 0 )

  {

    cerr << " \n";

    cerr << "BURR_CHECK - Fatal error!\n";

    cerr << "  C <= 0.\n";

    return false;

  }

  return true;

}

double burr_mean ( double a, double b, double c, double d )

{

  double mean;

  mean = a + b * r8_gamma ( 1.0 - 1.0 / c ) * r8_gamma ( d + 1.0 / c )

  / r8_gamma ( d );

  return mean;

}

double burr_pdf ( double x, double a, double b, double c, double d )

{

  double pdf;

  double y;

  if ( x <= a )

  {

    pdf = 0.0;

  }

  else

  {

    y = ( x - a ) / b;

    pdf = ( c * d / b ) * pow ( y, ( - c - 1.0 ) )

      * pow ( ( 1.0 + pow ( y, ( - c ) ) ), ( - d - 1.0 ) );

  }

  return pdf;

}

double burr_sample ( double a, double b, double c, double d, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = burr_cdf_inv ( cdf, a, b, c, d );

  return x;

}

double burr_variance ( double a, double b, double c, double d )

{

  double k;

  double variance;

  if ( c <= 2.0 )

  {

    cout << " \n";

    cout << "BURR_VARIANCE - Warning!\n";

    cout << "  Variance undefined for C <= 2.\n";

    variance = r8_huge ( );

  }

  else

  {

    k = r8_gamma ( d ) * r8_gamma ( 1.0 - 2.0 / c ) * r8_gamma ( d + 2.0 / c )

      - pow ( ( r8_gamma ( 1.0 - 1.0 / c ) * r8_gamma ( d + 1.0 / c ) ), 2 );

    variance = k * b * b / pow ( r8_gamma ( d ), 2 );

  }

  return variance;

}

double cardioid_cdf ( double x, double a, double b )

{

  double cdf;

  const double pi = 3.14159265358979323;

  if ( x <= a - pi )

  {

    cdf = 0.0;

  }

  else if ( x < a + pi )

  {

    cdf = ( pi + x - a + 2.0 * b * sin ( x - a ) ) / ( 2.0 * pi );

  }

  else

  {

    cdf = 1.0;

  }

  return cdf;

}

double cardioid_cdf_inv ( double cdf, double a, double b )

{

  double fp;

  double fx;

  int it;

  const double pi = 3.14159265358979323;

  double tol = 0.000001;

  double x;

  if ( cdf <= 0.0 )

  {

    x = a - pi;

  }

  else if ( cdf < 1.0 )

  {

    x = a;

    it = 0;

    for ( ; ; )

    {

      fx = cdf - ( pi + x - a + 2.0 * b * sin ( x - a ) ) / ( 2.0 * pi );

      if ( r8_abs ( fx ) < tol )

      {

        break;

      }

      if ( 10 < it )

      {

        cerr << "\n";

        cerr << "CARDIOID_CDF_INV - Fatal error!\n";

        cerr << "  Too many iterations.\n";

        exit ( 1 );

      }

      fp = - ( 1.0 + 2.0 * b * cos ( x - a ) ) / ( 2.0 * pi );

      x = x - fx / fp;

      x = r8_max ( x, a - pi );

      x = r8_min ( x, a + pi );

      it = it + 1;

    }

  }

  else

  {

    x = a + pi;

  }

  return x;

}

bool cardioid_check ( double a, double b )

{

  bool value;

  if ( b < -0.5 || 0.5 < b )

  {

    cerr << "\n";

    cerr << "CARDIOID_CHECK - Fatal error!\n";

    cerr << "  B < -0.5 or 0.5 < B.\n";

    value = false;

    return value;

  }

  value = true;

  return value;

}

double cardioid_mean ( double a, double b )

{

  double mean;

  mean = a;

  return mean;

}

double cardioid_pdf ( double x, double a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  pdf = ( 1.0 + 2.0 * b * cos ( x - a ) ) / ( 2.0 * pi );

  return pdf;

}

double cardioid_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = cardioid_cdf_inv ( cdf, a, b );

  return x;

}

double cardioid_variance ( double a, double b )

{

  double variance;

  variance = 0.0;

  return variance;

}

double cauchy_cdf ( double x, double a, double b )

{

  double cdf;

  const double pi = 3.14159265358979323;

  double y;

  y = ( x - a ) / b;

  cdf = 0.5 + atan ( y ) / pi;

  return cdf;

}

double cauchy_cdf_inv ( double cdf, double a, double b )

{

  const double pi = 3.14159265358979323;

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "CAUCHY_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = a + b * tan ( pi * ( cdf - 0.5 ) );

  return x;

}

void cauchy_cdf_values ( int &n_data, double &mu, double &sigma, double &x,

  double &fx )

{

# define N_MAX 12

  static double fx_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.8524163823495667E+00,

     0.9220208696226307E+00,

     0.9474315432887466E+00,

     0.6475836176504333E+00,

     0.6024163823495667E+00,

     0.5779791303773693E+00,

     0.5628329581890012E+00,

     0.6475836176504333E+00,

     0.5000000000000000E+00,

     0.3524163823495667E+00,

     0.2500000000000000E+00 };

  static double mu_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01 };

  static double sigma_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01 };

  static double x_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    mu = 0.0;

    sigma = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    mu = mu_vec[n_data-1];

    sigma = sigma_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool cauchy_check ( double a, double b )

{

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "CAUCHY_CHECK - Fatal error!\n";

    cerr << "  B <= 0.\n";

    return false;

  }

  return true;

}

double cauchy_mean ( double a, double b )

{

  double mean;

  mean = a;

  return mean;

}

double cauchy_pdf ( double x, double a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  double y;

  y = ( x - a ) / b;

  pdf = 1.0 / ( pi * b * ( 1.0 + y * y ) );

  return pdf;

}

double cauchy_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = cauchy_cdf_inv ( cdf, a, b );

  return x;

}

double cauchy_variance ( double a, double b )

{

  double variance;

  variance = r8_huge ( );

  return variance;

}

double chi_cdf ( double x, double a, double b, double c )

{

  double cdf;

  double p2;

  double x2;

  double y;

  if ( x <= a )

  {

    cdf = 0.0;

  }

  else

  {

    y = ( x - a ) / b;

    x2 = 0.5 * y * y;

    p2 = 0.5 * c;

    cdf = gamma_inc ( p2, x2 );

  }

  return cdf;

}

double chi_cdf_inv ( double cdf, double a, double b, double c )

{

  double cdf1;

  double cdf2;

  double cdf3;

  int it;

  int it_max = 100;

  double tol = 0.0001;

  double x;

  double x1;

  double x2;

  double x3;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "CHI_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = a;

    return x;

  }

  else if ( 1.0 == cdf )

  {

    x = r8_huge ( );

    return x;

  }

  x1 = a;

  cdf1 = 0.0;

  x2 = a + 1.0;

  for ( ; ; )

  {

    cdf2 = chi_cdf ( x2, a, b, c );

    if ( cdf < cdf2 )

    {

      break;

    }

    x2 = a + 2.0 * ( x2 - a );

  }

  it = 0;

  for ( ; ; )

  {

    it = it + 1;

    x3 = 0.5 * ( x1 + x2 );

    cdf3 = chi_cdf ( x3, a, b, c );

    if ( r8_abs ( cdf3 - cdf ) < tol )

    {

      x = x3;

      break;

    }

    if ( it_max < it )

    {

      cerr << " \n";

      cerr << "CHI_CDF_INV - Fatal error!\n";

      cerr << "  Iteration limit exceeded.\n";

      return x;

    }

    if ( ( cdf3 <= cdf && cdf1 <= cdf ) || ( cdf <= cdf3 && cdf <= cdf1 ) )

    {

      x1 = x3;

      cdf1 = cdf3;

    }

    else

    {

      x2 = x3;

      cdf2 = cdf3;

    }

  }

  return x;

}

bool chi_check ( double a, double b, double c )

{

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "CHI_CHECK - Fatal error!\n";

    cerr << "  B <= 0.0.\n";

    return false;

  }

  if ( c <= 0.0 )

  {

    cerr << " \n";

    cerr << "CHI_CHECK - Fatal error!\n";

    cerr << "  C <= 0.0.\n";

    return false;

  }

  return true;

}

double chi_mean ( double a, double b, double c )

{

  double mean;

  mean = a + sqrt ( 2.0 ) * b * r8_gamma ( 0.5 * ( c + 1.0 ) )

  / r8_gamma ( 0.5 * c );

  return mean;

}

double chi_pdf ( double x, double a, double b, double c )

{

  double pdf;

  double y;

  if ( x <= a )

  {

    pdf = 0.0;

  }

  else

  {

    y = ( x - a ) / b;

    pdf = exp ( - 0.5 * y * y ) * pow ( y, ( c - 1.0 ) ) /

      ( pow ( 2.0, ( 0.5 * c - 1.0 ) ) * b * r8_gamma ( 0.5 * c ) );

  }

  return pdf;

}

double chi_sample ( double a, double b, double c, int &seed )

{

  double x;

  x = chi_square_sample ( c, seed );

  x = a + b * sqrt ( x );

  return x;

}

double chi_variance ( double a, double b, double c )

{

  double variance;

  variance = b * b * ( c - 2.0 *

    pow ( ( r8_gamma ( 0.5 * ( c + 1.0 ) ) / r8_gamma ( 0.5 * c ) ), 2 ) );

  return variance;

}

double chi_square_cdf ( double x, double a )

{

  double a2;

  double b2;

  double c2;

  double cdf;

  double x2;

  x2 = 0.5 * x;

  a2 = 0.0;

  b2 = 1.0;

  c2 = 0.5 * a;

  cdf = gamma_cdf ( x2, a2, b2, c2 );

  return cdf;

}

double chi_square_cdf_inv ( double cdf, double a )

{

  double a2;

  double aa = 0.6931471806;

  double b;

  double c;

  double c1 = 0.01;

  double c2 = 0.222222;

  double c3 = 0.32;

  double c4 = 0.4;

  double c5 = 1.24;

  double c6 = 2.2;

  double c7 = 4.67;

  double c8 = 6.66;

  double c9 = 6.73;

  double c10 = 13.32;

  double c11 = 60.0;

  double c12 = 70.0;

  double c13 = 84.0;

  double c14 = 105.0;

  double c15 = 120.0;

  double c16 = 127.0;

  double c17 = 140.0;

  double c18 = 175.0;

  double c19 = 210.0;

  double c20 = 252.0;

  double c21 = 264.0;

  double c22 = 294.0;

  double c23 = 346.0;

  double c24 = 420.0;

  double c25 = 462.0;

  double c26 = 606.0;

  double c27 = 672.0;

  double c28 = 707.0;

  double c29 = 735.0;

  double c30 = 889.0;

  double c31 = 932.0;

  double c32 = 966.0;

  double c33 = 1141.0;

  double c34 = 1182.0;

  double c35 = 1278.0;

  double c36 = 1740.0;

  double c37 = 2520.0;

  double c38 = 5040.0;

  double cdf_max = 0.999998;

  double cdf_min = 0.000002;

  double ch;

  double e = 0.0000005;

  double g;

  int i;

  int it_max = 20;

  double p1;

  double p2;

  double q;

  double s1;

  double s2;

  double s3;

  double s4;

  double s5;

  double s6;

  double t;

  double x;

  double x2;

  double xx;

  if ( cdf < cdf_min )

  {

    x = -1.0;

    cerr << " \n";

    cerr << "CHI_SQUARE_CDF_INV - Fatal error!\n";

    cerr << "  CDF < CDF_MIN.\n";

    exit ( 1 );

  }

  if ( cdf_max < cdf )

  {

    x = -1.0;

    cerr << " \n";

    cerr << "CHI_SQUARE_CDF_INV - Fatal error!\n";

    cerr << "  CDF_MAX < CDF.\n";

    exit ( 1 );

  }

  xx = 0.5 * a;

  c = xx - 1.0;

  g = gamma_log ( a / 2.0 );

  if ( a < -c5 * log ( cdf ) )

  {

    ch = pow ( ( cdf * xx * exp ( g + xx * aa ) ), ( 1.0 / xx ) );

    if ( ch < e )

    {

      x = ch;

      return x;

    }

  }

  else if ( a <= c3 )

  {

    ch = c4;

    a2 = log ( 1.0 - cdf );

    for ( ; ; )

    {

      q = ch;

      p1 = 1.0 + ch * ( c7 + ch );

      p2 = ch * ( c9 + ch * ( c8 + ch ) );

      t = - 0.5 + ( c7 + 2.0 * ch ) / p1 - ( c9 + ch * ( c10 + 3.0 * ch ) ) / p2;

      ch = ch - ( 1.0 - exp ( a2 + g + 0.5 * ch + c * aa ) * p2 / p1 ) / t;

      if ( r8_abs ( q / ch - 1.0 ) <= c1 )

      {

        break;

      }

    }

  }

  else

  {

    x2 = normal_01_cdf_inv ( cdf );

    p1 = c2 / a;

    ch = a * pow ( ( x2 * sqrt ( p1 ) + 1.0 - p1 ), 3 );

    if ( c6 * a + 6.0 < ch )

    {

      ch = - 2.0 * ( log ( 1.0 - cdf ) - c * log ( 0.5 * ch ) + g );

    }

  }

  for ( i = 1; i <= it_max; i++ )

  {

    q = ch;

    p1 = 0.5 * ch;

    p2 = cdf - gamma_inc ( xx, p1 );

    t = p2 * exp ( xx * aa + g + p1 - c * log ( ch ) );

    b = t / ch;

    a2 = 0.5 * t - b * c;

    s1 = ( c19 + a2

       * ( c17 + a2

       * ( c14 + a2

       * ( c13 + a2

       * ( c12 + a2

       *   c11 ) ) ) ) ) / c24;

    s2 = ( c24 + a2

       * ( c29 + a2

       * ( c32 + a2

       * ( c33 + a2

       *   c35 ) ) ) ) / c37;

    s3 = ( c19 + a2

       * ( c25 + a2

       * ( c28 + a2

       *   c31 ) ) ) / c37;

    s4 = ( c20 + a2

       * ( c27 + a2

       *   c34 ) + c

       * ( c22 + a2

       * ( c30 + a2

       *   c36 ) ) ) / c38;

    s5 = ( c13 + c21 * a2 + c * ( c18 + c26 * a2 ) ) / c37;

    s6 = ( c15 + c * ( c23 + c16 * c ) ) / c38;

    ch = ch + t * ( 1.0 + 0.5 * t * s1 - b * c

      * ( s1 - b

      * ( s2 - b

      * ( s3 - b

      * ( s4 - b

      * ( s5 - b

      *   s6 ) ) ) ) ) );

    if ( e < r8_abs ( q / ch - 1.0 ) )

    {

      x = ch;

      return x;

    }

  }

  x = ch;

  cout << " \n";

  cout << "CHI_SQUARE_CDF_INV - Warning!\n";

  cout << "  Convergence not reached.\n";

  return x;

}

void chi_square_cdf_values ( int &n_data, int &a, double &x, double &fx )

{

# define N_MAX 21

  static int a_vec[N_MAX] = {

     1,  2,  1,  2,

     1,  2,  3,  4,

     1,  2,  3,  4,

     5,  3,  3,  3,

     3,  3, 10, 10,

    10 };

  static double fx_vec[N_MAX] = {

     0.7965567455405796E-01,

     0.4987520807317687E-02,

     0.1124629160182849E+00,

     0.9950166250831946E-02,

     0.4729107431344619E+00,

     0.1812692469220181E+00,

     0.5975750516063926E-01,

     0.1752309630642177E-01,

     0.6826894921370859E+00,

     0.3934693402873666E+00,

     0.1987480430987992E+00,

     0.9020401043104986E-01,

     0.3743422675270363E-01,

     0.4275932955291202E+00,

     0.6083748237289110E+00,

     0.7385358700508894E+00,

     0.8282028557032669E+00,

     0.8883897749052874E+00,

     0.1721156299558408E-03,

     0.3659846827343712E-02,

     0.1857593622214067E-01 };

  static double x_vec[N_MAX] = {

     0.01E+00,

     0.01E+00,

     0.02E+00,

     0.02E+00,

     0.40E+00,

     0.40E+00,

     0.40E+00,

     0.40E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     2.00E+00,

     3.00E+00,

     4.00E+00,

     5.00E+00,

     6.00E+00,

     1.00E+00,

     2.00E+00,

     3.00E+00 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    a = 0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    a = a_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool chi_square_check ( double a )

{

  if ( a < 1.0 )

  {

    cerr << " \n";

    cerr << "CHI_SQUARE_CHECK - Fatal error!\n";

    cerr << "  A < 1.0.\n";

    return false;

  }

  return true;

}

double chi_square_mean ( double a )

{

  double mean;

  mean = a;

  return mean;

}

double chi_square_pdf ( double x, double a )

{

  double b;

  double pdf;

  if ( x < 0.0 )

  {

    pdf = 0.0;

  }

  else

  {

    b = a / 2.0;

    pdf = exp ( -0.5 * x ) * pow ( x, ( b - 1.0 ) ) / ( pow ( 2.0, b )

    * r8_gamma ( b ) );

  }

  return pdf;

}

double chi_square_sample ( double a, int &seed )

{

  double a2;

  double b2;

  double c2;

  int i;

  int it_max = 100;

  int n;

  double x;

  double x2;

  n = ( int ) a;

  if ( ( double ) ( n ) == a && n <= it_max )

  {

    x = 0.0;

    for ( i = 1; i <= n; i++ )

    {

      x2 = normal_01_sample ( seed );

      x = x + x2 * x2;

    }

  }

  else

  {

    a2 = 0.0;

    b2 = 1.0;

    c2 = a / 2.0;

    x = gamma_sample ( a2, b2, c2, seed );

    x = 2.0 * x;

  }

  return x;

}

double chi_square_variance ( double a )

{

  double variance;

  variance = 2.0 * a;

  return variance;

}

void chi_square_noncentral_cdf_values ( int &n_data, int &df, double &lambda,

  double &x, double &cdf )

{

# define N_MAX 28

  static double cdf_vec[N_MAX] = {

     0.8399444269398261E+00,

     0.6959060300435139E+00,

     0.5350879697078847E+00,

     0.7647841496310313E+00,

     0.6206436532195436E+00,

     0.4691667375373180E+00,

     0.3070884345937569E+00,

     0.2203818092990903E+00,

     0.1500251895581519E+00,

     0.3071163194335791E-02,

     0.1763982670131894E-02,

     0.9816792594625022E-03,

     0.1651753140866208E-01,

     0.2023419573950451E-03,

     0.4984476352854074E-06,

     0.1513252400654827E-01,

     0.2090414910614367E-02,

     0.2465021206048452E-03,

     0.2636835050342939E-01,

     0.1857983220079215E-01,

     0.1305736595486640E-01,

     0.5838039534819351E-01,

     0.4249784402463712E-01,

     0.3082137716021596E-01,

     0.1057878223400849E+00,

     0.7940842984598509E-01,

     0.5932010895599639E-01,

     0.2110395656918684E+00 };

  static int df_vec[N_MAX] = {

      1,   2,   3,

      1,   2,   3,

      1,   2,   3,

      1,   2,   3,

     60,  80, 100,

      1,   2,   3,

     10,  10,  10,

     10,  10,  10,

     10,  10,  10,

      8 };

  static double lambda_vec[N_MAX] = {

     0.5E+00,

     0.5E+00,

     0.5E+00,

     1.0E+00,

     1.0E+00,

     1.0E+00,

     5.0E+00,

     5.0E+00,

     5.0E+00,

    20.0E+00,

    20.0E+00,

    20.0E+00,

    30.0E+00,

    30.0E+00,

    30.0E+00,

     5.0E+00,

     5.0E+00,

     5.0E+00,

     2.0E+00,

     3.0E+00,

     4.0E+00,

     2.0E+00,

     3.0E+00,

     4.0E+00,

     2.0E+00,

     3.0E+00,

     4.0E+00,

     0.5E+00 };

  static double x_vec[N_MAX] = {

      3.000E+00,

      3.000E+00,

      3.000E+00,

      3.000E+00,

      3.000E+00,

      3.000E+00,

      3.000E+00,

      3.000E+00,

      3.000E+00,

      3.000E+00,

      3.000E+00,

      3.000E+00,

     60.000E+00,

     60.000E+00,

     60.000E+00,

      0.050E+00,

      0.050E+00,

      0.050E+00,

      4.000E+00,

      4.000E+00,

      4.000E+00,

      5.000E+00,

      5.000E+00,

      5.000E+00,

      6.000E+00,

      6.000E+00,

      6.000E+00,

      5.000E+00 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    x = 0.0;

    lambda = 0.0;

    df = 0;

    cdf = 0.0;

  }

  else

  {

    x = x_vec[n_data-1];

    lambda = lambda_vec[n_data-1];

    df = df_vec[n_data-1];

    cdf = cdf_vec[n_data-1];

  }

  return;

# undef N_MAX

}

double chi_square_noncentral_check ( double a, double b )

{

  if ( a < 1.0 )

  {

    cerr << " \n";

    cerr << "CHI_SQUARE_NONCENTRAL_CHECK - Fatal error!\n";

    cerr << "  A < 1.\n";

    return false;

  }

  if ( b < 0.0 )

  {

    cerr << " \n";

    cerr << "CHI_SQUARE_NONCENTRAL_CHECK - Fatal error!\n";

    cerr << "  B < 0.\n";

    return false;

  }

  return true;

}

double chi_square_noncentral_mean ( double a, double b )

{

  double mean;

  mean = a + b;

  return mean;

}

double chi_square_noncentral_sample ( double a, double b, int &seed )

{

  double a1;

  double a2;

  double b2;

  double x;

  double x1;

  double x2;

  a1 = a - 1.0;

  x1 = chi_square_sample ( a1, seed );

  a2 = sqrt ( b );

  b2 = 1.0;

  x2 = normal_sample ( a2, b2, seed );

  x = x1 + x2 * x2;

  return x;

}

double chi_square_noncentral_variance ( double a, double b )

{

  double variance;

  variance = 2.0 * ( a + 2.0 * b );

  return variance;

}

double *circle_sample ( double a, double b, double c, int &seed )

{

  double angle;

  const double pi = 3.14159265358979323;

  double radius_frac;

  double *x;

  x = new double[2];

  radius_frac = sqrt ( r8_uniform_01 ( seed ) );

  angle = 2.0 * pi * r8_uniform_01 ( seed );

  x[0] = a + c * radius_frac * cos ( angle );

  x[1] = b + c * radius_frac * sin ( angle );

  return x;

}

double *circular_normal_01_mean ( )

{

  double *mean;

  mean = new double[2];

  mean[0] = 0.0;

  mean[1] = 0.0;

  return mean;

}

double circular_normal_01_pdf ( double x[2] )

{

  double pdf;

  const double pi = 3.14159265358979323;

  pdf = exp ( - 0.5 * ( x[0] * x[0] + x[1] * x[1] ) ) / ( 2.0 * pi );

  return pdf;

}

double *circular_normal_01_sample ( int &seed )

{

  const double pi = 3.14159265358979323;

  double v1;

  double v2;

  double *x;

  x = new double[2];

  v1 = r8_uniform_01 ( seed );

  v2 = r8_uniform_01 ( seed );

  x[0] = sqrt ( - 2.0 * log ( v1 ) ) * cos ( 2.0 * pi * v2 );

  x[1] = sqrt ( - 2.0 * log ( v1 ) ) * sin ( 2.0 * pi * v2 );

  return x;

}

double *circular_normal_01_variance ( )

{

  double *variance;

  variance = new double[2];

  variance[0] = 1.0;

  variance[1] = 1.0;

  return variance;

}

double *circular_normal_mean ( double a[2], double b )

{

  double *mean;

  mean = new double[2];

  mean[0] = a[0];

  mean[1] = a[1];

  return mean;

}

double circular_normal_pdf ( double x[2], double a[2], double b )

{

  double d;

  double pdf;

  const double pi = 3.14159265358979323;

  d = ( pow ( x[0] - a[0], 2 ) 

      + pow ( x[1] - a[1], 2 ) ) / pow ( b, 2 );

  pdf = exp ( - 0.5 * d ) / ( 2.0 * b * b * pi );

  return pdf;

}

double *circular_normal_sample ( double a[2], double b, int &seed )

{

  const double pi = 3.14159265358979323;

  double r;

  double v1;

  double v2;

  double *x;

  x = new double[2];

  v1 = r8_uniform_01 ( seed );

  v2 = r8_uniform_01 ( seed );

  r = sqrt ( - 2.0 * log ( v1 ) );

  x[0] = a[0] + b * r * cos ( 2.0 * pi * v2 );

  x[1] = a[1] + b * r * sin ( 2.0 * pi * v2 );

  return x;

}

double *circular_normal_variance ( double a[2], double b )

{

  double *variance;

  variance = new double[2];

  variance[0] = b;

  variance[1] = b;

  return variance;

}

int combinatorial ( int n, int k )

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

double cosine_cdf ( double x, double a, double b )

{

  double cdf;

  const double pi = 3.14159265358979323;

  double y;

  if ( x <= a - pi * b )

  {

    cdf = 0.0;

  }

  else if ( x <= a + pi * b )

  {

    y = ( x - a ) / b;

    cdf = 0.5 + ( y + sin ( y ) ) / ( 2.0 * pi );

  }

  else if ( a + pi * b < x )

  {

    cdf = 1.0;

  }

  return cdf;

}

double cosine_cdf_inv ( double cdf, double a, double b )

{

  double cdf1;

  double cdf2;

  double cdf3;

  int it;

  int it_max = 100;

  const double pi = 3.14159265358979323;

  double tol = 0.0001;

  double x;

  double x1;

  double x2;

  double x3;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "COSINE_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = a - pi * b;

    return x;

  }

  else if ( 1.0 == cdf )

  {

    x = a + pi * b;

    return x;

  }

  x1 = a - pi * b;

  cdf1 = 0.0;

  x2 = a + pi * b;

  cdf2 = 1.0;

  it = 0;

  for ( it = 1; it <= it_max; it++ )

  {

    x3 = 0.5 * ( x1 + x2 );

    cdf3 = cosine_cdf ( x3, a, b );

    if ( r8_abs ( cdf3 - cdf ) < tol )

    {

      x = x3;

      return x;

    }

    if ( ( cdf3 <= cdf && cdf1 <= cdf ) || ( cdf <= cdf3 && cdf <= cdf1 ) )

    {

      x1 = x3;

      cdf1 = cdf3;

    }

    else

    {

      x2 = x3;

      cdf2 = cdf3;

    }

  }

  cerr << " \n";

  cerr << "COSINE_CDF_INV - Fatal error!\n";

  cerr << "  Iteration limit exceeded.\n";

  exit ( 1 );

}

bool cosine_check ( double a, double b )

{

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "COSINE_CHECK - Fatal error!\n";

    cerr << "  B <= 0.0\n";

    return false;

  }

  return true;

}

double cosine_mean ( double a, double b )

{

  double mean;

  mean = a;

  return mean;

}

double cosine_pdf ( double x, double a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  double y;

  if ( x < a - pi * b )

  {

    pdf = 0.0;

  }

  else if ( x <= a + pi * b )

  {

    y = ( x - a ) / b;

    pdf = 1.0 / ( 2.0 * pi * b ) * cos ( y );

  }

  else if ( a + pi * b < x )

  {

    pdf = 0.0;

  }

  return pdf;

}

double cosine_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = cosine_cdf_inv ( cdf, a, b );

  return x;

}

double cosine_variance ( double a, double b )

{

  const double pi = 3.14159265358979323;

  double variance;

  variance = ( pi * pi / 3.0 - 2.0 ) * b * b;

  return variance;

}

double coupon_complete_pdf ( int type_num, int box_num )

{

  double factor;

  int i;

  double pdf;

  if ( box_num < 0 )

  {

    pdf = 0.0;

  }

  else if ( type_num < 1 )

  {

    pdf = 0.0;

  }

  else if ( type_num == 1 )

  {

    if ( box_num == 1 )

    {

      pdf = 1.0;

    }

    else

    {

      pdf = 0.0;

    }

  }

  else if ( box_num < type_num )

  {

    pdf = 0.0;

  }

  else

  {

    factor = 1.0;

    for ( i = 1; i <= type_num; i++ )

    {

      factor = factor * ( double ) ( i ) / ( double ) ( type_num );

    }

    for ( i = type_num+1; i <= box_num; i++ )

    {

      factor = factor / ( double ) ( type_num );

    }

    pdf = factor * ( double ) ( stirling2_value ( box_num-1, type_num-1 ) );

  }

  return pdf;

}

double coupon_mean ( int j, int type_num )

{

  int i;

  double mean;

  if ( type_num < j )

  {

    cerr << " \n";

    cerr << "COUPON_MEAN - Fatal error!\n";

    cerr << "  Number of distinct coupons desired must be no more\n";

    cerr << "  than the total number of boxes opened.\n";

    exit ( 1 );

  }

  mean = 0.0;

  for ( i = 1; i <= j; i++ )

  {

    mean = mean + 1.0 / ( double ) ( type_num - i + 1 );

  }

  mean = mean * ( double ) ( type_num );

  return mean;

}

void coupon_simulate ( int type_num, int &seed, int coupon[], int *box_num )

{

  int i;

  int box_max = 2000;

  int straight;

  for ( i = 0; i < type_num; i++ )

  {

    coupon[i] = 0;

  }

  straight = 0;

  *box_num = 0;

  while ( *box_num < box_max )

  {

    i = i4_uniform_ab ( 1, type_num, seed );

    coupon[i-1] = coupon[i-1] + 1;

    *box_num = *box_num + 1;

    if ( i == straight + 1 )

    {

      for ( ; ; )

      {

        straight = straight + 1;

        if ( type_num <= straight )

        {

          return;

        }

        if ( coupon[straight] <= 0 )

        {

          break;

        }

      }

    }

  }

  cerr << " \n";

  cerr << "COUPON_SIMULATE - Fatal error!\n";

  cerr << "  Maximum number of coupons drawn without success.\n";

  exit ( 1 );

}

double coupon_variance ( int j, int type_num )

{

  int i;

  double variance;

  if ( type_num < j )

  {

    cerr << " \n";

    cerr << "COUPON_VARIANCE - Fatal error!\n";

    cerr << "  Number of distinct coupons desired must be no more\n";

    cerr << "  than the total number of distinct coupons.\n";

    exit ( 1 );

  }

  variance = 0.0;

  for ( i = 1; i <= j; i++ )

  {

    variance = variance + ( double ) ( i - 1 ) /

      pow ( ( double ) ( type_num - i + 1 ), 2 );

  }

  variance = variance * ( double ) ( type_num );

  return variance;

}

double deranged_cdf ( int x, int a )

{

  double cdf;

  int cnk;

  int dnmk;

  int sum2;

  int x2;

  if ( x < 0 || a < x )

  {

    cdf = 0.0;

  }

  else

  {

    sum2 = 0;

    for ( x2 = 0; x2 <= x; x2++ )

    {

      cnk = binomial_coef ( a, x2 );

      dnmk = deranged_enum ( a - x2 );

      sum2 = sum2 + cnk * dnmk;

    }

    cdf = ( double ) ( sum2 ) / i4_factorial ( a );

  }

  return cdf;

}

int deranged_cdf_inv ( double cdf, int a )

{

  double cdf2;

  double pdf;

  int x;

  int x2;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "DERANGED_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  cdf2 = 0.0;

  for ( x2 = 0; x2 <= a; x2++ )

  {

    pdf = deranged_pdf ( x2, a );

    cdf2 = cdf2 + pdf;

    if ( cdf <= cdf2 )

    {

      x = x2;

      return x;

    }

  }

  x = a;

  return x;

}

bool deranged_check ( int a )

{

  if ( a < 1 )

  {

    cerr << " \n";

    cerr << "DERANGED_CHECK - Fatal error!\n";

    cerr << "  A < 1.\n";

    return false;

  }

  return true;

}

int deranged_enum ( int n )

{

  int dn;

  int dnm1;

  int dnm2;

  int i;

  if ( n < 0 )

  {

    dn = 0;

  }

  else if ( n == 0 )

  {

    dn = 1;

  }

  else if ( n == 1 )

  {

    dn = 0;

  }

  else if ( n == 2 )

  {

    dn = 1;

  }

  else

  {

    dnm1 = 0;

    dn = 1;

    for ( i = 3; i <= n; i++ )

    {

      dnm2 = dnm1;

      dnm1 = dn;

      dn = ( i - 1 ) * ( dnm1 + dnm2 );

    }

  }

  return dn;

}

double deranged_mean ( int a )

{

  double mean;

  double pdf;

  int x;

  mean = 0.0;

  for ( x = 1; x <= a; x++ )

  {

    pdf = deranged_pdf ( x, a );

    mean = mean + pdf * x;

  }

  return mean;

}

double deranged_pdf ( int x, int a )

{

  int cnk;

  int dnmk;

  double pdf;

  if ( x < 0 || a < x )

  {

    pdf = 0.0;

  }

  else

  {

    cnk = binomial_coef ( a, x );

    dnmk = deranged_enum ( a-x );

    pdf = ( double ) ( cnk * dnmk ) / i4_factorial ( a );

  }

  return pdf;

}

int deranged_sample ( int a, int &seed )

{

  double cdf;

  int x;

  cdf = r8_uniform_01 ( seed );

  x = deranged_cdf_inv ( cdf, a );

  return x;

}

double deranged_variance ( int a )

{

  double mean;

  double pdf;

  int x;

  double variance;

  mean = deranged_mean ( a );

  variance = 0.0;

  for ( x = 1; x <= a; x++ )

  {

    pdf = deranged_pdf ( x, a );

    variance = variance + pdf * pow ( ( x - mean ), 2 );

  }

  return variance;

}

double digamma ( double x )

{

  double c = 8.5;

  double d1 = -0.5772156649;

  double r;

  double s = 0.00001;

  double s3 = 0.08333333333;

  double s4 = 0.0083333333333;

  double s5 = 0.003968253968;

  double value;

  double y;

  if ( x <= 0.0 )

  {

    value = 0.0;

    cerr << " \n";

    cerr << "DIGAMMA - Fatal error!\n";

    cerr << "  X <= 0.\n";

    exit ( 1 );

  }

  else if ( x <= s )

  {

    value = d1 - 1.0 / x;

  }

  else

  {

    value = 0.0;

    y = x;

    while ( y < c )

    {

      value = value - 1.0 / y;

      y = y + 1.0;

    }

    r = 1.0 / ( y * y );

    value = value + log ( y ) - 0.5 / y - r * ( s3 - r * ( s4 - r * s5 ) );

  }

  return value;

}

double dipole_cdf ( double x, double a, double b )

{

  double cdf;

  const double pi = 3.14159265358979323;

  cdf = 0.5 + ( 1.0 / pi ) * atan ( x ) + b * b * ( x * cos ( 2.0 * a )

    - sin ( 2.0 * a ) ) / ( pi * ( 1.0 + x * x ) );

  return cdf;

}

double dipole_cdf_inv ( double cdf, double a, double b )

{

  double cdf1;

  double cdf2;

  double cdf3;

  int it;

  int it_max = 100;

  double tol = 0.0001;

  double x;

  double x1;

  double x2;

  double x3;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "DIPOLE_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = - r8_huge ( );

    return x;

  }

  else if ( 1.0 == cdf )

  {

    x = r8_huge ( );

    return x;

  }

  x1 = - 1.0;

  for ( ; ; )

  {

    cdf1 = dipole_cdf ( x1, a, b );

    if ( cdf1 <= cdf )

    {

      break;

    }

    x1 = 2.0 * x1;

  }

  x2 = 1.0;

  for ( ; ; )

  {

    cdf2 = dipole_cdf ( x2, a, b );

    if ( cdf <= cdf2 )

    {

      break;

    }

    x2 = 2.0 * x2;

  }

  it = 0;

  for ( ; ; )

  {

    it = it + 1;

    x3 = 0.5 * ( x1 + x2 );

    cdf3 = dipole_cdf ( x3, a, b );

    if ( r8_abs ( cdf3 - cdf ) < tol )

    {

      x = x3;

      break;

    }

    if ( it_max < it )

    {

      cerr << " \n";

      cerr << "DIPOLE_CDF_INV - Fatal error!\n";

      cerr << "  Iteration limit exceeded.\n";

      exit ( 1 );

    }

    if ( ( cdf3 <= cdf && cdf1 <= cdf ) || ( cdf <= cdf3 && cdf <= cdf1 ) )

    {

      x1 = x3;

      cdf1 = cdf3;

    }

    else

    {

      x2 = x3;

      cdf2 = cdf3;

    }

  }

  return x;

}

bool dipole_check ( double a, double b )

{

  if ( b < -1.0 || 1.0 < b )

  {

    cerr << " \n";

    cerr << "DIPOLE_CHECK - Fatal error!\n";

    cerr << "  -1.0 <= B <= 1.0 is required.\n";

    cerr << "  The input B = " << b << "\n";

    return false;

  }

  return true;

}

double dipole_pdf ( double x, double a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  pdf = 1.0 / ( pi * ( 1.0 + x * x ) )

    + b * b * ( ( 1.0 - x * x ) * cos ( 2.0 * a )

    + 2.0 * x * sin ( 2.0 * x ) )

    / ( pi * ( 1.0 + x * x ) * ( 1.0 + x * x ) );

  return pdf;

}

double dipole_sample ( double a, double b, int &seed )

{

  double a2;

  double b2;

  double c2;

  double x;

  double *xc;

  a2 = b * sin ( a );

  b2 = b * cos ( a );

  c2 = 1.0;

  xc = circle_sample ( a2, b2, c2, seed );

  x = xc[0] / xc[1];

  delete [] xc;

  return x;

}

bool dirichlet_check ( int n, double a[] )

{

  int i;

  bool positive;

  positive = false;

  for ( i = 0; i < n; i++ )

  {

    if ( a[i] <= 0.0 )

    {

      cerr << " \n";

      cerr << "DIRICHLET_CHECK - Fatal error!\n";

      cerr << "  A[" << i << "] <= 0.\n";

      cerr << "  A[" << i << "] = " << a[i] << ".\n";

      return false;

    }

    else if ( 0.0 < a[i] )

    {

      positive = true;

    }

  }

  if ( !positive )

  {

    cerr << " \n";

    cerr << "DIRICHLET_CHECK - Fatal error!\n";

    cerr << "  All parameters are zero!\n";

    return false;

  }

  return true;

}

double *dirichlet_mean ( int n, double a[] )

{

  int i;

  double *mean;

  mean = new double[n];

  for ( i = 0; i < n; i++ )

  {

    mean[i] = a[i];

  }

  r8vec_unit_sum ( n, mean );

  return mean;

}

double *dirichlet_moment2 ( int n, double a[] )

{

  double a_sum;

  double *m2;

  int i;

  int j;

  m2 = new double[n*n];

  a_sum = r8vec_sum ( n, a );

  for ( i = 0; i < n; i++ )

  {

    for ( j = 0; j < n; j++ )

    {

      if ( i == j )

      {

        m2[i+j*n] = a[i] * ( a[i] + 1.0 ) / ( a_sum * ( a_sum + 1.0 ) );

      }

      else

      {

        m2[i+j*n] = a[i] * a[j] / ( a_sum * ( a_sum + 1.0 ) );

      }

    }

  }

  return m2;

}

double dirichlet_pdf ( double x[], int n, double a[] )

{

  double a_prod;

  double a_sum;

  int i;

  double pdf;

  double tol = 0.0001;

  double x_sum;

  for ( i = 0; i < n; i++ )

  {

    if ( x[i] <= 0.0 )

    {

      cerr << " \n";

      cerr << "DIRICHLET_PDF - Fatal error!\n";

      cerr << "  X(I) <= 0.\n";

      exit ( 1 );

    }

  }

  x_sum = r8vec_sum ( n, x );

  if ( tol < r8_abs ( x_sum - 1.0 ) )

  {

    cerr << " \n";

    cerr << "DIRICHLET_PDF - Fatal error!\n";

    cerr << "  SUM X(I) =/= 1.\n";

    exit ( 1 );

  }

  a_sum = r8vec_sum ( n, a );

  a_prod = 1.0;

  for ( i = 0; i < n; i++ )

  {

    a_prod = a_prod * r8_gamma ( a[i] );

  }

  pdf = r8_gamma ( a_sum ) / a_prod;

  for ( i = 0; i < n; i++ )

  {

    pdf = pdf * pow ( x[i], a[i] - 1.0 );

  }

  return pdf;

}

double *dirichlet_sample ( int n, double a[], int &seed )

{

  double a2;

  double b2;

  double c2;

  int i;

  double *x;

  x = new double[n];

  a2 = 0.0;

  b2 = 1.0;

  for ( i = 0; i < n; i++ )

  {

    c2 = a[i];

    x[i] = gamma_sample ( a2, b2, c2, seed );

  }

  r8vec_unit_sum ( n, x );

  return x;

}

double *dirichlet_variance ( int n, double a[] )

{

  double a_sum;

  int i;

  double *variance;

  variance = new double[n];

  a_sum = r8vec_sum ( n, a );

  for ( i = 0; i < n; i++ )

  {

    variance[i] = a[i] * ( a_sum - a[i] ) / ( a_sum * a_sum * ( a_sum + 1.0 ) );

  }

  return variance;

}

bool dirichlet_mix_check ( int comp_num, int elem_num, double a[],

  double comp_weight[] )

{

  int comp_i;

  int elem_i;

  bool positive;

  for ( comp_i = 0; comp_i < comp_num; comp_i++ )

  {

    for ( elem_i = 0; elem_i < elem_num; elem_i++ )

    {

      if ( a[elem_i+comp_i*elem_num] <= 0.0 )

      {

        cerr << " \n";

        cerr << "DIRICHLET_MIX_CHECK - Fatal error!\n";

        cerr << "  A(ELEM,COMP) <= 0.\n";

        cerr << "  COMP = " << comp_i << "\n";

        cerr << "  ELEM = " << elem_i << "\n";

        cerr << "  A(COMP,ELEM) = " << a[elem_i+comp_i*elem_num] << "\n";

        return false;

      }

    }

  }

  positive = false;

  for ( comp_i = 0; comp_i < comp_num; comp_i++ )

  {

    if ( comp_weight[comp_i] < 0.0 )

    {

      cerr << " \n";

      cerr << "DIRICHLET_MIX_CHECK - Fatal error!\n";

      cerr << "  COMP_WEIGHT(COMP) < 0.\n";

      cerr << "  COMP = " << comp_i << "\n";

      cerr << "  COMP_WEIGHT(COMP) = " << comp_weight[comp_i] << "\n";

      return false;

    }

    else if ( 0.0 < comp_weight[comp_i] )

    {

      positive = true;

    }

  }

  if ( !positive )

  {

    cerr << " \n";

    cerr << "DIRICHLET_MIX_CHECK - Fatal error!\n";

    cerr << "  All component weights are zero.\n";

    return false;

  }

  return true;

}

double *dirichlet_mix_mean ( int comp_num, int elem_num, double a[],

  double comp_weight[] )

{

  double *a_vec;

  int comp_i;

  double *comp_mean;

  double comp_weight_sum;

  int elem_i;

  double *mean;

  a_vec = new double[elem_num];

  mean = new double[elem_num];

  comp_weight_sum = 0.0;

  for ( comp_i = 0; comp_i < comp_num; comp_i++ )

  {

    comp_weight_sum = comp_weight_sum + comp_weight[comp_i];

  }

  for ( elem_i = 0; elem_i < elem_num; elem_i++ )

  {

    mean[elem_i] = 0.0;

  }

  for ( comp_i = 0; comp_i < comp_num; comp_i++ )

  {

    for ( elem_i = 0; elem_i < elem_num; elem_i++ )

    {

      a_vec[elem_i] = a[elem_i+comp_i*elem_num];

    }

    comp_mean = dirichlet_mean ( elem_num, a_vec );

    for ( elem_i = 0; elem_i < elem_num; elem_i++ )

    {

      mean[elem_i] = mean[elem_i] + comp_weight[comp_i] * comp_mean[elem_i];

    }

    delete [] comp_mean;

  }

  for ( elem_i = 0; elem_i < elem_num; elem_i++ )

  {

    mean[elem_i] = mean[elem_i] / comp_weight_sum;

  }

  delete [] a_vec;

  return mean;

}

double dirichlet_mix_pdf ( double x[], int comp_num, int elem_num, double a[],

  double comp_weight[] )

{

  double *a_vec;

  double comp_pdf;

  double comp_weight_sum;

  int i;

  int j;

  double pdf;

  a_vec = new double[elem_num];

  comp_weight_sum = 0.0;

  for ( j = 0; j < comp_num; j++ )

  {

    comp_weight_sum = comp_weight_sum + comp_weight[j];

  }

  pdf = 0.0;

  for ( j = 0; j < comp_num; j++ )

  {

    for ( i = 0; i < elem_num; i++ )

    {

      a_vec[i] = a[i+j*elem_num];

    }

    comp_pdf = dirichlet_pdf ( x, elem_num, a_vec );

    pdf = pdf + comp_weight[j] * comp_pdf / comp_weight_sum;

  }

  delete [] a_vec;

  return pdf;

}

double *dirichlet_mix_sample ( int comp_num, int elem_num, double a[],

  double comp_weight[], int &seed, int *comp )

{

  double *a_vec;

  int elem_i;

  double *x;

  a_vec = new double[elem_num];

  *comp = discrete_sample ( comp_num, comp_weight, seed );

  for ( elem_i = 0; elem_i < elem_num; elem_i++ )

  {

    a_vec[elem_i] = a[elem_i+(*comp-1)*elem_num];

  }

  x = dirichlet_sample ( elem_num, a_vec, seed );

  delete [] a_vec;

  return x;

}

double dirichlet_multinomial_pdf ( int x[], int a, int b, double c[] )

{

  double c_sum;

  int i;

  double pdf;

  double pdf_log;

  c_sum = r8vec_sum ( b, c );

  pdf_log = - gamma_log ( c_sum + ( double ) ( a ) ) + gamma_log ( c_sum )

    + gamma_log ( ( double ) ( a + 1 ) );

  for ( i = 0; i < b; i++ )

  {

    pdf_log = pdf_log + gamma_log ( c[i] + ( double ) ( x[i] ) )

      - gamma_log ( c[i] ) - gamma_log ( ( double ) ( x[i] + 1 ) );

  }

  pdf = exp ( pdf_log );

  return pdf;

}

double discrete_cdf ( int x, int a, double b[] )

{

  double cdf;

  if ( x < 1 )

  {

    cdf = 0.0;

  }

  else if ( x < a )

  {

    cdf = r8vec_sum ( x, b ) / r8vec_sum ( a, b );

  }

  else if ( a <= x )

  {

    cdf = 1.0;

  }

  return cdf;

}

int discrete_cdf_inv ( double cdf, int a, double b[] )

{

  double b_sum;

  double cum;

  int j;

  int x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "DISCRETE_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  b_sum = r8vec_sum ( a, b );

  cum = 0.0;

  for ( j = 1; j <= a; j++ )

  {

    cum = cum + b[j-1] / b_sum;

    if ( cdf <= cum )

    {

      x = j;

      return x;

    }

  }

  x = a;

  return x;

}

bool discrete_check ( int a, double b[] )

{

  double b_sum;

  int j;

  for ( j = 0; j < a; j++ )

  {

    if ( b[j] < 0.0 )

    {

      cerr << " \n";

      cerr << "DISCRETE_CHECK - Fatal error!\n";

      cerr << "  Negative probabilities not allowed.\n";

      return false;

    }

  }

  b_sum = r8vec_sum ( a, b );

  if ( b_sum == 0.0 )

  {

    cerr << " \n";

    cerr << "DISCRETE_CHECK - Fatal error!\n";

    cerr << "  Total probablity is zero.\n";

    return false;

  }

  return true;

}

double discrete_mean ( int a, double b[] )

{

  double b_sum;

  int j;

  double mean;

  b_sum = r8vec_sum ( a, b );

  mean = 0.0;

  for ( j = 0; j < a; j++ )

  {

    mean = mean + ( double ) ( j + 1 ) * b[j];

  }

  mean = mean / b_sum;

  return mean;

}

double discrete_pdf ( int x, int a, double b[] )

{

  double b_sum;

  double pdf;

  b_sum = r8vec_sum ( a, b );

  if ( 1 <= x && x <= a )

  {

    pdf = b[x-1] / b_sum;

  }

  else

  {

    pdf = 0.0;

  }

  return pdf;

}

int discrete_sample ( int a, double b[], int &seed )

{

  double b_sum;

  double cdf;

  int x;

  b_sum = r8vec_sum ( a, b );

  cdf = r8_uniform_01 ( seed );

  x = discrete_cdf_inv ( cdf, a, b );

  return x;

}

double discrete_variance ( int a, double b[] )

{

  double b_sum;

  int j;

  double mean;

  double variance;

  b_sum = r8vec_sum ( a, b );

  mean = 0.0;

  for ( j = 1; j <= a; j++ )

  {

    mean = mean + ( double ) ( j ) * b[j-1];

  }

  mean = mean / b_sum;

  variance = 0.0;

  for ( j = 1; j <= a; j++ )

  {

    variance = variance + b[j-1] * pow ( ( double ) j - mean, 2 );

  }

  variance = variance / b_sum;

  return variance;

}

double e_constant ( )

{

  double value = 2.71828182845904523536028747135266249775724709369995;

  return value;

}

double empirical_discrete_cdf ( double x, int a, double b[], double c[] )

{

  double bsum;

  double cdf;

  int i;

  cdf = 0.0;

  bsum = r8vec_sum ( a, b );

  for ( i = 1; i <= a; i++ )

  {

    if ( x < c[i-1] )

    {

      return cdf;

    }

    cdf = cdf + b[i-1] / bsum;

  }

  return cdf;

}

double empirical_discrete_cdf_inv ( double cdf, int a, double b[], double c[] )

{

  double bsum;

  double cdf2;

  int i;

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "EMPIRICAL_DISCRETE_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  bsum = r8vec_sum ( a, b );

  x = c[0];

  cdf2 = b[0] / bsum;

  for ( i = 1; i < a; i++ )

  {

    if ( cdf <= cdf2 )

    {

      return x;

    }

    x = c[i];

    cdf2 = cdf2 + b[i] / bsum;

  }

  return x;

}

bool empirical_discrete_check ( int a, double b[], double c[] )

{

  int i;

  int j;

  bool positive;

  if ( a <= 0 )

  {

    cerr << " \n";

    cerr << "EMPIRICAL_DISCRETE_CHECK - Fatal error!\n";

    cerr << "  A must be positive.\n";

    cerr << "  Input A = " << a << "\n";

    cerr << "  A is the number of weights.\n";

    return false;

  }

  for ( i = 0; i < a; i++ )

  {

    if ( b[i] < 0.0 )

    {

      cerr << " \n";

      cerr << "EMPIRICAL_DISCRETE_CHECK - Fatal error!\n";

      cerr << "  B[" << i << "] < 0.\n";

      cerr << "  But all B values must be nonnegative.\n";

      return false;

    }

  }

  positive = false;

  for ( i = 0; i < a; i++ )

  {

    if ( 0.0 < b[i] )

    {

      positive = true;

    }

  }

  if ( !positive )

  {

    cerr << " \n";

    cerr << "EMPIRICAL_DISCRETE_CHECK - Fatal error!\n";

    cerr << "  All B(*) = 0.\n";

    cerr << "  But at least one B values must be nonzero.\n";

    return false;

  }

  for ( i = 0; i < a; i++ )

  {

    for ( j = i+1; j < a; j++ )

    {

      if ( c[i] == c[j] )

      {

        cerr << " \n";

        cerr << "EMPIRICAL_DISCRETE_CHECK - Fatal error!\n";

        cerr << "  All values C must be unique.\n";

        cerr << "  But at least two values are identical.\n";

        return false;

      }

    }

  }

  for ( i = 0; i < a-1; i++ )

  {

    if ( c[i+1] < c[i] )

    {

      cerr << " \n";

      cerr << "EMPIRICAL_DISCRETE_CHECK - Fatal error!\n";

      cerr << "  The values in C must be in ascending order.\n";

      return false;

    }

  }

  return true;

}

double empirical_discrete_mean ( int a, double b[], double c[] )

{

  int i;

  double mean;

  mean = 0.0;

  for ( i = 0; i < a; i++ )

  {

    mean = mean + b[i] * c[i];

  }

  mean = mean / r8vec_sum ( a, b );

  return mean;

}

double empirical_discrete_pdf ( double x, int a, double b[], double c[] )

{

  int i;

  double pdf;

  for ( i = 0; i <= a; i++ )

  {

    if ( x == c[i] )

    {

      pdf = b[i] / r8vec_sum ( a, b );

      return pdf;

    }

  }

  pdf = 0.0;

  return pdf;

}

double empirical_discrete_sample ( int a, double b[], double c[], int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = empirical_discrete_cdf_inv ( cdf, a, b, c );

  return x;

}

double empirical_discrete_variance ( int a, double b[], double c[] )

{

  double bsum;

  int i;

  double mean;

  double variance;

  bsum = r8vec_sum ( a, b );

  mean = empirical_discrete_mean ( a, b, c );

  variance = 0.0;

  for ( i = 0; i < a; i++ )

  {

    variance = variance + ( b[i] / bsum ) * pow ( c[i] - mean, 2 );

  }

  return variance;

}

double english_sentence_length_cdf ( int x )

{

# define SENTENCE_LENGTH_MAX 79

  double cdf;

  int i;

  double pdf_vec[SENTENCE_LENGTH_MAX] = {

    0.00806,

    0.01370,

    0.01862,

    0.02547,

    0.03043,

    0.03189,

    0.03516,

    0.03545,

    0.03286,

    0.03533,

    0.03562,

    0.03788,

    0.03669,

    0.03751,

    0.03518,

    0.03541,

    0.03434,

    0.03305,

    0.03329,

    0.03103,

    0.02867,

    0.02724,

    0.02647,

    0.02526,

    0.02086,

    0.02178,

    0.02128,

    0.01801,

    0.01690,

    0.01556,

    0.01512,

    0.01326,

    0.01277,

    0.01062,

    0.01051,

    0.00901,

    0.00838,

    0.00764,

    0.00683,

    0.00589,

    0.00624,

    0.00488,

    0.00477,

    0.00406,

    0.00390,

    0.00350,

    0.00318,

    0.00241,

    0.00224,

    0.00220,

    0.00262,

    0.00207,

    0.00174,

    0.00174,

    0.00128,

    0.00121,

    0.00103,

    0.00117,

    0.00124,

    0.00082,

    0.00088,

    0.00061,

    0.00061,

    0.00075,

    0.00063,

    0.00056,

    0.00052,

    0.00057,

    0.00031,

    0.00029,

    0.00021,

    0.00017,

    0.00021,

    0.00034,

    0.00031,

    0.00011,

    0.00011,

    0.00008,

    0.00006 };

  double pdf_sum = 0.99768;

  if ( x < 1 )

  {

    cdf = 0.0;

  }

  else if ( x < SENTENCE_LENGTH_MAX )

  {

    cdf = 0.0;

    for ( i = 0; i < x; i++ )

    {

      cdf = cdf + pdf_vec[i];

    }

    cdf = cdf / pdf_sum;

  }

  else if ( SENTENCE_LENGTH_MAX <= x )

  {

    cdf = 1.0;

  }

  return cdf;

# undef SENTENCE_LENGTH_MAX

}

int english_sentence_length_cdf_inv ( double cdf )

{

# define SENTENCE_LENGTH_MAX 79

  double cum;

  int j;

  double pdf_vec[SENTENCE_LENGTH_MAX] = {

    0.00806,

    0.01370,

    0.01862,

    0.02547,

    0.03043,

    0.03189,

    0.03516,

    0.03545,

    0.03286,

    0.03533,

    0.03562,

    0.03788,

    0.03669,

    0.03751,

    0.03518,

    0.03541,

    0.03434,

    0.03305,

    0.03329,

    0.03103,

    0.02867,

    0.02724,

    0.02647,

    0.02526,

    0.02086,

    0.02178,

    0.02128,

    0.01801,

    0.01690,

    0.01556,

    0.01512,

    0.01326,

    0.01277,

    0.01062,

    0.01051,

    0.00901,

    0.00838,

    0.00764,

    0.00683,

    0.00589,

    0.00624,

    0.00488,

    0.00477,

    0.00406,

    0.00390,

    0.00350,

    0.00318,

    0.00241,

    0.00224,

    0.00220,

    0.00262,

    0.00207,

    0.00174,

    0.00174,

    0.00128,

    0.00121,

    0.00103,

    0.00117,

    0.00124,

    0.00082,

    0.00088,

    0.00061,

    0.00061,

    0.00075,

    0.00063,

    0.00056,

    0.00052,

    0.00057,

    0.00031,

    0.00029,

    0.00021,

    0.00017,

    0.00021,

    0.00034,

    0.00031,

    0.00011,

    0.00011,

    0.00008,

    0.00006 };

  double pdf_sum = 0.99768;

  int x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "ENGLISH_SENTENCE_LENGTH_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  cum = 0.0;

  for ( j = 0; j < SENTENCE_LENGTH_MAX; j++ )

  {

    cum = cum + pdf_vec[j];

    if ( cdf <= cum / pdf_sum )

    {

      x = j + 1;

      return x;

    }

  }

  x = SENTENCE_LENGTH_MAX;

  return x;

# undef SENTENCE_LENGTH_MAX

}

double english_sentence_length_mean ( )

{

# define SENTENCE_LENGTH_MAX 79

  int j;

  double mean;

  double pdf_vec[SENTENCE_LENGTH_MAX] = {

    0.00806,

    0.01370,

    0.01862,

    0.02547,

    0.03043,

    0.03189,

    0.03516,

    0.03545,

    0.03286,

    0.03533,

    0.03562,

    0.03788,

    0.03669,

    0.03751,

    0.03518,

    0.03541,

    0.03434,

    0.03305,

    0.03329,

    0.03103,

    0.02867,

    0.02724,

    0.02647,

    0.02526,

    0.02086,

    0.02178,

    0.02128,

    0.01801,

    0.01690,

    0.01556,

    0.01512,

    0.01326,

    0.01277,

    0.01062,

    0.01051,

    0.00901,

    0.00838,

    0.00764,

    0.00683,

    0.00589,

    0.00624,

    0.00488,

    0.00477,

    0.00406,

    0.00390,

    0.00350,

    0.00318,

    0.00241,

    0.00224,

    0.00220,

    0.00262,

    0.00207,

    0.00174,

    0.00174,

    0.00128,

    0.00121,

    0.00103,

    0.00117,

    0.00124,

    0.00082,

    0.00088,

    0.00061,

    0.00061,

    0.00075,

    0.00063,

    0.00056,

    0.00052,

    0.00057,

    0.00031,

    0.00029,

    0.00021,

    0.00017,

    0.00021,

    0.00034,

    0.00031,

    0.00011,

    0.00011,

    0.00008,

    0.00006 };

  double pdf_sum = 0.99768;

  mean = 0.0;

  for ( j = 1; j <= SENTENCE_LENGTH_MAX; j++ )

  {

    mean = mean + ( double ) ( j ) * pdf_vec[j-1];

  }

  mean = mean / pdf_sum;

  return mean;

# undef SENTENCE_LENGTH_MAX

}

double english_sentence_length_pdf ( int x )

{

# define SENTENCE_LENGTH_MAX 79

  double pdf;

  double pdf_vec[SENTENCE_LENGTH_MAX] = {

    0.00806,

    0.01370,

    0.01862,

    0.02547,

    0.03043,

    0.03189,

    0.03516,

    0.03545,

    0.03286,

    0.03533,

    0.03562,

    0.03788,

    0.03669,

    0.03751,

    0.03518,

    0.03541,

    0.03434,

    0.03305,

    0.03329,

    0.03103,

    0.02867,

    0.02724,

    0.02647,

    0.02526,

    0.02086,

    0.02178,

    0.02128,

    0.01801,

    0.01690,

    0.01556,

    0.01512,

    0.01326,

    0.01277,

    0.01062,

    0.01051,

    0.00901,

    0.00838,

    0.00764,

    0.00683,

    0.00589,

    0.00624,

    0.00488,

    0.00477,

    0.00406,

    0.00390,

    0.00350,

    0.00318,

    0.00241,

    0.00224,

    0.00220,

    0.00262,

    0.00207,

    0.00174,

    0.00174,

    0.00128,

    0.00121,

    0.00103,

    0.00117,

    0.00124,

    0.00082,

    0.00088,

    0.00061,

    0.00061,

    0.00075,

    0.00063,

    0.00056,

    0.00052,

    0.00057,

    0.00031,

    0.00029,

    0.00021,

    0.00017,

    0.00021,

    0.00034,

    0.00031,

    0.00011,

    0.00011,

    0.00008,

    0.00006 };

  double pdf_sum = 0.99768;

  if ( 1 <= x && x <= SENTENCE_LENGTH_MAX )

  {

    pdf = pdf_vec[x-1] / pdf_sum;

  }

  else

  {

    pdf = 0.0;

  }

  return pdf;

# undef SENTENCE_LENGTH_MAX

}

int english_sentence_length_sample ( int &seed )

{

  double cdf;

  int x;

  cdf = r8_uniform_01 ( seed );

  x = english_sentence_length_cdf_inv ( cdf );

  return x;

# undef SENTENCE_LENGTH_MAX

}

double english_sentence_length_variance ( )

{

# define SENTENCE_LENGTH_MAX 79

  int j;

  double mean;

  double pdf_vec[SENTENCE_LENGTH_MAX] = {

    0.00806,

    0.01370,

    0.01862,

    0.02547,

    0.03043,

    0.03189,

    0.03516,

    0.03545,

    0.03286,

    0.03533,

    0.03562,

    0.03788,

    0.03669,

    0.03751,

    0.03518,

    0.03541,

    0.03434,

    0.03305,

    0.03329,

    0.03103,

    0.02867,

    0.02724,

    0.02647,

    0.02526,

    0.02086,

    0.02178,

    0.02128,

    0.01801,

    0.01690,

    0.01556,

    0.01512,

    0.01326,

    0.01277,

    0.01062,

    0.01051,

    0.00901,

    0.00838,

    0.00764,

    0.00683,

    0.00589,

    0.00624,

    0.00488,

    0.00477,

    0.00406,

    0.00390,

    0.00350,

    0.00318,

    0.00241,

    0.00224,

    0.00220,

    0.00262,

    0.00207,

    0.00174,

    0.00174,

    0.00128,

    0.00121,

    0.00103,

    0.00117,

    0.00124,

    0.00082,

    0.00088,

    0.00061,

    0.00061,

    0.00075,

    0.00063,

    0.00056,

    0.00052,

    0.00057,

    0.00031,

    0.00029,

    0.00021,

    0.00017,

    0.00021,

    0.00034,

    0.00031,

    0.00011,

    0.00011,

    0.00008,

    0.00006 };

  double pdf_sum = 0.99768;

  double variance;

  mean = 0.0;

  for ( j = 1; j <= SENTENCE_LENGTH_MAX; j++ )

  {

    mean = mean + ( double ) ( j ) * pdf_vec[j-1];

  }

  mean = mean / pdf_sum;

  variance = 0.0;

  for ( j = 1; j <= SENTENCE_LENGTH_MAX; j++ )

  {

    variance = variance + pdf_vec[j-1] * pow ( ( double ) j - mean, 2 );

  }

  variance = variance / pdf_sum;

  return variance;

# undef SENTENCE_LENGTH_MAX

}

double english_word_length_cdf ( int x )

{

# define WORD_LENGTH_MAX 27

  double cdf;

  int i;

  double pdf_vec[WORD_LENGTH_MAX] = {

    0.03160,

    0.16975,

    0.21192,

    0.15678,

    0.10852,

    0.08524,

    0.07724,

    0.05623,

    0.04032,

    0.02766,

    0.01582,

    0.00917,

    0.00483,

    0.00262,

    0.00099,

    0.00050,

    0.00027,

    0.00022,

    0.00011,

    0.00006,

    0.00005,

    0.00002,

    0.00001,

    0.00001,

    0.00001,

    0.00001,

    0.00001 };

  double pdf_sum = 0.99997;

  if ( x < 1 )

  {

    cdf = 0.0;

  }

  else if ( x < WORD_LENGTH_MAX )

  {

    cdf = 0.0;

    for ( i = 0; i < x; i++ )

    {

      cdf = cdf + pdf_vec[i];

    }

    cdf = cdf / pdf_sum;

  }

  else if ( WORD_LENGTH_MAX <= x )

  {

    cdf = 1.0;

  }

  return cdf;

# undef WORD_LENGTH_MAX

}

int english_word_length_cdf_inv ( double cdf )

{

# define WORD_LENGTH_MAX 27

  double cum;

  int j;

  double pdf_vec[WORD_LENGTH_MAX] = {

    0.03160,

    0.16975,

    0.21192,

    0.15678,

    0.10852,

    0.08524,

    0.07724,

    0.05623,

    0.04032,

    0.02766,

    0.01582,

    0.00917,

    0.00483,

    0.00262,

    0.00099,

    0.00050,

    0.00027,

    0.00022,

    0.00011,

    0.00006,

    0.00005,

    0.00002,

    0.00001,

    0.00001,

    0.00001,

    0.00001,

    0.00001 };

  double pdf_sum = 0.99997;

  int x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "ENGLISH_WORD_LENGTH_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  cum = 0.0;

  for ( j = 0; j < WORD_LENGTH_MAX; j++ )

  {

    cum = cum + pdf_vec[j];

    if ( cdf <= cum / pdf_sum )

    {

      x = j + 1;

      return x;

    }

  }

  x = WORD_LENGTH_MAX;

  return x;

# undef WORD_LENGTH_MAX

}

double english_word_length_mean ( )

{

# define WORD_LENGTH_MAX 27

  int j;

  double mean;

  double pdf_vec[WORD_LENGTH_MAX] = {

    0.03160,

    0.16975,

    0.21192,

    0.15678,

    0.10852,

    0.08524,

    0.07724,

    0.05623,

    0.04032,

    0.02766,

    0.01582,

    0.00917,

    0.00483,

    0.00262,

    0.00099,

    0.00050,

    0.00027,

    0.00022,

    0.00011,

    0.00006,

    0.00005,

    0.00002,

    0.00001,

    0.00001,

    0.00001,

    0.00001,

    0.00001 };

  double pdf_sum = 0.99997;

  mean = 0.0;

  for ( j = 1; j <= WORD_LENGTH_MAX; j++ )

  {

    mean = mean + ( double ) ( j ) * pdf_vec[j-1];

  }

  mean = mean / pdf_sum;

  return mean;

# undef WORD_LENGTH_MAX

}

double english_word_length_pdf ( int x )

{

# define WORD_LENGTH_MAX 27

  double pdf;

  double pdf_vec[WORD_LENGTH_MAX] = {

    0.03160,

    0.16975,

    0.21192,

    0.15678,

    0.10852,

    0.08524,

    0.07724,

    0.05623,

    0.04032,

    0.02766,

    0.01582,

    0.00917,

    0.00483,

    0.00262,

    0.00099,

    0.00050,

    0.00027,

    0.00022,

    0.00011,

    0.00006,

    0.00005,

    0.00002,

    0.00001,

    0.00001,

    0.00001,

    0.00001,

    0.00001 };

  double pdf_sum = 0.99997;

  if ( 1 <= x && x <= WORD_LENGTH_MAX )

  {

    pdf = pdf_vec[x-1] / pdf_sum;

  }

  else

  {

    pdf = 0.0;

  }

  return pdf;

# undef WORD_LENGTH_MAX

}

int english_word_length_sample ( int &seed )

{

  double cdf;

  int x;

  cdf = r8_uniform_01 ( seed );

  x = english_word_length_cdf_inv ( cdf );

  return x;

# undef WORD_LENGTH_MAX

}

double english_word_length_variance ( )

{

# define WORD_LENGTH_MAX 27

  int j;

  double mean;

  double pdf_vec[WORD_LENGTH_MAX] = {

    0.03160,

    0.16975,

    0.21192,

    0.15678,

    0.10852,

    0.08524,

    0.07724,

    0.05623,

    0.04032,

    0.02766,

    0.01582,

    0.00917,

    0.00483,

    0.00262,

    0.00099,

    0.00050,

    0.00027,

    0.00022,

    0.00011,

    0.00006,

    0.00005,

    0.00002,

    0.00001,

    0.00001,

    0.00001,

    0.00001,

    0.00001 };

  double pdf_sum = 0.99997;

  double variance;

  mean = 0.0;

  for ( j = 1; j <= WORD_LENGTH_MAX; j++ )

  {

    mean = mean + ( double ) ( j ) * pdf_vec[j-1];

  }

  mean = mean / pdf_sum;

  variance = 0.0;

  for ( j = 1; j <= WORD_LENGTH_MAX; j++ )

  {

    variance = variance + pdf_vec[j-1] * pow ( ( double ) j - mean, 2 );

  }

  variance = variance / pdf_sum;

  return variance;

# undef WORD_LENGTH_MAX

}

double erlang_cdf ( double x, double a, double b, int c )

{

  double cdf;

  double p2;

  double x2;

  if ( x < a )

  {

    cdf = 0.0;

  }

  else

  {

    x2 = ( x - a ) / b;

    p2 = ( double ) ( c );

    cdf = gamma_inc ( p2, x2 );

  }

  return cdf;

}

double erlang_cdf_inv ( double cdf, double a, double b, int c )

{

  double cdf1;

  double cdf2;

  double cdf3;

  int it;

  int it_max = 100;

  double tol = 0.0001;

  double x;

  double x1;

  double x2;

  double x3;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "ERLANG_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = a;

    return x;

  }

  else if ( 1.0 == cdf )

  {

    x = r8_huge ( );

    return x;

  }

  x1 = a;

  cdf1 = 0.0;

  x2 = a + 1.0;

  for ( ; ; )

  {

    cdf2 = erlang_cdf ( x2, a, b, c );

    if ( cdf < cdf2 )

    {

      break;

    }

    x2 = a + 2.0 * ( x2 - a );

  }

  it = 0;

  for ( ; ; )

  {

    it = it + 1;

    x3 = 0.5 * ( x1 + x2 );

    cdf3 = erlang_cdf ( x3, a, b, c );

    if ( r8_abs ( cdf3 - cdf ) < tol )

    {

      x = x3;

      break;

    }

    if ( it_max < it )

    {

      cout << " \n";

      cout << "ERLANG_CDF_INV - Warning!\n";

      cout << "  Iteration limit exceeded.\n";

      return x;

    }

    if ( ( cdf3 <= cdf && cdf1 <= cdf ) || ( cdf <= cdf3 && cdf <= cdf1 ) )

    {

      x1 = x3;

      cdf1 = cdf3;

    }

    else

    {

      x2 = x3;

      cdf2 = cdf3;

    }

  }

  return x;

}

bool erlang_check ( double a, double b, int c )

{

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "ERLANG_CHECK - Fatal error!\n";

    cerr << "  B <= 0.0\n";

    return false;

  }

  if ( c <= 0 )

  {

    cerr << " \n";

    cerr << "ERLANG_CHECK - Fatal error!\n";

    cerr << "  C <= 0.\n";

    return false;

  }

  return true;

}

double erlang_mean ( double a, double b, int c )

{

  double mean;

  mean = a + b * ( double ) ( c );

  return mean;

}

double erlang_pdf ( double x, double a, double b, int c )

{

  double pdf;

  double y;

  if ( x <= a )

  {

    pdf = 0.0;

  }

  else

  {

    y = ( x - a ) / b;

    pdf = pow ( y, c - 1 )

      / ( b * i4_factorial ( c - 1 ) * exp ( y ) );

  }

  return pdf;

}

double erlang_sample ( double a, double b, int c, int &seed )

{

  double a2;

  double b2;

  int i;

  double x;

  double x2;

  a2 = 0.0;

  b2 = b;

  x = a;

  for ( i = 1; i <= c; i++ )

  {

    x2 = exponential_sample ( a2, b2, seed );

    x = x + x2;

  }

  return x;

}

double erlang_variance ( double a, double b, int c )

{

  double variance;

  variance =  b * b * ( double ) ( c );

  return variance;

}

double error_f ( double x )

{

  double a[5] = {

    3.16112374387056560,

    1.13864154151050156E+02,

    3.77485237685302021E+02,

    3.20937758913846947E+03,

    1.85777706184603153E-01 };

  double b[4] = {

    2.36012909523441209E+01,

    2.44024637934444173E+02,

    1.28261652607737228E+03,

    2.84423683343917062E+03 };

  double c[9] = {

    5.64188496988670089E-01,

    8.88314979438837594,

    6.61191906371416295E+01,

    2.98635138197400131E+02,

    8.81952221241769090E+02,

    1.71204761263407058E+03,

    2.05107837782607147E+03,

    1.23033935479799725E+03,

    2.15311535474403846E-08 };

  double d[8] = {

    1.57449261107098347E+01,

    1.17693950891312499E+02,

    5.37181101862009858E+02,

    1.62138957456669019E+03,

    3.29079923573345963E+03,

    4.36261909014324716E+03,

    3.43936767414372164E+03,

    1.23033935480374942E+03 };

  double del;

  double erfxd;

  int i;

  double p[6] = {

    3.05326634961232344E-01,

    3.60344899949804439E-01,

    1.25781726111229246E-01,

    1.60837851487422766E-02,

    6.58749161529837803E-04,

    1.63153871373020978E-02 };

  double q[5] = {

    2.56852019228982242,

    1.87295284992346047,

    5.27905102951428412E-01,

    6.05183413124413191E-02,

    2.33520497626869185E-03 };

  double sqrpi = 0.56418958354775628695;

  double thresh = 0.46875;

  double xabs;

  double xbig = 26.543;

  double xden;

  double xnum;

  double xsmall = 1.11E-16;

  double xsq;

  xabs = r8_abs ( ( x ) );

  if ( xabs <= thresh )

  {

    if ( xsmall < xabs )

    {

      xsq = xabs * xabs;

    }

    else

    {

      xsq = 0.0;

    }

    xnum = a[4] * xsq;

    xden = xsq;

    for ( i = 0; i < 3; i++ )

    {

      xnum = ( xnum + a[i] ) * xsq;

      xden = ( xden + b[i] ) * xsq;

    }

    erfxd = x * ( xnum + a[3] ) / ( xden + b[3] );

  }

  else if ( xabs <= 4.0 )

  {

    xnum = c[8] * xabs;

    xden = xabs;

    for ( i = 0; i < 7; i++ )

    {

      xnum = ( xnum + c[i] ) * xabs;

      xden = ( xden + d[i] ) * xabs;

    }

    erfxd = ( xnum + c[7] ) / ( xden + d[7] );

    xsq = ( ( double ) ( ( int ) ( xabs * 16.0 ) ) ) / 16.0;

    del = ( xabs - xsq ) * ( xabs + xsq );

    erfxd = exp ( - xsq * xsq ) * exp ( -del ) * erfxd;

    erfxd = ( 0.5 - erfxd ) + 0.5;

    if ( x < 0.0 )

    {

      erfxd = -erfxd;

    }

  }

  else

  {

    if ( xbig <= xabs )

    {

      if ( 0.0 < x )

      {

        erfxd = 1.0;

      }

      else

      {

        erfxd = - 1.0;

      }

    }

    else

    {

      xsq = 1.0 / ( xabs * xabs );

      xnum = p[5] * xsq;

      xden = xsq;

      for ( i = 0; i < 4; i++ )

      {

        xnum = ( xnum + p[i] ) * xsq;

        xden = ( xden + q[i] ) * xsq;

      }

      erfxd = xsq * ( xnum + p[4] ) / ( xden + q[4] );

      erfxd = ( sqrpi - erfxd ) / xabs;

      xsq = ( ( double ) ( ( int ) ( xabs * 16.0 ) ) ) / 16.0;

      del = ( xabs - xsq ) * ( xabs + xsq );

      erfxd = exp ( - xsq * xsq ) * exp ( - del ) * erfxd;

      erfxd = ( 0.5 - erfxd ) + 0.5;

      if ( x < 0.0 )

      {

        erfxd = -erfxd;

      }

    }

  }

  return erfxd;

}

double error_f_inverse ( double y )

{

  double value;

  double x;

  double z;

  z = ( y + 1.0 ) / 2.0;

  x = normal_01_cdf_inv ( z );

  value = x / sqrt ( 2.0 );

  return value;

}

double euler_constant ( )

{

  double value = 0.577215664901532860606512090082402431042;

  return value;

}

double exponential_01_cdf ( double x )

{

  double cdf;

  if ( x <= 0.0 )

  {

    cdf = 0.0;

  }

  else

  {

    cdf = 1.0 - exp ( - x );

  }

  return cdf;

}

double exponential_01_cdf_inv ( double cdf )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "EXPONENTIAL_01_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = - log ( 1.0 - cdf );

  return x;

}

double exponential_01_mean ( )

{

  double mean;

  mean = 1.0;

  return mean;

}

double exponential_01_pdf ( double x )

{

  double pdf;

  if ( x < 0.0 )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = exp ( - x );

  }

  return pdf;

}

double exponential_01_sample ( int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = - log ( 1.0 - cdf );

  return x;

}

double exponential_01_variance ( )

{

  double variance;

  variance = 1.0;

  return variance;

}

double exponential_cdf ( double x, double a, double b )

{

  double cdf;

  if ( x <= a )

  {

    cdf = 0.0;

  }

  else

  {

    cdf = 1.0 - exp ( ( a - x ) / b );

  }

  return cdf;

}

double exponential_cdf_inv ( double cdf, double a, double b )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "EXPONENTIAL_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = a - b * log ( 1.0 - cdf );

  return x;

}

void exponential_cdf_values ( int &n_data, double &lambda, double &x,

  double &fx )

{

# define N_MAX 9

  static double fx_vec[N_MAX] = {

     0.3934693402873666E+00,

     0.6321205588285577E+00,

     0.7768698398515702E+00,

     0.8646647167633873E+00,

     0.8646647167633873E+00,

     0.9816843611112658E+00,

     0.9975212478233336E+00,

     0.9996645373720975E+00,

     0.9999546000702375E+00 };

  static double lambda_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01 };

  static double x_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    lambda = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    lambda = lambda_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool exponential_check ( double a, double b )

{

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "EXPONENTIAL_CHECK - Fatal error!\n";

    cerr << "  B <= 0.0\n";

    return false;

  }

  return true;

}

double exponential_mean ( double a, double b )

{

  double mean;

  mean = a + b;

  return mean;

}

double exponential_pdf ( double x, double a, double b )

{

  double pdf;

  if ( x < a )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = ( 1.0 / b ) * exp ( ( a - x ) / b );

  }

  return pdf;

}

double exponential_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = exponential_cdf_inv ( cdf, a, b );

  return x;

}

double exponential_variance ( double a, double b )

{

  double variance;

  variance = b * b;

  return variance;

}

double extreme_values_cdf ( double x, double a, double b )

{

  double cdf;

  double y;

  y = ( x - a ) / b;

  cdf = exp ( - exp ( - y ) );

  return cdf;

}

double extreme_values_cdf_inv ( double cdf, double a, double b )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "EXTREME_VALUES_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = a - b * log ( - log ( cdf ) );

  return x;

}

void extreme_values_cdf_values ( int &n_data, double &alpha, double &beta,

  double &x, double &fx )

{

# define N_MAX 12

  static double alpha_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01 };

  static double beta_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01 };

  static double fx_vec[N_MAX] = {

     0.3678794411714423E+00,

     0.8734230184931166E+00,

     0.9818510730616665E+00,

     0.9975243173927525E+00,

     0.5452392118926051E+00,

     0.4884435800065159E+00,

     0.4589560693076638E+00,

     0.4409910259429826E+00,

     0.5452392118926051E+00,

     0.3678794411714423E+00,

     0.1922956455479649E+00,

     0.6598803584531254E-01 };

  static double x_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    alpha = 0.0;

    beta = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    alpha = alpha_vec[n_data-1];

    beta = beta_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool extreme_values_check ( double a, double b )

{

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "EXTREME_VALUES_CHECK - Fatal error!\n";

    cerr << "  B <= 0.\n";

    return false;

  }

  return true;

}

double extreme_values_mean ( double a, double b )

{

  double mean;

  mean = a + b * euler_constant ( );

  return mean;

}

double extreme_values_pdf ( double x, double a, double b )

{

  double pdf;

  pdf = ( 1.0 / b ) * exp ( ( a - x ) / b - exp ( ( a - x ) / b ) );

  return pdf;

}

double extreme_values_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = extreme_values_cdf_inv ( cdf, a, b );

  return x;

}

double extreme_values_variance ( double a, double b )

{

  const double pi = 3.14159265358979323;

  double variance;

  variance = pi * pi * b * b / 6.0;

  return variance;

}

double f_cdf ( double x, int m, int n )

{

  double arg1;

  double arg2;

  double arg3;

  double cdf;

  if ( x <= 0.0 )

  {

    cdf = 0.0;

  }

  else

  {

    arg1 = 0.5 * ( double ) ( n );

    arg2 = 0.5 * ( double ) ( m );

    arg3 = ( double ) ( n ) / ( ( double ) ( n ) + ( double ) ( m ) * x );

    cdf = 1.0 - beta_inc ( arg1, arg2, arg3 );

  }

  return cdf;

}

void f_cdf_values ( int &n_data, int &a, int &b, double &x, double &fx )

{

# define N_MAX 20

  static int a_vec[N_MAX] = {

    1,

    1,

    5,

    1,

    2,

    4,

    1,

    6,

    8,

    1,

    3,

    6,

    1,

    1,

    1,

    1,

    2,

    3,

    4,

    5 };

  static int b_vec[N_MAX] = {

     1,

     5,

     1,

     5,

    10,

    20,

     5,

     6,

    16,

     5,

    10,

    12,

     5,

     5,

     5,

     5,

     5,

     5,

     5,

     5 };

  static double fx_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.4999714850534485E+00,

     0.4996034370170990E+00,

     0.7496993658293228E+00,

     0.7504656462757382E+00,

     0.7514156325324275E+00,

     0.8999867031372156E+00,

     0.8997127554259699E+00,

     0.9002845660853669E+00,

     0.9500248817817622E+00,

     0.9500574946122442E+00,

     0.9501926400000000E+00,

     0.9750133887312993E+00,

     0.9900022327445249E+00,

     0.9949977837872073E+00,

     0.9989999621122122E+00,

     0.5687988496283079E+00,

     0.5351452100063650E+00,

     0.5143428032407864E+00,

     0.5000000000000000E+00 };

  static double x_vec[N_MAX] = {

      1.00E+00,

      0.528E+00,

      1.89E+00,

      1.69E+00,

      1.60E+00,

      1.47E+00,

      4.06E+00,

      3.05E+00,

      2.09E+00,

      6.61E+00,

      3.71E+00,

      3.00E+00,

     10.01E+00,

     16.26E+00,

     22.78E+00,

     47.18E+00,

      1.00E+00,

      1.00E+00,

      1.00E+00,

      1.00E+00 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    a = 0;

    b = 0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    a = a_vec[n_data-1];

    b = b_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool f_check ( int m, int n )

{

  if ( m <= 0 )

  {

    cerr << "\n";

    cerr << "F_CHECK - Fatal error!\n";

    cerr << "  M <= 0.\n";

    return false;

  }

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "F_CHECK - Fatal error!\n";

    cerr << "  N <= 0.\n";

    return false;

  }

  return true;

}

double f_mean ( int m, int n )

{

  double mean;

  if ( n < 3 )

  {

    cerr << " \n";

    cerr << "F_MEAN - Fatal error!\n";

    cerr << "  The mean is not defined for N < 3.\n";

    exit ( 1 );

  }

  mean = ( double ) ( n ) / ( double ) ( n - 2 );

  return mean;

}

double f_pdf ( double x, int m, int n )

{

  double a;

  double b;

  double bot1;

  double bot2;

  double pdf;

  double top;

  if ( x < 0.0 )

  {

    pdf = 0.0;

  }

  else

  {

    a = ( double ) ( m );

    b = ( double ) ( n );

    top = sqrt ( pow ( a, m ) * pow ( b, n ) * pow ( x, m - 2 ) );

    bot1 = beta ( a / 2.0, b / 2.0 ) ;

    bot2 = sqrt ( pow ( b + a * x, m + n ) );

    pdf = top / ( bot1 * bot2 );

  }

  return pdf;

}

double f_sample ( int m, int n, int &seed )

{

  double a;

  double x;

  double xm;

  double xn;

  a = ( double ) ( m );

  xm = chi_square_sample ( a, seed );

  a = ( double ) ( n );

  xn = chi_square_sample ( a, seed );

  x = ( double ) ( n ) * xm / ( ( double ) ( m ) * xn );

  return x;

}

double f_variance ( int m, int n )

{

  double variance;

  if ( n < 5 )

  {

    cerr << " \n";

    cerr << "F_VARIANCE - Fatal error!\n";

    cerr << "  The variance is not defined for N < 5.\n";

    exit ( 1 );

  }

  variance = ( double ) ( 2 * n * n * ( m + n - 2 ) ) /

    ( double ) ( m * ( n - 2 ) * ( n - 2 ) * ( n - 4 ) );

  return variance;

}

void f_noncentral_cdf_values ( int &n_data, int &n1, int &n2, double &lambda,

  double &x, double &fx )

{

# define N_MAX 22

  static double fx_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.6367825323508774E+00,

     0.5840916116305482E+00,

     0.3234431872392788E+00,

     0.4501187879813550E+00,

     0.6078881441188312E+00,

     0.7059275551414605E+00,

     0.7721782003263727E+00,

     0.8191049017635072E+00,

     0.3170348430749965E+00,

     0.4327218008454471E+00,

     0.4502696915707327E+00,

     0.4261881186594096E+00,

     0.6753687206341544E+00,

     0.4229108778879005E+00,

     0.6927667261228938E+00,

     0.3632174676491226E+00,

     0.4210054012695865E+00,

     0.4266672258818927E+00,

     0.4464016600524644E+00,

     0.8445888579504827E+00,

     0.4339300273343604E+00 };

  static double lambda_vec[N_MAX] = {

     0.00E+00,

     0.00E+00,

     0.25E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     2.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     2.00E+00,

     1.00E+00,

     1.00E+00,

     0.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00 };

  static int n1_vec[N_MAX] = {

     1,  1,  1,  1,

     1,  1,  1,  1,

     1,  1,  2,  2,

     3,  3,  4,  4,

     5,  5,  6,  6,

     8, 16 };

  static int n2_vec[N_MAX] = {

     1,  5,  5,  5,

     5,  5,  5,  5,

     5,  5,  5, 10,

     5,  5,  5,  5,

     1,  5,  6, 12,

    16,  8 };

  static double x_vec[N_MAX] = {

     1.00E+00,

     1.00E+00,

     1.00E+00,

     0.50E+00,

     1.00E+00,

     2.00E+00,

     3.00E+00,

     4.00E+00,

     5.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     2.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     2.00E+00,

     2.00E+00 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    n1 = 0;

    n2 = 0;

    lambda = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    n1 = n1_vec[n_data-1];

    n2 = n2_vec[n_data-1];

    lambda = lambda_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool f_noncentral_check ( double a, int m, int n )

{

  if ( a <= 0.0 )

  {

    cerr << " \n";

    cerr << "F_NONCENTRAL_CHECK - Fatal error!\n";

    cerr << "  A <= 0.\n";

    exit ( 1 );

  }

  if ( m <= 0 )

  {

    cerr << "\n";

    cerr << "F_NONCENTRAL_CHECK - Fatal error!\n";

    cerr << "  M <= 0.\n";

    return false;

  }

  if ( n <= 0 )

  {

    cerr << "\n";

    cerr << "F_NONCENTRAL_CHECK - Fatal error!\n";

    cerr << "  N <= 0.\n";

    return false;

  }

  return true;

}

double f_noncentral_mean ( double a, int m, int n )

{

  double mean;

  if ( n < 3 )

  {

    cerr << " \n";

    cerr << "F_NONCENTRAL_MEAN - Fatal error!\n";

    cerr << "  The mean is not defined for N < 3.\n";

    exit ( 1 );

  }

  mean = ( ( double ) ( m ) + a ) * ( double ) ( n )

    / ( ( double ) ( m ) * ( double ) ( n - 2 ) );

  return mean;

}

double f_noncentral_variance ( double a, int m, int n )

{

  double mr;

  double nr;

  double variance;

  if ( n < 5 )

  {

    cerr << " \n";

    cerr << "F_NONCENTRAL_VARIANCE - Fatal error!\n";

    cerr << "  The variance is not defined for N < 5.\n";

    exit ( 1 );

  }

  mr = ( double ) ( m );

  nr = ( double ) ( n );

  variance = ( ( mr + a ) * ( mr + a ) + 2.0 * ( mr + a ) * nr * nr )

    / ( ( nr - 2.0 ) * ( nr - 4.0 ) * mr * mr )

    - ( mr + a ) * ( mr + a ) * nr * nr

    / ( ( nr - 2.0 ) * ( nr - 2.0 ) * mr * mr );

  return variance;

}

double factorial_log ( int n )

{

  int i;

  double value;

  if ( n < 0 )

  {

    cerr << "\n";

    cerr << "FACTORIAL_LOG - Fatal error!\n";

    cerr << "  N < 0.\n";

    exit ( 1 );

  }

  value = 0.0;

  for ( i = 2; i <= n; i++ )

  {

    value = value + log ( ( double ) ( i ) );

  }

  return value;

}

double factorial_stirling ( int n )

{

  const double e_natural = 2.71828182845904523536028747135266249775724709369995;

  const double pi = 3.14159265358979323;

  double value;

  if ( n < 0 )

  {

    value = 0.0;

  }

  else if ( n == 0 )

  {

    value = 1.0;

  }

  else

  {

    value = sqrt ( 2.0 * pi * ( double ) ( n ) )

      * pow ( ( double ) ( n ) / e_natural, n )

      * exp ( 1.0 / ( double ) ( 12 * n ) );

  }

  return value;

}

double fisher_pdf ( double x[3], double kappa, double mu[3] )

{

# define NB 1

  double alpha;

  double arg;

  double b[NB];

  double cf;

  int ize;

  double mu_norm;

  int ncalc;

  double pdf;

  double pi = 3.141592653589793;

  double x_norm;

  if ( kappa < 0.0 )

  {

    cerr << "\n";

    cerr << "FISHER_PDF - Fatal error!\n";

    cerr << "  KAPPA must be nonnegative.\n";

    cerr << "  Input KAPPA = " << kappa << "\n";

    exit ( 1 );

  }

  if ( kappa == 0.0 )

  {

    pdf = 1.0 / ( 4.0 * pi );

    return pdf;

  }

  alpha = 0.5;

  ize = 1;

  ncalc = ribesl ( kappa, alpha, NB, ize, b );

  cf = sqrt ( kappa ) / ( sqrt ( pow ( 2.0 * pi, 3 ) ) * b[0] );

  mu_norm = r8vec_length ( 3, mu );

  if ( mu_norm == 0.0 )

  {

    pdf = cf;

    return pdf;

  }

  x_norm = r8vec_length ( 3, x );

  if ( x_norm == 0.0 )

  {

    pdf = cf;

    return pdf;

  }

  arg = kappa * r8vec_dot ( 3, x, mu ) / ( x_norm * mu_norm );

  pdf = cf * exp ( arg );

  return pdf;

# undef NB

}

double *fisher_sample ( double kappa, double mu[], int n, int &seed )

{

  double a[3*3];

  double alpha;

  double beta;

  int i;

  int j;

  int k;

  double lambda;

  double mu_norm;

  double *phi;

  double pi = 3.141592653589793;

  double rst[3];

  double *theta;

  double *xyz;

  mu_norm = r8vec_length ( 3, mu );

  if ( mu_norm == 0.0 )

  {

    cerr << "\n";

    cerr << "FISHER_SAMPLE - Fatal error!\n";

    cerr << "  MU = 0.\n";

    exit ( 1 );

  }

  alpha = - acos ( mu[2] / mu_norm );

  beta = atan2 ( mu[1], mu[0] );

  lambda = exp ( - 2.0 * kappa );

  theta = r8vec_uniform_01 ( n, seed );

  for ( k = 0; k < n; k++ )

  {

    if ( kappa == 0.0 )

    {

      theta[k] = 2.0 * asin ( sqrt ( 1.0 - theta[k] ) );

    }

    else

    {

      theta[k] = 2.0 * asin ( sqrt (

        - log ( theta[k] * ( 1.0 - lambda ) + lambda )

        / ( 2.0 * kappa ) ) );

    }

  }

  phi = r8vec_uniform_01 ( n, seed );

  for ( k = 0; k < n; k++ )

  {

    phi[k] = 2.0 * pi * phi[k];

  }

  a[0+0*3] =   cos ( alpha ) * cos ( beta );

  a[1+0*3] =                 - sin ( beta );

  a[2+0*3] =   sin ( alpha ) * cos ( beta );

  a[0+1*3] =   cos ( alpha ) * sin ( beta );

  a[1+1*3] =                 + cos ( beta );

  a[2+1*3] =   sin ( alpha ) * sin ( beta );

  a[0+2*3] = - sin ( alpha );

  a[1+2*3] =   0.0;

  a[2+2*3] =   cos ( alpha );

  xyz = new double[3*n];

  for ( k = 0; k < n; k++ )

  {

    rst[0] = sin ( theta[k] ) * cos ( phi[k] );

    rst[1] = sin ( theta[k] ) * sin ( phi[k] );

    rst[2] = cos ( theta[k] );

    for ( i = 0; i < 3; i++ )

    {

      xyz[i+k*3] = 0.0;

      for ( j = 0; j < 3; j++ )

      {

        xyz[i+k*3] = xyz[i+k*3] + a[i+j*3] * rst[j];

      }

    }

  }

  delete [] theta;

  delete [] phi;

  return xyz;

}

double fisk_cdf ( double x, double a, double b, double c )

{

  double cdf;

  if ( x <= a )

  {

    cdf = 0.0;

  }

  else

  {

    cdf = 1.0 / ( 1.0 + pow ( ( b / ( x - a ) ), c ) );

  }

  return cdf;

}

double fisk_cdf_inv ( double cdf, double a, double b, double c )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "FISK_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf <= 0.0 )

  {

    x = a;

  }

  else if ( cdf < 1.0 )

  {

    x = a + b * pow ( cdf / ( 1.0 - cdf ), 1.0 / c );

  }

  else if ( 1.0 <= cdf )

  {

    x = r8_huge ( );

  }

  return x;

}

bool fisk_check ( double a, double b, double c )

{

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "FISK_CHECK - Fatal error!\n";

    cerr << "  B <= 0.\n";

    return false;

  }

  if ( c <= 0.0 )

  {

    cerr << " \n";

    cerr << "FISK_CHECK - Fatal error!\n";

    cerr << "  C <= 0.\n";

    return false;

  }

  return true;

}

double fisk_mean ( double a, double b, double c )

{

  double mean;

  const double pi = 3.14159265358979323;

  if ( c <= 1.0 )

  {

    cerr << " \n";

    cerr << "FISK_MEAN - Fatal error!\n";

    cerr << "  No mean defined for C <= 1.0\n";

    exit ( 1 );

  }

  mean = a + pi * ( b / c ) * r8_csc ( pi / c );

  return mean;

}

double fisk_pdf ( double x, double a, double b, double c )

{

  double pdf;

  double y;

  if ( x <= a )

  {

    pdf = 0.0;

  }

  else

  {

    y = ( x - a ) / b;

    pdf = ( c / b ) * pow ( y, ( c - 1.0 ) ) / pow ( ( 1.0 + pow ( y, c ) ), 2 );

  }

  return pdf;

}

double fisk_sample ( double a, double b, double c, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = fisk_cdf_inv ( cdf, a, b, c );

  return x;

}

double fisk_variance ( double a, double b, double c )

{

  double g;

  const double pi = 3.14159265358979323;

  double variance;

  if ( c <= 2.0 )

  {

    cerr << " \n";

    cerr << "FISK_VARIANCE - Fatal error!\n";

    cerr << "  No variance defined for C <= 2.0\n";

    exit ( 1 );

  }

  g = pi / c;

  variance = b * b * ( 2.0 * g * r8_csc ( 2.0 * g ) 

    - pow ( ( g * r8_csc ( g ) ), 2 ) );

  return variance;

}

double folded_normal_cdf ( double x, double a, double b )

{

  double cdf;

  double cdf1;

  double cdf2;

  double x1;

  double x2;

  if ( x < 0.0 )

  {

    cdf = 0.0;

  }

  else

  {

    x1 = ( x - a ) / b;

    cdf1 = normal_01_cdf ( x1 );

    x2 = ( - x - a ) / b;

    cdf2 = normal_01_cdf ( x2 );

    cdf = cdf1 - cdf2;

  }

  return cdf;

}

double folded_normal_cdf_inv ( double cdf, double a, double b )

{

  double cdf1;

  double cdf2;

  double cdf3;

  int it;

  int it_max = 100;

  double tol = 0.0001;

  double x;

  double x1;

  double x2;

  double x3;

  double xa;

  double xb;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "FOLDED_NORMAL_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = 0.0;

    return x;

  }

  else if ( 1.0 == cdf )

  {

    x = r8_huge ( );

    return x;

  }

  if ( 0.0 <= a )

  {

    x1 = normal_cdf_inv ( cdf, a, b );

  }

  else

  {

    x1 = normal_cdf_inv ( cdf, -a, b );

  }

  x1 = r8_max ( x1, 0.0 );

  cdf1 = folded_normal_cdf ( x1, a, b );

  cdf2 = ( 1.0 - cdf ) / 2.0;

  xa = normal_cdf_inv ( cdf2, a, b );

  xb = normal_cdf_inv ( cdf2, -a, b );

  x2 = r8_max ( r8_abs ( xa ), r8_abs ( xb ) );

  cdf2 = folded_normal_cdf ( x2, a, b );

  it = 0;

  for ( ; ; )

  {

    it = it + 1;

    x3 = 0.5 * ( x1 + x2 );

    cdf3 = folded_normal_cdf ( x3, a, b );

    if ( r8_abs ( cdf3 - cdf ) < tol )

    {

      x = x3;

      break;

    }

    if ( it_max < it )

    {

      cerr << " \n";

      cerr << "FOLDED_NORMAL_CDF_INV - Fatal error!\n";

      cerr << "  Iteration limit exceeded.\n";

      exit ( 1 );

    }

    if ( ( cdf3 <= cdf && cdf1 <= cdf ) || ( cdf <= cdf3 && cdf <= cdf1 ) )

    {

      x1 = x3;

      cdf1 = cdf3;

    }

    else

    {

      x2 = x3;

      cdf2 = cdf3;

    }

  }

  return x;

}

bool folded_normal_check ( double a, double b )

{

  if ( a < 0.0 )

  {

    cerr << " \n";

    cerr << "FOLDED_NORMAL_CHECK - Fatal error!\n";

    cerr << "  A < 0.\n";

    return false;

  }

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "FOLDED_NORMAL_CHECK - Fatal error!\n";

    cerr << "  B <= 0.\n";

    return false;

  }

  return true;

}

double folded_normal_mean ( double a, double b )

{

  double a2;

  double cdf;

  double mean;

  const double pi = 3.14159265358979323;

  a2 = a / b;

  cdf = normal_01_cdf ( a2 );

  mean = b * sqrt ( 2.0 / pi ) * exp ( - 0.5 * a2 * a2 )

    - a * ( 1.0 - 2.0 * cdf );

  return mean;

}

double folded_normal_pdf ( double x, double a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  if ( x < 0.0 )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = sqrt ( 2.0 / pi ) * ( 1.0 / b ) * cosh ( a * x / b / b )

      * exp ( - 0.5 * ( x * x + a * a ) / b / b );

  }

  return pdf;

}

double folded_normal_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = folded_normal_cdf_inv ( cdf, a, b );

  return x;

}

double folded_normal_variance ( double a, double b )

{

  double mean;

  double variance;

  mean = folded_normal_mean ( a, b );

  variance = a * a + b * b - mean * mean;

  return variance;

}

double frechet_cdf ( double x, double alpha )

{

  double cdf;

  if ( alpha <= 0.0 )

  {

    cerr << "\n";

    cerr << "FRECHET_CDF - Fatal error!\n";

    cerr << "  ALPHA <= 0.0.\n";

    exit ( 1 );

  }

  if ( x <= 0.0 )

  {

    cdf = 0.0;

  }

  else

  {

    cdf = exp ( - 1.0 / pow ( x, alpha ) );

  }

  return cdf;

}

double frechet_cdf_inv ( double cdf, double alpha )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "FRECHET_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( alpha <= 0.0 )

  {

    cerr << "\n";

    cerr << "FRECHET_CDF_INV - Fatal error!\n";

    cerr << "  ALPHA <= 0.0.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = 0.0;

  }

  else

  {

    x =  pow ( - 1.0 / log ( cdf ), 1.0 / alpha );

  }

  return x;

}

double frechet_mean ( double alpha )

{

  double mean;

  if ( alpha <= 1.0 )

  {

    cerr << "\n";

    cerr << "FRECHET_MEAN - Fatal error!\n";

    cerr << "  Mean does not exist if ALPHA <= 1.\n";

    exit ( 1 );

  }

  mean = r8_gamma ( ( alpha - 1.0 ) / alpha );

  return mean;

}

double frechet_pdf ( double x, double alpha )

{

  double pdf;

  if ( alpha <= 0.0 )

  {

    cerr << "\n";

    cerr << "FRECHET_PDF - Fatal error!\n";

    cerr << "  ALPHA <= 0.0.\n";

    exit ( 1 );

  }

  pdf = alpha * exp ( - 1.0 / pow ( x, alpha ) ) / pow ( x, alpha + 1.0 );

  return pdf;

}

double frechet_sample ( double alpha, int &seed )

{

  double cdf;

  double x;

  if ( alpha <= 0.0 )

  {

    cerr << "\n";

    cerr << "FRECHET_SAMPLE - Fatal error!\n";

    cerr << "  ALPHA <= 0.0.\n";

    exit ( 1 );

  }

  cdf = r8_uniform_01 ( seed );

  x = frechet_cdf_inv ( cdf, alpha );

  return x;

}

double frechet_variance ( double alpha )

{

  double mean;

  double variance;

  if ( alpha <= 2.0 )

  {

    cerr << "\n";

    cerr << "FRECHET_VARIANCE - Fatal error!\n";

    cerr << "  Variance does not exist if ALPHA <= 2.\n";

    exit ( 1 );

  }

  mean = r8_gamma ( ( alpha - 1.0 ) / alpha );

  variance = r8_gamma ( ( alpha - 2.0 ) / alpha ) - mean * mean;

  return variance;

}

double gamma_cdf ( double x, double a, double b, double c )

{

  double cdf;

  double p2;

  double x2;

  x2 = ( x - a ) / b;

  p2 = c;

  cdf = gamma_inc ( p2, x2 );

  return cdf;

}

void gamma_cdf_values ( int &n_data, double &mu, double &sigma, double &x,

  double &fx )

{

# define N_MAX 12

  static double fx_vec[N_MAX] = {

     0.8646647167633873E+00,

     0.9816843611112658E+00,

     0.9975212478233336E+00,

     0.9996645373720975E+00,

     0.6321205588285577E+00,

     0.4865828809674080E+00,

     0.3934693402873666E+00,

     0.3296799539643607E+00,

     0.4421745996289254E+00,

     0.1911531694619419E+00,

     0.6564245437845009E-01,

     0.1857593622214067E-01 };

  static double mu_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01 };

  static double sigma_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01 };

  static double x_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    mu = 0.0;

    sigma = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    mu = mu_vec[n_data-1];

    sigma = sigma_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool gamma_check ( double a, double b, double c )

{

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "GAMMA_CHECK - Fatal error!\n";

    cerr << "  B <= 0.\n";

    cerr << "  B = " << b << "\n";

    return false;

  }

  if ( c <= 0.0 )

  {

    cerr << " \n";

    cerr << "GAMMA_CHECK - Fatal error!\n";

    cerr << "  C <= 0.\n";

    cerr << "  C = " << c << "\n";

    return false;

  }

  return true;

}

double gamma_mean ( double a, double b, double c )

{

  double mean;

  mean = a + b * c;

  return mean;

}

double gamma_pdf ( double x, double a, double b, double c )

{

  double pdf;

  double y;

  if ( x <= a )

  {

    pdf = 0.0;

  }

  else

  {

    y = ( x - a ) / b;

    pdf = pow ( y, c - 1.0 ) / ( b * r8_gamma ( c ) * exp ( y ) );

  }

  return pdf;

}

double gamma_sample ( double a, double b, double c, int &seed )

{

  double a1 =   0.3333333;

  double a2 = - 0.2500030;

  double a3 =   0.2000062;

  double a4 = - 0.1662921;

  double a5 =   0.1423657;

  double a6 = - 0.1367177;

  double a7 =   0.1233795;

  double bcoef;

  double co;

  double d;

  double e;

  double e1 = 1.0;

  double e2 = 0.4999897;

  double e3 = 0.1668290;

  double e4 = 0.0407753;

  double e5 = 0.0102930;

  double euler = 2.71828182845904;

  double p;

  double q;

  double q0;

  double q1 =  0.04166669;

  double q2 =  0.02083148;

  double q3 =  0.00801191;

  double q4 =  0.00144121;

  double q5 = -0.00007388;

  double q6 =  0.00024511;

  double q7 =  0.00024240;

  double r;

  double s;

  double si;

  double s2;

  double t;

  double u;

  double v;

  double w;

  double x;

  if ( c == 0.0 )

  {

    x = a;

    return x;

  }

  if ( c < 1.0 )

  {

    for ( ; ; )

    {

      u = r8_uniform_01 ( seed );

      t = 1.0 + c / euler;

      p = u * t;

      s = exponential_01_sample ( seed );

      if ( p < 1.0 )

      {

        x = exp ( log ( p ) / c );

        if ( x <= s )

        {

          break;

        }

      }

      else

      {

        x = - log ( ( t - p ) / c );

        if ( ( 1.0 - c ) * log ( x ) <= s )

        {

          break;

        }

      }

    }

    x = a + b * x;

    return x;

  }

  else

  {

    s2 = c - 0.5;

    s = sqrt ( c - 0.5 );

    d = sqrt ( 32.0 ) - 12.0 * sqrt ( c - 0.5 );

    t = normal_01_sample ( seed );

    x = pow ( ( sqrt ( c - 0.5 ) + 0.5 * t ), 2 );

    if ( 0.0 <= t )

    {

      x = a + b * x;

      return x;

    }

    u = r8_uniform_01 ( seed );

    if ( d * u <= t * t * t )

    {

      x = a + b * x;

      return x;

    }

    r = 1.0 / c;

    q0 = ( ( ( ( ( (

           q7   * r

         + q6 ) * r

         + q5 ) * r

         + q4 ) * r

         + q3 ) * r

         + q2 ) * r

         + q1 ) * r;

    if ( c <= 3.686 )

    {

      bcoef = 0.463 + s - 0.178 * s2;

      si = 1.235;

      co = 0.195 / s - 0.079 + 0.016 * s;

    }

    else if ( c <= 13.022 )

    {

      bcoef = 1.654 + 0.0076 * s2;

      si = 1.68 / s + 0.275;

      co = 0.062 / s + 0.024;

    }

    else

    {

      bcoef = 1.77;

      si = 0.75;

      co = 0.1515 / s;

    }

    if ( 0.0 < sqrt ( c - 0.5 ) + 0.5 * t )

    {

      v = 0.5 * t / s;

      if ( 0.25 < r8_abs ( v ) )

      {

        q = q0 - s * t + 0.25 * t * t + 2.0 * s2 * log ( 1.0 + v );

      }

      else

      {

        q = q0 + 0.5 * t * t * ( ( ( ( ( (

               a7   * v

             + a6 ) * v

             + a5 ) * v

             + a4 ) * v

             + a3 ) * v

             + a2 ) * v

             + a1 ) * v;

      }

      if ( log ( 1.0 - u ) <= q )

      {

        x = a + b * x;

        return x;

      }

    }

    for ( ; ; )

    {

      e = exponential_01_sample ( seed );

      u = r8_uniform_01 ( seed );

      u = 2.0 * u - 1.0;

      t = bcoef + r8_abs ( si * e ) * r8_sign ( u );

      if ( -0.7187449 <= t )

      {

        v = 0.5 * t / s;

        if ( 0.25 < r8_abs ( v ) )

        {

          q = q0 - s * t + 0.25 * t * t + 2.0 * s2 * log ( 1.0 + v );

        }

        else

        {

          q = q0 + 0.5 * t * t * ( ( ( ( ( (

               a7   * v

             + a6 ) * v

             + a5 ) * v

             + a4 ) * v

             + a3 ) * v

             + a2 ) * v

             + a1 ) * v;

        }

        if ( 0.0 < q )

        {

          if ( 0.5 < q )

          {

            w = exp ( q ) - 1.0;

          }

          else

          {

            w = ( ( ( (

                    e5   * q

                  + e4 ) * q

                  + e3 ) * q

                  + e2 ) * q

                  + e1 ) * q;

          }

          if ( co * r8_abs ( u ) <= w * exp ( e - 0.5 * t * t ) )

          {

            x = a + b * pow ( s + 0.5 * t, 2 );

            return x;

          }

        }

      }

    }

  }

}

double gamma_variance ( double a, double b, double c )

{

  double variance;

  variance = b * b * c;

  return variance;

}

double gamma_inc ( double p, double x )

{

  double a;

  double arg;

  double b;

  double c;

  double exp_arg_min = -88.0;

  double overflow = 1.0E+37;

  double plimit = 1000.0;

  double pn1;

  double pn2;

  double pn3;

  double pn4;

  double pn5;

  double pn6;

  double rn;

  double value;

  double tol = 1.0E-07;

  double xbig = 1.0E+08;

  value = 0.0;

  if ( p <= 0.0 )

  {

    cout << " \n";

    cout << "GAMMA_INC - Fatal error!\n";

    cout << "  Parameter P <= 0.\n";

    exit ( 1 );

  }

  if ( x <= 0.0 )

  {

    value = 0.0;

    return value;

  }

  if ( plimit < p )

  {

    pn1 = 3.0 * sqrt ( p ) * ( pow ( x / p, 1.0 / 3.0 )

      + 1.0 / ( 9.0 * p ) - 1.0 );

    value = normal_01_cdf ( pn1 );

    return value;

  }

  if ( xbig < x )

  {

    value = 1.0;

    return value;

  }

  if ( x <= 1.0 || x < p )

  {

    arg = p * log ( x ) - x - gamma_log ( p + 1.0 );

    c = 1.0;

    value = 1.0;

    a = p;

    for ( ; ; )

    {

      a = a + 1.0;

      c = c * x / a;

      value = value + c;

      if ( c <= tol )

      {

        break;

      }

    }

    arg = arg + log ( value );

    if ( exp_arg_min <= arg )

    {

      value = exp ( arg );

    }

    else

    {

      value = 0.0;

    }

  }

  else

  {

    arg = p * log ( x ) - x - gamma_log ( p );

    a = 1.0 - p;

    b = a + x + 1.0;

    c = 0.0;

    pn1 = 1.0;

    pn2 = x;

    pn3 = x + 1.0;

    pn4 = x * b;

    value = pn3 / pn4;

    for ( ; ; )

    {

      a = a + 1.0;

      b = b + 2.0;

      c = c + 1.0;

      pn5 = b * pn3 - a * c * pn1;

      pn6 = b * pn4 - a * c * pn2;

      if ( 0.0 < r8_abs ( pn6 ) )

      {

        rn = pn5 / pn6;

        if ( r8_abs ( value - rn ) <= r8_min ( tol, tol * rn ) )

        {

          arg = arg + log ( value );

          if ( exp_arg_min <= arg )

          {

            value = 1.0 - exp ( arg );

          }

          else

          {

            value = 1.0;

          }

          return value;

        }

        value = rn;

      }

      pn1 = pn3;

      pn2 = pn4;

      pn3 = pn5;

      pn4 = pn6;

      if ( overflow <= r8_abs ( pn5 ) )

      {

        pn1 = pn1 / overflow;

        pn2 = pn2 / overflow;

        pn3 = pn3 / overflow;

        pn4 = pn4 / overflow;

      }

    }

  }

  return value;

}

void gamma_inc_values ( int &n_data, double &a, double &x, double &fx )

{

# define N_MAX 20

  static double a_vec[N_MAX] = {

     0.10E+00,

     0.10E+00,

     0.10E+00,

     0.50E+00,

     0.50E+00,

     0.50E+00,

     0.10E+01,

     0.10E+01,

     0.10E+01,

     0.11E+01,

     0.11E+01,

     0.11E+01,

     0.20E+01,

     0.20E+01,

     0.20E+01,

     0.60E+01,

     0.60E+01,

     0.11E+02,

     0.26E+02,

     0.41E+02  };

  static double fx_vec[N_MAX] = {

    2.490302836300570E+00,

    0.8718369702247978E+00,

    0.1079213896175866E+00,

    1.238121685818417E+00,

    0.3911298052193973E+00,

    0.01444722098952533E+00,

    0.9048374180359596E+00,

    0.3678794411714423E+00,

    0.006737946999085467E+00,

    0.8827966752611692E+00,

    0.3908330082003269E+00,

    0.008051456628620993E+00,

    0.9898141728888165E+00,

    0.5578254003710746E+00,

    0.007295055724436130E+00,

    114.9574754165633E+00,

    2.440923530031405E+00,

    280854.6620274718E+00,

    8.576480283455533E+24,

    2.085031346403364E+47 };

  static double x_vec[N_MAX] = {

     0.30E-01,

     0.30E+00,

     0.15E+01,

     0.75E-01,

     0.75E+00,

     0.35E+01,

     0.10E+00,

     0.10E+01,

     0.50E+01,

     0.10E+00,

     0.10E+01,

     0.50E+01,

     0.15E+00,

     0.15E+01,

     0.70E+01,

     0.25E+01,

     0.12E+02,

     0.16E+02,

     0.25E+02,

     0.45E+02 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    a = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    a = a_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

double gamma_log ( double x )

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

  double d4 =   1.791759469228055000094023;

  double frtbig = 1.42E+09;

  int i;

  double p1[8] = {

    4.945235359296727046734888,

    2.018112620856775083915565E+02,

    2.290838373831346393026739E+03,

    1.131967205903380828685045E+04,

    2.855724635671635335736389E+04,

    3.848496228443793359990269E+04,

    2.637748787624195437963534E+04,

    7.225813979700288197698961E+03 };

  double p2[8] = {

    4.974607845568932035012064,

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

  double pnt68 = 0.6796875;

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

  double sqrtpi = 0.9189385332046727417803297;

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

    res = - log ( x );

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

double gamma_log_int ( int n )

{

  double value;

  if ( n <= 0 )

  {

    cout << " \n";

    cout << "GAMMA_LOG_INT - Fatal error!\n";

    cout << "  Illegal input value of N = " << n << "\n";

    cout << "  But N must be strictly positive.\n";

    exit ( 1 );

  }

  value = gamma_log ( ( double ) ( n ) );

  return value;

}

double genlogistic_cdf ( double x, double a, double b, double c )

{

  double cdf;

  double y;

  y = ( x - a ) / b;

  cdf = 1.0 / pow ( ( 1.0 + exp ( - y ) ), c );

  return cdf;

}

double genlogistic_cdf_inv ( double cdf, double a, double b, double c )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "GENLOGISTIC_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = - r8_huge ( );

  }

  else if ( cdf < 1.0 )

  {

    x = a - b * log ( pow ( cdf, - 1.0 / c ) - 1.0 );

  }

  else if ( 1.0 == cdf )

  {

    x = r8_huge ( );

  }

  return x;

}

bool genlogistic_check ( double a, double b, double c )

{

  if ( b <= 0.0 )

  {

    cout << " \n";

    cout << "GENLOGISTIC_CHECK - Fatal error!\n";

    cout << "  B <= 0.\n";

    return false;

  }

  if ( c <= 0.0 )

  {

    cout << " \n";

    cout << "GENLOGISTIC_CHECK - Fatal error!\n";

    cout << "  C <= 0.\n";

    return false;

  }

  return true;

}

double genlogistic_mean ( double a, double b, double c )

{

  double mean;

  mean = a + b * ( euler_constant ( ) + digamma ( c ) );

  return mean;

}

double genlogistic_pdf ( double x, double a, double b, double c )

{

  double pdf;

  double y;

  y = ( x - a ) / b;

  pdf = ( c / b ) * exp ( - y ) / pow ( 1.0 + exp ( - y ), c + 1.0 );

  return pdf;

}

double genlogistic_sample ( double a, double b, double c, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = genlogistic_cdf_inv ( cdf, a, b, c );

  return x;

}

double genlogistic_variance ( double a, double b, double c )

{

  const double pi = 3.14159265358979323;

  double variance;

  variance = b * b * ( pi * pi / 6.0 + trigamma ( c ) );

  return variance;

}

double geometric_cdf ( int x, double a )

{

  double cdf;

  if ( x <= 0 )

  {

    cdf = 0.0;

  }

  else if ( a == 0.0 )

  {

    cdf = 0.0;

  }

  else if ( a == 1.0 )

  {

    cdf = 1.0;

  }

  else

  {

    cdf = 1.0 - pow ( ( 1.0 - a ), x );

  }

  return cdf;

}

int geometric_cdf_inv ( double cdf, double a )

{

  int x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "GEOMETRIC_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( a == 1.0 )

  {

    x = 1;

  }

  else if ( a == 0.0 )

  {

    x = i4_huge ( );

  }

  else

  {

    x = 1 + ( int ) ( log ( 1.0 - cdf ) / log ( 1.0 - a ) );

  }

  return x;

}

void geometric_cdf_values ( int &n_data, int &x, double &p, double &cdf )

{

# define N_MAX 14

  static double cdf_vec[N_MAX] = {

     0.1900000000000000E+00,

     0.2710000000000000E+00,

     0.3439000000000000E+00,

     0.6861894039100000E+00,

     0.3600000000000000E+00,

     0.4880000000000000E+00,

     0.5904000000000000E+00,

     0.9141006540800000E+00,

     0.7599000000000000E+00,

     0.8704000000000000E+00,

     0.9375000000000000E+00,

     0.9843750000000000E+00,

     0.9995117187500000E+00,

     0.9999000000000000E+00 };

  static double p_vec[N_MAX] = {

     0.1E+00,

     0.1E+00,

     0.1E+00,

     0.1E+00,

     0.2E+00,

     0.2E+00,

     0.2E+00,

     0.2E+00,

     0.3E+00,

     0.4E+00,

     0.5E+00,

     0.5E+00,

     0.5E+00,

     0.9E+00 };

  static int x_vec[N_MAX] = {

    1,  2,  3, 10, 1,

    2,  3, 10,  3, 3,

    3,  5, 10,  3 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    x = 0;

    p = 0.0;

    cdf = 0.0;

  }

  else

  {

    x = x_vec[n_data-1];

    p = p_vec[n_data-1];

    cdf = cdf_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool geometric_check ( double a )

{

  if ( a < 0.0 || 1.0 < a )

  {

    cout << " \n";

    cout << "GEOMETRIC_CHECK - Fatal error!\n";

    cout << "  A < 0 or 1 < A.\n";

    return false;

  }

  return true;

}

double geometric_mean ( double a )

{

  double mean;

  mean = 1.0 / a;

  return mean;

}

double geometric_pdf ( int x, double a )

{

  double pdf;

  if ( x < 1 )

  {

    pdf = 0.0;

  }

  else if ( a == 0.0 )

  {

    pdf = 0.0;

  }

  else if ( a == 1.0 )

  {

    if ( x == 1 )

    {

      pdf = 1.0;

    }

    else

    {

      pdf = 0.0;

    }

  }

  else

  {

    pdf = a * pow ( ( 1.0 - a ), ( x - 1 ) );

  }

  return pdf;

}

int geometric_sample ( double a, int &seed )

{

  double cdf;

  int x;

  cdf = r8_uniform_01 ( seed );

  x = geometric_cdf_inv ( cdf, a );

  return x;

}

double geometric_variance ( double a )

{

  double variance;

  variance = ( 1.0 - a ) / ( a * a );

  return variance;

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

    * ( ( double ) I_MAX ) / ( 60.0 * 60.0 * 12.0 ) );

  if ( seed == 0 )

  {

    seed = 1;

  }

  return seed;

#undef I_MAX

}

double gompertz_cdf ( double x, double a, double b )

{

  double cdf;

  if ( x <= 0.0 )

  {

    cdf = 0.0;

  }

  else

  {

    cdf = 1.0 - exp ( - b * ( pow ( a, x ) - 1.0 ) / log ( a ) );

  }

  return cdf;

}

double gompertz_cdf_inv ( double cdf, double a, double b )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "GOMPERTZ_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf < 1.0 )

  {

    x = log ( 1.0 - log ( 1.0 - cdf ) * log ( a ) / b  ) / log ( a );

  }

  else

  {

    x = r8_huge ( );

  }

  return x;

}

bool gompertz_check ( double a, double b )

{

  if ( a <= 1.0 )

  {

    cout << " \n";

    cout << "GOMPERTZ_CHECK - Fatal error!\n";

    cout << "  A <= 1.0!\n";

    return false;

  }

  if ( b <= 0.0 )

  {

    cout << " \n";

    cout << "GOMPERTZ_CHECK - Fatal error!\n";

    cout << "  B <= 0.0!\n";

    return false;

  }

  return true;

}

double gompertz_pdf ( double x, double a, double b )

{

  double pdf;

  if ( x < 0.0 )

  {

    pdf = 0.0;

  }

  else if ( 1.0 < a )

  {

    pdf = exp ( log ( b ) + x * log ( a )

      - ( b / log ( a ) ) * ( pow ( a, x ) - 1.0 ) );

  }

  return pdf;

}

double gompertz_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = gompertz_cdf_inv ( cdf, a, b );

  return x;

}

double gumbel_cdf ( double x )

{

  double cdf;

  cdf = exp ( - exp ( - x ) );

  return cdf;

}

double gumbel_cdf_inv ( double cdf )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "GUMBEL_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x =  - log ( - log ( cdf ) );

  return x;

}

double gumbel_mean ( )

{

  double mean;

  mean = euler_constant ( );

  return mean;

}

double gumbel_pdf ( double x )

{

  double pdf;

  pdf = exp ( - x - exp ( - x ) );

  return pdf;

}

double gumbel_sample ( int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = gumbel_cdf_inv ( cdf );

  return x;

}

double gumbel_variance ( )

{

  const double pi = 3.14159265358979323;

  double variance;

  variance = pi * pi / 6.0;

  return variance;

}

double half_normal_cdf ( double x, double a, double b )

{

  double cdf;

  double cdf2;

  if ( x <= a )

  {

    cdf = 0.0;

  }

  else

  {

    cdf2 = normal_cdf ( x, a, b );

    cdf = 2.0 * cdf2 - 1.0;

  }

  return cdf;

}

double half_normal_cdf_inv ( double cdf, double a, double b )

{

  double cdf2;

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "HALF_NORMAL_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  cdf2 = 0.5 * ( cdf + 1.0 );

  x = normal_cdf_inv ( cdf2, a, b );

  return x;

}

bool half_normal_check ( double a, double b )

{

  if ( b <= 0.0 )

  {

    cout << " \n";

    cout << "HALF_NORMAL_CHECK - Fatal error!\n";

    cout << "  B <= 0.\n";

    return false;

  }

  return true;

}

double half_normal_mean ( double a, double b )

{

  double mean;

  const double pi = 3.14159265358979323;

  mean = a + b * sqrt ( 2.0 / pi );

  return mean;

}

double half_normal_pdf ( double x, double a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  double y;

  if ( x <= a )

  {

    pdf = 0.0;

  }

  else

  {

    y = ( x - a ) / b;

    pdf = sqrt ( 2.0 / pi ) * ( 1.0 / b ) * exp ( - 0.5 * y * y );

  }

  return pdf;

}

double half_normal_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = half_normal_cdf_inv ( cdf, a, b );

  return x;

}

double half_normal_variance ( double a, double b )

{

  const double pi = 3.14159265358979323;

  double variance;

  variance = b * b * ( 1.0 - 2.0 / pi );

  return variance;

}

double hypergeometric_cdf ( int x, int n, int m, int l )

{

  double cdf;

  double c1_log;

  double c2_log;

  double pdf;

  int x2;

  c1_log = binomial_coef_log ( l - m, n );

  c2_log = binomial_coef_log ( l, n );

  pdf = exp ( c1_log - c2_log );

  cdf = pdf;

  for ( x2 = 0; x2 <= x - 1; x2++ )

  {

    pdf = pdf * ( double ) ( ( m - x2 ) * ( n - x2 ) )

      / ( double ) ( ( x2 + 1 ) * ( l - m - n + x2 + 1 ) );

    cdf = cdf + pdf;

  }

  return cdf;

}

void hypergeometric_cdf_values ( int &n_data, int &sam, int &suc, int &pop,

  int &n, double &fx )

{

# define N_MAX 16

  static double fx_vec[N_MAX] = {

     0.6001858177500578E-01,

     0.2615284665839845E+00,

     0.6695237889132748E+00,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.5332595856827856E+00,

     0.1819495964117640E+00,

     0.4448047017527730E-01,

     0.9999991751316731E+00,

     0.9926860896560750E+00,

     0.8410799901444538E+00,

     0.3459800113391901E+00,

     0.0000000000000000E+00,

     0.2088888139634505E-02,

     0.3876752992448843E+00,

     0.9135215248834896E+00 };

  static int n_vec[N_MAX] = {

     7,  8,  9, 10,

     6,  6,  6,  6,

     6,  6,  6,  6,

     0,  0,  0,  0 };

  static int pop_vec[N_MAX] = {

    100, 100, 100, 100,

    100, 100, 100, 100,

    100, 100, 100, 100,

    90,  200, 1000, 10000 };

  static int sam_vec[N_MAX] = {

    10, 10, 10, 10,

     6,  7,  8,  9,

    10, 10, 10, 10,

    10, 10, 10, 10 };

  static int suc_vec[N_MAX] = {

    90, 90, 90, 90,

    90, 90, 90, 90,

    10, 30, 50, 70,

    90, 90, 90, 90 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    sam = 0;

    suc = 0;

    pop = 0;

    n = 0;

    fx = 0.0;

  }

  else

  {

    sam = sam_vec[n_data-1];

    suc = suc_vec[n_data-1];

    pop = pop_vec[n_data-1];

    n = n_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool hypergeometric_check ( int n, int m, int l )

{

  if ( n < 0 || l < n )

  {

    cout << " \n";

    cout << "HYPERGEOMETRIC_CHECK - Fatal error!\n";

    cout << "  Input N is out of range.\n";

    return false;

  }

  if ( m < 0 || l < m )

  {

    cout << " \n";

    cout << "HYPERGEOMETRIC_CHECK - Fatal error!\n";

    cout << "  Input M is out of range.\n";

    return false;

  }

  if ( l < 0 )

  {

    cout << " \n";

    cout << "HYPERGEOMETRIC_CHECK - Fatal error!\n";

    cout << "  Input L is out of range.\n";

    return false;

  }

  return true;

}

double hypergeometric_mean ( int n, int m, int l )

{

  double mean;

  mean = ( double ) ( n * m ) / ( double ) ( l );

  return mean;

}

double hypergeometric_pdf ( int x, int n, int m, int l )

{

  double c1;

  double c2;

  double c3;

  double pdf;

  double pdf_log;

  if ( x < 0 )

  {

    pdf = 1.0;

  }

  else if ( n < x )

  {

    pdf = 0.0;

  }

  else if ( m < x )

  {

    pdf = 0.0;

  }

  else if ( l < x )

  {

    pdf = 0.0;

  }

  else if ( n == 0 )

  {

    if ( x == 0 )

    {

      pdf = 1.0;

    }

    else

    {

      pdf = 0.0;

    }

  }

  else

  {

    c1 = binomial_coef_log ( m, x );

    c2 = binomial_coef_log ( l-m, n-x );

    c3 = binomial_coef_log ( l, n );

    pdf_log = c1 + c2 - c3;

    pdf = exp ( pdf_log );

  }

  return pdf;

}

int hypergeometric_sample ( int n, int m, int l, int &seed )

{

  double a;

  double b;

  double c1_log;

  double c2_log;

  double u;

  int x;

  c1_log = binomial_coef_log ( l - m, n );

  c2_log = binomial_coef_log ( l, n );

  a = exp ( c1_log - c2_log );

  b = a;

  u = r8_uniform_01 ( seed );

  x = 0;

  while ( a < u )

  {

    b = b * ( double ) ( ( m - x ) * ( n - x ) )

      / ( double ) ( ( x + 1 ) * ( l - m - n + x + 1 ) );

    a = a + b;

    x = x + 1;

  }

  return x;

}

double hypergeometric_variance ( int n, int m, int l )

{

  double variance;

  variance = ( double ) ( n * m * ( l - m ) * ( l - n ) )

    / ( double ) ( l * l * ( l - 1 ) );

  return variance;

}

double i4_factorial ( int n )

{

  double fact;

  int i;

  if ( n < 0 )

  {

    cout << "\n";

    cout << "I4_FACTORIAL - Fatal error!\n";

    cout << "  N < 0.\n";

    return 0;

  }

  fact = 1.0;

  for ( i = 2; i <= n; i++ )

  {

    fact = fact * ( double ) i;

  }

  return fact;

}

int i4_huge ( )

{

  return 2147483647;

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

int *i4row_max ( int m, int n, int a[] )

{

  int i;

  int j;

  int *amax;

  amax = new int[m];

  for ( i = 0; i < m; i++ )

  {

    amax[i] = a[i+0*m];

    for ( j = 1; j < n; j++ )

    {

      if ( amax[i] < a[i+j*m] )

      {

        amax[i] = a[i+j*m];

      }

    }

  }

  return amax;

}

double *i4row_mean ( int m, int n, int a[] )

{

  int i;

  int j;

  double *mean;

  mean = new double[m];

  for ( i = 0; i < m; i++ )

  {

    mean[i] = 0.0;

    for ( j = 0; j < n; j++ )

    {

      mean[i] = mean[i] + ( double ) a[i+j*m];

    }

    mean[i] = mean[i] / ( double ) ( n );

  }

  return mean;

}

int *i4row_min ( int m, int n, int a[] )

{

  int i;

  int j;

  int *amin;

  amin = new int[m];

  for ( i = 0; i < m; i++ )

  {

    amin[i] = a[i+0*m];

    for ( j = 1; j < n; j++ )

    {

      if ( a[i+j*m] < amin[i] )

      {

        amin[i] = a[i+j*m];

      }

    }

  }

  return amin;

}

double *i4row_variance ( int m, int n, int a[] )

{

  int i;

  int j;

  double mean;

  double *variance;

  variance = new double[m];

  for ( i = 0; i < m; i++ )

  {

    mean = 0.0;

    for ( j = 0; j < n; j++ )

    {

      mean = mean + ( double ) a[i+j*m];

    }

    mean = mean / ( double ) ( n );

    variance[i] = 0.0;

    for ( j = 0; j < n; j++ )

    {

      variance[i] = variance[i] + pow ( ( ( double ) a[i+j*m] - mean ), 2 );

    }

    if ( 1 < n )

    {

      variance[i] = variance[i] / ( double ) ( n - 1 );

    }

    else

    {

      variance[i] = 0.0;

    }

  }

  return variance;

}

int i4vec_max ( int n, int x[] )

{

  int i;

  int value;

  value = x[0];

  for ( i = 1; i < n; i++ )

  {

    if ( value < x[i] )

    {

      value = x[i];

    }

  }

  return value;

}

double i4vec_mean ( int n, int x[] )

{

  int i;

  double mean;

  mean = 0.0;

  for ( i = 0; i < n; i++ )

  {

    mean = mean + ( double ) x[i];

  }

  mean = mean / ( double ) n;

  return mean;

}

int i4vec_min ( int n, int x[] )

{

  int i;

  int value;

  value = x[0];

  for ( i = 1; i < n; i++ )

  {

    if ( x[i] < value )

    {

      value = x[i];

    }

  }

  return value;

}

void i4vec_print ( int n, int a[], char *title )

{

  int i;

  if ( s_len_trim ( title ) != 0 )

  {

    cout << "\n";

    cout << title << "\n";

  }

  cout << "\n";

  for ( i = 0; i <= n-1; i++ )

  {

    cout << setw(6) << i << "  " << setw(8) << a[i] << "\n";

  }

  return;

}

int i4vec_run_count ( int n, int a[] )

{

  int i;

  int run_count;

  int test;

  run_count = 0;

  if ( n < 1 )

  {

    return run_count;

  }

  test = 0;

  for ( i = 0; i < n; i++ )

  {

    if ( i == 0 || a[i] != test )

    {

      run_count = run_count + 1;

      test = a[i];

    }

  }

  return run_count;

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

double i4vec_variance ( int n, int x[] )

{

  int i;

  double mean;

  double variance;

  mean = i4vec_mean ( n, x );

  variance = 0.0;

  for ( i = 0; i < n; i++ )

  {

    variance = variance + ( ( double ) x[i] - mean ) * ( ( double ) x[i] - mean );

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

double inverse_gaussian_cdf ( double x, double a, double b )

{

  double cdf;

  double cdf1;

  double cdf2;

  double x1;

  double x2;

  if ( x <= 0.0 )

  {

    cdf = 0.0;

  }

  else

  {

    x1 = sqrt ( b / x ) * ( x - a ) / a;

    cdf1 = normal_01_cdf ( x1 );

    x2 = - sqrt ( b / x ) * ( x + a ) / a;

    cdf2 = normal_01_cdf ( x2 );

    cdf = cdf1 + exp ( 2.0 * b / a ) * cdf2;

  }

  return cdf;

}

bool inverse_gaussian_check ( double a, double b )

{

  if ( a <= 0.0 )

  {

    cout << " \n";

    cout << "INVERSE_GAUSSIAN_CHECK - Fatal error!\n";

    cout << "  A <= 0.\n";

    return false;

  }

  if ( b <= 0.0 )

  {

    cout << " \n";

    cout << "INVERSE_GAUSSIAN_CHECK - Fatal error!\n";

    cout << "  B <= 0.\n";

    return false;

  }

  return true;

}

double inverse_gaussian_mean ( double a, double b )

{

  double mean;

  mean = a;

  return mean;

}

double inverse_gaussian_pdf ( double x, double a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  if ( x <= 0.0 )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = sqrt ( b / ( 2.0 * pi * pow ( x, 3 ) ) ) *

      exp ( - b * ( x - a ) * ( x - a ) / ( 2.0 * a * a * x ) );

  }

  return pdf;

}

double inverse_gaussian_sample ( double a, double b, int &seed )

{

  double phi;

  double t;

  double u;

  double x;

  double y;

  double z;

  phi = b / a;

  z = normal_01_sample ( seed );

  y = z * z;

  t = 1.0 + 0.5 * ( y - sqrt ( 4.0 * phi * y + y * y ) ) / phi;

  u = r8_uniform_01 ( seed );

  if ( u * ( 1.0 + t ) <= 1.0 )

  {

    x = a * t;

  }

  else

  {

    x = a / t;

  }

  return x;

}

double inverse_gaussian_variance ( double a, double b )

{

  double variance;

  variance = a * a * a / b;

  return variance;

}

void laplace_cdf_values ( int &n_data, double &mu, double &beta, double &x,

  double &fx )

{

# define N_MAX 12

  static double beta_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01 };

  static double fx_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.8160602794142788E+00,

     0.9323323583816937E+00,

     0.9751064658160680E+00,

     0.6967346701436833E+00,

     0.6417343447131054E+00,

     0.6105996084642976E+00,

     0.5906346234610091E+00,

     0.5000000000000000E+00,

     0.3032653298563167E+00,

     0.1839397205857212E+00,

     0.1115650800742149E+00 };

  static double mu_vec[N_MAX] = {

     0.0000000000000000E+01,

     0.0000000000000000E+01,

     0.0000000000000000E+01,

     0.0000000000000000E+01,

     0.0000000000000000E+01,

     0.0000000000000000E+01,

     0.0000000000000000E+01,

     0.0000000000000000E+01,

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01 };

  static double x_vec[N_MAX] = {

     0.0000000000000000E+01,

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    mu = 0.0;

    beta = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    mu = mu_vec[n_data-1];

    beta = beta_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

double laplace_cdf ( double x, double a, double b )

{

  double cdf;

  double y;

  y = ( x - a ) / b;

  if ( x <= a )

  {

    cdf = 0.5 * exp ( y );

  }

  else

  {

    cdf = 1.0 - 0.5 * exp ( - y );

  }

  return cdf;

}

double laplace_cdf_inv ( double cdf, double a, double b )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "LAPLACE_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf <= 0.5 )

  {

    x = a + b * log ( 2.0 * cdf );

  }

  else

  {

    x = a - b * log ( 2.0 * ( 1.0 - cdf ) );

  }

  return x;

}

bool laplace_check ( double a, double b )

{

  if ( b <= 0.0 )

  {

    cout << " \n";

    cout << "LAPLACE_CHECK - Fatal error!\n";

    cout << "  B <= 0.\n";

    return false;

  }

  return true;

}

double laplace_mean ( double a, double b )

{

  double mean;

  mean = a;

  return mean;

}

double laplace_pdf ( double x, double a, double b )

{

  double pdf;

  pdf = exp ( - r8_abs ( x - a ) / b ) / ( 2.0 * b );

  return pdf;

}

double laplace_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = laplace_cdf_inv ( cdf, a, b );

  return x;

}

double laplace_variance ( double a, double b )

{

  double variance;

  variance = 2.0 * b * b;

  return variance;

}

double lerch ( double a, double b, double c )

{

  double a_k;

  int k;

  double sum2;

  double sum2_old;

  sum2 = 0.0;

  k = 0;

  a_k = 1.0;

  for ( ; ; )

  {

    sum2_old = sum2;

    if ( c + ( double ) ( k ) == 0.0 )

    {

      k = k + 1;

      a_k = a_k * a;

      continue;

    }

    sum2 = sum2 + a_k / pow ( c + ( double ) ( k ), b );

    if ( sum2 <= sum2_old )

    {

      break;

    }

    k = k + 1;

    a_k = a_k * a;

  }

  return sum2;

}

double levy_cdf ( double x, double a, double b )

{

  double cdf;

  if ( b <= 0.0 )

  {

    cout << "\n";

    cout << "LEVY_CDF - Fatal error!\n";

    cout << "  B <= 0.0.\n";

    exit ( 1 );

  }

  if ( x <= a )

  {

    cdf = 0.0;

  }

  else

  {

    cdf = 1.0 - error_f ( sqrt ( b / ( 2.0 * ( x - a ) ) ) );

  }

  return cdf;

}

double levy_cdf_inv ( double cdf, double a, double b )

{

  double cdf1;

  double x;

  double x1;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "LEVY_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( b <= 0.0 )

  {

    cout << "\n";

    cout << "LEVY_CDF_INV - Fatal error!\n";

    cout << "  B <= 0.0.\n";

    exit ( 1 );

  }

  cdf1 = 1.0 - 0.5 * cdf;

  x1 = normal_01_cdf_inv ( cdf1 );

  x = a + b / ( x1 * x1 );

  return x;

}

double levy_pdf ( double x, double a, double b )

{

  double pdf;

  double pi = 3.141592653589793;

  if ( b <= 0.0 )

  {

    cout << "\n";

    cout << "LEVY_PDF - Fatal error!\n";

    cout << "  B <= 0.0.\n";

    exit ( 1 );

  }

  if ( x <= a )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = sqrt ( b / ( 2.0 * pi ) )

        * exp ( - b / ( 2.0 * ( x - a ) ) )

        / sqrt ( pow ( x - a, 3 ) );

  }

  return pdf;

}

double levy_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = levy_cdf_inv ( cdf, a, b );

  return x;

}

double log_normal_cdf ( double x, double a, double b )

{

  double cdf;

  double logx;

  if ( x <= 0.0 )

  {

    cdf = 0.0;

  }

  else

  {

    logx = log ( x );

    cdf = normal_cdf ( logx, a, b );

  }

  return cdf;

}

double log_normal_cdf_inv ( double cdf, double a, double b )

{

  double logx;

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << "\n";

    cout << "LOG_NORMAL_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  logx = normal_cdf_inv ( cdf, a, b );

  x = exp ( logx );

  return x;

}

void log_normal_cdf_values ( int &n_data, double &mu, double &sigma,

  double &x, double &fx )

{

# define N_MAX 12

  static double fx_vec[N_MAX] = {

     0.2275013194817921E-01,

     0.2697049307349095E+00,

     0.5781741008028732E+00,

     0.7801170895122241E+00,

     0.4390310097476894E+00,

     0.4592655190218048E+00,

     0.4694258497695908E+00,

     0.4755320473858733E+00,

     0.3261051056816658E+00,

     0.1708799040927608E+00,

     0.7343256357952060E-01,

     0.2554673736161761E-01 };

  static double mu_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01 };

  static double sigma_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01 };

  static double x_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    mu = 0.0;

    sigma = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    mu = mu_vec[n_data-1];

    sigma = sigma_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool log_normal_check ( double a, double b )

{

  if ( b <= 0.0 )

  {

    cout << "\n";

    cout << "LOG_NORMAL_CHECK - Fatal error!\n";

    cout << "  B <= 0.\n";

    return false;

  }

  return true;

}

double log_normal_mean ( double a, double b )

{

  double mean;

  mean = exp ( a + 0.5 * b * b );

  return mean;

}

double log_normal_pdf ( double x, double a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  double y;

  if ( x <= 0.0 )

  {

    pdf = 0.0;

  }

  else

  {

    y = ( log ( x ) - a ) / b;

    pdf = exp ( -0.5 * y * y ) / ( b * x * sqrt ( 2.0 * pi ) );

  }

  return pdf;

}

double log_normal_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = log_normal_cdf_inv ( cdf, a, b );

  return x;

}

double log_normal_variance ( double a, double b )

{

  double variance;

  variance = exp ( 2.0 * a + b * b ) * ( exp ( b * b ) - 1.0 );

  return variance;

}

double log_series_cdf ( double x, double a )

{

  double cdf;

  double pdf;

  int x2;

  cdf = 0.0;

  for ( x2 = 1; x2 <= x; x2++ )

  {

    if ( x2 == 1 )

    {

      pdf = - a / log ( 1.0 - a );

    }

    else

    {

      pdf = ( double ) ( x2 - 1 ) * a * pdf / ( double ) ( x2 );

    }

    cdf = cdf + pdf;

  }

  return cdf;

}

int log_series_cdf_inv ( double cdf, double a )

{

  double cdf2;

  double pdf;

  int x;

  int xmax = 1000;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "LOG_SERIES_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  cdf2 = 0.0;

  x = 1;

  while ( cdf2 < cdf && x < xmax )

  {

    if ( x == 1 )

    {

      pdf = - a / log ( 1.0 - a );

    }

    else

    {

      pdf = ( double ) ( x - 1 ) * a * pdf / ( double ) ( x );

    }

    cdf2 = cdf2 + pdf;

    x = x + 1;

  }

  return x;

}

void log_series_cdf_values ( int &n_data, double &t, int &n, double &fx )

{

# define N_MAX 29

  static double fx_vec[N_MAX] = {

     0.9491221581029903E+00,

     0.9433541128559735E+00,

     0.9361094611773272E+00,

     0.9267370278044118E+00,

     0.9141358246245129E+00,

     0.8962840235449100E+00,

     0.8690148741955517E+00,

     0.8221011541254772E+00,

     0.7213475204444817E+00,

     0.6068261510845583E+00,

     0.5410106403333613E+00,

     0.4970679476476894E+00,

     0.4650921887927060E+00,

     0.4404842934597863E+00,

     0.4207860535926143E+00,

     0.4045507673897055E+00,

     0.3908650337129266E+00,

     0.2149757685421097E+00,

     0.0000000000000000E+00,

     0.2149757685421097E+00,

     0.3213887739704539E+00,

     0.3916213575531612E+00,

     0.4437690508633213E+00,

     0.4850700239649681E+00,

     0.5191433267738267E+00,

     0.5480569580144867E+00,

     0.5731033910767085E+00,

     0.5951442521714636E+00,

     0.6147826594068904E+00 };

  static int n_vec[N_MAX] = {

     1, 1, 1, 1, 1,

     1, 1, 1, 1, 1,

     1, 1, 1, 1, 1,

     1, 1, 1, 0, 1,

     2, 3, 4, 5, 6,

     7, 8, 9, 10 };

  static double t_vec[N_MAX] = {

     0.1000000000000000E+00,

     0.1111111111111111E+00,

     0.1250000000000000E+00,

     0.1428571428571429E+00,

     0.1666666666666667E+00,

     0.2000000000000000E+00,

     0.2500000000000000E+00,

     0.3333333333333333E+00,

     0.5000000000000000E+00,

     0.6666666666666667E+00,

     0.7500000000000000E+00,

     0.8000000000000000E+00,

     0.8333333333333333E+00,

     0.8571485714857149E+00,

     0.8750000000000000E+00,

     0.8888888888888889E+00,

     0.9000000000000000E+00,

     0.9900000000000000E+00,

     0.9900000000000000E+00,

     0.9900000000000000E+00,

     0.9900000000000000E+00,

     0.9900000000000000E+00,

     0.9900000000000000E+00,

     0.9900000000000000E+00,

     0.9900000000000000E+00,

     0.9900000000000000E+00,

     0.9900000000000000E+00,

     0.9900000000000000E+00,

     0.9900000000000000E+00  };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    t = 0.0;

    n = 0;

    fx = 0.0;

  }

  else

  {

    t = t_vec[n_data-1];

    n = n_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool log_series_check ( double a )

{

  if ( a <= 0.0 || 1.0 <= a )

  {

    cout << " \n";

    cout << "LOG_SERIES_CHECK - Fatal error!\n";

    cout << "  A <= 0.0 or 1.0 <= A\n";

    return false;

  }

  return true;

}

double log_series_mean ( double a )

{

  double mean;

  mean = - a / ( ( 1.0 - a ) * log ( 1.0 - a ) );

  return mean;

}

double log_series_pdf ( int x, double a )

{

  double pdf;

  if ( x <= 0 )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = - pow ( a, x ) / ( ( double ) ( x ) * log ( 1.0 - a ) );

  }

  return pdf;

}

int log_series_sample ( double a, int &seed )

{

  double u;

  double v;

  int x;

  u = r8_uniform_01 ( seed );

  v = r8_uniform_01 ( seed );

  x = ( int ) ( 1.0 + log ( v ) / ( log ( 1.0 - pow ( 1.0 - a, u ) ) ) );

  return x;

}

double log_series_variance ( double a )

{

  double alpha;

  double variance;

  alpha = - 1.0 / log ( 1.0 - a );

  variance = a * alpha * ( 1.0 - alpha * a ) / pow ( ( 1.0 - a ), 2 );

  return variance;

}

double log_uniform_cdf ( double x, double a, double b )

{

  double cdf;

  if ( x <= a )

  {

    cdf = 0.0;

  }

  else if ( x < b )

  {

    cdf = ( log ( x ) - log ( a ) ) / ( log ( b ) - log ( a ) );

  }

  else

  {

    cdf = 1.0;

  }

  return cdf;

}

double log_uniform_cdf_inv ( double cdf, double a, double b )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << "\n";

    cout << "LOG_UNIFORM_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = a * exp ( ( log ( b ) - log ( a ) ) * cdf );

  return x;

}

bool log_uniform_check ( double a, double b )

{

  if ( a <= 1.0 )

  {

    cout << "\n";

    cout << "LOG_UNIFORM_CHECK - Fatal error!\n";

    cout << "  A <= 1.\n";

    return false;

  }

  if ( b <= a )

  {

    cout << "\n";

    cout << "LOG_UNIFORM_CHECK - Fatal error!\n";

    cout << "  B <= A.\n";

    return false;

  }

  return true;

}

double log_uniform_mean ( double a, double b )

{

  double mean;

  mean = ( b - a ) / ( log ( b ) - log ( a ) );

  return mean;

}

double log_uniform_pdf ( double x, double a, double b )

{

  double pdf;

  if ( x < a )

  {

    pdf = 0.0;

  }

  else if ( x <= b )

  {

    pdf = 1.0 / ( x * ( log ( b ) - log ( a ) ) );

  }

  else

  {

    pdf = 0.0;

  }

  return pdf;

}

double log_uniform_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = log_uniform_cdf_inv ( cdf, a, b );

  return x;

}

double log_uniform_variance ( double a, double b )

{

  double mean;

  double variance;

  mean = log_uniform_mean ( a, b );

  variance =

    ( ( 0.5 * b * b - 2.0 * mean * b + mean * mean * log ( b ) )

    - ( 0.5 * a * a - 2.0 * mean * a + mean * mean * log ( a ) ) )

    / ( log ( b ) - log ( a ) );

  return variance;

}

double logistic_cdf ( double x, double a, double b )

{

  double cdf;

  cdf = 1.0 / ( 1.0 + exp ( ( a - x ) / b ) );

  return cdf;

}

double logistic_cdf_inv ( double cdf, double a, double b )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "LOGISTIC_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = a - b * log ( ( 1.0 - cdf ) / cdf );

  return x;

}

void logistic_cdf_values ( int &n_data, double &mu, double &beta, double &x,

  double &fx )

{

# define N_MAX 12

  static double beta_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01 };

  static double fx_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.8807970779778824E+00,

     0.9820137900379084E+00,

     0.9975273768433652E+00,

     0.6224593312018546E+00,

     0.5825702064623147E+00,

     0.5621765008857981E+00,

     0.5498339973124779E+00,

     0.6224593312018546E+00,

     0.5000000000000000E+00,

     0.3775406687981454E+00,

     0.2689414213699951E+00 };

  static double mu_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01 };

  static double x_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    mu = 0.0;

    beta = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    mu = mu_vec[n_data-1];

    beta = beta_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool logistic_check ( double a, double b )

{

  if ( b <= 0.0 )

  {

    cout << " \n";

    cout << "LOGISTIC_CHECK - Fatal error!\n";

    cout << "  B <= 0.\n";

    return false;

  }

  return true;

}

double logistic_mean ( double a, double b )

{

  double mean;

  mean = a;

  return mean;

}

double logistic_pdf ( double x, double a, double b )

{

  double pdf;

  double temp;

  temp = exp ( ( a - x ) / b );

  pdf = temp / ( b * ( 1.0 + temp ) * ( 1.0 + temp ) );

  return pdf;

}

double logistic_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = logistic_cdf_inv ( cdf, a, b );

  return x;

}

double logistic_variance ( double a, double b )

{

  const double pi = 3.14159265358979323;

  double variance;

  variance = pi * pi * b * b / 3.0;

  return variance;

}

double lorentz_cdf ( double x )

{

  double cdf;

  const double pi = 3.14159265358979323;

  cdf = 0.5 + atan ( x ) / pi;

  return cdf;

}

double lorentz_cdf_inv ( double cdf )

{

  const double pi = 3.14159265358979323;

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "LORENTZ_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = tan ( pi * ( cdf - 0.5 ) );

  return x;

}

double lorentz_mean ( )

{

  double mean;

  mean = 0.0;

  return mean;

}

double lorentz_pdf ( double x )

{

  double pdf;

  const double pi = 3.14159265358979323;

  pdf = 1.0 / ( pi * ( 1.0 + x * x ) );

  return pdf;

}

double lorentz_sample ( int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = lorentz_cdf_inv ( cdf );

  return x;

}

double lorentz_variance ( )

{

  double variance;

  variance = r8_huge ( );

  return variance;

}

double maxwell_cdf ( double x, double a )

{

  double cdf;

  double p2;

  double x2;

  if ( x <= 0.0 )

  {

    cdf = 0.0;

  }

  else

  {

    x2 = x / a;

    p2 = 1.5;

    cdf = gamma_inc ( p2, x2 );

  }

  return cdf;

}

double maxwell_cdf_inv ( double cdf, double a )

{

  double cdf1;

  double cdf2;

  double cdf3;

  int it;

  int it_max = 100;

  double tol = 0.0001;

  double x;

  double x1;

  double x2;

  double x3;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "MAXWELL_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = 0.0;

    return x;

  }

  else if ( 1.0 == cdf )

  {

    x = r8_huge ( );

    return x;

  }

  x1 = 0.0;

  cdf1 = 0.0;

  x2 = 1.0;

  for ( ; ; )

  {

    cdf2 = maxwell_cdf ( x2, a );

    if ( cdf < cdf2 )

    {

      break;

    }

    x2 = 2.0 * x2;

    if ( 1000000.0 < x2 )

    {

      cout << " \n";

      cout << "MAXWELL_CDF_INV - Fatal error!\n";

      cout << "  Initial bracketing effort fails.\n";

      exit ( 1 );

    }

  }

  it = 0;

  for ( ; ; )

  {

    it = it + 1;

    x3 = 0.5 * ( x1 + x2 );

    cdf3 = maxwell_cdf ( x3, a );

    if ( r8_abs ( cdf3 - cdf ) < tol )

    {

      x = x3;

      break;

    }

    if ( it_max < it )

    {

      cout << " \n";

      cout << "MAXWELL_CDF_INV - Fatal error!\n";

      cout << "  Iteration limit exceeded.\n";

      exit ( 1 );

    }

    if ( ( cdf3 <= cdf && cdf1 <= cdf ) || ( cdf <= cdf3 && cdf <= cdf1 ) )

    {

      x1 = x3;

      cdf1 = cdf3;

    }

    else

    {

      x2 = x3;

      cdf2 = cdf3;

    }

  }

  return x;

}

bool maxwell_check ( double a )

{

  if ( a <= 0.0 )

  {

    cout << " \n";

    cout << "MAXWELL_CHECK - Fatal error!\n";

    cout << "  A <= 0.0.\n";

    return false;

  }

  return true;

}

double maxwell_mean ( double a )

{

  double mean;

  mean = sqrt ( 2.0 ) * a * r8_gamma ( 2.0 ) / r8_gamma ( 1.5 );

  return mean;

}

double maxwell_pdf ( double x, double a )

{

  double pdf;

  double y;

  if ( x <= 0.0 )

  {

    pdf = 0.0;

  }

  else

  {

    y = x / a;

    pdf = exp ( - 0.5 * y * y ) * y * y / ( sqrt ( 2.0 ) * a * r8_gamma ( 1.5 ) );

  }

  return pdf;

}

double maxwell_sample ( double a, int &seed )

{

  double a2;

  double x;

  a2 = 3.0;

  x = chi_square_sample ( a2, seed );

  x = a * sqrt ( x );

  return x;

}

double maxwell_variance ( double a )

{

  double temp;

  double variance;

  temp = r8_gamma ( 2.0 ) / r8_gamma ( 1.5 );

  variance = a * a * ( 3.0 - 2.0 * temp * temp );

  return variance;

}

bool multicoef_check ( int nfactor, int factor[] )

{

  int i;

  if ( nfactor < 1 )

  {

    cout << " \n";

    cout << "MULTICOEF_CHECK - Fatal error!\n";

    cout << "  NFACTOR < 1.\n";

    return false;

  }

  for ( i = 0; i < nfactor; i++ )

  {

    if ( factor[i] < 0 )

    {

      cout << " \n";

      cout << "MULTICOEF_CHECK - Fatal error\n";

      cout << "  Factor[" << i << "] = " << factor[i] << "\n";

      cout << "  But this value must be nonnegative.\n";

      return false;

    }

  }

  return true;

}

int multinomial_coef1 ( int nfactor, int factor[] )

{

  double facn;

  int i;

  int n;

  int ncomb;

  if (  !multicoef_check ( nfactor, factor ) )

  {

    cout << " \n";

    cout << "MULTINOMIAL_COEF1 - Fatal error!\n";

    cout << "  MULTICOEF_CHECK failed.\n";

    ncomb = -i4_huge ( );

    return ncomb;

  }

  n = i4vec_sum ( nfactor, factor );

  facn = factorial_log ( n );

  for ( i = 0; i < nfactor; i++ )

  {

    facn = facn - factorial_log ( factor[i] );

  }

  ncomb = r8_nint ( exp ( facn ) );

  return ncomb;

}

int multinomial_coef2 ( int nfactor, int factor[] )

{

  int i;

  int j;

  int k;

  int ncomb;

  if ( !multicoef_check ( nfactor, factor ) )

  {

    cout << " \n";

    cout << "MULTINOMIAL_COEF2 - Fatal error!\n";

    cout << "  MULTICOEF_CHECK failed.\n";

    ncomb = - i4_huge ( );

    return ncomb;

  }

  ncomb = 1;

  k = 0;

  for ( i = 0; i < nfactor; i++ )

  {

    for ( j = 1; j <= factor[i]; j++ )

    {

      k = k + 1;

      ncomb = ( ncomb * k ) / j;

    }

  }

  return ncomb;

}

bool multinomial_check ( int a, int b, double c[] )

{

  double c_sum;

  int i;

  if ( b < 1 )

  {

    cout << " \n";

    cout << "MULTINOMIAL_CHECK - Fatal error!\n";

    cout << "  B < 1.\n";

    return false;

  }

  for ( i = 0; i < b; i++ )

  {

    if ( c[i] < 0.0 || 1.0 < c[i] )

    {

      cout << " \n";

      cout << "MULTINOMIAL_CHECK - Fatal error!\n";

      cout << "  Input C(I) is out of range.\n";

      return false;

    }

  }

  c_sum = r8vec_sum ( b, c );

  if ( 0.0001 < r8_abs ( 1.0 - c_sum ) )

  {

    cout << " \n";

    cout << "MULTINOMIAL_CHECK - Fatal error!\n";

    cout << "  The probabilities do not sum to 1.\n";

    return false;

  }

  return true;

}

double *multinomial_covariance ( int a, int b, double c[] )

{

  double *covariance;

  int i;

  int j;

  covariance = new double[b*b];

  for ( i = 0; i < b; i++)

  {

    for ( j = 0; j < b; j++ )

    {

      if ( i == j )

      {

        covariance[i+j*b] = ( double ) ( a ) * c[i] * ( 1.0 - c[i] );

      }

      else

      {

        covariance[i+j*b] = - ( double ) ( a ) * c[i] * c[j];

      }

    }

  }

  return covariance;

}

double *multinomial_mean ( int a, int b, double c[] )

{

  int i;

  double *mean;

  mean = new double[b];

  for ( i = 0; i < b; i++ )

  {

    mean[i] = ( double ) ( a ) * c[i];

  }

  return mean;

}

double multinomial_pdf ( int x[], int a, int b, double c[] )

{

  int i;

  double pdf;

  double pdf_log;

  pdf_log = gamma_log ( ( double ) ( a + 1 ) );

  for ( i = 0; i < b; i++ )

  {

    pdf_log = pdf_log + x[i] * log ( c[i] )

      - gamma_log ( ( double ) ( x[i] + 1 ) );

  }

  pdf = exp ( pdf_log );

  return pdf;

}

int *multinomial_sample ( int a, int b, double c[], int &seed )

{

  int i;

  int ifactor;

  int ntot;

  double prob;

  double sum2;

  int *x;

  x = new int[b];

  ntot = a;

  sum2 = 1.0;

  for ( i = 0; i < b; i++ )

  {

    x[i] = 0;

  }

  for ( ifactor = 0; ifactor < b-1; ifactor++ )

  {

    prob = c[ifactor] / sum2;

    x[ifactor] = binomial_sample ( ntot, prob, seed );

    ntot = ntot - x[ifactor];

    if ( ntot <= 0 )

    {

      return x;

    }

    sum2 = sum2 - c[ifactor];

  }

  x[b-1] = ntot;

  return x;

}

double *multinomial_variance ( int a, int b, double c[] )

{

  int i;

  double *variance;

  variance = new double[b];

  for ( i = 0; i < b; i++ )

  {

    variance[i] = ( double ) ( a ) * c[i] * ( 1.0 - c[i] );

  }

  return variance;

}

double *multivariate_normal_sample ( int n, double mean[], 

  double covar_factor[], int &seed )

{

  int i;

  int j;

  double *x;

  double z;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    z = normal_01_sample ( seed );

    x[i] = mean[i];

    for ( j = 0; j <= i; j++ )

    {

      x[i] = x[i] + covar_factor[i+j*n] * z;

    }

  }

  return x;

}

double nakagami_cdf ( double x, double a, double b, double c )

{

  double cdf;

  double p2;

  double x2;

  double y;

  if ( x <= 0.0 )

  {

    cdf = 0.0;

  }

  else if ( 0.0 < x )

  {

    y = ( x - a ) / b;

    x2 = c * y * y;

    p2 = c;

    cdf = gamma_inc ( p2, x2 );

  }

  return cdf;

}

bool nakagami_check ( double a, double b, double c )

{

  if ( b <= 0.0 )

  {

    cout << " \n";

    cout << "NAKAGAMI_CHECK - Fatal error!\n";

    cout << "  B <= 0.\n";

    return false;

  }

  if ( c <= 0.0 )

  {

    cout << " \n";

    cout << "NAKAGAMI_CHECK - Fatal error!\n";

    cout << "  C <= 0.\n";

    return false;

  }

  return true;

}

double nakagami_mean ( double a, double b, double c )

{

  double mean;

  mean = a + b * r8_gamma ( c + 0.5 ) / ( sqrt ( c ) * r8_gamma ( c ) );

  return mean;

}

double nakagami_pdf ( double x, double a, double b, double c )

{

  double pdf;

  double y;

  if ( x <= 0.0 )

  {

    pdf = 0.0;

  }

  else if ( 0.0 < x )

  {

    y = ( x - a ) / b;

    pdf = 2.0 * pow ( c, c ) / ( b * r8_gamma ( c ) )

    * pow ( y, ( 2.0 * c - 1.0 ) )

    * exp ( - c * y * y );

  }

  return pdf;

}

double nakagami_variance ( double a, double b, double c )

{

  double t1;

  double t2;

  double variance;

  t1 = r8_gamma ( c + 0.5 );

  t2 = r8_gamma ( c );

  variance = b * b * ( 1.0 - t1 * t1 / ( c * t2 * t2 ) );

  return variance;

}

double negative_binomial_cdf ( int x, int a, double b )

{

  double cdf;

  int cnk;

  double pdf;

  int y;

  cdf = 0.0;

  for ( y = a; y <= x; y++ )

  {

    cnk = binomial_coef ( y-1, a-1 );

    pdf = ( double ) ( cnk ) * pow ( b, a ) * pow ( 1.0 - b, y - a );

    cdf = cdf + pdf;

  }

  return cdf;

}

int negative_binomial_cdf_inv ( double cdf, int a, double b )

{

  double cum;

  double pdf;

  int x;

  int x_max = 1000;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "NEGATIVE_BINOMIAL_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  cum = 0.0;

  x = a;

  for ( ; ; )

  {

    pdf = negative_binomial_pdf ( x, a, b );

    cum = cum + pdf;

    if ( cdf <= cum || x_max <= x )

    {

      break;

    }

    x = x + 1;

  }

  return x;

}

void negative_binomial_cdf_values ( int &n_data, int &f, int &s, double &p,

  double &cdf )

{

# define N_MAX 27

  static double cdf_vec[N_MAX] = {

     0.6367187500000000E+00,

     0.3632812500000000E+00,

     0.1445312500000000E+00,

     0.5000000000000000E+00,

     0.2265625000000000E+00,

     0.6250000000000000E-01,

     0.3437500000000000E+00,

     0.1093750000000000E+00,

     0.1562500000000000E-01,

     0.1792000000000000E+00,

     0.4096000000000000E-01,

     0.4096000000000000E-02,

     0.7047000000000000E-01,

     0.1093500000000000E-01,

     0.7290000000000000E-03,

     0.9861587127990000E+00,

     0.9149749500510000E+00,

     0.7471846521450000E+00,

     0.8499053647030009E+00,

     0.5497160941090026E+00,

     0.2662040052146710E+00,

     0.6513215599000000E+00,

     0.2639010709000000E+00,

     0.7019082640000000E-01,

     0.1000000000000000E+01,

     0.1990000000000000E-01,

     0.1000000000000000E-03 };

  static int f_vec[N_MAX] = {

     4,  3,  2,

     3,  2,  1,

     2,  1,  0,

     2,  1,  0,

     2,  1,  0,

    11, 10,  9,

    17, 16, 15,

     9,  8,  7,

     2,  1,  0 };

  static double p_vec[N_MAX] = {

     0.50E+00,

     0.50E+00,

     0.50E+00,

     0.50E+00,

     0.50E+00,

     0.50E+00,

     0.50E+00,

     0.50E+00,

     0.50E+00,

     0.40E+00,

     0.40E+00,

     0.40E+00,

     0.30E+00,

     0.30E+00,

     0.30E+00,

     0.30E+00,

     0.30E+00,

     0.30E+00,

     0.10E+00,

     0.10E+00,

     0.10E+00,

     0.10E+00,

     0.10E+00,

     0.10E+00,

     0.10E-01,

     0.10E-01,

     0.10E-01 };

  static int s_vec[N_MAX] = {

    4, 5, 6,

    4, 5, 6,

    4, 5, 6,

    4, 5, 6,

    4, 5, 6,

    1, 2, 3,

    1, 2, 3,

    1, 2, 3,

    0, 1, 2 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    f = 0;

    s = 0;

    p = 0.0;

    cdf = 0.0;

  }

  else

  {

    f = f_vec[n_data-1];

    s = s_vec[n_data-1];

    p = p_vec[n_data-1];

    cdf = cdf_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool negative_binomial_check ( int a, double b )

{

  if ( a < 0 )

  {

    cout << " \n";

    cout << "NEGATIVE_BINOMIAL_CHECK - Fatal error!\n";

    cout << "  A < 0.\n";

    return false;

  }

  if ( b <= 0.0 || 1.0 < b )

  {

    cout << " \n";

    cout << "NEGATIVE_BINOMIAL_CHECK - Fatal error!\n";

    cout << "  B <= 0 or 1 < B.\n";

    return false;

  }

  return true;

}

double negative_binomial_mean ( int a, double b )

{

  double mean;

  mean = ( double ) ( a ) / b;

  return mean;

}

double negative_binomial_pdf ( int x, int a, double b )

{

  int cnk;

  double pdf;

  if ( x < a )

  {

    pdf = 0.0;

  }

  else

  {

    cnk = binomial_coef ( x-1, a-1 );

    pdf = ( double ) ( cnk ) * pow ( b, a ) * pow ( 1.0 - b, x - a );

  }

  return pdf;

}

int negative_binomial_sample ( int a, double b, int &seed )

{

  int num_success;

  double r;

  int x;

  if ( b == 1.0 )

  {

    x = a;

    return x;

  }

  else if ( b == 0.0 )

  {

    x = i4_huge ( );

    return x;

  }

  x = 0;

  num_success = 0;

  while ( num_success < a )

  {

    x = x + 1;

    r = r8_uniform_01 ( seed );

    if ( r <= b )

    {

      num_success = num_success + 1;

    }

  }

  return x;

}

double negative_binomial_variance ( int a, double b )

{

  double variance;

  variance = ( double ) ( a ) * ( 1.0 - b ) / ( b * b );

  return variance;

}

double normal_01_cdf ( double x )

{

  double a1 = 0.398942280444;

  double a2 = 0.399903438504;

  double a3 = 5.75885480458;

  double a4 = 29.8213557808;

  double a5 = 2.62433121679;

  double a6 = 48.6959930692;

  double a7 = 5.92885724438;

  double b0 = 0.398942280385;

  double b1 = 3.8052E-08;

  double b2 = 1.00000615302;

  double b3 = 3.98064794E-04;

  double b4 = 1.98615381364;

  double b5 = 0.151679116635;

  double b6 = 5.29330324926;

  double b7 = 4.8385912808;

  double b8 = 15.1508972451;

  double b9 = 0.742380924027;

  double b10 = 30.789933034;

  double b11 = 3.99019417011;

  double cdf;

  double q;

  double y;

  if ( r8_abs ( x ) <= 1.28 )

  {

    y = 0.5 * x * x;

    q = 0.5 - r8_abs ( x ) * ( a1 - a2 * y / ( y + a3 - a4 / ( y + a5

      + a6 / ( y + a7 ) ) ) );

  }

  else if ( r8_abs ( x ) <= 12.7 )

  {

    y = 0.5 * x * x;

    q = exp ( - y ) * b0 / ( r8_abs ( x ) - b1

      + b2 / ( r8_abs ( x ) + b3

      + b4 / ( r8_abs ( x ) - b5

      + b6 / ( r8_abs ( x ) + b7

      - b8 / ( r8_abs ( x ) + b9

      + b10 / ( r8_abs ( x ) + b11 ) ) ) ) ) );

  }

  else

  {

    q = 0.0;

  }

  if ( x < 0.0 )

  {

    cdf = q;

  }

  else

  {

    cdf = 1.0 - q;

  }

  return cdf;

}

double normal_01_cdf_inv ( double p )

{

  double a[8] = {

    3.3871328727963666080,     1.3314166789178437745e+2,

    1.9715909503065514427e+3,  1.3731693765509461125e+4,

    4.5921953931549871457e+4,  6.7265770927008700853e+4,

    3.3430575583588128105e+4,  2.5090809287301226727e+3 };

  double b[8] = {

    1.0,                       4.2313330701600911252e+1,

    6.8718700749205790830e+2,  5.3941960214247511077e+3,

    2.1213794301586595867e+4,  3.9307895800092710610e+4,

    2.8729085735721942674e+4,  5.2264952788528545610e+3 };

  double c[8] = {

    1.42343711074968357734,     4.63033784615654529590,

    5.76949722146069140550,     3.64784832476320460504,

    1.27045825245236838258,     2.41780725177450611770e-1,

    2.27238449892691845833e-2,  7.74545014278341407640e-4 };

  double const1 = 0.180625;

  double const2 = 1.6;

  double d[8] = {

    1.0,                        2.05319162663775882187,

    1.67638483018380384940,     6.89767334985100004550e-1,

    1.48103976427480074590e-1,  1.51986665636164571966e-2,

    5.47593808499534494600e-4,  1.05075007164441684324e-9 };

  double e[8] = {

    6.65790464350110377720,     5.46378491116411436990,

    1.78482653991729133580,     2.96560571828504891230e-1,

    2.65321895265761230930e-2,  1.24266094738807843860e-3,

    2.71155556874348757815e-5,  2.01033439929228813265e-7 };

  double f[8] = {

    1.0,                        5.99832206555887937690e-1,

    1.36929880922735805310e-1,  1.48753612908506148525e-2,

    7.86869131145613259100e-4,  1.84631831751005468180e-5,

    1.42151175831644588870e-7,  2.04426310338993978564e-15 };

  double q;

  double r;

  double split1 = 0.425;

  double split2 = 5.0;

  double value;

  if ( p <= 0.0 )

  {

    value = -r8_huge ( );

    return value;

  }

  if ( 1.0 <= p )

  {

    value = r8_huge ( );

    return value;

  }

  q = p - 0.5;

  if ( r8_abs ( q ) <= split1 )

  {

    r = const1 - q * q;

    value = q * r8poly_value ( 8, a, r ) / r8poly_value ( 8, b, r );

  }

  else

  {

    if ( q < 0.0 )

    {

      r = p;

    }

    else

    {

      r = 1.0 - p;

    }

    if ( r <= 0.0 )

    {

      value = r8_huge ( );

    }

    else

    {

      r = sqrt ( - log ( r ) );

      if ( r <= split2 )

      {

        r = r - const2;

        value = r8poly_value ( 8, c, r ) / r8poly_value ( 8, d, r );

       }

       else

       {

         r = r - split2;

         value = r8poly_value ( 8, e, r ) / r8poly_value ( 8, f, r );

      }

    }

    if ( q < 0.0 )

    {

      value = - value;

    }

  }

  return value;

}

void normal_01_cdf_values ( int &n_data, double &x, double &fx )

{

# define N_MAX 17

  static double fx_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.5398278372770290E+00,

     0.5792597094391030E+00,

     0.6179114221889526E+00,

     0.6554217416103242E+00,

     0.6914624612740131E+00,

     0.7257468822499270E+00,

     0.7580363477769270E+00,

     0.7881446014166033E+00,

     0.8159398746532405E+00,

     0.8413447460685429E+00,

     0.9331927987311419E+00,

     0.9772498680518208E+00,

     0.9937903346742239E+00,

     0.9986501019683699E+00,

     0.9997673709209645E+00,

     0.9999683287581669E+00 };

  static double x_vec[N_MAX] = {

     0.0000000000000000E+00,

     0.1000000000000000E+00,

     0.2000000000000000E+00,

     0.3000000000000000E+00,

     0.4000000000000000E+00,

     0.5000000000000000E+00,

     0.6000000000000000E+00,

     0.7000000000000000E+00,

     0.8000000000000000E+00,

     0.9000000000000000E+00,

     0.1000000000000000E+01,

     0.1500000000000000E+01,

     0.2000000000000000E+01,

     0.2500000000000000E+01,

     0.3000000000000000E+01,

     0.3500000000000000E+01,

     0.4000000000000000E+01 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

double normal_01_mean ( )

{

  double mean;

  mean = 0.0;

  return mean;

}

double normal_01_pdf ( double x )

{

  double pdf;

  const double pi = 3.14159265358979323;

  pdf = exp ( -0.5 * x * x ) / sqrt ( 2.0 * pi );

  return pdf;

}

double normal_01_sample ( int &seed )

{

  const double pi = 3.14159265358979323;

  double r1;

  double r2;

  double x;

  r1 = r8_uniform_01 ( seed );

  r2 = r8_uniform_01 ( seed );

  x = sqrt ( -2.0 * log ( r1 ) ) * cos ( 2.0 * pi * r2 );

  return x;

}

double normal_01_variance ( )

{

  double variance;

  variance = 1.0;

  return variance;

}

double *normal_01_vector ( int n, int &seed )

{

  int i;

  int m;

  const double pi = 3.14159265358979323;

  double *r;

  double *x;

  int x_hi;

  int x_lo;

  x = new double[n];

  x_lo = 1;

  x_hi = n;

  if ( x_hi - x_lo + 1 == 1 )

  {

    r = r8vec_uniform_01 ( 2, seed );

    x[x_hi-1] = sqrt ( -2.0 * log ( r[0] ) ) * cos ( 2.0 * pi * r[1] );

    delete [] r;

  }

  else if ( ( x_hi - x_lo + 1 ) % 2 == 0 )

  {

    m = ( x_hi - x_lo + 1 ) / 2;

    r = r8vec_uniform_01 ( 2*m, seed );

    for ( i = 0; i <= 2*m-2; i = i + 2 )

    {

      x[x_lo+i-1] = sqrt ( -2.0 * log ( r[i] ) ) * cos ( 2.0 * pi * r[i+1] );

      x[x_lo+i  ] = sqrt ( -2.0 * log ( r[i] ) ) * sin ( 2.0 * pi * r[i+1] );

    }

    delete [] r;

  }

  else

  {

    x_hi = x_hi - 1;

    m = ( x_hi - x_lo + 1 ) / 2 + 1;

    r = r8vec_uniform_01 ( 2*m, seed );

    for ( i = 0; i <= 2*m-4; i = i + 2 )

    {

      x[x_lo+i-1] = sqrt ( -2.0 * log ( r[i] ) ) * cos ( 2.0 * pi * r[i+1] );

      x[x_lo+i  ] = sqrt ( -2.0 * log ( r[i] ) ) * sin ( 2.0 * pi * r[i+1] );

    }

    i = 2*m - 2;

    x[x_lo+i-1] = sqrt ( -2.0 * log ( r[i] ) ) * cos ( 2.0 * pi * r[i+1] );

    delete [] r;

  }

  return x;

}

double normal_cdf ( double x, double a, double b )

{

  double cdf;

  double y;

  y = ( x - a ) / b;

  cdf = normal_01_cdf ( y );

  return cdf;

}

double normal_cdf_inv ( double cdf, double a, double b )

{

  double x;

  double x2;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << "\n";

    cout << "NORMAL_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x2 = normal_01_cdf_inv ( cdf );

  x = a + b * x2;

  return x;

}

void normal_cdf_values ( int &n_data, double &mu, double &sigma, double &x,

  double &fx )

{

# define N_MAX 12

  static double fx_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.9772498680518208E+00,

     0.9999683287581669E+00,

     0.9999999990134124E+00,

     0.6914624612740131E+00,

     0.6305586598182364E+00,

     0.5987063256829237E+00,

     0.5792597094391030E+00,

     0.6914624612740131E+00,

     0.5000000000000000E+00,

     0.3085375387259869E+00,

     0.1586552539314571E+00 };

  static double mu_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01 };

  static double sigma_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01 };

  static double x_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    mu = 0.0;

    sigma = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    mu = mu_vec[n_data-1];

    sigma = sigma_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool normal_check ( double a, double b )

{

  if ( b <= 0.0 )

  {

    cout << "\n";

    cout << "NORMAL_CHECK - Fatal error!\n";

    cout << "  B <= 0.\n";

    return false;

  }

  return true;

}

double normal_mean ( double a, double b )

{

  double mean;

  mean = a;

  return mean;

}

double normal_pdf ( double x, double a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  double y;

  y = ( x - a ) / b;

  pdf = exp ( -0.5 * y * y )  / ( b * sqrt ( 2.0 * pi ) );

  return pdf;

}

double normal_sample ( double a, double b, int &seed )

{

  double x;

  x = normal_01_sample ( seed );

  x = a + b * x;

  return x;

}

double normal_variance ( double a, double b )

{

  double variance;

  variance = b * b;

  return variance;

}

double *normal_vector ( int n, double mean, double dev, int &seed )

{

  int i;

  double *x;

  x = normal_01_vector ( n, seed );

  for ( i = 0; i < n; i++ )

  {

    x[i] = mean + dev * x[i];

  }

  return x;

}

double normal_truncated_ab_cdf ( double x, double mu, double s, double a, 

  double b )

{

  double alpha;

  double alpha_cdf;

  double beta;

  double beta_cdf;

  double cdf;

  double xi;

  double xi_cdf;

  alpha = ( a - mu ) / s;

  beta = ( b - mu ) / s;

  xi = ( x - mu ) / s;

  alpha_cdf = normal_01_cdf ( alpha );

  beta_cdf = normal_01_cdf ( beta );

  xi_cdf = normal_01_cdf ( xi );

  cdf = ( xi_cdf - alpha_cdf ) / ( beta_cdf - alpha_cdf );

  return cdf;

}

double normal_truncated_ab_cdf_inv ( double cdf, double mu, double s, double a, 

  double b )

{

  double alpha;

  double alpha_cdf;

  double beta;

  double beta_cdf;

  double x;

  double xi;

  double xi_cdf;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "NORMAL_TRUNCATED_AB_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  alpha = ( a - mu ) / s;

  beta = ( b - mu ) / s;

  alpha_cdf = normal_01_cdf ( alpha );

  beta_cdf = normal_01_cdf ( beta );

  xi_cdf = ( beta_cdf - alpha_cdf ) * cdf + alpha_cdf;

  xi = normal_01_cdf_inv ( xi_cdf );

  x = mu + s * xi;

  return x;

}

double normal_truncated_ab_mean ( double mu, double s, double a, double b )

{

  double alpha;

  double alpha_cdf;

  double alpha_pdf;

  double beta;

  double beta_cdf;

  double beta_pdf;

  double mean;

  alpha = ( a - mu ) / s;

  beta = ( b - mu ) / s;

  alpha_cdf = normal_01_cdf ( alpha );

  beta_cdf = normal_01_cdf ( beta  );

  alpha_pdf = normal_01_pdf ( alpha );

  beta_pdf = normal_01_pdf ( beta );

  mean = mu + s * ( alpha_pdf - beta_pdf ) / ( beta_cdf - alpha_cdf );

  return mean;

}

double normal_truncated_ab_pdf ( double x, double mu, double s, double a, 

  double b )

{

  double alpha;

  double alpha_cdf;

  double beta;

  double beta_cdf;

  double pdf;

  double xi;

  double xi_pdf;

  alpha = ( a - mu ) / s;

  beta = ( b - mu ) / s;

  xi = ( x - mu ) / s;

  alpha_cdf = normal_01_cdf ( alpha );

  beta_cdf = normal_01_cdf ( beta );

  xi_pdf = normal_01_pdf ( xi );

  pdf = xi_pdf / ( beta_cdf - alpha_cdf ) / s;

  return pdf;

}

double normal_truncated_ab_sample ( double mu, double s, double a, double b, 

  int &seed )

{

  double alpha;

  double alpha_cdf;

  double beta;

  double beta_cdf;

  double u;

  double x;

  double xi;

  double xi_cdf;

  alpha = ( a - mu ) / s;

  beta = ( b - mu ) / s;

  alpha_cdf = normal_01_cdf ( alpha );

  beta_cdf = normal_01_cdf ( beta );

  u = r8_uniform_01 ( seed );

  xi_cdf = alpha_cdf + u * ( beta_cdf - alpha_cdf );

  xi = normal_01_cdf_inv ( xi_cdf );

  x = mu + s * xi;

  return x;

}

double normal_truncated_ab_variance ( double mu, double s, double a, double b )

{

  double alpha;

  double alpha_cdf;

  double alpha_pdf;

  double beta;

  double beta_cdf;

  double beta_pdf;

  double variance;

  alpha = ( a - mu ) / s;

  beta = ( b - mu ) / s;

  alpha_pdf = normal_01_pdf ( alpha );

  beta_pdf = normal_01_pdf ( beta );

  alpha_cdf = normal_01_cdf ( alpha );

  beta_cdf = normal_01_cdf ( beta );

  variance = s * s * ( 1.0 

    + ( alpha * alpha_pdf - beta * beta_pdf ) / ( beta_cdf - alpha_cdf ) 

    - pow ( ( alpha_pdf - beta_pdf ) / ( beta_cdf - alpha_cdf ), 2 ) );

  return variance;

}

double normal_truncated_a_cdf ( double x, double mu, double s, double a )

{

  double alpha;

  double alpha_cdf;

  double cdf;

  double xi;

  double xi_cdf;

  alpha = ( a - mu ) / s;

  xi = ( x - mu ) / s;

  alpha_cdf = normal_01_cdf ( alpha );

  xi_cdf = normal_01_cdf ( xi );

  cdf = ( xi_cdf - alpha_cdf ) / ( 1.0 - alpha_cdf );

  return cdf;

}

double normal_truncated_a_cdf_inv ( double cdf, double mu, double s, double a )

{

  double alpha;

  double alpha_cdf;

  double x;

  double xi;

  double xi_cdf;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "NORMAL_TRUNCATED_A_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  alpha = ( a - mu ) / s;

  alpha_cdf = normal_01_cdf ( alpha );

  xi_cdf = ( 1.0 - alpha_cdf ) * cdf + alpha_cdf;

  xi = normal_01_cdf_inv ( xi_cdf );

  x = mu + s * xi;

  return x;

}

double normal_truncated_a_mean ( double mu, double s, double a )

{

  double alpha;

  double alpha_cdf;

  double alpha_pdf;

  double mean;

  alpha = ( a - mu ) / s;

  alpha_cdf = normal_01_cdf ( alpha );

  alpha_pdf = normal_01_pdf ( alpha );

  mean = mu + s * alpha_pdf / ( 1.0 - alpha_cdf );

  return mean;

}

double normal_truncated_a_pdf ( double x, double mu, double s, double a )

{

  double alpha;

  double alpha_cdf;

  double pdf;

  double xi;

  double xi_pdf;

  alpha = ( a - mu ) / s;

  xi = ( x - mu ) / s;

  alpha_cdf = normal_01_cdf ( alpha );

  xi_pdf = normal_01_pdf ( xi );

  pdf = xi_pdf / ( 1.0 - alpha_cdf ) / s;

  return pdf;

}

double normal_truncated_a_sample ( double mu, double s, double a, int &seed )

{

  double alpha;

  double alpha_cdf;

  double u;

  double x;

  double xi;

  double xi_cdf;

  alpha = ( a - mu ) / s;

  alpha_cdf = normal_01_cdf ( alpha );

  u = r8_uniform_01 ( seed );

  xi_cdf = alpha_cdf + u * ( 1.0 - alpha_cdf );

  xi = normal_01_cdf_inv ( xi_cdf );

  x = mu + s * xi;

  return x;

}

double normal_truncated_a_variance ( double mu, double s, double a )

{

  double alpha;

  double alpha_cdf;

  double alpha_pdf;

  double variance;

  alpha = ( a - mu ) / s;

  alpha_pdf = normal_01_pdf ( alpha );

  alpha_cdf = normal_01_cdf ( alpha );

  variance = s * s * ( 1.0 

    + alpha * alpha_pdf / ( 1.0 - alpha_cdf ) 

    - pow ( alpha_pdf / ( 1.0 - alpha_cdf ), 2 ) );

  return variance;

}

double normal_truncated_b_cdf ( double x, double mu, double s, double b )

{

  double beta;

  double beta_cdf;

  double cdf;

  double xi;

  double xi_cdf;

  beta = ( b - mu ) / s;

  xi = ( x - mu ) / s;

  beta_cdf = normal_01_cdf ( beta );

  xi_cdf = normal_01_cdf ( xi );

  cdf = xi_cdf / beta_cdf;

  return cdf;

}

double normal_truncated_b_cdf_inv ( double cdf, double mu, double s, double b )

{

  double beta;

  double beta_cdf;

  double x;

  double xi;

  double xi_cdf;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "NORMAL_TRUNCATED_B_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  beta = ( b - mu ) / s;

  beta_cdf = normal_01_cdf ( beta );

  xi_cdf = beta_cdf * cdf;

  xi = normal_01_cdf_inv ( xi_cdf );

  x = mu + s * xi;

  return x;

}

double normal_truncated_b_mean ( double mu, double s, double b )

{

  double beta;

  double beta_cdf;

  double beta_pdf;

  double mean;

  beta = ( b - mu ) / s;

  beta_cdf = normal_01_cdf ( beta );

  beta_pdf = normal_01_pdf ( beta );

  mean = mu - s * beta_pdf / beta_cdf;

  return mean;

}

double normal_truncated_b_pdf ( double x, double mu, double s, double b )

{

  double beta;

  double beta_cdf;

  double pdf;

  double xi;

  double xi_pdf;

  beta = ( b - mu ) / s;

  xi = ( x - mu ) / s;

  beta_cdf = normal_01_cdf ( beta );

  xi_pdf = normal_01_pdf ( xi );

  pdf = xi_pdf / beta_cdf / s;

  return pdf;

}

double normal_truncated_b_sample ( double mu, double s, double b, int &seed )

{

  double beta;

  double beta_cdf;

  double u;

  double x;

  double xi;

  double xi_cdf;

  beta = ( b - mu ) / s;

  beta_cdf = normal_01_cdf ( beta );

  u = r8_uniform_01 ( seed );

  xi_cdf = u * beta_cdf;

  xi = normal_01_cdf_inv ( xi_cdf );

  x = mu + s * xi;

  return x;

}

double normal_truncated_b_variance ( double mu, double s, double b )

{

  double beta;

  double beta_cdf;

  double beta_pdf;

  double variance;

  beta = ( b - mu ) / s;

  beta_pdf = normal_01_pdf ( beta );

  beta_cdf = normal_01_cdf ( beta );

  variance = s * s * ( 1.0 

    - beta * beta_pdf / beta_cdf 

    - pow ( beta_pdf / beta_cdf, 2 ) );

  return variance;

}

void owen_values ( int &n_data, double &h, double &a, double &t )

{

# define N_MAX 28

  static double a_vec[N_MAX] = {

    0.2500000000000000E+00,

    0.4375000000000000E+00,

    0.9687500000000000E+00,

    0.0625000000000000E+00,

    0.5000000000000000E+00,

    0.9999975000000000E+00,

    0.5000000000000000E+00,

    0.1000000000000000E+01,

    0.2000000000000000E+01,

    0.3000000000000000E+01,

    0.5000000000000000E+00,

    0.1000000000000000E+01,

    0.2000000000000000E+01,

    0.3000000000000000E+01,

    0.5000000000000000E+00,

    0.1000000000000000E+01,

    0.2000000000000000E+01,

    0.3000000000000000E+01,

    0.5000000000000000E+00,

    0.1000000000000000E+01,

    0.2000000000000000E+01,

    0.3000000000000000E+01,

    0.5000000000000000E+00,

    0.1000000000000000E+01,

    0.2000000000000000E+01,

    0.3000000000000000E+01,

    0.1000000000000000E+02,

    0.1000000000000000E+03 };

  static double h_vec[N_MAX] = {

    0.0625000000000000E+00,

    6.5000000000000000E+00,

    7.0000000000000000E+00,

    4.7812500000000000E+00,

    2.0000000000000000E+00,

    1.0000000000000000E+00,

    0.1000000000000000E+01,

    0.1000000000000000E+01,

    0.1000000000000000E+01,

    0.1000000000000000E+01,

    0.5000000000000000E+00,

    0.5000000000000000E+00,

    0.5000000000000000E+00,

    0.5000000000000000E+00,

    0.2500000000000000E+00,

    0.2500000000000000E+00,

    0.2500000000000000E+00,

    0.2500000000000000E+00,

    0.1250000000000000E+00,

    0.1250000000000000E+00,

    0.1250000000000000E+00,

    0.1250000000000000E+00,

    0.7812500000000000E-02,

    0.7812500000000000E-02,

    0.7812500000000000E-02,

    0.7812500000000000E-02,

    0.7812500000000000E-02,

    0.7812500000000000E-02 };

  static double t_vec[N_MAX] = {

    3.8911930234701366E-02,

    2.0005773048508315E-11,

    6.3990627193898685E-13,

    1.0632974804687463E-07,

    8.6250779855215071E-03,

    6.6741808978228592E-02,

    0.4306469112078537E-01,

    0.6674188216570097E-01,

    0.7846818699308410E-01,

    0.7929950474887259E-01,

    0.6448860284750376E-01,

    0.1066710629614485E+00,

    0.1415806036539784E+00,

    0.1510840430760184E+00,

    0.7134663382271778E-01,

    0.1201285306350883E+00,

    0.1666128410939293E+00,

    0.1847501847929859E+00,

    0.7317273327500385E-01,

    0.1237630544953746E+00,

    0.1737438887583106E+00,

    0.1951190307092811E+00,

    0.7378938035365546E-01,

    0.1249951430754052E+00,

    0.1761984774738108E+00,

    0.1987772386442824E+00,

    0.2340886964802671E+00,

    0.2479460829231492E+00 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    h = 0.0;

    a = 0.0;

    t = 0.0;

  }

  else

  {

    h = h_vec[n_data-1];

    a = a_vec[n_data-1];

    t = t_vec[n_data-1];

  }

  return;

# undef N_MAX

}

double pareto_cdf ( double x, double a, double b )

{

  double cdf;

  if ( x < a )

  {

    cdf = 0.0;

  }

  else

  {

    cdf = 1.0 - pow ( ( a / x ), b );

  }

  return cdf;

}

double pareto_cdf_inv ( double cdf, double a, double b )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "PARETO_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = a / pow ( 1.0 - cdf, 1.0 / b );

  return x;

}

bool pareto_check ( double a, double b )

{

  if ( a <= 0.0 )

  {

    cerr << " \n";

    cerr << "PARETO_CHECK - Fatal error!\n";

    cerr << "  A <= 0.\n";

    return false;

  }

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "PARETO_CHECK - Fatal error!\n";

    cerr << "  B <= 0.\n";

    return false;

  }

  return true;

}

double pareto_mean ( double a, double b )

{

  double mean;

  if ( b <= 1.0 )

  {

    cerr << " \n";

    cerr << "PARETO_MEAN - Fatal error!\n";

    cerr << "  For B <= 1, the mean does not exist.\n";

    mean = 0.0;

    return mean;

  }

  mean = b * a / ( b - 1.0 );

  return mean;

}

double pareto_pdf ( double x, double a, double b )

{

  double pdf;

  if ( x < a )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = b * pow ( a, b ) / pow ( x, ( b + 1.0 ) );

  }

  return pdf;

}

double pareto_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = pareto_cdf_inv ( cdf, a, b );

  return x;

}

double pareto_variance ( double a, double b )

{

  double variance;

  if ( b <= 2.0 )

  {

    cout << " \n";

    cout << "PARETO_VARIANCE - Warning!\n";

    cout << "  For B <= 2, the variance does not exist.\n";

    variance = 0.0;

    return variance;

  }

  variance = a * a * b / ( pow ( ( b - 1.0 ), 2 ) * ( b - 2.0 ) );

  return variance;

}

bool pearson_05_check ( double a, double b, double c )

{

  if ( a <= 0.0 )

  {

    cerr << " \n";

    cerr << "PEARSON_05_CHECK - Fatal error!\n";

    cerr << "  A <= 0.\n";

    return false;

  }

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "PEARSON_05_CHECK - Fatal error!\n";

    cerr << "  B <= 0.\n";

    return false;

  }

  return true;

}

double pearson_05_mean ( double a, double b, double c )

{

  double mean;

  if ( b <= 1.0 )

  {

    cout << " \n";

    cout << "PEARSON_05_MEAN - Warning!\n";

    cout << "  MEAN undefined for B <= 1.\n";

    mean = c;

    return mean;

  }

  mean = c + a / ( b - 1.0 );

  return mean;

}

double pearson_05_pdf ( double x, double a, double b, double c )

{

  double pdf;

  if ( x <= c )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = pow ( a, b ) * pow ( x - c, - b - 1.0 )

      * exp ( - a / ( x - c ) ) / r8_gamma ( b );

  }

  return pdf;

}

double pearson_05_sample ( double a, double b, double c, int &seed )

{

  double a2;

  double b2;

  double c2;

  double x;

  double x2;

  a2 = 0.0;

  b2 = b;

  c2 = 1.0 / a;

  x2 = gamma_sample ( a2, b2, c2, seed );

  x = c + 1.0 / x2;

  return x;

}

bool planck_check ( double a, double b )

{

  if ( a <= 0.0 )

  {

    cerr << "\n";

    cerr << "PLANCK_CHECK - Fatal error!\n";

    cerr << "  A <= 0.\n";

    return false;

  }

  if ( b <= 0.0 )

  {

    cerr << "\n";

    cerr << "PLANCK_CHECK - Fatal error!\n";

    cerr << "  B <= 0.\n";

    return false;

  }

  return true;

}

double planck_mean ( double a, double b )

{

  double mean;

  mean = ( b + 1.0 ) * zeta ( b + 2.0 ) / zeta ( b + 1.0 );

  return mean;

}

double planck_pdf ( double x, double a, double b )

{

  double k;

  double pdf;

  if ( x < 0.0 )

  {

    pdf = 0.0;

  }

  else

  {

    k = r8_gamma ( b + 1.0 ) * zeta ( b + 1.0 );

    pdf = pow ( a, b + 1.0 ) * pow ( x, b ) / ( exp ( a * x ) - 1.0 ) / k;

  }

  return pdf;

}

double planck_sample ( double a, double b, int &seed )

{

  double a2;

  double b2;

  double c2;

  double g;

  double x;

  int z;

  a2 = 0.0;

  b2 = 1.0;

  c2 = b + 1.0;

  g = gamma_sample ( a2, b2, c2, seed );

  z = zipf_sample ( c2, seed );

  x = g / ( a * ( double ) ( z ) );

  return x;

}

double planck_variance ( double a, double b )

{

  double variance;

  variance = 0.0;

  return variance;

}

double point_distance_1d_pdf ( double x, int a, double b )

{

  double pdf;

  if ( a < 1 )

  {

    cerr << " \n";

    cerr << "POINT_DISTANCE_1D_PDF - Fatal error!\n";

    cerr << "  Input parameter A < 1.\n";

    exit ( 1 );

  }

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "POINT_DISTANCE_1D_PDF - Fatal error!\n";

    cerr << "  Input parameter B <= 0.0.\n";

    exit ( 1 );

  }

  if ( x < 0.0 )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = pow ( b, a ) * pow ( x, a - 1 ) * exp ( - b * x )

      / i4_factorial ( a - 1 );

  }

  return pdf;

}

double point_distance_2d_pdf ( double x, int a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  if ( a < 1 )

  {

    cerr << " \n";

    cerr << "POINT_DISTANCE_2D_PDF - Fatal error!\n";

    cerr << "  Input parameter A < 1.\n";

    exit ( 1 );

  }

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "POINT_DISTANCE_2D_PDF - Fatal error!\n";

    cerr << "  Input parameter B <= 0.0.\n";

    exit ( 1 );

  }

  if ( x < 0.0 )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = 2.0 * pow ( b * pi, a ) * pow ( x, 2 * a - 1 )

      * exp ( - b * pi * x * x ) / i4_factorial ( a - 1 );

  }

  return pdf;

}

double point_distance_3d_pdf ( double x, int a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  if ( a < 1 )

  {

    cerr << " \n";

    cerr << "POINT_DISTANCE_3D_PDF - Fatal error!\n";

    cerr << "  Input parameter A < 1.\n";

    exit ( 1 );

  }

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "POINT_DISTANCE_3D_PDF - Fatal error!\n";

    cerr << "  Input parameter B <= 0.0.\n";

    exit ( 1 );

  }

  if ( x < 0.0 )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = 3.0 * pow ( ( ( 4.0 / 3.0 ) * b * pi ), a )

      * pow ( x, 3 * a - 1 ) * exp ( - ( 4.0 / 3.0 ) * b * pi * x * x * x )

      / i4_factorial ( a - 1 );

  }

  return pdf;

}

double poisson_cdf ( int k, double a )

{

  double cdf;

  int i;

  double last;

  double next;

  if ( a <= 0.0 )

  {

    cerr << "\n";

    cerr << "POISSON_CDF - Fatal error!\n";

    cerr << "  A <= 0.\n";

    return 0;

  }

  if ( k < 0 )

  {

    cdf = 0.0;

    return cdf;

  }

  next = exp ( - a );

  cdf = next;

  for ( i = 1; i <= k; i++ )

  {

    last = next;

    next = last * a / ( double ) i;

    cdf = cdf + next;

  }

  return cdf;

}

int poisson_cdf_inv ( double cdf, double a )

{

  int i;

  double last;

  double newval;

  double sum2;

  double sumold;

  int x;

  int xmax = 100;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "POISSON_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  sum2 = 0.0;

  for ( i = 0; i <= xmax; i++ )

  {

    sumold = sum2;

    if ( i == 0 )

    {

      newval = exp ( - a );

      sum2 = newval;

    }

    else

    {

      last = newval;

      newval = last * a / ( double ) ( i );

      sum2 = sum2 + newval;

    }

    if ( sumold <= cdf && cdf <= sum2 )

    {

      x = i;

      return x;

    }

  }

  cout << " \n";

  cout << "POISSON_CDF_INV - Warning!\n";

  cout << "  Exceeded XMAX = " << xmax << "\n";

  x = xmax;

  return x;

}

void poisson_cdf_values ( int &n_data, double &a, int &x, double &fx )

{

# define N_MAX 21

  static double a_vec[N_MAX] = {

     0.02E+00,

     0.10E+00,

     0.10E+00,

     0.50E+00,

     0.50E+00,

     0.50E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     1.00E+00,

     2.00E+00,

     2.00E+00,

     2.00E+00,

     2.00E+00,

     5.00E+00,

     5.00E+00,

     5.00E+00,

     5.00E+00,

     5.00E+00,

     5.00E+00,

     5.00E+00 };

  static double fx_vec[N_MAX] = {

     0.9801986733067553E+00,

     0.9048374180359596E+00,

     0.9953211598395555E+00,

     0.6065306597126334E+00,

     0.9097959895689501E+00,

     0.9856123220330293E+00,

     0.3678794411714423E+00,

     0.7357588823428846E+00,

     0.9196986029286058E+00,

     0.9810118431238462E+00,

     0.1353352832366127E+00,

     0.4060058497098381E+00,

     0.6766764161830635E+00,

     0.8571234604985470E+00,

     0.6737946999085467E-02,

     0.4042768199451280E-01,

     0.1246520194830811E+00,

     0.2650259152973617E+00,

     0.4404932850652124E+00,

     0.6159606548330631E+00,

     0.7621834629729387E+00 };

  static int x_vec[N_MAX] = {

     0, 0, 1, 0,

     1, 2, 0, 1,

     2, 3, 0, 1,

     2, 3, 0, 1,

     2, 3, 4, 5,

     6 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    a = 0.0;

    x = 0;

    fx = 0.0;

  }

  else

  {

    a = a_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool poisson_check ( double a )

{

  if ( a <= 0.0 )

  {

    cerr << " \n";

    cerr << "POISSON_CHECK - Fatal error!\n";

    cerr << "  A <= 0.\n";

    return false;

  }

  return true;

}

double poisson_kernel ( double r, int n, double c[], double x[], double y[] )

{

  double area;

  double b;

  double p;

  double t;

  double xc_diff_norm;

  double xy_diff_norm;

  xc_diff_norm = r8vec_diff_norm ( n, x, c );

  xy_diff_norm = r8vec_diff_norm ( n, x, y );

  area = sphere_unit_area_nd ( n );

  t = ( r + xc_diff_norm ) * ( r - xc_diff_norm );

  b = r * area * pow ( xy_diff_norm, n );

  p = t / b;

  return p;

}

double poisson_mean ( double a )

{

  if ( a <= 0.0 )

  {

    cerr << "\n";

    cerr << "POISSON_MEAN - Fatal error!\n" ;

    cerr << "  A <= 0.\n";

    return 0;

  }

  return a;

}

double poisson_pdf ( int k, double a )

{

  double pdf;

  if ( a <= 0.0 )

  {

    cerr << "\n";

    cerr << "POISSON_PDF - Fatal error!\n";

    cerr << "  A <= 0.\n";

    pdf = 0.0;

    return pdf;

  }

  pdf = exp ( -a ) * pow ( a, ( double ) k ) / i4_factorial ( k );

  return pdf;

}

int poisson_sample ( double a, int &seed )

{

  double cdf;

  int i;

  int KMAX = 100;

  double last;

  double next;

  double sum;

  double sumold;

  if ( a <= 0.0 )

  {

    cerr << "\n";

    cerr << "POISSON_SAMPLE - Fatal error!\n";

    cerr << "  A <= 0.\n";

    return 0;

  }

  cdf = uniform_01_sample ( seed );

  sum = 0.0;

  for ( i = 0; i <= KMAX; i++ )

  {

    sumold = sum;

    if ( i == 0 )

    {

      next = exp ( -a );

      sum = next;

    }

    else

    {

      last = next;

      next = last * a / ( double ) i;

      sum = sum + next;

    }

    if ( sumold <= cdf && cdf <= sum )

    {

      return i;

    }

  }

  cout << "\n";

  cout << "POISSON_SAMPLE - Warning!\n";

  cout << "  Exceeded KMAX = " << KMAX << "\n";

  return KMAX;

}

double poisson_variance ( double a )

{

  if ( a <= 0.0 )

  {

    cerr << "\n";

    cerr << "POISSON_VARIANCE - Fatal error!\n";

    cerr << "  A <= 0.\n";

    return (0.0);

  }

  return a;

}

double power_cdf ( double x, double a, double b )

{

  double cdf;

  if ( x <= 0.0 )

  {

    cdf = 0.0;

  }

  else if ( x <= b )

  {

    cdf = pow ( ( x / b ), a );

  }

  else

  {

    cdf = 1.0;

  }

  return cdf;

}

double power_cdf_inv ( double cdf, double a, double b )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << " \n";

    cerr << "POWER_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = 0.0;

  }

  else if ( cdf < 1.0 )

  {

    x = b * exp ( log ( cdf ) / a );

  }

  else

  {

    x = b;

  }

  return x;

}

bool power_check ( double a, double b )

{

  if ( a <= 0.0 )

  {

    cerr << " \n";

    cerr << "POWER_CHECK - Fatal error!\n";

    cerr << "  A <= 0.\n";

    return false;

  }

  if ( b <= 0.0 )

  {

    cerr << " \n";

    cerr << "POWER_CHECK - Fatal error!\n";

    cerr << "  B <= 0.\n";

    return false;

  }

  return true;

}

double power_mean ( double a, double b )

{

  double mean;

  mean = a * b / ( a + 1.0 );

  return mean;

}

double power_pdf ( double x, double a, double b )

{

  double pdf;

  if ( x < 0.0 || b < x )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = ( a / b ) * pow ( x / b, a - 1.0 );

  }

  return pdf;

}

double power_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = power_cdf_inv ( cdf, a, b );

  return x;

}

double power_variance ( double a, double b )

{

  double variance;

  variance = b * b * a / ( ( a + 1.0 ) * ( a + 1.0 ) * ( a + 2.0 ) );

  return variance;

}

void psi_values ( int &n_data, double &x, double &fx )

{

# define N_MAX 20

  static double fx_vec[N_MAX] = {

    -10.42375494041108E+00, 

     -5.289039896592188E+00, 

     -3.502524222200133E+00, 

     -2.561384544585116E+00, 

     -1.963510026021423E+00, 

     -1.540619213893190E+00, 

     -1.220023553697935E+00, 

     -0.9650085667061385E+00, 

     -0.7549269499470514E+00, 

     -0.5772156649015329E+00,

     -0.4237549404110768E+00,

     -0.2890398965921883E+00,

     -0.1691908888667997E+00,

     -0.6138454458511615E-01,

      0.3648997397857652E-01,

      0.1260474527734763E+00,

      0.2085478748734940E+00,

      0.2849914332938615E+00,

      0.3561841611640597E+00,

      0.4227843350984671E+00 };

  static double x_vec[N_MAX] = {

     0.1E+00,

     0.2E+00,

     0.3E+00,

     0.4E+00,

     0.5E+00,

     0.6E+00,

     0.7E+00,

     0.8E+00,

     0.9E+00,

     1.0E+00,

     1.1E+00,

     1.2E+00,

     1.3E+00,

     1.4E+00,

     1.5E+00,

     1.6E+00,

     1.7E+00,

     1.8E+00,

     1.9E+00,

     2.0E+00 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

double quasigeometric_cdf ( int x, double a, double b )

{

  double cdf;

  if ( x < 0 )

  {

    cdf = 0.0;

  }

  else if ( x == 0 )

  {

    cdf = a;

  }

  else if ( b == 0.0 )

  {

    cdf = 1.0;

  }

  else

  {

    cdf = a + ( 1.0 - a ) * ( 1.0 - pow ( b, x ) );

  }

  return cdf;

}

int quasigeometric_cdf_inv ( double cdf, double a, double b )

{

  int x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cerr << "\n";

    cerr << "QUASIGEOMETRIC_CDF_INV - Fatal error!\n";

    cerr << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf < a )

  {

    x = 0;

  }

  else if ( b == 0.0 )

  {

    x = 1;

  }

  else

  {

    x = 1 + ( int ) ( ( log ( 1.0 - cdf ) - log ( 1.0 - a ) ) / log ( b ) );

  }

  return x;

}

bool quasigeometric_check ( double a, double b )

{

  bool check;

  if ( a < 0.0 || 1.0 < a )

  {

    cerr << "\n";

    cerr << "QUASIGEOMETRIC_CHECK - Fatal error!\n";

    cerr << "  A < 0 or 1 < A.\n";

    check = false;

    exit ( 1 );

  }

  if ( b < 0.0 || 1.0 <= b )

  {

    cerr << "\n";

    cerr << "QUASIGEOMETRIC_CHECK - Fatal error!\n";

    cerr << "  B < 0 or 1 <= B.\n";

    check = false;

    exit ( 1 );

  }

  check = true;

  return check;

}

double quasigeometric_mean ( double a, double b )

{

  double mean;

  mean = ( 1.0 - a  ) / ( 1.0 - b );

  return mean;

}

double quasigeometric_pdf ( int x, double a, double b )

{

  double pdf;

  if ( x < 0 )

  {

    pdf = 0.0;

  }

  else if ( x == 0 )

  {

    pdf = a;

  }

  else if ( b == 0.0 )

  {

    if ( x == 1 )

    {

      pdf = 1.0;

    }

    else

    {

      pdf = 0.0;

    }

  }

  else

  {

    pdf = ( 1.0 - a ) * ( 1.0 - b ) * pow ( b, x - 1 );

  }

  return pdf;

}

int quasigeometric_sample ( double a, double b, int &seed )

{

  double cdf;

  int x;

  cdf = r8_uniform_01 ( seed );

  x = quasigeometric_cdf_inv ( cdf, a, b );

  return x;

}

double quasigeometric_variance ( double a, double b )

{

  double variance;

  variance = ( 1.0 - a ) * ( a + b ) / ( 1.0 - b ) / ( 1.0 - b );

  return variance;

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

float r4_uniform_01 ( int &seed )

{

  int k;

  float r;

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )

  {

    seed = seed + 2147483647;

  }

  r = ( float ) ( seed ) * 4.656612875E-10;

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

int r8_ceiling ( double r )

{

  int value;

  value = ( int ) ( r );

  if ( ( double ) value < r )

  {

    value = value + 1;

  }

  return value;

}

double r8_csc ( double theta )

{

  double value;

  value = sin ( theta );

  if ( value == 0.0 )

  {

    cout << " \n";

    cout << "R8_CSC - Fatal error!\n";

    cout << "  Cosecant undefined for THETA = " << theta << "\n";

    exit ( 1 );

  }

  value = 1.0 / value;

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

double r8_gamma ( double x )

{

  double c[7] = {

   -1.910444077728E-03,

    8.4171387781295E-04,

   -5.952379913043012E-04,

    7.93650793500350248E-04,

   -2.777777777777681622553E-03,

    8.333333333333333331554247E-02,

    5.7083835261E-03 };

  double eps = 2.22E-16;

  double fact;

  double half = 0.5;

  int i;

  int n;

  double one = 1.0;

  double p[8] = {

  -1.71618513886549492533811E+00,

   2.47656508055759199108314E+01,

  -3.79804256470945635097577E+02,

   6.29331155312818442661052E+02,

   8.66966202790413211295064E+02,

  -3.14512729688483675254357E+04,

  -3.61444134186911729807069E+04,

   6.64561438202405440627855E+04 };

  bool parity;

  double pi = 3.1415926535897932384626434;

  double q[8] = {

  -3.08402300119738975254353E+01,

   3.15350626979604161529144E+02,

  -1.01515636749021914166146E+03,

  -3.10777167157231109440444E+03,

   2.25381184209801510330112E+04,

   4.75584627752788110767815E+03,

  -1.34659959864969306392456E+05,

  -1.15132259675553483497211E+05 };

  double res;

  double sqrtpi = 0.9189385332046727417803297;

  double sum;

  double twelve = 12.0;

  double two = 2.0;

  double value;

  double xbig = 171.624;

  double xden;

  double xinf = 1.79E+308;

  double xminin = 2.23E-308;

  double xnum;

  double y;

  double y1;

  double ysq;

  double z;

  double zero = 0.0;;

  parity = false;

  fact = one;

  n = 0;

  y = x;

  if ( y <= zero )

  {

    y = - x;

    y1 = ( double ) ( int ) ( y );

    res = y - y1;

    if ( res != zero )

    {

      if ( y1 != ( double ) ( int ) ( y1 * half ) * two )

      {

        parity = true;

      }

      fact = - pi / sin ( pi * res );

      y = y + one;

    }

    else

    {

      res = xinf;

      value = res;

      return value;

    }

  }

  if ( y < eps )

  {

    if ( xminin <= y )

    {

      res = one / y;

    }

    else

    {

      res = xinf;

      value = res;

      return value;

    }

  }

  else if ( y < twelve )

  {

    y1 = y;

    if ( y < one )

    {

      z = y;

      y = y + one;

    }

    else

    {

      n = ( int ) ( y ) - 1;

      y = y - ( double ) ( n );

      z = y - one;

    }

    xnum = zero;

    xden = one;

    for ( i = 0; i < 8; i++ )

    {

      xnum = ( xnum + p[i] ) * z;

      xden = xden * z + q[i];

    }

    res = xnum / xden + one;

    if ( y1 < y )

    {

      res = res / y1;

    }

    else if ( y < y1 )

    {

      for ( i = 1; i <= n; i++ )

      {

        res = res * y;

        y = y + one;

      }

    }

  }

  else

  {

    if ( y <= xbig )

    {

      ysq = y * y;

      sum = c[6];

      for ( i = 0; i < 6; i++ )

      {

        sum = sum / ysq + c[i];

      }

      sum = sum / y - y + sqrtpi;

      sum = sum + ( y - half ) * log ( y );

      res = exp ( sum );

    }

    else

    {

      res = xinf;

      value = res;

      return value;

    }

  }

  if ( parity )

  {

    res = - res;

  }

  if ( fact != one )

  {

    res = fact / res;

  }

  value = res;

  return value;

}

double r8_huge ( )

{

  return HUGE_VAL;

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

double r8_modp ( double x, double y )

{

  double value;

  if ( y == 0.0 )

  {

    cout << "\n";

    cout << "R8_MODP - Fatal error!\n";

    cout << "  R8_MODP ( X, Y ) called with Y = " << y << "\n";

    exit ( 1 );

  }

  value = x - ( ( double ) ( ( int ) ( x / y ) ) ) * y;

  if ( value < 0.0 )

  {

    value = value + r8_abs ( y );

  }

  return value;

}

int r8_nint ( double x )

{

  int s;

  if ( x < 0.0 )

  {

    s = -1;

  }

  else

  {

    s = 1;

  }

  return ( s * ( int ) ( r8_abs ( x ) + 0.5 ) );

}

double r8_pi ( )

{

  const double pi = 3.14159265358979323;

  return pi;

}

double r8_random ( double rlo, double rhi, int &seed )

{

  double t;

  t = r8_uniform_01 ( seed );

  return ( 1.0 - t ) * rlo + t * rhi;

}

double r8_sign ( double x )

{

  if ( x < 0.0 )

  {

    return ( -1.0 );

  }

  else

  {

    return ( 1.0 );

  }

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

void r8mat_print ( int m, int n, double a[], char *title )

{

  r8mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;

}

void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,

  int jhi, char *title )

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

double r8poly_value ( int n, double a[], double x )

{

  int i;

  double value;

  value = 0.0;

  for ( i = n-1; 0 <= i; i-- )

  {

    value = value * x + a[i];

  }

  return value;

}

double *r8row_max ( int m, int n, double a[] )

{

  int i;

  int j;

  double *amax;

  amax = new double[m];

  for ( i = 0; i < m; i++ )

  {

    amax[i] = a[i+0*m];

    for ( j = 1; j < n; j++ )

    {

      if ( amax[i] < a[i+j*m] )

      {

        amax[i] = a[i+j*m];

      }

    }

  }

  return amax;

}

double *r8row_mean ( int m, int n, double a[] )

{

  int i;

  int j;

  double *mean;

  mean = new double[m];

  for ( i = 0; i < m; i++ )

  {

    mean[i] = 0.0;

    for ( j = 0; j < n; j++ )

    {

      mean[i] = mean[i] + a[i+j*m];

    }

    mean[i] = mean[i] / ( double ) ( n );

  }

  return mean;

}

double *r8row_min ( int m, int n, double a[] )

{

  int i;

  int j;

  double *amin;

  amin = new double[m];

  for ( i = 0; i < m; i++ )

  {

    amin[i] = a[i+0*m];

    for ( j = 1; j < n; j++ )

    {

      if ( a[i+j*m] < amin[i] )

      {

        amin[i] = a[i+j*m];

      }

    }

  }

  return amin;

}

double *r8row_variance ( int m, int n, double a[] )

{

  int i;

  int j;

  double mean;

  double *variance;

  variance = new double[m];

  for ( i = 0; i < m; i++ )

  {

    mean = 0.0;

    for ( j = 0; j < n; j++ )

    {

      mean = mean + a[i+j*m];

    }

    mean = mean / ( double ) ( n );

    variance[i] = 0.0;

    for ( j = 0; j < n; j++ )

    {

      variance[i] = variance[i] + pow ( ( a[i+j*m] - mean ), 2 );

    }

    if ( 1 < n )

    {

      variance[i] = variance[i] / ( double ) ( n - 1 );

    }

    else

    {

      variance[i] = 0.0;

    }

  }

  return variance;

}

double r8vec_circular_variance ( int n, double x[] )

{

  int i;

  double mean;

  double sum_c;

  double sum_s;

  double value;

  mean = r8vec_mean ( n, x );

  sum_c = 0.0;

  for ( i = 0; i < n; i++ )

  {

    sum_c = sum_c + cos ( x[i] - mean );

  }

  sum_s = 0.0;

  for ( i = 0; i < n; i++ )

  {

    sum_s = sum_s + sin ( x[i] - mean );

  }

  value = sqrt ( sum_c * sum_c + sum_s * sum_s ) / ( double ) n;

  value = 1.0 - value;

  return value;

}

double r8vec_diff_norm ( int n, double a[], double b[] )

{

  int i;

  double value;

  value = 0.0;

  for ( i = 0; i < n; i++ )

  {

    value = value + ( a[i] - b[i] ) * ( a[i] - b[i] );

  }

  value = sqrt ( value );

  return value;

}

double r8vec_dot ( int n, double a1[], double a2[] )

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

double r8vec_max ( int n, double *dvec )

{

  int i;

  double rmax;

  double *r8vec_pointer;

  if ( n <= 0 )

  {

    return 0.0;

  }

  for ( i = 0; i < n; i++ )

  {

    if ( i == 0 )

    {

      rmax = *dvec;

      r8vec_pointer = dvec;

    }

    else

    {

      r8vec_pointer++;

      if ( rmax < *r8vec_pointer )

      {

        rmax = *r8vec_pointer;

      }

    }

  }

  return rmax;

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

double r8vec_min ( int n, double *dvec )

{

  int i;

  double rmin;

  double *r8vec_pointer;

  if ( n <= 0 )

  {

    return 0.0;

  }

  for ( i = 0; i < n; i++ )

  {

    if ( i == 0 )

    {

      rmin = *dvec;

      r8vec_pointer = dvec;

    }

    else

    {

      r8vec_pointer++;

      if ( *r8vec_pointer < rmin )

      {

        rmin = *r8vec_pointer;

      }

    }

  }

  return rmin;

}

void r8vec_print ( int n, double a[], char *title )

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

double *r8vec_random ( int n, double alo, double ahi, int &seed )

{

  double *a;

  int i;

  a = new double[n];

  for ( i = 0; i < n; i++ )

  {

    a[i] = r8_random ( alo, ahi, seed );

  }

  return a;

}

double r8vec_sum ( int n, double a[] )

{

  int i;

  float sum;

  sum = 0.0;

  for ( i = 0; i < n; i++ )

  {

    sum = sum + a[i];

  }

  return sum;

}

double *r8vec_uniform_01 ( int n, int &seed )

{

  int i;

  int k;

  double *r;

  r = new double[n];

  for ( i = 0; i < n; i++ )

  {

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )

    {

      seed = seed + 2147483647;

    }

    r[i] = ( double ) ( seed ) * 4.656612875E-10;

  }

  return r;

}

void r8vec_unit_sum ( int n, double a[] )

{

  double a_sum;

  int i;

  a_sum = 0.0;

  for ( i = 0; i < n; i++ )

  {

    a_sum = a_sum + a[i];

  }

  if ( a_sum == 0.0 )

  {

    cout << "\n";

    cout << "R8VEC_UNIT_SUM - Fatal error!\n";

    cout << "  The vector entries sum to 0.\n";

    exit ( 1 );

  }

  for ( i = 0; i < n; i++ )

  {

    a[i] = a[i] / a_sum;

  }

  return;

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

double rayleigh_cdf ( double x, double a )

{

  double cdf;

  if ( x < 0.0 )

  {

    cdf = 0.0;

  }

  else

  {

    cdf = 1.0 - exp ( - x * x / ( 2.0 * a * a ) );

  }

  return cdf;

}

double rayleigh_cdf_inv ( double cdf, double a )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "RAYLEIGH_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = sqrt ( - 2.0 * a * a * log ( 1.0 - cdf ) );

  return x;

}

void rayleigh_cdf_values ( int &n_data, double &sigma, double &x, double &fx )

{

# define N_MAX 9

  static double fx_vec[N_MAX] = {

     0.8646647167633873E+00,

     0.9996645373720975E+00,

     0.9999999847700203E+00,

     0.999999999999987E+00,

     0.8646647167633873E+00,

     0.3934693402873666E+00,

     0.1992625970831920E+00,

     0.1175030974154046E+00,

     0.7688365361336422E-01 };

  static double sigma_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01 };

  static double x_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    sigma = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    sigma = sigma_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool rayleigh_check ( double a )

{

  if ( a <= 0.0 )

  {

    cout << " \n";

    cout << "RAYLEIGH_CHECK - Fatal error!\n";

    cout << "  A <= 0.\n";

    return false;

  }

  return true;

}

double rayleigh_mean ( double a )

{

  double mean;

  const double pi = 3.14159265358979323;

  mean = a * sqrt ( 0.5 * pi );

  return mean;

}

double rayleigh_pdf ( double x, double a )

{

  double pdf;

  if ( x < 0.0 )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = ( x / ( a * a ) ) * exp ( - x * x / ( 2.0 * a * a ) );

  }

  return pdf;

}

double rayleigh_sample ( double a, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = rayleigh_cdf_inv ( cdf, a );

  return x;

}

double rayleigh_variance ( double a )

{

  const double pi = 3.14159265358979323;

  double variance;

  variance = 2.0 * a * a * ( 1.0 - 0.25 * pi );

  return variance;

}

double reciprocal_cdf ( double x, double a, double b )

{

  double cdf;

  if ( x <= 0.0 )

  {

    cdf = 0.0;

  }

  else if ( 0.0 < x )

  {

    cdf = log ( a / x ) / log ( a / b );

  }

  return cdf;

}

double reciprocal_cdf_inv ( double cdf, double a, double b )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "RECIPROCAL_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = 0.0;

  }

  else if ( 0.0 < cdf )

  {

    x = pow ( b, cdf ) / pow ( a, ( cdf - 1.0 ) );

  }

  return x;

}

bool reciprocal_check ( double a, double b )

{

  if ( a <= 0.0 )

  {

    cout << " \n";

    cout << "RECIPROCAL_CHECK - Fatal error!\n";

    cout << "  A <= 0.0\n";

    return false;

  }

  if ( b < a )

  {

    cout << " \n";

    cout << "RECIPROCAL_CHECK - Fatal error!\n";

    cout << "  B < A\n";

    return false;

  }

  return true;

}

double reciprocal_mean ( double a, double b )

{

  double mean;

  mean = ( a - b ) / log ( a / b );

  return mean;

}

double reciprocal_pdf ( double x, double a, double b )

{

  double pdf;

  if ( x <= 0.0 )

  {

    pdf = 0.0;

  }

  else if ( 0.0 < x )

  {

    pdf = 1.0 / ( x * log ( b / a ) );

  }

  return pdf;

}

double reciprocal_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = pow ( b, cdf ) / pow ( a, ( cdf - 1.0 ) );

  return x;

}

double reciprocal_variance ( double a, double b )

{

  double d;

  double variance;

  d = log ( a / b );

  variance = ( a - b )* ( a * ( d - 2.0 ) + b * ( d + 2.0 ) )

    / ( 2.0 * d * d );

  return variance;

}

int ribesl ( double x, double alpha, int nb, int ize, double b[] )

{

  double constant = 1.585;

  double em;

  double empal;

  double emp2al;

  double en;

  double enmten = 8.9E-308;

  double ensig = 1.0E+16;

  double enten = 1.0E+308;

  double exparg = 709.0;

  bool flag;

  double half = 0.5;

  double halfx;

  int i;

  int k;

  int l;

  int magx;

  int n;

  int nbmx;

  int ncalc;

  int nend;

  int nsig = 16;

  int nstart;

  double one = 1.0;

  double p;

  double plast;

  double pold;

  double psave;

  double psavel;

  double rtnsig = 1.0E-04;

  double tempa;

  double tempb;

  double tempc;

  double test;

  double total;

  double tover;

  double two = 2.0;

  double xlarge = 1.0E+04;

  double zero = 0.0;

  if ( nb <= 0 )

  {

    ncalc = i4_min ( nb, 0 ) - 1;

    return ncalc;

  }

  if ( x < 0.0 )

  {

    ncalc = i4_min ( nb, 0 ) - 1;

    return ncalc;

  }

  if ( alpha < 0.0 )

  {

    ncalc = i4_min ( nb, 0 ) - 1;

    return ncalc;

  }

  if ( 1.0 <= alpha )

  {

    ncalc = i4_min ( nb, 0 ) - 1;

    return ncalc;

  }

  if ( ize == 1 && exparg < x )

  {

    ncalc = i4_min ( nb, 0 ) - 1;

    return ncalc;

  }

  if ( ize == 2 && xlarge < x )

  {

    ncalc = i4_min ( nb, 0 ) - 1;

    return ncalc;

  }

  ncalc = nb;

  magx = ( int ) ( x );

  if ( rtnsig <= x )

  {

    nbmx = nb - magx;

    n = magx + 1;

    en = ( double ) ( n + n ) + ( alpha + alpha );

    plast = one;

    p = en / x;

    test = ensig + ensig;

    if ( 5 * nsig < 2 * magx )

    {

      test = sqrt ( test * p );

    }

    else

    {

      test = test / pow ( constant, magx );

    }

    flag = false;

    if ( 3 <= nbmx )

    {

      tover = enten / ensig;

      nstart = magx + 2;

      nend = nb - 1;

      for ( k = nstart; k <= nend; k++ )

      {

        n = k;

        en = en + two;

        pold = plast;

        plast = p;

        p = en * plast / x + pold;

        if ( tover < p )

        {

          tover = enten;

          p = p / tover;

          plast = plast / tover;

          psave = p;

          psavel = plast;

          nstart = n + 1;

          for ( ; ; )

          {

            n = n + 1;

            en = en + two;

            pold = plast;

            plast = p;

            p = en * plast / x + pold;

            if ( 1.0 < p )

            {

              break;

            }

          }

          tempb = en / x;

          test = pold * plast / ensig;

          test = test * ( half - half / ( tempb * tempb ) );

          p = plast * tover;

          n = n - 1;

          en = en - two;

          nend = i4_min ( nb, n );

          ncalc = nend + 1;

          for ( l = nstart; l <= nend; l++ )

          {

            pold = psavel;

            psavel = psave;

            psave = en * psavel / x + pold;

            if ( test < psave * psavel )

            {

              ncalc = l;

              break;

            }

          }

          ncalc = ncalc - 1;

          flag = true;

          break;

        }

      }

      if ( !flag )

      {

        n = nend;

        en = ( double ) ( n + n ) + ( alpha + alpha );

        test = r8_max ( test, sqrt ( plast * ensig ) * sqrt ( p + p ) );

      }

    }

    if ( !flag )

    {

      for ( ; ; )

      {

        n = n + 1;

        en = en + two;

        pold = plast;

        plast = p;

        p = en * plast / x + pold;

        if ( test <= p )

        {

          break;

        }

      }

    }

    n = n + 1;

    en = en + two;

    tempb = zero;

    tempa = one / p;

    em = ( double ) ( n ) - one;

    empal = em + alpha;

    emp2al = ( em - one ) + ( alpha + alpha );

    total = tempa * empal * emp2al / em;

    nend = n - nb;

    if ( nend < 0 )

    {

      b[n-1] = tempa;

      nend = -nend;

      for ( l = 1; l <= nend; l++ )

      {

        b[n+l-1] = zero;

      }

      nend = n - 2;

      if ( 0 < nend )

      {

        for ( l = 1; l <= nend; l++ )

        {

          n = n - 1;

          en = en - two;

          b[n-1] = ( en * b[n] ) / x + b[n+1];

          em = em - one;

          emp2al = emp2al - one;

          if ( n == 2 )

          {

            emp2al = one;

          }

          empal = empal - one;

          total = ( total + b[n-1] * empal ) * emp2al / em;

        }

      }

      b[0] = two * empal * b[1] / x + b[2];

      total = ( total + total ) + b[0];

    }

    else

    {

      if ( 0 < nend )

      {

        for ( l = 1; l <= nend; l++ )

        {

          n = n - 1;

          en = en - two;

          tempc = tempb;

          tempb = tempa;

          tempa = ( en * tempb ) / x + tempc;

          em = em - one;

          emp2al = emp2al - one;

          if ( n == 1 )

          {

            break;

          }

          if ( n == 2 )

          {

            emp2al = one;

          }

          empal = empal - one;

          total = ( total + tempa * empal ) * emp2al / em;

        }

      }

      b[n-1] = tempa;

      if ( nb <= 1 )

      {

        total = ( total + total ) + tempa;

      }

      else

      {

        n = n - 1;

        en = en - two;

        b[n-1] = ( en * tempa ) / x + tempb;

        if ( 1 < n  )

        {

          em = em - one;

          emp2al = emp2al - one;

          if ( n == 2 )

          {

            emp2al = one;

          }

          empal = empal - one;

          total = ( total + b[n-1] * empal ) * emp2al / em;

          nend = n - 2;

          if ( 0 < nend )

          {

            for ( l = 1; l <= nend; l++ )

            {

              n = n - 1;

              en = en - two;

              b[n-1] = ( en * b[n] ) / x + b[n+1];

              em = em - one;

              emp2al = emp2al - one;

              if ( n == 2 )

              {

                emp2al = one;

              }

              empal = empal - one;

              total = ( total + b[n-1] * empal ) * emp2al / em;

            }

          }

          b[0] = two * empal * b[1] / x + b[2];

        }

        total = ( total + total ) + b[0];

      }

    }

    if ( alpha != zero )

    {

       total = total * r8_gamma ( one + alpha ) * pow ( x * half, -alpha );

    }

    if ( ize == 1 )

    {

      total = total * exp ( -x );

    }

    tempa = enmten;

    if ( 1.0 < total )

    {

      tempa = tempa * total;

    }

    for ( n = 1; n <= nb; n++ )

    {

      if ( b[n-1] < tempa )

      {

        b[n-1] = zero;

      }

      b[n-1] = b[n-1] / total;

    }

    return ncalc;

  }

  else

  {

    tempa = one;

    empal = one + alpha;

    halfx = zero;

    if ( enmten < x )

    {

      halfx = half * x;

    }

    if ( alpha != zero )

    {

      tempa = pow ( halfx, alpha ) / r8_gamma ( empal );

    }

    if ( ize == 2 )

    {

      tempa = tempa * exp ( - x );

    }

    tempb = zero;

    if ( one < x + one )

    {

      tempb = halfx * halfx;

    }

    b[0] = tempa + tempa * tempb / empal;

    if ( x != zero && b[0] == zero )

    {

      ncalc = 0;

    }

    if ( 1 < nb )

    {

      if ( x == zero )

      {

        for ( i = 1; i < nb; i++ )

        {

          b[i] = zero;

        }

      }

      else

      {

        tempc = halfx;

        tover = ( enmten + enmten ) / x;

        if ( tempb != zero )

        {

          tover = enmten / tempb;

        }

        for ( n = 2; n <= nb; n++ )

        {

          tempa = tempa / empal;

          empal = empal + one;

          tempa = tempa * tempc;

          if ( tempa <= tover * empal )

          {

            tempa = zero;

          }

          b[n-1] = tempa + tempa * tempb / empal;

          if ( b[n-1] == zero && n < ncalc )

          {

            ncalc = n - 1;

          }

        }

      }

    }

  }

  return ncalc;

}

double runs_mean ( int m, int n )

{

  double mean;

  mean = ( double ) ( m + 2 * m * n + n )

       / ( double ) ( m             + n );

  return mean;

}

double runs_pdf ( int m, int n, int r )

{

  double pdf;

  if ( m < 0 )

  {

    cout << "\n";

    cout << "RUN_PDF - Fatal error!\n";

    cout << "  M must be at least 0.\n";

    cout << "  The input value of M = " << m << "\n";

    exit ( 1 );

  }

  if ( n < 0 )

  {

    cout << "\n";

    cout << "RUN_PDF - Fatal error!\n";

    cout << "  N must be at least 0.\n";

    cout << "  The input value of N = " << n << "\n";

    exit ( 1 );

  }

  if ( n + m <= 0 )

  {

    cout << "\n";

    cout << "RUN_PDF - Fatal error!\n";

    cout << "  M+N must be at least 1.\n";

    cout << "  The input value of M+N = " << m + n << "\n";

    exit ( 1 );

  }

  if ( m == 0 || n == 0 )

  {

    if ( r == 1 )

    {

      pdf = 1.0;

    }

    else

    {

      pdf = 0.0;

    }

    return pdf;

  }

  if ( r < 2 || m + n < r )

  {

    pdf = 0.0;

    return pdf;

  }

  if ( ( r % 2 ) == 0 )

  {

    pdf = ( double ) ( 2 * combinatorial ( m - 1, ( r / 2 ) - 1 )

                         * combinatorial ( n - 1, ( r / 2 ) - 1 ) )

        / ( double ) (     combinatorial ( m + n, n ) );

  }

  else

  {

    pdf = ( double ) (   combinatorial ( m - 1, ( r - 1 ) / 2 )

                       * combinatorial ( n - 1, ( r - 3 ) / 2 )

                       + combinatorial ( m - 1, ( r - 3 ) / 2 )

                       * combinatorial ( n - 1, ( r - 1 ) / 2 ) )

        / ( double ) (   combinatorial ( m + n, n ) );

  }

  return pdf;

}

int runs_sample ( int m, int n, int &seed )

{

  int *a;

  int r;

  a = runs_simulate ( m, n, seed );

  r = i4vec_run_count ( m+n, a );

  delete [] a;

  return r;

}

int *runs_simulate ( int m, int n, int &seed )

{

  int *a;

  int i;

  int j;

  int k;

  a = new int[m+n];

  for ( i = 0; i < m; i++ )

  {

    a[i] = 0;

  }

  for ( i = m; i < m + n; i++ )

  {

    a[i] = 1;

  }

  for ( i = 1; i <= m + n - 1; i++ )

  {

    j = i4_uniform_ab ( i, m + n, seed );

    k      = a[i-1];

    a[i-1] = a[j-1];

    a[j-1] = k;

  }

  return a;

}

double runs_variance ( int m, int n )

{

  double variance;

  variance = ( double ) ( 2 * m * n * ( 2 * m * n - m - n ) )

           / ( double ) ( ( m + n ) * ( m + n ) * ( m + n - 1 ) );

  return variance;

}

int s_len_trim ( char *s )

{

  int n;

  char* t;

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

double sech ( double x )

{

  double value;

  value = 1.0 / cosh ( x );

  return value;

}

double sech_cdf ( double x, double a, double b )

{

  double cdf;

  const double pi = 3.14159265358979323;

  double y;

  y = ( x - a ) / b;

  cdf = 2.0 * atan ( exp ( y ) ) / pi;

  return cdf;

}

double sech_cdf_inv ( double cdf, double a, double b )

{

  const double pi = 3.14159265358979323;

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "SECH_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = - r8_huge (  );

  }

  else if ( cdf < 1.0 )

  {

    x = a + b * log ( tan ( 0.5 * pi * cdf ) );

  }

  else if ( 1.0 == cdf )

  {

    x = r8_huge ( );

  }

  return x;

}

bool sech_check ( double a, double b )

{

  if ( b <= 0.0 )

  {

    cout << " \n";

    cout << "SECH_CHECK - Fatal error!\n";

    cout << "  B <= 0.0\n";

    return false;

  }

  return true;

}

double sech_mean ( double a, double b )

{

  double mean;

  mean = a;

  return mean;

}

double sech_pdf ( double x, double a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  double y;

  y = ( x - a ) / b;

  pdf = sech ( y ) / ( pi * b );

  return pdf;

}

double sech_sample ( double a, double b, int &seed )

{

  double cdf;

  const double pi = 3.14159265358979323;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = a + b * log ( tan ( 0.5 *pi * cdf ) );

  return x;

}

double sech_variance ( double a, double b )

{

  const double pi = 3.14159265358979323;

  double variance;

  variance = 0.25 * pi * pi * b * b;

  return variance;

}

double semicircular_cdf ( double x, double a, double b )

{

  double cdf;

  const double pi = 3.14159265358979323;

  double y;

  if ( x <= a - b )

  {

    cdf = 0.0;

  }

  else if ( x <= a + b )

  {

    y = ( x - a ) / b;

    cdf = 0.5 + ( y * sqrt ( 1.0 - y * y ) + asin ( y ) ) / pi;

  }

  else if ( a + b < x )

  {

    cdf = 1.0;

  }

  return cdf;

}

double semicircular_cdf_inv ( double cdf, double a, double b )

{

  double cdf1;

  double cdf2;

  double cdf3;

  int it;

  int it_max = 100;

  double tol = 0.0001;

  double x;

  double x1;

  double x2;

  double x3;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "SEMICIRCULAR_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = a - b;

    return x;

  }

  else if ( 1.0 == cdf )

  {

    x = a + b;

    return x;

  }

  x1 = a - b;

  cdf1 = 0.0;

  x2 = a + b;

  cdf2 = 1.0;

  it = 0;

  for ( ; ; )

  {

    it = it + 1;

    x3 = 0.5 * ( x1 + x2 );

    cdf3 = semicircular_cdf ( x3, a, b );

    if ( r8_abs ( cdf3 - cdf ) < tol )

    {

      x = x3;

      break;

    }

    if ( it_max < it )

    {

      cout << " \n";

      cout << "SEMICIRCULAR_CDF_INV - Fatal error!\n";

      cout << "  Iteration limit exceeded.\n";

      exit ( 1 );

    }

    if ( ( cdf3 <= cdf && cdf1 <= cdf ) || ( cdf <= cdf3 && cdf <= cdf1 ) )

    {

      x1 = x3;

      cdf1 = cdf3;

    }

    else

    {

      x2 = x3;

      cdf2 = cdf3;

    }

  }

  return x;

}

bool semicircular_check ( double a, double b )

{

  if ( b <= 0.0 )

  {

    cout << " \n";

    cout << "SEMICIRCULAR_CHECK - Fatal error!\n";

    cout << "  B <= 0.0\n";

    return false;

  }

  return true;

}

double semicircular_mean ( double a, double b )

{

  double mean;

  mean = a;

  return mean;

}

double semicircular_pdf ( double x, double a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  double y;

  if ( x < a - b )

  {

    pdf = 0.0;

  }

  else if ( x <= a + b )

  {

    y = ( x - a ) / b;

    pdf = 2.0 / ( b * pi ) * sqrt ( 1.0 - y * y );

  }

  else if ( a + b < x )

  {

    pdf = 0.0;

  }

  return pdf;

}

double semicircular_sample ( double a, double b, int &seed )

{

  double angle;

  const double pi = 3.14159265358979323;

  double radius;

  double x;

  radius = r8_uniform_01 ( seed );

  radius = b * sqrt ( radius );

  angle = pi * r8_uniform_01 ( seed );

  x = a + radius * cos ( angle );

  return x;

}

double semicircular_variance ( double a, double b )

{

  double variance;

  variance = b * b / 4.0;

  return variance;

}

double sin_power_int ( double a, double b, int n )

{

  double ca;

  double cb;

  int m;

  int mlo;

  double sa;

  double sb;

  double value;

  if ( n < 0 )

  {

    cout << "\n";

    cout << "SIN_POWER_INT - Fatal error!\n";

    cout << "  Power N < 0.\n";

    value = 0.0;

    exit ( 1 );

  }

  sa = sin ( a );

  sb = sin ( b );

  ca = cos ( a );

  cb = cos ( b );

  if ( ( n % 2 ) == 0 )

  {

    value = b - a;

    mlo = 2;

  }

  else

  {

    value = ca - cb;

    mlo = 3;

  }

  for ( m = mlo; m <= n; m = m + 2 )

  {

    value = ( ( double ) ( m - 1 ) * value

      + pow ( sa, (m-1) ) * ca - pow ( sb, (m-1) ) * cb )

      / ( double ) ( m );

  }

  return value;

}

double sphere_unit_area_nd ( int dim_num )

{

  double area;

  int i;

  int m;

  double pi = 3.141592653589793;

  if ( ( dim_num % 2 ) == 0 )

  {

    m = dim_num / 2;

    area = 2.0 * pow ( pi, m );

    for ( i = 1; i <= m-1; i++ )

    {

      area = area / ( ( double ) i );

    }

  }

  else

  {

    m = ( dim_num - 1 ) / 2;

    area = pow ( 2.0, dim_num ) * pow ( pi, m );

    for ( i = m+1; i <= 2*m; i++ )

    {

      area = area / ( ( double ) i );

    }

  }

  return area;

}

int stirling2_value ( int n, int m )

{

  int i;

  int j;

  int *s2;

  int value;

  s2 = new int[n*m];

  if ( n <= 0 )

  {

    value = 0;

    return value;

  }

  if ( m <= 0 )

  {

    value = 0;

    return value;

  }

  s2[0+0*n] = 1;

  for ( j = 2; j <= m; j++ )

  {

    s2[0+(j-1)*n] = 0;

  }

  for ( i = 2; i <= n; i++ )

  {

    s2[i-1+0*n] = 1;

    for ( j = 2; j <= m; j++ )

    {

      s2[i-1+(j-1)*n] = j * s2[i-2+(j-1)*n] + s2[i-2+(j-2)*n];

    }

  }

  value = s2[n-1+(m-1)*n];

  delete [] s2;

  return value;

}

double student_cdf ( double x, double a, double b, double c )

{

  double a2;

  double b2;

  double c2;

  double cdf;

  double y;

  y = ( x - a ) / b;

  a2 = 0.5 * c;

  b2 = 0.5;

  c2 = c / ( c + y * y );

  if ( y <= 0.0 )

  {

    cdf = 0.5 * beta_inc ( a2, b2, c2 );

  }

  else

  {

    cdf = 1.0 - 0.5 * beta_inc ( a2, b2, c2 );

  }

  return cdf;

}

void student_cdf_values ( int &n_data, double &c, double &x, double &fx )

{

# define N_MAX 13

  static double c_vec[N_MAX] = {

    1.0, 2.0, 3.0, 4.0,

    5.0, 2.0, 5.0, 2.0,

    5.0, 2.0, 3.0, 4.0,

    5.0 };

  static double fx_vec[N_MAX] = {

     0.6000231200328521,

     0.6001080279134390,

     0.6001150934648930,

     0.6000995134721354,

     0.5999341989834830,

     0.7498859393137811,

     0.7500879487671045,

     0.9500004222186464,

     0.9499969138365968,

     0.9900012348724744,

     0.9900017619355059,

     0.9900004567580596,

     0.9900007637471291 };

  static double x_vec[N_MAX] = {

     0.325,

     0.289,

     0.277,

     0.271,

     0.267,

     0.816,

     0.727,

     2.920,

     2.015,

     6.965,

     4.541,

     3.747,

     3.365 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    c = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    c = c_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool student_check ( double a, double b, double c )

{

  if ( b == 0.0 )

  {

    cout << " \n";

    cout << "STUDENT_CHECK - Fatal error!\n";

    cout << "  B must be nonzero.\n";

    return false;

  }

  if ( c <= 0.0 )

  {

    cout << " \n";

    cout << "STUDENT_CHECK - Fatal error!\n";

    cout << "  C must be greater than 0.\n";

    return false;

  }

  return true;

}

double student_mean ( double a, double b, double c )

{

  double mean;

  mean = a;

  return mean;

}

double student_pdf ( double x, double a, double b, double c )

{

  double pdf;

  const double pi = 3.14159265358979323;

  double y;

  y = ( x - a ) / b;

  pdf = r8_gamma ( 0.5 * ( c + 1.0 ) ) / ( sqrt ( pi * c )

    * r8_gamma ( 0.5 * c )

    * sqrt ( pow ( ( 1.0 + y * y / c ), ( 2 * c + 1.0 ) ) ) );

  return pdf;

}

double student_sample ( double a, double b, double c, int &seed )

{

  double a2;

  double b2;

  double x;

  double x2;

  double x3;

  if ( c <= 2.0 )

  {

    cout << " \n";

    cout << "STUDENT_SAMPLE - Fatal error!\n";

    cout << "  Sampling fails for C <= 2.\n";

    exit ( 1 );

  }

  a2 = 0.0;

  b2 = c  / ( c - 2.0 );

  x2 = normal_sample ( a2, b2, seed );

  x3 = chi_square_sample ( c, seed );

  x3 = x3 * c / ( c - 2.0 );

  x = a + b * x2 * sqrt ( c ) / x3;

  return x;

}

double student_variance ( double a, double b, double c )

{

  double variance;

  if ( c <= 2.0 )

  {

    cout << " \n";

    cout << "STUDENT_VARIANCE - Fatal error!\n";

    cout << "  Variance not defined for C <= 2.\n";

    exit ( 1 );

  }

  variance = b * b * c / ( c - 2.0 );

  return variance;

}

double student_noncentral_cdf ( double x, int idf, double d )

{

  double a;

  int a_max = 100;

  double ak;

  double b;

  double cdf;

  double cdf2;

  double drb;

  double emin = 12.5;

  double f;

  double fk;

  double fmkm1;

  double fmkm2;

  int k;

  const double pi = 3.14159265358979323;

  double sum2;

  double temp;

  f = ( double ) idf;

  if ( idf == 1 )

  {

    a = x / sqrt ( f );

    b = f / ( f + x * x );

    drb = d * sqrt ( b );

    cdf2 = normal_01_cdf ( drb );

    cdf = 1.0 - cdf2 + 2.0 * tfn ( drb, a );

  }

  else if ( idf <= a_max )

  {

    a = x / sqrt ( f );

    b = f / ( f + x * x );

    drb = d * sqrt ( b );

    sum2 = 0.0;

    fmkm2 = 0.0;

    if ( r8_abs ( drb ) < emin )

    {

      cdf2 = normal_01_cdf ( a * drb );

      fmkm2 = a * sqrt ( b ) * exp ( - 0.5 * drb * drb ) * cdf2

        / sqrt ( 2.0 * pi );

    }

    fmkm1 = b * d * a * fmkm2;

    if ( r8_abs ( d ) < emin )

    {

      fmkm1 = fmkm1 + 0.5 * b * a * exp ( - 0.5 * d * d ) / pi;

    }

    if ( idf % 2 == 0 )

    {

      sum2 = fmkm2;

    }

    else

    {

      sum2 = fmkm1;

    }

    ak = 1.0;

    for ( k = 2; k <= idf - 2; k = k + 2 )

    {

      fk = ( double ) ( k );

      fmkm2 = b * ( d * a * ak * fmkm1 + fmkm2 ) * ( fk - 1.0 ) / fk;

      ak = 1.0 / ( ak * ( fk - 1.0 ) );

      fmkm1 = b * ( d * a * ak * fmkm2 + fmkm1 ) * fk / ( fk + 1.0 );

      if ( idf % 2 == 0 )

      {

        sum2 = sum2 + fmkm2;

      }

      else

      {

        sum2 = sum2 + fmkm1;

      }

      ak = 1.0 / ( ak * fk );

    }

    if ( idf % 2 == 0 )

    {

      cdf2 = normal_01_cdf ( d );

      cdf = 1.0 - cdf2 + sum2 * sqrt ( 2.0 * pi );

    }

    else

    {

      cdf2 = normal_01_cdf ( drb );

      cdf = 1.0 - cdf2 + 2.0 * ( sum2 + tfn ( drb, a ) );

    }

  }

  else

  {

    a = sqrt ( 0.5 * f ) * exp ( gamma_log ( 0.5 * ( f - 1.0 ) )

      - gamma_log ( 0.5 * f ) ) * d;

    temp = ( x - a ) / sqrt ( f * ( 1.0 + d * d ) / ( f - 2.0 ) - a * a );

    cdf2 = normal_01_cdf ( temp );

    cdf = cdf2;

  }

  return cdf;

}

void student_noncentral_cdf_values ( int &n_data, int &df, double &lambda,

  double &x, double &fx )

{

# define N_MAX 30

  static int df_vec[N_MAX] = {

     1,  2,  3,

     1,  2,  3,

     1,  2,  3,

     1,  2,  3,

     1,  2,  3,

    15, 20, 25,

     1,  2,  3,

    10, 10, 10,

    10, 10, 10,

    10, 10, 10 };

  static double fx_vec[N_MAX] = {

     0.8975836176504333E+00,

     0.9522670169E+00,

     0.9711655571887813E+00,

     0.8231218864E+00,

     0.9049021510E+00,

     0.9363471834E+00,

     0.7301025986E+00,

     0.8335594263E+00,

     0.8774010255E+00,

     0.5248571617E+00,

     0.6293856597E+00,

     0.6800271741E+00,

     0.20590131975E+00,

     0.2112148916E+00,

     0.2074730718E+00,

     0.9981130072E+00,

     0.9994873850E+00,

     0.9998391562E+00,

     0.168610566972E+00,

     0.16967950985E+00,

     0.1701041003E+00,

     0.9247683363E+00,

     0.7483139269E+00,

     0.4659802096E+00,

     0.9761872541E+00,

     0.8979689357E+00,

     0.7181904627E+00,

     0.9923658945E+00,

     0.9610341649E+00,

     0.8688007350E+00 };

  static double lambda_vec[N_MAX] = {

     0.0E+00,

     0.0E+00,

     0.0E+00,

     0.5E+00,

     0.5E+00,

     0.5E+00,

     1.0E+00,

     1.0E+00,

     1.0E+00,

     2.0E+00,

     2.0E+00,

     2.0E+00,

     4.0E+00,

     4.0E+00,

     4.0E+00,

     7.0E+00,

     7.0E+00,

     7.0E+00,

     1.0E+00,

     1.0E+00,

     1.0E+00,

     2.0E+00,

     3.0E+00,

     4.0E+00,

     2.0E+00,

     3.0E+00,

     4.0E+00,

     2.0E+00,

     3.0E+00,

     4.0E+00 };

  static double x_vec[N_MAX] = {

      3.00E+00,

      3.00E+00,

      3.00E+00,

      3.00E+00,

      3.00E+00,

      3.00E+00,

      3.00E+00,

      3.00E+00,

      3.00E+00,

      3.00E+00,

      3.00E+00,

      3.00E+00,

      3.00E+00,

      3.00E+00,

      3.00E+00,

     15.00E+00,

     15.00E+00,

     15.00E+00,

      0.05E+00,

      0.05E+00,

      0.05E+00,

      4.00E+00,

      4.00E+00,

      4.00E+00,

      5.00E+00,

      5.00E+00,

      5.00E+00,

      6.00E+00,

      6.00E+00,

      6.00E+00 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    df = 0;

    lambda = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    df = df_vec[n_data-1];

    lambda = lambda_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

double tfn ( double h, double a )

{

# define NGAUSS 10

  double as;

  double h1;

  double h2;

  double hs;

  int i;

  double rt;

  double two_pi_inverse = 0.1591549430918953;

  double tv1 = 1.0E-35;

  double tv2 = 15.0;

  double tv3 = 15.0;

  double tv4 = 1.0E-05;

  double value;

  double weight[NGAUSS] = {

    0.666713443086881375935688098933E-01,

    0.149451349150580593145776339658,

    0.219086362515982043995534934228,

    0.269266719309996355091226921569,

    0.295524224714752870173892994651,

    0.295524224714752870173892994651,

    0.269266719309996355091226921569,

    0.219086362515982043995534934228,

    0.149451349150580593145776339658,

    0.666713443086881375935688098933E-01 };

  double x;

  double xtab[NGAUSS] = {

   -0.973906528517171720077964012084,

   -0.865063366688984510732096688423,

   -0.679409568299024406234327365115,

   -0.433395394129247190799265943166,

   -0.148874338981631210884826001130,

    0.148874338981631210884826001130,

    0.433395394129247190799265943166,

    0.679409568299024406234327365115,

    0.865063366688984510732096688423,

    0.973906528517171720077964012084 };

  if ( r8_abs ( h ) < tv1 )

  {

    value = atan ( a ) * two_pi_inverse;

  }

  else if ( tv2 < r8_abs ( h ) )

  {

    value = 0.0;

  }

  else if ( r8_abs ( a ) < tv1 )

  {

    value = 0.0;

  }

  else

  {

    hs = - 0.5 * h * h;

    h2 = a;

    as = a * a;

    if ( tv3 <= log ( 1.0 + as ) - hs * as )

    {

      h1 = 0.5 * a;

      as = 0.25 * as;

      for ( ; ; )

      {

        rt = as + 1.0;

        h2 = h1 + ( hs * as + tv3 - log ( rt ) )

          / ( 2.0 * h1 * ( 1.0 / rt - hs ) );

        as = h2 * h2;

        if ( r8_abs ( h2 - h1 ) < tv4 )

        {

          break;

        }

        h1 = h2;

      }

    }

    rt = 0.0;

    for ( i = 0; i < NGAUSS; i++ )

    {

      x = 0.5 * h2 * ( xtab[i] + 1.0 );

      rt = rt + weight[i] * exp ( hs * ( 1.0 + x * x ) ) / ( 1.0 + x * x );

    }

    value = rt * 0.5 * h2 * two_pi_inverse;

  }

  return value;

# undef NGAUSS

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

double triangle_cdf ( double x, double a, double b, double c )

{

  double cdf;

  if ( x <= a )

  {

    cdf = 0.0;

  }

  else if ( x <= b )

  {

    if ( a == b )

    {

      cdf = 0.0;

    }

    else

    {

      cdf = ( x - a ) * ( x - a ) / ( b - a ) / ( c - a );

    }

  }

  else if ( x <= c )

  {

    cdf = ( b - a ) / ( c - a )

        + ( 2.0 * c - b - x ) * ( x - b ) / ( c - b ) / ( c - a );

  }

  else

  {

    cdf = 1.0;

  }

  return cdf;

}

double triangle_cdf_inv ( double cdf, double a, double b, double c )

{

  double cdf_mid;

  double d;

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << "\n";

    cout << "TRIANGLE_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  d = 2.0 / ( c - a );

  cdf_mid = 0.5 * d * ( b - a );

  if ( cdf <= cdf_mid )

  {

    x = a + sqrt ( cdf * ( b - a ) * ( c - a ) );

  }

  else

  {

    x = c - sqrt ( ( c - b ) * ( ( c - b ) - ( cdf - cdf_mid ) * ( c - a ) ) );

  }

  return x;

}

bool triangle_check ( double a, double b, double c )

{

  if ( b < a )

  {

    cout << "\n";

    cout << "TRIANGLE_CHECK - Fatal error!\n";

    cout << "  B < A.\n";

    return false;

  }

  if ( c < b )

  {

    cout << "\n";

    cout << "TRIANGLE_CHECK - Fatal error!\n";

    cout << "  C < B.\n";

    return false;

  }

  if ( a == c )

  {

    cout << "\n";

    cout << "TRIANGLE_CHECK - Fatal error!\n";

    cout << "  A == C.\n";

    return false;

  }

  return true;

}

double triangle_mean ( double a, double b, double c )

{

  double mean;

  mean = a + ( c + b - 2.0 * a ) / 3.0;

  return mean;

}

double triangle_pdf ( double x, double a, double b, double c )

{

  double pdf;

  if ( x <= a )

  {

    pdf = 0.0;

  }

  else if ( x <= b )

  {

    if ( a == b )

    {

      pdf = 0.0;

    }

    else

    {

      pdf = 2.0 * ( x - a ) / ( b - a ) / ( c - a );

    }

  }

  else if ( x <= c )

  {

    if ( b == c )

    {

      pdf = 0.0;

    }

    else

    {

      pdf = 2.0 * ( c - x ) / ( c - b ) / ( c - a );

    }

  }

  else

  {

    pdf = 0.0;

  }

  return pdf;

}

double triangle_sample ( double a, double b, double c, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = triangle_cdf_inv ( cdf, a, b, c );

  return x;

}

double triangle_variance ( double a, double b, double c )

{

  double variance;

  variance = ( ( c - a ) * ( c - a )

             - ( c - a ) * ( b - a )

             + ( b - a ) * ( b - a ) ) / 18.0;

  return variance;

}

double triangular_cdf ( double x, double a, double b )

{

  double cdf;

  if ( x <= a )

  {

    cdf = 0.0;

  }

  else if ( x <= 0.5 * ( a + b ) )

  {

    cdf = 2.0 * ( x * x - 2.0 * a * x + a * a ) / pow ( ( b - a ), 2 );

  }

  else if ( x <= b )

  {

    cdf = 0.5 + ( - 2.0 * x * x + 4.0 * b * x + 0.5 * a * a

      - a * b - 1.5 * b * b ) / pow ( ( b - a ), 2 );

  }

  else

  {

    cdf = 1.0;

  }

  return cdf;

}

double triangular_cdf_inv ( double cdf, double a, double b )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "TRIANGULAR_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf <= 0.5 )

  {

    x = a + 0.5 * ( b - a ) * sqrt ( 2.0 * cdf );

  }

  else

  {

    x = b - 0.5 * ( b - a ) * sqrt ( 2.0 * ( 1.0 - cdf ) );

  }

  return x;

}

bool triangular_check ( double a, double b )

{

  if ( b <= a )

  {

    cout << " \n";

    cout << "TRIANGULAR_CHECK - Fatal error!\n";

    cout << "  B <= A.\n";

    return false;

  }

  return true;

}

double triangular_mean ( double a, double b )

{

  double mean;

  mean = 0.5 * ( a + b );

  return mean;

}

double triangular_pdf ( double x, double a, double b )

{

  double pdf;

  if ( x <= a )

  {

    pdf = 0.0;

  }

  else if ( x <= 0.5 * ( a + b ) )

  {

    pdf = 4.0 * ( x - a ) / ( b - a ) / ( b - a );

  }

  else if ( x <= b )

  {

    pdf = 4.0 * ( b - x ) / ( b - a ) / ( b - a );

  }

  else

  {

    pdf = 0.0;

  }

  return pdf;

}

double triangular_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = triangular_cdf_inv ( cdf, a, b );

  return x;

}

double triangular_variance ( double a, double b )

{

  double variance;

  variance = ( b - a ) * ( b - a ) / 24.0;

  return variance;

}

double trigamma ( double x )

{

  double a = 0.0001;

  double b = 5.0;

  double b2 =   1.0 / 6.0;

  double b4 = - 1.0 / 30.0;

  double b6 =   1.0 / 42.0;

  double b8 = - 1.0 / 30.0;

  double value;

  double y;

  double z;

  if ( x <= 0.0 )

  {

    value = 0.0;

    cout << " \n";

    cout << "TRIGAMMA - Fatal error!\n";

    cout << "  X <= 0.\n";

    exit ( 1 );

  }

  else if ( x <= a )

  {

    value = 1.0 / x / x;

  }

  else

  {

    z = x;

    value = 0.0;

    while ( z < b )

    {

      value = value + 1.0 / z / z;

      z = z + 1.0;

    }

    y = 1.0 / z / z;

    value = value + 0.5 *

            y + ( 1.0

          + y * ( b2

          + y * ( b4

          + y * ( b6

          + y *   b8 )))) / z;

  }

  return value;

}

double uniform_01_cdf ( double x )

{

  double cdf;

  if ( x < 0.0 )

  {

    cdf = 0.0;

  }

  else if ( 1.0 < x )

  {

    cdf = 1.0;

  }

  else

  {

    cdf = x;

  }

  return cdf;

}

double uniform_01_cdf_inv ( double cdf )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "UNIFORM_01_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = cdf;

  return x;

}

double uniform_01_mean ( )

{

  double mean;

  mean = 0.5;

  return mean;

}

double uniform_01_pdf ( double x )

{

  double pdf;

  if ( x < 0.0 || 1.0 < x )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = 1.0;

  }

  return pdf;

}

double uniform_01_sample ( int &seed )

{

  static int ia = 16807;

  static int ib15 = 32768;

  static int ib16 = 65536;

  static int ip = 2147483647;

  int iprhi;

  int ixhi;

  int k;

  int leftlo;

  int loxa;

  double temp;

  if ( seed == 0 )

  {

    seed = ip;

  }

  ixhi = seed / ib16;

  loxa = ( seed - ixhi * ib16 ) * ia;

  leftlo = loxa / ib16;

  iprhi = ixhi * ia + leftlo;

  k = iprhi / ib15;

  seed = ( ( ( loxa - leftlo * ib16 ) - ip ) +

    ( iprhi - k * ib15 ) * ib16 ) + k;

  if ( seed < 0 )

  {

    seed = seed + ip;

  }

  temp = ( ( double ) seed ) * 4.656612875E-10;

  return temp;

}

double uniform_01_variance ( )

{

  double variance;

  variance = 1.0 / 12.0;

  return variance;

}

double *uniform_01_order_sample ( int n, int &seed )

{

  int i;

  double u;

  double v;

  double *x;

  x = new double[n];

  v = 1.0;

  for ( i = n-1; 0 <= i; i-- )

  {

    u = r8_uniform_01 ( seed );

    v = v * pow ( u, 1.0 / ( double ) ( i + 1 ) );

    x[i] = v;

  }

  return x;

}

double uniform_cdf ( double x, double a, double b )

{

  double cdf;

  if ( x < a )

  {

    cdf = 0.0;

  }

  else if ( b < x )

  {

    cdf = 1.0;

  }

  else

  {

    cdf = ( x - a ) / ( b - a );

  }

  return cdf;

}

double uniform_cdf_inv ( double cdf, double a, double b )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "UNIFORM_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = a + ( b - a ) * cdf;

  return x;

}

bool uniform_check ( double a, double b )

{

  if ( b <= a )

  {

    cout << " \n";

    cout << "UNIFORM_CHECK - Fatal error!\n";

    cout << "  B <= A.\n";

    return false;

  }

  return true;

}

double uniform_mean ( double a, double b )

{

  double mean;

  mean = 0.5 * ( a + b );

  return mean;

}

double uniform_pdf ( double x, double a, double b )

{

  double pdf;

  if ( x < a || b < x )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = 1.0 / ( b - a );

  }

  return pdf;

}

double uniform_sample ( double a, double b, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = uniform_cdf_inv ( cdf, a, b );

  return x;

}

double uniform_variance ( double a, double b )

{

  double variance;

  variance = ( b - a ) * ( b - a ) / 12.0;

  return variance;

}

double uniform_discrete_cdf ( int x, int a, int b )

{

  double cdf;

  if ( x < a )

  {

    cdf = 0.0;

  }

  else if ( b < x )

  {

    cdf = 1.0;

  }

  else

  {

    cdf = ( double ) ( x + 1 - a ) / ( double ) ( b + 1 - a );

  }

  return cdf;

}

int uniform_discrete_cdf_inv ( double cdf, int a, int b )

{

  double a2;

  double b2;

  int x;

  double x2;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "UNIFORM_DISCRETE_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  a2 = ( double ) ( a ) - 0.5;

  b2 = ( double ) ( b ) + 0.5;

  x2 = a + cdf * ( b2 - a2 );

  x = r8_nint ( x2 );

  x = i4_max ( x, a );

  x = i4_min ( x, b );

  return x;

}

bool uniform_discrete_check ( int a, int b )

{

  if ( b < a )

  {

    cout << " \n";

    cout << "UNIFORM_DISCRETE_CHECK - Fatal error!\n";

    cout << "  B < A.\n";

    return false;

  }

  return true;

}

double uniform_discrete_mean ( int a, int b )

{

  double mean;

  mean = 0.5 * ( double ) ( a + b );

  return mean;

}

double uniform_discrete_pdf ( int x, int a, int b )

{

  double pdf;

  if ( x < a || b < x )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = 1.0 / ( double ) ( b + 1 - a );

  }

  return pdf;

}

int uniform_discrete_sample ( int a, int b, int &seed )

{

  double cdf;

  int x;

  cdf = r8_uniform_01 ( seed );

  x = uniform_discrete_cdf_inv ( cdf, a, b );

  return x;

}

double uniform_discrete_variance ( int a, int b )

{

  double variance;

  variance = ( double ) ( ( b + 1 - a ) * ( b + 1 - a ) - 1 ) / 12.0;

  return variance;

}

double *uniform_nsphere_sample ( int n, int &seed )

{

  int i;

  double sum;

  double *x;

  x = new double[n];

  for ( i = 0; i < n; i++ )

  {

    x[i] = normal_01_sample ( seed );

  }

  sum = 0.0;

  for ( i = 0; i < n; i++ )

  {

    sum = sum + x[i] * x[i];

  }

  sum = sqrt ( sum );

  for ( i = 0; i < n; i++ )

  {

    x[i] = x[i] / sum;

  }

  return x;

}

double von_mises_cdf ( double x, double a, double b )

{

  double a1 = 12.0;

  double a2 = 0.8;

  double a3 = 8.0;

  double a4 = 1.0;

  double arg;

  double c;

  double c1 = 56.0;

  double cdf;

  double ck = 10.5;

  double cn;

  double erfx;

  int ip;

  int n;

  double p;

  const double pi = 3.14159265358979323;

  double r;

  double s;

  double sn;

  double u;

  double v;

  double y;

  double z;

  if ( x - a <= -pi )

  {

    cdf = 0.0;

    return cdf;

  }

  if ( pi <= x - a )

  {

    cdf = 1.0;

    return cdf;

  }

  z = b;

  u = r8_modp ( x - a + pi, 2.0 * pi );

  if ( u < 0.0 )

  {

    u = u + 2.0 * pi;

  }

  y = u - pi;

  if ( z <= ck )

  {

    v = 0.0;

    if ( 0.0 < z )

    {

      ip = ( int ) ( z * a2 - a3 / ( z + a4 ) + a1 );

      p = ( double ) ( ip );

      s = sin ( y );

      c = cos ( y );

      y = p * y;

      sn = sin ( y );

      cn = cos ( y );

      r = 0.0;

      z = 2.0 / z;

      for ( n = 2; n <= ip; n++ )

      {

        p = p - 1.0;

        y = sn;

        sn = sn * c - cn * s;

        cn = cn * c + y * s;

        r = 1.0 / ( p * z + r );

        v = ( sn / p + v ) * r;

      }

    }

    cdf = ( u * 0.5 + v ) / pi;

  }

  else

  {

    c = 24.0 * z;

    v = c - c1;

    r = sqrt ( ( 54.0 / ( 347.0 / v + 26.0 - c ) - 6.0 + c ) / 12.0 );

    z = sin ( 0.5 * y ) * r;

    s = 2.0 * z * z;

    v = v - s + 3.0;

    y = ( c - s - s - 16.0 ) / 3.0;

    y = ( ( s + 1.75 ) * s + 83.5 ) / v - y;

    arg = z * ( 1.0 - s / y / y );

    erfx = error_f ( arg );

    cdf = 0.5 * erfx + 0.5;

  }

  cdf = r8_max ( cdf, 0.0 );

  cdf = r8_min ( cdf, 1.0 );

  return cdf;

}

double von_mises_cdf_inv ( double cdf, double a, double b )

{

  double cdf1;

  double cdf2;

  double cdf3;

  int it;

  int it_max = 100;

  const double pi = 3.14159265358979323;

  double tol = 0.0001;

  double x;

  double x1;

  double x2;

  double x3;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "VON_MISES_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  if ( cdf == 0.0 )

  {

    x = a - pi;

    return x;

  }

  else if ( 1.0 == cdf )

  {

    x = a + pi;

    return x;

  }

  x1 = a - pi;

  cdf1 = 0.0;

  x2 = a + pi;

  cdf2 = 1.0;

  it = 0;

  for ( ; ; )

  {

    it = it + 1;

    x3 = 0.5 * ( x1 + x2 );

    cdf3 = von_mises_cdf ( x3, a, b );

    if ( r8_abs ( cdf3 - cdf ) < tol )

    {

      x = x3;

      break;

    }

    if ( it_max < it )

    {

      cout << " \n";

      cout << "VON_MISES_CDF_INV - Fatal error!\n";

      cout << "  Iteration limit exceeded.\n";

      exit ( 1 );

    }

    if ( ( cdf3 <= cdf && cdf1 <= cdf ) || ( cdf <= cdf3 && cdf <= cdf1 ) )

    {

      x1 = x3;

      cdf1 = cdf3;

    }

    else

    {

      x2 = x3;

      cdf2 = cdf3;

    }

  }

  return x;

}

void von_mises_cdf_values ( int &n_data, double &a, double &b, double &x,

  double &fx )

{

# define N_MAX 23

  static double a_vec[N_MAX] = {

     0.0E+00,

     0.0E+00,

     0.0E+00,

     0.0E+00,

     0.0E+00,

     0.1E+01,

     0.1E+01,

     0.1E+01,

     0.1E+01,

     0.1E+01,

     0.1E+01,

    -0.2E+01,

    -0.1E+01,

     0.0E+01,

     0.1E+01,

     0.2E+01,

     0.3E+01,

     0.0E+00,

     0.0E+00,

     0.0E+00,

     0.0E+00,

     0.0E+00,

     0.0E+00 };

  static double b_vec[N_MAX] = {

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.1E+01,

      0.2E+01,

      0.2E+01,

      0.2E+01,

      0.2E+01,

      0.2E+01,

      0.2E+01,

      0.3E+01,

      0.3E+01,

      0.3E+01,

      0.3E+01,

      0.3E+01,

      0.3E+01,

      0.0E+00,

      0.1E+01,

      0.2E+01,

      0.3E+01,

      0.4E+01,

      0.5E+01 };

  static double fx_vec[N_MAX] = {

     0.2535089956281180E-01,

     0.1097539041177346E+00,

     0.5000000000000000E+00,

     0.8043381312498558E+00,

     0.9417460124555197E+00,

     0.5000000000000000E+00,

     0.6018204118446155E+00,

     0.6959356933122230E+00,

     0.7765935901304593E+00,

     0.8410725934916615E+00,

     0.8895777369550366E+00,

     0.9960322705517925E+00,

     0.9404336090170247E+00,

     0.5000000000000000E+00,

     0.5956639098297530E-01,

     0.3967729448207649E-02,

     0.2321953958111930E-03,

     0.6250000000000000E+00,

     0.7438406999109122E+00,

     0.8369224904294019E+00,

     0.8941711407897124E+00,

     0.9291058600568743E+00,

     0.9514289900655436E+00 };

  static double x_vec[N_MAX] = {

     -0.2617993977991494E+01,

     -0.1570796326794897E+01,

      0.0000000000000000E+00,

      0.1047197551196598E+01,

      0.2094395102393195E+01,

      0.1000000000000000E+01,

      0.1200000000000000E+01,

      0.1400000000000000E+01,

      0.1600000000000000E+01,

      0.1800000000000000E+01,

      0.2000000000000000E+01,

      0.0000000000000000E+00,

      0.0000000000000000E+00,

      0.0000000000000000E+00,

      0.0000000000000000E+00,

      0.0000000000000000E+00,

      0.0000000000000000E+00,

      0.7853981633974483E+00,

      0.7853981633974483E+00,

      0.7853981633974483E+00,

      0.7853981633974483E+00,

      0.7853981633974483E+00,

      0.7853981633974483E+00 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    a = 0.0;

    b = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    a = a_vec[n_data-1];

    b = b_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool von_mises_check ( double a, double b )

{

  const double pi = 3.14159265358979323;

  if ( a < - pi || pi < a )

  {

    cout << " \n";

    cout << "VON_MISES_CHECK - Fatal error!\n";

    cout << "  A < -PI or PI < A.\n";

    return false;

  }

  if ( b <= 0.0 )

  {

    cout << " \n";

    cout << "VON_MISES_CHECK - Fatal error!\n";

    cout << "  B <= 0.0\n";

    return false;

  }

  return true;

#

}

double von_mises_circular_variance ( double a, double b )

{

  double value;

  value = 1.0 - bessel_i1 ( b ) / bessel_i0 ( b );

  return value;

}

double von_mises_mean ( double a, double b )

{

  double mean;

  mean = a;

  return mean;

}

double von_mises_pdf ( double x, double a, double b )

{

  double pdf;

  const double pi = 3.14159265358979323;

  if ( x < a - pi )

  {

    pdf = 0.0;

  }

  else if ( x <= a + pi )

  {

    pdf = exp ( b * cos ( x - a ) ) / ( 2.0 * pi * bessel_i0 ( b ) );

  }

  else

  {

    pdf = 0.0;

  }

  return pdf;

}

double von_mises_sample ( double a, double b, int &seed )

{

  double c;

  double f;

  const double pi = 3.14159265358979323;

  double r;

  double rho;

  double tau;

  double u1;

  double u2;

  double u3;

  double x;

  double z;

  tau = 1.0 + sqrt ( 1.0 + 4.0 * b * b );

  rho = ( tau - sqrt ( 2.0 * tau ) ) / ( 2.0 * b );

  r = ( 1.0 + rho * rho ) / ( 2.0 * rho );

  for ( ; ; )

  {

    u1 = r8_uniform_01 ( seed );

    z = cos ( pi * u1 );

    f = ( 1.0 + r * z ) / ( r + z );

    c = b * ( r - f );

    u2 = r8_uniform_01 ( seed );

    if ( u2 < c * ( 2.0 - c ) )

    {

      break;

    }

    if ( c <= log ( c / u2 ) + 1.0 )

    {

      break;

    }

  }

  u3 = r8_uniform_01 ( seed );

  x = a + r8_sign ( u3 - 0.5 ) * acos ( f );

  return x;

}

double weibull_cdf ( double x, double a, double b, double c )

{

  double cdf;

  double y;

  if ( x < a )

  {

    cdf = 0.0;

  }

  else

  {

    y = ( x - a ) / b;

    cdf = 1.0 - 1.0 / exp ( pow ( y, c ) );

  }

  return cdf;

}

double weibull_cdf_inv ( double cdf, double a, double b, double c )

{

  double x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << "\n";

    cout << "WEIBULL_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = a + b * pow ( ( - log ( 1.0 - cdf ) ), ( 1.0 / c ) );

  return x;

}

void weibull_cdf_values ( int &n_data, double &alpha, double &beta,

  double &x, double &fx )

{

# define N_MAX 12

  static double alpha_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01 };

  static double beta_vec[N_MAX] = {

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.5000000000000000E+00,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.5000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01 };

  static double fx_vec[N_MAX] = {

     0.8646647167633873E+00,

     0.9816843611112658E+00,

     0.9975212478233336E+00,

     0.9996645373720975E+00,

     0.6321205588285577E+00,

     0.4865828809674080E+00,

     0.3934693402873666E+00,

     0.3296799539643607E+00,

     0.8946007754381357E+00,

     0.9657818816883340E+00,

     0.9936702845725143E+00,

     0.9994964109502630E+00 };

  static double x_vec[N_MAX] = {

     0.1000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.4000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.2000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01,

     0.3000000000000000E+01 };

  if ( n_data < 0 )

  {

    n_data = 0;

  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )

  {

    n_data = 0;

    alpha = 0.0;

    beta = 0.0;

    x = 0.0;

    fx = 0.0;

  }

  else

  {

    alpha = alpha_vec[n_data-1];

    beta = beta_vec[n_data-1];

    x = x_vec[n_data-1];

    fx = fx_vec[n_data-1];

  }

  return;

# undef N_MAX

}

bool weibull_check ( double a, double b, double c )

{

  if ( b <= 0.0 )

  {

    cout << "\n";

    cout << "WEIBULL_CHECK - Fatal error!\n";

    cout << "  B <= 0.\n";

    return false;

  }

  if ( c <= 0.0 )

  {

    cout << "\n";

    cout << "WEIBULL_CHECK - Fatal error!\n";

    cout << "  C <= 0.\n";

    return false;

  }

  return true;

}

double weibull_mean ( double a, double b, double c )

{

  double mean;

  mean = b * r8_gamma ( ( c + 1.0 ) / c ) + a;

  return mean;

}

double weibull_pdf ( double x, double a, double b, double c )

{

  double pdf;

  double y;

  if ( x < a )

  {

    pdf = 0.0;

  }

  else

  {

    y = ( x - a ) / b;

    pdf = ( c / b ) * pow ( y, ( c - 1.0 ) )  / exp ( pow ( y, c ) );

  }

  return pdf;

}

double weibull_sample ( double a, double b, double c, int &seed )

{

  double cdf;

  double x;

  cdf = r8_uniform_01 ( seed );

  x = weibull_cdf_inv ( cdf, a, b, c );

  return x;

}

double weibull_variance ( double a, double b, double c )

{

  double g1;

  double g2;

  double variance;

  g1 = r8_gamma ( ( c + 2.0 ) / c );

  g2 = r8_gamma ( ( c + 1.0 ) / c );

  variance = b * b * ( g1 - g2 * g2 );

  return variance;

}

double weibull_discrete_cdf ( int x, double a, double b )

{

  double cdf;

  if ( x < 0 )

  {

    cdf = 0.0;

  }

  else

  {

    cdf = 1.0 - pow ( 1.0 - a, pow ( x + 1, b ) );

  }

  return cdf;

}

int weibull_discrete_cdf_inv ( double cdf, double a, double b )

{

  int x;

  if ( cdf < 0.0 || 1.0 < cdf )

  {

    cout << " \n";

    cout << "WEIBULL_DISCRETE_CDF_INV - Fatal error!\n";

    cout << "  CDF < 0 or 1 < CDF.\n";

    exit ( 1 );

  }

  x = r8_ceiling (

    pow ( log ( 1.0 - cdf ) / log ( 1.0 - a ), 1.0 / b ) - 1.0 );

  return x;

}

bool weibull_discrete_check ( double a, double b )

{

  if ( a < 0.0 || 1.0 < a )

  {

    cout << " \n";

    cout << "WEIBULL_DISCRETE_CHECK - Fatal error!\n";

    cout << "  A < 0 or 1 < A.\n";

    return false;

  }

  if ( b <= 0.0 )

  {

    cout << " \n";

    cout << "WEIBULL_DISCRETE_CHECK - Fatal error!\n";

    cout << "  B <= 0.\n";

    return false;

  }

  return true;

}

double weibull_discrete_pdf ( int x, double a, double b )

{

  double pdf;

  if ( x < 0 )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = pow ( 1.0 - a , pow ( x, b ) ) - pow ( 1.0 - a, pow ( x + 1, b ) );

  }

  return pdf;

}

int weibull_discrete_sample ( double a, double b, int &seed )

{

  double cdf;

  int x;

  cdf = r8_uniform_01 ( seed );

  x = weibull_discrete_cdf_inv ( cdf, a, b );

  return x;

}

double zeta ( double p )

{

  int n;

  const double pi = 3.14159265358979323;

  double value;

  double zsum;

  double zsum_old;

  if ( p <= 1.0 )

  {

    cout << " \n";

    cout << "ZETA - Fatal error!\n";

    cout << "  Exponent P <= 1.0.\n";

    exit ( 1 );

  }

  else if ( p == 2.0 )

  {

    value = pow ( pi, 2 ) / 6.0;

  }

  else if ( p == 3.0 )

  {

    value = 1.2020569032;

  }

  else if ( p == 4.0 )

  {

    value = pow ( pi, 4 ) / 90.0;

  }

  else if ( p == 5.0 )

  {

    value = 1.0369277551;

  }

  else if ( p == 6.0 )

  {

    value = pow ( pi, 6 ) / 945.0;

  }

  else if ( p == 7.0 )

  {

    value = 1.0083492774;

  }

  else if ( p == 8.0 )

  {

    value = pow ( pi, 8 ) / 9450.0;

  }

  else if ( p == 9.0 )

  {

    value = 1.0020083928;

  }

  else if ( p == 10.0 )

  {

    value = pow ( pi, 10 ) / 93555.0;

  }

  else if ( p == 11.0 )

  {

    value = 1.0004941886;

  }

  else if ( p == 12.0 )

  {

    value = 1.0002460866;

  }

  else if ( p == 13.0 )

  {

    value = 1.0001227133;

  }

  else if ( p == 14.0 )

  {

    value = 1.0000612482;

  }

  else if ( p == 15.0 )

  {

    value = 1.0000305882;

  }

  else if ( p == 16.0 )

  {

    value = 1.0000152823;

  }

  else if ( p == 17.0 )

  {

    value = 1.0000076372;

  }

  else if ( p == 18.0 )

  {

    value = 1.0000038173;

  }

  else if ( p == 19.0 )

  {

    value = 1.0000019082;

  }

  else if ( p == 20.0 )

  {

    value = 1.0000009540;

  }

  else

  {

    zsum = 0.0;

    n = 0;

    for ( ; ; )

    {

      n = n + 1;

      zsum_old = zsum;

      zsum = zsum + 1.0 / pow ( ( double ) n, p );

      if ( zsum <= zsum_old )

      {

        break;

      }

    }

    value = zsum;

  }

  return value;

}

double zipf_cdf ( int x, double a )

{

  double c;

  double cdf;

  double pdf;

  int y;

  if ( x < 1 )

  {

    cdf = 0.0;

  }

  else

  {

    c = zeta ( a );

    cdf = 0.0;

    for ( y = 1; y <= x; y++ )

    {

      pdf = 1.0 / pow ( y, a ) / c;

      cdf = cdf + pdf;

    }

  }

  return cdf;

}

bool zipf_check ( double a )

{

  if ( a <= 1.0 )

  {

    cout << " \n";

    cout << "ZIPF_CHECK - Fatal error!\n";

    cout << "  A <= 1.\n";

    return false;

  }

  return true;

}

double zipf_mean ( double a )

{

  double mean;

  if ( a <= 2.0 )

  {

    cout << " \n";

    cout << "ZIPF_MEAN - Fatal error!\n";

    cout << "  No mean defined for A <= 2.\n";

    exit ( 1 );

  }

  mean = zeta ( a - 1.0 ) / zeta ( a );

  return mean;

}

double zipf_pdf ( int x, double a )

{

  double pdf;

  if ( x < 1 )

  {

    pdf = 0.0;

  }

  else

  {

    pdf = 1.0 / pow ( x, a ) / zeta ( a );

  }

  return pdf;

}

int zipf_sample ( double a, int &seed )

{

  double b;

  double t;

  double u;

  double v;

  double w;

  int x;

  b = pow ( 2.0, ( a - 1.0 ) );

  for ( ; ; )

  {

    u = r8_uniform_01 ( seed );

    v = r8_uniform_01 ( seed );

    w = ( int ) ( 1.0 / pow ( u, 1.0 / ( a - 1.0 ) ) );

    t = pow ( ( w + 1.0 ) / w, a - 1.0 );

    if ( v * w * ( t - 1.0 ) * b <= t * ( b - 1.0 ) )

    {

      break;

    }

  }

  x = ( int ) w;

  return x;

}

double zipf_variance ( double a )

{

  double mean;

  double variance;

  if ( a <= 3.0 )

  {

    cerr << " \n";

    cerr << "ZIPF_VARIANCE - Fatal error!\n";

    cerr << "  No variance defined for A <= 3.0.\n";

    exit ( 1 );

  }

  mean = zipf_mean ( a );

  variance = zeta ( a - 2.0 ) / zeta ( a ) - mean * mean;

  return variance;

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/