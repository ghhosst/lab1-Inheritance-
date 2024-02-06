#pragma once

#include "Element.h"

class BaseQueue{
private:
	Element* front;	// �������� ����� �������
	Element* rear;	// ������ �����
public:
	BaseQueue();
	~BaseQueue();
	Element* Get_front();
	Element* Get_rear();
	void Set_front(Element* front);
	void Set_rear(Element* rear);

	void Insert(int data);													// �������� �������
	void Clear();															// ������� ������
	void Retrieve(bool* empty);												// ������� �������
	void ShowQueue(bool* empty);														// ������� ������� �� ����� 
	void ShowMerge();
	void Copy(BaseQueue* original, BaseQueue* copy, bool* empty);						// ����������� �������
	void Merge(BaseQueue* original, BaseQueue* copy, BaseQueue* merge, bool* empty);	// ������ ����� ������� � � ����������
	void Empty(bool* empty);															// ��������� ������� �� �������.
};