/*
 * Author: Brandon Valiente
 * Assignment Title: Group Project
 * Assignment Description: This program creates a controllable player class
 * Due Date: 12/9/2019
 * Date Created: 12/9/19
 * Date Last Modified: 12/9/19
 */

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "TheVault.h"
#include "Bullet.h"

class Player{
    int cannonSizeX;
    int cannonSizeY;
    int speed;
    int cannonX;
    int cannonY;
    Rectangle_t bound;
    Point p;

public:
    Player();

/*
 * description: gets player's x coordinate
 * return: int
 * precondition: player exists
 * postcondition: no values changed
 */

    int getX();

/*
 * description: gets player's y coordinate
 * return: int
 * precondition: player exists
 * postcondition: no values changed
 */

    int getY();


/*
 * description: spawns the player's ship
 * return: void
 * precondition: games has started
 * postcondition: ship is displayed to the screen
 */

    void spawn(SDL_Plotter& g);

/*
 * description: ship movement and controls is implemented
 * return: void
 * precondition: player exists and playable
 * postcondition: player ship moves and acts in accordance to user input
 */

    void ship(SDL_Plotter& g, char key);

/*
 * description: gets the rectangle border of player ship
 * return: Rectangle_t
 * precondition: player exists
 * postcondition: no values changed
 */

    Rectangle_t getRect();



};

#endif // PLAYER_H_INCLUDED
