#pragma once
#include "Screen.h"
#include <windows.h>

class Texture
{
private:

public:
	Texture();
	~Texture();

	Screen& createObject(Screen& scr, int& i);
	void create(Screen& scr, int& i);
};

