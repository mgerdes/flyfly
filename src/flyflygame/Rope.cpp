#include "Rope.h"

Rope::Rope() : Mesh(new BoxGeometry(), new BasicMaterial()) {
    Matrix4 translationMatrix = Matrix4::translation(0.0, 0.0, 1.0);
    getGeometry()->applyMatrix(&translationMatrix);
    updateVertices();

    this->getScale()->setThis(0.05, 0.05, 500.0);
    this->updateModelMat();
    getRotation()->z = M_PI;
}

void Rope::update(float dt) {

}

float Rope::getLength() {
    return length;
}
