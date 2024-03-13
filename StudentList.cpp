#include "StudentList.h"

void StudentList::addStudent()
{
	countStudents++;

	printf("������� ���������� � ����� ��������:\n");
	std::string surname = Student::inputSurname();
	std::string inicials = Student::inputInitials();
	int yearOfBirth = Student::inputYearOfBirth();
	int yearOfAdmission = Student::inputYearOfAdmission(yearOfBirth);
	RecordBook studentRecordBook;
	studentRecordBook.physicsMark = Student::inputMark(Student::CODE_PHYSICS);
	studentRecordBook.higherMathMark = Student::inputMark(Student::CODE_HIGHER_MATH);
	studentRecordBook.computerScienceMark = Student::inputMark(Student::CODE_COMPUTER_SCIENCE);


	Student student(surname,inicials,yearOfBirth,yearOfAdmission,studentRecordBook);
	NodeList* newElement = new NodeList;
	newElement->data = student;
	newElement->next = nullptr;
	if (begin_ == nullptr) {
		begin_ = newElement;
	}
	else {
		NodeList* ptr = begin_;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		ptr->next = newElement;
	}
}

void StudentList::updateStudent()
{
	if (countStudents == 0) {
		printf("������ ��������� ����\n");
	}
	else {
		int index;
		do {
			printf("�������� ����� ��������, ���������� � ������� �� ������ ��������: ");

			index = Student::inputIntOptions();
			if (index <= 0 || index > countStudents) {
				index = 0;
				printf("�� ����� ������������ ����� ��������, ���������� ��� ���\n");
			}
		} while (index == 0);
		index--;

		NodeList* ptr = begin_;

		while (index--)
		{
			ptr = ptr->next;
		}

		Student& student = ptr->data;
		

		int options;
		do {
			printf("�������� ��������, ������� �� ������ ��������\n");
			printf("1 - �������\n");
			printf("2 - ��������\n");
			printf("3 - ��� ��������\n");
			printf("4 - ��� ����������� � �����\n");
			printf("5 - ������ � �������\n");
			printf("�������� ��� ���������: ");
			options = Student::inputIntOptions();
			switch (options)
			{
			case 1:
			{
				student.surname_ = Student::inputSurname();
			}
			break;
			case 2:
			{
				 student.inicials_ = Student::inputSurname();
			}
			break;
			case 3:
				student.yearOfBirth_ = Student::inputYearOfBirth();
				break;
			case 4:
				student.yearOfAdmission_ = Student::inputYearOfAdmission(student.yearOfBirth_);
				break;
			case 5:
				int disciplineIndex;
				do {
					printf("�������� ���������� �� ������� �� ������ �������� ������\n");
					printf("1 - ������\n");
					printf("2 - ������ ����������\n");
					printf("3 - �����������\n");
					printf("����� ����������: ");
					disciplineIndex = Student::inputIntOptions();
					switch (disciplineIndex)
					{
					case Student::CODE_PHYSICS:
						student.studentsRecordBook_.physicsMark = Student::inputMark(Student::CODE_PHYSICS);
						break;
					case Student::CODE_HIGHER_MATH:
						student.studentsRecordBook_.higherMathMark = Student::inputMark(Student::CODE_HIGHER_MATH);
						break;
					case Student::CODE_COMPUTER_SCIENCE:
						student.studentsRecordBook_.computerScienceMark = Student::inputMark(Student::CODE_COMPUTER_SCIENCE);
						break;
					default:
						disciplineIndex = 0;
						printf("�� ����� ������������ ����� ����������, ���������� ��� ���\n");
						break;
					}
				} while (!disciplineIndex);
				//student.;
				break;
			default:
				printf("�� ������� �������� ��������, ���������� ��� ���\n");
				break;
			}
		} while (!options);
		printf("������ �������� ������� ���������\n");
	}
}

void StudentList::deleteStudent()
{
	if (countStudents == 0) {
		printf("������ ��������� ����\n");
	}
	else {
		int index;
		do {
			printf("�������� ����� ��������, ���������� � ������� �� �������: ");

			index = Student::inputIntOptions();
			if (index <= 0 || index > countStudents) {
				index = 0;
				printf("�� ����� ������������ ����� ��������, ���������� ��� ���\n");
			}

		} while (index == 0);

		NodeList* ptr = begin_;

		if (index == 1) {
			begin_ = begin_->next;
			delete ptr;
		}
		else {

			NodeList* ptrPrevious = nullptr;

			index--;
			while (index--)
			{
				ptrPrevious = ptr;
				ptr = ptr->next;
			}

			ptrPrevious->next = ptr->next;
			delete ptr;
		}

		printf("������� ������� �����\n");
	}
}

void StudentList::printStudents()
{
	printf("������ ���������\n");
	if (countStudents == 0) {
		printf("������ ��������� ����\n");
	}
	else {
		int maxLenSurname = 7;
		NodeList* ptr = begin_;
		while (ptr != nullptr)
		{
			maxLenSurname = ptr->data.surname_.size() > maxLenSurname ?
				ptr->data.surname_.size() : maxLenSurname;
		
			ptr = ptr->next;
		}

		for (int i = 0; i < maxLenSurname + 101; i++) {
			printf("-");
		}
		printf("\n|  �|�������");
		for (int i = 0; i < maxLenSurname + 5 - 7; i++) {
			printf(" ");
		}
		printf("|��� ��������|��� �����������|������� ������|������� ������ ����������|������� �����������|\n");
		for (int i = 0; i < maxLenSurname + 101; i++) {
			printf("-");
		}printf("\n");

		int i = 0;
		ptr = begin_;
		while (ptr != nullptr)
		{
			printf("|%3d|", i++ + 1);
			printf("%s", ptr->data.surname_.c_str());
			for (int j = 0; j < maxLenSurname - ptr->data.surname_.size(); j++) {
				printf(" ");
			}
			printf(" %s", ptr->data.inicials_.c_str());
			printf("|%-12d|", ptr->data.yearOfBirth_);
			printf("%-15d", ptr->data.yearOfAdmission_);
			printf("|%-14d|", ptr->data.studentsRecordBook_.physicsMark);
			printf("%-25d", ptr->data.studentsRecordBook_.higherMathMark);
			printf("|%-19d|\n", ptr->data.studentsRecordBook_.computerScienceMark);
			for (int i = 0; i < maxLenSurname + 101; i++) {
				printf("-");
			}printf("\n");
			ptr = ptr->next;
		}
	}
}

void StudentList::printStudentsWhoHasMarksThree()
{
	printf("������ ���������\n");
	if (countStudents == 0) {
		printf("������ ��������� ����\n");
	}
	else {
		int maxLenSurname = 7;
		NodeList* ptr = begin_;
		while (ptr != nullptr)
		{
			maxLenSurname = ptr->data.surname_.size() > maxLenSurname &&
				(ptr->data.studentsRecordBook_.computerScienceMark == 3 ||
					ptr->data.studentsRecordBook_.physicsMark == 3 ||
					ptr->data.studentsRecordBook_.higherMathMark == 3) ?
				ptr->data.surname_.size() : maxLenSurname;

			ptr = ptr->next;
		}

		for (int i = 0; i < maxLenSurname + 101; i++) {
			printf("-");
		}
		printf("\n|  �|�������");
		for (int i = 0; i < maxLenSurname + 5 - 7; i++) {
			printf(" ");
		}
		printf("|��� ��������|��� �����������|������� ������|������� ������ ����������|������� �����������|\n");
		for (int i = 0; i < maxLenSurname + 101; i++) {
			printf("-");
		}printf("\n");
		int i = 0;
		bool isHaventStudentsWhoWhasThree = true;
		ptr = begin_;
		while (ptr != nullptr)
		{
			if (ptr->data.studentsRecordBook_.computerScienceMark == 3 ||
				ptr->data.studentsRecordBook_.physicsMark == 3 ||
				ptr->data.studentsRecordBook_.higherMathMark == 3) {
				printf("|%3d|", i + 1);
				printf("%s", ptr->data.surname_.c_str());
				for (int j = 0; j < maxLenSurname - ptr->data.surname_.size(); j++) {
					printf(" ");
				}
				printf(" %s", ptr->data.inicials_.c_str());
				printf("|%-12d|", ptr->data.yearOfBirth_);
				printf("%-15d", ptr->data.yearOfAdmission_);
				printf("|%-14d|", ptr->data.studentsRecordBook_.physicsMark);
				printf("%-25d", ptr->data.studentsRecordBook_.higherMathMark);
				printf("|%-19d|\n", ptr->data.studentsRecordBook_.computerScienceMark);
				for (int i = 0; i < maxLenSurname + 101; i++) {
					printf("-");
				}printf("\n");
				isHaventStudentsWhoWhasThree = false;
			}
			ptr = ptr->next;
			i++;
		}
		if (isHaventStudentsWhoWhasThree) {
			printf("������ ��������� ����\n");
		}
	}
}

void StudentList::sortStudent()
{
	if (countStudents == 0) {
		printf("������ ��������� ����\n");
	}
	else {
		bool isIncorrect = false;
		int options;
		do {
			printf("�������� �������� �� ��������, �� ������ ������������� ���������\n");
			printf("1 - �� �������(� ���������� �������)\n");
			printf("2 - �� �������� �����\n");
			printf("��� ��������: ");
			options = Student::inputIntOptions();
			isIncorrect = false;
			if (options != 1 && options != 2) {
				isIncorrect = true;
				printf("�� ������� �������� ��������, ���������� ��� ���\n");
			}

		} while (isIncorrect);


		bool isSwap = false;

		NodeList* previous = nullptr;
		NodeList* ptr = begin_;
		NodeList* next = ptr->next;

		while (true)
		{
			if (next == nullptr) {
				if (!isSwap) {
					break;
				}
				ptr = begin_;
				next = ptr->next;
				previous = nullptr;
			}
			else {
				isSwap = false;
				if (options == 1 && ptr->data.surname_ > next->data.surname_ > 0 ||
					options == 2 && ptr->data.studentsRecordBook_.middleMark < next->data.studentsRecordBook_.middleMark) {
					ptr->next = next->next;
					next->next = ptr;
					if (previous != nullptr) {
						previous->next = next;
					}
					else {
						begin_ = next;
					}
					previous = next;
					next = ptr->next;
					isSwap = true;
				}
				else {
					previous = ptr;
					ptr = next;
					next = next->next;
				}
				
			}
		}

		printf("�������� ������� �������������\n");
	}
}

void StudentList::readFromFile()
{

	std::ifstream fin("Students.txt");

	Student student;

	std::string buffer;
	fin >> buffer;
	fin >> buffer;
	
	int studentNumber;

	fin >> studentNumber;


	for (int i = 0; i < studentNumber; i++) {
		fin >> buffer;
		fin >> buffer;
		fin >> buffer;

		fin >> student.surname_;
		fin >> student.inicials_;

		fin >> buffer;
		fin >> buffer;

		fin >> student.yearOfBirth_;

		fin >> buffer;
		fin >> buffer;
		fin >> buffer;
		fin >> buffer;

		fin >> student.yearOfAdmission_;

		fin >> buffer;
		fin >> buffer;
		fin >> buffer;

		fin >> student.studentsRecordBook_.physicsMark;

		fin >> buffer;
		fin >> buffer;
		fin >> buffer;
		fin >> buffer;

		fin >> student.studentsRecordBook_.higherMathMark;

		fin >> buffer;
		fin >> buffer;
		fin >> buffer;

		fin >> student.studentsRecordBook_.computerScienceMark;

		student.calculateMiddleMark();

		NodeList* newElement = new NodeList;
		newElement->data = student;
		newElement->next = nullptr;
		if (begin_ == nullptr) {
			begin_ = newElement;
		}
		else {
			NodeList* ptr = begin_;
			while (ptr->next != nullptr)
			{
				ptr = ptr->next;
			}
			ptr->next = newElement;
		}
		countStudents++;
	}
	std::cout << "���������� �� ����� ������� ���������" << std::endl;
	fin.close();
}

void StudentList::writeToFile()
{

	std::ofstream fout("Students.txt");

	fout << "���������� ���������: " << countStudents << std::endl;
	fout.close();
	fout.open("Students.txt", std::ios::app);

	NodeList* ptr = begin_;

	while (ptr != nullptr)
	{
		fout << std::endl << "������� � ��������: " << ptr->data.surname_ << " " << ptr->data.inicials_ << std::endl;
		fout << "��� ��������: " << ptr->data.yearOfBirth_ << std::endl;
		fout << "��� ����������� � �����: " << ptr->data.yearOfAdmission_ << std::endl;
		fout << "������ �� ������: " << ptr->data.studentsRecordBook_.physicsMark << std::endl;
		fout << "������ �� ������ ����������: " << ptr->data.studentsRecordBook_.higherMathMark << std::endl;
		fout << "������ �� �����������: " << ptr->data.studentsRecordBook_.computerScienceMark << std::endl;

		ptr = ptr->next;
	}

	fout.close();
	std::cout << "���������� � ��������� ������� �������� � ����" << std::endl;
}

void StudentList::menu()
{
	Student::russianAlphabet();

	printf("��� ������������ ������� ����� ��������� �����\n");

	while (true)
	{
		printf("�������� ������ �������\n");
		printf("1 - ��������� ���������� � ��������� �� �����\n");
		printf("2 - �������� ���������� � ��������� � ���� (���������� ������������ � ����� ����� �������)\n");
		printf("3 - �������� ���������� � ����� ��������\n");
		printf("4 - ���������� ���������� � ���� ��������� �� �����\n");
		printf("5 - ���������� ���������� � ����������-���������� �� �����\n");
		printf("6 - �������� ���������� � ��������\n");
		printf("7 - ������� ���������� � ��������\n");
		printf("8 - ������������� ���� ������ ���������\n");
		printf("9 - ����� �� ������� ����� ��������� �����\n");
		printf("���� �������: ");
		int options = Student::inputIntOptions();

		switch (options)
		{
		case 1:
			readFromFile();
			break;
		case 2:
			writeToFile();
			break;
		case 3:
			addStudent();
			break;
		case 4:
			printStudents();
			break;
		case 5:
			printStudentsWhoHasMarksThree();
			break;
		case 6:
			updateStudent();
			break;
		case 7:
			deleteStudent();
			break;
		case 8:
			sortStudent();
			break;
		case 9:
			printf("������� �� ������������� ������� �����\n");
			return;
		default:
			printf("�������� �������, ���������� ��� ���\n");
			break;
		}
		printf("\n\n");
	}
}
