//Heap.cpp
//c. 2015 A. Deeter
//Revision 2017. Seung Jun Lee

#include "Heap.hpp"

void Heap::print(){
	for (auto i : tree) {
		std::cout << "(" << i->value << "," << i->weight << ") ";
	}
	std::cout << std::endl;
}
// add an element to the tree
void Heap::enqueue(HNode* new_node) {
	tree.push_back(new HNode('n', 0));
	//std::cout << tree[0]->weight << tree[0]->value << std::endl;

	count = tree.size();

	position = tree.size()-1; //last index

	int tmp = 0;
	if (position > 1 && position % 2 == 0) {
		tmp = position - 1;
	}else{
		tmp = position;
	}

	while (position >0 && tree[tmp /2]->weight > new_node->weight){		
		fix_up(position);
	}
	//store vacant slot
	tree[position] = new_node;
}

// fix the heap from a specific index up
void Heap::fix_up(const int& index) {
	int tmp = 0;
	if (index > 1 && index % 2 == 0) {
		tmp = index - 1;
	}
	else {
		tmp = index;
	}
	//demote parents 
	tree[index] = tree[tmp / 2];

	position = tmp / 2;
}

// remove the smallest element
HNode* Heap::dequeue() {
	//store minimum
	HNode* pop = tree[0];

	//remove last element
	HNode* back = tree.back();
	tree.pop_back();
	count = tree.size();
	position = tree.size() - 1;

	
	if (position >= 0) {
		tree[0] = back;
		fix_down(count);
	}
	return pop;

}

// fix the tree after replacing the smallest element
void Heap::fix_down(const int& lastindex) {
	HNode* root_tmp = tree[0];

	bool loop = true;
	int index = 0;

	while (loop) {
		int childIndex = index * 2 + 1;

		if (childIndex<position) {
			int child = tree[index * 2 + 1]->weight;
			
			if (2 * index + 2 <= position && tree[2 * index + 2]->weight == child) {
				if (tree[2 * index + 2]->value < tree[index * 2 + 1]->value) {
					childIndex = 2 * index + 2;
					child = tree[2 * index + 2]->weight;
				}
			}
			if (2 * index + 2 <= position && tree[2 * index + 2]->weight < child) {
				childIndex = 2 * index + 2; 
				child = tree[2*index+2]->weight; 
			}

			if (child < root_tmp->weight) {
				tree[index] = tree[childIndex];
				index = childIndex;
			}

			else { loop = false; }
		}
		else { loop = false; }
	}
	tree[index] = root_tmp;
}

void Heap::clear() {
	tree.clear();
	tree.resize();
	tree.shrink_to_fit();
}



