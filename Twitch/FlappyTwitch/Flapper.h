#ifndef TWITCH_FLAPPER
#define TWITCH_FLAPPER

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"


class Flapper {
public:
	Flapper();
	Flapper(Sprite _sprite);

	void update();
	void render();

	void flap();

	Sprite& getSprite();
	Rigidbody& getRB();

	void reset();

private:
	void handleInput(); 

private:
	Sprite sprite;
	Rigidbody rb;
	float flapForce;
	float maxRot;
	float minRot;
};


#endif // !TWITCH_FLAPPER
