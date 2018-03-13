#include "ImportExportClass.h"

void drawFieldInputFileName()
{
	system("cls");
	gotoXY(60, 10);
	cout << "IMPORT / EXPORT LIST STUDENTS FROM CLASS";
	drawLabel(50, 20, 5, 70, "");
	gotoXY(47, 18);
	cout << "File to import";
	gotoXY(47, 22);
	cout << "File to export";
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
				gotoXY(x + importFile.length(), 18);
				importFile.push_back(getimportFile);
				cout << getimportFile;
			}
			else //show warning about too long importFile
			{
				gotoXY(45, 14);
				cout << "The number of characters in file's name must be shorter than 45 characters.";
			}
		}
		else if (getimportFile == 8 && importFile.length() > 0)
		{
			if (importFile.length() >= 45) //delete warning about too long importFile or invalid chracters in importFile
			{
				gotoXY(45, 14);
				cout << "                                                                              ";
			}
			importFile.pop_back();
			gotoXY(x + importFile.length(), 18);
			cout << " ";
			gotoXY(x + importFile.length(), 18);
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
		string fileImport = getFileName(65, 18);
		string fileExport = getFileName(65, 22);
		int getChoose = controlFileImportExport();
		if (getChoose == 0)
			importStudentFromFile(faculty, fileImport);
		else if (getChoose == 2)
			return;
	}
}

void importStudentFromFile(Faculty & faculty, string & path)
{
	string getLine;
	ifstream fileInput(path);
	if (fileInput.fail()) return;
	getline(fileInput, getLine);
	Class newClass;
	Student *currentStudent = nullptr;
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

void exportStudentToFile(Faculty & faculty, string & path)
{

}
