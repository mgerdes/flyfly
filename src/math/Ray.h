#ifndef MATH_RAY_H
#define MATH_RAY_H

#include "Vector3.h"

class Ray {
    private:
        Vector3 origin;
        Vector3 direction;
    public:
        Ray(Vector3 origin, Vector3 direction);

        Vector3 getPointAtTime(float t);

        Vector3 *getOrigin();

        Vector3 *getDirection();
};

#endif
