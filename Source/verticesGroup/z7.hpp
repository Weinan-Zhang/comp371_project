//
//  z7.hpp
//  COMP371_Labs
//
//  Created by ZhangDong on 2020-07-03.
//  Copyright © 2020 Concordia. All rights reserved.
//

#ifndef z7_h
#define z7_h
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "glm/gtc/type_ptr.hpp"

GLfloat z7_vertices[] = {
    // Z7 face
      -0.9f, 0.8f, 0.3f,  // 0
      -0.1f, 0.8f, 0.3f,  // 1
      -0.1f, 0.6f, 0.3f,  // 2
      -0.9f, 0.6f, 0.3f,  // 3
      -0.3f, 0.6f, 0.3f,  // 4
      -0.9f, 0.2f, 0.3f,  // 5
      -0.7f, 0.2f, 0.3f,  // 6
      -0.9f, 0.0f, 0.3f,  // 7
      -0.1f, 0.2f, 0.3f,  // 8
      -0.1f, 0.0f, 0.3f,  // 9
      0.1f, 0.8f, 0.3f,  // 10
      0.9f, 0.8f, 0.3f,  // 11
      0.1f, 0.6f, 0.3f,  // 12
      0.9f, 0.6f, 0.3f,  // 13
      0.7f, 0.6f, 0.3f,  // 14
      0.7f, 0.0f, 0.3f ,  // 15
      0.9f, 0.0f, 0.3f ,  // 16
    
    // Z7 Back
    -0.9f, 0.8f, 0.0f,  // 0
    -0.1f, 0.8f, 0.0f,  // 1
    -0.1f, 0.6f, 0.0f,  // 2
    -0.9f, 0.6f, 0.0f,  // 3
    -0.3f, 0.6f, 0.0f,  // 4
    -0.9f, 0.2f, 0.0f,  // 5
    -0.7f, 0.2f, 0.0f,  // 6
    -0.9f, 0.0f, 0.0f,  // 7
    -0.1f, 0.2f, 0.0f,  // 8
    -0.1f, 0.0f, 0.0f,  // 9
    0.1f, 0.8f, 0.0f,  // 10
    0.9f, 0.8f, 0.0f,  // 11
    0.1f, 0.6f, 0.0f,  // 12
    0.9f, 0.6f, 0.0f,  // 13
    0.7f, 0.6f, 0.0f,  // 14
    0.7f, 0.0f, 0.0f ,  // 15
    0.9f, 0.0f, 0.0f ,  // 16
    
    
};

GLint z7_indices[] = {
    // Z7 face
    0,1,2,
    0,2,3,
    2,4,6,
    4,6,5,
    5,8,7,
    7,8,9,
    10,11,13,
    10,13,12,
    13,14,16,
    14,15,16,
    
    //Z7 back + 17
    17,18,19,
    17,19,20,
    19,21,23,
    21,23,22,
    22,25,24,
    24,25,26,
    27,28,30,
    27,30,29,
    30,31,33,
    31,32,33,
    
    // Z7 Top & Bottom
    0,1,17,
    1,17,18,
    2,3,20,
    2,20,19,
    22,5,8,
    22,25,8,
    7,9,24,
    24,9,26,
    10,11,27,
    11,27,28,
    29,30,13,
    12,13,29,
    15,16,32,
    32,16,33,
    
    //Z7 Left and right
    0,3,17,
    17,3,20,
    4,5,21,
    21,5,22,
    5,7,22,
    22,7,24,
    1,2,18,
    18,19,2,
    19,2,6,
    19,23,6,
    10,12,27,
    27,12,29,
    14,15,32,
    32,31,14,
    11,16,33,
    11,33,28,
    
    
    
    
};

#endif /* z7_h */