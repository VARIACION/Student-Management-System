#include "EditSchedule.h"

void drawFieldEditSchedule() {
	system("cls");
	gotoXY(75, 8);
	cout << "EDIT A SCHEDULE";
  drawLabel(50, 18, 5, 70, "");
  gotoXY(47, 16);
  cout << "Class's name";
  gotoXY(47, 20);
  cout << "Semester to edit";
  drawLabel(65, 16, 1, 45, "");
  drawLabel(65, 20, 1, 45, "");
  drawLabel(60, 28, 1, 15, "Edit");
  drawLabel(85, 28, 1, 15, "Cancel");
}

void editScheduleMenu(ListSchedules* & listSchedules) {
  bool messageStatus = false;
  int checkIfEditSuccess = 1;
	while (true) {
    drawFieldEditSchedule();
    if (checkIfEditSuccess == -1) {
      gotoXY(50, 12);
      cout << "Failed to edit schedule. Found no schedule like input information.\a";
    } else if (checkIfEditSuccess == 0) {
      gotoXY(50, 12);
      cout << "                      Succeed to edit schedule.                     ";
    }

		string schedule = getFileName(65, 16, 45, 60, 12, messageStatus, "Enter the schedule of class you want to edit");
    messageStatus = false;
    string semester = getFileName(65, 20, 45, 60, 12, messageStatus, "Enter the semester of schedule you want to edit");
    clearText(50, 12, 70);
		int getChoose = controlAddClassMenu();
    if (getChoose == 1) {
      break;
    } else if (getChoose == 2) {
      messageStatus = false;
      continue;
    } else {
			bool checkExist = false;
			for (size_t i = 0; i < listSchedules->list.size(); ++i)
				if (listSchedules->list[i].getClassName() == schedule && to_string(listSchedules->list[i].getSemester()) == semester) {
					listSchedules->list.erase(listSchedules->list.begin() + i);
					checkExist = true;
					break;
				}
      if (checkExist) {
        addScheduleMenu(listSchedules);
        checkIfEditSuccess = 0;
      }
      else 
        checkIfEditSuccess = -1;
      messageStatus = true;
		}
	}
}