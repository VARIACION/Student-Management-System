#include "Courses.h"


Time::Time()
{
	this->minute = this->hour = -1;
}

int Time::getHour() { return this->hour; }

int Time::getMinute() { return this->minute; }

bool Time::setHour(const int & hourInput)
{
	if (hourInput < 7 || hourInput > 17)
		return false;
	this->hour = hourInput;
	return true;
}

bool Time::setMinute(const int & minuteInput)
{
	if (minuteInput < 0 || minuteInput > 59)
		return false;
	this->minute = minuteInput;
	return true;
}

Date::Date()
{
	this->day = this->month = this->year = 0;
}

int Date::getDay() { return this->day; }

int Date::getMonth() { return this->month; }

int Date::getYear() { return this->year; }

bool Date::setMonth(const int & monthInput)
{
	if (monthInput < 1 || monthInput > 12)
		return false;
	this->month = monthInput;
	return true;
}

bool Date::setYear(const int & yearInput)
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	if (yearInput < 2000 || yearInput > 1900 + newtime.tm_year)
		return false;
	this->year = yearInput;
	return true;
}

bool Date::setDate(const int & dayInput)
{
	if (this->month == 0 || this->year == 0)
		return false;
	if (dayInput < 1)
		return false;
	switch (this->month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (dayInput <= 31) this->day = dayInput;
		break;
	case 4: case 6: case 9: case 11:
		if (dayInput <= 30) this->day = dayInput;
		break;
	case 2:
		if (this->year % 4 == 0 && this->year % 100 != 0 && dayInput <= 29)
			this->day = dayInput;
		else if (this->year % 400 == 0 && dayInput <= 29)
			this->day = dayInput;
		else if (dayInput <= 28)
			this->day = dayInput;
		else return false;
		break;
	}
	return true;
}

Courses::Courses()
{
	this->code = this->name = this->lecturerUsername = this->year = "";
	this->semester = 1;
}


Courses::~Courses()
{
}

void Courses::setCode(const string & codeInput) { this->code = codeInput; }

string Courses::getCode() { return this->code; }

void Courses::setName(const string & nameInput) { this->name = nameInput; }

string Courses::getName() { return this->name; }

void Courses::setLecturerUsername(const string & lecturerUsernameInput) { this->lecturerUsername = lecturerUsernameInput; }

string Courses::getLecturerUsername() { return this->lecturerUsername; }

bool Courses::setYear(const string & yearInput)
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	if (stoi(yearInput.substr(0, 4)) < 2000 || stoi(yearInput.substr(5, 4)) > 1900 + newtime.tm_year)
		return false;
	this->year = yearInput;
	return true;
}

string Courses::getYear() { return this->year; }

int Courses::getSemester() { return this->semester - '0'; }

bool Courses::setSemester(const char & semesterInput)
{
	if (semesterInput < '1' || semesterInput > '3')
		return false;
	this->semester = semesterInput;
	return true;
}

Date Courses::getStartDate() { return this->start; }

bool Courses::setStartDate(Date & startDateInput)
{
	if (this->year == "")
		return false;
	if (startDateInput.getYear() < stoi(this->year.substr(0, 4)) || startDateInput.getYear() > stoi(this->year.substr(0, 4)) + 1)
		return false;
	this->start = startDateInput;
	return true;
}

Date Courses::getEndDate() { return this->end; }

bool Courses::setEndDate(Date & endDateInput)
{
	if (this->year == "")
		return false;
	if (endDateInput.getYear() < stoi(this->year.substr(0, 4)) || endDateInput.getYear() > stoi(this->year.substr(0, 4)) + 1)
		return false;
	this->end = endDateInput;
	return true;
}

Time Courses::getStartTime() { return this->from; }

void Courses::setStartTime(Time & startTimeInput) { this->from = startTimeInput; }

Time Courses::getEndTime() { return this->to; }

string Courses::getStartTime_str()
{
	return to_string(this->from.getHour()) + "h" + to_string(this->from.getMinute());
}

string Courses::getEndTime_str()
{
	return to_string(this->to.getHour()) + "h" + to_string(this->to.getMinute());
}

void Courses::setEndTime(Time & endTimeInput) { this->to = endTimeInput; }

void Courses::setDateOfWeek(Week & dayStart) { this->dateOfWeek = dayStart; }

Week Courses::getDateOfWeek() { return this->dateOfWeek; }

ListCourses::~ListCourses()
{
	this->list.clear();
}

string Courses::getStartDate_str()
{
	return to_string(this->start.getDay()) + "/" + to_string(this->start.getMonth()) + "/" + to_string(this->start.getYear());
}

string Courses::getEndDate_str()
{
	return to_string(this->end.getDay()) + "/" + to_string(this->end.getMonth()) + "/" + to_string(this->end.getYear());
}

string Courses::getDateOfWeek_str()
{
	switch (this->dateOfWeek)
	{
	case MONDAY:
		return "MONDAY";
	case TUESDAY:
		return "TUESDAY";
	case WEDNESDAY:
		return "WEDNESDAY";
	case THURSDAY:
		return "THURSDAY";
	case FRIDAY:
		return "FRIDAY";
	case SATURDAY:
		return "SATURDAY";
	case SUNDAY:
		return "SUNDAY";
	}
}