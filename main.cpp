#include "LoginScreen.h"
#include "AcademicStaff.h"
#include "StudentMenu.h"
#include "Lecturer.h"
#include "StudentRoleMenu.h"
#include "ScoreBoard.h"
#include "AttendanceList.h"

int main() {
	setFullScreen();
	setScreenAttribute();
  ListScoreboard *listScoreboard = new ListScoreboard;
  ListPresence *listPresence = new ListPresence;
  ListSchedules *listSchedules = new ListSchedules;
  ListCourses *listCourses = new ListCourses;
  bool exit_signal = false;
	while (true) {
		User userLogin = loginMenu(exit_signal);
    if (exit_signal)
      break;
		if (userLogin.getType() == 1)
			academicStaffMenu(userLogin, listScoreboard, listPresence, listSchedules, listCourses);
		else if (userLogin.getType() == 2)
			lecturerMenu(userLogin, listScoreboard, listPresence, listSchedules);
		else
			studentRoleMenu(listCourses, listSchedules, listPresence, listScoreboard, userLogin);
	}
  delete listScoreboard;
  delete listPresence;
  delete listSchedules;
  delete listCourses;
  return EXIT_SUCCESS;
}