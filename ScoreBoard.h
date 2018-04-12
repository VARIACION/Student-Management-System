#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>
#include <vector>
#include <iterator>
using namespace std;

struct SheetScore
{
	map<int, string> student;
	map<int, vector<double>> list;
};

class ScoreBoard
{
private:
	string className, year, course, lecturerName;
	char semester;
	SheetScore score;

public:
	ScoreBoard();

	~ScoreBoard();

	void setClassName(const string &name);

	string getClassName();

  void setLecturerName(const string &name);

  string getLecturerName();

	void setCourse(const string &courseInput);

	string getCourse();

	bool setYear(const string &yearInput);

	string getYear();

	bool setSemester(const int &semesterInput);

	int getSemester();

	void setStudent(const int &no, const string &name);

	string getStudent(const int &no);

  int getStudent(const string &name);

	int getSizeOfClass();

	bool setScore(const int &no, const double &scoreInput);

  bool setScore(const int &no, const double &scoreInput, const int &type);

	double getScore(const int &no, const int &type);
};

struct ListScoreboard
{
	vector<ScoreBoard> list;
	~ListScoreboard();
};