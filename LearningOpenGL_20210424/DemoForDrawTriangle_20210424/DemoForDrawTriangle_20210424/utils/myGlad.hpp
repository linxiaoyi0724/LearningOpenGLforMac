//
//  myGlad.hpp
//  DemoForDrawTriangle_20210424
//
//  Created by linxiaoyi on 2021/4/27.
//

#ifndef myGlad_hpp
#define myGlad_hpp

#include <stdio.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace xiaoyi {
    class myGlad
    {
    public:
        static myGlad* getInstance();
        void init();
    private:
        myGlad();
        static myGlad mInstance;
    
    };
}

#endif /* myGlad_hpp */
