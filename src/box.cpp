// Copyright (c) 2003 - 2004 Anselm R. Garbe <anselmg at t-online.de>
// Copyright (c) 2007 - 2008 Edmondas Girkantas <eg at fbsd.lt>
// See ../LICENSE.txt for license details.
//
// $Id: box.cpp 13 2008-04-18 08:02:14Z eg1981 $

#include "box.h"

#include "draw.h"
#include "label.h"
#include "monitor.h"
#include "theme.h"
#include "xcore.h"

Box::Box(Monitor *monitor, Rectangle *rect, string text) :
    Widget(monitor, rect)
{
    theme_ = this->monitor()->theme();
    label_ = new Label(this->monitor(), window(), Label::CENTER, gc());
    label_->setX(1);
    label_->setY(1);
    label_->setHeight(height() - 2);
    setText(text);
}

Box::~Box() {
    delete label_;
}

void Box::setText(string text) {
    label_->setText(text);
    label_->adjustWidth();
    setX(monitor()->width() / 2 - label_->width() / 2 - 1);
    setWidth(label_->width() + 2);
    resize();
}

void Box::illuminate() {
    if (!isVisible()) {
        return;
    }
    Rectangle borderRect(0, 0, width(), height());
    label_->update(theme_->TAB_BACKGROUND_ACTIVE_FOCUSSED,
                   theme_->TAB_TEXT_ACTIVE_FOCUSSED,
                   theme_->TAB_SHINE_ACTIVE_FOCUSSED,
                   theme_->TAB_SHADOW_ACTIVE_FOCUSSED,
                   true, true);
    Draw::drawRectBorder(window(), gc(), &borderRect,
                        theme_->BAR_SHINE, theme_->BAR_SHADOW);
    XCORE->sync();
}
