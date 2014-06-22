#include "Sequence\Game\Loading.h"
#include "Sequence\Game\GParent.h"
#include "Image.h"

namespace Sequence{
namespace Game{

//���[�h���n�߂�̂�update�����炱���ł̓��[�h�͊J�n���Ȃ����A
//�u���[�h���v�Ƃ����摜�͂����Ń��[�h����B
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
	//�`��
	mImage->draw();

	if (!mStarted){
		//���ǃ��[�h����̂͐e�B�Ȃ��Ȃ�State�������Ă���̂͐e������B
		parent->startLoading();
		mStarted = true;
	}
	else if (mCount == 60){	//1�b�҂�
		parent->moveTo(GParent::SEQ_PLAY);	//Play�Ɉړ�
	}

	++mCount;
}

} //namespace Game
} //namespace Sequence