#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Util.h"
#include "Controls.h"

class Window {
    private:
        Controls controls;
    public:
        GLFWwindow *glfwWindow;
        int width, height;
        bool whereDimensionsChanged;

        Window(const char *title, int width, int height);

        ~Window();

        bool shouldClose();

        void clearBufferAndColor();

        void swapBuffers();

        void updateDimensions();

        void updateControls();

        Controls *getControls();
};

#endif 
