#include "SingleLinkedList.h"

void SingleSortedLinkedList::releaseList_(ListNode* ptr)
{

	if (ptr != nullptr && ptr->nextNode != nullptr) {
		releaseList_(ptr->nextNode);
		delete ptr->nextNode;
	}
	
}

SingleSortedLinkedList::SingleSortedLinkedList()
{

	size_ = 0;
	beginList_ = nullptr;

}

SingleSortedLinkedList::~SingleSortedLinkedList()
{
	releaseList_(beginList_);
}

void SingleSortedLinkedList::insert(int element)
{
	ListNode* ptr = beginList_;

	ListNode* newElement = new ListNode;
	newElement->data = element;
	newElement->nextNode = nullptr;
	ListNode* ptrPrevious = nullptr;

	while (ptr != nullptr && ptr->data < element )
	{
		ptrPrevious = ptr;
		ptr = ptr->nextNode;
	}
	if (ptrPrevious == nullptr) {

		newElement->nextNode = beginList_;
		beginList_ = newElement;
	}
	else {
		ptrPrevious->nextNode = newElement;
		newElement->nextNode = ptr;
	}
	size_++;
}

void SingleSortedLinkedList::insert(int element, int postition)
{
	ListNode* ptr = beginList_;

	ListNode* newElement = new ListNode;
	newElement->data = element;
	newElement->nextNode = nullptr;
	ListNode* ptrPrevious = nullptr;
	postition--;
	while (postition-- && ptr != nullptr)
	{
		ptrPrevious = ptr;
		ptr = ptr->nextNode;

	}

	if (ptrPrevious == nullptr) {

		newElement->nextNode = beginList_;
		beginList_ = newElement;
	}
	else {
		ptrPrevious->nextNode = newElement;
		newElement->nextNode = ptr;
	}
	size_++;
}

bool SingleSortedLinkedList::delFirstOccurrence(int element)
{
	ListNode* ptr = beginList_;
	if (ptr == nullptr) {
		return false;
	}
	if (ptr->data == element) {
		beginList_ = ptr->nextNode;
		delete ptr;
		size_--;
		return true;
	}
	ListNode* ptrPrevious = ptr;
	ptr = ptr->nextNode;
	while (ptr != nullptr)
	{
		if (ptr->data == element) {
			ptrPrevious->nextNode = ptr->nextNode;
			delete ptr;
			size_--;
			return true;
		}
		ptrPrevious = ptr;
		ptr = ptr->nextNode;
	}
	return false;
}

bool SingleSortedLinkedList::isEmpty() const
{
	return (size_ == 0);
}

void SingleSortedLinkedList::printList()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ListNode* ptr = beginList_;
	if (ptr == nullptr) {
		std::cout << "���� ������" << std::endl;
	}
	while (ptr != nullptr)
	{
		std::cout << ptr->data;
		if (ptr->nextNode != nullptr) {
			std::cout << "->" << std::endl << "->";
		}
		else
		{
			std::cout << std::endl;
		}
		ptr = ptr->nextNode;
	}
}

int SingleSortedLinkedList::countList() const
{
	return size_;
}

int SingleSortedLinkedList::findMax()
{

	ListNode* ptr = beginList_;

	if (ptr == nullptr) {
		return 0;
	}
	
	while (ptr->nextNode != nullptr)
	{
		ptr = ptr->nextNode;
	}
	
	return ptr->data;
}

int SingleSortedLinkedList::findMin()
{

	ListNode* ptr = beginList_;

	if (ptr == nullptr) {
		return 0;
	}
	return ptr->data;
}

bool SingleSortedLinkedList::delAllOccurrence(int element)
{

	bool isHaveThatElement = false;

	while (true)
	{
		if (!delFirstOccurrence(element)) {
			break;
		}
		else
		{
			isHaveThatElement = true;
		}
	}
	return isHaveThatElement;
}

bool SingleSortedLinkedList::delAllRepetitions(int element)
{
	bool isHaveThatElemet = delAllOccurrence(element);
	if (isHaveThatElemet) {
		insert(element);
	}
	return isHaveThatElemet;

}

void SingleSortedLinkedList::menu()
{
	Student::russianAlphabet();
	while (true)
	{
		std::cout << "�������� �������� ������� ������ ��������� �� �������: " << std::endl;
		std::cout << "1 - �������� ������� � ������" << std::endl;
		std::cout << "2 - �������� ������� � ���������� �������" << std::endl;
		std::cout << "3 - ������� ������ ��������� ��������" << std::endl;
		std::cout << "4 - ������� ��� ��������� ��������" << std::endl;
		std::cout << "5 - ������� ��� ���������� ��������" << std::endl;
		std::cout << "6 - ������� ��� �������� ������" << std::endl;
		std::cout << "7 - ������� ������ ������" << std::endl;
		std::cout << "8 - ������� ������������ ������� ������" << std::endl;
		std::cout << "9 - ������� ����������� ������� ������" << std::endl;
		std::cout << "0 - �����" << std::endl;

		int options = Student::inputIntOptions();
		switch (options)
		{
		case 1:
			{std::cout << "������� ������� ������� ������ �������� � ������: ";
			int element;
			std::cin >> element;
			insert(element);
			}
			break;
		case 2:
		{
			{std::cout << "������� ������� ������� ������ �������� � ������: ";
			int element;
			std::cin >> element;
			std::cout << "������� ������� �� ������� �� ������ �������� �������: ";
			int position;
			std::cin >> position;
			insert(element, position);
			}

		}
		break;
		case 3:
		{
			std::cout << "������� ������� ���   ��������: ";
			int element;
			std::cin >> element;
			delFirstOccurrence(element);

		}
		break;
		case 4:
		{
			std::cout << "������� ������� ���   ��������: ";
			int element;
			std::cin >> element;
			delAllOccurrence(element);
		}
		break;
		case 5:
		{
			std::cout << "������� ������� ���   ��������: ";
			int element;
			std::cin >> element;
			delAllRepetitions(element);
		}
		break;
		case 6:
			std::cout << "��� ��������� ������: " << std::endl;
			printList();
			break;
		case 7:
			std::cout << "������ ������: " << countList() << std::endl;
			break;
		case 8:
			std::cout << "������������ ������� ������: " << findMax() << std::endl;
			break;
		case 9:
			std::cout << "����������� ������� ������: " << findMin() << std::endl;
			break;
		case 0:
			return;
		default:
			std::cout << "�������� ��������" << std::endl;
			break;
		}
	}
}