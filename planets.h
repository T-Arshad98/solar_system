using namespace std;

GLuint texture;

GLuint LoadTexture( const char * filename )
{

  GLuint texture;

  int width, height;

  unsigned char * data;

  FILE * file;

  file = fopen( filename, "rb" );

  if ( file == NULL ) return 0;
  width = 400;
  height = 200;
  data = (unsigned char *)malloc( width * height * 3 );
  //int size = fseek(file,);
  fread( data, width * height * 3, 1, file );
  fclose( file );

 for(int i = 0; i < width * height ; ++i)
{
   int index = i*3;
   unsigned char B,R;
   B = data[index];
   R = data[index+2];

   data[index] = B;
   data[index+2] = R;

}


glGenTextures( 1, &texture );
glBindTexture( GL_TEXTURE_2D, texture );
glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );


glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
free( data );

return texture;
}

//char texLocation[50] = "/home/user/Downloads/SMALL LAPTOP/";

void simpleplanets( float r1,float r2,float r3, float r4,float t1,float t2,float t3,float r5,float r6,float r7, float r8,float c1,float c2,float c3, float rad, float res1, float res2) 
{
glPushMatrix();	

	glRotatef(r1,r2,r3,r4);				
	glTranslatef(t1,t2,t3);
	glRotatef(r5,r6,r7,r8);				
	glColor3ub(c1,c2,c3);		
	glutSolidSphere(rad,res1,res2); 					                           	
glPopMatrix();
}

void planetEarth(float r1,float r2,float r3, float r4,float t1,float t2,float t3,float r5,float r6,float r7, float r8,float c1,float c2,float c3, float rad, float res1, float res2) 
{
//texLocation = "/home/user/Downloads/SMALL LAPTOP/stars.bmp";

texture= LoadTexture( "/home/user/Downloads/SMALL LAPTOP/stars.bmp" );
glBindTexture (GL_TEXTURE_2D, texture);
GLUquadric *qobj = gluNewQuadric();

gluQuadricTexture(qobj,GL_TRUE);

glEnable(GL_TEXTURE_2D);

glBindTexture(GL_TEXTURE_2D,texture);

	glRotatef(r1,r2,r3,r4);				
	glTranslatef(t1,t2,t3);	
	glRotatef(r5,r6,r7,r8);							
	glColor3ub(c1,c2,c3);			
	//glutSolidSphere(rad,res1,res2); 
gluSphere(qobj,rad,res1,res2);

gluDeleteQuadric(qobj);
glDisable(GL_TEXTURE_2D); 
}

void complexplanets(float r1,float r2,float r3, float r4,float t1,float t2,float t3,float r5,float r6,float r7, float r8,float c1,float c2,float c3, float rad, float res1, float res2) 
{

	glRotatef(r1,r2,r3,r4);				
	glTranslatef(t1,t2,t3);	
	glRotatef(r5,r6,r7,r8);							
	glColor3ub(c1,c2,c3);			
	glutSolidSphere(rad,res1,res2); 
}

void rings (float c1, float c2, float c3, float r)
{
const double PI = 4.0*atan(1.0);
float x,y;
glBegin(GL_LINES);		//how to draw cirlce
	glColor3ub(c1, c2, c3);
	x = (float) r * cos(359 * PI/180.0f);
	y = (float) r * sin(359 * PI/180.0f);
	for (int j = 0; j<360; j++)
	{
	     glVertex2f (x,y);
	     x = (float) r * cos(j * PI/180.f);
	     y = (float) r * sin(j * PI/180.f);
	     glVertex2f(x,y);
	}
glEnd();
}
