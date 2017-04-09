//
// Created by Max on 4/7/2017.
//

#include "Macro.h"

Macro::Macro(std::list<Vector3d> thumb_accel_, std::list<Vector3d> index_accel_,
             std::list<Vector3d> middle_accel_, std::list<Vector3d> mag_meter_, double length_) :
        thumb_accel(thumb_accel_), index_accel(index_accel_), middle_accel(middle_accel_), mag_meter(mag_meter_), length(length_) {
    //Reserved for any necessary vector init
}

Macro::Macro(const Macro& old){
    thumb_accel = old.thumb_accel;
    index_accel = old.index_accel;
    middle_accel = old.middle_accel;
    mag_meter = old.mag_meter;
}