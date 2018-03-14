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

string getFileName(const int &x, const int &y)
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
		else if (getimportFile > 32 && getimportFile < 127)
		{
			if (importFile.length() < 45)
			{
				gotoXY(x + importFile.length(), y);
				importFile.push_back(getimportFile);
				cout << getimportFile;
			}
			else //show warning about too long importFile
			{
				gotoXY(45, 10);
				cout << "The number of characters in file's name must be shorter than 45 characters.";
			}
		}
		else if (getimportFile == 8 && importFile.length() > 0)
		{
			if (importFile.length() >= 45) //delete warning about too long importFile or invalid chracters in importFile
			{
				gotoXY(45, 10);
				cout << "                                                                              ";
			}
			importFile.pop_back();
			gotoXY(x + importFile.length(), y);
			cout << " ";
			gotoXY(x + importFile.length(), y);
		}
		while (_kbhit()) _getch();
	}
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
		string fileImport = getFileName(65, 14);
		gotoXY(40, 10);	cout << "                                                                           ";
		gotoXY(57, 10);	cout << "Enter the path to the file you want to export data";
		string fileExport = getFileName(65, 18);
		gotoXY(45, 10);	cout << "                                                                           ";
		gotoXY(45, 10);	cout << "Enter the name of the class you want to export or type all to export all";
		string classExport = getFileName(65, 22);
		gotoXY(45, 10);	cout << "                                                                           ";
		int getChoose = controlFileImportExport();
		if (getChoose == 0)
			importStudentFromFile(faculty, fileImport);
		else if (getChoose == 1)
			exportStudentToFile(faculty, fileExport, classExport);
		else if (getChoose == 2)
			return;
	}
}

void importStudentFromFile(Faculty & faculty, const string & path)
{
	string getLine;
	ifstream fileInput(path);
	if (fileInput.fail())
	{
		gotoXY(30, 10);
		cout << "Failed to open database file. Please check your file's name and path to file and try again in 3 seconds.";
		Sleep(3000);
		return;
	}
	getline(fileInput, getLine);
	Class newClass;
	Student *currentStudent = nullptr;
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
}

void exportStudentToFile(Faculty & faculty, const string & path, const string &mode)
{
	ofstream fileOutput(path);
	if (fileOutput.fail())
	{
		gotoXY(33, 10);
		cout << "Failed to save data to file. Please check again if you have permission or broken hard drive";
		Sleep(3000);
	}
	if (mode == "all")
	{
		if (faculty.classMember.size() == 0)
		{
			gotoXY(40, 10);
			cout << "          Failed to save data to file. There is no exist data to save.          ";
			Sleep(3000);
			return;
		}
		for (auto i : faculty.classMember)
		{
			fileOutput << "Class," << i.name << "," << endl;
			fileOutput << "No,Student ID,Student name" << endl;
			for (Student *j = i.student; j; j = j->nextStudent)
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
				for (Student *j = i.student; j; j = j->nextStudent)
					fileOutput << j->getNo() << "," << j->getId() << "," << j->getName() << endl;
				fileOutput.close();
				return;
			}
		gotoXY(40, 10);
		cout << "          Failed to save data to file. Found no class has name: " << mode << "         ";
		Sleep(3000);
	}
	fileOutput.close();
}
