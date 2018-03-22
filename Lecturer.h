#ifndef LECTURER_H
#define LECTURER_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include "Screen.h"
#include "User.h"
#include "UserInformation.h"
using namespace std;

void drawFieldLecturer();
int controlLecturerMenu();
void lecturerMenu(User &lecturer);

#endif // !LECTURER_H