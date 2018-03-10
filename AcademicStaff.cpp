#include "AcademicStaff.h"

void drawAcademicStaffMenu()
{
	system("cls");
	gotoXY(67, 6);
	cout << "ACADEMIC STAFF";
	drawLabel(20, 20, 8, 120, "");
	drawLabel(25, 16, 2, 20, "Information");
	drawLabel(65, 16, 2, 20, "Students");
	drawLabel(105, 16, 2, 20, "Courses");
	drawLabel(25, 24, 2, 20, "Schedules");
	drawLabel(65, 24, 2, 20, "Attendance");
	drawLabel(105, 24, 2, 20, "Scoreboard");
	drawLabel(105, 32, 2, 20, "Log out");
}

int controlAcademicStaffMenu()
{
	drawLabel(25, 16, 3, 22, "");
	string textDescribeFeature[7] =
	{
		{"View/Change your information like password, email, etc."},
		{"   Classes's informtion and students's information."},
		{"                Courses's information."},
		{"          Courses's schedules's information."},
		{"                 Attendance lists."},
		{"                 Scoreboard lists."},
		{"             Log out to log in screen."}
	};
	Point academicStaffMenuPoint[7] = { {25, 16}, {65, 16}, {105, 16}, {25, 24}, {65, 24}, {105, 24}, {105, 32} };
	int chooseControlAcademicStaffMenu = 0;
	while (true)
	{
		if (_kbhit())
		{
			char getSwitchKey = _getch();
			eraseLabel(academicStaffMenuPoint[chooseControlAcademicStaffMenu].x,
				academicStaffMenuPoint[chooseControlAcademicStaffMenu].y, 3, 22);
			gotoXY(50, 10);
			cout << "                                                                             ";
			switch (getSwitchKey)
			{
			case 13:
				return chooseControlAcademicStaffMenu;
			case 77: //->
				if (chooseControlAcademicStaffMenu < 6) ++chooseControlAcademicStaffMenu;
				else chooseControlAcademicStaffMenu = 0;
				break;
			case 75: // <-
				if (chooseControlAcademicStaffMenu > 0) --chooseControlAcademicStaffMenu;
				else chooseControlAcademicStaffMenu = 6;
				break;
			case 72: // ^
				if (chooseControlAcademicStaffMenu < 2) chooseControlAcademicStaffMenu += 3;
				else if (chooseControlAcademicStaffMenu == 6) chooseControlAcademicStaffMenu = 5;
				else if (chooseControlAcademicStaffMenu == 2) chooseControlAcademicStaffMenu = 6;
				else chooseControlAcademicStaffMenu -= 3;
				break;
			case 80: // v
				if (chooseControlAcademicStaffMenu < 3) chooseControlAcademicStaffMenu += 3;
				else if (chooseControlAcademicStaffMenu == 5) chooseControlAcademicStaffMenu = 6;
				else if (chooseControlAcademicStaffMenu == 6) chooseControlAcademicStaffMenu = 2;
				else chooseControlAcademicStaffMenu -= 3;
				break;
			}
			drawLabel(academicStaffMenuPoint[chooseControlAcademicStaffMenu].x,
				academicStaffMenuPoint[chooseControlAcademicStaffMenu].y, 3, 22, "");
			gotoXY(50, 10);
			cout << textDescribeFeature[chooseControlAcademicStaffMenu];
			gotoXY(academicStaffMenuPoint[chooseControlAcademicStaffMenu].x,
				academicStaffMenuPoint[chooseControlAcademicStaffMenu].y);
		}
	}
}

void academicStaffMenu()
{
	ShowConsoleCursor(false);
	int chooseFeature = -1;
	while (true)
	{
		drawAcademicStaffMenu();
		chooseFeature = controlAcademicStaffMenu();
		if (chooseFeature == 6)
			break;
	}
	loginMenu();
}
