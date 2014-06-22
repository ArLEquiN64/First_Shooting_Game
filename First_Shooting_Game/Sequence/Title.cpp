#include "DxLib.h"
#include "Sequence\Title.h"
#include "Sequence\Parent.h"
#include "Image.h"

namespace Sequence{

Title::Title() : mImage(0){
	mImage = new Image("image/Title.bmp");
}

Title::~Title(){
	delete mImage;
	mImage = 0;
}

void Title::update(Parent* parent){
	//“ü—ÍŽæ“¾
	if (gKey[KEY_INPUT_SPACE]){	parent->moveTo(Parent::SEQ_MENU); }
	if (gKey[KEY_INPUT_ESCAPE]){ endRequest = true; }
	//•`‰æ
	mImage->draw();
}

} //namespace Sequence