#ifndef SCOREBOARD_STAFF_H
#define SCOREBOARD_STAFF_H

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "Screen.h"
#include "ScoreBoard.h"
#include "ImportExportScoreboard.h"
#include "SearchViewScoreboard.h"
using namespace std;

void drawFieldScoreboardStaff();
int controlScoreboardStaffMenu();
void scoreboardStaffMenu(ListScoreboard* &listScoreboard);

#endif // !SCOREBOARD_STAFF_H
