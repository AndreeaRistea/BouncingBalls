void drawTree(float posX, float posY, float posZ, float trunkHeight, float trunkRadius, float crownRadius, unsigned int trunkTexture, unsigned int crownTexture) {
    // Salvează atributele curente și lumina pentru OpenGL
    glPushAttrib(GL_CURRENT_BIT | GL_LIGHTING_BIT);
    
    // Translatează matricea pentru a plasa copacul în poziția specificată
    glPushMatrix();
    glTranslatef(posX, posY, posZ);

    // Desenează trunchiul
    glPushMatrix();
    // Setează textura pentru trunchi
    glBindTexture(GL_TEXTURE_2D, trunkTexture);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotire pentru a alinia cilindrul vertical
    GLUquadricObj *quad = gluNewQuadric();
    // Permite texturarea cilindrului
    gluQuadricTexture(quad, GL_TRUE);
    // Normale pentru iluminare corectă
    gluQuadricNormals(quad, GLU_SMOOTH);
    // Desenează cilindrul
    gluCylinder(quad, trunkRadius, trunkRadius, trunkHeight, 20, 20);
    gluDeleteQuadric(quad);
    glPopMatrix();

    // Desenează coroana
    glPushMatrix();
    // Setează textura pentru coroană
    glBindTexture(GL_TEXTURE_2D, crownTexture);
    glTranslatef(0.0f, trunkHeight, 0.0f); // Translatează coordonatele la partea de sus a trunchiului
    GLUquadricObj* quadCrown = gluNewQuadric();
    // Permite texturarea sferei
    gluQuadricTexture(quadCrown, GL_TRUE);
    // Normale pentru iluminare corectă
    gluQuadricNormals(quadCrown, GLU_SMOOTH);
    // Desenează sfera (coroana copacului)
    gluSphere(quadCrown, crownRadius, 20, 20);
    // Eliberează quadricul pentru coroană
    gluDeleteQuadric(quadCrown);
    glPopMatrix();

    // Restabilește starea inițială a OpenGL
    glPopMatrix();
    glPopAttrib();
}
