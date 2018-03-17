#include "StudentMenu.h"

void drawStudentMenu()
{
	system("cls");
	gotoXY(67, 6);
	cout << "EDIT CLASS AND STUDENT";
	drawLabel(23, 24, 12, 120, "");
	drawLabel(25, 16, 2, 20, "Import/Export");
	drawLabel(65, 16, 2, 20, "Add student");
	drawLabel(105, 16, 2, 20, "Edit");
	drawLabel(25, 24, 2, 20, "Remove");
	drawLabel(65, 24, 2, 20, "Change");
	drawLabel(105, 24, 2, 20, "Add class");
	drawLabel(105, 32, 2, 20, "View classes");
	drawLabel(65, 32, 2, 20, "View students");
	drawLabel(25, 32, 2, 20, "Back");
}

int controlStudentMenu()
{
	drawLabel(25, 16, 3, 22, "");
	string textDescribeFeature[9] =
	{
		{ "   Import/Export students of a class from a csv file" },
		{ "             Add a new student to a class" },
		{ "               Edit an existing student" },
		{ "                   Remove a student" },
		{ "        Change students from class A to class B" },
		{ "                 Add a new empty class" },
		{ "              Back to ACADEMIC STAFF menu" },
		{ "           View list of students in a class" },
		{ "                 View list of classes" }
	};
	Point academicStaffMenuPoint[9] = { { 25, 16 }, { 65, 16 }, { 105, 16 }, { 25, 24 }, { 65, 24 },
	{ 105, 24 }, { 25, 32 }, { 65, 32 }, { 105, 32 } };
	int chooseControlStudentMenu = 0;
	gotoXY(50, 10);
	cout << textDescribeFeature[chooseControlStudentMenu];
	while (true)
	{
		if (_kbhit())
		{
			char getSwitchKey = _getch();
			eraseLabel(academicStaffMenuPoint[chooseControlStudentMenu].x,
				academicStaffMenuPoint[chooseControlStudentMenu].y, 3, 22);
			gotoXY(50, 10);
			cout << "                                                                             ";
			switch (getSwitchKey)
			{
			case 13:
				return chooseControlStudentMenu;
			case 77: case 9: //->
				if (chooseControlStudentMenu < 8) ++chooseControlStudentMenu;
				else chooseControlStudentMenu = 0;
				break;
			case 75: // <-
				if (chooseControlStudentMenu > 0) --chooseControlStudentMenu;
				else chooseControlStudentMenu = 8;
				break;
			case 72: // ^
				if (chooseControlStudentMenu >= 0 && chooseControlStudentMenu <= 2)
					chooseControlStudentMenu += 6;
				else
					chooseControlStudentMenu -= 3;
				break;
			case 80: // v
				if (chooseControlStudentMenu >= 6 && chooseControlStudentMenu <= 8)
					chooseControlStudentMenu -= 6;
				else
					chooseControlStudentMenu += 3;
				break;
			}
			drawLabel(academicStaffMenuPoint[chooseControlStudentMenu].x,
				academicStaffMenuPoint[chooseControlStudentMenu].y, 3, 22, "");
			gotoXY(50, 10);
			cout << textDescribeFeature[chooseControlStudentMenu];
			gotoXY(academicStaffMenuPoint[chooseControlStudentMenu].x,
				academicStaffMenuPoint[chooseControlStudentMenu].y);
		}
	}
}

void studentMenu(Faculty &faculty)
{
	while (true)
	{
		ShowConsoleCursor(false);
		drawStudentMenu();
		int getChoose = controlStudentMenu();
		if (getChoose == 6)
			return;
		else if (getChoose == 0)
			importExportStudentFromFile(faculty);
		else if (getChoose == 1)
			addStudentMenu(faculty);
		else if (getChoose == 2)
			editStudentMenu(faculty);
		else if (getChoose == 3)
			removeStudentMenu(faculty);
		else if (getChoose == 4)
			changeClassMenu(faculty);
		else if (getChoose == 5)
			addClassMenu(faculty);
	}
}