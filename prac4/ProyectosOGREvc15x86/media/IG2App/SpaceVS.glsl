#version 330 core

in vec4 vertex; // atributos de los vertices a procesar
in vec2 uv0; // coordenadas de textura 0
uniform mat4 modelViewProjectionMatrix; // constante de programa
uniform float sintime; // time factor
uniform float a;
uniform float b;
out vec2 vUv0; // out del vertex shader
out vec2 vUv1; // out del vertex shader con zoom

void main()
{
    vUv0 = uv0; // se pasan las coordenadas de textura
    vUv1 = (uv0 - 0.5) * ((sintime * a) + b) + 0.5; // se pasan las coordenadas de textura
    gl_Position = modelViewProjectionMatrix * vertex; // calculo de la posicion del vertice
}