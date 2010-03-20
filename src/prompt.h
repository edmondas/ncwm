// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: prompt.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __PROMPT_H
#define __PROMPT_H

#include <set>
#include <string>
#include "ncwm.h"

class Binder;

typedef set<string> Sstring;
typedef string (Binder::*QueryNamesForPrefix)
            (string prefix, Sstring *nameSet);

/**
 * Represents a prompt in input mode. A prompt may also contain a
 * query method pointer for dynamic menu support.
 */
class Prompt {

public:

    Prompt(string prompt, QueryNamesForPrefix toQuery);

    string prompt() const;

    QueryNamesForPrefix toQuery() const;

private:

    string prompt_;
    QueryNamesForPrefix toQuery_;
};

#endif // __PROMPT_H
