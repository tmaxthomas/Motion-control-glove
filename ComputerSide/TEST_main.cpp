#include <iostream>
#include <bitset>

#include "io.h"

int main(int argc, char* argv[]) {
	int fd;

	fd = openPort(argv[1]);

	if(fd == -1){
		std::cout << "ERROR: Unable to open serial port\n";
		return 1;
	}

	char buf[4];
	readBuf(fd, buf, 4);
	void* ptr = (void*)buf;
	int val = *(int*)ptr;
	std::cout << val << "\n";

	return 0;
}
