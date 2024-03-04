#include <iostream>
#include <vector>
#include <iomanip>
#include "cScreen.h"
#include "cClient.h"
#include "../Librarys/cUtil.h"

class cTotalBalancesScreen : protected cScreen
{
private:
	static void _printTotalBalancesList(vector<cClient>& clientsList)
	{
		//check if list of clients is empty
		if (clientsList.empty())
		{
			cout << "\nNo found any client to display it on screen, plz add some." << endl;
			return;
		}
		short numberOfTabs = 3, numberOfSpaces = 3;
		cout << "\n\n" << cFormat::tab(numberOfTabs) << cFormat::spaces(numberOfSpaces) << cFormat::color("--------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		cout << cFormat::tab(numberOfTabs) << cFormat::spaces(numberOfSpaces)<< "\t\t Number Of Clinets (" << cFormat::colorbg(to_string(clientsList.size()), cFormat::txBlack, cFormat::bgYellow) << ") Client(s)\t\t" << endl;
		cout << cFormat::tab(numberOfTabs) << cFormat::spaces(numberOfSpaces) << cFormat::color("--------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		cout << cFormat::tab(numberOfTabs) << cFormat::spaces(numberOfSpaces) << cFormat::color("|Account Number      |Client Name              |Account Balance    |") << endl;
		cout << cFormat::tab(numberOfTabs) << cFormat::spaces(numberOfSpaces) << cFormat::color("--------------------------------------------------------------------", cFormat::txBrightYellow) << endl;

		for (cClient& client : clientsList)
		{
			cout << cFormat::tab(numberOfTabs) << cFormat::spaces(numberOfSpaces) << cFormat::color("|") << left << setw(20) << client.accountNumber;
			cout << cFormat::color("|") << left << setw(25) << client.fullName();
			cout << cFormat::color("|") << left << setw(19) << client.balance << cFormat::color("|\n");
			cout << cFormat::tab(numberOfTabs) << cFormat::spaces(numberOfSpaces) << cFormat::color("--------------------------------------------------------------------", cFormat::txBrightYellow) << endl;
		}
		cout << endl << cFormat::tab(6) << "Total Balances: " << cFormat::colorbg(to_string(cClient::getTotalBalances()), cFormat::txBlack, cFormat::bgYellow) << endl;
		cout << cFormat::tab(4) << "(" << cFormat::color(cUtil::numbertoText(cClient::getTotalBalances()),cFormat::txBrightGreen) << ")" << endl;
		cout << endl;
	}
public:

	// show list of clients screen
	static void showTotalBalancesScreen()
	{
		system("cls");
		vector<cClient> clientsList = cClient::getClients();
		string title = "Total Balances Screen", subTitle = "Number Of Clinets (" + to_string(clientsList.size()) + ") client(s).";
		printHeaderOfPage(title, subTitle);
		_printTotalBalancesList(clientsList);
	}
};

