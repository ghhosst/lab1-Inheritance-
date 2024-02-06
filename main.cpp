#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include "BaseQueue.h"
#include "queue1_public.h"
#include "queue2_protected.h"
#include  "queue3_private.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	 
	bool empty = true;
	int data;
	BaseQueue TheQueue;
	BaseQueue CopyQueue;
	BaseQueue MergeCopy_with_Original;

	queue1_public calcQueue_public;
	queue2_protected calcQueue_protected;
	queue3_private calcQueue_private;

	int n = 0; // для выбора пункта меню

	do {

		system("cls");

		cout << "\n1) Добавление элемента очереди\n"
			 << "2) Извлечение элемента очереди\n"
			 << "3) Вывод очереди на экран\n"
			 << "4) Вычисление требуемого значения\n"
			 << "5) Создание копии очереди\n"
			 << "6) Слияние оригинальной очереди с копией и вывод результата на экран\n"
			 << "7) Выход из программы\n\n"
			 << "Выбранный пункт меню: ";

		cin >> n;  

		switch (n){
		case 1:
			cout << "\nВведите элемент: ";
			cin >> data;
			TheQueue.Insert(data);
			empty = false;
			break;
		case 2:
			TheQueue.Retrieve(&empty);
			TheQueue.Empty(&empty);
			system("pause");
			break;
		case 3:
			TheQueue.ShowQueue(&empty);
			TheQueue.Empty(&empty);
			system("pause");
			break;
		case 4:
			cout << "\nВыберете режим доступа при наследовании\n"
				 << "1) public\n"
				 << "2) protected\n"
				 << "3) private\n"
				 << "Выбранный пункт меню: ";

			cin >> n;

			switch (n)
			{
			case 1:
				calcQueue_public.ShowCalculation_public(&TheQueue, &empty);
				calcQueue_public.Empty(&empty);
				system("pause");
				break;
			case 2:
				calcQueue_protected.ShowCalculation_protected(&TheQueue, &empty);
				system("pause");
				break;
			case 3:
				calcQueue_private.ShowCalculation_private(&TheQueue, &empty);
				system("pause");
				break;
			default:
				cout << "\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
				system("pause");
				break;
			}
			
			break;
		case 5:
			TheQueue.Copy(&TheQueue, &CopyQueue, &empty);
			TheQueue.Empty(&empty);
			system("pause");
			break;
		case 6:
			MergeCopy_with_Original.Merge(&TheQueue, &CopyQueue, &MergeCopy_with_Original, &empty);
			TheQueue.Empty(&empty);
			system("pause");
			break;
		case 7: 
			break;
		default:
			cout << "\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 7.\n\n";
			system("pause");
		}


	} while (n != 7);

	return 0;
}