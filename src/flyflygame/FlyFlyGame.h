#ifndef FLY_FLY_GAME
#define FLY_FLY_GAME

#include <stdlib.h>  

#include "Window.h"
#include "Scene.h"
#include "Camera.h"
#include "BoxGeometry.h"
#include "BasicMaterial.h"

class FlyFlyGame {
    private:
        Scene scene; 
        Camera camera;
    public:
        FlyFlyGame();

        void update(float dt, Controls *controls);

        Scene *getScene();
        
        Camera *getCamera();
};

#endif
