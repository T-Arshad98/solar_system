#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <iostream>
#include "planets.h"
#include "keys.h"
#include "surfaces.h"
using namespace std;

float red=0.0f, blue=0.0f, green=0.0f, alpha=1.0f;
float theta=0;
float thetaEarth=0;
float thetaMars=0;
float x, y, radius=5.0f, rsun=0.0f;
const double PI = 4.0*atan(1.0);
float rmercury=0.0f, rvenus=0.0f, rearth=0.0f, rmoon=0.0f, rmars=0.0f, rjupiter=0.0f, rsaturn=0.0f, ruranus=0.0f, rneptune=0.0f, rpluto=0.0f, rrings=0.0f;
float eyeX, eyeY, eyeZ, centerX=0.0f, centerY=0.0f, centerZ=0.0f, upX=0.0f, upY=1.0f, upZ=0.0f,r1=0.0f;
int num_segments=50;
float Rearth=0.5;


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




	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();   // Reset transformations
	gluLookAt(eyeX+a+A, eyeY+c, eyeZ+b+B,      // Set the camera
		  centerX+a, centerY+c, centerZ+b,		//coordinates where it will look
		  upX, upY, upZ);		//tilting the camera	

glPushMatrix();	
	surfaces(0, 50, 100,   0.0, 0.0, 0.0,   -100.0, -20.0, -100.0,   -100.0, -20.0, 100.0,   100.0, -20.0f, 100.0,     		 100.0, -20.0f, -100.0);
glPopMatrix();

simpleplanets(rsun,0.0,1.0,0.0,    0.0,0.0,0.0,    rsun,0.0,1.0,0.0,    255,255,0,    12, 40, 40); //sun
simpleplanets(rmercury,0.0,1,0.0,  -17,0.0,-10.0,   rmercury,0.0,1,0.0,  213,115,17,  0.38,20,20);  //mercury
simpleplanets(rvenus,0.0,1,0.0,  -23.0,0.0,20.0,   rvenus,0.0,1,0.0,  189,102,15,   0.95,20,20);    //venus

glPushMatrix();
  planetEarth(rearth,0.0,1.0,0.0,    46.0,0.0,0,     r1,0.0,0,0,    100,100,200,    0.5,20,20);    //earth
    glBegin(GL_POLYGON);		//surface
	for(int ii = 0; ii < num_segments; ii++)
	{
	float theta = 3.0f * PI * float(ii) / float(num_segments);//get the current angle
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
  //surfaces(100, 25, 10,   0.0, 0.0, 0.0,   -0.1, 0.05, -0.1,   -0.1, 0.05, 0.1,   0.1, 0.05, 0.1,   0.1, 0.05,-0.1); 
  simpleplanets(rmoon,0.0,1,0.0,  0.0,0.0,-2.0,   rmoon,0.0,1,0.0,  191,191,191,   0.15,50,50);       //moon
glPopMatrix();


simpleplanets(rmars,0.0,1,0.0,  65,0.0,20.0,   rmars,0.0,1,0.0,  179,0,0,   0.53,20,20); 	    //mars
simpleplanets(rjupiter,0.0,1,0.0,  0.0,0.0,-110.0,    rjupiter,0.0,1,0.0,  153,102,51,   9,20,20);  //jupiter

glPushMatrix();	
  complexplanets(rsaturn,0.0,1,0.0,   -170.0,0.0,0.0,    rsaturn,0.0,1,0.0,   197,141,83,   8,20,20); //saturn
    glPushMatrix();
	glRotatef(90.0,5.0,1.0,0.0);
	rings (255, 25, 10, 10);
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
	r1=r1+1;


	if (var1==true){
	eyeX=0+a; eyeY=100+c; eyeZ=0.1+b, centerX=0+a, centerY=0+c, centerZ=0+b;
	}

	if (var2==true){
	thetaEarth=theta+0;
	
	eyeX=50 * cos(thetaEarth * PI/180.0f); eyeZ=50 * sin(thetaEarth * PI/180.0f);eyeY=0.0; centerX=0.0f; centerY=0.0f; centerZ=0.0f; upX=0.0f; upY=1.0f; upZ=0.0f;a=0.0f; b=0.0f; c=0.0f; d=0.0f; e=0.0f; f=0.0f;A=0.0f; B=0.0f;
	}

	if (var3==true){
	//theta=theta-1.0;
	thetaMars=theta-0.802;	
	eyeX=70 * cos(thetaMars * PI/180.0f); eyeZ=70 * sin(thetaMars * PI/180.0f);eyeY=20.0f; centerX=0.0f; centerY=20.0f; centerZ=0.0f; upX=0.0f; upY=1.0f; upZ=0.0f;a=0.0f; b=0.0f; c=0.0f; d=0.0f; e=0.0f; f=0.0f;A=0.0f; B=0.0f;
	}

	glutSwapBuffers();


}

//g++ main.cpp -lX11 -lGL -lGLU -lglut -g -Wall -O2 -o X

