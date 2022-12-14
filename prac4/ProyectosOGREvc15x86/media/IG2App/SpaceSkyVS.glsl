#version 330 core

in vec4 vertex; // atributos de los vertices a procesar
in vec2 uv0; // coordenadas de textura 0
uniform mat4 modelViewProjectionMatrix; // constante de programa
out vec2 vUv0; // out del vertex shader

void main()
{
    vUv0 = uv0; // se pasan las coordenadas de textura
    gl_Position = modelViewProjectionMatrix * vertex; // calculo de la posicion del vertice
}