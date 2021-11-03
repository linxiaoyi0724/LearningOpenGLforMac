////
////  demoLearningModel.cpp
////  DemoForDrawTriangle_20210424
////
////  Created by linxiaoyi on 2021/10/29.
////
//
//#include <iostream>
//#include "myGlad.hpp"
//#include "myGlfw.hpp"
//#include "myCamera.hpp"
//#include "myShaderProgram.hpp"
//#include "myModel.hpp"
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//xiaoyi::myCamera camera(glm::vec3(0.0f,0.0f,3.0f));
//
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
//float lastX = SCR_WIDTH / 2.0f;
//float lastY = SCR_HEIGHT / 2.0f;
//
//bool firstMouse = true;
//
//using namespace xiaoyi;
//
//void processInput(GLFWwindow *window);
//void mouseCallback(GLFWwindow* window, double xPos, double yPos);
//void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
//
//
//int main(){
//    myGlfw::getInstance()->creatWindow();
//    myGlad::getInstance()->init();
//
//    glfwSetCursorPosCallback(myGlfw::getInstance()->mWindow, mouseCallback);
//    glfwSetScrollCallback(myGlfw::getInstance()->mWindow, scrollCallback);
//
//    glfwSetInputMode(myGlfw::getInstance()->mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    stbi_set_flip_vertically_on_load(true);
//
//    glEnable(GL_DEPTH_TEST);
//
//    myShaderProgram ourShader("./vs/demoLearningModel/demoLearningModel.vs", "./fs/demoLearningModel/demoLearningModel.fs");
//
//    myModel ourModel("./resources/nanosuit/nanosuit.obj");
//
//    while (!glfwWindowShouldClose(myGlfw::getInstance()->mWindow)) {
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        processInput(myGlfw::getInstance()->mWindow);
//
//        glClearColor(0.05f, 0.05f, 0.05f,1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        ourShader.use();
//
//        glm::mat4 projection = glm::perspective(glm::radians(camera.mZoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//        glm::mat4 view = camera.getViewMatrix();
//        ourShader.setMat4f("projection", projection);
//        ourShader.setMat4f("view", view);
//
//        glm::mat4 model = glm::mat4(1.0f);
//        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
//        model = glm::scale(model, glm::vec3(1.0f,1.0f,1.0f));
//        ourShader.setMat4f("model", model);
//        ourModel.Draw(ourShader);
//
//        glfwSwapBuffers(myGlfw::getInstance()->mWindow);
//        glfwPollEvents();
//
//    }
//
//    glfwTerminate();
//    return 0;
//
//}
//
//
//void processInput(GLFWwindow *window){
//    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        camera.processKeyBorad(FORWARD, deltaTime);
//    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        camera.processKeyBorad(BACKWARD, deltaTime);
//    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        camera.processKeyBorad(LEFT, deltaTime);
//    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        camera.processKeyBorad(RIGHT, deltaTime);
//}
//
//void mouseCallback(GLFWwindow *window, double xPos, double yPos){
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
//void scrollCallback(GLFWwindow *window, double xOffset, double yOffset){
//    camera.processMouseScroll(yOffset);
//}
