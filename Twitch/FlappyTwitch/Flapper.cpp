#include "Flapper.h"

Flapper::Flapper() {

}

Flapper::Flapper(Sprite _sprite) {
	sprite = _sprite;
	rb.initialize(0.8f, 0, sprite.getPos(), sprite.getRot(), sprite.getScale(), sprite.getSize());

}


void Flapper::update() {
	sprite.Update();
	rb.update();
}
void Flapper::render() {
	sprite.Render();
	rb.render(Vector3(0,0,0));
}

Sprite& Flapper::getSprite() {
	return sprite;
}

Rigidbody& Flapper::getRB() {
	return rb;
}
