#include "AddCourse.h"

void drawFieldBasicInfo() {
	system("cls");
	gotoXY(70, 3);
	cout << "BASIC INFO";
	drawLabel(41, 14, 6, 80, "");
	gotoXY(40, 10); cout << "Code";
	drawLabel(46, 10, 1, 15, "");
	gotoXY(66, 10); cout << "Year";
	drawLabel(72, 10, 1, 20, "");
	gotoXY(96, 10); cout << "Semester";
	drawLabel(106, 10, 1, 5, "");
	gotoXY(40, 14); cout << "Name";
	drawLabel(46, 14, 1, 65, "");
	gotoXY(40, 18); cout << "Lecturer's username";
	drawLabel(61, 18, 1, 50, "");
	drawLabel(60, 28, 1, 15, "Next");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void drawFieldDateTime() {
	system("cls");
	gotoXY(70, 3);
	cout << "DATE AND TIME";
	drawLabel(41, 14, 6, 80, "");
	gotoXY(40, 12); cout << "Start";
	drawLabel(47, 12, 1, 28, "");
	gotoXY(78, 12); cout << "End";
	drawLabel(83, 12, 1, 28, "");
	gotoXY(40, 16); cout << "From";
	drawLabel(46, 16, 1, 15, "");
	gotoXY(68, 16); cout << "To";
	drawLabel(72, 16, 1, 15, "");
	gotoXY(92, 16); cout << "Day";
	drawLabel(97, 16, 1, 14, "");
	drawLabel(60, 28, 1, 15, "Add");
	drawLabel(85, 28, 1, 15, "Cancel");
}

int basicInfoMenu(string basicInfo[]) {
	while (true) {
		drawFieldBasicInfo();
		gotoXY(40, 6); cout << "                    Enter the code of the course. Eg: CTT008   ";
		basicInfo[0] = getFileName(46, 10, 15, 6, "code");
		gotoXY(40, 6); cout << "                   Enter the year of the course. Eg: 2017-2018;";
		basicInfo[1] = getFileName(72, 10, 20, 6, "year");
		gotoXY(40, 6); cout << "                      Enter the semester of the course (1-3)   ";
		basicInfo[2] = getFileName(106, 10, 5, 6, "semester");
		gotoXY(40, 6); cout << "                        Enter the full name of the course      ";
		basicInfo[3] = getFileName(46, 14, 65, 6, "course");
		gotoXY(40, 6); cout << "                     Enter the lecturer's username of the course";
		basicInfo[4] = getFileName(61, 18, 50, 6, "username");
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			return 0;
		else if (getChoose == 2)
			continue;
		else
			return 1;
	}
}

void dateTimeMenu(string dateInfo[]) {
	while (true) {
		drawFieldDateTime();
		gotoXY(40, 6); cout << "              Enter the start date of the course. Eg: 01/01/2018";
		dateInfo[0] = getFileName(47, 12, 28, 6, "start date");
		gotoXY(40, 6); cout << "              Enter the end date of the course. Eg: 12/12/2018  ";
		dateInfo[1] = getFileName(83, 12, 28, 6, "end date");
		gotoXY(40, 6); cout << "              Enter the start time of the course. Eg: 7h30      ";
		dateInfo[2] = getFileName(46, 16, 15, 6, "start time");
		gotoXY(40, 6); cout << "              Enter the end time of the course. Eg: 17h30       ";
		dateInfo[3] = getFileName(72, 16, 15, 6, "end time");
		gotoXY(40, 6); cout << "                Enter the day of the course. Eg: WEDNESDAY      ";
		dateInfo[4] = getFileName(97, 16, 14, 6, "day of week");
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			return;
		else if (getChoose == 2)
			continue;
		else return;
	}
}

void addCourseMenu(ListCourses* & listCourses) {
	Courses newCourse;
	int getChoose = 0;
	while (true) {
		string basicInfo[5];
		if (basicInfoMenu(basicInfo) == 0) return;
		newCourse.setCode(basicInfo[0]);
		if (!newCourse.setYear(basicInfo[1]) || !newCourse.setSemester(basicInfo[2][0])) {
			gotoXY(40, 6); cout << "                   Invalid data input. Please try again in 3 seconds       ";
			Sleep(3000);
			continue;
		}
		newCourse.setName(basicInfo[3]);
		newCourse.setLecturerUsername(basicInfo[4]);

		string dateInfo[5];
		dateTimeMenu(dateInfo);
		if (!newCourse.setStartDate_str(dateInfo[0]) || !newCourse.setEndDate_str(dateInfo[1]) 
			|| !newCourse.setStartTime(dateInfo[2]) || !newCourse.setEndTime(dateInfo[3]) || !newCourse.setDateOfWeek(dateInfo[4])) {
			gotoXY(40, 6); cout << "                   Invalid data input. Please try again in 3 seconds       ";
			Sleep(3000);
			continue;
		}
		listCourses->list.push_back(newCourse);
		return;
	}
}