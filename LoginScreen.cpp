#include "LoginScreen.h"

void drawFrameInput()
{
	drawLabel(50, 20, 5, 70, "");
}

void drawLoginMenu()
{
	system("cls");
	gotoXY(67, 12);
	cout << "STUDENT MANAGEMENT SYSTEM";
	drawFrameInput();
	gotoXY(50, 18);
	cout << "Username";
	gotoXY(50, 22);
	cout << "Password";
	drawLabel(65, 18, 1, 45, "");
	drawLabel(65, 22, 1, 45, "");
	drawLabel(53, 28, 1, 15, "Log in");
	drawLabel(73, 28, 1, 15, "About project");
	drawLabel(93, 28, 1, 15, "Exit");
}

int controlLoginMenu()
{
	ShowConsoleCursor(false);
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
			case 72:
				return 3;
			}
			drawLabel(loginMenuButton[chooseButtonLoginMenu].x, loginMenuButton[chooseButtonLoginMenu].y, 2, 17, "");
			gotoXY(loginMenuButton[chooseButtonLoginMenu].x, loginMenuButton[chooseButtonLoginMenu].y);
		}
	}
}

void checkPasswordInput(const int &x, const int &y, string & password)
{
	password = "";
	while (_kbhit()) _getch();
	gotoXY(x, y);
	while (!_kbhit())
	{
		char getPassword = _getch();
		if (getPassword == 13)
			return;
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
			gotoXY(x + password.length(), y);
			cout << " ";	
			gotoXY(x + password.length(), y);
		}
		while (_kbhit()) _getch();
	}
}

void checkUsernameInput(string &username)
{
	username = "";
	while (_kbhit()) _getch();
	ShowCursor(true);
	bool checkValidCharacters = true;
		gotoXY(65, 18);
	while (!kbhit())
	{
		char getUsername = _getch();
		if (getUsername == 13)
			return;
		else if ((getUsername >= '0' && getUsername <= '9') || (getUsername >= 'A' && getUsername <= 'Z')
			|| (getUsername >= 'a' && getUsername <= 'z'))
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
		while (_kbhit()) _getch();
	}
}

User loginMenu()
{
	while (true)
	{
		drawLoginMenu();
		ShowConsoleCursor(true);
		string username = " ", password = " ";
		int chooseButton;
		checkUsernameInput(username);
		checkPasswordInput(65, 22, password);
		chooseButton = controlLoginMenu();
		if (chooseButton == 2)
			prompExit();
		else if (chooseButton == 0)
		{
			bool checkValidData;
			User userLogin = checkLogin(username, password, checkValidData);
			if (checkValidData) return userLogin;
			else
			{
				gotoXY(60, 14);
				cout << "Failed to login. Please try again in 3 seconds.";
				Sleep(3000);
			}
		}
		else if (chooseButton == 1)
			aboutProject();
	}
}

void encryptDataInput(const string & username, const string & password, string & usernameToMD5, string & passwordToMD5)
{
	MD5 md5Generate;
	char *username_cType = fromStrCppToStrC(username);
	char *password_cType = fromStrCppToStrC(password);

	usernameToMD5 = md5Generate.digestString(username_cType);
	passwordToMD5 = md5Generate.digestString(password_cType);

	delete[] username_cType;
	delete[] password_cType;
}

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

User checkLogin(const string &username, const string & password, bool &checkValidLogin)
{
	User userLogin;
	string usernameToMD5, passwordToMD5, usernameFromFile, passwordFromFile;
	encryptDataInput(username, password, usernameToMD5, passwordToMD5);
	ifstream fileInput("Resources/UsersMD5.csv");
	string getEachRow;
	getline(fileInput, getEachRow);
	while (!fileInput.eof())
	{
		getline(fileInput, getEachRow);
		char *splitColumnInRow = reformatInputData(getEachRow);
		char *token = strtok(splitColumnInRow, ",");
		usernameFromFile = token;
		if (usernameFromFile != usernameToMD5)
		{
			delete[] splitColumnInRow;
			continue;
		}
		userLogin.setUsername(username);
		token = strtok(nullptr, ",");	userLogin.setFullname(token);
		token = strtok(nullptr, ",");	userLogin.setEmail(token);
		token = strtok(nullptr, ",");	userLogin.setMobilePhone(token);
		token = strtok(nullptr, ",");	userLogin.setType(stoi(token));
		token = strtok(nullptr, ",");	passwordFromFile = token;
		token = strtok(nullptr, ",");	userLogin.setClass(token);
		if (passwordFromFile == passwordToMD5)
		{
			delete[] splitColumnInRow;
			checkValidLogin = true;
			userLogin.setPassword(passwordToMD5);
			return userLogin;
		}
	}
	fileInput.close();
	checkValidLogin = false;
	return userLogin;
}

void prompExit()
{
	ShowConsoleCursor(false);
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
}

void aboutProject()
{
	system("cls");
	gotoXY(55, 8);
	cout << "PROJECT: STUDENT MANAGEMENT SYSTEM";
	drawLabel(30, 22, 12, 120, "");
	gotoXY(20, 11);	cout << "About this project";
	gotoXY(20, 12);	cout << "Version: pre-released alpha 1.2.";
	gotoXY(20, 13);	cout << "This project is open source, you can freely download, use, and modify it with no cost.";
	gotoXY(20, 14);	cout << "This project is a part of my course Programming Techniques at school.";
	gotoXY(20, 15);	cout << "Any information about bugs or feature, contact me at huaanhminh0412@gmail.com.";
	gotoXY(20, 17);	cout << "About my team";
	gotoXY(20, 18);	cout << "*	Anh Minh - Team Leader";
	gotoXY(20, 19); cout << "*	Nhat Minh";
	gotoXY(20, 20);	cout << "*	Cong Phuc";
	gotoXY(20, 21);	cout << "*	Minh Khoa";
	gotoXY(20, 23);	cout << "System requirements";
	gotoXY(20, 24);	cout << "Operating system: Microsoft Windows 7 or higher.";
	gotoXY(20, 25);	cout << "RAM: at least 20MB free of RAM.";
	gotoXY(20, 26);	cout << "Package: Microsoft Visual C++ 2015 or higher.";
	_getch();
}
