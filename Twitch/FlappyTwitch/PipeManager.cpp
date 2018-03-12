#include "PipeManager.h"

#include "../Engine/Engine.h"
#include "../Engine/Physics/Rigidbody.h"


PipeManager::PipeManager(): 
	xStartSeparation(800),
	//yStartSeparation(1000),
	yStartSeparation(300),
	xSeparation(xStartSeparation),
	ySeparation(yStartSeparation),
	minXSeparation(200),
	minYSeparation(300),
	xSeparationSpeed(10),
	ySeparationSpeed(10),
	///minSpawnY(100),
	minSpawnY(284),
	//maxSpawnY(Engine::SCREEN_HEIGHT - 100),
	maxSpawnY(Engine::SCREEN_HEIGHT - 284),
	totalPipes(0),
	points(0)
{
	Pipe::Initialize();
	createPipe();
}

PipeManager::~PipeManager() {

	for (unsigned int i = 0; i < pipes.size(); i++) {
		delete pipes[i];
	}
}

void PipeManager::update() {
	
	vector<int> pipesToDetele;
	for (unsigned int i = 0; i < pipes.size(); i++) {
		pipes[i]->update();
		if (pipes[i]->getX() < -(pipes[i]->getWidth() / 2)) {
			pipesToDetele.push_back(i);
		}

		if (i == pipes.size() - 1) {
			if (pipes[i]->getX() < Engine::SCREEN_WIDTH - xSeparation) {
				createPipe();
			}
		}

		if (pipes[i]->getX() < Engine::SCREEN_WIDTH / 2 &&
			pipes[i]->getPrevPos() > Engine::SCREEN_WIDTH / 2)
		{
			points++;
		}
	}

	for (unsigned int i = 0; i < pipesToDetele.size(); i++) {
		delete pipes[pipesToDetele[i]];
		pipes.erase(pipes.begin() + pipesToDetele[i]);
	}

	cout << "Points: " << points << endl;
}


void PipeManager::render() {
	for (unsigned int i = 0; i < pipes.size(); i++) {
		pipes[i]->render();
	}
}

bool PipeManager::checkCollision(Flapper& flapper) {
	bool isColliding = false;
	for (unsigned int i = 0; i < pipes.size(); i++) {
		isColliding = Rigidbody::isColliding(flapper.getRB(), pipes[i]->getTopRB()) || 
						Rigidbody::isColliding(flapper.getRB(), pipes[i]->getBotRB());
		if (isColliding) {
			break;
		}
	}

	return isColliding;
}

void PipeManager::reset() {
	
	for (unsigned int i = 0; i < pipes.size(); i++) {
		delete pipes[i];
	}
	pipes.clear();

	xSeparation = xStartSeparation;
	ySeparation = yStartSeparation;
	totalPipes = 0;
	points = 0;

	createPipe();
}

//Private

void PipeManager::createPipe() {

	float spawnY = (rand() % (maxSpawnY - minSpawnY)) + minSpawnY;
	Pipe* pipe = new Pipe(Vector3(Engine::SCREEN_WIDTH, spawnY, 0));
	pipe->setGap(ySeparation);

	pipes.push_back(pipe);
	totalPipes++;

	if (totalPipes % 2 == 0) {
		if (xSeparation > minXSeparation + xSeparationSpeed) {
			xSeparation -= xSeparationSpeed;
		}

		if (ySeparation > minYSeparation + ySeparationSpeed) {
			ySeparation -= ySeparationSpeed;
		}
	}
}