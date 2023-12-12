#include <iostream>
#include <graphics.h>
#include <vector>
#include <cmath>
using namespace std;

//to draw a 2d shape and transform it.
/*
Translation is straightforward. Simply add Tx and Ty to the X and Y coordinates of the vertices
Same goes for scaling. just multiply the Sx and Sy scaling factors with the X and Y coordinates of the vertices.
For rotation use this formula on all vertices:
	theta = deg * 3.1415/180.0
	xnew = xcos(theta)-ysin(theta)
	ynew = xsin(theta)+ycos(theta)
*/
class Shape
{
	public:
		vector<int> xverts;
		vector<int> yverts;
		vector<int> xvertsTranslated;
		vector<int> yvertsTranslated;
		vector<int> xvertsScaled;
		vector<int> yvertsScaled;
		vector<int> xvertsRotated;
		vector<int> yvertsRotated;
		int vert;
		Shape(int v)
		{
			vert = v;
		}
		void acceptVert()
		{
			for (int i = 0; i<vert; i++)
			{
				int xtemp, ytemp;
				cout << "Enter x" << (i + 1) << " & y" << (i + 1) << endl;
				cin >> xtemp >> ytemp;
				xverts.push_back(xtemp);
				yverts.push_back(ytemp);
			}
		}
	void drawShape(vector<int> xv, vector<int>yv)
	{
		for (int i = 0; i<(vert-1); i++)
		{
			line(xv[i],yv[i],xv[i+1],yv[i+1]);
		}
		line(xv[vert-1],yv[vert-1],xv[0],yv[0]);
	}
	void translate(int tx, int ty)
	{
		for (int i = 0; i<vert; i++)
		{
			xvertsTranslated.push_back(xverts[i] + tx);
			yvertsTranslated.push_back(yverts[i] + ty);
		}
	}
	void scale(float sx, float sy)
	{
		for (int i = 0; i<vert; i++)
		{
			xvertsScaled.push_back(xverts[i] * sx);
			yvertsScaled.push_back(yverts[i] * sy);
		}
	}
	void rotate(double deg)
	{
		double radians = deg * 3.14159 / 180.0;
		for (int i = 0; i<vert; i++)
		{
			int newX = round(xverts[i] * cos(radians) - yverts[i] * sin(radians));
    		int newY = round(xverts[i] * sin(radians) + yverts[i] * cos(radians));
			xvertsRotated.push_back(newX);
			yvertsRotated.push_back(newY);
		}
	}
};

int main()
{
	int gd = DETECT,gm;
	initgraph(&gd, &gm, NULL);
	cout << "Enter the number of vertices: " << endl;
	int vert;
	cin >> vert;
	Shape s1(vert);
	s1.acceptVert();
	s1.drawShape(s1.xverts, s1.yverts);
	cout << "Enter translation values (tx,ty): " << endl;
	int transx, transy;
	cin >> transx >> transy;
	s1.translate(transx, transy);
	cleardevice();
	s1.drawShape(s1.xvertsTranslated, s1.yvertsTranslated);
	cout << "Enter scaling values (sx,sy): " << endl;
	float scalex, scaley;
	cin >> scalex >> scaley;
	s1.scale(scalex, scaley);
	cleardevice();
	s1.drawShape(s1.xvertsScaled, s1.yvertsScaled);
	cout << "Enter the angle by which to rotate the shape: (degrees)" << endl;
	double deg;
	cin >> deg;
	cleardevice();
	s1.rotate(deg);
	s1.drawShape(s1.xvertsRotated, s1.yvertsRotated);
	delay(5000);
	closegraph();
}
