/*
 * GraphAlgs.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: rmhyman
 */
#include "GraphAlgs.h"
#include <array>
#include <queue>
#include <algorithm>
template <typename T = unsigned>
bool IsTreebalanced(std::vector<Node<T>> & graph){

	std::array<bool,graph.size()> visited;
	std::array<unsigned,graph.size()> distance;

	visited.fill(0);
	distance.fill(0);
	unsigned dist_to_root(0);
	auto root = graph.at(0);
	std::queue<Node<T>> q;
	q.push(root);
	while(not q.empty()){
		auto tmp = q.front();
		q.pop();
		++dist_to_root;
		for(auto & adj_node : tmp.adj_list){
			if(not visited.at(adj_node.number)){
				visited.at(adj_node.number) = true;
				distance.at(adj_node.number) = dist_to_root;
				graph.at(adj_node.number).dist_to_root = dist_to_root;
				q.push(adj_node);
			}
		}
	}
auto max_dist = std::max(distance.begin(),distance.end());
auto leaf_out_of_range = [&] (Node<T> & node) -> bool { return std::abs(node.dist_to_root) - std::abs(max_dist) > 1;};


	return std::find_if(graph.begin(),graph.end(),leaf_out_of_range) != graph.end();
}

