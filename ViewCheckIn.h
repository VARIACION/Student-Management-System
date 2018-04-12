#ifndef VIEW_CHECK_IN_H
#define VIEW_CHECK_IN_H

#include <conio.h>
#include <Windows.h>

#include <iostream>
#include <fstream>
#include <string>

#include "Screen.h"
#include "User.h"
#include "Courses.h"
#include "Presence.h"
#include "AddClass.h"
using namespace std;

void DrawFieldInputCourseToCheckIn();
void drawFieldViewCheckIn(const int &current_week, const string &courseName);
void DisplayDetailCheckIn(Presence &presence, User &student, const int &pointPresence, const int &getNoOfStudent);
void ViewCheckInMenu(Presence &presence, User &student, const int &current_week);
void CheckViewCheckIn(ListPresence* &listPresence, User &student, const int &current_week);

#endif // !VIEW_CHECK_IN_H
