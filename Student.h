#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	uint32_t no, id;
	string name;

public:
	Student();
	~Student();

	uint32_t getNo();
	void setNo(const uint32_t &noInput);
	void setNo(const string &noInput);

	uint32_t getId();
	bool setId(const uint32_t &idInput);
	bool setId(const string &idInput);

	string getName();
	void setName(const string &nameInput);

	Student *nextStudent;
};

#endif // !STUDENT_H