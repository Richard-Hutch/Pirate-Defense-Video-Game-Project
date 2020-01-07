#include "Rectangle_t.h"

Rectangle_t::Rectangle_t(){
    upperLeft.x = 0;
    upperLeft.y = 0;
    lowerRight.x = 1;
    lowerRight.y = 1;
    c = RED;
    isAlive = true;
}
Rectangle_t::Rectangle_t(Point ul, Point lr, Color col){
    upperLeft = ul;
    lowerRight = lr;
    c = col;
}
Rectangle_t::Rectangle_t(const Rectangle_t& other){
    upperLeft = other.upperLeft;
    lowerRight = other.lowerRight;
    c = other.c;
}

void Rectangle_t::setUpperLeft(const Point p){
    upperLeft = p;
}
void Rectangle_t::setLowerRight(const Point p){
    lowerRight = p;
}
void Rectangle_t::setColor(const Color a){
    c = a;
}
void Rectangle_t::setIsAlive(bool a){

    isAlive = a;

}
bool Rectangle_t::getIsAlive(){
    return isAlive;
}


Point Rectangle_t::getUpperLeft() const{
    return upperLeft;
}
Point Rectangle_t::getLowerRight() const{
    return lowerRight;
}
Color Rectangle_t::getColor() const{
    return c;
}

void Rectangle_t::draw(SDL_Plotter& g) const{
    for(int y = min(upperLeft.y, lowerRight.y); y <= max(upperLeft.y, lowerRight.y); y++){
        for(int x = min(upperLeft.x, lowerRight.x); x <= max(upperLeft.x, lowerRight.x); x++){
            g.plotPixel(x, y, c.R, c.G, c.B);
        }
    }
}

void Rectangle_t::eraseChest(SDL_Plotter& g) const{
    for(int y = min(upperLeft.y, lowerRight.y); y <= max(upperLeft.y, lowerRight.y); y++){
        for(int x = min(upperLeft.x, lowerRight.x); x <= max(upperLeft.x, lowerRight.x); x++){
            g.plotPixel(x, y, 0, 0, 80);
        }
    }
}

