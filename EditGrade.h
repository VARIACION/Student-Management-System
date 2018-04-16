#ifndef EDIT_GRADE_H
#define EDIT_GRADE_H

#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Screen.h"
#include "ScoreBoard.h"
#include "AddClass.h"
#include "User.h"
using namespace std;

void DrawFieldEditGrade();
void DrawFieldInputNewGrade();
int InputNewGrade(double new_grade[3], bool &validInput);
void EditGradeMenu(User &lecturer, ListScoreboard* &listScoreboard);
int EditGrade(User &lecturer, ListScoreboard* &listScoreboard, const string &studentName, const string &className);

#endif // !EDIT_GRADE_H
