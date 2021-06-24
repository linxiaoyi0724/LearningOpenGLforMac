////
////  demoLearningCamera.cpp
////  DemoForDrawTriangle_20210424
////
////  Created by linxiaoyi on 2021/5/27.
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
//xiaoyi::myCamera camera(glm::vec3(0.0f,0.0f,3.0f));
//
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
//float lastX = SCR_WIDTH / 2.0;
//float lastY = SCR_HEIGHT / 2.0;
//
//bool firstMouse = true;
//
//using namespace xiaoyi;
//
//void processInput(GLFWwindow* window);
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//
//void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);
//
//int main()
//{
//    myGlfw::getInstance()->creatWindow();
//    myGlad::getInstance()->init();
//    
//    float vertics[] = {
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//          0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//          0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//          0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//         -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//         -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//          0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//          0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//          0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//         -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//         -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//         -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//         -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//         -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//          0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//          0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//          0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//          0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//          0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//          0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//         -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//          0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//          0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//          0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//         -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//         -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//         -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//          0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//          0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//          0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//         -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//         -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//    };
//    
//    glm::vec3 cubePositions[] ={
//        glm::vec3( 0.0f,  0.0f,  0.0f),
//        glm::vec3( 2.0f,  5.0f, -15.0f),
//        glm::vec3(-1.5f, -2.2f, -2.5f),
//        glm::vec3(-3.8f, -2.0f, -12.3f),
//        glm::vec3 (2.4f, -0.4f, -3.5f),
//        glm::vec3(-1.7f,  3.0f, -7.5f),
//        glm::vec3( 1.3f, -2.0f, -2.5f),
//        glm::vec3( 1.5f,  2.0f, -2.5f),
//        glm::vec3( 1.5f,  0.2f, -1.5f),
//        glm::vec3(-1.3f,  1.0f, -1.5f)
//    };
//    
//    unsigned int VBO, VAO, texture;
//    glGenVertexArrays(1,&VAO);
//    glGenBuffers(1,&VBO);
//    glGenTextures(1,&texture);
//    
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER,VBO);
//    glBindTexture(GL_TEXTURE_2D,texture);
//    
//    glBufferData(GL_ARRAY_BUFFER,sizeof(vertics),vertics,GL_STATIC_DRAW);
//    
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//    
//    int width, height, nrChannel;
//    unsigned char* data = stbi_load("./resources/awesomeface.png", &width, &height, &nrChannel, 0);
//    if(data){
//        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
//        glGenerateMipmap(true);
//    }else{
//        std::cout << "Failed to load Texture."<<std::endl;
//    }
//    
//    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)(3*sizeof(float)));
//    glEnableVertexAttribArray(1);
//    
//    glEnable(GL_DEPTH_TEST);
//    
//    myShaderProgram shaderProgram("./vs/demoLearningCoordinateSystems.vs","./fs/demoLearningCoordinateSystems.fs");
//    shaderProgram.use();
//    shaderProgram.setInt("myTexture", 0);
//    
//    glm::mat4 view = glm::mat4(1.0f);
//    
//    glfwSetInputMode(myGlfw::getInstance()->mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    
//    while (!glfwWindowShouldClose(myGlfw::getInstance()->mWindow)) {
//        
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//        
//        processInput(myGlfw::getInstance()->mWindow);
//        
//        glfwSetCursorPosCallback(myGlfw::getInstance()->mWindow, mouse_callback);
//        glfwSetScrollCallback(myGlfw::getInstance()->mWindow, scroll_callback);
//        
//        view = camera.getViewMatrix();
//        shaderProgram.setMat4f("view", view);
//        
//        glClearColor(0.2f,0.3f,0.3f,1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D,texture);
//        glBindVertexArray(VAO);
//                
//        glm::mat4 projection = glm::mat4(1.0f);
//        projection = glm::perspective(glm::radians(camera.mZoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//        
//        shaderProgram.setMat4f("view", view);
//        shaderProgram.setMat4f("projection", projection);
//        
//        for(int i = 0 ; i< 10; i++){
//            glm::mat4 model = glm::mat4(1.0f);
//            model = glm::translate(model, cubePositions[i]);
//            
//            float angle= 20.0f * i;
//            if(i == 0 || i % 3 == 0){
//                angle = glfwGetTime() * 90;
//            }
//            
//            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//            shaderProgram.setMat4f("model", model);
//            glDrawArrays(GL_TRIANGLES,0,36);
//            
//        }
//        glfwSwapBuffers(myGlfw::getInstance()->mWindow);
//        glfwPollEvents();
//    }
//    glDeleteVertexArrays(1,&VAO );
//    glDeleteBuffers(1,&VBO);
//
//    glfwTerminate();
//    return 0;
//}
//
//void processInput(GLFWwindow* windows){
//
//    
//    if(glfwGetKey(windows, GLFW_KEY_ESCAPE) == GLFW_PRESS){
//        glfwSetWindowShouldClose(windows, true);
//    }
//    
//    if(glfwGetKey(windows, GLFW_KEY_W) == GLFW_PRESS){
//        camera.processKeyBorad(FORWARD, deltaTime);
//    }
//    if(glfwGetKey(windows, GLFW_KEY_S) == GLFW_PRESS){
//        camera.processKeyBorad(BACKWARD, deltaTime);
//    }
//    if(glfwGetKey(windows, GLFW_KEY_A) == GLFW_PRESS){
//        camera.processKeyBorad(LEFT, deltaTime);
//    }
//    if(glfwGetKey(windows, GLFW_KEY_D) == GLFW_PRESS){
//        camera.processKeyBorad(RIGHT, deltaTime);
//    }
//}
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos){
//    if(firstMouse){
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//    
//    float xOffset = xpos - lastX;
//    float yOffset = ypos - lastY;
//    
//    lastX = xpos;
//    lastY = ypos;
//    
//    camera.processMouseMovement(xOffset, yOffset);
//}
//
//void scroll_callback(GLFWwindow* window, double xOffset, double yOffset)
//{
//    camera.processMouseScroll(yOffset);
//}
