#ifndef CLASS_H
#define CLASS_H

#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Class
{
public:
	Student *student;
	string name;
	Class();
};

struct Faculty
{
	vector<Class> classMember;
	~Faculty();
};


void deleteClass(Class &classMember);
#endif // !CLASS_H
