#include "Control.h"
#include "Scenery.h"
#include "Player.h"
#include "Enemy.h"
#include "DeathJudge.h"

extern int gCount;

Control::Control() {
	mScenery = new Scenery();
	mPlayer = new Player();
	mEnemy = new Enemy();
	E_shotFlag = false;
	P_shotFlag = false;/*
	P_shotSound = LoadSoundMem("S:/images/SE v0.20/shot1.wav");
	E_shotSound = LoadSoundMem("S:/images/SE v0.20/shot2.wav");*/
}

Control::~Control() {
	delete mScenery;
	mScenery = 0;
	delete mPlayer;
	mPlayer = 0;
	delete mEnemy;
	mEnemy = 0;
}

Player* Control::player(){
	return mPlayer;
}

Enemy* Control::enemy(){
	return mEnemy;
}

void Control::update() {
	mScenery->update();
	mPlayer->update();
	mEnemy->update();
	mJudge->update(mPlayer,mEnemy);
}

void Control::draw(){
	mScenery->draw();
	mPlayer->draw();
	mEnemy->draw();
}

void Control::reset() {
	mScenery = new Scenery();
	mPlayer = new Player();
	mEnemy = new Enemy();
	gCount = 0;
}