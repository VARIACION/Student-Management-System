#include "ImportExportClass.h"

void drawFieldInputFileName()
{
	system("cls");
	gotoXY(60, 6);
	cout << "IMPORT / EXPORT LIST STUDENTS FROM CLASS";
	drawLabel(50, 18, 6, 70, "");
	gotoXY(47, 18);
	cout << "File to export";
	gotoXY(47, 22);
	cout << "Class to export";
	gotoXY(47, 14);
	cout << "File to import";
	drawLabel(65, 14, 1, 45, "");
	drawLabel(65, 18, 1, 45, "");
	drawLabel(65, 22, 1, 45, "");
	drawLabel(53, 28, 1, 15, "Import");
	drawLabel(73, 28, 1, 15, "Export");
	drawLabel(93, 28, 1, 15, "Back");
}

int controlFileImportExport()
{
	ShowConsoleCursor(false);
	drawLabel(53, 28, 2, 17, "");
	Point loginMenuButton[3] = { { 53, 28 },{ 73, 28 },{ 93, 28 } };
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
			case 77: case 9:
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

string getFileName(const int &x, const int &y, const string &tooLongInputWarning)
{
	ShowConsoleCursor(true);
	string importFile = "";
	while (_kbhit()) _getch();
	gotoXY(x, y);
	while (!_kbhit())
	{
		char getimportFile = _getch();
		if (getimportFile == 13 || getimportFile == 9)
			return importFile;
		else if (getimportFile >= 32 && getimportFile < 127)
		{
			if (importFile.length() < 45)
			{
				gotoXY(x + importFile.length(), y);
				importFile.push_back(getimportFile);
				cout << getimportFile;
			}
			else
			{
				gotoXY(45, 10);
				cout << "The number of characters in " << tooLongInputWarning << "'s name must be shorter than 45 characters.";
			}
		}
		else if (getimportFile == 8 && importFile.length() > 0)
		{
			if (importFile.length() >= 45)
			{
				gotoXY(45, 10);
				cout << "                                                                                             ";
			}
			importFile.pop_back();
			gotoXY(x + importFile.length(), y);
			cout << " ";
			gotoXY(x + importFile.length(), y);
		}
		while (_kbhit()) _getch();
	}
  return "";
}

string getFileName(const int &x, const int &y, const int &length, const int &errorLine, const string &tooLongInputWarning)
{
	ShowConsoleCursor(true);
	string importFile = "";
	while (_kbhit()) _getch();
	gotoXY(x, y);
	while (!_kbhit())
	{
		char getimportFile = _getch();
		if (getimportFile == 13 || getimportFile == 9)
			return importFile;
		else if (getimportFile >= 32 && getimportFile < 127)
		{
			if (importFile.length() < length)
			{
				gotoXY(x + importFile.length(), y);
				importFile.push_back(getimportFile);
				cout << getimportFile;
			}
			else
			{
				gotoXY(45, errorLine);
				cout << "The number of characters in " << tooLongInputWarning << "'s name must be shorter than 45 characters.";
			}
		}
		else if (getimportFile == 8 && importFile.length() > 0)
		{
			if (importFile.length() >= length)
			{
				gotoXY(45, errorLine);
				cout << "                                                                                                     ";
			}
			importFile.pop_back();
			gotoXY(x + importFile.length(), y);
			cout << " ";
			gotoXY(x + importFile.length(), y);
		}
		while (_kbhit()) _getch();
	}
  return "";
}

Student * allocateNewStudent(string & input)
{
	if (input.back() == ',') input.pop_back();
	Student *newStudent = new Student;
	int count = 0, saveLasPosComma = 0;
	for (size_t i = 0; i < input.length(); ++i)
		if (input[i] == ',')
		{
			if (count == 0)
				newStudent->setNo(stoi(input.substr(saveLasPosComma, i)));
			else if (count == 1)
			{
				newStudent->setId(stoi(input.substr(saveLasPosComma, 7)));
				newStudent->setName(input.substr(i + 1, input.length() - i - 1));
				break;
			}
			++count;
			saveLasPosComma = i + 1;
		}
	return newStudent;
}

void importExportStudentFromFile(Faculty &faculty)
{
	while (true)
	{
		drawFieldInputFileName();
		gotoXY(40, 10);	cout << "                                                                           ";
		gotoXY(57, 10);	cout << "Enter the path to the file you want to import data";
		string fileImport = getFileName(65, 14, "file");
		gotoXY(40, 10);	cout << "                                                                           ";
		gotoXY(57, 10);	cout << "Enter the path to the file you want to export data";
		string fileExport = getFileName(65, 18, "file");
		gotoXY(45, 10);	cout << "                                                                           ";
		gotoXY(45, 10);	cout << "Enter the name of the class you want to export or type all to export all";
		string classExport = getFileName(65, 22, "class");
		gotoXY(45, 10);	cout << "                                                                           ";
		int getChoose = controlFileImportExport();
		if (getChoose == 0)
		{
			if (!importStudentFromFile(faculty, fileImport))
			{
				gotoXY(30, 10);
				cout << "Failed to open database file. Please check your file's name and path to file and try again in 3 seconds.";
				Sleep(1000);
			}
			else
			{
				gotoXY(40, 10);
				cout << "Succeed to import data from file. You will be back to STUDENT menu in 3 seconds.";
				Sleep(1000);
				return;
			}
		}
		else if (getChoose == 1)
		{
			int getResultAfterExport = exportStudentToFile(faculty, fileExport, classExport);
			if (getResultAfterExport == 1)
			{
				gotoXY(33, 10);
				cout << "Failed to save data to file. Please check again if you have permission or broken hard drive";
			}
			else if (getResultAfterExport == 2)
			{
				gotoXY(40, 10);
				cout << "          Failed to save data to file. There is no exist data to save.          ";
			}
			else if (getResultAfterExport == 3)
			{
				gotoXY(40, 10);
				cout << "          Failed to save data to file. Found no class has name: " << classExport << "         ";
			}
			else
			{
				gotoXY(40, 10);
				cout << "Succeed to save data to file. You will be back to STUDENT menu in 3 seconds" << "             ";
				Sleep(1000);
				return;
			}
			Sleep(1000);
		}
		else if (getChoose == 2)
			return;
	}
}

bool importStudentFromFile(Faculty & faculty, const string & path)
{
	
	string getLine;
	ifstream fileInput(path);
	if (fileInput.fail())
		return false;
	getline(fileInput, getLine);
	Class newClass;
	newClass.student = new Student;
	newClass.student->setName("NULL");
	Student *currentStudent = newClass.student;
	getLine.pop_back();
	newClass.name = getLine.substr(6, getLine.length() - 6);
	getline(fileInput, getLine);
	while (!fileInput.eof())
	{
		getline(fileInput, getLine);
		if (getLine == "") break;
		Student *newStudent = allocateNewStudent(getLine);
		if (newClass.student == nullptr)
			newClass.student = currentStudent = newStudent;
		else
		{
			currentStudent->nextStudent = newStudent;
			currentStudent = newStudent;
		}
	}
	fileInput.close();
	faculty.classMember.push_back(newClass);
	return true;
}

int exportStudentToFile(Faculty & faculty, const string & path, const string &mode)
{
	ofstream fileOutput(path);
	if (fileOutput.fail())
		return 1;
	if (mode == "all")
	{
		if (faculty.classMember.size() == 0)
			return 2;
		for (auto i : faculty.classMember)
		{
			fileOutput << "Class," << i.name << "," << endl;
			fileOutput << "No,Student ID,Student name" << endl;
			for (Student *j = i.student->nextStudent; j; j = j->nextStudent)
				fileOutput << j->getNo() << "," << j->getId() << "," << j->getName() << endl;
		}
	}
	else
	{
		for (auto i : faculty.classMember)
			if (i.name == mode)
			{
				fileOutput << "Class," << i.name << "," << endl;
				fileOutput << "No,Student ID,Student name" << endl;
				for (Student *j = i.student->nextStudent; j; j = j->nextStudent)
					fileOutput << j->getNo() << "," << j->getId() << "," << j->getName() << endl;
				fileOutput.close();
				return 0;
			}
		return 3;
	}
	fileOutput.close();
  return 0;
}
