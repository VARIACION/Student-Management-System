#ifndef CHECK_IN_H
#define CHECK_IN_H

#include <conio.h>
#include <Windows.h>
#include <ctime>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "Screen.h"
#include "Schedules.h"
#include "Courses.h"
#include "Presence.h"
#include "User.h"
using namespace std;

void GetCurrentDay(Time &current_time, Week &current_day);
bool CheckIn(ListCourses* &listCourses, ListPresence* &listPresence, User &student, const int &current_week);

#endif // !CHECK_IN_H
