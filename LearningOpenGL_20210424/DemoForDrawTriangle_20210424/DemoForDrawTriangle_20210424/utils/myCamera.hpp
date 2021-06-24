//
//  myCamera.hpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/5/28.
//

#ifndef myCamera_hpp
#define myCamera_hpp

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace xiaoyi {

enum cameraMovement{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class myCamera{
public:
    glm::vec3 mPosition;
    glm::vec3 mFront;
    glm::vec3 mUp;
    glm::vec3 mRight;
    glm::vec3 mWorldUp;
    
    float mYaw;
    float mPicth;
    
    float mMovementSpeed;
    float mMouseSensitivity;
    float mZoom;
    
    myCamera(glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f),glm::vec3 up = glm::vec3(0.0f,1.0f,0.0f), float yaw = YAW, float pitch = PITCH);
    
    myCamera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
    
    glm::mat4 getViewMatrix();
    
    glm::mat4 getMyViewMatrix();
    
    glm::mat4 calculateLookAtMatrix(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp);
    
    void processKeyBorad(cameraMovement direction, float deltaTime);
    
    void processMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch = true);
    
    void processMouseScroll(float yOffset);
    
private:
    void updateCameraVectors();
};
}

#endif /* myCamera_hpp */
