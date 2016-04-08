#ifndef MATH_QUATERNION_H
#define MATH_QUATERNION_H

#include <math.h>
#include "Matrix4.h"
#include "Vector3.h"

class Quaternion {
    public:
        float w, x, y, z;

        Quaternion();

        Quaternion(float angle, Vector3 *rotationAxis);

        Quaternion(float angle, float x, float y, float z);

        Quaternion(Vector3 *v1, Vector3 *v2);

        Matrix4 getMatrix();

        void normalizeThis();

        void setThis(Quaternion *q);

        void setThis(float w, float x, float y, float z);

        void multiplyThisBy(Quaternion *q);
};

#endif 
