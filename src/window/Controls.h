#ifndef WINDOW_CONTROLS
#define WINDOW_CONTROLS

class Controls {
    public:
        /* Mouse Controls */
        double mouseSensitivity = 2.5;
        bool isLeftMouseDown = false, wasLeftMouseClicked = false;
        double mousePositionX, mouseDeltaX, mouseDeltaY, mousePositionY;

        /* Keyboard Controls */
        bool isLeftKeyPressed = false, isRightKeyPressed = false, isUpKeyPressed = false, isDownKeyPressed = false;
        bool isWKeyPressed = false, isSKeyPressed = false, isAKeyPressed = false, isDKeyPressed = false;
        bool isQKeyPressed = false, isEKeyPressed = false;
        bool isSpaceKeyPressed = false;
};

#endif
