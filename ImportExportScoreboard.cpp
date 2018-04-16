#include "ImportExportScoreboard.h"

void drawFieldImportExportScoreboard()
{
	system("cls");
	gotoXY(62, 3);
	cout << "IMPORT / EXPORT LIST SCOREBOARDS";
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

void importExportScoreboardMenu(ListScoreboard* &listScoreboard)
{
  drawFieldImportExportScoreboard();
	int getChoose = 0;
  bool messageStatus = false;
	while (true) {
    clearText(65, 10, 45);
    clearText(65, 14, 45);
    clearText(65, 18, 45);
    clearText(65, 22, 45);

		string fileImport = getFileName(65, 10, 45, 57, 6, messageStatus, "Enter the path to the file you want to import data");
		string fileExport = getFileName(65, 14, 45, 57, 6, messageStatus, "Enter the path to the file you want to export data");
		string classExport = getFileName(65, 18, 45, 58, 6, messageStatus, "Enter the name of the class you want to export");
    string courseExport = getFileName(65, 22, 45, 57, 6, messageStatus, "Enter the name of the course you want to export");
    clearText(50, 6, 60);

		int getChoose = controlFileImportExport();
    if (getChoose == 2)
      return;
    else if (getChoose == 3) {
      messageStatus = false;
      continue;
    }
		else if (getChoose == 0)
		{
      gotoXY(40, 6);
      int importResult = importScoreboardFromFile(listScoreboard, fileImport);
      if (importResult == -1)
        cout << "Failed to open database file. Please check your file's name and path to file.\a";
      else if (importResult == 0)
        cout << "                    Succeed to import data from file.                          ";
      else if (importResult == -2)
        cout << "          Failed to import data. Lecturer's username can not be empty.       \a";
      else if (importResult == -3)
        cout << "             Failed to import data. Course's name can not be empty.\a           ";
      else if (importResult == -4)
        cout << "             Failed to import data. Class's name can not be empty.\a            ";
      else if (importResult == -5)
        cout << "                  Failed to import data. Invalid date input.\a                  ";
      else if (importResult == -6)
        cout << "                  Failed to import data. Invalid semester input.\a              ";
      else
        cout << "                 Failed to import data. Found a same scoreboard.\a              ";
      messageStatus = true;
		}
		else
		{
			int getResultAfterExport = exportScoreboardToFile(listScoreboard, fileExport, classExport, courseExport);
      gotoXY(33, 6);
			if (getResultAfterExport == 1)
				cout << "Failed to save data to file. Please check again if you have permission or broken hard drive\a      ";
			else if (getResultAfterExport == 2)
				cout << "                 Failed to save data to file. There is no exist data to save.              \a     ";
			else if (getResultAfterExport == 3)
				cout << "                 Failed to save data to file. Found no class has name: " << classExport << "         \a";
			else
				cout << "                                     Succeed to save data to file.                                     ";
      messageStatus = true;
		}
	}
}

int importScoreboardFromFile(ListScoreboard* &listScoreboard, const string & path)
{
	ifstream fileInput(path);
	if (fileInput.fail()) return -1;
	string getLine;
	while (!fileInput.eof())
	{
		getline(fileInput, getLine);
		if (getLine == "") break;
		ScoreBoard newScoreboard;
		getline(fileInput, getLine);
		while (getLine[0] != 'L')
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
    if (token == "") {
      fileInput.close();
      return -2;
    }
    newScoreboard.setLecturerName(token);

    token = splitToken(getLine, ",");
    if (token == "") {
      fileInput.close();
      return -3;
    }
		newScoreboard.setCourse(token);

		token = splitToken(getLine, ",");
    if (token == "") {
      fileInput.close();
      return -4;
    }
		newScoreboard.setClassName(token);

		token = splitToken(getLine, ",");
    if (!newScoreboard.setYear(token)) {
      fileInput.close();
      return -5;
    }

    if (!newScoreboard.setSemester(getLine[0] - '0')) {
      fileInput.close();
      return -6;
    }

    for (auto& i : listScoreboard->list)
      if (i.getClassName() == newScoreboard.getClassName() && i.getCourse() == newScoreboard.getCourse()
          && i.getLecturerName() == newScoreboard.getLecturerName() && i.getYear() == newScoreboard.getYear()
          && i.getSemester() == newScoreboard.getSemester()) {
        fileInput.close();
        return -7;
      }

		listScoreboard->list.push_back(newScoreboard);
	}
	fileInput.close();
  return 0;
}

int exportScoreboardToFile(ListScoreboard* &listScoreboard, const string & path, const string &className, const string &course)
{
	if (listScoreboard->list.size() == 0) return 2;
	ofstream fileOutput(path);
	if (fileOutput.fail()) return 1;
	bool existClass = false;
	for (auto i : listScoreboard->list)
		if (i.getClassName() == className && i.getCourse() == course)
		{
			existClass = true;
			fileOutput << "STT,MSSV,Midterm,Lab,Final" << endl;
			for (int j = 1; j <= i.getSizeOfClass(); ++j)
				fileOutput << j << "," << i.getStudent(j) << "," << i.getScore(j, 1) << "," << i.getScore(j, 2) << "," << i.getScore(j, 3) << endl;
			fileOutput << "Lecturer,Course,Class,Year,Semester" << endl;
			fileOutput << i.getLecturerName() << "," << i.getCourse() << "," << i.getClassName() << "," << i.getYear() << "," << i.getSemester() << endl;
			break;
		}
	fileOutput.close();
	if (!existClass) return 3;
	return 4;
}