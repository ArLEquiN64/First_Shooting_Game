#include "Sequence\Game\Loading.h"
#include "Sequence\Game\GParent.h"
#include "Image.h"

namespace Sequence{
namespace Game{

//ロードを始めるのはupdateだからここではロードは開始しないが、
//「ロード中」という画像はここでロードする。
Loading::Loading() :
	mImage(0),
	mCount(0),
	mStarted(false){
	mImage = new Image("S:/materials/images/Loading.png");
}

Loading::~Loading(){
	delete mImage;
	mImage = 0;
}

void Loading::update(GParent* parent) {
	//描画
	mImage->draw();

	if (!mStarted){
		//結局ロードするのは親。なぜならStateを持っているのは親だから。
		parent->startLoading();
		mStarted = true;
	}
	else if (mCount == 60){	//1秒待つ
		parent->moveTo(GParent::SEQ_PLAY);	//Playに移動
	}

	++mCount;
}

} //namespace Game
} //namespace Sequence