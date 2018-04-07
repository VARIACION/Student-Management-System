#ifndef EDIT_SCHEDULE_H
#define EDIT_SCHEDULE_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Screen.h"
#include "Schedules.h"
#include "AddClass.h"
#include "AddSchedule.h"
using namespace std;

void drawFieldEditSchedule();
void editScheduleMenu(ListSchedules* &listSchedules);

#endif // !EDIT_SCHEDULE_H
