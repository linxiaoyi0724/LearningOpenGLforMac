//
//  myGlad.cpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/4/27.
//

#include "myGlad.hpp"

namespace xiaoyi {

myGlad myGlad::mInstance;

myGlad::myGlad()
{
}

void myGlad::init(){
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initilize glad" <<std::endl;
    }
}

myGlad* myGlad::getInstance(){
    return &mInstance;
}


}
