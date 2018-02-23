#include "Sprite.h"
#include "../Engine.h"


Sprite::Sprite() {
	pos = Vector3(0);
	
	rot = 0;
	speed = 100;
	texture = Texture();
	scale = Vector3(1);
	size = Vector3(0);
}

Sprite::Sprite(string imagePath) {

	pos = Vector3(0);
	rot = 0;
	speed = 100;
	texture = Texture(imagePath);

	scale = Vector3(1);
	size = Vector3((float)texture.getWidth(), (float)texture.getHeight(), 1);
}

Sprite::Sprite(string imagePath, Vector3 v) {
	texture = Texture(imagePath);

	pos = v;
	rot = 0;
	speed = 100;

	scale = Vector3(1);
	size = Vector3((float)texture.getWidth(), (float)texture.getHeight(), 1);

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
	{
		glTexCoord2f(0, 0);	glVertex2i(-texture.getWidth()/2, -texture.getHeight()/2);
		glTexCoord2f(1, 0);	glVertex2i(texture.getWidth() / 2, -texture.getHeight() / 2);
		glTexCoord2f(1, 1);	glVertex2i(texture.getWidth()/2, texture.getHeight()/2);
		glTexCoord2f(0, 1);	glVertex2i(-texture.getWidth() / 2, texture.getHeight() / 2);

	}
	
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



Vector3* Sprite::getPos() {
	return &pos;
}
float* Sprite::getRot() {
	return &rot;
}
Vector3* Sprite::getScale() {
	return &scale;
}
Vector3* Sprite::getSize() {
	return &scale;
}

