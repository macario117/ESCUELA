//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Macario Falcon Leonel				    ******//
//*************		Visual Studio 2015					******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);							    // Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);							// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar (PARA ESETE EJEMPLO LAS DIMENSIONES SON DE -10 A 10)
	                                     // apartir de aqui empezamos a dibujar
	glPointSize(10);                    //tamaño del punto
	

	                     // LETRA C CON RELLENO 

	glBegin(GL_QUADS);
	
	//VERTICAL1
	glVertex3f(3, 4, -1.2); //P1
	glVertex3f(-2, 4, -1.2); //P3
	glVertex3f(3, 3, -1.2); //P2
	glVertex3f(-2, 3, -1.2); //P4
	
    //Horizontal1
	
	glVertex3f(3, 4, -1.2);
	glVertex3f(3, 3, -1.2);
	glVertex3f(-2, 4, -1.2);
	glVertex3f(-2, 3, -1.2);

	glBegin(GL_QUADS);

	//VERTICAL2
	glVertex3f(-3, 4, -1.2); //P1
	glVertex3f(-2, 4, -1.2); //P3
	glVertex3f(-3, -2, -1.2); //P2
	glVertex3f(-2, -2, -1.2); //P4

	//Horizontal2

	glVertex3f(-3, 4, -1.2);
	glVertex3f(-3, -2, -1.2);
	glVertex3f(-2, 4, -1.2);
	glVertex3f(-2, -2, -1.2);

	glBegin(GL_QUADS);

	//VERTICAL3
	glVertex3f( 3, -2, -1.2); //P1
	glVertex3f(-2, -2, -1.2); //P3
	glVertex3f(-2, -1, -1.2); //P2
	glVertex3f( 3, -1, -1.2); //P4

							  //Horizontal3

	glVertex3f( 2, -1, -1.2);
	glVertex3f(-2, -2, -1.2);
	glVertex3f( 3, -1, -1.2);
	glVertex3f(, -2, -1.2);

	glEnd();

	glFlush();
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

	// Ortogonal
	glOrtho(-10,10,-10,10,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

