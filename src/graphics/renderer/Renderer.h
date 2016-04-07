#ifndef GRAPHICS_RENDERER_H
#define GRAPHICS_RENDERER_H

#include "Scene.h"
#include "Camera.h"
#include "Mesh.h"
#include "Line.h"
#include "BasicMaterial.h"

class Renderer {
    private:
        Scene *scene;
        Camera *camera;

        void renderObject(Object3D *object, Matrix4 *modelMat);

        void renderCursor(Mesh *cursor);
    public:
        Renderer(Scene *scene, Camera *camera);

        void renderScene();
};

#endif
