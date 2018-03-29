#include "Presence.h"

Presence::Presence()
{
	this->className = this->year = "";
	this->semester = '0';
}

Presence::~Presence()
{
	for (int i = 0; i < this->presence.list.size(); ++i)
		this->presence.list[i].clear();
	for (int i = 0; i < this->presence.students.size(); ++i)
		this->presence.students[i].clear();
}

void Presence::setClassName(const string & name) { this->className = name; }

string Presence::getClassName() { return this->className; }

void Presence::setCourse(const string & courseInput) { this->course = courseInput; }

string Presence::getCourse() { return this->course; }

bool Presence::setYear(const string & yearInput)
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
		return false;
	}
	this->year = yearInput;
	return true;
}

string Presence::getYear() { return this->year; }

bool Presence::setSemester(const int & semesterInput)
{
	if (semesterInput < 1 || semesterInput > 3)
		return false;
	this->semester = to_string(semesterInput)[0];
	return true;
}

int Presence::getSemester() { return this->semester - '0'; }

bool Presence::setPresence(const int & no, const bool & isPresence)
{
	if (no < 1 || no > this->presence.students.size()) return false;
	this->presence.list[no - 1].push_back(isPresence);
	return true;
}

string Presence::getPresence(int & no, int & week)
{
	if (no < 1 || no > this->presence.students.size() || week < 1 || week > this->presence.list[no - 1].size()) return "";
	else if (this->presence.list[no - 1][week - 1]) return "1";
	else return "0";
}

void Presence::setStudent(const int & no, const string & name)
{
	this->presence.students[no - 1] = name;
}

string Presence::getStudent(const int & no)
{
	return this->presence.students[no - 1];
}

int Presence::getSizeOfClass()
{
	return this->presence.students.size();
}

int Presence::getNumberOfWeek()
{
	return this->presence.list[0].size();
}

ListPresence::~ListPresence()
{
	this->list.clear();
}