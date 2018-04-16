#include "AddSchedule.h"

void drawFieldBasicInfoSchedule() {
	system("cls");
	gotoXY(70, 5);
	cout << "ADD A SCHEDULE";
	drawLabel(38, 14, 5, 90, "");
	gotoXY(37, 12); cout << "Class";
	drawLabel(45, 12, 1, 15, "");
	gotoXY(67, 12); cout << "Year";
	drawLabel(74, 12, 1, 15, "");
	gotoXY(95, 12); cout << "Semester";
	drawLabel(105, 12, 1, 15, "");
	gotoXY(37, 16); cout << "Start date";
	drawLabel(50, 16, 1, 25, "");
	gotoXY(85, 16); cout << "End date";
	drawLabel(95, 16, 1, 25, "");
	drawLabel(60, 28, 1, 15, "Next");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void drawFieldAddSchedule() {
	system("cls");
	gotoXY(35, 5);
	cout << "    MONDAY    |    TUESDAY   |   WEDNESDAY  |   THURSDAY   |    FRIDAY    |   SATURDAY   ";
	gotoXY(20, 8); cout << "7h30-9h15";
	gotoXY(20, 13); cout << "9h30-11h15";
	gotoXY(20, 18); cout << "13h30-15h15";
	gotoXY(20, 23); cout << "15h30-17h00";
	int setX[6];	setX[0] = 37;
	for (int i = 1; i < 6; ++i)
		setX[i] = setX[i - 1] + 15;
	for (int i = 0; i < 6; ++i) {
		drawLabel(setX[i], 8, 2, 12, "");
		drawLabel(setX[i], 13, 2, 12, "");
		drawLabel(setX[i], 18, 2, 12, "");
		drawLabel(setX[i], 23, 2, 12, "");
	}
	drawLabel(60, 28, 1, 15, "Add");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void inputBasicInfoSchedule(string basicInfo[], bool &invalidInformation) {
	ShowConsoleCursor(false);

   clearText(45, 12, 15);
   clearText(74, 12, 15);
   clearText(105, 12, 15);
   clearText(50, 16, 25);
   clearText(95, 16, 25);
		
	basicInfo[0] = getFileName(45, 12, 15, 70, 7, invalidInformation, "Enter class");
  invalidInformation = false;

	basicInfo[1] = getFileName(74, 12, 15, 70, 7, invalidInformation, "Enter year");

	basicInfo[2] = getFileName(105, 12, 15, 69, 7, invalidInformation, "Enter semester");

	basicInfo[3] = getFileName(50, 16, 25, 61, 7, invalidInformation, "Enter the start date of schedule");
		
	basicInfo[4] = getFileName(95, 16, 25, 61, 7, invalidInformation, "Enter the end date of schedule");
		
}

void inputSchedule(Schedule & schedule) {
	drawFieldAddSchedule();
	int setX[6];	setX[0] = 37;
	for (int i = 1; i < 6; ++i)
		setX[i] = setX[i - 1] + 15;

	int setY[] = { 8, 13, 18, 23 };

	for (int i = 0; i < 4; ++i) {
		for (Week j = (Week)0; j != SUNDAY; j = (Week)(j + 1)) {
			string courseInput = getFileName(setX[j], setY[i], 12, 70, 3, false, "Enter course");
			schedule.setSchedule(j, i, courseInput);
		}
	}
}

void addScheduleMenu(ListSchedules* & listSchedules) {
  int getChoose;
  bool messageStatus = false;
	while (true) {
    Schedule newSchedule;
    string basicInfo[5];
    drawFieldBasicInfoSchedule();
    if (messageStatus) {
      gotoXY(50, 7);
      cout << "                 Found a same schedule in system.      \a";
    }
    messageStatus = false;
    while (true) {
      inputBasicInfoSchedule(basicInfo, messageStatus);
      int getChoose = controlAddClassMenu();
      if (getChoose == 1) return;
      else if (getChoose == 2) continue;

      if (basicInfo[0].length() == 0) {
        messageStatus = true;
        gotoXY(50, 7);
        cout << "               Name of class can not be empty.\a      ";
        continue;
      }

      if (!newSchedule.setYear(basicInfo[1])) {
        messageStatus = true;
        gotoXY(50, 7);
        cout << "                   Invalid year format.\a               ";
        continue;
      }

      if (!newSchedule.setSemester(basicInfo[2][0] - '0')) {
        messageStatus = true;
        gotoXY(50, 7);
        cout << "                 Invalid semester format.\a              ";
        continue;
      }

      string temp = basicInfo[3];
      if (!newSchedule.setStartDate(basicInfo[3])) {
        messageStatus = true;
        gotoXY(50, 7);
        cout << "                   Invalid date format.              \a";
        continue;
      }
      basicInfo[3] = temp;

      temp = basicInfo[4];
      if (!newSchedule.setEndDate(basicInfo[4])) {
        messageStatus = true;
        gotoXY(50, 7);
        cout << "                   Invalid date format.              \a";
        continue;
      }
      basicInfo[4] = temp;

      if (newSchedule.compareStartEndDate()) {
        messageStatus = true;
        gotoXY(50, 7);
        cout << "          Start date can not be after End date.       \a";
        continue;
      }
      break;
    }

    inputSchedule(newSchedule);
    getChoose = controlAddClassMenu();
    if (getChoose == 1) return;
    else if (getChoose == 2) continue;
    newSchedule.setClassName(basicInfo[0]);
    newSchedule.setYear(basicInfo[1]);
    newSchedule.setSemester(basicInfo[2][0] - '0');
    newSchedule.setStartDate(basicInfo[3]);
    newSchedule.setEndDate(basicInfo[4]);
    listSchedules->list.push_back(newSchedule);
		inputSchedule(newSchedule);
		getChoose = controlAddClassMenu();
		if (getChoose == 1) return;
		else if (getChoose == 2) continue;

    for (auto& i : listSchedules->list)
      if (i.getClassName() == newSchedule.getClassName() && i.getStartDate() == newSchedule.getStartDate()
          && i.getEndDate() == newSchedule.getEndDate() && i.getYear() == newSchedule.getYear() && i.getSemester() == newSchedule.getSemester()) {
        messageStatus = true;
        break;
      }

    if (!messageStatus) {
      gotoXY(50, 7);
      cout << "                  Succeed to add a new schedule.                ";
      listSchedules->list.push_back(newSchedule);
    }
	}
}