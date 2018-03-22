#ifndef IMPORT_EXPORT_SCHEDULE_H
#define IMPORT_EXPORT_SCHEDULE_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "ImportExportClass.h"
#include "Schedules.h"
#include "Screen.h"
#include <string.h>
using namespace std;

void drawFiledImportExportSchedules();
void importExportSchedulesMenu(ListSchedules &listSchedules);
bool importScheduleFromFile(ListSchedules &listSchedules, const string &path);
bool exportScheduleToFile(ListSchedules &listSchedules, const string &path, const string &className);

#endif // !IMPORT_EXPORT_SCHEDULE_H
