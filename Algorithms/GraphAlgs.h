/*
 * GraphAlgs.h
 *
 *  Created on: Nov 22, 2014
 *      Author: rmhyman
 */

#ifndef GRAPHALGS_H_
#define GRAPHALGS_H_
#include <vector>
#include <forward_list>


template<typename T = unsigned>
class Node {
public:
	Node();
	bool isLeaf();
	bool isRoot();
	T value;
	std::forward_list<Node> adj_list;
	unsigned number = 0;
	unsigned dist_to_root = 0;
	~Node();
};
template<typename T = unsigned>
bool IsTreebalanced(std::vector<Node<T>> & graph);



#endif /* GRAPHALGS_H_ */
