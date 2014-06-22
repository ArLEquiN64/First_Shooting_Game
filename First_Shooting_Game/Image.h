#ifndef INCLUDED_IMAGE_H
#define INCLUDED_IMAGE_H

class Image{
public:
	Image(const char* filename,double extendRate=1.0);
	~Image();
	int width() const;
	int height() const;
	void draw(int x = 0, int y = 0, int i = 0) const;
	void rotationDraw(int x =0,int y=0,int i=0, double angle=0) const;
	void setDivGraph(int rectX, int rectY, int sizeX, int sizeY, int xNum, int yNum);
	void setAnimetion();
private:
	const char* mFileName;
	int mBaseHandle;
	int mBaseWidth;
	int mBaseHeight;
	int mBuffHandle;
	bool mDivFlag;
	int* mDivHandle;
	int mDivNum;
	int mDivWidth;
	int mDivHeight;
	double mExtendRate;
};

#endif