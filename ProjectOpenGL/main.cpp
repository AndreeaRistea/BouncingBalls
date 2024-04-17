#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <stdlib.h>   
#include <GL/glut.h>
#endif

#include <cmath>

#include <vector>
#include "Board.h"
#include "Camera.h"
#include "Ball.h"
#include "header.h"

#include <GL/glut.h>
#include <cmath>


//colors

GLfloat RED[] = { 1, 0, 0 };
GLfloat YELLOW[] = { 1, 1, 0 };
GLfloat GREEN[] = { 0, 1, 0 };

GLfloat MAGENTA[] = { 1, 0, 1 };
GLfloat PINK[] = { 0.6, 0, 0.6 };
GLfloat CYAN[] = { 0, 1, 1 };
GLfloat BROWN[] = { 0.30, 0.15, 0.05 };



Board board(9, 9, CYAN);
Camera camera;
Ball balls[] = {
	Ball(1, YELLOW, 2, 1, 1, { 0, 1, 0}),
	Ball(0.5, BLUE, 4, 1, 1, {0, 1, 0}),
	Ball(0.5, GREEN, 6, 1, 4, {1, 1, 1}),
	Ball(0.2, MAGENTA, 1, 1, 1, {1, 1, 1}),
	Ball(0.5, BROWN, 7, 7, 7, {-1, -1, -1}),
	Ball(0.5, RED, 2, 1, 4, {-1, 1, 1}),
	Ball(0.75, CYAN, 6, 3, 4, {1, 2, 1})

};

int numBalls = sizeof(balls) / sizeof(Ball);

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
	glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
	glMaterialf(GL_FRONT, GL_SHININESS, 30);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	board.create();
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(camera.getX(), camera.getY() + 8.0, camera.getZ(),
		board.centerX(), 0.0, board.centerZ(),
		0.0, 1.0, 0.0);


	board.draw();

	for (int i = 0; i < sizeof balls / sizeof(Ball); i++)
	{
		balls[i].update(balls);
	}

	for (int i = 0; i < sizeof balls / sizeof(Ball); i++)
	{
		for (int j = i + 1; j < sizeof balls / sizeof(Ball); j++)
		{
			if (i != j) {
				double distance = sqrt(
					pow(balls[i].position[0] - balls[j].position[0], 2) +
					pow(balls[i].position[1] - balls[j].position[1], 2) +
					pow(balls[i].position[2] - balls[j].position[2], 2)
				);
				if (distance < balls[i].radius + balls[j].radius) {
					auto direction = balls[i].directions;
					balls[i].directions = balls[j].directions;
					balls[j].directions = direction;
				}
			}
		}
	}

	glFlush();

	GLfloat* color = MAGENTA;
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

	//perete fata
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, 0.0f);    // Stânga-sus
	glVertex3f(0.0f, 8.0f, 0.0f);    // Stânga-jos
	glVertex3f(8.0f, 8.0f, 0.0f);    // Dreapta-jos
	glVertex3f(8.0f, 0.0f, 0.0f);    // Dreapta-sus
	glEnd();

	color = PINK;
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
	//perete dreapta
	glBegin(GL_QUADS);
	glVertex3f(8.0f, 0.0f, 0.0f);    // Dreapta-sus
	glVertex3f(8.0f, 8.0f, 0.0f);    // Dreapta-jos
	glVertex3f(8.0f, 8.0f, 8.0f);    // Stânga-jos
	glVertex3f(8.0f, 0.0f, 8.0f);    // Stânga-sus
	glEnd();

	//perete stanga
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, 8.0f);    // Dreapta-sus
	glVertex3f(0.0f, 8.0f, 8.0f);    // Dreapta-jos
	glVertex3f(0.0f, 8.0f, 0.0f);    // Stânga-jos
	glVertex3f(0.0f, 0.0f, 0.0f);    // Stânga-sus
	glEnd();

	//perete superior
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 8.0f, 0.0f);    // Stânga-sus
	glVertex3f(8.0f, 8.0f, 0.0f);    // Dreapta-sus
	glVertex3f(8.0f, 8.0f, 4.0f);    // Dreapta-jos
	glVertex3f(0.0f, 8.0f, 4.0f);    // Stânga-jos
	glEnd();

	glutSwapBuffers();
}

//creeaza o camera care are aceeasi dimensiune cu window-ul
void reshape(GLint width, GLint height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, GLfloat(width) / GLfloat(height), 1.0, 150.0);
	glMatrixMode(GL_MODELVIEW);
}

//draw next frame
void timer(int unused)
{
	glutPostRedisplay();
	glutTimerFunc(FRAME_RATE_MS, timer, unused); //balls's speed
}

//misca camera in functie de tasta apasata
void special(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: camera.moveLeft(); break;
	case GLUT_KEY_RIGHT: camera.moveRight(); break;
	case GLUT_KEY_UP: camera.moveUp(); break;
	case GLUT_KEY_DOWN: camera.moveDown(); break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Bouncing Balls");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(special);
	glutTimerFunc(FRAME_RATE_MS, timer, 0);
	init();
	glutMainLoop();
}
