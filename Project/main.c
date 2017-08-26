#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "color.h"
#include "drawTracks.h"
#include "drawBush.h"
#include "drawTree.h"

/* Callback func. */
static void on_display();
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);

static float animationParameter;
static float activated;
static float sphereX = 0.0, sphereY = -0.6, sphereZ = -2.5, sphereSize = 0.1;

/* Drawing func. */
static void draw_tracks();
static void draw_bush();
/* Colors */
static void color(int id);

/* tracks info in tracks.h */

int main(int argc, char **argv) {
	 /* GLUT Init */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    animationParameter = 0;
    activated = 0;

    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    /* OpenGL Init. */
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
	glLineWidth(50);

    glutMainLoop();

	return 0;
}

static void on_display(){
    GLfloat light_position[] = { 0, 0.8, 1, 1 };
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1 };
    GLfloat light_diffuse[] = { 1, 1, 1, 1 };
    GLfloat light_specular[] = { 1, 1, 1, 1 };
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0.4, 0, 0, 0.35, -0.26, 0, 1, 0);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	

    //there would be a function of drawing everything
    //in some loop just call that function multiple times
    //with different positions of obstacles
    draw_tracks();
    draw_bush();
    draw_tree();

	/* creating runner */
	color(2);
	glTranslatef(sphereX, sphereY, sphereZ);
	glRotatef(45, 1, 1, 1);
	glRotatef(-15*animationParameter, 1, 0, 0.5);
	/*glutSolidSphere(sphereSize,200,200);*/
    glutWireSphere(sphereSize, 5, 5);
    glRotatef(15*animationParameter, 1, 0, 0.5);
	glRotatef(-45, 1, 1, 1);
	glTranslatef(-sphereX, -sphereY, -sphereZ);
    
    /* creating hunter */    
    color(3);
    glTranslatef(sphereX, sphereY, sphereZ);
	glRotatef(20, 1, 1, 1);
    glRotatef(15*animationParameter, 0, 0, 0.1);
    glTranslatef(0,0,0.25);
    glutSolidSphere(sphereSize*1.3,200,200);
    /*glutWireSphere(sphereSize*1.3,5,5);*/
    glRotatef(-45, 1, 1, 1);
	glTranslatef(-sphereX, -sphereY, -sphereZ);
        
	glutSwapBuffers();
}

static void on_keyboard(unsigned char key, int x, int y){
	switch(key){
		case 27: /* ESC - quit the program */
			exit(0);
			break;
        case 'p': /* p - pause the program */
        case 'P':
            activated = 0;
            break;
	}

	glutPostRedisplay();
}

static void on_reshape(int width, int height){
    /* safely resize window */
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, (float) width / height, 0.5, 20); 
}
