all: Main
	
MinesModel.o: MinesModel.cpp MinesModel.hpp MinesState.hpp
	g++ -g -c -std=c++11 MinesModel.cpp -o MinesModel.o

MinesTerminal.o: MinesTerminal.cpp MinesTerminal.hpp
	g++ -g -c -std=c++11 MinesTerminal.cpp -o MinesTerminal.o

Main: MinesModel.o MinesTerminal.o main.cpp
	g++ -g -o mines -std=c++11 main.cpp MinesModel.o MinesTerminal.o

clean:
	rm mines MinesModel.o MinesTerminal.o
