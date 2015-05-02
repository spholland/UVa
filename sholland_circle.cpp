// Steven Holland
// UVa 190 Circle Through Three Points

// For this problem we need to find the center and radius of a circle
// when given three points that lie on the radius of the circle. 


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

// Distance formula
double findDist(double x1, double y1, double x2, double y2) {
	double D = sqrt(pow(x2 + x1, 2) + pow(y2 + y1, 2));
	return D;
}

// My method for finding the middle of the circle
pair<double, double> findMid(double x1, double y1, double x2, double y2, double x3, double y3) {
	pair<double, double> res;

	// Slopes of lines between points
	double mr = 0;
	double mt = 0;


	// Midpoints of the line segments
	pair<double, double> midab;
	pair<double, double> midbc;

	midab.first = (x1 + x2) / 2;
	midab.second = (y1 + y2) / 2;

	midbc.first = (x2 + x3) / 2;
	midbc.second = (y2 + y3) / 2;

	// Coordinates of center of the circle
	double xcoord = 0;
	double ycoord = 0;

	// Slopes of lines that intersect the midpoint of each of the line segments
	double m1 = (y2 - y1) / (x2 - x1);
	double m2 = (y2 - y3) / (x2 - x3);
	mr = -1 / m1;
	mt = -1 / m2;

	// Y-intercepts of these lines that intersect the middle of each of the line segments
	double b1 = ((-midab.first) * mr) + midab.second;
	double b2 = ((-midbc.first) * mt) + midbc.second;

	// (x,y) coordinates of the center of the circle
	xcoord = (b2 - b1) / (mt - mr);
	ycoord = (mr*xcoord) - b1;

	res.first = xcoord;
	res.second = ycoord;

	return res;
}


int main() {
	freopen("input.txt", "r", stdin);
	double Ax, Ay, Bx, By, Cx, Cy;

	int temp = 0;

	while (cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy){

		// This adds the endline to put the code in the correct format
		if (temp != 0) {
			cout << endl;
		}
		temp++;

		pair<double, double> center;

		center = findMid(Ax, Ay, Bx, By, Cx, Cy);

		double r;
		r = findDist(center.first,center.second,Ax,Ay);

		// Prints out answer in equation (x + h)^2 + (y + k)^2 = r^2
		if (center.first < 0) {
			cout << "(x - ";
			printf("%.3f", 0 - center.first);
			cout << ")^2 + ";
		}
		if (center.first > 0) {
			cout << "(x + ";
			printf("%.3f", center.first);
			cout << ")^2 + ";
		}
		if (center.second < 0) {
			cout << "(y - ";
			printf("%.3f", 0 - center.second);
			cout << ")^2 = ";
		}
		if (center.second > 0) {
			cout << "(y + ";
			printf("%.3f", center.second);
			cout << ")^2 = ";
		}
		printf("%.3f", r);
		cout << "^2" << endl;

		// Prints out answer in equation x^2 + y^2 + Cx + Dy + E = 0;
		double c = center.first * 2;
		double d = center.second * 2;
		double e = pow(center.first, 2) + pow(center.second, 2) - pow(r, 2);

		cout << "x^2 + y^2 ";
		if (c < 0) {
			cout << "- ";
			printf("%.3f", 0 - c);
			cout << "x ";
		}
		if (c > 0) {
			cout << "+ ";
			printf("%.3f", c);
			cout << "x ";
		}
		if (d < 0) {
			cout << "- ";
			printf("%.3f", 0 - d);
			cout << "y ";
		}
		if (d > 0) {
			cout << "+ ";
			printf("%.3f", d);
			cout << "y ";
		}
		if (e < 0) {
			cout << "- ";
			printf("%.3f", 0 - e);
			cout << " = 0" << endl;
		}
		if (e > 0) {
			cout << "+ ";
			printf("%.3f", e);
			cout << " = 0" << endl;
		}

	}
	return 0;
}