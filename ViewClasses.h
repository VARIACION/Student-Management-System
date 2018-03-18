#ifndef VIEW_CLASSES_H
#define VIEW_CLASSES_H

#include <iostream>
#include <conio.h>
#include "Class.h"
#include "Student.h"
#include "Screen.h"
#include <string>
using namespace std;

void drawFieldViewClasses();
void displayClass(Faculty &faculty, const int &pointClass);
int countNumberOfStudentsInClass(Class &className);
void viewClassesMenu(Faculty &faculty);

#endif // !VIEW_CLASSES_H
