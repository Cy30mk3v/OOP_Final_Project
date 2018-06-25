#define RED false
#define GREEN true
#include "Texture.h"
#include "Screen.h"

using namespace std;
class Object
{
private:
	Texture* H;

public:
	Object();

	bool isImpact(Object &E);
	void setObject(Point E);
	void moveObject(int x, int y);
	Point valuePosition();//get
	void drawObjects(int n);
};

class Human: public Object
{
private:
	bool mState;
public:
	bool isFinish();
	bool isDead();
};


