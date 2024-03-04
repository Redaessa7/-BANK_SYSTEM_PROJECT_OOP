#pragma once
#include "../Librarys/cInput.h"
#include "cScreen.h"
#include "cUser.h"
class cFindUserScreen : protected cScreen
{
private:
	// print user info
	static void _printUser(cUser& user)
	{

		// empty User
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
	static void _showFindUser()
	{
		string userName = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Plz enter UserName");

		while (userName.size() < 3 || !cUser::isExist(userName))
		{
			if (userName.size() < 3)
			{
				userName = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " UserName is invalid, Plz enter another one");
				continue;
			}
			userName = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " UserName is not exist, Plz enter another one");
		}

		// find User
		cUser User = cUser::find(userName);
		if (!User.isEmpty())
		{
			// print User
			cout << endl << cFormat::tab(2) << cFormat::color("Found User (^_^)", cFormat::txGreen) << endl;
			_printUser(User);
		}
		else
		{
			cout << endl << cFormat::tab(2) << cFormat::color("Not Find User (X_X)") << endl;
		}

	}

public:
	// show find user screen
	static void showFindUserScreen()
	{
		system("cls");
		printHeaderOfPage("Find User Screen");
		_showFindUser();
	}
};

