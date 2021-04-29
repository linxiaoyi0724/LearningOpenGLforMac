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

namespace xiaoyi {
    class myGlfw{
    public:
        static myGlfw* getInstance();
        GLFWwindow* mWindow;
        void creatWindow();
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
        static void processInput(GLFWwindow* window);
        
    private:
        static myGlfw mInstance;
        
        myGlfw();

    };
}
#endif /* myGlfw_hpp */
