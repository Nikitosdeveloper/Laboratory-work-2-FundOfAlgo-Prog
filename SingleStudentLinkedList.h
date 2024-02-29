#pragma once
#include "Student.h"
#include<iostream>
#include <windows.h>

class SingleStudentLinkedList
{
private:

	class ListNode
	{
	public:
		Student data;
		ListNode* nextNode;

	} *beginList_;

	int size_;

	void releaseList_(ListNode* ptr);

public:

	SingleStudentLinkedList();

	~SingleStudentLinkedList();

	void insert(Student element);
	bool isEmpty() const;
	void printList();

	int countList() const;

	bool delFirstOccurrence(Student element);

};

