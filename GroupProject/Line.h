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

#ifndef LINE_H_
#define LINE_H_

#include "Point.h"
#include "Color.h"

using namespace std;

class Line{
    private:
        Point p1, p2;
        Color c;


    public:

        Line(Point = Point(0,0), Point = Point(1,1), Color = BLACK);
        /*
         description: returns if there is a slope and sets the value of slope
         return: bool
         precondition: int exists, Point exists
         postcondition: nothing altered except value of slope if there is one
                        is set to double
        */
        bool slope(double& m) const;
         /*
         description: finds y intercept of line
         return: double
         precondition: slope function exists, points exist
         postcondition: nothing altered but y-intercept if there is one is
                        returned
        */
        double y_intercept() const;
        /*
         description: draws line to screen
         return: void
         precondition: SDL_Plotter exists, two points exist
         postcondition: nothing altered but pixels to form line plottted
        */
        void draw(SDL_Plotter&);
        /*
        description: set Point to x and y values
        return: void
        precondition: Point object exists
        postcondition: Point object set to new values
        */

        void setPointOne(const Point);
        /*
        description: set Point to x and y values
        return: void
        precondition: Point object exists
        postcondition: Point object set to new values
        */
        void setPointTwo(const Point);
        /*
         description: set color of Line
         return: void
         precondition: Color object exists
         postcondition: color set but nothing else altered
        */
        void setColor(const Color);
        /*
         description: returns Point object
         return: Point object
         precondition: Point exists
         postcondition: Point returned, nothing altered
        */
        Point getPointOne() const;
        /*
         description: returns Point object
         return: Point object
         precondition: Point exists
         postcondition: Point returned, nothing altered
        */
        Point getPointTwo() const;
        /*
         description: returns Color object
         return: Color
         precondition: Color exists
         postcondition: nothing altered, Color object returned
        */
        Color getColor() const;

};

#endif /* line_h */
