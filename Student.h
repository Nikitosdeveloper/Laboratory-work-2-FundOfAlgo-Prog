#pragma once
#include <iostream>
#include <string>
#include <Windows.h>




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

	static void russianAlphabet();

	static std::string inputSurname();
	static std::string inputInitials();
	static int inputYearOfBirth();
	static int inputYearOfAdmission(int yearOfBirth);

	static int inputMark(int codeOfDiscipline);

	static int inputIntOptions();

	static void deleteBeginsAndEndsSpaces(std::string& str);

	static const int CODE_PHYSICS = 1;
	static const int CODE_HIGHER_MATH = 2;
	static const int CODE_COMPUTER_SCIENCE = 3;

	

private:

	std::string surname_;
	std::string inicials_;
	int yearOfBirth_;
	int yearOfAdmission_;
	RecordBook studentsRecordBook_;

	friend class StudentList;
	
};



