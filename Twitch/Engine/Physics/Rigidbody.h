#ifndef TWITCH_RIGIDBODY
#define TWITH_RIGIDBODY
#include "../Math/Vector3.h"
#include "../Math/Rect.h"



class Rigidbody {
public:
	Rigidbody();
	void initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* size, Rect _boundingRect);
	void update();
	void render(Vector3 c);

	void addForce(Vector3 force);

	Vector3 getVel();
	void setVel(Vector3 _vel);


private:
	Vector3* pos;
	Vector3* scale;
	Vector3* size;
	float* rot;

	float gravity;
	float friction;
	Vector3 vel;

	Rect boundingRect;
	
};

#endif // !TWITCH_RIGIDBODY
