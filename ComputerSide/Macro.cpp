//
// Created by Max on 4/7/2017.
//

#include "Macro.h"

Macro::Macro(Macro::keys key_, std::list<Vector3d> thumb_accel_, std::list<Vector3d> index_accel_,
             std::list<Vector3d> middle_accel_, std::list<Vector3d> mag_meter_) :
        thumb_accel(thumb_accel_), index_accel(index_accel_), middle_accel(middle_accel_), mag_meter(mag_meter_), key(key_){
    //Reserved for any necessary vector init
}

Macro::Macro(const Macro& old){
    key = old.key;
    thumb_accel = old.thumb_accel;
    index_accel = old.index_accel;
    middle_accel = old.middle_accel;
    mag_meter = old.mag_meter;
}

//Hoo boy, conditionals
Macro::keys getKey(const std::string& ch) {
    if(ch == "a")
        return Macro::keys::a;
    else if(ch == "b")
        return Macro::keys::b;
    else if(ch == "c")
        return Macro::keys::c;
    else if(ch == "d")
        return Macro::keys::d;
    else if(ch == "e")
        return Macro::keys::e;
    else if(ch == "f")
        return Macro::keys::f;
    else if(ch == "g")
        return Macro::keys::g;
    else if(ch == "h")
        return Macro::keys::h;
    else if(ch == "i")
        return Macro::keys::i;
    else if(ch == "j")
        return Macro::keys::j;
    else if(ch == "k")
        return Macro::keys::k;
    else if(ch == "l")
        return Macro::keys::l;
    else if(ch == "m")
        return Macro::keys::m;
    else if(ch == "n")
        return Macro::keys::n;
    else if(ch == "o")
        return Macro::keys::o;
    else if(ch == "p")
        return Macro::keys::p;
    else if(ch == "q")
        return Macro::keys::q;
    else if(ch == "r")
        return Macro::keys::r;
    else if(ch == "s")
        return Macro::keys::s;
    else if(ch == "t")
        return Macro::keys::t;
    else if(ch == "u")
        return Macro::keys::u;
    else if(ch == "v")
        return Macro::keys::v;
    else if(ch == "w")
        return Macro::keys::w;
    else if(ch == "x")
        return Macro::keys::x;
    else if(ch == "y")
        return Macro::keys::y;
    else if(ch == "z")
        return Macro::keys::z;
    else if(ch == "1")
        return Macro::keys::_1;
    else if(ch == "2")
        return Macro::keys::_2;
    else if(ch == "3")
        return Macro::keys::_3;
    else if(ch == "4")
        return Macro::keys::_4;
    else if(ch == "5")
        return Macro::keys::_5;
    else if(ch == "6")
        return Macro::keys::_6;
    else if(ch == "7")
        return Macro::keys::_7;
    else if(ch == "8")
        return Macro::keys::_8;
    else if(ch == "9")
        return Macro::keys::_9;
    else if(ch == "0")
        return Macro::keys::_0;
    else if(ch == "[")
        return Macro::keys::lbrack;
    else if(ch == "]")
        return Macro::keys::rbrack;
    else if(ch == "\\")
        return Macro::keys::bs;
    else if(ch == "/")
        return Macro::keys::fs;
    else if(ch == ",")
        return Macro::keys::cm;
    else if(ch == ".")
        return Macro::keys::pd;
    else if(ch == "`")
        return Macro::keys::grave;
    else if(ch == "-")
        return Macro::keys::sub;
    else if(ch == "=")
        return Macro::keys::eq;
	else {
		std::cout << "Warning: Macro assigned to null key\n";
		return Macro::keys::null;
	}
}
