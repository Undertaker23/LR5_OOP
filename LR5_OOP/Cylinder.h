#pragma once
#include "Circle.h"
class Cylinder : public Circle
{
private:
	float h;
public:
	//����������� �� ��������� ��� ������ Cylinder
	Cylinder();

	//����������� � ����������� ��� ������ Cylinder
	Cylinder(float a, float b, float rad, float he);

	//����������� ����������� ( �.�. �������� � � � )
	Cylinder(Cylinder& cylinder);

	//����� ����������� ������
	void Print();

	void Modify() override;
	// ����������� ����� Circle
	float GetCh();

	//������� ����� ����
	const string ClassName() override;

	//��������� �� ������������ �������� � ��������� �������� ������
	bool isA(string className) override;

	//������� ����� ����
	const char* GetType() override;

	//��������� ������ 
	float GetH();

	//��������� ������
	void SetH(float he);


	~Cylinder()override;
};


