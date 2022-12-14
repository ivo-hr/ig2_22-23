#version 330 core

in vec4 vVertexWorld;
in vec3 vNormalWorld;
in vec2 vUv0;

uniform float cutoff;
uniform vec3 lightDiff;
uniform vec4 lightPos;
uniform sampler2D tex;

out vec4 fFragColor;

float atenuation(vec3 cVertex, vec3 cNormal)
{
    vec3 lightDir = lightPos.xyz;
    if (lightPos.w == 1)
        lightDir = lightPos.xyz - cVertex;
    
    float att = 0.2;

    if (dot(cNormal, normalize(lightDir)) > (cutoff * 0.5) + 0.5)
        att = 1.0;

    return att;
}

void main(void)
{
    vec3 texColour = vec3(texture(tex, vUv0));
    vec3 diff = lightDiff * atenuation(vec3(vVertexWorld), vNormalWorld);
    vec3 col = texColour * diff;
    
    fFragColor = vec4(col, 1.0);
}