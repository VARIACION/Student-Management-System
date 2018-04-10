#ifndef REMOVE_COURSE_H
#define REMOVE_COURSE_H

#include <iostream>
#include <string>
#include <conio.h>
#include "Courses.h"
#include "ImportExportClass.h"
#include "Screen.h"
#include "AddClass.h"
using namespace std;

void drawFieldRemoveCourse();
void removeCourseMenu(ListCourses* &listCourses);
bool removeCourse(ListCourses* &listCourses, const string &code);

#endif // !REMOVE_COURSE_H
