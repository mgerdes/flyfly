#ifndef GRAPHICS_MESH_H
#define GRAPHICS_MESH_H

#include "Object3D.h"
#include "Geometry.h"
#include "Material.h"

class Mesh : public Object3D {
    private:
        unsigned int EBO, VAO, verticesVBO, normalsVBO, indicesVBO;

        Geometry *geometry;
        Material *material;
    public:
        Mesh(Geometry *geometry, Material *material);

        ~Mesh();

        void draw();

        Material *getMaterial();

        Geometry *getGeometry();
};

#endif 
