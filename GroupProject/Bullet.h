/*
 * Author: Brandon Valiente
 * Assignment Title: Group Project
 * Assignment Description: This program creates a bullet class
 * Due Date: 12/9/2019
 * Date Created: 12/9/19
 * Date Last Modified: 12/9/19
 */

#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "TheVault.h"
#include "Player.h"


class Bullet {
    int currentX, enemyX;
    int currentY, enemyY;
    bool active, activeEnemy;
    bool friendly;
    Rectangle_t bound;
    Point p;
    Color c;

public:
    Bullet();

/*
 * description: gets rectangle boundary
 * return: Rectangle_t
 * precondition: bound exists
 * postcondition: returns rectangle bound
 */

    Rectangle_t getRect();

/*
 * description: gets if player bullet is active
 * return: boolean
 * precondition: none
 * postcondition: returns if player bullet is active
 */

    bool getActive();

/*
 * description: gets if enemy bullet is active
 * return: boolean
 * precondition: none
 * postcondition: returns if enemy bullet is active
 */

    bool getEBulletActive();

/*
 * description: sets if player bullet is active
 * return: void
 * precondition: boolean
 * postcondition: set player bullet active status
 */

    void setActive(bool);

/*
 * description: sets if enemy bullet is active
 * return: void
 * precondition: boolean
 * postcondition: set enemy bullet active status
 */

    void setEBulletActive(bool);

/*
 * description: shoots enemy bullet
 * return: void
 * precondition: enemy exists and shoots
 * postcondition: fires bullet downwards
 */

    void enemyShoot(int, int, SDL_Plotter& g);

/*
 * description: shoots player bullet
 * return: void
 * precondition: player exists and shoots
 * postcondition: fires bullet upwards
 */

    void friendlyShoot(int, int, SDL_Plotter& g);

/*
 * description: draws player bullet to screen
 * return: void
 * precondition: player exists and shoots
 * postcondition: draws fired player bullet
 */

    void drawBullet(SDL_Plotter& g);

/*
 * description: draws enemy bullet to screen
 * return: void
 * precondition: enemy exists and shoots
 * postcondition: draws fired enemy bullet
 */

    void drawEnemyBullet(SDL_Plotter& g);

/*
 * description: erases player bullet
 * return: void
 * precondition: bullet in situation of being erased
 * postcondition: bullet no longer displayed on screen
 */

    void eraseBullet(SDL_Plotter& g);

/*
 * description: erases enemy bullet
 * return: void
 * precondition: bullet in situation of being erased
 * postcondition: bullet no longer displayed on screen
 */

    void enemyEraseBullet(SDL_Plotter& g);

};

#endif // BULLET_H_INCLUDED
