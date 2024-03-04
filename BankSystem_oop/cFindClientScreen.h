#pragma once
#include <iostream>
#include "cScreen.h"
#include "cClient.h"
#include "../Librarys/cInput.h"

class cFindClientScreen : protected cScreen
{
private:

	// print client info
	static void _printClient(cClient& client)
	{

		// empty client
		if (client.isEmpty())
		{
			cout << "\n" << cFormat::tab(4) + cFormat::color("This client not have any information to print ):") << endl;
			return;
		}

		cout << "\n" << cFormat::tab(2) << "-------------------------------------------------\n";
		cout << cFormat::tab(3) << "[" + cFormat::color(client.fullName()) + "'s Info]              ";
		cout << "\n" << cFormat::tab(2) << "-------------------------------------------------\n";
		cout << "\n" << cFormat::tab(2) << "FirstName   " + cFormat::color(": ") << client.firstName;
		cout << "\n" << cFormat::tab(2) << "LastName    " + cFormat::color(": ") << client.lastName;
		cout << "\n" << cFormat::tab(2) << "FullName    " + cFormat::color(": ") << client.fullName();
		cout << "\n" << cFormat::tab(2) << "Email       " + cFormat::color(": ") << client.email;
		cout << "\n" << cFormat::tab(2) << "Phone       " + cFormat::color(": ") << client.phone;
		cout << "\n" << cFormat::tab(2) << "Account No  " + cFormat::color(": ") << client.accountNumber;
		cout << "\n" << cFormat::tab(2) << "PinCode     " + cFormat::color(": ") << client.pinCode;
		cout << "\n" << cFormat::tab(2) << "Balance     " + cFormat::color(": ") << client.balance << endl;
	}
	
	static void _showFindClient()
	{

		string accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Plz enter account number");

		while (accountNum.size() < 3 || !cClient::isClientExist(accountNum))
		{
			if (accountNum.size() < 3)
			{
				accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Account number is invalid, Plz enter another one");
				continue;
			}
			accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Account number is not exist, Plz enter another one");
		}

		// find client
		cClient client = cClient::find(accountNum);
		if (!client.isEmpty())
		{
			// print client
			cout << endl << cFormat::tab(2) << cFormat::color("Found Client (^_^)",cFormat::txGreen) << endl;
			_printClient(client);
		}
		else
		{
			cout << endl << cFormat::tab(2) << cFormat::color("Not Find Client (X_X)") << endl;
		}
		
	}

public:
	// show find client screen
	static void showFindClientScreen()
	{
		system("cls");
		printHeaderOfPage("Find Client Screen");

		// check if user has access to this page or not
		if (checkUserPermission(cUser::pFindClient))
		{
			// user has access to this page
			_showFindClient();
		}
	}
};

