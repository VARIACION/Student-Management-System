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

void inputBasicInfoSchedule(string basicInfo[]) {
	while (true) {
		Schedule newSchedule;
		ShowConsoleCursor(false);
		drawFieldBasicInfoSchedule();
		basicInfo[0] = getFileName(45, 12, 15, 7, "class");

		basicInfo[1] = getFileName(74, 12, 15, 7, "year");
		if (!newSchedule.setYear(basicInfo[1])) continue;

		basicInfo[2] = getFileName(105, 12, 15, 7, "semester");
		if (!newSchedule.setSemester(basicInfo[2][0] - '0')) continue;

		basicInfo[3] = getFileName(50, 16, 25, 7, "start date");
		string temp = basicInfo[3];
		if (!newSchedule.setStartDate(basicInfo[3])) continue;
		basicInfo[3] = temp;
		
		basicInfo[4] = getFileName(95, 16, 25, 7, "end date");
		temp = basicInfo[4];
		if (!newSchedule.setEndDate(basicInfo[4])) continue;
		basicInfo[4] = temp;
		
		break;
	}
}

void inputSchedule(Schedule & schedule) {
	drawFieldAddSchedule();
	int setX[6];	setX[0] = 37;
	for (int i = 1; i < 6; ++i)
		setX[i] = setX[i - 1] + 15;

	int setY[] = { 8, 13, 18, 23 };

	for (int i = 0; i < 4; ++i) {
		for (Week j = (Week)0; j != SUNDAY; j = (Week)(j + 1)) {
			string courseInput = getFileName(setX[j], setY[i], 12, 7, "course");
			schedule.setSchedule(j, i, courseInput);
		}
	}
}

void addScheduleMenu(ListSchedules* & listSchedules) {
	while (true) {
		Schedule newSchedule;
		string basicInfo[5];
		inputBasicInfoSchedule(basicInfo);
		int getChoose = controlAddClassMenu();
		if (getChoose == 1) return;
		else if (getChoose == 2) continue;
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
		break;
	}
}