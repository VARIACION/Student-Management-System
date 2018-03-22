#include "AttendanceList.h"

void drawFieldAttendanceList()
{
	system("cls");
	gotoXY(67, 6);
	cout << "EDIT COURSES";
	drawLabel(21, 16, 4, 110, "");
	drawLabel(25, 16, 2, 20, "Search/View");
	drawLabel(65, 16, 2, 20, "Export");
	drawLabel(105, 16, 2, 20, "Back");
}

int controlAttendanceListMenu()
{
	drawLabel(25, 16, 3, 22, "");
	string textDescribeFeature[3] =
	{
		{ "        Search and view attendance list of a course" },
		{ "                  Export attendance list           " },
		{ "                Back to ACADEMIC STAFF menu        "}
	};
	Point courseMenuPoint[9] = { { 25, 16 },{ 65, 16 },{ 105, 16 } };
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
				if (chooseControlCourseMenu < 2) ++chooseControlCourseMenu;
				else chooseControlCourseMenu = 0;
				break;
			case 75:
				if (chooseControlCourseMenu > 0) --chooseControlCourseMenu;
				else chooseControlCourseMenu = 2;
				break;
			}
			drawLabel(courseMenuPoint[chooseControlCourseMenu].x, courseMenuPoint[chooseControlCourseMenu].y, 3, 22, "");
			gotoXY(47, 10);
			cout << textDescribeFeature[chooseControlCourseMenu];
		}
	}
}

void attendanceListMenu()
{
	while (true)
	{
		drawFieldAttendanceList();
		int getChoose = controlAttendanceListMenu();
		if (getChoose == 2)
			return;
	}
}