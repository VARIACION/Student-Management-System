#ifndef SEARCH_VIEW_SCOREBOARD_H
#define SEARCH_VIEW_SCOREBOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include "Screen.h"
#include "ScoreBoard.h"
#include "AddClass.h"
using namespace std;

void drawFieldSearchViewScoreboard();
void drawFieldViewDetailScoreboard();
void viewBasicInfoScoreboard(ScoreBoard &scoreboard);
void searchViewScoreboardMenu(ListScoreboard &listScoreboard);
bool checkViewScoreboard(ListScoreboard &listScroreboard, const string &courseName, const string &className);
void viewDetailInfoScoreboard(ScoreBoard &scoreboard);
void displayDetailScoreboard(ScoreBoard &scoreboard, const int &pointStudent);

#endif // !SEARCH_VIEW_SCOREBOARD_H
