//
//  PracticeLearningTexture.cpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/5/19.
//

#include <stdio.h>
#include <iostream>

#include "myGlad.hpp"
#include "myGlfw.hpp"
#include "myShaderProgram.hpp"
#include "stb_image.h"
using namespace xiaoyi;

float mixValue = 0.2f;
void processInput(GLFWwindow* window);

int main()
{
    myGlfw::getInstance()->creatWindow();
    myGlad::getInstance()->init();
    
    float vertices[] = {
        //     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
        
        //习题2
        //        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   2.0f, 2.0f,   // 右上
        //        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   2.0f, 0.0f,   // 右下
        //        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
        //        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 2.0f    // 左上
        
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.8f, 0.8f,   // 右上
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   0.8f, 0.2f,   // 右下
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.2f, 0.2f,   // 左下
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.2f, 0.8f    // 左上
    };
    
    unsigned int indexs[] = {
        0, 1, 3,
        1, 2, 3
    };
    
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    unsigned int texture1, texture2;
    
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);
    glGenTextures(1, &texture1);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBindTexture(GL_TEXTURE_2D,texture1);
    
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indexs),indexs,GL_STATIC_DRAW);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    
    int width, height, nrChannel;
    stbi_set_flip_vertically_on_load(true);
    
    unsigned char* data = stbi_load("./resources/container.jpeg", &width, &height, &nrChannel, 0);
    if(data){
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        std::cout << "Failed to load texture1" << std::endl;
    }
    stbi_image_free(data);
    
    glGenTextures(1,&texture2);
    glBindTexture(GL_TEXTURE_2D,texture2);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    
    data = stbi_load("./resources/awesomeface.png", &width, &height, &nrChannel, 0);
    if(data){
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        std::cout << "Failed to load texture2" << std::endl;
    }
    stbi_image_free(data);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);
    
    myShaderProgram shaderProgram("./vs/PracticesLearningTexture.vs","./fs/PracticesLearningTexture.fs");
    shaderProgram.use();
    shaderProgram.setInt("ourTexture1", 0);
    shaderProgram.setInt("ourTexture2", 1);
    
    while (!glfwWindowShouldClose(myGlfw::getInstance()->mWindow)) {
        processInput(myGlfw::getInstance()->mWindow);
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D,texture2);
        
        shaderProgram.use();
        shaderProgram.setFloat("mixValue", mixValue);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
        glfwSwapBuffers(myGlfw::getInstance()->mWindow);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1,&EBO);
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
        mixValue += 0.002f;
        if(mixValue > 1.0f){
            mixValue = 1.0f;
        }
        
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        mixValue -= 0.002f;
        if(mixValue <0.0f){
            mixValue = 0.0f;
        }
        
    }
}
