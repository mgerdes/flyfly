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

    setMaxNumFaces(12);

    addFace(0, 1, 2);
    addFace(3, 4, 5);
    addFace(6, 7, 8);
    addFace(9, 10, 11);
    addFace(12, 13, 14);
    addFace(15, 16, 17);
    addFace(18, 19, 20);
    addFace(21, 22, 23);
    addFace(24, 25, 26);
    addFace(27, 28, 29);
    addFace(30, 31, 32);
    addFace(33, 34, 35);
};
