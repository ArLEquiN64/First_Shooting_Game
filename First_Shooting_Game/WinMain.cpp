#include "DxLib.h"
#include "State.h"



// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ChangeWindowMode(TRUE);
	SetGraphMode(800, 600, 16);
	SetMainWindowText("First Shooting Game");
	if (DxLib_Init() == -1)
		return -1;
	
	SetDrawScreen(DX_SCREEN_BACK);

	State player('p',400,400);
	State enemy('e');

	while(CheckHitKey(KEY_INPUT_ESCAPE)!=1){
		//int Time = GetNowCount();
		ClearDrawScreen();

		player.update();
		player.draw();
		enemy.update();
		enemy.draw();

		ScreenFlip();
		// �P�V�~���b(��b�ԂU�O�t���[�����������̂P�t���[��������̌o�ߎ���)
		// �o�߂���܂ł����ő҂�
		//while (GetNowCount() - Time < 17){}
	}



	//�㏈��
	DxLib_End();
	return 0;
}