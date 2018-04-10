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
	while (true)
	{
		drawFieldImportExportCourses();
		gotoXY(50, 12);	cout << "                                                                        ";
		gotoXY(55, 12);	cout << "Enter the path to the file you want to import courses";
		string fileImportCourses = getFileName(65, 16, "file");
		gotoXY(50, 12);	cout << "                                                                        ";
		gotoXY(55, 12);	cout << "Enter the path to the file you want to export courses";
		string fileExportCourses = getFileName(65, 20, "file");
		gotoXY(50, 12);	cout << "                                                                        ";
		int getChoose = controlFileImportExport();
		if (getChoose == 2)
			return;
		else if (getChoose == 0)
		{
			if (importCoursesFromFile(listCourses, fileImportCourses))
			{
				gotoXY(48, 12); cout << "Succeed to import courses. You will be back to COURSE menu in 3 seconds";
				Sleep(3000);
				return;
			}
			else
			{
				gotoXY(55, 12); cout << "Failed to import courses. Try again in 3 seconds";
				Sleep(3000);
			}
		}
		else if (getChoose == 1)
		{
			if (exportCoursesToFile(listCourses, fileExportCourses))
			{
				gotoXY(48, 12); cout << "Succeed to export courses. You will be back to COURSE menu in 3 seconds";
				Sleep(1000);
				return;
			}
			else
			{
				gotoXY(55, 12); cout << "Failed to export courses. Try again in 3 seconds";
				Sleep(1000);
			}
		}
	}
}

bool importCoursesFromFile(ListCourses* &listCourses, const string &path)
{
	string getLine;
	ifstream fileInput(path);
	if (fileInput.fail())
		return false;
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
		if (!newCourse.setStartDate_str(token)) return false;
		token = splitToken(getLine, ",");
		if (!newCourse.setEndDate_str(token)) return false;
		Time courseTime;
		token = splitToken(getLine, ",");
		if (!newCourse.setStartTime(token)) return false;
		token = splitToken(getLine, ",");
		if (!newCourse.setEndTime(token)) return false;
		token = splitToken(getLine, ",");
		if (!newCourse.setDateOfWeek(getLine)) return false;
		listCourses->list.push_back(newCourse);
	}
	fileInput.close();
	return true;
}

bool exportCoursesToFile(ListCourses* &listCourses, const string &path)
{
	ofstream fileOutput(path);
	if (!fileOutput)
		return false;
	fileOutput << "Code,Year,Semester,Name,Lecturer Username,Start,End,From,To,Date" << endl;
	for (auto& i : listCourses->list)
		fileOutput << i.getCode() << "," << i.getYear() << "," << i.getSemester() << "," << i.getName()
		<< "," << i.getLecturerUsername() << "," << i.getStartDate_str() << "," << i.getEndDate_str() << ","
		<< i.getStartTime_str() << "," << i.getEndTime_str() << "," << i.getDateOfWeek_str() << endl;
	fileOutput.close();
	return true;
}