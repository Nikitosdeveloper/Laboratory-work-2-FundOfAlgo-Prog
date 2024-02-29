#include "StackChar.h"

StackChar::StackChar(int maxSize)
{
	etalon_ = '\0';
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

void StackChar::releaseStack_(StackNode* ptr)
{
	if (ptr != nullptr && ptr->nextNode != nullptr) {
		releaseStack_(ptr->nextNode);
		delete ptr->nextNode;
	}
}
