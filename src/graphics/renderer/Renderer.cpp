#include "Renderer.h"

Renderer::Renderer(Scene *scene, Camera *camera) {
    this->scene = scene;
    this->camera = camera;
}

void Renderer::renderObject(Object3D *object, Matrix4 *modelMat) {
    if (!object->isVisible) {
        return;
    }

    Matrix4 temp = Matrix4::multiply(object->getModelMat(), modelMat);
    modelMat = &temp;

    if (object->isMesh) {
        Mesh *mesh = (Mesh*) object;

        mesh->getMaterial()->getShader()->bind();
        if (mesh->getMaterial()->getTexture()) {
            mesh->getMaterial()->getTexture()->bind();
        }

        mesh->getMaterial()->getShader()->setMatProperty("proj_mat", camera->getProjectionMatrix()->m);
        mesh->getMaterial()->getShader()->setMatProperty("view_mat", camera->getViewMatrix()->m);
        mesh->getMaterial()->getShader()->setMatProperty("model_mat", modelMat->m);

        Matrix4 transpose = Matrix4::transposeOf(modelMat);
        Matrix4 normalMat = Matrix4::inverseOf(&transpose);
        mesh->getMaterial()->getShader()->setMatProperty("normal_mat", normalMat.m);

        mesh->getMaterial()->getShader()->setVec3Property("material_color", mesh->getMaterial()->getColor());

        mesh->draw();

        if (mesh->getMaterial()->getTexture()) {
            mesh->getMaterial()->getTexture()->unbind();
        }
        mesh->getMaterial()->getShader()->unbind();

        if (mesh->getWireframe()) {
            //Matrix4 identity = Matrix4::identity();
            //renderObject(mesh->getWireframe(), &identity);
        }
    }
    else if (object->isLine) {
        Line *line = (Line*) object;

        line->getMaterial()->getShader()->bind();

        line->getMaterial()->getShader()->setMatProperty("proj_mat", camera->getProjectionMatrix()->m);
        line->getMaterial()->getShader()->setMatProperty("view_mat", camera->getViewMatrix()->m);
        line->getMaterial()->getShader()->setMatProperty("model_mat", modelMat->m);

        line->getMaterial()->getShader()->setVec3Property("material_color", line->getMaterial()->getColor());

        line->draw();

        line->getMaterial()->getShader()->unbind();
    }

    Object3D **children = object->getChildren();
    for (int i = 0; i < object->getNumChildren(); i++) {
        renderObject(children[i], modelMat);
    }
}

void Renderer::renderCursor(Mesh* cursor) {
    cursor->getMaterial()->getShader()->bind();

    Matrix4 identity = Matrix4::identity();
    cursor->getMaterial()->getShader()->setMatProperty("proj_mat", identity.m);
    cursor->getMaterial()->getShader()->setMatProperty("view_mat", identity.m);
    Matrix4 modelMat = Matrix4::scale(0.005, 0.005, 0.0);
    cursor->getMaterial()->getShader()->setMatProperty("model_mat", modelMat.m);
    cursor->getMaterial()->getShader()->setVec3Property("material_color", cursor->getMaterial()->getColor());

    cursor->draw();

    cursor->getMaterial()->getShader()->unbind();
}

void Renderer::renderScene() {
    Object3D** objects = this->scene->getObjects();
    int numObjects = this->scene->getNumObjects();

    Matrix4 identity = Matrix4::identity();
    for (int i = 0; i < numObjects; i++) {
        renderObject(objects[i], &identity);
    }

    renderCursor(scene->getCursor());
}
