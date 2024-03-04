#pragma once
#include <vector>
#include "../Librarys/cInput.h"
#include "../Librarys/cUtil.h"
#include "cScreen.h"
#include "cListClientsScreen.h"
#include "cAddNewClientScreen.h"
#include "cDeleteClientScreen.h"
#include "cUpdateClientScreen.h"
#include "cFindClientScreen.h"
#include "cTransactionScreen.h"
#include "cMangeUsersScreen.h"
#include "../Librarys/rMenu.h"

class cMainScreen :protected cScreen
{
private:

	enum eMainChoice
	{
		eShowClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClientInfo = 4,
		eFindClient = 5, eTransactions = 6, eManagement = 7, eLogout = 8,
	};
	
	// Screens
	static void _showClientsScreen()
	{
		//cout << "\nShow Clients Screen Be Here!" << endl;
		cListClientsScreen::showListOfClients();
	}
	
	static void _showAddNewClientScreen()
	{
		//cout << "\nShow Add New Client Screen Be Here!" << endl;
		cAddNewClientScreen::showAddNewClientScrren();
	}
	
	static void _showDeleteClientScreen()
	{
		//cout << "\nShow Delete Client Screen Be Here!" << endl;
		cDeleteClientScreen::showDeleteClientScreen();
	}
	
	static void _showUpdateClientInfoScreen()
	{
		//system("cls");
		//cout << "\nShow Update Client Info Screen Be Here!" << endl;
		cUpdateClientScreen::showUpdateClientScreen();
	}
	
	static void _showFindClientScreen()
	{
		//system("cls");
		//cout << "\nShow Find Client Screen Be Here!" << endl;
		cFindClientScreen::showFindClientScreen();
	}
	
	static void _showTransactionsScreen()
	{
		//system("cls");
		//cout << "\nShow Transactions Screen Be Here!" << endl;
		cTransactionScreen::showTransactionScreen();
	}

	static void _showManagementScreen()
	{
		//system("cls");
		//cout << "\nShow Management Screen Be Here!" << endl;
		cMangeUsersScreen::showMangeUsersScreen();
	}
	
	static void _showLogOutScreen()
	{
		//cout << "\nShow LogOut Screen Be Here!" << endl;
		currentUser = cUser::find("", "");
		
		system("cls");
		system("COLOR 6");

		cFormat::cursPosition(40, 25);
		cout << "THIS PROGRAM DEVELOPE BY (^_^): REDA ESSA";
		cFormat::cursPosition(55, 14);
		cout << "LOGOUT (X_X)";
		cFormat::cursPosition(45, 16);
		cout << "Press any key to next step.....";
		system("pause>0");
		cFormat::reastColor();
	}


	//static short _getUserChoice()
	//{
	//	string tabs = cFormat::tab(5);
	//	return cInput::readNumber(1, 8, tabs + "Invalid choice, Plz enter number between [1 to 8]!: ", tabs +"Choose what do you want to do? [1 to 8]?: ");
	//}
	static void _backMainMenuScreen()
	{
		cout << "\n" + cFormat::tab(5) << "Prass enter key to back main menu screen.... ";
		system("pause>>0");
		// retrun defualt console color
		cFormat::reastColor();
		_showMainScreen();
	}
	static void _performMainMenuChoice(eMainChoice menuChoice)
	{
		switch (menuChoice)
		{
		case cMainScreen::eShowClients:
			_showClientsScreen();
			_backMainMenuScreen();
			break;
		case cMainScreen::eAddNewClient:
			_showAddNewClientScreen();
			_backMainMenuScreen();
			break;
		case cMainScreen::eDeleteClient:
			_showDeleteClientScreen();
			_backMainMenuScreen();
			break;
		case cMainScreen::eUpdateClientInfo:
			_showUpdateClientInfoScreen();
			_backMainMenuScreen();
			break;
		case cMainScreen::eFindClient:
			_showFindClientScreen();
			_backMainMenuScreen();
			break;
		case cMainScreen::eTransactions:
			_showTransactionsScreen();
			_backMainMenuScreen();
			break;
		case cMainScreen::eManagement:
			_showManagementScreen();
			_backMainMenuScreen();
			break;
		case cMainScreen::eLogout:
			_showLogOutScreen();
			/*_backMainMenuScreen();*/
			break;
		default:
			break;
		}
	}
	static void _showMainMenu()
	{
		vector<string> _itemOfMenu = {
		"Show Clients", "Add New Client", "Delete Client", "Update Client Info", "Find Client", "Transactions" ,"Management","Logout"
		};

		cout << cFormat::tab(5) <<"========================================" << endl;
		cout << cFormat::tab(5) <<"             Main Mnue Screen           " << endl;
		cout << cFormat::tab(5) <<"========================================\n" << endl;
		//// print item of menu
		//for (short i = 0; i < _itemOfMenu.size(); i++)
		//{
		//	cout << cFormat::tab(5) << cFormat::spaces(5) << "[" << i + 1 << "]: " << _itemOfMenu[i] << endl;
		//}
		
		for (short i = 0; i < _itemOfMenu.size(); i++)
		{
			cout << cFormat::tab(5) << "==                                    ==" << endl;
		}

		cout << "\n" << cFormat::tab(5) << "========================================" << endl;
		
		// draw item menu
		rMenu mainMenu;
		mainMenu.set_xy(48, 9);
		mainMenu.color(7, 6);
		short choice = mainMenu.menu(_itemOfMenu);

		_performMainMenuChoice((eMainChoice)(choice+1));
	}

	// show main menu screen
	static void _showMainScreen()
	{
		system("cls");
		printHeaderOfPage("Main Screen","",true);
		_showMainMenu();
	}
public:
	// show main menu screen
	static void showMainScreen()
	{
		/*cLonginScreen::showLoginScreen();*/
		_showMainScreen();
	}
};

