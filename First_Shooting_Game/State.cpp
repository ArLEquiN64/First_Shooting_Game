#include "State.h"
#include "DxLib.h"

State::State(char status, int x, int y){
	switch (status){
	case 'p':
		s = STATUS_PLAYER;
		imgname = LoadGraph("S:/images/KMAP弾幕風素材/自機素材/Reisen.png");
		atarihantei = LoadGraph("S:/images/KMAP弾幕風素材/自機素材/atarihantei.png");
		break;
	case 'e':
		s = STATUS_ENEMY;
		imgname = LoadGraph("S:/images/KMAP弾幕風素材/その他ボス素材/dot_rumia.png");
		break;
	}
	State::x = x;
	State::y = y;

	GetGraphSize(imgname, &sizex, &sizey);
}

void State::update(){
	switch (s){
	case STATUS_PLAYER:{
		//移動量
		int dx = 0;
		int dy = 0;
		char key[256];
		GetHitKeyStateAll(key);
		if (key[KEY_INPUT_A] == 0 && key[KEY_INPUT_D] == 1){ dx = 2; }
		if (key[KEY_INPUT_A] == 1 && key[KEY_INPUT_D] == 0){ dx = -2; }
		if (key[KEY_INPUT_W] == 0 && key[KEY_INPUT_S] == 1){ dy = 2; }
		if (key[KEY_INPUT_W] == 1 && key[KEY_INPUT_S] == 0){ dy = -2; }
		if (key[KEY_INPUT_SPACE] == 0){ dx *= 2; dy *= 2; }	//Spaceキーで速度半減
		//移動後座標
		int tx = x + dx;
		int ty = y + dy;
		//座標の最大最小チェック。外れていれば不許可
		if (tx < -21 || tx >= 800 - 24){ tx = x; }
		if (ty < -21 || ty >= 600 - 21){ ty = y; }
		x = tx;
		y = ty;

		if (dx == 0){ direction = 0; }
		if (dx < 0){ direction = 1; }
		if (dx > 0){ direction = 2; }

		break;
	}

	case STATUS_ENEMY:{
		//移動量
		int dx = 1;
		int dy = 0;
		//移動後座標
		int tx = x + dx;
		int ty = y + dy;
		//座標の最大最小チェック。外れていれば不許可
		if (tx < 0 || tx >= 800 - sizex){ tx = x; }
		if (ty < 0 || ty >= 600 - sizey){ ty = y; }
		x = tx;
		y = ty;

		if (dx == 0){ direction = 0; }
		if (dx < 0){ direction = 1; }
		if (dx > 0){ direction = 2; }

		break;
	}
	}

}

void State::draw(){
	drawScreen(x, y, direction);
}

void State::drawScreen(int x, int y, int direction){
	if (s == STATUS_PLAYER){
		switch (direction){
		case 0:	DrawRectGraph(x, y, 0, 0, 48, 48, imgname, true, false); break;
		case 1:	DrawRectGraph(x, y, 48, 0, 48, 48, imgname, true, false); break;
		case 2:	DrawRectGraph(x, y, 96, 0, 48, 48, imgname, true, false); break;
		}
		DrawGraph(x+12, y+12, atarihantei, true);
	}
	else{ DrawGraph(x, y, imgname,true); }
}