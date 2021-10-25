//
//  demoLearningMultipleLights.cpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/10/19.
//

#include <iostream>
#include "myGlad.hpp"
#include "myGlfw.hpp"
#include "myCamera.hpp"
#include "myShaderProgram.hpp"
#include "myTexture.hpp"

#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

xiaoyi::myCamera camera(glm::vec3(0.0f,0.0f,3.0f));

float deltaTime = 0.0f;
float lastFrame = 0.0f;

float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;

bool firstMouse = true;

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
using namespace xiaoyi;

void processInput(GLFWwindow* window);
void mouseCallback(GLFWwindow* windoew, double xPos, double yPos);
void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);

int main()
{
    myGlfw::getInstance()->creatWindow();
    myGlad::getInstance()->init();
    
    float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
        
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
        
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
        
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };
    
    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    
    glm::vec3 pointLightPositions[] = {
        glm::vec3( 0.7f,  0.2f,  2.0f),
        glm::vec3( 2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f,  2.0f, -12.0f),
        glm::vec3( 0.0f,  0.0f, -3.0f)
    };
    
    unsigned int VBO, cubeVAO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindVertexArray(cubeVAO);
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,2,GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    
    unsigned int lightCubeVAO;
    glGenVertexArrays(1, & lightCubeVAO);
    glBindVertexArray(lightCubeVAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glEnable(GL_DEPTH_TEST);
    
    myShaderProgram lightingShaderProgram("./vs/demoLearningMultipleLights/demoLearningMultipleLights.vs", "./fs/demoLearningMultipleLights/demoLearningMultipleLights.fs");
    
    myShaderProgram lightingCubeShaderProgram("./vs/demoLearningMultipleLights/demoLearningMultipleLightsCube.vs", "./fs/demoLearningMultipleLights/demoLearningMultipleLightsCube.fs");
    
    glfwSetInputMode(myGlfw::getInstance()->mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    unsigned int diffuseMap = myTexture::getInstance()->loadTexture("./resources/container.png");
    unsigned int specularMap = myTexture::getInstance()->loadTexture("./resources/lighting_maps_specular_color.png");
    
    lightingShaderProgram.use();
    lightingShaderProgram.setInt("material.diffuse", 0);
    lightingShaderProgram.setInt("material.specular", 1);
    
    while(!glfwWindowShouldClose(myGlfw::getInstance()->mWindow)){
        float currentFrame = glfwGetTime();
        deltaTime = (currentFrame - lastFrame) * 0.01;
        lastFrame = deltaTime;
        
        processInput(myGlfw::getInstance()->mWindow);
        glfwSetCursorPosCallback(myGlfw::getInstance()->mWindow, mouseCallback);
        glfwSetScrollCallback(myGlfw::getInstance()->mWindow, scrollCallback);
        
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        lightingShaderProgram.use();
        lightingShaderProgram.setVec3("viewPos", camera.mPosition);
        lightingShaderProgram.setFloat("material.shininess", 32.0f);
        
        lightingShaderProgram.setVec3("dirLight.direction", glm::vec3(-0.2f, -1.0f, -0.3f));
        lightingShaderProgram.setVec3("dirLight.ambient", glm::vec3(0.05f, 0.05f, 0.05f));
        lightingShaderProgram.setVec3("dirLight.diffuse", glm::vec3(0.4f, 0.4f, 0.4f));
        lightingShaderProgram.setVec3("dirLight.specular", glm::vec3(0.5f, 0.5f, 0.5f));
        
        lightingShaderProgram.setVec3("pointLights[0].position", glm::vec3(pointLightPositions[0]));
        lightingShaderProgram.setVec3("pointLights[0].ambient", glm::vec3(0.05f, 0.05f, 0.05f));
        lightingShaderProgram.setVec3("pointLights[0].diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
        lightingShaderProgram.setVec3("pointLights[0].specular", glm::vec3(1.0f, 1.0f, 1.0f));
        lightingShaderProgram.setFloat("pointLights[0].constant", 1.0f);
        lightingShaderProgram.setFloat("pointLights[0].linear", 0.09);
        lightingShaderProgram.setFloat("pointLights[0].quadratic", 0.032);
        
        lightingShaderProgram.setVec3("pointLights[1].position", pointLightPositions[1]);
        lightingShaderProgram.setVec3("pointLights[1].ambient", glm::vec3(0.05f, 0.05f, 0.05f));
        lightingShaderProgram.setVec3("pointLights[1].diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
        lightingShaderProgram.setVec3("pointLights[1].specular", glm::vec3(1.0f, 1.0f, 1.0f));
        lightingShaderProgram.setFloat("pointLights[1].constant", 1.0f);
        lightingShaderProgram.setFloat("pointLights[1].linear", 0.09);
        lightingShaderProgram.setFloat("pointLights[1].quadratic", 0.032);
        
        // point light 3
        lightingShaderProgram.setVec3("pointLights[2].position", pointLightPositions[2]);
        lightingShaderProgram.setVec3("pointLights[2].ambient", glm::vec3(0.05f, 0.05f, 0.05f));
        lightingShaderProgram.setVec3("pointLights[2].diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
        lightingShaderProgram.setVec3("pointLights[2].specular", glm::vec3(1.0f, 1.0f, 1.0f));
        lightingShaderProgram.setFloat("pointLights[2].constant", 1.0f);
        lightingShaderProgram.setFloat("pointLights[2].linear", 0.09);
        lightingShaderProgram.setFloat("pointLights[2].quadratic", 0.032);
        // point light 4
        lightingShaderProgram.setVec3("pointLights[3].position", pointLightPositions[3]);
        lightingShaderProgram.setVec3("pointLights[3].ambient", glm::vec3(0.05f, 0.05f, 0.05f));
        lightingShaderProgram.setVec3("pointLights[3].diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
        lightingShaderProgram.setVec3("pointLights[3].specular", glm::vec3(1.0f, 1.0f, 1.0f));
        lightingShaderProgram.setFloat("pointLights[3].constant", 1.0f);
        lightingShaderProgram.setFloat("pointLights[3].linear", 0.09);
        lightingShaderProgram.setFloat("pointLights[3].quadratic", 0.032);
        // spotLight
        lightingShaderProgram.setVec3("spotLight.position", camera.mPosition);
        lightingShaderProgram.setVec3("spotLight.direction", camera.mFront);
        lightingShaderProgram.setVec3("spotLight.ambient", glm::vec3(0.0f, 0.0f, 0.0f));
        lightingShaderProgram.setVec3("spotLight.diffuse", glm::vec3(1.0f, 1.0f, 1.0f));
        lightingShaderProgram.setVec3("spotLight.specular", glm::vec3(1.0f, 1.0f, 1.0f));
        lightingShaderProgram.setFloat("spotLight.constant", 1.0f);
        lightingShaderProgram.setFloat("spotLight.linear", 0.09);
        lightingShaderProgram.setFloat("spotLight.quadratic", 0.032);
        lightingShaderProgram.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
        lightingShaderProgram.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
        
        glm::mat4 projection = glm::perspective((glm::radians(camera.mZoom)), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.getViewMatrix();
        lightingShaderProgram.setMat4f("projection", projection);
        lightingShaderProgram.setMat4f("view", view);
        
        glm::mat4 model = glm::mat4(1.0f);
        lightingShaderProgram.setMat4f("model", model);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,diffuseMap);
        
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D,specularMap);
        
        for(unsigned int i = 0; i < 10; i++){
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f,0.3f, 0.5f));
            lightingShaderProgram.setMat4f("model", model);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        
        lightingCubeShaderProgram.use();
        lightingCubeShaderProgram.setMat4f("projection", projection);
        lightingCubeShaderProgram.setMat4f("view", view);
        
        glBindVertexArray(cubeVAO);
        for(unsigned int i = 0; i < 4; i++){
            model = glm::mat4(1.0f);
            model = glm::translate(model, pointLightPositions[i]);
            model = glm::scale(model, glm::vec3(0.2f));
            lightingCubeShaderProgram.setMat4f("model", model);
            glDrawArrays(GL_TRIANGLES, 0 , 36);
        }
        
        glfwSwapBuffers(myGlfw::getInstance()->mWindow);
        glfwPollEvents();
    }
    
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteBuffers(1, &VBO);
    
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.processKeyBorad(FORWARD, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.processKeyBorad(BACKWARD, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.processKeyBorad(LEFT, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.processKeyBorad(RIGHT, deltaTime);
}

void mouseCallback(GLFWwindow *window, double xPos, double yPos){
    if(firstMouse){
        lastX = xPos;
        lastY = yPos;
        firstMouse = false;
    }
    
    float xOffset = xPos - lastX;
    float yOffset = lastY - yPos;
    
    lastX = xPos;
    lastY = yPos;
    
    camera.processMouseMovement(xOffset, yOffset);
}

void scrollCallback(GLFWwindow *window, double xOffset, double yOffset){
    camera.processMouseScroll(yOffset);
}
