// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: atoms.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __ATOMS_H
#define __ATOMS_H

extern "C" {
#include "X11/Xlib.h"
}

/**
 * Container of all necessary X atoms used by NCWM.
 */
class Atoms
{

public:

    /** Inits all atoms. */
    static void initAtoms();

    /** ICCCM atoms */
    static Atom WM_STATE;
    static Atom WM_CHANGE_STATE;
    static Atom WM_PROTOCOLS;
    static Atom WM_DELETE;
    static Atom WM_TAKE_FOCUS;
    static Atom WM_COLORMAPS;

    /** MOTIF atoms */
    static Atom MWM_HINTS;

    /** NETWM atoms */
    static Atom NET_WM_DESKTOP;

    /** ncwm atoms */
    static Atom NCWM_ACTIONCMD;
    static Atom NCWM_METERTEXT;
    static Atom NCWM_STATUSTEXT;
    static Atom NCWM_PRETTYPRINT_REQUEST;
    static Atom NCWM_PRETTYPRINT_RESPONSE;

private:

    static bool initialized_;
};

#endif // __ATOMS_H
