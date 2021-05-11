#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform vec3 rightBias;

out vec3 outputColor;

void main()
{
    gl_Position = vec4((vec3(aPos.x, -aPos.y, aPos.z) + rightBias), 1.0f);
    outputColor = aPos;
}
