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

int controlAddStudentMenu()
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

void addStudentMenu(Faculty & faculty)
{
	while (true)
	{
		drawFieldAddStudent();
		gotoXY(57, 10);	cout << "                                                          ";
		gotoXY(57, 10);	cout << "Enter the name of the class you want to add student";
		string classToAdd = getFileName(65, 14);
		gotoXY(57, 10);	cout << "                                                          ";
		gotoXY(60, 10);	cout << "Enter the ID of the new student you want to add";
		string idNewStudent = getFileName(65, 18);
		gotoXY(57, 10);	cout << "                                                          ";
		gotoXY(57, 10);	cout << "Enter the name of the new student you want to add";
		string nameNewStudent = getFileName(65, 22);
		gotoXY(57, 10);	cout << "                                                          ";
		int getChoose = controlAddStudentMenu();
		if (getChoose == 1)
			break;
		else if (getChoose == 2)
			continue;
	}
}