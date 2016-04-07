#ifndef GRAPHICS_LINE_H
#define GRAPHICS_LINE_H

#include "Object3D.h"
#include "Geometry.h"
#include "Material.h"

class Line : public Object3D {
    private:
        Geometry *geometry;
        Material *material;
    public:
        Line(Geometry *geometry, Material *material);

        ~Line();

        void draw();

        Geometry *Line::getGeometry();

        Material *Line::getMaterial();
};

#endif
