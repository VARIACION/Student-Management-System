#ifndef ACADEMIC_STAFF_H
#define ACADEMIC_STAFF_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "LoginScreen.h"
#include "MD5Generate.h"
#include "User.h"
using namespace std;

void drawAcademicStaffMenu();
int controlAcademicStaffMenu();
void accessInfo(User &staff);
void academicStaffMenu(User &staff);
int chooseMenuInInfoMenu();
void changePassword(User &staff);
char * fromStrCppToStrC(const string &stringCpp);
void saveNewPassword(User &staff, string &oldPassword, string &newPassword, string &renewPassword);

#endif // !ACADEMIC_STAFF_H
