#include "RemoveSchedule.h"

void drawFieldRemoveSchedule()
{
	system("cls");
	gotoXY(75, 8);
	cout << "REMOVE A SCHEDULE";
  drawLabel(50, 18, 5, 70, "");
  gotoXY(47, 16);
  cout << "Class's name";
  gotoXY(47, 20);
  cout << "Semester";
  drawLabel(65, 16, 1, 45, "");
  drawLabel(65, 20, 1, 45, "");
  drawLabel(60, 28, 1, 15, "Remove");
  drawLabel(85, 28, 1, 15, "Cancel");
}

void removeScheduleMenu(ListSchedules* &listSchedules)
{
  bool messageStatus = false;
  drawFieldRemoveSchedule();
  while (true)
  {
    clearText(65, 16, 45);
    clearText(65, 20, 45);
    string getClass = getFileName(65, 16, 45, 60, 12, messageStatus, "Enter the class's schedule you want to remove");
    string getSemester = getFileName(65, 20, 45, 56, 12, messageStatus, "Enter the schedule's semester you want to remove");
    clearText(50, 12, 100);
    int getChoose = controlAddClassMenu();
    if (getChoose == 1)
      break;
    else if (getChoose == 2){
      messageStatus = false;
      continue;
    }
		else
		{
      gotoXY(50, 12);
			if (removeSchedule(listSchedules, getClass, getSemester))
				cout << "                       Succeed to remove schedule.                      ";
			else
				cout << "                       Failed to remove schedule.\a                     ";
      messageStatus = true;
		}
	}
}

bool removeSchedule(ListSchedules* & listSchedules, const string & className, const string &semester)
{
	for (size_t i = 0; i < listSchedules->list.size(); ++i)
		if (listSchedules->list[i].getClassName() == className && to_string(listSchedules->list[i].getSemester()) == semester)
		{
			listSchedules->list.erase(listSchedules->list.begin() + i);
			return true;
		}
	return false;
}