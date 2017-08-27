/* sphere size and id in witch path is sphere currently */
static float sphereX = 0.0, sphereY = -0.6, sphereZ = -2.5, sphereSize = 0.1;
static int sphereXid = 0; // -1 0 1, left - middle - right path
static int isJumping = 0;
static int activated;
static int collisionId = 0;

static void smash(int id, int id_x, float runnerY, float runnerZ){
    /* proveravamo da li je doslo do sudara sa drvetom ili sa zbunjem */
    /* drvo - 1, zbunje - 0 */

    /* first param id of tree or bush
       second param id of path where the obstcale is
       third param y coord of runner
       forth param z coord of runner
    */

    if (id == 0){
        if (!isJumping && sphereXid == id_x &&
            runnerY <= sphereY + sphereSize/2 + 0.12 &&
            runnerY >= sphereY - sphereSize/2 - 0.12 &&
            runnerZ <= sphereZ + sphereSize/2 + 0.12 &&
            runnerZ >= sphereZ - sphereSize/2 - 0.12){
            activated = 0;
            collisionId = 1;
        }
    } else {
        if (sphereXid == id_x &&
            runnerY <= sphereY + sphereSize - 0.04 &&
            runnerY >= sphereY - sphereSize + 0.04 &&
            runnerZ >= sphereZ - sphereSize*10 - 0.1 &&
            runnerZ <= sphereZ + sphereSize*10 + 0.1){
            activated = 0;
            collisionId = 1;
        }
    }
}