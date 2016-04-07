#include "Rope.h"

Rope::Rope(Vector3 position) : position(position) {
    length = 0;
}

void Rope::update(float dt) {
    length += speed * dt;      
}

Vector3 *Rope::getPosition() {
    return &position;
}

float Rope::getLength() {
    return length;
}
