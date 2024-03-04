#include <iostream>
#include "cWelcomeScreen.h"
#include "cLonginScreen.h"


using namespace std;

int main()
{
	cWelcomeScreen::showWeclomeScreen();

	while (true)
	{
		if (!cLonginScreen::showLoginScreen())
		{
			break;
		}
		
	}

	return 0;
}
