#include "AcademicStaff.h"

void drawAcademicStaffMenu()
{
	system("cls");
	gotoXY(67, 6);
	cout << "ACADEMIC STAFF";
	drawLabel(23, 24, 12, 120, "");
	drawLabel(25, 16, 2, 20, "Information");
	drawLabel(65, 16, 2, 20, "Students");
	drawLabel(105, 16, 2, 20, "Courses");
	drawLabel(25, 24, 2, 20, "Schedules");
	drawLabel(65, 24, 2, 20, "Attendance");
	drawLabel(105, 24, 2, 20, "Scoreboard");
	drawLabel(105, 32, 2, 20, "Log out");
	drawLabel(65, 32, 2, 20, "Quit");
}

int controlAcademicStaffMenu()
{
	drawLabel(25, 16, 3, 22, "");
	string textDescribeFeature[8] =
	{
		{"View/Change your information like password, email, etc"},
		{"   Classes's informtion and students's information    "},
		{"                Courses's information                 "},
		{"          Courses's schedules's information           "},
		{"                 Attendance lists                     "},
		{"                 Scoreboard lists                     "},
		{"                       Quit                           "},
		{"             Log out to log in screen                 "}
	};
	Point academicStaffMenuPoint[8] = { {25, 16}, {65, 16}, {105, 16}, {25, 24}, {65, 24}, {105, 24}, { 65, 32 }, {105, 32} };
	int chooseControlAcademicStaffMenu = 0;
	gotoXY(50, 10);
	cout << textDescribeFeature[chooseControlAcademicStaffMenu];
	while (true)
	{
		if (_kbhit())
		{
			char getSwitchKey = _getch();
			eraseLabel(academicStaffMenuPoint[chooseControlAcademicStaffMenu].x,
				academicStaffMenuPoint[chooseControlAcademicStaffMenu].y, 3, 22);
			gotoXY(50, 10);
			switch (getSwitchKey)
			{
			case 13:
				return chooseControlAcademicStaffMenu;
			case 77: case 9: //->
				if (chooseControlAcademicStaffMenu < 7) ++chooseControlAcademicStaffMenu;
				else chooseControlAcademicStaffMenu = 0;
				break;
			case 75: // <-
				if (chooseControlAcademicStaffMenu > 0) --chooseControlAcademicStaffMenu;
				else chooseControlAcademicStaffMenu = 7;
				break;
			case 72: // ^
				if (chooseControlAcademicStaffMenu == 0) chooseControlAcademicStaffMenu = 3;
				else if (chooseControlAcademicStaffMenu == 1 || chooseControlAcademicStaffMenu == 2) 
					chooseControlAcademicStaffMenu += 5;
				else if (chooseControlAcademicStaffMenu >= 3 && chooseControlAcademicStaffMenu <= 5) 
					chooseControlAcademicStaffMenu -= 3;
				else chooseControlAcademicStaffMenu -= 2;
				break;
			case 80: // v
				if (chooseControlAcademicStaffMenu < 3) chooseControlAcademicStaffMenu += 3;
				else if (chooseControlAcademicStaffMenu == 4 || chooseControlAcademicStaffMenu == 5)
					chooseControlAcademicStaffMenu += 2;
				else if (chooseControlAcademicStaffMenu == 6 || chooseControlAcademicStaffMenu == 7)
					chooseControlAcademicStaffMenu -= 5;
				break;
			}
			drawLabel(academicStaffMenuPoint[chooseControlAcademicStaffMenu].x,
				academicStaffMenuPoint[chooseControlAcademicStaffMenu].y, 3, 22, "");
			gotoXY(50, 10);
			cout << textDescribeFeature[chooseControlAcademicStaffMenu];
		}
	}
}

void academicStaffMenu(User &staff)
{
	int chooseFeature = -1;
	Faculty faculty;
	ListCourses listCourses;
	while (true)
	{
		ShowConsoleCursor(false);
		drawAcademicStaffMenu();
		chooseFeature = controlAcademicStaffMenu();
		if (chooseFeature == 7)
			break;
		else if (chooseFeature == 6)
			prompExit();
		else if (chooseFeature == 0)
			accessInfo(staff);
		else if (chooseFeature == 1)
			studentMenu(faculty);
		else if (chooseFeature == 2)
			courseMenu(listCourses);
	}
}