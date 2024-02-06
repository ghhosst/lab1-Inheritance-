#include "Element.h"

Element::Element(int data) {
	this->data = data;
	this->next = nullptr;
}
 
int Element::Get_data() { return data; }
Element* Element::Get_next() { return next; }
void Element::Set_data(int data) { this->data = data; }
void Element::Set_next(Element* next) { this->next = next; }