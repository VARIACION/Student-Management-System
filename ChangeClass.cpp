#include "ChangeClass.h"

void drawFieldChangeClass()
{
	system("cls");
	gotoXY(65, 8);
	cout << "CHANGE STUDENT TO ANOTHER CLASS";
	drawLabel(50, 18, 5, 70, "");
	gotoXY(47, 16);
	cout << "Student's ID";
	gotoXY(47, 20);
	cout << "Class to change";
	drawLabel(65, 16, 1, 45, "");
	drawLabel(65, 20, 1, 45, "");
	drawLabel(60, 28, 1, 15, "Change");
	drawLabel(85, 28, 1, 15, "Cancel");
}

int controlChangeClassMenu()
{
	ShowConsoleCursor(false);
	drawLabel(60, 28, 2, 17, "");
	int getButton = 0;
	while (true)
	{
		if (_kbhit())
		{
			char getSwitchKey = _getch();
			switch (getSwitchKey)
			{
			case 13:
				return getButton;
			case 75: case 77: case 9:
				if (getButton == 0)
				{
					getButton = 1;
					eraseLabel(60, 28, 2, 17);
					drawLabel(85, 28, 2, 17, "");
				}
				else
				{
					getButton = 0;
					eraseLabel(85, 28, 2, 17);
					drawLabel(60, 28, 2, 17, "");
				}
				break;
			case 72:
				return 2;
			}
		}
	}
}

void changeClassMenu(Faculty &faculty)
{
	while (true)
	{
		drawFieldChangeClass();
		gotoXY(50, 12);	cout << "                                                                        ";
		gotoXY(54, 12);	cout << "Enter the ID of the student you want to change class";
		string idStudentChange = getFileName(65, 16);
		gotoXY(50, 12);	cout << "                                                                        ";
		gotoXY(67, 12);	cout << "Enter the name of the class";
		string classStudentChange = getFileName(65, 20);
		gotoXY(50, 12);	cout << "                                                                        ";
		int getChoose = controlRemoveStudentMenu();
		if (getChoose == 1)
			break;
		else if (getChoose == 2)
			continue;
		else
		{
			if (changeClass(faculty, idStudentChange, classStudentChange))
			{
				gotoXY(45, 12);
				cout << "Succeed to change class. You will be back to STUDENT menu in 3 seconds.";
				Sleep(3000);
				return;
			}
			else
			{
				gotoXY(50, 12);
				cout << "Failed to change class. Check the data and try again in 3 seconds";
				Sleep(3000);
			}
		}
	}
}

bool changeClass(Faculty &faculty, const string &id, const string &newClass)
{
	bool checkExistedClass = false;
	string currentClassHaveStudent = "";

	for (auto i : faculty.classMember)
		if (newClass == i.name)
			checkExistedClass = true;

	for (auto i : faculty.classMember)
	{
		for (Student *j = i.student->nextStudent; j; j = j->nextStudent)
			if (to_string(j->getId()) == id)
				if (checkExistedClass)
				{
					addNewStudent(faculty, newClass, id, j->getName());
					removeStudent(faculty, id, i.name);
					return true;
				}
				else
					return false;
	}
	return false;
}