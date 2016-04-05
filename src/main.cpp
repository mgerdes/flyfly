#include "Window.h"
#include "ShaderLibrary.h"
#include "Renderer.h"
#include "FlyFlyGame.h"

int main() {
    Window window = Window("opengl", 1000, 1000);

    ShaderLibrary::createShaders();

    FlyFlyGame game;
    Renderer renderer(game.getScene(), game.getCamera());

    static double lastTime = glfwGetTime(); 
    while (!window.shouldClose()) {
        window.clearBufferAndColor();

        double currentTime = glfwGetTime();
        double timeDelta = currentTime - lastTime;
        lastTime = currentTime;

        window.updateControls();
        game.update(timeDelta, window.getControls());
        renderer.renderScene();

        window.swapBuffers();
    }

    ShaderLibrary::deleteShaders();

    glfwTerminate();

    return 0;
}
