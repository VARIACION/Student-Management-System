#include "EditSchedule.h"

void drawFieldEditSchedule()
{
	system("cls");
	gotoXY(75, 12);
	cout << "EDIT A SCHEDULE";
	drawLabel(50, 20, 4, 70, "");
	gotoXY(50, 20);
	cout << "Class's name";
	drawLabel(65, 20, 1, 45, "");
	drawLabel(60, 28, 1, 15, "Edit");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void editScheduleMenu(ListSchedules & listSchedules)
{
	int checkIfEditSuccess = 0;
	while (true)
	{
		drawFieldEditSchedule();
		gotoXY(60, 15);	cout << "                                                                        ";
		gotoXY(60, 15);	cout << "Enter the schedule of class you want to edit";
		string schedule = getFileName(65, 20, "class");
		gotoXY(60, 15);	cout << "                                                                        ";
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			break;
		else if (getChoose == 2)
			continue;
		else
		{
			bool checkExist = false;
			for (int i = 0; i < listSchedules.list.size(); ++i)
				if (listSchedules.list[i].getClassName() == schedule)
				{
					listSchedules.list.erase(listSchedules.list.begin() + i);
					checkExist = true;
					break;
				}
			if (checkExist)
				addScheduleMenu(listSchedules);
		}
	}
}