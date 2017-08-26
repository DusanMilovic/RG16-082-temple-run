static float bushY = -0.4, bushZ = -3.1;

static void draw_bush(){
    color(1);
    glTranslatef(0, bushY, bushZ);
    glRotatef(16, 1, 0, 0);
    glutSolidCube(0.2);
    glRotatef(-16, 1, 0, 0);
    glTranslatef(0, -bushY, -bushZ);
}