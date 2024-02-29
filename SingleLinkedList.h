#pragma once
#include<iostream>
#include <windows.h>

class SingleSortedLinkedList
{
private:

	class ListNode
	{
	public:
		int data;
		ListNode* nextNode;

	} *beginList_;

	int size_;

	void releaseList_(ListNode* ptr);

public:

	SingleSortedLinkedList();

	~SingleSortedLinkedList();

	void insert(int element);
	bool delFirstOccurrence(int element);
	bool isEmpty() const;
	void printList();

	int countList() const;
	int findMax();
	int findMin();
	bool delAllOccurrence(int element);
	bool delAllRepetitions(int element);

};

