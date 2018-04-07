#include "StudentRoleMenu.h"

void drawFieldStudentRoleMenu()
{
	system("cls");
	gotoXY(67, 6);
	cout << "LECTURER MENU";
	drawLabel(23, 20, 8, 120, "");
	drawLabel(25, 16, 2, 20, "Information");
	drawLabel(65, 16, 2, 20, "Check in");
	drawLabel(105, 16, 2, 20, "View check-in");
	drawLabel(25, 24, 2, 20, "View course's score");
	drawLabel(65, 24, 2, 20, "View schedules");
	drawLabel(105, 24, 2, 20, "Log out/Exit");
}

int controlStudentRoleMenu()
{
	drawLabel(25, 16, 3, 22, "");
	string textDescribeFeature[6] =
	{
		{ "                   View Information            " },
		{ "                       Check in                " },
		{ "                 View check in result          " },
		{ "                View scores of a course        " },
		{ "                     View schedules            " },
		{ "                     Log out / Exit            " }
	};
	Point courseMenuPoint[9] = { { 25, 16 },{ 65, 16 },{ 105, 16 },{ 25, 24 },{ 65, 24 }, { 105, 24 } };
	int chooseControlCourseMenu = 0;
	gotoXY(47, 10);
	cout << textDescribeFeature[chooseControlCourseMenu];
	while (true)
	{
		if (_kbhit())
		{
			char getSwitchKey = _getch();
			eraseLabel(courseMenuPoint[chooseControlCourseMenu].x, courseMenuPoint[chooseControlCourseMenu].y, 3, 22);
			switch (getSwitchKey)
			{
			case 13:
				return chooseControlCourseMenu;
			case 77: case 9:
				if (chooseControlCourseMenu < 5) ++chooseControlCourseMenu;
				else chooseControlCourseMenu = 0;
				break;
			case 75:
				if (chooseControlCourseMenu > 0) --chooseControlCourseMenu;
				else chooseControlCourseMenu = 5;
				break;
			case 72:
				if (chooseControlCourseMenu < 3) chooseControlCourseMenu += 3;
				else chooseControlCourseMenu -= 3;
				break;
			case 80:
				if (chooseControlCourseMenu > 2) chooseControlCourseMenu -= 3;
				else chooseControlCourseMenu += 3;
				break;
			}
			drawLabel(courseMenuPoint[chooseControlCourseMenu].x, courseMenuPoint[chooseControlCourseMenu].y, 3, 22, "");
			gotoXY(47, 10);
			cout << textDescribeFeature[chooseControlCourseMenu];
		}
	}
	return 0;
}

void drawFieldLogoutExit()
{
	system("cls");
	drawLabel(60, 20, 1, 15, "Log out");
	drawLabel(85, 20, 1, 15, "Exit");
}

int controlLogoutExitMenu()
{
	ShowConsoleCursor(false);
	drawLabel(60, 20, 2, 17, "");
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
					eraseLabel(60, 20, 2, 17);
					drawLabel(85, 20, 2, 17, "");
				}
				else
				{
					getButton = 0;
					eraseLabel(85, 20, 2, 17);
					drawLabel(60, 20, 2, 17, "");
				}
				break;
			case 72:
				return 2;
			}
		}
	}
}

void studentRoleMenu(ListSchedules* &listSchedule, ListPresence* &listPresence, ListScoreboard* &listScoreboard, User & student)
{
	while (true)
	{
		ShowConsoleCursor(false);
		drawFieldStudentRoleMenu();
		int getChoose = controlStudentRoleMenu();
    if (getChoose == 0)
      accessInfo(student);
    else if (getChoose == 5)
    {
      drawFieldLogoutExit();
      int exitLogout = controlLogoutExitMenu();
      if (exitLogout == 0)
        return;
      else if (exitLogout == 1)
        if (prompExit()) {
          delete listPresence;
          delete listScoreboard;
          delete listSchedule;
          exit(EXIT_SUCCESS);
        }
    }
    else if (getChoose == 4)
      viewSchedulesMenu(listSchedule);
	}
}