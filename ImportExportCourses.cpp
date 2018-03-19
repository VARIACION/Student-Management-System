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

void importExportCoursesMenu(ListCourses &listCourses)
{
	while (true)
	{
		drawFieldImportExportCourses();
		gotoXY(50, 12);	cout << "                                                                        ";
		gotoXY(55, 12);	cout << "Enter the path to the file you want to import courses";
		string fileImportCourses = getFileName(65, 16);
		gotoXY(50, 12);	cout << "                                                                        ";
		gotoXY(55, 12);	cout << "Enter the path to the file you want to export courses";
		string fileExportCourses = getFileName(65, 20);
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

bool reformatDate(string dateString, Date &date)
{
	int countSplash = 0, day, month, year;
	for (auto i : dateString)
		if (i == '/')
			++countSplash;
	if (countSplash != 2)
		return false;
	char *dateCStr = fromStrCppToStrC(dateString);
	char *token = strtok(dateCStr, "/");
	day = stoi(token);
	token = strtok(nullptr, "/");
	month = stoi(token);
	token = strtok(nullptr, "/");
	year = stoi(token);
	delete[] dateCStr;

	if (!date.setYear(year))
		return false;
	else if (!date.setMonth(month))
		return false;
	else if (!date.setDate(day))
		return false;
	return true;
}

bool reformatTime(string timeInput, Time &time)
{
	bool checkExistH = false;
	for (auto i : timeInput)
		if (i == 'h')
			checkExistH = true;
	if (!checkExistH) return false;
	char *time_c = fromStrCppToStrC(timeInput);
	int hour, minute;
	char *token = strtok(time_c, "h");
	hour = stoi(token);
	token = strtok(nullptr, "h");
	minute = stoi(token);
	delete[] time_c;
	if (!time.setHour(hour))
		return false;
	else if (!time.setMinute(minute))
		return false;
	return true;
}

Week reformatDateOfWeek(const string &date)
{
	if (date == "MONDAY")
		return MONDAY;
	else if (date == "TUESDAY")
		return TUESDAY;
	else if (date == "WEDNESDAY")
		return WEDNESDAY;
	else if (date == "THURSDAY")
		return THURSDAY;
	else if (date == "FRIDAY")
		return FRIDAY;
	else if (date == "SATURDAY")
		return SATURDAY;
	else if (date == "SUNDAY")
		return SUNDAY;
}

string splitToken(string &stringInput, const string &delim)
{
	size_t pos = 0;
	string token = "";
	if ((pos = stringInput.find(delim)) != string::npos)
	{
		token = stringInput.substr(0, pos);
		stringInput.erase(0, pos + delim.length());
	}
	return token;
}

bool importCoursesFromFile(ListCourses &listCourses, const string &path)
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
		Date courseDate;
		if (!reformatDate(token, courseDate)) return false;
		newCourse.setStartDate(courseDate);
		token = splitToken(getLine, ",");
		if (!reformatDate(token, courseDate)) return false;
		newCourse.setEndDate(courseDate);
		Time courseTime;
		token = splitToken(getLine, ",");
		if (!reformatTime(token, courseTime)) return false;
		newCourse.setStartTime(courseTime);
		token = splitToken(getLine, ",");
		if (!reformatTime(token, courseTime)) return false;
		newCourse.setEndTime(courseTime);
		token = splitToken(getLine, ",");
		Week courseWeek = reformatDateOfWeek(getLine);
		newCourse.setDateOfWeek(courseWeek);
		listCourses.list.push_back(newCourse);
	}
	fileInput.close();
	return true;
}

bool exportCoursesToFile(ListCourses &listCourses, const string &path)
{
	ofstream fileOutput(path);
	if (!fileOutput)
		return false;
	fileOutput << "Code,Year,Semester,Name,Lecturer Username,Start,End,From,To,Date" << endl;
	for (auto i : listCourses.list)
		fileOutput << i.getCode() << "," << i.getYear() << "," << i.getSemester() << "," << i.getName()
		<< "," << i.getLecturerUsername() << "," << i.getStartDate_str() << "," << i.getEndDate_str() << ","
		<< i.getStartTime_str() << "," << i.getEndTime_str() << "," << i.getDateOfWeek_str() << endl;
	fileOutput.close();
	return true;
}