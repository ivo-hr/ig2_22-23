#version 330 core

uniform sampler2D texturaL; // tipo sampler2D para texturas 2D
uniform sampler2D texturaM; // -> unidades de textura (int)
uniform float BF; // blending factor
uniform float intLuzAmb; // luz ambiente blanca
in vec2 vUv0; // out del vertex shader
in vec2 vUv1; // out del vertex shader con zoom
out vec4 fFragColor; // out del fragment shader

void main()
{
    vec3 colorL = vec3(texture(texturaL, vUv0)); // acceso al texel
    vec3 colorM = vec3(texture(texturaM, vUv1)); // configuracion
    vec3 color = mix(colorL, colorM, BF) * intLuzAmb; // mix -> (1 -BF).colorL + BF.colorM
    fFragColor = vec4(color, 1.0); // out
}