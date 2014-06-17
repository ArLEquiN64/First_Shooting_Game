#include "Sequence\Game\Play.h"
#include "Sequence\Game\GParent.h"
#include "State.h"

namespace Sequence{
namespace Game{

Play::Play(){
}

Play::~Play(){
}

void Play::update(GParent* parent){
	//State* state = parent->state();
	State gPlayer('p', 400, 400);
	State gEnemy('e');

	gPlayer.update();
	gPlayer.draw();
	gEnemy.update();
	gEnemy.draw();
}

}	//namespace Game
}	//namespace Sequence