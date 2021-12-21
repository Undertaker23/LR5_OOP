#pragma once
#include "Point.h"

class Circle : public Point
{
protected:
	//������ �����
	float r;
public:
	//�����������  �� ��������� 
	Circle();

	//�����������  � �����������
	Circle(float a, float b, float rad);

	//����������� ����������� ( �.�. �������� � � � )
	Circle(Circle& point);

	float GetCh();

	//����� ����������� ������
	void Print();
	//������� ����� ����
	const string ClassName() override;

	//��������� �� ������������ �������� � ��������� �������� ������
	bool isA(string className) override;

	//������� ����� ����
	const char* GetType() override;

	void Modify() override;

	//����������
	~Circle() override;
};


