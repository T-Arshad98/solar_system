float a=0.0f, b=0.0f, c=0.0f, d=0.0f, e=0.0f, f=0.0f;
float A=0.0f, B=0.0f;
bool var1 = true;
bool var2, var3;

void processNormalKeys(unsigned char key, int x, int y) 
{
	switch(key) {
case  27 :	exit(0);
case 'd' :	a+=5;break; 	case 'a' :	a-=5;break;
case 'w' :	b-=5;break; 	case 's' :	b+=5;break;
case 'e' :	c+=5;break; 	case 'q' :	c-=5;break;
case 'h' :	d++;break; 	case 'f' :	d--;break;
case 't' :	e++;break; 	case 'g' :	e--;break;
case 'y' :	f++;break; 	case 'r' :	f--;break;
case  49 : 	var1=true;var2=false; var3=false;	break;
case  50 : 	var2=true;var1=false; var3=false;	break;
case  51 : 	var3=true;var1=false; var2=false;	break;
	}
}

void processSpecialKeys(int key, int x, int y) 
{
	switch(key) {
		case GLUT_KEY_UP :
				B++; break;
		case GLUT_KEY_DOWN :
				B--; break;
		case GLUT_KEY_LEFT :
				A--; break;
	case GLUT_KEY_RIGHT :
				A++; break;
	}
}
