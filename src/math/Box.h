#ifndef MATH_BOX_H
#define MATH_BOX_H

#include "Vector3.h"
#include "Ray.h"
#include "Geometry.h"

class Box {
    private:
        Vector3 min, max;

        bool testIntersection(float o, float d, float tmin, float tmax);
    public:
        Box();

        Box(Vector3 min, Vector3 max);

        bool doesRayIntersectThis(Ray *r, float tmin, float tmax);

        Vector3 *getMin();

        Vector3 *getMax();

        void setFromGeometry(Geometry *geometry);
};

#endif
