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

	int n = 0; // ��� ������ ������ ����

	do {

		system("cls");

		cout << "\n1) ���������� �������� �������\n"
			 << "2) ���������� �������� �������\n"
			 << "3) ����� ������� �� �����\n"
			 << "4) ���������� ���������� ��������\n"
			 << "5) �������� ����� �������\n"
			 << "6) ������� ������������ ������� � ������ � ����� ���������� �� �����\n"
			 << "7) ����� �� ���������\n\n"
			 << "��������� ����� ����: ";

		cin >> n;  

		switch (n){
		case 1:
			cout << "\n������� �������: ";
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
			cout << "\n�������� ����� ������� ��� ������������\n"
				 << "1) public\n"
				 << "2) protected\n"
				 << "3) private\n"
				 << "��������� ����� ����: ";

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
				cout << "\n������������ ����� !!!\n����������, �������� ����� �� 1 �� 3.\n\n";
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
			cout << "\n������������ ����� !!!\n����������, �������� ����� �� 1 �� 7.\n\n";
			system("pause");
		}


	} while (n != 7);

	return 0;
}