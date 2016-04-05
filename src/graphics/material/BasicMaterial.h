#ifndef GRAPHICS_BASIC_MATERIAL_H
#define GRAPHICS_BASIC_MATERIAL_H

#include "Material.h"
#include "ShaderLibrary.h"

class BasicMaterial : public Material {
    public:
        BasicMaterial() : Material(ShaderLibrary::getShader(ShaderEnum::BASIC_SHADER)) { };
};

#endif
