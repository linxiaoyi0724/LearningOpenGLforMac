#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexture;

out vec3 ourColor;
out vec2 texCoord;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(aPos,1.0f);
    texCoord = aTexture;
    texCoord = vec2(aTexture.x, 1.0 - aTexture.y);
}
