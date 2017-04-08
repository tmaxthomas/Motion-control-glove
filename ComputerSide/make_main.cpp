//
// Created by Max on 4/3/2017.
//

#include "io.h"
#include "Vector3d.h"
#include "Macro.h"
#include <list>
#include <iostream>
#include <fstream>

Vector3d readVector();

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
    std::list<Macro> macros;

    fd = openPort(0);
    std::ifstream istr(argv[1]);

    if(!istr) {                      //If there isn't a macro file already,
        std::ofstream ostr(argv[1]); //Make one by opening a stream
    } else { //Read in the macro file
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
            Macro temp(name, thumb_accel, index_accel, middle_accel, magnet, thumb_accel.size());
            macros.push_back(temp);
            if(control == '#')
                break;
        }
    }


    return 0;
}

void readVector(std::istream& istr, Vector3d& vec) {
    float x, y, z;
    istr >> x >> y >> z;
    vec.x = x;
    vec.y = y;
    vec.z = z;
}