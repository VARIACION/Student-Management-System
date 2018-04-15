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
	bool messageStatus = false;
  drawFieldRemoveStudent();
	while (true)
	{
    clearText(65, 16, 45);
    clearText(65, 20, 45);
		string idStudentRemoved = getFileName(65, 16, 45, 45, 12, messageStatus, "             Enter the ID of the student you want to remove             ");
		string classStudentRemoved = getFileName(65, 20, 45, 45, 12, messageStatus, "          Enter the class of the student you want to remove          ");
    clearText(30, 12, 100);
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			break;
    else if (getChoose == 2) {
      messageStatus = false;
      continue;
    }
		else
		{
      int checkIfRemoveSuccess = removeStudent(faculty, idStudentRemoved, classStudentRemoved);
			if (checkIfRemoveSuccess == 0)
			{
				gotoXY(50, 12);
				cout << "                         Succeed to remove student.                          ";
			} else if (checkIfRemoveSuccess == -1) {
				gotoXY(55, 12);
				cout << "Failed to remove student. Found no class name " << classStudentRemoved << "\a";
      } else {
        gotoXY(55, 12);
        cout << "Failed to remove student. Found no student has ID " << idStudentRemoved << "\a";
      }
      messageStatus = true;
		}
	}
}

int removeStudent(Faculty &faculty, const string &idStudentRemoved, const string &classStudentRemoved)
{
	for (auto& i : faculty.classMember)
    if (i.name == classStudentRemoved) {
      for (Student *j = i.student; j; j = j->nextStudent)
        if (j->nextStudent && j->nextStudent->getId() == stoi(idStudentRemoved))
        {
          Student *deleteStudent = j->nextStudent;
          j->nextStudent = j->nextStudent->nextStudent;
          delete deleteStudent;
          for (Student *k = j->nextStudent; k; k = k->nextStudent)
            k->setNo(k->getNo() - 1);
          return 0;
        }
      return -2;
    }
	return -1;
}