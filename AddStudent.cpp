#include "AddStudent.h"

void drawFieldAddStudent() {
	system("cls");
	gotoXY(68, 8);
	cout << "ADD A NEW STUDENT TO CLASS";
	drawLabel(50, 18, 6, 70, "");
	gotoXY(47, 14);
	cout << "Class to add";
	gotoXY(47, 18);
	cout << "Student's ID";
	gotoXY(47, 22);
	cout << "Student's name";
	drawLabel(65, 14, 1, 45, "");
	drawLabel(65, 18, 1, 45, "");
	drawLabel(65, 22, 1, 45, "");
	drawLabel(60, 28, 1, 15, "Add..");
	drawLabel(85, 28, 1, 15, "Cancel");
}

void addStudentMenu(Faculty & faculty) {
  int resultAddStudent = -1;
  bool messageStatus = false;
  drawFieldAddStudent();
	while (true) {
    clearText(65, 14, 45);
    clearText(65, 18, 45);
    clearText(65, 22, 45);

		string classToAdd = getFileName(65, 14, 45, 57, 10, messageStatus, "Enter the name of the class you want to add student");
		string idNewStudent = getFileName(65, 18, 45, 60, 10, messageStatus, "Enter the ID of the new student you want to add");
		string nameNewStudent = getFileName(65, 22, 45, 57, 10, messageStatus, "Enter the name of the new student you want to add");
    clearText(40, 10, 100);
		int getChoose = controlAddClassMenu();
    if (getChoose == 1) {
      break;
    } else if (getChoose == 2) {
      messageStatus = false;
      continue;
    } else {
      resultAddStudent = addNewStudent(faculty, classToAdd, idNewStudent, nameNewStudent);
      gotoXY(45, 10);
      if (resultAddStudent == -1)
        cout << "                   Class " << classToAdd << " already has this student.            " << "\a";
      else if (resultAddStudent == -2)
        cout << "                          Your ID is invalid.                             " << "\a";
      else if (resultAddStudent == -3)
        cout << "              Found no class name " << classToAdd << " in your database.        " << "\a";
      else if (resultAddStudent == -4)
        cout << "                    Student's name can not be empty.                     " << "\a";
			else {
				cout << "                    Succeed to add new student.                           ";
			}
      messageStatus = true;
		}
	}
}

int addNewStudent(Faculty &faculty, const string & className, const string & ID, const string & name) {
  if (name == "")
    return -4;
  Student checkStudentData;
  if (!checkStudentData.setId(ID))
    return -2;
	for (auto i : faculty.classMember)
		if (i.name == className) {
      for (Student *j = i.student->nextStudent; j; j = j->nextStudent)
        if (j->getId() == stoi(ID) && j->getName() == name)
          return -1; // exist student
			Student *newStudent = new Student;
			newStudent->setName(name);
      newStudent->setId(ID);
			if (!i.student->nextStudent || ID <= to_string(i.student->nextStudent->getId())) {
				newStudent->setNo(1);
				newStudent->nextStudent = i.student->nextStudent;
				i.student->nextStudent = newStudent;
      } else {
        for (Student *j = i.student->nextStudent; j; j = j->nextStudent)
          if (to_string(j->getId()) <= ID)
            if (!j->nextStudent) {
              j->nextStudent = newStudent;
              newStudent->setNo(j->nextStudent->getNo() + 1);
              break;
            } else if (to_string(j->nextStudent->getId()) >= ID) {
              newStudent->nextStudent = j->nextStudent;
              j->nextStudent = newStudent;
              newStudent->setNo(j->getNo() + 1);
              break;
            }
      }
			for (Student *j = newStudent->nextStudent; j; j = j->nextStudent)
				j->setNo(j->getNo() + 1);
			return 0;
		}
  return -3; // found no class to add student
}
