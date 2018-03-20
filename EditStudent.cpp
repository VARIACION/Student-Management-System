#include "EditStudent.h"

void drawFieldEditStudent()
{
	system("cls");
	gotoXY(68, 6);
	cout << "EDIT STUDENT'S INFORMATION";
	drawLabel(50, 18, 6, 70, "");
	gotoXY(47, 14);
	cout << "ID of student";
	gotoXY(54, 18);
	cout << "New ID";
	gotoXY(52, 22);
	cout << "New name";
	drawLabel(65, 14, 1, 45, "");
	drawLabel(65, 18, 1, 45, "");
	drawLabel(65, 22, 1, 45, "");
	drawLabel(60, 28, 1, 15, "Edit");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void editStudentMenu(Faculty &faculty)
{
	while (true)
	{
		drawFieldEditStudent();
		gotoXY(45, 10);	cout << "                                                                           ";
		gotoXY(70, 10);	cout << "Enter the ID of student";
		string currentID = getFileName(65, 14, "ID");
		gotoXY(40, 10);	cout << "                                                                           ";
		gotoXY(45, 10);	cout << "Enter the new ID of student. Leave blank if you don't want to change";
		string newID = getFileName(65, 18, "ID");
		gotoXY(45, 10);	cout << "                                                                           ";
		gotoXY(45, 10);	cout << "Enter the new name of student. Leave blank if you don't want to change";
		string newName = getFileName(65, 22, "student");
		gotoXY(45, 10);	cout << "                                                                           ";
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			break;
		else if (getChoose == 2)
			continue;
		else
		{
			if (editStudent(faculty, currentID, newID, newName))
			{
				gotoXY(43, 10);
				cout << "Succeed to edit student's info. You will be back to STUDENT menu in 3 seconds.";
				Sleep(3000);
				return;
			}
			else
			{
				gotoXY(47, 10);
				cout << "Failed to edit student's info. Check the data and try again in 3 seconds";
				Sleep(3000);
			}
		}
	}
}

bool editStudent(Faculty &faculty, const string &currentID, const string &newId, const string &newName)
{
	for (auto i : faculty.classMember)
		for (Student *j = i.student->nextStudent; j; j = j->nextStudent)
			if (to_string(j->getId()) == currentID)
			{
				if (newId.length() > 0)
					j->setId(newId);
				if (newName.length() > 0)
					j->setName(newName);
				return true;
			}
	return false;
}