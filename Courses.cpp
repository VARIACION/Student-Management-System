#include "Courses.h"

Time::Time() {
	this->minute = this->hour = -1;
}

int Time::getHour() { return this->hour; }

int Time::getMinute() { return this->minute; }

bool Time::setHour(const int & hourInput) {
	if (hourInput < 7 || hourInput > 17)
		return false;
	this->hour = hourInput;
	return true;
}

bool Time::setMinute(const int & minuteInput) {
	if (minuteInput < 0 || minuteInput > 59)
		return false;
	this->minute = minuteInput;
	return true;
}

bool Time::operator>(Time & timeCompare)
{
  if (this->hour > timeCompare.getHour())
    return true;
  else if (this->hour < timeCompare.getHour())
    return false;
  else if (this->hour == timeCompare.getHour())
    if (this->minute > timeCompare.getMinute())
      return true;
  return false;
}

bool Time::operator<(Time & timeCompare)
{
  if (this->hour < timeCompare.getHour())
    return true;
  else if (this->hour > timeCompare.getHour())
    return false;
  else if (this->hour == timeCompare.getHour())
    if (this->minute < timeCompare.getMinute())
      return true;
  return false;
}

bool Time::operator==(Time & timeCompare)
{
  return (this->hour == timeCompare.getHour() && this->minute == timeCompare.getMinute());
}

Date::Date() {
	this->day = this->month = this->year = 0;
}

int Date::getDay() { return this->day; }

int Date::getMonth() { return this->month; }

int Date::getYear() { return this->year; }

bool Date::setMonth(const int & monthInput) {
	if (monthInput < 1 || monthInput > 12)
		return false;
	this->month = monthInput;
	return true;
}

bool Date::setYear(const int & yearInput) {
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	if (yearInput < 2000 || yearInput > 1900 + newtime.tm_year)
		return false;
	this->year = yearInput;
	return true;
}

bool Date::setDate(const int & dayInput) {
	if (this->month == 0 || this->year == 0)
		return false;
	if (dayInput < 1)
		return false;
	switch (this->month) {
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

bool Date::operator>(Date & dateCompare)
{
  if (this->year > dateCompare.getYear())
    return true;
  else if (this->year < dateCompare.getYear())
    return false;
  else if (this->year == dateCompare.getYear())
    if (this->month > dateCompare.getMonth())
      return true;
    else if (this->month < dateCompare.getMonth())
      return false;
    else if (this->month == dateCompare.getMonth())
      if (this->day > dateCompare.getDay())
        return true;
  return false;
}

bool Date::operator<(Date & dateCompare)
{
  if (this->year < dateCompare.getYear())
    return true;
  else if (this->year > dateCompare.getYear())
    return false;
  else if (this->year == dateCompare.getYear())
    if (this->month < dateCompare.getMonth())
      return true;
    else if (this->month > dateCompare.getMonth())
      return false;
    else if (this->month == dateCompare.getMonth())
      if (this->day < dateCompare.getDay())
        return true;
  return false;
}

bool Date::operator==(Date & dateCompare)
{
  if (this->day == dateCompare.getDay() && this->month == dateCompare.getMonth() && this->year == dateCompare.getYear())
    return true;
  return false;
}

Courses::Courses() {
	this->code = this->name = this->lecturerUsername = this->year = "";
	this->semester = 1;
}


Courses::~Courses(){
}

void Courses::setCode(const string & codeInput) { this->code = codeInput; }

string Courses::getCode() { return this->code; }

void Courses::setName(const string & nameInput) { this->name = nameInput; }

string Courses::getName() { return this->name; }

void Courses::setLecturerUsername(const string & lecturerUsernameInput) { this->lecturerUsername = lecturerUsernameInput; }

string Courses::getLecturerUsername() { return this->lecturerUsername; }

bool Courses::setYear(const string & yearInput) {
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
  try {
    if (yearInput.substr(0, 4) == yearInput.substr(5, 4) || 
      stoi(yearInput.substr(0, 4)) < 2000 || stoi(yearInput.substr(5, 4)) > 1900 + newtime.tm_year)
			return false;
	}
	catch (const exception &error) {
    ofstream error_message("errors_messages.log", ios::app);
    error_message << error.what() << endl;
    error_message.close();
		return false;
	}
	this->year = yearInput;
	return true;
}

string Courses::getYear() { return this->year; }

int Courses::getSemester() { return this->semester - '0'; }

bool Courses::setSemester(const char & semesterInput) {
	if (semesterInput < '1' || semesterInput > '3')
		return false;
	this->semester = semesterInput;
	return true;
}

Date Courses::getStartDate() { return this->start; }

bool Courses::setStartDate(Date & startDateInput) {
	if (this->year == "")
		return false;
	try {
		if (startDateInput.getYear() < stoi(this->year.substr(0, 4)) || startDateInput.getYear() > stoi(this->year.substr(0, 4)) + 1)
			return false;
	}
	catch (const exception &error) {
    ofstream error_message("errors_messages.log", ios::app);
    error_message << error.what() << endl;
    error_message.close();
		return false;
	}
	this->start = startDateInput;
	return true;
}

Date Courses::getEndDate() { return this->end; }

bool Courses::setEndDate(Date & endDateInput) {
	if (this->year == "")
		return false;
	try {
		if (endDateInput.getYear() < stoi(this->year.substr(0, 4)) || endDateInput.getYear() > stoi(this->year.substr(0, 4)) + 1)
			return false;
	}
	catch (const exception &error) {
    ofstream error_message("errors_messages.log", ios::app);
    error_message << error.what() << endl;
    error_message.close();
		return false;
	}
	this->end = endDateInput;
	return true;
}

Time Courses::getStartTime() { return this->from; }

bool Courses::setStartTime(string & startTimeInput) { 
	int hour, minute;
	try {
		hour = stoi(splitToken(startTimeInput, "h"));
		minute = stoi(startTimeInput);
	}
	catch (exception &error) {
    ofstream error_message("errors_messages.log", ios::app);
    error_message << error.what() << endl;
    error_message.close();
		return false;
	}
	return (this->from.setHour(hour) && this->from.setMinute(minute));
}

Time Courses::getEndTime() { return this->to; }

string Courses::getStartTime_str() {
	return to_string(this->from.getHour()) + "h" + to_string(this->from.getMinute());
}

string Courses::getEndTime_str() {
	return to_string(this->to.getHour()) + "h" + to_string(this->to.getMinute());
}

bool Courses::setEndTime(string & endTimeInput) {
	int hour, minute;
	try {
		hour = stoi(splitToken(endTimeInput, "h"));
		minute = stoi(endTimeInput);
	}
	catch (const exception &error) {
    ofstream error_message("errors_messages.log", ios::app);
    error_message << error.what() << endl;
    error_message.close();
		return false;
	}
	return (this->to.setHour(hour) && this->to.setMinute(minute));
}

bool Courses::setDateOfWeek(const string &dayStart)  {
	if (dayStart == "MONDAY")
		this->dateOfWeek = MONDAY;
	else if (dayStart == "TUESDAY")
		this->dateOfWeek = TUESDAY;
	else if (dayStart == "WEDNESDAY")
		this->dateOfWeek = WEDNESDAY;
	else if (dayStart == "THURSDAY")
		this->dateOfWeek = THURSDAY;
	else if (dayStart == "FRIDAY")
		this->dateOfWeek = FRIDAY;
	else if (dayStart == "SATURDAY")
		this->dateOfWeek = SATURDAY;
	else if (dayStart == "SUNDAY")
		this->dateOfWeek = SUNDAY;
	else return false;
	return true;
}

Week Courses::getDateOfWeek() { return this->dateOfWeek; }

ListCourses::~ListCourses() {
	this->list.clear();
}

string Courses::getStartDate_str() {
	return to_string(this->start.getDay()) + "/" + to_string(this->start.getMonth()) + "/" + to_string(this->start.getYear());
}

string Courses::getEndDate_str() {
	return to_string(this->end.getDay()) + "/" + to_string(this->end.getMonth()) + "/" + to_string(this->end.getYear());
}

string Courses::getDateOfWeek_str() {
	switch (this->dateOfWeek) {
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
  return "";
}

bool Courses::setStartDate_str(string & startDataInput) {
	string day = splitToken(startDataInput, "/");
	string month = splitToken(startDataInput, "/");
	Date checkDate;
	try {
		checkDate.setYear(stoi(startDataInput));
		checkDate.setMonth(stoi(month));
		checkDate.setDate(stoi(day));
	}
	catch (const exception &error) {
    ofstream error_message("errors_messages.log", ios::app);
    error_message << error.what() << endl;
    error_message.close();
		return false;
	}
	return this->setStartDate(checkDate);
}

bool Courses::setEndDate_str(string & endDataInput) {
	string day = splitToken(endDataInput, "/");
	string month = splitToken(endDataInput, "/");
	Date checkDate;
	try {
		checkDate.setYear(stoi(endDataInput));
		checkDate.setMonth(stoi(month));
		checkDate.setDate(stoi(day));
	}
	catch (const exception &error) {
    ofstream error_message("errors_messages.log", ios::app);
    error_message << error.what() << endl;
    error_message.close();
		return false;
	}
	return this->setEndDate(checkDate);
}

bool Courses::compareStartEndDate() {
  if (this->start > this->end)
    return true;
  else
    return false;
}

bool Courses::compareStartEndTime()
{
  if (this->from > this->to)
    return true;
  else
    return false;
}