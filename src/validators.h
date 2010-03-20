// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt> 
// See ../LICENSE.txt for license details.
//
// $Id: validators.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __VALIDATORS_H
#define __VALIDATORS_H

#include "ncwm.h"

#include "singleton.h"

class Kernel;
class Monitor;

class Validators;

/** Note: existance checks are qualified only on focused stuff. */
class Validators : public Singleton<Validators>
{

public:

    Validators();
    ~Validators();

    // validation methods
    bool isAlwaysPossible();

    /**
     * Return <code>true</code> if a client can be unhooked.
     */
    bool validateUnhookClient();

    /**
     * Return <code>true</code> if a client can be unhooked.
     */
    bool validateHookClient();

    /**
     * Returns <code>true</code> if a frame is focussed and there're
     * more frames.
     */
    bool validateCycleFrame();

    /** Returns <code>true</code> if the ncwm kernel has recorded actions. */
    bool validateEndRecord();

    /** Returns <code>true</code> if the ncwm is recording actions. */
    bool validateCancelRecord();

    /** Returns <code>true</code> if the ncwm kernel is not recording actions. */
    bool validateBeginRecord();

    /** Returns <code>true</code> if a workspace exists. */
    bool isWorkspaceFocused();

    /** Returns <code>true</code> if at least two workspaces exist. */
    bool existMonitors();

    /** Returns <code>true</code> if at least two workspaces exist. */
    bool existWorkspaces();

    bool isEmptyWorkspaceFocused();
    bool validateDestroyWorkspace();
    bool validateDestroyFrame();

    bool validateDestroyAction();

    /** Validates directional grow/shrink actions. */
    bool validateResizeLeft();
    bool validateResizeRight();
    bool validateResizeUp();
    bool validateResizeDown();

    /** Returns <code>true</code> if a frame into direction exist. */
    bool existsFrameLeft();
    bool existsFrameRight();
    bool existsFrameUp();
    bool existsFrameDown();

    /** Returns <code>true</code> if a frame is focused. */
    bool isFrameFocused();

    /** Returns <code>true</code> if a frame or client exist. */
    bool isFrameOrClientFrameFocused();

    /** Returns <code>true</code> if at least two frames exist. */
    bool existFrames();

    /** Returns <code>true</code> if toggleMode is valid. */
    bool validateToggleMode();

    /** Returns <code>true</code> if a client frame exists. */
    bool isClientFrameFocused();

    /** Returns <code>true</code> if a client exists. */
    bool isClientFocused();

    /** Returns <code>true</code> if a floating client exists. */
    bool isFloatingClientFocused();

    /** Returns <code>true</code> if at least two clients exists. */
    bool existClients();

    /** Returns <code>true</code> if at least two clients exists. */
    bool existClientsWithinFrame();

    bool existsDetachedClient();
    bool existDetachedClients();

    /** Returns <code>true</code> if input mode is not active. */
    bool validateInputMode();

    /**
     * Returns <code>true</code> if any client exists on the
     * focused monitor.
     */ 
    bool validateSelectClient();
#ifdef SLOT_SUPPORT
    bool existsSlotClient();
    bool existSlotTabs();
#endif // SLOT_SUPPORT

};

#endif // __VALIDATORS_H
