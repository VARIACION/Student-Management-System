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

int basicInfoMenu(string basicInfo[], bool &validInformation) {
	while (true) {
    clearText(46, 10, 15);
    clearText(72, 10, 20);
    clearText(106, 10, 5);
    clearText(46, 14, 65);
    clearText(61, 18, 50);

		basicInfo[0] = getFileName(46, 10, 15, 40, 6, validInformation, "                    Enter the code of the course. Eg: CTT008   ");
		basicInfo[1] = getFileName(72, 10, 20, 40, 6, validInformation, "                   Enter the year of the course. Eg: 2017-2018");
		basicInfo[2] = getFileName(106, 10, 5, 40, 6, validInformation, "                      Enter the semester of the course (1-3)   ");
		basicInfo[3] = getFileName(46, 14, 65, 40, 6, validInformation, "                        Enter the full name of the course     ");
		basicInfo[4] = getFileName(61, 18, 50, 40, 6, validInformation, "                     Enter the lecturer's username of the course");
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			return 0;
    else if (getChoose == 2) {
      validInformation = false;
      continue;
    }
		else
			return 1;
	}
}

int dateTimeMenu(string dateInfo[], bool &validInformation) {
	while (true) {
    clearText(47, 12, 28);
    clearText(83, 12, 28);
    clearText(46, 16, 15);
    clearText(72, 16, 15);
    clearText(97, 16, 14);

		dateInfo[0] = getFileName(47, 12, 28, 40, 6, validInformation, "              Enter the start date of the course. Eg: 01/01/2018");
		dateInfo[1] = getFileName(83, 12, 28, 40, 6, validInformation, "              Enter the end date of the course. Eg: 12/12/2018  ");
    dateInfo[2] = getFileName(46, 16, 15, 40, 6, validInformation, "              Enter the start time of the course. Eg: 7h30      ");
		dateInfo[3] = getFileName(72, 16, 15, 40, 6, validInformation, "              Enter the end time of the course. Eg: 17h30       ");
		dateInfo[4] = getFileName(97, 16, 14, 40, 6, validInformation, "                Enter the day of the course. Eg: WEDNESDAY      ");
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			return 1;
    else if (getChoose == 2) {
      validInformation = false;
      continue;
    }
		else 
      return 0;
	}
}

void addCourseMenu(ListCourses* & listCourses) {
	Courses newCourse;
	int getChoose = 0;
  bool validInformation = false, existCourse = false;
  string basicInfo[5], dateInfo[5];
  
  while (true) {
    drawFieldBasicInfo();
    if (existCourse) {
      gotoXY(40, 6);
      cout << "                Same course has been found. Check your data and try again\a     ";
    }
    existCourse = false;
    while (true) {
      if (basicInfoMenu(basicInfo, validInformation) == 0) return;
      newCourse.setCode(basicInfo[0]);
      gotoXY(40, 6);
      if (!newCourse.setYear(basicInfo[1])) {
        cout << "                   Invalid year input. Check your year and try again       \a";
        validInformation = true;
        continue;
      }
      if (!newCourse.setSemester(basicInfo[2][0])) {
        cout << "               Invalid semester input. Check your semester and try again\a    ";
        validInformation = true;
        continue;
      }

      if (basicInfo[3].length() == 0) {
        cout << "              Invalid course's name input. Course's name can not be empty\a      ";
        validInformation = true;
        continue;
      }

      if (basicInfo[4].length() == 0) {
        cout << "      Invalid lecturer's username input. Lecturer's username can not be empty\a    ";
        validInformation = true;
        continue;
      }

      newCourse.setName(basicInfo[3]);
      newCourse.setLecturerUsername(basicInfo[4]);
      break;
    }

    drawFieldDateTime();
    while (true) {
      if (dateTimeMenu(dateInfo, validInformation) == 1)
        return;
      gotoXY(40, 6);
      if (!newCourse.setStartDate_str(dateInfo[0]) || !newCourse.setEndDate_str(dateInfo[1])) {
        cout << "                   Invalid date input. Check your date and try again       \a";
        validInformation = true;
        continue;
      }

      if (newCourse.compareStartEndDate()) {
        cout << "                      Start date can not be after End date.\a                ";
        validInformation = true;
        continue;
      }

      if (!newCourse.setStartTime(dateInfo[2]) || !newCourse.setEndTime(dateInfo[3])) {
        cout << "                   Invalid time input. Check your time and try again        \a";
        validInformation = true;
        continue;
      }

      if (newCourse.compareStartEndTime()) {
        cout << "                      Start time can not be after End time.\a                ";
        validInformation = true;
        continue;
      }

      if (!newCourse.setDateOfWeek(dateInfo[4])) {
        cout << "                Invalid day of week input. Check your day and try again\a      ";
        validInformation = true;
        continue;
      }
      break;
    }

    for (auto& i : listCourses->list)
      if (i.getCode() == newCourse.getCode() && i.getDateOfWeek_str() == newCourse.getDateOfWeek_str()
        && i.getEndDate_str() == newCourse.getEndDate_str() && i.getLecturerUsername() == newCourse.getLecturerUsername()
        && i.getSemester() == newCourse.getSemester() && i.getStartDate_str() == newCourse.getStartDate_str()
        && i.getStartTime_str() == newCourse.getStartTime_str() && i.getEndTime_str() == newCourse.getEndTime_str()) {
        validInformation = true;
        existCourse = true;
        break;
      }
    if (!existCourse)
      break;
  }
		listCourses->list.push_back(newCourse);
		return;
}