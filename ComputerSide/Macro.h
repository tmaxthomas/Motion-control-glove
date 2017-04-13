//
// Created by Max on 4/7/2017.
//

#ifndef GLOVE_PROJECT_MACRO_H
#define GLOVE_PROJECT_MACRO_H

#include <list>
#include <iostream>
#include <string>
#include "Vector3d.h"


//Container class for macros

//Macro length is measured in the number of glove-computer transmissions that happen over the course of the macro. This is
//distinct from the user-provided length value, which is the duration of the macro in seconds.
class Macro {
public:
    enum keys{q, w, e, r, t, y, u, i, o, p, a, s, d, f, g, h, j, k, l, z, x, c, v, b, n, m, _1, _2, _3, _4, _5, _6, _7, _8, _9, _0, lbrack, rbrack, bs, fs, cm,
                pd, grave, sub, eq, null};
    Macro() {}
    Macro(keys key_, std::list<Vector3d> thumb_accel_, std::list<Vector3d> index_accel_, std::list<Vector3d> middle_accel_, std::list<Vector3d> mag_meter_);
    Macro(const Macro& old); //Copy constructor
    std::list<Vector3d> thumb_accel, index_accel, middle_accel, mag_meter;
    keys key;
    int getLength() { return thumb_accel.size(); } //Simple get_length
};

Macro::keys getKey(const std::string& ch);


#endif //GLOVE_PROJECT_MACRO_H
