#ifndef GRAPHICS_BASIC_LINE_MATERIAL_H
#define GRAPHICS_BASIC_LINE_MATERIAL_H

#include "Material.h"
#include "ShaderLibrary.h"

class BasicLineMaterial : public Material {
    public:
        BasicLineMaterial() : Material(ShaderLibrary::getShader(ShaderEnum::BASIC_LINE_SHADER)) { };
};

#endif
