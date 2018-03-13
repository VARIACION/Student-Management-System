#ifndef USER_INFORMATION_H
#define USER_INFORMATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "User.h"
#include "LoginScreen.h"
#include "AcademicStaff.h"
using namespace std;

void accessInfo(User &staff);
int chooseMenuInInfoMenu();
bool changePassword(User &staff);
bool checkNewPassword(User &staff, string &oldPassword, string &newPassword, string &renewPassword);
void applyNewPassword(User &staff, const string &newPassword);


#endif // !USER_INFORMATION_H
