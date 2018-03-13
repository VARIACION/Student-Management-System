#include "AcademicStaff.h"

void drawAcademicStaffMenu()
{
	system("cls");
	gotoXY(67, 6);
	cout << "ACADEMIC STAFF";
	drawLabel(23, 24, 12, 120, "");
	drawLabel(25, 16, 2, 20, "Information");
	drawLabel(65, 16, 2, 20, "Students");
	drawLabel(105, 16, 2, 20, "Courses");
	drawLabel(25, 24, 2, 20, "Schedules");
	drawLabel(65, 24, 2, 20, "Attendance");
	drawLabel(105, 24, 2, 20, "Scoreboard");
	drawLabel(105, 32, 2, 20, "Log out");
	drawLabel(65, 32, 2, 20, "Quit");
}

int controlAcademicStaffMenu()
{
	drawLabel(25, 16, 3, 22, "");
	string textDescribeFeature[8] =
	{
		{"View/Change your information like password, email, etc."},
		{"   Classes's informtion and students's information."},
		{"                Courses's information."},
		{"          Courses's schedules's information."},
		{"                 Attendance lists."},
		{"                 Scoreboard lists."},
		{"                       Quit."},
		{"             Log out to log in screen."},
	};
	Point academicStaffMenuPoint[8] = { {25, 16}, {65, 16}, {105, 16}, {25, 24}, {65, 24}, {105, 24}, { 65, 32 }, {105, 32} };
	int chooseControlAcademicStaffMenu = 0;
	gotoXY(50, 10);
	cout << textDescribeFeature[chooseControlAcademicStaffMenu];
	while (true)
	{
		if (_kbhit())
		{
			char getSwitchKey = _getch();
			eraseLabel(academicStaffMenuPoint[chooseControlAcademicStaffMenu].x,
				academicStaffMenuPoint[chooseControlAcademicStaffMenu].y, 3, 22);
			gotoXY(50, 10);
			cout << "                                                                             ";
			switch (getSwitchKey)
			{
			case 13:
				return chooseControlAcademicStaffMenu;
			case 77: //->
				if (chooseControlAcademicStaffMenu < 7) ++chooseControlAcademicStaffMenu;
				else chooseControlAcademicStaffMenu = 0;
				break;
			case 75: // <-
				if (chooseControlAcademicStaffMenu > 0) --chooseControlAcademicStaffMenu;
				else chooseControlAcademicStaffMenu = 7;
				break;
			case 72: // ^
				if (chooseControlAcademicStaffMenu == 0) chooseControlAcademicStaffMenu = 3;
				else if (chooseControlAcademicStaffMenu == 1 || chooseControlAcademicStaffMenu == 2) 
					chooseControlAcademicStaffMenu += 5;
				else if (chooseControlAcademicStaffMenu >= 3 && chooseControlAcademicStaffMenu <= 5) 
					chooseControlAcademicStaffMenu -= 3;
				else chooseControlAcademicStaffMenu -= 2;
				break;
			case 80: // v
				if (chooseControlAcademicStaffMenu < 3) chooseControlAcademicStaffMenu += 3;
				else if (chooseControlAcademicStaffMenu == 4 || chooseControlAcademicStaffMenu == 5)
					chooseControlAcademicStaffMenu += 2;
				else if (chooseControlAcademicStaffMenu == 6 || chooseControlAcademicStaffMenu == 7)
					chooseControlAcademicStaffMenu -= 5;
				break;
			}
			drawLabel(academicStaffMenuPoint[chooseControlAcademicStaffMenu].x,
				academicStaffMenuPoint[chooseControlAcademicStaffMenu].y, 3, 22, "");
			gotoXY(50, 10);
			cout << textDescribeFeature[chooseControlAcademicStaffMenu];
			gotoXY(academicStaffMenuPoint[chooseControlAcademicStaffMenu].x,
				academicStaffMenuPoint[chooseControlAcademicStaffMenu].y);
		}
	}
}

void accessInfo(User & staff)
{
	system("cls");
	gotoXY(67, 6);
	cout << "PROFILE";
	gotoXY(40, 10);		cout << "Username ";
	drawLabel(55, 10, 1, 40, staff.getUsername());
	gotoXY(40, 13);		cout << "Fullname";
	drawLabel(55, 13, 1, 40, staff.getFullname());
	gotoXY(40, 16);		cout << "Email";
	drawLabel(55, 16, 1, 40, staff.getEmail());
	gotoXY(40, 19);		cout << "Mobile Phone";
	drawLabel(55, 19, 1, 40, staff.getMobilePhone());
	gotoXY(40, 22);		cout << "Role";
	string role;
	if (staff.getType() == 0)
		role = "Student";
	else if (staff.getType() == 1)
		role = "Academic Staff";
	else
		role = "Lecturer";
	drawLabel(55, 22, 1, 40, role);
	gotoXY(40, 25);		cout << "Class";
	drawLabel(55, 25, 1, 40, "Not available for this role");
	drawLabel(50, 30, 1, 20, "Change password");
	drawLabel(80, 30, 1, 20, "Go back");
	int choose = chooseMenuInInfoMenu();
	if (choose == 1)
		return;
	else
		changePassword(staff);
}

void academicStaffMenu(User &staff)
{
	int chooseFeature = -1;
	while (true)
	{
		ShowConsoleCursor(false);
		drawAcademicStaffMenu();
		chooseFeature = controlAcademicStaffMenu();
		if (chooseFeature == 7)
			break;
		else if (chooseFeature == 6)
			prompExit();
		else if (chooseFeature == 0)
			accessInfo(staff);
	}
}

int chooseMenuInInfoMenu()
{
	ShowConsoleCursor(false);
	drawLabel(50, 30, 2, 22, "");
	int getButton = 0;
	while (true)
	{
		if (_kbhit())
		{
			char getSwitchKey = _getch();
			switch (getSwitchKey)
			{
			case 13:
				return getButton;
			case 75: case 77:
				if (getButton == 0)
				{
					getButton = 1;
					eraseLabel(50, 30, 2, 22);
					drawLabel(80, 30, 2, 22, "");
				}
				else
				{
					getButton = 0;
					eraseLabel(80, 30, 2, 22);
					drawLabel(50, 30, 2, 22, "");
				}
				break;
			}
		}
	}
}

void changePassword(User & staff)
{
	while (true)
	{
		system("cls");
		ShowConsoleCursor(true);
		gotoXY(67, 8);
		cout << "CHANGE PASSWORD";
		drawLabel(30, 20, 6, 100, "");
		gotoXY(45, 16);
		cout << "Old password";				drawLabel(65, 16, 1, 45, "");
		gotoXY(45, 20);
		cout << "New password";				drawLabel(65, 20, 1, 45, "");
		gotoXY(36, 24);
		cout << "Re-enter new password";	drawLabel(65, 24, 1, 45, "");
		drawLabel(50, 30, 1, 20, "Change password");
		drawLabel(80, 30, 1, 20, "Cancel");
		string oldPassword = "", newPassword = "", renewPassword = "";
		checkPasswordInput(65, 16, oldPassword);
		checkPasswordInput(65, 20, newPassword);
		checkPasswordInput(65, 24, renewPassword);

		drawLabel(50, 30, 2, 22, "");
		int getButton = chooseMenuInInfoMenu();
		if (getButton == 1) return;
		else saveNewPassword(staff, oldPassword, newPassword, renewPassword);
	}
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

void saveNewPassword(User & staff, string & oldPassword, string & newPassword, string & renewPassword)
{
	MD5 md5Generate;
	char *oldPasswordC = fromStrCppToStrC(oldPassword);
	char *newPasswordC = fromStrCppToStrC(newPassword);
	char *renewPasswordC = fromStrCppToStrC(renewPassword);

	oldPassword = md5Generate.digestString(oldPasswordC);
	newPassword = md5Generate.digestString(newPasswordC);
	renewPassword = md5Generate.digestString(renewPasswordC);

	delete[] oldPasswordC;
	delete[] newPasswordC;
	delete[] renewPasswordC;

	if (oldPassword != staff.getPassword())
	{
		gotoXY(20, 12);
		cout << "Your old password that you have typed does not match with your current password. Please try again in 5 seconds.";
		Sleep(5000);
		return;
	}
	else if (newPassword != renewPassword)
	{
		gotoXY(25, 12);
		cout << "Your new password and the re-enter new password must be the same. Please try again in 5 seconds.";
		Sleep(5000);
		return;
	}
}
