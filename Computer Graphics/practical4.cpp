//cohen southerland line clipping
/*
intersection formulae

with top:
y = ymax
x = x1 + (ymax - y1)/m

with bottom:
y = ymin
x = x1 + (ymin - y1)/m

with left
x = xmin
y = y1 + (xmin - x1) * m

with right
x = xmax
y = y1 + (xmax - x1) * m
*/
#include <iostream>
#include <graphics.h>

using namespace std;

int xmin, ymin, xmax, ymax;
static int TOP = 8;
static int BOTTOM = 4;
static int RIGHT = 2;
static int LEFT = 1;

int getcode(int x, int y)
{
	int code = 0;
	if (x>xmax)
		code = RIGHT;
	if (x<xmin)
		code = LEFT;
	if (y>ymax)
		code = TOP;
	if (y<ymin)
		code = BOTTOM;
	return code;
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	cout << "Enter the bounds of the window: (xmin,ymin)(xmax,ymax)" << endl;
	cin >> xmin >> ymin >> xmax >> ymax;
	cout << "Enter the coordinates of the line: (x1, y1)(x2, y2)" << endl;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	line(x1,y1,x2,y2);
	rectangle(xmin,ymin,xmax,ymax);
	cout << "Shapes drawn. We will clip after 5 seconds delay." << endl;
	delay (5000);
	cleardevice();
	int outcode1 = getcode(x1, y1);
	int outcode2 = getcode(x2, y2);
	if (outcode1 == 0 && outcode2 == 0)
	{
		cout << "The line is completely inside the window. No need to clip." << endl;
		return 0;
	}
	else
	{
		float m = (y2 - y1)/(x2 - x1);
		float x, y;
		if (outcode1 == 0 && outcode2!=0)
		{
			if (outcode2 == 1)
			{
				//point 1 inside and point 2 is at left of window.
				x = xmin;
		        y = y2 + (xmin - x2) * m;	
			}
			if (outcode2 == 2)
			{
				//point 1 inside and point 2 is at right of window.
				x = xmax;
		        y = y2 + (xmax - x2) * m;	
			}
			if (outcode2 == 4)
			{
				//point 1 inside and point 2 is at bottom of window.
				x = x2 + (ymin - y2)/m;
		        y = ymin;	
			}
			if (outcode2 == 8)
			{
				//point 1 inside and point 2 is at top of window.
				x = x2 + (ymax - y2)/m;
		        y = ymax;	
			}
			cout << "Intersection point is ("<<x<<","<<y<<")"<<endl;
	        rectangle(xmin, ymin, xmax, ymax);
	        setcolor(RED);
	        line(x1, y1, x, y);	
		}
		if (outcode1!=0 && outcode2==0)
		{
			if (outcode1 == 1)
			{
				//point 1 at left and point 2 is inside.
				x = xmin;
		        y = y1 + (xmin - x1) * m;
			}
			if (outcode1 == 2)
			{
				//point 1 at right and point 2 is inside.
				x = xmax;
		        y = y1 + (xmax - x1) * m;
			}
			if (outcode1 == 4)
			{
				//point 1 at bottom and point 2 is inside.
				x = x1 + (ymin - y1)/m;
		        y = ymin;
			}
			if (outcode1 == 8)
			{
				//point 1 at top and point 2 is inside.
				x = x1 + (ymax-y1)/m;
		        y = ymax;
			}
			cout << "Intersection point is ("<<x<<","<<y<<")"<<endl;
	        rectangle(xmin, ymin, xmax, ymax);
	        setcolor(RED);
	        line(x, y, x2, y2);
		}
	}
	delay(5000);
	closegraph();	
}
