#ifndef TWITCH_INPUTMANAGER
#define TWITCH_INPUTMANAGER

#include "../Engine/Engine.h"
#include "../Engine/IO/Keyboard.h"
#include "../Engine/IO/Mouse.h"

#include "Flapper.h"

class InputManager {

public:
	InputManager(Flapper* _flapper);
	void update();
	 


private:
	Flapper * flapper;


};


#endif // !TWITCH_INPUTMANAGER
