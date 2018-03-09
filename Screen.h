#ifndef STUDENT_MANAGEMENT_SYSTEM_SCREEN_H
#define STUDENT_MANAGEMENT_SYSTEM_SCREEN_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

struct Point
{
	int x, y;
};

bool gotoXY(const int &x, const int &y);
void setFullScreen();
void setScreenAttribute();
void getCursorPosition(int &x, int &y);
void drawLabel(const int &x, const int &y, const int &height, const int &width, const string &textInButton);
void eraseLabel(const int &x, const int &y, const int &height, const int &width);
void changeFontSize(const int &fontSize);

#endif //STUDENT_MANAGEMENT_SYSTEM_SCREEN_H