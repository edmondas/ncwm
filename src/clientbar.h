// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: clientbar.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __CLIENTBAR_H
#define __CLIENTBAR_H

#include "bar.h"

class Menu;
class Monitor;

/**
 * Represents the floating app bar of NCWM.
 */
class ClientBar : public Bar {

public:

    enum Mode {PAGER, CLIENTINFO};

    ClientBar(Monitor *monitor, Rectangle *rect);

    ~ClientBar();

    virtual void illuminate();

    virtual void handleMotionNotify(XMotionEvent *event);
    virtual void handleButtonPress(XButtonEvent *event);
    virtual void handleButtonRelease(XButtonEvent *event);

    void toggleMenuMode();
    void setMode(Mode mode);
    Mode mode() const;

    Menu *menu() const;

private:

    void updateClientInfo();
    void updateClientPager();
    void updateModeButton();
    void updateMenuButton();

    void invokeClickedThing(int xPosition);
    bool isModeButtonPressed_;
    bool isMenuButtonPressed_;
    Mode mode_;
    Menu *menu_;
};

#endif // __CLIENTBAR_H
