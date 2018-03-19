#ifndef IMPORT_EXPORT_COURSES_H
#define IMPORT_EXPORT_COURSES_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "ImportExportClass.h"
#include "Screen.h"
#include "LoginScreen.h"
#include "Courses.h"
using namespace std;

void drawFieldImportExportCourses();
void importExportCoursesMenu(ListCourses &listCourses);
bool reformatDate(string dateString, Date &date);
bool reformatTime(string timeInput, Time &time);
Week reformatDateOfWeek(const string &date);
string splitToken(string &stringInput, const string &delim);
bool importCoursesFromFile(ListCourses &listCourses, const string &path);
bool exportCoursesToFile(ListCourses &listCourses, const string &path);

#endif // !IMPORT_EXPORT_COURSES_H
