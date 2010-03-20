// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: atoms.cpp 13 2008-04-18 08:02:14Z eg1981 $

extern "C" {
#include "X11/Xatom.h"
}
#include <sstream>

#include "atoms.h"

#include "logger.h"
#include "kernel.h"
#include "ncwm.h"
#include "xcore.h"

Atom Atoms::WM_STATE = 0;
Atom Atoms::WM_CHANGE_STATE = 0;
Atom Atoms::WM_PROTOCOLS = 0;
Atom Atoms::WM_DELETE = 0;
Atom Atoms::WM_TAKE_FOCUS = 0;
Atom Atoms::WM_COLORMAPS = 0;

Atom Atoms::MWM_HINTS = 0;

Atom Atoms::NET_WM_DESKTOP = 0;

Atom Atoms::NCWM_ACTIONCMD = 0;
Atom Atoms::NCWM_STATUSTEXT = 0;
Atom Atoms::NCWM_METERTEXT = 0;
Atom Atoms::NCWM_PRETTYPRINT_REQUEST = 0;
Atom Atoms::NCWM_PRETTYPRINT_RESPONSE = 0;

bool Atoms::initialized_ = false;

void Atoms::initAtoms()
{
    if (initialized_) {
        return;
    }

    ostringstream oss;

    // ICCCM
    WM_STATE = XCORE->internAtom("WM_STATE");
    oss << "WM_STATE: " << WM_STATE << endl;
    WM_CHANGE_STATE = XCORE->internAtom("WM_CHANGE_STATE");
    oss << "WM_CHANGE_STATE: " << WM_CHANGE_STATE << endl;
    WM_PROTOCOLS = XCORE->internAtom("WM_PROTOCOLS");
    oss << "WM_PROTOCOLS: " << WM_PROTOCOLS << endl;
    WM_DELETE = XCORE->internAtom("WM_DELETE_WINDOW");
    oss << "WM_DELETE_WINDOW: " << WM_DELETE << endl;
    WM_TAKE_FOCUS = XCORE->internAtom("WM_TAKE_FOCUS");
    oss << "WM_TAKE_FOCUS: " << WM_TAKE_FOCUS << endl;
    WM_COLORMAPS = XCORE->internAtom("WM_COLORMAP_WINDOWS");
    oss << "WM_COLORMAP_WINDOWS: " << WM_COLORMAPS << endl;
    oss << "XA_WM_ICON_NAME: " << XA_WM_ICON_NAME << endl;
    oss << "XA_WM_NAME: " << XA_WM_NAME << endl;
    oss << "XA_WM_TRANSIENT_FOR: " << XA_WM_TRANSIENT_FOR;

    LOGDEBUG(oss.str());

    // MOTIF
    MWM_HINTS = XCORE->internAtom("_MOTIF_WM_HINTS");

    // NETWM
    NET_WM_DESKTOP = XCORE->internAtom("_NET_WM_DESKTOP");

    // NCWM
    NCWM_ACTIONCMD = XCORE->internAtom("_NCWM_ACTIONCMD");
    NCWM_STATUSTEXT = XCORE->internAtom("_NCWM_STATUSTEXT");
    NCWM_METERTEXT = XCORE->internAtom("_NCWM_METERTEXT");
    NCWM_PRETTYPRINT_REQUEST =
        XCORE->internAtom("_NCWM_PRETTYPRINT_REQUEST");
    NCWM_PRETTYPRINT_RESPONSE =
        XCORE->internAtom("_NCWM_PRETTYPRINT_RESPONSE");

    initialized_ = true;
}
