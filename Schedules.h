#ifndef SCHEDULES_H
#define SCHEDULES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Courses.h"
#include <iterator>
#include <ctime>
#include "Screen.h"
using namespace std;

class Schedule
{
private:
	string className, year;
	char semester;
	Date start, end;
	map<Week, vector<string>> schedule;
public:
	Schedule();

	~Schedule();

	void setClassName(const string &name);

	string getClassName();

	bool setYear(const string &yearInput);

	string getYear();

	bool setSemester(const int &semesterInput);

	int getSemester();

	bool setStartDate(Date &startDate);

	bool setStartDate(string &startDate);

	string getStartDate();

	bool setEndDate(Date &endDate);

	bool setEndDate(string &endDate);

	string getEndDate();

	bool setSchedule(const Week &day, const int &hour, const string &course);

	string getSchedule(const Week &day, const int &hour);
};

struct ListSchedules
{
	vector<Schedule> list;
	~ListSchedules();
};

#endif // !SCHEDULES_H