#ifndef IMPORT_EXPORT_ATTENDANCE_LIST_H
#define IMPORT_EXPORT_ATTENDANCE_LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include "Screen.h"
#include <conio.h>
#include "Presence.h"
#include "ImportExportClass.h"

void drawFieldImportExportAttendanceList();
void importExportAttendanceListFromFile(ListPresence* &listPresence);
int importAttendanceListFromFile(ListPresence* &listPresence, const string &path);
int exportAttendanceListToFile(ListPresence* &listPresence, const string &path, const string &className, const string &course);

#endif // !IMPORT_EXPORT_ATTENDACE_LIST_H
