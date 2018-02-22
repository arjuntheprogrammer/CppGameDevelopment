#include "Rigidbody.h"
#include "../Engine.h"
Rigidbody::Rigidbody() {
	friction = 1;
	gravity = 0;

}

void Rigidbody::initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size) {
	friction = _friction;
	gravity = _gravity;

	pos = _pos;
	rot = _rot;
	scale = _scale;
	size = _size;
}

void Rigidbody::update() {
	vel.x *= friction;
	vel.y -= gravity;

	*pos = *pos + (vel + Engine::getDt());
	vel = Vector3(0);

}

void Rigidbody::render(Vector3 c) {
	glLoadIdentity();
	glTranslatef(pos->x, pos->y, pos->z);
	glRotatef(*rot, 0, 0, 1);
	glScalef(scale->x, scale->y, scale->z);

	glColor4f(c.x, c.y, c.z, 1);
	glBegin(GL_LINES);
	{
		glVertex2i(0, 0);
		glVertex2i((int)size->x, 0);

		glVertex2i((int)size->x, 0);
		glVertex2i((int)size->x, (int)size->y);

		glVertex2i((int)size->x, (int)size->y);
		glVertex2i(0, (int)size->y);

		glVertex2i(0, (int)size->y);
		glVertex2i(0, 0);


	}	
	glEnd();

	  
}

void Rigidbody::addForce(Vector3 force) {
	vel = vel + force;
}