// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: font.cpp 13 2008-04-18 08:02:14Z eg1981 $

#include "font.h"

#include "xcore.h"
#include "xfont.h"
#include "xftfont.h"

WFont::WFont(Monitor *monitor) {
    monitor_ = monitor;
}

WFont::~WFont() {
}

WFont *WFont::load(Monitor *monitor, string name) {

    WFont *font = XFont::load(monitor, name);
#ifdef XFT_SUPPORT
    if (!font) {
        // fallback if XFT_SUPPORT enabled
        font = WXftFont::load(monitor, name);
    }
#endif
    return font;
}


WFont::Type WFont::type() const{
    return type_;
}
