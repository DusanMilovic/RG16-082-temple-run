/* paths info */
static float SceneY = 1.5, SceneZ = -10, SceneYDown = -0.8, SceneZDown = -2.1;

static void draw_tracks(){
    glDisable(GL_LIGHTING);
    
    glColor3f(0.35, 0.20, 0.07);
    /* Very left fence */
    glBegin(GL_POLYGON);
        glVertex3f(-0.85, SceneYDown, SceneZDown);
        glVertex3f(-0.78, SceneYDown, SceneZDown);
        glVertex3f(-0.78, SceneY, SceneZ);
        glVertex3f(-0.85, SceneY, SceneZ);
    glEnd();
    
    /* very right fence */    
    glColor3f(0.35, 0.20, 0.07);
    glBegin(GL_POLYGON);
        glVertex3f(0.80, SceneYDown, SceneZDown);
        glVertex3f(0.86, SceneYDown, SceneZDown);
        glVertex3f(0.86, SceneY, SceneZ);
        glVertex3f(0.80, SceneY, SceneZ);
    glEnd();

    /* path color */
    glColor3f(0.93, 0.86, 0.5);
        //middle path
        glBegin(GL_POLYGON);
            glVertex3f(-0.33, SceneYDown, SceneZDown);
            glVertex3f(0.33, SceneYDown, SceneZDown);
            glVertex3f(0.31, SceneYDown+41*0.055+0.04, SceneZDown-41*0.185);
            glVertex3f(-0.31, SceneYDown+41*0.055+0.04, SceneZDown-41*0.185);
        glEnd();
        
        //left path
        glBegin(GL_POLYGON);
            glVertex3f(-0.77, SceneYDown, SceneZDown);
            glVertex3f(-0.31, SceneYDown, SceneZDown);
            glVertex3f(-0.31, SceneYDown+41*0.055+0.04, SceneZDown-41*0.185);
            glVertex3f(-0.77, SceneYDown+41*0.055+0.04, SceneZDown-41*0.185);
    glEnd();
        
        //right path
        glBegin(GL_POLYGON);
            glVertex3f(0.31, SceneYDown, SceneZDown-0.01);
            glVertex3f(0.79, SceneYDown, SceneZDown-0.01);
            glVertex3f(0.79, SceneYDown+41*0.055+0.04, SceneZDown-41*0.185);
            glVertex3f(0.31, SceneYDown+41*0.055+0.04, SceneZDown-41*0.185);
    glEnd();
        

    /* Turn on the lights */
    glEnable(GL_LIGHTING);
}