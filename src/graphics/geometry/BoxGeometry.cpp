#include "BoxGeometry.h"

BoxGeometry::BoxGeometry() : Geometry(36) {
    addVertex(1.0, -1.0, 1.0);
    addVertex(-1.0,-1.0,-1.0);
    addVertex(1.0, -1.0,-1.0);
    addVertex(1.0, -1.0, 1.0);
    addVertex(-1.0,-1.0, 1.0);
    addVertex(-1.0,-1.0,-1.0);

    addVertex(1.0,  1.0,-1.0);
    addVertex(-1.0,-1.0,-1.0);
    addVertex(1.0, -1.0,-1.0);
    addVertex(1.0,  1.0,-1.0);
    addVertex(-1.0, 1.0,-1.0);
    addVertex(-1.0,-1.0,-1.0);

    addVertex(-1.0, 1.0, 1.0);
    addVertex(-1.0,-1.0,-1.0);
    addVertex(-1.0, 1.0,-1.0);
    addVertex(-1.0, 1.0, 1.0);
    addVertex(-1.0,-1.0, 1.0);
    addVertex(-1.0,-1.0,-1.0);

    addVertex(1.0, 1.0, 1.0);
    addVertex(1.0,-1.0,-1.0);
    addVertex(1.0, 1.0,-1.0);
    addVertex(1.0, 1.0, 1.0);
    addVertex(1.0,-1.0, 1.0);
    addVertex(1.0,-1.0,-1.0);

    addVertex(1.0,  1.0, 1.0);
    addVertex(-1.0, 1.0,-1.0);
    addVertex(1.0,  1.0,-1.0);
    addVertex(1.0,  1.0, 1.0);
    addVertex(-1.0, 1.0, 1.0);
    addVertex(-1.0, 1.0,-1.0);

    addVertex(1.0,  1.0, 1.0);
    addVertex(-1.0,-1.0, 1.0);
    addVertex(1.0, -1.0, 1.0);
    addVertex(1.0, 1.0, 1.0);
    addVertex(-1.0, 1.0, 1.0);
    addVertex(-1.0, -1.0, 1.0);

    setMaxNumNormals(36);

    addNormal(0.0, -1.0, 0.0);
    addNormal(0.0, -1.0, 0.0);
    addNormal(0.0, -1.0, 0.0);
    addNormal(0.0, -1.0, 0.0);
    addNormal(0.0, -1.0, 0.0);
    addNormal(0.0, -1.0, 0.0);

    addNormal(0.0, 0.0, -1.0);
    addNormal(0.0, 0.0, -1.0);
    addNormal(0.0, 0.0, -1.0);
    addNormal(0.0, 0.0, -1.0);
    addNormal(0.0, 0.0, -1.0);
    addNormal(0.0, 0.0, -1.0);

    addNormal(-1.0, 0.0, 0.0);
    addNormal(-1.0, 0.0, 0.0);
    addNormal(-1.0, 0.0, 0.0);
    addNormal(-1.0, -0.0, 0.0);
    addNormal(-1.0, -0.0, 0.0);
    addNormal(-1.0, -0.0, 0.0);

    addNormal(1.0, 0.0, 0.0);
    addNormal(1.0, 0.0, 0.0);
    addNormal(1.0, 0.0, 0.0);
    addNormal(1.0, 0.0, 0.0);
    addNormal(1.0, 0.0, 0.0);
    addNormal(1.0, 0.0, 0.0);

    addNormal(0.0, 1.0, 0.0);
    addNormal(0.0, 1.0, 0.0);
    addNormal(0.0, 1.0, 0.0);
    addNormal(0.0, 1.0, 0.0);
    addNormal(0.0, 1.0, 0.0);
    addNormal(0.0, 1.0, 0.0);

    addNormal(0.0, 0.0, 1.0);
    addNormal(0.0, 0.0, 1.0);
    addNormal(0.0, 0.0, 1.0);
    addNormal(0.0, 0.0, 1.0);
    addNormal(0.0, 0.0, 1.0);
    addNormal(0.0, 0.0, 1.0);
};
