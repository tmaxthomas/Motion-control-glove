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
#include <vector>
#include <stdint.h>

int openPort(char* port); //Returns file descriptor for the selected port
void readBuf(int file, void* buf, int size);

#endif //GLOVE_PROJECT_IO_H
