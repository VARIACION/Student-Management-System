#include "ImportExportSchedule.h"
#pragma warning(disable:4996)
void drawFiledImportExportSchedules()
{
	system("cls");
	gotoXY(60, 6);
	cout << "        IMPORT / EXPORT SCHEDULE FROM FILE          ";
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

void importExportSchedulesMenu(ListSchedules* & listSchedules)
{
	while (true)
	{
		drawFiledImportExportSchedules();
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
		if (getChoose == 2) return;
		else if (getChoose == 0)
		{
			if (importScheduleFromFile(listSchedules, fileImport))
			{
				gotoXY(40, 10); cout << "Succeed to import courses's schedule. You will be back to SCHEDULES menu in 3 seconds";
				Sleep(1000);
				return;
			}
		}
		else if (getChoose == 1)
		{
			if (exportScheduleToFile(listSchedules, fileExport, classExport))
			{
				gotoXY(40, 10); cout << "Succeed to export courses's schedule. You will be back to SCHEDULES menu in 3 seconds";
				Sleep(1000);
				return;
			}
		}
	}
}

bool importScheduleFromFile(ListSchedules* & listSchedules, const string &path)
{
	Schedule newSchedule;
	ifstream fileInput(path);
	if (fileInput.fail()) return false;
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
	if (!newSchedule.setYear(token)) return false;

	token = splitToken(getLine, ",");
	if (!newSchedule.setSemester(token[0] - '0')) return false;

	token = splitToken(getLine, ",");
	if (!newSchedule.setStartDate(token)) return false;

	if (!newSchedule.setEndDate(getLine)) return false;

	fileInput.close();
	listSchedules->list.push_back(newSchedule);
	return true;
}

bool exportScheduleToFile(ListSchedules* & listSchedules, const string & path, const string &className)
{
	ofstream fileOutput(path);
	if (fileOutput.fail()) return false;
	for (auto& i : listSchedules->list)
		if (i.getClassName() == className)
		{
			fileOutput << "Time,MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY,SUNDAY" << endl;
			fileOutput << "7h30-9h15,";
			for (Week j = (Week)0; j != SUNDAY; j = (Week)(j + 1))
				fileOutput << i.getSchedule(j, 0) << ",";
			fileOutput << endl << "9h30-11h15";
			for (Week j = (Week)0; j != SUNDAY; j = (Week)(j + 1))
				fileOutput << i.getSchedule(j, 1) << ",";
			fileOutput << endl << "13h30-17h00";
			for (Week j = (Week)0; j != SUNDAY; j = (Week)(j + 1))
				fileOutput << i.getSchedule(j, 2) << ",";
			fileOutput << endl << "15h30-17h00";
			for (Week j = (Week)0; j != SUNDAY; j = (Week)(j + 1))
				fileOutput << i.getSchedule(j, 3) << ",";
			fileOutput << endl << "Class,Year,Semester,Start date,End date" << endl;
			fileOutput << i.getClassName() << "," << i.getYear() << "," << i.getSemester() << "," << i.getStartDate() << "," << i.getEndDate();
			fileOutput.close();
			return true;
		}
	return false;
	fileOutput.close();
}