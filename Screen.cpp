#include "Screen.h"

char * reformatInputData(string & dataInput)
{
	int i = 0;
	while (true)
	{
		if (i == dataInput.length()) break;
		if (dataInput[i] == ',' && dataInput[i + 1] == ',')
			dataInput.insert(dataInput.begin() + i + 1, ' ');
		++i;
	}
	if (dataInput.back() == ',') dataInput.push_back(' ');
	char *splitColumnInRow = new char[dataInput.length() + 1];
	for (size_t i = 0; i < dataInput.length(); ++i)
		splitColumnInRow[i] = dataInput[i];
	splitColumnInRow[dataInput.length()] = '\0';
	return splitColumnInRow;
}

bool prompExit()
{
  ShowConsoleCursor(false);
  system("cls");
  drawLabel(55, 18, 2, 35, "Are you sure you want to quit?");
  drawLabel(63, 24, 1, 5, "Yes");
  drawLabel(75, 24, 1, 5, "No");

  Point exitButtonMenu[2] = { { 63, 24 }, { 75, 24 } };
  drawLabel(63, 24, 2, 7, "");
  int choose = 0;
  while (true)
  {
    if (_kbhit())
    {
      char getSwitchKey = _getch();
      eraseLabel(exitButtonMenu[choose].x, exitButtonMenu[choose].y, 2, 7);
      switch (getSwitchKey)
      {
      case 13:
        if (choose == 0) return true;
        else return false;
      case 77:
        if (choose == 1) choose = 0; else ++choose;
        break;
      case 75:
        if (choose == 0) choose = 1; else --choose;
        break;
      }
      drawLabel(exitButtonMenu[choose].x, exitButtonMenu[choose].y, 2, 7, "");
      gotoXY(exitButtonMenu[choose].x, exitButtonMenu[choose].y);
    }
  }
  return true;
}

string splitToken(string &stringInput, const string &delim)
{
	size_t pos = 0;
	string token = "";
	if ((pos = stringInput.find(delim)) != string::npos)
	{
		token = stringInput.substr(0, pos);
		stringInput.erase(0, pos + delim.length());
	}
	return token;
}

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
	changeFontSize(20);
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
    gotoXY(x + alignTextToCenter, y);
	cout << textInButton;
}

void eraseLabel(const int & x, const int & y, const int & height, const int & width)
{
	gotoXY(x - height, y - height);
	cout << " ";

	for (int i = 0; i < width; ++i)
		cout << " ";
	cout << " ";

	for (int i = -height + 1; i <= height - 1; ++i)
	{
		gotoXY(x - height, y + i);
		cout << " ";
	}

	gotoXY(x - height, y + height);
	cout << " ";

	for (int i = 0; i < width; ++i)
		cout << " ";
	cout << " ";

	for (int i = -height + 1; i <= height - 1; ++i)
	{
		gotoXY(x + width + 1 - height, y + i);
		cout << " ";
	}
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

void ShowConsoleCursor(const bool &showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

char * fromStrCppToStrC(const string & stringCpp)
{
	char *stringC = new (nothrow) char[stringCpp.length() + 1];
	if (!stringC)
	{
		gotoXY(45, 14);
		cout << "Failed. Make sure you have enough memory in RAM.";
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < stringCpp.length(); ++i)
		stringC[i] = stringCpp[i];
	stringC[stringCpp.length()] = '\0';
	return stringC;
}

void clearText(const int & x, const int & y, const int & length) {
  gotoXY(x, y);
  string overrideField(length, ' ');
  cout << overrideField;
}