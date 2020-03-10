/**
 * Graph.h
 * Graph class -- builds graphs as adjacency lists,
 *  with vertices labeled by a string name,
 *  and directed, weighted edges (default weight of 1)
 * 
 * @author Mark Chesney, Seattle University
 * @see CPSC5031, Winter 2020, HW #8
 */

#pragma once
#include <string>
#include <vector>

class Graph {
public:
	typedef std::vector<std::string> Vertices;

    Graph() {}
    ~Graph() {}
	
	Graph(const Vertices& initial);

	int size();
	
private:
	Vertices v;
};
