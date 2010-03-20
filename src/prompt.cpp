// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: prompt.cpp 13 2008-04-18 08:02:14Z eg1981 $

#include "prompt.h"

#include "binder.h"

Prompt::Prompt(string prompt, QueryNamesForPrefix toQuery)
{
    prompt_ = prompt;
    toQuery_ = toQuery;
};

string Prompt::prompt() const {
    return prompt_;
}

QueryNamesForPrefix Prompt::toQuery() const {
    return toQuery_;
}
