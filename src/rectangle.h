// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: rectangle.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __RECTANGLE_H
#define __RECTANGLE_H

/**
 * Basic rectangle used by all viewable items of NCWM.
 */
class Rectangle
{

public:

    Rectangle();

    Rectangle(int x, int y, unsigned int w, unsigned int h);

    ~Rectangle();

    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);

    unsigned int width() const;
    void setWidth(unsigned int w);

    unsigned int height() const;
    void setHeight(unsigned int h);

    void copy(Rectangle *source);

    bool fitsInto(Rectangle *rect);

private:

    int x_, y_;
    unsigned int w_, h_;
};

#endif // __RECTANGLE_H
