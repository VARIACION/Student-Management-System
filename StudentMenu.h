#ifndef STUDENT_MENU_H
#define STUDENT_MENU_H

#include "Student.h"
#include "Class.h"
#include <iostream>
#include "Screen.h"
#include <fstream>
#include <string>
#include <conio.h>
#include "AcademicStaff.h"
#include <vector>
#include "Class.h"
#include "ImportExportClass.h"
#include "AddStudent.h"
#include "RemoveStudent.h"
#include "AddClass.h"
#include "ChangeClass.h"
#include "EditStudent.h"
#include "ViewClasses.h"
#include "ViewStudents.h"
using namespace std;

void drawStudentMenu();
int controlStudentMenu();
void studentMenu(Faculty &faculty);

#endif // !STUDENT_MENU_H
