#ifndef EDIT_STUDENT_H
#define EDIT_STUDENT_H

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "Class.h"
#include "Student.h"
#include "Screen.h"
#include "ImportExportClass.h"
#include "AddClass.h"
using namespace std;

void drawFieldEditStudent();
void editStudentMenu(Faculty &faculty);
int editStudent(Faculty &faculty, const string &currentID, const string &newId, const string &newName);

#endif // !EDIT_STUDENT_H
