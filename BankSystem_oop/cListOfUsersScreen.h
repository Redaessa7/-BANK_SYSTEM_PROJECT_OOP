#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "cScreen.h"
#include "cUser.h"
class cListOfUsersScreen : protected cScreen
{
private:
	static void _printUsersList(vector<cUser>& UsersList)
	{
		//check if list of clients is empty
		if (UsersList.empty())
		{
			cout << "\nNo found any user to display it on screen, plz add some." << endl;
			return;
		}

		cout << "\n\n" << cFormat::tab(2) << cFormat::color("---------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		cout << cFormat::tab(2) << "\t\t\t\t Number Of Users (" << cFormat::colorbg(to_string(UsersList.size()), cFormat::txBlack, cFormat::bgYellow) << ") User(s)\t\t\t\t" << endl;
		cout << cFormat::tab(2) << cFormat::color("---------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		cout << cFormat::tab(2) << cFormat::color("|UserName       |Pasword       |Permissions  |Name           |Email           |Phone        |") << endl;
		cout << cFormat::tab(2) << cFormat::color("---------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;

		for (cUser& user : UsersList)
		{
			cout << cFormat::tab(2) << cFormat::color("|") << left << setw(15) << user.userName << cFormat::color("|") << left << setw(14) << user.password;
			cout << cFormat::color("|") << left << setw(13) << user.permissions << cFormat::color("|") << left << setw(15) << user.fullName();
			cout << cFormat::color("|") << left << setw(16) << user.email << cFormat::color("|") << left << setw(13) << user.phone << cFormat::color("|\n");
			cout << cFormat::tab(2) << cFormat::color("---------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		}
		cout << endl;
	}
public:

	// show list of clients screen
	static void showListOfUsersScreen()
	{
		system("cls");
		vector<cUser> usersList = cUser::getUsers();
		string title = "List OF Users Screen", subTitle = "Number Of Users (" + to_string(usersList.size()) + ") User(s).";
		printHeaderOfPage(title, subTitle);
		_printUsersList(usersList);
	}

};

