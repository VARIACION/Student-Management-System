#include "ViewCourses.h"

void drawFieldViewCourses()
{
	system("cls");
	gotoXY(68, 3);
	cout << "VIEW LIST OF COURSES";
	drawLabel(70, 20, 14, 40, "");
	drawLabel(57, 36, 1, 40, "");
	gotoXY(40, 5);
	cout << "Press ENTER to go back to COURSE menu or TAB to choose course for detail";
}

void displayCourses(ListCourses* & listCourses, const int &pointCourse)
{
	drawFieldViewCourses();
	ShowConsoleCursor(false);
	int posY[] = { 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32 };
	for (int i = 0; i < 13; ++i)
	{
		gotoXY(60, posY[i]);
		if (i + pointCourse < listCourses->list.size())
			cout << pointCourse + i << ". " << listCourses->list[pointCourse + i].getCode() << "       ";
		else
			break;
	}
}

void displayDetailCourse(Courses & course)
{
	ShowConsoleCursor(false);
	system("cls");
	gotoXY(67, 6);
	cout << "DETAIL";
	gotoXY(40, 10); cout << "Code";
	drawLabel(55, 10, 1, 40, course.getCode());
	gotoXY(40, 13); cout << "Year";
	drawLabel(55, 13, 1, 40, course.getYear());
	gotoXY(40, 16); cout << "Semester";
	drawLabel(55, 16, 1, 40, to_string(course.getSemester()));
	gotoXY(40, 19); cout << "Name";
	drawLabel(55, 19, 1, 40, course.getName());
	gotoXY(40, 22); cout << "Lecturer";
	drawLabel(55, 22, 1, 40, course.getLecturerUsername());
	gotoXY(40, 25); cout << "Start date";
	drawLabel(55, 25, 1, 20, course.getStartDate_str());
	gotoXY(80, 25); cout << "End date";
	drawLabel(90, 25, 1, 20, course.getEndDate_str());
	gotoXY(40, 28); cout << "Start time";
	drawLabel(55, 28, 1, 20, course.getStartTime_str());
	gotoXY(80, 28); cout << "End time";
	drawLabel(90, 28, 1, 20, course.getEndTime_str());
	gotoXY(40, 31); cout << "Day";
	drawLabel(55, 31, 1, 40, course.getDateOfWeek_str());
	_getch();
}

void viewCourseMenu(ListCourses* & listCourses)
{
	while (true)
	{
		int startCourseToDisplay = 0;
		displayCourses(listCourses, startCourseToDisplay);
		while (true)
		{
			if (_kbhit())
			{
				char scroll = _getch();
				if (scroll == 13)
					return;
				else if (scroll == 9)
				{
					string getCourse = getFileName(57, 36, 40, 38, "id");
					int getCourseInt;
					try
					{
						getCourseInt = stoi(getCourse);
					}
					catch (const exception &error)
					{
            cerr << error.what();
						gotoXY(60, 36);
						cout << "Invalid number";
						break;
					}
					if (getCourseInt < listCourses->list.size())
						displayDetailCourse(listCourses->list[getCourseInt]);
				}
				else if (scroll == 80)
				{
					if (listCourses->list.size() > 13 && startCourseToDisplay < listCourses->list.size() - 13)
						startCourseToDisplay += 1;
					else if (listCourses->list.size() > 13 && startCourseToDisplay >= listCourses->list.size() - 13)
						startCourseToDisplay = listCourses->list.size() - 13;
					else
						startCourseToDisplay = 0;
				}
				else if (scroll == 72)
				{
					if (startCourseToDisplay > 0)
						startCourseToDisplay -= 1;
					else
						startCourseToDisplay = 0;
				}
				displayCourses(listCourses, startCourseToDisplay);
			}
		}
	}
}