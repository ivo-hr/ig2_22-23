#version 330 core

uniform sampler2D texturaC;
uniform sampler2D texturaBS; // tipo sampler2D para texturas 2D
uniform sampler2D texturaBM; // -> unidades de textura (int)
uniform float intLuzAmb; // luz ambiente blanca
in vec2 vUv0; // out del vertex shader
out vec4 fFragColor; // out del fragment shader

uniform float Flipping;

void main()
{
    vec3 colorC = vec3(texture(texturaC, vUv0)); // coordenadas de textura
    if (colorC.x > 0.6) discard; // descartar fragmentos
    vec3 colorBS = vec3(texture(texturaBM, vUv0)); // acceso al texel
    vec3 colorBM = vec3(texture(texturaBS, vUv0)); // configuracion


    if (Flipping > -1)  gl_FrontFacing;
    else    !gl_FrontFacing;

    bool b = gl_FrontFacing;

    vec3 color; //
    if (!b) color = colorBM * intLuzAmb;
    else color = colorBS * intLuzAmb;

    fFragColor = vec4(color, 1.0); // out
}