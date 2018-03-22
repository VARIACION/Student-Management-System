#ifndef COURSE_MENU_H
#define COURSE_MENU_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Screen.h"
#include "ImportExportClass.h"
#include "Student.h"
#include "Courses.h"
#include "Class.h"
#include "ImportExportCourses.h"
#include "RemoveCourse.h"
#include "AddCourse.h"
#include "EditCourse.h"
#include "ViewCourses.h"
using namespace std;

void drawCoursesMenu();
int controlCoursesMenu();
void courseMenu(ListCourses &listCourses);

#endif // !COURSE_MENU_H
