#include "DxLib.h"
#include "State.h"
#include "Image.h"
#include "Sequence\Parent.h"

//グローバル変数
Sequence::Parent* gRootSequence = 0; //根っこシーケンス

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ChangeWindowMode(TRUE);
	SetGraphMode(800, 600, 16);
	SetMainWindowText("First Shooting Game");
	if (DxLib_Init() == -1)
		return -1;
	
	SetDrawScreen(DX_SCREEN_BACK);

	while(true){
		//int Time = GetNowCount();
		ClearDrawScreen();

		if (!gRootSequence){
			gRootSequence = new Sequence::Parent();
		}

		gRootSequence->update();
/*
		State gPlayer('p', 400, 400);
		State gEnemy('e');

		gPlayer.update();
		gPlayer.draw();
		gEnemy.update();
		gEnemy.draw();
*/
		ScreenFlip();
		// １７ミリ秒(約秒間６０フレームだった時の１フレームあたりの経過時間)
		// 経過するまでここで待つ
		//while (GetNowCount() - Time < 17){}//終了判定

		if (ProcessMessage() == -1){
			break;
		}
	}
	//後処理
	delete gRootSequence;
	gRootSequence = 0;
	DxLib_End();

	return 0;
}