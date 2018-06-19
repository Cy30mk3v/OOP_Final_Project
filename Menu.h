#pragma once
#define _CRT_SECURE_NO_WARNINGS 0
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>
#include "Misc.h"

using namespace std;


void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

/*void setBgColor(WORD color)
{
	// lấy vị trí hiện tại của dấu nháy
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen_buffer_info);
	COORD currentPos = { screen_buffer_info.dwCursorPosition.X,screen_buffer_info.dwCursorPosition.Y };

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 80; j++)
			cout << " ";
	// thiết lập lại vị trí của dấu nháy
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), currentPos);
}*/

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void DrawBolder()
{
	resizeConsole(755, 425);
	setBgColor(BACKGROUND_BLUE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	for (int i = 0; i < 120; ++i)
		printf("%c", 270);

	cout << endl;


	for (int i = 0; i < 28; ++i)
	{
		for (int j = 0; j < 120; ++j)
		{
			if (j == 0 || j == 119)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
				printf("%c", 177);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
				cout << " ";
			}
		}
		cout << endl;

	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	for (int i = 0; i < 120; ++i)
		printf("%c", 270);
}

void WriteMenu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	// Draw small box
	gotoxy(44, 1);
	printf("%c", 270);
	gotoxy(74, 1);
	printf("%c", 270);
	gotoxy(44, 2);
	printf("%c", 270);
	gotoxy(74, 2);
	printf("%c", 270);
	gotoxy(44, 3);
	printf("%c", 270);
	gotoxy(74, 3);
	printf("%c", 270);
	gotoxy(44, 4);
	printf("%c", 270);
	gotoxy(74, 4);
	printf("%c", 270);
	gotoxy(44, 5);
	for (int i = 0; i <= 30; ++i)
	{
		printf("%c", 126);
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(57, 3);
	cout << "$ $ $";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);

	gotoxy(53, 2);
	cout << "**** MENU ****";

	gotoxy(47, 9);
	cout << "~~~ 1. N E W  G A M E ~~~ ";

	gotoxy(47, 12);
	cout << "~~~ 2. L O A D  G A M E ~~~";

	gotoxy(47, 15);
	cout << "~~~ 3. S E T T I N G S ~~~";

	gotoxy(51, 18);
	cout << "~~~ 4. Q U I T ~~~";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(15, 23);
	cout << "~~~ C H O I C E : ";

}

int ReadMenu()
{
	int re;
	do
	{
		gotoxy(34, 23);
		cout << "            ";
		gotoxy(34, 23);
		cin >> re;
	} while (re > 4 || re < 1);

	return re;
}

void Stary1()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	for (int i = 0; i < 110; ++i)
	{
		int x, y;
		x = rand() % 118 + 1;
		y = rand() % 28 + 1;
		gotoxy(x, y);
		cout << "*";
	}
}

void Stary2()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | BACKGROUND_BLUE);
	for (int i = 0; i < 100; ++i)
	{
		int x, y;
		x = rand() % 118 + 1;
		y = rand() % 28 + 1;
		gotoxy(x, y);
		cout << "*";
	}
}

void Stary3()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | BACKGROUND_BLUE);
	for (int i = 0; i < 50; ++i)
	{
		int x, y;
		x = rand() % 118 + 1;
		y = rand() % 28 + 1;
		gotoxy(x, y);
		cout << "*";
	}
}


int DrawMenu()
{
	int re = 1;
	DrawBolder();
	Stary1();
	Stary2();
	Stary3();
	WriteMenu();

	re = ReadMenu();
	gotoxy(35, 23);

	return re;
}
