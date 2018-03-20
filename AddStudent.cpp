#include "AddStudent.h"

void drawFieldAddStudent()
{
	system("cls");
	gotoXY(68, 8);
	cout << "ADD A NEW STUDENT TO CLASS";
	drawLabel(50, 18, 6, 70, "");
	gotoXY(47, 14);
	cout << "Class to add";
	gotoXY(47, 18);
	cout << "Student's ID";
	gotoXY(47, 22);
	cout << "Student's name";
	drawLabel(65, 14, 1, 45, "");
	drawLabel(65, 18, 1, 45, "");
	drawLabel(65, 22, 1, 45, "");
	drawLabel(60, 28, 1, 15, "Add..");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void addStudentMenu(Faculty & faculty)
{
	int checkIfAddSuccess = 0;
	while (true)
	{
		drawFieldAddStudent();
		gotoXY(55, 10);	cout << "                                                                  ";
		gotoXY(57, 10);	cout << "Enter the name of the class you want to add student";
		string classToAdd = getFileName(65, 14, "class");
		gotoXY(57, 10);	cout << "                                                                  ";
		gotoXY(60, 10);	cout << "Enter the ID of the new student you want to add";
		string idNewStudent = getFileName(65, 18, "id");
		gotoXY(57, 10);	cout << "                                                                  ";
		gotoXY(57, 10);	cout << "Enter the name of the new student you want to add";
		string nameNewStudent = getFileName(65, 22, "student");
		gotoXY(57, 10);	cout << "                                                                  ";
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			break;
		else if (getChoose == 2)
			continue;
		else
		{
			if (!addNewStudent(faculty, classToAdd, idNewStudent, nameNewStudent))
			{
				gotoXY(50, 10);
				cout << "Failed to add new student. Check your data and try again in 3 seconds";
				Sleep(3000);
			}
			else
			{
				gotoXY(45, 10);
				cout << "Succeed to add new student. You will be back to STUDENT menu in 3 seconds";
				Sleep(3000);
				return;
			}
		}
	}
}

bool addNewStudent(Faculty &faculty, const string & className, const string & ID, const string & name)
{
	for (auto i : faculty.classMember)
		if (i.name == className)
		{
			Student *newStudent = new Student;
			newStudent->setName(name);
			if (!newStudent->setId(ID))
			{
				delete newStudent;
				return false;
			}
			if (!i.student->nextStudent || ID <= to_string(i.student->nextStudent->getId()))
			{
				newStudent->setNo(1);
				newStudent->nextStudent = i.student->nextStudent;
				i.student->nextStudent = newStudent;
			}
			else
				for (Student *j = i.student->nextStudent; j; j = j->nextStudent)
					if (to_string(j->getId()) <= ID)
						if (!j->nextStudent)
						{
							j->nextStudent = newStudent;
							newStudent->setNo(j->nextStudent->getNo() + 1);
							break;
						}
						else if (to_string(j->nextStudent->getId()) >= ID)
						{
							newStudent->nextStudent = j->nextStudent;
							j->nextStudent = newStudent;
							newStudent->setNo(j->getNo() + 1);
							break;
						}
			for (Student *j = newStudent->nextStudent; j; j = j->nextStudent)
				j->setNo(j->getNo() + 1);
			return true;
		}
	return false;
}
