#include "ViewScoreStudent.h"

void DrawFieldViewMyScore() {
  system("cls");
  gotoXY(75, 12);
  cout << "VIEW YOUR SCORE";
  drawLabel(50, 20, 4, 70, "");
  gotoXY(50, 20);
  cout << "Course's code";
  drawLabel(65, 20, 1, 45, "");
  drawLabel(60, 28, 1, 15, "View");
  drawLabel(85, 28, 1, 15, "Cancel");
}

void DrawFieldPrintScore(ScoreBoard &scoreboard, User &student) {
  system("cls");
  double *score = new double[3];
  cout << fixed;
  int getNoOfStudent = scoreboard.getStudent(student.getUsername());
  score[0] = scoreboard.getScore(getNoOfStudent, 1);
  score[1] = scoreboard.getScore(getNoOfStudent, 2);
  score[2] = scoreboard.getScore(getNoOfStudent, 3);
  drawLabel(50, 15, 4, 70, "");
  gotoXY(48, 12);
  cout << "Course";
  gotoXY(48, 16);
  cout << scoreboard.getCourse();
  gotoXY(60, 12);
  cout << "Year";
  gotoXY(58, 16);
  cout << scoreboard.getYear();
  gotoXY(70, 12);
  cout << "Semester";
  gotoXY(73, 16);
  cout << scoreboard.getSemester();
  gotoXY(85, 12);
  cout << "Midterm";
  gotoXY(87, 16);
  cout << setprecision(1) << score[0];
  gotoXY(100, 12);
  cout << "Lab";
  gotoXY(100, 16);
  cout << setprecision(1) << score[1];
  gotoXY(110, 12);
  cout << "Final";
  gotoXY(111, 16);
  cout << setprecision(1) << score[2];
  gotoXY(70, 9);
  cout << "Press any key to back to continue";
  _getch();
  delete[] score;
}

void ViewScoreStudentMenu(ListScoreboard *& listScoreboard, User & student) {
  bool checkIfViewSuccess = false;
  while (true) {
    DrawFieldViewMyScore();
    gotoXY(60, 15);	cout << "                                                                        ";
    gotoXY(60, 15);	cout << "Enter the code of the course you want to view";
    string courseCode = getFileName(65, 20, "code");
    gotoXY(60, 15);	cout << "                                                                        ";
    int getChoose = controlAddClassMenu();
    if (getChoose == 1)
      break;
    else if (getChoose == 2)
      continue;
    else {
      for (auto& i : listScoreboard->list)
        if (i.getClassName() == student.getClass() && i.getCourse() == courseCode) {
          checkIfViewSuccess = true;
          DrawFieldPrintScore(i, student);
        }
      if (!checkIfViewSuccess) {
        gotoXY(50, 15); cout << "Failed to view your score. Check your data and try again in 1 second.";
        Sleep(1000);
      }
    }
  }
}