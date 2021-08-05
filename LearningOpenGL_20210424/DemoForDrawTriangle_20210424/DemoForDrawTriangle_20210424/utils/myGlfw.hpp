//
//  myGlfw.hpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/4/27.
//

#ifndef myGlfw_hpp
#define myGlfw_hpp

#include <stdio.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "myCamera.hpp"

namespace xiaoyi {
    class myGlfw{
    public:
        static myGlfw* getInstance();
        GLFWwindow* mWindow;
        void creatWindow();
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
        static void processInput(GLFWwindow* window);
        static void processInput(GLFWwindow* windows, xiaoyi::myCamera camear, float deltaTime);
        static void mouseCallback(GLFWwindow* windows, xiaoyi::myCamera camear, double xPos, double yPos, float lastX, float lastY, bool firstMouse);
        static void scrollCallback(GLFWwindow* window, xiaoyi::myCamera camear, double xOffset, double yOffset);
        
    private:
        static myGlfw mInstance;
        
        myGlfw();

    };
}
#endif /* myGlfw_hpp */
