static float treeY = -0.4, treeZ = -3.1;

static void draw_tree(){
    color(0);
    glTranslatef(0, treeY, treeZ);
    glScalef(1, 4, 1);
    glRotatef(16, 1, 0, 0);
    glutSolidCube(0.2); 
    glRotatef(-16, 1, 0, 0);
    glScalef(1, 0.25, 1);
    glTranslatef(0, -treeY, -treeZ);
}