// Implementation file for the Graph class
// Created by Mark Chesney, March 2020.
#include "Graph.h"
#include <iostream>
#include <string>
using namespace std;

Graph::Graph(const Vertices& initial) {
	vector<std::string>::const_iterator itr;
	for (auto itr : initial) {
		v.push_back(itr);
	}
}

int Graph::size() {
	return v.size();
}
