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

#ifndef EndingScreen_h
#define EndingScreen_h

#include "TheVault.h"

const int endingROW = 13;
const int endingCOL = 28;

class EndingScreen{

    private:
        int endingX;
        int endingY;
    
    public:
        //************************************************************
        // description: Default Constructor for EndingScreen.
        // return: none
        // precondition: An EndingScreen object is created
        // postcondition: The ending X and Y coordinates are set to
        //      their proper values.
        //
        //************************************************************
        EndingScreen();
    
        //************************************************************
        // description: Constructor for Endingscreen with x and y
        //      parameters.
        // return: none
        // precondition: Two integers for the x and y coordinates exist.
        // postcondition: An Endingscreen is created with the parameters
        //      inserted, given those x/y coords.
        //
        //************************************************************
        EndingScreen(int x,int y);
    
        //************************************************************
        // description: This method draws the Ending screen of the
        //      game.
        // return: none
        // precondition: SDL_Plotter g exists.
        // postcondition: Game over is displayed to the screen.
        //
        //************************************************************
        void draw(SDL_Plotter& g);
    
        //************************************************************
        // description: This method sets the x coordinate of the
        //      Ending screen.
        // return: none
        // precondition: An integer exists.
        // postcondition: The current x coordinate of the location of
        //      the game over message is set to the new x coordinate.
        //
        //************************************************************
        void setX(int);
    
        //************************************************************
        // description: This method sets the y coordinate of the
        //      Ending screen.
        // return: none
        // precondition: An integer exists.
        // postcondition: The current y coordinate of the location of
        //      the game over message to set to the new y coordinate.
        //
        //************************************************************
        void setY(int);
};

#endif /* EndingScreen_h */
