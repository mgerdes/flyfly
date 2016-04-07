#ifndef GRAPHICS_CURSOR_GEOMETRY_H
#define GRAPHICS_CURSOR_GEOMETRY_H

#include "Geometry.h"

class CursorGeometry : public Geometry {
    public:
        CursorGeometry() : Geometry(4) {
            addVertex(1.0, 1.0, 0.0);
            addVertex(1.0, -1.0, 0.0);
            addVertex(-1.0, 1.0, 0.0);
            addVertex(-1.0, -1.0, 0.0);

            setMaxNumFaces(2);
            addFace(0, 2, 3);
            addFace(0, 1, 3);

            setMaxNumNormals(4);
            addNormal(0.0, 0.0, 0.0);
            addNormal(0.0, 0.0, 0.0);
            addNormal(0.0, 0.0, 0.0);
            addNormal(0.0, 0.0, 0.0);
        };
};

#endif
