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
  ListSchedules *listSchedules;
  bool exit_signal = false;
	while (true) {
		User userLogin = loginMenu(exit_signal);
    if (exit_signal)
      break;
		if (userLogin.getType() == 1)
			academicStaffMenu(userLogin, listScoreboard, listPresence, listSchedules);
		else if (userLogin.getType() == 2)
			lecturerMenu(userLogin, listScoreboard, listPresence);
		else
			studentRoleMenu(listSchedules, listPresence, listScoreboard, userLogin);
	}
  delete listScoreboard;
  delete listPresence;
  return EXIT_SUCCESS;
}