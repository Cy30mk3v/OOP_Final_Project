#pragma once

#include "Misc.h"

class Screen {
private:
	uint8**	_colors;
	char**	_chars;
	Rect	_rect;
	bool	_showbor;
	bool	_isFocused;
public:
	Screen(Rect& rect);
	Screen(int x, int y, int w, int h);
	~Screen();

	int getX() { return _rect.x; }
	int getY() { return _rect.y; }
	int getW() { return _rect.w; }
	int getH() { return _rect.h; }

	void showBorder(bool show = true);
	void focus(bool focus = true);
	void present();
	void clear();
	void write(int x, int y, std::string msg, bool center = false);
	bool isLegal(int x, int y);
	void replaceChar(int x, int y, char c);
	void replaceChar(Point p, char c);
	void replaceBgColor(int x, int y, uint8 color);
};

