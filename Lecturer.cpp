#include "Lecturer.h"

void drawFieldLecturer()
{
	system("cls");
	gotoXY(67, 6);
	cout << "LECTURER MENU";
	drawLabel(23, 20, 8, 120, "");
	drawLabel(25, 16, 2, 20, "Information");
	drawLabel(65, 16, 2, 20, "Import/Export");
	drawLabel(105, 16, 2, 20, "Edit grade");
	drawLabel(25, 24, 2, 20, "View scoreboard");
	drawLabel(65, 24, 2, 20, "Log out");
	drawLabel(105, 24, 2, 20, "Exit");
}

int controlLecturerMenu()
{
	drawLabel(25, 16, 3, 22, "");
	string textDescribeFeature[6] =
	{
		{ "                   View Information            " },
		{ "        Import / Export scoreboard of a course " },
		{ "               Edit grade of a student         " },
		{ "                   View a scoreboard           " },
		{ "                 Log out to LOG IN menu        " },
		{ "                          Quit                 " }
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

void lecturerMenu(User &lecturer, ListScoreboard* &listScoreboard, ListPresence* &listPresence, ListSchedules* &listSchedules)
{
	while (true)
	{
		ShowConsoleCursor(false);
		drawFieldLecturer();
		int getChoose = controlLecturerMenu();
    if (getChoose == 5) {
      if (prompExit()) {
        delete listScoreboard;
        delete listPresence;
        delete listSchedules;
        exit(EXIT_SUCCESS);
      }
    }
    else if (getChoose == 4)
      return;
    else if (getChoose == 0)
      accessInfo(lecturer);
    else if (getChoose == 1)
      importExportScoreboardMenu(listScoreboard);
    else if (getChoose == 2)
      EditGradeMenu(lecturer, listScoreboard);
    else if (getChoose == 3)
      searchViewScoreboardMenu(listScoreboard);
	}
}