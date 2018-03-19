#ifndef ADD_STUDENT_H
#define ADD_STUDENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "Screen.h"
#include "Class.h"
#include <conio.h>
#include "ImportExportClass.h"
#include "AddClass.h"
using namespace std;

void drawFieldAddStudent();
void addStudentMenu(Faculty &faculty);
bool addNewStudent(Faculty &faculty, const string &className, const string &ID, const string &name);

#endif // !ADD_STUDENT_H
