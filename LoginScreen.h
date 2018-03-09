#ifndef STUDENT_MANAGEMENT_SYSTEM_LOGIN_SCREEN_H
#define STUDENT_MANAGEMENT_SYSTEM_LOGIN_SCREEN_H

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "Screen.h"
#include "MD5Generate.h"
#include <fstream>
using namespace std;

void drawFrameInput();
void drawLoginMenu();
int controlLoginMenu();
void checkPasswordInput(string &password);
void checkUsernameInput(string &username);
void loginMenu();
void encryptDataInput(const string &username, const string &password, string & usernameToMD5, string & passwordToMD5);
int checkRoleLogin(const string &username, const string & password);
void prompExit();

#endif // !STUDENT_MANAGEMENT_SYSTEM_LOGIN_SCREEN_H
