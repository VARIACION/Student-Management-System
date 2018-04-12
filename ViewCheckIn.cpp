#include "ViewCheckIn.h"

void DrawFieldInputCourseToCheckIn() {
  system("cls");
  gotoXY(72, 12);
  cout << "VIEW YOUR ATTENDANCE";
  drawLabel(50, 20, 4, 70, "");
  gotoXY(50, 20);
  cout << "Course's code";
  drawLabel(65, 20, 1, 45, "");
  drawLabel(60, 28, 1, 15, "View");
  drawLabel(85, 28, 1, 15, "Cancel");
}

void drawFieldViewCheckIn(const int &current_week, const string &courseName)
{
  system("cls");
  gotoXY(68, 3);
  cout << "VIEW YOUR CHECK-IN";
  drawLabel(47, 12, 4, 80, "");
  gotoXY(45, 9);
  cout << "Current week: " << current_week;
  gotoXY(45, 11);
  cout << "Course";
  gotoXY(45, 13);
  cout << courseName;
}

void DisplayDetailCheckIn(Presence &presence, User &student, const int &pointPresence, const int &getNoOfStudent) {
  gotoXY(55, 11);
  for (int i = 0; i < 5; ++i)
    if (i + pointPresence <= presence.getNumberOfWeek()) {
      if (i + pointPresence < 10)
        cout << " |  Week " << i + pointPresence;
      else
        cout << " | Week " << i + pointPresence;
    }
    else
      break;
  gotoXY(56, 13);
  for (int i = 0; i < 5; ++i)
    if (i + pointPresence <= presence.getNumberOfWeek()) {
      if (presence.getPresence(getNoOfStudent, i + pointPresence) == "1")
        cout << "|   Yes   ";
      else
        cout << "|    No   ";
    }
    else break;
}

void ViewCheckInMenu(Presence & presence, User & student, const int &current_week) {
  int getNoOfStudent = presence.getNoOfStudent(student.getUsername());
  while (true) {
    drawFieldViewCheckIn(current_week, presence.getCourse());
    int startPresenceToDisplay = 1;
    DisplayDetailCheckIn(presence, student, startPresenceToDisplay, getNoOfStudent);
    while (true) {
      if (_kbhit()) {
        char scroll = _getch();
        switch (scroll) {
        case 13:
          return;
        case 77: case 9:
          if (presence.getNumberOfWeek() > 5 && startPresenceToDisplay <= presence.getNumberOfWeek() - 5)
            startPresenceToDisplay += 1;
          else if (presence.getNumberOfWeek() > 5 && startPresenceToDisplay > presence.getNumberOfWeek() - 5)
            startPresenceToDisplay = presence.getNumberOfWeek() - 4;
          else
            startPresenceToDisplay = 1;
          break;
        case 75:
          if (startPresenceToDisplay > 1)
            startPresenceToDisplay -= 1;
          else
            startPresenceToDisplay = 1;
          break;
        }
        DisplayDetailCheckIn(presence, student, startPresenceToDisplay, getNoOfStudent);
      }
    }
  }
}

void CheckViewCheckIn(ListPresence *& listPresence, User & student, const int & current_week)
{
  bool checkIfViewSuccess = false;
  while (true) {
    DrawFieldInputCourseToCheckIn();
    gotoXY(60, 15);	cout << "                                                                        ";
    gotoXY(56, 15);	cout << "Enter the code of the course you want to view check in";
    string courseCode = getFileName(65, 20, "code");
    gotoXY(55, 15);	cout << "                                                                        ";
    int getChoose = controlAddClassMenu();
    if (getChoose == 1)
      break;
    else if (getChoose == 2)
      continue;
    else {
      for (auto &i : listPresence->list)
        if (i.getClassName() == student.getClass() && i.getCourse() == courseCode) {
          checkIfViewSuccess = true;
          ViewCheckInMenu(i, student, current_week);
          break;
        }
      if (!checkIfViewSuccess) {
        gotoXY(50, 15); cout << "Failed to view your course's attendance. Try again in 1 second.";
        Sleep(1000);
      }
    }
  }
}