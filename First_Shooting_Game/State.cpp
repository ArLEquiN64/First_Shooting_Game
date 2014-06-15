#include "State.h"
#include "DxLib.h"

State::State(char status, int x, int y){
	switch (status){
	case 'p': s = STATUS_PLAYER; imgname = LoadGraph("S:/images/KMAP�e�����f��/���@�f��/Reisen.png"); break;
	case 'e': s = STATUS_ENEMY; imgname = LoadGraph("img/Sikaku.png"); break;
	}
	State::x = x;
	State::y = y;

	GetGraphSize(imgname, &sizex, &sizey);
}

void State::update(){
	switch (s){
	case STATUS_PLAYER:{
		//�ړ���
		int dx = 0;
		int dy = 0;
		char key[256];
		GetHitKeyStateAll(key);
		if (key[KEY_INPUT_A] == 0 && key[KEY_INPUT_D] == 1){ dx = 2; }
		if (key[KEY_INPUT_A] == 1 && key[KEY_INPUT_D] == 0){ dx = -2; }
		if (key[KEY_INPUT_W] == 0 && key[KEY_INPUT_S] == 1){ dy = 2; }
		if (key[KEY_INPUT_W] == 1 && key[KEY_INPUT_S] == 0){ dy = -2; }
		if (key[KEY_INPUT_SPACE] == 0){ dx *= 2; dy *= 2; }	//Space�L�[�ő��x����
		//�ړ�����W
		int tx = x + dx;
		int ty = y + dy;
		//���W�̍ő�ŏ��`�F�b�N�B�O��Ă���Εs����
		if (tx < 0 || ty < 0 || tx >= 800-sizex || ty >= 600-sizey){
			return;
		}
		x = tx;
		y = ty;

		break; }

	case STATUS_ENEMY:{
		//�ړ���
		int dx = 1;
		int dy = 0;
		//�ړ�����W
		int tx = x + dx;
		int ty = y + dy;
		//���W�̍ő�ŏ��`�F�b�N�B�O��Ă���Εs����
		if (tx < 0 || ty < 0 || tx >= 800-sizex || ty >= 600-sizey){
			return;
		}
		x = tx;
		y = ty;

		break; }
	}

}

void State::draw(){
	drawScreen(x, y);
}

void State::drawScreen(int x, int y){
	DrawGraph(x, y, imgname, false);
}