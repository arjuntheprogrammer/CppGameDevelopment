#ifndef TWITCH_SPRITE
#define TWITCH_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"

#include <iostream>
#include <string>
using namespace std;


class Sprite {

public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 _pos);
	void Update();
	void Render();

	void speedTo(float x);
	void speedBy(float x);

	void moveTo(Vector3 v);
	void moveBy(Vector3 v);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void rotateTo(float x);
	void rotateBy(float x);
	
	void setScale(float x);
	void setScale(Vector3 v);

	Vector3* getPos();
	float* getRot();
	Vector3* getScale();
	Vector3* getSize();




private:
	Texture texture;

	Vector3 pos;
	Vector3 scale;
	float speed;
	float rot;
	Vector3 size;
};



#endif
