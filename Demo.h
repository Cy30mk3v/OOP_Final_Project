#pragma once
#include "Menu.h"
#include "Screen.h"
#include "Texture.h"

class Demo {
private:
	Texture* _texture;
	Screen*	 _mainScr;
	Screen*	 _subScr;
public:
	Demo();
	~Demo();

	void run();
};

