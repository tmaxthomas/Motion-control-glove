//
// Created by Max on 4/6/2017.
//

#ifndef GLOVE_PROJECT_VECTOR3D_H
#define GLOVE_PROJECT_VECTOR3D_H

#include <cmath>


class Vector3d {
public:
    float x, y, z;
    float mag() { return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));}
};


#endif //GLOVE_PROJECT_VECTOR3D_H
