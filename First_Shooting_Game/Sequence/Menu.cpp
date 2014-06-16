#include "Sequence/Menu.h"
#include "Sequence/Parent.h"
#include "Image.h"

namespace Sequence{

Menu::Menu() : mImage(0){
	mImage = new Image();
}

Menu::~Menu(){

}

void Menu::update(Parent*){

}

}	//namespace Sequence