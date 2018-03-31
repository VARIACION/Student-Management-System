#include "SearchViewScoreboard.h"

void drawFieldSearchViewScoreboard()
{
	system("cls");
	gotoXY(70, 5);
	cout << "VIEW LIST SCOREBOARD";
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

void drawFieldViewDetailScoreboard()
{
	system("cls");
	gotoXY(68, 1);
	cout << "VIEW ATTENDANCE LIST";
	drawLabel(65, 20, 16, 60, "");
}

void viewBasicInfoScoreboard(ScoreBoard &scoreboard)
{
	system("cls");
	gotoXY(70, 5);
	cout << "BASIC INFORMATION";
	drawLabel(38, 14, 5, 90, "");
	gotoXY(47, 12); cout << "Class";
	drawLabel(55, 12, 1, 15, scoreboard.getClassName());
	gotoXY(77, 12); cout << "Course";
	drawLabel(85, 12, 1, 25, scoreboard.getCourse());
	gotoXY(52, 16); cout << "Year";
	drawLabel(58, 16, 1, 15, scoreboard.getYear());
	gotoXY(81, 16); cout << "Semester";
	drawLabel(91, 16, 1, 15, to_string(scoreboard.getSemester()));
	drawLabel(60, 28, 1, 15, "Next");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void searchViewScoreboardMenu(ListScoreboard & listScoreboard)
{
	while (true)
	{
		drawFieldSearchViewScoreboard();
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
		else if (!checkViewScoreboard(listScoreboard, courseName, className))
		{
			gotoXY(45, 10); cout << "Failed to view list scoreboard. Check your data and try again in 1 second.";
			Sleep(1000);
		}
	}
}

bool checkViewScoreboard(ListScoreboard & listScroreboard, const string & courseName, const string & className)
{
	for (auto i : listScroreboard.list)
		if (i.getClassName() == className && i.getCourse() == courseName)
		{
			while (true)
			{
				viewBasicInfoScoreboard(i);
				int getChoose = controlAddClassMenu();
				if (getChoose == 1) return true;
				else viewDetailInfoScoreboard(i);
			}
			return true;
		}
	return false;
}

void viewDetailInfoScoreboard(ScoreBoard & scoreboard)
{
	while (true)
	{
		drawFieldViewDetailScoreboard();
		int startStudentToDisplay = 1;
		displayDetailScoreboard(scoreboard, startStudentToDisplay);
		while (true)
		{
			if (_kbhit())
			{
				int scroll = _getch();
				switch (scroll)
				{
				case 13:
					return;
				case 80:
					if (scoreboard.getSizeOfClass() > 13 && startStudentToDisplay <= scoreboard.getSizeOfClass() - 13)
						startStudentToDisplay += 1;
					else if (scoreboard.getSizeOfClass() > 13 && startStudentToDisplay > scoreboard.getSizeOfClass() - 13)
						startStudentToDisplay = scoreboard.getSizeOfClass() - 12;
					else
						startStudentToDisplay = 1;
					break;
				case 72:
					if (startStudentToDisplay > 1)
						startStudentToDisplay -= 1;
					else
						startStudentToDisplay = 1;
					break;
				}
				displayDetailScoreboard(scoreboard, startStudentToDisplay);
			}
		}
	}
}

void displayDetailScoreboard(ScoreBoard & scoreboard, const int & pointStudent)
{
	int posY[] = { 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32 };
	gotoXY(70, 6); cout << "  Midterm  |    Lab    |    Final  ";
	for (int i = 0; i < 13; ++i)
	{
		gotoXY(55, posY[i]);
		if (i + pointStudent <= scoreboard.getSizeOfClass())
			cout << scoreboard.getStudent(pointStudent + i);
		else break;
		gotoXY(74, posY[i]);
		string printScore = to_string(scoreboard.getScore(pointStudent + i, 1));
		for (int j = 0; j < 5; ++j) printScore.pop_back();
		while (printScore.size() < 11) printScore.push_back(' ');
		printScore += to_string(scoreboard.getScore(pointStudent + i, 2));
		for (int j = 0; j < 5; ++j) printScore.pop_back();
		while (printScore.size() < 22) printScore.push_back(' ');
		printScore += to_string(scoreboard.getScore(pointStudent + i, 3));
		for (int j = 0; j < 5; ++j) printScore.pop_back();
		while (printScore.size() < 22) printScore.push_back(' ');
		cout << printScore;
	}
}