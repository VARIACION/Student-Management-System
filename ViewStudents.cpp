#include "ViewStudents.h"

void drawFieldViewStudents()
{
	system("cls");
	gotoXY(70, 12);
	cout << "VIEW STUDENTS IN CLASS";
	drawLabel(50, 20, 4, 70, "");
	gotoXY(50, 20);
	cout << "Class's Name";
	drawLabel(65, 20, 1, 45, "");
	drawLabel(60, 28, 1, 15, "View");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void drawFieldDisplayStudents()
{
	system("cls");
	gotoXY(68, 3);
	cout << "VIEW LIST OF CLASSES";
	drawLabel(55, 20, 14, 80, "");
	gotoXY(60, 5);
	cout << "Press ESC to go back to STUDENT menu";
}

void displayStudent(Student* &copyStudents, const int &pointStudent, const int &numberOfStudents)
{
	int posY[] = { 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32 };

	for (int i = 0; i < 13; ++i)
	{
		gotoXY(60, posY[i]);
		if (i + pointStudent < numberOfStudents)
			cout << "No." << copyStudents[pointStudent + i].getNo() << " - ID: "
			<< copyStudents[pointStudent + i].getId() << " - Name: " << copyStudents[pointStudent + i].getName();
		else
			break;
	}
}

void copyStudentsFromListToArray(Class &className, Student* &copyStudents)
{
	
	int count = 0;
	for (Student *i = className.student->nextStudent; i; i = i->nextStudent)
	{
		copyStudents[count].setNo(i->getNo());
		copyStudents[count].setId(i->getId());
		copyStudents[count].setName(i->getName());
		int appendWhiteCharacters = 19 + to_string(copyStudents[count].getNo()).length() + to_string(copyStudents[count].getId()).length()
			+ copyStudents[count].getName().length();
		if (appendWhiteCharacters < 57)
			for (int i = 0; i < 57 - appendWhiteCharacters; ++i)
				copyStudents[count].setName(copyStudents[count].getName() + " ");
		++count;
	}
}

bool callScreenDisplayMenu(Faculty &faculty, const string &className)
{
	bool checkExistedClass = false;
	Class checkClass;
	for (auto i : faculty.classMember)
		if (i.name == className)
		{
			checkExistedClass = true;
			checkClass = i;
		}
	if (!checkExistedClass) return false;

	int getNumberOfStudents = countNumberOfStudentsInClass(checkClass);
	Student *copyStudents = new Student[getNumberOfStudents];
	copyStudentsFromListToArray(checkClass, copyStudents);
	int markStudentByNo = 0;
	drawFieldDisplayStudents();
	displayStudent(copyStudents, markStudentByNo, getNumberOfStudents);
	while (true)
	{
		
		if (_kbhit())
		{
			char scroll = _getch();
			switch (scroll)
			{
      case 13: case 27:
				delete[] copyStudents;
        drawFieldViewStudents();
				return true;
			case 72:
				if (markStudentByNo > 0)
					markStudentByNo -= 1;
				else
					markStudentByNo = 0;
				break;
			case 80:
				if (getNumberOfStudents > 13 && markStudentByNo < getNumberOfStudents - 13)
					markStudentByNo += 1;
				else if (getNumberOfStudents > 13 && markStudentByNo >= getNumberOfStudents - 13)
					markStudentByNo = getNumberOfStudents - 13;
				else
					markStudentByNo = 0;
				break;
			}
			displayStudent(copyStudents, markStudentByNo, getNumberOfStudents);
		}
	}
}

void viewStudentsMenu(Faculty &faculty)
{
  bool messageStatus = false;
  drawFieldViewStudents();
	while (true)
	{
    clearText(65, 20, 45);
		string classToView = getFileName(65, 20, 45, 60, 15, messageStatus, "Enter the name of the class you want to view");
    clearText(50, 15, 100);
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			break;
    else if (getChoose == 2) {
      messageStatus = false;
      continue;
    }
		else
		{
			if (!callScreenDisplayMenu(faculty, classToView))
			{
				gotoXY(55, 15);
				cout << "Failed to view students. Found no class name " << classToView << "\a";
        messageStatus = true;
			}
		}
	}
}