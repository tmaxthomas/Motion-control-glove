//
// Created by Max on 4/3/2017.
//

#include "io.h"

int main(int argc, char* argv[]) {
    struct termios attribs, config;
    int fd;
    fd = open_port(0);
    return 0;
}