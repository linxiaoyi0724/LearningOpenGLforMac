/////Users/linxiaoyi/xiaoyi/Code/GitRepo/text_flower/textOptimizeV3_1/event.lua
////  demoLearningLightingMap.cpp
////  DemoForDrawTriangle_20210424
////
////  Created by linxiaoyi on 2021/8/24.
////
//
//#include <iostream>
//#include "myGlad.hpp"
//#include "myGlfw.hpp"
//#include "myCamera.hpp"
//#include "myShaderProgram.hpp"
//#include "myTexture.hpp"
//
//#include "stb_image.h"
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//xiaoyi::myCamera camera(glm::vec3(0.0f, 0.0f, 3.0f));
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
//
//using namespace xiaoyi;
//
//void processInput(GLFWwindow* window);
//void mouseCallback(GLFWwindow* window, double xPos, double yPos);
//void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
//
//int main()
//{
//    myGlfw::getInstance()->creatWindow();
//    myGlad::getInstance()->init();
//
//    float vertices[] = {
//        // positions          // normals           // texture coords
//         -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
//          0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
//          0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
//          0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
//         -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
//         -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
//
//         -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
//          0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
//          0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
//          0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
//         -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
//         -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
//
//         -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//         -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
//         -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//         -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//         -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
//         -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//
//          0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//          0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
//          0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//          0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//          0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
//          0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//
//         -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
//          0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
//          0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
//          0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
//         -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
//         -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
//
//         -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
//          0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
//          0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
//          0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
//         -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
//         -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
//    };
//
//
//    unsigned int VBO, cubeVAO;
//    glGenVertexArrays(1, &cubeVAO);
//    glGenBuffers(1, &VBO);
//
//    glBindVertexArray(cubeVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1,3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//    glEnableVertexAttribArray(2);
//
//
//    unsigned int lightVAO;
//    glGenVertexArrays(1, &lightVAO);
//    glBindVertexArray(lightVAO);
//    glBindBuffer(GL_ARRAY_BUFFER,VBO);
//    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 8 *sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glEnable(GL_DEPTH_TEST);
//
//
//    myShaderProgram lightingShaderProgram("./vs/demoLearningLightingMap/demoLearningLightingMap.vs","./fs/demoLearningLightingMap/demoLearningLightingMap.fs");
//    myShaderProgram lightingCubeShaderProgram("./vs/demoLearningLightingMap/demoLearningLightingMapCube.vs", "./fs/demoLearningLightingMap/demoLearningLightingMapCube.fs");
//
//    glfwSetInputMode(myGlfw::getInstance()->mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    unsigned int diffuseMap = myTexture::getInstance()->loadTexture("./resources/container.png");
//    unsigned int specularMap = myTexture::getInstance()->loadTexture("./resources/container2_specular.png");
//
//    lightingShaderProgram.use();
//    lightingShaderProgram.setInt("material.diffuse", 0);
//    lightingShaderProgram.setInt("material.specular", 1);
//
//    while (!glfwWindowShouldClose(myGlfw::getInstance()->mWindow)) {
//        float currentFrame = glfwGetTime();
//        deltaTime = (currentFrame - lastFrame) * 0.01;
//        lastFrame = deltaTime;
//
//        processInput(myGlfw::getInstance()->mWindow);
//        glfwSetCursorPosCallback(myGlfw::getInstance()->mWindow, mouseCallback);
//        glfwSetScrollCallback(myGlfw::getInstance()->mWindow, scrollCallback);
//
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        lightingShaderProgram.use();
//        lightingShaderProgram.setVec3("light.position", lightPos);
//        lightingShaderProgram.setVec3("viewPos", camera.mPosition);
//
//        lightingShaderProgram.setVec3("light.ambient", glm::vec3(0.2f, 0.2f, 0.2f));
//        lightingShaderProgram.setVec3("light.diffuse", glm::vec3(0.5f, 0.5f, 0.5f));
//        lightingShaderProgram.setVec3("light.specular", glm::vec3(1.0f, 1.0f, 1.0f));
//
////        lightingShaderProgram.setVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
//        lightingShaderProgram.setFloat("material.shininess", 64.0f);
//
//        glm::mat4 projection = glm::perspective(glm::radians(camera.mZoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//        glm::mat4 view = camera.getViewMatrix();
//        lightingShaderProgram.setMat4f("projection", projection);
//        lightingShaderProgram.setMat4f("view", view);
//
//        glm::mat4 model = glm::mat4(1.0f);
//        lightingShaderProgram.setMat4f("model", model);
//
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, diffuseMap);
//
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D,specularMap);
//
//
//        glBindVertexArray(cubeVAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//        lightingCubeShaderProgram.use();
//        lightingCubeShaderProgram.setMat4f("projection", projection);
//        lightingCubeShaderProgram.setMat4f("view", view);
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, lightPos);
//        model = glm::scale(model, glm::vec3(0.2f));
//        lightingCubeShaderProgram.setMat4f("model", model);
//
//        glBindVertexArray(lightVAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        glfwSwapBuffers(myGlfw::getInstance()->mWindow);
//        glfwPollEvents();
//    }
//
//    glDeleteVertexArrays(1, &cubeVAO);
//    glDeleteVertexArrays(1, &lightVAO);
//    glDeleteBuffers(1, &VBO);
//
//    glfwTerminate();
//    return 0;
//}
//
//void processInput(GLFWwindow *window){
//    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        camera.processKeyBorad(FORWARD, deltaTime);
//
//    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        camera.processKeyBorad(BACKWARD, deltaTime);
//
//    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        camera.processKeyBorad(LEFT, deltaTime);
//
//    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        camera.processKeyBorad(RIGHT, deltaTime);
//}
//
//void mouseCallback(GLFWwindow* window, double xPos, double yPos){
//    if(firstMouse){
//        lastX = xPos;
//        lastY = yPos;
//        firstMouse = false;
//    }
//
//    float xOffset = xPos - lastX;
//    float yOffset = lastY - yPos;
//
//    lastX = xPos;
//    lastY = yPos;
//
//    camera.processMouseMovement(xOffset, yOffset);
//}
//
//void scrollCallback(GLFWwindow* window, double xOffset, double yOffset){
//    camera.processMouseScroll(yOffset);
//}
//
//
//
