#include "queue1_public.h"
#include <iostream>

// подсчет числа элементов, больших среднего арифметического значения
int queue1_public::Calculation_public(BaseQueue* ptr) {
	float summ = 0;
	float average = 0;
	int num_of_elements = 0;

	Element* front = ptr->Get_front();
	while (front != nullptr) {
		summ += front->Get_data();
		front = front->Get_next();
		num_of_elements++;
	}

	average = (float)summ / num_of_elements;

	front = ptr->Get_front();
	int result = 0;
	while (front != nullptr) {
		if (front->Get_data() > average)
			result++;
		front = front->Get_next();
	}
	front = nullptr;

	return result;
}

void queue1_public::ShowCalculation_public(BaseQueue* ptr, bool* empty) {
	if (!*empty)
		std::cout << "\nЧисло элементов, больших среднего арифметического значения: " << Calculation_public(ptr) << "\n\n";
}