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
*/

#ifndef POINT_H_
#define POINT_H_
#include <ostream>
#include <cmath>
#include "SDL_Plotter.h"
#include "Color.h"

using namespace std;


struct Point{
    int x, y;
    Color c;
    Point();

    Point(int, int);


    Point(const Point&);

    /*
     description: draws Point on to screen
     return: void
     precondition: SDL_Plotter exists and Point exists
     postcondition: nothing altered, but point plotted to screen
    */
    void draw(SDL_Plotter&);
    /*
     description: return double, distance between points
     return: double
     precondition: Point exists
     postcondition: point returned, nothing altered
    */
    double distance(Point);


};


#endif /* point_h */
