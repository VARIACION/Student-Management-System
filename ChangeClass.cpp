#include "ChangeClass.h"

void drawFieldChangeClass() {
	system("cls");
	gotoXY(65, 8);
	cout << "CHANGE STUDENT TO ANOTHER CLASS";
	drawLabel(50, 18, 5, 70, "");
	gotoXY(47, 16);
	cout << "Student's ID";
	gotoXY(47, 20);
	cout << "Class to change";
	drawLabel(65, 16, 1, 45, "");
	drawLabel(65, 20, 1, 45, "");
	drawLabel(60, 28, 1, 15, "Change");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void changeClassMenu(Faculty &faculty) {
  drawFieldChangeClass();
  int changeClassResult = -1;
  bool messageStatus = false;
	while (true) {
    clearText(65, 16, 45);
    clearText(65, 20, 45);
		string idStudentChange = getFileName(65, 16, 45, 50, 12, messageStatus, "    Enter the ID of the student you want to change class                ");
		string classStudentChange = getFileName(65, 20, 45, 40, 12, messageStatus, "                          Enter the name of the class                                      ");
		int getChoose = controlAddClassMenu();
    if (getChoose == 1) {
      break;
    } else if (getChoose == 2) {
      messageStatus = false;
      continue;
    } else {
      clearText(30, 12, 100);
      changeClassResult = changeClass(faculty, idStudentChange, classStudentChange);
      gotoXY(35, 12);
      if (changeClassResult == 0)
        cout << "          Succeed to change class. You will be back to STUDENT menu in 1 seconds.             ";
      else if (changeClassResult == -1)
        cout << "                  Failed to change class. Found no class name " << classStudentChange << "\a        ";
      else if (changeClassResult == -2)
        cout << "  Failed to change class. The class you want to change is the same with current student's class\a";
      messageStatus = true;
		}
	}
}

int changeClass(Faculty &faculty, const string &id, const string &newClass) {
	bool checkExistedClass = false;
	string currentClassHaveStudent = "";

	for (auto i : faculty.classMember)
		if (newClass == i.name)
			checkExistedClass = true;
  if (!checkExistedClass)
    return -1;

	for (auto i : faculty.classMember) {
    for (Student *j = i.student->nextStudent; j; j = j->nextStudent)
        if (to_string(j->getId()) == id) {
          if (i.name == newClass)
            return -2;
          addNewStudent(faculty, newClass, id, j->getName());
          removeStudent(faculty, id, i.name);
          return 0;
        }
	}
	return false;
}