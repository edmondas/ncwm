// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: float.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __FLOAT_H
#define __FLOAT_H

#include "ncwm.h"

class Rectangle;

/**
 * Provides base algorithms for moving and resizing rectangles
 * in a floating manner.
 */
class Float {

public:

    /** Used for resizing. */
    static void resize(Rectangle *rect, Direction dir,
                       int stepW, int stepH);

    static void move(Rectangle *rect, int stepW, int stepH);

    static void center(Rectangle *rect, Rectangle *parentRect);

};
#endif // __FLOAT_H
