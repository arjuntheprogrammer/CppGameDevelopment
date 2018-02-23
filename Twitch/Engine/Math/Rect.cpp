#include "Rect.h"

Rect::Rect() {
	pos = Vector3(0);
	size = Vector3(0);
}

Rect::Rect(Vector3 _size) : Rect() {	
	pos= Vector3(0);
	size = _size;
}

Rect::Rect(Vector3 _pos, Vector3 _size) : Rect(_size) {

	pos = _pos;

}

void Rect::MoveBy(Vector3 by) {
	pos = pos + by;
}

void Rect::MoveTo(Vector3 to) {
	pos = to;
}


void Rect::SetSize(Vector3 _size) {
	size = _size;
}


void Rect::UpdateVertices() {
	lowerLeftVertex = Vector3(pos.x - (size.x / 2), pos.y - (size.y / 2), 0);
	lowerRightVertex = Vector3(pos.x + (size.x / 2), pos.y - (size.y / 2), 0);
	upperLeftVertex = Vector3(pos.x - (size.x / 2), pos.y + (size.y / 2), 0);
	upperRightVertex = Vector3(pos.x + (size.x / 2), pos.y + (size.y / 2), 0);

}