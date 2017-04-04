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
#include <iostream>
#include <fstream>

int open_port(int port_num); //Returns file descriptor for the selected port
void write_bits(char* bit_buf, int size, int fd);
void read_bits(char* bit_buf, int size, int fd);

#endif //GLOVE_PROJECT_IO_H
