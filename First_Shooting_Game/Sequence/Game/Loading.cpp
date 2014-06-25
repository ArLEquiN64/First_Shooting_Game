#include "Sequence\Game\Loading.h"
#include "Sequence\Game\GParent.h"
#include "Image.h"
#include "StringRenderer.h"

#include "DxLib.h"

extern int gCount;

namespace Sequence{
namespace Game{

//ロードを始めるのはupdateだからここではロードは開始しないが、
//「ロード中」という画像はここでロードする。
Loading::Loading() : mImage(0), mCount(0), mStarted(false) {
	mImage = new Image("S:/materials/images/東方風素材/自機/pl02_option.png");
	mImage->setDivGraph(0, 0, 32, 32, 8, 2);
	int buf[] = { 0, 1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8 };
	mImage->setAnimetion(0, buf, 16, 16);
	mStr = new StringRenderer();
}

Loading::~Loading(){
	delete mImage;
	mImage = 0;
}

void Loading::update(GParent* parent) {
	//描画
	mImage->animationDraw(750,550,0);
	if (0 <= mCount && mCount < 20) { mStr->draw(500, 550, "now loading."); }
	if (20 <= mCount && mCount < 40) { mStr->draw(500, 550, "now loading.."); }
	if (40 <= mCount && mCount < 60) { mStr->draw(500, 550, "now loading..."); }

	if (!mStarted){
		//結局ロードするのは親。なぜならStateを持っているのは親だから。
		//SetUseASyncLoadFlag(true);
		parent->startLoading();
		mStarted = true;
		SetUseASyncLoadFlag(false);
	}
	else if (GetASyncLoadNum() == 0){	//読み込み完了
		gCount = 0;
		parent->moveTo(GParent::SEQ_PLAY);	//Playに移動
	}

	mCount++;
	gCount++;
}

} //namespace Game
} //namespace Sequence