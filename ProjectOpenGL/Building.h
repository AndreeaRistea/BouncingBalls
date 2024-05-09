//#pragma once

unsigned int loadTexture(const char* texturePath);

void drawBuilding(float x, float y, float z, float width, float height, float depth, unsigned int textureID) {
    glBindTexture(GL_TEXTURE_2D, textureID);
    glPushMatrix();
    glTranslatef(x, y, z);

    glBegin(GL_QUADS);

    // Fața de jos
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, 0.0f, depth);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, depth);

    // Fața superioară
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, height, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, height, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, depth);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, height, depth);

    // Fața din spate
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, depth);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0.0f, depth);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, depth);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, height, depth);

    // Fața din față
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, height, 0.0f);

    // Fața stângă
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, depth);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, height, depth);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, height, 0.0f);

    // Fața dreaptă
    glTexCoord2f(0.0f, 0.0f); glVertex3f(width, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(width, 0.0f, depth);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(width, height, depth);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(width, height, 0.0f);

    glEnd();
    glPopMatrix();
}
