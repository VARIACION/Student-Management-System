#include "LoginScreen.h"
#include "AcademicStaff.h"
#include "StudentMenu.h"
#include "Lecturer.h"
#include "StudentRoleMenu.h"

int main()
{
	setFullScreen();
	setScreenAttribute();
	while (true)
	{
		User userLogin = loginMenu();
		if (userLogin.getType() == 1)
			academicStaffMenu(userLogin);
		else if (userLogin.getType() == 2)
			lecturerMenu(userLogin);
		else
			studentRoleMenu(userLogin);
	}
    return EXIT_SUCCESS;
}