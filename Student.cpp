#include "Student.h"

RecordBook::RecordBook(int physicsMark, int higherMathMark, int computerScienceMark)
{
	this->physicsMark = physicsMark;
	this->higherMathMark = higherMathMark;
	this->computerScienceMark = computerScienceMark;
	this->middleMark = (double)(physicsMark + higherMathMark + computerScienceMark) / 3;
}

RecordBook::RecordBook()
{
	this->higherMathMark = 
	this->physicsMark = 
	this->computerScienceMark = 
	this->middleMark = 0;
}

Student::Student(std::string surname, std::string inicials, int yearOfBirth, int yearOfAdmission, RecordBook studentsRecordBook)
{
	surname_ = surname;
	inicials_ = inicials;
	yearOfAdmission_ = yearOfAdmission;
	yearOfBirth_ = yearOfBirth;
	studentsRecordBook_ = studentsRecordBook;
	calculateMiddleMark();
}

Student::Student()
{
	surname_ = "";
	inicials_ = "";
	yearOfBirth_ = 0;
	yearOfAdmission_ = 0;
	studentsRecordBook_ = RecordBook(0, 0, 0);
}

void Student::printStudent()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "ФИО: " << surname_ << " " << inicials_ << std::endl;
	std::cout << "Год рождения: " << yearOfBirth_ << std::endl;
	std::cout << "Год поступления в БГУИР: " << yearOfAdmission_ << std::endl;
	std::cout << "Оценка по физике: " << studentsRecordBook_.physicsMark << std::endl;
	std::cout << "Оценка по высшей математике: " << studentsRecordBook_.higherMathMark << std::endl;
	std::cout << "Оценка по высшей информатике: " << studentsRecordBook_.computerScienceMark << std::endl;
	std::cout << std::endl;
}

void Student::addStudent()
{
	printf("Введите информацию о новом студенте:\n");
	surname_ = InputCheck::inputSurname();
	inicials_ = InputCheck::inputInitials();
	yearOfBirth_ = InputCheck::inputYearOfBirth();
	yearOfAdmission_ = InputCheck::inputYearOfAdmission(yearOfBirth_);
	studentsRecordBook_.physicsMark = InputCheck::inputMark(InputCheck::CODE_PHYSICS);
	studentsRecordBook_.higherMathMark = InputCheck::inputMark(InputCheck::CODE_HIGHER_MATH);
	studentsRecordBook_.computerScienceMark = InputCheck::inputMark(InputCheck::CODE_COMPUTER_SCIENCE);
}

bool Student::operator<(const Student& other)
{
	return this->surname_ < other.surname_;
}

bool Student::operator>(const Student& other)
{
	return this->surname_ > other.surname_;
}

bool Student::operator==(const Student& other)
{
	return this->surname_ == other.surname_;
}

void Student::calculateMiddleMark()
{
	studentsRecordBook_.middleMark = (double)(
		studentsRecordBook_.computerScienceMark +
		studentsRecordBook_.higherMathMark +
		studentsRecordBook_.physicsMark
		) / 3;
}

