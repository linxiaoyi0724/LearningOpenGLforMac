#version 330 core
out vec4 FragColor;
in vec3 ourColor;
in vec2 texCoord;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
uniform float mixValue;

void main()
{
    //习题1
    //    FragColor = mix(texture(ourTexture1,texCoord),texture(ourTexture2,vec2(1.0f-texCoord.x,texCoord.y)),0.2f);
    
    FragColor = mix(texture(ourTexture1,texCoord),texture(ourTexture2,texCoord),mixValue);
}
