//
// Created by Max on 4/3/2017.
//

#ifndef GLOVE_PROJECT_IO_H
#define GLOVE_PROJECT_IO_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <string>

//Yeah, it seems a bit strange that I gave this lone method its own header and cpp file. However! It's needed by both rum_main and make_main,
//which makes it more efficient to store it in a common file

int openPort(char* port); //Returns file descriptor for the selected port

#endif //GLOVE_PROJECT_IO_H
