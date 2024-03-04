#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h> // _getch : read single character without user press any key
using namespace std;

class rMenu
{
	// constants
	#define KEY_UP 72      // Up arrow character
	#define KEY_DOWN 80    // Down arrow character;
	#define KEY_ENTER '\r' // Enter key character;

private:

	short _xPos;
	short _yPos;
	short _color[2]; //[main color ,  selected color]
	bool _clsScreen;

    //================================================================

    // Curser Position : this function will let us put the text and icons where we want on console window
    void _cursPosition(int x, int y)
    {
        HANDLE console;
        COORD pos;

        pos.X = x;
        pos.Y = y;
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(console, pos);
    }
    // hideCursor
    void _hideCursor()
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(console, &info);
    }
    // showCursor
    void _showCursor()
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = TRUE;
        SetConsoleCursorInfo(console, &info);
    }
    // return console color to default color
    void _rColor()
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    // display items of menu on screen
    void _displayMenu(vector<string>& menuItem, short selected)
    {
        if (_clsScreen)
        {
            system("cls");
        }

        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        for (short i = 0; i < menuItem.size(); i++)
        {

            _cursPosition(_xPos, _yPos + i);

            if (i == selected)
            {
                SetConsoleTextAttribute(console, _color[1]);
                cout << menuItem[i] << endl;
            }
            else
            {
                SetConsoleTextAttribute(console, _color[0]);
                cout << menuItem[i] << endl;
                SetConsoleTextAttribute(console, _color[1]);
            }
        }
    }


public:
	// defualt counstractor
	rMenu()
	{
		_xPos = 30;
		_yPos = 5;
		_color[0] = 8, _color[1] = 2;
		_clsScreen = false;
	}

    // properties setters
    // set x and y position
    void set_xy(short x, short y)
    {
        _xPos = x;
        _yPos = y;
    } 
    void color(short mainColor, short selectedColor)
    {
        _color[0] = mainColor;
        _color[1] = selectedColor;
    }
    void clrScreen(bool clearScreen)
    {
        _clsScreen = clearScreen;
    }
    
    // draw items of menu and return currect user choice  
    short menu(vector<string>& menuItem)
    {
        short selected = 0;                       // keeps track of which option is selected
        short numOfChoices = menuItem.size() - 1; // The total number of choices
        bool selecting = true;                    // A boolean flag to control the selection process.
        bool update = false;                      // A boolean flag to indicate if the selected value has been updated.

        _hideCursor();
        char choice; // Store choice outside of loop for efficiency
        while (selecting)
        {
            // print menu items
            _displayMenu(menuItem, selected);

            switch ((choice = _getch()))
            {
            case KEY_UP:
                if (selected > 0)
                {
                    // Don't decrement if we are at the first option
                    --selected;
                    update = true;
                }
                break;
            case KEY_DOWN:
                if (selected < numOfChoices)
                {
                    // Don't increment if we are at the last option
                    ++selected;
                    update = true;
                }
                break;
            case KEY_ENTER:
            {
                // We are done selecting the option
                selecting = false;
                break;
            }
            default:
                break;
            }
        }

        // current selected
        _rColor();
        _showCursor();
        cout << endl;
        return selected;
    }


};

