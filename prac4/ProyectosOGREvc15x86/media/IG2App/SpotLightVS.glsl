#version 330 core

in vec4 vertex;
in vec3 normal;
in vec2 uv0;

uniform mat4 modelViewProjMat;
uniform mat4 WorldMat;
uniform mat4 NormalMat;

out vec3 vNormal;
out vec2 vUv0;
out vec4 vVertex;

void main(void){

    vNormal = normalize(vec3(NormalMat * vec4(normal,0)));
    
    vVertex = WorldMat * vertex;
    
    vUv0 = uv0;

    gl_Position = modelViewProjMat * vertex;
}