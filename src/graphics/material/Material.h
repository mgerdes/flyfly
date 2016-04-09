#ifndef GRAPHICS_MATERIAL_H
#define GRAPHICS_MATERIAL_H

#include "Texture.h"
#include "Shader.h"
#include "Vector3.h"

class Material {
    private:
        Shader *shader;
        Texture *texture;
        Vector3 color;
    public:

        Material(Shader *shader);

        Shader *getShader();

        void setShader(Shader *shader);

        Texture *getTexture();

        void setTexture(Texture *texture);

        Vector3 *getColor();
};

#endif 
