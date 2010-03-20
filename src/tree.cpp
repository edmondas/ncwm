// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt> 
// See ../LICENSE.txt for license details.
//
// $Id: tree.cpp 13 2008-04-18 08:02:14Z eg1981 $

#include "tree.h"

#include "frame.h"

Tree::Tree(Tree *parent, Rectangle *rect)
    : Rectangle(*rect)
{
    parent_ = parent;
    frame_ = 0;
    first_ = last_ = 0;
    visits_ = 0;
}

Tree::~Tree() {
}

Tree *Tree::parent() const {
    return parent_;
}

void Tree::setParent(Tree *tree) {
    parent_ = tree;
}

void Tree::setFrame(Frame *frame) {
    frame_ = frame;
    if (frame_) {
        frame_->setTree(this);
        frame_->copy(this);
    }
}

Frame *Tree::frame() const {
    return frame_;
}

Tree *Tree::first() const {
    return first_;
}

Tree *Tree::last() const {
    return last_;
}

void Tree::setChilds(Tree *first, Tree *last) {
    first_ = first;
    last_ = last;
    if (first_ && last_) {
        first_->setParent(this);
        last_->setParent(this);
    }
}

void Tree::setHoriz(bool horiz) {
    isHoriz_ = horiz;
}

bool Tree::isHoriz() const {
    return isHoriz_;
}

unsigned int Tree::visits() const {
    return visits_;
}

void Tree::setVisit(unsigned int visit) {
    visits_ = visit;
}
