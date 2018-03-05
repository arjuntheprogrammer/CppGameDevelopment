#include "PipeManager.h"
#include "../Engine/Engine.h"

PipeManager::PipeManager(): xSeparation(1000), ySeparation() {
	pipes.push_back(new Pipe(Vector3(1500, Engine::SCREEN_HEIGHT / 2, 0)));
	pipes.push_back(new Pipe(Vector3(3000, Engine::SCREEN_HEIGHT / 2, 0)));
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
		if (pipes[i]->getX() < -100) {
			pipesToDetele.push_back(i);
			
		}
	}

	for (unsigned int i = 0; i < pipesToDetele.size(); i++) {
		delete pipes[pipesToDetele[i]];
		pipes.erase(pipes.begin() + pipesToDetele[i]);
	}

}


void PipeManager::render() {
	for (unsigned int i = 0; i < pipes.size(); i++) {
		pipes[i]->render();
	}
}