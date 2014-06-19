#include "DxLib.h"
#include "Image.h"
#include "Sequence\Parent.h"

//グローバル変数
Sequence::Parent* gRootSequence = 0; //根っこシーケンス
char gKey[256];		//キーステート
int gCount = 0;
bool endRequest = false;	//ゲーム終了フラグ

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ChangeWindowMode(TRUE);
	SetGraphMode(800, 600, 16);
	SetMainWindowText("First Shooting Game");
	if (DxLib_Init() == -1)
		return -1;
	
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && endRequest == false){
		//int Time = GetNowCount();
		ClearDrawScreen();

		if (!gRootSequence){
			gRootSequence = new Sequence::Parent();
		}

		GetHitKeyStateAll(gKey);

		gRootSequence->update();

		// １７ミリ秒(約秒間６０フレームだった時の１フレームあたりの経過時間)
		// 経過するまでここで待つ
		//while (GetNowCount() - Time < 17){}//終了判定

		ScreenFlip();
	}

	//後処理
	delete gRootSequence;
	gRootSequence = 0;
	DxLib_End();

	return 0;
}