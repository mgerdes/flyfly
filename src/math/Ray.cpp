#include "Ray.h"

Ray::Ray(Vector3 origin, Vector3 direction) : origin(origin), direction(direction) { }

Vector3 Ray::getPointAtTime(float t) {
    Vector3 v;
    v.setThis(&direction);
    v.scaleThis(t);
    v.addToThis(&origin);
    return v; 
}

Vector3 *Ray::getOrigin() {
    return &origin;
}

Vector3 *Ray::getDirection() {
    return &direction;
}
