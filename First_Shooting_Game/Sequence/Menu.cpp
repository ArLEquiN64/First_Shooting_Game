#include "DxLib.h"
#include "Sequence\Menu.h"
#include "Sequence\Parent.h"
#include "Image.h"

namespace Sequence{

Menu::Menu() : mImage(0){
	mImage = new Image("S:/images/Menu.png");
}

Menu::~Menu(){
	delete mImage;
	mImage = 0;
}

void Menu::update(Parent* parent){
	//���͎擾
	char next[256];
	GetHitKeyStateAll(next);
	if (next[KEY_INPUT_K]){ parent->moveTo(Parent::SEQ_TITLE); }
	else if (next[KEY_INPUT_J]){ parent->moveTo(Parent::SEQ_GAME); }
	//�`��
	mImage->draw();
}

}	//namespace Sequence