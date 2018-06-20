#include "Screen.h"
#include "Texture.h"
#include "Menu.h"

#define DELAY 50

//roi ok mai se viet cai menu trong project nay
//may cai nay la example nen mai comment no lai het roi viet cung duoc
//nhung ma may' cai' ham` mai viet' nho' comment cach' dung` de t con biet
//viet xong thi 
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

	// Texture 
	Texture t(&mainScreen, "test.txt");
	int i = 0, j = i + 15, k = j + 15, m = k + 15;
	//

	while (1) {
		startTick = GetTickCount();
		++x;
		mainScreen.clear();

		// Texture
		/*t.makeObjectRunForeverUntilPlayerLoseOrWin(&mainScreen, m);
		t.makeObjectRunForeverUntilPlayerLoseOrWin(&mainScreen, k);
		t.makeObjectRunForeverUntilPlayerLoseOrWin(&mainScreen, j);
		t.makeObjectRunForeverUntilPlayerLoseOrWin(&mainScreen, i);*/

		/*t.draw();
		t.draw(5, 5);*/
			
		//  

		//vẽ ra trên màn hình
		mainScreen.write(60, 28, std::to_string(ticks), false);
		//vẽ ra màn hình hiện tại
		mainScreen.present();

		ticks = GetTickCount() - startTick;
		if (ticks >= DELAY)
			continue;
		Sleep(DELAY - ticks);
	}
	return 0;
}

//void main()
//{
//	int a = DrawMenu();
//
//	cout << a << endl;
//
//	_getch();
//}