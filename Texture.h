#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include "Screen.h"

using namespace std;

class Texture
{
private:
	Screen* m_screen;
	vector<Point> m_point;
	uint8** m_color;
	int m_countPoint, m_countColsColor, m_countRowsColor;
public:
	Texture::Texture();
	Texture(Screen* scr);
	~Texture();

	// so luong Point, cac Point roi toi matrix color
	bool load(string a);
	void createObject(Screen* scr, int& i);
};

