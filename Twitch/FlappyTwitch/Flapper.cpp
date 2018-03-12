#include "Flapper.h"
#include "../Engine/Engine.h"
#include "../Engine/Math/Rect.h"
#include "../Engine/IO/Keyboard.h"
#include "../Engine/IO/Mouse.h"


Flapper::Flapper() {
	flapForce = 750;
	maxRot = 30;
	minRot = -maxRot;

}

Flapper::Flapper(Sprite _sprite):Flapper() {
	sprite = _sprite;
	Rect boundingRect = Rect();
	Vector3 sizeOffset(0.8, 0.3, 1);
	boundingRect.SetSize(*sprite.getSize() * *sprite.getScale() * sizeOffset);
	rb.initialize(0.8f, -10, sprite.getPos(), sprite.getRot(), sprite.getScale(), sprite.getSize(), boundingRect);

}


void Flapper::update() {
	handleInput();
	sprite.Update();
	rb.update();

	float yVel = rb.getVel().y;
	if (flapForce == 0) {
		cout << " Error! Flapping will do no good! Setting to 750" << endl;
		flapForce = 750;
	}
	float newRot = yVel* (maxRot/ flapForce) ;
	sprite.rotateTo(newRot);
}
void Flapper::render() {
	sprite.Render();
	rb.render(Vector3(255, 0, 0));
}

void Flapper::flap() {

	rb.setVel(Vector3(0, flapForce, 0));
	sprite.rotateTo(maxRot);
	//sprite.rotateBy(10);
	
}


Sprite& Flapper::getSprite() {
	return sprite;
}

Rigidbody& Flapper::getRB() {
	return rb;
}

void Flapper::reset() {
	sprite.moveTo(Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	sprite.rotateTo(0);
	rb.setVel(Vector3(0, 0, 0));


}

void Flapper::handleInput() {
	if (Keyboard::key(GLFW_KEY_SPACE) || Mouse::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
		flap();
	}
}