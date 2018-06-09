#include "Screen.h"

int main() {
	//for example:

	Screen leftScreen(0, 0, 80, 20);
	Screen rightScreen(81, 0, 39, 20);
	Screen botScreen(0, 20, 120, 10);

	leftScreen.showBorder();
	rightScreen.showBorder();
	botScreen.showBorder();

	

	while (1) {
		leftScreen.clear();
		rightScreen.clear();
		botScreen.clear();
		rightScreen.write(20, 5, "User: Thai Chi Cuong", true);
		rightScreen.write(20, 6, "Score: 999", true);
		rightScreen.write(20, 7, "Sex: Female", true);
		botScreen.write(60, 4, "Xin chao tat ca cac ban da den voi tro choi xam nach nay", true);

		rightScreen.present();
		leftScreen.present();
		botScreen.present();
	}
	return 0;
}