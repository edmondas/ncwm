// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: ncwm.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __NCWM_H
#define __NCWM_H

#include "../config.h"

#define LOGERROR(X, Y) Logger::instance()->error(X, Y)
#define LOGWARN(X) Logger::instance()->warning(X)
#define CONFPATH "/etc/ncwm"
#define KERNEL Kernel::instance()
#define XCORE XCore::instance()

#ifdef DEBUG
#define LOGDEBUG(X) Logger::instance()->debug(X)
#else
#define LOGDEBUG(X)
#endif

enum Direction {LEFT, RIGHT, UP, DOWN, NORTH_WEST,
                NORTH_EAST, SOUTH_WEST, SOUTH_EAST};

// we use only std namespace
using namespace std;

// Motif bits - see Motif reference manual for further information.
#define MWM_HINTS_FUNCTIONS     (1L << 0)
#define MWM_HINTS_DECORATIONS   (1L << 1)
#define MWM_HINTS_INPUT_MODE    (1L << 2)
#define MWM_HINTS_STATUS        (1L << 3)

#define MWM_DECOR_ALL           (1L << 0)
#define MWM_DECOR_BORDER        (1L << 1)
#define MWM_DECOR_RESIZEH       (1L << 2)
#define MWM_DECOR_TITLE         (1L << 3)
#define MWM_DECOR_MENU          (1L << 4)
#define MWM_DECOR_MINIMIZE      (1L << 5)
#define MWM_DECOR_MAXIMIZE      (1L << 6)

#define MINIMAL_BARHEIGHT       13
#endif // __NCWM_H
