#ifndef ADD_CLASS_H
#define ADD_CLASS_H

#include <iostream>
#include <string>
#include "Class.h"
#include <conio.h>
#include "ImportExportClass.h"
using namespace std;

void drawFieldAddClass();
int controlAddClassMenu();
void addClassMenu(Faculty &faculty);
bool addClass(Faculty &faculty, const string &nameNewClass);

#endif // !ADD_CLASS_H