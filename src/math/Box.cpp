#include "Box.h"

Box::Box() : min(0.0, 0.0, 0.0), max(0.0, 0.0, 0.0) { };

Box::Box(Vector3 min, Vector3 max) : min(min), max(max) { }

/*
 * http://psgraphics.blogspot.com/2016/02/new-simple-ray-box-test-from-andrew.html
 */
bool Box::testIntersection(float o, float d, float tmin, float tmax) {
    if (d == 0) return false;
    float invD = 1.0 / d;

    float t0 = min.x - o * invD;
    float t1 = max.x - o * invD;

    if (invD < 0.0) {
        float temp = t0;
        t0 = t1;
        t1 = temp;
    }

    tmin = t0 > tmin ? t0 : tmin;
    tmax = t1 < tmax ? t1 : tmax;
    if (tmax <= tmin) {
        return false;
    }

    return true;
}

bool Box::doesRayIntersectThis(Ray *r, float tmin, float tmax) {
    return testIntersection(r->getOrigin()->x, r->getDirection()->x, tmin, tmax) &&
        testIntersection(r->getOrigin()->y, r->getDirection()->y, tmin, tmax) &&
        testIntersection(r->getOrigin()->z, r->getDirection()->z, tmin, tmax);
}

Vector3 *Box::getMin() {
    return &min;
}

Vector3 *Box::getMax() {
    return &max;
}

void Box::setFromGeometry(Geometry *geometry) {
    max.x = min.x = geometry->getVertices()[0];
    max.y = min.y = geometry->getVertices()[1];
    max.z = min.z = geometry->getVertices()[2];
    
    for (int i = 0; i < geometry->getNumVertices(); i++) {
        float x = geometry->getVertices()[i*3];
        float y = geometry->getVertices()[i*3 + 1];
        float z = geometry->getVertices()[i*3 + 2];

        if (x < min.x) {
            min.x = x;
        }
        if (x > max.x) {
            max.x = x;
        }

        if (y < min.y) {
            min.y = y;
        }
        if (y > max.y) {
            max.y = y;
        }

        if (z < min.z) {
            min.z = z;
        }
        if (z > max.z) {
            max.z = z;
        }
    }
}
