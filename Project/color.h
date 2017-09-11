static void color(int id){
    GLfloat ambient_coeffs[] = { 0.1, 0.1, 0.1, 1 };
    GLfloat diffuse_coeffs[] = { 0, 0, 0, 1 }, shininess = 10;
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

    switch(id){
        case 0: //tree
                diffuse_coeffs[0] = 0.36;
                diffuse_coeffs[1] = 0.22;
                diffuse_coeffs[2] = 0.03;
                break;
        case 1: //bush
                diffuse_coeffs[0] = 0;
                diffuse_coeffs[1] = 1;
                diffuse_coeffs[2] = 0;
                break;
        case 2: //runner     
                diffuse_coeffs[0] = 1;
                diffuse_coeffs[1] = 1;
                diffuse_coeffs[2] = 0;
                break;
        case 3: //red runner
                diffuse_coeffs[0] = 1;
                diffuse_coeffs[1] = 0;
                diffuse_coeffs[2] = 0;
                break;
        default:        
                diffuse_coeffs[0] = 0.1;
                diffuse_coeffs[1] = 0.1;
                diffuse_coeffs[2] = 0.1;
    }

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}
