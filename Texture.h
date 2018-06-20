#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include "Screen.h"

using namespace std;

class Texture
{
private:
	Screen* m_screen;
	vector<Point> m_point;
	uint8** m_color;
	int m_countPoint, m_countColsColor, m_countRowsColor;
public:
	//Default constructor se gay ra loi~ cho cai Screen, vi vay bat buoc phai truyen vao Screen
	//Nen default constructor la khong can thiet
	//Hoac viet default, nhung phai dua ra warning va phai co them ham` setScreen ben duoi'???
	Texture();


	Texture(Screen* scr);
	//vi du
	//Texture(Screen* scr, string fileName) :m_screen(scr) { load(fileName); }
	~Texture();

	// so luong Point, cac Point roi toi matrix color

	// @TODO: mài phải làm việc chung với thăng Hưng :))
	bool load(string a);
	void createObject(Screen* scr, int& i);
	
	/*void draw();
	void draw(int x, int y);
	void draw(Point p);*/
};

