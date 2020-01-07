#include "Point.h"

Point::Point(){
    x = 0;
    y = 0;
}
Point::Point(int a, int b){
    x = a;
    y = b;
}
Point::Point(const Point& other){
    x = other.x;
    y = other.y;
}

void Point::draw(SDL_Plotter& g){
    if(x >= 0 && x < g.getCol() && y >= 0 && y < g.getRow()){
        //object scoped x and y:
        g.plotPixel(x, y, 0, 0, 0);
    }

}

double Point::distance(Point p){
    return (sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)));

}
