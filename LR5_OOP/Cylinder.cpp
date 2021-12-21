#include "pch.h"
#include "Cylinder.h"
#include <iostream>
using namespace std;

Cylinder::Cylinder() : Circle(), h(0)
{
	cout << "������ ����������� �� ��������� ������ Cylinder : Cylinder()" << endl;
}

Cylinder::Cylinder(float a, float b, float rad, float he) : Circle(a, b, rad), h(he)
{
	cout << "������ ����������� � ����������� ������ Circle : Circle(" << x << ", " << y << "," << rad << "," << he << ")" << endl;
}

Cylinder::Cylinder(Cylinder& cylinder) : Circle(cylinder), h(cylinder.h)
{
	cout << "������ ����������� ����������� ������ Cylinder : Cylinder (Cylindert& cylinder)" << endl;
}

void Cylinder::Print()
{
	Circle::Print();
	cout << "|| �������� h : " << h;
}

void Cylinder::Modify()
{
	Circle::Modify();
	cout << " ||  h = ";
	cin >> h;
}

//������� ����� ����
const string Cylinder::ClassName()
{
	return "Cylinder";
}

//��������� �� ������������ �������� � ��������� �������� ������
bool Cylinder::isA(string className)
{


	//��������� � ��������� ������ Circle
	if (className.compare("Cylinder") == 0)
		return true;

	return Circle::isA(className);
}

float Cylinder::GetCh()
{
	cout << "������ ����� Get�h ������ Cylinder" << endl;
	return h * 3, 14 * r * r;
}

const char* Cylinder::GetType()
{
	return "Cylinder";
}

float Cylinder::GetH()
{
	return h;
}

void Cylinder::SetH(float he)
{
	h = he;
}

Cylinder::~Cylinder()
{
	cout << "������ ���������� ������ Cyliner" << endl;
}