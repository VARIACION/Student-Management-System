#ifndef ADD_STUDENT_H
#define ADD_STUDENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "Screen.h"
#include "Class.h"
#include <conio.h>
#include "ImportExportClass.h"
using namespace std;

void drawFieldAddStudent();
int controlAddStudentMenu();
void addStudentMenu(Faculty &faculty);

#endif // !ADD_STUDENT_H
