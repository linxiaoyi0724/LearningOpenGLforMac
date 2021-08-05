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

    void myGlfw::processInput(GLFWwindow* window, xiaoyi::myCamera camear,float deltaTime){
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(window, true);
        }
        if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
            camear.processKeyBorad(FORWARD, deltaTime);
        }
        if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
            camear.processKeyBorad(BACKWARD, deltaTime);
        }
        if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
            camear.processKeyBorad(LEFT, deltaTime);
        }
        if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
            camear.processKeyBorad(RIGHT, deltaTime);
        }
    }
    void mouseCallback(GLFWwindow* windows, xiaoyi::myCamera camear, double xPos, double yPos, float lastX, float lastY, bool firstMouse)
    {
        if(firstMouse){
            lastX = xPos;
            lastY = yPos;
            firstMouse = false;
        }
        float xOffset = xPos - lastX;
        float yOffset = yPos - lastY;
        
        lastX = xPos;
        lastY = yPos;
        
        camear.processMouseMovement(xOffset, yOffset);
    }
    void scrollCallback(GLFWwindow* window, xiaoyi::myCamera camear, double xOffset, double yOffset)
    {
        camear.processMouseScroll(yOffset);
    }
}

