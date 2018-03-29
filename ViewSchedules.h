#ifndef VIEW_SCHEDULES_H
#define VIEW_SCHEDULES_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Screen.h"
#include "Schedules.h"
#include "AddClass.h"
using namespace std;

void drawFieldViewSchedules();
void displayBasicSchedule(Schedule &schedule);
void displayDetailSchedule(Schedule &schedule);
void displaySchedule(Schedule &schedule);
void displayListSchedules(ListSchedules &listSchedules, const int &pointSchedule);
void viewSchedulesMenu(ListSchedules &listSchedules);

#endif // !VIEW_SCHEDULES_H
