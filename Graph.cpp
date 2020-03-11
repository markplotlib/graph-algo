// Implementation file for the Graph class
// Created by Mark Chesney, March 2020.
#include "Graph.h"
#include <iostream>
#include <string>
using namespace std;

Graph::Graph(const Vertices& initial) {
	vector<string>::const_iterator itr;
	for (auto itr : initial) {
		v.push_back(itr);
	}
}

int Graph::size() {
	return v.size();
}

vector<string> Graph::vertices() const {
	return v;
}

void Graph::addVertex(string vertex) {
	v.push_back(vertex);
}

// void Graph::addEdge(string vertexFrom, string vertexTo, int weight) {
// }
