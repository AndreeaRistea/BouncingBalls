#ifdef __APPLE_CC__
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>   
#include <GL/glut.h>
#endif

#include <iostream>
#include <fstream>
#define STB_IMAGE_IMPLEMENTATION   
#include "stb_image.h"


#include <cmath>

#include <vector>
#include "Board.h"
#include "Camera.h"
#include "header.h"
#include "Walls.h"
#include "Building.h"
#include "Tree.h"
#include "Road.h"
#include "Elements.h"
#include <GL/glut.h>
#include <cmath>


using namespace std;

float BROWN[] = { 0.30, 0.15, 0.05 };
float GREEN[] = { 0, 1, 0 };
unsigned int skyTextureId;
unsigned int mountainTextureId;
unsigned int buildingTextureId1;
unsigned int buildingTextureId2;
unsigned int buildingTextureId3;
unsigned int buildingTextureId4;
unsigned int roadTexture;
unsigned int newRoadTexture;
unsigned int trunkTextureId;
unsigned int crownTextureId;
unsigned int boardTexture;

int boardLength = 100;
int boardWidth = 100;
Board board(boardLength, boardWidth);
Camera camera;

unsigned int loadTexture(const char* texturePath) {
	if (!texturePath) {
		std::cout << "Invalid texture path" << std::endl;
		return 0;
	}
	std::ifstream file(texturePath);
	if (!file.is_open()) {
		cout << "Failed to open texture file" << endl;
		return 0;
	}
	file.close();

	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	int width, height, nrChannels;
	unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

	GLenum glewStatus = glewInit();

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	else {
		std::cout << "Failed to load texture" << std::endl;
		return 0;
	}

	stbi_image_free(data);

	return texture;
}

void init() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	boardTexture = loadTexture("grass.jpg");
	glClearColor(0.5f, 0.7f, 1.0f, 1.0f);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat lightPosition[] = { 50.0f, 50.0f, 50.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	GLfloat lightAmbient[] = { 1.3f, 1.3f, 1.3f, 1.3f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);

	GLfloat lightDiffuse[] = { 2.0f, 2.0f, 2.0f, 2.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);

	GLfloat lightSpecular[] = { 2.0f, 2.0f, 2.0f, 2.0f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

	GLfloat materialAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat materialDiffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat materialSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat materialShininess = 100.0f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	board.create(boardTexture);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(camera.getX() + boardLength / 2, camera.getY() + 4, camera.getZ() + boardWidth / 2,
		boardLength / 2, 4, boardWidth / 2,
		0.0, 1.0, 0.0);

	board.draw();

	skyTextureId = loadTexture("sky3.jpg");
	mountainTextureId = loadTexture("hill2.jpg");
	buildingTextureId1 = loadTexture("building.jpg");
	buildingTextureId2 = loadTexture("building2.jpg");
	buildingTextureId3 = loadTexture("building3.jpg");
	buildingTextureId4 = loadTexture("building4.jpg");
	roadTexture = loadTexture("asphalt.jpg");
	newRoadTexture = loadTexture("street2.jpg");
	trunkTextureId = loadTexture("treeTrunk.jpg");
	crownTextureId = loadTexture("treeCrown.png");
	drawWallB(mountainTextureId);
	drawWallF(skyTextureId);
	drawWallL(mountainTextureId);
	drawWallR(mountainTextureId);
	drawWallU(skyTextureId);

	addBuildingType1(buildingTextureId1);
	
	addBuildingsType2(buildingTextureId2);
	
	addBuildingsType3(buildingTextureId3);
	
	addTree(trunkTextureId, crownTextureId);

	addRoad(roadTexture);

	addRoadWithTree(trunkTextureId, crownTextureId);

	glutSwapBuffers();
}

void reshape(GLint width, GLint height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, GLfloat(width) / GLfloat(height), 1.0, 150.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int unused)
{
	glutPostRedisplay();
	glutTimerFunc(FRAME_RATE_MS, timer, unused); 
}

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
	glutCreateWindow("World");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(special);
	glutTimerFunc(FRAME_RATE_MS, timer, 0);


	init();

	glutMainLoop();
}
