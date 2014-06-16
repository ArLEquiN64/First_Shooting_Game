#include "DxLib.h"
#include "Sequence/Title.h"
#include "Sequence/Parent.h"
#include "Image.h"

namespace Sequence{

Title::Title() : mImage(0){
	mImage = new Image();
}

Title::~Title(){
	delete mImage;
	mImage = 0;
}

void Title::update(Parent* parent){
	//入力取得
	if (CheckHitKey(KEY_INPUT_SPACE)){
		parent->moveTo(Parent::SEQ_MENU);
	}
	//描画
	mImage->draw();
}

} //namespace Sequence