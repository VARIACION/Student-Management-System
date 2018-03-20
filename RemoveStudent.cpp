#include "RemoveStudent.h"

void drawFieldRemoveStudent()
{
	system("cls");
	gotoXY(68, 8);
	cout << "REMOVE A STUDENT";
	drawLabel(50, 18, 5, 70, "");
	gotoXY(47, 16);
	cout << "Student's ID";
	gotoXY(47, 20);
	cout << "Student's Class";
	drawLabel(65, 16, 1, 45, "");
	drawLabel(65, 20, 1, 45, "");
	drawLabel(60, 28, 1, 15, "Remove");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void removeStudentMenu(Faculty &faculty)
{
	int checkIfRemoveSuccess = 0;
	while (true)
	{
		drawFieldRemoveStudent();
		gotoXY(50, 10);	cout << "                                                                        ";
		gotoXY(60, 10);	cout << "Enter the ID of the student you want to remove";
		string idStudentRemoved = getFileName(65, 16, "ID");
		gotoXY(50, 10);	cout << "                                                                        ";
		gotoXY(50, 10);	cout << "Optional: enter the class of the student you want to remove";
		string classStudentRemoved = getFileName(65, 20, "class");
		gotoXY(50, 10);	cout << "                                                                        ";
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			break;
		else if (getChoose == 2)
			continue;
		else
		{
			if (removeStudent(faculty, idStudentRemoved, classStudentRemoved))
			{
				gotoXY(45, 10);
				cout << "Succeed to remove student. You will be back to STUDENT menu in 3 seconds.";
				Sleep(3000);
				return;
			}
			else
			{
				gotoXY(50, 10);
				cout << "Failed to remove student. Check the data and try again in 3 seconds";
				Sleep(3000);
			}
		}
	}
}

bool removeStudent(Faculty &faculty, const string &idStudentRemoved, const string &classStudentRemoved)
{
	for (auto i : faculty.classMember)
		for (Student *j = i.student; j; j = j->nextStudent)
			if (j->nextStudent->getId() == stoi(idStudentRemoved))
			{
				Student *deleteStudent = j->nextStudent;
				j->nextStudent = j->nextStudent->nextStudent;
				delete deleteStudent;
				for (Student *k = j->nextStudent; k; k = k->nextStudent)
					k->setNo(k->getNo() - 1);
				return true;
			}
	return false;
}