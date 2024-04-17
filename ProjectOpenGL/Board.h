#pragma once
#include <gl/GL.h>

GLfloat BLUE[] = { 0, 0, 1 };
GLfloat WHITE[] = { 1, 1, 1 };

class Board
{
	int displayListId;
	int width;
	int depth;
	GLfloat* color;
public:

	Board(int width, int depth, GLfloat* c) : width(width), depth(depth), color(c) {}
	double centerX() { return width / 2; }
	double centerZ() { return depth / 2; }

	void create()
	{
		displayListId = glGenLists(1);
		glNewList(displayListId, GL_COMPILE);
		glBegin(GL_QUADS);
		glNormal3d(0, 1, 0);
		for (int x = 0; x < width - 1; x++)
		{
			for (int z = 0; z < depth - 1; z++) {
				glGetMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, (x + z) % 2 == 0 ? BLUE : WHITE);
				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
				glVertex3d(x, 0, z);
				glVertex3d(x + 1, 0, z);
				glVertex3d(x + 1, 0, z + 1);
				glVertex3d(x, 0, z + 1);
			}
		}
		glEnd();
		glEndList();
	}

	void draw()
	{
		glCallList(displayListId);
	}

};