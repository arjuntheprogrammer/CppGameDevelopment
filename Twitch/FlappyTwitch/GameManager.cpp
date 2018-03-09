#include "GameManager.h"

GameManager::GameManager() {

	mEngine = new Engine();
	mEngine->Initialize("Twitch!");

	Sprite testSprite = Sprite("Assets/Art/Biplane.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	testSprite.setScale(0.25f);
	mFlapper = new Flapper(testSprite);
	mPipeManager = new PipeManager();
	
	mStartSprite = Sprite("Assets/Art/spacetostart.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	mGameOverSprite = Sprite("Assets/Art/gameover.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));


	mState = State::START;
	
}
GameManager::~GameManager() {
	delete mEngine;
	delete mFlapper;
	delete mPipeManager;
}

void GameManager::start() {
	while (true) {
		mEngine->Update();
		switch (mState) {
			case State::START: {
				mEngine->BeginRender();
				mStartSprite.Render();
				
				mEngine->EndRender();
			}
			break;

			case State::GAMEPLAY: {
				mFlapper->update();
				mPipeManager->update();

				bool isColliding = mPipeManager->checkCollision(*mFlapper);
				cout << (isColliding ? "Colliding!!!" : "...") << endl;

				mEngine->BeginRender();
				mFlapper->render();

				mPipeManager->render();
				mEngine->EndRender();
			}
			break;

			case State::GAMEOVER: {

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