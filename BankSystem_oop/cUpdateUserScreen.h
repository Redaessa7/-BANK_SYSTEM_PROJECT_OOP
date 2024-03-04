#pragma once
#include <iostream>
#include "../Librarys/cInput.h"
#include "cScreen.h"
#include "cUser.h"

class cUpdateUserScreen :protected cScreen
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

	static void _showUpdateUser()
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

		// find User
		cUser User = cUser::find(userName);
		// print User
		_printUser(User);

		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Are you sure you want to update this User"))
		{
			cout << "\n\n" + cFormat::tab(2) + "Update User Info : " << endl;
			cout << cFormat::tab(2) << "----------------------------\n";

			// read new User info
			_readUser(User);
			// save User data
			switch (User.save())
			{
			case cUser::eSvSuccessfully:
				cout << endl << cFormat::tab(4) + cFormat::color("Update Succefully\n", cFormat::txGreen);
				// print User
				_printUser(User);
				break;
			case cUser::eSvFaildEmptyObj:
				cout << endl << cFormat::tab(4) + cFormat::color("Update Faild, The User is empty\n");
				break;
			}

		}
	}
public:
	// show update User info screen
	static void showUpdateUserScreen()
	{
		system("cls");
		printHeaderOfPage("Update User Info Screen");
		_showUpdateUser();
	}
};

