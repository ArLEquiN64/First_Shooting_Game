#include "DxLib.h"
#include "Sequence\Menu.h"
#include "Sequence\Parent.h"
#include "Image.h"
#include "StringRenderer.h"

namespace Sequence{

Menu::Menu() : mImage(0){
	mImage = new Image("S:/materials/images/Menu.png");
	str = new StringRenderer;
}

Menu::~Menu(){
	delete mImage;
	mImage = 0;
}

void Menu::update(Parent* parent) {
	//•`‰æ
	mImage->draw();
	str->drawBig(64, 256, "Press J to start,");
	str->drawBig(64, 288, "Press K to return.");
	//“ü—ÍŽæ“¾
	if (gKey[KEY_INPUT_K]){ parent->moveTo(Parent::SEQ_TITLE); }
	else if (gKey[KEY_INPUT_J]){ parent->moveTo(Parent::SEQ_GAME); }
}

}	//namespace Sequence