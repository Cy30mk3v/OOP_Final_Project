#pragma once
#include <iostream>
#include <string>
#include "Screen.h"

using namespace std;

class Texture
{
private:
	Screen* m_screen;
	vector<Point> m_point;
	/*uint8** m_color;
	int m_countPoint, m_countColsColor, m_countRowsColor;*/
public:
	Texture(Screen* scr, string fileName);
	~Texture();

	// @TODO: mài phải làm việc chung với thăng Hưng :))
	bool load(string a);
	void makeObjectRunForeverUntilPlayerLoseOrWin(Screen* scr, int& i);
	
	void draw();
	void draw(int x, int y);
	void draw(Point p);
	
	Point getPointAtIndex(int pos) {
		return this->m_point[pos];
	}
	void setPointAtIndex(int pos, Point p) {
		this->m_point[pos] = p;
	}
};

