// Copyright (c) 2003 - 2004 Marcel Manthe <schneegloeckchen at gmx.li>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: expander.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __EXPANDER_H
#define __EXPANDER_H

#include <string>
#include <set>

#include "singleton.h"

using namespace std;


/**
 * Provides PATH executable expansion.
 */
class Expander : public Singleton<Expander>{
    public:
        Expander();
        bool queryString (string s);
        bool rehash();
        set<string> expands();

    private:
        set<string> read();
        bool pathSearch_;
        string key_;
        string path_;
        set<string> paths_;
        set<string> expands_;
        set<string> pathExpands_;
};

#endif // __EXPANDER_H
