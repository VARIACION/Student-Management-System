#ifndef COURSES_H
#define COURSES_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;


class Time
{
private:
	int hour, minute;
public:
	Time();
	int getHour();
	int getMinute();

	bool setHour(const int &hourInput);
	bool setMinute(const int &minuteInput);
};

class Date
{
private:
	int day, month, year;
public:
	int getDay();
	int getMonth();
	int getYear();

	bool setMonth(const int &monthInput);
	bool setYear(const int &yearInput);
	bool setDate(const int &dayInput);

	Date();
};

enum Week
{
	MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

class Courses
{
private:
	string code, name, lecturerUsername, year;
	char semester;
	Date start, end;
	Time from, to;
	Week dateOfWeek;
public:
	Courses();
	~Courses();

	void setCode(const string &codeInput);
	string getCode();
	void setName(const string &nameInput);
	string getName();
	void setLecturerUsername(const string &lecturerUsernameInput);
	string getLecturerUsername();
	bool setYear(const string &yearInput);
	string getYear();
	int getSemester();
	bool setSemester(const char &semesterInput);
	Date getStartDate();
	bool setStartDate(Date &startDateInput);
	Date getEndDate();
	bool setEndDate(Date &endDateInput);
	string getStartDate_str();
	string getEndDate_str();
	Time getStartTime();
	void setStartTime(Time &startTimeInput);
	Time getEndTime();
	string getStartTime_str();
	string getEndTime_str();
	void setEndTime(Time &endTimeInput);
	void setDateOfWeek(Week &dayStart);
	Week getDateOfWeek();
	string getDateOfWeek_str();
};

struct ListCourses
{
	vector<Courses> list;
	~ListCourses();
};

#endif // !COURSES_H