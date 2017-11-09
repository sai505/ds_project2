// test_huffman.cpp
// c. 2015 A. Deeter
// Revision 2017. Seung Jun Lee
/*
Steps:
1. Input String
2. Count the Frequency of Each Character
3. Create Priority Queue
4. Create Huffman Tree from Priority Queue
5. Binary Encoding
6. Serialize Representation : PreoderTraverse
#endif
*/
#include <iostream>
#include "Huffman.hpp"
#include <vector>


int main() {
	Huffman h;

	std::cout << "Input: MISSISSIPPI" << std::endl;
	Encoded e = h.encode("MISSISSIPPI");
	std::cout << e.encoded_string << std::endl;
	std::cout << e.serialized_tree << std::endl;
	std::cout << std::endl;

	std::cout << "Input: A man a plan, a canal, Panama!" << std::endl;
	Encoded a = h.encode("A man a plan, a canal, Panama!");
	//std::cout << a.encoded_string << std::endl;
	std::cout << a.serialized_tree << std::endl;
}