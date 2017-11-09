all:
	g++ -std=c++14 -c *.cpp
	g++ -std=c++14 *.o -o huffman.out
