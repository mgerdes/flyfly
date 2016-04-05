#version 330 core

in vec3 frag_normal;
in vec3 frag_position;

out vec4 color;

void main () {
    vec3 light_position = vec3(1.0, 2.0, 3.0);
    float kd = max(dot(normalize(light_position), frag_normal), 0.0);
    kd *= 0.8;
    color = vec4(0.2, 0.2, 0.2, 2.0) + vec4(kd, kd, kd, 1.0);
}
