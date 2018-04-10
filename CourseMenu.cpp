#include "CourseMenu.h"

void drawCoursesMenu() {
	system("cls");
	gotoXY(67, 6);
	cout << "EDIT COURSES";
	drawLabel(23, 20, 8, 120, "");
	drawLabel(25, 16, 2, 20, "Import/Export");
	drawLabel(65, 16, 2, 20, "Add courses");
	drawLabel(105, 16, 2, 20, "Edit courses");
	drawLabel(25, 24, 2, 20, "Remove courses");
	drawLabel(65, 24, 2, 20, "View courses");
	drawLabel(105, 24, 2, 20, "Back");
}

int controlCoursesMenu() {
	drawLabel(25, 16, 3, 22, "");
	string textDescribeFeature[6] =
	{
		{ "         Import/Export courses from a csv file" },
		{ "                   Add a new course           " },
		{ "               Edit an existing course        " },
		{ "                   Remove a course            " },
		{ "                 View list of courses         " },
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

void courseMenu(ListCourses* & listCourses) {
	while (true) {
		ShowConsoleCursor(false);
		drawCoursesMenu();
		int getChoose = controlCoursesMenu();
		if (getChoose == 5)
			return;
		else if (getChoose == 0)
			importExportCoursesMenu(listCourses);
		else if (getChoose == 1)
			addCourseMenu(listCourses);
		else if (getChoose == 2)
			editCourseMenu(listCourses);
		else if (getChoose == 3)
			removeCourseMenu(listCourses);
		else if (getChoose == 4)
			viewCourseMenu(listCourses);
	}
}