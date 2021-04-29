//
//  myGlfw.cpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/4/27.
//

#include "myGlfw.hpp"

namespace xiaoyi {
    myGlfw myGlfw::mInstance;

    myGlfw::myGlfw()
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
#endif
    }

    myGlfw* myGlfw::getInstance()
    {
        return &mInstance;
    }

    void myGlfw::creatWindow()
    {
        mWindow = glfwCreateWindow(800, 600, "learningShader", NULL, NULL);
        if(mWindow == NULL){
            std::cout << "Failed to create windows." <<std::endl;
            glfwTerminate();
        }
        glfwMakeContextCurrent(mWindow);
        glfwSetFramebufferSizeCallback(mWindow, framebufferSizeCallback);
    }
    
    void myGlfw::framebufferSizeCallback(GLFWwindow* window, int width, int height){
        glViewport(0,0,width,height);
    }

    void myGlfw::processInput(GLFWwindow* window){
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(window, true);
        }
    }
}

