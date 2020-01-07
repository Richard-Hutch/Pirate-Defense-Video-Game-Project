/*
 * Author: Brandon Valiente
 * Assignment Title: Group Project
 * Assignment Description: This program creates a bullet class
 * Due Date: 12/9/2019
 * Date Created: 12/9/19
 * Date Last Modified: 12/9/19
 */

#include "Bullet.h"


Bullet::Bullet(){
    enemyX = 250;
    enemyY = 100;
    currentX = 250;
    currentY = 750;
    active = false;
    activeEnemy = false;

}

bool Bullet::getActive(){

    return active;

}

bool Bullet::getEBulletActive(){

    return activeEnemy;
}

void Bullet::setActive(bool a){

    active = a;
}

void Bullet::setEBulletActive(bool a){

    activeEnemy = a;

}

//shoot bullet at input coordinate up
void Bullet::friendlyShoot(int x, int y, SDL_Plotter& g){
    if(!active){
        g.playSound("cannon.wav");
        x += 14;
        y -= 25;
        currentX = x;
        currentY = y;
        Color c = GREY;
        p.x = x;
        p.y = y;
        bound.setColor(c);
        bound.setUpperLeft(Point(p.x,p.y));
        bound.setLowerRight(Point(p.x + 8,p.y + 9));
        bound.draw(g);
        //erase bullet
        for(int r = 0; r < 10; r++){
            for(int c = 0; c < 9; c++){
                g.plotPixel(x + c ,y + r,0,0,80);
            }
        }
        active = true;
    }
}

//shoot bullet at input coordinate down
void Bullet::enemyShoot(int x, int y, SDL_Plotter& g){
    if(!activeEnemy){
        //g.playSound("cannon.wav");
        //adjust bullet position below alien
        x += 16;
        y += 25;
        enemyX = x;
        enemyY = y;

        //Rectangle around bullet
        Color c = RED;
        p.x = x;
        p.y = y;
        bound.setColor(c);
        bound.setUpperLeft(Point(p.x,p.y));
        bound.setLowerRight(Point(p.x + 8,p.y + 9));
        bound.draw(g);

        //erase bullet
        for(int r = 0; r < 10; r++){
            for(int c = 0; c < 9; c++){
                g.plotPixel(x + c ,y + r,0,0,80);
            }
        }
        activeEnemy = true;
    }
}


void Bullet::drawBullet(SDL_Plotter& g){
    if(currentY > 60){
        //bullet speed
        currentY -= 2;
        //draw bullet
        Color c = GREY;
        p.x = currentX;
        p.y = currentY;
        bound.setColor(c);
        bound.setUpperLeft(Point(p.x,p.y));
        bound.setLowerRight(Point(p.x + 8,p.y + 23));
        bound.draw(g);
    }
}

void Bullet::drawEnemyBullet(SDL_Plotter& g){

    if(enemyY  < 770){
        //bullet speed
        enemyY += 2;
        //draw bullet
        Color c = RED;
        p.x = enemyX;
        p.y = enemyY;
        bound.setColor(c);
        bound.setUpperLeft(Point(p.x, p.y));
        bound.setLowerRight(Point(p.x + 8, p.y + 23));
        bound.draw(g);
    }


}

void Bullet::eraseBullet(SDL_Plotter& g){


    //erase bullet

    Color c = BLUE;
    p.x = currentX;
    p.y =  currentY;
    bound.setColor(c);
    bound.setUpperLeft(Point(p.x + 8, p.y));
    bound.setLowerRight(Point(p.x, p.y + 23));
    bound.draw(g);

    if (currentY < 61) {
        active = false;
    }



}


void Bullet::enemyEraseBullet(SDL_Plotter& g){

    //erase bullet
    Color c = BLUE;
    p.x = enemyX;
    p.y = enemyY;
    bound.setColor(c);
    bound.setUpperLeft(Point(p.x + 8, p.y));
    bound.setLowerRight(Point(p.x, p.y + 23));
    bound.draw(g);
    //turn off active enemy bullet if it goes too near off screen
    if (enemyY > 769){
        activeEnemy = false;
    }

}

Rectangle_t Bullet::getRect(){
    return bound;
}

