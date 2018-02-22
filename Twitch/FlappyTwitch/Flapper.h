#ifndef TWITCH_FLAPPER
#define TWITCH_FLAPPER

#include"../Engine/Graphics/Sprite.h"
#include"../Engine/Physics/Rigidbody.h"

class Flapper {
public:
	Flapper();
	Flapper(Sprite _sprite);

	void update();
	void render();

	Sprite& getSprite();
	Rigidbody& getRB();


private:
	Sprite sprite;
	Rigidbody rb;
};


#endif // !TWITCH_FLAPPER
