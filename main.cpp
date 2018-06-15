#include "Screen.h"

#define DELAY 50

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
		for (int i = 1; i < 28; ++i)
			for (int j = 0; j < 120; ++j)
				mainScreen.replaceC(j, i, 219);

		mainScreen.write(60, 28, std::to_string(ticks), false);
		mainScreen.present();

		ticks = GetTickCount() - startTick;
		if (ticks >= DELAY)
			continue;
		Sleep(DELAY - ticks);
	}
	return 0;
}