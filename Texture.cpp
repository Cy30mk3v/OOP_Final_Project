#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
}

void Texture::createObject(Screen* scr, int& i) {
	// Object di chuyen theo truc Ox voi delta x = 1, co the thay doi neu muon
	scr->replaceChar(5 + i, 6, 219);
	scr->replaceChar(5 + i, 7, 219);

	scr->replaceChar(6 + i, 5, 219);
	scr->replaceChar(6 + i, 6, 219);
	scr->replaceChar(6 + i, 7, 219);

	scr->replaceChar(7 + i, 5, 219);
	scr->replaceChar(7 + i, 6, 219);
	scr->replaceChar(7 + i, 7, 219);	

	scr->replaceChar(8 + i, 5, 219);
	scr->replaceChar(8 + i, 6, 219);
	scr->replaceChar(8 + i, 7, 219);

	++i;
	// Khi chay toi gan cuoi khung hinh` thi reset = 0 chay tu vi tri ban dau	
	if (i == 110)
		i = 0;

	//return scr;
}

/*bool Texture::checkAccident() {

	return 1;
}*/