#ifndef ADD_COURSE_H
#define ADD_COURSE_H

#include <iostream>
#include <string>
#include <conio.h>
#include "Screen.h"
#include "Courses.h"
#include "Screen.h"
#include "AddClass.h"
using namespace std;

void drawFieldBasicInfo();
void drawFieldDateTime();
int basicInfoMenu(string basicInfo[]);
void dateTimeMenu(string dateInfo[]);
void addCourseMenu(ListCourses &listCourses);

#endif // !ADD_COURSE_H
