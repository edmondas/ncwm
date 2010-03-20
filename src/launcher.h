// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: launcher.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __LAUNCHER_H
#define __LAUNCHER_H

#include <string>

#include "ncwm.h"

#include "singleton.h"

// forward declaration
class Action;
class Launcher;

/**
 * Launches external processes and is capable to process chain
 * invocations.
 *
 * Determines recursion in chain invocation.
 */
class Launcher : public Singleton<Launcher>
{

public:

    /** Constructs a new process manager instance.  */
    Launcher();

    ~Launcher();

    /** Execs the given command. */
    void exec(string command);

    /** Execs a chain. */
    void execSeq(Action *caller, string command);
};

#endif // __LAUNCHER_H
