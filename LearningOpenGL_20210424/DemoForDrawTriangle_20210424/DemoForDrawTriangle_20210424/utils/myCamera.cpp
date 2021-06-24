//
//  myCamera.cpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/5/28.
//

#include "myCamera.hpp"
namespace xiaoyi{

myCamera::myCamera(glm::vec3 position ,glm::vec3 up , float yaw , float pitch) : mFront(glm::vec3(0.0f,0.0f,-1.0f)),mMovementSpeed(SPEED),mMouseSensitivity(SENSITIVITY),mZoom(ZOOM){
    mPosition = position;
    mWorldUp = up;
    mYaw = yaw;
    mPicth = pitch;
}

myCamera::myCamera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch):mFront(glm::vec3(0.0f,0.0f,-1.0f)),mMovementSpeed(SPEED),mMouseSensitivity(SENSITIVITY),mZoom(ZOOM){
    mPosition = glm::vec3(posX,posY,posZ);
    mWorldUp = glm::vec3(upX,upY,upZ);
    mYaw = yaw;
    mPicth = pitch;
}

glm::mat4 myCamera::getViewMatrix(){
    return glm::lookAt(mPosition, mPosition + mFront, mUp);
}

glm::mat4 myCamera::getMyViewMatrix(){
    return calculateLookAtMatrix(mPosition, mPosition + mFront, mUp);
}

void myCamera::processKeyBorad(cameraMovement direction, float deltaTime){
    float velocity = mMovementSpeed * deltaTime;
    if(direction == FORWARD){
        mPosition += mFront * velocity;
    }
    if(direction == BACKWARD){
        mPosition -= mFront * velocity;
    }
    if(direction == LEFT){
        mPosition -= mRight * velocity;
    }
    if(direction == RIGHT){
        mPosition += mRight * velocity;
    }
//    mPosition.y = 0.0f;
}

void myCamera::processMouseMovement(float xOffset, float yOffset, GLboolean constrianPitch){
    xOffset *= mMouseSensitivity;
    yOffset *= mMouseSensitivity;
    
    mYaw += xOffset;
    mPicth += yOffset;
    
    if(constrianPitch){
        if(mPicth > 89.0f){
            mPicth = 89.0f;
        }
        if(mPicth < -89.0f){
            mPicth = -89.0f;
        }
    }
    updateCameraVectors();
}

void myCamera::processMouseScroll(float yOffset){
    mZoom -= (float)yOffset;
    if(mZoom < 1.0f){
        mZoom = 1.0f;
    }
    if(mZoom > 45.0f){
        mZoom = 45.0f;
    }
}


void myCamera::updateCameraVectors(){
    glm::vec3 front;
    front.x = cos(glm::radians(mYaw)) * cos(glm::radians(mPicth));
    front.y = sin(glm::radians(mPicth));
    front.z = sin(glm::radians(mYaw)) * cos(glm::radians(mPicth));
    mFront = glm::normalize(front);
    mRight = glm::normalize(glm::cross(mFront, mWorldUp));
    mUp = glm::normalize(glm::cross(mRight, mFront));
}


glm::mat4 myCamera::calculateLookAtMatrix(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp){
    glm::vec3 zaxis = glm::normalize(position - target);
    glm::vec3 xaxis = glm::normalize(glm::cross(glm::normalize(worldUp), zaxis));
    glm::vec3 yaxis = glm::cross(zaxis, xaxis);
    
    glm::mat4 translation = glm::mat4(1.0f);
    translation[3][0] = -position.x;
    translation[3][1] = -position.y;
    translation[3][2] = -position.z;
    
    glm::mat4 rotation = glm::mat4(1.0f);
    rotation[0][0] = xaxis.x;
    rotation[1][0] = xaxis.y;
    rotation[2][0] = xaxis.z;
    
    rotation[0][1] = yaxis.x;
    rotation[1][1] = yaxis.y;
    rotation[2][1] = yaxis.z;
    
    rotation[0][2] = zaxis.x;
    rotation[1][2] = zaxis.y;
    rotation[2][2] = zaxis.z;
    
    return  rotation * translation;
}


}
