#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Util.h"

class Window {
    public:
        GLFWwindow *glfwWindow;

        Window(const char *title, int width, int height);

        ~Window();

        bool shouldClose();

        void clearBufferAndColor();

        void swapBuffers();

        int getWidth();

        int getHeight();
};

#endif 
