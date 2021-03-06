#include "Sequence\Game\Clear.h"
#include "Sequence\Game\GParent.h"
#include "Image.h"
#include "Control.h"

namespace Sequence{
namespace Game{

Clear::Clear() : mImage(0), mCount(0){
	mImage = new Image("S:/images/Clear.png");
}

Clear::~Clear(){
	delete mImage;
	mImage = 0;
}

void Clear::update(GParent* parent){
	if (mCount == 60){ //60フレームで移動
		parent->moveTo(GParent::SEQ_MENU);
	}

	//描画
	//まずゲーム画面を描画
	parent->control()->draw();
	//上に祝いのメッセージを描画
	mImage->draw();

	++mCount;
}

} //namespace Game
} //namespace Sequence
