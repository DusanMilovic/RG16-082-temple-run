/* sphere size and id in witch path is sphere currently */
static float sphereX = 0.0, sphereY = -0.6, sphereZ = -2.5, sphereSize = 0.1;
static int sphereXid = 0; // -1 0 1, left - middle - right path
static int isJumping = 0;
static int activated;
static int collisionId = 0;
static float ground = -0.1;


float sphereXCopy;
int left =0;
int right = 0;
float move_y;
float move_z;


bool fullscreen;
bool changeRunner;
bool changeView;

int brojac = 0;

static float moveSpeed = 0.5;

static void randInit(){
    sphereX = 0.0, sphereY = -0.6, sphereZ = -2.5, sphereSize = 0.1;
    sphereXid = 0;
    isJumping = 0;
    activated = 0;
    collisionId = 0;
    ground = -0.1;
    left = 0;
    right = 0;    
    moveSpeed = 0.5;
    //move_y = brojac*227.683990;
    move_y = -0.8+41*0.055+0.04;
    move_z = brojac*-782.100037;
    //brojac = 0;
    fullscreen = true;
    changeRunner = false;
    changeView = false;
}

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
            sleep(2);
            randInit();
        }
    } else {
        if (sphereXid == id_x &&
            runnerY <= sphereY + sphereSize - 0.04 &&
            runnerY >= sphereY - sphereSize + 0.04 &&
            runnerZ >= sphereZ - sphereSize*10 - 0.1 &&
            runnerZ <= sphereZ + sphereSize*10 + 0.1){
                if (sphereY < -0.55){
                    
                    activated = 0;
                    collisionId = 1;
                    sleep(2);
                    randInit();
                } else {
                    ground = -0.4;
                }
        }
    }
}