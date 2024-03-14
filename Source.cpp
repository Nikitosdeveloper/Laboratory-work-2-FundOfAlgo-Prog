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
		std::cout << "Выберете структуру данных с которой вы будете работать" << std::endl;
		std::cout << "1 - односвязный списко" << std::endl;
		std::cout << "2 - очередь" << std::endl;
		std::cout << "3 - стек" << std::endl;
		std::cout << "Выбранная структура: ";
		int options = Student::inputIntOptions();

		switch (options)
		{
		case 1:
			{
				std::cout << "Выберете тип данных с которым будет работать стек" << std::endl;
				std::cout << "1 - Числа" << std::endl;
				std::cout << "2 - студенты" << std::endl;
				std::cout << "Ваш тип: " << std::endl;
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
				std::cout << "Выберете тип данных с которым будет работать стек" << std::endl;
				std::cout << "1 - Символы" << std::endl;
				std::cout << "2 - студенты" << std::endl;
				std::cout << "Ваш тип: " << std::endl;
				int options = Student::inputIntOptions();
			switch (options)
			{
				case 1:
				{
					std::cout << "Введите максимальный размер стека: " << std::endl;
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
			std::cout << "Неправильно выбранная структура" << std::endl;
			break;
		}
	}
}

int main() {

	menu();

	return 0;
}