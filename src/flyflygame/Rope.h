#ifndef FLY_FLY_ROPE
#define FLY_FLY_ROPE

#include "Vector3.h"
#include "BasicMaterial.h"
#include "BoxGeometry.h"
#include "Mesh.h"

class Rope : public Mesh {
    private:
        float speed = 1.0; 
        float length;
    public:
        Rope();

        void update(float dt);

        float getLength();
};

#endif
