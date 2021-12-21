#include "pch.h"
#include "Scope.h"
#include <iostream>
using namespace std;

Scope::Scope()
{
	cout << "������ ����������� �� ��������� ������ Scope : Scope()" << endl;
}

Scope::Scope(float a, float b, float ze, float rad) : Point(a, b), z(ze), r(rad)
{
	cout << "������ ����������� � ����������� ������ Scope : Scope()" << endl;
}

Scope::Scope(Scope& scope) : Point(scope), z(scope.z)
{
	cout << "������ ����������� ����������� ������ Scope : Scope (Scope& scope)" << endl;
}

void Scope::Print()
{
	Point::Print();
	cout << " ||  �������� r : " << r << " || �������� z : " << z;

}

void Scope::Modify()
{
	Point::Modify();
	cout << "  Radius = ";
	cin >> r;
	cout << "  z = ";
	cin >> z;
}

const char* Scope::GetType()
{
	return "Scope";
}

float Scope::GetZ() {
	return z;
}

void Scope::SetZ(float ze) {
	z = ze;
}

float Scope::GetRadius() {
	return r;
}

const string Scope::ClassName()
{
	return "Scope";
}


//��������� �� ������������ �������� � ��������� �������� ������
bool Scope::isA(string className)
{

	//��������� � ��������� ������ Circle
	if (className.compare("Scope") == 0)
		return true;

	return Point::isA(className);
}


void Scope::SetRadius(float rad) {
	r = rad;
}

Scope::~Scope()
{
	cout << "������ ���������� ������ Scope" << endl;
}
