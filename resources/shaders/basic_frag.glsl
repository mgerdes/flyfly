#version 330 core

in vec3 frag_position;
in vec3 frag_normal;

out vec4 color;

void main () {
    vec3 light_position1 = vec3(0.0, 0.0, 2.0);

    float kd = max(dot(light_position1, frag_normal), 0.0) * 0.12;

    color = vec4(0.1, 0.1, 0.1, 1.0) + vec4(kd, kd, kd, 1.0);
}
