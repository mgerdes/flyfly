#ifndef GRAPHICS_LINE_H
#define GRAPHICS_LINE_H

#include "Object3D.h"
#include "Geometry.h"
#include "Material.h"
#include "BasicLineMaterial.h"

class Line : public Object3D {
    private:
        unsigned int VAO;
        Geometry *geometry;
        Material *material;
    public:
        Line(Geometry *geometry, Material *material);

        static Line *createWireframeForBox(Box *box);

        ~Line();

        void draw();

        Geometry *getGeometry();

        Material *getMaterial();

        void updateVertices();
};

#endif
