#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <string.h>
#include "planets.h"
#include "keys.h"
#include "surfaces.h"

float red=0.0f, blue=0.0f, green=0.0f, alpha=1.0f;
float theta=0;
float x, y, radius=5.0f, rsun=0.0f;
const double PI = 4.0*atan(1.0);
float rmercury=0.0f, rvenus=0.0f, rearth=0.0f, rmoon=0.0f, rmars=0.0f, rjupiter=0.0f, rsaturn=0.0f, ruranus=0.0f, rneptune=0.0f, rpluto=0.0f, rrings=0.0f;
float eyeX, eyeY, eyeZ, centerX=0.0f, centerY=0.0f, centerZ=0.0f, upX=0.0f, upY=1.0f, upZ=0.0f;
int num_segments=50;
float Rearth=0.5;

extern int num_texture;
typedef struct                       /**** BMP file info structure ****/
    {
    unsigned int   biSize;           /* Size of info header */
    int            biWidth;          /* Width of image */
    int            biHeight;         /* Height of image */
    unsigned short biPlanes;         /* Number of color planes */
    unsigned short biBitCount;       /* Number of bits per pixel */
    unsigned int   biCompression;    /* Type of compression to use */
    unsigned int   biSizeImage;      /* Size of image data */
    int            biXPelsPerMeter;  /* X pixels per meter */
    int            biYPelsPerMeter;  /* Y pixels per meter */
    unsigned int   biClrUsed;        /* Number of colors used */
    unsigned int   biClrImportant;   /* Number of important colors */
    char *data;
    } BITMAPINFOHEADER;

int LoadBitmap(char *filename)
{
 unsigned char *l_texture;
 int i, j=0;
 FILE *l_file;
 BITMAPFILEHEADER fileheader;
 BITMAPINFOHEADER infoheader;
 RGBTRIPLE rgb;
 num_texture++;

 if ( (l_file = fopen(filename, "rb"))==null) return (-1);
 fread(&fileheader, sizeof(fileheader), 1, l_file);
 fseek(l_file, sizeof(fileheader), SEEK_SET);

 fread (&infoheader, sizeof(infoheader), 1, l_file);
 l_texture = (byte *) malloc(infoheader.biWidth * infoheader.biHeight * 4);
 memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);


   for (i=0; i<infoheader.biWidth*infoheader.biHeight; i++)
   {
	fread(&rgb, sizeof(rgb), 1, file);

	l_texture[j+0] = rgb.rgbtRed;
	l_texture[j+1] = rgb.rgbtGreen;
	l_texture[j+2] = rgb.rgbtBlue;
	l_texture[j+3] = 255;
	j+=4;
   }

 fclose(l_file);
 glBindTexture(GL_TEXTURE_2D, num_texture);

 glTexParamaterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
 glTexParamaterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
 glTexParamaterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 glTexParamaterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
 glTexImage2D(GL_TEXTURE_2D, 0, 4, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);
 gluBuild2DMipmaps(GL_TEXTURE_2D, 4, infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);

 free(l_texture);
 return (num_texture);
}

typedef struct{
	float u, v;
}mapcoord_type;

typedef struct {
	vertex_type vertex[MAX_VERTICES];
	polygon_type polygon[MAX_POLYGONS];
	mapcoord_type mapcoord[MAX_VERTICES];
	int id_texture;
} obj_type, *obj_type_ptr;

#define MAX_POLYGONS 2000
polygon_type polygon[MAX_POLYGONS];

#define MAX_VERTICES 2000
vertex_type vertex[MAX_VERTICES];

obj_type cube =
{
   {
	-50, -50, 50,
	50, -50, 50,
	50, -50, -50,
	-50, -50, -50,
	-50, 50, 50,
	50, 50, 50,
	50, 50, -50,
	-50, 50, -50
   },
   {
	0, 1, 4,
	1, 5, 4,
	1, 2, 5,
	2, 6, 5,
	2, 3, 6, 
	3, 7, 6,
	3, 0, 7, 
	0, 4, 7,
	4, 5, 7, 
	5, 6, 7,
	3, 2, 0,
	2, 1, 0,
   },
   {
	0.0, 0.0,
	1.0, 0.0,
	1.0, 0.0,
	0.0, 0.0,
	0.0, 1.0,
	1.0, 1.0,
	1.0, 1.0,
	0.0, 1.0,
   },
   0,
}



void changeSize(int w, int h)
{
		if (h == 0)  
		h = 1;
	float ratio =  w * 1.0 / h;      
	glMatrixMode(GL_PROJECTION);      // Use the Projection Matrix    
	glLoadIdentity();// Reset Matrix
	glViewport(0, 0, w, h);    // Set the viewport to be the entire window
	gluPerspective(45.0f, ratio, 0.1f, 1500.0f);  
	glMatrixMode(GL_MODELVIEW);    // Get Back to the Modelview
	glEnable(GL_DEPTH_TEST);
}

void renderScene(void) 
{	
	if (var2==true){	
	eyeX=50 * cos(theta * PI/180.0f); eyeZ=50 * sin(theta * PI/180.0f); eyeY=0.0;
	}
	else{
	eyeX=0; eyeY=100; eyeZ=0.1;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();   // Reset transformations
	gluLookAt(eyeX+a+A, eyeY+c, eyeZ+b+B,      // Set the camera
		  centerX+a, centerY+c, centerZ+b,		//coordinates where it will look
		  upX, upY, upZ);		//tilting the camera	
	glEnable(GL_DEPTH_TEST);

	glBegin(GL_QUADS);
	 glVertex3f(-256.0, -20.0, -256.0);
	 glVertex3f(-256.0, -20.0, 256.0);
	 glVertex3f(256.0, -20.0f, 256.0);
	 glVertex3f(256.0, -20.0f, -256.0);
	glEnd();

//surfaces(0, 50, 100,   0.0, 0.0, 0.0,   -100.0, -20.0, -100.0,   -100.0, -20.0, 100.0,   100.0, -20.0f, 100.0,     		 100.0, -20.0f, -100.0);
	

glPushMatrix();			//sun
	glTranslatef(0.0,0.0,0.0);
	glRotatef(rsun,0.0,1.0,0.0);
	glColor3ub(255,255,0);
	glutSolidSphere(12, 50, 50);
glPopMatrix();

simpleplanets(rmercury,0.0,1,0.0,  -17,0.0,-10.0,   rmercury,0.0,1,0.0,  213,115,17,  0.38,20,20);  //mercury
simpleplanets(rvenus,0.0,1,0.0,  -23.0,0.0,20.0,   rvenus,0.0,1,0.0,  189,102,15,   0.95,20,20);    //venus

glPushMatrix();

	glRotatef(rearth,0.0,1,0.0);				
	glTranslatef(46.0,0.0,0);	
	glRotatef(rearth,0.0,1,0.0);							
	glColor3ub(0,82,204);
	glutSolidSphere(0.5,20,20); 
	

//complexplanets(rearth,0.0,1,0.0,    46.0,0.0,0,    rearth,0.0,1,0.0,    0,82,204,    0.5,20,20);    //earth

glBegin(GL_POLYGON);
	for(int ii = 0; ii < num_segments; ii++)
	{
	float theta = 2.0f * PI * float(ii) / float(num_segments);//get the current angle
	float x = Rearth * cosf(theta);//calculate the x component
	float z = Rearth * sinf(theta);//calculate the y component
	glColor3b(100,20,10);
	glVertex3f(x , 0 ,z);//output vertex
	}
glEnd();

    glPushMatrix();
   	 glTranslatef(0.0,0.2,0.0);
   	 glutSolidCube(0.25);
    glPopMatrix();

surfaces(100, 25, 10,   0.0, 0.0, 0.0,   -0.1, 0.05, -0.1,   -0.1, 0.05, 0.1,   0.1, 0.05, 0.1,   0.1, 0.05,-0.1); 
simpleplanets(rmoon,0.0,1,0.0,  0.0,0.0,-2.0,   rmoon,0.0,1,0.0,  191,191,191,   0.15,50,50);       //moon
glPopMatrix();

simpleplanets(rmars,0.0,1,0.0,  65,0.0,20.0,   rmars,0.0,1,0.0,  179,0,0,   0.53,20,20); 	    //mars
simpleplanets(rjupiter,0.0,1,0.0,  0.0,0.0,-110.0,    rjupiter,0.0,1,0.0,  153,102,51,   9,20,20);  //jupiter

glPushMatrix();	
complexplanets(rsaturn,0.0,1,0.0,   -170.0,0.0,0.0,    rsaturn,0.0,1,0.0,   197,141,83,   8,20,20); //saturn
glPushMatrix();
	glRotatef(90.0,5.0,1.0,0.0);	
glBegin(GL_LINES);		//rings
	glColor3f(1.0f, 0.0f, 0.0f);
	x = (float) 10 * cos(359 * PI/180.0f);
	y = (float) 10 * sin(359 * PI/180.0f);
	for (int j = 0; j<360; j++)
	{
	     glVertex2f (x,y);
	     x = (float) 10 * cos(j * PI/180.f);
	     y = (float) 10 * sin(j * PI/180.f);
	     glVertex2f(x,y);
	}
glEnd();	
glPopMatrix();				                           	
glPopMatrix();

simpleplanets(ruranus,0.0,1,0.0,  0.0,0.0,200.0,    ruranus,0.0,1,0.0,  0,255,255,   2.4,20,20); //uranus
simpleplanets(rneptune,0.0,1,0.0,  -70.0,0.0,225.0,    rneptune,0.0,1,0.0,  0,204,255,   6,20,20); //neptune
simpleplanets(rpluto,0.0,1,0.0,  -250.0,0.0,-90.0,    rpluto,0.0,1,0.0,  179,89,0,   2.4,20,20); //pluto
	
	rsun = rsun+4.104;
	rmercury = rmercury + 1.607;
	rvenus = rvenus + 1.174 ;
	rearth  = rearth + 1.0;
	rmoon = rmoon + 1.5;
	rmars = rmars + 0.802;
	rjupiter = rjupiter + 0.434;
	rrings = rrings + 0.1;
	rsaturn = rsaturn + 0.323;
	ruranus = ruranus + 0.228;
	rneptune = rneptune + 0.182;
	rpluto = rpluto + 0.159;
	theta=theta-1.0;

	glutSwapBuffers();

}
