//
//  myTexture.hpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/9/2.
//

#ifndef myTexture_hpp
#define myTexture_hpp

#include <stdio.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace  xiaoyi {
class myTexture{
public:
    static myTexture* getInstance();
    unsigned int loadTexture(char const *path);
private:
    myTexture();
    static myTexture mInstance;
};
}

#endif /* myTexture_hpp */
