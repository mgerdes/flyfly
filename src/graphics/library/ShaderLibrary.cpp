#include "ShaderLibrary.h"

Shader *ShaderLibrary::shaders[ShaderEnum::NUM_SHADERS];

void ShaderLibrary::createShaders() {
    shaders[ShaderEnum::BASIC_SHADER] = new Shader("resources/shaders/basic_vert.glsl", "resources/shaders/basic_frag.glsl");
}

void ShaderLibrary::deleteShaders() {
    for (int i = 0; i < ShaderEnum::NUM_SHADERS; i++) {
        delete shaders[i];
    }
}

Shader *ShaderLibrary::getShader(ShaderEnum shader) {
    return shaders[shader];
}
