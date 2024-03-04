#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "cScreen.h"
#include "cUser.h"
class cListOfRegisterLoginScreen : protected cScreen
{
private:
	static void _printRegisterLogins(vector<cUser::stUserLog>& UsersList)
	{
		//check if list of clients is empty
		if (UsersList.empty())
		{
			cout << "\nNo found any user to display it on screen, plz add some." << endl;
			return;
		}

		cout << "\n\n" << cFormat::tab(3) << cFormat::color("-----------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		cout << cFormat::tab(3) << "\t\t\t Number Of Users (" << cFormat::colorbg(to_string(UsersList.size()), cFormat::txBlack, cFormat::bgYellow) << ") User(s)\t\t\t" << endl;
		cout << cFormat::tab(3) << cFormat::color("-----------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		cout << cFormat::tab(3) << cFormat::color("|Date                     |UserName         |Password       |Permissions    |") << endl;
		cout << cFormat::tab(3) << cFormat::color("-----------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;

		for (cUser::stUserLog& user : UsersList)
		{
			cout << cFormat::tab(3) << cFormat::color("|") << left << setw(25) << user.dateTime << cFormat::color("|") << left << setw(16) << user.userName;
			cout << cFormat::color("|") << left << setw(16) << user.password << cFormat::color("|") << left << setw(15) << user.permission << cFormat::color("|\n");
			cout << cFormat::tab(3) << cFormat::color("-----------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		}
		cout << endl;
	}
public:

	// show list of clients screen
	static void showListOfRegisterLoginScreen()
	{
		system("cls");
		vector<cUser::stUserLog> usersList = cUser::getUserLogs();
		string title = "List OF Register Login Screen", subTitle = "Number Of Users (" + to_string(usersList.size()) + ") User(s).";
		printHeaderOfPage(title, subTitle);
		_printRegisterLogins(usersList);
	}
};

