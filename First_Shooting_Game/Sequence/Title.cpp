#include "DxLib.h"
#include "Sequence\Title.h"
#include "Sequence\Parent.h"
#include "Image.h"

namespace Sequence{

Title::Title() : mImage(0){
	mImage = new Image("S:/images/First_Shooting_Game_Title.bmp");
}

Title::~Title(){
	delete mImage;
	mImage = 0;
}

void Title::update(Parent* parent){
	//���͎擾
	if (CheckHitKey(KEY_INPUT_SPACE)){
		parent->moveTo(Parent::SEQ_MENU);
	}
	//�`��
	//ClearDrawScreen();
	mImage->draw();
	//ScreenFlip();
}

} //namespace Sequence