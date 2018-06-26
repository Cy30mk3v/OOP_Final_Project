#include "Object.h"
#include "Misc.h"

Object::Object()
{
	H1.x = 0;
	H1.y = 0;
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

	this->H1.x = x;
	this->H1.y = y;
}

Point Object::valuePosition()
{
	return H1;
}

Texture Object::getTexture()
{
	return H;
}

// Thời gian truyền vào được tính từ lúc bắt đầu chơi
// Đèn đỏ thì dòng xe dừng và ngược lại khi đèn xanh
// Dương sẽ lấy tín hiệu từ hàm này để vẽ Texture (nên để hàm này trong File Texture)
bool statusSignal(int time)
{
	if(time < rand() % 60 + 1);
	{
		return RED;
	}
	return GREEN;
}

// Từ đây, n = số lượng Object
void drawObjects(Object *E,int n)
{
	for (int i = 0; i < n; i++)
	{
		E[i].getTexture.draw(E[i].valuePosition);
	}
}

// max_y là vị trí của hàng object cao nhất +1
bool Human::isFinish(Object *E, int n, int max_y)
{
	if(this->valuePosition().y == max_y && this->isImpact(E,n)==false);
	{
		this->mState = ALIVE;
		return ALIVE;
	}
}

bool Human::isDead(Object *E, int n)
{
	if (this->isImpact(E, n))
	{
		this->mState = DEAD;
		return DEAD;
	}
	return ALIVE;
}

bool Human::isImpact(Object *E, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (E[i].valuePosition.x == this->valuePosition.x && E[i].valuePosition.y == this->valuePosition.y)
		{
			this->mState = DEAD;
			return DEAD;
		}
	}
	this->mState = ALIVE;
	return ALIVE;
}

void Human::drawHuman()
{
	this->getTexture().draw(this->valuePosition());
}




