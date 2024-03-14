#pragma once
#include "Student.h"

class Queue
{
public:

	Queue();

	~Queue();

	void add(Student element);
	Student remove();
	
	void print();

	int size();

	bool isEmpty();

	void menu();

private:
	class ListNode
	{
	public:
		Student data;
		ListNode* nextNode;
	}*head_, *tail_;

	int size_;

	void releaseQueue_(ListNode* ptr);
};

