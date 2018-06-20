#include "Texture.h"

Texture::Texture(Screen* scr, string fileName) :m_screen(scr) {
	load(fileName); 
}
Texture::~Texture() {
	this->m_point.clear();
	for (int i = 0; i < m_countRowsColor; ++i)
		delete[] this->m_color[i];
	delete[] this->m_color;

	delete[]this->m_screen;
}

bool Texture::load(string link) {
	ifstream f;
	f.open(link, ios::in);
	if (f.fail())
		return false;
	int number;
	Point x;
	
	while (!f.eof())
	{
		f >> this->m_countPoint;
		f >> x.x;
		f >> x.y;
		this->m_point.push_back(x);
	}
	return true;
}

// @TODO: fix lai cai nay ho t cai
void Texture::makeObjectRunForeverUntilPlayerLoseOrWin(Screen* scr, int& i) {
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


void Texture::draw(int x, int y) {
	for (int i = 0; i < m_point.size(); ++i)
		m_screen->replaceChar(m_point[i].x + x, m_point[i].y + y, 219);
}

void Texture::draw(Point p) {
	draw(p.x, p.y);
}

void Texture::draw() {
	draw(0, 0);
}