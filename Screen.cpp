#include "Screen.h"

bool gotoXY(const int &x, const int &y)
{
	/* Move cursor to (x, y) coordinate */
	if (x < 0 || y < 0 || x > 1920 || y > 1080)
		return false;
	COORD setPos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), setPos);
	return true;
}

void setFullScreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void setScreenAttribute()
{
	/* Change background and foreground color */
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | BACKGROUND_BLUE |
		BACKGROUND_GREEN | BACKGROUND_RED);
}

void getCursorPosition(int &x, int &y)
{
    POINT position;
    GetCursorPos(&position);
    x = position.x;
    y = position.y;
}

void drawLabel(const int & x, const int & y, const int &height, const int &width, const string & textInButton)
{
    /* Draw border around text */
	gotoXY(x - height, y - height);
	cout << char(218);

	for (int i = 0; i < width; ++i)
		cout << char(196);
	cout << char(191);
	
	for (int i = -height + 1; i <= height - 1; ++i)
	{
		gotoXY(x - height, y + i);
		cout << char(179);
	}

	gotoXY(x - height, y + height);
	cout << char(192);

    for (int i = 0; i < width; ++i)
        cout << char(196);
    cout << char(217);

	for (int i = -height + 1; i <= height - 1; ++i)
	{
		gotoXY(x + width + 1 - height, y + i);
		cout << char(179);
	}

	int alignTextToCenter = (width - textInButton.length()) / 2;
    gotoXY(x - 2 + alignTextToCenter, y);
	cout << textInButton;
}

void changeFontSize(const int & fontSize)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = fontSize;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
