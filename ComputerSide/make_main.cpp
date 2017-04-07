//
// Created by Max on 4/3/2017.
//

#include "io.h"
#include "Vector3d.h"
#include <list>

int main(int argc, char* argv[]) {
    struct termios attribs, config;
    int fd;
    std::list<Vector3d> thumb_accel, index_accel, middle_accel, magnet;
    fd = openPort(0);
    //Reading thumb acceleration


    return 0;
}