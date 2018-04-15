#include "RemoveCourse.h"

void drawFieldRemoveCourse()
{
	system("cls");
	gotoXY(75, 12);
	cout << "REMOVE A COURSE";
	drawLabel(50, 20, 4, 70, "");
	gotoXY(50, 20);
	cout << "Course's code";
	drawLabel(65, 20, 1, 45, "");
	drawLabel(60, 28, 1, 15, "Remove");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void removeCourseMenu(ListCourses* & listCourses)
{
	int checkIfRemoveSuccess = 0;
  bool messageStatus = false;
  drawFieldRemoveCourse();
	while (true)
	{
    clearText(65, 20, 45);
		string courseCode = getFileName(65, 20, 45, 60, 15, messageStatus, "Enter the code of the course you want to remove");
    clearText(65, 20, 45);
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			break;
    else if (getChoose == 2) {
      messageStatus = false;
      continue;
    }
		else
		{
      gotoXY(50, 15);
			if (removeCourse(listCourses, courseCode))
				cout << "                        Succeed to remove course.                     ";
			else
				cout << "\a          Failed to remove course. Found no course name " << courseCode << "              ";
      messageStatus = true;
		}
	}
}

bool removeCourse(ListCourses* & listCourses, const string &code)
{
	for (size_t i = 0; i < listCourses->list.size(); ++i)
		if (listCourses->list[i].getCode() == code)
		{
			listCourses->list.erase(listCourses->list.begin() + i);
			return true;
		}
	return false;
}