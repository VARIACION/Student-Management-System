#include "AddCourse.h"

void drawFieldAddCourse()
{
	system("cls");
	gotoXY(68, 3);
	cout << "ADD NEW COURSE";
	gotoXY(40, 8); cout << "Code";
	drawLabel(46, 8, 1, 15, "");
	gotoXY(66, 8); cout << "Year";
	drawLabel(72, 8, 1, 20, "");
	gotoXY(96, 8); cout << "Semester";
	drawLabel(106, 8, 1, 5, "");
	gotoXY(40, 12); cout << "Name";
	drawLabel(46, 12, 1, 65, "");
	gotoXY(40, 16); cout << "Lecturer's username";
	drawLabel(61, 16, 1, 50, "");
	gotoXY(40, 20); cout << "Start";
	drawLabel(47, 20, 1, 28, "");
	gotoXY(78, 20); cout << "End";
	drawLabel(83, 20, 1, 28, "");
	gotoXY(40, 24); cout << "From";
	drawLabel(46, 24, 1, 15, "");
	gotoXY(66, 24); cout << "To";
	drawLabel(72, 24, 1, 15, "");
	gotoXY(92, 24); cout << "Day";
	drawLabel(97, 24, 1, 10, "");
	drawLabel(60, 28, 1, 15, "Add");
	drawLabel(85, 28, 1, 15, "Cancel");
	_getch();
}