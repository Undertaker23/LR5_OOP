#pragma once
#include <string>

using std::string;
class Point {

protected:
	//���������� �����
	float x, y;

public:
	//�����������  �� ��������� 
	Point();

	//�����������  � �����������
	Point(float a, float b);

	//����������� ����������� ������ Point ( �.�. �������� � � � )
	Point(Point& point);

	//����������� �����
	void Move(float dx, float dy);

	//������� ���� (����� ������ ���������)
	virtual const char* GetType();

	//�������� �������� �����
	virtual void Modify();

	//������� ����� ����
	virtual const string  ClassName();
	//��������� �� ������������ �������� � ��������� �������� ������

	virtual bool isA(string className);

	//����� ����������� ������
	virtual void Print();

	//������ ����� ���������� � ������� ������������ ������
	virtual void SetXY(float a, float b);

	void SetX(float a);

	static void funcc(const Point* const point);

	void SetY(float b);

	//�������� �������� � 
	float GetX();

	//�������� �������� �
	float GetY();

	//����������
	virtual ~Point();
};


