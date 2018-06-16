#include "Screen.h"

#define DELAY 50

/*
 01
0 #
1##
2 #
*/
int main() {
	//for example:

	Screen mainScreen(0, 0, 120, 30);

	mainScreen.showBorder();
	
	DWORD startTick = 0;
	DWORD ticks = 0;
	int x = 1;
	while (1) {
		startTick = GetTickCount();
		++x;
		mainScreen.clear();
		mainScreen.replaceC(5, 5, 219);
		mainScreen.replaceC(6, 5, 219);
		mainScreen.replaceC(6, 6, 219);
		mainScreen.replaceC(6, 4, 219);

		mainScreen.write(60, 28, std::to_string(ticks), false);
		mainScreen.present();

		ticks = GetTickCount() - startTick;
		if (ticks >= DELAY)
			continue;
		Sleep(DELAY - ticks);
	}
	return 0;
}