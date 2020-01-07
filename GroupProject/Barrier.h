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
#ifndef Barrier_h
#define Barrier_h

#include "TheVault.h"
//#include "Chunk.h"
using namespace std;



class Barriers{
    private:

        int barrierRow = 3;
        int barrierCol = 4;

        int y1 = 550;
        int y2 = 520;
        int x1 = 50;
        int x2 = 100;
        int currentCOL = 0;



    public:

        Rectangle_t partONE[3][4];
        Rectangle_t partTWO[3][4];
        int x = 0;
    
        //************************************************************
        // description: Default constructor for Barriers.
        // return: none
        // precondition: A Barriers object is created.
        // postcondition: Two arrays of Rectangles are set on the screen
        //
        //************************************************************
        Barriers();
    
        //************************************************************
        // description: This is a constructor for a Barrier with the
        //      parameters of another Barrier Object.
        // return: none
        // precondition: Another Barrier object exists
        // postcondition: A Barrier object is created with another
        //      Barriers parameters.
        //
        //************************************************************
        Barriers(const Barriers&);
    
        //************************************************************
        // description: This is a method to get the Array of rectangles
        // return: Rectangle_t
        // precondition: An array of Rectangle exist.
        // postcondition: An array of Rectangles is returned. The array
        //      is left unchanged.
        //
        //************************************************************
        Rectangle_t getArray() const;
    
        //************************************************************
        // description: This method gets the first (left) barrier of
        //      the barriers (partONE).
        // return: Rectangle_t
        // precondition: An array of rectangles exist.
        // postcondition: The fist array of rectangles is returned.
        //      The array is left unchanged.
        //
        //************************************************************
        Rectangle_t getPartOne();
    
        //************************************************************
        // description: This method gets the second (right) barrier of
        //      the barriers (partTWO).
        // return: Rectangle_t
        // precondition: An array of recrtangles exist.
        // postcondition: The second array of rectangles is returned.
        //      The array is left unchanged.
        //
        //************************************************************
        Rectangle_t getPartTwo();
    
        //************************************************************
        // description: This method starts drawing the two barriers
        // return: none
        // precondition: And SDL_Plotter g exists. 
        // postcondition: The barriers are drawn.
        //
        //************************************************************
        void start(SDL_Plotter& g);
    
        //************************************************************
        // description: This method returns the Barrier row size.
        // return: integer
        // precondition: A integer barrier row size exists.
        // postcondition: The barrier row size is returned. It is left
        //      unchanged.
        //
        //************************************************************
        int getBarRow();
    
        //************************************************************
        // description: This method returns the Barrier column size.
        // return: integer
        // precondition: An integer barrier column size exists.
        // postcondition: The barrier column size is returned. It is
        //      left unchanged.
        //
        //************************************************************
        int getBarCol();

};

#endif /* Barrier_h */
