#include "pch.h"
#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle() : Point(), r(0)
{
	cout << "������ ����������� �� ��������� ������ Circle : Circle()" << endl;
}

Circle::Circle(float a, float b, float rad) : Point(a, b), r(rad)
{
	cout << "������ ����������� � ����������� ������ Circle : Circle(" << x << ", " << y << "," << rad << ")" << endl;
}

Circle::Circle(Circle& circle) : Point(circle), r(circle.r)
{
	cout << "������ ����������� ����������� ������ Circle : Circle (Circle& circle)" << endl;
}

float Circle::GetCh()
{
	cout << "������ ����� Get�h ������ Circle" << endl;
	return 3, 14 * r * r;
}

void Circle::Modify()
{
	Point::Modify();
	cout << "  Radius = ";
	cin >> r;
}

const string Circle::ClassName()
{
	return "Circle";
}


//��������� �� ������������ �������� � ��������� �������� ������
bool Circle::isA(string className)
{

	//��������� � ��������� ������ Circle
	if (className.compare("Circle") == 0)
		return true;

	return Point::isA(className);
}



void Circle::Print()
{
	Point::Print();
	cout << " || �������� r : " << r;
}

const char* Circle::GetType()
{
	return "Circle";
}


Circle::~Circle()
{
	cout << "������ ���������� ������ Circle" << endl;
}
