
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <cmath>

# include <ctime>

# include <complex>

# include <cstring>

using namespace std;

# include "test_zero.hpp"

int main ( )

{

  double fatol = 1.0E-06;

  double fx;

  double fxa;

  double fxb;

  double fxc;

  int i;

  int max_step = 25;

  int prob;

  int prob_num;

  double *range;

  int root_num;

  int start_num;

  string title;

  double x;

  double xa;

  double xatol = 1.0E-06;

  double xb;

  double xc;

  double xmax;

  double xmin;

  double xrtol = 1.0E-06;

  timestamp ( );

  cout << "\n";

  cout << "TEST_ZERO_PRB\n";

  cout << "  C++ version\n";

  cout << "  Test the TEST_ZERO library.\n";

  cout << "\n";

  cout << "  Function value tolerance = " << fatol << "\n";

  cout << "  Root absolute tolerance =  " << xatol << "\n";

  cout << "  Root relative tolerance =  " << xrtol << "\n";

  cout << "  Maximum number of steps =  " << max_step << "\n";

  prob_num = p00_prob_num ( );

  cout << "\n";

  cout << "  Number of problems available is " << prob_num << "\n";

  for ( prob = 1; prob <= prob_num; prob++ )

  {

    title = p00_title ( prob );

    cout << "\n";

    cout << "\n";

    cout << "  Problem number " << prob << "\n";

    cout << "  \"" << title << "\"\n";

    if ( prob == 16 )

    {

    }

    range = p00_range ( prob );

    xmin = range[0];

    xmax = range[1];

    cout << "  We seek roots between " << range[0] << " and " << range[1] << "\n";

    root_num = p00_root_num ( prob );

    cout << "\n";

    cout << "  Number of known roots = " << root_num << "\n";

    if ( 0 < root_num )

    {

      cout << "\n";

      cout << "     I          X          F(X)\n";

      cout << "\n";

      for ( i = 1; i <= root_num; i++ )

      {

        x = p00_root ( prob, i );

        fx = p00_fx ( prob, x );

        cout << "  " << setw(4) << i

             << "  " << setw(10) << x

             << "  " << setw(10) << fx << "\n";

      }

    }

    start_num = p00_start_num ( prob );

    cout << "\n";

    cout << "  Number of starting points = " << start_num << "\n";

    cout << "\n";

    cout << "     I          X          F(X)\n";

    cout << "\n";

    for ( i = 1; i <= start_num; i++ )

    {

      x = p00_start ( prob, i );

      fx = p00_fx ( prob, x );

      cout << "  " << setw(4) << i

           << "  " << setw(10) << x

           << "  " << setw(10) << fx << "\n";

    }

    xa = p00_start ( prob, 1 );

    fxa = p00_fx ( prob, xa );

    for ( i = 2; i <= start_num; i++ )

    {

      xb = p00_start ( prob, i );

      fxb = p00_fx ( prob, xb );

      if ( r8_sign ( fxa ) != r8_sign ( fxb ) )

      {

         bisection ( fatol, max_step, prob, xatol, &xa, &xb, &fxa, &fxb );

         break;

      }

    }

    xa = p00_start ( prob, 1 );

    fxa = p00_fx ( prob, xa );

    for ( i = 2; i <= start_num; i++ )

    {

      xb = p00_start ( prob, i );

      fxb = p00_fx ( prob, xb );

      if ( r8_sign ( fxa ) != r8_sign ( fxb ) )

      {

         brent ( fatol, max_step, prob, xatol, xrtol, &xa, &xb, &fxa, &fxb );

         break;

      }

    }

    if ( 3 <= p00_start_num ( prob ) )

    {

      xa = p00_start ( prob, 1 );

      fxa = p00_fx ( prob, xa );

      xb = p00_start ( prob, 2 );

      fxb = p00_fx ( prob, xb );

      xc = p00_start ( prob, 3 );

      fxc = p00_fx ( prob, xc );

      muller ( fatol, max_step, prob, xatol, xrtol, &xa, &xb, &xc, &fxa, &fxb, &fxc );

    }

    for ( i = 1; i <= start_num; i++ )

    {

      xa = p00_start ( prob, i );

      fxa = p00_fx ( prob, xa );

      newton ( fatol, max_step, prob, xatol, xmin, xmax, &xa, &fxa );

    }

    xa = p00_start ( prob, 1 );

    fxa = p00_fx ( prob, xa );

    for ( i = 2; i <= start_num; i++ )

    {

      xb = p00_start ( prob, i );

      fxb = p00_fx ( prob, xb );

      if ( r8_sign ( fxa ) != r8_sign ( fxb ) )

      {

         regula_falsi ( fatol, max_step, prob, xatol, &xa, &xb, &fxa, &fxb );

         break;

      }

    }

    for ( i = 1; i < start_num; i++ )

    {

      xa = p00_start ( prob, i );

      fxa = p00_fx ( prob, xa );

      xb = p00_start ( prob, i + 1 );

      fxb = p00_fx ( prob, xb );

      secant ( fatol, max_step, prob, xatol, xmin, xmax, &xa, &xb, &fxa, &fxb );

    }

    delete [] range;

  }

  cout << "\n";

  cout << "TEST_ZERO_PRB\n";

  cout << "  Normal end of execution.\n";

  cout << "\n";

  timestamp ( );

  return 0;

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/