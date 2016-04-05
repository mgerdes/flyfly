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
};
