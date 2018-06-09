#include "Screen.h"

Screen::Screen(int x, int y, int w, int h)
	: _rect(x, y, w, h)
	, _colors(NULL)
	, _chars(NULL)
	, _showbor(false)
	, _isFocused(true)
{
	_colors = new uint8*[_rect.h];
	_chars = new char*[_rect.h];
	for (int i = 0; i < _rect.h; ++i) {
		_colors[i] = new uint8[_rect.w];
		_chars[i] = new char[_rect.w];
		for (int j = 0; j < _rect.w; ++j) {
			_colors[i][j] = 0;
			_chars[i][j] = ' ';
		}
	}

	fixWindowConsole();
	showConsoleCursor(false);
}

Screen::Screen(Rect& rect)
	: _rect(rect) {}

Screen::~Screen() {
	for (int i = 0; i < _rect.h; ++i) {
		delete[] _colors[i];
		delete[] _chars[i];
	}
	delete[] _colors;
	delete[] _chars;
}

void Screen::focus(bool focus) {
	_isFocused = focus;
}

void Screen::showBorder(bool show) {
	_showbor = show;
	if (_showbor) {
		int tw = _rect.w - 1;
		int th = _rect.h - 1;
		_chars[0][0] = char(201);
		_chars[th][0] = char(200);
		_chars[0][tw] = char(187);
		_chars[th][tw] = char(188);

		for (int i = 1; i < tw; ++i) {
			_chars[0][i] = char(205);
			_chars[th][i] = char(205);
		}

		for (int i = 1; i < th; ++i) {
			_chars[i][0] = char(186);
			_chars[i][tw] = char(186);
		}
	}
}

void Screen::present() {
	int last = 0;

	for (int i = 0; i < _rect.h; ++i) {
		moveCursor(_rect.x, _rect.y + i);
		for (int j = 0; j < _rect.w; ++j) {
			if (_colors[i][j] != last) {
				setBgColor(_colors[i][j]);
				last = _colors[i][j];
			}
			fputc(_chars[i][j], stdout);
		}
	}
}

void Screen::clear() {
	for (int i = 0; i < _rect.h; ++i) {
		for (int j = 0; j < _rect.w; ++j) {
			_colors[i][j] = 0;
			if (_showbor && (i == 0 || j == 0 || i == (_rect.h - 1) || j == (_rect.w - 1))) 
				continue;
			_chars[i][j] = ' ';
		}
	}
}

void Screen::write(int x, int y, std::string msg, bool center) {
	x = x - (center ? msg.length() / 2 : 0);

	for (int i = 0; i < msg.length(); ++i)
		replaceC(x + i, y, msg[i]);
}

bool Screen::isLegal(int x, int y) {
	if (_isFocused == false)
		return false; 

	if (x >= _rect.w - _showbor)
		return false;

	if (y >= _rect.h - _showbor)
		return false;

	if (x < _showbor || y < _showbor)
		return false;
	
	return true;
}

void Screen::replaceC(int x, int y, char c) {
	if (isLegal(x, y) == false)
		return;

	_chars[y][x] = c;
}

void Screen::replace(int x, int y, uint8 color) {
	if (isLegal(x, y) == false)
		return;

	_colors[y][x] = color;
}