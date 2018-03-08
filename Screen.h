#ifndef STUDENT_MANAGEMENT_SYSTEM_SCREEN_H
#define STUDENT_MANAGEMENT_SYSTEM_SCREEN_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

bool gotoXY(const int &x, const int &y);
void setFullScreen();
void setScreenAttribute();
void getCursorPosition(int &x, int &y);
void drawLabel(const int &x, const int &y, const int &height, const int &width, const string &textInButton);
void changeFontSize(const int &fontSize);

#endif //STUDENT_MANAGEMENT_SYSTEM_SCREEN_H