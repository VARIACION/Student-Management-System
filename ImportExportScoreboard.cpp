#include "ImportExportScoreboard.h"

void drawFieldImportExportScoreboard()
{
	system("cls");
	gotoXY(65, 6);
	cout << "IMPORT / EXPORT LIST SCOREBOARDS";
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

void importExportScoreboardMenu(ListScoreboard & listScoreboard)
{
	int getChoose = 0;
	while (true)
	{
		drawFieldImportExportScoreboard();
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
		if (getChoose == 2)
			return;
		else if (getChoose == 0)
		{
			if (!importScoreboardFromFile(listScoreboard, fileImport))
			{
				gotoXY(30, 10);
				cout << "Failed to open database file. Please check your file's name and path to file and try again in 3 seconds.";
				Sleep(1000);
			}
			else
			{
				gotoXY(40, 10);
				cout << "Succeed to import data from file. You will be back to ATENDANCE menu in 3 seconds.";
				Sleep(1000);
				return;
			}
		}
		else
		{
			int getResultAfterExport = exportScoreboardToFile(listScoreboard, fileExport, classExport);
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
				cout << "Succeed to save data to file. You will be back to SCOREBOARD menu in 3 seconds" << "             ";
				Sleep(1000);
				return;
			}
			Sleep(1000);
		}
	}
}

bool importScoreboardFromFile(ListScoreboard & listScoreboard, const string & path)
{
	ifstream fileInput(path);
	if (fileInput.fail()) return false;
	string getLine;
	while (!fileInput.eof())
	{
		getline(fileInput, getLine);
		if (getLine == "") break;
		ScoreBoard newScoreboard;
		getline(fileInput, getLine);
		while (getLine[0] != 'C')
		{
			int no = stoi(splitToken(getLine, ","));
			string name = splitToken(getLine, ",");
			newScoreboard.setStudent(no, name);
			while (name != "")
			{
				name = splitToken(getLine, ",");
				if (name != "") newScoreboard.setScore(no, stod(name));
			}
			newScoreboard.setScore(no, stod(getLine));
			getline(fileInput, getLine);
		}
		getline(fileInput, getLine);
		string token = splitToken(getLine, ",");
		newScoreboard.setCourse(token);
		token = splitToken(getLine, ",");
		newScoreboard.setClassName(token);
		token = splitToken(getLine, ",");
		if (!newScoreboard.setYear(token)) return false;
		if (!newScoreboard.setSemester(getLine[0] - '0')) return false;
		listScoreboard.list.push_back(newScoreboard);
	}
	fileInput.close();
	return true;
}

int exportScoreboardToFile(ListScoreboard & listScoreboard, const string & path, const string &className)
{
	if (listScoreboard.list.size() == 0) return 2;
	ofstream fileOutput(path);
	if (fileOutput.fail()) return 1;
	bool existClass = false;
	for (auto i : listScoreboard.list)
		if (i.getClassName() == className)
		{
			existClass = true;
			fileOutput << "STT,MSSV,Midterm,Lab,Final" << endl;
			for (int j = 1; j <= i.getSizeOfClass(); ++j)
				fileOutput << j << "," << i.getStudent(j) << "," << i.getScore(j, 1) << "," << i.getScore(j, 2) << "," << i.getScore(j, 3) << endl;
			fileOutput << "Course,Class,Year,Semester" << endl;
			fileOutput << i.getCourse() << "," << i.getClassName() << "," << i.getYear() << "," << i.getSemester() << endl;
			break;
		}
	fileOutput.close();
	if (!existClass) return 3;
	return 4;
}