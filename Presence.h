#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>
#include <vector>
#include <iterator>
using namespace std;

struct SheetPresence
{
	map<int, string> students;
	map<int, vector<bool>> list;
};

class Presence
{
private:
	string className, year, course;
	char semester;
	SheetPresence presence;
public:
	Presence();

	~Presence();

	void setClassName(const string &name);

	string getClassName();

	void setCourse(const string &courseInput);

	string getCourse();

	bool setYear(const string &yearInput);

	string getYear();

	bool setSemester(const int &semesterInput);

	int getSemester();

	bool setPresence(const int &no, const bool &isPresence);

	string getPresence(int &no, int &week);

	void setStudent(const int &no, const string &name);

	string getStudent(const int &no);

	int getSizeOfClass();

	int getNumberOfWeek();
};

struct ListPresence
{
	vector<Presence> list;
	~ListPresence();
};