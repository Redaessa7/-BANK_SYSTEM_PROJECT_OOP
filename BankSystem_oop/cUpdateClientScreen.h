#pragma once
#include <iostream>
#include "cScreen.h"
#include "cClient.h"
#include "../Librarys/cInput.h"

class cUpdateClientScreen :protected cScreen
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
	//read new data of client
	static void _readClient(cClient& client)
	{
		client.firstName = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter FristName");
		client.lastName = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter LastName");
		client.email = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter Email");
		client.phone = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter Phone");
		client.pinCode = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter Password");
		client.balance = cInput::readDlNumber(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter Account Balance");
	}
	
	static void _showUpdateClient()
	{
		string accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Plz enter account number");

		while (accountNum.size() < 3 || !cClient::isClientExist(accountNum))
		{
			if (accountNum.size() < 3)
			{
				accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Account number is invalid, Plz enter another one");
				continue;
			}
			accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Account number is allredy exist, Plz enter another one");
		}

		// find client
		cClient client = cClient::find(accountNum);
		// print client
		_printClient(client);

		if (cInput::askUser("\n" + cFormat::tab(2) + cFormat::color(("(*)")) + " Are you sure you want to update this client"))
		{
			cout << "\n\n"+ cFormat::tab(2) + "Update Client Info : " << endl;
			cout << cFormat::tab(2) << "----------------------------\n";

			// read new client info
			_readClient(client);
			// save client data
			switch (client.save())
			{
			case cClient::svSuccefully:
				cout << endl <<cFormat::tab(4) + cFormat::color("Update Succefully\n",cFormat::txGreen);
				// print client
				_printClient(client);
				break;
			case cClient::svFaildEmptyObject:
				cout << endl << cFormat::tab(4) + cFormat::color("Update Faild, The client is empty\n");
				break;
			}

		}
	}
public:
	// show update client info screen
	static void showUpdateClientScreen()
	{
		system("cls");
		printHeaderOfPage("Update Client Info Screen");

		// check if user has access to this page or not
		if (checkUserPermission(cUser::pUpdateClient))
		{
			// user has access to this page
			_showUpdateClient();
		}
	}

};

