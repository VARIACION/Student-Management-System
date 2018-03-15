#include "Student.h"

Student::Student()
{
	this->no = 0;
	this->id = 0;
	this->name = "";
	this->nextStudent = nullptr;
}


Student::~Student()
{
	this->name.clear();
}

uint32_t Student::getNo() { return this->no; }

void Student::setNo(const uint32_t &noInput) { this->no = noInput; }

void Student::setNo(const string & noInput) { this->no = stoi(noInput); }

uint32_t Student::getId() { return this->id; }

bool Student::setId(const uint32_t & idInput)
{ 
	this->id = idInput;
	return true;
}

bool Student::setId(const string & idInput) 
{
	for (auto i : idInput)
		if (i < 48 || i > 57)
			return false;
	this->id = stoi(idInput); 
	return true;
}

string Student::getName() { return this->name; }

void Student::setName(const string & nameInput) { this->name = nameInput; }
