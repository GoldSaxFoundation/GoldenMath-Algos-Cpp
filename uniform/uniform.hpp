
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/complex <float> c4_uniform_01 ( int &seed );

void c4mat_uniform_01 ( int m, int n, int &seed, complex <float> c[] );

complex <float> *c4mat_uniform_01_new ( int m, int n, int &seed );

void c4mat_uniform_write ( int m, int n, int seed, complex <float> r[], 

  char *file_out_name );

void c4vec_uniform_01 ( int n, int &seed, complex <float> c[] );

complex <float> *c4vec_uniform_01_new ( int n, int &seed );

complex <double> c8_uniform_01 ( int &seed );

void c8mat_uniform_01 ( int m, int n, int &seed, complex <double> c[] );

complex <double> *c8mat_uniform_01_new ( int m, int n, int &seed );

void c8vec_uniform_01 ( int n, int &seed, complex <double> c[] );

complex <double> *c8vec_uniform_01_new ( int n, int &seed );

char ch_uniform_ab ( char a, char b, int &seed );

int congruence ( int a, int b, int c, bool *error );

char digit_to_ch ( int i );

int get_seed ( );

int i4_gcd ( int i, int j );

int i4_huge ( );

int i4_log_10 ( int i );

int i4_max ( int i1, int i2 );

int i4_min ( int i1, int i2 );

int i4_seed_advance ( int seed );

int i4_sign ( int i );

void i4_swap ( int *i, int *j );

char *i4_to_s ( int i );

int i4_uniform_0i ( int &seed );

int i4_uniform_ab ( int a, int b, int &seed );

void i4mat_uniform_ab ( int m, int n, int a, int b, int &seed, int x[] );

int *i4mat_uniform_ab_new ( int m, int n, int a, int b, int &seed );

int i4vec_max ( int n, int a[] );

float i4vec_mean ( int n, int x[] );

int i4vec_min ( int n, int a[] );

void i4vec_uniform_ab ( int n, int a, int b, int &seed, int x[]);

int *i4vec_uniform_ab_new ( int n, int a, int b, int &seed );

float i4vec_variance ( int n, int x[] );

long long int i8_huge ( );

long long int i8_max ( long long int i1, long long int i2 );

long long int i8_min ( long long int i1, long long int i2 );

long long int i8_uniform_ab ( long long int a, long long int b, int &seed );

bool l_uniform ( int &seed );

void lcrg_anbn ( int a, int b, int c, int n, int *an, int *bn );

int lcrg_evaluate ( int a, int b, int c, int x );

int lcrg_seed ( int a, int b, int c, int n, int seed );

void lmat_uniform ( int m, int n, int &seed, bool lmat[] );

bool *lmat_uniform_new ( int m, int n, int &seed );

bool *lvec_uniform_new ( int n, int &seed );

int power_mod ( int a, int n, int m );

float r4_abs ( float x );

int r4_nint ( float x );

float r4_uniform_ab ( float a, float b, int &seed );

float r4_uniform_01 ( int &seed );

void r4mat_uniform_ab ( int m, int n, float b, float c, int &seed, float r[] );

float *r4mat_uniform_ab_new ( int m, int n, float b, float c, int &seed );

void r4mat_uniform_01 ( int m, int n, int &seed, float r[] );

float *r4mat_uniform_01_new ( int m, int n, int &seed );

void r4vec_uniform_ab ( int n, float b, float c, int &seed, float r[] );

float *r4vec_uniform_ab_new ( int n, float b, float c, int &seed );

void r4vec_uniform_01 ( int n, int &seed, float r[] );

float *r4vec_uniform_01_new ( int n, int &seed );

double r8_abs ( double x );

int r8_nint ( double x );

double r8_uniform_ab ( double a, double b, int &seed );

double r8_uniform_01 ( int &seed );

double *r8col_uniform_ab_new ( int m, int n, double a[], double b[], int &seed );

double r8i8_uniform_ab ( double a, double b, long long int &seed );

double r8i8_uniform_01 ( long long int &seed );

void r8mat_uniform_01 ( int m, int n, int &seed, double r[] );

double *r8mat_uniform_01_new ( int m, int n, int &seed );

void r8mat_uniform_ab ( int m, int n, double a, double b, int &seed, double r[] );

double *r8mat_uniform_ab_new ( int m, int n, double a, double b, int &seed );

void r8mat_uniform_ab ( int m, int n, double a[], double b[], int &seed, double r[] );

double *r8mat_uniform_ab_new ( int m, int n, double a[], double b[], int &seed );

double *r8row_uniform_ab_new ( int m, int n, double a[], double b[], int &seed );

void r8vec_copy ( int n, double a1[], double a2[] );

double *r8vec_normal_01_new ( int n, int &seed );

void r8vec_uniform_01 ( int n, int &seed, double r[] );

double *r8vec_uniform_01_new ( int n, int &seed );

void r8vec_uniform_ab ( int n, double a, double b, int &seed, double x[] );

double *r8vec_uniform_ab_new ( int n, double a, double b, int &seed );

void r8vec_uniform_abvec ( int n, double a[], double b[], int &seed, double x[] );

double *r8vec_uniform_abvec_new ( int n, double a[], double b[], int &seed );

double *r8vec_uniform_unit_new ( int dim_num, int &seed );

void timestamp ( );

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/