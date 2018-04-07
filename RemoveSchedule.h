#ifndef REMOVE_SCHEDULE_H
#define REMOVE_SCHEDULE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Screen.h"
#include "Schedules.h"
#include "AddClass.h"
using namespace std;

void drawFieldRemoveSchedule();
void removeScheduleMenu(ListSchedules* &listSchedules);
bool removeSchedule(ListSchedules* &listSchedules, const string &className);

#endif // !REMOVE_SCHEDULE_H
