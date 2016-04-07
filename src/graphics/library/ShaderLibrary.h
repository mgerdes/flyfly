#ifndef GRAPHICS_SHADER_LIBRARY_H
#define GRAPHICS_SHADER_LIBRARY_H

#include "Shader.h"

enum ShaderEnum {
    BASIC_SHADER = 0, BASIC_LINE_SHADER, NUM_SHADERS   
};

class ShaderLibrary {
    private:
        static Shader *shaders[];
    public:
        static void createShaders();

        static void deleteShaders();

        static Shader *getShader(ShaderEnum shader);
};

#endif
