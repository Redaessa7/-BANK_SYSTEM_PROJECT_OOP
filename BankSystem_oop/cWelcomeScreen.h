#pragma once
#include "cScreen.h"

class cWelcomeScreen : protected cScreen
{
private:
	static void _welcomeScreen()
	{
		system("cls");
		cFormat::cursPosition(50, 14);
		cout << "WELCOME TO MY WORLD";
		cFormat::cursPosition(43, 16);
		cout << "Press Any Key To Start Program...";
		system("pause>0");
	}
public:
	static void showWeclomeScreen()
	{
		// colors
		system("COLOR 6"); // white background, Bright black text
		cFormat::progressBar(); // We call the bar.
		_welcomeScreen();
		
		// reast color 
		cFormat::reastColor();
	}
};

