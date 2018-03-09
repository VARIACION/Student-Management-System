#include "LoginScreen.h"

int main()
{
	setFullScreen();
	setScreenAttribute();
	gotoXY(65, 35);
	cout << "Pre-released Alpha version 1.0";
	loginMenu();
	gotoXY(0, 0);
	system("pause");
    return EXIT_SUCCESS;
}