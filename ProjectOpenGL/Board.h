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
	int textureId;
public:
	Board(int width, int depth) : width(width), depth(depth) {}
	double centerX() { return width / 2; }
	double centerZ() { return depth / 2; }

	void create(int textureId)
	{
		this->textureId = textureId;
	}

	void draw()
	{
		glMatrixMode(GL_MODELVIEW);

		glBindTexture(GL_TEXTURE_2D, textureId);
		glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);    // Stânga-sus

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, depth);  // Stânga-jos

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(width, 0.0f, depth);  // Dreapta-jos

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(width, 0.0f, 0.0f);  // Dreapta-sus

		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
	}
};
