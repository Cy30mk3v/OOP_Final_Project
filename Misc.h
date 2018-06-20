#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>

#define COLOR_FG 7
#define COLOR_BG 0
#define KB_L 108
#define KB_LEFT 77
#define KB_RIGHT 75
#define KB_UP 72
#define KB_DOWN 80
#define KB_ESC 27

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint;
typedef unsigned long uint64;

struct Point {
	int x;
	int y;

	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}
};

struct Rect {
	int x;
	int y;
	int w;
	int h;

	Rect() : x(0), y(0), w(0), h(0) {}
	Rect(int _x, int _y, int _w, int _h)
		: x(_x)
		, y(_y)
		, w(_w)
		, h(_h) {}

	bool isImpact(Rect& rect) {
		if (rect.isInside(x, y) 
			|| rect.isInside(x + w, y + h) 
			|| rect.isInside(x + w, y) 
			|| rect.isInside(x, y + h))
			return true;

		return false;
	}

	bool isInside(int _x, int _y) {
		return _x > x 
			&& _y > y 
			&& _x < x + w 
			&& _y < y + h;
	}

	bool isInside(Point& p) {
		return isInside(p.x, p.y);
	}
};

void resizeConsole(int width, int height);

// default console size 128x32
void fixWindowConsole();

// get current console buffer size
void getConsoleBufferSize(int &w, int &h);

void showConsoleCursor(bool showFlag);

// set background color
void setBgColor(WORD color);

//set foreground color
void setFgColor(WORD color);

// origin(0, 0)
void moveCursor(int x, int y);
