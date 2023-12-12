//DDA Line Algorithm
/*
find steps = max(abs(dx),abs(dy)) + 1
Conditions:
1. ((dx > dely) && (x1 < x2) && (m<1))
	x = x + 1
	y = y + m
2. ((dx > dely) && (x1 > x2) && (m<1))
	x = x - 1
	y = y - m
3. ((dx < dely) && (y1 < y2) && (m>1))
	x = x + 1/m
	y = y + 1
4. ((dx < dely) && (y1 > y2) && (m>1))
	x = x - 1/m
	y = y - 1
*/

#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
	float x1, x2, y1, y2;
	cout << "Enter x1: " << endl;
	cin >> x1;
	cout << "Enter y1: " << endl;
	cin >> y1;
	cout << "Enter x2: " << endl;
	cin >> x2;
	cout << "Enter y2: " << endl;
	cin >> y2;
	
	float dx = x2 - x1;
	float dely = y2 - y1;
	
	float m = dely / dx;
	int steps = max(abs(dx),abs(dely)) + 1;
	float xpoints[steps], ypoints[steps];
	xpoints[0] = x1;
	ypoints[0] = y1;
	if ((x1==x2)&&(y1==y2))
	{
		cout << "Both points are same so no line can be drawn." << endl;
		return 0;
	}
	else
	{
		cout << "The slope of the line is " << m << endl;
		if ((x1<x2)&&(m<1)&&(dx>dely))
		{
			float xcurr = x1, ycurr = y1;
			for (int i = 1; i<steps; i++)
			{
				xpoints[i] = xcurr+1;
				xcurr = xcurr + 1;
				ypoints[i] = ycurr+m;
				ycurr = ycurr + m;
			}
		}
		if ((x1>x2)&&(m<1)&&(dx>dely))
		{
			float xcurr = x1, ycurr = y1;
			for (int i = 1; i<steps; i++)
			{
				xpoints[i] = xcurr-1;
				xcurr = xcurr - 1;
				ypoints[i] = ycurr - m;
				ycurr = ycurr - m;
			}
		}
		if ((y1 < y2)&&(m>1)&&(dely>dx))
		{
			float xcurr = x1, ycurr = y1;
			for (int i = 1; i<steps; i++)
			{
				xpoints[i] = xcurr + 1/m;
				xcurr = xcurr + 1/m;
				ypoints[i] = ycurr + 1;
				ycurr = ycurr + 1;
			}
		}
		if ((y1 > y2)&&(m>1)&&(dely>dx))
		{
			float xcurr = x1, ycurr = y1;
			for (int i = 1; i<steps; i++)
			{
				xpoints[i] = xcurr - 1/m;
				xcurr = xcurr - 1/m;
				ypoints[i] = ycurr - 1;
				ycurr = ycurr - 1;
			}
		}
	}
	for (int i = 0; i<steps; i++)
	{
		cout << "(" << xpoints[i] << "," << ypoints[i] << ")" << endl;
		putpixel(xpoints[i] , ypoints[i], RED);
	}
	delay (50000);
	getch();
	closegraph();
}
