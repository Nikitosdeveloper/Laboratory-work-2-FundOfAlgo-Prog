#include "StackStudent.h"

StackStudent::StackStudent()
{
	size_ = 0;
	top_ = nullptr;
}

StackStudent::~StackStudent()
{
	releaseQueue_(top_);
}

void StackStudent::push(Student element)
{
	StackNode* newElement = new StackNode;
	newElement->nextNode = nullptr;
	newElement->data = element;

	if (top_ == nullptr) {
		top_ = newElement;
	}
	else {
		newElement->nextNode = top_;
		top_ = newElement;
	}
	size_++;

}

Student StackStudent::remove()
{
	if (top_ == nullptr) {
		return Student();
	}
	Student student = top_->data;
	StackNode* node = top_;
	top_ = top_->nextNode;
	delete node;
	size_--;
	return student;
}

Student StackStudent::getTop()
{
	if (top_ == nullptr) {
		return Student();
	}

	return top_->data;

}

bool StackStudent::isEmpty()
{
	return (size_ == 0);
}

int StackStudent::size()
{
	return size_;
}

void StackStudent::menu()
{
	InputCheck::russianAlphabet();
	while (true)
	{
		std::cout << "Выберете операцию которую хотите совершить со стеком: " << std::endl;
		std::cout << "1 - добавить студента в стек" << std::endl;
		std::cout << "2 - извлечь студента из стека" << std::endl;
		std::cout << "3 - показать верхнего студента стека" << std::endl;
		std::cout << "4 - получить размер стека" << std::endl;
		std::cout << "5 - проверить стек на пустоту" << std::endl;
		std::cout << "6 - выйти" << std::endl;

		int options = InputCheck::inputIntOptions();
		switch (options)
		{
		case 1:
			{
				Student student;
				student.addStudent();
				push(student);
			}
		break;
		case 2:
		{
			Student student = remove();
			if (student == Student()) {
				std::cout << "Стек пустой" << std::endl;
			}
			else {
				std::cout << "Студент извлечённый из стека: " << std::endl;
				student.printStudent();
			}

		}
		break;
		case 3:
			std::cout << "Верхний элемент стека: " << std::endl;
			getTop().printStudent();
			break;
		case 4:
			std::cout << "Размер стека: " << size() << std::endl;
			break;
		case 5:
			if (isEmpty()) {
				std::cout << "Стек пустой" << std::endl;
			}
			else {
				std::cout << "Стек не пустой" << std::endl;
			}
			break;
		case 6:
			return;
		default:
			std::cout << "Неверная операция" << std::endl;
			break;
		}
	}
}

void StackStudent::releaseQueue_(StackNode* ptr)
{
	if (ptr != nullptr && ptr->nextNode != nullptr) {
		releaseQueue_(ptr->nextNode);
		delete ptr->nextNode;
	}
}
