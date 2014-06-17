#include "DxLib.h"
#include "State.h"
#include "Image.h"
#include "Sequence\Parent.h"

//�O���[�o���ϐ�
Sequence::Parent* gRootSequence = 0; //�������V�[�P���X

// WinMain�֐�
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
		// �P�V�~���b(��b�ԂU�O�t���[�����������̂P�t���[��������̌o�ߎ���)
		// �o�߂���܂ł����ő҂�
		//while (GetNowCount() - Time < 17){}//�I������

		if (ProcessMessage() == -1){
			break;
		}
	}
	//�㏈��
	delete gRootSequence;
	gRootSequence = 0;
	DxLib_End();

	return 0;
}