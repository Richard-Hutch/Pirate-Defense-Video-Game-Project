#include "DoCollide.h"

bool doCollide(Rectangle_t a, Rectangle_t b){
    /*ONLY WORKS IF COORDINATES ARE IN CORRECT ORDER
        EX: top left x is < bottom right x.
        An example of what will not work is:
        top left x > bottom right x
    */

    bool collision = false;
    Point upLeft1, lowRight1, upLeft2, lowRight2;
    upLeft1.x = a.getUpperLeft().x;
    upLeft1.y = a.getUpperLeft().y;
    lowRight1.x = a.getLowerRight().x;
    lowRight1.y = a.getLowerRight().y;

    upLeft2.x = b.getUpperLeft().x;
    upLeft2.y = b.getUpperLeft().y;
    lowRight2.x = b.getLowerRight().x;
    lowRight2.y = b.getLowerRight().y;

    if (upLeft1.x < lowRight2.x && lowRight1.x > upLeft2.x
        && upLeft1.y < lowRight2.y && lowRight1.y > upLeft2.y){
        collision = true;
    }


    return collision;
    /*
    if (upLeft1.x < lowRight2.x){
        cout << "upLeft1.x < lowRight2.x = true" << endl;
    }else {
        cout << "upLeft1.x < lowRight2.x = false" << endl;
    }

    if (lowRight1.x > upLeft2.x){
        cout << "lowRight1.x > upLeft2.x = true" << endl;
    }else {
        cout << "lowRight1.x > upLeft2.x = false" << endl;
    }


    if (upLeft1.y < lowRight2.y){
        cout << "upLeft1.y < lowRight2.y = true" << endl;
    }else {
        cout << "upLeft1.y < lowRight2.y = false" << endl;
    }


    if(lowRight1.y > upLeft2.y){
        cout << "lowRight1.y > upLeft2.y = true" << endl;


    }else {
        cout << "lowRight1.y > upLeft2.y = false" << endl;
    }*/
}
