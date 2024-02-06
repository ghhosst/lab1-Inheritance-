#pragma once

#include "Element.h"

class BaseQueue{
private:
	Element* front;	// передняя часть очереди
	Element* rear;	// задняя часть
public:
	BaseQueue();
	~BaseQueue();
	Element* Get_front();
	Element* Get_rear();
	void Set_front(Element* front);
	void Set_rear(Element* rear);

	void Insert(int data);													// вставить элемент
	void Clear();															// очистка памяти
	void Retrieve(bool* empty);												// извлечь элемент
	void ShowQueue(bool* empty);														// вывести очередь на экран 
	void ShowMerge();
	void Copy(BaseQueue* original, BaseQueue* copy, bool* empty);						// скопировать очередь
	void Merge(BaseQueue* original, BaseQueue* copy, BaseQueue* merge, bool* empty);	// слиять копию очереди с её оригиналом
	void Empty(bool* empty);															// проверить очередь на пустоту.
};