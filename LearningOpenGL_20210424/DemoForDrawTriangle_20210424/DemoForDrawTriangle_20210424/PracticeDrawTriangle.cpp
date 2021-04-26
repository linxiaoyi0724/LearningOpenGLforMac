//
//  PracticeDrawTriangle.cpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/4/26.
//


//你好三角形 课后习题
#include <stdio.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos; \n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char* fragmentOrangeShaderSource = "#version 330 core\n"
    "out vec4 FragColor; \n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f,0.5f,0.2f,1.0f);\n"
    "}\0";

const char* fragmentYellowShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
    "}\0";

void framebufferSizeCallback(GLFWwindow* window, int weight, int height){
    glViewport(0,0,weight,height);
}

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
#endif
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "practiceDrawTriangle", NULL, NULL);
    if(window ==  NULL){
        std::cout << "Failed to create window." <<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to init glad." <<std::endl;
        return -1;
    }
    
    
    float firstTriangle[] = {
        -0.9f, -0.5f, 0.0f,  // left
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  // top
    };
    float secondTriangle[] = {
        0.0f, -0.5f, 0.0f,  // left
        0.9f, -0.5f, 0.0f,  // right
        0.45f, 0.5f, 0.0f   // top
    };
    
    unsigned int VBOs[2];
    unsigned int VAOs[2];
    
    glGenBuffers(2, VBOs);
    glGenVertexArrays(2, VAOs);
    
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER,VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(firstTriangle),firstTriangle,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 *sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER,VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(secondTriangle),secondTriangle,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 *sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    
    
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);
    
    
    unsigned int fragmentOrangeShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentOrangeShader, 1, &fragmentOrangeShaderSource, NULL);
    glCompileShader(fragmentOrangeShader);
    
    unsigned int fragmentYellowShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentYellowShader, 1, &fragmentYellowShaderSource, NULL);
    glCompileShader(fragmentYellowShader);
    
    
    unsigned int shaderOrangeProgram = glCreateProgram();
    glAttachShader(shaderOrangeProgram,vertexShader);
    glAttachShader(shaderOrangeProgram,fragmentOrangeShader);
    glLinkProgram(shaderOrangeProgram);
    
    unsigned int shaderYellowProgram = glCreateProgram();
    glAttachShader(shaderYellowProgram, vertexShader);
    glAttachShader(shaderYellowProgram,fragmentYellowShader);
    glLinkProgram(shaderYellowProgram);
    
    
    while(!glfwWindowShouldClose(window)){
        processInput(window);
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shaderOrangeProgram);
        glBindVertexArray(VAOs[0]);
//        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        glDrawArrays(GL_TRIANGLES,0,3);
        
        glUseProgram(shaderYellowProgram);
        glBindVertexArray(VAOs[1]);
//        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        glDrawArrays(GL_TRIANGLES,0,3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glDeleteVertexArrays(2,VAOs);
    glDeleteBuffers(2, VBOs);
    glDeleteProgram(shaderOrangeProgram);
    glDeleteProgram(shaderYellowProgram);
    glfwTerminate();
    return 0;
    
}
