/*
key codes:
72 - up arrow
80 - down arrow
77 - right arrow
75 - left arrow
*/

#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int i = 250, j = 250;
	int x = 0, y = -1, ch;
	while(1)
	{
		circle(i, j, 50);
		if (kbhit())
		{
			ch = getch();
			if(ch==KEY_UP)
			{
				x = 0;
				y = -5;
				cout << "UP" << endl;
			}
			if(ch==KEY_DOWN)
			{
				x = 0;
				y = 5;
				cout << "DOWN" << endl;
			}
			if (ch==KEY_RIGHT)
			{
				x = 5;
				y = 0;
				cout << "RIGHT" << endl;
			}
			if (ch==KEY_LEFT)
			{
				x = -5;
				y = 0;
				cout << "LEFT" << endl;
			}
			i = i + x;
			j = j + y;
			cleardevice();
		}
	}
}
