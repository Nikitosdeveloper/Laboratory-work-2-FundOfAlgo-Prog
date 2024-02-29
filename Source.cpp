#include "SingleLinkedList.h"
#include "SingleStudentLinkedList.h"
#include "Queue.h"
#include "StackStudent.h"
#include "StackChar.h"

int main() {

	
	StackStudent stk;

	Student a("Яковлев", "Н. Е.", 2005, 2023, RecordBook(9, 9, 9));
	Student b("Яковлев", "Н. Д.", 2005, 2023, RecordBook(9, 9, 9));
	Student c("Ковалвевский", "Н. Д.", 2005, 2023, RecordBook(9, 9, 9));

	stk.push(a);
	stk.push(b);
	stk.push(c);

	while (!stk.isEmpty())
	{
		stk.remove().printStudent();
	}
	
	


	return 0;
}