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

class Graph {
public:
    Graph() {}
    ~Graph() {}
	std::string getName();
	int getNum();
	void setNum(int n);
	void setName(std::string n);
	
private:
	std::string name;
	int num;
};
