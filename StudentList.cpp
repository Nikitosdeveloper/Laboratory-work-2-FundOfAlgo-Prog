#include "StudentList.h"

void StudentList::addStudent()
{
	countStudents++;

	printf("Введите информацию о новом студенте:\n");
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
		printf("Списко студентов пуст\n");
	}
	else {
		int index;
		do {
			printf("Выберете номер студента, информацию о котором вы хотите изменить: ");

			index = Student::inputIntOptions();
			if (index <= 0 || index > countStudents) {
				index = 0;
				printf("Вы ввели некорректный номер студента, попробуйте ещё раз\n");
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
			printf("Выберете параметр, который вы хотите изменить\n");
			printf("1 - фамилию\n");
			printf("2 - инициалы\n");
			printf("3 - год рождения\n");
			printf("4 - год поступления в БГУИР\n");
			printf("5 - оценку в зачётке\n");
			printf("Параметр для изменения: ");
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
					printf("Выберете дисциплину по которой вы хотите изменить оценку\n");
					printf("1 - физика\n");
					printf("2 - высшая математика\n");
					printf("3 - информатика\n");
					printf("Номер дисциплины: ");
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
						printf("Вы ввели неправильный номер дисциплины, попробуйте ещё раз\n");
						break;
					}
				} while (!disciplineIndex);
				//student.;
				break;
			default:
				printf("Вы выбрали неверный параметр, попробуйте ещё раз\n");
				break;
			}
		} while (!options);
		printf("Данные студента успешно обновлены\n");
	}
}

void StudentList::deleteStudent()
{
	if (countStudents == 0) {
		printf("Списко студентов пуст\n");
	}
	else {
		int index;
		do {
			printf("Выберете номер студента, информацию о котором вы удалить: ");

			index = Student::inputIntOptions();
			if (index <= 0 || index > countStudents) {
				index = 0;
				printf("Вы ввели некорректный номер студента, попробуйте ещё раз\n");
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

		printf("Студент успешно удалён\n");
	}
}

void StudentList::printStudents()
{
	printf("Список студентов\n");
	if (countStudents == 0) {
		printf("Списко студентов пуст\n");
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
		printf("\n|  №|Фамилия");
		for (int i = 0; i < maxLenSurname + 5 - 7; i++) {
			printf(" ");
		}
		printf("|Год рождения|Год поступления|Отметка Физика|Отметка высшая математика|Отметка информатика|\n");
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
	printf("Список студентов\n");
	if (countStudents == 0) {
		printf("Списко студентов пуст\n");
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
		printf("\n|  №|Фамилия");
		for (int i = 0; i < maxLenSurname + 5 - 7; i++) {
			printf(" ");
		}
		printf("|Год рождения|Год поступления|Отметка Физика|Отметка высшая математика|Отметка информатика|\n");
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
			printf("Списко студентов пуст\n");
		}
	}
}

void StudentList::sortStudent()
{
	if (countStudents == 0) {
		printf("Списко студентов пуст\n");
	}
	else {
		bool isIncorrect = false;
		int options;
		do {
			printf("Выберете параметр по которому, вы хотите отсортировать студентов\n");
			printf("1 - по фамилии(в алфавитном порядке)\n");
			printf("2 - по среднему баллу\n");
			printf("Ваш параметр: ");
			options = Student::inputIntOptions();
			isIncorrect = false;
			if (options != 1 && options != 2) {
				isIncorrect = true;
				printf("Вы выбрали неверный параметр, попробуйте ещё раз\n");
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

		printf("Студенты успешно отсортированы\n");
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
	std::cout << "Информация из файла успешно прочитана" << std::endl;
	fin.close();
}

void StudentList::writeToFile()
{

	std::ofstream fout("Students.txt");

	fout << "Количество студентов: " << countStudents << std::endl;
	fout.close();
	fout.open("Students.txt", std::ios::app);

	NodeList* ptr = begin_;

	while (ptr != nullptr)
	{
		fout << std::endl << "Фамилия и инициалы: " << ptr->data.surname_ << " " << ptr->data.inicials_ << std::endl;
		fout << "Год Рождения: " << ptr->data.yearOfBirth_ << std::endl;
		fout << "Год поступления в БГУИР: " << ptr->data.yearOfAdmission_ << std::endl;
		fout << "Оценка по физике: " << ptr->data.studentsRecordBook_.physicsMark << std::endl;
		fout << "Оценка по высшей математике: " << ptr->data.studentsRecordBook_.higherMathMark << std::endl;
		fout << "Оценка по информатике: " << ptr->data.studentsRecordBook_.computerScienceMark << std::endl;

		ptr = ptr->next;
	}

	fout.close();
	std::cout << "Информация о студентах успешно записана в файл" << std::endl;
}

void StudentList::menu()
{
	Student::russianAlphabet();

	printf("Вас приветствует система учёта студентов БГУИР\n");

	while (true)
	{
		printf("Выберете нужную команду\n");
		printf("1 - прочитать информацию о студентах из файла\n");
		printf("2 - записать информацию о студентах в файл (информация находившаяся в файле будет утеряна)\n");
		printf("3 - добавить информацию о новом студенте\n");
		printf("4 - напечатать информацию о всех студентах на экран\n");
		printf("5 - напечатать информацию о стундентах-троешниках на экран\n");
		printf("6 - обновить информацию о студенте\n");
		printf("7 - удалить информацию о студенте\n");
		printf("8 - отсортировать всех список студентов\n");
		printf("9 - выйти из системы учёта студентов БГУИР\n");
		printf("Ваша команда: ");
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
			printf("Спасибо за использование системы учёта\n");
			return;
		default:
			printf("Неверная команда, попробуйте ещё раз\n");
			break;
		}
		printf("\n\n");
	}
}
