
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <iostream>

# include <iomanip>

# include <cmath>

# include <complex>

# include <cstring>

using namespace std;

# include "test_values.hpp"

int main ( );

void test001 ( );

void test002 ( );

void test003 ( );

void test0035 ( );

void test004 ( );

void test005 ( );

void test006 ( );

void test007 ( );

void test008 ( );

void test009 ( );

void test0093 ( );

void test0095 ( );

void test010 ( );

void test011 ( );

void test0114 ( );

void test01145 ( );

void test0115 ( );

void test01155 ( );

void test0116 ( );

void test012 ( );

void test0123 ( );

void test0127 ( );

void test0128 ( );

void test013 ( );

void test0134 ( );

void test0135 ( );

void test014 ( );

void test015 ( );

void test016 ( );

void test017 ( );

void test018 ( );

void test0185 ( );

void test019 ( );

void test0195 ( );

void test020 ( );

void test0205 ( );

void test021 ( );

void test022 ( );

void test023 ( );

void test024 ( );

void test025 ( );

void test026 ( );

void test0265 ( );

void test027 ( );

void test028 ( );

void test029 ( );

void test030 ( );

void test0305 ( );

void test031 ( );

void test032 ( );

void test033 ( );

void test034 ( );

void test035 ( );

void test036 ( );

void test0365 ( );

void test037 ( );

void test038 ( );

void test039 ( );

void test0395 ( );

void test040 ( );

void test041 ( );

void test042 ( );

void test0425 ( );

void test043 ( );

void test044 ( );

void test0445 ( );

void test045 ( );

void test046 ( );

void test0465 ( );

void test047 ( );

void test048 ( );

void test049 ( );

void test050 ( );

void test051 ( );

void test05125 ( );

void test0515 ( );

void test0517 ( );

void test0519 ( );

void test052 ( );

void test053 ( );

void test054 ( );

void test055 ( );

void test056 ( );

void test057 ( );

void test0575 ( );

void test058 ( );

void test059 ( );

void test060 ( );

void test061 ( );

void test062 ( );

void test063 ( );

void test064 ( );

void test065 ( );

void test066 ( );

void test0665 ( );

void test067 ( );

void test068 ( );

void test0685 ( );

void test069 ( );

void test070 ( );

void test071 ( );

void test072 ( );

void test073 ( );

void test074 ( );

void test075 ( );

void test0755 ( );

void test0756 ( );

void test076 ( );

void test077 ( );

void test078 ( );

void test079 ( );

void test080 ( );

void test081 ( );

void test082 ( );

void test083 ( );

void test0835 ( );

void test084 ( );

void test0843 ( );

void test0845 ( );

void test085 ( );

void test0855 ( );

void test086 ( );

void test087 ( );

void test088 ( );

void test089 ( );

void test090 ( );

void test091 ( );

void test092 ( );

void test093 ( );

void test094 ( );

void test0945 ( );

void test095 ( );

void test096 ( );

void test097 ( );

void test0972 ( );

void test0973 ( );

void test0974 ( );

void test0975 ( );

void test098 ( );

void test099 ( );

void test0995 ( );

void test100 ( );

void test101 ( );

void test1015 ( );

void test1016 ( );

void test102 ( );

void test103 ( );

void test1035 ( );

void test1037 ( );

void test104 ( );

void test1045 ( );

void test105 ( );

void test106 ( );

void test107 ( );

void test108 ( );

void test10875 ( );

void test109 ( );

void test110 ( );

void test1105 ( );

void test111 ( );

void test112 ( );

void test113 ( );

void test1135 ( );

void test114 ( );

void test115 ( );

void test116 ( );

void test117 ( );

void test118 ( );

void test1185 ( );

void test119 ( );

void test120 ( );

void test121 ( );

void test122 ( );

void test123 ( );

void test124 ( );

void test125 ( );

void test1255 ( );

void test126 ( );

void test127 ( );

void test1275 ( );

void test128 ( );

void test1283 ( );

void test1285 ( );

void test129 ( );

void test131 ( );

void test132 ( );

void test1325 ( );

void test130 ( );

void test133 ( );

void test134 ( );

void test135 ( );

void test136 ( );

void test137 ( );

void test138 ( );

void test139 ( );

void test140 ( );

void test141 ( );

void test1415 ( );

void test142 ( );

void test143 ( );

void test144 ( );

void test1445 ( );

void test1447 ( );

void test145 ( );

void test146 ( );

void test1465 ( );

void test147 ( );

void test148 ( );

void test149 ( );

void test150 ( );

void test151 ( );

void test152 ( );

void test153 ( );

void test154 ( );

void test1545 ( );

void test1546 ( );

void test1547 ( );

void test1548 ( );

void test15485 ( );

void test1549 ( );

void test15495 ( );

void test155 ( );

void test156 ( );

void test157 ( );

void test1575 ( );

void test158 ( );

void test159 ( );

int main ( )

{

  timestamp ( );

  cout << "\n";

  cout << "TEST_VALUES_PRB:\n";

  cout << "  C++ version,\n";

  cout << "  Test the TEST_VALUES library.\n";

  test001 ( );

  test002 ( );

  test003 ( );

  test0035 ( );

  test004 ( );

  test005 ( );

  test006 ( );

  test007 ( );

  test008 ( );

  test009 ( );

  test0093 ( );

  test0095 ( );

  test010 ( );

  test011 ( );

  test0114 ( );

  test01145 ( );

  test0115 ( );

  test01155 ( );

  test0116 ( );

  test012 ( );

  test0123 ( );

  test0127 ( );

  test0128 ( );

  test013 ( );

  test0134 ( );

  test0135 ( );

  test014 ( );

  test015 ( );

  test016 ( );

  test017 ( );

  test018 ( );

  test0185 ( );

  test019 ( );

  test0195 ( );

  test020 ( );

  test0205 ( );

  test021 ( );

  test022 ( );

  test023 ( );

  test024 ( );

  test025 ( );

  test026 ( );

  test0265 ( );

  test027 ( );

  test028 ( );

  test029 ( );

  test030 ( );

  test0305 ( );

  test031 ( );

  test032 ( );

  test033 ( );

  test034 ( );

  test035 ( );

  test036 ( );

  test0365 ( );

  test037 ( );

  test038 ( );

  test039 ( );

  test0395 ( );

  test040 ( );

  test041 ( );

  test042 ( );

  test0425 ( );

  test043 ( );

  test044 ( );

  test0445 ( );

  test045 ( );

  test046 ( );

  test0465 ( );

  test047 ( );

  test048 ( );

  test049 ( );

  test050 ( );

  test051 ( );

  test05125 ( );

  test0515 ( );

  test0517 ( );

  test0519 ( );

  test052 ( );

  test053 ( );

  test054 ( );

  test055 ( );

  test056 ( );

  test057 ( );

  test0575 ( );

  test058 ( );

  test059 ( );

  test060 ( );

  test061 ( );

  test062 ( );

  test063 ( );

  test064 ( );

  test065 ( );

  test066 ( );

  test0665 ( );

  test067 ( );

  test068 ( );

  test0685 ( );

  test069 ( );

  test070 ( );

  test071 ( );

  test072 ( );

  test073 ( );

  test074 ( );

  test075 ( );

  test0755 ( );

  test0756 ( );

  test076 ( );

  test077 ( );

  test078 ( );

  test079 ( );

  test080 ( );

  test081 ( );

  test082 ( );

  test083 ( );

  test0835 ( );

  test084 ( );

  test0843 ( );

  test0845 ( );

  test085 ( );

  test0855 ( );

  test086 ( );

  test087 ( );

  test088 ( );

  test089 ( );

  test090 ( );

  test091 ( );

  test092 ( );

  test093 ( );

  test094 ( );

  test0945 ( );

  test095 ( );

  test096 ( );

  test097 ( );

  test0972 ( );

  test0973 ( );

  test0974 ( );

  test0975 ( );

  test098 ( );

  test099 ( );

  test0995 ( );

  test100 ( );

  test101 ( );

  test1015 ( );

  test1016 ( );

  test102 ( );

  test103 ( );

  test1035 ( );

  test104 ( );

  test1045 ( );

  test1037 ( );

  test105 ( );

  test106 ( );

  test107 ( );

  test108 ( );

  test10875 ( );

  test109 ( );

  test110 ( );

  test1105 ( );

  test111 ( );

  test112 ( );

  test113 ( );

  test1135 ( );

  test114 ( );

  test115 ( );

  test116 ( );

  test117 ( );

  test118 ( );

  test1185 ( );

  test119 ( );

  test120 ( );

  test121 ( );

  test122 ( );

  test123 ( );

  test124 ( );

  test125 ( );

  test1255 ( );

  test126 ( );

  test127 ( );

  test1275 ( );

  test128 ( );

  test1283 ( );

  test1285 ( );

  test129 ( );

  test131 ( );

  test132 ( );

  test1325 ( );

  test130 ( );

  test133 ( );

  test134 ( );

  test135 ( );

  test136 ( );

  test137 ( );

  test138 ( );

  test139 ( );

  test140 ( );

  test141 ( );

  test1415 ( );

  test142 ( );

  test143 ( );

  test144 ( );

  test1445 ( );

  test1447 ( );

  test145 ( );

  test146 ( );

  test1465 ( );

  test147 ( );

  test148 ( );

  test149 ( );

  test150 ( );

  test151 ( );

  test152 ( );

  test153 ( );

  test154 ( );

  test1545 ( );

  test1546 ( );

  test1547 ( );

  test1548 ( );

  test15485 ( );

  test1549 ( );

  test15495 ( );

  test155 ( );

  test156 ( );

  test157 ( );

  test1575 ( );

  test158 ( );

  test159 ( );

  cout << "\n";

  cout << "TEST_VALUES_PRB:\n";

  cout << "  Normal end of execution.\n";

  cout << "\n";

  timestamp ( );

  return 0;

}

void test001 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST001:\n";

  cout << "  ABRAM0_VALUES stores values of \n";

  cout << "  the Abramowitz function of order 0.\n";

  cout << "\n";

  cout << "                X                   ABRAM0(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    abram0_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test002 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST002:\n";

  cout << "  ABRAM1_VALUES stores values of \n";

  cout << "  the Abramowitz function of order 1.\n";

  cout << "\n";

  cout << "                X                   ABRAM1(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    abram1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test003 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST003:\n";

  cout << "  ABRAM2_VALUES stores values of \n";

  cout << "  the Abramowitz function of order 2.\n";

  cout << "\n";

  cout << "                X                   ABRAM3(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    abram2_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test0035 ( )

{

  double a;

  double b;

  double fx;

  int n_data;

  cout << "\n";

  cout << "TEST0035:\n";

  cout << "  AGM_VALUES stores values of \n";

  cout << "  the arithmetic geometric mean function.\n";

  cout << "\n";

  cout << "           A          B              AGM(A,B)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    agm_values ( n_data, a, b, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(14) << setprecision (  6 ) << a  << "  "

         << setw(14) << setprecision (  6 ) << b  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test004 ( )

{

  double ai;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST004:\n";

  cout << "  AIRY_AI_VALUES stores values of \n";

  cout << "  the Airy functions Ai(X).\n";

  cout << "\n";

  cout << "                X                     Ai(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    airy_ai_values ( n_data, x, ai );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << ai << "\n";

  }

  return;

}

void test005 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST005:\n";

  cout << "  AIRY_AI_INT_VALUES stores values of \n";

  cout << "  the integral of the Airy Ai function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    airy_ai_int_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test006 ( )

{

  double aip;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST006:\n";

  cout << "  AIRY_AI_PRIME_VALUES stores values of \n";

  cout << "  the derivative of the Airy function Ai'(X).\n";

  cout << "\n";

  cout << "                X                    Ai'\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    airy_ai_prime_values ( n_data, x, aip );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                           << "  "

         << setw(24) << setprecision ( 16 ) << x   << "  "

         << setw(24) << setprecision ( 16 ) << aip << "\n";

  }

  return;

}

void test007 ( )

{

  double bi;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST007:\n";

  cout << "  AIRY_BI_VALUES stores values of \n";

  cout << "  the Airy function Bi.\n";

  cout << "\n";

  cout << "                X                     Bi\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    airy_bi_values ( n_data, x, bi );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << bi << "\n";

  }

  return;

}

void test008 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST008:\n";

  cout << "  AIRY_BI_INT_VALUES stores values of \n";

  cout << "  the integral of the Airy Bi function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    airy_bi_int_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test009 ( )

{

  double bip;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST009:\n";

  cout << "  AIRY_BI_PRIME_VALUES stores values of \n";

  cout << "  the derivative of Airy function Bi'(X).\n";

  cout << "\n";

  cout << "                X                     Bi'\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    airy_bi_prime_values ( n_data, x, bip );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                           << "  "

         << setw(24) << setprecision ( 16 ) << x   << "  "

         << setw(24) << setprecision ( 16 ) << bip << "\n";

  }

  return;

}

void test0093 ( )

{

  complex <double> cai;

  int n_data;

  complex <double> x;

  cout << "\n";

  cout << "TEST0093:\n";

  cout << "  AIRY_CAI_VALUES stores values of \n";

  cout << "  the Airy functions Ai(X) for complex argument.\n";

  cout << "\n";

  cout << "                X                     Ai\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    airy_cai_values ( n_data, x, cai );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                                   << "  "

         << setw(14) << setprecision ( 6 ) << real ( x )   << "  "

         << setw(14) << setprecision ( 6 ) << imag ( x )   << "  "

         << setw(24) << setprecision (16 ) << real ( cai ) << "  "

         << setw(24) << setprecision (16 ) << imag ( cai ) << "\n";

  }

  return;

}

void test0095 ( )

{

  complex <double> cbi;

  int n_data;

  complex <double> x;

  cout << "\n";

  cout << "TEST0095:\n";

  cout << "  AIRY_CBI_VALUES stores values of \n";

  cout << "  the Airy functions Bi(X) for complex argument.\n";

  cout << "\n";

  cout << "                X                     Bi\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    airy_cbi_values ( n_data, x, cbi );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                                   << "  "

         << setw(14) << setprecision ( 6 ) << real ( x )   << "  "

         << setw(14) << setprecision ( 6 ) << imag ( x )   << "  "

         << setw(24) << setprecision (16 ) << real ( cbi ) << "  "

         << setw(24) << setprecision (16 ) << imag ( cbi ) << "\n";

  }

  return;

}

void test010 ( )

{

  double bip;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST010:\n";

  cout << "  AIRY_GI_VALUES stores values of \n";

  cout << "  the modified Airy function Gi(X).\n";

  cout << "\n";

  cout << "                X                     Gi\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    airy_gi_values ( n_data, x, bip );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                           << "  "

         << setw(24) << setprecision ( 16 ) << x   << "  "

         << setw(24) << setprecision ( 16 ) << bip << "\n";

  }

  return;

}

void test011 ( )

{

  double bip;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST011:\n";

  cout << "  AIRY_HI_VALUES stores values of \n";

  cout << "  the modified Airy function Hi(X).\n";

  cout << "\n";

  cout << "                X                     Hi\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    airy_hi_values ( n_data, x, bip );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                           << "  "

         << setw(24) << setprecision ( 16 ) << x   << "  "

         << setw(24) << setprecision ( 16 ) << bip << "\n";

  }

  return;

}

void test0114 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0114:\n";

  cout << "  ARCCOS_VALUES stores values of the arc cosine function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    arccos_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test01145 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST01145:\n";

  cout << 

    "  ARCCOSH_VALUES stores values of the hyperbolic arc cosine function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    arccosh_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test0115 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0115:\n";

  cout << "  ARCSIN_VALUES stores values of the arc sine function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    arcsin_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test01155 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST01155:\n";

  cout << 

    "  ARCSINH_VALUES stores values of the hyperbolic arc sine function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    arcsinh_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test0116 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0116:\n";

  cout << "  ARCTAN_VALUES stores values of the arc tangent function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    arctan_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test012 ( )

{

  double bip;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST012:\n";

  cout << "  ARCTAN_INT_VALUES stores values of \n";

  cout << "  the arctangent integral.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    arctan_int_values ( n_data, x, bip );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                           << "  "

         << setw(24) << setprecision ( 16 ) << x   << "  "

         << setw(24) << setprecision ( 16 ) << bip << "\n";

  }

  return;

}

void test0123 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0123:\n";

  cout << 

    "  ARCTANH_VALUES stores values of the hyperbolic arc tangent function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    arctanh_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test0127 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0127:\n";

  cout << "  BEI0_VALUES stores values of \n";

  cout << "  the Kelvin function BEI of order 0.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bei0_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test0128 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0128:\n";

  cout << "  BEI1_VALUES stores values of \n";

  cout << "  the Kelvin function BEI of order 1.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bei1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test013 ( )

{

  int c;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST013:\n";

  cout << "  BELL_VALUES returns values of \n";

  cout << "  the Bell numbers.\n";

  cout << "\n";

  cout << "     N        BELL(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bell_values ( n_data, n, c );

    if ( n_data == 0 )

    {

      break;

    }

    cout                  << "  "

         << setw(6)  << n << "  "

         << setw(10) << c << "\n";

  }

  return;

}

void test0134 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0134:\n";

  cout << "  BER0_VALUES stores values of \n";

  cout << "  the Kelvin function BER of order 0.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    ber0_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test0135 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0135:\n";

  cout << "  BER1_VALUES stores values of \n";

  cout << "  the Kelvin function BER of order 1.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    ber1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test014 ( )

{

  double c;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST014:\n";

  cout << "  BERNOULLI_NUMBER_VALUES returns values of \n";

  cout << "  the Bernoulli numbers.\n";

  cout << "\n";

  cout << "     N              B(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bernoulli_number_values ( n_data, n, c );

    if ( n_data == 0 )

    {

      break;

    }

    cout                  << "  "

         << setw(6)  << n << "  "

         << setw(12) << c << "\n";

  }

  return;

}

void test015 ( )

{

  double b;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST015:\n";

  cout << "  BERNOULLI_POLY_VALUES returns values of \n";

  cout << "  the Bernoulli Polynomials.\n";

  cout << "\n";

  cout << "     N     X      BERNOULLI(N)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bernoulli_poly_values ( n_data, n, x, b );

    if ( n_data == 0 )

    {

      break;

    }

    cout                  << "  "

         << setw(6)  << n << "  "

         << setw(12) << x << "  "

         << setw(12) << b << "\n";

  }

  return;

}

void test016 ( )

{

  double b;

  int k;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST016:\n";

  cout << "  BERNSTEIN_POLY_01_VALUES returns values of \n";

  cout << "  the Bernstein Polynomials.\n";

  cout << "\n";

  cout << "     N     K       X      BERNSTEIN(N,K)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bernstein_poly_01_values ( n_data, n, k, x, b );

    if ( n_data == 0 )

    {

      break;

    }

    cout                  << "  "

         << setw(6)  << n << "  "

         << setw(6)  << k << "  "

         << setw(12) << x << "  "

         << setw(12) << b << "\n";

  }

  return;

}

void test017 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST017:\n";

  cout << "  BESSEL_I0_VALUES stores values of \n";

  cout << "  the Bessel I0 function.\n";

  cout << "\n";

  cout << "      X         I0(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_i0_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test018 ( )

{

  double bip;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST018:\n";

  cout << "  BESSEL_I0_INT_VALUES stores values of \n";

  cout << "  the integral of the Bessel I0 function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_i0_int_values ( n_data, x, bip );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                           << "  "

         << setw(24) << setprecision ( 16 ) << x   << "  "

         << setw(24) << setprecision ( 16 ) << bip << "\n";

  }

  return;

}

void test0185 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0185:\n";

  cout << "  BESSEL_I0_SPHERICAL_VALUES stores values of\n";

  cout << "  the spherical Bessel i0 function.\n";

  cout << "\n";

  cout << "      X            i0(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   bessel_i0_spherical_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test019 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST019:\n";

  cout << "  BESSEL_I1_VALUES stores values of \n";

  cout << "  the Bessel I1 function.\n";

  cout << "\n";

  cout << "      X         I1(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_i1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test0195 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0195:\n";

  cout << "  BESSEL_I1_SPHERICAL_VALUES stores values of\n";

  cout << "  the spherical Bessel i1 function.\n";

  cout << "\n";

  cout << "      X            i1(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   bessel_i1_spherical_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test020 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST020:\n";

  cout << "  BESSEL_IN_VALUES stores values of \n";

  cout << "  the Bessel In function.\n";

  cout << "\n";

  cout << "      N     X         IN(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_in_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test0205 ( )

{

  double fx;

  double nu;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0205:\n";

  cout << "  BESSEL_IX_VALUES stores values of \n";

  cout << "  the Bessel In function for NONINTEGER order.\n";

  cout << "\n";

  cout << "      NU    X         IN(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_ix_values ( n_data, nu, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << nu << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test021 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST021:\n";

  cout << "  BESSEL_J0_VALUES stores values of \n";

  cout << "  the Bessel J0 function.\n";

  cout << "\n";

  cout << "      X         J0(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_j0_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test022 ( )

{

  double bip;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST022:\n";

  cout << "  BESSEL_J0_INT_VALUES stores values of \n";

  cout << "  the integral of the Bessel J0 function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_j0_int_values ( n_data, x, bip );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                           << "  "

         << setw(24) << setprecision ( 16 ) << x   << "  "

         << setw(24) << setprecision ( 16 ) << bip << "\n";

  }

  return;

}

void test023 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST023:\n";

  cout << "  BESSEL_J0_SPHERICAL_VALUES stores values of\n";

  cout << "  the spherical Bessel j0 function.\n";

  cout << "\n";

  cout << "      X            j0(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   bessel_j0_spherical_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test024 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST024:\n";

  cout << "  BESSEL_J1_VALUES stores values of \n";

  cout << "  the Bessel J1 function.\n";

  cout << "\n";

  cout << "      X         J1(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_j1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test025 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST025:\n";

  cout << "  BESSEL_J1_SPHERICAL_VALUES stores values of\n";

  cout << "  the spherical Bessel j1 function.\n";

  cout << "\n";

  cout << "      X            j1(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   bessel_j1_spherical_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test026 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST026:\n";

  cout << "  BESSEL_JN_VALUES stores values of \n";

  cout << "  the Bessel Jn function.\n";

  cout << "\n";

  cout << "      N     X         JN(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_jn_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test0265 ( )

{

  double fx;

  double nu;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0265:\n";

  cout << "  BESSEL_JX_VALUES stores values of \n";

  cout << "  the Bessel Jn function for NONINTEGER order.\n";

  cout << "\n";

  cout << "      NU      X         JN(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_jx_values ( n_data, nu, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << nu << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test027 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST027:\n";

  cout << "  BESSEL_K0_VALUES stores values of \n";

  cout << "  the Bessel K0 function.\n";

  cout << "\n";

  cout << "      X         K0(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_k0_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test028 ( )

{

  double bip;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST028:\n";

  cout << "  BESSEL_K0_INT_VALUES stores values of \n";

  cout << "  the integral of the Bessel K0 function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_k0_int_values ( n_data, x, bip );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                           << "  "

         << setw(24) << setprecision ( 16 ) << x   << "  "

         << setw(24) << setprecision ( 16 ) << bip << "\n";

  }

  return;

}

void test029 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST029:\n";

  cout << "  BESSEL_K1_VALUES stores values of \n";

  cout << "  the Bessel K1 function.\n";

  cout << "\n";

  cout << "      X         K1(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_k1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test030 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST030:\n";

  cout << "  BESSEL_KN_VALUES stores values of \n";

  cout << "  the Bessel Kn function.\n";

  cout << "\n";

  cout << "      N      X         KN(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_kn_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test0305 ( )

{

  double fx;

  double nu;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0305:\n";

  cout << "  BESSEL_KX_VALUES stores values of \n";

  cout << "  the Bessel Kn function for NONINTEGER order.\n";

  cout << "\n";

  cout << "      NU     X         KN(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_kx_values ( n_data, nu, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << nu << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test031 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST031:\n";

  cout << "  BESSEL_Y0_VALUES stores values of \n";

  cout << "  the Bessel Y0 function.\n";

  cout << "\n";

  cout << "      X         Y0(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_y0_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test032 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST032:\n";

  cout << "  BESSEL_Y0_INT_VALUES stores values of \n";

  cout << "  the integral of the Bessel Y0 function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_y0_int_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test033 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST033:\n";

  cout << "  BESSEL_Y0_SPHERICAL_VALUES stores values of\n";

  cout << "  the spherical Bessel y0 function.\n";

  cout << "\n";

  cout << "                X                      y0(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   bessel_y0_spherical_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test034 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST034:\n";

  cout << "  BESSEL_Y1_VALUES stores values of \n";

  cout << "  the Bessel Y1 function.\n";

  cout << "\n";

  cout << "                X                   Y1(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_y1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test035 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST035:\n";

  cout << "  BESSEL_Y1_SPHERICAL_VALUES stores values of\n";

  cout << "  the spherical Bessel y1 function.\n";

  cout << "\n";

  cout << "                X                      y1(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   bessel_y1_spherical_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test036 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST036:\n";

  cout << "  BESSEL_YN_VALUES stores values of \n";

  cout << "  the Bessel Yn function.\n";

  cout << "\n";

  cout << "      N     X         YN(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_yn_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test0365 ( )

{

  double fx;

  double nu;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0365:\n";

  cout << "  BESSEL_YX_VALUES stores values of \n";

  cout << "  the Bessel Yn function for NONINTEGER order.\n";

  cout << "\n";

  cout << "      NU    X         YN(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bessel_yx_values ( n_data, nu, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << nu << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test037 ( )

{

  double a;

  double b;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST037:\n";

  cout << "  BETA_CDF_VALUES stores values of\n";

  cout << "  the Beta CDF.\n";

  cout << "\n";

  cout << "      A            B            X            CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    beta_cdf_values ( n_data, a, b, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(12)                     << a  << "  "

         << setw(12)                     << b  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test038 ( )

{

  double a;

  double b;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST038:\n";

  cout << "  BETA_INC_VALUES stores values of\n";

  cout << "  the incomplete Beta function.\n";

  cout << "\n";

  cout << "      A            B            X            BETA_INC(A,B)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    beta_inc_values ( n_data, a, b, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(12)                     << a  << "  "

         << setw(12)                     << b  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test039 ( )

{

  double fxy;

  int n_data;

  double x;

  double y;

  cout << "\n";

  cout << "TEST039:\n";

  cout << "  BETA_LOG_VALUES stores values of\n";

  cout << "  the logarithm of the Beta function.\n";

  cout << "\n";

  cout << "      X              Y         BETA_LOG(X,Y)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    beta_log_values ( n_data, x, y, fxy );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(12)                     << x   << "  "

         << setw(12)                     << y   << "  "

         << setw(24) << setprecision(16) << fxy << "\n";

  }

  return;

}

void test0395 ( )

{

  double a;

  double b;

  double fx;

  double lambda;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0395:\n";

  cout << "  BETA_NONCENTRAL_CDF_VALUES stores values of\n";

  cout << "  the noncentral Beta CDF.\n";

  cout << "\n";

  cout << "      A            B       LAMBDA             X            CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    beta_noncentral_cdf_values ( n_data, a, b, lambda, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(12)                     << a  << "  "

         << setw(12)                     << b  << "  "

         << setw(12)                     << lambda << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test040 ( )

{

  double fxy;

  int n_data;

  double x;

  double y;

  cout << "\n";

  cout << "TEST040:\n";

  cout << "  BETA_VALUES stores values of\n";

  cout << "  the Beta function.\n";

  cout << "\n";

  cout << "      X              Y         BETA(X,Y)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    beta_values ( n_data, x, y, fxy );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(12)                     << x   << "  "

         << setw(12)                     << y   << "  "

         << setw(24) << setprecision(16) << fxy << "\n";

  }

  return;

}

void test041 ( )

{

  int a;

  int b;

  int c;

  int n_data;

  cout << "\n";

  cout << "TEST041:\n";

  cout << "  BINOMIAL_VALUES returns values of\n";

  cout << "  the binomial numbers.\n";

  cout << "\n";

  cout << "     A     B        C(A,B)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    binomial_values ( n_data, a, b, c );

    if ( n_data == 0 )

    {

      break;

    }

    cout                  << "  "

         << setw(6)  << a << "  "

         << setw(6)  << b << "  "

         << setw(12) << c << "\n";

  }

  return;

}

void test042 ( )

{

  int a;

  double b;

  double fx;

  int n_data;

  int x;

  cout << "\n";

  cout << "TEST042:\n";

  cout << "  BINOMIAL_CDF_VALUES returns values of \n";

  cout << "  the Binomial Cumulative Density Function.\n";

  cout << "\n";

  cout << "     A      B        X   CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    binomial_cdf_values ( n_data, a, b, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                  << "  "

         << setw(6)                      << a  << "  "

         << setw(8)                      << b  << "  "

         << setw(4)                      << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test0425 ( )

{

  double fxy;

  int n_data;

  double r;

  double x;

  double y;

  cout << "\n";

  cout << "TEST0425:\n";

  cout << "  BIVARIATE_NORMAL_CDF_VALUES stores values of\n";

  cout << "  the bivariate normal CDF.\n";

  cout << "\n";

  cout << "      X            Y            R            F(R)(X,Y)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    bivariate_normal_cdf_values ( n_data, x, y, r, fxy );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(12)                     << x   << "  "

         << setw(12)                     << y   << "  "

         << setw(12)                     << r   << "  "

         << setw(24) << setprecision(16) << fxy << "\n";

  }

  return;

}

void test043 ( )

{

  int c;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST043:\n";

  cout << "  CATALAN_VALUES returns values of \n";

  cout << "  the Catalan numbers.\n";

  cout << "\n";

  cout << "     N        C(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    catalan_values ( n_data, n, c );

    if ( n_data == 0 )

    {

      break;

    }

    cout                  << "  "

         << setw(6)  << n << "  "

         << setw(10) << c << "\n";

  }

  return;

}

void test044 ( )

{

  double fx;

  double mu;

  int n_data;

  double sigma;

  double x;

  cout << "\n";

  cout << "TEST044:\n";

  cout << "  CAUCHY_CDF_VALUES returns values of \n";

  cout << "  the Cauchy Cumulative Density Function.\n";

  cout << "\n";

  cout << "     Mu      Sigma        X   CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    cauchy_cdf_values ( n_data, mu, sigma, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(8)                      << mu    << "  "

         << setw(8)                      << sigma << "  "

         << setw(8)                      << x     << "  "

         << setw(24) << setprecision(16) << fx    << "\n";

  }

  return;

}

void test0445 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0445:\n";

  cout << "  CBRT_VALUES stores values of the cube root function.\n";

  cout << "\n";

  cout << "      X            CBRT(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    cbrt_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test045 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST045:\n";

  cout << "  CHEBY_T_POLY_VALUES returns values of\n";

  cout << "  the Chebyshev T polynomials.\n";

  cout << "\n";

  cout << "     N       X      T(N)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    cheby_t_poly_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(8)  << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test046 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST046:\n";

  cout << "  CHEBY_U_POLY_VALUES returns values of\n";

  cout << "  the Chebyshev U polynomials.\n";

  cout << "\n";

  cout << "     N       X      U(N)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    cheby_u_poly_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(8)  << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test0465 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0465:\n";

  cout << "  CHI_VALUES stores values of\n";

  cout << "  the Hyperbolic Cosine Integral function CHI(X).\n";

  cout << "\n";

  cout << "      X            CHI(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    chi_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test047 ( )

{

  int a;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST047:\n";

  cout << "  CHI_SQUARE_CDF_VALUES returns values of \n";

  cout << "  the Chi-Squared Cumulative Density Function.\n";

  cout << "\n";

  cout << "     N       X    CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    chi_square_cdf_values ( n_data, a, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << a  << "  "

         << setw(8)  << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test048 ( )

{

  int df;

  double fx;

  double lambda;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST048:\n";

  cout << "  CHI_SQUARE_NONCENTRAL_CDF_VALUES returns values of\n";

  cout << "  the noncentral Chi-Squared Cumulative Density Function.\n";

  cout << "\n";

  cout << "      X      LAMBDA     DF     CDF\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    chi_square_noncentral_cdf_values ( n_data, df, lambda, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                       << "  "

         << setw(10) << x      << "  "

         << setw(8)  << lambda << "  "

         << setw(4)  << df     << "  "

         << setw(12) << fx     << "\n";

  }

  return;

}

void test049 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST049:\n";

  cout << "  CI_VALUES stores values of\n";

  cout << "  the Cosine Integral function CI(X).\n";

  cout << "\n";

  cout << "      X            CI(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    ci_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test050 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST050:\n";

  cout << "  CIN_VALUES stores values of\n";

  cout << "  the Cosine Integral function CIN(X).\n";

  cout << "\n";

  cout << "      X            CIN(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    cin_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test051 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST051:\n";

  cout << "  CLAUSEN_VALUES stores values of \n";

  cout << "  Clausen's integral function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    clausen_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test05125 ( )

{

  double fx;

  double j1;

  double j2;

  double j3;

  double m1;

  double m2;

  double m3;

  int n_data;

  cout << "\n";

  cout << "TEST05125:\n";

  cout << "  CLEBSCH_GORDAN_VALUES returns values of\n";

  cout << "  the Clebsch Gordan coefficient.\n";

  cout << "\n";

  cout << "      J1      J2      J3      M1      M2      M3        CG\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    clebsch_gordan_values ( n_data, j1, j2, j3, m1, m2, m3, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(6) << j1

         << "  " << setw(6) << j2

         << "  " << setw(6) << j3

         << "  " << setw(6) << m1

         << "  " << setw(6) << m2

         << "  " << setw(6) << m3

         << "  " << setprecision(16) << setw(24) << fx << "\n";

  }

  return;

}

void test0515 ( )

{

  int count;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST0515:\n";

  cout << "  COLLATZ_COUNT_VALUES returns values of\n";

  cout << "  the length of the Collatz sequence that\n";

  cout << "  starts at N.\n";

  cout << "\n";

  cout << "         N      COLLATZ_COUNT(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    collatz_count_values ( n_data, n, count );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(8)  << n

         << "  " << setw(12) << count << "\n";

  }

  return;

}

void test0517 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0517:\n";

  cout << "   COS_VALUES stores values of the cosine function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    cos_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test0519 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0519:\n";

  cout << "   COSH_VALUES stores values of the hyperbolic cosine function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    cosh_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test052 ( )

{

  double cp;

  int n_data;

  double p;

  double tc;

  cout << "\n";

  cout << "TEST052:\n";

  cout << "  CP_VALUES stores values of\n";

  cout << "  the specific heat CP\n";

  cout << "  as a function of temperature and pressure.\n";

  cout << "\n";

  cout << "      T            P            CP(T,P)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    cp_values ( n_data, tc, p, cp );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << tc << "  "

         << setw(12) << p  << "  "

         << setw(12) << cp << "\n";

  }

  return;

}

void test053 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST053:\n";

  cout << "  DAWSON_VALUES stores values of\n";

  cout << "  Dawson's integral function.\n";

  cout << "\n";

  cout << "      X          DAWSON(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    dawson_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test054 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST054:\n";

  cout << "  DEBYE1_VALUES stores values of \n";

  cout << "  the Debye function of order 1.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    debye1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test055 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST055:\n";

  cout << "  DEBYE2_VALUES stores values of \n";

  cout << "  the Debye function of order 2.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    debye2_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test056 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST056:\n";

  cout << "  DEBYE3_VALUES stores values of \n";

  cout << "  the Debye function of order 3.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    debye3_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test057 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST057:\n";

  cout << "  DEBYE4_VALUES stores values of \n";

  cout << "  the Debye function of order 4.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    debye4_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test0575 ( )

{

  int d;

  int n;

  int n_data;

  int p;

  int q;

  cout << "\n";

  cout << "TEST0575:\n";

  cout << "  DEDEKIND_SUM_VALUES stores values of the Dedekind sum\n";

  cout << "  (N/D) = Dedekind_Sum(P,Q).\n";

  cout << "\n";

  cout << "       P       Q       N       D\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    dedekind_sum_values ( n_data, p, q, n, d );

    if ( n_data == 0 )

    {

      break;

    }

    cout                  << "  "

         << setw(6) << p  << "  "

         << setw(6) << q  << "  "

         << setw(6) << n  << "  "

         << setw(6) << d  << "\n";

  }

  return;

}

void test058 ( )

{

  double eps;

  int n_data;

  double p;

  double tc;

  cout << "\n";

  cout << "TEST058:\n";

  cout << "  DIELECTRIC_VALUES stores values of\n";

  cout << "  the dielectric function.\n";

  cout << "\n";

  cout << "      T           P            EPS(T,P)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    dielectric_values ( n_data, tc, p, eps );

    if ( n_data == 0 )

    {

      break;

    }

    cout                    << "  "

         << setw(12) << tc  << "  "

         << setw(12) << p   << "  "

         << setw(12) << eps << "\n";

  }

  return;

}

void test059 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST059:\n";

  cout << "  DILOGARITHM_VALUES stores values of\n";

  cout << "  the dilogarithm function.\n";

  cout << "\n";

  cout << "      X          DILOGARITHM(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    dilogarithm_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test060 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST060:\n";

  cout << "  E1_VALUES stores values of\n";

  cout << "  the exponential integral function E1(X).\n";

  cout << "\n";

  cout << "      X          E1(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    e1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test061 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST061:\n";

  cout << "  EI_VALUES stores values of\n";

  cout << "  the exponential integral function EI(X).\n";

  cout << "\n";

  cout << "      X          EI(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    ei_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test062 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST062:\n";

  cout << "  ELLIPTIC_EA_VALUES stores values of\n";

  cout << "  the complete elliptic integral of the second\n";

  cout << "  kind, with parameter angle ALPHA in degrees.\n";

  cout << "\n";

  cout << "    ALPHA        EA(ALPHA)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    elliptic_ea_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test063 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST063:\n";

  cout << "  ELLIPTIC_EM_VALUES stores values of\n";

  cout << "  the complete elliptic integral of the second\n";

  cout << "  kind, with parameter modulus M.\n";

  cout << "\n";

  cout << "      M            EM(M)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    elliptic_em_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test064 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST064:\n";

  cout << "  ELLIPTIC_KA_VALUES stores values of\n";

  cout << "  the complete elliptic integral of the first\n";

  cout << "  kind, with parameter angle ALPHA in degrees.\n";

  cout << "\n";

  cout << "    ALPHA        KA(ALPHA)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    elliptic_ka_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test065 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST065:\n";

  cout << "  ELLIPTIC_KM_VALUES stores values of\n";

  cout << "  the complete elliptic integral of the first\n";

  cout << "  kind, with parameter modulus M.\n";

  cout << "\n";

  cout << "      M            KM(M)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    elliptic_km_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test066 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST066:\n";

  cout << "  ERF_VALUES stores values of\n";

  cout << "  the error function ERF(X).\n";

  cout << "\n";

  cout << "      X          ERF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    erf_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test0665 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0665:\n";

  cout << "  ERFC_VALUES stores values of\n";

  cout << "  the complementary error function ERFC(X).\n";

  cout << "\n";

  cout << "      X          ERFC(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    erfc_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test067 ( )

{

  int c;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST067:\n";

  cout << "  EULER_NUMBER_VALUES returns values of\n";

  cout << "  the Euler numbers.\n";

  cout << "\n";

  cout << "     N        EULER_NUMBER(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    euler_number_values ( n_data, n, c );

    if ( n_data == 0 )

    {

      break;

    }

    cout                  << "  "

         << setw(6)  << n << "  "

         << setw(10) << c << "\n";

  }

  return;

}

void test068 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST068:\n";

  cout << "  EULER_POLY_VALUES returns values of\n";

  cout << "  the Euler numbers.\n";

  cout << "\n";

  cout << "     N     X       EULER_POLY(N)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    euler_poly_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(8)  << x  << "  "

         << setw(16) << fx << "\n";

  }

  return;

}

void test0685 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0685:\n";

  cout << "   EXP_VALUES stores values of the exponential function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    exp_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test069 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST069:\n";

  cout << "  EXP3_INT_VALUES stores values of \n";

  cout << "  the exponential integral function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    exp3_int_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test070 ( )

{

  double fx;

  double lambda;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST070:\n";

  cout << "  EXPONENTIAL_CDF_VALUES stores values of \n";

  cout << "  the exponential CDF.\n";

  cout << "\n";

  cout << "       LAMBDA         X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    exponential_cdf_values ( n_data, lambda, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                              << "  "

         << setw(24) << setprecision ( 8 )  << lambda << "  "

         << setw(24) << setprecision ( 8 )  << x      << "  "

         << setw(24) << setprecision ( 16 ) << fx     << "\n";

  }

  return;

}

void test071 ( )

{

  double alpha;

  double beta;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST071:\n";

  cout << "  EXTREME_VALUES_CDF_VALUES stores values of \n";

  cout << "  the extreme values CDF.\n";

  cout << "\n";

  cout << "        Alpha    Beta        X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    extreme_values_cdf_values ( n_data, alpha, beta, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                              << "  "

         << setw(12)                        << alpha  << "  "

         << setw(12)                        << beta   << "  "

         << setw(12)                        << x      << "  "

         << setw(24) << setprecision ( 16 ) << fx     << "\n";

  }

  return;

}

void test072 ( )

{

  int a;

  int b;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << " TEST072:\n";

  cout << "   F_CDF_VALUES stores values of\n";

  cout << "   the F cumulative density function.\n";

  cout << "\n";

  cout << "     A       B            X            CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    f_cdf_values ( n_data, a, b, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << a  << "  "

         << setw(6)  << b  << "  "

         << setw(12) << x  << "  "

         << setw(12) << fx << "\n";

  }

  return;

}

void test073 ( )

{

  int a;

  int b;

  double fx;

  double lambda;

  int n_data;

  double x;

  cout << "\n";

  cout << " TEST073:\n";

  cout << "   F_NONCENTRAL_CDF_VALUES stores values of\n";

  cout << "   the F cumulative density function.\n";

  cout << "\n";

  cout << "     A       B            LAMBDA    X            CDF\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    f_noncentral_cdf_values ( n_data, a, b, lambda, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                       << "  "

         << setw(6)  << a      << "  "

         << setw(6)  << b      << "  "

         << setw(8)  << lambda << "  "

         << setw(12) << x      << "  "

         << setw(12) << fx     << "\n";

  }

  return;

}

void test074 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << " TEST074:\n";

  cout << "   FRESNEL_COS_VALUES stores values of\n";

  cout << "   the Fresnel cosine integral C(X).\n";

  cout << "\n";

  cout << "      X           C(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    fresnel_cos_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test075 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << " TEST075:\n";

  cout << "   FRESNEL_SIN_VALUES stores values of\n";

  cout << "   the Fresnel sine integral S(X).\n";

  cout << "\n";

  cout << "      X           S(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    fresnel_sin_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test0755 ( )

{

  int c1;

  int c2;

  int f;

  int n_data;

  cout << "\n";

  cout << "TEST0755:\n";

  cout << "  FROBENIUS_NUMBER_ORDER2_VALUES returns values of \n";

  cout << "  the Frobenius number of order 2.\n";

  cout << "\n";

  cout << "         C1        C2          F(C1,C2)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    frobenius_number_order2_values ( n_data, c1, c2, f );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(8) << c1

         << "  " << setw(8) << c2

         << "  " << setw(8) << f << "\n";

  }

  return;

}

void test0756 ( )

{

  int *c;

  int f;

  int i;

  int n_data;

  int order;

  cout << "\n";

  cout << "TEST0756:\n";

  cout << "  FROBENIUS_NUMBER_ORDER_VALUES returns the order for\n";

  cout << "  a Frobenius problem;\n";

  cout << "  FROBENIUS_NUMBER_DATA_VALUES returns the corresponding\n";

  cout << "  coin denominations.\n";

  n_data = 0;

  for ( ; ; )

  {

    frobenius_number_order_values ( n_data, order );

    if ( n_data == 0 )

    {

      break;

    }

    c = new int[order];

    frobenius_number_data_values ( n_data, order, c, f );

    cout << "\n";

    cout << "  Order = " << order << "\n";

    for ( i = 0; i < order; i++ )

    {

      cout << "  " << setw(8) << c[i];

    }

    cout << "\n";

    cout << "  Frobenius number = " << f << "\n";

    delete [] c;

  }

  return;

}

void test076 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << " TEST076:\n";

  cout << "   GAMMA_VALUES stores values of the Gamma function.\n";

  cout << "\n";

  cout << "      X            GAMMA(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    gamma_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test077 ( )

{

  double fx;

  double mu;

  int n_data;

  double sigma;

  double x;

  cout << "\n";

  cout << " TEST077:\n";

  cout << "   GAMMA_CDF_VALUES stores values of\n";

  cout << "   the Gamma CDF.\n";

  cout << "\n";

  cout << "      M    Sigma      X            CDF((X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    gamma_cdf_values ( n_data, mu, sigma, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                           << "  "

         << setw(12)                     << mu     << "  "

         << setw(12)                     << sigma  << "  "

         << setw(12)                     << x      << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test078 ( )

{

  double a;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << " TEST078:\n";

  cout << "   GAMMA_INC_VALUES stores values of\n";

  cout << "   the incomplete Gamma function.\n";

  cout << "\n";

  cout << "      A            X            GAMMA_INC(A)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    gamma_inc_values ( n_data, a, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << a  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test079 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << " TEST079:\n";

  cout << "   GAMMA_LOG_VALUES stores values of\n";

  cout << "   the logarithm of the Gamma function.\n";

  cout << "\n";

  cout << "      X            GAMMA_LOG(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    gamma_log_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test080 ( )

{

  double a;

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST080:\n";

  cout << "  GEGENBAUER_POLY_VALUES returns values of\n";

  cout << "  the Gegenbauer polynomials.\n";

  cout << "\n";

  cout << "       N       A       X       G(N,A)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    gegenbauer_poly_values ( n_data, n, a, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(10)                     << a  << "  "

         << setw(10)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test081 ( )

{

  double cdf;

  int n_data;

  double p;

  int x;

  cout << "\n";

  cout << " TEST081:\n";

  cout << "   GEOMETRIC_CDF_VALUES stores values of\n";

  cout << "   the Geometric Probability Cumulative Density Function.\n";

  cout << "\n";

  cout << "      X      P       CDF\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    geometric_cdf_values ( n_data, x, p, cdf );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                        << "  "

         << setw(6)                      << x   << "  "

         << setw(8)                      << p   << "  "

         << setw(24) << setprecision(16) << cdf << "\n";

  }

  return;

}

void test082 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST082:\n";

  cout << "  GOODWIN_VALUES stores values of \n";

  cout << "  the Goodwin function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    goodwin_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test083 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << " TEST083:\n";

  cout << "   GUD_VALUES stores values of\n";

  cout << "   the Gudermannian function.\n";

  cout << "\n";

  cout << "      X            GUD(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    gud_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test0835 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << " TEST0835\n";

  cout << "   HERMITE_FUNCTION_VALUES stores values of\n";

  cout << "   the Hermite function.\n";

  cout << "\n";

  cout << "     N      X            Hf(N,X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    hermite_function_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test084 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << " TEST084\n";

  cout << "   HERMITE_POLY_PHYS_VALUES stores values of\n";

  cout << "   the physicist's Hermite polynomials.\n";

  cout << "\n";

  cout << "     N      X            H(N,X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    hermite_poly_phys_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test0843 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << " TEST0843\n";

  cout << "   HERMITE_POLY_PROB_VALUES stores values of\n";

  cout << "   the probabilist's Hermite polynomials.\n";

  cout << "\n";

  cout << "     N      X            He(N,X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    hermite_poly_prob_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test0845 ( )

{

  double a;

  double b;

  double c;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << " TEST0845:\n";

  cout << "   HYPER_2F1_VALUES stores values of\n";

  cout << "   the hypergeometric function 2F1.\n";

  cout << "\n";

  cout << "      A      B     C      X   Hyper_2F1(A,B,C,X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    hyper_2f1_values ( n_data, a, b, c, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(8)                      << a  << "  "

         << setw(8)                      << b  << "  "

         << setw(8)                      << c  << "  "

         << setw(8)                      << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test085 ( )

{

  double fx;

  int n_data;

  int pop;

  int sam;

  int succ;

  int x;

  cout << "\n";

  cout << " TEST085:\n";

  cout << "   HYPERGEOMETRIC_CDF_VALUES stores values of\n";

  cout << "   the Hypergeometric CDF.\n";

  cout << "\n";

  cout << "     SAM    SUC   POP     X   HyperCDF(S,S,P)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    hypergeometric_cdf_values ( n_data, sam, succ, pop, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                         << "  "

         << setw(8)                      << sam  << "  "

         << setw(8)                      << succ << "  "

         << setw(8)                      << pop  << "  "

         << setw(8)                      << x    << "  "

         << setw(24) << setprecision(16) << fx   << "\n";

  }

  return;

}

void test0855 ( )

{

  double fx;

  int n_data;

  int pop;

  int sam;

  int succ;

  int x;

  cout << "\n";

  cout << " TEST0855:\n";

  cout << "   HYPERGEOMETRIC_PDF_VALUES stores values of\n";

  cout << "   the Hypergeometric PDF.\n";

  cout << "\n";

  cout << "     SAM    SUC   POP     X   HyperPDF(S,S,P)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    hypergeometric_pdf_values ( n_data, sam, succ, pop, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                         << "  "

         << setw(8)                      << sam  << "  "

         << setw(8)                      << succ << "  "

         << setw(8)                      << pop  << "  "

         << setw(8)                      << x    << "  "

         << setw(24) << setprecision(16) << fx   << "\n";

  }

  return;

}

void test086 ( )

{

  int fn;

  int n;

  int n_data;

  cout << "\n";

  cout << " TEST086:\n";

  cout << "   FACTORIAL_VALUES returns values of\n";

  cout << "   the factorial function.\n";

  cout << "\n";

  cout << "      N        Factorial(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    factorial_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(12) << fn << "\n";

  }

  return;

}

void test087 ( )

{

  int fn;

  int n;

  int n_data;

  cout << "\n";

  cout << " TEST087:\n";

  cout << "   FACTORIAL2_VALUES return;s values of\n";

  cout << "   the double factorial function.\n";

  cout << "\n";

  cout << "      N         DoubleFactorial(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    factorial2_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(12) << fn << "\n";

  }

  return;

}

void test088 ( )

{

  int fmn;

  int m;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST088:\n";

  cout << "  FACTORIAL_RISING_VALUES returns some exact values\n";

  cout << "  of the Pochhammer symbol:\n";

  cout << "\n";

  cout << "     M     N      Factorial_Rising(M,N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    factorial_rising_values ( n_data, m, n, fmn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << m   << "  "

         << setw(6)  << n   << "  "

         << setw(12) << fmn << "\n";

  }

  return;

}

void test089 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST089:\n";

  cout << "  I0ML0_VALUES stores values of \n";

  cout << "  the I0-L0 function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    i0ml0_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test090 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST090:\n";

  cout << "  I1ML1_VALUES stores values of \n";

  cout << "  the I1-L1 function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    i1ml1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test091 ( )

{

  double a;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST091:\n";

  cout << "  JACOBI_CN_VALUES returns values of \n";

  cout << "  the Jacobi elliptic CN function.\n";

  cout << "\n";

  cout << "      A         X       CN(A,X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    jacobi_cn_values ( n_data, a, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(10)                     << a  << "  "

         << setw(10)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test092 ( )

{

  double a;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST092:\n";

  cout << "  JACOBI_DN_VALUES returns values of \n";

  cout << "  the Jacobi elliptic DN function.\n";

  cout << "\n";

  cout << "      A         X       DN(A,X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    jacobi_dn_values ( n_data, a, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(10)                     << a  << "  "

         << setw(10)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test093 ( )

{

  double a;

  double b;

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST093:\n";

  cout << "  JACOBI_POLY_VALUES returns values of\n";

  cout << "  the Jacobi polynomial.\n";

  cout << "\n";

  cout << "       N         A         B      X       J(N,A,B)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    jacobi_poly_values ( n_data, n, a, b, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(8)                      << a  << "  "

         << setw(8)                      << b  << "  "

         << setw(10)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test094 ( )

{

  double a;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST094:\n";

  cout << "  JACOBI_SN_VALUES returns values of \n";

  cout << "  the Jacobi elliptic SN function.\n";

  cout << "\n";

  cout << "      A         X       SN(A,X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    jacobi_sn_values ( n_data, a, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(10)                     << a  << "  "

         << setw(10)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test0945 ( )

{

  int d;

  double f;

  double jed;

  int n_data;

  int m;

  int y;

  cout << "\n";

  cout << "TEST0945:\n";

  cout << "  JED_CE_VALUES returns:\n";

  cout << "  JED, a Julian Ephemeris Date, and\n";

  cout << "  YMDF, the corresponding year, month, day, fraction.\n";

  cout << "\n";

  cout << "        JED          Y   M   D    F\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    jed_ce_values ( n_data, jed, y, m, d, f );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(12) << jed

         << "  " << setw(6)  << y

         << "  " << setw(2)  << m

         << "  " << setw(2)  << d

         << "  " << setw(6)  << f << "\n";

  }

  return;

}

void test095 ( )

{

  double jed;

  int n_data;

  double mjd;

  cout << "\n";

  cout << "TEST095:\n";

  cout << "  JED_MJD_VALUES returns:\n";

  cout << "  JED, a Julian Ephemeris Date, and\n";

  cout << "  MJD, the corresponding Modified Julian Day count.\n";

  cout << "\n";

  cout << "   JED      MJD\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    jed_mjd_values ( n_data, jed, mjd );

    if ( n_data == 0 )

    {

      break;

    }

    cout                    << "  "

         << setw(12) << jed << "  "

         << setw(12) << mjd << "\n";

  }

  return;

}

void test096 ( )

{

  double jed;

  int n_data;

  double rd;

  cout << "\n";

  cout << "TEST096:\n";

  cout << "  JED_RD_VALUES returns:\n";

  cout << "  JED, a Julian Ephemeris Date, and\n";

  cout << "  RD, the corresponding Reingold Dershowitz Day count.\n";

  cout << "\n";

  cout << "   JED      RD\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    jed_rd_values ( n_data, jed, rd );

    if ( n_data == 0 )

    {

      break;

    }

    cout                    << "  "

         << setw(12) << jed << "  "

         << setw(12) << rd  << "\n";

  }

  return;

}

void test097 ( )

{

  double jed;

  int n_data;

  int weekday;

  string weekday_name[7] = {

    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", 

    "Friday", "Saturday" };

  cout << "\n";

  cout << "TEST097:\n";

  cout << "  JED_WEEKDAY_VALUES returns Julian Ephemeris Dates \n";

  cout << "  (JED) and the corresponding weekday\n";

  cout << "\n";

  cout << "   JED      #  Weekday\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    jed_weekday_values ( n_data, jed, weekday );

    if ( n_data == 0 )

    {

      break;

    }

    cout                            << "  "

         << setw(12) << jed         << "  "

         << setw(1)  << weekday     << "  "

         << weekday_name[weekday-1] << "\n";

  }

  return;

}

void test0972 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0972:\n";

  cout << "  KEI0_VALUES stores values of \n";

  cout << "  the Kelvin function KEI of order 0.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    kei0_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test0973 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0973:\n";

  cout << "  KEI1_VALUES stores values of \n";

  cout << "  the Kelvin function KEI of order 1.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    kei1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test0974 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0974:\n";

  cout << "  KER0_VALUES stores values of \n";

  cout << "  the Kelvin function KER of order 0.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    ker0_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test0975 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0975:\n";

  cout << "  KER1_VALUES stores values of \n";

  cout << "  the Kelvin function KER of order 1.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    ker1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test098 ( )

{

  double fx;

  int m;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST098:\n";

  cout << "  LAGUERRE_ASSOCIATED_VALUES stores values of\n";

  cout << "  the associated Laguerre polynomials.\n";

  cout << "\n";

  cout << "     N     M    X             L(N,M)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    laguerre_associated_values ( n_data, n, m, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(6)                      << n  << "  "

         << setw(6)                      << m  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test099 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST099:\n";

  cout << "  LAGUERRE_POLYNOMIAL_VALUES stores values of \n";

  cout << "  the Laguerre polynomials.\n";

  cout << "\n";

  cout << "     N     X            L(N)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    laguerre_polynomial_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test0995 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST0995:\n";

  cout << "  LAMBERT_W_VALUES stores values of \n";

  cout << "  the Lambert W function.\n";

  cout << "\n";

  cout << "                X                     W(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    lambert_w_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test100 ( )

{

  double beta;

  double fx;

  double mu;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST100:\n";

  cout << "  LAPLACE_CDF_VALUES returns values of \n";

  cout << "  the Laplace Cumulative Density Function.\n";

  cout << "\n";

  cout << "     Mu      Beta         X   CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    laplace_cdf_values ( n_data, mu, beta, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                         << "  "

         << setw(8)                      << mu   << "  "

         << setw(8)                      << beta << "  "

         << setw(8)                      << x    << "  "

         << setw(24) << setprecision(16) << fx   << "\n";

  }

  return;

}

void test101 ( )

{

  double fx;

  int m;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST101:\n";

  cout << "  LEGENDRE_ASSOCIATED_VALUES stores values of\n";

  cout << "  the associated Legendre polynomials.\n";

  cout << "\n";

  cout << "     N     M    X             P(N,M)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    legendre_associated_values ( n_data, n, m, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(6)                      << m  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test1015 ( )

{

  double fx;

  int m;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST1015:\n";

  cout << "  LEGENDRE_ASSOCIATED_NORMALIZED_VALUES stores values of\n";

  cout << "  the normalized associated Legendre polynomials.\n";

  cout << "\n";

  cout << "     N     M    X             P(N,M)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    legendre_associated_normalized_values ( n_data, n, m, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(6)                      << m  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test1016 ( )

{

  double fx;

  int m;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST1016:\n";

  cout << "  LEGENDRE_ASSOCIATED_NORMALIZED_SPHERE_VALUES stores values of\n";

  cout << "  the associated Legendre polynomials, normalized for the unit sphere.\n";

  cout << "\n";

  cout << "     N     M    X             P(N,M)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    legendre_associated_normalized_sphere_values ( n_data, n, m, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(6)                      << m  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test102 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST102:\n";

  cout << "  LEGENDRE_POLY_VALUES stores values of \n";

  cout << "  the Legendre polynomials.\n";

  cout << "\n";

  cout << "     N    X             P(N)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    legendre_poly_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test103 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST103:\n";

  cout << "  LEGENDRE_FUNCTION_Q_VALUES stores values of\n";

  cout << "  the Legendre Q function.\n";

  cout << "\n";

  cout << "     N    X             Q(N)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    legendre_function_q_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(6)                      << n  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test1035 ( )

{

  double a;

  double fx;

  int n_data;

  int s;

  double z;

  cout << "\n";

  cout << "TEST1035:\n";

  cout << "  LERCH_VALUES returns values of\n";

  cout << "  the Lerch transcendent function.\n";

  cout << "\n";

  cout << "      Z      S      A      Fx\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    lerch_values ( n_data, z, s, a, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(24) << setprecision(16) << z  << "  "

         << setw(6)                      << s  << "  "

         << setw(12)                     << a  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test104 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST104:\n";

  cout << "  LOBACHEVSKY_VALUES stores values of \n";

  cout << "  the Lobachevsky function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    lobachevsky_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(12)                        << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test1045 ( )

{

  double fx;

  int n;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST1045:\n";

  cout << "  LOBATTO_POLY_VALUES stores values of \n";

  cout << "  the completed Lobatto polynomials.\n";

  cout << "\n";

  cout << "     N    X             Lo(N)(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    lobatto_poly_values ( n_data, n, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test1037 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST1037:\n";

  cout << "   LOG_VALUES stores values of the natural logarithm function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    log_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test105 ( )

{

  double fx;

  double mu;

  int n_data;

  double sigma;

  double x;

  cout << "\n";

  cout << "TEST105:\n";

  cout << "  LOG_NORMAL_CDF_VALUES returns values of \n";

  cout << "  the Log Normal Cumulative Density Function.\n";

  cout << "\n";

  cout << "     Mu      Sigma        X   CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    log_normal_cdf_values ( n_data, mu, sigma, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(8)                      << mu    << "  "

         << setw(8)                      << sigma << "  "

         << setw(8)                      << x     << "  "

         << setw(24) << setprecision(16) << fx    << "\n";

  }

  return;

}

void test106 ( )

{

  double fx;

  int n;

  int n_data;

  double t;

  cout << "\n";

  cout << "TEST106:\n";

  cout << "  LOG_SERIES_CDF_VALUES returns values of \n";

  cout << "  the Log Series Cumulative Density Function.\n";

  cout << "\n";

  cout << "     T      N   CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    log_series_cdf_values ( n_data, t, n, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(24) << setprecision(16) << t  << "  "

         << setw(6)                      << n  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test107 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST107:\n";

  cout << "  LOGARITHMIC_INTEGAL_VALUES stores values of\n";

  cout << "  the logarithmic integral function.\n";

  cout << "\n";

  cout << "      X            LI(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    logarithmic_integral_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test108 ( )

{

  double beta;

  double fx;

  double mu;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST108:\n";

  cout << "  LOGISTIC_CDF_VALUES returns values of \n";

  cout << "  the Logistic Cumulative Density Function.\n";

  cout << "\n";

  cout << "     Mu      Beta         X   CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    logistic_cdf_values ( n_data, mu, beta, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(8)                      << mu   << "  "

         << setw(8)                      << beta << "  "

         << setw(8)                      << x    << "  "

         << setw(24) << setprecision(16) << fx   << "\n";

  }

  return;

}

void test10875 ( )

{

  int fn;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST10875:\n";

  cout << "  MERTENS_VALUES returns values of\n";

  cout << "  the Mertens function.\n";

  cout << "\n";

  cout << "     N         MERTENS(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    mertens_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    } 

    cout                   << "  "

         << setw(8)  << n  << "  "

         << setw(12) << fn << "\n";

  }

  return;

}

void test109 ( )

{

  int fn;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST109:\n";

  cout << "  MOEBIUS_VALUES returns values of\n";

  cout << "  the Moebius function.\n";

  cout << "\n";

  cout << "     N         MU(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    moebius_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    } 

    cout                   << "  "

         << setw(8)  << n  << "  "

         << setw(12) << fn << "\n";

  }

  return;

}

void test110 ( )

{

  double cdf;

  int f;

  int n_data;

  double p;

  int s;

  cout << "\n";

  cout << "TEST110:\n";

  cout << "  NEGATIVE_BINOMIAL_CDF_VALUES stores values of\n";

  cout << "  the Negative Binomial Cumulative Density Function.\n";

  cout << "\n";

  cout << "     F     S         P         CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    negative_binomial_cdf_values ( n_data, f, s, p, cdf );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                        << "  "

         << setw(6)                      << f   << "  "

         << setw(6)                      << s   << "  "

         << setw(12)                     << p   << "  "

         << setw(24) << setprecision(16) << cdf << "\n";

  }

  return;

}

void test1105 ( )

{

  double fx;

  double j1;

  double j2;

  double j3;

  double j4;

  double j5;

  double j6;

  double j7;

  double j8;

  double j9;

  int n_data;

  cout << "\n";

  cout << "TEST1105:\n";

  cout << "  GSL_SF_COUPLING_9J returns values of\n";

  cout << "  the Wigner 9J coefficient.\n";

  cout << "\n";

  cout << "      J1      J2      J3      J4      J5      J6"

       << "      J7      J8      J9        NINE_J\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    nine_j_values ( n_data, j1, j2, j3, j4, j5, j6, j7, j8, j9, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(6) << j1

         << "  " << setw(6) << j2

         << "  " << setw(6) << j3

         << "  " << setw(6) << j4

         << "  " << setw(6) << j5

         << "  " << setw(6) << j6

         << "  " << setw(6) << j7

         << "  " << setw(6) << j8

         << "  " << setw(6) << j9

         << "  " << setprecision(16) << setw(24) << fx << "\n";

  }

  return;

}

void test111 ( )

{

  double fx;

  double mu;

  int n_data;

  double sigma;

  double x;

  cout << "\n";

  cout << "TEST111:\n";

  cout << "  NORMAL_CDF_VALUES stores values of\n";

  cout << "  the Normal Cumulative Density Function.\n";

  cout << "\n";

  cout << "            X                   CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    normal_cdf_values ( n_data, mu, sigma, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                             << "  "

         << setw(12)                        << mu    << "  "

         << setw(12)                        << sigma << "  "

         << setw(12)                        << x     << "  "

         << setw(24) << setprecision ( 16 ) << fx    << "\n";

  }

  return;

}

void test112 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST112:\n";

  cout << "  NORMAL_01_CDF_VALUES stores values of\n";

  cout << "  the Normal 01 Cumulative Density Function.\n";

  cout << "\n";

  cout << "            X                   CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    normal_01_cdf_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test113 ( )

{

  int fn;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST113:\n";

  cout << "  OMEGA_VALUES returns values of\n";

  cout << "  the Omega function.\n";

  cout << "\n";

  cout << "     N           OMEGA(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    omega_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << n  << "  "

         << setw(10) << fn << "\n";

  }

  return;

}

void test1135 ( )

{

  double a;

  double h;

  int n_data;

  double t;

  cout << "\n";

  cout << "TEST1135\n";

  cout << "  OWEN_VALUES stores values of\n";

  cout << "  Owen's T function.\n";

  cout << "\n";

  cout << "          H            A            T\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    owen_values ( n_data, h, a, t );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                      << "  "

         << setw(12)                     << h << "  "

         << setw(12)                     << a << "  "

         << setw(24) << setprecision(16) << t << "\n";

  }

  return;

}

void test114 ( )

 

{

  int fn;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST114:\n";

  cout << "  PARTITION_COUNT_VALUES returns values of \n";

  cout << "  the integer partition count function.\n";

  cout << "\n";

  cout << "     N         P(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    partition_count_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(12) << fn << "\n";

  }

  return;

}

void test115 ( )

{

  int fn;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST115:\n";

  cout << "  PARTITION_DISTINCT_COUNT_VALUES returns values of \n";

  cout << "  the integer distinct partition count function.\n";

  cout << "\n";

  cout << "     N         Q(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    partition_distinct_count_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(12) << fn << "\n";

  }

  return;

}

void test116 ( )

{

  int fn;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST116:\n";

  cout << "  PHI_VALUES returns values of\n";

  cout << "  the PHI function.\n";

  cout << "\n";

  cout << "     N         PHI(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    phi_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(10) << fn << "\n";

  }

  return;

}

void test117 ( )

{

  int fn;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST117:\n";

  cout << "  PI_VALUES returns values of\n";

  cout << "  the PI function.\n";

  cout << "\n";

  cout << "     N         PI(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    pi_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << n  << "  "

         << setw(10) << fn << "\n";

  }

  return;

}

void test118 ( )

{

  double a;

  double fx;

  int n_data;

  int x;

  cout << "\n";

  cout << "TEST118:\n";

  cout << "  POISSON_CDF_VALUES returns values of\n";

  cout << "  the Poisson Cumulative Density Function.\n";

  cout << "\n";

  cout << "      A     X       CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    poisson_cdf_values ( n_data, a, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(8)                      << a  << "  "

         << setw(4)                      << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test1185 ( )

{

  double fx;

  int n;

  int n_data;

  double z;

  cout << "\n";

  cout << "TEST1185:\n";

  cout << "  POLYLOGARITHM_VALUES returns values of \n";

  cout << "  the polylogarithm function.\n";

  cout << "\n";

  cout << "     N      Z          Fx\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    polylogarithm_values ( n_data, n, z, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(24) << setprecision(16) << z  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test119 ( )

{

  int n_data;

  double p;

  double pr;

  double tc;

  cout << "\n";

  cout << "TEST119:\n";

  cout << "  PRANDTL_VALUES stores values of\n";

  cout << "  the Prandtl number of water\n";

  cout << "  as a function of temperature and pressure.\n";

  cout << "\n";

  cout << "      T            P            Pr(T,P)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    prandtl_values ( n_data, tc, p, pr );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << tc << "  "

         << setw(12) << p  << "  "

         << setw(12) << pr << "\n";

  }

  return;

}

void test120 ( )

{

  int n;

  int n_data;

  int p;

  cout << "\n";

  cout << "TEST120:\n";

  cout << "  PRIME_VALUES returns values of\n";

  cout << "  the prime function.\n";

  cout << "\n";

  cout << "           N          P[N]\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    prime_values ( n_data, n, p );

    if ( n_data == 0 )

    {

      break;

    }

    cout                  << "  "

         << setw(12) << n << "  "

         << setw(12) << p << "\n";

  }

  return;

}

void test121 ( )

{

  int n_data;

  double psat;

  double tc;

  cout << "\n";

  cout << "TEST121:\n";

  cout << "  PSAT_VALUES stores values of\n";

  cout << "  the saturation pressure of water\n";

  cout << "  as a function of temperature.\n";

  cout << "\n";

  cout << "      T            PSAT(T)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    psat_values ( n_data, tc, psat );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                         << "  "

         << setw(24) << setprecision(16) << tc   << "  "

         << setw(24) << setprecision(16) << psat << "\n";

  }

  return;

}

void test122 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST122\n";

  cout << "  PSI_VALUES stores values of\n";

  cout << "  the PSI function.\n";

  cout << "\n";

  cout << "      X            PSI(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    psi_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test123 ( )

{

  double fn;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST123:\n";

  cout << "  R8_FACTORIAL_VALUES stores values of\n";

  cout << "  the factorial function (using double arithmetic).\n";

  cout << "\n";

  cout << "      N       Factorial(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    r8_factorial_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(24) << setprecision(16) << fn << "\n";

  }

  return;

}

void test124 ( )

{

  double fn;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST124:\n";

  cout << "  R8_FACTORIAL_LOG_VALUES stores values of\n";

  cout << "  the logarithm of the factorial function\n";

  cout << "  (using real arithmetic).\n";

  cout << "\n";

  cout << "      N       Log(Factorial(N))\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    r8_factorial_log_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(24) << setprecision(16) << fn << "\n";

  }

  return;

}

void test125 ( )

{

  int n_data;

  double tc;

  double vir;

  cout << "\n";

  cout << "TEST125:\n";

  cout << "  SECVIR_VALUES stores values of\n";

  cout << "  the second virial coefficient of water\n";

  cout << "  as a function of temperature.\n";

  cout << "\n";

  cout << "      T            VIR(T)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   secvir_values ( n_data, tc, vir );

    if ( n_data == 0 )

    {

      break;

    }

    cout                    << "  "

         << setw(12) << tc  << "  "

         << setw(12) << vir << "\n";

  }

  return;

}

void test1255 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST1255:\n";

  cout << "  SHI_VALUES stores values of\n";

  cout << "  the hyperbolic sine integral function.\n";

  cout << "\n";

  cout << "      X            SHI(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   shi_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test126 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST126:\n";

  cout << "  SI_VALUES stores values of\n";

  cout << "  the sine integral function.\n";

  cout << "\n";

  cout << "      X            SI(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   si_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test127 ( )

{

  int fn;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST127:\n";

  cout << "  SIGMA_VALUES returns values of\n";

  cout << "  the SIGMA function.\n";

  cout << "\n";

  cout << "       N         SIGMA(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   sigma_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(12) << fn << "\n";

  }

  return;

}

void test1275 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST1275:\n";

  cout << "   SIN_VALUES stores values of the sine function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    sin_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test128 ( )

{

  double a;

  double b;

  double fx;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST128:\n";

  cout << "  SIN_POWER_INT_VALUES returns values of\n";

  cout << "  the integral of the N-th power of the sine function.\n";

  cout << "\n";

  cout << "         A         B       N        FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   sin_power_int_values ( n_data, a, b, n, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(8)                      << a  << "  "

         << setw(8)                      << b  << "  "

         << setw(6)                      << n  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test1283 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST1283:\n";

  cout << "   SINH_VALUES stores values of the hyperbolic sine function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    sinh_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test1285 ( )

{

  double fx;

  double j1;

  double j2;

  double j3;

  double j4;

  double j5;

  double j6;

  int n_data;

  cout << "\n";

  cout << "TEST1285:\n";

  cout << "  SIX_J_VALUES returns values of \n";

  cout << "  the Wigner 6J coefficient.\n";

  cout << "\n";

  cout << 

    "      J1      J2      J3      J4      J5      J6        SIX_J\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    six_j_values ( n_data, j1, j2, j3, j4, j5, j6, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(6) << j1

         << "  " << setw(6) << j2

         << "  " << setw(6) << j3

         << "  " << setw(6) << j4

         << "  " << setw(6) << j5

         << "  " << setw(6) << j6

         << "  " << setprecision(16) << setw(24) << fx << "\n";

  }

  return;

}

void test129 ( )

{

  double c;

  int n_data;

  double p;

  double tc;

  cout << "\n";

  cout << "TEST129:\n";

  cout << "  SOUND_VALUES stores values of\n";

  cout << "  the spead of sound in water\n";

  cout << "  as a function of temperature and pressure.\n";

  cout << "\n";

  cout << "      T            P            C(T,P)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   sound_values ( n_data, tc, p, c );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << tc << "  "

         << setw(12) << p  << "  "

         << setw(12) << c  << "\n";

  }

  return;

}

void test131 ( )

{  

  double fx;

  int n_data;

  int n;

  cout << "\n";

  cout << "TEST131:\n";

  cout << "  SPHERE_UNIT_AREA_VALUES stores values of\n";

  cout << "  the area of the unit sphere in various dimensions.\n";

  cout << "\n";

  cout << "      N           AREA\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    sphere_unit_area_values ( n_data, n, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test132 ( )

{  

  double fx;

  int n_data;

  int n;

  cout << "\n";

  cout << "TEST132:\n";

  cout << "  SPHERE_UNIT_VOLUME_VALUES stores values of\n";

  cout << "  the volume of the unit sphere in various dimensions.\n";

  cout << "\n";

  cout << "      N           VOLUME\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    sphere_unit_volume_values ( n_data, n, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(6)                      << n  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test1325 ( )

{

  int l;

  int m;

  int n_data;

  double phi;

  double theta;

  double yi;

  double yr;

  cout << "\n";

  cout << "TEST1325:\n";

  cout << "  SPHERICAL_HARMONIC_VALUES stores values of\n";

  cout << "  the spherical harmonic function.\n";

  cout << "\n";

  cout << "   L   M    THETA       PHI           Yr                    Yi\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    spherical_harmonic_values ( n_data, l, m, theta, phi, yr, yi );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(2)                      << l     << "  "

         << setw(2)                      << m     << "  "

         << setw(8)  << setprecision(4)  << theta << "  "

         << setw(8)  << setprecision(4)  << phi   << "  "

         << setw(24) << setprecision(16) << yr    << "  "

         << setw(24) << setprecision(16) << yi    << "\n";

  }

  return;

}

void test130 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST130:\n";

  cout << "  SQRT_VALUES returns some exact values.\n";

  cout << "\n";

  cout << "     X       Fx\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   sqrt_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test133 ( )

{

  int m;

  int n;

  int n_data;

  int s1;

  cout << "\n";

  cout << "TEST133:\n";

  cout << "  STIRLING1_VALUES returns values of\n";

  cout << "  the Stirling numbers of the first kind.\n";

  cout << "\n";

  cout << "     N     N        S1\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    stirling1_values ( n_data, n, m, s1 );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(6)  << m  << "  "

         << setw(12) << s1 << "\n";

  }

  return;

}

void test134 ( )

{

  int m;

  int n;

  int n_data;

  int s2;

  cout << "\n";

  cout << "TEST134:\n";

  cout << "  STIRLING2_VALUES returns values of\n";

  cout << "  the Stirling numbers of the second kind.\n";

  cout << "\n";

  cout << "     N     N        S2\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    stirling1_values ( n_data, n, m, s2 );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(6)  << m  << "  "

         << setw(12) << s2 << "\n";

  }

  return;

}

void test135 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST135:\n";

  cout << "  STROMGEN_VALUES stores values of \n";

  cout << "  the Stromgen function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    stromgen_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test136 ( )

{  

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST136:\n";

  cout << "  STRUVE_H0_VALUES stores values of\n";

  cout << "  the Struve H0 function.\n";

  cout << "\n";

  cout << "      X            H0(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    struve_h0_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test137 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST137:\n";

  cout << "  STRUVE_H1_VALUES stores values of\n";

  cout << "  the Struve H1 function.\n";

  cout << "\n";

  cout << "      X            H1(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   struve_h1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test138 ( )

{  

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST138:\n";

  cout << "  STRUVE_L0_VALUES stores values of\n";

  cout << "  the Struve L0 function.\n";

  cout << "\n";

  cout << "      X            L0(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    struve_l0_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test139 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST139:\n";

  cout << "  STRUVE_L1_VALUES stores values of\n";

  cout << "  the Struve L1 function.\n";

  cout << "\n";

  cout << "      X            L1(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   struve_l1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test140 ( )

{

  double c;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST140:\n";

  cout << "  STUDENT_CDF_VALUES returns values of\n";

  cout << "  the Student T Cumulative Density Function.\n";

  cout << "\n";

  cout << "      C     X       CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   student_cdf_values ( n_data, c, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                       << "  "

         << setw(16)                     << c  << "  "

         << setw(16)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test141 ( )

{

  int df;

  double fx;

  double lambda;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST141:\n";

  cout << "  STUDENT_NONCENTRAL_CDF_VALUES returns values of\n";

  cout << "  the noncentral Student T Cumulative Density Function.\n";

  cout << "\n";

  cout << "    DF     LAMBDA        X        CDF\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    student_noncentral_cdf_values ( n_data, df, lambda, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                           << "  "

         << setw(6)                      << df     << "  "

         << setw(8)                      << lambda << "  "

         << setw(8)                      << x      << "  "

         << setw(24) << setprecision(16) << fx     << "\n";

  }

  return;

}

void test1415 ( )

{

  int fn;

  int n;

  int n_data;

  cout << "\n";

  cout << " TEST1415:\n";

  cout << "   SUBFACTORIAL_VALUES returns values of\n";

  cout << "   the subfactorial function.\n";

  cout << "\n";

  cout << "      N       Subfactorial[N]\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    subfactorial_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(12) << fn << "\n";

  }

  return;

}

void test142 ( )

{

  int n_data;

  double sigma;

  double tc;

  cout << "\n";

  cout << "TEST142:\n";

  cout << "  SURTEN_VALUES stores values of\n";

  cout << "  the surface tension of water\n";

  cout << "  as a function of temperature.\n";

  cout << "\n";

  cout << "      T            SIGMA(T)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   surten_values ( n_data, tc, sigma );

    if ( n_data == 0 )

    {

      break;

    }

    cout                      << "  "

         << setw(12) << tc    << "  "

         << setw(12) << sigma << "\n";

  }

  return;

}

void test143 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST143:\n";

  cout << "  SYNCH1_VALUES stores values of \n";

  cout << "  the Synchrotron function of order 1.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    synch1_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test144 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST144:\n";

  cout << "  SYNCH2_VALUES stores values of \n";

  cout << "  the Synchrotron function of order 2.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    synch2_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test1445 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST1445:\n";

  cout << "   TAN_VALUES stores values of the tangent function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    tan_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test1447 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST1447:\n";

  cout << "   TANH_VALUES stores values of the hyperbolic tangent function.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    tanh_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test145 ( )

{

  int fn;

  int n;

  int n_data;

  cout << "\n";

  cout << "TEST145:\n";

  cout << "  TAU_VALUES returns values of\n";

  cout << "  the TAU function.\n";

  cout << "\n";

  cout << "     N         TAU(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   tau_values ( n_data, n, fn );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(6)  << n  << "  "

         << setw(12) << fn << "\n";

  }

  return;

}

void test146 ( )

{

  double lambda;

  int n_data;

  double p;

  double tc;

  cout << "\n";

  cout << "TEST146:\n";

  cout << "  THERCON_VALUES stores values of\n";

  cout << "  the thermal conductivity of water\n";

  cout << "  as a function of temperature and pressure.\n";

  cout << "\n";

  cout << "      T            P            LAMBDA(T,P)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   thercon_values ( n_data, tc, p, lambda );

    if ( n_data == 0 )

    {

      break;

    }

    cout                       << "  "

         << setw(12) << tc     << "  "

         << setw(12) << p      << "  "

         << setw(12) << lambda << "\n";

  }

  return;

}

void test1465 ( )

{

  double fx;

  double j1;

  double j2;

  double j3;

  double m1;

  double m2;

  double m3;

  int n_data;

  cout << "\n";

  cout << "TEST1465:\n";

  cout << "  THREE_J_VALUES returns values of\n";

  cout << "  the Wigner 3J coefficient.\n";

  cout << "\n";

  cout << "      J1      J2      J3      M1      M2      M3        THREE_J\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    three_j_values ( n_data, j1, j2, j3, m1, m2, m3, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(6) << j1

         << "  " << setw(6) << j2

         << "  " << setw(6) << j3

         << "  " << setw(6) << m1

         << "  " << setw(6) << m2

         << "  " << setw(6) << m3

         << "  " << setprecision(16) << setw(24) << fx << "\n";

  }

  return;

}

void test147 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST147:\n";

  cout << "  TRAN02_VALUES stores values of \n";

  cout << "  the Transport function of order 2.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    tran02_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test148 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST148:\n";

  cout << "  TRAN03_VALUES stores values of \n";

  cout << "  the Transport function of order 3.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    tran03_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test149 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST149:\n";

  cout << "  TRAN04_VALUES stores values of \n";

  cout << "  the Transport function of order 4.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    tran04_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test150 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST150:\n";

  cout << "  TRAN05_VALUES stores values of \n";

  cout << "  the Transport function of order 5.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    tran05_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test151 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST151:\n";

  cout << "  TRAN06_VALUES stores values of \n";

  cout << "  the Transport function of order 6.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    tran06_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test152 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST152:\n";

  cout << "  TRAN07_VALUES stores values of \n";

  cout << "  the Transport function of order 7.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    tran07_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test153 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST153:\n";

  cout << "  TRAN08_VALUES stores values of \n";

  cout << "  the Transport function of order 8.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    tran08_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(24) << setprecision ( 16 ) << x  

         << "  " << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test154 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST154:\n";

  cout << "  TRAN09_VALUES stores values of \n";

  cout << "  the Transport function of order 9.\n";

  cout << "\n";

  cout << "                X                     FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    tran09_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                          << "  "

         << setw(24) << setprecision ( 16 ) << x  << "  "

         << setw(24) << setprecision ( 16 ) << fx << "\n";

  }

  return;

}

void test1545 ( )

{

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST1545\n";

  cout << "  TRIGAMMA_VALUES stores values of\n";

  cout << "  the TriGamma function.\n";

  cout << "\n";

  cout << "      X            FX\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    trigamma_values ( n_data, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(12)                     << x  

         << "  " << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test1546 ( )

{

  double a;

  double b;

  double fx;

  double mu;

  int n_data;

  double sigma;

  double x;

  cout << "\n";

  cout << "TEST1546:\n";

  cout << "  TRUNCATED_NORMAL_AB_CDF_VALUES stores values of\n";

  cout << "  the Truncated Normal Cumulative Density Function.\n";

  cout << "\n";

  cout << "        MU     SIGMA       A         B         X        CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    truncated_normal_ab_cdf_values ( n_data, mu, sigma, a, b, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(8) << mu

         << "  " << setw(8) << sigma

         << "  " << setw(8) << a

         << "  " << setw(8) << b

         << "  " << setw(8) << x

         << "  " << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test1547 ( )

{

  double a;

  double b;

  double fx;

  double mu;

  int n_data;

  double sigma;

  double x;

  cout << "\n";

  cout << "TEST1547:\n";

  cout << "  TRUNCATED_NORMAL_AB_PDF_VALUES stores values of\n";

  cout << "  the Truncated Normal Probability Density Function.\n";

  cout << "\n";

  cout << "        MU     SIGMA       A         B         X        PDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    truncated_normal_ab_pdf_values ( n_data, mu, sigma, a, b, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(8) << mu

         << "  " << setw(8) << sigma

         << "  " << setw(8) << a

         << "  " << setw(8) << b

         << "  " << setw(8) << x

         << "  " << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test1548 ( )

{

  double a;

  double fx;

  double mu;

  int n_data;

  double sigma;

  double x;

  cout << "\n";

  cout << "TEST1548:\n";

  cout << "  TRUNCATED_NORMAL_A_CDF_VALUES stores values of\n";

  cout << "  the lower Truncated Normal Cumulative Density Function.\n";

  cout << "\n";

  cout << "        MU     SIGMA       A         X        CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    truncated_normal_a_cdf_values ( n_data, mu, sigma, a, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(8) << mu

         << "  " << setw(8) << sigma

         << "  " << setw(8) << a

         << "  " << setw(8) << x

         << "  " << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test15485 ( )

{

  double a;

  double fx;

  double mu;

  int n_data;

  double sigma;

  double x;

  cout << "\n";

  cout << "TEST1585:\n";

  cout << "  TRUNCATED_NORMAL_A_PDF_VALUES stores values of\n";

  cout << "  the lower Truncated Normal Probability Density Function.\n";

  cout << "\n";

  cout << "        MU     SIGMA       A         X        PDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    truncated_normal_a_pdf_values ( n_data, mu, sigma, a, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(8) << mu

         << "  " << setw(8) << sigma

         << "  " << setw(8) << a

         << "  " << setw(8) << x

         << "  " << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test1549 ( )

{

  double b;

  double fx;

  double mu;

  int n_data;

  double sigma;

  double x;

  cout << "\n";

  cout << "TEST1549:\n";

  cout << "  TRUNCATED_NORMAL_B_CDF_VALUES stores values of\n";

  cout << "  the upper Truncated Normal Cumulative Density Function.\n";

  cout << "\n";

  cout << "        MU     SIGMA       B         X        CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    truncated_normal_b_cdf_values ( n_data, mu, sigma, b, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(8) << mu

         << "  " << setw(8) << sigma

         << "  " << setw(8) << b

         << "  " << setw(8) << x

         << "  " << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test15495 ( )

{

  double a;

  double b;

  double fx;

  double mu;

  int n_data;

  double sigma;

  double x;

  cout << "\n";

  cout << "TEST15495:\n";

  cout << "  TRUNCATED_NORMAL_B_PDF_VALUES stores values of\n";

  cout << "  the upper Truncated Normal Probability Density Function.\n";

  cout << "\n";

  cout << "        MU     SIGMA       B         X        PDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    truncated_normal_b_pdf_values ( n_data, mu, sigma, b, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout << "  " << setw(8) << mu

         << "  " << setw(8) << sigma

         << "  " << setw(8) << b

         << "  " << setw(8) << x

         << "  " << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test155 ( )

{

  int n_data;

  double p;

  double tc;

  cout << "\n";

  cout << "TEST155:\n";

  cout << "  TSAT_VALUES stores values of\n";

  cout << "  the saturation temperature\n";

  cout << "  as a function of pressure.\n";

  cout << "\n";

  cout << "      P           Tsat(P)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   tsat_values ( n_data, p, tc );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << p  << "  "

         << setw(12) << tc << "\n";

  }

  return;

}

void test156 ( )

{

  int base;

  int n_data;

  int seed;

  double value;

  cout << "\n";

  cout << "TEST156:\n";

  cout << "  VAN_DER_CORPUT_VALUES stores values of\n";

  cout << "  the van der Corput sequence in a given base.\n";

  cout << "\n";

  cout << "      BASE      SEED    VDC(BASE,SEED)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    van_der_corput_values ( n_data, base, seed, value );

    if ( n_data == 0 )

    {

      break;

    }

    cout                      << "  "

         << setw(8)  << base  << "  "

         << setw(8)  << seed  << "  "

         << setw(14) << value << "\n";

  }

  return;

}

void test157 ( )

{

  double eta;

  int n_data;

  double p;

  double tc;

  cout << "\n";

  cout << "TEST157:\n";

  cout << "  VISCOSITY_VALUES stores values of\n";

  cout << "  the viscosity of water\n";

  cout << "  as a function of temperature and pressure.\n";

  cout << "\n";

  cout << "      T            P            ETA(T,P)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

   viscosity_values ( n_data, tc, p, eta );

    if ( n_data == 0 )

    {

      break;

    }

    cout                   << "  "

         << setw(12) << tc  << "  "

         << setw(12) << p   << "  "

         << setw(12) << eta << "\n";

  }

  return;

}

void test1575 ( )

{

  double a;

  double b;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST1575:\n";

  cout << "  VON_MISES_CDF_VALUES stores values of\n";

  cout << "  the von Mises CDF.\n";

  cout << "\n";

  cout << "      A            B            X            CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    von_mises_cdf_values ( n_data, a, b, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(12)                     << a  << "  "

         << setw(12)                     << b  << "  "

         << setw(12)                     << x  << "  "

         << setw(24) << setprecision(16) << fx << "\n";

  }

  return;

}

void test158 ( )

{

  double alpha;

  double beta;

  double fx;

  int n_data;

  double x;

  cout << "\n";

  cout << "TEST158:\n";

  cout << "  WEIBULL_CDF_VALUES returns values of \n";

  cout << "  the Weibull Cumulative Density Function.\n";

  cout << "\n";

  cout << "     Alpha   Beta        X   CDF(X)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    weibull_cdf_values ( n_data, alpha, beta, x, fx );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                 << "  "

         << setw(8)                      << alpha << "  "

         << setw(8)                      << beta  << "  "

         << setw(8)                      << x     << "  "

         << setw(24) << setprecision(16) << fx    << "\n";

  }

  return;

}

void test159 ( )

{

  int n;

  int n_data;

  double zeta;

  cout << "\n";

  cout << "TEST159:\n";

  cout << "  ZETA_VALUES returns values of \n";

  cout << "  the Riemann Zeta function.\n";

  cout << "\n";

  cout << "     N        ZETA(N)\n";

  cout << "\n";

  n_data = 0;

  for ( ; ; )

  {

    zeta_values ( n_data, n, zeta );

    if ( n_data == 0 )

    {

      break;

    }

    cout                                         << "  "

         << setw(6)                      << n    << "  "

         << setw(24) << setprecision(16) << zeta << "\n";

  }

  return;

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/