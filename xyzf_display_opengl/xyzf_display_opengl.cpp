
/*Owner & Copyrights: Vance King Saxbe. A.*/

/* Copyright (c) <2014> Author Vance King Saxbe. A, and contributors Power Dominion Enterprise, Precieux Consulting and other contributors. Modelled, Architected and designed by Vance King Saxbe. A. with the geeks from GoldSax Consulting and GoldSax Technologies email @vsaxbe@yahoo.com. Development teams from Power Dominion Enterprise, Precieux Consulting. Project sponsored by GoldSax Foundation, GoldSax Group and executed by GoldSax Manager.*/# include <cstdlib>

# include <ctime>

# include <cmath>

# include <fstream>

# include <iostream>

# include <iomanip>

# include <cstring>

# include <GLUT/glut.h>

using namespace std;

int main ( int argc, char *argv[] );

bool ch_eqi ( char ch1, char ch2 );

int ch_to_digit ( char ch );

void display ( );

void mouse ( int btn, int state, int x, int y );

int i4vec_max ( int n, int a[] );

int i4vec_min ( int n, int a[] );

void myinit ( );

void myReshape ( int w, int h );

double r8_max ( double x, double y );

double r8_min ( double x, double y );

double *r83vec_max ( int n, double a[] );

double *r83vec_min ( int n, double a[] );

int s_len_trim ( string s );

int s_to_i4 ( string s, int *last, bool *error );

bool s_to_i4vec ( string s, int n, int ivec[] );

double s_to_r8 ( string s, int *lchar, bool *error );

bool s_to_r8vec ( string s, int n, double rvec[] );

int s_word_count ( string s );

void spin_image ( );

void timestamp ( );

void xyz_data_print ( int point_num, double xyz[] );

void xyz_data_read ( string input_filename, int point_num, double xyz[] );

void xyz_header_print ( int point_num );

void xyz_header_read ( string input_filename, int *point_num );

void xyzf_data_print ( int point_num, int face_num,

  int face_data_num, int face_pointer[], int face_data[] );

void xyzf_data_read ( string input_filename, int face_num, int face_data_num,

  int face_pointer[], int face_data[] );

void xyzf_header_print ( int point_num, int face_num, int face_data_num );

void xyzf_header_read ( string input_filename, int *face_num, 

  int *face_data_num );

  static GLint axis = 2;

  int dim_num = 3;

  int *face_data = NULL;

  int face_data_num;

  int face_num;

  int *face_pointer = NULL;

  int pixel_height;

  int pixel_width;

  int point_num = 0;

  bool spinning = true;

  static GLfloat theta[3] = { 0.0, 0.0, 0.0 };

  double theta_speed = 0.020;

  double *xyz = NULL;

  double xyz_center[3];

  double *xyz_max = NULL;

  double *xyz_min = NULL;

  double xyz_range[3];

  double xyz_scale;

int main ( int argc, char *argv[] )

{

  int dim;

  int i;

  int point;

  string prefix;

  string xyz_filename;

  string xyzf_filename;

  cout << "\n";

  timestamp ( );

  cout << "\n";

  cout << "XYZF_DISPLAY_OPENGL:\n";

  cout << "  C++ version\n";

  cout << "\n";

  cout << "  Compiled on " << __DATE__ << " at " << __TIME__ << ".\n";

  cout << "\n";

  cout << "  This is a program which uses OpenGL\n";

  cout << "  to display the points and faces defined by an XYZF file.\n";

  if ( argc <= 1 ) 

  {

    cout << "\n";

    cout << "XYZF_DISPLAY_OPENGL:\n";

    cout << "  Please enter the \"prefix\" of the XYZ and XYZF files.\n";

    cin >> prefix;

  }

  else 

  {

    prefix = argv[1];

  }

  xyz_filename = prefix + ".xyz";

  xyz_header_read ( xyz_filename, &point_num );

  cout << "\n";

  cout << "  The number of points POINT_NUM = " << point_num << "\n";

  xyz = new double[3*point_num];

  xyz_data_read ( xyz_filename, point_num, xyz );

  if ( false )

  {

    xyz_data_print ( point_num, xyz );

  }

  xyz_min = r83vec_min ( point_num, xyz );

  xyz_max = r83vec_max ( point_num, xyz );

  xyz_range[0] = xyz_max[0] - xyz_min[0];

  xyz_range[1] = xyz_max[1] - xyz_min[1];

  xyz_range[2] = xyz_max[2] - xyz_min[2];

  cout << "\n";

  cout << "  Minimum: " << xyz_min[0]

       << "  " << xyz_min[1]

       << "  " << xyz_min[2] << "\n";

  cout << "  Maximum: " << xyz_max[0] 

       << "  " << xyz_max[1]

       << "  " << xyz_max[2] << "\n";

  cout << "  Range:   " << xyz_range[0] 

       << "  " << xyz_range[1]

       << "  " << xyz_range[2] << "\n";

  if ( xyz_range[0] == 0.0 ) 

  {

    cout << "\n";

    cout << "XYZL_DISPLAY_OPENGL - Fatal error!\n";

    cout << "  The X data range is 0.\n";

    exit ( 1 );

  }

  if ( xyz_range[1] == 0.0 ) 

  {

    cout << "\n";

    cout << "XYZL_DISPLAY_OPENGL - Fatal error!\n";

    cout << "  The Y data range is 0.\n";

    exit ( 1 );

  }

  if ( xyz_range[2] == 0.0 ) 

  {

    cout << "\n";

    cout << "XYZL_DISPLAY_OPENGL - Fatal error!\n";

    cout << "  The Z data range is 0.\n";

    exit ( 1 );

  }

  xyz_scale = 0.0;

  for ( dim = 0; dim < dim_num; dim++ )

  {

    xyz_center[dim] = ( xyz_min[dim] + xyz_max[dim] ) / 2.0;

    xyz_scale = r8_max ( xyz_scale, ( xyz_max[dim] - xyz_min[dim] ) / 2.0 );

  }

  for ( point = 0; point < point_num; point++ )

  {

    for ( dim = 0; dim < dim_num; dim++ )

    {

      xyz[dim+point*dim_num] = ( xyz[dim+point*dim_num] - xyz_center[dim] ) / xyz_scale;

    }

  }

  xyzf_filename = prefix + ".xyzf";

  xyzf_header_read ( xyzf_filename, &face_num, &face_data_num );

  cout << "\n";

  cout << "  The number of faces FACE_NUM           = " << face_num << "\n";

  cout << "  The number of face items FACE_DATA_NUM = " << face_data_num << "\n";

  face_pointer = new int[face_num+1];

  face_data = new int[face_data_num];

  xyzf_data_read ( xyzf_filename, face_num, face_data_num, face_pointer, face_data );

  if ( false )

  {

    xyzf_data_print ( point_num, face_num, face_data_num, face_pointer, face_data );

  }

  if ( 0 < i4vec_min ( face_data_num, face_data ) &&

       point_num == i4vec_max ( face_data_num, face_data ) )

  {

    cout << "\n";

    cout << "  Converting face data from 1-based to 0-based indexing.\n";

    for ( i = 0; i < face_data_num; i++ )

    {

      face_data[i] = face_data[i] - 1;

    }

  }

  glutInit ( &argc, argv );

  glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

  glutInitWindowSize ( 500, 500 );

  glutInitWindowPosition ( 0, 0 );

  glutCreateWindow ( prefix.c_str ( ) );

  glutReshapeFunc ( myReshape );

  glutDisplayFunc ( display );

  glutIdleFunc ( spin_image );

  glutMouseFunc ( mouse );

  glEnable ( GL_DEPTH_TEST );

  myinit ( );

  glutMainLoop ( );

  delete [] face_data;

  delete [] face_pointer;

  delete [] xyz;

  cout << "\n";

  cout << "XYZL_DISPLAY_OPENGL:\n";

  cout << "  Normal end of execution.\n";

  cout << "\n";

  timestamp ( );

  return 0;

}

bool ch_eqi ( char ch1, char ch2 )

{

  if ( 97 <= ch1 && ch1 <= 122 ) 

  {

    ch1 = ch1 - 32;

  } 

  if ( 97 <= ch2 && ch2 <= 122 ) 

  {

    ch2 = ch2 - 32;

  }     

  return ( ch1 == ch2 );

}

int ch_to_digit ( char ch )

{

  int digit;

  if ( '0' <= ch && ch <= '9' )

  {

    digit = ch - '0';

  }

  else if ( ch == ' ' )

  {

    digit = 0;

  }

  else

  {

    digit = -1;

  }

  return digit;

}

void display ( )

{

  int face;

  int j;

  float p[3];

  int point;

  glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glLoadIdentity ( );

  

  glRotatef ( theta[0], 1.0, 0.0, 0.0 );

  glRotatef ( theta[1], 0.0, 1.0, 0.0 );

  glRotatef ( theta[2], 0.0, 0.0, 1.0 );

  glColor3f ( 0.80, 0.95, 0.90 );

  for ( face = 0; face < face_num; face++ )

  {

    glBegin ( GL_POLYGON );

    for ( j = face_pointer[face]; j < face_pointer[face+1]; j++ )

    {

      point = face_data[j];

      p[0] = ( float ) xyz[0+point*dim_num];

      p[1] = ( float ) xyz[1+point*dim_num];

      p[2] = ( float ) xyz[2+point*dim_num];

      glVertex3fv ( p );

    }

    glEnd ( );

  }

  glColor3f ( 0.0, 0.0, 1.0 );

  for ( face = 0; face < face_num; face++ )

  {

    glBegin ( GL_LINE_STRIP );

    for ( j = face_pointer[face]; j < face_pointer[face+1]; j++ )

    {

      point = face_data[j];

      p[0] = ( float ) xyz[0+point*dim_num];

      p[1] = ( float ) xyz[1+point*dim_num];

      p[2] = ( float ) xyz[2+point*dim_num];

      glVertex3fv ( p );

    }

    j = face_pointer[face];

    point = face_data[j];

    p[0] = ( float ) xyz[0+point*dim_num];

    p[1] = ( float ) xyz[1+point*dim_num];

    p[2] = ( float ) xyz[2+point*dim_num];

    glVertex3fv ( p );

    glEnd ( );

  }

  glColor3f ( 1.0, 0.0, 0.0 );

  for ( point = 0; point < point_num; point++ )

  {

    glBegin ( GL_POINTS );

      p[0] = ( float ) xyz[0+point*dim_num];

      p[1] = ( float ) xyz[1+point*dim_num];

      p[2] = ( float ) xyz[2+point*dim_num];

      glVertex3fv ( p );

    glEnd ( );

  }

  glFlush ( );

  glutSwapBuffers ( );

  return;

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

void mouse ( int btn, int state, int x, int y )

{

  if ( ( btn == GLUT_LEFT_BUTTON   && state == GLUT_DOWN ) ||

       ( btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN ) ||

       ( btn == GLUT_RIGHT_BUTTON  && state == GLUT_DOWN ) )

  {

    if ( spinning )

    {

      spinning = false;

      theta_speed = 0.0;

    }

    else

    {

      spinning = true;

      theta_speed = 0.020;

      axis = axis + 1;

    }

  }

  axis = axis % 3;

  return;

}

void myinit ( )

{

  GLfloat line_width;

  GLfloat point_size;

  glClearColor ( 1.0, 1.0, 1.0, 1.0 );

  glEnable ( GL_POINT_SMOOTH );

  glEnable ( GL_LINE_SMOOTH );

  glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

  glHint ( GL_LINE_SMOOTH_HINT, GL_DONT_CARE );

  if ( point_num <= 400 )

  {

    point_size = 6.0;

  }

  else if ( point_num <= 1000 )

  {

    point_size = 3.0;

  }

  else

  {

    point_size = 1.0;

  }

  glPointSize ( point_size );

  line_width = 2.0;

  glLineWidth ( line_width );

  return;

}

void myReshape ( int w, int h )

{

  glViewport ( 0, 0, w, h );

  glMatrixMode ( GL_PROJECTION );

  glLoadIdentity ( );

  if ( w <= h )

  {

    glOrtho ( 

      -1.05, +1.05, 

      - 1.05 * ( GLfloat ) h / ( GLfloat ) w, + 1.05 * ( GLfloat ) h / ( GLfloat ) w, 

      -10.0, 10.0 );

  }

  else

  {

    glOrtho ( 

      - 1.05 * ( GLfloat ) h / ( GLfloat ) w, + 1.05 * ( GLfloat ) h / ( GLfloat ) w,  

      - 1.05, + 1.05, 

      -10.0, 10.0 );

  }

  glMatrixMode ( GL_MODELVIEW );

  return;

}

double r8_max ( double x, double y )

{

  double value;

  if ( y < x )

  {

    value = x;

  } 

  else

  {

    value = y;

  }

  return value;

}

double r8_min ( double x, double y )

{

  double value;

  if ( y < x )

  {

    value = y;

  } 

  else

  {

    value = x;

  }

  return value;

}

double *r83vec_max ( int n, double a[] )

{

# define DIM_NUM 3

  double *amax = NULL;

  int i;

  int j;

  if ( n <= 0 )

  {

    return NULL;

  }

  amax = new double[DIM_NUM];

  for ( i = 0; i < DIM_NUM; i++ )

  {

    amax[i] = a[i+0*DIM_NUM];

    for ( j = 1; j < n; j++ )

    {

      if ( amax[i] < a[i+j*DIM_NUM] )

      {

        amax[i] = a[i+j*DIM_NUM];

      }

    }

  }

  return amax;

# undef DIM_NUM

}

double *r83vec_min ( int n, double a[] )

{

# define DIM_NUM 3

  double *amin = NULL;

  int i;

  int j;

  if ( n <= 0 )

  {

    return NULL;

  }

  amin = new double[DIM_NUM];

  for ( i = 0; i < DIM_NUM; i++ )

  {

    amin[i] = a[i+0*DIM_NUM];

    for ( j = 1; j < n; j++ )

    {

      if ( a[i+j*DIM_NUM] < amin[i] )

      {

        amin[i] = a[i+j*DIM_NUM];

      }

    }

  }

  return amin;

# undef DIM_NUM

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

int s_to_i4 ( string s, int *last, bool *error )

{

  char c;

  int i;

  int isgn;

  int istate;

  int ival;

  *error = false;

  istate = 0;

  isgn = 1;

  i = 0;

  ival = 0;

  for ( ; ; ) 

  {

    c = s[i];

    i = i + 1;

    if ( istate == 0 )

    {

      if ( c == ' ' )

      {

      }

      else if ( c == '-' )

      {

        istate = 1;

        isgn = -1;

      }

      else if ( c == '+' )

      {

        istate = 1;

        isgn = + 1;

      }

      else if ( '0' <= c && c <= '9' )

      {

        istate = 2;

        ival = c - '0';

      }

      else

      {

        *error = true;

        return ival;

      }

    }

    else if ( istate == 1 )

    {

      if ( c == ' ' )

      {

      }

      else if ( '0' <= c && c <= '9' )

      {

        istate = 2;

        ival = c - '0';

      }

      else

      {

        *error = true;

        return ival;

      }

    }

    else if ( istate == 2 )

    {

      if ( '0' <= c && c <= '9' )

      {

        ival = 10 * (ival) + c - '0';

      }

      else

      {

        ival = isgn * ival;

        *last = i - 1;

        return ival;

      }

    }

  }

  if ( istate == 2 )

  {

    ival = isgn * ival;

    *last = s_len_trim ( s );

  }

  else

  {

    *error = true;

    *last = 0;

  }

  return ival;

}

bool s_to_i4vec ( string s, int n, int ivec[] )

{

  int begin;

  bool error;

  int i;

  int lchar;

  int length;

  begin = 0;

  length = s.length ( );

  error = 0;

  for ( i = 0; i < n; i++ )

  {

    ivec[i] = s_to_i4 ( s.substr(begin,length), &lchar, &error );

    if ( error )

    {

      return error;

    }

    begin = begin + lchar;

    length = length - lchar;

  }

  return error;

}

double s_to_r8 ( string s, int *lchar, bool *error )

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

bool s_to_r8vec ( string s, int n, double rvec[] )

{

  int begin;

  bool error;

  int i;

  int lchar;

  int length;

  begin = 0;

  length = s.length ( );

  error = 0;

  for ( i = 0; i < n; i++ )

  {

    rvec[i] = s_to_r8 ( s.substr(begin,length), &lchar, &error );

    if ( error )

    {

      return error;

    }

    begin = begin + lchar;

    length = length - lchar;

  }

  return error;

}

int s_word_count ( string s )

{

  bool blank;

  int char_count;

  int i;

  int word_count;

  word_count = 0;

  blank = true;

  char_count = s.length ( );

  for ( i = 0; i < char_count; i++ )

  {

    if ( isspace ( s[i] ) )

    {

      blank = true;

    }

    else if ( blank )

    {

      word_count = word_count + 1;

      blank = false;

    }

  }

  return word_count;

}

void spin_image ( )

{

  theta[axis] = theta[axis] + theta_speed;

  if ( 360.0 < theta[axis] ) 

  {

    theta[axis] = theta[axis] - 360.0;

  }

  glutPostRedisplay ( );

  return;

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

void xyz_data_print ( int point_num, double xyz[] )

{

  int j;

  cout << "\n";

  for ( j = 0; j < point_num; j++ )

  {

    cout << setw(10) << xyz[0+j*3] << "  "

         << setw(10) << xyz[1+j*3] << "  " 

         << setw(10) << xyz[2+j*3] << "\n";

  }

  return;

}

void xyz_data_read ( string input_filename, int point_num, double xyz[] )

{

  bool error;

  int i;

  ifstream input;

  int j;

  string text;

  double temp[3];

  input.open ( input_filename.c_str ( ) );

  if ( !input )

  {

    cout << "\n";

    cout << "XYZ_DATA_READ - Fatal error!\n";

    cout << "  Cannot open the input file \"" << input_filename << "\".\n";

    exit ( 1 );

  }

  j = 0;

  while ( j < point_num )

  {

    getline ( input, text );

    if ( input.eof ( ) )

    {

      break;

    }

    

    if ( text[0] == '#' || s_len_trim ( text ) == 0 )

    {

      continue;

    }

    error = s_to_r8vec ( text, 3, temp );

    if ( error )

    {

      cout << "\n";

      cout << "XYZ_DATA_READ - Fatal error!\n";

      cout << "  S_TO_R8VEC returned error flag.\n";

      exit ( 1 );

    }

    xyz[0+j*3] = temp[0];

    xyz[1+j*3] = temp[1];

    xyz[2+j*3] = temp[2];

    j = j + 1;

  }

  input.close ( );

  return;

}

void xyz_header_print ( int point_num )

{

  cout << "\n";

  cout << "  Number of points = " << point_num << "\n";

  return;

}

void xyz_header_read ( string input_filename, int *point_num )

{

  ifstream input;

  string text;

  *point_num = 0;

  input.open ( input_filename.c_str ( ) );

  if ( !input )

  {

    cout << "\n";

    cout << "XYZ_HEADER_READ - Fatal error!\n";

    cout << "  Cannot open the input file \"" << input_filename << "\".\n";

    return;

  }

  while ( 1 )

  {

    getline ( input, text );

    if ( input.eof ( ) )

    {

      break;

    }

    if ( text[0] == '#' || s_len_trim ( text ) == 0 )

    {

      continue;

    }

    *point_num = *point_num + 1;

  }

  input.close ( );

  return;

}

void xyzf_data_print ( int point_num, int face_num,

  int face_data_num, int face_pointer[], int face_data[] )

{

  int i;

  int face;

  cout << "\n";

  for ( face = 0; face < face_num; face++ )

  {

    cout << "  " << setw(4) << face << "  "

         << "  " << setw(8) << face_pointer[face]

         << "  " << setw(8) << face_pointer[face+1] - 1 << "\n"; 

  }

  cout << "\n";

  for ( face = 0; face < face_num; face++ )

  {

    cout << "  " << setw(4) << face << "  ";

    for ( i = face_pointer[face]; i < face_pointer[face+1]; i++ )

    {

      cout << "  " << setw(4) << face_data[i];

    }

    cout << "\n";    

  }

  return;

}

void xyzf_data_read ( string input_filename, int face_num, int face_data_num,

  int face_pointer[], int face_data[] )

{

  int face;

  int ierror;

  int ilo;

  ifstream input;

  int n;

  string text;

  input.open ( input_filename.c_str() );

  if ( !input )

  {

    cout << "\n";

    cout << "XYZF_DATA_READ - Fatal error!\n";

    cout << "  Cannot open the input file \"" << input_filename << "\".\n";

    exit ( 1 );

  }

  face = 0;

  face_pointer[0] = 0;

  while ( face < face_num )

  {

    getline ( input, text );

    if ( input.eof ( ) )

    {

      cout << "\n";

      cout << "XYZF_DATA_READ - Fatal error!\n";

      cout << "  Unexpected end of information.\n";

      exit ( 1 );

    }

    if ( text[0] == '#' || s_len_trim ( text ) == 0 )

    {

      continue;

    }

    n = s_word_count ( text );

    face_pointer[face+1] = face_pointer[face] + n;

 

    ilo = face_pointer[face];

    ierror = s_to_i4vec ( text, n, face_data+ilo );

    if ( ierror != 0 )

    {

      cout << "\n";

      cout << "XYZF_DATA_READ - Fatal error!\n";

      cout << "  Error from S_TO_I4VEC.\n";

      exit ( 1 );

    }

    face = face + 1;

  }

  input.close ( );

  return;

}

void xyzf_header_print ( int point_num, int face_num, int face_data_num )

{

  cout << "\n";

  cout << "  Number of points     = " << point_num << "\n";

  cout << "  Number of faces      = " << face_num << "\n";

  cout << "  Number of face items = " << face_data_num << "\n";

  return;

}

void xyzf_header_read ( string input_filename, int *face_num, 

  int *face_data_num )

{

  int i;

  int i4_val;

  int ierror;

  ifstream  input;

  int length;

  int n;

  string text;

  *face_data_num = 0;

  *face_num = 0;

  input.open ( input_filename.c_str() );

  if ( !input )

  {

    cout << "\n";

    cout << "XYZF_HEADER_READ - Fatal error!\n";

    cout << "  Cannot open the input file \"" << input_filename << "\".\n";

    exit ( 1 );

  }

  for ( ; ; )

  {

    getline ( input, text );

    if ( input.eof ( ) )

    {

      break;

    }

    if ( text[0] == '#' || s_len_trim ( text ) == 0 )

    {

      continue;

    }

    n = s_word_count ( text );

    *face_data_num = *face_data_num + n;

    *face_num = *face_num + 1;

  }

  input.close ( );

  return;

}

/*email to provide support at vancekingsaxbe@powerdominionenterprise.com, businessaffairs@powerdominionenterprise.com, For donations please write to fundraising@powerdominionenterprise.com*/