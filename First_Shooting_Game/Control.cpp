#include "Control.h"
#include "Scenery.h"
#include "Player.h"
#include "Enemy.h"

Control::Control() {
	mScenery = new Scenery();
	mPlayer = new Player();
	mEnemy = new Enemy();
}

Control::~Control() {
	delete mScenery;
	mScenery = 0;
	delete mPlayer;
	mPlayer = 0;
	delete mEnemy;
	mEnemy = 0;
}

void Control::update() {
	mScenery->update();
	mPlayer->update();
	mEnemy->update();
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
}