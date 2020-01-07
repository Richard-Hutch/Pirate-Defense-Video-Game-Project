/*
* Author: Jonathan Acosta
* Assignment Title:  Group Project
* Assignment Description: This file contains the prototype
*   functions of class Enemy and a prototype function
*   that utilizes and array of Enemies.
* Due Date: 12/9/2019
* Date Created: 11/20/2019
* Date Last Modified: 12/9/2019
 */
#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "TheVault.h"

class Enemy{


    private:
        Color c;
        Point p;
        int size;

        Rectangle_t bound;
        bool isAlive;
        bool canShoot;

    public:
        Enemy();
        Enemy(Color, Point);
        Enemy(Color, Point, int);

        /*
         * description: Changes the color of an enemy
         * return: none
         * precondition: parameter is a Color
         * postcondition: c is changed.
         *
         */
        void setColor(const Color);
        /*
         * description: Changes the isAlive of enemy
         * return: none
         * precondition: Parameter is a boolean
         * postcondition: isAlive is changed
         *
         */
        void setAlive(bool);
        /*
         * description: Changes the point of an enemy
         * return: none
         * precondition: Parameter is a point
         * postcondition: center of enemy is changed
         *
         */
        void setPoint(const Point);
        /*
         * description: Changes the size of enemy
         * return: none
         * precondition: Parameter is an int
         * postcondition: size is changed
         *
         */
        void setSize(const int);
        /*
         * description: Changes the canShoot attribute
         * return: none
         * precondition: Parameter is a boolean
         * postcondition: canShoot is changed
         *
         */
        void setShoot(const bool);

        /*
         * description: Returns the color of an enemy
         * return: color
         * precondition: enemy exists
         * postcondition: color remains unchanged
         *
         */
        Color getColor() const;
        /*
         * description: Returns the isAlive private member of an enemy
         * return: boolean
         * precondition: Enemy exists
         * postcondition: isAlive remains unchanged
         *
         */
        bool getIsAlive() const;
        /*
         * description: Returns the point that is in the center of an Enemy
         * return: point
         * precondition: Enemy exists
         * postcondition: center of the enemy remains unchanged
         *
         */
        Point getCenter() const;
        /*
         * description: Returns the value of size for an enemy
         * return: int
         * precondition: Enemy exists
         * postcondition: size remains unchanged
         *
         */
        int getSize() const;
        /*
         * description: Returns the bounded rectangle of an Enemy
         * return: Rectangle_t
         * precondition: Enemy exists
         * postcondition: Rectangle object remains unchanged
         *
         */
        Rectangle_t getBound() const;
        /*
         * description: Returns the value of canShoot
         * return: boolean
         * precondition: Enemy exists
         * postcondition: canShoot remains unchanged
         *
         */
        bool getCanShoot() const;
        /*
         * description: Draws the enemy
         * return: none
         * precondition: Enemy exists
         * postcondition: Enemy is drawn on SDL Plotter
         *
         */
        void draw(SDL_Plotter& g) const;
        /*
         * description: Draws the bound rectangle over the enemy
         * return: none
         * precondition: Enemy exists
         * postcondition: Bound is drawn over the enemy
         *
         */
        void drawBound(SDL_Plotter& g) const;
        /*
         * description: Redraws the enemy to the color of the background
         * return: none
         * precondition: Enemy exists
         * postcondition: Enemy's color is the color of background
         *
         */
        void eraseEnemy(SDL_Plotter& g) const;


};

/*
 * description: A functions that moves the position
 *   of an array of enemies based on its past position.
 *   Assigns the attributes of canShoot to each enemy
 *   accordingly.
 * return: int
 * precondition: The parameters of row and col
 *  match the row and col of the enemy integers.
 * postcondition: The array of enemies are changed in
 *  position and in their canShoot attributes.
 *
 */
int moveA(int row, int col, Enemy b[][7],int& dir);

#endif // ENEMY_H_INCLUDED

