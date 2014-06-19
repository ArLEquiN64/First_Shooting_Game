#include "DxLib.h"
#include "Image.h"
#include "Sequence\Parent.h"

//�O���[�o���ϐ�
Sequence::Parent* gRootSequence = 0; //�������V�[�P���X
char gKey[256];		//�L�[�X�e�[�g
int gCount = 0;
bool endRequest = false;	//�Q�[���I���t���O

// WinMain�֐�
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

		// �P�V�~���b(��b�ԂU�O�t���[�����������̂P�t���[��������̌o�ߎ���)
		// �o�߂���܂ł����ő҂�
		//while (GetNowCount() - Time < 17){}//�I������

		ScreenFlip();
	}

	//�㏈��
	delete gRootSequence;
	gRootSequence = 0;
	DxLib_End();

	return 0;
}