#ifndef TWITCH_PIPE
#define TWITCH_PIPE

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"
#include "../Engine/Math/Vector3.h"

class Pipe {

public:
	static Sprite* pipeSprite;
	static void Initialize();


	Pipe();
	Pipe(Vector3 _pos);

	void setGap(float _gap);

	void update();
	void render();
	void moveTo(Vector3 to);
	void moveBy(Vector3 by);
	
	float getX();
	float getWidth();


	Rigidbody getTopRB();
	Rigidbody getBotRB();




private:
	void updatePos();
	Sprite topSprite;
	Sprite botSprite;
	Rigidbody topRB;
	Rigidbody botRB;
	
	Vector3 pos;

	float gap;
	float speed;
};

#endif