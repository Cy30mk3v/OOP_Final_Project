#pragma once
#include "Screen.h"
#include <windows.h>

class Texture
{
private:

public:
	Texture();
	~Texture();

	void createObject(Screen* scr, int& i);
	void create(Screen& scr, int& i);
};

