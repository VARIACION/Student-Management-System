#include "SearchViewAttendanceList.h"

void drawSearchAndViewAttendanceList()
{
	system("cls");
	gotoXY(70, 5);
	cout << "VIEW ATTENDANCE LIST";
	drawLabel(50, 18, 5, 70, "");
	gotoXY(47, 16);
	cout << "Course's name";
	gotoXY(47, 20);
	cout << "Class's name";
	drawLabel(65, 16, 1, 45, "");
	drawLabel(65, 20, 1, 45, "");
	drawLabel(60, 28, 1, 15, "View");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void drawFieldViewDetailInfoAttendanceList()
{
	system("cls");
	gotoXY(68, 1);
	cout << "VIEW ATTENDANCE LIST";
	drawLabel(55, 20, 16, 80, "");
}

void searchViewAttendanceListMenu(ListPresence* & listPresence)
{
	while (true)
	{
		drawSearchAndViewAttendanceList();
		gotoXY(50, 10);	cout << "                                                                        ";
		gotoXY(60, 10);	cout << "Enter the course's name you want to view data";
		string courseName = getFileName(65, 16, "ID");
		gotoXY(50, 10);	cout << "                                                                        ";
		gotoXY(60, 10);	cout << "Enter the class's name you want to view data";
		string className = getFileName(65, 20, "class");
		gotoXY(50, 10);	cout << "                                                                        ";
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			break;
		else if (getChoose == 2)
			continue;
		else if (!checkViewAtendanceList(listPresence, courseName, className))
		{
			gotoXY(45, 10); cout << "Failed to view attendance list. Check your data and try again in 1 second.";
			Sleep(1000);
		}
		else break;
	}
}

void viewBasicInfoAttendanceList(Presence & presence)
{
	system("cls");
	gotoXY(70, 5);
	cout << "BASIC INFORMATION";
	drawLabel(38, 14, 5, 90, "");
	gotoXY(47, 12); cout << "Class";
	drawLabel(55, 12, 1, 15, presence.getClassName());
	gotoXY(77, 12); cout << "Course";
	drawLabel(85, 12, 1, 25, presence.getCourse());
	gotoXY(52, 16); cout << "Year";
	drawLabel(58, 16, 1, 15, presence.getYear());
	gotoXY(81, 16); cout << "Semester";
	drawLabel(91, 16, 1, 15, to_string(presence.getSemester()));
	drawLabel(60, 28, 1, 15, "Next");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void displayDetail(Presence & presence, const int & pointStudent, const int &pointPresence)
{
	int posY[] = { 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32 };
	gotoXY(57, 6);
	for (int i = 0; i < 5; ++i)
		if (i + pointPresence <= presence.getNumberOfWeek())
		{
			if (i + pointPresence < 10)
				cout << " |  Week " << i + pointPresence;
			else
				cout << " | Week " << i + pointPresence << " ";
		}
		else break;

	for (int i = 0; i < 13; ++i)
	{
		gotoXY(45, posY[i]);
		if (i + pointStudent <= presence.getSizeOfClass())
			cout << presence.getStudent(pointStudent + i);
		else break;
		gotoXY(58, posY[i]);
		for (int j = 0; j < 5; ++j)
			if (j + pointPresence <= presence.getNumberOfWeek())
			{
				if (presence.getPresence(pointStudent + i, pointPresence + j) == "1")
					cout << "|   Yes   ";
				else
					cout << "|    No   ";
			}
			else break;
	}
}

void viewDetailInforAttendanceList(Presence & presence)
{
	while (true)
	{
		drawFieldViewDetailInfoAttendanceList();
		int startStudentToDisplay = 1, startPresenceToDisplay = 1;
		displayDetail(presence, startStudentToDisplay, startPresenceToDisplay);
		while (true)
		{
			if (_kbhit())
			{
				char scroll = _getch();
				switch (scroll)
				{
				case 13:
					return;
				case 80:
					if (presence.getSizeOfClass() > 13 && startStudentToDisplay <= presence.getSizeOfClass() - 13)
						startStudentToDisplay += 1;
					else if (presence.getSizeOfClass() > 13 && startStudentToDisplay > presence.getSizeOfClass() - 13)
						startStudentToDisplay = presence.getSizeOfClass() - 12;
					else
						startStudentToDisplay = 1;
					break;
				case 72:
					if (startStudentToDisplay > 1)
						startStudentToDisplay -= 1;
					else
						startStudentToDisplay = 1;
					break;
				case 77: case 9: //>
					if (presence.getNumberOfWeek() > 5 && startPresenceToDisplay <= presence.getNumberOfWeek() - 5)
						startPresenceToDisplay += 1;
					else if (presence.getNumberOfWeek() > 5 && startPresenceToDisplay > presence.getNumberOfWeek() - 5)
						startPresenceToDisplay = presence.getNumberOfWeek() - 4;
					else
						startPresenceToDisplay = 1;
					break;
				case 75: //<
					if (startPresenceToDisplay > 1)
						startPresenceToDisplay -= 1;
					else
						startPresenceToDisplay = 1;
					break;
				}
				displayDetail(presence, startStudentToDisplay, startPresenceToDisplay);
			}
		}
	}
}

bool checkViewAtendanceList(ListPresence* & listPresence, const string & courseName, const string & className)
{
	for (auto& i : listPresence->list)
		if (i.getCourse() == courseName && i.getClassName() == className)
		{
			while (true)
			{
				viewBasicInfoAttendanceList(i);
				int getChoose = controlAddClassMenu();
				if (getChoose == 1) return true;
				else viewDetailInforAttendanceList(i);
			}
			return true;
		}
	return false;
}