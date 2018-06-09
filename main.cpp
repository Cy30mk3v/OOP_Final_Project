#include "Screen.h"

#define DELAY 50

int main() {
	//for example:

	Screen leftScreen(0, 0, 40, 20);
	Screen rightScreen(41, 0, 40, 20);
	Screen bottomScreen(0, 21, 80, 10);

	leftScreen.showBorder();
	rightScreen.showBorder();
	bottomScreen.showBorder();
	int x = 5;
	int k = 0;
	DWORD startTick = 0;
	DWORD ticks = 0;

	while (1) {
		startTick = GetTickCount();

		leftScreen.clear();
		rightScreen.clear();
		bottomScreen.clear();

		x++;

		for (int i = 0; i < leftScreen.getW(); ++i) {
			k = i + x;
			leftScreen.replace(i, 1, k % 16);
			leftScreen.replace(i, 3, k % 16);
			leftScreen.replace(i, 5, k % 16);
			leftScreen.replace(i, 7, k % 16);
			rightScreen.replace(i, 1, k % 16);
			rightScreen.replace(i, 3, k % 16);
			rightScreen.replace(i, 5, k % 16);
			rightScreen.replace(i, 7, k % 16);
			k = x - i;
			leftScreen.replace(i, 2, k % 16);
			leftScreen.replace(i, 4, k % 16);
			leftScreen.replace(i, 6, k % 16);
			leftScreen.replace(i, 8, k % 16);
			rightScreen.replace(i, 2, k % 16);
			rightScreen.replace(i, 4, k % 16);
			rightScreen.replace(i, 6, k % 16);
			rightScreen.replace(i, 8, k % 16);
		}

		for (int i = 0; i < bottomScreen.getW(); ++i) {
			k = i + x;
			bottomScreen.replace(i, 1, k % 16);
			bottomScreen.replace(i, 5, k % 16);
			bottomScreen.replace(i, 3, k % 16);
			bottomScreen.replace(i, 7, k % 16);
			bottomScreen.replace(i, 9, k % 16);
			k = x - i;
			bottomScreen.replace(i, 2, k % 16);
			bottomScreen.replace(i, 4, k % 16);
			bottomScreen.replace(i, 6, k % 16);
			bottomScreen.replace(i, 8, k % 16);
		}

		leftScreen.write(1, 12, std::to_string(ticks));
		rightScreen.write(1, 12, "Test Performance");

		rightScreen.present();
		leftScreen.present();
		bottomScreen.present();

		ticks = GetTickCount() - startTick;
		if (ticks >= DELAY)
			continue;
		Sleep(DELAY - ticks);
	}
	return 0;
}