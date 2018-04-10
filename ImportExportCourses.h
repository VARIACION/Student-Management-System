#ifndef IMPORT_EXPORT_COURSES_H
#define IMPORT_EXPORT_COURSES_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "ImportExportClass.h"
#include "Screen.h"
#include "Courses.h"
#include "LoginScreen.h"
using namespace std;

void drawFieldImportExportCourses();
void importExportCoursesMenu(ListCourses* &listCourses);
bool importCoursesFromFile(ListCourses* &listCourses, const string &path);
bool exportCoursesToFile(ListCourses* &listCourses, const string &path);

#endif // !IMPORT_EXPORT_COURSES_H
