#pragma once
#include "ofMain.h"


class FrameBuffer {
public:


	void setup();
	void update();
	void draw();
	void putpixel(const int& x, const int& y, const ofColor color);
	
	void clear(const ofColor& color);
	void line(int xo, int yo, int xi, int yi);
	void angle();
	/*void circle(const int& h, const int& k, const int& r);
	void moveTo(const int& Dx, const int& Dy);
	void lineTo(const int& Dx, const int& Dy);
	void setColor(const ofColor& color);
	void triangle(const int& x0, const int& y0, const int& x1, const int& y1, const int& xs, const int& ys);*/
	

private:
	ofImage _img;
	void FASTputpixel(const int& x, const int& y, const ofColor color);
};