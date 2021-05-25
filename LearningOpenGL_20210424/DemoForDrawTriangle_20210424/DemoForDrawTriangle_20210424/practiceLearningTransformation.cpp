////
////  practiceLearningTransformation.cpp
////  DemoForDrawTriangle_20210424
////
////  Created by linxiaoyi on 2021/5/23.
////
//
//#include <iostream>
//#include "myGlfw.hpp"
//#include "myGlad.hpp"
//#include "myShaderProgram.hpp"
//#include "stb_image.h"
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//using namespace xiaoyi;
//
//int main(){
//    myGlfw::getInstance()->creatWindow();
//    myGlad::getInstance()->init();
//    
//    float vertices[] = {
//        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
//        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
//        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
//        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
//    };
//    
//    unsigned int indexs[] = {
//        0,1,3,
//        1,2,3
//    };
//    
//    unsigned int VBO, EBO, VAO, texture;
//    
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//    glGenTextures(1, &texture);
//    
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER,VBO);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
//    glBindTexture(GL_TEXTURE_2D,texture);
//    
//    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indexs),indexs,GL_STATIC_DRAW);
//    
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//    
//    int width, height, nrChannel;
//    stbi_set_flip_vertically_on_load(true);
//    unsigned char* data = stbi_load("./resources/awesomeface.png", &width, &height, &nrChannel, 0);
//    if(data){
//        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }else{
//        std::cout<<"Failed to load texture!"<<std::endl;
//    }
//    stbi_image_free(data);
//    
//    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(3*sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(6*sizeof(float)));
//    glEnableVertexAttribArray(2);
//    
//    myShaderProgram shaderProgram("./vs/demoLearningTransformation.vs","./fs/demoLearningTransformation.fs");
//    shaderProgram.use();
//    shaderProgram.setInt("myTexture", 0);
//    
//    while (!glfwWindowShouldClose(myGlfw::getInstance()->mWindow)) {
//        myGlfw::getInstance()->processInput(myGlfw::getInstance()->mWindow);
//        glClearColor(0.2f,0.3f,0.3f,1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//        
//        
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D,texture);
//        glBindVertexArray(VAO);
//        
//        glm::mat4 trans = glm::mat4(1.0f);
//        trans = glm::translate(trans, glm::vec3(0.5f,-0.5f,0.0f));
//        trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0,0.0,1.0));
//        shaderProgram.setMat4f("transform", trans);
//        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
//        
//        
//        trans = glm::mat4(1.0f);
//        trans = glm::translate(trans, glm::vec3(-0.5f,0.5f,0.0f));
//        float scaleAmount = sin(glfwGetTime());
//        trans = glm::scale(trans, glm::vec3(scaleAmount,scaleAmount,scaleAmount));
//        shaderProgram.setMat4f("transform", trans);
////        unsigned int transformLoc = glGetUniformLocation(shaderProgram.shaderProgam,"transform");
////        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
//        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
//        
//        glfwSwapBuffers(myGlfw::getInstance()->mWindow);
//        glfwPollEvents();
//    }
//    glDeleteVertexArrays(1,&VAO);
//    glDeleteBuffers(1,&VBO);
//    glDeleteBuffers(1,&EBO);
//    glfwTerminate();
//    return 0;
//}
