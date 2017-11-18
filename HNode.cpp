// hnode.cpp -- heap node class
// c. 2015 A. Deeter
// Revision 2017. Seung Jun Lee

#include "HNode.hpp"

//constructor for leaf nodes
HNode::HNode(const char& s, const int& t) {
	value = s;
	weight = t;
}

//constructor for internal nodes
HNode::HNode(HNode* l,HNode*r) {
	
	bool bgeq = l->weight <= r->weight;

	if (bgeq) {
		weight = l->weight + r->weight;
		left = l;
		right = r;
	}
	else {
		weight = l->weight + r->weight;
		left = r;
		right = l;
	}
}