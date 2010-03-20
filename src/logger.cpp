// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: logger.cpp 13 2008-04-18 08:02:14Z eg1981 $

#include <cstdlib>
#include <iostream>

#include "logger.h"
#include "util.h"

Logger::Logger() {

}

Logger::~Logger() {

}

void Logger::error(string message, bool fatal) {
    cerr << "ncwm[E " << Util::timestamp() << "]: " << message;
    if (fatal) {
        cerr << ", giving up" << endl;
        exit(1);
    }
    cerr << endl;
}

void Logger::warning(string message) {
    cerr << "ncwm[W " << Util::timestamp() << "]: " << message << endl;
}

void Logger::debug(string message) {
    cout << "ncwm[D " << Util::timestamp() << "]: "
         << message << endl;
}
