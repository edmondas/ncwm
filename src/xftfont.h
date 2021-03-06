// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt> 
// See ../LICENSE.txt for license details.
//
// $Id: xftfont.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __XFTFONT_H
#define __XFTFONT_H

#include "ncwm.h"

#ifdef XFT_SUPPORT

extern "C" {
#include <X11/Xft/Xft.h>
}

#include <string>

#include "font.h"

class Monitor;

/** Base class for XftFonts. */
class WXftFont : public WFont {

public:

    WXftFont(Monitor *monitor, XftFont *font);
    virtual ~WXftFont();

    virtual void drawText(Window window, GC gc, int x, int y, string text);

    virtual int textWidth(string text);

    virtual unsigned int height();

    virtual void setHeight(unsigned int height);

    virtual int ascent();

    virtual int descent();

    static WXftFont *load(Monitor *monitor, string name);

private:

    XftFont *font_;
    unsigned int height_;

};

#endif // XFT_SUPPORT

#endif // __XFTFONT_H
