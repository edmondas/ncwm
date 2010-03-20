// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: label.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __LABEL_H
#define __LABEL_H

extern "C" {
#include <X11/Xlib.h>
}

#include <string>
#include "ncwm.h"

#include "rectangle.h"

class Monitor;
class WFont;

/**
 * Represents a low-level label widget implementation with alignment
 * handling.
 *
 * This widget is capable of using old style PCF fonts and new style
 * XFT fonts.
 */
class Label : public Rectangle
{

public:

    enum Alignment {LEFT, CENTER, RIGHT};

    Label(Monitor *monitor, Window window, Alignment align, GC gc);

    ~Label();

    void setText(string text);

    string text() const;

    /** 
     * Updates this label.
     * @param leftBorder if <code>true</code> a left border
     *        will be drawn.
     * @param rightBorder if <code>true</code> a right border
     *        will be drawn.
     */
    void update(unsigned long background, unsigned long text,
                unsigned long shine, unsigned long shadow,
                bool shineBorder = false, bool shadowBorder = false);

    void setAlignment(const Alignment align);

    /**
     * Adjusts label width with the currently set text. 
     * Returns the adjusted width.
     */
    unsigned int adjustWidth();

    /**
     * Helper method for adjustWidth, also useful for menu and bar stuff.
     */
    unsigned int textWidth();

private:

    Alignment align_;
    GC gc_;
    Monitor *monitor_;
    string text_;
    Window window_;
    WFont *font_;
};

#endif // __LABEL_H
