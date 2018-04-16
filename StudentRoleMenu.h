#ifndef STUDENT_ROLE_MENU_H
#define STUDENT_ROLE_MENU_H

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "User.h"
#include "Screen.h"
#include "UserInformation.h"
#include "SearchViewAttendanceList.h"
#include "CheckIn.h"
#include "ViewCheckIn.h"
#include "ViewScoreStudent.h"
#include "MD5Generate.h"
using namespace std;

void drawFieldStudentRoleMenu();
int controlStudentRoleMenu();
void drawFieldLogoutExit();
int controlLogoutExitMenu();
void studentRoleMenu(ListCourses* &listCourses, ListSchedules* &listSchedules, ListPresence* &listPresence, ListScoreboard* &listScoreboard, User &student);

#endif // !STUDENT_ROLE_MENU_H
