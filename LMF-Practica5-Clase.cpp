//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Macario Falcon Leonel					******//
//************* Visual Studio 2017						******//
//************************************************************//

/* Para mover toda la mano de arriba<--->abajo utilizamos la variable J y j
   Para mover toda la mano de izquieda<--->derecha utilizamos la variable M y m
   Para mover el codo izquieda<--->derecha utilizamos la variable C y c
   Para mover la muñeca de izquieda<--->derecha utizamos la variable P y p
   Para articular el pulgar utilizamos la variable F y f
   Para simular cerrar la mano utilizamos las variables T y t para intentar  
   cerrar los dedos, L y l para inclinar los dedos.  
*/

#include "Main.h"
float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
float tranzD = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angCodo = 0.0;
float angleM = 0;
float angleC = 0.0;
float angleP = 0.0;
float angleF = 0.0;
float angleT = 0;

GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Bufferas
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner Código Aquí.
	//hombro
	glRotatef(angCodo, 0, 0.0, 1.0); //Mueve desde el hombro hasta a los dedos de arriba---abajo
	glRotatef(angleM, 0, 1.0, 0.0);  //Mueve desde el hombro hasta a los dedos de izquierda---derecha 
	glPushMatrix();
	glScalef(1,2,2);
	glColor3f(1, 0,3);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 0.2, 0.4);
	glTranslatef(2,0, 0);
	glScalef(3, 2, 2);
	prisma();
	glPopMatrix();

	glRotatef(angleC, 0, 1.0, 0.0); //Mueve desde el Codo hasta los dedos de Derecha <---> Izquierda
	glPushMatrix();
	glColor3f(0, 2, 4);
	glTranslatef(3.75, 0, 0);
	glScalef(0.5, 2, 2);
	prisma();
	glPopMatrix();

	glTranslatef(6, 0, 0);
	glPushMatrix();
	glColor3f(11, 2, 4);
	glScalef(4, 2, 2);
	prisma();
	glPopMatrix();
	//MUÑECA
	glPushMatrix();
	glTranslatef(2, 0, 0);
	glColor3f(0, 2, 4);
	glScalef(0.5, 2, 2);
	prisma();
	glPopMatrix();
	glRotatef(angleP, 0, 1.0, 0.0); //Mueve toda la mano de Izquierda <---> Derecha
	//PALMA
	glPushMatrix();
	glTranslatef(3.25, 0, 0);
	glColor3f(0, 0, 4);
	glScalef(2, 2, 2);
	prisma();
	glPopMatrix();
    //DEDOS 
	  //PULGAR
	glTranslatef(3.1, 1.25, 0);
	glPushMatrix();
    glColor3f(1, 0, 0);
	glScalef(0.5, 0.5, 1);
	prisma();
	glPopMatrix();

	glTranslatef(0, 0.5, 0);
	glPushMatrix();
	glColor3f(1, 0, 0);
	glScalef(0.5, 0.5, 1);
	prisma();
	glPopMatrix();
	 
	glTranslatef(0, 0.5, 0);
	glPushMatrix();
	glRotatef(angleF, 1.0, 0, 0.0); //MUEVE EL PULGAR
	glColor3f(25, 100, 90);
	glScalef(0.5, 0.5, 1);
	prisma();
	glPopMatrix();

	//INDICE
	glTranslatef(1.4, -1.5, 0);
	glPushMatrix();
	glTranslatef(0.0F, 0.0f, tranzD);
	glRotatef(angleT, 0.0, 1, 0.0); //MUEVE EL INDICE
	glColor3f(2, 1, 0);
	glScalef(0.5, 0.4, 1);
	prisma();
	glPopMatrix();

	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glTranslatef(0.0F, 0.0f, tranzD*1.5);
	glRotatef(angleT/1.5, 0.0, 1, 0.0); 
	glColor3f(25, 80, 0);
	glScalef(0.5, 0.4, 1);
	prisma();
	glPopMatrix();

	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glTranslatef(0.0F, 0.0f, tranzD*2);
	glRotatef(angleT / 1.5, 0.0, 1, 0.0);
	glColor3f(85, 80, 99);
	glScalef(0.5, 0.4, 1);
	prisma();
	glPopMatrix();
  	//CORDIAL
    glTranslatef(-1, -0.5, 0);
	glPushMatrix();
	glTranslatef(0.0F, 0.0f, tranzD * 2);
	glRotatef(angleT / 1.5, 0.0, 1, 0.0);
	glColor3f(250, 80, 99);
	glScalef(0.5, 0.4, 1);
	prisma();
	glPopMatrix();

	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glTranslatef(0.0F, 0.0f, tranzD * 2);
	glRotatef(angleT / 1.5, 0.0, 1, 0.0);
	glColor3f(105, 1, 3);
	glScalef(0.5, 0.4, 1);
	prisma();
	glPopMatrix();

	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glTranslatef(0.0F, 0.0f, tranzD * 2);
	glRotatef(angleT / 1.5, 0.0, 1, 0.0);
	glColor3f(99, 107, 3);
	glScalef(0.5, 0.4, 1);
	prisma();
	glPopMatrix();
	//ANULAR
	glTranslatef(-1, -0.5, 0);
	glPushMatrix();
	glTranslatef(0.0F, 0.0f, tranzD * 2);
	glRotatef(angleT / 1.5, 0.0, 1, 0.0);
	glColor3f(1, 0, 9);
	glScalef(0.5, 0.4, 1);
	prisma();
	glPopMatrix();

	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glTranslatef(0.0F, 0.0f, tranzD * 2);
	glRotatef(angleT / 1.5, 0.0, 1, 0.0);
	glColor3f(105, 1, 3);
	glScalef(0.5, 0.4, 1);
	prisma();
	glPopMatrix();

	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glTranslatef(0.0F, 0.0f, tranzD * 2);
	glRotatef(angleT / 1.5, 0.0, 1, 0.0);
	glColor3f(99, 107, 3);
	glScalef(0.5, 0.4, 1);
	prisma();
	glPopMatrix();
	//MENIQUE
	glTranslatef(-1, -0.5, 0);
	glPushMatrix();
	glTranslatef(0.0F, 0.0f, tranzD * 2);
	glRotatef(angleT / 1.5, 0.0, 1, 0.0);
	glColor3f(0, 0, 1);
	glScalef(0.5, 0.4, 1);
	prisma();
	glPopMatrix();

	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glTranslatef(0.0F, 0.0f, tranzD * 2);
	glRotatef(angleT / 1.5, 0.0, 1, 0.0);
	glColor3f(0, 1, 3);
	glScalef(0.5, 0.4, 1);
	prisma();
	glPopMatrix();

	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glTranslatef(0.0F, 0.0f, tranzD * 2);
	glRotatef(angleT / 1.5, 0.0, 1, 0.0);
	glColor3f(430, 107, 3);
	glScalef(0.5, 0.4, 1);
	prisma();
	glPopMatrix();
	//

	glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
	case 'L':
		if ( tranzD <= 0.4)
			tranzD += 0.2f;  //recien agragado 
		printf("%f\n", tranzD);
		
		break;
	case 'l':
		if (tranzD >= -1 )
			tranzD -= 0.2f;  //recien agragado 
		printf("%f\n", tranzD);
		break;

	case 'T':
		if (angleT <= 30)
			angleT += 0.2f;  //recien agragado 
		printf("%f\n", angleT);

		break;
	case 't':
		if (angleT >= -30)
			angleT -= 0.2f;  //recien agragado 
		printf("%f\n", angleT);
		break;

	case 'F':
		if (angleF <= 30)
			angleF += 0.2f;  //recien agragado 
		printf("%f\n", angleM);

		break;
	case 'f':
		if (angleF >= -30)
			angleF -= 0.2f;  //recien agragado 
		printf("%f\n", angleM);
		break;

	case 'P':
		if (angleP <= 60)
			angleP += 0.2f;  //recien agragado 
		printf("%f\n", angleM);

		break;
	case 'p':
		if (angleP >= -60)
			angleP -= 0.2f;  //recien agragado 
		printf("%f\n", angleM);
		break;

	case 'C':
		if (angleC <= 60)
			angleC += 0.2f;  //recien agragado 
		printf("%f\n", angleM);

		break;
	case 'c':
		if (angleC >= -60)
			angleC -= 0.2f;  //recien agragado 
		printf("%f\n", angleM);
		break;
	case 'M':
		if (angleM <= 60)
			angleM += 0.2f;  //recien agragado 
		printf("%f\n", angleM);

		break;
	case 'm':
		if (angleM >= -60)
			angleM -= 0.2f;  //recien agragado 
		printf("%f\n", angleM);
		break; 
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		
		case 'J':
			if(angCodo <= 60)
			angCodo += 0.2f;  //recien agragado 
			printf("%f\n",angCodo);
			
			break;
		case 'j':
			if (angCodo >= -60)
				angCodo -= 0.2f;  //recien agragado 
				printf("%f\n", angCodo);
			
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



