#include "Node.h"
#include "iostream"
#pragma once

using namespace std;

template <class T>
class LinkedList {

private:

	//������� ������������ ������� ������
	Node<T>* current;


	//����� ����������
	int length;

	//��������� �� ������ ������� ������
	Node<T>* first;

	//���������� �������� ����� ����������
	void SetLength(int _length);

	//�������� ������ �� ��������� ������� ������
	Node<T>* GetLast();



public:

	//����������� �� ���������
	LinkedList();

	//�������� �������� �������� ���������������� ��������
	void Set();

	//�������� ����� �������� ����������������
	void AddAfter(T* value);

	//�������� ����� ������� ���������������
	void AddBefore(T* value);

	//������� ������� ������� �� ������
	void Delete();

	//������ � ���������� � ���������� �������
	void MoveNext();

	//������ � ����������� � ���������� �������
	void MovePrev();

	//������� � ������� �������� ������
	void MoveFirst();

	//������� ����� �� ����� ������
	bool GetEOL();

	//����� ������
	int GetLength();

	//�������� �������� �������� �������������
	T* GetValue();

	//�������� ������ �� ������� ������������
	Node<T>* GetCurrent();

	//���������� �������� �������� ��������
	void SetCurrent(Node<T>* current);

	//����������
	~LinkedList();
};

template <class T>
//����������� �� ���������
LinkedList<T>::LinkedList() {

	length = 0;

	//��������� �������� ��������� ������ 0
	current = NULL;

	cout << "������ ����������� �� ��������� ������ LinkedList" << endl;
}

template <class T>
//���������� ��������� �������� �������� ����� ������
void LinkedList<T>::SetLength(int _length)
{

	//������ ( �.�. � ��� ����� ���� ������ >0 )
	if (_length >= 0) {
		length = _length;
	}
	else {
		//���������� �����
		cout << "������� ��������� �������������� �������� ����� LinkedList " << endl;
		length = 0;
	}
}

template <class T>
//�������� ����� ���������� � ������
Node<T>* LinkedList<T>::GetLast() {

	return first->GetPrev();
}

template <class T>
//������� ����� �� ����� ������
bool LinkedList<T>::GetEOL() {

	if (length == 0)
		return true;

	//���� ������ ���������������� �������� ����� ����� ������, �� ������ true
	return current->GetNext() == first;
}

template <class T>
//�������� �������� ����� �������� ���������������� ��������
void LinkedList<T>::AddAfter(T* obj) {

	// � ������, ���� ������ ����
	//������ �������� current
	if (length == 0) {

		//������� ����� ����
		current = new Node<T>();

		//������� ������� ������������ ������ ����� ������
		first = current;

		//�������� next �� ������ ����, ����� ���������� ��������������� ���������
		current->SetNext(current);

		//�������� prev �� ������ ����, ����� ���������� ��������������� ���������
		current->SetPrev(current);

		//���������� � current ��������
		current->SetValue(obj);

		//����� ���������� � ����� ������ 
		SetLength(length + 1);

		return;
	}

	//�������� ����� ��������, �������� �� ������� � ������ ������
	Node<T>* oldNext = current->GetNext();

	//����������� ���
	Node<T>* addedNode = new Node<T>(current, obj, oldNext);

	//������� ����� ������ ������������ ���� � ���� next �������� ������������� ����
	current->SetNext(addedNode);

	//������� ����� ������ ������������ ���� � ���� prev ��������� �� ����� addedNode ����
	oldNext->SetPrev(addedNode);

	//����� ���������� 
	SetLength(length + 1);

	//����������� ������ ���������� �������
	current = addedNode;
}

template <class T>
void LinkedList<T>::AddBefore(T* obj) {
	// ���� �� ������ �� ��������� ��� � ������
	if (length == 0) {
		AddAfter(obj);
		return;
	}

	//�������� ����� ��������, �������� �� ������� � ������ 
	Node<T>* oldPrev = current->GetPrev();

	//����������� ����
	Node<T>* addedNode = new Node<T>(oldPrev, obj, current);

	//������� ����� ������ ������������ ���� � ���� next �������� ������������� ����
	current->SetPrev(addedNode);

	//������� ����� ������ ������������ ���� � ���� prev ��������� �� ����� addedNode ����
	oldPrev->SetNext(addedNode);

	//����� ���������� 
	SetLength(length + 1);

	if (current == first)
		first = addedNode;

	//����������� ������ ���������� �������
	current = addedNode;
}

template <class T>
//������� �������
void LinkedList<T>::Delete() {

	int k = 0;
	//���� ������� ������, �� ������ �� ������ (������ ����)
	if (length == 0)
		return;

	Node<T>* prev = current->GetPrev();

	Node<T>* newNext = current->GetNext();

	prev->SetNext(newNext);

	newNext->SetPrev(prev);

	if (first == current)
	{
		first = current->GetNext();
		k = 1;

	}

	delete current;

	if (k == 1)  current = first;
	else  current = prev;

	// ����� �����������
	SetLength(length - 1);
}

template <class T>
//������� � ������� (��� �����)
void LinkedList<T>::MoveFirst() {
	current = first;
}

template <class T>
//������� � ���������� � ���������� �������
void LinkedList<T>::MoveNext() {

	//���� ������ ����
	if (length == 0)
		return;

	//������� � ���������� �������� ������
	current = current->GetNext();
}

template <class T>
//������ � ����������� � ���������� �������
void LinkedList<T>::MovePrev() {

	//���� ������ ����
	if (length == 0)
		return;

	//������� � ����������� �������� ������
	current = current->GetPrev();
}

template <class T>
//�������� �������� �������� ���������������� ��������
T* LinkedList<T>::GetValue() {

	return current->GetValue();
}

template <class T>
Node<T>* LinkedList<T>::GetCurrent() {
	return current;
}

template <class T>
void LinkedList<T>::SetCurrent(Node<T>* _current) {
	current = _current;
}

template <class T>
int LinkedList<T>::GetLength() {
	return length;
}

template <class T>
void LinkedList<T>::Set() {

	if (length == 0)
		return;

	current->GetValue()->Modify();
}

//����������
template <class T>
LinkedList<T>::~LinkedList() {

	//���������� �����
	cout << "������ ���������� ������ LinkedList" << endl;

	//���� ������ ����, �� ������ �������
	if (length == 0)
		return;

	//�������� �������� length � tmp, �.�. ��� �������� �������� length ����� ��������
	int tmp = length;

	//������ �� ������ length ���������
	for (int i = 0; i < tmp; i++)
		Delete();
}

