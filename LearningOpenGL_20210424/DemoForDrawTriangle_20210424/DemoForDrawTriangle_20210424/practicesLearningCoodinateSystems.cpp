////
////  practicesLearningCoodinateSystems.cpp
////  DemoForDrawTriangle_20210424
////
////  Created by linxiaoyi on 2021/5/26.
////
//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include "myGlad.hpp"
//#include "myGlfw.hpp"
//#include "myShaderProgram.hpp"
//#include "stb_image.h"
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//using namespace xiaoyi;
//
//int main()
//{
//    myGlfw::getInstance()->creatWindow();
//    myGlad::getInstance()->init();
//    
//    float vertices[] = {
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//        
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        
//        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//    };
//    
//    glm::vec3 cubePositions[] = {
//        glm::vec3( 0.0f,  0.0f,  0.0f),
//        glm::vec3( 2.0f,  5.0f, -15.0f),
//        glm::vec3(-1.5f, -2.2f, -2.5f),
//        glm::vec3(-3.8f, -2.0f, -12.3f),
//        glm::vec3( 2.4f, -0.4f, -3.5f),
//        glm::vec3(-1.7f,  3.0f, -7.5f),
//        glm::vec3( 1.3f, -2.0f, -2.5f),
//        glm::vec3( 1.5f,  2.0f, -2.5f),
//        glm::vec3( 1.5f,  0.2f, -1.5f),
//        glm::vec3(-1.3f,  1.0f, -1.5f)
//        
//    };
//    //    unsigned int indexs[] = {
//    //        0,1,3,
//    //        1,2,3
//    //    };
//    
//    unsigned int VBO, VAO,EBO,texture;
//    glGenVertexArrays(1,&VAO);
//    glGenBuffers(1,&VBO);
//    //    glGenBuffers(1,&EBO);
//    glGenTextures(1,&texture);
//    
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER,VBO);
//    //    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
//    glBindTexture(GL_TEXTURE_2D,texture);
//    
//    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
//    //    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indexs),indexs,GL_STATIC_DRAW);
//    
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//    
//    int width, height, nrChannel;
//    
//    unsigned char* data = stbi_load("./resources/awesomeface.png", &width, &height, &nrChannel, 0);
//    if(data){
//        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
//        glGenerateMipmap(true);
//    }else{
//        std::cout << "Failed to load Texture." <<std::endl;
//    }
//    
//    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)0);
//    glEnableVertexAttribArray(0);
//    //    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(6*sizeof(float)));
//    //    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)(3*sizeof(float)));
//    glEnableVertexAttribArray(1);
//    
//    glEnable(GL_DEPTH_TEST);
//    
//    myShaderProgram shaderProgram("./vs/demoLearningCoordinateSystems.vs","./fs/demoLearningCoordinateSystems.fs");
//    shaderProgram.use();
//    shaderProgram.setInt("myTexture", 0);
//    
//    while (!glfwWindowShouldClose(myGlfw::getInstance()->mWindow)) {
//        myGlfw::getInstance()->processInput(myGlfw::getInstance()->mWindow);
//        glClearColor(0.2f,0.3f,0.3f,1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D,texture);
//        glBindVertexArray(VAO);
//        
//        glm::mat4 view =glm::mat4(1.0f);
//        glm::mat4 projection = glm::mat4(1.0f);
//        
//        view = glm::translate(view, glm::vec3(0.0f,0.0f,-3.0f));
//        projection = glm::perspective(glm::radians(90.0f), (float)SCR_WIDTH  / (float)SCR_HEIGHT, 0.1f, 100.0f);
//        
//        shaderProgram.setMat4f("view", view);
//        shaderProgram.setMat4f("projection", projection);
//        
//        for(int i = 0; i < 10; i++){
//            glm::mat4 model = glm::mat4(1.0f);
//            model = glm::translate(model, cubePositions[i]);
//            
//            float angle = 20.0f *i;
//            if(i ==0 || i % 3==0){
//                angle = glfwGetTime() * 90;
//            }
//            
//            model = glm::rotate(model,glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//            shaderProgram.setMat4f("model", model);
//            glDrawArrays(GL_TRIANGLES,0,36);
//        }
//        
//        
//        glfwSwapBuffers(myGlfw::getInstance()->mWindow);
//        glfwPollEvents();
//    }
//    glDeleteVertexArrays(1,&VAO);
//    glDeleteBuffers(1,&VBO);
//    glDeleteBuffers(1,&EBO);
//    glfwTerminate();
//    return 0;
//    
//}
