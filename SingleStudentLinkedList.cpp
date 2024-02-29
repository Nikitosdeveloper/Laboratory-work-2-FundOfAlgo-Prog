#include "SingleStudentLinkedList.h"

void SingleStudentLinkedList::releaseList_(ListNode* ptr)
{
	if (ptr != nullptr && ptr->nextNode != nullptr) {
		releaseList_(ptr->nextNode);
		delete ptr->nextNode;
	}
}

SingleStudentLinkedList::SingleStudentLinkedList()
{
	size_ = 0;
	beginList_ = nullptr;
}

SingleStudentLinkedList::~SingleStudentLinkedList()
{
	releaseList_(beginList_);
}

void SingleStudentLinkedList::insert(Student element)
{
	ListNode* ptr = beginList_;

	ListNode* newElement = new ListNode;
	newElement->data = element;
	newElement->nextNode = nullptr;
	ListNode* ptrRrevious = nullptr;

	while (ptr != nullptr && ptr->data < element)
	{
		ptrRrevious = ptr;
		ptr = ptr->nextNode;
	}
	if (ptrRrevious == nullptr) {

		newElement->nextNode = beginList_;
		beginList_ = newElement;
	}
	else {
		ptrRrevious->nextNode = newElement;
		newElement->nextNode = ptr;
	}
	size_++;
}

bool SingleStudentLinkedList::isEmpty() const
{
	return (size_ == 0);
}

void SingleStudentLinkedList::printList()
{
	ListNode* ptr = beginList_;
	if (ptr == nullptr) {
		std::cout << "Лист пустой" << std::endl;
	}
	while (ptr != nullptr)
	{
		(ptr->data).printStudent();
		if (ptr->nextNode != nullptr) {
			std::cout << "->->->" << std::endl;
		}
		else
		{
			std::cout << std::endl;
		}
		ptr = ptr->nextNode;
	}
}

int SingleStudentLinkedList::countList() const
{
	return size_;
}

bool SingleStudentLinkedList::delFirstOccurrence(Student element)
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
