// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt> 
// See ../LICENSE.txt for license details.
//
// $Id: statusbar.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __STATUSBAR_H
#define __STATUSBAR_H

#include "bar.h"

#include <set>
#include <string>
#include "ncwm.h"

class Kernel;
class Monitor;

/**
 * Represents the statusbar of NCWM.
 */
class StatusBar : public Bar  {

public:

    StatusBar(Monitor *monitor, Rectangle *rect);

    ~StatusBar();

    virtual void illuminate();

    virtual void handleMotionNotify(XMotionEvent *event);
    virtual void handleButtonPress(XButtonEvent *event);
    virtual void handleButtonRelease(XButtonEvent *event);

    void setText(const string text);
    void setMeterText(const string meterText);

private:

    unsigned int calculateMetersWidth();
    unsigned int calculateWorkspaceWidth();
    void invokeClickedThing(int xPosition);

    void updateInputModeButton(unsigned int *offsetX);
    void updateWorkspacePager(unsigned int *offsetX);
    void updateDetachedClients(unsigned int *offsetX);
    void updateStatus(unsigned int *offsetX);
    void updateMeters(unsigned int offsetX);

    string meterText_;
    string text_;
    bool buttonPressed_;
};

#endif // __STATUSBAR_H
