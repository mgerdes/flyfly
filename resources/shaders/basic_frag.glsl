#version 330 core

in vec3 frag_normal;
in vec3 frag_position;

uniform vec3 material_color; 

out vec4 color;

void main () {
    vec3 light_position = vec3(1.0, 2.0, 3.0);
    float kd = max(dot(normalize(light_position), frag_normal), 0.0);

    vec3 ambient = material_color * 0.2;
    vec3 diffuse = material_color * kd;

    color = vec4(ambient + diffuse, 1.0);
}
