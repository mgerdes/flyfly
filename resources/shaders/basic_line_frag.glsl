#version 330 core

uniform vec3 material_color;

out vec4 color;

void main () {
    color = vec4(material_color, 1.0);
}
