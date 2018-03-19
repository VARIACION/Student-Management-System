#ifndef CHANGE_CLASS_H
#define CHANGE_CLASS_H

#include <iostream>
#include <conio.h>
#include <string>
#include "Screen.h"
#include "RemoveStudent.h"
#include "AddStudent.h"
#include "Class.h"
#include "AddClass.h"
using namespace std;

void drawFieldChangeClass();
void changeClassMenu(Faculty &faculty);
bool changeClass(Faculty &faculty, const string &id, const string &newClass);

#endif // !CHANGE_CLASS_H
