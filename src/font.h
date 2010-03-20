// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: font.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __FONT_H
#define __FONT_H

extern "C" {
#include <X11/Xlib.h>
}

#include <string>

#include "ncwm.h"

class Monitor;

/** Base class for fonts (currently default XFonts and XftFonts). */
class WFont {

public:

    enum Type {NORMAL, XFT};

    WFont(Monitor *monitor);
    virtual ~WFont();

    Type type() const;

    static WFont *load(Monitor *monitor, string name);

    virtual void drawText(Window window, GC gc, int x, int y, string text) = 0;

    virtual int textWidth(string text) = 0;

    virtual unsigned int height() = 0;

    virtual void setHeight(unsigned int height) = 0;

    virtual int ascent() = 0;

    virtual int descent() = 0;

protected:

    Monitor *monitor_;
    Type type_;

};

#endif // __FONT_H
