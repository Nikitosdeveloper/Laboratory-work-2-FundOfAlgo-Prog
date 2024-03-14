#pragma once
#include "Student.h"

class StackStudent
{
public:

	StackStudent();

	~StackStudent();

	void push(Student element);
	Student remove();
	Student getTop();

	bool isEmpty();
	int size();

	void menu();

private:

	class StackNode
	{
	public:
		Student data;
		StackNode* nextNode;
	}*top_;

	int size_;

	void releaseQueue_(StackNode* ptr);

};

