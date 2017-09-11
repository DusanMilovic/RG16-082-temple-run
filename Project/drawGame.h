#define MOVE_X 0.6
#define MOVE_Y 1.15
#define MOVE_Z 3.95

static void draw_game(int level, float moveY, float moveZ){
    draw_tracks();
    
    int mode;

    /* level is always different (for loop),
    depends on that, we make different path mode,
    we have diferent modes, obstcales positions */
    
    /* IDEA - from 0-3 (for loop) only possible level is 0
              from 4-6 (for loop) we add 1 more level so possible are 0,1
              from 7-9 (for loop) we add 1 more level so possible are 0,1,2
              from 10-inf we add 1 more, so the all are possible to be shown 0,1,2,3
    */
    if(level > 10){
        mode = 4; /* 10,11 ... LVL = 0,1,2,3 */
    }
    else if(level > 6){
        mode = 3; /* 7,8,9 LVL=0, 1, 2 */
    }
    else if(level > 3){
        mode = 2;/* 4,5,6 LVL=0, 1 */
    }
    else mode = 1;/* FROM 0-3 LVL=0 */

    switch (level % mode){
        case 1: 
            draw_bush();
            smash(0, 0, moveY+bushY, moveZ+bushZ);

            glTranslatef(-MOVE_X, 0, 0);
            draw_tree();
            glTranslatef(MOVE_X, 0, 0);
            if(!isJumping){
                smash(1, -1, moveY+treeY, moveZ+treeZ);
            }
            
            glTranslatef(MOVE_X, 0, 0);
            draw_tree();
            glTranslatef(-MOVE_X, 0, 0);
            if(!isJumping){
                smash(1, 1, moveY+treeY, moveZ+treeZ);
            }
            
            glTranslatef(0, MOVE_Y/1.2, -MOVE_Z/1.2);
            draw_tree();
            glTranslatef(0, -MOVE_Y/1.2, MOVE_Z/1.2);
            if(!isJumping){
                smash(1, 0, moveY+treeY+MOVE_Y/1.2, moveZ+treeZ-MOVE_Z/1.2);
            }
            
            glTranslatef(-MOVE_X, MOVE_Y, -MOVE_Z);
            draw_bush();
            glTranslatef(MOVE_X, -MOVE_Y, MOVE_Z);
            smash(0, -1, moveY+bushY+MOVE_Y, moveZ+bushZ-MOVE_Z);

            glTranslatef(MOVE_X, MOVE_Y, -MOVE_Z);
            draw_bush();
            glTranslatef(-MOVE_X, -MOVE_Y, MOVE_Z);
            smash(0, 1, moveY+bushY+MOVE_Y, moveZ+bushZ-MOVE_Z);

            glTranslatef(-MOVE_X, MOVE_Y*1.5, -MOVE_Z*1.5);
            draw_tree();
            glTranslatef(MOVE_X, -MOVE_Y*1.5, MOVE_Z*1.5);
            if(!isJumping){
                smash(1, -1, moveY+treeY+MOVE_Y*1.5, moveZ+treeZ-MOVE_Z*1.5);
            }
            
            glTranslatef(0, MOVE_Y*1.5, -MOVE_Z*1.5);
            draw_bush();
            glTranslatef(0, -MOVE_Y*1.5, MOVE_Z*1.5);
            smash(0, 0, moveY+bushY+MOVE_Y*1.5, moveZ+bushZ-MOVE_Z*1.5);

            glTranslatef(MOVE_X, MOVE_Y*1.5, -MOVE_Z*1.5);
            draw_bush();
            glTranslatef(-MOVE_X, -MOVE_Y*1.5, MOVE_Z*1.5);
            smash(0, 1, moveY+bushY+MOVE_Y*1.5, moveZ+bushZ-MOVE_Z*1.5);

            break;
        case 2:
            glTranslatef(-MOVE_X, 0, 0);
            draw_tree();
            glTranslatef(MOVE_X, 0, 0);
            if(!isJumping){
                smash(1, -1, moveY+treeY, moveZ+treeZ);
            }
            
            draw_tree();
            if(!isJumping){
                smash(1, 0, moveY+treeY, moveZ+treeZ);
            }
            
            glTranslatef(MOVE_X, MOVE_Y/1.5, -MOVE_Z/1.5);
            draw_tree();
            glTranslatef(-MOVE_X, -MOVE_Y/1.5, MOVE_Z/1.5);
            if(!isJumping){
                smash(1, 1, moveY+treeY+MOVE_Y/1.5, moveZ+treeZ-MOVE_Z/1.5);
            }
                
            glTranslatef(0, MOVE_Y, -MOVE_Z);
            draw_bush();
            glTranslatef(0, -MOVE_Y, MOVE_Z);
            smash(0, 0, moveY+bushY+MOVE_Y, moveZ+bushZ-MOVE_Z);

            glTranslatef(0, MOVE_Y*1.5, -MOVE_Z*1.5);
            draw_bush();
            glTranslatef(0, -MOVE_Y*1.5, MOVE_Z*1.5);
            smash(0, 0, moveY+bushY+MOVE_Y*1.5, moveZ+bushZ-MOVE_Z*1.5);

            glTranslatef(-MOVE_X, MOVE_Y/1.5, -MOVE_Z/1.5);
            draw_tree();
            glTranslatef(MOVE_X, -MOVE_Y/1.5, MOVE_Z/1.5);
            if(!isJumping){
                smash(1, -1, moveY+treeY+MOVE_Y/1.5, moveZ+treeZ-MOVE_Z/1.5);
            }
            
            glTranslatef(-MOVE_X, MOVE_Y*1.2, -MOVE_Z*1.2);
            draw_tree();
            glTranslatef(MOVE_X, -MOVE_Y*1.2, MOVE_Z*1.2);
            if(!isJumping){
                smash(1, -1, moveY+treeY+MOVE_Y*1.2, moveZ+treeZ-MOVE_Z*1.2);
            }
            
            break;
        case 3:
            draw_tree();
            if(!isJumping){
                smash(1, 0, moveY+treeY, moveZ+treeZ);
            }
            
            glTranslatef(MOVE_X, MOVE_Y/4, -MOVE_Z/4);
            draw_tree();
            glTranslatef(-MOVE_X, -MOVE_Y/4, MOVE_Z/4);
            if(!isJumping){
                smash(1, 1, moveY+treeY+MOVE_Y/4, moveZ+treeZ-MOVE_Z/4);
            }
            
            glTranslatef(-MOVE_X, MOVE_Y/4, -MOVE_Z/4);
            draw_bush();
            glTranslatef(MOVE_X, -MOVE_Y/4, MOVE_Z/4);
            smash(0, -1, moveY+bushY+MOVE_Y/4, moveZ+bushZ-MOVE_Z/4);
            
            glTranslatef(-MOVE_X, MOVE_Y, -MOVE_Z);
            draw_tree();
            glTranslatef(MOVE_X, -MOVE_Y, MOVE_Z);
            if(!isJumping){
                smash(1, -1, moveY+treeY+MOVE_Y, moveZ+treeZ-MOVE_Z);
            }
            
            glTranslatef(0, MOVE_Y*1.2, -MOVE_Z*1.2);
            draw_tree();
            glTranslatef(0, -MOVE_Y*1.2, MOVE_Z*1.2);
            if(!isJumping){
                smash(1, 0, moveY+treeY+MOVE_Y*1.2, moveZ+treeZ-MOVE_Z*1.2);
            }
            
            glTranslatef(MOVE_X, MOVE_Y*1.5, -MOVE_Z*1.5);
            draw_bush();
            glTranslatef(-MOVE_X, -MOVE_Y*1.5, MOVE_Z*1.5);
            smash(0, 1, moveY+bushY+MOVE_Y*1.5, moveZ+bushZ-MOVE_Z*1.5);

            break;
        /*0-ti level*/
        default:
            glTranslatef(MOVE_X, 0, 0);
            draw_tree();
            glTranslatef(-MOVE_X, 0, 0);
            if(!isJumping){
                smash(1, 1, moveY+treeY, moveZ+treeZ);    
            }
            
            glTranslatef(-MOVE_X, 0, 0);
            draw_tree();
            glTranslatef(MOVE_X, 0, 0);
            if(!isJumping){
                smash(1, -1, moveY+treeY, moveZ+treeZ);
            }
            
            glTranslatef(0, MOVE_Y/1.5, -MOVE_Z/1.5);
            draw_tree();
            glTranslatef(0, -MOVE_Y/1.5, MOVE_Z/1.5);
            if(!isJumping){
                smash(1, 0, moveY+treeY+MOVE_Y/1.5, moveZ+treeZ-MOVE_Z/1.5);
            }
                
            glTranslatef(-MOVE_X, MOVE_Y/1.2, -MOVE_Z/1.2);
            draw_tree();
            glTranslatef(MOVE_X, -MOVE_Y/1.2, MOVE_Z/1.2);
            if(!isJumping){
                smash(1, -1, moveY+treeY+MOVE_Y/1.2, moveZ+treeZ-MOVE_Z/1.2);
            }
            
            glTranslatef(MOVE_X, MOVE_Y, -MOVE_Z);
            draw_bush();
            glTranslatef(-MOVE_X, -MOVE_Y, MOVE_Z);
            smash(0, 1, moveY+bushY+MOVE_Y, moveZ+bushZ-MOVE_Z);

            glTranslatef(MOVE_X, MOVE_Y*1.5, -MOVE_Z*1.5);
            draw_tree();
            glTranslatef(-MOVE_X, -MOVE_Y*1.5, MOVE_Z*1.5);
            if(!isJumping){
                smash(1, 1, moveY+treeY+MOVE_Y*1.5, moveZ+treeZ-MOVE_Z*1.5);
            }
            
            glTranslatef(-MOVE_X, MOVE_Y*1.5, -MOVE_Z*1.5);
            draw_tree();
            glTranslatef(MOVE_X, -MOVE_Y*1.5, MOVE_Z*1.5);
            if(!isJumping){
                smash(1, -1, moveY+treeY+MOVE_Y*1.5, moveZ+treeZ-MOVE_Z*1.5);
            }
                
            glTranslatef(0, MOVE_Y*1.5, -MOVE_Z*1.5);
            draw_bush();
            glTranslatef(0, -MOVE_Y*1.5, MOVE_Z*1.5);
            smash(0, 0, moveY+bushY+MOVE_Y*1.5, moveZ+bushZ-MOVE_Z*1.5);
    }
}
