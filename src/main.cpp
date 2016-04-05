#include "Window.h"
#include "ShaderLibrary.h"
#include "Renderer.h"
#include "BasicMaterial.h"
#include "BoxGeometry.h"
#include "Scene.h"

int main() {
    Window window = Window("opengl", 1000, 1000);

    ShaderLibrary::createShaders();

    BoxGeometry geometry;

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

        mesh.getRotation()->x += 0.01;
        mesh.getRotation()->y += 0.01;
        mesh.updateModelMat();

        renderer.renderScene();

        window.swapBuffers();
    }

    ShaderLibrary::deleteShaders();

    glfwTerminate();

    return 0;
}
