#pragma once
void drawWallB(int textureID)
{
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 100.0f);    // Stânga-sus

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 100.0f);  // Stânga-jos

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(100.0f, 100.0f, 100.0f);  // Dreapta-jos

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);  // Dreapta-sus

	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
};


void drawWallF(int textureID)
{
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 1.0f);  
	glVertex3f(0.0f, 0.0f, 0.0f);    // Stânga-sus

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);  // Stânga-jos

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(100.0f, 100.0f, 0.0f); // Dreapta-jos

	glTexCoord2f(1.0f, 1.0f);  
	glVertex3f(100.0f, 0.0f, 0.0f);  // Dreapta-sus

	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
};


void drawWallL(int textureID)
{
	glMatrixMode(GL_MODELVIEW);

	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);    // Stânga-sus

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);  // Stânga-jos

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 100.0f); // Dreapta-jos

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 100.0f);  // Dreapta-sus

	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
};


void drawWallR(int textureID)
{
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);    // Stânga-sus

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(100.0f, 100.0f, 100.0f);    // Stânga-jos

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(100.0f, 100.0f, 0.0f);    // Dreapta-jos

	glTexCoord2f(1.0f, 1.0f);  
	glVertex3f(100.0f, 0.0f, 0.0f);    // Dreapta-sus

	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
};


void drawWallU(int textureID)
{
	glMatrixMode(GL_MODELVIEW);

	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);    // Stânga-sus

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 100.0f, 100.0f);    // Stânga-jos

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(100.0f, 100.0f, 100.0f);    // Dreapta-jos

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(100.0f, 100.0f, 0.0f);    // Dreapta-sus

	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
};