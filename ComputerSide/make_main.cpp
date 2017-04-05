//
// Created by Max on 4/3/2017.
//

#include "io.h"

int main(int argc, char* argv[]) {
    struct termios attribs, config;
    int fd;
    fd = openPort(0);

    //TODO: Do some read/write stuff with the board

    return 0;
}