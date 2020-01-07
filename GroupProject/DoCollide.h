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
#ifndef DOCOLLIDE_H_INCLUDED
#define DOCOLLIDE_H_INCLUDED

#include "Rectangle_t.h"


/*
 description: return boolean after finding out if two rectangles intersect
 return: bool
 precondition: two rectangle_t objects exist
 postcondition: two objects unchanged, bool returned
*/

bool doCollide(Rectangle_t, Rectangle_t);


#endif // DOCOLLIDE_H_INCLUDED
