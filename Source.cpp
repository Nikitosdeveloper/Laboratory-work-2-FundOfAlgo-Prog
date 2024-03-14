#include "SingleLinkedList.h"
#include "SingleStudentLinkedList.h"
#include "Queue.h"
#include "StackStudent.h"
#include "StackChar.h"
#include "StudentList.h"

void menu() {
	Student::russianAlphabet();
	
	bool isIncorrect = true;
	while (isIncorrect)
	{
		std::cout << "�������� ��������� ������ � ������� �� ������ ��������" << std::endl;
		std::cout << "1 - ����������� ������" << std::endl;
		std::cout << "2 - �������" << std::endl;
		std::cout << "3 - ����" << std::endl;
		std::cout << "��������� ���������: ";
		int options = Student::inputIntOptions();

		switch (options)
		{
		case 1:
			{
				std::cout << "�������� ��� ������ � ������� ����� �������� ����" << std::endl;
				std::cout << "1 - �����" << std::endl;
				std::cout << "2 - ��������" << std::endl;
				std::cout << "��� ���: " << std::endl;
				int options = Student::inputIntOptions();
				switch (options)
				{
				case 1:
				{
					SingleSortedLinkedList list;
					list.menu();

				}
				break;

				case 2:
				{
					StudentList st;
					st.menu();
				}
				break;
				default:
					break;
				}
			}
			isIncorrect = false;
			isIncorrect = false;
			break;
		case 2:
			{	
				Queue q;
				q.menu();
			}
			isIncorrect = false;
			break;
		case 3:
			{
				std::cout << "�������� ��� ������ � ������� ����� �������� ����" << std::endl;
				std::cout << "1 - �������" << std::endl;
				std::cout << "2 - ��������" << std::endl;
				std::cout << "��� ���: " << std::endl;
				int options = Student::inputIntOptions();
			switch (options)
			{
				case 1:
				{
					std::cout << "������� ������������ ������ �����: " << std::endl;
					int maxSize = Student::inputIntOptions();
					StackChar st(maxSize);
					st.menu();

				}
				break;

				case 2:
					{
					StackStudent st;
					st.menu();
					}
					break;
				default:
					break;
			}
			}
			isIncorrect = false;
			break;
		default:
			std::cout << "����������� ��������� ���������" << std::endl;
			break;
		}
	}
}

int main() {

	menu();

	return 0;
}