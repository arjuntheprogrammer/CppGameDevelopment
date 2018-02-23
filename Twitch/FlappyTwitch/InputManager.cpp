#include "InputManager.h"

InputManager::InputManager(Flapper* _flapper) {
	flapper = _flapper;
}

void InputManager::update() {
	/*
	
	if (Mouse::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
		flapper->getSprite().rotateBy(100);
	}
	if (Mouse::buttonUp(GLFW_MOUSE_BUTTON_RIGHT)) {
		flapper->getSprite().rotateBy(-100);
	}
	if (Mouse::button(GLFWr_MOUSE_BUTTON_MIDDLE)) {
		flapper->getSprite().rotateBy(100);
	}
	*/

	if (Keyboard::key(GLFW_KEY_SPACE) || Mouse::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
		flapper->flap();
	}

	/*
	if (Keyboard::key(GLFW_KEY_W)) {
		flapper->getRB().addForce(Vector3(0, 20, 0));
		//player.getSprite().moveUp();
	}
	if (Keyboard::key(GLFW_KEY_S)) {

		flapper->getRB().addForce(Vector3(0, -20, 0));
		//player.getSprite().moveDown();
	}
	if (Keyboard::key(GLFW_KEY_A)) {

		flapper->getRB().addForce(Vector3(-200, 0, 0));
		//player.getSprite().moveLeft();
	}
	if (Keyboard::key(GLFW_KEY_D)) {

		flapper->getRB().addForce(Vector3(200, 0, 0));
		//player.getSprite().moveRight();
	}
	*/
}