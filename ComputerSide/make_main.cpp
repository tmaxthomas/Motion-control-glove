//
// Created by Max on 4/3/2017.
//

#include "io.h"
#include "Vector3d.h"
#include "Macro.h"
#include <iostream>
#include <fstream>
#include <list>
#include <stdint.h>
#include <map>

#define byte uint8_t
#define THRESHOLD 0.5

void readVector(std::istream& istr, Vector3d& vec);
void writeVector(std::ostream& ostr, Vector3d& vec);
float readFloat(int fd);

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cout << "ERROR: Incorrect number of inputs\n";
        return 1;
    }

    int fd;
    //Temp storage for macros
    std::list<Vector3d> thumb_accel, index_accel, middle_accel, magnet;
    //List of macros in file
    std::map<std::string, Macro> macros;
	
	fd = openPort(0);
	if(fd == -1) {
		return 1;
	}

    std::ifstream istr(argv[1]);

    if(!istr) {                      //If there isn't a macro file already,
        std::ofstream ostr(argv[1]); //Make one by opening a stream
    } else { //Read in the macro file
        std::string name, ch;
        char control;
        //Loop has an exit condition other than end of stream; don't worry
        while(istr.good()) {
            istr >> name >> ch;
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
            Macro temp(getKey(ch), thumb_accel, index_accel, middle_accel, magnet);
            macros[name] = temp;
			thumb_accel.erase(thumb_accel.begin(), thumb_accel.end());
            index_accel.erase(index_accel.begin(), index_accel.end());
            middle_accel.erase(middle_accel.begin(), middle_accel.end());
            magnet.erase(magnet.begin(), magnet.end());
            if(control == '#')
                break;
        }
    }

    std::string command;
    while(std::cin >> command) {
        if(command == "exit")
            break;
        else if(command == "create") {
            std::string name;
            std::string ch;
            bool start = false, end = false;
            while(!start) {
                Vector3d t_ac(readFloat(fd), readFloat(fd), readFloat(fd));
                Vector3d i_ac(readFloat(fd), readFloat(fd), readFloat(fd));
                Vector3d m_ac(readFloat(fd), readFloat(fd), readFloat(fd));
                Vector3d mg(readFloat(fd), readFloat(fd), readFloat(fd));
                if(t_ac.mag > THRESHOLD || i_ac.mag > THRESHOLD || m_ac.mag > THRESHOLD  || mg.mag > THRESHOLD)
                    start = true;
            }
            while(!end) {
                Vector3d t_ac(readFloat(fd), readFloat(fd), readFloat(fd));
                Vector3d i_ac(readFloat(fd), readFloat(fd), readFloat(fd));
                Vector3d m_ac(readFloat(fd), readFloat(fd), readFloat(fd));
                Vector3d mg(readFloat(fd), readFloat(fd), readFloat(fd));

                if(t_ac.mag < THRESHOLD && i_ac.mag < THRESHOLD && m_ac.mag < THRESHOLD && mg.mag < THRESHOLD)
                    end = true;
            }

        } else if(command == "rename") {
            std::string old_name, new_name;
            std::cin >> old_name >> new_name;
            Macro temp(macros[old_name]);
            macros.erase(old_name);
            macros[new_name] = temp;
        } else if(command == "delete") {
            std::string name;
            std::cin >> name;
            macros.erase(name);
        }
    }

    //Save macros and exit

    std::ofstream ostr(argv[1]);
    //Yeah, the way I disassemble this map is messy. Whatever.
    while(macros.size() > 0) {
        ostr << macros.begin()->first << " ";
        std::list<Vector3d>::iterator i_itr = macros.begin()->second.index_accel.begin();
        std::list<Vector3d>::iterator m_itr = macros.begin()->second.middle_accel.begin();
        std::list<Vector3d>::iterator mg_itr = macros.begin()->second.mag_meter.begin();
        for(std::list<Vector3d>::iterator t_itr = macros.begin()->second.thumb_accel.begin(); t_itr != macros.begin()->second.thumb_accel.end(); t_itr++) {
            writeVector(ostr, *t_itr);
            writeVector(ostr, *i_itr);
            writeVector(ostr, *m_itr);
            writeVector(ostr, *mg_itr);
            i_itr++; m_itr++; mg_itr++;
            if(i_itr != macros.begin()->second.index_accel.end())
                ostr << ", ";
        }
        macros.erase(macros.begin()->first);
        if(macros.size() == 0)
            ostr << "#";
        else
            ostr << "/\n";
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

void writeVector(std::ostream& ostr, Vector3d& vec) {
    ostr << vec.x << " " << vec.y << " " << vec.z << " ";
}

float readFloat(int fd) {
	float buf = 0;
    while(!read(fd, &buf, 4));
    return buf;
}
