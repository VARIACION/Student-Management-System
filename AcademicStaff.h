#ifndef ACADEMIC_STAFF_H
#define ACADEMIC_STAFF_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "LoginScreen.h"
#include "MD5Generate.h"
#include "User.h"
#include "UserInformation.h"
#include "Screen.h"
#include "StudentMenu.h"
using namespace std;

void drawAcademicStaffMenu();
int controlAcademicStaffMenu();
void academicStaffMenu(User &staff);

#endif // !ACADEMIC_STAFF_H
