#pragma once
#include <iostream>
using namespace std;

class cPerson
{
private:
	string _firstName;
	string _lastName;
	string _email;
	string _phone;

public:
	// parameterized constructor
	cPerson(string firstName, string lastName, string email, string phone):_firstName(firstName), _lastName(lastName), _email(email), _phone(phone)
	{}

	// properties setters
	void setFirstName(string firstName)
	{
		_firstName = firstName;
	}
	void setLastName(string lastName)
	{
		_lastName = lastName;
	}
	void setEmail(string email)
	{
		_email = email;
	}
	void setPhone(string phone)
	{
		_phone = phone;
	}
	
	// properties getters
	string getFirstName()
	{
		return _firstName;
	}
	string getLastName()
	{
		return _lastName;
	}
	string getEmail()
	{
		return _email;
	}
	string getPhone()
	{
		return _phone;
	}

	__declspec(property(get = getFirstName, put = setFirstName)) string firstName;
	__declspec(property(get = getLastName, put = setLastName)) string lastName;
	__declspec(property(get = getEmail, put = setEmail)) string email;
	__declspec(property(get = getPhone, put = setPhone)) string phone;

	// methods
	string fullName()
	{
		return _firstName + " " + _lastName;
	}
};

