all: macro_make macro_run TEST

macro_make:
	g++ -std=c++11 make_main.cpp io.cpp Vector3d.cpp Macro.cpp -o MakeMacros -Wall
	
macro_run:
	g++ -std=c++11 run_main.cpp io.cpp Vector3d.cpp Macro.cpp -o RunMacros -Wall -lX11 -lXtst
	
TEST:
	g++ -std=c++11 TEST_main.cpp io.cpp -o TEST -Wall
