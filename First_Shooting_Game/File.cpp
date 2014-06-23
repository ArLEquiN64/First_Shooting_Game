#include "DxLib.h"
#include "File.h"

void File::loadStageData() {
	FILE* fp;
	int c;
	row = 0;	//行数

	fopen_s(&fp, "data/StageData.csv", "r");

	while (fgetc(fp) != '\n');	//ヘッダ読み飛ばし

	while (true) {
		c = fgetc(fp);
		if (c == '\n') { ++row; }
		if (c == EOF) { break; }
	}

	mStageData = new ENEMY[row + 1];
	//setEnemuNum(row);

	char buf[128];	//バッファ
	int col = 1;	//列数
	row = 0;

	memset(buf, 0, sizeof(buf));
	fopen_s(&fp, "data/StageData.csv", "r");


	while (fgetc(fp) != '\n');	//ヘッダ読み飛ばし

	while (true) {
		while (true) {
			c = fgetc(fp);

			//末尾ならループを抜ける
			if (c == EOF) { goto out; }

			//カンマか改行でなければ文字としてつなげる
			if (c != ','&&c != '\n') { strcat_s(buf, (const char*)&c); }
			else { break; }
		}

		//ここに来たら1セル文の文字が出来上がっているということ
		switch (col) {
		case 1: mStageData[row].mType = atoi(buf); break;				//種類
		case 2: mStageData[row].mBulletType = atoi(buf); break;			//弾種類
		case 3: mStageData[row].mBulletSpeed = atoi(buf); break;		//弾速度
		case 4: mStageData[row].mMotionType = atoi(buf); break;			//移動パターン
		case 5: mStageData[row].mShotType = atoi(buf); break;			//攻撃パターン
		case 6: mStageData[row].mInTime = atoi(buf); break;				//出現時間
		case 7: mStageData[row].mMoveTime = atoi(buf); break;			//移動時間
		case 8: mStageData[row].mStayTime = atoi(buf); break;			//滞在時間
		case 9: mStageData[row].mShotTime = atoi(buf); break;			//弾発射開始時間
		case 10: mStageData[row].mShootingTime = atoi(buf); break;		//弾発射時間
		case 11: mStageData[row].mX = atoi(buf); break;					//x座標
		case 12: mStageData[row].mY = atoi(buf); break;					//y座標
		case 13: mStageData[row].mHp = atoi(buf); break;				//体力
		case 14: mStageData[row].mItem = atoi(buf); break;				//アイテム
		}

		memset(buf, 0, sizeof(buf));	//バッファ初期化
		col++;							//列数を足す

		//もし読み込んだ文字が改行だったら列数を初期化し、行数を増やす
		if (c == '\n') {
			col = 1;
			++row;
		}
	}

out:	//ファイル読み込み終了
	fclose(fp);
	return;
}

ENEMY* File::storeStageData() {
	return mStageData;
}

int File::enemyNum() {
	return row+1;
}