#version 330 core

in vec4 vertex; // layout (location = 0) in vec4 vertex;
in vec3 normal; // layout (location = 1) in vec3 normal;
in vec2 uv0; // layout (location = 2) in vec2 uv0;
out vec2 vUv0; // coordenadas de textura

uniform mat4 modelViewProjMat; // matriz de proyección
uniform mat4 modelViewMat; // matriz de vista
uniform mat4 normalMat; // matriz de normal

out vec3 viewVertex; // coordenadas de vértice en view space
out vec3 viewNormal; // coordenadas de normal en view space


void main() {
    // diffuse en view space
    vec3 viewVertex = vec3(modelViewMat * vertex);
    vec3 viewNormal = normalize(vec3(normalMat * vec4(normal,0)));

    vUv0 = uv0;

    gl_Position = modelViewProjMat * vertex;
    // en Clip-space
}

