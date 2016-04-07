#include "Mesh.h"

Mesh::Mesh(Geometry *geometry, Material *material) : Object3D(0) {
    this->isMesh = true;   

    this->geometry = geometry;
    this->material = material;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int verticesVBO;
    glGenBuffers(1, &verticesVBO);
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
    glBufferData(GL_ARRAY_BUFFER,
            3 * geometry->getNumVertices() * sizeof(float),
            geometry->getVertices(),
            GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    unsigned int normalsVBO;
    glGenBuffers(1, &normalsVBO);
    glBindBuffer(GL_ARRAY_BUFFER, normalsVBO);
    glBufferData(GL_ARRAY_BUFFER,
            3 * geometry->getNumNormals() * sizeof(float),
            geometry->getNormals(),
            GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
            3 * geometry->getNumFaces() * sizeof(unsigned int),
            geometry->getFaces(),
            GL_STATIC_DRAW);

    glBindVertexArray(0);
}

Mesh::~Mesh() {

}

void Mesh::draw() {
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 3 * geometry->getNumFaces(), GL_UNSIGNED_INT, NULL);
    glBindVertexArray(0);
}

Material *Mesh::getMaterial() {
    return material;
}

Geometry *Mesh::getGeometry() {
    return geometry;
}

void Mesh::updateVertices() {
    glBindVertexArray(VAO);

    unsigned int verticesVBO;
    glGenBuffers(1, &verticesVBO);
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
    glBufferData(GL_ARRAY_BUFFER,
            3 * geometry->getNumVertices() * sizeof(float),
            geometry->getVertices(),
            GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}
