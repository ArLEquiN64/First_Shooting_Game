#include "Info.h"
#include "Image.h"
#include "StringRenderer.h"
#include "Player.h"

#include <stdlib.h>

Info::Info() {
	mImage = new Image("S:/materials/images/ScoreBord.png");
	mStr = new StringRenderer();
}

Info::~Info() {
	delete mImage;
	mImage = 0;
	delete mStr;
	mStr = 0;
}

void Info::update(Player* player) {	
	player->getState(&plive, &px, &py);
	dpx = new char[_CVTBUFSIZE];
	dpy = new char[_CVTBUFSIZE];
	_gcvt_s(dpx, _CVTBUFSIZE, px, 10);
	_gcvt_s(dpy, _CVTBUFSIZE, py, 10);
}

void Info::draw() {
	mStr->drawBig(610, 60, "Infomation");
	plive == true ? mStr->draw(640, 100, "live") : mStr->draw(640, 100, "death");
	mStr->draw(620, 120, "Xposition : ");
	mStr->draw(640, 140, dpx);
	mStr->draw(620, 160, "Yposition : ");
	mStr->draw(640, 180, dpy);
}