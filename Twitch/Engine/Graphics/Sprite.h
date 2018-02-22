#ifndef TWITCH_SPRITE
#define TWITCH_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"

#include <iostream>
#include <string>
using namespace std;


class Sprite {

public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float _xpos, float _yPos);

	void Update();
	void Render();

	void speedTo(float x);
	void speedBy(float x);

	void moveTo(float x, float y);
	void moveBy(float x, float y);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void rotateTo(float x);
	void rotateBy(float x);
	
	void setScale(float x);
	void setScale(float x, float y);

private:
	Texture texture;
	float speed;
	float xPos;
	float yPos;
	float rot;
	float xScale;
	float yScale;


};



#endif
