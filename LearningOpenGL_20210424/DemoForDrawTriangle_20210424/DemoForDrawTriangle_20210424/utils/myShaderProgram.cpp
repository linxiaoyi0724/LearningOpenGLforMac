//
//  myShaderProgram.cpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/4/28.
//

#include "myShaderProgram.hpp"

namespace xiaoyi {

myShaderProgram myShaderProgram::mInstance;


myShaderProgram::myShaderProgram(){
}

myShaderProgram::~myShaderProgram(){
}

myShaderProgram* myShaderProgram::getInstance(){
    return &mInstance;
}

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

unsigned int myShaderProgram::createAndLinkShaderProgram(unsigned int vertexShader, unsigned int FragmentShader){
    unsigned int shaderProgam = glCreateProgram();
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
    
    return shaderProgam;
}

void myShaderProgram::deleteShader(unsigned int shader){
    glDeleteShader(shader);
}

void myShaderProgram::deleteProgram(unsigned int program){
    glDeleteProgram(program);
}

}
