#pragma once
#include <iostream>
#include "../Librarys/cInput.h"
#include "cScreen.h"
#include "cUser.h"

class cAddNewUserScreen : protected cScreen
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
	//read new data of user
	static void _readUser(cUser& user)
	{
		user.firstName = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter FristName");
		user.lastName = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter LastName");
		user.email = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter Email");
		user.phone = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter Phone");
		user.password = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter Password");
		user.permissions = _readPermissions();
	}
	// read permissions
	static int _readPermissions()
	{
		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " do you want to give this user all permissions"))
		{
			return cUser::ePermissions::eAll;
		}
		int permissions = 0;
		cout << endl << cFormat::tab(2) + cFormat::color(("(*)")) + "Do you want to give access to: " << endl;
		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Show Clients List Screen"))
		{
			permissions += cUser::ePermissions::pListClinets;
		}
		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Add New Client Screen"))
		{
			permissions += cUser::ePermissions::pAddClient;
		}
		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Delete Client Screen"))
		{
			permissions += cUser::ePermissions::pDeleteClient;
		}
		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Update Client Screen"))
		{
			permissions += cUser::ePermissions::pUpdateClient;
		}
		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Find Client Screen"))
		{
			permissions += cUser::ePermissions::pFindClient;
		}
		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Transaction Screen"))
		{
			permissions += cUser::ePermissions::pTrnasaction;
		}
		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Mange Users Screen"))
		{
			permissions += cUser::ePermissions::pMangeUsers;
		}
		return permissions;

	}
	static void _showAddNewUser()
	{
		string userName = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Plz enter userName");

		while (userName.size() < 3 || cUser::isExist(userName))
		{
			if (userName.size() < 3)
			{
				userName = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " UserName is invalid, Plz enter another one");
				continue;
			}
			userName = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " UserName is allredy exist, Plz enter another one");
		}

		// create new user
		cUser user = cUser::addNewUser(userName);
		// read client info from user
		_readUser(user);

		// save user data
		switch (user.save())
		{
		case cUser::eSvSuccessfully:
			cout << endl << cFormat::tab(3) + "Add New User Succefully" + cFormat::color("(^_+)", cFormat::txYellow) + "\n";
			_printUser(user);
			break;
		case cUser::eSvUserExist:
			cout << endl << cFormat::tab(3) + "Add Faild! " + cFormat::color("(~_~)", cFormat::txRed) + ", This User Is Existing\n";
			break;
		}
	}

public:

	// show add new user screen
	static void showAddNewClientScrren()
	{
		system("cls");
		printHeaderOfPage("Add New User Screen");
		_showAddNewUser();
	}
};

