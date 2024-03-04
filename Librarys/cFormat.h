#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "stringo.h"
//#include <Windows.h>
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")


using namespace std;

class cFormat
{
private:
	// draw frame, note :_x and _y are position of curser
	static void genframe(short _x, short _y, short hLen, short vLen, bool defaultShape = true, char hShape = 205, char vShape = 186)
	{
		short horizontalEndFrame = hLen;
		short verticalEndFrame = vLen;
		// draw frame of progress bar
		// horizontal
		for (short x = _x; x < horizontalEndFrame; x++)
		{
			// 2 horizontal lines
			cursPosition(x, _y);
			printf("%c", hShape);

			cursPosition(x, verticalEndFrame);
			printf("%c", hShape);
			
		}
		// vertical
		for (short y = _y + 1; y < verticalEndFrame; y++)
		{
			// 2 vertical lines
			cursPosition(_x, y);
			printf("%c", vShape);

			cursPosition(horizontalEndFrame, y);
			printf("%c", vShape);
		}

		if (defaultShape)
		{
			// Corners of the frame
			// top left
			cursPosition(_x, _y);
			printf("%c", 201);
			// top right
			cursPosition(horizontalEndFrame, _y);
			printf("%c", 187);
			// bottom left
			cursPosition(_x, verticalEndFrame);
			printf("%c", 200);
			// bottom right
			cursPosition(horizontalEndFrame, verticalEndFrame);
			printf("%c", 188);
		}
		else
		{
			// Corners of the frame
			// top left
			cursPosition(_x, _y);
			printf("%c", hShape);
			// top right
			cursPosition(horizontalEndFrame, _y);
			printf("%c", hShape);
			// bottom left
			cursPosition(_x, verticalEndFrame);
			printf("%c", hShape);
			// bottom right
			cursPosition(horizontalEndFrame, verticalEndFrame);
			printf("%c", hShape);
		}
	}

public:
	//--------------------[Static Methods]--------------------------//

	enum enColor {
		txBlack = 30, bgBlack = 40,
		txRed = 31, bgRed = 41,
		txGreen = 32, bgGreen = 42,
		txYellow = 33, bgYellow = 43,
		txBlue = 34, bgBlue = 44,
		txMagenta = 35, bgMagenta = 45,
		txCyan = 36, bgCyan = 46,
		txWhite = 37, bgWhite = 47,
		txNoColor = 0,

		txBrightBlack = 90, bgBrightBlack = 100,
		txBrightRed = 91, bgBrightRed = 101,
		txBrightGreen = 92, bgBrightGreen = 102,
		txBrightYellow = 93, bgBrightYellow = 103,
		txBrightBlue = 94, bgBrightBlue = 104,
		txBrightMagenta = 95, bgBrightMagenta = 105,
		txBrightCyan = 96, bgBrightCyan = 106,
		txBrightWhite = 97, bgBrightWhite = 107,
	};

	// text color in termnal
	static string color(string str, enColor txtColor = enColor::txBrightRed)
	{
		// "\x1B[31mTexting\033[0m"
		// "\033[3;42;30mTexting\033[0m"

		return ("\x1B[" + to_string(txtColor) + "m" + str + "\033[0m");
	}
	// text color with background in termnal
	static string colorbg(string str, enColor txtColor, enColor bgColor = enColor::bgWhite)
	{
		// "\x1B[31mTexting\033[0m"
		// "\033[3;42;30mTexting\033[0m"

		return ("\033[3;" + to_string(bgColor) + ";" + to_string(txtColor) + "m" + str + "\033[0m");
	}
	// reast console color
	static void reastColor()
	{
		//// Reset the console colors to their defaults
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	/*==========================================================
		testeing: printPalestineFlag , playsound
	*/
	// print palestine flag
	static void printPalestineFlag(short flagLen = 24, short flagWidth = 48,string shape ="#")
	{
		string flag = "";
		// to increse i and decrese g by 2
		flagLen *= 2;

		int g = (flagLen/2);
		int w = 0;

		// create flag
		for (short i = 1; i <= flagLen; i+=2)
		{	// part one
			if (i <= (flagLen/2))
			{
				for (short j = 0; j < i; j++)
				{
					flag += color(shape);
					w = j;
				}

				if ( i <= (flagLen/3))
				{
					for (short k = w; k < flagWidth - 2; k++)
					{
						flag += color(shape, txGreen);
					}
				}
				else
				{
					for (short k = w; k < flagWidth - 2; k++)
					{
						flag += color(shape, txWhite);
					}
				}

				flag += "\n";
				w = 0;
			}
			// part two
			else
			{
				w = g;
				for (short j = g; j > 1; j--)
				{
					flag += color(shape);
				}

				if (g > (flagLen / 3))
				{
					for (short k = w; k < flagWidth; k++)
					{
						flag += color(shape, txWhite);
					}
				}
				else
				{
					for (short k = w; k < flagWidth; k++)
					{
						flag += color(shape, txBrightBlack);
					}
				}

				flag += "\n";
				g-=2;
			}
		}
		
		// print flag
		cout << flag << endl;
		cout << stringo::center("FREE PALESTINE", flagWidth) << endl;
		
	}
	// play sound must be file .mav
	static void playsound(string dpath = "../data/videoplayback.wav")
	{
		//cout << "\nPlaying music" << endl;
		//PlaySoundA(dpath.c_str(), NULL, SND_FILENAME | SND_SYNC);
		//cout << "\nEnd" << endl;
	}

	// hideCursor
	static void rhideCursor()
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(console, &info);
	}
	// showCursor
	static void rshowCursor()
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = TRUE;
		SetConsoleCursorInfo(console, &info);
	}
	//*============================================================

	// return tabs
	static string tab(short numOfTabs)
	{
		string tabs("");
		for (short i = 0; i < numOfTabs; i++)
		{
			tabs += "\t";
		}
		return tabs;
	}
	// return spaces
	static string spaces(short numOfSpaces)
	{
		string spaces("");
		for (short i = 0; i < numOfSpaces; i++)
		{
			spaces += " ";
		}
		return spaces;
	}
	
	// Curser Position : this function will let us put the text and icons where we want on console window
	static void cursPosition(short x, short y)
	{
		HANDLE console;
		COORD pos;

		pos.X = x;
		pos.Y = y;
		console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(console, pos);
	}
	
	// create frame
	static void frame(short xPos, short yPos, short hLen, short vLen, bool defaultShape = true, char hShape = 205, char vShape = 186)
	{
		short widthFrame = xPos + hLen;
		short lenFrame = yPos + vLen;
		// draw frame
		genframe(xPos, yPos+1, widthFrame, lenFrame,defaultShape,hShape,vShape);

		//Take the cursor out of the frame
		cursPosition(widthFrame+1, lenFrame);
		cout << endl << endl;

	}
	// create frame
	static void frame(string title, short xPos, short yPos, short hLen, short vLen)
	{
		short widthFrame = xPos + hLen;
		short lenFrame = yPos + vLen;
		// The frame width must be greater than the title length
		if (widthFrame < title.length())
		{
			widthFrame += (title.length() - widthFrame);
		}
		// draw frame
		genframe(xPos, yPos+1, widthFrame, lenFrame);

		short half = ((widthFrame - title.length()) - xPos) / 2;
		// print title inside frame
		cursPosition((xPos+(half)+1), yPos + 2);
		cout << title;
		
		//Take the cursor out of the frame
		cursPosition(widthFrame+1, lenFrame);
		cout << endl << endl;

	}
	// create input faild
	static string inField(string lebal, short xPos, short yPos, short hLen = 40, short vLen = 2)
	{
		short widthFrame = xPos + hLen;
		short lenFrame = yPos + vLen;

		cursPosition(xPos, yPos -1);
		cout << lebal;

		// draw frame
		genframe(xPos,yPos,widthFrame, lenFrame);

		string input;
		cursPosition(xPos + 2, yPos + 1);
		cin >> input;
		
		//Take the cursor out of the frame
		cursPosition(widthFrame + 1, lenFrame);
		cout << endl << endl;

		return input;

	}
	// progress bar
	static void progressBar()
	{
		rhideCursor();
		SetConsoleCP(437);
		SetConsoleOutputCP(437);

		system("cls");
		// add some text
		cursPosition(44, 13);
		cout << "LOADING....";

		cursPosition(90, 26);
		cout << "Develope ^_^ By: Reda Essa";

		// set level
		int level = 13; // it go until %100;

		// draw frame of progress bar
		// horizontal
		for (int x = 44; x < 74; x++)
		{
			// 2 horizontal lines
			cursPosition(x, 14);
			printf("%c", 205);

			cursPosition(x, 16);
			printf("%c", 205);
		}
		// vertical
		for (int y = 15; y < 16; y++)
		{
			// 2 vertical lines
			cursPosition(44, y);
			printf("%c", 186);

			cursPosition(74, y);
			printf("%c", 186);
		}

		// Corners of the frame
		// top left
		cursPosition(44, 14);
		printf("%c", 201);
		// top right
		cursPosition(74, 14);
		printf("%c", 187);
		// bottom left
		cursPosition(44, 16);
		printf("%c", 200);
		// bottom right
		cursPosition(74, 16);
		printf("%c", 188);

		// progress bar internal content
		for (int load = 45; load <= 73; load++)
		{
			cursPosition(load, 15);
			printf("%c", 219); // 178 ASCII code, it is a square
			Sleep(100);        // we pause the action in every cycle, so it gives an effect of a running bar.

			// number with the loaded level
			level += 3; // we had 13 at the beginning and it adds +3 every cycle
			cursPosition(58, 17);
			cout << level << "%"; // this shows the number until 100% loaded...
		}
		rshowCursor();
	}
};








// Color
/*
Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107

========================================
(*)craete text color without background:

color = 31 => "\x1B[31mTexting\033[0m"
+++++++++++++++++++++++++++++++++++++++++

(*)craete text color and background:

color = 30, background  = 42, color degree = 3,

"\033[3;42;30mTexting\033[0m"

================================================
		========== Some Colors ===========

		// text color without background
		str = "\x1B[31mTexting\033[0m"; // red
		str = "\x1B[32mTexting\033[0m"; // green
		str = "\x1B[33mTexting\033[0m"; // gold
		str = "\x1B[34mTexting\033[0m"; // blue
		str = "\x1B[35mTexting\033[0m"; // Magenta

		// text color and background			fc    ,   bc
		str = "\033[3;42;30mTexting\033[0m"; // black ,  green
		str = "\033[3;43;30mTexting\033[0m"; // black ,  gold
		str = "\033[3;44;30mTexting\033[0m"; // black ,  blue
		str = "\033[3;104;30mTexting\033[0m";// black ,  Bright Blue
		str = "\033[3;100;30mTexting\033[0m";// black ,  Bright Black
		str = "\033[3;47;35mTexting\033[0m"; // Magenta, White


*/

