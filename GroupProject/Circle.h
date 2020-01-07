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
#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Point.h"
#include "Color.h"
#include "SDL_Plotter.h"

class Circle_t{
private:
    double radius;
    Point center;
    Color c;

public:
    Circle_t();
    Circle_t(double, Point, Color);
    Circle_t(const Circle_t&);
    /*
    description: set radius of circle
    return: void
    precondition: double exists
    postcondition: radius altered
    */
    void setRadius(double);
     /*
     description: set center
     return: void
     precondition: Point object exists
     postcondition: center of circle altered
    */
    void setCenter(Point);
    /*
     description: set color of circle
     return: void
     precondition: Color object exists
     postcondition: set color of circle
    */
    void setColor(Color);
    /*
     description: returns radius of circle
     return: double
     precondition: radius value exists
     postcondition: returns radius, alters nothing
    */
    double getRadius() const;
    /*
     description: get center of circle
     return: Point object
     precondition: Point object exists
     postcondition: returns Point, alters nothing
    */
    Point getCenter() const;
    /*
     description: returns Color object
     return: Color object
     precondition: Color object exists
     postcondition: returns Color object, nothing altered
    */
    Color getColor() const;
    /*
     description: plot pixels in shape of circle
     return: void
     precondition: SDL_Plotter exists, circle exists
     postcondition: nothing altered, plots pixels
    */
    void draw(SDL_Plotter&);
};


#endif // CIRCLE_H_INCLUDED
