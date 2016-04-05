#include "Window.h"
#include "ShaderLibrary.h"
#include "Renderer.h"
#include "BasicMaterial.h"
#include "BoxGeometry.h"
#include "Scene.h"

int main() {
    Window window = Window("opengl", 1000, 1000);

    ShaderLibrary::createShaders();

    BasicMaterial material1;
    BoxGeometry geometry1;
    Mesh mesh1(&geometry1, &material1);
    mesh1.getTranslation()->setThis(2.0, 0.0, 4.0);
    mesh1.getScale()->setThis(1.0, 1.0, 1.0);
    mesh1.updateModelMat();

    BasicMaterial material2;
    BoxGeometry geometry2;
    Mesh mesh2(&geometry2, &material2);
    mesh2.getTranslation()->setThis(-2.0, 0.0, 0.0);
    mesh2.updateModelMat();

    Scene scene(2);
    scene.addObject(&mesh1);
    scene.addObject(&mesh2);

    Camera camera(67.0, 1.0, 0.1, 100.0);

    Renderer renderer(&scene, &camera);

    static double lastTime = glfwGetTime(); 
    while (!window.shouldClose()) {
        window.clearBufferAndColor();

        double currentTime = glfwGetTime();
        double timeDelta = currentTime - lastTime;
        lastTime = currentTime;

        mesh1.getRotation()->x += 0.01;
        mesh1.updateModelMat();

        renderer.renderScene();

        window.swapBuffers();
    }

    ShaderLibrary::deleteShaders();

    glfwTerminate();

    return 0;
}
