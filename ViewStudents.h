#ifndef VIEW_STUDENTS_H
#define VIEW_STUDENTS_H

#include <iostream>
#include <conio.h>
#include "Class.h"
#include "Student.h"
#include "Screen.h"
#include <string>
#include "ImportExportClass.h"
#include "ViewClasses.h"
using namespace std;

void drawFieldViewStudents();
void drawFieldDisplayStudents();
int controlViewStudentsMenu();
void displayStudent(Student* &copyStudents, const int &pointStudent, const int &numberOfStudents);
void copyStudentsFromListToArray(Class &className, Student* &copyStudents);
bool callScreenDisplayMenu(Faculty &faculty, const string &className);
void viewStudentsMenu(Faculty &faculty);

#endif // !VIEW_STUDENTS_H
