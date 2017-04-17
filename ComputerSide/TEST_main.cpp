#include <iostream>
#include <bitset>
#include <SerialStream.h>
#include <SerialStreamBuf.h>

#include "io.h"

int main(int argc, char* argv[]) {
	/*
	int fd;

	fd = openPort(argv[1]);

	if(fd == -1){
		std::cout << "ERROR: Unable to open serial port\n";
		return 1;
	}
	while(true) {
		int val = 0;
		readBuf(fd, &val, 4);
		std::cout << std::bitset<32>(val) << "\n";
	}
	*/
	std::string port(argv[1]);
	LibSerial::SerialStream sstr(port, LibSerial::SerialStreamBuf::BAUD_19200, LibSerial::SerialStreamBuf::CHAR_SIZE_8,
								 LibSerial::SerialStreamBuf::PARITY_NONE, 1, LibSerial::SerialStreamBuf::FLOW_CONTROL_HARD);
	while(true) {
		char buf[4];
		sstr.get(buf[0]);
		if(buf[0] != EOF) {
			sstr.get(buf[1]); sstr.get(buf[2]); sstr.get(buf[3]);
		    std::cout << std::bitset<8>(buf[3]) << " " << std::bitset<8>(buf[2]) << " " <<  std::bitset<8>(buf[1]) << " " << std::bitset<8>(buf[0]) << " " << *(float*)buf << "\n";
		}
	}
	return 0;
}
