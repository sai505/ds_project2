// hnode.cpp -- heap node class
// c. 2015 A. Deeter
// Revision 2017. Seung Jun Lee
/*
1. Create Node for Huffman tree and MinHeap
//DataType = struct HNode: left, right, char value, int weight
//Method = operator <, operator <=
a) Create Leaf Node
HNode::HNode(const char& s, const int& t) {
	1. Save Character : value = s
	2. Save Frequency : weight = t
}

b) Create Internal Node
HNode::HNode(HNode* l, HNode* r) {
	1. Compare frequency of LeafNode : left Node and right node
		bool beq = l <= r
	2. If true, then Make Internal Node : Frequency + Left Node + Right Node
		frequncy = left.weight + right.weight
		left = left leaf node
		right = right leaf node
	3. else, then
		frequncy = left.weight + right.weight
		left = right leaf node
		right = left leaf node
}
#endif
*/
#include "HNode.hpp"

//constructor for leaf nodes
HNode::HNode(const char& s, const int& t) {
	value = s;
	weight = t;
}

//constructor for internal nodes
HNode::HNode(HNode* l,HNode* r) {
	
	weight = l->weight + r->weight;
	left = l;
	right = r;
	/*
	bool bgeq = l->weight <= r->weight;
	bool bg = l->weight < r->weight;
	bool bg_v = l->value < r->value;
	//when weights are same, check the value and place small one to the left
	if (!bgeq) {
		weight = l->weight + r->weight;
		left = r;
		right = l;
	}
	else if (bgeq && bg && !bg_v) {
		weight = l->weight + r->weight;
		left = r;
		right = l;
	}
	else {
		weight = l->weight + r->weight;
		left = l;
		right = r;
	}*/
}