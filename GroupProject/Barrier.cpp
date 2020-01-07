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


#include "Barrier.h"

Barriers::Barriers(){

    y1 = 550;
    y2 = 520;
    x1 = 50;
    x2 = 100;
    //int theColor = 50;
    currentCOL = 0;


    //ALL OF FIRST BARRIER COLORS:
    partONE[0][0].setColor(Color(128,128,128));
    partONE[1][0].setColor(Color(128,128,128));
    partONE[2][0].setColor(Color(105,105,105));
    partONE[0][1].setColor(Color(169,169,169));
    partONE[1][1].setColor(Color(128,128,128));
    partONE[2][1].setColor(Color(128,128,128));
    partONE[0][2].setColor(Color(169,169,169));
    partONE[1][2].setColor(Color(169,169,169));
    partONE[2][2].setColor(Color(128,128,128));
    partONE[0][3].setColor(Color(211,211,211));
    partONE[1][3].setColor(Color(169,169,169));
    partONE[2][3].setColor(Color(169,169,169));



    //ALL OF SECOND BARRIER COLORS:
    partTWO[0][0].setColor(Color(128,128,128));
    partTWO[1][0].setColor(Color(128,128,128));
    partTWO[2][0].setColor(Color(105,105,105));
    partTWO[0][1].setColor(Color(169,169,169));
    partTWO[1][1].setColor(Color(128,128,128));
    partTWO[2][1].setColor(Color(128,128,128));
    partTWO[0][2].setColor(Color(169,169,169));
    partTWO[1][2].setColor(Color(169,169,169));
    partTWO[2][2].setColor(Color(128,128,128));
    partTWO[0][3].setColor(Color(211,211,211));
    partTWO[1][3].setColor(Color(169,169,169));
    partTWO[2][3].setColor(Color(169,169,169));
    int x2Old;

    for(int r = 0; r < barrierRow; r++){

        x1 = 50;
        y1 = 550;

        x2 = 80;
        y2 = 520;


        for(int c = 0; c < barrierCol; c++){
                if (c > 0){
                    x1 = x2Old + 1;
                }
                partONE[r][c].setUpperLeft(Point(x1, y2 + currentCOL));
                partONE[r][c].setLowerRight(Point(x2, y1 + currentCOL));
                partTWO[r][c].setUpperLeft(Point(x1 + 290, y2 + currentCOL));
                partTWO[r][c].setLowerRight(Point(x2 + 290, y1 + currentCOL));

                x2Old = x2;
                x2 += 15;

        }
        //set to 30 for them to be next to each other
        currentCOL+=30;
    }
}
void Barriers::start(SDL_Plotter& g){

    for(int r = 0; r < barrierRow; r++){
        for(int c = 0; c < barrierCol; c++){
            if(partONE[r][c].getIsAlive()){
                partONE[r][c].draw(g);
            }
            if (partTWO[r][c].getIsAlive()){
                partTWO[r][c].draw(g);

            }
            //MOVE TO GRAVEVYARD
            if (!partTWO[r][c].getIsAlive()){
                partTWO[r][c].setUpperLeft(Point(0, 1));
                partTWO[r][c].setLowerRight(Point(1, 2));
            }
            if (!partONE[r][c].getIsAlive()){
                partONE[r][c].setUpperLeft(Point(0, 1));
                partONE[r][c].setLowerRight(Point(1, 2));
            }


        }
    }
}

int Barriers::getBarRow(){
    return barrierRow;
}
int Barriers::getBarCol(){
    return barrierCol;
}
