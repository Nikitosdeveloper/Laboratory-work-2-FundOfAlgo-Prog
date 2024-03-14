#pragma once
#include <iostream>
#include "Student.h"

class StackChar
{

public:

	StackChar(int maxSize);

	~StackChar();

	void push(char element);
	char remove();
	char getTop();

	void print();

	void inputBeforEtalon();

	void setEtalon(char etalon);

	bool isEmpty();
	int size();

	void menu();
private:

	class StackNode
	{
	public:
		char data;
		StackNode* nextNode;
	}*top_;

	int size_;
	int maxSize_;
	char etalon_;

	void releaseStack_(StackNode* ptr);

};

