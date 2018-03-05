#include "Pipe.h"
#include "../Engine/Math/Rect.h"
#include "../Engine/Math/Math.h"
#include "../Engine/Engine.h"


Sprite* Pipe::pipeSprite = NULL;

void Pipe::Initialize() {
	pipeSprite = new Sprite("Assets/Art/pipe.png");
}

Pipe::Pipe() {
	if (!pipeSprite) {
		cout << "Trying to instantiate a Pipe without calling the Initialize method!" << endl;
		return;
	}

	topSprite = Sprite(*pipeSprite);
	botSprite = Sprite(*pipeSprite);

	gap = 100;
	speed = 10;

}

Pipe::Pipe(Vector3 _pos) :Pipe() {
	if (!pipeSprite) {
		return;
	}

	pos = _pos;
	Vector3 topPos = pos;
	topPos.y += (gap / 2);
	topSprite.moveTo(topPos);
	topSprite.setScale((*topSprite.getScale()) * Vector3(0, -1, 0));

	Rect topRC = Rect();
	topRC.SetSize(Vector3(Math::Abs(topSprite.getSize()->x * topSprite.getScale()->x), Math::Abs(topSprite.getSize()->y * topSprite.getScale()->y), 1) );
	topRC.MoveBy(Vector3(0, (topSprite.getSize()->y * topSprite.getScale()->y)/2, 0));



	topRB = Rigidbody();
	topRB.initialize(0, 0, topSprite.getPos(), topSprite.getRot(), topSprite.getScale(),topSprite.getSize(), topRC);

	//////////////////////////////////////////////

	Vector3 botPos = pos;
	botPos.y -= (gap / 2);
	botSprite.moveTo(botPos);

	Rect botRC = Rect();
	botRC.SetSize(Vector3(Math::Abs(botSprite.getSize()->x * botSprite.getScale()->x), Math::Abs(botSprite.getSize()->y * botSprite.getScale()->y), 1));
	botRC.MoveBy(Vector3(0, (botSprite.getSize()->y * botSprite.getScale()->y), 0));



	botRB = Rigidbody();
	botRB.initialize(0, 0, botSprite.getPos(), botSprite.getRot(), botSprite.getScale(), botSprite.getSize(), botRC);

}

void Pipe::update() {
	topSprite.moveBy(Vector3(-speed * Engine::getDt(), 0, 0));
	botSprite.moveBy(Vector3(-speed * Engine::getDt(), 0, 0));
	topRB.update();
	botRB.update();

}

void Pipe::render() {
	topSprite.Render();
	botSprite.Render();

	topRB.render(Vector3(255, 0 ,0));
	botRB.render(Vector3(255, 0, 0));

}

void Pipe::moveTo(Vector3 to) {
	pos = to;
	updatePos();


}
void Pipe::moveBy(Vector3 by) {

	pos = pos + by;
	updatePos();

}


void Pipe::updatePos(){
	Vector3 topPos = pos;
	topPos.y += (gap / 2);
	topSprite.moveTo(topPos);


	Vector3 botPos = pos;
	botPos.y -= (gap / 2);
	botSprite.moveTo(botPos);
}
