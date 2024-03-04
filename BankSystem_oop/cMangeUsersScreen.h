#pragma once
#include <iostream>
#include <vector>
#include "../Librarys/cInput.h"
#include "../Librarys/cUtil.h"
#include "cScreen.h"
#include "cListOfUsersScreen.h"
#include "cAddNewUserScreen.h"
#include "cDeleteUserScreen.h"
#include "cUpdateUserScreen.h"
#include "cFindUserScreen.h"
#include "cListOfRegisterLoginScreen.h"
#include "../Librarys/rMenu.h"

class cMangeUsersScreen : protected cScreen
{
private:
	enum eMangeUsersMenuChoice
	{
		eListOfUser = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5,eUserLogs = 6, eMainMenue = 7,
	};

	// screen
	static void _showListOfUsersScreen()
	{
		//system("cls");
		//cout << "\nShow List Of Users Screen will be here...";
		cListOfUsersScreen::showListOfUsersScreen();
	}
	static void _showAddNewUserScreen()
	{
		//system("cls");
		//cout << "\nShow Add New User Screen will be here...";
		cAddNewUserScreen::showAddNewClientScrren();
	}
	static void _showDeleteUserScreen()
	{
		//system("cls");
		//cout << "\nShow Delete User Screen will be here...";
		cDeleteUserScreen::showDeleteUserScreen();
	}
	static void _showUpdateUserScreen()
	{
		//system("cls");
		//cout << "\nShow Update User Screen will be here...";
		cUpdateUserScreen::showUpdateUserScreen();
	}
	static void _showFindUserScreen()
	{
		//system("cls");
		//cout << "\nShow Find Users Screen will be here...";
		cFindUserScreen::showFindUserScreen();
	}
	static void _showRegisterLonginsScreen()
	{
		cListOfRegisterLoginScreen::showListOfRegisterLoginScreen();
	}


	//static short _getUserChoice()
	//{
	//	string tabs = cFormat::tab(5);
	//	return cInput::readNumber(1, 7, tabs + "Invalid choice, Plz enter number between [1 to 7]!: ", tabs + "Choose what do you want to do? [1 to 7]?: ");
	//}
	static void _backMangeUserMenuScreen()
	{
		cout << "\n" + cFormat::tab(5) << "Prass enter key to back mange user menu screen.... ";
		system("pause>>0");
		showMangeUsersScreen();
	}
	static void _performMangeUsersChoice(eMangeUsersMenuChoice menuChoice)
	{
		switch (menuChoice)
		{
		case eMangeUsersMenuChoice::eListOfUser:
			_showListOfUsersScreen();
			_backMangeUserMenuScreen();
			break;
		case eMangeUsersMenuChoice::eAddNewUser:
			_showAddNewUserScreen();
			_backMangeUserMenuScreen();
			break;
		case eMangeUsersMenuChoice::eDeleteUser:
			_showDeleteUserScreen();
			_backMangeUserMenuScreen();
			break;
		case eMangeUsersMenuChoice::eUpdateUser:
			_showUpdateUserScreen();
			_backMangeUserMenuScreen();
			break;
		case eMangeUsersMenuChoice::eFindUser:
			_showFindUserScreen();
			_backMangeUserMenuScreen();
			break;
		case eMangeUsersMenuChoice::eUserLogs:
			_showRegisterLonginsScreen();
			_backMangeUserMenuScreen();
			break;

		default:
			break;
		}
	}

	static void _showMangeUsersMenu()
	{
		vector<string> _itemOfMenu = {
		"List Of Users", "Add New User", "Delete User", "Update User","Find User","Login Register","Main Menue"
		};

		cout << cFormat::tab(5) << "========================================" << endl;
		cout << cFormat::tab(5) << "          Mange Users Mnue Screen       " << endl;
		cout << cFormat::tab(5) << "========================================\n" << endl;

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

		_performMangeUsersChoice((eMangeUsersMenuChoice)(choice+1));
	}
public:

	// show Transaction menu screen
	static void showMangeUsersScreen()
	{
		system("cls");
		printHeaderOfPage("Mange Users Screen","",true);

		// check if user has access to this page or not
		if (checkUserPermission(cUser::pMangeUsers))
		{
			// user has access to this page
			_showMangeUsersMenu();
		}
	}

};

