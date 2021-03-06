#include "AcademicStaff.h"

void drawAcademicStaffMenu() {
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
  drawLabel(25, 32, 2, 20, "Set week");
	drawLabel(105, 32, 2, 20, "Log out");
	drawLabel(65, 32, 2, 20, "Quit");
}

int controlAcademicStaffMenu() {
	drawLabel(25, 16, 3, 22, "");
	string textDescribeFeature[9] =
	{
		{"View/Change your information like password, email, etc"},
		{"   Classes's informtion and students's information    "},
		{"                Courses's information                 "},
		{"          Courses's schedules's information           "},
		{"                 Attendance lists                     "},
		{"                 Scoreboard lists                     "},
    {"                 Set current week                     "},
		{"                       Quit                           "},
		{"             Log out to log in screen                 "}
	};
  Point academicStaffMenuPoint[9] = { {25, 16}, {65, 16}, {105, 16}, {25, 24}, {65, 24}, {105, 24}, {25, 32}, { 65, 32 }, {105, 32} };
	int chooseControlAcademicStaffMenu = 0;
	gotoXY(50, 10);
	cout << textDescribeFeature[chooseControlAcademicStaffMenu];
	while (true) {
		if (_kbhit()) {
			char getSwitchKey = _getch();
			eraseLabel(academicStaffMenuPoint[chooseControlAcademicStaffMenu].x,
				academicStaffMenuPoint[chooseControlAcademicStaffMenu].y, 3, 22);
			gotoXY(50, 10);
			switch (getSwitchKey) {
			case 13:
				return chooseControlAcademicStaffMenu;
			case 77: case 9: //->
				if (chooseControlAcademicStaffMenu < 8) ++chooseControlAcademicStaffMenu;
				else chooseControlAcademicStaffMenu = 0;
				break;
			case 75: // <-
				if (chooseControlAcademicStaffMenu > 0) --chooseControlAcademicStaffMenu;
				else chooseControlAcademicStaffMenu = 8;
				break;
			case 72: // ^
        if (chooseControlAcademicStaffMenu < 3)
          chooseControlAcademicStaffMenu += 6;
        else
          chooseControlAcademicStaffMenu -= 3;
				break;
			case 80: // v
        if (chooseControlAcademicStaffMenu > 5)
          chooseControlAcademicStaffMenu -= 6;
        else
          chooseControlAcademicStaffMenu += 3;
				break;
      case 27:
        return 7;
			}
			drawLabel(academicStaffMenuPoint[chooseControlAcademicStaffMenu].x,
				academicStaffMenuPoint[chooseControlAcademicStaffMenu].y, 3, 22, "");
			gotoXY(50, 10);
			cout << textDescribeFeature[chooseControlAcademicStaffMenu];
		}
	}
}

void academicStaffMenu(User &staff, ListScoreboard* &listScoreboard, ListPresence* &listPresence, ListSchedules* &listSchedules, ListCourses* &listCourses) {
	int chooseFeature = -1;
	Faculty faculty;
	while (true) {
		ShowConsoleCursor(false);
		drawAcademicStaffMenu();
		chooseFeature = controlAcademicStaffMenu();
    if (chooseFeature == 8)
      break;
    else if (chooseFeature == 7) {
      if (prompExit()) {
        delete listScoreboard;
        delete listPresence;
        delete listSchedules;
        delete listCourses;
        exit(EXIT_SUCCESS);
      }
    }
    else if (chooseFeature == 0)
      accessInfo(staff);
    else if (chooseFeature == 1)
      studentMenu(faculty);
    else if (chooseFeature == 2)
      courseMenu(listCourses);
    else if (chooseFeature == 3)
      courseSchedulesMenu(listSchedules);
    else if (chooseFeature == 4)
      attendanceListMenu(listPresence);
    else if (chooseFeature == 5)
      scoreboardStaffMenu(listScoreboard);
    else if (chooseFeature == 6)
      SetCurrentWeekMenu();
	}
}