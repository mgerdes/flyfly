#include "Line.h"

Line::Line(Geometry *geometry, Material *material) : Object3D(0) {
    this->isLine = true;        

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

    glBindVertexArray(0);
}

Line *Line::createWireframeForBox(Box *box) {
    Geometry *geometry = new Geometry(24);

    Vector3 *min = box->getMin();
    Vector3 *max = box->getMax();

    geometry->addVertex(min->x, min->y, min->z);
    geometry->addVertex(max->x, min->y, min->z);

    geometry->addVertex(min->x, min->y, min->z);
    geometry->addVertex(min->x, max->y, min->z);

    geometry->addVertex(min->x, min->y, min->z);
    geometry->addVertex(min->x, min->y, max->z);

    geometry->addVertex(max->x, min->y, min->z);
    geometry->addVertex(max->x, max->y, min->z);

    geometry->addVertex(max->x, min->y, min->z);
    geometry->addVertex(max->x, min->y, max->z);

    geometry->addVertex(max->x, max->y, min->z);
    geometry->addVertex(min->x, max->y, min->z);

    geometry->addVertex(max->x, max->y, min->z);
    geometry->addVertex(max->x, max->y, max->z);

    geometry->addVertex(max->x, max->y, max->z);
    geometry->addVertex(max->x, min->y, max->z);

    geometry->addVertex(max->x, max->y, max->z);
    geometry->addVertex(min->x, max->y, max->z);

    geometry->addVertex(min->x, max->y, max->z);
    geometry->addVertex(min->x, max->y, min->z);

    geometry->addVertex(min->x, max->y, max->z);
    geometry->addVertex(min->x, min->y, max->z);

    geometry->addVertex(max->x, min->y, max->z);
    geometry->addVertex(min->x, min->y, max->z);

    Material *material = new BasicLineMaterial();
    material->getColor()->setThis(1.0, 0.0, 0.0);

    return new Line(geometry, material);
}

Line::~Line() {

}

void Line::draw() {
    glBindVertexArray(VAO);
    glLineWidth(50.0);
    glDrawArrays(GL_LINES, 0, geometry->getNumVertices());
    glBindVertexArray(0);
}

Geometry *Line::getGeometry() {
    return this->geometry;
}

Material *Line::getMaterial() {
    return this->material;
}

void Line::updateVertices() {
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

    glBindVertexArray(0);
}
