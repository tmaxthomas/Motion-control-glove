#include <iostream>

#include "io.h"

int main(int argc, char* argv[]) {
	int fd;
	
	fd = openPort(argv[1]);

	if(fd == -1){
		std::cout << "ERROR: Unable to open serial port\n";
		return 1;
	}
	
	while(true) {
		int buf = 0;
		while(buf == 0)
			read(fd, &buf, 4);
		std::cout << buf << "\n";
	}

	return 0;
}
