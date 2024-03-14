#include "StackChar.h"

StackChar::StackChar(int maxSize)
{
	etalon_ = '0';
	size_ = 0;
	top_ = nullptr;
	maxSize_ = maxSize;
}

StackChar::~StackChar()
{
	releaseStack_(top_);
}

void StackChar::push(char element)
{
	if (maxSize_ - size_ != 0) {
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
}

char StackChar::remove()
{
	if (top_ == nullptr) {
		return '\0';
	}
	char element = top_->data;
	StackNode* node = top_;
	top_ = top_->nextNode;
	delete node;
	size_--;
	return element;
}

char StackChar::getTop()
{
	if (top_ == nullptr) {
		return '\0';
	}

	return top_->data;
}

void StackChar::print()
{
	StackNode* p = top_;
	while (p != nullptr)
	{
		std::cout << p->data << std::endl;
		p = p->nextNode;
	}
}

void StackChar::inputBeforEtalon()
{
	if (etalon_ != '\0') {
		char element;
		std::cin >> element;
		while (element != etalon_)
		{
			if (size_ == maxSize_) {
				std::cout << "Достигнут максимальный размер стека" << std::endl;
				return;
			}
			push(element);
			std::cin >> element;
		}
	}
}

void StackChar::setEtalon(char etalon)
{
	etalon_ = etalon;
}

bool StackChar::isEmpty()
{
	return (size_==0);
}

int StackChar::size()
{
	return size_;
}

void StackChar::menu()
{
	Student::russianAlphabet();
	while (true)
	{
		std::cout << "Выберете операцию которую хотите совершить со стеком: " << std::endl;
		std::cout << "1 - добавить символ в стек" << std::endl;
		std::cout << "2 - извлечь символ из стека" << std::endl;
		std::cout << "3 - показать верхний символ стека" << std::endl;
		std::cout << "4 - показать все символы в стеке" << std::endl;
		std::cout << "5 - вводить символы, пока не будет введён эталонный(по умолчания: '0')" << std::endl;
		std::cout << "6 - ввести эталонный элемент" << std::endl;
		std::cout << "7 - получить размер стека" << std::endl;
		std::cout << "8 - проверить стек на пустоту" << std::endl;
		std::cout << "9 - выйти" << std::endl;

		int options = Student::inputIntOptions();
		switch (options)
		{
		case 1:
		{
			std::cout << "Символ, который вы хотите добавить в стек: " << std::endl;
			char c;
			std::cin >> c;
			push(c);
		}
		break;
		case 2:
		{
			char c = remove();
			if (c == '\0') {
				std::cout << "Стек пустой" << std::endl;
			}
			else {
				std::cout << "Символ извлечённый из стека: " << std::endl;
				std::cout << c << std::endl;
			}

		}
		break;
		case 3:
			std::cout << "Верхний элемент стека: " << getTop() << std::endl;
			break;
		case 4:
			print();
			break;
		case 5:
			std::cout << "Вводите элементы в стек" << std::endl;
			std::cout << "Завершите ввод эталонным элементом: " << etalon_ << std::endl;
			inputBeforEtalon();
			break;
		case 6:
			std::cout << "Введите новый эталонный элемент: ";
			char c;
			std::cin >> c;
			setEtalon(c);
			break;
		case 7:
			std::cout << "Размер стека: " << size() << std::endl;
			break;
		case 8:
			if (isEmpty()) {
				std::cout << "Стек пустой" << std::endl;
			}
			else {
				std::cout << "Стек не пустой" << std::endl;
			}
			break;
		case 9:
			return;
		default:
			std::cout << "Неверная операция" << std::endl;
			break;
		}
	}
}

void StackChar::releaseStack_(StackNode* ptr)
{
	if (ptr != nullptr && ptr->nextNode != nullptr) {
		releaseStack_(ptr->nextNode);
		delete ptr->nextNode;
	}
}
