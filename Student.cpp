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

void Student::russianAlphabet_()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

std::string Student::inputSurname()
{
	std::string surname;
	bool isIncorrect;
	do
	{
		std::cout << "Введите фамилиию: ";
		std::getline(std::cin, surname);
		deleteBeginsAndEndsSpaces(surname);
		isIncorrect = false;
		if (surname.size() == 0) {
			isIncorrect = true;
		}
		else {
			for (int i = 0; i < surname.size(); i++) {
				if ((('А' > surname[i] || surname[i] > 'я'))
					&& surname[i] != '-' && !std::isalpha(surname[i])) {
					isIncorrect = true;
					break;
				}
			}
		}

		if (isIncorrect) {
			std::cout << "Некорректная фамилия, попробуйте ещё раз" << std::endl;
		}

	} while (isIncorrect);
	return surname;
}

std::string Student::inputInitials()
{
	std::string inicials;
	bool isIncorrect;
	do
	{
		std::cout << "Введите инициалы: ";
		std::getline(std::cin, inicials);
		deleteBeginsAndEndsSpaces(inicials);
		isIncorrect = false;
		if (inicials.size() != 4 && inicials.size() != 5) {
			isIncorrect = true;
		}
		else {
			for (int i = 0; inicials[i] != '\0'; i++) {
				if (('А' > inicials[i] || inicials[i] > 'я')
					&& inicials[i] != '.' && !std::isalpha(inicials[i])) {
					if (inicials[i] != ' ') {
						isIncorrect = true;
						break;
					}
					else if (i != 2) {
						isIncorrect = true;
						break;
					}
				}
				else if (inicials[i] == '.' &&
					((i != 1 && i != 3) && inicials.size() == 4 ||
						(i != 1 && i != 4) && inicials.size() == 5)) {
					isIncorrect = true;
					break;
				}
				else if (('А' <= inicials[i] && inicials[i] <= 'я') &&
					((i != 0 && i != 2) && inicials.size() == 4 ||
						(i != 0 && i != 3) && inicials.size() == 5)) {
					isIncorrect = true;
					break;
				}
			}
		}
		if (isIncorrect) {
			std::cout << "Некорректные инициалы, попробуйте ещё раз" << std::endl;
		}

	} while (isIncorrect);

	if (inicials.size() == 5) {
		inicials[2] = inicials[3];
		inicials[3] = inicials[4];
		inicials[4] = '\0';
	}
	return inicials;
}

int Student::inputYearOfBirth()
{
	std::string yearOfBirth;
	bool isIncorrect;
	do
	{
		printf("Введите год рождения: ");
		std::getline(std::cin,yearOfBirth);
		deleteBeginsAndEndsSpaces(yearOfBirth);
		isIncorrect = false;
		if (yearOfBirth.size() != 4) {
			isIncorrect = true;
		}
		else {
			for (register int i = 0; yearOfBirth[i] != '\0'; i++) {
				if (('А' < yearOfBirth[i] && yearOfBirth[i] < 'я') || !std::isdigit(yearOfBirth[i])) {
					isIncorrect = true;
					break;
				}
			}
		}
		if (!isIncorrect) {
			int year = std::stoi(yearOfBirth);
			if (1907 <= year && year <= 2006) {
				return year;
			}
			isIncorrect = true;
		}
		if (isIncorrect) {
			printf("Некорректный год рождения, попробуйте ещё раз\n");
		}

	} while (isIncorrect);
}

int Student::inputYearOfAdmission(int yearOfBirth)
{
	std::string yearOfAdmission;
	bool isIncorrect;
	do
	{
		printf("Введите год поступления в БГУИР: ");
		getline(std::cin,yearOfAdmission);
		deleteBeginsAndEndsSpaces(yearOfAdmission);
		isIncorrect = false;
		if (yearOfAdmission.size() != 4) {
			isIncorrect = true;
		}
		else {
			for (register int i = 0; yearOfAdmission[i] != '\0'; i++) {
				if (('А' < yearOfAdmission[i] && yearOfAdmission[i] < 'я') || !std::isdigit(yearOfAdmission[i])) {
					isIncorrect = true;
					break;
				}
			}
		}
		if (!isIncorrect) {
			int year = std::stoi(yearOfAdmission);
			if (1964 <= year && year <= 2024 && (year - yearOfBirth >= 17)) {
				return year;
			}
			isIncorrect = true;
		}
		if (isIncorrect) {
			printf("Некорректный год поступления в БГУИР, попробуйте ещё раз\n");
		}

	} while (isIncorrect);
}

int Student::inputMark(int codeOfDiscipline)
{
	std::string mark;
	bool isIncorrect;
	do
	{
		switch (codeOfDiscipline)
		{
		case CODE_PHYSICS:
			printf("Введите оценку по физике: ");
			break;
		case CODE_HIGHER_MATH:
			printf("Введите оценку по высшей матиматике: ");
			break;
		case CODE_COMPUTER_SCIENCE:
			printf("Введите оценку по информатике: ");
			break;
		}
		getline(std::cin,mark);
		deleteBeginsAndEndsSpaces(mark);
		isIncorrect = false;
		if (mark.size() != 1 && mark.size() != 2) {
			isIncorrect = true;
		}
		else {
			for (register int i = 0; mark[i] != '\0'; i++) {
				if (('А' < mark[i] && mark[i] < 'я') || !std::isdigit(mark[i])) {
					isIncorrect = true;
					break;
				}
			}
		}
		if (!isIncorrect) {
			int year = std::stoi(mark);
			if (0 <= year && year <= 10) {
				return year;
			}
			isIncorrect = true;
		}
		if (isIncorrect) {
			printf("Некорректная оценка, попробуйте ещё раз\n");
		}

	} while (isIncorrect);
}

int Student::inputIntOptions()
{
	std::string options;
	bool isIncorrect;

	getline(std::cin,options);
	deleteBeginsAndEndsSpaces(options);
	isIncorrect = false;
	for (int i = 0; options[i] != '\0'; i++) {
		if (('А' < options[i] && options[i] < 'я') || !std::isdigit(options[i])) {
			isIncorrect = true;
			break;
		}
	}
	if (isIncorrect) {
		return 0;
	}


	return std::stoi(options);
}

void Student::deleteBeginsAndEndsSpaces(std::string& str)
{
	std::string strUpdate = str;

	int begin, end;

	for (begin = 0; begin < str.size() && str[begin] == ' '; begin++);
	for (end = str.size() - 1; end > begin && str[end] == ' '; end--);

	str = strUpdate.substr(begin, end - begin + 1);
}
