/*
Author: Richard Hutcheson
Assignment Title: Group Project: "Pirate Defense"
Assignment Description:
                        Small game written with SDL and SDL Plotter.
                        Player is a pirate ship defending his treasure
                        from bounty hunter ships while attempting to get
                        as high of a score as possible and stay alive
Due Date: 12/9/2019
Date Created: 11/17/2019
Date Last Modified: 12/9/2019


Data Abstraction:
    5 int constants for how many rows and columns of Enemy Objects to hold,
      and hold how many rows and columns to make the window of the game
      and for how many score objects to hold in array
    1 char for holding value of user's key presses
    5 ints for direction of enemies to start, int to slow down display of
      movement, two for ints to randomly grab object in array of enemies to
      see if they can fire their cannons, and set spacing for UI letters
    4 bools if bullet and enemy bullet needs to be erased after collision,
      if game is over, if all enemies are wiped out
    1 SDL Plotter object for game window and plotting pixels
    3 Number objects for amnt of lives and for score
    1 EndingScreen to display the game over text on the screen
    2 Bullet objects for player bullet and enemy bullet
    1 Player for player ship to handle
    1 Enemy object array to hold array of enemies to fight player
    1 Barriers object to create barriers to protect player from enemies
    1 Special object to create bonus point objective for player
    1 Rectangle_t for ui line as a visual


Input:
    user input from keyboard to move player ship and fire cannon
Process:

    initialize game objects, sounds, and values.
    spawn objects and organize.
    enter game loop and get key input and draw entities to screen
    check for collisions and move objects accordingly
    update screen

Output:

    lot pixels to display video output for video game via SDL and SDL Plotter

Assumptions:
    it's assumed the player will follow rules outlined in manual and try to have fun
    user has arrow keys in keyboard and has specs that support the game to run
    successfully

*/
#include "TheVault.h"


int main(int argc, char ** argv)
{
    int const ENEMY_ROW = 6;
    int const ENEMY_COL = 7;
    const int ROWS = 800, COLS = 500;
    char key;
    int dir = 1;
    int t = 0;
    int randR, randC;
    bool bulletNeedsErased = false;
    bool enemyBulletNeedsErased = false;
    bool gameOver = false;
    bool allDead = false;

    SDL_Plotter g(ROWS, COLS);

    //INITIALIZE SOUND
    g.initSound("cannon.wav");
    g.initSound("barrierHit.wav");
    g.initSound("explosion.wav");
    g.initSound("gameOver.wav");
    g.initSound("ocean.wav");
    g.initSound("lifeLost.wav");
    g.initSound("shipBreak.wav");

    int const amntScores = 6;
    Number scores[amntScores];
    scores[0].setX(300);
    int xSpacing = scores[0].getX();
    Number theX(30, 35, -1);
    Number lives(50, 30, 3);
    EndingScreen endScreen(125, 300);
    Bullet shot, enemyShot;
    Player ship;
    Enemy fleet[ENEMY_ROW][ENEMY_COL];
    Barriers barrier;
    Special treasureChest;

    Rectangle_t uiLine(Point(1, 60), Point(499, 70), Color( 200, 200, 200));

    srand(time(0));
    //CREATES SEA BACKGROUND
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            g.plotPixel(c, r, 0, 0, 80);
        }
    }

    //CREATES THE SCORE UI
    for (int i = 0; i < amntScores; i++){
            scores[i].setNumber(0);
            if (i > 0){
                xSpacing -= 19;
                scores[i].setX(xSpacing);
            }

    }

    //PLAY OCEAN SOUND
    g.playSound("ocean.wav");

    //SPAWN SHIP
    ship.spawn(g);


    //Initializes army of enemies
    for(int r = 0; r < ENEMY_ROW; r++){
        for(int c = 0; c < ENEMY_COL; c++){

            fleet[r][c].setPoint(Point(80+r*60,150+c*40));
            fleet[r][c].setSize(10);
            fleet[r][c].draw(g);
        }
    }
    /////////////////
    //GAME-----LOOP//
    /////////////////
    while(!g.getQuit()){

        if (!gameOver){
            //RENDER PLAYER AND CHECK FOR KEY INPUT
            if(g.kbhit()){
                key = g.getKey();
                ship.ship(g, key);
                if(key == ' '){
                    shot.friendlyShoot(ship.getX(), ship.getY(), g);
                }
            }

            //Slow down enemies
            if(t % 500 == 0){
                for(int r = 0; r < ENEMY_ROW; r++){
                    for(int c = 0; c < ENEMY_COL; c++){
                        if(fleet[r][c].getIsAlive()){
                            fleet[r][c].drawBound(g);
                        }
                    }
                }
                dir = moveA( ENEMY_COL, ENEMY_ROW, fleet, dir);
                for(int r = 0; r < ENEMY_ROW; r++){
                    for(int c = 0; c < ENEMY_COL; c++){
                        if(fleet[r][c].getIsAlive()){
                            fleet[r][c].draw(g);
                        }
                    }
                }
                //ENEMY SHOOTING
                //i determines shooting
                for (int i = 0; i < 6; i++){
                    randR = rand() % ENEMY_ROW;
                    randC = rand() % ENEMY_COL;
                    if (fleet[randR][randC].getIsAlive() && fleet[randR][randC].getCanShoot()){
                        enemyShot.enemyShoot(fleet[randR][randC].getBound().getUpperLeft().x,
                                             fleet[randR][randC].getBound().getUpperLeft().y, g);
                    }
                }

            }
            //MOVES TREASURE CHEST
            if (t % 8 == 0 && treasureChest.getAlive()){
                treasureChest.moveChest(g);
            }
            //if enemy shot exists, draw it and check collisions
            if (enemyShot.getEBulletActive()){

                enemyShot.drawEnemyBullet(g);

                for (int r = 0; r < barrier.getBarRow(); r++){

                    for (int c = 0; c < barrier.getBarCol(); c++){
                        //ENEMY HITS BARRIERS
                        if (doCollide(enemyShot.getRect(), barrier.partONE[r][c])){
                            g.playSound("barrierHit.wav");

                            //erases rect object. name is a misnomer
                            barrier.partONE[r][c].eraseChest(g);
                            barrier.partONE[r][c].setIsAlive(false);
                            enemyShot.setEBulletActive(false);
                            enemyBulletNeedsErased = true;

                        }
                        if (doCollide(enemyShot.getRect(), barrier.partTWO[r][c])){
                            g.playSound("barrierHit.wav");

                            barrier.partTWO[r][c].setIsAlive(false);
                            //erases rect object. name is a misnomer
                            barrier.partTWO[r][c].eraseChest(g);
                            enemyShot.setEBulletActive(false);
                            enemyBulletNeedsErased = true;

                        }
                    }
                }
                //Enemy bullet hits player
                if (doCollide(ship.getRect(), enemyShot.getRect())){
                    g.playSound("lifeLost.wav");
                    enemyBulletNeedsErased = true;
                    enemyShot.setEBulletActive(false);
                    lives.setNumber(lives.getNumber() - 1);
                }
            }



            t++;

            //IF PLAYER BULLET EXISTS THEN DRAW AND CHECK FOR COLLISIONS
            if (shot.getActive()){

                shot.drawBullet(g);

                //CANNON HITS TREASURE CHEST
                if (doCollide(shot.getRect(), treasureChest.getRect())){
                    g.playSound("explosion.wav");
                    shot.setActive(false);
                    treasureChest.setAlive(false);
                    treasureChest.eraseChest(g);
                    bulletNeedsErased = true;
                    increment(scores, amntScores, 300);
                }

                //PLAYER CANNON BALL HITS ENEMY
                for(int r = 0; r < ENEMY_ROW; r++){
                    for(int c = 0; c < ENEMY_COL; c++){
                        if(fleet[r][c].getIsAlive()){
                            if (doCollide(shot.getRect(), fleet[r][c].getBound())){
                                g.playSound("shipBreak.wav");
                                shot.setActive(false);
                                fleet[r][c].setAlive(false);
                                fleet[r][c].eraseEnemy(g);
                                bulletNeedsErased = true;
                                increment(scores, amntScores, 10);
                            }
                        }
                    }
                }

                //PLAYER HITS ROCK BARRIER
                for (int r = 0; r < barrier.getBarRow(); r++){

                    for (int c = 0; c < barrier.getBarCol(); c++){

                        if (doCollide(shot.getRect(), barrier.partONE[r][c])){
                            g.playSound("barrierHit.wav");
                            shot.setActive(false);
                            bulletNeedsErased = true;
                        }
                        if (doCollide(shot.getRect(), barrier.partTWO[r][c])){
                            g.playSound("barrierHit.wav");
                            shot.setActive(false);
                            bulletNeedsErased = true;
                        }
                    }
                }
            }
            //DRAWS BARRIERS
            barrier.start(g);

            //UI DRAWING
            theX.draw(g);
            lives.draw(g);
            //GAME OVER PLAYER RAN OUT OF LIVES//////////////////////////////
            if (lives.getNumber() == 0){
                g.playSound("gameOver.wav");
                gameOver = true;
            }
            uiLine.draw(g);
            //DRAWS SCORE
            for (int i = 0; i < amntScores; i++){
                    scores[i].draw(g);
            }

            //UPDATE SCREEN
            g.update();
            //ERASES PLAYER'S BULLET
            if (shot.getActive() || bulletNeedsErased){
                shot.eraseBullet(g);

                if (bulletNeedsErased){
                    bulletNeedsErased = false;
                }
            }
            //ERASES ENEMY BULLET
            if (enemyShot.getEBulletActive() || enemyBulletNeedsErased){

                enemyShot.enemyEraseBullet(g);

                if (enemyBulletNeedsErased){

                    enemyBulletNeedsErased = false;
                }
            }


            //CHECKS TO SEE IF IT NEEDS TO RESPAWN ENEMIES
            allDead = true;
            for(int r = 0; r < ENEMY_ROW; r++){
                for(int c = 0; c < ENEMY_COL; c++){
                    if(fleet[r][c].getIsAlive()){
                        allDead = false;
                    }
                }
            }
            if(allDead){
                for(int r = 0; r < ENEMY_ROW; r++){
                    for(int c = 0; c < ENEMY_COL; c++){

                        fleet[r][c].setPoint(Point(80+r*60,150+c*40));
                        fleet[r][c].setSize(10);
                        fleet[r][c].draw(g);
                        fleet[r][c].setAlive(true);
                        fleet[r][c].setShoot(false);
                    }
                }
                if (!treasureChest.getAlive()){
                    treasureChest.setAlive(true);
                    treasureChest.setX(0);
                }
            }





        }else{
            //GAME OVER SCREEN

            if(g.kbhit()){
                key = g.getKey();
            }
            //CREATES BLACK BACKGROUND
            for (int r = 0; r < ROWS; r++){
                for (int c = 0; c < COLS; c++){
                    g.plotPixel(c, r, 0, 0, 0);
                }
            }
            endScreen.draw(g);
            g.update();
        }



    }

    return 0;
}


