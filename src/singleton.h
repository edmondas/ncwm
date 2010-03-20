// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt> 
// See ../LICENSE.txt for license details.
//
// $Id: singleton.h 13 2008-04-18 08:02:14Z eg1981 $

#ifndef __SINGLETON_H
#define __SINGLETON_H

/**
 * Basic singleton template used by various controller classes of NCWM.
 */
template <class T> class Singleton
{

public:

    static T *instance() {
        if (instance_ == 0) {
            // use default constructor
            instance_ = new T;
        }
        return instance_;
    }

private:

    // the singleton instance
    static T *instance_;
};

template <class T> T* Singleton<T>::instance_ = 0;

#endif // __SINGLETON_H
