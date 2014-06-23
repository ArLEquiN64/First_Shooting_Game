#include "DxLib.h"
#include "File.h"

void File::loadStageData() {
	FILE* fp;
	int c;
	row = 0;	//�s��

	fopen_s(&fp, "data/StageData.csv", "r");

	while (fgetc(fp) != '\n');	//�w�b�_�ǂݔ�΂�

	while (true) {
		c = fgetc(fp);
		if (c == '\n') { ++row; }
		if (c == EOF) { break; }
	}

	mStageData = new ENEMY[row + 1];
	//setEnemuNum(row);

	char buf[128];	//�o�b�t�@
	int col = 1;	//��
	row = 0;

	memset(buf, 0, sizeof(buf));
	fopen_s(&fp, "data/StageData.csv", "r");


	while (fgetc(fp) != '\n');	//�w�b�_�ǂݔ�΂�

	while (true) {
		while (true) {
			c = fgetc(fp);

			//�����Ȃ烋�[�v�𔲂���
			if (c == EOF) { goto out; }

			//�J���}�����s�łȂ���Ε����Ƃ��ĂȂ���
			if (c != ','&&c != '\n') { strcat_s(buf, (const char*)&c); }
			else { break; }
		}

		//�����ɗ�����1�Z�����̕������o���オ���Ă���Ƃ�������
		switch (col) {
		case 1: mStageData[row].mType = atoi(buf); break;				//���
		case 2: mStageData[row].mBulletType = atoi(buf); break;			//�e���
		case 3: mStageData[row].mBulletSpeed = atoi(buf); break;		//�e���x
		case 4: mStageData[row].mMotionType = atoi(buf); break;			//�ړ��p�^�[��
		case 5: mStageData[row].mShotType = atoi(buf); break;			//�U���p�^�[��
		case 6: mStageData[row].mInTime = atoi(buf); break;				//�o������
		case 7: mStageData[row].mMoveTime = atoi(buf); break;			//�ړ�����
		case 8: mStageData[row].mStayTime = atoi(buf); break;			//�؍ݎ���
		case 9: mStageData[row].mShotTime = atoi(buf); break;			//�e���ˊJ�n����
		case 10: mStageData[row].mShootingTime = atoi(buf); break;		//�e���ˎ���
		case 11: mStageData[row].mX = atoi(buf); break;					//x���W
		case 12: mStageData[row].mY = atoi(buf); break;					//y���W
		case 13: mStageData[row].mHp = atoi(buf); break;				//�̗�
		case 14: mStageData[row].mItem = atoi(buf); break;				//�A�C�e��
		}

		memset(buf, 0, sizeof(buf));	//�o�b�t�@������
		col++;							//�񐔂𑫂�

		//�����ǂݍ��񂾕��������s��������񐔂����������A�s���𑝂₷
		if (c == '\n') {
			col = 1;
			++row;
		}
	}

out:	//�t�@�C���ǂݍ��ݏI��
	fclose(fp);
	return;
}

ENEMY* File::storeStageData() {
	return mStageData;
}

int File::enemyNum() {
	return row+1;
}