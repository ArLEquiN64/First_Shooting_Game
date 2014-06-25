#define _USE_MATH_DEFINES
#include <math.h>
#include "DxLib.h"
#include "Image.h"
#include "Control.h"
#include "Enemy.h"
#include "E_Shot.h"
#include "Player.h"

extern int gCount;

E_Shot::E_Shot() {
	mImage = new Image("S:/materials/images/niconi-commons/niconicommons_only/nc89509.png",0.6);
	mImage->setDivGraph(0,0,32,32,16,12);
	mShot = new E_SHOT[BULLET];
	for (int i = 0; i < BULLET; i++) {
		mShot[i].live = false;
	}
}

E_Shot::~E_Shot() {
	delete mImage;
	mImage = 0;
}

void E_Shot::fire(double x, double y, int shotType, Player* player) {
	//弾発射
	double px, py;
	bool a;
	player->getState(&a, &px, &py);
	if (msCount == 0) { rad = atan2(py - y, px - x); }
	switch (shotType) {
	case 1:
		for (int i = 0; i < BULLET; i++) {
			if (mShot[i].live == false && gCount % 16 == 0) {
				mShot[i].live = true;
				mShot[i].x = x;
				mShot[i].y = y;
				mShot[i].rad = M_PI/2; break;
			}
		}
		break;
	case 2:
		for (int i = 0; i < BULLET; i++) {
			if (mShot[i].live == false && gCount % 16 == 0) {
				mShot[i].live = true;
				mShot[i].x = x;
				mShot[i].y = y;
				mShot[i].rad = rad; break;
			}
		}
		break;
	case 3:
		for (int i = 0; i < BULLET; i++) {
			if (mShot[i].live == false && gCount % 16 == 0) {
				mShot[i].live = true;
				mShot[i].x = x;
				mShot[i].y = y;
				//0の時は左より
				if (num == 0) {

					//敵とプレイヤーとの逆正接から10度引いたラジアンを代入
					mShot[i].rad = rad - (10 * 3.14 / 180);
					//1の時はプレイヤー一直線
				}
				else if (num == 1) {
					//敵とプレイヤーとの逆正接を代入
					mShot[i].rad = rad;
					//2の時は右より
				}
				else if (num == 2) {
					//敵とプレイヤーとの逆正接から10度足したラジアンを代入
					mShot[i].rad = rad + (10 * M_PI / 180);

				}
				++num;

				//3発発射したら,numを0にしてループを抜ける。
				if (num == 3) {
					num = 0;
					break;
				}
			}
		}
		break;
	case 4:
		for (int i = 0; i < BULLET; i++) {
			if (mShot[i].live == false && gCount % 2 == 0) {
				mShot[i].live = true;
				mShot[i].x = x;
				mShot[i].y = y;
				//初回だけ乱数初期化
				if (num == 0) { srand(128); }

				mShot[i].rad = atan2(py - y, px - x) - (120 * M_PI / 180) + ((rand() % 240)*M_PI / 180);
				++num;
				break;
			}
		}
		break;
	case 5:
		for (int i = 0; i < BULLET; i++) {
			if (mShot[i].live == false && gCount % 3 == 0) {
				mShot[i].live = true;
				mShot[i].x = x;
				mShot[i].y = y;
				if (msCount == 5) { msCount = 0; }
				if (num == 0) {				//0の時は左より
					//敵とプレイヤーとの逆正接から10度引いたラジアンを代入
					mShot[i].rad = rad - (2*msCount * M_PI / 180);
				}
				else if (num == 1) {		//1の時はプレイヤー一直線
					//敵とプレイヤーとの逆正接を代入
					mShot[i].rad = msCount*rad;
				}
				else if (num == 2) {		//2の時は右より
					//敵とプレイヤーとの逆正接から10度足したラジアンを代入
					mShot[i].rad = rad + (2*msCount * M_PI / 180);
				}
				++num;
				//3発発射したら,numを0にしてループを抜ける。
				if (num == 3) {
					num = 0;
					msCount++;
					break;
				}
			}
		}
		break;
	}
}

void E_Shot::update(int shotType, Player* player) {
	//弾移動
	for (int i = 0; i < BULLET; i++) {
		if (mShot[i].live) {
			switch (shotType) {
			case 1:
				mShot[i].y += 4;
				break;
			case 2:
			case 3:
			case 4:
			case 5:
				mShot[i].x += 4 * cos(mShot[i].rad);
				mShot[i].y += 4 * sin(mShot[i].rad);
				break;
			}

			//画面外判定
			if (mShot[i].y < 0 - mImage->height() / 2 || mShot[i].y > 600 + mImage->height() / 2
				|| mShot[i].x < 0 - mImage->width() / 2 || mShot[i].x>600 + mImage->width() / 2) {
				mShot[i].live = false;
			}
		}

	}
}

void E_Shot::draw() {
	for (int i = 0; i < BULLET; i++) {
		if (mShot[i].live == true) { mImage->rotationDraw(mShot[i].x, mShot[i].y, 18, 1, mShot[i].rad + M_PI/2); }
	}
}