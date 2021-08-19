////
////  practicesLearningBasicLighting.cpp
////  DemoForDrawTriangle_20210424
////
////  Created by linxiaoyi on 2021/7/21.
////
//
//#include <iostream>
//#include "myGlad.hpp"
//#include "myGlfw.hpp"
//#include "myCamera.hpp"
//#include "myShaderProgram.hpp"
//
//#include "stb_image.h"
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//xiaoyi::myCamera camear(glm::vec3(0.0f, 0.0f, 3.0f));
//
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
//float lastX = SCR_WIDTH / 2.0f;
//float lastY = SCR_HEIGHT / 2.0f;
//
//bool firstMouse = true;
//
//glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
//using namespace xiaoyi;
//
//void processInput(GLFWwindow* window);
//void mouseCallback(GLFWwindow* window, double xPos, double yPos);
//void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
//
//
//int main(){
//    myGlfw::getInstance()->creatWindow();
//    myGlad::getInstance()->init();
//
//    float vertices[] = {
//        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
//
//        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//    };
//
//    unsigned int VBO, cubeVAO;
//    //生成cube vertices array object
//    glGenVertexArrays(1,&cubeVAO);
//    glGenBuffers(1, &VBO);
//
//    //绑定 cube vertices array object
//    glBindVertexArray(cubeVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//    //分配数据
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 6*sizeof(float),(void*)(3*sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    unsigned int lightVAO;
//    glGenVertexArrays(1,&lightVAO);
//    glBindVertexArray(lightVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glEnable(GL_DEPTH_TEST);
//
//    myShaderProgram lightingShaderProgram("./vs/practicesLearningBasicLighting.vs", "./fs/practicesLearningBasicLighting.fs");
//    myShaderProgram lightCubeShaderProgram("./vs/practicesLearningBasicLighting.vs","./fs/demoLearningColorLightCube.fs");
//
//    glfwSetInputMode(myGlfw::getInstance()->mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    while(!glfwWindowShouldClose(myGlfw::getInstance()->mWindow)){
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        processInput(myGlfw::getInstance()->mWindow);
//        glfwSetCursorPosCallback(myGlfw::getInstance()->mWindow, mouseCallback);
//        glfwSetScrollCallback(myGlfw::getInstance()->mWindow, scrollCallback);
//
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        lightPos.x = 1.0f + sin(glfwGetTime()) * 2.0f;
//        lightPos.y = sin(glfwGetTime() / 2.0f) * 1.0f;
//
//        lightingShaderProgram.use();
//        lightingShaderProgram.setVec3("objectColor", glm::vec3(1.0f,0.5f,0.31f));
//        lightingShaderProgram.setVec3("lightColor", glm::vec3(1.0f,1.0f,1.0f));
//        lightingShaderProgram.setVec3("lightPos", lightPos);
//        lightingShaderProgram.setVec3("viewPos", camear.mPosition);
//
//        glm::mat4 projection = glm::perspective(glm::radians(camear.mZoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.f);
//        glm::mat4 view = camear.getViewMatrix();
//        glm::mat4 model = glm::mat4(1.0f);
//
//        lightingShaderProgram.setMat4f("projection", projection);
//        lightingShaderProgram.setMat4f("view", view);
//        lightingShaderProgram.setMat4f("model", model);
//
//        glBindVertexArray(cubeVAO);
//        glDrawArrays(GL_TRIANGLES,0,36);
//
//        lightCubeShaderProgram.use();
//        lightCubeShaderProgram.setMat4f("projection", projection);
//        lightCubeShaderProgram.setMat4f("view", view);
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, lightPos);
//        model = glm::scale(model, glm::vec3(0.2f));
//
//        lightCubeShaderProgram.setMat4f("model", model);
//
//        glBindVertexArray(lightVAO);
//        glDrawArrays(GL_TRIANGLES,0,36);
//
//        glfwSwapBuffers(myGlfw::getInstance()->mWindow);
//        glfwPollEvents();
//    }
//    glDeleteVertexArrays(1,&cubeVAO);
//    glDeleteVertexArrays(1,&lightVAO);
//    glDeleteBuffers(1,&VBO);
//
//    glfwTerminate();
//    return 0;
//}
//
//void processInput(GLFWwindow* windows){
//    if(glfwGetKey(windows, GLFW_KEY_ESCAPE) == GLFW_PRESS){
//        glfwSetWindowShouldClose(windows, true);
//    }
//    if(glfwGetKey(windows, GLFW_KEY_W) == GLFW_PRESS){
//        camear.processKeyBorad(FORWARD, deltaTime);
//    }
//    if(glfwGetKey(windows, GLFW_KEY_S) == GLFW_PRESS){
//        camear.processKeyBorad(BACKWARD, deltaTime);
//    }
//    if(glfwGetKey(windows, GLFW_KEY_A) == GLFW_PRESS){
//        camear.processKeyBorad(LEFT, deltaTime);
//    }
//    if(glfwGetKey(windows, GLFW_KEY_D) == GLFW_PRESS){
//        camear.processKeyBorad(RIGHT, deltaTime);
//    }
//}
//
//void mouseCallback(GLFWwindow* windows, double xPos, double yPos){
//    if(firstMouse){
//        lastX = xPos;
//        lastY = yPos;
//        firstMouse = false;
//    }
//    float xOffset = xPos - lastX;
//    float yOffset = yPos - lastY;
//
//    lastX = xPos;
//    lastY = yPos;
//
//    camear.processMouseMovement(xOffset, yOffset);
//}
//
//void scrollCallback(GLFWwindow* window, double xOffset, double yOffset){
//    camear.processMouseScroll(yOffset);
//}
