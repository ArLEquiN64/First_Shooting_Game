#include "DxLib.h"
#include "State.h"
#include "Sequence\Parent.h"


// WinMain関数
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
		// １７ミリ秒(約秒間６０フレームだった時の１フレームあたりの経過時間)
		// 経過するまでここで待つ
		//while (GetNowCount() - Time < 17){}
	}



	//後処理
	DxLib_End();
	return 0;
}