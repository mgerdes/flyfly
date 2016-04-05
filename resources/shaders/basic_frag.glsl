#version 330 core
#
in vec3 frag_normal;
in vec3 frag_position;

out vec4 color;

void main () {
    color = vec4(abs(frag_normal), 1.0);
}
