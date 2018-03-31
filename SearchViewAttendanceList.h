#ifndef SEARCH_VIEW_ATTENDANCE_LIST_H
#define SEARCH_VIEW_ATTENDANCE_LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include "Screen.h"
#include "Presence.h"
#include "AddClass.h"
using namespace std;

void drawSearchAndViewAttendanceList();

void searchViewAttendanceListMenu(ListPresence &listPresence);

bool checkViewAtendanceList(ListPresence &listPresence, const string &courseName, const string &className);

void viewBasicInfoAttendanceList(Presence &presence);

void viewDetailInforAttendanceList(Presence &presence);

void drawFieldViewDetailInfoAttendanceList();

void displayDetail(Presence &presence, const int &pointStudent, const int &pointPresence);

#endif // !SEARCH_VIEW_ATTENDANCE_LIST_H
