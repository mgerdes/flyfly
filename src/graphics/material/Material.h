#ifndef GRAPHICS_MATERIAL_H
#define GRAPHICS_MATERIAL_H

#include "Texture.h"
#include "Shader.h"

class Material {
    private:
        Shader *shader;
        Texture *texture;
    public:
        Material(Shader *shader);

        Shader *getShader();

        void setShader(Shader *shader);

        Texture *getTexture();

        void setTexture(Texture *texture);
};

#endif 
