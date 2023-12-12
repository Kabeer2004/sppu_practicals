/*
COLOR               INT VALUES
-------------------------------
BLACK                   0
BLUE                    1
GREEN                   2
CYAN                    3   
RED                     4
MAGENTA                 5
BROWN                   6 
LIGHTGRAY               7 
DARKGRAY                8
LIGHTBLUE               9
LIGHTGREEN             10
LIGHTCYAN              11
LIGHTRED               12
LIGHTMAGENTA           13
YELLOW                 14
WHITE                  15

PATTERN              INT VALUES
-------------------------------
EMPTY_FILL               0
SOLID_FILL               1
LINE_FILL                2
LTSLASH_FILL             3   
SLASH_FILL               4
BKSLASH_FILL             5
LTBKSLASH_FILL           6 
HATCH_FILL               7 
XHATCH_FILL              8
INTERLEAVE_FILL          9
WIDE_DOT_FILL           10
CLOSE_DOT_FILL          11
USER_FILL               12
*/

#include<iostream>
#include<graphics.h>

using namespace std;

void mountain(int x, int y, int width, int height)
{
	line (x,y,(x+width/2),y-height);
	line ((x+width/2),y-height, x+width, y);
	line (x+width, y, x, y);
	setfillstyle(SOLID_FILL,BROWN); 
	floodfill (x+width/2, y-height/2, WHITE);
}

void sun(int height)
{
	setcolor(BLACK);
	circle(300,300 - height,50);
	setfillstyle(SOLID_FILL, YELLOW);
	if (height>0)
		floodfill(300,300 - height,BLACK);
}

void drawscene(int sunstate)
{
	if (sunstate == 1)
	{
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		floodfill (1, 1, BLACK);
		floodfill(50,50, WHITE);
		mountain(100,300,200,200);
		mountain(275,300,200,150);
		rectangle(0,300,800,800);
		setfillstyle(SOLID_FILL, GREEN);
		floodfill(1,301,WHITE);
		sun(150);
	}
	else if (sunstate == 0)
	{
		setfillstyle(SOLID_FILL, BLACK);
		floodfill (1, 1, BLACK);
		floodfill(50,50, WHITE);
		mountain(100,300,200,200);
		mountain(275,300,200,150);
		rectangle(0,300,800,800);
		setfillstyle(SOLID_FILL, GREEN);
		floodfill(400,400,WHITE);
	}
}

int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int choice;
	cout << "1. Sunrise" << endl;
	cout << "2. Sunset" << endl;
	cin >> choice;
	switch(choice)
	{
		case 1:
			drawscene(1);
			break;
		case 2:
			drawscene(0);
			break;
		default:
			cout << "Invalid Input" << endl;
	}
	delay(50000);
	cleardevice();
	closegraph();
}
