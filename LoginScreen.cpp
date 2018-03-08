#include "LoginScreen.h"

void drawFrameInput()
{
	drawLabel(50, 20, 5, 70, "");
}

void drawLoginMenu()
{
	gotoXY(67, 12);
	changeFontSize(20);
	cout << "STUDENT MANAGEMENT SYSTEM";
	drawFrameInput();
	gotoXY(50, 18);
	cout << "Username";
	gotoXY(50, 22);
	cout << "Password";
	drawLabel(65, 18, 1, 45, "");
	drawLabel(65, 22, 1, 45, "");
	gotoXY(66, 18);
}
