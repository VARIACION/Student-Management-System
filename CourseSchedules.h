#ifndef COURSE_SCHEDULES_H
#define COURSE_SCHEDULES_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Screen.h"
#include "Schedules.h"
#include "ImportExportSchedule.h"
#include "RemoveSchedule.h"
#include "AddSchedule.h"
#include "EditSchedule.h"
#include "ViewSchedules.h"
using namespace std;

void drawFieldCourseSchedulesMenu();
int controlCourseSchedulesMenu();
ListSchedules * courseSchedulesMenu();

#endif // !COURSE_SCHEDULES_H
