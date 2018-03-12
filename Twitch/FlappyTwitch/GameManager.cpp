#include "GameManager.h"

#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"

GameManager::GameManager() {

	mEngine = new Engine();
	mEngine->Initialize("Twitch!");

	Sprite testSprite = Sprite("Assets/Art/Biplane.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	testSprite.setScale(0.15f);
	mFlapper = new Flapper(testSprite);
	mPipeManager = new PipeManager();
	
	mStartSprite = Sprite("Assets/Art/spacetostart.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	
	mGameOverSprite = Sprite("Assets/Art/gameover.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	mGameOverSprite.setScale(0.15f);


	mState = State::START;
	
}
GameManager::~GameManager() {
	delete mEngine;
	delete mFlapper;
	delete mPipeManager;
}

void GameManager::start() {
	while (true) {
	if (Keyboard::keyDown(GLFW_KEY_ESCAPE))
		{
			break;
		}

		mEngine->Update();

		switch (mState) {
			case State::START: {
				mEngine->BeginRender();
				mStartSprite.Render();
				
				mEngine->EndRender();

				if (Keyboard::keyDown(GLFW_KEY_SPACE) || Mouse::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
					setState(State::GAMEPLAY);
				}
			}
			break;

			case State::GAMEPLAY: {
				mFlapper->update();
				mPipeManager->update();

				mEngine->BeginRender();
				mFlapper->render();
				mPipeManager->render();
				mEngine->EndRender();

				bool isDead = mPipeManager->checkCollision(*mFlapper);
				//cout << (isDead ? "Colliding!!!" : "...") << endl;

				if (mFlapper->getSprite().getPos()->y < 0 || mFlapper->getSprite().getPos()->y > Engine::SCREEN_HEIGHT) {
					isDead = true;
				}

				if (isDead) {
					setState(State::GAMEOVER);
				}
			}
			break;

			case State::GAMEOVER: {
				mEngine->BeginRender();
				mPipeManager->render();
				mFlapper->render();
				mGameOverSprite.Render();
				mEngine->EndRender();

				if (Keyboard::key(GLFW_KEY_SPACE) || Mouse::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
					setState(State::START);
				}
			}
			break;

			case State::COUNT: {

			}
			break;
			default:
				cout << "Unhandled Game State: " << static_cast<int> (mState) << endl;
				break;
		}
	}
}

//Private

void GameManager::setState(State state) {
	mState = state;
	if (mState == State::START) {
		mFlapper->reset();
		mPipeManager->reset();

	}
}
