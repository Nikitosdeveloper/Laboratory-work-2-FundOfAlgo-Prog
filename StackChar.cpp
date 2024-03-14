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
				std::cout << "��������� ������������ ������ �����" << std::endl;
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
		std::cout << "�������� �������� ������� ������ ��������� �� ������: " << std::endl;
		std::cout << "1 - �������� ������ � ����" << std::endl;
		std::cout << "2 - ������� ������ �� �����" << std::endl;
		std::cout << "3 - �������� ������� ������ �����" << std::endl;
		std::cout << "4 - �������� ��� ������� � �����" << std::endl;
		std::cout << "5 - ������� �������, ���� �� ����� ����� ���������(�� ���������: '0')" << std::endl;
		std::cout << "6 - ������ ��������� �������" << std::endl;
		std::cout << "7 - �������� ������ �����" << std::endl;
		std::cout << "8 - ��������� ���� �� �������" << std::endl;
		std::cout << "9 - �����" << std::endl;

		int options = Student::inputIntOptions();
		switch (options)
		{
		case 1:
		{
			std::cout << "������, ������� �� ������ �������� � ����: " << std::endl;
			char c;
			std::cin >> c;
			push(c);
		}
		break;
		case 2:
		{
			char c = remove();
			if (c == '\0') {
				std::cout << "���� ������" << std::endl;
			}
			else {
				std::cout << "������ ����������� �� �����: " << std::endl;
				std::cout << c << std::endl;
			}

		}
		break;
		case 3:
			std::cout << "������� ������� �����: " << getTop() << std::endl;
			break;
		case 4:
			print();
			break;
		case 5:
			std::cout << "������� �������� � ����" << std::endl;
			std::cout << "��������� ���� ��������� ���������: " << etalon_ << std::endl;
			inputBeforEtalon();
			break;
		case 6:
			std::cout << "������� ����� ��������� �������: ";
			char c;
			std::cin >> c;
			setEtalon(c);
			break;
		case 7:
			std::cout << "������ �����: " << size() << std::endl;
			break;
		case 8:
			if (isEmpty()) {
				std::cout << "���� ������" << std::endl;
			}
			else {
				std::cout << "���� �� ������" << std::endl;
			}
			break;
		case 9:
			return;
		default:
			std::cout << "�������� ��������" << std::endl;
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
