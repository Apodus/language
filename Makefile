all:
	g++ -O3 core/*.cpp -std=c++0x -o french.exe
	mkdir -p users
	mkdir -p data
