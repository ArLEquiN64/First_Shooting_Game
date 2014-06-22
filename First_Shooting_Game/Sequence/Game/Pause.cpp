#include "DxLib.h"
#include "Image.h"
#include "Control.h"
#include "Sequence\Game\Pause.h"
#include "Sequence\Game\GParent.h"

namespace Sequence{
namespace Game{

Pause::Pause() : mImage(0){
	mImage = new Image("S:/materials/Images/Pause.png");
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
	if (gKey[KEY_INPUT_1]) {	//やりなおし
		parent->control()->reset();
		parent->moveTo(GParent::SEQ_PLAY);
	}
	if (gKey[KEY_INPUT_2]){	//メニューへ
		parent->moveTo(GParent::SEQ_MENU);
	}
	if (gKey[KEY_INPUT_3]){	//タイトルへ
		parent->moveTo(GParent::SEQ_TITLE);
	}
	if (gKey[KEY_INPUT_4]){	//そのまま戻る
		parent->moveTo(GParent::SEQ_PLAY);
	}	//その他は無視

	//描画
	//まずゲーム画面
	parent->control()->draw();
	//上に重ねる
	mImage->draw();
}


} //namespace Game
} //namespace Sequence