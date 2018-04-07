#include "CourseSchedules.h"

void drawFieldCourseSchedulesMenu() {
	system("cls");
	gotoXY(67, 6);
	cout << "EDIT COURSES";
	drawLabel(23, 20, 8, 120, "");
	drawLabel(25, 16, 2, 20, "Import/Export");
	drawLabel(65, 16, 2, 20, "Add schedule");
	drawLabel(105, 16, 2, 20, "Edit schedule");
	drawLabel(25, 24, 2, 20, "Remove schedule");
	drawLabel(65, 24, 2, 20, "View schedules");
	drawLabel(105, 24, 2, 20, "Back");
}

int controlCourseSchedulesMenu() {
	drawLabel(25, 16, 3, 22, "");
	string textDescribeFeature[6] =
	{
		{ "         Import/Export schedules from a csv file" },
		{ "                   Add a new schedule           " },
		{ "               Edit an existing schedule        " },
		{ "                   Remove a schedule            " },
		{ "                 View list of schedules         " },
		{ "              Back to ACADEMIC STAFF menu     "}
	};
	Point courseMenuPoint[9] = { { 25, 16 },{ 65, 16 },{ 105, 16 },{ 25, 24 },{ 65, 24 }, { 105, 24 } };
	int chooseControlCourseMenu = 0;
	gotoXY(47, 10);
	cout << textDescribeFeature[chooseControlCourseMenu];
	while (true) {
		if (_kbhit()) {
			char getSwitchKey = _getch();
			eraseLabel(courseMenuPoint[chooseControlCourseMenu].x, courseMenuPoint[chooseControlCourseMenu].y, 3, 22);
			switch (getSwitchKey) {
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
}

ListSchedules * courseSchedulesMenu() {
	ListSchedules *listSchedules = new ListSchedules;
	while (true) {
		ShowConsoleCursor(false);
		drawFieldCourseSchedulesMenu();
		int getChoose = controlCourseSchedulesMenu();
    if (getChoose == 5)
      return listSchedules;
		else if (getChoose == 0)
			importExportSchedulesMenu(listSchedules);
		else if (getChoose == 1)
			addScheduleMenu(listSchedules);
		else if (getChoose == 2)
			editScheduleMenu(listSchedules);
		else if (getChoose == 3)
			removeScheduleMenu(listSchedules);
		else if (getChoose == 4)
			viewSchedulesMenu(listSchedules);
	}
  return listSchedules;
}