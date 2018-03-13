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
using namespace std;

void drawFrameInput();
void drawLoginMenu();
int controlLoginMenu();
void checkPasswordInput(const int &x, const int &y, string &password);
void checkUsernameInput(string &username);
User loginMenu();
void encryptDataInput(const string &username, const string &password, string & usernameToMD5, string & passwordToMD5);
char * reformatInputData(string &dataInput);
User checkLogin(const string &username, const string & password, bool &checkValidLogin);
void prompExit();
void aboutProject();

#endif // !STUDENT_MANAGEMENT_SYSTEM_LOGIN_SCREEN_H
