#ifndef GRAPHICS_SHADER_H
#define GRAPHICS_SHADER_H

#include <unordered_map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Util.h"
#include "Vector3.h"

class Shader {
    private:
        unsigned int shaderProgram;
        std::unordered_map<string, GLint> properties;

        unsigned int compileShader(const char *fileName, int shaderType);
    public:
        Shader(const char *vertexShaderLocation, const char *fragmentShaderLocation);

        void addProperty(const char *propertyName);

        void setMatProperty(const char* propertyName, float m[16]);

        void setVec3Property(const char* propertyName, Vector3 *v);

        void setVec3Property(const char* propertyName, float x, float y, float z);

        void bind();

        void unbind();
};


#endif 
