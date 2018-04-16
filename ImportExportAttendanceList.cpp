#include "ImportExportAttendanceList.h"

void drawFieldImportExportAttendanceList()
{
	system("cls");
	gotoXY(65, 3);
	cout << "IMPORT / EXPORT ATTENDANCE LISTS";
  drawLabel(50, 16, 8, 70, "");
  gotoXY(44, 14);
  cout << "File to export";
  gotoXY(44, 18);
  cout << "Class to export";
  gotoXY(44, 10);
  cout << "File to import";
  gotoXY(44, 22);
  cout << "Course to export";

  drawLabel(65, 10, 1, 45, "");
  drawLabel(65, 14, 1, 45, "");
  drawLabel(65, 18, 1, 45, "");
  drawLabel(65, 22, 1, 45, "");
  drawLabel(53, 28, 1, 15, "Import");
  drawLabel(73, 28, 1, 15, "Export");
  drawLabel(93, 28, 1, 15, "Back");
}

void importExportAttendanceListFromFile(ListPresence* & listPresence)
{
  drawFieldImportExportAttendanceList();
  bool messageResult = false;
	while (true)
	{	
    clearText(65, 10, 45);
    clearText(65, 14, 45);
    clearText(65, 18, 45);
    clearText(65, 22, 45);

		string fileImport = getFileName(65, 10, 45, 57, 6, messageResult, "Enter the path to the file you want to import data");
		string fileExport = getFileName(65, 14, 45, 56, 6, messageResult, "Enter the path to the file you want to export data");
		string classExport = getFileName(65, 18, 45, 57, 6, messageResult, "Enter the name of the class you want to export");
    string courseExport = getFileName(65, 22, 45, 57, 6, messageResult, "Enter the name of the course you want to export");
    clearText(45, 6, 100);

		int getChoose = controlFileImportExport();
		if (getChoose == 0)
		{
      int importResult = importAttendanceListFromFile(listPresence, fileImport);
      gotoXY(40, 6);
      if (importResult == -1)
        cout << "Failed to open database file. Please check your file's name and path to file.\a   ";
      else if (importResult == 0)
        cout << "                        Succeed to import data from file.                          ";
      else if (importResult == -2)
        cout << "         Failed to import data from file. Course's name can not be empty.         \a";
      else if (importResult == -3)
        cout << "          Failed to import data from file. Class's name can not be empty.          \a";
      else if (importResult == -4)
        cout << "               Failed to import data from file. Invalid year input.                \a";
      else if (importResult == -5)
        cout << "             Failed to import data from file. Invalid semester input.              \a";
      else
        cout << "                     Found a same attendance list in system.                       \a";
      messageResult = true;
		}
		else if (getChoose == 1)
		{
      gotoXY(33, 6);
			int getResultAfterExport = exportAttendanceListToFile(listPresence, fileExport, classExport, courseExport);
			if (getResultAfterExport == 1)
				cout << "Failed to save data to file. Please check again if you have permission or broken hard drive\a";
			else if (getResultAfterExport == 2)
				cout << "                 Failed to save data to file. There is no exist data to save.              \a";
			else if (getResultAfterExport == 3)
				cout << "Failed to save data to file. Found no class has name: " << classExport << " or course " << courseExport << "\a         ";
			else
				cout << "                            Succeed to save data to file.                                  ";
      messageResult = true;
		}
    else if (getChoose == 2) {
      messageResult = false;
      return;
    }
	}
}

int importAttendanceListFromFile(ListPresence* & listPresence, const string & path)
{
	string getLine;
	ifstream fileInput(path);
	if (fileInput.fail()) return -1;
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
			if (getLine.size() == 1 && (getLine[0] == '1' || getLine[0] == '0'))
        newPresence.setPresence(no, getLine[0] - '0');
			getline(fileInput, getLine);
		}
		getline(fileInput, getLine);
		string token = splitToken(getLine, ",");
    if (token == "") {
      fileInput.close();
      return -2;
    }
		newPresence.setCourse(token);

		token = splitToken(getLine, ",");
    if (token == "") {
      fileInput.close();
      return -3;
    }
		newPresence.setClassName(token);
		token = splitToken(getLine, ",");
    if (!newPresence.setYear(token)) {
      fileInput.close();
      return -4;
    }
    if (!newPresence.setSemester(getLine[0] - '0')) {
      fileInput.close();
      return -5;
    }

    for (auto& i : listPresence->list)
      if (i.getClassName() == newPresence.getClassName() && i.getCourse() == newPresence.getCourse()) {
        fileInput.close();
        return -6;
      }

		listPresence->list.push_back(newPresence);
	}
	fileInput.close();
	return 0;
}

int exportAttendanceListToFile(ListPresence* & listPresence, const string & path, const string & className, const string &course)
{
	ofstream fileOutput(path);
	if (fileOutput.fail()) return 1;
	bool existClass = false;
	if (listPresence->list.size() == 0) return 2;
	for (auto& i : listPresence->list)
		if (i.getClassName() == className && i.getCourse() == course)
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