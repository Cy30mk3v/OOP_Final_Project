#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
}

Screen* Texture::createObject(Screen* scr, int& i) {
	scr->replaceChar(6 + i, 5, 219);
	scr->replaceChar(7 + i, 5, 219);
	scr->replaceChar(8 + i, 5, 219);
	scr->replaceChar(5 + i, 6, 219);
	scr->replaceChar(5 + i, 7, 219);
	scr->replaceChar(6 + i, 6, 219);
	scr->replaceChar(6 + i, 7, 219);
	scr->replaceChar(7 + i, 6, 219);
	scr->replaceChar(7 + i, 7, 219);
	scr->replaceChar(8 + i, 6, 219);
	scr->replaceChar(8 + i, 7, 219);
	++i;

	if (i == 110)
		i = 0;

	return scr;
}
