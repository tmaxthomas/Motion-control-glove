//
// Created by Max on 4/6/2017.
//

#ifndef GLOVE_PROJECT_VECTOR3D_H
#define GLOVE_PROJECT_VECTOR3D_H

#include <cmath>


class Vector3d {
public:
    Vector3d() : x(0), y(0), z(0) {}
    Vector3d(Vector3d& old) : x(old.x), y(old.y), z(old.z) {}
    Vector3d(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
    float x, y, z;
    float mag() { return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));}
};


#endif //GLOVE_PROJECT_VECTOR3D_H
