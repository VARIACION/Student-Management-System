#ifndef IMPORT_EXPORT_CLASS_H
#define IMPORT_EXPORT_CLASS_H

#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include "Screen.h"
#include "Class.h"
using namespace std;

void drawFieldInputFileName();
int controlFileImportExport();
string getFileName(const int &x, const int &y);

Student *allocateNewStudent(string &input);

void importExportStudentFromFile(Faculty &faculty);
bool importStudentFromFile(Faculty &faculty, const string &path);
int exportStudentToFile(Faculty &faculty, const string &path, const string &mode);

#endif // !IMPORT_EXPORT_CLASS_H
