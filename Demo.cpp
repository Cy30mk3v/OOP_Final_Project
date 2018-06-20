#include "Demo.h"



Demo::Demo()
{
	_mainScr = new Screen(0, 0, 80, 24);
	_subScr = new Screen(81, 0, 30, 24);
	_texture = new Texture(_mainScr, "wtf.txt");

	_mainScr->showBorder();
	_subScr->showBorder();

}


Demo::~Demo()
{
	delete _mainScr;
	delete _subScr;
	delete _texture;
}

void Demo::run() {
	int choice = DrawMenu();

	Point test(0, 5);
	int x = 1;

	DWORD startTick = 0;
	DWORD ticks = 0;

	while (1) {
		_mainScr->clear();
		_subScr->clear();

		for (int i = 0; i < 5; ++i)
			_texture->draw((i * 8) + x, 5);

		++x;

		if (x > 100)
			x = 0;

		_subScr->write(15, 3, "ROAD CROSSING GAME", true);
		_subScr->write(1, 6, "- Thai Chi Cuong", false);
		_subScr->write(1, 7, "- Dinh Le Trieu Duong", false);
		_subScr->write(1, 8, "- Phan Viet Duc", false);
		_subScr->write(1, 9, "- Vo Tran Chi Hung", false);

		_mainScr->present();
		_subScr->present();

		ticks = GetTickCount() - startTick;
		if (ticks >= 50)
			continue;
		Sleep(50 - ticks);
	}
}