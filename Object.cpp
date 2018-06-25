#include "Object.h"
#include "Misc.h"

Object::Object()
{
	this->H1.x = 0;

}

bool Object::isImpact(Object &E)
{
	return (H1.x==E.H1.x && H1.y==E.H1.y);
}

void Object::setObject(Point E)
{
	H1.x = E.x;
	H1.y = E.y;
	return;
}


void Object::moveObject(int x, int y)
{
	Point P;
	P.x = x;
	P.y = y;
}

Point Object::valuePosition()
{
	
}

// Thời gian truyền vào được tính từ lúc bắt đầu chơi
bool statusSignal(int time)
{
	return(time < rand() % 60 + 1);
}

void Object::drawObjects(int n)
{
	Object P;
	P.H = new Texture[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			P[i].H[j].draw;
		}
	}
}


void 





