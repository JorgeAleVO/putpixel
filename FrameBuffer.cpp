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

void FrameBuffer::line(int xo, int yo, int xi, int yi)
{
	int d = 0;
	int dy = (yi - yo);
	int dx = (xi - xo);
	int DNE = dy;
	int DE = (dy - dx);
	
	int x = xo, y = yo;


	if (yi >= yo && xi >= xo)
	{
		if (dx > dy)
		{
			for (int x = xo; x <= xi; x++)
			{
				ofColor color(255, 100, 255);
				putpixel(x, y, color);

				if (d > 0) {
					d = d + DE;
					y++;
				}
				else
				{
					d = d + DNE;

				}

			}
		}
		else if (dy >= dx)
		{
			for (int y = yo; y <= yi; y++) {
				{
					ofColor color(255, 100, 255);
					putpixel(x, y, color);
					if (d > 0)
					{
						d = d + dx - DNE;
						x++;
					}
					else
					{
						d = d + dx;
					}
				}
			}
		}
	}

	else if (yi <= yo && xi <= xo)
	{
		if (dy  > dx)
		{
			for (int x = xo; x >= xi; x--)
			{
				ofColor color(0, 255, 255);
				putpixel(x, y, color);
				if (d <= 0)
				{
					d = d + DE;
					y--;
				}
				else
				{
				 d = d + DNE;
				}

			}
		}
		else if (dy <= dx)
		{
			for (int y = yo; y >= yi; y--)
			{
				ofColor color(100, 0, 255);
				putpixel(x, y, color);
				if (d <= 0)
				{
					d = d + dx - dy;
					x--;
				}
				else
				{
				 d = d + dx;
				}

			}
		}
	}

	else if (yi >= yo && xi <= xo)
	{
		if (dx > dy *-1)
		{
			for (int y = yo; y <= yi; y++)
			{
				ofColor color(255, 0, 100);
				putpixel(x, y, color);
				if (d <= 0)
				{
					d = d + dx + dy;
					x--;
				}
				else
				{
					d = d + dx;
				}

			}
		}
		else if (dx <= dy *-1)
		{
			for (int x = xo; x >= xi; x--)
			{
				ofColor color(255, 0, 0);
				putpixel(x, y, color);

				if (d < 0)
				{
					d = d - dx - dy;
					y++;
				}

				else
				{
					d = d - dy;


				}

			}
		}
	}


	else if (yi < yo && xi > xo)
	{
		if (dx * -1 >= dy) {
			for (int y = yo; y >= yi; y--)
			{
				ofColor color(0, 100, 255);
				putpixel(x, y, color);
				if (d > 0)
				{
					d = d + dx +DNE;
					x++;
				}
				else
				{
					d = d + dx;

				}

			}
		}
		else if (dy >= dx*-1) {
			for (int x = xo; x <= xi; x++)
			{
				ofColor color(0, 100, 255);
				putpixel(x, y, color);
				if (d > 0)
				{
					d = d - dy - dx;
					y--;
				}
				else
				{
					d = d - dy ;
				}

			}
		}
	}
}

void FrameBuffer::angle()
{
	int xc = ofGetWidth() / 2;
	int yc = ofGetHeight() / 2;
	int xo = 0;
	int yo = 0;

	for (float angle = 0; angle < 360; ++angle)
	{
		int xi = 100 * cos(angle*PI / 180.0);
		int yi = 100 * sin(angle*PI / 180.0);

		line(xo + xc, yo + yc, xi + xc, yi + yc);
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
// ofColor color ( 0, 100, 255);
//	
//	putpixel(y, x, color);
//	putpixel(x, y, color);
//	putpixel(-x, y, color);
//	putpixel(-y, x, color);
//	putpixel(-y, -x, color);
//	putpixel(-x, -y, color);
//	putpixel(x, -y, color);
//	putpixel(y, -x, color);
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
//		putpixel(y, x, color);
//		putpixel(x, y, color);
//		putpixel(-x, y, color);
//		putpixel(-y, x, color);
//		putpixel(-y, -x, color);
//		putpixel(-x, -y, color);
//		putpixel(x, -y, color);
//		putpixel(y, -x, color);
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



