//rewrite with DDA line and bresenham circle

#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd, &gm, NULL);
	int x1,y1,x2,y2,x3,y3;
	cout << "Enter the coordinates of vertices of triangle: (x1,y1), (x2,y2), (x3,y3)" << endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	line (x1, y1, x2, y2);
	line (x2, y2, x3, y3);
	line (x3, y3, x1, y1);
	float circumcentrex = (((pow(x1,2)+pow(y1,2))*(y2-y3))+((pow(x2,2)+pow(y2,2))*(y3-y1))+((pow(x3,2)+pow(y3,2))*(y1-y2)))/(2*((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2))));
	float circumcentrey = (((pow(x1,2)+pow(y1,2))*(x3-x2))+((pow(x2,2)+pow(y2,2))*(x1-x3))+((pow(x3,2)+pow(y3,2))*(x2-x1)))/(2*((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2))));
	float circumradius = pow((pow((x1 - circumcentrex),2)+pow((y1 - circumcentrey),2)),0.5);
	circle (circumcentrex, circumcentrey, circumradius);
	
	double a = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double b = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    double c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double perimeter = a + b + c;
    double Ix = (a * x1 + b * x2 + c * x3) / perimeter;
    double Iy = (a * y1 + b * y2 + c * y3) / perimeter;
    // Calculate the inradius
    double s = perimeter / 2;  // semi-perimeter
    double area = sqrt(s * (s - a) * (s - b) * (s - c));  // Heron's formula
    double inradius = area / s;
    circle (Ix, Iy, inradius);
	delay(5000);
	closegraph();
}
