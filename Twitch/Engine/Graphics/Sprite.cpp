#include "Sprite.h"
#include "../Engine.h"


Sprite::Sprite() {
	pos = Vector3(0);
	
	rot = 0;
	speed = 100;
	texture = Texture();
}

Sprite::Sprite(string imagePath) {

	pos = Vector3(0);
	rot = 0;
	speed = 100;
	texture = Texture(imagePath);

}

Sprite::Sprite(string imagePath, Vector3 v) {
	texture = Texture(imagePath);

	pos = v;
	rot = 0;
	speed = 100;

}
void Sprite::Update() {

	
}

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.getID());
	glLoadIdentity();

	//Translate -> Rotate -> Scale

	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);

	
	
	//Rendering
	glColor4f(1, 1, 1, 1);
	  
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);	glVertex2i(0, 0);
	glTexCoord2f(1, 0);	glVertex2i(texture.getWidth(), 0);
	glTexCoord2f(1, 1);	glVertex2i(texture.getWidth(), texture.getHeight());
	glTexCoord2f(0, 1);	glVertex2i(0 , texture.getHeight());

	glEnd();
	glDisable(GL_TEXTURE_2D);



}


void Sprite::speedTo(float x) {
	speed = x;
}

void Sprite::speedBy(float x) {
	speed += x;
	
}

void Sprite::moveTo(Vector3 v) {
	pos = v;
}

void Sprite::moveBy(Vector3 v) {

	pos = pos + (v*(float)Engine::getDt());
}

void Sprite::moveLeft() {
	pos = pos - Vector3((speed * Engine::getDt()), 0, 0);

}
void Sprite::moveRight() {
	pos = pos + Vector3((speed *Engine::getDt()), 0, 0);

}

void Sprite::moveUp() {
	pos = pos + Vector3(0, (speed * Engine::getDt()), 0);

}

void Sprite::moveDown() {
	pos = pos - Vector3(0, (speed * Engine::getDt()), 0);

}

void Sprite::rotateTo(float x) {
	rot = x;
}


void Sprite::rotateBy(float x) {
	rot += (x * Engine::getDt());
}
void Sprite::setScale(float x) {
	scale = Vector3(x, x, 0);
}
void Sprite::setScale(Vector3 v) {
	scale = v;
}




