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
	while (true)
	{
		drawFieldRemoveCourse();
		gotoXY(60, 15);	cout << "                                                                        ";
		gotoXY(60, 15);	cout << "Enter the code of the course you want to remove";
		string courseCode = getFileName(65, 20, "code");
		gotoXY(60, 15);	cout << "                                                                        ";
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			break;
		else if (getChoose == 2)
			continue;
		else
		{
			if (removeCourse(listCourses, courseCode))
			{
				gotoXY(50, 15); cout << "Succeed to remove course. You will be back to COURSE menu in 3 seconds.";
				Sleep(1000);
				return;
			}
			else
			{
				gotoXY(60, 15); cout << "Failed to remove course. Try again in 3 seconds.";
				Sleep(1000);
			}
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