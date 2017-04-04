#include "io.h"

//NOTE: The files here aren't accessible to normal users, which means you'll probably have to sudo this program to make it run
int open_port(int port_num) {
    struct termios config;
    int fd;

    //Find the correct port
    if(port_num == 1)
        fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);
    else if(port_num == 2)
        fd = open("/dev/ttyS1", O_RDWR | O_NOCTTY | O_NDELAY);
    else {
        perror("ERROR: Illegal port number passed to function open_port()\n");
        return -1;
    }
    //Make sure the port exists
    if(fd == -1) {
        printf("ERROR: Unable to open port at /dev/ttyS%d\n", port_num - 1);
    }

    if(tcgetattr(fd, &config) < 0) {
        printf("ERROR: Failed to acquire port config\n");
    }

    //Now... configs galore!

    //Theoretically speaking, I could just set these config values to 0 and skip the hassle...
    //But I'd rather have them all laid out in case I need to change them later.

    //In order... convert break to null byte, no CR to NL translation, no NL to CR translation,
    //don't mark parity errors or breaks, no input parity check, don't strip high bit off,
    //no XON/XOFF software flow control
    config.c_iflag &= ~(IGNBRK | BRKINT | ICRNL | INLCR | PARMRK | INPCK | ISTRIP | IXON);

    //In order... no CR to NL translationm no NL to CR-NL translation, no NL to CR translation,
    //no column 0 CR suppression, no fill characters, no case mapping, no local output processing
    config.c_oflag &= ~( OCRNL | ONLCR | ONLRET | ONOCR | OFILL | OLCUC | OPOST);

    //In order... echo off, echo newline off, canonical mode off, extended input processing off,
    //signal chars off
    config.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);

    //In order... clear current char size mask, no parity checking, no output processing, force 8 bit input
    config.c_cflag &= ~(CSIZE | PARENB);
    config.c_cflag |= CS8;

    config.c_cc[VMIN] = 1;
    config.c_cc[VTIME] = 0;


    //TODO: Check full list of configs to make sure everything's configured correctly

    //Set the baud rate to 9600
    if(cfsetispeed(&config, B9600) < 0 || cfsetospeed(&config, B9600) < 0) {
        printf("ERROR: Failed to set baud rate\n");
    }

    //Apply the configs to the port
    if(tcsetattr(fd, TCSAFLUSH, &config) < 0) {
        printf("ERROR: Failed to apply configs\n");
    }

    fcntl(fd, F_SETFL, O_NONBLOCK);
    return fd;
}

void write_bits(char* bit_buf, int size, int fd) {
    if(write(fd, bit_buf, size) < size)
        printf("ERROR: Write to %d failed to transmit all bytes\n", fd);
}

void read_bits(char* bit_buf, int size, int fd) {
    if(read(fd, bit_buf, size) < size)
        printf("ERRORL Read from %d failed to acquire all bytes\n", fd);
}