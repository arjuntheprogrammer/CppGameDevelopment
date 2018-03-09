#ifndef TWITCH_GAMEMANAGER
#define TWITCH_GAMEMANAGER

#include "../Engine/Engine.h"
#include "../Engine/Graphics/Sprite.h"
#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"
#include "Flapper.h"
#include "PipeManager.h"


class GameManager {

public:
	enum class State {
		START,
		GAMEPLAY,
		GAMEOVER,
		COUNT
	};

public:
	GameManager();
	~GameManager();
	void start();
private:
	Engine* mEngine;
	Flapper* mFlapper;
	PipeManager* mPipeManager;

	Sprite mStartSprite;
	Sprite mGameOverSprite;

	State mState;
};


#endif // !TWITCH_GAMEMANAGER
