#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include "Screen.h"

using namespace std;

class Texture
{
private:
	//Screen* m_screen;
	float *m_x, *m_y, *m_color;
	int m_countX, m_countY, m_countColor;
public:
	Texture::Texture();
	Texture(const Screen* scr);
	~Texture();

	bool load(string a);
	void createObject(Screen* scr, int& i);
};

