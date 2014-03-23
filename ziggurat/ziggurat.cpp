
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <cmath>

# include <ctime>

# include <stdint.h>

using namespace std;

# include "ziggurat.hpp"

uint32_t cong_seeded ( uint32_t &jcong )

{

  uint32_t value;

  jcong = 69069 * ( jcong ) + 1234567;

  value = jcong;

  return value;

}

double cpu_time ( )

{

  double value;

  value = ( double ) clock ( ) / ( double ) CLOCKS_PER_SEC;

  return value;

}

uint32_t kiss_seeded ( uint32_t &jcong, uint32_t &jsr, uint32_t &w, uint32_t &z )

{

  uint32_t value;

  value = ( mwc_seeded ( w, z ) ^ cong_seeded ( jcong ) ) + shr3_seeded ( jsr );

  return value;

}

uint32_t mwc_seeded ( uint32_t &w, uint32_t &z )

{

  uint32_t value;

  z = 36969 * ( z & 65535 ) + ( z >> 16 );

  w = 18000 * ( w & 65535 ) + ( w >> 16 );

  value = ( z << 16 ) + w;

  return value;

}

float r4_exp ( uint32_t &jsr, uint32_t ke[256], float fe[256], float we[256] )

{

  uint32_t iz;

  uint32_t jz;

  float value;

  float x;

  jz = shr3_seeded ( jsr );

  iz = ( jz & 255 );

  if ( jz < ke[iz] )

  {

    value = ( float ) ( jz ) * we[iz];

  }

  else

  {

    for ( ; ; )

    {

      if ( iz == 0 )

      {

        value = 7.69711 - log ( r4_uni ( jsr ) );

        break;

      }

      x = ( float ) ( jz ) * we[iz];

      if ( fe[iz] + r4_uni ( jsr ) * ( fe[iz-1] - fe[iz] ) < exp ( - x ) )

      {

        value = x;

        break;

      }

      jz = shr3_seeded ( jsr );

      iz = ( jz & 255 );

      if ( jz < ke[iz] )

      {

        value = ( float ) ( jz ) * we[iz];

        break;

      }

    }

  }

  return value;

}

void r4_exp_setup ( uint32_t ke[256], float fe[256], float we[256] )

{

  double de = 7.697117470131487;

  int i;

  const double m2 = 2147483648.0;

  double q;

  double te = 7.697117470131487;

  const double ve = 3.949659822581572E-03;

  q = ve / exp ( - de );

  ke[0] = ( uint32_t ) ( ( de / q ) * m2 );

  ke[1] = 0;

  we[0] = ( float ) ( q / m2 );

  we[255] = ( float ) ( de / m2 );

  fe[0] = 1.0;

  fe[255] = ( float ) ( exp ( - de ) );

  for ( i = 254; 1 <= i; i-- )

  {

    de = - log ( ve / de + exp ( - de ) );

    ke[i+1] = ( uint32_t ) ( ( de / te ) * m2 );

    te = de;

    fe[i] = ( float ) ( exp ( - de ) );

    we[i] = ( float ) ( de / m2 );

  }

  return;

}

float r4_nor ( uint32_t &jsr, uint32_t kn[128], float fn[128], float wn[128] )

{

  int hz;

  uint32_t iz;

  const float r = 3.442620;

  float value;

  float x;

  float y;

  hz = ( int ) shr3_seeded ( jsr );

  iz = ( hz & 127 );

  if ( fabs ( hz ) < kn[iz] )

  {

    value = ( float ) ( hz ) * wn[iz];

  }

  else

  {

    for ( ; ; )

    {

      if ( iz == 0 )

      {

        for ( ; ; )

        {

          x = - 0.2904764 * log ( r4_uni ( jsr ) );

          y = - log ( r4_uni ( jsr ) );

          if ( x * x <= y + y );

          {

            break;

          }

        }

        if ( hz <= 0 )

        {

          value = - r - x;

        }

        else

        {

          value = + r + x;

        }

        break;

      }

      x = ( float ) ( hz ) * wn[iz];

      if ( fn[iz] + r4_uni ( jsr ) * ( fn[iz-1] - fn[iz] ) 

        < exp ( - 0.5 * x * x ) )

      {

        value = x;

        break;

      }

      hz = ( int ) shr3_seeded ( jsr );

      iz = ( hz & 127 );

      if ( fabs ( hz ) < kn[iz] )

      {

        value = ( float ) ( hz ) * wn[iz];

        break;

      }

    }

  }

  return value;

}

void r4_nor_setup ( uint32_t kn[128], float fn[128], float wn[128] )

{

  double dn = 3.442619855899;

  int i;

  const double m1 = 2147483648.0;

  double q;

  double tn = 3.442619855899;

  const double vn = 9.91256303526217E-03;

  q = vn / exp ( - 0.5 * dn * dn );

  kn[0] = ( uint32_t ) ( ( dn / q ) * m1 );

  kn[1] = 0;

  wn[0] = ( float ) ( q / m1 );

  wn[127] = ( float ) ( dn / m1 );

  fn[0] = 1.0;

  fn[127] = ( float ) ( exp ( - 0.5 * dn * dn ) );

  for ( i = 126; 1 <= i; i-- )

  {

    dn = sqrt ( - 2.0 * log ( vn / dn + exp ( - 0.5 * dn * dn ) ) );

    kn[i+1] = ( uint32_t ) ( ( dn / tn ) * m1 );

    tn = dn;

    fn[i] = ( float ) ( exp ( - 0.5 * dn * dn ) );

    wn[i] = ( float ) ( dn / m1 );

  }

  return;

}

float r4_uni ( uint32_t &jsr )

{

  uint32_t jsr_input;

  float value;

  jsr_input = jsr;

  jsr = ( jsr ^ ( jsr <<   13 ) );

  jsr = ( jsr ^ ( jsr >>   17 ) );

  jsr = ( jsr ^ ( jsr <<    5 ) );

  value = fmod ( 0.5 

    + ( float ) ( jsr_input + jsr ) / 65536.0 / 65536.0, 1.0 );

  return value;

}

uint32_t shr3_seeded ( uint32_t &jsr )

{

  uint32_t value;

  value = jsr;

  jsr = ( jsr ^ ( jsr <<   13 ) );

  jsr = ( jsr ^ ( jsr >>   17 ) );

  jsr = ( jsr ^ ( jsr <<    5 ) );

  value = value + jsr;

  return value;

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

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/