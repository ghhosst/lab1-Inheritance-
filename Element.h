#pragma once

class Element{
private:
	int data;
	Element* next;
public:
	Element(int data);
	int Get_data();
	Element* Get_next();
	void Set_data(int data);
	void Set_next(Element* next);
};