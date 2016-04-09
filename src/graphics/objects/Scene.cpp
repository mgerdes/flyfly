#include "Scene.h"

Scene::Scene(int maxNumObjects) : cursor(new CursorGeometry(), new BasicMaterial()) {
    this->cursor.getMaterial()->getColor()->setThis(10.0, 10.0, 10.0);
    this->numObjects = 0;
    this->maxNumObjects = maxNumObjects;
    this->objects = new Object3D*[maxNumObjects];    
}

Scene::~Scene() {
    delete[] this->objects;
}

void Scene::addObject(Object3D *object) {
    this->objects[this->numObjects++] = object;
}

int Scene::getNumObjects() {
    return this->numObjects;
}

Object3D **Scene::getObjects() {
    return this->objects;
}

Mesh *Scene::getCursor() {
    return &this->cursor;
}

Object3D *Scene::getClosestHit(Ray *r) {
    for (int i = 0; i < numObjects; i++) {
        Box *box = objects[i]->getBoundingBox();
        if (box->doesRayIntersectThis(r, 0.0, 10000.0)) {
            return objects[i];
        }
    }
}
