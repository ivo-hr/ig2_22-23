#version 330 core

uniform sampler2D texturaC;
uniform sampler2D texturaF; // tipo sampler2D para texturas 2D
uniform sampler2D texturaB; // -> unidades de textura (int)

uniform vec3 lightDiff;
uniform vec4 lightPos;
uniform vec3 matFDiff;
uniform vec3 matBDiff;


in vec2 vUv0; // out del vertex shader
in vec3 viewVertex;
in vec3 viewNormal;

out vec4 fFragColor; // out del fragment shader

uniform float Flipping;

float diff(vec3 cVertex, vec3 cNormal)
{
    vec3 lightDir = lightPos.xyz; // directional light ?
    if (lightPos.w == 1) // positional light ?
    lightDir = lightPos.xyz - cVertex;
    return max(dot(cNormal, normalize(lightDir)), 0.0);
    // dot: coseno ángulo
}

void main()
{
    vec3 diffuse = diff(viewVertex, viewNormal) * lightDiff * matFDiff;
    vec3 vFColor = diffuse;

    diffuse = diff(viewVertex, -viewNormal) * lightDiff * matBDiff;
    vec3 vBColor = diffuse;

    vec3 colorC = vec3(texture(texturaC, vUv0)); // coordenadas de textura
    if (colorC.x > 0.6) discard; // descartar fragmentos
    vec3 colorBS = vec3(texture(texturaF, vUv0)); // acceso al texel
    vec3 colorBM = vec3(texture(texturaB, vUv0)); // configuracion


    if (Flipping > -1)  gl_FrontFacing;
    else    !gl_FrontFacing;

    bool b = gl_FrontFacing;

    vec3 color; //
    if (b) color = colorBM * vFrontColor;
    else color = colorBS * vBackColor;

    fFragColor = vec4(color, 1.0); // out
}