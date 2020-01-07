/*
* Author: Matthew Day
* Assignment Title: Pirate Defense (Return One Group Project)
* Assignment Description: This program creates a number class
*   that can increment numbers and draw them on the screen
* Due Date: 12/9/19
* Date Created: 11/29/19
* Date Last Modified: 12/9/19
 */
#ifndef NUMBERS_H_INCLUDED
#define NUMBERS_H_INCLUDED

#include "SDL_Plotter.h"
#include "Numbers.h"

class Number{
    int number;
    int numberX, numberY;

public:
    Number(){
        numberX = 10;
        numberY = 30;
        number = 0;
    }
    Number(int x, int y, int n){
        numberX = x;
        numberY = y;
        number = n;
    }
//************************************************************
// description: sets the number (variable) of the Number object
// return: void (none)
// precondition: int n is valid
// postcondition: number (variable) is set to n
//************************************************************
    void setNumber(int n);
//************************************************************
// description: sets the Number's X coordinate
// return: void (none)
// precondition: int n is valid
// postcondition: numberX is set to n
//************************************************************
    void setX(int);
//************************************************************
// description: sets the Number's Y coordinate
// return: void (none)
// precondition: int n is valid
// postcondition: numberY is set to n
//************************************************************
    void setY(int);
//************************************************************
// description: gets the Number's X coordinate
// return: int
// precondition: the Number has a valid x coordinate
// postcondition: numberX is returned
//************************************************************
    int getX();
//************************************************************
// description: gets the Number's Y coordinate
// return: int
// precondition: the Number has a valid y coordinate
// postcondition: numberY is returned
//************************************************************
    int getY();
//************************************************************
// description: gets the Number's  (variable)
// return: int
// precondition: the Number has a valid number
// postcondition: number (variable) is returned
//************************************************************
    int getNumber();
//************************************************************
// description: the Number is drawn on SDL plotter g
// return: void (none)
// precondition: SDL_Plotter g is valid
// postcondition: the Number is drawn on SDL plotter g
//************************************************************
    void draw(SDL_Plotter& g);
};

//************************************************************
// description: the numbers of Number array num[] are incremented by
//   1 multiplied by the scoreMod
// return: void (none)
// precondition: Number array num[], int n, and int scoreMod
// are valid
// postcondition: the numbers of Number array num[] are incremented by
// 1 multiplied by the scoreMod
//************************************************************
void increment(Number num[], int n, int scoreMod);

#endif // NUMBERS_H_INCLUDED
