// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: ncwmremote.cpp 13 2008-04-18 08:02:14Z eg1981 $

#include "../version.h"

extern "C" {
#include <unistd.h> // getopt stuff
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
}

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

static void version() {
    cout << "ncwmremote - no cheese window manager - " << __NCWM_VERSION
         << endl << " (C)opyright 2003 - 2004 by Anselm R. Garbe"
         << endl;
    exit(0);
}

static void usage() {
    cout << "usage: " << endl << endl
         << " ncwmremote [-d <display>] [-t <text>] [-m <percentage>#<text>,...]"
         << endl
         << "           [-a <action>[+arg1[+...]]] [-p] [-v]"
         << endl << endl
         << "  -a invokes an NCWM action remotely" << endl
         << "  -d specifies the display to use" << endl
         << "  -m sets meters info (see manual page for details)" << endl
         << "  -p prints current key bindings of running NCWM" << endl
         << "  -t displays bartext in the ncwm" << endl
         << "  -v show version info" << endl << endl;
    exit(1);
}

int main(int argc, char *argv[]) {

    string *displayName = 0;
    string *msgText = 0;
    string *actionCmd = 0;
    string *meterText = 0;
    bool prettyPrint = false;

    int c;

    // command line args
    while ((c = getopt(argc, argv, "a:d:t:m:pv")) != -1) {
        switch (c) {
        case 'a':
            actionCmd = new string(optarg);
            break;
        case 'd':
            displayName = new string(optarg);
            break;
        case 't':
            msgText = new string(optarg);
            break;
        case 'm':
            meterText = new string(optarg);
            break;
        case 'p':
            prettyPrint = true;
            break;
        case '?':
        case 'h':
            usage();
            break;
        case 'v':
            version();
            break;
        }
    }

    if (!msgText && !actionCmd && !prettyPrint && !meterText) {
        usage();
        exit(1);
    }

    Display *display = XOpenDisplay(displayName ? displayName->c_str() : 0);

    if (display == 0) {
        if (displayName) {
            cerr << "ncwmremote: error, cannot open display '" <<
                displayName << "'" << endl;
        }
        else {
            cerr << "ncwmremote: error, cannot open display '0'" << endl;
        }
        exit (1);
    }


    XTextProperty property;

    if (msgText) {
        Atom NCWM_STATUSTEXT = XInternAtom(display, "_NCWM_STATUSTEXT", False);
        char *text = (char *)msgText->c_str();
        XStringListToTextProperty(&text, 1, &property);
        XSetTextProperty(display, DefaultRootWindow(display), &property, NCWM_STATUSTEXT);
    }

    if (meterText) {
        Atom NCWM_METERTEXT = XInternAtom(display, "_NCWM_METERTEXT", False);
        char *text = (char *)meterText->c_str();
        XStringListToTextProperty(&text, 1, &property);
        XSetTextProperty(display, DefaultRootWindow(display), &property, NCWM_METERTEXT);
    }

    if (actionCmd) {
        Atom NCWM_ACTIONCMD = XInternAtom(display, "_NCWM_ACTIONCMD", False);
        char *action = (char *)actionCmd->c_str();
        XStringListToTextProperty(&action, 1, &property);
        XSetTextProperty(display, DefaultRootWindow(display), &property, NCWM_ACTIONCMD);
    }

    if (prettyPrint) {
        Atom NCWM_PRETTYPRINT_REQUEST = XInternAtom(display,
                "_NCWM_PRETTYPRINT_REQUEST", False);
        Atom NCWM_PRETTYPRINT_RESPONSE = XInternAtom(display,
                "_NCWM_PRETTYPRINT_RESPONSE", False);
        string value = "";
        char *val = (char *)value.c_str();
        XStringListToTextProperty(&val, 1, &property);
        XSetTextProperty(display, DefaultRootWindow(display), &property,
                         NCWM_PRETTYPRINT_REQUEST);
        // init's response value
        XSetTextProperty(display, DefaultRootWindow(display), &property,
                         NCWM_PRETTYPRINT_RESPONSE);
        bool success;
        while ((success = XGetTextProperty(display, DefaultRootWindow(display),
                             &property, NCWM_PRETTYPRINT_RESPONSE)))
        {
            if (property.nitems > 0) {
                value = (const char *)property.value;
                if (value != "") {
                    cout << value;
                    // resets value back to empty
                    value = "";
                    val = (char *)value.c_str();
                    XStringListToTextProperty(&val, 1, &property);
                    XSetTextProperty(display, DefaultRootWindow(display), &property,
                            NCWM_PRETTYPRINT_RESPONSE);
                    break;
                }
            }
            usleep(500000); // 0.5 seconds
        }
        if (!success) {
            cerr << "ncwmremote: error, it seems that NCWM is not running"
                 << endl;
            exit(1);
        }
    }
    XSync(display, False);
    return 0;
}
