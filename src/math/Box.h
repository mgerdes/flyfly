#ifndef MATH_BOX_H
#define MATH_BOX_H

#include "Vector3.h"
#include "Ray.h"

class Box {
    private:
        Vector3 min, max;

        bool testIntersection(float o, float d, float tmin, float tmax);
    public:
        Box(Vector3 min, Vector3 max);

        bool doesRayIntersectThis(Ray *r, float tmin, float tmax);
};

#endif
