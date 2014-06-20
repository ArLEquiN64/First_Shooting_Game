#ifndef INCLUDED_ENEMY_H
#define INCLUDED_ENEMY_H

#define ENEMY_NUM 10	//���ƂłȂ�Ƃ�����

class Image;
class E_Shot;

struct ENEMY {
	int mType;				//���
	int mBulletType;		//�e���
	int mBulletSpeed;		//�e���x
	int mMotionType;		//�ړ��p�^�[��
	int mShotType;			//�U���p�^�[��
	int mInTime;			//�o������
	int mMoveTime;			//�ړ�����
	int mStayTime;			//�؍ݎ���
	int mShotTime;			//�e���ˊJ�n����
	int mShootingTime;		//�e���ˎ���
	int mX;					//x���W
	int mY;					//y���W
	int mHp;				//�̗�
	int mItem;				//�A�C�e��

	int mWidth;				//��
	int mHeight;			//����
	int mHitArea;			//�����蔻��
	int mDirection;			//N:0, L:1, R:2

	bool mLive;				//�o���t���O

	Image* mImage;
	E_Shot* mShot;
};

class Enemy{
public:
	Enemy();
	~Enemy();
	void update();
	void draw();

private:
	int mEnemyNum;
	ENEMY mEnemy[ENEMY_NUM];

	void move(int i);
	bool checkOutOfField(int i);
	void drawScreen(int x, int y, int direction) const;
};

#endif