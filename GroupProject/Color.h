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
#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct Color{
    int R, G, B;

    Color(){
        R = G = B = 0;
    }
    Color(int r, int g, int b){
        R = r;
        G = g;
        B = b;
    }


    Color(const Color& c){
        R = c.R;
        G = c.G;
        B = c.B;
    }
};

const Color RED(220, 0, 0);
const Color BLACK(0,0,0);
const Color GREY(192,192,192);
const Color BROWN(139,69,19);
const Color LIGHTBROWN(210,180,140);
const Color BLUE(0,0,80);
const Color ORANGE(220,67,33);

#endif // COLOR_H_INCLUDED
