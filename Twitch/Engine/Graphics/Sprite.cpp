#include "Sprite.h"

Sprite::Sprite() {
	xPos = 0;
	yPos = 0;
	rot = 0;
	speed = 5;
	texture = Texture();
}

Sprite::Sprite(string imagePath) {
	xPos = 0;
	yPos = 0;
	rot = 0;
	speed = 5;
	texture = Texture(imagePath);

}

Sprite::Sprite(string imagePath, float _xPos, float _yPos) {
	texture = Texture(imagePath);
	xPos = _xPos;
	yPos = _yPos;
	rot = 0;
	speed = 5;

}
void Sprite::Update() {

	
}

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.getID());
	glLoadIdentity();

	//Translate -> Rotate -> Scale

	glTranslatef(xPos, yPos, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(xScale, yScale, 1);

	
	
	//Rendering
	glColor4f(1, 1, 1, 1);
	  
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);	glVertex2f(0, 0);
	glTexCoord2f(1, 0);	glVertex2f(texture.getWidth(), 0);
	glTexCoord2f(1, 1);	glVertex2f(texture.getWidth(), texture.getHeight());
	glTexCoord2f(0, 1);	glVertex2f(0 ,  texture.getHeight());

	glEnd();
	glDisable(GL_TEXTURE_2D);



}


void Sprite::speedTo(float x) {
	speed = x;
}

void Sprite::speedBy(float x) {
	speed += x;
	
}

void Sprite::moveTo(float x, float y) {
	xPos = x;
	yPos = y;
}

void Sprite::moveBy(float x, float y) {
	xPos += x;
	yPos += y;
}

void Sprite::moveLeft() {
	xPos -= speed;
}
void Sprite::moveRight() {
	xPos += speed;
}

void Sprite::moveUp() {
	yPos += speed;
}

void Sprite::moveDown() {
	yPos -= speed;
}

void Sprite::rotateTo(float x) {
	rot = x;
}


void Sprite::rotateBy(float x) {
	rot += x;
}
void Sprite::setScale(float x) {
	xScale = x;
	yScale = x;
}
void Sprite::setScale(float x, float y) {
	xScale = x;
	yScale = y;
}




