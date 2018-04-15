#ifndef STUDENT_MANAGEMENT_SYSTEM_LOGIN_SCREEN_H
#define STUDENT_MANAGEMENT_SYSTEM_LOGIN_SCREEN_H

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "Screen.h"
#include "MD5Generate.h"
#include <fstream>
#include "User.h"
#include "AcademicStaff.h"
#include "UserInformation.h"
#include <iterator>
using namespace std;

void drawFrameInput();
void drawLoginMenu();
int controlLoginMenu();
bool checkPasswordInput(const int &x, const int &y, string &password);
void checkUsernameInput(string &username);
User loginMenu(bool &exit_signal);
void encryptDataInput(const string &username, const string &password, string & usernameToMD5, string & passwordToMD5);
User checkLogin(const string &username, const string & password, bool &checkValidLogin);
void aboutProject();
bool checkInputDatabase();

#endif // !STUDENT_MANAGEMENT_SYSTEM_LOGIN_SCREEN_H
