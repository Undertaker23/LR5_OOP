#include "pch.h"
#include "Point.h"
#include <iostream>
using namespace std;
// ����������� ��� point �� ���������
Point::Point()
{
	x = 0;
	y = 0;
	cout << "������ ����������� �� ��������� ������ Point : Point()" << endl;
}

Point::Point(float a, float b)
{
	x = a;
	y = b;
	cout << "������ ����������� � ����������� ������ Point :  Point(" << x << ", " << y << ")" << endl;
}

Point::Point(Point& point)
{
	x = point.x;
	y = point.y;
	cout << "������ ����������� ����������� ������ Point :   Point (Point& point)" << endl;
}

void Point::Move(float dx, float dy)
{
	x = x + dx;
	y = y + dy;
	cout << "������ ����� Move ������ Point" << endl;
}

void Point::Print()
{
	cout << "�������� � : " << x << " || �������� � : " << y;
}


//�������� �������� 
void Point::Modify()
{
	cout << "  x = ";
	cin >> x;
	cout << "  y = ";
	cin >> y;
}


void Point::SetXY(float a, float b)
{
	x = a;
	y = b;
	cout << "������ ����������� ����� SetXY(" << a << "," << b << ") ������ Point" << endl;
}


float Point::GetX() {
	return x;
}

//������� ����� ����
const char* Point::GetType()
{
	return "Point";
}

//������� ����� ����
const string Point::ClassName()
{
	return "Point";
}

void Point::SetX(float a)
{
	x = a;
}

void Point::SetY(float b)
{
	x = b;
}

void Point::funcc(const Point* const point)
{
	cout << "point->x = " << point->x << endl;
	cout << "point->y = " << point->y << endl;
}

//��������� �� ������������ �������� � ��������� �������� ������
bool Point::isA(string className)
{

	if (className.compare("Point") == 0)
		return true;

	return false;
}

float Point::GetY()
{
	return y;
}


Point::~Point()
{
	cout << "������ ���������� ������ Point" << endl;
}

