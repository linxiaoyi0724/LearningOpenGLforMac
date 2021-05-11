//
//  myShaderProgram.cpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/4/28.
//

#include "myShaderProgram.hpp"

namespace xiaoyi {

myShaderProgram::myShaderProgram(const GLchar* vertexPath, const GLchar* fragmentPath){
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    
    try{
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        
        vShaderFile.close();
        fShaderFile.close();
        
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    
    unsigned int vertex, fragment;
    vertex = createAndComplieVertexShader(vShaderCode);
    fragment = createAndComplieFragmentShader(fShaderCode);
    
    createAndLinkShaderProgram(vertex, fragment);
}

myShaderProgram::~myShaderProgram(){}

unsigned int myShaderProgram::createAndComplieVertexShader(const char* vertexShaderSource){
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);
    
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    if(!success){
        glGetShaderInfoLog(vertexShader,512,NULL,infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED!" <<std::endl;
    }
    return vertexShader;
}

unsigned int myShaderProgram::createAndComplieFragmentShader(const char* fragmentShaderSource){
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
    glCompileShader(fragmentShader);
    
    int success;
    char infoLog[512];
    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
    if(!success){
        glGetShaderInfoLog(fragmentShader,512,NULL,infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED!"<<std::endl;
    }
    return fragmentShader;
}

void myShaderProgram::createAndLinkShaderProgram(unsigned int vertexShader, unsigned int FragmentShader){
    shaderProgam = glCreateProgram();
    glAttachShader(shaderProgam,vertexShader);
    glAttachShader(shaderProgam,FragmentShader);
    glLinkProgram(shaderProgam);
    
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgam,GL_LINK_STATUS,&success);
    if(!success){
        glGetProgramInfoLog(shaderProgam,512,NULL,infoLog);
        std::cout << "ERROR::PROGRAM::FRAGMENT::LINK_FAILD\n" << infoLog << std::endl;
    }
    
    deleteShader(vertexShader);
    deleteShader(FragmentShader);
    
}

void myShaderProgram::deleteShader(unsigned int shader){
    glDeleteShader(shader);
}

void myShaderProgram::deleteProgram(unsigned int program){
    glDeleteProgram(program);
}

void myShaderProgram::use(){
    glUseProgram(shaderProgam);
}

void myShaderProgram::setBool(const std::string &name, bool value)const{
    glUniform1i(glGetUniformLocation(shaderProgam, name.c_str()), (int)value);
}

void myShaderProgram::setInt(const std::string &name, int value)const{
    glUniform1i(glGetUniformLocation(shaderProgam, name.c_str()),value);
}

void myShaderProgram::setFloat(const std::string &name, float value)const{
    glUniform1f(glGetUniformLocation(shaderProgam, name.c_str()), value);
}

void myShaderProgram::setVec3(const std::string &name, glm::vec3 value)const{
    glUniform3f(glGetUniformLocation(shaderProgam, name.c_str()),value.x,value.y,value.z);
}

}
