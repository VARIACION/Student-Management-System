#include "SetCurrentWeek.h"

void DrawFieldSetCurrentWeek() {
  system("cls");
  gotoXY(70, 12);
  cout << "SET CURRENT WEEK";
  drawLabel(67, 20, 1, 1, "<");
  drawLabel(67, 20, 2, 3, "");
  drawLabel(89, 20, 1, 1, ">");
  drawLabel(89, 20, 2, 3, "");
  drawLabel(73, 20, 1, 10, "");
  drawLabel(60, 28, 1, 15, "Set");
  drawLabel(85, 28, 1, 15, "Cancel");
}

void SetCurrentWeekMenu() {
  DrawFieldSetCurrentWeek();
  int week = 1;
  ifstream file_input("Resources/current_week.txt", ios::binary);
  if (file_input.fail()) {
    ofstream file_output("Resources/current_week.txt", ios::binary);
    file_output.write((char*)&week, sizeof(week));
    file_output.close();
    file_input.open("Resources/current_week.txt", ios::binary);
  }
  
  file_input.read((char*)&week, sizeof(week));

  file_input.close();

  if (week < 1 || week > 11)
    week = 1;

  clearText(73, 20, 10);
  gotoXY(77, 20);
  cout << to_string(week);
  while (true) {
    while (true) {
      if (_kbhit()) {
        char getKey = _getch();
        switch (getKey) {
        case 77:
          if (week < 11)
            ++week;
          break;
        case 75:
          if (week > 1)
            --week;
          break;
        case 13: case 27:
          goto SET_WEEK;
          break;
        }
        clearText(73, 20, 10);
        gotoXY(77, 20);
        cout << to_string(week);
      }
    }
    
    SET_WEEK:
    int controlSetCurrentWeek = controlAddClassMenu();
    if (controlSetCurrentWeek == 1)
      return;
    else if (controlSetCurrentWeek == 2)
      continue;
    else if (controlSetCurrentWeek == 0) {
      ofstream file_output("Resources/current_week.txt", ios::binary);
      file_output.write((char*)&week, sizeof(week));
      file_output.close();
      return;
    }
  }
}