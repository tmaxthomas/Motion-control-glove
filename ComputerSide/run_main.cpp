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
#include <X11/Xlib.h>
#include <X11/Intrinsic.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>


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


    return 0;
}

//Generate a fake keypress using X11. Will add support for key toggle later, if time permits.
void fakeKey(Display* disp, KeySym keysym) {
    KeyCode keycode = 0;
    keycode = XKeysymToKeycode(disp, keysym);
    if(keycode == 0) return;
    XTestGrabControl(disp, True);
    XTestFakeKeyEvent (disp, keycode, True, 0);
    XTestFakeKeyEvent (disp, keycode, False, 0);

    XSync (disp, False);
    XTestGrabControl (disp, False);
}

void generateKeypress(Macro::keys key) {
    Display* disp = XOpenDisplay(NULL);
    switch(key) {
        case Macro::keys::a: fakeKey(disp, XK_A); break;
        case Macro::keys::b: fakeKey(disp, XK_B); break;
        case Macro::keys::c: fakeKey(disp, XK_C); break;
        case Macro::keys::d: fakeKey(disp, XK_D); break;
        case Macro::keys::e: fakeKey(disp, XK_E); break;
		case Macro::keys::f: fakeKey(disp, XK_F); break;
		case Macro::keys::g: fakeKey(disp, XK_G); break;
		case Macro::keys::h: fakeKey(disp, XK_H); break;
		case Macro::keys::i: fakeKey(disp, XK_I); break;
		case Macro::keys::j: fakeKey(disp, XK_J); break;
		case Macro::keys::k: fakeKey(disp, XK_K); break;
		case Macro::keys::l: fakeKey(disp, XK_L); break;
		case Macro::keys::m: fakeKey(disp, XK_M); break;
		case Macro::keys::n: fakeKey(disp, XK_N); break;
		case Macro::keys::o: fakeKey(disp, XK_O); break;
		case Macro::keys::p: fakeKey(disp, XK_P); break;
		case Macro::keys::q: fakeKey(disp, XK_Q); break;
		case Macro::keys::r: fakeKey(disp, XK_R); break;
		case Macro::keys::s: fakeKey(disp, XK_S); break;
		case Macro::keys::t: fakeKey(disp, XK_T); break;
		case Macro::keys::u: fakeKey(disp, XK_U); break;
		case Macro::keys::v: fakeKey(disp, XK_V); break;
		case Macro::keys::w: fakeKey(disp, XK_W); break;
		case Macro::keys::x: fakeKey(disp, XK_X); break;
		case Macro::keys::y: fakeKey(disp, XK_Y); break;
		case Macro::keys::z: fakeKey(disp, XK_Z); break;
		case Macro::keys::_1: fakeKey(disp, XK_1); break;
		case Macro::keys::_2: fakeKey(disp, XK_2); break;
		case Macro::keys::_3: fakeKey(disp, XK_3); break;
		case Macro::keys::_4: fakeKey(disp, XK_4); break;
		case Macro::keys::_5: fakeKey(disp, XK_5); break;
		case Macro::keys::_6: fakeKey(disp, XK_6); break;
		case Macro::keys::_7: fakeKey(disp, XK_7); break;
		case Macro::keys::_8: fakeKey(disp, XK_8); break;
		case Macro::keys::_9: fakeKey(disp, XK_9); break;
		case Macro::keys::_0: fakeKey(disp, XK_0); break;
		case Macro::keys::lbrack: fakeKey(disp, XK_bracketleft); break;
		case Macro::keys::rbrack: fakeKey(disp, XK_bracketright); break;
		case Macro::keys::bs: fakeKey(disp, XK_backslash); break;
		case Macro::keys::fs: fakeKey(disp, XK_slash); break;
		case Macro::keys::cm: fakeKey(disp, XK_comma); break;
		case Macro::keys::pd: fakeKey(disp, XK_period); break;
		case Macro::keys::grave: fakeKey(disp, XK_grave); break;
		case Macro::keys::sub: fakeKey(disp, XK_minus); break;
		case Macro::keys::eq: fakeKey(disp, XK_equal); break;
		case Macro::keys::null: break;
    }
}
