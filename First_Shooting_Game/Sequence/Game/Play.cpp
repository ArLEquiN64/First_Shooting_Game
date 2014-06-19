#include "DxLib.h"
#include "Sequence\Game\Play.h"
#include "Sequence\Game\GParent.h"
#include "Control.h"

extern int gCount;

namespace Sequence{
namespace Game{

Play::Play() {
	gCount = 0;
}

Play::~Play(){
}

void Play::update(GParent* parent){
	Control* control = parent->control();
	if (gKey[KEY_INPUT_Q]) { parent->moveTo(GParent::SEQ_PAUSE); }
	control->update();
	control->draw();
	gCount++;
}

}	//namespace Game
}	//namespace Sequence