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
using namespace xiaoyi;

int main()
{
    xiaoyi::myGlfw::getInstance()->creatWindow();
    xiaoyi::myGlad::getInstance()->init();
        
    while (!glfwWindowShouldClose(xiaoyi::myGlfw::getInstance()->mWindow)) {
        myGlfw::processInput(xiaoyi::myGlfw::getInstance()->mWindow);
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(xiaoyi::myGlfw::getInstance()->mWindow);
        glfwPollEvents();
    }
}
