#include "User.h"

User::User()
{
	this->username = this->fullName = this->email
		= this->password = this->mobilePhone = this->className
		= "";
	this->type = -1;
}

User::~User()
{
	this->username.clear();
	this->fullName.clear();
	this->email.clear();
	this->password.clear();
	this->mobilePhone.clear();
	this->className.clear();
}

string User::getUsername() { return this->username; }

void User::setUsername(const string &usernameInput)
{
	this->username = usernameInput;
}

string User::getFullname() { return this->fullName; }

void User::setFullname(const string & fullnameInput)
{
	this->fullName = fullnameInput;
}

string User::getEmail() { return this->email; }

void User::setEmail(const string & emailInput)
{
	this->email = emailInput;
}

string User::getMobilePhone() { return this->mobilePhone; }

void User::setMobilePhone(const string & mobilePhone)
{
	this->mobilePhone = mobilePhone;
}

string User::getPassword() { return this->password; }

bool User::checkInputPassword(const string & passwordInput)
{
	// check if the password is strong enough to make change
	bool hasLowCase = false;
	bool hasUpCase = false;
	bool hasNumber = false;
	bool hasSpecicalCharacter = false;

	for (auto i : passwordInput)
		if (i > 64 && i < 91 && !hasUpCase)
			hasUpCase = true;
		else if (i > 96 && i < 123 && !hasLowCase)
			hasLowCase = true;
		else if (i > 47 && i < 58 && !hasNumber)
			hasNumber = true;
		else if (((i > 32 && i < 48) || (i > 57 && i < 65) || (i > 90 && i < 97) || (i > 122 && i < 127)) && !hasSpecicalCharacter)
			hasSpecicalCharacter = true;
	if (!hasLowCase || !hasUpCase || !hasNumber || !hasSpecicalCharacter)
		return false;
	return true;
}

void User::setPassword(const string & passwordInput)
{
	this->password = passwordInput;
}

string User::getClass() { return this->className; }

void User::setClass(const string & classInput)
{
	this->className = classInput;
}

uint32_t User::getType() { return this->type; }

void User::setType(const uint32_t & typeInput)
{
	this->type = typeInput;
}
