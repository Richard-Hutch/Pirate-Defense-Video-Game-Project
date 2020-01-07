/*
* Author: Jonathan Acosta
* Assignment Title:  Group Project
* Assignment Description: This file contains the implementations
*   of the functions created in Enemy.h
* Due Date: 12/9/2019
* Date Created: 11/20/2019
* Date Last Modified: 12/9/2019
 */
#include "Enemy.h"

Enemy::Enemy(){
    c = ORANGE;

    size = 10;
    p.x = 100;
    p.y = 100;
    bound.setUpperLeft(Point(p.x-size*2,p.y-size));
    bound.setLowerRight(Point(p.x+size*2,p.y+size));
    isAlive = true;
    canShoot = false;
}

Enemy::Enemy(Color col, Point pt){
    c = col;
    p = pt;

    size = 8;
    bound.setUpperLeft(Point(p.x-size*2,p.y-size));
    bound.setLowerRight(Point(p.x+size*2,p.y+size+1));
    bound.setColor(BLACK);
    isAlive = true;
    canShoot = false;
}
Enemy::Enemy(Color col, Point pt, int s){
    c = col;
    p = pt;
    size = s;
    bound.setUpperLeft(Point(p.x-size*2,p.y-size));
    bound.setLowerRight(Point(p.x+size*2,p.y+size+1));
    bound.setColor(BLUE);
    isAlive = true;
    canShoot = false;
}

void Enemy::setColor(const Color col){
    c = col;
}
void Enemy::setAlive(bool b){
    isAlive = b;
}
void Enemy::setPoint(const Point pt){
    p = pt;
    bound.setUpperLeft(Point(p.x-size*2,p.y-size));
    bound.setLowerRight(Point(p.x+size*2,p.y+size+1));
    bound.setColor(BLUE);
}
void Enemy::setSize(const int s){
    size = s;
}

Color Enemy::getColor() const{
    return c;
}
bool Enemy::getIsAlive() const{
    return isAlive;
}
Point Enemy::getCenter() const{
    return p;

}
int Enemy::getSize() const{
    return size;
}

void Enemy::setShoot(const bool b){
    canShoot = b;
}

bool Enemy::getCanShoot() const{
    return canShoot;
}
Rectangle_t Enemy::getBound() const{
    return bound;
}

void Enemy::draw(SDL_Plotter& g) const{
    int ship[20][40] ={

                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,1,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,1,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,1,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,1,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,1,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,1,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
                          {1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,2,2,2,2,2,1,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
                          {1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,2,2,2,2,2,1,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0},
                          {1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                          {1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                          {1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                          {1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                          {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                          {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                          {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
                          {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
                          {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0}
                        };
    for(int r = 0; r < 20; r++){
        for(int c = 0; c < 40; c++){
            if(ship[r][c]==0){
                g.plotPixel(bound.getUpperLeft().x+c,bound.getUpperLeft().y+r,BLUE.R,BLUE.G,BLUE.B);
            }
            else if(ship[r][c]==1){
                g.plotPixel(bound.getUpperLeft().x+c,bound.getUpperLeft().y+r,BROWN.R,BROWN.G,BROWN.B);
            }
            else if(ship[r][c]==2){
                g.plotPixel(bound.getUpperLeft().x+c,bound.getUpperLeft().y+r,RED.R,RED.G,RED.B);
            }
        }
    }
}
void Enemy::drawBound(SDL_Plotter& g) const{
    bound.draw(g);
}

int moveA(int col, int row, Enemy b[][7],int& dir){

    double maxY,maxX, minX;
    bool first =true, left = false, right = false, down = false;
    //Finds greatest y coordinate and max and min x coordinate
    for( int r = 0; r< row; r++){
        for(int c = 0; c < col; c++){
            if(b[r][c].getIsAlive() && first){
                maxX = minX = b[r][c].getCenter().x;
                maxY = b[r][c].getCenter().y;

                first = false;
            }
            else if(maxX < b[r][c].getCenter().x && b[r][c].getIsAlive()){
                maxX = b[r][c].getCenter().x;
                if(maxY < b[r][c].getCenter().y && b[r][c].getIsAlive()){
                    maxY = b[r][c].getCenter().y;
                }
            }
            else if(maxY < b[r][c].getCenter().y && b[r][c].getIsAlive()){
                    maxY = b[r][c].getCenter().y;
            }
            else if(minX>b[r][c].getCenter().x && b[r][c].getIsAlive()){
                minX = b[r][c].getCenter().x;
            }
        }
    }
    //Determines if the array should move to the left, right, or down.
    if(dir==1){
        if(maxX<440 && minX>30){
            right = true;
        }
        else{

            dir = 2;
        }
    }
    else if(dir==2){
        if(maxY<=490){

            down = true;
        }

        dir = 3;


    }
    else if(dir==3){
        if(minX>=50){
            left = true;
        }
        else{
            dir = 1;
        }
    }

    //Assigns a boolean shoot value to every enemy accordingly
    bool shoot = false;
    for(int r = 0; r < row; r++){
        for(int c = col + 6; c>=0; c--){

            if(b[r][c].getIsAlive()&&(!shoot)){
                shoot = true;
                b[r][c].setShoot(true);
             }



        }
        shoot = false;
    }




    //Moves the array of aliens according to dir or direction
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(b[r][c].getIsAlive()){
                b[r][c].setColor(Color(0,220,0));
            }
            if(down && b[r][c].getIsAlive()){
                b[r][c].setPoint(Point(b[r][c].getCenter().x,b[r][c].getCenter().y+10));
            }
            else if(right && b[r][c].getIsAlive()){
                b[r][c].setPoint(Point(b[r][c].getCenter().x+10,b[r][c].getCenter().y));
            }
            else if(left && b[r][c].getIsAlive()){
                b[r][c].setPoint(Point(b[r][c].getCenter().x-10,b[r][c].getCenter().y));

            }


        }
    }
    return dir;
}



void Enemy::eraseEnemy(SDL_Plotter& g) const{

    for(int r = 0; r < 20; r++){
        for(int c = 0; c < 40; c++){

            g.plotPixel(bound.getUpperLeft().x+c,bound.getUpperLeft().y+r,BLUE.R,BLUE.G,BLUE.B);
        }
    }



}
