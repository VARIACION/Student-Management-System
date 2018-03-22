#include "EditCourse.h"

void drawFieldEditCourse()
{
	system("cls");
	gotoXY(80, 12); cout << "EDIT COURSE";
	drawLabel(50, 20, 5, 70, "");
	gotoXY(50, 18);
	cout << "Course's code";
	gotoXY(49, 22);
	cout << "Lec's username";
	drawLabel(65, 18, 1, 45, "");
	drawLabel(65, 22, 1, 45, "");
	drawLabel(60, 28, 1, 15, "Edit");
	drawLabel(85, 28, 1, 15, "Cancel");
}

bool checkExistedCourse(const string & code, const string & name, ListCourses &listCourses)
{
	for (size_t i = 0; i < listCourses.list.size(); ++i)
		if (listCourses.list[i].getCode() == code && listCourses.list[i].getLecturerUsername() == name)
		{
			listCourses.list.erase(listCourses.list.begin() + i);
			return true;
		}
	return false;
}

void editCourseMenu(ListCourses &listCourses)
{
	while (true)
	{
		ShowConsoleCursor(false);
		drawFieldEditCourse();
		string getCode = getFileName(65, 18, 45, 14, "code");
		string getName = getFileName(65, 22, 45, 14, "username");
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			return;
		else
		{
			if (!checkExistedCourse(getCode, getName, listCourses))
			{
				gotoXY(50, 14);
				cout << "Failed to edit course. Check the data and try again in 3 seconds";
				Sleep(3000);
			}
			else
			{
				addCourseMenu(listCourses);
				return;
			}
		}
	}
}