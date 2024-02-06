#include "queue3_private.h"
#include <iostream>

// подсчет числа элементов, больших среднего арифметического значения
int queue3_private::Calculation_private(BaseQueue* ptr) {
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

void queue3_private::ShowCalculation_private(BaseQueue* ptr, bool* empty) {
	if (!*empty)
		std::cout << "\nЧисло элементов, больших среднего арифметического значения: " << Calculation_private(ptr) << "\n\n";
	Empty(empty);
}