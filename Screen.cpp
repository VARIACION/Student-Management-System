#include "Screen.h"

bool gotoXY(const int &x, const int &y)
{
    if (x < 0 || y < 0 || x > 1920 || y > 1080)
        return false;
    COORD setPos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), setPos);
    return true;
}

void setFullScreen()
{ SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0); }

void setScreen()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_BLUE |
    BACKGROUND_GREEN | BACKGROUND_RED);
}
