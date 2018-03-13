#include "Class.h"

Class::Class()
{
	this->name = "";
	if (this->student != nullptr)
		this->student = nullptr;
}

Faculty::~Faculty()
{
	for (auto i : this->classMember)
		deleteClass(i);
}

void deleteClass(Class & classMember)
{
	Student *getStudent = nullptr;
	while (classMember.student)
	{
		getStudent = classMember.student;
		classMember.student = classMember.student->nextStudent;
		delete getStudent;
	}
}
