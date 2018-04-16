#include "CheckIn.h"

void GetCurrentDay(Time &current_time, Week &current_day) {
  system("cls");
  struct tm newtime;
  time_t now = time(0);
  localtime_s(&newtime, &now);
  current_time.setHour(newtime.tm_hour);
  current_time.setMinute(newtime.tm_min);
  int week_day = newtime.tm_wday;
  switch (week_day) {
  case 0:
    current_day = SUNDAY;
    break;
  case 1:
    current_day = MONDAY;
    break;
  case 2:
    current_day = TUESDAY;
    break;
  case 3:
    current_day = WEDNESDAY;
    break;
  case 4:
    current_day = THURSDAY;
  case 5:
    current_day = FRIDAY;
  case 6:
    current_day = SATURDAY;
  }
}

bool CheckIn(ListCourses* &listCourses, ListPresence* &listPresence, User &student, const int &current_week) {
  if (current_week < 1 || current_week > 11)
    return false;
  bool checkAvailable = false;
  for (auto& i : listPresence->list)
    if (i.getClassName() == student.getClass())
      checkAvailable = true;
  if (!checkAvailable)
    return false;

  Time current_time;
  Week current_day;
  
  if (listCourses->list.size() == 0)
    return false;

  GetCurrentDay(current_time, current_day);
  for (auto& i : listCourses->list)
    if (i.getStartTime() < current_time && i.getEndTime() > current_time && i.getDateOfWeek() == current_day)
      for (auto& j : listPresence->list)
        if (j.getClassName() == student.getClass() && j.getCourse() == i.getCode()) {
          int getNoOfStudent = j.getNoOfStudent(student.getUsername());
          if (!j.setPresence(getNoOfStudent, true, current_week))
            return false;
          else
            return true;
        }
  return true;
}