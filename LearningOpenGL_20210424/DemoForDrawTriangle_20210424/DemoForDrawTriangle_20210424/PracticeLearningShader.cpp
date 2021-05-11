//
//  PracticeLearningShader.cpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/5/11.
//

#include <stdio.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "myGlad.hpp"
#include "myGlfw.hpp"
#include "myShaderProgram.hpp"

using namespace xiaoyi;

int main()
{
    myGlfw::getInstance()->creatWindow();
    myGlad::getInstance()->init();
    
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };
    
    unsigned int indexs[] = {
        0,1,2
    };
    
    unsigned int VBO;
    unsigned int IBO;
    unsigned int VAO;
    
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &IBO);
    glGenVertexArrays(1, &VAO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexs),indexs, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6 * sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6 * sizeof(float),(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
    
    xiaoyi::myShaderProgram shaderProgram("./vs/practiceLearningShader.vs","./fs/shader.fs");
    while (!glfwWindowShouldClose(myGlfw::getInstance()->mWindow)) {
        myGlfw::getInstance()->processInput(myGlfw::getInstance()->mWindow);
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        shaderProgram.use();
        shaderProgram.setVec3("rightBias", glm::vec3(0.5f,0.0f,0.0f));
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,0);
        glfwSwapBuffers(myGlfw::getInstance()->mWindow);
        glfwPollEvents();
    }
    
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1,&IBO);
    glfwTerminate();
    return 0;
    
}
