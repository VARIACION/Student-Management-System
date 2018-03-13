#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User
{
private:
	string username, fullName, email, mobilePhone, password, className;
	uint32_t type;

public:
	User();
	~User();

	string getUsername();
	void setUsername(const string &usernameInput);
	string getFullname();
	void setFullname(const string &fullnameInput);
	string getEmail();
	void setEmail(const string &emailInput);
	string getMobilePhone();
	void setMobilePhone(const string &mobilePhone);
	string getPassword();
	bool setPassword(const string &passwordInput);
	string getClass();
	void setClass(const string &classInput);
	uint32_t getType();
	void setType(const uint32_t &typeInput);
};

#endif // !USER_H