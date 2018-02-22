// Twitch.cpp : Defines the entry point for the console application.
//

#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "FlappyTwitch/Flapper.h"
#include<iostream>
using namespace std;




int main()
{
	cout << "Hello twitch!" << endl;

	
	Engine engine;
	engine.Initialize("Twitch!");

	Sprite testSprite = Sprite("Assets/Art/Biplane.png", Vector3(100, 100, 0));
	testSprite.setScale(0.25f);

	Flapper player(testSprite);

	while (true) {
		engine.Update();
		player.update();

		//testSprite.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());

		if (Mouse::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
			player.getSprite().rotateBy(100);
		}
		if (Mouse::buttonUp(GLFW_MOUSE_BUTTON_RIGHT)) {
			player.getSprite().rotateBy(-100);
		}
		if (Mouse::button(GLFW_MOUSE_BUTTON_MIDDLE)) {
			player.getSprite().rotateBy(100);
		}

		if (Keyboard::key(GLFW_KEY_W)) {
			player.getRB().addForce(Vector3(0, 20, 0));
			//player.getSprite().moveUp();
		}
		if (Keyboard::key(GLFW_KEY_S)) {

			player.getRB().addForce(Vector3(0, -20, 0));
			//player.getSprite().moveDown();
		}
		if (Keyboard::key(GLFW_KEY_A)) {

			player.getRB().addForce(Vector3(-200, 0, 0));
			//player.getSprite().moveLeft();
		}
		if (Keyboard::key(GLFW_KEY_D)) {

			player.getRB().addForce(Vector3(200, 0, 0));
			//player.getSprite().moveRight();
		}
		
		engine.BeginRender();
		player.render();
		engine.EndRender();


	}
	
	return 0;
}

