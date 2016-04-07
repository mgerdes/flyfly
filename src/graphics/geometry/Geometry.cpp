#include "Geometry.h"
#include "stdio.h"

Geometry::Geometry(int maxVertices) {
    this->numVertices = 0;
    this->maxVertices = maxVertices;
    this->vertices = new float[maxVertices * 3];

    this->numTextureCoords = 0;
    this->maxNumTextureCoords = 0;
    this->textureCoords = 0;

    this->numNormals = 0;
    this->maxNumNormals = 0;
    this->normals = 0;

    this->numFaces = 0;
    this->maxNumFaces = 0;
    this->faces = 0;
}

Geometry::~Geometry() {
    delete[] this->vertices;
    if (this->hasTextureCoords()) {
        delete[] this->textureCoords;
    }
    if (this->hasNormals()) {
        delete[] this->normals;
    }
}

void Geometry::addVertex(float x, float y, float z) {
    this->vertices[this->numVertices * 3] = x;
    this->vertices[this->numVertices * 3 + 1] = y;
    this->vertices[this->numVertices * 3 + 2] = z;
    this->numVertices++;
}

int Geometry::getNumVertices() {
    return this->numVertices;
}

float *Geometry::getVertices() {
    return this->vertices;
}

void Geometry::setMaxNumTextureCoords(int maxNumTextureCoords) {
    this->numTextureCoords = 0;
    this->maxNumTextureCoords = maxNumTextureCoords;
    this->textureCoords = new float[maxNumTextureCoords * 2];
}

void Geometry::addTextureCoord(float x, float y) {
    this->textureCoords[this->numTextureCoords * 2] = x;
    this->textureCoords[this->numTextureCoords * 2 + 1] = y;
    this->numTextureCoords++;
}

int Geometry::getNumTextureCoords() {
    return this->numTextureCoords;
}

float *Geometry::getTextureCoords() {
    return this->textureCoords;
}

bool Geometry::hasTextureCoords() {
    return this->numTextureCoords > 0;
}

void Geometry::setMaxNumNormals(int maxNumNormals) {
    this->numNormals = 0;
    this->maxNumNormals = maxNumNormals;
    this->normals = new float[maxNumNormals * 3];
}

float *Geometry::getNormals() {
    return this->normals;
}

int Geometry::getNumNormals() {
    return this->numNormals;
}

void Geometry::addNormal(float x, float y, float z) {
    this->normals[this->numNormals * 3] = x;
    this->normals[this->numNormals * 3 + 1] = y;
    this->normals[this->numNormals * 3 + 2] = z;
    this->numNormals++;
}

bool Geometry::hasNormals() {
    return this->numNormals > 0;
}

void Geometry::setMaxNumFaces(int maxNumFaces) {
    this->faces = new int[maxNumFaces * 3];
}

void Geometry::addFace(int x, int y, int z) {
    this->faces[this->numFaces * 3] = x;
    this->faces[this->numFaces * 3 + 1] = y;
    this->faces[this->numFaces * 3 + 2] = z;
    this->numFaces++;
}

int Geometry::getNumFaces() {
    return this->numFaces;
}

int *Geometry::getFaces() {
    return this->faces;
}

void Geometry::applyMatrix(Matrix4 *m) {
    for (int i = 0; i < getNumVertices(); i++) {
        Vector3 v = Vector3(vertices[i*3], vertices[i*3+1], vertices[i*3+2]);
        v.applyMatrix(m);
        vertices[i*3] = v.x;
        vertices[i*3+1] = v.y;
        vertices[i*3+2] = v.z;
    }
}
