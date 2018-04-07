#include "ImportExportAttendanceList.h"

void drawFieldImportExportAttendanceList()
{
	system("cls");
	gotoXY(65, 6);
	cout << "IMPORT / EXPORT ATTENDANCE LISTS";
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

void importExportAttendanceListFromFile(ListPresence* & listPresence)
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
			if (!importAttendanceListFromFile(listPresence, fileImport))
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
		else if (getChoose == 1)
		{
			int getResultAfterExport = exportAttendanceListToFile(listPresence, fileExport, classExport);
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
				cout << "Succeed to save data to file. You will be back to ATTENDANCE menu in 3 seconds" << "             ";
				Sleep(1000);
				return;
			}
			Sleep(1000);
		}
		else if (getChoose == 2)
			return;
	}
}

bool importAttendanceListFromFile(ListPresence* & listPresence, const string & path)
{
	string getLine;
	ifstream fileInput(path);
	if (fileInput.fail()) return false;
	while (!fileInput.eof())
	{
		getline(fileInput, getLine);
		if (getLine == "") break;
		Presence newPresence;
		getline(fileInput, getLine);
		while (getLine[0] != 'C')
		{
			int no = stoi(splitToken(getLine, ","));
			string name = splitToken(getLine, ",");
			newPresence.setStudent(no, name);
			while (name != "")
			{
				name = splitToken(getLine, ",");
				if (name != "") newPresence.setPresence(no, name[0] - '0');
			}
			newPresence.setPresence(no, getLine[0] - '0');
			getline(fileInput, getLine);
		}
		getline(fileInput, getLine);
		string token = splitToken(getLine, ",");
		newPresence.setCourse(token);
		token = splitToken(getLine, ",");
		newPresence.setClassName(token);
		token = splitToken(getLine, ",");
		if (!newPresence.setYear(token)) return false;
		if (!newPresence.setSemester(getLine[0] - '0')) return false;
		listPresence->list.push_back(newPresence);
	}
	fileInput.close();
	return true;
}

int exportAttendanceListToFile(ListPresence* & listPresence, const string & path, const string & className)
{
	ofstream fileOutput(path);
	if (fileOutput.fail()) return 1;
	bool existClass = false;
	if (listPresence->list.size() == 0) return 2;
	for (auto& i : listPresence->list)
		if (i.getClassName() == className)
		{
			existClass = true;
			fileOutput << "STT,MSSV";
			for (int j = 1; j <= i.getNumberOfWeek(); ++j)
				fileOutput << ",tuan " << j;
			fileOutput << endl;
			for (int j = 1; j <= i.getSizeOfClass(); ++j)
			{
				fileOutput << j << "," << i.getStudent(j);
				for (int k = 1; k <= i.getNumberOfWeek(); ++k)
					fileOutput << "," << i.getPresence(j, k);
				fileOutput << endl;
			}
			fileOutput << "Course,Class,Year,Semester" << endl;
			fileOutput << i.getCourse() << "," << i.getClassName() << "," << i.getYear() << "," << i.getSemester() << endl;
			break;
		}
	fileOutput.close();
	if (!existClass) return 3;
	return 4;
}