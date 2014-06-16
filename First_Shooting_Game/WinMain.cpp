#include "DxLib.h"
#include "State.h"
#include "Sequence\Parent.h"


// WinMainŠÖ”
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ChangeWindowMode(TRUE);
	SetGraphMode(800, 600, 16);
	SetMainWindowText("First Shooting Game");
	if (DxLib_Init() == -1)
		return -1;
	
	SetDrawScreen(DX_SCREEN_BACK);

	State gPlayer('p',400,400);
	State gEnemy('e');


	while(CheckHitKey(KEY_INPUT_ESCAPE)!=1){
		//int Time = GetNowCount();
		ClearDrawScreen();

		gPlayer.update();
		gPlayer.draw();
		gEnemy.update();
		gEnemy.draw();

		ScreenFlip();
		// ‚P‚Vƒ~ƒŠ•b(–ñ•bŠÔ‚U‚OƒtƒŒ[ƒ€‚¾‚Á‚½‚Ì‚PƒtƒŒ[ƒ€‚ ‚½‚è‚ÌŒo‰ßŠÔ)
		// Œo‰ß‚·‚é‚Ü‚Å‚±‚±‚Å‘Ò‚Â
		//while (GetNowCount() - Time < 17){}
	}



	//Œãˆ—
	DxLib_End();
	return 0;
}