#include "ScoreBoard.h"

ScoreBoard::ScoreBoard()
{
	this->className = this->year = this->lecturerName = "";
	this->semester = '0';
}

ScoreBoard::~ScoreBoard()
{
	for (size_t i = 0; i < this->score.student.size(); ++i)
		this->score.student[i].clear();
	for (size_t i = 0; i < this->score.list.size(); ++i)
		this->score.list[i].clear();
}

void ScoreBoard::setClassName(const string & name) { this->className = name; }

string ScoreBoard::getClassName() { return this->className; }

void ScoreBoard::setCourse(const string & courseInput) { this->course = courseInput; }

string ScoreBoard::getCourse() { return this->course; }

bool ScoreBoard::setYear(const string & yearInput)
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

string ScoreBoard::getYear() { return this->year; }

bool ScoreBoard::setSemester(const int & semesterInput)
{
	if (semesterInput < 1 || semesterInput > 3)
		return false;
	this->semester = to_string(semesterInput)[0];
	return true;
}

int ScoreBoard::getSemester() { return this->semester - '0'; }

void ScoreBoard::setStudent(const int & no, const string & name) { this->score.student[no - 1] = name; }

string ScoreBoard::getStudent(const int & no) { return this->score.student[no - 1]; }

int ScoreBoard::getStudent(const string & name)
{
  for (int i = 0; i < this->score.student.size(); ++i)
    if (this->score.student[i] == name)
      return i + 1;
  return -1;
}

int ScoreBoard::getSizeOfClass() { return this->score.student.size(); }

bool ScoreBoard::setScore(const int & no, const double & scoreInput)
{
	if (no < 1 || no > this->score.student.size() || scoreInput < 0 || scoreInput > 10) 
    return false;
	this->score.list[no - 1].push_back(scoreInput);
	return true;
}

bool ScoreBoard::setScore(const int & no, const double & scoreInput, const int & type)
{
  if (no < 1 || no > this->score.student.size() || scoreInput < 0 || scoreInput > 10 || type < 0 || type > 2)
    return false;
  this->score.list[no - 1][type] = scoreInput;
  return true;
}

double ScoreBoard::getScore(const int & no, const int & type)
{
	if (no < 1 || no > this->score.student.size() || type < 1 || type > 3) return -1;
	return this->score.list[no - 1][type - 1];
}

ListScoreboard::~ListScoreboard()
{
	this->list.clear();
}

void ScoreBoard::setLecturerName(const string & name)
{
  this->lecturerName = name;
}

string ScoreBoard::getLecturerName()
{
  return this->lecturerName;
}