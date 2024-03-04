#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "cScreen.h"
#include "cClient.h"


class cListClientsScreen : protected cScreen
{
private:
	static void _printClientsList(vector<cClient> &clientsList)
	{
		//check if list of clients is empty
		if (clientsList.empty())
		{
			cout << "\nNo found any client to display it on screen, plz add some." << endl;
			return;
		}

		cout <<"\n\n" << cFormat::tab(2) << cFormat::color("---------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		cout << cFormat::tab(2) << "\t\t\t\t Number Of Clinets (" << cFormat::colorbg(to_string(clientsList.size()),cFormat::txBlack, cFormat::bgYellow) << ") Client(s)\t\t\t\t" << endl;
		cout << cFormat::tab(2) << cFormat::color("---------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		cout << cFormat::tab(2) << cFormat::color("|Account Number   |Pin Code    |Client Name            |Phone           |Account Balance    |") << endl;
		cout << cFormat::tab(2) << cFormat::color("---------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		
		for (cClient& client : clientsList)
		{
			cout << cFormat::tab(2) << cFormat::color("|") << left << setw(17) << client.accountNumber << cFormat::color("|") << left << setw(12) << client.pinCode;
			cout <<  cFormat::color("|") << left << setw(23) << client.fullName()<< cFormat::color("|") << left << setw(16) << client.phone;
			cout << cFormat::color("|") << left << setw(19) << client.balance << cFormat::color("|\n");
			cout << cFormat::tab(2) << cFormat::color("--------------------------------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		}
		cout << endl;
	}
public:

	// show list of clients screen
	static void showListOfClients()
	{
		system("cls");
		vector<cClient> clientsList = cClient::getClients();
		string title = "List OF Clients Screen", subTitle = "Number Of Clinets (" + to_string(clientsList.size()) +") client(s).";
		printHeaderOfPage(title, subTitle);

		// check if user has access to this page or not
		if (checkUserPermission(cUser::pListClinets))
		{
			// user has access to this page
			_printClientsList(clientsList);
		}
	}
};

