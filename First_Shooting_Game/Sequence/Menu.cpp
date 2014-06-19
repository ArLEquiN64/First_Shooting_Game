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
	//入力取得
	if (gKey[KEY_INPUT_K]){ parent->moveTo(Parent::SEQ_TITLE); }
	else if (gKey[KEY_INPUT_J]){ parent->moveTo(Parent::SEQ_GAME); }
	//描画
	mImage->draw();
}

}	//namespace Sequence