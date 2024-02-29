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

void StackStudent::releaseQueue_(StackNode* ptr)
{
	if (ptr != nullptr && ptr->nextNode != nullptr) {
		releaseQueue_(ptr->nextNode);
		delete ptr->nextNode;
	}
}
