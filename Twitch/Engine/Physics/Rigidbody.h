#ifndef TWITCH_RIGIDBODY
#define TWITH_RIGIDBODY
#include "../Math/Vector3.h"


class Rigidbody {
public:
	Rigidbody();
	void initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* size);
	void update();
	void render(Vector3 c);

	void addForce(Vector3 force);



private:
	Vector3* pos;
	Vector3* scale;
	Vector3* size;
	float* rot;

	float gravity;
	float friction;
	Vector3 vel;
	
};

#endif // !TWITCH_RIGIDBODY
