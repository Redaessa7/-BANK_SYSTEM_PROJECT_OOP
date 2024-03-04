#pragma once
#include <iostream>
#include "cClient.h"
#include "../Librarys/cInput.h"
#include "cScreen.h"

using namespace std;

class cAddNewClientScreen : protected cScreen
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
		cout << "\n" << cFormat::tab(2) << "FirstName   "+ cFormat::color(": ")<< client.firstName;
		cout << "\n" << cFormat::tab(2) << "LastName    " + cFormat::color(": ") << client.lastName;
		cout << "\n" << cFormat::tab(2) << "FullName    " + cFormat::color(": ") << client.fullName();
		cout << "\n" << cFormat::tab(2) << "Email       " + cFormat::color(": ") << client.email;
		cout << "\n" << cFormat::tab(2) << "Phone       " + cFormat::color(": ") << client.phone;
		cout << "\n" << cFormat::tab(2) << "Account No  " + cFormat::color(": ") << client.accountNumber;
		cout << "\n" << cFormat::tab(2) << "PinCode     " + cFormat::color(": ") << client.pinCode;
		cout << "\n" << cFormat::tab(2) << "Balance     " + cFormat::color(": ") << client.balance << endl;
	}
	//read new data of client
	static void _readClient(cClient & client)
	{
		client.firstName = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)",cFormat::txBrightGreen) + " Plz Enter FristName");
	    client.lastName = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter LastName");
		client.email = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter Email");
		client.phone = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter Phone");
		client.pinCode = cInput::readStr(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) +  " Plz Enter Password");
		client.balance= cInput::readDlNumber(cFormat::tab(2) + cFormat::color("(*)", cFormat::txBrightGreen) + " Plz Enter Account Balance");
	}
	static void _showAddNewClient()
	{
		string accountNum = cInput::readStr(cFormat::tab(2) + cFormat::color(("(*)")) + " Plz enter account number");

		while (accountNum.size() < 3 || cClient::isClientExist(accountNum))
		{
			if (accountNum.size() < 3)
			{
				accountNum = cInput::readStr(cFormat::tab(2)+ cFormat::color(("(*)")) +" Account number is invalid, Plz enter another one");
				continue;
			}
			accountNum = cInput::readStr(cFormat::tab(2)+ cFormat::color(("(*)")) +" Account number is allredy exist, Plz enter another one");
		}

		// create new client
		cClient client = cClient::addNewClient(accountNum);
		// read client info from user
		_readClient(client);

		// save client data
		switch (client.save())
		{
		case cClient::svSuccefully:
			cout << endl << cFormat::tab(3) + "Add New Client Succefully" + cFormat::color("(^_+)", cFormat::txYellow) + "\n";
			_printClient(client);
			break;
		case cClient::svFaildClientExist:
			cout << endl <<cFormat::tab(3)+ "Add Faild! "+ cFormat::color("(~_~)", cFormat::txRed)+ ", This Client Is Existing\n";
			break;
		}
	}

public:
	
	// show add new client screen
	static void showAddNewClientScrren()
	{
		system("cls");
		printHeaderOfPage("Add New Client Screen");

		// check if user has access to this page or not
		if (checkUserPermission(cUser::pAddClient))
		{
			// user has access to this page
			_showAddNewClient();
		}
	}
};

