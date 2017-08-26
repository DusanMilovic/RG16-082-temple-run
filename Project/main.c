#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "color.h"
#include "drawTracks.h"
#include "drawBush.h"
#include "drawTree.h"
#include "drawGame.h"

#define RUNNING 0
#define JUMPING 1

/* Callback func. */
static void on_display();
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_timer(int id);

static float animationParameter;
static float activated;
static float sphereX = 0.0, sphereY = -0.6, sphereZ = -2.5, sphereSize = 0.1;

/* Drawing func. */
static void draw_tracks();
static void draw_bush();
/* Colors */
static void color(int id);

static float moveSpeed = 0.5;

static int sphereXid = 0;
static int isJumping = 0;

/* jumping info */
static float height = -0.8;
static float ground = -0.1;

/* tracks info in tracks.h */

/* paths movement */
static float sideY = 2.3, sideZ = 7.9;

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

    //draw_tracks();
    // draw_bush();
    // draw_tree();

    int i;
    for (i = 0; i < 100; i++){
        /* pomeramo scenu simuliramo kretanje */
        float move_y = i*(sideY)-0.0023*animationParameter*moveSpeed-0.016; 
        float move_z = i*(-sideZ)+0.0079*animationParameter*moveSpeed;
        glTranslatef(0, move_y, move_z);
        draw_game(i, move_y, move_z);
        glTranslatef(0, -move_y, -move_z);

        /* speed improvment */
        moveSpeed += 0.000025;   
    }

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
        case 's': /* S - start the program */
        case 'S':
            if (!activated){
                glutTimerFunc(10, on_timer, RUNNING);
                activated = 1;
            }
            break;
        case 'p': /* p - pause the program */
        case 'P':
            activated = 0;
            break;
        case 'a': /* a - turn left */
        case 'A':
            if (activated){
                if(sphereX < -0.4) /* smash the border */
                    break;
                else {
                    sphereX -= 0.6;
                    sphereXid -= 1;
                }   
            }
            break;
        case 'd': /* d - turn right */
        case 'D':
            if (activated){
                if(sphereX > 0.4) /* smash the border */
                    break;
                else {
                    sphereX += 0.6;
                    sphereXid += 1;
                }
            }
            break;
        case 32: /* SPACE - jumping */
            if (!isJumping && activated){
                glutTimerFunc(10, on_timer, JUMPING);
                isJumping = 1;
            }
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

static void on_timer(int id){
    if (id != 0 && id != 1)
        return;

    animationParameter = animationParameter + 0.5;
    
    /* DO NOT let run during the jump */
    if (id == RUNNING){
        if (activated){
            glutTimerFunc(10, on_timer, RUNNING);
        }    
    }

    /* time to jump */
    if (id == JUMPING) {
        if (height < -0.1) {
            sphereY += 0.023*moveSpeed;
            height += 0.023*moveSpeed; 

        }
        /* riches the height */
        else if (ground > -0.6) {
            /* until hit the ground */
            sphereY -= 0.023*moveSpeed;
            ground -= 0.023*moveSpeed;
        }
        /* ground = reset values */
        else {
            isJumping = 0;
            height = -0.6;
            ground = -0.1;
            sphereY = -0.6;
            return;
        }

        if(isJumping)
            glutTimerFunc(10, on_timer, JUMPING);
        else
            glutTimerFunc(10, on_timer, RUNNING);
    }
    glutPostRedisplay();
}