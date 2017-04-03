#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>


//NOTE: The files here aren't accessible to normal users, which means you'll probably have to sudo this program to make it run
int open_port(int port_num) {
    int fd;
    if(port_num == 1)
        fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);
    else if(port_num == 2)
        fd = open("/dev/ttyS1", O_RDWR | O_NOCTTY | O_NDELAY);
    else {
        perror("ERROR: Illegal port number passed to function open_port()\n");
        return -1;
    }
    if(fd == -1) {
        printf("ERROR: Unable to open port at /dev/ttyS%d\n", port_num - 1);
    } else {
        fcntl(fd, F_SETFL, 0);
    }
    return fd;
}

void write_bits(char* bits, int fd) {
    int n = write(fd, bits, sizeof bits);
    if(n < 0)
        printf("ERROR: Write to %d failed in function write_bits\n", fd);
}

int main(int argc, char* argv[]) {
    int fd;
    fd = open_port(1);
    return 0;
}