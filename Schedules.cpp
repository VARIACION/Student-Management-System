#include "Schedules.h"

ListSchedules::~ListSchedules()
{
	this->list.clear();
}

Schedule::Schedule()
{
	this->className = this->year = "";
	this->semester = '0';
	for (Week i = (Week)0; i != SUNDAY; i = (Week)(i + 1))
		this->schedule[i].resize(4);
}

Schedule::~Schedule()
{
	this->className.clear();
	this->year.clear();
	for (Week i = (Week)0; i != SUNDAY; i = (Week)(i + 1))
		this->schedule[i].clear();
	this->schedule.clear();
}

void Schedule::setClassName(const string & name) { this->className = name; }

string Schedule::getClassName() { return this->className; }

bool Schedule::setYear(const string & yearInput)
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	try
	{
		if (stoi(yearInput.substr(0, 4)) < 2000 || stoi(yearInput.substr(5, 4)) > 1900 + newtime.tm_year)
			return false;
	}
	catch (const exception &error)
	{
    cerr << error.what();
		return false;
	}
	this->year = yearInput;
	return true;
}

string Schedule::getYear() { return this->year; }

bool Schedule::setSemester(const int & semesterInput)
{
	if (semesterInput < 1 || semesterInput > 3)
		return false;
	this->semester = to_string(semesterInput)[0];
	return true;
}

int Schedule::getSemester() { return this->semester - '0'; }

bool Schedule::setStartDate(Date & startDate)
{
	if (this->year == "") return false;
	try
	{
		if (startDate.getYear() < stoi(this->year.substr(0, 4)) || startDate.getYear() > stoi(this->year.substr(0, 4)) + 1)
			return false;
	}
	catch (const exception &error)
	{
    cerr << error.what();
		return false;
	}
	this->start = startDate;
	return true;
}

bool Schedule::setStartDate(string & startDate)
{
	string day = splitToken(startDate, "/"), month = splitToken(startDate, "/");
	Date checkDate;
	try
	{
		checkDate.setYear(stoi(startDate));
		checkDate.setMonth(stoi(month));
		checkDate.setDate(stoi(day));
	}
	catch (const exception &error)
	{
    cerr << error.what();
		return false;
	}
	return this->setStartDate(checkDate);
}

string Schedule::getStartDate()
{
	return to_string(this->start.getDay()) + "/" + to_string(this->start.getMonth()) + "/" + to_string(this->start.getYear());
}

bool Schedule::setEndDate(Date & endDate)
{
	if (this->year == "") return false;
	try
	{
		if (endDate.getYear() < stoi(this->year.substr(0, 4)) || endDate.getYear() > stoi(this->year.substr(0, 4)) + 1)
			return false;
	}
	catch (const exception &error)
	{
    cerr << error.what();
		return false;
	}
	this->end = endDate;
	return true;
}

bool Schedule::setEndDate(string & endDate)
{
	string day = splitToken(endDate, "/"), month = splitToken(endDate, "/");
	Date checkDate;
	try
	{
		checkDate.setYear(stoi(endDate));
		checkDate.setMonth(stoi(month));
		checkDate.setDate(stoi(day));
	}
	catch (const exception &error)
	{
    cerr << error.what();
		return false;
	}
	return this->setEndDate(checkDate);
}

string Schedule::getEndDate()
{
	return to_string(this->end.getDay()) + "/" + to_string(this->end.getMonth()) + "/" + to_string(this->end.getYear());
}

bool Schedule::setSchedule(const Week & day, const int & hour, const string &course)
{
	if (hour < 0 || hour > 3) return false;
	this->schedule[day][hour] = course;
	return true;
}

string Schedule::getSchedule(const Week & day, const int & hour)
{
	if (hour < 0 || hour > 3) return "";
	return this->schedule[day][hour];
}
