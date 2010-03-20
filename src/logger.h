// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: logger.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __LOGGER_H
#define __LOGGER_H

#include <fstream>
#include <string>

#include "singleton.h"
#include "ncwm.h"

// forward declaration
class Logger;

/**
 * Basic logger which distinguishes error, warning and debug logging.
 */
class Logger : public Singleton<Logger>
{

public:

    Logger();
    ~Logger();

    /** If fatal <code>true</code> then exit(1) occurs */
    void error(string message, bool fatal = false); // will be logged always
    void warning(string message);
    void debug(string message);

};

#endif // __LOGGER_H
