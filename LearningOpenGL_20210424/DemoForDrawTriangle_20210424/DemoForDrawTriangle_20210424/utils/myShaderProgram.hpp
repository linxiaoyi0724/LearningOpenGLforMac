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
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace xiaoyi {
class myShaderProgram{
public:
    static myShaderProgram* getInstance();
    unsigned int createAndComplieVertexShader(const char* vertexShaderSource);
    unsigned int createAndComplieFragmentShader(const char* fragmentShaderSource);
    unsigned int createAndLinkShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);
    void deleteShader(unsigned int vertexShader);
    void deleteProgram(unsigned int program);
private:
    myShaderProgram();
    ~myShaderProgram();
    static myShaderProgram mInstance;
};
}

#endif /* myShaderProgram_hpp */
