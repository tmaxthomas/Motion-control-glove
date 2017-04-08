//
// Created by Max on 4/7/2017.
//

#include "Macro.h"

Macro::Macro(std::string name_, std::list<Vector3d> thumb_accel_, std::list<Vector3d> index_accel_,
             std::list<Vector3d> middle_accel_, std::list<Vector3d> mag_meter_, double length_) :
name(name_), thumb_accel(thumb_accel_), index_accel(index_accel_), middle_accel(middle_accel_), mag_meter(mag_meter_), length(length_) {
    //Reserved for any necessary vector init
}