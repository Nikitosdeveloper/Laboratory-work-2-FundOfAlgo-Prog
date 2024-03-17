#pragma once
#include "Student.h"
#include "InputCheck.h"
#include <fstream>
#include <Windows.h>


class StudentList {

public:

	void addStudent();
	void updateStudent();
	void deleteStudent();
	void printStudents();
	void printStudentsWhoHasMarksThree();
	void sortStudent();
	void readFromFile();
	void writeToFile();

	void menu();

private:
	
	class NodeList {

	public:
		Student data;
		NodeList* next;

	}*begin_ = nullptr;

	int countStudents;

};
