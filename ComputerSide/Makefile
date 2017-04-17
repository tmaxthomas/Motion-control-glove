all:
	g++ -std=c++11 make_main.cpp io.cpp Vector3d.cpp Macro.cpp -o MakeMacros -Wall; \
	g++ -std=c++11 run_main.cpp io.cpp Vector3d.cpp Macro.cpp -o RunMacros -Wall -lX11 -lXtst; \
	g++ -std=c++11 TEST_main.cpp io.cpp -o TEST -Wall -lserial -lpthread
