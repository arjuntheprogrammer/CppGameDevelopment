#ifndef TWITCH_VECTOR3
#define TWITCH_VECTOR3

class Vector3 {

public:
	Vector3();
	Vector3(const Vector3& other);
	Vector3(float _x);
	Vector3(float _x, float _y, float _z);
	



	float x;
	float y;
	float z;

};



#endif