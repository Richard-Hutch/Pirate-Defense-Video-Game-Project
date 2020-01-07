/*
* Author: Noah Lambaria
* Assignment Title: Group Project
* Assignment Description: This project creates space-invaders game,
*       with a Pirate theme. I wrote the Special Treasure chest,
*       Ending screen, and Barrier to protect the player.
* Due Date: 12/9/19
* Date Created: 11/20/19
* Date Last Modified: 12/9/19
*/

#include "Special.h"

Special::Special(){
    r = Rectangle_t(Point(0,0),Point(1,1), BROWN);

}

Special::Special(Rectangle_t rectangle){
    r = rectangle;

}

Special::Special(const Special& other){
    r = other.r;
}

void Special::setX(int n){

    x = n;

}

void Special::moveChest(SDL_Plotter& g){


    r.setColor(Color(BROWN));
    latch.setColor(Color(218,165,32));
    line.setColor(Color(BLACK));

    if(right){


        eraseChest(g);

        r.setUpperLeft(Point(x, y1));
        r.setLowerRight(Point(x + 50, y2));
        r.draw(g);

        line.setUpperLeft(Point(x, lineY1));
        line.setLowerRight(Point(x + 50, lineY2));
        line.draw(g);



        latch.setUpperLeft(Point(x + 17, latchY1));
        latch.setLowerRight(Point(x + 32, latchY2));
        latch.draw(g);


        x+=speed;

        if(x >= 450){
            right = false;
        }
    }
    else if(!right){

        eraseChest(g);

        r.setUpperLeft(Point(x - 50, y1));
        r.setLowerRight(Point(x, y2));
        r.draw(g);
        //x-=speed;


        line.setUpperLeft(Point(x - 50, lineY1));
        line.setLowerRight(Point(x, lineY2));
        line.draw(g);



        latch.setUpperLeft(Point(x - 32, latchY1));
        latch.setLowerRight(Point(x - 17, latchY2));
        latch.draw(g);


        x -= speed;

        if(x <= 50){
            right = true;
        }
    }
}

Rectangle_t Special::getRect(){

    return r;

}

bool Special::getAlive(){
    return alive;
}

void Special::setAlive(bool a){
    alive = a;
}

void Special::eraseChest(SDL_Plotter& g){
    r.eraseChest(g);
    line.eraseChest(g);
    latch.eraseChest(g);

    if (!alive){
        //TREASURE CHEST IS DEAD AND ITS MOVED TO THE GRAVE YARD

        r.setColor(Color(0, 0, 80));
        line.setColor(Color(0, 0, 80));
        latch.setColor(Color(0, 0, 80));

        r.setUpperLeft(Point(0, y1));
        r.setLowerRight(Point(1, y2));
        r.draw(g);
        //x-=speed;


        line.setUpperLeft(Point(0, lineY1));
        line.setLowerRight(Point(1, lineY2));
        line.draw(g);

        latch.setUpperLeft(Point(0, latchY1));
        latch.setLowerRight(Point(1, latchY2));

    }
}



