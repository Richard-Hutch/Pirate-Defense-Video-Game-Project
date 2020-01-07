#include "Circle.h"


Circle_t::Circle_t(){
    radius = 1;
    c = RED;
}
Circle_t::Circle_t(double r, Point cent, Color col){
    radius = r;
    center = cent;
    c = col;
}
Circle_t::Circle_t(const Circle_t& other){
    radius = other.radius;
    center = other.center;
    c = other.c;
}

void Circle_t::setRadius(double r){
    radius = r;
}
void Circle_t::setCenter(Point cent){
    center = cent;
}
void Circle_t::setColor(Color col){
    c = col;
}

double Circle_t::getRadius() const{
    return radius;
}
Point Circle_t::getCenter() const{
    return center;
}
Color Circle_t::getColor() const{
    return c;
}

void Circle_t::draw(SDL_Plotter& g){
    for(int y = center.y - radius; y <= center.y + radius; y++){
        for(int x = center.x - radius; x <= center.x + radius; x++){
            if(sqrt(pow(center.x - x,2) + pow(center.y - y, 2)) <= radius){
                if(x >= 0 && y >= 0 && x < g.getCol() && y < g.getRow()){
                    g.plotPixel(x, y, c.R, c.G, c.B);
                }
            }
        }
    }
}
