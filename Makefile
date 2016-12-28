main: main.cpp Player.cpp Computer.cpp Ships.cpp
	g++ --std=c++11 -o main main.cpp Player.cpp Computer.cpp Ships.cpp
	./main