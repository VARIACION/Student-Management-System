#ifndef IMPORT_EXPORT_SCOREBOARD_H
#define IMPORT_EXPORT_SCOREBOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Screen.h"
#include "ScoreBoard.h"
#include "AddClass.h"
using namespace std;

void drawFieldImportExportScoreboard();

void importExportScoreboardMenu(ListScoreboard &listScoreboard);

bool importScoreboardFromFile(ListScoreboard &listScoreboard, const string &path);

int exportScoreboardToFile(ListScoreboard &listScoreboard, const string &path, const string &className);

#endif // !IMPORT_EXPORT_SCOREBOARD_H
