#ifndef ADD_SCHEDULE_H
#define ADD_SCHEDULE_H

#include <iostream>
#include <fstream>
#include <string>
#include "Screen.h"
#include "Schedules.h"
#include "AddClass.h"
using namespace std;

void drawFieldBasicInfoSchedule();
void drawFieldAddSchedule();
void inputBasicInfoSchedule(string basicInfo[], bool &invalidInformation);
void inputSchedule(Schedule &schedule);
void addScheduleMenu(ListSchedules* &listSchedules);

#endif // !ADD_SCHEDULE_H
