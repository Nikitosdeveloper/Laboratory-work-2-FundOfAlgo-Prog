#include "Queue.h"

Queue::Queue()
{
	size_ = 0;
	head_ = nullptr;
	tail_ = nullptr;
}

Queue::~Queue()
{
	releaseQueue_(head_);
}

void Queue::add(Student element)
{
	ListNode* newElement = new ListNode;
	newElement->data = element;
	newElement->nextNode = nullptr;
	if (head_ == nullptr) {
		head_ = tail_ = newElement;
	}
	else {
		tail_->nextNode = newElement;
		tail_ = newElement;
	}
	size_++;
}

Student Queue::remove()
{
	if (head_ == nullptr) {
		return Student();
	}
	Student student = head_->data;
	ListNode* p = head_;
	head_ = head_->nextNode;
	delete p;
	if (head_ == nullptr) {
		tail_ = nullptr;
	}
	size_--;
	return student;
}

void Queue::print()
{
	ListNode* ptr = head_;
	if (ptr == nullptr) {
		std::cout << "Очередь пустая" << std::endl;
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

int Queue::size()
{
	return size_;
}

bool Queue::isEmpty()
{
	return (size_==0);
}

void Queue::releaseQueue_(ListNode* ptr)
{
	if (ptr!=nullptr && ptr->nextNode != nullptr) {
		releaseQueue_(ptr->nextNode);
		delete ptr->nextNode;
	}
}
