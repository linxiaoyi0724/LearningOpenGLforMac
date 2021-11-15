////
////  demoLearningFaceCulling.cpp
////  DemoForDrawTriangle_20210424
////
////  Created by linxiaoyi on 2021/11/11.
////
//
//#include <iostream>
//#include "myGlad.hpp"
//#include "myGlfw.hpp"
//#include "myCamera.hpp"
//#include "myShaderProgram.hpp"
//#include "myTexture.hpp"
//
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
//using namespace xiaoyi;
//
//void processInput(GLFWwindow* window);
//void mouseCallback(GLFWwindow* window, double xPos, double yPos);
//void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
//
//int main(){
//    myGlfw::getInstance()->creatWindow();
//    myGlad::getInstance()->init();
//    
//    glfwSetCursorPosCallback(myGlfw::getInstance()->mWindow, mouseCallback);
//    glfwSetScrollCallback(myGlfw::getInstance()->mWindow, scrollCallback);
//    glfwSetInputMode(myGlfw::getInstance()->mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//    
//    
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_BACK);
//    glFrontFace(GL_CCW);
//    
//    myShaderProgram ourShader("./vs/demoLearningFaceCulling/demoLearningFaceCulling.vs","./fs/demoLearningFaceCulling/demoLearningFaceCulling.fs");
//    
//    float cubeVertices[] = {
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Bottom-left
//        0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
//        0.5f, -0.5f, -0.5f,  1.0f, 0.0f, // bottom-right
//        0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // bottom-left
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
//        // Front face
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
//        0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
//        0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
//        0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
//        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, // top-left
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
//        // Left face
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
//        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-left
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
//        // Right face
//        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
//        0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
//        0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
//        0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
//        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
//        0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
//        // Bottom face
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
//        0.5f, -0.5f, -0.5f,  1.0f, 1.0f, // top-left
//        0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
//        0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
//        // Top face
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
//        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
//        0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
//        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
//        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f  // bottom-left
//    };
//    
//    
//    
//    unsigned int cubeVAO, cubeVBO;
//    glGenVertexArrays(1, &cubeVAO);
//    glGenBuffers(1,&cubeVBO);
//    
//    glBindVertexArray(cubeVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
//    
//    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
//    
//    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)(3*sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glBindVertexArray(0);
//    
//    unsigned int cubeTexture = myTexture::getInstance()->loadTexture("./resources/container.png");
//    ourShader.use();
//    ourShader.setInt("texture1", 0);
//    
//    
//    while (!glfwWindowShouldClose(myGlfw::getInstance()->mWindow)) {
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//        
//        processInput(myGlfw::getInstance()->mWindow);
//        
//        glClearColor(0.1f,0.1f,0.1f,1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        
//        ourShader.use();
//        glm::mat4 model = glm::mat4(1.0f);
//        glm::mat4 view = camera.getViewMatrix();
//        glm::mat4 projection = glm::perspective(glm::radians(camera.mZoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.f);
//        ourShader.setMat4f("view", view);
//        ourShader.setMat4f("projection", projection);
//        
//        glBindVertexArray(cubeVAO);
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, cubeTexture);
//        model = glm::translate(model, glm::vec3(-1.0f,0.0f,-1.0f));
//        ourShader.setMat4f("model", model);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        glBindVertexArray(0);
//        
//        glfwSwapBuffers(myGlfw::getInstance()->mWindow);
//        glfwPollEvents();
//    }
//}
//
//void  processInput(GLFWwindow * window){
//    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
//        glfwSetWindowShouldClose(window, true);
//    }
//    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
//        camera.processKeyBorad(FORWARD, deltaTime);
//    }
//    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
//        camera.processKeyBorad(BACKWARD, deltaTime);
//    }
//    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
//        camera.processKeyBorad(LEFT, deltaTime);
//    }
//    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
//        camera.processKeyBorad(RIGHT, deltaTime);
//    }
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
//    float yOffset = yPos - lastY;
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
