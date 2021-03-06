#ifndef REMOVE_STUDENT_H
#define REMOVE_STUDENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "Class.h"
#include "Student.h"
#include "Screen.h"
#include <conio.h>
#include <string>
#include "ImportExportClass.h"
#include "AddClass.h"
using namespace std;

void drawFieldRemoveStudent();
void removeStudentMenu(Faculty &faculty);
int removeStudent(Faculty &faculty, const string &idStudentRemoved, const string &classStudentRemoved);

#endif // !REMOVE_STUDENT_H
