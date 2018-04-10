#ifndef VIEW_COURSES_H
#define VIEW_COURSES_H

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "Screen.h"
#include "Courses.h"
#include "ImportExportClass.h"
using namespace std;

void drawFieldViewCourses();
void displayCourses(ListCourses* &listCourses, const int &pointCourse);
void displayDetailCourse(Courses &course);
void viewCourseMenu(ListCourses* &listCourses);

#endif // !VIEW_COURSES_H
