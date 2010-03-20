// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: box.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __BOX_H
#define __BOX_H

extern "C" {
#include <X11/Xlib.h>
}

#include <string>

#include "widget.h"
#include "ncwm.h"

class Label;
class Monitor;
class Theme;

/** Basic info box. */
class Box : public Widget {

public:

    Box(Monitor *monitor, Rectangle *rect, string text);
    ~Box();

    void setText(string text);
    void illuminate();

private:

    Label *label_;
    Theme *theme_;
};

#endif // __BOX_H
