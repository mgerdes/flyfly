#include "FlyFlyGame.h"

FlyFlyGame::FlyFlyGame() : scene(501), camera(67.0, 1.0, 0.1, 1000.0) {
    for (int i = 0; i < 500; i++) {
        BasicMaterial *material = new BasicMaterial();
        BoxGeometry *boxGeometry = new BoxGeometry();
        Mesh *mesh = new Mesh(boxGeometry, material);

        float a = (rand() % 1000) / 1000.0 * M_PI;
        float b = (rand() % 1000) / 1000.0 * 2 * M_PI;

        float cosA = cos(a);
        float sinA = sin(a);
        float cosB = cos(b);
        float sinB = sin(b);

        int r = (rand() % 5000) + 25;

        mesh->getTranslation()->setThis(r * sinA * cosB, r * sinA * sinB, r * cosA);
        mesh->getScale()->setThis(3.0, 3.0, 3.0);
        mesh->updateModelMat();
        scene.addObject(mesh);
    }
    scene.addObject(&rope);
}

void FlyFlyGame::update(float dt, Controls *controls) {
    static float azimuthAngle = 180.0; 
    static float inclinationAngle = 90.0;
    static float PI_OVER_180 = M_PI / 180.0;

    azimuthAngle -= controls->mouseDeltaX * dt * controls->mouseSensitivity;
    inclinationAngle += controls->mouseDeltaY * dt * controls->mouseSensitivity;

    if (inclinationAngle > 179) {
        inclinationAngle = 179;
    }
    if (inclinationAngle < 1) {
        inclinationAngle = 1; 
    }

    float azimuthAngleRads = azimuthAngle * PI_OVER_180;
    float inclinationAngleRads = inclinationAngle * PI_OVER_180;

    float cosAzimuth = cos(azimuthAngleRads);
    float sinAzimuth = sin(azimuthAngleRads);
    float cosInclination = cos(inclinationAngleRads);
    float sinInclination = sin(inclinationAngleRads);

    if (controls->isLeftKeyPressed) {
        azimuthAngle += 50 * dt;
    }
    if (controls->isRightKeyPressed) {
        azimuthAngle -= 50 * dt;
    }
    if (controls->isUpKeyPressed) {
        inclinationAngle -= 50 * dt;
    }
    if (controls->isDownKeyPressed) {
        inclinationAngle += 50 * dt;
    }

    if (controls->isWKeyPressed) {
        camera.getPosition()->addToThis(sinInclination * sinAzimuth, cosInclination, sinInclination * cosAzimuth);
    }
    if (controls->isSKeyPressed) {
        camera.getPosition()->addToThis(-sinInclination * sinAzimuth, -cosInclination, -sinInclination * cosAzimuth);
    }
    if (controls->isAKeyPressed) {
        camera.getPosition()->addToThis(sinInclination * cosAzimuth, cosInclination, -sinInclination * sinAzimuth);
    }
    if (controls->isDKeyPressed) {
        camera.getPosition()->addToThis(-sinInclination * cosAzimuth, cosInclination, sinInclination * sinAzimuth);
    }
    if (controls->isQKeyPressed) {
        rope.update(dt);
    }
    if (controls->isEKeyPressed) {
        rope.update(-dt);
    }

    camera.getLookAt()->setThis(camera.getPosition());
    camera.getLookAt()->addToThis(sinInclination * sinAzimuth, cosInclination, sinInclination * cosAzimuth);

    rope.getTranslation()->setThis(camera.getPosition());
    rope.getTranslation()->addToThis(0.0, -1.0, 0.0);

    Vector3 v1(0.0, 0.0, 1.0);
    Vector3 v2(sinInclination * sinAzimuth, cosInclination, -sinInclination * cosAzimuth);
    v2.normalizeThis();
    Quaternion q(&v1, &v2); 
    rope.getQuaternion()->setThis(&q);

    rope.updateModelMat();

    camera.updateViewMatrix();
}

Scene *FlyFlyGame::getScene() {
    return &scene;
}

Camera *FlyFlyGame::getCamera() {
    return &camera;
}
