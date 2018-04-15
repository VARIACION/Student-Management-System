#include "ViewSchedules.h"

void drawFieldViewSchedules()
{
	system("cls");
	gotoXY(68, 3);
	cout << "VIEW LIST OF SCHEDULES";
	drawLabel(70, 20, 14, 40, "");
	drawLabel(57, 36, 1, 40, "");
	gotoXY(40, 5);
	cout << "Press ENTER to go back to SCHEDULE menu or TAB to choose schedule for detail";
}

void displayBasicSchedule(Schedule &schedule)
{
	ShowConsoleCursor(false);
	system("cls");
	gotoXY(70, 5);
	cout << "BASIC INFORMATION";
	drawLabel(38, 14, 5, 90, "");
	gotoXY(37, 12); cout << "Class";
	drawLabel(45, 12, 1, 15, schedule.getClassName());
	gotoXY(67, 12); cout << "Year";
	drawLabel(74, 12, 1, 15, schedule.getYear());
	gotoXY(95, 12); cout << "Semester";
	drawLabel(105, 12, 1, 15, to_string(schedule.getSemester()));
	gotoXY(37, 16); cout << "Start date";
	drawLabel(50, 16, 1, 25, schedule.getStartDate());
	gotoXY(85, 16); cout << "End date";
	drawLabel(95, 16, 1, 25, schedule.getEndDate());
	drawLabel(60, 28, 1, 15, "Next");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void displayDetailSchedule(Schedule & schedule)
{
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
	for (int i = 0; i < 6; ++i)
	{
		drawLabel(setX[i], 8, 2, 12, schedule.getSchedule(Week(i), 0));
		drawLabel(setX[i], 13, 2, 12, schedule.getSchedule(Week(i), 1));
		drawLabel(setX[i], 18, 2, 12, schedule.getSchedule(Week(i), 2));
		drawLabel(setX[i], 23, 2, 12, schedule.getSchedule(Week(i), 3));
	}
	drawLabel(60, 28, 1, 15, "Back");
	drawLabel(85, 28, 1, 15, "Ok");
}

void displaySchedule(Schedule & schedule)
{
	while (true)
	{
		displayBasicSchedule(schedule);
		int getChoose = controlAddClassMenu();
		if (getChoose == 1) return;
		else if (getChoose == 2) continue;
		else
			displayDetailSchedule(schedule);
		getChoose = controlAddClassMenu();
		if (getChoose == 1) return;
		else continue;
	}
}

void displayListSchedules(ListSchedules* & listSchedules, const int & pointSchedule)
{
	drawFieldViewSchedules();
	ShowConsoleCursor(false);
	int posY[] = { 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32 };
	for (int i = 0; i < 13; ++i)
	{
		gotoXY(60, posY[i]);
		if (i + pointSchedule < listSchedules->list.size())
			cout << pointSchedule + i << ". " << listSchedules->list[pointSchedule + i].getClassName() << "       ";
		else
			break;
	}
}

void viewSchedulesMenu(ListSchedules* & listSchedules)
{
	while (true)
	{
		int startScheduleToDisplay = 0;
		displayListSchedules(listSchedules, startScheduleToDisplay);
		while (true)
		{
			if (_kbhit())
			{
				char scroll = _getch();
				if (scroll == 13)
					return;
				else if (scroll == 9)
				{
					string getClass = getFileName(57, 36, 40, 65, 38, false, "Enter ID");
					for (size_t i = 0; i < listSchedules->list.size(); ++i)
						if (listSchedules->list[i].getClassName() == getClass)
						{
							displaySchedule(listSchedules->list[i]);
							break;
						}
				}
				else if (scroll == 80)
				{
					if (listSchedules->list.size() > 13 && startScheduleToDisplay < listSchedules->list.size() - 13)
						startScheduleToDisplay += 1;
					else if (listSchedules->list.size() > 13 && startScheduleToDisplay >= listSchedules->list.size() - 13)
						startScheduleToDisplay = listSchedules->list.size() - 13;
					else
						startScheduleToDisplay = 0;
				}
				else if (scroll == 72)
				{
					if (startScheduleToDisplay > 0)
						startScheduleToDisplay -= 1;
					else
						startScheduleToDisplay = 0;
				}
				displayListSchedules(listSchedules, startScheduleToDisplay);
			}
		}
	}
}