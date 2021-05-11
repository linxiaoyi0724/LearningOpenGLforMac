//
//  myShaderProgram.hpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/4/28.
//

#ifndef myShaderProgram_hpp
#define myShaderProgram_hpp

#include <stdio.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
namespace xiaoyi {
class myShaderProgram{
public:
    unsigned int shaderProgam;
    myShaderProgram(const GLchar* vertexPath, const GLchar* fragmentPath);
    ~myShaderProgram();
    
    unsigned int createAndComplieFragmentShader(const char* fragmentShaderSource);
    unsigned int createAndComplieVertexShader(const char* vertexShaderSource);
    void createAndLinkShaderProgram(unsigned int vertexShader, unsigned int FragmentShader);
    
    void deleteShader(unsigned int shader);
    void deleteProgram(unsigned int program);
    
    void use();
    void setBool(const std::string &name, bool value)const;
    void setInt(const std::string &name, int value)const;
    void setFloat(const std::string& name, float value)const;
    void setVec3(const std::string& name, glm::vec3 value)const;
};
}

#endif /* myShaderProgram_hpp */
