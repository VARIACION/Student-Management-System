#include "EditGrade.h"

void DrawFieldEditGrade() {
  system("cls");
  gotoXY(75, 5);
  cout << "EDIT GRADE";
  drawLabel(50, 18, 5, 70, "");
  gotoXY(47, 16);
  cout << "Student's ID";
  gotoXY(47, 20);
  cout << "Class's name";
  drawLabel(65, 16, 1, 45, "");
  drawLabel(65, 20, 1, 45, "");
  drawLabel(60, 28, 1, 15, "Edit");
  drawLabel(85, 28, 1, 15, "Cancel");
}

void DrawFieldInputNewGrade() {
  system("cls");
  gotoXY(71, 5);
  cout << "ENTER NEW GRADE";
  drawLabel(43, 16, 2, 70, "");
  gotoXY(47, 16);
  cout << "Midterm";
  drawLabel(56, 16, 1, 10, "");
  gotoXY(70, 16);
  cout << "Lab";
  drawLabel(75, 16, 1, 10, "");
  gotoXY(90, 16);
  cout << "Final";
  drawLabel(96, 16, 1, 10, "");
}

void EditGradeMenu(User &lecturer, ListScoreboard* & listScoreboard) {
  while (true) {
    DrawFieldEditGrade();
    gotoXY(50, 10);	cout << "                                                                        ";
    gotoXY(60, 10);	cout << "Enter the student's name you want to edit data";
    string studentName = getFileName(65, 16, "ID");
    gotoXY(50, 10);	cout << "                                                                        ";
    gotoXY(60, 10);	cout << "Enter the class's name you want to edit data";
    string className = getFileName(65, 20, "class");
    gotoXY(50, 10);	cout << "                                                                        ";
    int getChoose = controlAddClassMenu();
    if (getChoose == 1) {
      break;
    }
    else if (getChoose == 2) {
      continue;
    }
    else {
      int edit_result = EditGrade(lecturer, listScoreboard, studentName, className);
      if (edit_result == 1) {
        gotoXY(50, 10); cout << "Succeed to edit. You will be back to LECTURER menu in 1 seconds.";
        Sleep(1000);
        return;
      } else if (edit_result == -1) {
        gotoXY(50, 10); cout << "Failed to edit. Found no class has name " << className;
        Sleep(1000);
      } else if (edit_result == -3) {
        gotoXY(50, 10); cout << "Failed to edit. You can not edit this class" << endl;
        Sleep(1000);
      } else {
        gotoXY(50, 10); cout << "Failed to edit. Found no student has name " << studentName;
        Sleep(1000);
      }
    }
  }
}

bool InputNewGrade(double new_grade[3], const bool &validInput) {
  string midterm = getFileName(56, 16, 3, 60, 10, validInput, "Enter midterm score");
  string lab = getFileName(76, 16, 3, 60, 10, validInput, "Enter lab score");
  string _final = getFileName(96, 16, 3, 60, 10, validInput, "Enter final score");
  try {
    new_grade[0] = stod(midterm);
    new_grade[1] = stod(lab);
    new_grade[2] = stod(_final);
  } catch (const exception &error) {
    ofstream error_message("errors_messages.log", ios::app);
    error_message << error.what() << endl;
    error_message.close();
    gotoXY(60, 10); cout << "Invalid score input. Check your data and try again.";
    return false;
  }
  if (new_grade[0] < 0 || new_grade[0] > 10 || new_grade[1] < 0 || new_grade[1] > 10 || new_grade[2] < 0 || new_grade[2] > 10) {
    gotoXY(45, 10); cout << "Score can not bigger than 10 or smaller than 0. Check your data and try again";
    return false;
  }
  return true;
}

int EditGrade(User &lecturer, ListScoreboard* & listScoreboard, const string & studentName, const string & className) {
  bool invalidInput = false;
  double new_grade[3] = { 0 };
  for (auto& i : listScoreboard->list) {
    if (i.getClassName() == className && i.getLecturerName() == lecturer.getUsername()) {
      for (int j = 1; j <= i.getSizeOfClass(); ++j)
        if (i.getStudent(j) == studentName) {
          while (true) {
            DrawFieldInputNewGrade();
            if (InputNewGrade(new_grade, invalidInput)) {
              i.setScore(j, new_grade[0], 0);
              i.setScore(j, new_grade[1], 1);
              i.setScore(j, new_grade[2], 2);
              return 1;
            } else {
              invalidInput = true;
              continue;
            }
          }
        }
    } else if (i.getClassName() == className && i.getLecturerName() != lecturer.getUsername()) {
      return -3;
    }
    return -2;
  }
  return -1;
}