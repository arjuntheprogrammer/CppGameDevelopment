// Twitch.cpp : Defines the entry point for the console application.
//

#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include<iostream>
using namespace std;




int main()
{
	cout << "Hello twitch!" << endl;

	
	Engine engine;
	engine.Initialize("Twitch!");

	Sprite testSprite = Sprite("Assets/Art/Biplane.png", -100, -100);

	while (true) {
		engine.Update();
		testSprite.Update();

		testSprite.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());


		engine.BeginRender();
		testSprite.Render();
		engine.EndRender();
	}
	
	return 0;
}

