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


#include "EndingScreen.h"
EndingScreen::EndingScreen(){
    endingX = 0;
    endingY = 0;
}


EndingScreen::EndingScreen(int x,int y){
    endingX = x;
    endingY = y;
}
void EndingScreen::draw(SDL_Plotter& g){
    //THIS WILL DRAW THE GAME OVER SCREEN
    int scale = 10;
    int lose[endingROW][endingCOL] = {
        {0,1,1,1,0,0,0,1,1,0,0,0,1,1,0,1,1,0,0,1,1,1,1},
        {1,0,0,0,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0},
        {1,0,1,1,0,0,1,1,1,1,0,0,1,0,1,0,1,0,0,1,1,1,1},
        {1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0},
        {0,1,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,0,1,1,1,0,0},
        {1,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0},
        {1,0,0,1,0,0,0,1,0,1,0,0,1,1,1,1,0,0,1,1,1,0,0},
        {1,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0},
        {0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,1,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    int a = 0, b = 0;
    
    for(int r = 0; r < endingROW; r++){
        for(int c = 0; c < endingCOL; c++){
            for(int i = 0; i<=scale; i++){
                for(int j = 0; j<=scale;j++){
                    
                    if(lose[r][c]) {
                        //g.plotPixel(endingX + c+a, endingY + r+a, 0, 0, 0);
                        g.plotPixel(endingX + c+(a*scale-1)+i, endingY + r+j+(b*scale-1),220,20,60);
                    }
                    else{
                        //g.plotPixel(endingX + c+a, endingY + r+a, 0, 220, 0);
                        g.plotPixel(endingX + c+(a*scale-1)+i, endingY + r+j+(b*scale-1), 0, 0, 0);
                    }
                }
            }
            a++;
        }
        a=0;
        b++;
        
    }
    
}

void EndingScreen::setX(int x){
    endingX = x;
}

void EndingScreen::setY(int y){
    endingY = y;
}
