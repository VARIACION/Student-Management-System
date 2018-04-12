#ifndef VIEW_SCORE_STUDENT_H_
#define VIEW_SCORE_STUDENT_H_

#include <conio.h>
#include <Windows.h>

#include <iostream>
#include <string>
#include <iomanip>

#include "Screen.h"
#include "ScoreBoard.h"
#include "User.h"
#include "AddClass.h"
using namespace std;

void DrawFieldViewMyScore();
void DrawFieldPrintScore(ScoreBoard &scoreboard, User &student);
void ViewScoreStudentMenu(ListScoreboard* &listScoreboard, User &student);

#endif // !VIEW_SCORE_STUDENT_H_
