#version 330 core

in vec3 Normal;
in vec3 FragPos;


uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;

out vec4 FragColor;
 
void main()
{
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;
    
    //漫反射光照到方向向量
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    
    //向量的点乘算出在法向量的投影
    float diff = max(dot(norm,lightDir), 0.0);
    vec3 diffuse = diff * lightDir;

    vec3 result = (ambient + diffuse) * objectColor;
    FragColor = vec4(result,1.0);
}
