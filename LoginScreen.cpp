#include "LoginScreen.h"

void drawFrameInput()
{
	drawLabel(50, 20, 5, 70, "");
}

void drawLoginMenu()
{
	system("cls");
	gotoXY(67, 12);
	changeFontSize(20);
	cout << "STUDENT MANAGEMENT SYSTEM";
	drawFrameInput();
	gotoXY(50, 18);
	cout << "Username";
	gotoXY(50, 22);
	cout << "Password";
	drawLabel(65, 18, 1, 45, "");
	drawLabel(65, 22, 1, 45, "");
	drawLabel(53, 28, 1, 15, "Log in");
	drawLabel(73, 28, 1, 15, "Remember me");
	drawLabel(93, 28, 1, 15, "Exit");
}

int controlLoginMenu()
{
	drawLabel(53, 28, 2, 17, "");
	Point loginMenuButton[3] = { {53, 28}, {73, 28}, {93, 28} };
	int chooseButtonLoginMenu = 0;
	while (true)
	{
		if (_kbhit())
		{
			char getSwitchKey = _getch();
			eraseLabel(loginMenuButton[chooseButtonLoginMenu].x, loginMenuButton[chooseButtonLoginMenu].y, 2, 17);
			switch (getSwitchKey)
			{
			case 13:
				return chooseButtonLoginMenu;
			case 77:
				if (chooseButtonLoginMenu < 2) ++chooseButtonLoginMenu;
				else chooseButtonLoginMenu = 0;
				break;
			case 75:
				if (chooseButtonLoginMenu > 0) --chooseButtonLoginMenu;
				else chooseButtonLoginMenu = 2;
				break;
			}
			drawLabel(loginMenuButton[chooseButtonLoginMenu].x, loginMenuButton[chooseButtonLoginMenu].y, 2, 17, "");
			gotoXY(loginMenuButton[chooseButtonLoginMenu].x, loginMenuButton[chooseButtonLoginMenu].y);
		}
	}
}

void checkPasswordInput(string & password)
{
	while (password.length() == 0)
	{
		gotoXY(65, 22);
		while (!_kbhit())
		{
			char getPassword = _getch();
			if (getPassword == 13)
				break;
			else if (getPassword > 32 && getPassword < 127)
			{
				if (password.length() < 45)
				{
					password.push_back(getPassword);
					cout << "*";
				}
				else
				{
					gotoXY(45, 14);
					cout << "The number of characters in password must be shorter than 45 characters.";
				}
			}
			else if (getPassword == 8 && password.length() > 0)
			{
				if (password.length() >= 45)
				{
					gotoXY(45, 14);
					cout << "                                                                        ";
				}
				password.pop_back();
				gotoXY(65 + password.length(), 22);
				cout << " ";
				gotoXY(65 + password.length(), 22);
			}
		}
	}
}

void checkUsernameInput(string &username)
{
	bool checkValidCharacters = true;
	while (username.length() == 0)
	{
		gotoXY(65, 18);
		while (!_kbhit())
		{
			char getUsername = _getch();
			if (getUsername == 13)
				break;
			else if ((getUsername > 47 && getUsername < 58) || (getUsername > 64 && getUsername < 91)
				|| (getUsername > 96 && getUsername < 123))
			{
				if (!checkValidCharacters) //delete warning about invalid characters.
				{
					checkValidCharacters = true;
					gotoXY(45, 14);
					cout << "                                                                        ";
				}
				if (username.length() < 45)
				{
					gotoXY(65 + username.length(), 18);
					username.push_back(getUsername);
					cout << getUsername;
				}
				else //show warning about too long username
				{
					gotoXY(45, 14);
					cout << "The number of characters in username must be shorter than 45 characters.";
				}
			}
			else if (getUsername == 8 && username.length() > 0)
			{
				if (username.length() >= 45 || !checkValidCharacters) //delete warning about too long username or invalid chracters in username
				{
					gotoXY(45, 14);
					cout << "                                                                        ";
					checkValidCharacters = true;
				}
				username.pop_back();
				gotoXY(65 + username.length(), 18);
				cout << " ";
				gotoXY(65 + username.length(), 18);
			}
			else if ((getUsername > 32 && getUsername < 48) || (getUsername > 57 && getUsername < 65)
				|| (getUsername > 90 && getUsername < 97) && (getUsername > 122 && getUsername < 127)) 
			{
				//show warning about invalid characters in username
				gotoXY(50, 14);
				cout << "Username must only have characters in 0..9, a..z and A..Z.";
				checkValidCharacters = false;
			}
		}
	}
}

void loginMenu()
{
	int roleLogin;
	while (true)
	{
		drawLoginMenu();
		string username, password;
		int chooseButton;
		checkUsernameInput(username);
		checkPasswordInput(password);
		chooseButton = controlLoginMenu();
		if (chooseButton == 2)
			prompExit();
		else if (chooseButton == 0)
		{
			int roleLogin = checkRoleLogin(username, password);
			if (roleLogin > 0) break;
			else
			{
				gotoXY(60, 14);
				cout << "Failed to login. Please try again in 3 seconds.";
				Sleep(3000);
			}
		}
	}
	gotoXY(70, 14);
	cout << "Succeed to login.";
}

void encryptDataInput(const string & username, const string & password, string & usernameToMD5, string & passwordToMD5)
{
	MD5 md5Generate;
	char *username_cType = new (nothrow) char[username.length() + 1];
	char *password_cType = new (nothrow) char[password.length() + 1];
	if (username_cType == nullptr || password_cType == nullptr)
	{
		gotoXY(45, 14);
		cout << "Failed to encrypt your password. Please make sure you have enough memory.";
		Sleep(5000);
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < username.length(); ++i)
		username_cType[i] = username[i];
	for (size_t i = 0; i < password.length(); ++i)
		password_cType[i] = password[i];
	username_cType[username.length()] = '\0';
	password_cType[password.length()] = '\0';
	usernameToMD5 = md5Generate.digestString(username_cType);
	passwordToMD5 = md5Generate.digestString(password_cType);
}

int checkRoleLogin(const string &username, const string & password)
{
	string usernameToMD5, passwordToMD5, usernameFromFile, passwordFromFile;
	encryptDataInput(username, password, usernameToMD5, passwordToMD5);
	ifstream fileInput("Resources/password.txt");
	while (!fileInput.eof())
	{
		getline(fileInput, usernameFromFile);
		getline(fileInput, passwordFromFile);
		usernameFromFile.pop_back();
		char role = passwordFromFile[passwordFromFile.length() - 1];
		passwordFromFile.pop_back();
		if (usernameToMD5 == usernameFromFile && passwordToMD5 == passwordFromFile)
		{
			fileInput.close();
			return role - '0';
		}
	}
	fileInput.close();
	return 0;
}

void prompExit()
{
	system("cls");
	drawLabel(55, 18, 2, 35, "Are you sure you want to quit?");
	drawLabel(63, 24, 1, 5, "Yes");
	drawLabel(75, 24, 1, 5, "No");
	
	Point exitButtonMenu[2] = { {63, 24}, {75, 24} };
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
				if (choose == 0) exit(EXIT_SUCCESS);
				else return;
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
	gotoXY(0, 0);
	system("pause");
}