//
// Created by Max on 4/3/2017.
//

#include "Macro.h"
#include "io.h"
#include "Vector3d.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <map>

void readVector(std::istream& istr, Vector3d& vec) {
    float x, y, z;
    istr >> x >> y >> z;
    vec.x = x;
    vec.y = y;
    vec.z = z;
}

void writeVector(std::ostream& ostr, Vector3d& vec) {
    ostr << vec.x << " " << vec.y << " " << vec.z << " ";
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cout << "ERROR: Incorrect number of inputs\n";
        return 1;
    }

    struct termios attribs, config;
    int fd;
    //Temp storage for macros
    std::list<Vector3d> thumb_accel, index_accel, middle_accel, magnet;
    //List of macros in file
    std::map<std::string, Macro> macros;

    /*fd = openPort(0);
    if(fd == -1) {
        return 1;
    }
    */
    std::ifstream istr(argv[1]);
    std::string name;
    char control;
    //Loop has an exit condition other than end of stream; don't worry
    while(istr.good()) {
        istr >> name;
        while(istr.good()) {
            Vector3d temp;
            readVector(istr, temp);
            thumb_accel.push_back(temp);
            readVector(istr, temp);
            index_accel.push_back(temp);
            readVector(istr, temp);
            middle_accel.push_back(temp);
            readVector(istr, temp);
            magnet.push_back(temp);
            istr >> control;
            if(control == '/' || control == '#')
                break;
        }
        Macro temp(thumb_accel, index_accel, middle_accel, magnet);
        macros[name] = temp;
        thumb_accel.erase(thumb_accel.begin(), thumb_accel.end());
        index_accel.erase(index_accel.begin(), index_accel.end());
        middle_accel.erase(middle_accel.begin(), middle_accel.end());
        magnet.erase(magnet.begin(), magnet.end());
        if(control == '#')
            break;
    }


    return 0;
}

