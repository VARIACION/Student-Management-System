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
using namespace std;

void drawFieldRemoveStudent();
int controlRemoveStudentMenu();
void removeStudentMenu(Faculty &faculty);
bool removeStudent(Faculty &faculty, const string &idStudentRemoved, const string &classStudentRemoved);

#endif // !REMOVE_STUDENT_H
