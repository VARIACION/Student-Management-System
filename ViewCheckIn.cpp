#include "ViewCheckIn.h"

void drawFieldViewCheckIn(const int &current_week)
{
  system("cls");
  gotoXY(68, 1);
  cout << "VIEW YOUR CHECK-IN";
  drawLabel(47, 12, 8, 80, "");
  gotoXY(40, 5);
  cout << "Current week: " << current_week;
  gotoXY(40, 7);
  cout << "Course";
  _getch();
}