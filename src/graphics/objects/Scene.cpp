#include "Scene.h"

Scene::Scene(int maxNumObjects) : cursor(new CursorGeometry(), new BasicMaterial()) {
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
