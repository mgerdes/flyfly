#ifndef FLY_FLY_ROPE
#define FLY_FLY_ROPE

#include "Vector3.h"

class Rope {
    private:
        float speed = 1.0; 
        Vector3 position;
        float length;
    public:
        Rope(Vector3 startPosition);

        void update(float dt);

        float getLength();

        Vector3 *getPosition();
};

#endif
