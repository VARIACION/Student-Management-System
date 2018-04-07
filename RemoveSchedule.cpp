#include "RemoveSchedule.h"

void drawFieldRemoveSchedule()
{
	system("cls");
	gotoXY(75, 12);
	cout << "REMOVE A SCHEDULE";
	drawLabel(50, 20, 4, 70, "");
	gotoXY(50, 20);
	cout << "Class name";
	drawLabel(65, 20, 1, 45, "");
	drawLabel(60, 28, 1, 15, "Remove");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void removeScheduleMenu(ListSchedules* &listSchedules)
{
	int checkIfRemoveSuccess = 0;
	while (true)
	{
		drawFieldRemoveSchedule();
		gotoXY(60, 15);	cout << "                                                                        ";
		gotoXY(60, 15);	cout << "Enter the class's schedule you want to remove";
		string getClass = getFileName(65, 20, "code");
		gotoXY(60, 15);	cout << "                                                                        ";
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			break;
		else if (getChoose == 2)
			continue;
		else
		{
			if (removeSchedule(listSchedules, getClass))
			{
				gotoXY(50, 15); cout << "Succeed to remove schedule. You will be back to SCHEDULE menu in 3 seconds.";
				Sleep(1000);
				return;
			}
			else
			{
				gotoXY(60, 15); cout << "Failed to remove schedule. Try again in 3 seconds.";
				Sleep(1000);
			}
		}
	}
}

bool removeSchedule(ListSchedules* & listSchedules, const string & className)
{
	for (size_t i = 0; i < listSchedules->list.size(); ++i)
		if (listSchedules->list[i].getClassName() == className)
		{
			listSchedules->list.erase(listSchedules->list.begin() + i);
			return true;
		}
	return false;
}