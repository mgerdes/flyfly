#ifndef WINDOW_CONTROLS
#define WINDOW_CONTROLS

class Controls {
    public:
        /* Mouse Controls */
        double mouseSensitivity = 5.0;
        bool isLeftMouseDown = false, wasLeftMouseClicked = false;
        double mousePositionX, mouseDeltaX, mouseDeltaY, mousePositionY;
};

#endif
