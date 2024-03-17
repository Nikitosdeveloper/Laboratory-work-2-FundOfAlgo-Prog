#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

class InputCheck
{
public:
	static void russianAlphabet();

	static std::string inputSurname();
	static std::string inputInitials();
	static int inputYearOfBirth();
	static int inputYearOfAdmission(int yearOfBirth);

	static int inputMark(int codeOfDiscipline);

	static int inputIntOptions();

	static int inputInt();
	static int InputUnsignedInt();
	static char inputChar();

	static void deleteBeginsAndEndsSpaces(std::string& str);

	static const int CODE_PHYSICS = 1;
	static const int CODE_HIGHER_MATH = 2;
	static const int CODE_COMPUTER_SCIENCE = 3;
	
};

