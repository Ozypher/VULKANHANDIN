#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D texSampler;
layout(location = 0) in vec3 fragNormal;
layout(location = 1) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;


void main()
{
    vec3 lightVector = vec3(0,0,3);
    float cosTheta = dot( fragNormal,lightVector );
    vec4 baseColor = texture(texSampler, fragTexCoord);
    outColor = baseColor + baseColor * vec4(0.80,0.14,0.18,0.2) *cosTheta;
    outColor.w = baseColor.w + vec4(0.20,0.66,0.32,0.0).w;
}
