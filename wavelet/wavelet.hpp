
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/double *cascade ( int n, int t_length, double t[], int c_length, double c[] );

double *daub_coefficients ( int n );

double *daub2_matrix ( int n );

double daub2_scale ( int n, double x );

double *daub2_transform ( int n, double x[] );

double *daub2_transform_inverse ( int n, double y[] );

double *daub4_matrix ( int n );

double daub4_scale ( int n, double x );

double *daub4_transform ( int n, double x[] );

double *daub4_transform_inverse ( int n, double y[] );

double *daub6_matrix ( int n );

double daub6_scale ( int n, double x );

double *daub6_transform ( int n, double x[] );

double *daub6_transform_inverse ( int n, double y[] );

double *daub8_matrix ( int n );

double daub8_scale ( int n, double x );

double *daub8_transform ( int n, double x[] );

double *daub8_transform_inverse ( int n, double y[] );

double *daub10_matrix ( int n );

double daub10_scale ( int n, double x );

double *daub10_transform ( int n, double x[] );

double *daub10_transform_inverse ( int n, double y[] );

double *daub12_matrix ( int n );

double *daub12_transform ( int n, double x[] );

double *daub12_transform_inverse ( int n, double y[] );

double *daub14_transform ( int n, double x[] );

double *daub14_transform_inverse ( int n, double y[] );

double *daub16_transform ( int n, double x[] );

double *daub16_transform_inverse ( int n, double y[] );

double *daub18_transform ( int n, double x[] );

double *daub18_transform_inverse ( int n, double y[] );

double *daub20_transform ( int n, double x[] );

double *daub20_transform_inverse ( int n, double y[] );

bool i4_is_power_of_2 ( int n );

int i4_max ( int i1, int i2 );

int i4_min ( int i1, int i2 );

int i4_modp ( int i, int j );

int i4_wrap ( int ival, int ilo, int ihi );

double r8_uniform_01 ( int &seed );

double r8mat_is_identity ( int n, double a[] );

double *r8mat_zero_new ( int m, int n );

double *r8vec_conjugate ( int n, double c[] );

double *r8vec_convolution ( int m, double x[], int n, double y[] );

double *r8vec_copy_new ( int n, double a1[] );

double *r8vec_linspace_new ( int n, double a_first, double a_last );

void r8vec_print ( int n, double a[], string title );

double *r8vec_uniform_01_new ( int n, int &seed );

void timestamp ( );

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/