//
//  demoLearningShader.cpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/4/27.
//

#include <stdio.h>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "myGlad.hpp"
#include "myGlfw.hpp"
#include "myShaderProgram.hpp"
using namespace xiaoyi;

const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
    "}\0";

const char* fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f,0.5f,0.2f,1.0f);\n"
    "}\0";




int main()
{
    xiaoyi::myGlfw::getInstance()->creatWindow();
    xiaoyi::myGlad::getInstance()->init();

    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maxium nr of vertex attrbutes supported: " << nrAttributes << std::endl;

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    unsigned int indices[] = {
        0,1,2
    };


    unsigned int VBO;
    unsigned int IBO;
    unsigned int VAO;

    glGenBuffers(1,&VBO);
    glGenBuffers(1,&IBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);  // 需要先绑定顶点数组对象，然后再绑定顶点缓冲对象，跟索引缓冲对象
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);



    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);

    unsigned int vertexShader =  myShaderProgram::getInstance()->createAndComplieVertexShader(vertexShaderSource);
    unsigned int fragmentShader = myShaderProgram::getInstance()->createAndComplieFragmentShader(fragmentShaderSource);
    unsigned int shaderProgram = myShaderProgram::getInstance()->createAndLinkShaderProgram(vertexShader, fragmentShader);


    while (!glfwWindowShouldClose(xiaoyi::myGlfw::getInstance()->mWindow)) {
        myGlfw::processInput(xiaoyi::myGlfw::getInstance()->mWindow);
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
//        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(xiaoyi::myGlfw::getInstance()->mWindow);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1,&IBO);
    myShaderProgram::getInstance()->deleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}







