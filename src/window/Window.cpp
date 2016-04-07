#include "Window.h"

Window::Window(const char *title, int width, int height) {
    if (!glfwInit()) {
        Util::log(ERROR, "Could not start GLFW3");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);

    glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!glfwWindow) {
        Util::log(ERROR, "Could not create window");
    }

    glfwMakeContextCurrent(glfwWindow);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        Util::log(ERROR, "Could not start GLEW");
    }
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

Window::~Window() {
    glfwDestroyWindow(glfwWindow);
}

bool Window::shouldClose() {
    return (bool) glfwWindowShouldClose(glfwWindow);
}

void Window::clearBufferAndColor() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swapBuffers() {
    glfwPollEvents();
    glfwSwapBuffers(glfwWindow);
}

Controls *Window::getControls() {
    return &controls;
}

void Window::updateDimensions() {
    int newWidth, newHeight;
    glfwGetFramebufferSize(glfwWindow, &newWidth, &newHeight); 
    if (newWidth != width || newHeight != height) {
        width = newWidth;
        height = newHeight;
        whereDimensionsChanged = true;
        glViewport(0, 0, width, height);
    } 
    else {
        whereDimensionsChanged = false;
    }
}

void Window::updateControls() {
    double newMousePositionX, newMousePositionY;
    glfwGetCursorPos(glfwWindow, &newMousePositionX, &newMousePositionY);

    controls.mouseDeltaX = newMousePositionX - controls.mousePositionX;
    controls.mouseDeltaY = newMousePositionY - controls.mousePositionY;

    controls.mousePositionX = newMousePositionX;
    controls.mousePositionY = newMousePositionY;

    int leftMouseState = glfwGetMouseButton(glfwWindow, GLFW_MOUSE_BUTTON_LEFT);
    if (leftMouseState == GLFW_PRESS) {
        controls.isLeftMouseDown = true;
    }
    else {
        controls.wasLeftMouseClicked = controls.isLeftMouseDown;
        controls.isLeftMouseDown = false;
    }

    controls.isLeftKeyPressed = glfwGetKey(glfwWindow, GLFW_KEY_LEFT);
    controls.isRightKeyPressed = glfwGetKey(glfwWindow, GLFW_KEY_RIGHT);
    controls.isUpKeyPressed = glfwGetKey(glfwWindow, GLFW_KEY_UP);
    controls.isDownKeyPressed = glfwGetKey(glfwWindow, GLFW_KEY_DOWN);

    controls.isAKeyPressed = glfwGetKey(glfwWindow, GLFW_KEY_A);
    controls.isSKeyPressed = glfwGetKey(glfwWindow, GLFW_KEY_S);
    controls.isDKeyPressed = glfwGetKey(glfwWindow, GLFW_KEY_D);
    controls.isWKeyPressed = glfwGetKey(glfwWindow, GLFW_KEY_W);
    controls.isQKeyPressed = glfwGetKey(glfwWindow, GLFW_KEY_Q);
    controls.isEKeyPressed = glfwGetKey(glfwWindow, GLFW_KEY_E);

    controls.isSpaceKeyPressed = glfwGetKey(glfwWindow, GLFW_KEY_SPACE);
}
