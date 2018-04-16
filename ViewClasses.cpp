#include "ViewClasses.h"

void drawFieldViewClasses()
{
	system("cls");
	gotoXY(68, 3);
	cout << "VIEW LIST OF CLASSES";
	drawLabel(70, 20, 14, 40, "");
	gotoXY(58, 5);
	cout << "Press ESC to go back to STUDENT menu";
}

int countNumberOfStudentsInClass(Class &className)
{
	int count = 0;
	for (Student *i = className.student->nextStudent; i; i = i->nextStudent)
		++count;
	return count;
}

void displayClass(Faculty &faculty, const int &pointClass)
{
	int posY[] = { 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32 };
	for (int i = 0; i < 13; ++i)
	{
		gotoXY(60, posY[i]);
		if (i + pointClass < faculty.classMember.size())
			cout << faculty.classMember[pointClass + i].name << ": " 
			<< countNumberOfStudentsInClass(faculty.classMember[pointClass + i]) << " student(s)      ";
		else
			break;
	}
}

void viewClassesMenu(Faculty &faculty)
{
	while (true)
	{
		drawFieldViewClasses();
		int startClassToDisplay = 0;
		displayClass(faculty, startClassToDisplay);
		while (true)
		{
			if (_kbhit())
			{
				char scroll = _getch();
				switch (scroll)
				{
        case 13: case 27:
					return;
				case 80:
					if (faculty.classMember.size() > 13 && startClassToDisplay < faculty.classMember.size() - 13)
						startClassToDisplay += 1;
					else if (faculty.classMember.size() > 13 && startClassToDisplay >= faculty.classMember.size() - 13)
						startClassToDisplay = faculty.classMember.size() - 13;
					else
						startClassToDisplay = 0;
					break;
				case 72:
					if (startClassToDisplay > 0)
						startClassToDisplay -= 1;
					else
						startClassToDisplay = 0;
					break;
				}
				displayClass(faculty, startClassToDisplay);
			}
		}
	}
}