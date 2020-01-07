/*
* Author: Noah Lambaria
* Assignment Title: Group Project
* Assignment Description: This project creates space-invaders game,
*       with a Pirate theme. I wrote the Special Treasure chest,
*       Ending screen, and Barrier to protect the player.
* Due Date: 12/9/19
* Date Created: 11/20/19
* Date Last Modified: 12/9/19
*/

#ifndef Special_h
#define Special_h

#include "Rectangle_t.h"
#include "TheVault.h"
using namespace std;

class Special{
    private:
        //main part of chest:
        Rectangle_t r;
        //latch:
        Rectangle_t latch;

        //line in-between chest:
        Rectangle_t line;
        int x = 0;
        int speed = 1;
        bool right = true;
        bool alive = true;
        int y1 = 100;
        int y2 = 120;

        int latchY1 = 105;
        int latchY2 = 115;

        int lineY1 = 108;
        int lineY2 = 112;



    public:

        //************************************************************
        // description: This is the Default Constructor for Special
        // return: none
        // precondition: A special object is created.
        // postcondition: The x/y coordinates and the color of the chest
        //      are set to the default values.
        //
        //************************************************************
        Special();

        //************************************************************
        // description: This is a constructor of special with a
        //      Rectangle_t the user wants to enter.
        // return: none
        // precondition: A special object and a Rectangle_t exists.
        // postcondition: A Special (Treasure chest) is created with
        //      the Rectangle_t parameters.
        //
        //************************************************************
        Special(Rectangle_t);

        //************************************************************
        // description: Constructor for Special with another Special
        //              object given
        // return: Special
        // precondition: Special object
        // postcondition: Special object exists
        //
        //************************************************************
        Special(const Special&);

        //************************************************************
        // description: handles movement and drawing of treasurechest
        // return: void
        // precondition: SDL Plotter exists
        // postcondition: chest pixels are plotted
        //
        //************************************************************
        void moveChest(SDL_Plotter&);

        //************************************************************
        // description: SDL Plotter to update screen with background
        //              color after chest moves
        // return: void
        // precondition: SDL Plotter exists
        // postcondition: background color pixels placed
        //
        //************************************************************
        void eraseChest(SDL_Plotter&);

        //************************************************************
        // description: sets treasure chest is alive or not
        // return: void
        // precondition: bool
        // postcondition: bool altered
        //
        //************************************************************
        void setAlive(bool);

        //************************************************************
        // description: returns state of chest's life
        // return: bool
        // precondition: bool exists
        // postcondition: bool altered
        //
        //************************************************************
        bool getAlive();

        //************************************************************
        // description: set x value of chest
        // return: void
        // precondition: int exists
        // postcondition: x altered
        //
        //************************************************************
        void setX(int);

        //************************************************************
        // description: returns rectangle body of object
        // return: Rectangle_t object
        // precondition: rectangle_t exists
        // postcondition: rect returned, nothing altered
        //
        //************************************************************
        Rectangle_t getRect();

};

#endif /* Special_h */
