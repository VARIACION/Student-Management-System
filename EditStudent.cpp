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
  drawFieldEditStudent();
  int editStudentResult = -1;
  bool messageResult = false;
	while (true)
	{
    clearText(65, 14, 45);
    clearText(65, 18, 45);
    clearText(65, 22, 45);

		string currentID = getFileName(65, 14, 45, 70, 10, messageResult, "Enter the ID of student");
		string newID = getFileName(65, 18, 45, 45, 10, messageResult, "Enter the new ID of student. Leave blank if you don't want to change");
		string newName = getFileName(65, 22, 45, 45, 10, messageResult, "Enter the new name of student. Leave blank if you don't want to change");

    clearText(40, 10, 100);
		int getChoose = controlAddClassMenu();
		if (getChoose == 1)
			break;
    else if (getChoose == 2) {
      messageResult = false;
      continue;
    }
		else {
      editStudentResult = editStudent(faculty, currentID, newID, newName);
      gotoXY(43, 10);
      if (editStudentResult == 0) {
        cout << "Succeed to edit student's info. You will be back to STUDENT menu in 1 seconds.";
      } else if (editStudentResult == -1)
        cout << "     Failed to edit student's info. Found no student has ID " << currentID << "\a";
      else if (editStudentResult == -2)
        cout << "         Failed to edit student's info. Your new ID is invalid." << "\a";
      messageResult = true;
		}
	}
}

int editStudent(Faculty &faculty, const string &currentID, const string &newId, const string &newName)
{
	for (auto i : faculty.classMember)
		for (Student *j = i.student->nextStudent; j; j = j->nextStudent)
			if (to_string(j->getId()) == currentID)
			{
        Student checkInfoStudent;
        if (newId.length() > 0)
          if (!checkInfoStudent.setId(newId))
            return -2;
          else
            j->setId(newId);
        if (newName.length() > 0)
          j->setName(newName);
				return 0;
			}
	return -1;
}