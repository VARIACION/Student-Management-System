#include "ImportExportCourses.h"

void drawFieldImportExportCourses()
{
	system("cls");
	gotoXY(68, 8);
	cout << "IMPORT / EXPORT COURSES";
	drawLabel(50, 18, 5, 70, "");
	gotoXY(47, 16);
	cout << "File to import";
	gotoXY(47, 20);
	cout << "File to export";
	drawLabel(65, 16, 1, 45, "");
	drawLabel(65, 20, 1, 45, "");
	drawLabel(53, 28, 1, 15, "Import");
	drawLabel(73, 28, 1, 15, "Export");
	drawLabel(93, 28, 1, 15, "Back");
}

void importExportCoursesMenu(ListCourses* &listCourses)
{
  drawFieldImportExportCourses();
  bool messageStatus = false;
	while (true)
	{
    clearText(65, 16, 45);
    clearText(65, 20, 45);

		string fileImportCourses = getFileName(65, 16, 45, 55, 12, messageStatus, "Enter the path to the file you want to import courses");
		string fileExportCourses = getFileName(65, 20, 45, 55, 12, messageStatus, "Enter the path to the file you want to export courses");
		gotoXY(50, 12);	cout << "                                                                        ";
		int getChoose = controlFileImportExport();
		if (getChoose == 2)
			return;
    else if (getChoose == 3) {
      messageStatus = false;
      continue;
    }
		else if (getChoose == 0)
		{
      gotoXY(48, 12);
      int importResult = importCoursesFromFile(listCourses, fileImportCourses);
      if (importResult == 0)
        cout << "                    Succeed to import courses.                         ";
      else if (importResult == -1)
        cout << "          Failed to import courses. Can not open database file.          \a";
      else if (importResult == -2)
        cout << "Succeed to import courses. But there are some courses existed in system. \a";
      else if (importResult == -3)
        cout << "Succeed to import courses. But there are some courses has invalid date.  \a";
      else if (importResult == -4)
        cout << "Succeed to import courses. But there are some courses has invalid time.  \a";
      else if (importResult == -5)
        cout << "Succeed to import courses. But there are some courses has invalid week day.\a";
      messageStatus = true;
		}
		else if (getChoose == 1)
		{
      gotoXY(48, 12);
			if (exportCoursesToFile(listCourses, fileExportCourses))
				cout << "                        Succeed to export courses.                       ";
			else
				cout << "        Failed to export courses. Can not open file to save.\a";
      messageStatus = true;
		}
	}
}

int importCoursesFromFile(ListCourses* &listCourses, const string &path)
{
  int messageReturn = 0;
	string getLine;
	ifstream fileInput(path);
	if (fileInput.fail())
		return -1;
	getline(fileInput, getLine);
	while (!fileInput.eof())
	{
		Courses newCourse;
		getline(fileInput, getLine);
		if (getLine == "") break;
		size_t pos = 0;
		string token;
		token = splitToken(getLine, ",");
		newCourse.setCode(token);

		token = splitToken(getLine, ",");
		newCourse.setYear(token);

		token = splitToken(getLine, ",");
		newCourse.setSemester(token[0]);

		token = splitToken(getLine, ",");
		newCourse.setName(token);

		token = splitToken(getLine, ",");
		newCourse.setLecturerUsername(token);

		token = splitToken(getLine, ",");
    if (!newCourse.setStartDate_str(token)) {
      messageReturn = -3;
      continue;
    }
		token = splitToken(getLine, ",");
    if (!newCourse.setEndDate_str(token)) {
      messageReturn = -3;
      continue;
    }
		Time courseTime;
		token = splitToken(getLine, ",");
    if (!newCourse.setStartTime(token)) {
      messageReturn = -4;
      continue;
    }
		token = splitToken(getLine, ",");
    if (!newCourse.setEndTime(token)) {
      messageReturn = -4;
      continue;
    }
		token = splitToken(getLine, ",");
    if (!newCourse.setDateOfWeek(getLine)) {
      messageReturn = -5;
      continue;
    }

    for (auto& i : listCourses->list)
      if (i.getCode() == newCourse.getCode() && i.getDateOfWeek_str() == newCourse.getDateOfWeek_str()
        && i.getEndDate_str() == newCourse.getEndDate_str() && i.getLecturerUsername() == newCourse.getLecturerUsername()
        && i.getSemester() == newCourse.getSemester() && i.getStartDate_str() == newCourse.getStartDate_str()
        && i.getStartTime_str() == newCourse.getStartTime_str() && i.getEndTime_str() == newCourse.getEndTime_str()) {
        messageReturn = -2;
        break;
      }
    if (messageReturn == -2)
      continue;

		listCourses->list.push_back(newCourse);
	}
	fileInput.close();
	return messageReturn;
}

bool exportCoursesToFile(ListCourses* &listCourses, const string &path)
{
	ofstream fileOutput(path);
	if (fileOutput.fail())
		return false;
	fileOutput << "Code,Year,Semester,Name,Lecturer Username,Start,End,From,To,Date" << endl;
	for (auto& i : listCourses->list)
		fileOutput << i.getCode() << "," << i.getYear() << "," << i.getSemester() << "," << i.getName()
		<< "," << i.getLecturerUsername() << "," << i.getStartDate_str() << "," << i.getEndDate_str() << ","
		<< i.getStartTime_str() << "," << i.getEndTime_str() << "," << i.getDateOfWeek_str() << endl;
	fileOutput.close();
	return true;
}