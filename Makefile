run: a.exe
	./a

a.exe: main.cpp
	g++ main.cpp -std=c++14 -I .
