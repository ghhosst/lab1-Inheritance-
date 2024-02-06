#include <iostream>
#include "BaseQueue.h"

BaseQueue::BaseQueue() {
	front = nullptr;
	rear = nullptr;
}

BaseQueue::~BaseQueue() {
	while (front != nullptr)
		Clear();
}

Element* BaseQueue::Get_front() { return front; }
Element* BaseQueue::Get_rear() { return rear; }
void BaseQueue::Set_front(Element* front) { this->front = front; }
void BaseQueue::Set_rear(Element* rear) { this->rear = rear; }

void BaseQueue::Insert(int data) {
	Element* element = new Element(data);
	if (front == nullptr)	// очередь пустая
		front = element;
	if (rear != nullptr)
		rear->Set_next(element);
	rear = element;
}

void BaseQueue::Clear() {
	if (front == nullptr) {
		return;
	}

	if (front == rear) {
		delete rear;
		front = nullptr;
		rear = nullptr;
		return;
	}

	Element* tmp_element = front;
	front = tmp_element->Get_next();
	delete tmp_element;
}

void BaseQueue::Retrieve(bool* empty) {

	if (front == nullptr) {
		*empty = true;
		return;
	}

	if (front == rear) {
		delete rear;
		front = nullptr;
		rear = nullptr;
		*empty = true;
		return;
	}

	Element* tmp_element = front;
	front = tmp_element->Get_next();
	delete tmp_element;

	if (!*empty)
		std::cout << "Элемент очереди успешно извлечён !!!\n\n";
}

void BaseQueue::ShowQueue(bool* empty) {
	if (!*empty) {
		std::cout << "\nОчередь:\n";
		int cnt = 0;
		Element* tmp_front = front;
		while (front != nullptr) {
			std::cout << front->Get_data() << " ";
			front = front->Get_next();
			cnt++;
		}
		std::cout << "\nКоличесвто элементов в этой очереди: " << cnt << "\n\n";
		front = tmp_front;
		tmp_front = nullptr;
	}
}

void BaseQueue::ShowMerge() {
		int cnt = 0;
		Element* tmp_front = front;
		while (front != nullptr) {
			std::cout << front->Get_data() << " ";
			front = front->Get_next();
			cnt++;
		}
		std::cout << "\nКоличество элементов в результате слияния: " << cnt << "\n\n";
		front = tmp_front;
		tmp_front = nullptr;
}

void BaseQueue::Copy(BaseQueue* original, BaseQueue* copy, bool* empty) {
		copy->~BaseQueue();

		Element* head;
		head = original->front;
		while (head != nullptr) {
			copy->Insert(head->Get_data());
			head = head->Get_next();
		}
		head = nullptr;

		std::cout << "Копия !!!\n";
		copy->ShowQueue(empty);
}

void BaseQueue::Merge(BaseQueue* original, BaseQueue* copy, BaseQueue* merge, bool* empty) {
		merge->~BaseQueue();

		Element* head;
		head = original->front;
		while (head != nullptr) {
			merge->Insert(head->Get_data());
			head = head->Get_next();
		}
	
		head = copy->front;
		while (head != nullptr) {
			merge->Insert(head->Get_data());
			head = head->Get_next();
		}
		head = nullptr;

		std::cout << "\nРезультат слияния оригинальной очереди с её копией:\n\n";
		merge->ShowMerge();
}

void BaseQueue::Empty(bool* empty) {
	if (*empty)
		std::cout << "\nОригинальная очередь пустая !!!\n\n";
}