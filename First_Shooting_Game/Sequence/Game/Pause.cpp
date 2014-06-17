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
	//1:���Ȃ���
	//2:���j���[��
	//3:�^�C�g����ʂ�
	//4:�߂�
	//�Y�����������Ɩʓ|�Ȃ̂�0������Ă���
	int inputNumber = 0;
	CheckKeyInput(inputNumber);
	switch (inputNumber){
	case 1: //���Ȃ���
		parent->state()->reset();
		parent->moveTo(GParent::SEQ_PLAY);
		break;
	case 2: //���j���[��
		parent->moveTo(GParent::SEQ_MENU);
		break;
	case 3: //�^�C�g����
		parent->moveTo(GParent::SEQ_TITLE);
		break;
	case 4: //���̂܂ܖ߂�
		parent->moveTo(GParent::SEQ_PLAY);
		break;
	default: //���̑��͖���
		break;
	}
	//�`��
	//�܂��Q�[�����
	parent->state()->draw();
	//��ɏd�˂�
	mImage->draw();
}



} //namespace Game
} //namespace Sequence