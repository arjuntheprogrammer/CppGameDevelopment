#ifndef TWITCH_TEXTURE
#define TWITCH_TEXTURE

#include "GLFW/glfw3.h"
#include "SOIL/include/SOIL.h"

#include <iostream>
#include <string>
using namespace std;


class Texture {

public:
	Texture();
	Texture(int _id);
	Texture(string path);

	int getID();
	int getWidth();
	int getHeight();
	

private:
	bool GetTextureParams();

	int id;
	int width;
	int height;
};

#endif