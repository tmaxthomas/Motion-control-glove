//
// Created by Max on 4/7/2017.
//

#ifndef GLOVE_PROJECT_MACRO_H
#define GLOVE_PROJECT_MACRO_H

#include <list>
#include <string>
#include "Vector3d.h"


//Container class for macros

//Macro length is measured in the number of glove-computer transmissions that happen over the course of the macro. This is
//distinct from the user-provided length value, which is the duration of the macro in seconds.
class Macro {
public:
    Macro(std::string name_, std::list<Vector3d> thumb_accel_, std::list<Vector3d> index_accel_, std::list<Vector3d> middle_accel_, std::list<Vector3d> mag_meter_, double length_);
    std::list<Vector3d> thumb_accel, index_accel, middle_accel, mag_meter;
    double length;
    std::string name;
};


#endif //GLOVE_PROJECT_MACRO_H
