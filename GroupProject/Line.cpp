#include "line.h"


Line::Line(Point a, Point b, Color col){
    p1 = a;
    p2 = b;
    c = col;


}


void Line::setPointOne(const Point p){
    p1 = p;
}

void Line::setPointTwo(const Point p){
    p2 = p;
}
void Line::setColor(const Color col){
    c = col;
}


Point Line::getPointOne() const{
    return p1;
}

Point Line::getPointTwo() const{
    return p2;
}

Color Line::getColor() const{
    return c;
}



bool Line::slope(double& m) const{
    bool hasSlope = false;
    hasSlope = p1.x != p2.x;
    if(hasSlope){
        m = static_cast<double>(p1.y - p2.y)/(p1.x - p2.x);
    }


    return hasSlope;
}


double Line::y_intercept() const{
    //y = mx + b
    //b = y - mx

    double m, b;

    if(slope(m)){
        b = p1.y - m * p1.x;
    }

    return b;
}

void Line::draw(SDL_Plotter& g){
    double m, b, y;
        if(slope(m)){
        b = y_intercept();
        for(int x = min(p1.x, p2.x); x <= max(p1.x, p2.x); x++){
            y = m * x + b;
            g.plotPixel(x,y, c.R, c.G, c.B);
       }
    }
}

