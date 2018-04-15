#include "ImportExportSchedule.h"
#pragma warning(disable:4996)
void drawFiledImportExportSchedules()
{
	system("cls");
	gotoXY(56, 3);
	cout << "        IMPORT / EXPORT SCHEDULE FROM FILE          ";
	drawLabel(50, 16, 8, 70, "");
	gotoXY(44, 14);
	cout << "File to export";
	gotoXY(44, 18);
	cout << "Class to export";
	gotoXY(44, 10);
	cout << "File to import";
  gotoXY(44, 22);
  cout << "Semester to export";

	drawLabel(65, 10, 1, 45, "");
	drawLabel(65, 14, 1, 45, "");
	drawLabel(65, 18, 1, 45, "");
  drawLabel(65, 22, 1, 45, "");
	drawLabel(53, 28, 1, 15, "Import");
	drawLabel(73, 28, 1, 15, "Export");
	drawLabel(93, 28, 1, 15, "Back");
}

void importExportSchedulesMenu(ListSchedules* & listSchedules)
{
  bool messageStatus = false;
  drawFiledImportExportSchedules();
	while (true)
	{
    clearText(65, 10, 45);
    clearText(65, 14, 45);
    clearText(65, 18, 45);
    clearText(65, 22, 45);

		string fileImport = getFileName(65, 10, 45, 57, 6, messageStatus, "Enter the path to the file you want to import data");
		string fileExport = getFileName(65, 14, 45, 57, 6, messageStatus, "Enter the path to the file you want to export data");
		string classExport = getFileName(65, 18, 45, 57, 6, messageStatus, "Enter the name of the class you want to export");
    string semesterExport = getFileName(65, 22, 45, 57, 6, messageStatus, "Enter the semester of schedule you want to export");
    clearText(45, 6, 100);

		int getChoose = controlFileImportExport();
    if (getChoose == 2) return;
    else if (getChoose == 0)
    {
      gotoXY(40, 6);
      int importResult = importScheduleFromFile(listSchedules, fileImport);
      if (importResult == 0)
        cout << "                      Succeed to import courses's schedule.";
      else if (importResult == -1)
        cout << "   Failed to import courses's schedule. Can not open database file to import data.\a";
      else if (importResult == -2)
        cout << "             Failed to import courses's schedule. Invalid year's format.\a           ";
      else if (importResult == -3)
        cout << "           Failed to import courses's schedule. Invalid semester's format.\a         ";
      else if (importResult == -4)
        cout << "             Failed to import courses's schedule. Invalid date's format.\a           ";
      else if (importResult == -5)
        cout << "        Failed to import courses's schedule. Start date can not after End date.\a    ";
      else
        cout << "        Failed to import courses's schedule. Found same schedule in database.\a     ";
      messageStatus = true;
    }
    else if (getChoose == 1)
    {
      gotoXY(40, 6);
      int exportResult = exportScheduleToFile(listSchedules, fileExport, classExport, semesterExport);
      if (exportResult == 0)
        cout << "                      Succeed to export courses's schedule.                          ";
      else if (exportResult == -1)
        cout << "        Failed to export courses's schedule. Can not open file to export.\a            ";
      else
        cout << "          Failed to export courses's schedule. Found no data to export.\a              ";
      messageStatus = true;
    }
    else
      messageStatus = false;
	}
}

int importScheduleFromFile(ListSchedules* & listSchedules, const string &path)
{
  bool checkExist = false;
	Schedule newSchedule;
	ifstream fileInput(path);
	if (fileInput.fail()) return -1;
	string getLine;
	getline(fileInput, getLine);
	for (int i = 0; i < 4; ++i)
	{
		getline(fileInput, getLine);
		char *courses = reformatInputData(getLine);
		char *token = strtok(courses, ",");

		for (Week j = (Week)0; j != SUNDAY; j = (Week)(j + 1))
		{
			token = strtok(nullptr, ",");
			newSchedule.setSchedule(j, i, token);
		}
		delete[] courses;
	}

	getline(fileInput, getLine);
	getline(fileInput, getLine);

	string token = splitToken(getLine, ",");
	newSchedule.setClassName(token);

	token = splitToken(getLine, ",");
  if (!newSchedule.setYear(token)) {
    fileInput.close();
    return -2;
  }

	token = splitToken(getLine, ",");
  if (!newSchedule.setSemester(token[0] - '0')) {
    fileInput.close();
    return -3;
  }

	token = splitToken(getLine, ",");
  if (!newSchedule.setStartDate(token)) {
    fileInput.close();
    return -4;
  }

  if (!newSchedule.setEndDate(getLine)) {
    fileInput.close();
    return -4;
  }

  if (newSchedule.compareStartEndDate()) {
    fileInput.close();
    return -5;
  }

	fileInput.close();

  for (auto& i : listSchedules->list)
    if (i.getClassName() == newSchedule.getClassName() && i.getStartDate() == newSchedule.getStartDate()
      && i.getEndDate() == newSchedule.getEndDate() && i.getYear() == newSchedule.getYear() && i.getSemester() == newSchedule.getSemester())
      return -6;
	listSchedules->list.push_back(newSchedule);
  return 0;
}

int exportScheduleToFile(ListSchedules* & listSchedules, const string & path, const string &className, const string &semesterExport)
{
	ofstream fileOutput(path);
	if (fileOutput.fail()) return -1;
	for (auto& i : listSchedules->list)
		if (i.getClassName() == className && to_string(i.getSemester()) == semesterExport)
		{
			fileOutput << "Time,MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY,SUNDAY" << endl;

			fileOutput << "7h30-9h15,";
			for (Week j = (Week)0; j != SUNDAY; j = (Week)(j + 1))
				fileOutput << i.getSchedule(j, 0) << ",";

			fileOutput << endl << "9h30-11h15,";
			for (Week j = (Week)0; j != SUNDAY; j = (Week)(j + 1))
				fileOutput << i.getSchedule(j, 1) << ",";

			fileOutput << endl << "13h30-17h00,";
			for (Week j = (Week)0; j != SUNDAY; j = (Week)(j + 1))
				fileOutput << i.getSchedule(j, 2) << ",";

			fileOutput << endl << "15h30-17h00,";
			for (Week j = (Week)0; j != SUNDAY; j = (Week)(j + 1))
				fileOutput << i.getSchedule(j, 3) << ",";

			fileOutput << endl << "Class,Year,Semester,Start date,End date" << endl;
			fileOutput << i.getClassName() << "," << i.getYear() << "," << i.getSemester() << "," << i.getStartDate() << "," << i.getEndDate();
			fileOutput.close();
			return 0;
		}
	return -2;
	fileOutput.close();
}