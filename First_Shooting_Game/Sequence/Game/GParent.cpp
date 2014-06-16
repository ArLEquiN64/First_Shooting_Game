#include "Sequence/Game/GParent.h"
#include "Sequence/Parent.h"
#include "State.h"

namespace Sequence{
namespace Game{

//Parent::Parent(int stageID) :
//	mState(0),
//	mStageID(stageID),
//	mNext(SEQ_NONE),
//	mClear(0),
//	mLoading(0),
//	mMenu(0),
//	mPlay(0){
//	//ç≈èâÇ…ÉçÅ[Éh
//	mLoading = new Loading();
//}

void GParent::update(Parent* parent){
	mNext = SEQ_NONE;
}

}	//namespace game
}	//namespace Sequence