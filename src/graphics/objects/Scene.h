#ifndef GRAPHICS_SCENE_H
#define GRAPHICS_SCENE_H

#include "Mesh.h"
#include "CursorGeometry.h"
#include "BasicMaterial.h"
#include "Ray.h"

class Scene {
    private:
        int maxNumObjects, numObjects;
        Object3D **objects;
        Mesh cursor;
    public:
        Scene(int maxNumObjects);

        ~Scene();

        void addObject(Object3D *object);

        Object3D** getObjects();

        int getNumObjects();

        Mesh *getCursor();

        Object3D *getClosestHit(Ray *r);
};

#endif
