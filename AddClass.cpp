#include "AddClass.h"

void drawFieldAddClass() {
	system("cls");
	gotoXY(70, 12);
	cout << "ADD A NEW EMPTY CLASS";
	drawLabel(50, 20, 4, 70, "");
	gotoXY(50, 20);
	cout << "Class's Name";
	drawLabel(65, 20, 1, 45, "");
	drawLabel(60, 28, 1, 15, "Add..");
	drawLabel(85, 28, 1, 15, "Cancel");
}

int controlAddClassMenu() {
	ShowConsoleCursor(false);
	drawLabel(60, 28, 2, 17, "");
	int getButton = 0;
	while (true) {
		if (_kbhit()) {
			char getSwitchKey = _getch();
			switch (getSwitchKey) {
			case 13:
        if (getButton == 0)
          eraseLabel(60, 28, 2, 17);
        else
          eraseLabel(85, 28, 2, 17);
				return getButton;
			case 75: case 77: case 9:
				if (getButton == 0) {
					getButton = 1;
					eraseLabel(60, 28, 2, 17);
					drawLabel(85, 28, 2, 17, "");
				}
				else {
					getButton = 0;
					eraseLabel(85, 28, 2, 17);
					drawLabel(60, 28, 2, 17, "");
				}
				break;
			case 72:
        if (getButton == 0)
          eraseLabel(60, 28, 2, 17);
        else
          eraseLabel(85, 28, 2, 17);
				return 2;
      case 27:
        return 1;
			}
		}
	}
}

void addClassMenu(Faculty &faculty) {
	bool messageStatus = false;
  drawFieldAddClass();
	while (true) {
    clearText(65, 20, 45);
		string classToAdd = getFileName(65, 20, 45, 60, 15, messageStatus, "Enter the name of the class you want to add");
    clearText(40, 15, 100);
		int getChoose = controlAddClassMenu();
    if (getChoose == 1) {
      break;
    } else if (getChoose == 2) {
      messageStatus = false;
      continue;
    } else {
      gotoXY(43, 15);
      if (addClass(faculty, classToAdd))
        cout << "                         Succeed to add new empty class.          ";
      else
        cout << "                Failed to add new empty class. CLass is existed.\a";
      messageStatus = true;
		}
	}
}

bool addClass(Faculty &faculty, const string &nameNewClass) {
	if (nameNewClass.length() == 0)
		return false;
	for (auto& i : faculty.classMember)
		if (i.name == nameNewClass)
			return false;
	Class newClass;
	newClass.name = nameNewClass;
	newClass.student = new Student;
	faculty.classMember.push_back(newClass);
	return true;
}