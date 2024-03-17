#include "InputCheck.h"
void InputCheck::russianAlphabet()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

std::string InputCheck::inputSurname()
{
	std::string surname;
	bool isIncorrect;
	do
	{
		std::cout << "������� ��������: ";
		std::getline(std::cin, surname);
		deleteBeginsAndEndsSpaces(surname);
		isIncorrect = false;
		if (surname.size() == 0) {
			isIncorrect = true;
		}
		else {
			for (int i = 0; i < surname.size(); i++) {
				if ((('�' > surname[i] || surname[i] > '�'))
					&& surname[i] != '-' && !std::isalpha(surname[i])) {
					isIncorrect = true;
					break;
				}
			}
		}

		if (isIncorrect) {
			std::cout << "������������ �������, ���������� ��� ���" << std::endl;
		}

	} while (isIncorrect);
	return surname;
}

std::string InputCheck::inputInitials()
{
	std::string inicials;
	bool isIncorrect;
	do
	{
		std::cout << "������� ��������: ";
		std::getline(std::cin, inicials);
		deleteBeginsAndEndsSpaces(inicials);
		isIncorrect = false;
		if (inicials.size() != 4 && inicials.size() != 5) {
			isIncorrect = true;
		}
		else {
			for (int i = 0; inicials[i] != '\0'; i++) {
				if (('�' > inicials[i] || inicials[i] > '�')
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
				else if (('�' <= inicials[i] && inicials[i] <= '�') &&
					((i != 0 && i != 2) && inicials.size() == 4 ||
						(i != 0 && i != 3) && inicials.size() == 5)) {
					isIncorrect = true;
					break;
				}
			}
		}
		if (isIncorrect) {
			std::cout << "������������ ��������, ���������� ��� ���" << std::endl;
		}

	} while (isIncorrect);

	if (inicials.size() == 5) {
		inicials[2] = inicials[3];
		inicials[3] = inicials[4];
		inicials[4] = '\0';
	}
	return inicials;
}

int InputCheck::inputYearOfBirth()
{
	std::string yearOfBirth;
	bool isIncorrect;
	do
	{
		printf("������� ��� ��������: ");
		std::getline(std::cin, yearOfBirth);
		deleteBeginsAndEndsSpaces(yearOfBirth);
		isIncorrect = false;
		if (yearOfBirth.size() != 4) {
			isIncorrect = true;
		}
		else {
			for (int i = 0; yearOfBirth[i] != '\0'; i++) {
				if (('�' < yearOfBirth[i] && yearOfBirth[i] < '�') || !std::isdigit(yearOfBirth[i])) {
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
			printf("������������ ��� ��������, ���������� ��� ���\n");
		}

	} while (isIncorrect);
}

int InputCheck::inputYearOfAdmission(int yearOfBirth)
{
	std::string yearOfAdmission;
	bool isIncorrect;
	do
	{
		printf("������� ��� ����������� � �����: ");
		getline(std::cin, yearOfAdmission);
		deleteBeginsAndEndsSpaces(yearOfAdmission);
		isIncorrect = false;
		if (yearOfAdmission.size() != 4) {
			isIncorrect = true;
		}
		else {
			for (int i = 0; yearOfAdmission[i] != '\0'; i++) {
				if (('�' < yearOfAdmission[i] && yearOfAdmission[i] < '�') || !std::isdigit(yearOfAdmission[i])) {
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
			printf("������������ ��� ����������� � �����, ���������� ��� ���\n");
		}

	} while (isIncorrect);
}



int InputCheck::inputMark(int codeOfDiscipline)
{
	std::string mark;
	bool isIncorrect;
	do
	{
		switch (codeOfDiscipline)
		{
		case CODE_PHYSICS:
			printf("������� ������ �� ������: ");
			break;
		case CODE_HIGHER_MATH:
			printf("������� ������ �� ������ ����������: ");
			break;
		case CODE_COMPUTER_SCIENCE:
			printf("������� ������ �� �����������: ");
			break;
		}
		getline(std::cin, mark);
		deleteBeginsAndEndsSpaces(mark);
		isIncorrect = false;
		if (mark.size() != 1 && mark.size() != 2) {
			isIncorrect = true;
		}
		else {
			for (int i = 0; mark[i] != '\0'; i++) {
				if (('�' < mark[i] && mark[i] < '�') || !std::isdigit(mark[i])) {
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
			printf("������������ ������, ���������� ��� ���\n");
		}

	} while (isIncorrect);
}

int InputCheck::inputIntOptions()
{
	std::string options;
	bool isIncorrect;

	getline(std::cin, options);
	if (options == "") {
		getline(std::cin, options);
	}
	deleteBeginsAndEndsSpaces(options);
	isIncorrect = false;
	for (int i = 0; options[i] != '\0'; i++) {
		if (('�' < options[i] && options[i] < '�') || !std::isdigit(options[i])) {
			isIncorrect = true;
			break;
		}
	}
	if (options == "") {
		isIncorrect = true;
	}
	if (isIncorrect) {
		return 0;
	}


	return std::stoi(options);
}

int InputCheck::inputInt()
{
	std::string number;
	bool isIncorrect;
	do
	{
		printf("������� �����: ");
		getline(std::cin, number);
		deleteBeginsAndEndsSpaces(number);
		isIncorrect = false;
		for (int i = 0; number[i] != '\0'; i++) {
			if ((('�' < number[i] && number[i] < '�') || !std::isdigit(number[i])) && !(i == 0 && number[i] == '-')) {
				isIncorrect = true;
				break;
			}
		}
		if (number == "") {
			isIncorrect = true;
		}
		if (isIncorrect) {
			printf("������������ �����, ���������� ��� ���\n");
		}
		else {
			int intNumber = std::stoi(number);
			return intNumber;
		}

	} while (isIncorrect);
}

int InputCheck::InputUnsignedInt()
{
	std::string number;
	bool isIncorrect;
	do
	{
		printf("������� �����: ");
		getline(std::cin, number);
		deleteBeginsAndEndsSpaces(number);
		isIncorrect = false;
		for (int i = 0; number[i] != '\0'; i++) {
			if (('�' < number[i] && number[i] < '�') || !std::isdigit(number[i])) {
				isIncorrect = true;
				break;
			}
		}
		if (number == "") {
			isIncorrect = true;
		}
		if (isIncorrect) {
			printf("������������ �����, ���������� ��� ���\n");
		}
		else {
			int intNumber = std::stoi(number);
			return intNumber;
		}

	} while (isIncorrect);
}

char InputCheck::inputChar()
{
	std::string symbol;
	bool isIncorrect;
	do
	{
		printf("������� ������: ");
		getline(std::cin, symbol);
		deleteBeginsAndEndsSpaces(symbol);
		isIncorrect = false;
		if (symbol.size() != 1) {
			isIncorrect = true;
		}
		if (isIncorrect) {
			printf("������������ ������, ���������� ��� ���\n");
		}
		else {
			return symbol[0];
		}

	} while (isIncorrect);
}

void InputCheck::deleteBeginsAndEndsSpaces(std::string& str)
{
	std::string strUpdate = str;

	int begin, end;

	for (begin = 0; begin < str.size() && str[begin] == ' '; begin++);
	for (end = str.size() - 1; end > begin && str[end] == ' '; end--);

	str = strUpdate.substr(begin, end - begin + 1);
}
