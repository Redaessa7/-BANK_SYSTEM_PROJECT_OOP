#pragma once
#include <iostream>
#include "cScreen.h"
#include "cUser.h"
#include "../Librarys/cInput.h"
class cDeleteUserScreen : protected cScreen
{
private:
	// print user info
	static void _printUser(cUser& user)
	{

		// empty client
		if (user.isEmpty())
		{
			cout << "\n" << cFormat::tab(4) + cFormat::color("This User not have any information to print ):") << endl;
			return;
		}

		cout << "\n" << cFormat::tab(2) << "-------------------------------------------------\n";
		cout << cFormat::tab(3) << "[" + cFormat::color(user.fullName()) + "'s Info]              ";
		cout << "\n" << cFormat::tab(2) << "-------------------------------------------------\n";
		cout << "\n" << cFormat::tab(2) << "FirstName   " + cFormat::color(": ") << user.firstName;
		cout << "\n" << cFormat::tab(2) << "LastName    " + cFormat::color(": ") << user.lastName;
		cout << "\n" << cFormat::tab(2) << "FullName    " + cFormat::color(": ") << user.fullName();
		cout << "\n" << cFormat::tab(2) << "Email       " + cFormat::color(": ") << user.email;
		cout << "\n" << cFormat::tab(2) << "Phone       " + cFormat::color(": ") << user.phone;
		cout << "\n" << cFormat::tab(2) << "UserName    " + cFormat::color(": ") << user.userName;
		cout << "\n" << cFormat::tab(2) << "Password    " + cFormat::color(": ") << user.password;
		cout << "\n" << cFormat::tab(2) << "Permisions  " + cFormat::color(": ") << user.permissions << endl;
	}
	static void _showDeleteUser()
	{

		string userName = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Plz enter UserName");

		while (userName.size() < 3 || !cUser::isExist(userName))
		{
			if (userName.size() < 3)
			{
				userName = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " UserName is invalid, Plz enter another one");
				continue;
			}
			userName = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " UserName is allredy exist, Plz enter another one");
		}

		// find user
		cUser user = cUser::find(userName);
		// print user
		_printUser(user);

		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Are you sure you want to delete this user"))
		{
			// delete user
			if (user._delete())
			{
				cout << endl << cFormat::tab(2) + cFormat::color("Delete a user from database successfully\n", cFormat::txGreen);
				_printUser(user);
			}
			else
			{
				cout << cFormat::tab(2) + cFormat::color("Faild deleting user!\n");
			}
		}
	}

public:
	//show delete user screen
	static void showDeleteUserScreen()
	{
		system("cls");
		printHeaderOfPage("Delete User Screen");
		_showDeleteUser();
	}
};

