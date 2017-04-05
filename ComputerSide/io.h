//
// Created by Max on 4/3/2017.
//

#ifndef GLOVE_PROJECT_IO_H
#define GLOVE_PROJECT_IO_H

#include <io.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <string>

//I should have made this a class, but I was trying to write C-compliant code. Which is why it's a mess, and why you need
//to store the file handler in an integer and pass it to everything.

int openPort(int port_num); //Returns file descriptor for the selected port
void writeBits(char* bit_buf, int size, int fd);
void readBits(char* bit_buf, int size, int fd);

#endif //GLOVE_PROJECT_IO_H
