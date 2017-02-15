#include "FrameBuffer.h"


void FrameBuffer::setup()
{
	_img.allocate(1024, 768, ofImageType::OF_IMAGE_COLOR_ALPHA);
	clear(ofColor::black);
}

void FrameBuffer::update()
{

}

void FrameBuffer::draw()
{
	/*for (int y = 0; y < 768; ++y)
		putpixel(512, y, ofColor::red);*/
	/*for (int x = 0; x < 1024; ++x)
		putpixel(x, 384, ofColor::red);*/
}

void FrameBuffer::FASTputpixel(const int& x, const int& y, const ofColor color)
{
	_img.setColor(x, y, color);
}

void FrameBuffer::clear(const ofColor& color)
{
		for (int y = 0; y < 768; ++y)
			for (int x = 0; x < 1024; ++x)
				FASTputpixel(x, y, color);
		_img.update();
		_img.draw(ofPoint(0, 0, 0));
}

void FrameBuffer::line(int xo, int yo, int xi, int yi, const ofColor& color)
{
	int angle;
	int dy = yi - yo;
	int dx = xi - yi;
	int DNE = 2 * dy;
	int DE = 2 * (dy - dx);
	int d = 2 * dy - dx;
	int x = xo, y = yo;

		putpixel(xo, yo, ofColor::red);	
		
		if (dx > dy) {
			while (x <= xi)
			{
				x++;
				if (d <= 0)
				{
					d = d + DNE;
				}
				else
				{
					d = d + DE;
					y++;
				}
				putpixel(x, y, ofColor::blue);
			}
		}
		else if (dx <= dy) {
			while (y <= yi)
			{
				y++;
				if (d > 0)
				{
					d = d + dx - dy;
					x++;
				}
				else
				{
					d = d + dx;
				}
				putpixel(x, y, ofColor::blue);
			}
		}
		while (x <= xi)
		{
			y--;
			if (d < 0)
			{
				d = d + dx;
			}
			else
			{
				d = d - DNE;
				x++;
			}
			putpixel(x, y, ofColor::green);
		}
		while (y <= yi)
		{
			x--;
			if (d <= 0)
			{
				d = d - dy + DE;
				y++;
			}
			else
			{
				d = d - dy;
			}
			putpixel(x, y, ofColor::blue);
		}
		while (x <= xi)
		{
			x++;
			if (d > 0)
			{
				d = d + dx + DE + dy;
				y--;
			}
			else
			{
				d = d + dx + DNE - dy;
			}
			putpixel(x, y, ofColor::blue);
		}
}

void FrameBuffer::angle()
{
	int xc = 512;
	int yc = 384;
	int xo = 0;
	int yo = 0;

	for (float angle = 0; angle < 360; ++angle)
	{
		int xi = 100 * cos(angle*PI / 180.0);
		int yi = 100 * sin(angle*PI / 180.0);

		line(xo + xc, yo + yc, xi + xc, yi + yc, ofColor::blue);
	}
}

//void FrameBuffer::circle(const int& h, const int& k, const int& r)
//{
//	int x = 0;
//	int y = r;
//	int g = 1 - r;
//	int GE = 2; x + 3;
//	int GSE = 2; x - 2; y + 5;
//	
//	putpixel(y, x, ofColor::green);
//	putpixel(x, y, ofColor::green);
//	putpixel(-x, y, ofColor::green);
//	putpixel(-y, x, ofColor::green);
//	putpixel(-y, -x, ofColor::green);
//	putpixel(-x, -y, ofColor::green);
//	putpixel(x, -y, ofColor::green);
//	putpixel(y, -x, ofColor::green);
//
//	while (x!= y)
//	{
//		if (g < 0)
//		{
//			g += GE;
//		}
//		else
//		{
//			g += GSE;
//			--y;
//		}
//		++y;
//
//		putpixel(y, x, ofColor::green);
//		putpixel(x, y, ofColor::green);
//		putpixel(-x, y, ofColor::green);
//		putpixel(-y, x, ofColor::green);
//		putpixel(-y, -x, ofColor::green);
//		putpixel(-x, -y, ofColor::green);
//		putpixel(x, -y, ofColor::green);
//		putpixel(y, -x, ofColor::green);
//	} 
//
//}
//
//void FrameBuffer::moveTo(const int& Dx, const int& Dy)
//{
//	//currentPosition.Dx = x;
//	//currentPosition.Dy = y;
//}
//
//void FrameBuffer::lineTo(const int & Dx, const int & Dy)
//{
//	//line(currentPos.x, currentPos.y, Dx, Dy, current color);
//	//moveTo(x, y);
//}
//
//void FrameBuffer::setColor(const ofColor& color)
//{
//	//currentColor = color;
//}
//
//void FrameBuffer::triangle(const int& x0, const int& y0, const int& x1, const int& y1, const int& xs, const int& ys)
//{
//	int angle = 90;
//	int R = 300;
//	moveTo(R, 0);
//	for (int i = 0; i < 3; ++i) {
//		angle += 360.0 / (float)3;
//		int x = R * cos(angle*PI / 180.0);
//		int y = R * sin(angle*PI / 180.0);
//		lineTo(x, y);
//	}
//}

void FrameBuffer::putpixel(const int & x, const int & y, const ofColor color)
{
	_img.setColor(x, y, color);
	_img.update();
	_img.draw(ofPoint(0, 0, 0));
}



