#include "LoginScreen.h"
#include "AcademicStaff.h"

int main()
{
	setFullScreen();
	setScreenAttribute();
	loginMenu();
	//academicStaffMenu();
	gotoXY(0, 0);
	system("pause");
    return EXIT_SUCCESS;
}