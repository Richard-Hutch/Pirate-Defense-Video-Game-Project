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
#ifndef RECTANGLE_T_H_INCLUDED
#define RECTANGLE_T_H_INCLUDED
#include "Point.h"
#include "Color.h"

class Rectangle_t{
private:
    Point upperLeft, lowerRight;
    bool isAlive;
    Color c;

public:
    Rectangle_t();
    Rectangle_t(Point, Point, Color);
    Rectangle_t(const Rectangle_t&);
    /*
     description: sets the top left point of rectangle
     return: void
     precondition: Point exists
     postcondition: Point set to upper left but other Point unaltered
    */
    void setUpperLeft(const Point);
    /*
     description: sets lower right point of rectangle
     return: void
     precondition: Point exists
     postcondition: point set and other point unchanged
    */
    void setLowerRight(const Point);
    /*
     description: sets color of rectangle
     return: void
     precondition: color exists
     postcondition: Color set for rectangle
    */
    void setColor(const Color);
    /*
     description: sets whether rectangle is alive or not
     return: void
     precondition: bool exists
     postcondition: sets isAlive bool
    */
    void setIsAlive(bool);
    /*
     description: returns Point of top left point of rect
     return: Point
     precondition: Point exists
     postcondition: returns top left point of rect, nothing altered
    */
    Point getUpperLeft() const;
    /*
     description: returns Point of bottom right point of rect
     return: Point
     precondition: Point exists
     postcondition: returns bottom right point of rect, nothing altered
    */
    Point getLowerRight() const;
    /*
     description: returns rgb values for color of rectangle
     return: Color
     precondition: Color exists
     postcondition: returns color of rectangle, nothing altered
    */
    Color getColor() const;
    /*
     description: returns whether or not the rectangle is alive
     return: bool
     precondition: bool exists
     postcondition: returns if rectangle is alive, nothing altered
    */
    bool getIsAlive();
    /*
     description: plot pixels in shape of rectangle
     return: void
     precondition: SDL_Plotter exists, circle exists
     postcondition: nothing altered, plots pixels
    */
    void draw(SDL_Plotter& g) const;
    /*
     description: plot pixels in shape of rectangle but in color of background
     return: void
     precondition: SDL plotter exists
     postcondition: nothing altered but pixels plotted
    */
    void eraseChest(SDL_Plotter& g) const;

};

#endif // RECTANGLE_T_H_INCLUDED
