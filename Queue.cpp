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

void Queue::menu()
{
	InputCheck::russianAlphabet();
	while (true)
	{
		std::cout << "Выберете операцию которую хотите совершить с очередью: " << std::endl;
		std::cout << "1 - добавить студента в очередь" << std::endl;
		std::cout << "2 - извлечь студента из очерели" << std::endl;
		std::cout << "3 - показать всех студентов в очереди" << std::endl;
		std::cout << "4 - получить размер очереди" << std::endl;
		std::cout << "5 - проверить очередь на пустоту" <<std::endl;
		std::cout << "6 - выйти" << std::endl;
		std::cout << "Ваша операция: ";
		int options = InputCheck::inputIntOptions();
		switch (options)
		{
		case 1:
		{
			Student student;
			student.addStudent();
			add(student);
		}
		break;
		case 2:
		{
			Student student = remove();
			if (student == Student()) {
				std::cout << "Очередь пустая" << std::endl;
			}
			else {
				std::cout << "Студент извлечённый из очереди: " << std::endl;
				student.printStudent();
			}
				
			}
			break;
		case 3:
			print();
			break;
		case 4:
			std::cout << "Размер очереди: " << size() << std::endl;
			break;
		case 5:
			if (isEmpty()) {
				std::cout << "Очередь пустая" << std::endl;
			}
			else {
				std::cout << "Очередь не пустая" << std::endl;
			}
			break;
		case 6:
			return;
		default:
			std::cout << "Неверная операция" << std::endl;
			break;
		}
	}
	
}

void Queue::releaseQueue_(ListNode* ptr)
{
	if (ptr!=nullptr && ptr->nextNode != nullptr) {
		releaseQueue_(ptr->nextNode);
		delete ptr->nextNode;
	}
}
