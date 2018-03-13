#include "LoginScreen.h"
#include "AcademicStaff.h"
#include "StudentMenu.h"

int main()
{
	setFullScreen();
	setScreenAttribute();
	while (true)
	{
		User userLogin = loginMenu();
		if (userLogin.getType() == 1)
			academicStaffMenu(userLogin);
	}
    return EXIT_SUCCESS;
}