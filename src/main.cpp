#include "Window.h"
#include "ShaderLibrary.h"
#include "Renderer.h"
#include "BasicMaterial.h"
#include "Geometry.h"
#include "Scene.h"

int main() {
    Window window = Window("opengl", 1000, 1000);

    ShaderLibrary::createShaders();

    Geometry geometry(6);
    geometry.addVertex(-0.5, -0.5, 0.0);
    geometry.addVertex(-0.5,  0.5, 0.0);
    geometry.addVertex( 0.5,  0.5, 0.0);
    geometry.addVertex(-0.5, -0.5, 0.0);
    geometry.addVertex( 0.5, -0.5, 0.0);
    geometry.addVertex( 0.5,  0.5, 0.0);

    BasicMaterial material;
    Mesh mesh(&geometry, &material);

    Scene scene(1);
    scene.addObject(&mesh);

    Camera camera(67.0, 1.0, 0.1, 100.0);

    Renderer renderer(&scene, &camera);

    static double lastTime = glfwGetTime(); 
    while (!window.shouldClose()) {
        window.clearBufferAndColor();

        double currentTime = glfwGetTime();
        double timeDelta = currentTime - lastTime;
        lastTime = currentTime;

        renderer.render();

        window.swapBuffers();
    }

    ShaderLibrary::deleteShaders();

    glfwTerminate();

    return 0;
}
