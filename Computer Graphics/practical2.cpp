#include <graphics.h>
#include <iostream>

/*
Initial decision parameter: 3 - 2r

if dec param<0
	x = x+1
	y = y
	d = d+4x+6
else if dec param >= 0
	x = x+1
	y = y-1
	d = d + 4(x-y) + 10

and then plot the points with 8 way symmetry (add x coordinate of centre to putpixel x-coord and same for y-coord
*/

void plotPoint8way(int x, int y, int xc, int yc)
{
	putpixel(xc + x, yc + y, WHITE);
	putpixel(xc + x, yc - y, WHITE);
	putpixel(xc - x, yc + y, WHITE);
	putpixel(xc - x, yc - y, WHITE);
	putpixel(xc + y, yc + x, WHITE);
	putpixel(xc + y, yc - x, WHITE);
	putpixel(xc - y, yc + x, WHITE);
	putpixel(xc - y, yc - x, WHITE);
}

void drawCircle(int xc, int yc, int radius) {
  int x = 0;
  int y = radius;
  int d = 3 - (2 * radius);
  while (x<=y)
  {
  	plotPoint8way(x, y, xc, yc);
	if (d<0)
  	{
  		x++;
  		d = d + 4*x + 6;
	}
	else if (d>=0)
	{
		x++;
		y--;
		d = d + 4*(x - y) + 10;
	}
  }
}



int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  // User input for radius and center coordinates
  int radius, xc, yc;
  std::cout << "Enter radius: ";
  std::cin >> radius;
  std::cout << "Enter x coordinate of center: ";
  std::cin >> xc;
  std::cout << "Enter y coordinate of center: ";
  std::cin >> yc;

  drawCircle(xc, yc, radius);

  getch();
  closegraph();

  return 0;
}

