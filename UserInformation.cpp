#include "UserInformation.h"

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
			case 75: case 77: case 9:
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

bool changePassword(User & staff)
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
		if (getButton == 1) return false;
		else if (checkNewPassword(staff, oldPassword, newPassword, renewPassword))
			return true;
	}
}

bool checkNewPassword(User & staff, string & oldPassword, string & newPassword, string & renewPassword)
{
	MD5 md5Generate;
	char *oldPasswordC = fromStrCppToStrC(oldPassword);
	char *newPasswordC = fromStrCppToStrC(newPassword);
	char *renewPasswordC = fromStrCppToStrC(renewPassword);

	oldPassword = md5Generate.digestString(oldPasswordC);
	newPassword = md5Generate.digestString(newPasswordC);
	renewPassword = md5Generate.digestString(renewPasswordC);

	delete[] oldPasswordC;
	delete[] renewPasswordC;

	if (oldPassword != staff.getPassword())
	{
		gotoXY(20, 12);
		cout << "Your old password that you have typed does not match with your current password. Please try again in 5 seconds.";
		Sleep(5000);
		delete[] newPasswordC;
		return false;
	}
	else if (newPassword != renewPassword)
	{
		gotoXY(25, 12);
		cout << "Your new password and the re-enter new password must be the same. Please try again in 5 seconds.";
		Sleep(5000);
		delete[] newPasswordC;
		return false;
	}
	else if (!staff.checkInputPassword(newPasswordC))
	{
		gotoXY(22, 11);
		cout << "Password must have numbers (0..9), upcase (A..Z), lowcase (a..z) and special chracter (!,@,#,$,%,^,&,*)";
		gotoXY(60, 12);	cout << "Please try again in 5 seconds.";
		Sleep(5000);
		delete[] newPasswordC;
		return false;
	}
	delete[] newPasswordC;
	applyNewPassword(staff, newPassword);
	return true;
}

void applyNewPassword(User & staff, const string & newPassword)
{
	MD5 md5Generate;
	char oldDatabaseFile[] = "Resources/UsersMD5.csv", newTempDatabaseFile[] = "Resources/UsersMD5Temp.csv";
	rename(oldDatabaseFile, newTempDatabaseFile);

	string getUserData;
	char *username_toC = fromStrCppToStrC(staff.getUsername());
	string saveNewPassword = md5Generate.digestString(username_toC);
	delete[] username_toC;

	ifstream fileInput(newTempDatabaseFile);
	ofstream fileOutput(oldDatabaseFile);

	while (!fileInput.eof())
	{
		getline(fileInput, getUserData);
		if (getUserData.find(staff.getPassword()) != string::npos)
		{
			saveNewPassword += "," + staff.getFullname() + "," + staff.getEmail() + "," + staff.getMobilePhone() + ","
				+ to_string(staff.getType()) + "," + newPassword + ",";
			staff.setPassword(newPassword);
			fileOutput << saveNewPassword << endl;
		}
		else
			fileOutput << getUserData << endl;
	}
	fileOutput.close();
	fileInput.close();

	if (remove("Resources/UsersMD5Temp.csv") != 0)
	{
		gotoXY(25, 12);
		cout << "We have successfully changed your password but for some reasons that we can not delete the cache file.";
		return;
	}

	gotoXY(25, 12);
	cout << "Password has been changed successfully. You will automatically go back to PROFILE window in 3 seconds.";
	Sleep(3000);
	return;
}