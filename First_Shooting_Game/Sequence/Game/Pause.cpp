#include "DxLib.h"
#include "Image.h"
#include "State.h"
#include "Sequence\Game\Pause.h"
#include "Sequence\Game\GParent.h"

namespace Sequence{
namespace Game{

Pause::Pause() : mImage(0){
	mImage = new Image("S:/Images/Pause.png");
}

Pause::~Pause(){
	delete mImage;
	mImage = 0;
}

void Pause::update(GParent* parent){
	//1:やりなおし
	//2:メニューへ
	//3:タイトル画面へ
	//4:戻る
	//添え字がずれると面倒なので0も入れておく
	int inputNumber = 0;
	CheckKeyInput(inputNumber);
	switch (inputNumber){
	case 1: //やりなおし
		parent->state()->reset();
		parent->moveTo(GParent::SEQ_PLAY);
		break;
	case 2: //メニューへ
		parent->moveTo(GParent::SEQ_MENU);
		break;
	case 3: //タイトルへ
		parent->moveTo(GParent::SEQ_TITLE);
		break;
	case 4: //そのまま戻る
		parent->moveTo(GParent::SEQ_PLAY);
		break;
	default: //その他は無視
		break;
	}
	//描画
	//まずゲーム画面
	parent->state()->draw();
	//上に重ねる
	mImage->draw();
}



} //namespace Game
} //namespace Sequence