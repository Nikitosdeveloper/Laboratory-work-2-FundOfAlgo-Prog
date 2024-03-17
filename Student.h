#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "InputCheck.h"




class RecordBook {

public:

	RecordBook(int physicsMark, int higherMathMark, int computerScienceMark);
	RecordBook();

	int physicsMark;
	int higherMathMark;
	int computerScienceMark;
	double middleMark;

};


class Student
{
public:

	Student(std::string surname, std::string inicials, int yearOfBirth, int yearOfAdmission, RecordBook studentsRecordBook);
	Student();

	void printStudent();

	void addStudent();

	bool operator<(const Student& other);
	bool operator>(const Student& other);

	bool operator==(const Student& other);

	void calculateMiddleMark();

private:

	std::string surname_;
	std::string inicials_;
	int yearOfBirth_;
	int yearOfAdmission_;
	RecordBook studentsRecordBook_;

	friend class StudentList;
	
};



