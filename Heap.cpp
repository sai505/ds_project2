/*
//Heap.cpp
//c. 2015 A. Deeter
//Revision 2017. Seung Jun Lee

2. Create MinHeap
//DataType = class Heap: vector<HNode> tree, int position, int count
//Method = enqueue, fix_up, deque, fix_down
a) Enqueue = Add Node to Tree Vector at the Back
void enqueue(HNode* new_node) {
	1. Update Position = tree.size-1
		2. while (position not reach root && parent(position / 2) > New Node)
		- Promote : fix_up(position)
		3. Otherwise
		- Just store : Node[position] = newNode
}

b) Dequeue = Remove Node from Tree at the front
HNode* dequeue() {
	1. Pop node from at the top
		2. fix_down(rightindex);
}

c) Fix Up = Promote Child Node(if parent bigger than child)
void fix_up(const int& index) {
	1. Promote Child : node[index] to Parent : node[index / 2]
		2. Update position to Parent Index : position / 2
}

d) Fix Down = Demote Parent Node(if parent bigger than child)
void fix_down(const int& index) {
	1. root index = 1, lastindex = tree.size - 1, loop = true;
	2. while (true) {
		3. Update position = childindex:index * 2
			4. If(position : Left childindex < lastindex) {
			5. Store child = LeftChild
				6. If(Right childindex : 2 * position + 1 < lastindex && Right Child < Left Child) {
				7. Store child = RightChild, Update Position = position + 1;
			}

			6. If(Child < root) {
				7. Promote Child = Node[index] = child
					8. Update Parent Index to Child : index = position;
			}

			6. Else: Parent>Both Child = Exit while Loop
		}

		4. Else: No Children = Exit while loop
	}
}
#endif
*/

#include "Heap.hpp"

void Heap::print(){
	for (auto i : tree) {
		std::cout << "(" << i->value << "," << i->weight << ") ";
	}
	std::cout << std::endl;
}
// add an element to the tree
void Heap::enqueue(HNode* new_node) {
	tree.push_back(new HNode(NULL, 0));
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
	tree[position]->value = new_node->value;
	tree[position]->weight = new_node->weight;
}
// fix the heap from a specific index up

void Heap::fix_up(const int& index) {
	
	//demote parents 
	tree[index]->value = tree[index / 2]->value;
	tree[index]->weight = tree[index / 2]->weight;

	position = index / 2;
}

// remove the smallest element
HNode* Heap::dequeue() {
	//store minimum
	HNode* tmp = tree[0];
	HNode* pop = new HNode(tmp->value, tmp->weight);
	//remove last element
	HNode* back = tree.back();
	tree.pop_back();
	count = tree.size();
	position = tree.size() - 1;

	
	if (position >= 0) {
		tree[0]->weight = back->weight;
		tree[0]->value = back->value;
		fix_down(count);
	}
	return pop;

}

// fix the tree after replacing the smallest element
void Heap::fix_down(const int& lastindex) {
	int root_weight = tree[0]->weight;
	int root_value = tree[0]->value;   

	bool loop = true;
	int index = 0;

	while (loop) {
		int childIndex = index * 2 + 1;

		if (childIndex<position) {
			int child = tree[index * 2 + 1]->weight;

			if (2 * index + 2 <= position && tree[2 * index + 2]->weight < child) {
				childIndex = 2 * index + 2; 
				child = tree[2*index+2]->weight; 
			}

			if (child < root_weight) {
				tree[index]->weight = tree[childIndex]->weight;
				tree[index]->value = tree[childIndex]->value;
				index = childIndex;
			}

			else { loop = false; }
		}
		else { loop = false; }
	}
	tree[index]->weight = root_weight;
	tree[index]->value = root_value;
}

void Heap::clear() {
	tree.clear();
}



