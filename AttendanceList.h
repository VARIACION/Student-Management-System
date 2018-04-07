#ifndef ATTENDANCE_LIST_H
#define ATTENDANCE_LIST_H

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "Screen.h"
#include "Presence.h"
#include "SearchViewAttendanceList.h"
#include "ImportExportAttendanceList.h"
using namespace std;

void drawFieldAttendanceList();
int controlAttendanceListMenu();
void attendanceListMenu(ListPresence* &listPresence);

#endif // !ATTENDANCE_LIST_H
