// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt> 
// See ../LICENSE.txt for license details.
//
// $Id: xfont.cpp 13 2008-04-18 08:02:14Z eg1981 $

#include "xfont.h"

#include "monitor.h"
#include "xcore.h"

XFont::XFont(Monitor *monitor, XFontStruct *font) :
    WFont(monitor)
{
    font_ = font;
    type_ = WFont::NORMAL;
}

XFont *XFont::load(Monitor *monitor, string name) {

    XFontStruct *font = XCORE->loadQueryFont(name);
    XFont *xfont = 0;
    if (font) {
        xfont = new XFont(monitor, font);
        xfont->setHeight(font->ascent + font->descent);
    }
    else {
        delete font;
    }
    return xfont;
}

XFont::~XFont() {
}

int XFont::textWidth(string text) {
    return XCORE->textWidth(font_, text);
}

unsigned int XFont::height() {
    return height_;
}

void XFont::setHeight(unsigned int height) {
    height_ = height;
}

void XFont::drawText(Window window, GC gc, int x, int y, string text) {
    XCORE->drawText(window, gc, x, y, text);
}

int XFont::ascent() {
    return font_->ascent;
}

int XFont::descent() {
    return font_->descent;
}


XFontStruct *XFont::font() const {
    return font_;
}
