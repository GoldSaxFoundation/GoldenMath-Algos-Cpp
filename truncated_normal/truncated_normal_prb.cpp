
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <cmath>

# include <ctime>

using namespace std;

# include "truncated_normal.hpp"

int main ( );

void test01 ( );

void test02 ( );

void test03 ( );

void test04 ( );

void test05 ( );

void test06 ( );

void test07 ( );

void test08 ( );

void test09 ( );

void test10 ( );

void test11 ( );

void test12 ( );

void test13 ( );

void test14 ( );

void test15 ( );

void test16 ( );

void test17 ( );

void test18 ( );

void test19 ( );

void test20 ( );

void test21 ( );

void test22 ( );

int main ( )

{

  timestamp ( );

  cout << "\n";

  cout << "TRUNCATED_NORMAL_PRB\n";

  cout << "  C++ version.\n";

  cout << "  Test the TRUNCATED_NORMAL library.\n";

  test01 ( );

  test02 ( );

  test03 ( );

  test04 ( );

  test05 ( );

  test06 ( );

  test07 ( );

  test08 ( );

  test09 ( );

  test10 ( );

  test11 ( );

  test12 ( );

  test13 ( );

  test14 ( );

  test15 ( );

  test16 ( );

  test17 ( );

  test18 ( );

  test19 ( );

  test20 ( );

  test21 ( );

  test22 ( );

  cout << "\n";

  cout << "TRUNCATED_NORMAL_PRB\n";

  cout << "  Normal end of execution.\n";

  cout << "\n";

  timestamp ( );

  return 0;

}

void test01 ( )

{

  double cdf;

  int i;

  double pdf;

  int seed = 123456789;

  double x;

  double x2;

  cout << "\n";

  cout << "TEST01\n";

  cout << "  For the Normal 01 PDF:\n";

  cout << "  NORMAL_01_CDF evaluates the CDF;\n";

  cout << "  NORMAL_01_CDF_INV inverts the CDF.\n";

  cout << "  NORMAL_01_PDF evaluates the PDF;\n";

  cout << "\n";

  cout << "       X            PDF           CDF            CDF_INV\n";

  cout << "\n";

  for ( i = 1; i <= 10; i++ )

  {

    x = normal_01_sample ( seed );

    pdf = normal_01_pdf ( x );

    cdf = normal_01_cdf ( x );

    x2 = normal_01_cdf_inv ( cdf );

    cout << "  "

         << setw(24) << setprecision(16) << x   << "  "

         << setw(12) << setprecision(6)  << pdf << "  "

         << setw(12) << setprecision(6)  << cdf << "  "

         << setw(24) << setprecision(16) << x2  << "\n";

  }

  cout << setprecision(6);

  return;

}

void test02 ( )

{

# define SAMPLE_NUM 1000

  int i;

  double mean;

  int seed = 123456789;

  double variance;

  double x[SAMPLE_NUM];

  double xmax;

  double xmin;

  cout << "\n";

  cout << "TEST02\n";

  cout << "  For the Normal 01 PDF:\n";

  cout << "  NORMAL_01_MEAN computes the mean;\n";

  cout << "  NORMAL_01_SAMPLE samples;\n";

  cout << "  NORMAL_01_VARIANCE computes the variance;\n";

  mean = normal_01_mean ( );

  variance = normal_01_variance ( );

  cout << "\n";

  cout << "  PDF mean =     " << mean     << "\n";

  cout << "  PDF variance = " << variance << "\n";

  for ( i = 0; i < SAMPLE_NUM; i++ )

  {

    x[i] = normal_01_sample ( seed );

  }

  mean = r8vec_mean ( SAMPLE_NUM, x );

  variance = r8vec_variance ( SAMPLE_NUM, x );

  xmax = r8vec_max ( SAMPLE_NUM, x );

  xmin = r8vec_min ( SAMPLE_NUM, x );

  cout << "\n";

  cout << "  Sample size =     " << SAMPLE_NUM  << "\n";

  cout << "  Sample mean =     " << mean     << "\n";

  cout << "  Sample variance = " << variance << "\n";

  cout << "  Sample maximum =  " << xmax     << "\n";

  cout << "  Sample minimum =  " << xmin     << "\n";

  return;

# undef SAMPLE_NUM

}

void test03 ( )

{

  double a;

  double b;

  double cdf;

  int i;

  double pdf;

  int seed = 123456789;

  double x;

  double x2;

  cout << "\n";

  cout << "TEST03\n";

  cout << "  For the Normal PDF:\n";

  cout << "  NORMAL_CDF evaluates the CDF;\n";

  cout << "  NORMAL_CDF_INV inverts the CDF.\n";

  cout << "  NORMAL_PDF evaluates the PDF;\n";

  a = 100.0;

  b = 15.0;

  cout << "\n";

  cout << "  PDF parameter A =      " << a << "\n";

  cout << "  PDF parameter B =      " << b << "\n";

  cout << "\n";

  cout << "       X            PDF           CDF            CDF_INV\n";

  cout << "\n";

  for ( i = 1; i <= 10; i++ )

  {

    x = normal_sample ( a, b, seed );

    pdf = normal_pdf ( x, a, b );

    cdf = normal_cdf ( x, a, b );

    x2 = normal_cdf_inv ( cdf, a, b );

    cout << "  "

         << setw(12) << x   << "  "

         << setw(12) << pdf << "  "

         << setw(12) << cdf << "  "

         << setw(12) << x2  << "\n";

  }

  return;

}

void test04 ( )

{

# define SAMPLE_NUM 1000

  double a;

  double b;

  int i;

  double mean;

  int seed = 123456789;

  double variance;

  double x[SAMPLE_NUM];

  double xmax;

  double xmin;

  cout << "\n";

  cout << "TEST04\n";

  cout << "  For the Normal PDF:\n";

  cout << "  NORMAL_MEAN computes the mean;\n";

  cout << "  NORMAL_SAMPLE samples;\n";

  cout << "  NORMAL_VARIANCE computes the variance;\n";

  a = 100.0;

  b = 15.0;

  cout << "\n";

  cout << "  PDF parameter A =      " << a << "\n";

  cout << "  PDF parameter B =      " << b << "\n";

  mean = normal_mean ( a, b );

  variance = normal_variance ( a, b );

  cout << "\n";

  cout << "  PDF mean =     " << mean     << "\n";

  cout << "  PDF variance = " << variance << "\n";

  for ( i = 0; i < SAMPLE_NUM; i++ )

  {

    x[i] = normal_sample ( a, b, seed );

  }

  mean = r8vec_mean ( SAMPLE_NUM, x );

  variance = r8vec_variance ( SAMPLE_NUM, x );

  xmax = r8vec_max ( SAMPLE_NUM, x );

  xmin = r8vec_min ( SAMPLE_NUM, x );

  cout << "\n";

  cout << "  Sample size =     " << SAMPLE_NUM  << "\n";

  cout << "  Sample mean =     " << mean     << "\n";

  cout << "  Sample variance = " << variance << "\n";

  cout << "  Sample maximum =  " << xmax     << "\n";

  cout << "  Sample minimum =  " << xmin     << "\n";

  return;

# undef SAMPLE_NUM

}

void test05 ( )

{

  double a;

  double b;

  double cdf;

  int i;

  double mu;

  double pdf;

  double s;

  int seed;

  double x;

  double x2;

  a = 50.0;

  b = 150.0;

  mu = 100.0;

  s = 25.0;

  seed = 123456789;

  cout << "\n";

  cout << "TEST05\n";

  cout << "  For the Truncated Normal PDF:\n";

  cout << "  TRUNCATED_NORMAL_AB_CDF evaluates the CDF.\n";

  cout << "  TRUNCATED_NORMAL_AB_CDF_INV inverts the CDF.\n";

  cout << "  TRUNCATED_NORMAL_AB_PDF evaluates the PDF.\n";

  cout << "\n";

  cout << "  The parent normal distribution has\n";

  cout << "    mean =               " << mu << "\n";

  cout << "    standard deviation = " << s << "\n";

  cout << "  The parent distribution is truncated to\n";

  cout << "  the interval [" << a << "," << b << "]\n";

  cout << "\n";

  cout << "       X            PDF           CDF            CDF_INV\n";

  cout << "\n";

  for ( i = 1; i <= 10; i++ )

  {

    x = truncated_normal_ab_sample ( mu, s, a, b, seed );

    pdf = truncated_normal_ab_pdf ( x, mu, s, a, b );

    cdf = truncated_normal_ab_cdf ( x, mu, s, a, b );

    x2 = truncated_normal_ab_cdf_inv ( cdf, mu, s, a, b );

    cout << "  " << setw(14) << x

         << "  " << setw(14) << pdf

         << "  " << setw(14) << cdf

         << "  " << setw(14) << x2 << "\n";

  }

  return;

}

void test06 ( )

{

  double a;

  double b;

  int i;

  double mean;

  double mu;

  double s;

  int sample_num = 1000;

  int seed;

  double variance;

  double *x;

  double xmax;

  double xmin;

  a = 50.0;

  b = 150.0;

  mu = 100.0;

  s = 25.0;

  seed = 123456789;

  cout << "\n";

  cout << "TEST06\n";

  cout << "  For the Truncated Normal PDF:\n";

  cout << "  TRUNCATED_NORMAL_AB_MEAN computes the mean;\n";

  cout << "  TRUNCATED_NORMAL_AB_SAMPLE samples;\n";

  cout << "  TRUNCATED_NORMAL_AB_VARIANCE computes the variance.\n";

  cout << "\n";

  cout << "  The parent normal distribution has\n";

  cout << "    mean =               " << mu << "\n";

  cout << "    standard deviation = " << s << "\n";

  cout << "  The parent distribution is truncated to\n";

  cout << "  the interval [" << a << "," << b << "]\n";

  mean = truncated_normal_ab_mean ( mu, s, a, b );

  variance = truncated_normal_ab_variance ( mu, s, a, b );

  cout << "\n";

  cout << "  PDF mean      =               " << mean << "\n";

  cout << "  PDF variance =                " << variance << "\n";

  x = ( double * ) malloc ( sample_num * sizeof ( double ) );

  for ( i = 0; i < sample_num; i++ )

  {

    x[i] = truncated_normal_ab_sample ( mu, s, a, b, seed );

  }

  mean = r8vec_mean ( sample_num, x );

  variance = r8vec_variance ( sample_num, x );

  xmax = r8vec_max ( sample_num, x );

  xmin = r8vec_min ( sample_num, x );

  cout << "\n";

  cout << "  Sample size =     " << sample_num << "\n";

  cout << "  Sample mean =     " << mean << "\n";

  cout << "  Sample variance = " << variance << "\n";

  cout << "  Sample maximum =  " << xmax << "\n";

  cout << "  Sample minimum =  " << xmin << "\n";

  delete [] x;

  return;

}

void test07 ( )

{

  double a;

  double cdf;

  int i;

  double mu;

  double pdf;

  double s;

  int seed;

  double x;

  double x2;

  a = 50.0;

  mu = 100.0;

  s = 25.0;

  seed = 123456789;

  cout << "\n";

  cout << "TEST07\n";

  cout << "  For the Lower Truncated Normal PDF:\n";

  cout << "  TRUNCATED_NORMAL_A_CDF evaluates the CDF.\n";

  cout << "  TRUNCATED_NORMAL_A_CDF_INV inverts the CDF.\n";

  cout << "  TRUNCATED_NORMAL_A_PDF evaluates the PDF.\n";

  cout << "\n";

  cout << "  The parent normal distribution has\n";

  cout << "    mean =               " << mu << "\n";

  cout << "    standard deviation = " << s << "\n";

  cout << "  The parent distribution is truncated to\n";

  cout << "  the interval [" << a << ",+oo]\n";

  cout << "\n";

  cout << "       X            PDF           CDF            CDF_INV\n";

  cout << "\n";

  for ( i = 1; i <= 10; i++ )

  {

    x = truncated_normal_a_sample ( mu, s, a, seed );

    pdf = truncated_normal_a_pdf ( x, mu, s, a );

    cdf = truncated_normal_a_cdf ( x, mu, s, a );

    x2 = truncated_normal_a_cdf_inv ( cdf, mu, s, a );

    cout << "  " << setw(14) << x

         << "  " << setw(14) << pdf

         << "  " << setw(14) << cdf

         << "  " << setw(14) << x2 << "\n";

  }

  return;

}

void test08 ( )

{

  double a;

  int i;

  double mean;

  double mu;

  double s;

  int sample_num = 1000;

  int seed;

  double variance;

  double *x;

  double xmax;

  double xmin;

  a = 50.0;

  mu = 100.0;

  s = 25.0;

  seed = 123456789;

  cout << "\n";

  cout << "TEST08\n";

  cout << "  For the Lower Truncated Normal PDF:\n";

  cout << "  TRUNCATED_NORMAL_A_MEAN computes the mean;\n";

  cout << "  TRUNCATED_NORMAL_A_SAMPLE samples;\n";

  cout << "  TRUNCATED_NORMAL_A_VARIANCE computes the variance.\n";

  cout << "\n";

  cout << "  The parent normal distribution has\n";

  cout << "    mean =               " << mu << "\n";

  cout << "    standard deviation = " << s << "\n";

  cout << "  The parent distribution is truncated to\n";

  cout << "  the interval [" << a << ",+oo]\n";

  mean = truncated_normal_a_mean ( mu, s, a );

  variance = truncated_normal_a_variance ( mu, s, a );

  cout << "\n";

  cout << "  PDF mean      =               " << mean << "\n";

  cout << "  PDF variance =                " << variance << "\n";

  x = ( double * ) malloc ( sample_num * sizeof ( double ) );

  for ( i = 0; i < sample_num; i++ )

  {

    x[i] = truncated_normal_a_sample ( mu, s, a, seed );

  }

  mean = r8vec_mean ( sample_num, x );

  variance = r8vec_variance ( sample_num, x );

  xmax = r8vec_max ( sample_num, x );

  xmin = r8vec_min ( sample_num, x );

  cout << "\n";

  cout << "  Sample size =     " << sample_num << "\n";

  cout << "  Sample mean =     " << mean << "\n";

  cout << "  Sample variance = " << variance << "\n";

  cout << "  Sample maximum =  " << xmax << "\n";

  cout << "  Sample minimum =  " << xmin << "\n";

  delete [] x;

  return;

}

void test09 ( )

{

  double b;

  double cdf;

  int i;

  double mu;

  double pdf;

  double s;

  int seed;

  double x;

  double x2;

  b = 150.0;

  mu = 100.0;

  s = 25.0;

  seed = 123456789;

  cout << "\n";

  cout << "TEST09\n";

  cout << "  For the Upper Truncated Normal PDF:\n";

  cout << "  TRUNCATED_NORMAL_B_CDF evaluates the CDF.\n";

  cout << "  TRUNCATED_NORMAL_B_CDF_INV inverts the CDF.\n";

  cout << "  TRUNCATED_NORMAL_B_PDF evaluates the PDF.\n";

  cout << "\n";

  cout << "  The parent normal distribution has\n";

  cout << "    mean =               " << mu << "\n";

  cout << "    standard deviation = " << s << "\n";

  cout << "  The parent distribution is truncated to\n";

  cout << "  the interval [-oo," << b << "]\n";

  cout << "\n";

  cout << "       X            PDF           CDF            CDF_INV\n";

  cout << "\n";

  for ( i = 1; i <= 10; i++ )

  {

    x = truncated_normal_b_sample ( mu, s, b, seed );

    pdf = truncated_normal_b_pdf ( x, mu, s, b );

    cdf = truncated_normal_b_cdf ( x, mu, s, b );

    x2 = truncated_normal_b_cdf_inv ( cdf, mu, s, b );

    cout << "  " << setw(14) << x

         << "  " << setw(14) << pdf

         << "  " << setw(14) << cdf

         << "  " << setw(14) << x2 << "\n";

  }

  return;

}

void test10 ( )

{

  double b;

  int i;

  double mean;

  double mu;

  double s;

  int sample_num = 1000;

  int seed;

  double variance;

  double *x;

  double xmax;

  double xmin;

  b = 150.0;

  mu = 100.0;

  s = 25.0;

  seed = 123456789;

  cout << "\n";

  cout << "TEST10\n";

  cout << "  For the Upper Truncated Normal PDF:\n";

  cout << "  TRUNCATED_NORMAL_B_MEAN computes the mean;\n";

  cout << "  TRUNCATED_NORMAL_B_SAMPLE samples;\n";

  cout << "  TRUNCATED_NORMAL_B_VARIANCE computes the variance.\n";

  cout << "\n";

  cout << "  The parent normal distribution has\n";

  cout << "    mean =               " << mu << "\n";

  cout << "    standard deviation = " << s << "\n";

  cout << "  The parent distribution is truncated to\n";

  cout << "  the interval [-oo," << b << "]\n";

  mean = truncated_normal_b_mean ( mu, s, b );

  variance = truncated_normal_b_variance ( mu, s, b );

  cout << "\n";

  cout << "  PDF mean      =               " << mean << "\n";

  cout << "  PDF variance =                " << variance << "\n";

  x = ( double * ) malloc ( sample_num * sizeof ( double ) );

  for ( i = 0; i < sample_num; i++ )

  {

    x[i] = truncated_normal_b_sample ( mu, s, b, seed );

  }

  mean = r8vec_mean ( sample_num, x );

  variance = r8vec_variance ( sample_num, x );

  xmax = r8vec_max ( sample_num, x );

  xmin = r8vec_min ( sample_num, x );

  cout << "\n";

  cout << "  Sample size =     " << sample_num << "\n";

  cout << "  Sample mean =     " << mean << "\n";

  cout << "  Sample variance = " << variance << "\n";

  cout << "  Sample maximum =  " << xmax << "\n";

  cout << "  Sample minimum =  " << xmin << "\n";

  delete [] x;

  return;

}

void test11 ( )

{

  double moment;

  int order;

  cout << "\n";

  cout << "TEST11\n";

  cout << "  For the Normal 01 PDF:\n";

  cout << "  NORMAL_01_MOMENT evaluates the moments.\n";

  cout << "\n";

  cout << " Order  Moment\n";

  cout << "\n";

  for ( order = 0; order <= 10; order++ )

  {

    moment = normal_01_moment ( order );

    cout << "  " << setw(2) << order

         << "  " << setw(14) << moment << "\n";

  }

  return;

}

void test12 ( )

{

  double moment1;

  double moment2;

  double mu;

  double mu_test[4] = { 0.0, 2.0, 10.0, 0.0 };

  int order;

  double sigma;

  double sigma_test[4] = { 1.0, 1.0, 2.0, 2.0 };

  int test;

  int test_num = 4;

 

  cout << "\n";

  cout << "TEST12\n";

  cout << "  For the Normal PDF:\n";

  cout << "  NORMAL_MOMENT evaluates the moments.\n";

  cout << "  NORMAL_MOMENT_VALUES evaluates moments 0 through 8.\n";

  for ( test = 0; test < test_num; test++ )

  {

    mu = mu_test[test];

    sigma = sigma_test[test];

    cout << "\n";

    cout << "  Mu = " << mu

         << "  Sigma = " << sigma << "\n";

    cout << " Order  Moment\n";

    cout << "\n";

    for ( order = 0; order <= 8; order++ )

    {

      moment1 = normal_moment ( order, mu, sigma );

      moment2 = normal_moment_values ( order, mu, sigma );

      cout << "  " << setw(2) << order

           << "  " << setw(14) << moment1 

           << "  " << setw(14) << moment2 << "\n";

    }

  }

  return;

}

void test13 ( )

{

  double moment1;

  double moment2;

  double mu;

  double mu_test[4] = { 0.0, 2.0, 10.0, 0.0 };

  int order;

  double sigma;

  double sigma_test[4] = { 1.0, 1.0, 2.0, 2.0 };

  int test;

  int test_num = 4;

 

  cout << "\n";

  cout << "TEST13\n";

  cout << "  For the Normal PDF:\n";

  cout << "  NORMAL_MOMENT_CENTRAL evaluates the central moments.\n";

  cout << "  NORMAL_MOMENT_CENTRAL_VALUES evaluates moments 0 through 8.\n";

  for ( test = 0; test < test_num; test++ )

  {

    mu = mu_test[test];

    sigma = sigma_test[test];

    cout << "\n";

    cout << "  Mu = " << mu

         << "  Sigma = " << sigma << "\n";

    cout << " Order  Moment\n";

    cout << "\n";

    for ( order = 0; order <= 8; order++ )

    {

      moment1 = normal_moment_central ( order, mu, sigma );

      moment2 = normal_moment_central_values ( order, mu, sigma );

      cout << "  " << setw(2) << order

           << "  " << setw(14) << moment1 

           << "  " << setw(14) << moment2 << "\n";

    }

  }

  return;

}

void test14 ( )

{

  double b;

  double b_test[6] = {

    0.0, 10.0, -10.0, 10.0, -10.0, 10.0 };

  double moment;

  double mu;

  double mu_test[6] = {

    0.0,  0.0,  0.0,  0.0, 0.0, 5.0 };

  int order;

  double sigma;

  double sigma_test[6] = {

    1.0,  1.0,  1.0, 2.0, 2.0, 1.0 };

  int test;

  int test_num;

  test_num = 6;

 

  cout << "\n";

  cout << "TEST14\n";

  cout << "  For the Upper Truncated Normal PDF:\n";

  cout << "  TRUNCATED_NORMAL_B_MOMENT evaluates the moments.\n";

  for ( test = 0; test < test_num; test++ )

  {

    mu = mu_test[test];

    sigma = sigma_test[test];

    b = b_test[test];

    cout << "\n";

    cout << "  Test = " << test 

         << ", Mu = " << mu 

         << ", Sigma = " << sigma 

         << ", B = " << b << "\n";

    cout << " Order  Moment\n";

    cout << "\n";

    for ( order = 0; order <= 8; order++ )

    {

      moment = truncated_normal_b_moment ( order, mu, sigma, b );

      cout << "  " << setw(2) << order

           << "  " << setw(14) << moment << "\n";

    }

  }

  return;

}

void test15 ( )

{

  double a;

  double a_test[6] = {

    0.0, -10.0, 10.0, -10.0, 10.0, -10.0 };

  double moment;

  double mu;

  double mu_test[6] = {

    0.0,  0.0,  0.0,  0.0, 0.0, -5.0 };

  int order;

  double sigma;

  double sigma_test[6] = {

    1.0,  1.0,  1.0, 2.0, 2.0, 1.0 };

  int test;

  int test_num;

  test_num = 6;

 

  cout << "\n";

  cout << "TEST15\n";

  cout << "  For the Lower Truncated Normal PDF:\n";

  cout << "  TRUNCATED_NORMAL_A_MOMENT evaluates the moments.\n";

  for ( test = 0; test < test_num; test++ )

  {

    mu = mu_test[test];

    sigma = sigma_test[test];

    a = a_test[test];

    cout << "\n";

    cout << "  Test = " << test 

         << ", Mu = " << mu 

         << ", Sigma = " << sigma 

         << ", A = " << a << "\n";

    cout << " Order  Moment\n";

    cout << "\n";

    for ( order = 0; order <= 8; order++ )

    {

      moment = truncated_normal_a_moment ( order, mu, sigma, a );

      cout << "  " << setw(2) << order

           << "  " << setw(14) << moment << "\n";

    }

  }

  return;

}

void test16 ( )

{

  double a;

  double a_test[9] = {

    -1.0, 0.0, -1.0, -1.0,  0.0, 0.5, -2.0, -4.0, 4.0  };

  double b;

  double b_test[9] = {

    1.0, 1.0,  0.0,  1.0,  2.0, 2.0,  2.0,  4.0, 7.0 };

  double moment;

  double mu;

  double mu_test[9] = {

    0.0, 0.0,  0.0,  0.0,  1.0, 0.0,  0.0,  0.0, 5.0 };

  int order;

  double sigma;

  double sigma_test[9] = {

    1.0, 1.0,  1.0,  2.0,  1.0, 1.0,  1.0,  1.0, 0.5 };

  int test;

  int test_num;

  test_num = 9;

 

  cout << "\n";

  cout << "TEST16\n";

  cout << "  For the Truncated Normal PDF:\n";

  cout << "  TRUNCATED_NORMAL_AB_MOMENT evaluates the moments.\n";

  for ( test = 0; test < test_num; test++ )

  {

    mu = mu_test[test];

    sigma = sigma_test[test];

    a = a_test[test];

    b = b_test[test];

    cout << "\n";

    cout << "  Test = " << test 

         << ", Mu = " << mu 

         << ", Sigma = " << sigma 

         << ", A = " << a

         << ", B = " << b << "\n";

    cout << " Order  Moment\n";

    cout << "\n";

    for ( order = 0; order <= 8; order++ )

    {

      moment = truncated_normal_ab_moment ( order, mu, sigma, a, b );

      cout << "  " << setw(2) << order

           << "  " << setw(14) << moment << "\n";

    }

  }

  return;

}

void test17 ( void )

{

  double a;

  double b;

  double cdf1;

  double cdf2;

  double mu;

  int n_data;

  double s;

  double x;

  cout << "\n";

  cout << "TEST17:\n";

  cout << "  TRUNCATED_NORMAL_AB_CDF_VALUES stores values of\n";

  cout << "  the Truncated Normal Cumulative Density Function.\n";

  cout << "  TRUNCATED_NORMAL_AB_CDF evaluates\n";

  cout << "  the Truncated Normal Cumulative Density Function.\n";

  cout << "\n";

  cout << "        MU       S         A         B         X        CDF1           CDF2\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    truncated_normal_ab_cdf_values ( n_data, mu, s, a, b, x, cdf1 );

    if ( n_data == 0 )

    {

      break;

    }

    cdf2 = truncated_normal_ab_cdf ( x, mu, s, a, b );

    cout << "  " << setw(8) << mu

         << "  " << setw(8) << s

         << "  " << setw(8) << a

         << "  " << setw(8) << b

         << "  " << setw(8) << x

         << "  " << setprecision(16) << setw(24) << cdf1

         << "  " << setprecision(16) << setw(24) << cdf2 << "\n";

  }

  return;

}

void test18 ( )

{

  double a;

  double b;

  double mu;

  int n_data;

  double pdf1;

  double pdf2;

  double s;

  double x;

  cout << "\n";

  cout << "TEST18:\n";

  cout << "  TRUNCATED_NORMAL_AB_PDF_VALUES stores values of\n";

  cout << "  the Truncated Normal Probability Density Function.\n";

  cout << "  TRUNCATED_NORMAL_AB_PDF evaluates\n";

  cout << "  the Truncated Normal Probability Density Function.\n";

  cout << "\n";

  cout << "        MU       S         A         B         X        PDF1        PDF2\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    truncated_normal_ab_pdf_values ( n_data, mu, s, a, b, x, pdf1 );

    if ( n_data == 0 )

    {

      break;

    }

    pdf2 = truncated_normal_ab_pdf ( x, mu, s, a, b );

   cout << "  " << setw(8) << mu

         << "  " << setw(8) << s

         << "  " << setw(8) << a

         << "  " << setw(8) << b

         << "  " << setw(8) << x

         << "  " << setprecision(16) << setw(24) << pdf1

         << "  " << setprecision(16)<< setw(24) << pdf2 << "\n";

  }

  return;

}

void test19 ( void )

{

  double a;

  double cdf1;

  double cdf2;

  double mu;

  int n_data;

  double s;

  double x;

  cout << "\n";

  cout << "TEST19:\n";

  cout << "  TRUNCATED_NORMAL_A_CDF_VALUES stores values of\n";

  cout << "  the lower Truncated Normal Cumulative Density Function.\n";

  cout << "  TRUNCATED_NORMAL_A_CDF evaluates\n";

  cout << "  the lower Truncated Normal Cumulative Density Function.\n";

  cout << "\n";

  cout << "        MU       S         A         X        CDF1           CDF2\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    truncated_normal_a_cdf_values ( n_data, mu, s, a, x, cdf1 );

    if ( n_data == 0 )

    {

      break;

    }

    cdf2 = truncated_normal_a_cdf ( x, mu, s, a );

    cout << "  " << setw(8) << mu

         << "  " << setw(8) << s

         << "  " << setw(8) << a

         << "  " << setw(8) << x

         << "  " << setprecision(16) << setw(24) << cdf1

         << "  " << setprecision(16) << setw(24) << cdf2 << "\n";

  }

  return;

}

void test20 ( )

{

  double a;

  double mu;

  int n_data;

  double pdf1;

  double pdf2;

  double s;

  double x;

  cout << "\n";

  cout << "TEST20:\n";

  cout << "  TRUNCATED_NORMAL_A_PDF_VALUES stores values of\n";

  cout << "  the lower Truncated Normal Probability Density Function.\n";

  cout << "  TRUNCATED_NORMAL_A_PDF evaluates\n";

  cout << "  the lower Truncated Normal Probability Density Function.\n";

  cout << "\n";

  cout << "        MU       S         A         X        PDF1        PDF2\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    truncated_normal_a_pdf_values ( n_data, mu, s, a, x, pdf1 );

    if ( n_data == 0 )

    {

      break;

    }

    pdf2 = truncated_normal_a_pdf ( x, mu, s, a );

   cout << "  " << setw(8) << mu

         << "  " << setw(8) << s

         << "  " << setw(8) << a

         << "  " << setw(8) << x

         << "  " << setprecision(16) << setw(24) << pdf1

         << "  " << setprecision(16)<< setw(24) << pdf2 << "\n";

  }

  return;

}

void test21 ( void )

{

  double b;

  double cdf1;

  double cdf2;

  double mu;

  int n_data;

  double s;

  double x;

  cout << "\n";

  cout << "TEST21:\n";

  cout << "  TRUNCATED_NORMAL_B_CDF_VALUES stores values of\n";

  cout << "  the upper Truncated Normal Cumulative Density Function.\n";

  cout << "  TRUNCATED_NORMAL_B_CDF evaluates\n";

  cout << "  the upper Truncated Normal Cumulative Density Function.\n";

  cout << "\n";

  cout << "        MU       S         B         X        CDF1           CDF2\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    truncated_normal_b_cdf_values ( n_data, mu, s, b, x, cdf1 );

    if ( n_data == 0 )

    {

      break;

    }

    cdf2 = truncated_normal_b_cdf ( x, mu, s, b );

    cout << "  " << setw(8) << mu

         << "  " << setw(8) << s

         << "  " << setw(8) << b

         << "  " << setw(8) << x

         << "  " << setprecision(16) << setw(24) << cdf1

         << "  " << setprecision(16) << setw(24) << cdf2 << "\n";

  }

  return;

}

void test22 ( )

{

  double b;

  double mu;

  int n_data;

  double pdf1;

  double pdf2;

  double s;

  double x;

  cout << "\n";

  cout << "TEST22:\n";

  cout << "  TRUNCATED_NORMAL_B_PDF_VALUES stores values of\n";

  cout << "  the upper Truncated Normal Probability Density Function.\n";

  cout << "  TRUNCATED_NORMAL_B_PDF evaluates\n";

  cout << "  the upper Truncated Normal Probability Density Function.\n";

  cout << "\n";

  cout << "        MU       S         B         X        PDF1        PDF2\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    truncated_normal_b_pdf_values ( n_data, mu, s, b, x, pdf1 );

    if ( n_data == 0 )

    {

      break;

    }

    pdf2 = truncated_normal_b_pdf ( x, mu, s, b );

   cout << "  " << setw(8) << mu

         << "  " << setw(8) << s

         << "  " << setw(8) << b

         << "  " << setw(8) << x

         << "  " << setprecision(16) << setw(24) << pdf1

         << "  " << setprecision(16)<< setw(24) << pdf2 << "\n";

  }

  return;

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/