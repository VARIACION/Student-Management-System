#ifndef EDIT_COURSE_H
#define EDIT_COURSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Screen.h"
#include "AddClass.h"
#include "Courses.h"
#include "AddCourse.h"
using namespace std;

void drawFieldEditCourse();
void editCourseMenu(ListCourses* &listCourses);
bool checkExistedCourse(const string &code, const string &name, ListCourses* &listCourses);

#endif // !EDIT_COURSE_H
