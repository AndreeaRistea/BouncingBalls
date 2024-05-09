#pragma once
void drawRoad(unsigned int roadTextureId, float outerLength, float outerWidth, float innerLength, float innerWidth, float roadHeight = 0.1f) {
	int boardLength = 100;
	int boardWidth = 100;
	glBindTexture(GL_TEXTURE_2D, roadTextureId);

	float outerX1 = (boardLength - outerLength) / 2.0f;
	float outerX2 = outerX1 + outerLength;
	float outerZ1 = (boardWidth - outerWidth) / 2.0f;
	float outerZ2 = outerZ1 + outerWidth;

	float innerX1 = (boardLength - innerLength) / 2.0f;
	float innerX2 = innerX1 + innerLength;
	float innerZ1 = (boardWidth - innerWidth) / 2.0f;
	float innerZ2 = innerZ1 + innerWidth;

	float marginOffset = 15.0f;

	glBegin(GL_QUADS);

	glTexCoord2f(0, 0); glVertex3f(outerX1, roadHeight, outerZ1);
	glTexCoord2f(1, 0); glVertex3f(outerX2, roadHeight, outerZ1);
	glTexCoord2f(1, 1); glVertex3f(innerX2, roadHeight, outerZ1);
	glTexCoord2f(0, 1); glVertex3f(innerX1, roadHeight, outerZ1);

	glTexCoord2f(0, 0); glVertex3f(outerX1, roadHeight, outerZ2);
	glTexCoord2f(1, 0); glVertex3f(outerX2, roadHeight, outerZ2);
	glTexCoord2f(1, 1); glVertex3f(innerX2, roadHeight, outerZ2);
	glTexCoord2f(0, 1); glVertex3f(innerX1, roadHeight, outerZ2);

	glTexCoord2f(0, 0); glVertex3f(outerX1, roadHeight, outerZ1);
	glTexCoord2f(1, 0); glVertex3f(outerX1, roadHeight, outerZ2);
	glTexCoord2f(1, 1); glVertex3f(innerX1 - marginOffset, roadHeight, outerZ2);
	glTexCoord2f(0, 1); glVertex3f(innerX1 - marginOffset, roadHeight, outerZ1);

	glTexCoord2f(0, 0); glVertex3f(outerX2, roadHeight, outerZ1);
	glTexCoord2f(1, 0); glVertex3f(outerX2, roadHeight, outerZ2);
	glTexCoord2f(1, 1); glVertex3f(innerX2 + marginOffset, roadHeight, outerZ2);
	glTexCoord2f(0, 1); glVertex3f(innerX2 + marginOffset, roadHeight, outerZ1);

	glEnd();
}


