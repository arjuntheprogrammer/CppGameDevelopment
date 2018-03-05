#ifndef TWITCH_PIPEMANAGER
#define TWITCH_PIPEMANAGER
#include "Pipe.h"
#include<vector>
using namespace std;


class PipeManager {
public: 
	PipeManager();
	~PipeManager();
	void update();
	void render();

private:
	vector<Pipe*> pipes;
	float xSeparation;
	float ySeparation;


};

#endif