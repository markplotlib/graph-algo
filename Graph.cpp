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

vector<string> Graph::vertices() const {
	return v;
}

void Graph::addVertex(string vertex) {
	v.push_back(vertex);
	AdjList adjList;
	adjList.insert(pair<string, int>(vertex, 0));
	adjMatrix.insert(pair<string, AdjList>(vertex, adjList));
}

int Graph::getEdge(string vertexFrom, string vertexTo) {
	return 5;
}

void Graph::addEdge(string vertexFrom, string vertexTo, int weight) {
	int i = 0;
	bool hasOrigin = false, hasDest = false;
	int end = v.size();
	// search vector v for two vertex inputs 
	while (i < end) {
		if (v.at(i) == vertexFrom) 	hasOrigin = true;
		if (v.at(i) == vertexTo) 	hasDest = true;
		i++;
	}
	if (hasOrigin && hasDest)
		cout << "Vertex found." << endl;
	else
		cout << "Warning: Vertex not found." << endl;		
}
