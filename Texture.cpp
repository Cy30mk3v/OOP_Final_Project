#include "Texture.h"

Texture::Texture()
{
	m_x = m_y = m_color = NULL;
}
/*Texture::Texture(const Screen* scr)
{
	this->m_screen = scr;
}*/
Texture::~Texture()
{
	delete[]this->m_x;
	delete[]this->m_y;
	delete[]this->m_color;
	//delete[]this->m_screen;
}

bool Texture::load(string link) {
	
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
	if (i == scr->getW() - 10)
		i = 0;

	//return scr;
}
