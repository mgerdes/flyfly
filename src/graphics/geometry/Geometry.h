#ifndef GRAPHICS_GEOMETRY_H
#define GRAPHICS_GEOMETRY_H

#include "Vector3.h"
#include "Matrix4.h"

class Geometry {
    private:
        int numVertices, maxVertices;
        float *vertices;

        int numTextureCoords, maxNumTextureCoords;
        float *textureCoords;

        int numNormals, maxNumNormals;
        float *normals;

        int numFaces, maxNumFaces;
        int *faces;
    public:
        Geometry(int maxVertices);

        ~Geometry();

        void addVertex(float x, float y, float z);

        int getNumVertices();

        float *getVertices();

        void setMaxNumTextureCoords(int maxNumTextureCoords);

        void addTextureCoord(float x, float y);

        int getNumTextureCoords();

        float *getTextureCoords();

        bool hasTextureCoords();

        void setMaxNumNormals(int maxNumNormals);

        void addNormal(float x, float y, float z);

        int getNumNormals();

        float *getNormals();

        bool hasNormals();

        void setMaxNumFaces(int maxNumFaces);

        void addFace(int x, int y, int z);

        int getNumFaces();

        int *getFaces();

        void applyMatrix(Matrix4 *m);
};

#endif
