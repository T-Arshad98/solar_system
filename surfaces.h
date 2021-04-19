void surfaces (float c1, float c2, float c3,		float n1, float n2, float n3, 		 		       
	       float v11, float v12, float v13,		float v21, float v22, float v23,
	       float v31, float v32, float v33, 	float v41, float v42, float v43)
{
texture= LoadTexture( "/home/user/Downloads/SMALL LAPTOP/stars.bmp" );
glBindTexture (GL_TEXTURE_2D, texture);
GLUquadric *qobj = gluNewQuadric();

gluQuadricTexture(qobj,GL_TRUE);

glEnable(GL_TEXTURE_2D);

glBindTexture(GL_TEXTURE_2D,texture);

//glBegin(GL_QUADS);
	glColor3ub(c1, c2, c3);
	glNormal3f(n1, n2, n3);
	glVertex3f(v11, v12, v13);
	glVertex3f(v21, v22, v23);
	glVertex3f(v31, v32, v33);
	glVertex3f(v41, v42, v43);
//glEnd();

gluDeleteQuadric(qobj);
glDisable(GL_TEXTURE_2D); 
}
/*						CUBE
    void drawCube(float x, float y, float z) 
    {
    glBegin(GL_QUADS); 
    glVertex3f(-1.0f+x, -1.0f+y, -1.0f+z);
    glVertex3f(1.0f+x, -1.0f+y, -1.0f+z);
    glVertex3f(1.0f+x, 1.0f+y, -1.0f+z);
    glVertex3f(-1.0f+x, 1.0f+y, -1.0f+z);

    glVertex3f(-1.0f+x, -1.0f+y, -1.0f+z);
    glVertex3f(-1.0f+x, -1.0f+y, 1.0f+z);
    glVertex3f(-1.0f+x, 1.0f+y, -1.0f+z);
    glVertex3f(-1.0f+x, 1.0f+y, 1.0f+z);

    glVertex3f(-1.0f+x, -1.0f+y, -1.0f+z);
    glVertex3f(-1.0f+x, -1.0f+y, 1.0f+z);
    glVertex3f(1.0f+x, -1.0f+y, 1.0f+z);
    glVertex3f(1.0f+x, -1.0f+y, -1.0f+z);

    glVertex3f(-1.0f+x, -1.0f+y, 1.0f+z);
    glVertex3f(1.0f+x, -1.0f+y, 1.0f+z);
    glVertex3f(1.0f+x, 1.0f+y, 1.0f+z);
    glVertex3f(-1.0f+x, 1.0f+y, 1.0f+z);

    glVertex3f(-1.0f+x, -1.0f+y, 1.0f+z);
    glVertex3f(1.0f+x, -1.0f+y, 1.0f+z);
    glVertex3f(1.0f+x, 1.0f+y, 1.0f+z);
    glVertex3f(-1.0f+x, 1.0f+y, 1.0f+z);

    glVertex3f(-1.0f+x, 1.0f+y, -1.0f+z);
    glVertex3f(-1.0f+x, 1.0f+y, 1.0f+z);
    glVertex3f(1.0f+x, 1.0f+y, 1.0f+z);
    glVertex3f(1.0f+x, 1.0f+y, -1.0f+z);

    glEnd();
     }
*/
