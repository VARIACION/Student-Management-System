#include "EditCourse.h"

void drawFieldEditCourse() {
	system("cls");
	gotoXY(73, 12); cout << "EDIT COURSE";
	drawLabel(50, 20, 5, 70, "");
	gotoXY(50, 18);
	cout << "Course's code";
	gotoXY(49, 22);
	cout << "Lec's username";
	drawLabel(65, 18, 1, 45, "");
	drawLabel(65, 22, 1, 45, "");
	drawLabel(60, 28, 1, 15, "Edit");
	drawLabel(85, 28, 1, 15, "Cancel");
}

bool checkExistedCourse(const string & code, const string & name, ListCourses* &listCourses) {
	for (size_t i = 0; i < listCourses->list.size(); ++i)
		if (listCourses->list[i].getCode() == code && listCourses->list[i].getLecturerUsername() == name) {
			listCourses->list.erase(listCourses->list.begin() + i);
			return true;
		}
	return false;
}

void editCourseMenu(ListCourses* &listCourses) {
  drawFieldEditCourse();
  bool editCourseResult = false;
	while (true) {
		ShowConsoleCursor(false);
    clearText(65, 18, 45);
    clearText(65, 22, 45);
		string getCode = getFileName(65, 18, 45, 73, 14, editCourseResult, "Enter code");
		string getName = getFileName(65, 22, 45, 71, 14, editCourseResult, "Enter username");
		int getChoose = controlAddClassMenu();
    if (getChoose == 1) {
      return;
    } else if (getChoose == 0) {
      editCourseResult = checkExistedCourse(getCode, getName, listCourses);
      if (!editCourseResult) {
        gotoXY(55, 14);
        cout << "Failed to edit course. Check the data and try again.\a";
        editCourseResult = true;
      }
      else {
        addCourseMenu(listCourses);
        return;
      }
    }
    else
      editCourseResult = false;
	}
}